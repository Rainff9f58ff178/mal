//
// Created by rain on 2022/6/15.
//

#ifndef LINUXNETWORKPROGRAMCHENSHUO_TCPSERVER_H
#define LINUXNETWORKPROGRAMCHENSHUO_TCPSERVER_H

#include "Acceptor.h"
#include<map>
#include "TcpConnection.h"
#include"Callbacks.h"
#include"EventLoopThreadPool.h"
namespace mal{


    class TcpServer {

    public:
        TcpServer(EventLoop* loop,const InetAddress& addr,std::string name);

        void start();
        void setOnConnectionCallback_(const ConnectionCallback& cb);
        void setOnMessageCallback(const MessageCallback& cb);
        void setThreadInitCallback_(const ThreadInitCallback& cb);
        EventLoop* getLoop();
        void setThreadNums(int n);
    private:
        typedef std::map<std::string,TcpConnectionPtr > ConnectionMap;
        void newConnection(int fd,const InetAddress& addr);
        void removeConnection(const TcpConnectionPtr& tcpConnection);
        void removeConnectionInLoop(const TcpConnectionPtr& tcpConnection);

        ConnectionCallback onConnectionCallback_;
        MessageCallback  onMessageCallback_;
        ThreadInitCallback threadInitCallback_;
        std::unique_ptr<EventLoopThreadPool> pools_;

        ConnectionMap connections_;
        bool started_;
        const std::string name_;

        std::unique_ptr<Acceptor> acceptor_;
        int nextConnId_;
        EventLoop* loop_;
        std::mutex mutex_;
    };
}


#endif //LINUXNETWORKPROGRAMCHENSHUO_TCPSERVER_H
