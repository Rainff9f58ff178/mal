//
// Created by rain on 2022/6/14.
//

#include "Acceptor.h"
#include "EventLoop.h"

mal::Acceptor::Acceptor(mal::EventLoop *loop,
                        const mal::InetAddress &listenAddr):
                        loop_(loop),
                        acceptSocket_(sockets::createNonBlockOrDie()),
                        acceptChannel_(loop,acceptSocket_.fd()),
                        listening_(false){
    acceptSocket_.bindAddresss(listenAddr);
    acceptChannel_.setReadCallback(std::bind(&Acceptor::handleRead,this));
}

void mal::Acceptor::setNewConnectionCallback(
        const mal::Acceptor::newConnectionCallback &cb) {
    newConnectionCallback_ = cb;
}

void mal::Acceptor::handleRead() {
    loop_->assertInLoopThread();
    InetAddress peerAddr(0);

    int peerfd = acceptSocket_.accept(peerAddr);

    if(peerfd > 0){
        if(newConnectionCallback_) newConnectionCallback_(peerfd,peerAddr);
        else close(peerfd);
    }
}

void mal::Acceptor::listen() {
    loop_->assertInLoopThread();
    acceptSocket_.listen();
    listening_= true;
    acceptChannel_.enableReading();
}
