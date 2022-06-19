//
// Created by rain on 2022/6/14.
//

#include "InetAddress.h"
#include<string.h>
#include"SocketsOps.h"
mal::InetAddress::InetAddress(
        uint16_t port,
        bool loopbackOnly,
        bool ipv6) {
    //TODO:: not include ipv6 simulation
    memset(&addr_,0,sizeof addr_);
    addr_.sin_port = htons(port);
    addr_.sin_family=AF_INET;
    addr_.sin_addr.s_addr=INADDR_ANY;

}

mal::InetAddress::InetAddress(
        std::string ip,
        uint16_t port,
        bool ipv6) {
    //TODO::
}

mal::InetAddress::InetAddress(const mal::InetAddress &other) {
    addr_=other.addr_;
    addr6_=other.addr6_;
}

std::string mal::InetAddress::toIpPort() const{

    char buf[64];
    sockets::toIpPort(buf, sizeof buf,&addr_);

    std::string ipPort(buf);
    return ipPort;
}
