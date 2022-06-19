//
// Created by rain on 2022/6/17.
//

#ifndef LINUXNETWORKPROGRAMCHENSHUO_BUFFER_H
#define LINUXNETWORKPROGRAMCHENSHUO_BUFFER_H
#include<vector>
#include<string>
namespace mal{

    class Buffer {
    public:
        static const size_t CheapPrepend = 8;
        static const size_t InitialSize = 1024;

        Buffer(size_t initialSize=InitialSize);
        ssize_t readFd(int sockfd,int* savedError);
        size_t readableBytes();
        size_t writeableBytes();
        size_t prependableBytes();
        const char* peek() const
        { return begin() + readindex_; }
        char* begin()
        { return &*buffer_.begin(); }
        void retrieve(int);
        void retrieveAll();
        std::string retrieveAsString();
        void append(const char*,int);
        void prepend(const void*,int);
        void hasWritten(size_t n);
        void ensureWritableBytes(size_t len);
        char* beginWrite();
        void makeSpace(int len);
        const char* begin() const;


    private:
        std::vector<char> buffer_;
        size_t writeIndex_;
        size_t readindex_;

    };


}
#endif //LINUXNETWORKPROGRAMCHENSHUO_BUFFER_H
