//
// Created by rain on 2022/6/15.
//

#include "SocketsOps.h"
#include <arpa/inet.h>
#include <unistd.h>
#include<stdio.h>
#include <cstring>
#include<boost/implicit_cast.hpp>
#include<cassert>
#include<muduo/base/Logging.h>

namespace mal{

    const struct sockaddr* sockets::sockaddr_cast(const struct sockaddr_in6* addr)
    {
        return static_cast<const struct sockaddr*>(boost::implicit_cast<const void*>(addr));
    }

    struct sockaddr* sockets::sockaddr_cast(struct sockaddr_in6* addr)
    {
        return static_cast<struct sockaddr*>(boost::implicit_cast<void*>(addr));
    }

    const struct sockaddr* sockets::sockaddr_cast(const struct sockaddr_in* addr)
    {
        return static_cast<const struct sockaddr*>(boost::implicit_cast<const void*>(addr));
    }

    const struct sockaddr_in* sockets::sockaddr_in_cast(const struct sockaddr* addr)
    {
        return static_cast<const struct sockaddr_in*>(boost::implicit_cast<const void*>(addr));
    }

    const struct sockaddr_in6* sockets::sockaddr_in6_cast(const struct sockaddr* addr)
    {
        return static_cast<const struct sockaddr_in6*>(boost::implicit_cast<const void*>(addr));
    }


    void sockets::toIpPort(char* buf, size_t size,
                           const struct sockaddr_in* addr) {
        toIp(buf, size, addr);
        size_t end = ::strlen(buf);
        uint16_t port = sockets::networkToHost16(addr->sin_port);
        assert(size > end);
        snprintf(buf+end, size-end, ":%u", port);
    }
    void sockets::toIp(char *buf, size_t size,
                       const struct sockaddr_in *addr) {
        ::inet_ntop(AF_INET,
                    &addr->sin_addr,
                    buf,
                    static_cast<socklen_t>(size));
    }




    inline uint16_t sockets::networkToHost16(in_port_t port) {
        return be16toh(port);
    }

    struct sockaddr_in sockets::getLocalAddr(int sockfd) {
        {
            struct sockaddr_in localaddr;
            memset(&localaddr,0, sizeof localaddr);
            socklen_t addrlen =
                    static_cast<socklen_t>(sizeof localaddr);
            if (::getsockname(sockfd,
                              (sockaddr*)&localaddr,
                              &addrlen) < 0){
                LOG_SYSERR << "sockets::getLocalAddr";
            }
            return localaddr;
        }
    }

    int sockets::getSockErr(int sockfd) {
        int optval;
        socklen_t optlen =
                static_cast<socklen_t >(sizeof(optval));
        if(::getsockopt(sockfd,
                        SOL_SOCKET,
                        SO_ERROR,
                        &optval, &optlen) <0)
            return errno;
        else
            return optval;
    }

    void sockets::shutdownWrite(int sockfd) {
        if(::shutdown(sockfd,SHUT_WR) < 0){
            LOG_SYSERR << "sockets::shutdownWrite(int sockfd)";
        }
    }

    int sockets::createNonBlockSocket(sa_family_t family) {
        int sock= socket(AF_INET,
                         SOCK_STREAM |SOCK_NONBLOCK,
                         IPPROTO_TCP);
        if (sock < 0)
            LOG_SYSFATAL << "CreateNonBlockSocket";
        return sock;
    }

}//namespace mal




