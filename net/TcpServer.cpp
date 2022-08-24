//
// Created by rain on 2022/6/15.
//

#include "TcpServer.h"
#include"EventLoop.h"
#include"muduo/base/Logging.h"
#include<iostream>
namespace mal{


    TcpServer::TcpServer(EventLoop *loop,
                         const InetAddress &addr,
                         std::string name):
        loop_(loop), acceptor_(new Acceptor(loop,addr)),
        nextConnId_(0),name_(name),
        pools_(new EventLoopThreadPool(loop,"name")){

        acceptor_->setNewConnectionCallback(
                std::bind(&TcpServer::newConnection, this,
                          std::placeholders::_1,
                          std::placeholders::_2)
                );


    }

    void TcpServer::newConnection(int sockfd, const InetAddress &addr) {
        loop_->assertInLoopThread();
        char buf[32];
        snprintf(buf,sizeof buf,"#%d",nextConnId_);
        ++nextConnId_;
        std::string connName = name_+buf;
        LOG_INFO << "TcpServer::newConnection [" << name_
                 << "] - new connection [" << connName
                 << "] from " << addr.toIpPort();

        //setMessageCallback,and call connectEstablished
        InetAddress localAddr(sockets::getLocalAddr(sockfd));

        EventLoop* ioLoop = pools_->getNextLoop();
        TcpConnectionPtr conn(new TcpConnection(ioLoop,connName,
                                                sockfd,localAddr,
                                                addr));
        connections_[connName] = conn;
        conn->setMessageCallback(onMessageCallback_);
        conn->setConnectionCallback(onConnectionCallback_);
        conn->setCloseCallback(std::bind(&TcpServer::removeConnection,
                                         this,
                                         std::placeholders::_1));
        ioLoop->runInLoopImmediately(
                std::bind(&TcpConnection::connectEstablished,conn));
    }
    void TcpServer::start() {
        acceptor_->listen();
        pools_->start(threadInitCallback_);
    }

    void TcpServer::setOnConnectionCallback_(const ConnectionCallback &cb) {
        onConnectionCallback_=cb;
    }

    void TcpServer::setOnMessageCallback(const MessageCallback &cb) {
        onMessageCallback_=cb;
    }

    void TcpServer::removeConnection(
            const TcpConnectionPtr &conn) {
        loop_->runInLoopImmediately(std::bind(&TcpServer::removeConnectionInLoop,
                                              this,conn));
    }
    void TcpServer::removeConnectionInLoop(const TcpConnectionPtr &tcpConnection) {
        loop_->assertInLoopThread();
        LOG_INFO <<"TcpServer::removeConnectionInLoop["<<name_
        <<"]-connection" <<tcpConnection->name();

        size_t n =connections_.erase(tcpConnection->name());
        assert(n==1);
        EventLoop* ioLoop=tcpConnection->getLoop();
        ioLoop->runInQueenWhileAfterHandle(std::bind(&TcpConnection::connectDestroyed,tcpConnection));
    }
    void TcpServer::setThreadNums(int n) {
        pools_->setNumThreads(n);
    }

    void TcpServer::setThreadInitCallback_(const ThreadInitCallback &cb) {
        threadInitCallback_=cb;
    }

    EventLoop* TcpServer::getLoop() {
        return loop_;
    }


}
