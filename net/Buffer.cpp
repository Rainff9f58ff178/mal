//
// Created by rain on 2022/6/17.
//

#include "Buffer.h"
#include "Type.h"
#include<cassert>
#include <cerrno>
#include <sys/uio.h>
namespace mal{


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

    ssize_t Buffer:: readFd(int sockfd, int *savedError) {
        // saved an ioctl()/FIONREAD call to tell how much to read
        char extrabuf[65536];
        struct iovec vec[2];
        const size_t writable = writeableBytes();
        vec[0].iov_base = begin()+writeIndex_;
        vec[0].iov_len = writable;
        vec[1].iov_base = extrabuf;
        vec[1].iov_len = sizeof extrabuf;
        // when there is enough space in this buffer, don't read into extrabuf.
        // when extrabuf is used, we read 128k-1 bytes at most.
        const ssize_t n = readv(sockfd, vec, 2);
        if (n < 0)
        {
            *savedError = errno;
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
        return n;
    }

    void Buffer::append(const char * data, int size) {
        //make sure sufficient place to store surplus data
        ensureWritableBytes(size);
        //copy
        std::copy(data,data+size,beginWrite());
        //update writeIndex_
        hasWritten(size);
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

    char *Buffer::beginWrite() {
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
}
