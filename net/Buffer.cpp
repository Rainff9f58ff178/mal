//
// Created by rain on 2022/6/17.
//

#include "Buffer.h"
#include "Type.h"
#include<cassert>
#include <cerrno>
#include <sys/uio.h>
#include<algorithm>
#include <liburing.h>
#include"log.h"
namespace mal{


    const char Buffer::CRLF[] = "\r\n";

    Buffer::Buffer(size_t initialSize):
            writeIndex_(CheapPrepend),
            readindex_(CheapPrepend),
            buffer_(CheapPrepend+initialSize){
        assert(readableBytes()==0);
        assert(writeableBytes()==initialSize);
        assert(prependableBytes() == CheapPrepend);

    }

    size_t Buffer::readableBytes() {
        return writeIndex_-readindex_;
    }

    size_t Buffer::writeableBytes() {
        return buffer_.size() - writeIndex_;
    }

    size_t Buffer::prependableBytes() {
        return readindex_;
    }

    const char *Buffer::begin() const {
        return &(*buffer_.begin());
    }

    io_uring_sqe* Buffer::readFd(int sockfd, int *savedError,::io_uring& read_ring) {
        // saved an ioctl()/FIONREAD call to tell how much to read
        struct iovec vec[2];
        const size_t writable = writeableBytes();
        vec[0].iov_base = begin()+writeIndex_;
        vec[0].iov_len = writable;
        vec[1].iov_base = extrabuf;
        vec[1].iov_len = sizeof extrabuf;
        // when there is enough space in this buffer, don't read into extrabuf.
        // when extrabuf is used, we read 128k-1 bytes at most.
//        const ssize_t n = readv(sockfd, vec, 2);
        auto sqe= io_uring_get_sqe(&read_ring);
        io_uring_prep_readv(sqe,sockfd,vec,2,0);
        return sqe;
    }

    void Buffer::readFdLater(int n){
        const size_t writable = writeableBytes();
        if (n < 0)
        {
            CONSOLE_ERROR("void Buffer::readFdLater n <0 ");
        }
        else if (implicit_cast<size_t>(n) <= writable)
        {
            writeIndex_ += n;
        }
        else
        {
            writeIndex_ = buffer_.size();
            append(extrabuf, n - writable);
        }
    }
    void Buffer::append(const char * data, int size) {
        //make sure sufficient place to store surplus data
        ensureWritableBytes(size);
        //copy
        std::copy(data,data+size,beginWrite());
        //update writeIndex_
        hasWritten(size);
    }


    void Buffer::append(const std::string &msg) {
        append(msg.data(),msg.size());
    }

    void Buffer::ensureWritableBytes(size_t len) {
        if(writeableBytes() < len )
            makeSpace(len);
        assert(writeableBytes() >= len);
    }

    void Buffer::makeSpace(int len) {
        if (writeableBytes() + prependableBytes() < len + CheapPrepend)
            buffer_.resize(writeIndex_+len);
        else{
            // move readable data to the front, make space inside buffer
            assert(CheapPrepend < readindex_);
            size_t readable = readableBytes();
            std::copy(begin()+readindex_,
                      begin()+writeIndex_,
                      begin()+CheapPrepend);
            readindex_ = CheapPrepend;
            writeIndex_ = readindex_ + readable;
            assert(readable == readableBytes());
        }
    }

    const char *Buffer::beginWrite() const {
        return begin()+writeIndex_;
    }

    void Buffer::hasWritten(size_t n) {
        assert(n <= writeableBytes());
        writeIndex_ += n;
    }

    void Buffer::retrieve(int len) {
        assert(len <= readableBytes());
        if (len < readableBytes())
        {
            readindex_ += len;
        }
        else
        {
            retrieveAll();
        }
    }

    void Buffer::retrieveAll() {
        readindex_ = CheapPrepend;
        writeIndex_ = CheapPrepend;
    }

    const char *Buffer::findCRLF() const {
        const char* crlf = std::search(peek(),beginWrite(),CRLF,CRLF+2);
        return crlf == beginWrite() ? nullptr : crlf;
    }

    const char *Buffer::findCRLF(const char *start) const {
        assert(peek() <= start);
        assert(start <= beginWrite());
        const char* crlf = std::search(start, beginWrite(), CRLF, CRLF+2);
        return crlf == beginWrite() ? NULL : crlf;
    }

    void Buffer::retrieveUntil(const char *end) {

        retrieve(end-peek());
    }

    char *Buffer::beginWrite() {
        return &*begin()+writeIndex_;
    }

    std::string Buffer::retrieveAsString(int len) {
        std::string s(peek(),peek()+len);
        if(!s.empty()){
            retrieve(len);
        }
        return s;
    }


}
