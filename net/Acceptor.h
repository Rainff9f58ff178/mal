//
// Created by rain on 2022/6/14.
//

#ifndef LINUXNETWORKPROGRAMCHENSHUO_ACCEPTOR_H
#define LINUXNETWORKPROGRAMCHENSHUO_ACCEPTOR_H


#include "Channel.h"
#include "Socket.h"
#include"InetAddress.h"
#include<functional>
namespace mal{



    class Acceptor {
    public:
        typedef std::function<void(int sockfd,
                const InetAddress& listenAdd)>
                newConnectionCallback;
        Acceptor(EventLoop* loop,
                 const InetAddress& listenAddr);



        void setNewConnectionCallback(const newConnectionCallback& cb);
        void listen();
    private:


        newConnectionCallback newConnectionCallback_;
        EventLoop* loop_;

        Socket acceptSocket_;
        void handleRead(io_uring& read_ring);

        Channel acceptChannel_;

        bool listening_;
    };
};


#endif //LINUXNETWORKPROGRAMCHENSHUO_ACCEPTOR_H
