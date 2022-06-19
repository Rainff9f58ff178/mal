//
// Created by rain on 2022/6/14.
//

#include "Socket.h"
#include<unistd.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<iostream>
#include <sys/types.h>
#include <netinet/tcp.h>
mal::Socket::Socket(int fd):
    fd_(fd){

}

mal::Socket::~Socket() {
    close(fd_);
}

void mal::Socket::bindAddresss(mal::InetAddress addr){
    bind(fd_,(sockaddr*)&addr.addr(),sizeof(sockaddr));
}

void mal::Socket::listen() {
    ::listen(fd_,300);
}

int mal::Socket::accept(mal::InetAddress& addr) {
    struct sockaddr_in client_addr;
    socklen_t len = sizeof client_addr;
    int peerfd = ::accept(fd_,(sockaddr*)&client_addr,&len);
    addr.setAddr(client_addr);
    return peerfd;
}

void mal::Socket::shutdownWrite() {
    sockets::shutdownWrite(fd_);
}

void mal::Socket::setTcoNoDelay(bool on) {
    int optval=on ? 1:0;
    ::setsockopt(fd_,IPPROTO_TCP,TCP_NODELAY,&optval,sizeof optval);
}

int mal::sockets::createNonBlockOrDie() {
    int sockfd = socket(AF_INET,
                        SOCK_STREAM | SOCK_NONBLOCK | SOCK_CLOEXEC,
                        IPPROTO_TCP);
    if(sockfd<0)
        std::cout<<"int mal::sockets::createNonBlockOrDie() fali,"
                   <<"sockfd < 0";
    return sockfd;
}
