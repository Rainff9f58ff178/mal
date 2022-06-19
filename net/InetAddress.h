//
// Created by rain on 2022/6/14.
//

#ifndef LINUXNETWORKPROGRAMCHENSHUO_INETADDRESS_H
#define LINUXNETWORKPROGRAMCHENSHUO_INETADDRESS_H

#include<netinet/in.h>
#include<string>
#include"SocketsOps.h"
namespace mal{

    class InetAddress {
    public:
        explicit InetAddress(uint16_t port = 0,
                             bool loopbackOnly = false,
                             bool ipv6 = false);


        InetAddress(std::string ip, uint16_t port, bool ipv6 = false);

        std::string toIpPort() const;

        explicit InetAddress(const struct sockaddr_in& addr)
                : addr_(addr)
        { }

        explicit InetAddress(const struct sockaddr_in6& addr)
                : addr6_(addr)
        { }
        void setAddr(const struct sockaddr_in& addr){
            addr_=addr;
        }
        InetAddress(const InetAddress& other);
        sockaddr_in& addr(){return addr_;}
        sockaddr_in getAddr()const {return addr_;}
        const struct sockaddr* getSockAddr() const { return sockets::sockaddr_cast(&addr6_); }
    private:
        struct sockaddr_in addr_;
        struct sockaddr_in6 addr6_;
    };

}



#endif //LINUXNETWORKPROGRAMCHENSHUO_INETADDRESS_H
