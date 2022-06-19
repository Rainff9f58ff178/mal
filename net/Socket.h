//
// Created by rain on 2022/6/14.
//

#ifndef LINUXNETWORKPROGRAMCHENSHUO_SOCKET_H
#define LINUXNETWORKPROGRAMCHENSHUO_SOCKET_H

#include"InetAddress.h"
namespace mal{


    namespace sockets{
        int createNonBlockOrDie();
    }

    class Socket {
    public:
        Socket(int fd);

        ~Socket();

        int fd(){return fd_;}
        void bindAddresss(InetAddress addr);
        void listen();
        void shutdownWrite();
        void setTcoNoDelay(bool on);
        int accept(InetAddress& addr);
    private:
        int fd_;
    };
}


#endif //LINUXNETWORKPROGRAMCHENSHUO_SOCKET_H
