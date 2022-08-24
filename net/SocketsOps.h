//
// Created by rain on 2022/6/15.
//

#ifndef LINUXNETWORKPROGRAMCHENSHUO_SOCKETSOPS_H
#define LINUXNETWORKPROGRAMCHENSHUO_SOCKETSOPS_H


#include <cstdio>
#include<netinet/in.h>
namespace mal{
    namespace sockets{
        int createNonBlockSocket(sa_family_t family);
        int connect(int sockfd,const sockaddr* addr);
        struct sockaddr_in getLocalAddr(int sockfd);

        void toIpPort(char* buf, size_t size,
                               const struct sockaddr_in* addr);
        void toIp(char* buf, size_t size,
                           const struct sockaddr_in* addr);

        inline uint16_t networkToHost16(in_port_t port);
        int getSockErr(int sockfd);
        void shutdownWrite(int sockfd);
        const struct sockaddr* sockaddr_cast(const struct sockaddr_in* addr);
        const struct sockaddr* sockaddr_cast(const struct sockaddr_in6* addr);
        struct sockaddr* sockaddr_cast(struct sockaddr_in6* addr);
        const struct sockaddr_in* sockaddr_in_cast(const struct sockaddr* addr);
        const struct sockaddr_in6* sockaddr_in6_cast(const struct sockaddr* addr);

    }
}


#endif //LINUXNETWORKPROGRAMCHENSHUO_SOCKETSOPS_H
