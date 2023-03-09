//
// Created by rain on 2022/6/17.
//

#ifndef LINUXNETWORKPROGRAMCHENSHUO_BUFFER_H
#define LINUXNETWORKPROGRAMCHENSHUO_BUFFER_H
#include<vector>
#include<string>
#include<liburing.h>
namespace mal{

    class Buffer {
    public:
        static const size_t CheapPrepend = 8;
        static const size_t InitialSize = 1024;

        Buffer(size_t initialSize=InitialSize);
        ::io_uring_sqe* readFd(int sockfd,int* savedError,::io_uring& read_ring);
        size_t readableBytes();
        size_t writeableBytes();
        size_t prependableBytes();
        const char* peek() const
        { return begin() + readindex_; }
        char* begin()
        { return &*buffer_.begin(); }
        void retrieve(int);
        void retrieveAll();
        std::string retrieveAsString(int len);
        void append(const char*,int);
        void append(const std::string& msg);
        void prepend(const void*,int);
        void hasWritten(size_t n);
        void ensureWritableBytes(size_t len);
        const char* beginWrite()const;
        char* beginWrite();
        void makeSpace(int len);
        const char* begin() const;
        const char* findCRLF()const;
        const char* findCRLF(const char* start)const;
        void retrieveUntil(const char* end);
        void readFdLater(int n);
        char extrabuf[65536];
    private:
        std::vector<char> buffer_;
        size_t writeIndex_;
        size_t readindex_;
        static const char CRLF[];

    };


}
#endif //LINUXNETWORKPROGRAMCHENSHUO_BUFFER_H
