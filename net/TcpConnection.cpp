//
// Created by rain on 2022/6/15.
//

#include "TcpConnection.h"
#include"Socket.h"
#include"Channel.h"
#include"InetAddress.h"
#include<string>
#include"EventLoop.h"
#include<muduo/base/Logging.h>
#include "SocketsOps.h"
namespace mal{

    void TcpConnection::handleRead() {
        int savedError=0;
        ssize_t  n = inputBuffer_.readFd(channel_->fd(),&savedError);
        if(n>0)
            messageCallback_(shared_from_this(),&inputBuffer_,n);
        else if(n==0)
            handleClose();
        else{
            errno=savedError;
            LOG_ERROR <<"TcpConnection::handleRead";
            handleError();
        }
    }

    void TcpConnection::setConnectionCallback(ConnectionCallback &cb) {
        connectionCallback_=cb;
    }

    void TcpConnection::setMessageCallback(MessageCallback &cb) {
        messageCallback_=cb;
    }

    TcpConnection::TcpConnection(EventLoop *loop,
                                 std::string name,
                                 int sockfd,
                                 const InetAddress& localAddr,
                                 const InetAddress& peerAddr):
                                 loop_(loop),
                                 name_(name),
                                 socket_(new Socket(sockfd)),
                                 localAddr_(localAddr),
                                 peerAddr_(peerAddr),
                                 channel_(new Channel(loop,sockfd)),
                                 state_(Connecting){
        channel_->setReadCallback(
                std::bind(&TcpConnection::handleRead,
                          this));
        channel_->setCloseCallback(std::bind(&TcpConnection::handleClose,
                                             this));
        channel_->setWriteCallback(std::bind(&TcpConnection::handleWrite,this));
        channel_->setErrorCallback(std::bind(&TcpConnection::handleError,this));
    }

    void TcpConnection::connectEstablished() {
        channel_->enableReading();
        //TODO:neek enableFunc ? not sure need enableWriting ,
        // muduo doesn't enable
        state_=Connected;
        connectionCallback_(shared_from_this());
    }
    void TcpConnection::setCloseCallback(const CloseCallback &cb) {
        closeCallback_=cb;
    }

    void TcpConnection::connectDestroyed() {
        loop_->assertInLoopThread();
        if(state_==Connected){
            setState(Disconnected);
            channel_->disableAll();
            connectionCallback_(shared_from_this());
        }
        channel_->remove();
    }
    /*
     * this function send surplus data.
     * */
    void TcpConnection::handleWrite() {
        loop_->assertInLoopThread();
        if(channel_->isWriting()){
            ssize_t n = ::write(channel_->fd(),outputBuffer_.peek(),
                                outputBuffer_.readableBytes());
            if(n >0){
                outputBuffer_.retrieve(n);
                if(outputBuffer_.readableBytes()==0){
                    channel_->disableWriting();
                    if(writeCompleteCallback_)
                        loop_->runInQueenWhileAfterHandle(
                                std::bind(writeCompleteCallback_,
                                          shared_from_this()));
                    if(state_=Disconnecting)
                        shutdownInLoop();
                }else{
                    LOG_TRACE<<"need send writing more ...";
                }
            }else{
                LOG_SYSERR<<"TcpConnection::handleWrite()";
            }
        }else{
            LOG_TRACE<<"connection will destory,no more writing";
        }
    }

    void TcpConnection::handleClose() {
        loop_->assertInLoopThread();
        LOG_TRACE <<"TcpConnection::handleClose state = "<<state_;
        assert(state_==Connected || state_==Disconnecting);
        channel_->disableAll();
        closeCallback_(shared_from_this());
    }

    void TcpConnection::handleError() {
        LOG_ERROR<<"TcpConnection::handleError ["<<name_
                <<"] - SO_ERROR = " <<sockets::getSockErr(channel_->fd())<<" ";
    }

    TcpConnection::~TcpConnection() {

    }

    void TcpConnection::shutdown() {
        if(state_==Connected){
            setState(Disconnecting);
            loop_->runInLoopImmediately(std::bind(&TcpConnection::shutdownInLoop,
                                                  this));
        }

    }

    void TcpConnection::shutdownInLoop() {
        loop_->assertInLoopThread();
        if(!channel_->isWriting())
            socket_->shutdownWrite();
    }

    void TcpConnection::send(std::string &message, size_t len) {
        if(state_==Connected){
            if(loop_->isInloopThread())
                sendInLoop(message);
            else
                loop_->runInQueenWhileAfterHandle(std::bind(
                        &TcpConnection::sendInLoop,
                        this,
                        message));
        }
    }

    void TcpConnection::sendInLoop(std::string &message) {
        loop_->assertInLoopThread();
        /*
         * we must wait channel_ doesn't monitoring
         * kWriteevnt and outputBuffer.raedableBytes==0
         * to ensure data is ordered.
         * */
        ssize_t nwrote=0;
        if(!channel_->isWriting() && outputBuffer_.readableBytes()==0){
            nwrote = ::write(channel_->fd(),message.data(),message.size());
            if(nwrote >=0 ){
                if(muduo::implicit_cast<size_t>(nwrote) < message.size())
                    LOG_TRACE <<" need write more data";
                else if (writeCompleteCallback_)
                    writeCompleteCallback_(shared_from_this());
            }else{
                nwrote=0;
                LOG_SYSERR<<"TcpConnection::sendInLoop";
            }
        }
        assert(nwrote > 0);
        if(muduo::implicit_cast<size_t>(nwrote) < message.size()){
            outputBuffer_.append(message.data()+nwrote,
                                 message.size()-nwrote);
            if(!channel_->isWriting())
                channel_->enableWriting();
        }
    }

    void TcpConnection::setTcpNoDelay(bool on) {
        socket_->setTcoNoDelay(on);
    }

    void TcpConnection::setWriteCompleteCallback(WriteCompleteCallback &cb) {
        writeCompleteCallback_=cb;
    }

    void TcpConnection::setHighWaterMarkCallback(HighWaterMarkCallback &cb) {
        highWaterMarkCallback_=cb;
    }


}