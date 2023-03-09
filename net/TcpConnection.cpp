//
// Created by rain on 2022/6/15.
//

#include "TcpConnection.h"
#include"Socket.h"
#include"Channel.h"
#include"InetAddress.h"
#include<string>
#include"EventLoop.h"
#include "SocketsOps.h"
#include "HttpContext.h"
#include"TimeStamp.h"
#include"log.h"
namespace mal{

    void TcpConnection::handleRead(io_uring& read_ring) {
        CONSOLE_INFO("handlerRead");
        int savedError=0;
        auto sqe = inputBuffer_.readFd(channel_->fd(),&savedError,read_ring);
        io_uring_sqe_set_data(sqe,this);


    }
    void TcpConnection::handleReadLater(int n){
        inputBuffer_.readFdLater(n);
        if(n>0)
            messageCallback_(shared_from_this(),&inputBuffer_,TimeStamp());
        else if(n==0)
            handleClose();
        else{
//            errno=savedError;
            CONSOLE_DEBUG(" void TcpConnection::handleReadLater(int n) error ")
//            LOG_ERROR <<"TcpConnection::handleRead";
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
                          this,std::placeholders::_1));
        channel_->setCloseCallback(std::bind(&TcpConnection::handleClose,
                                             this));
        channel_->setWriteCallback(std::bind(&TcpConnection::handleWrite,this));
        channel_->setErrorCallback(std::bind(&TcpConnection::handleError,this));
    }

    void TcpConnection::connectEstablished() {
        channel_->enableReading();
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
//                    LOG_TRACE<<"need send writing more ...";
                }
            }else{
//                LOG_SYSERR<<"TcpConnection::handleWrite()";
            }
        }else{
//            LOG_TRACE<<"connection will destory,no more writing";
        }
    }

    void TcpConnection::handleClose() {
        loop_->assertInLoopThread();
//        LOG_TRACE <<"TcpConnection::handleClose state = "<<state_;
        assert(state_==Connected || state_==Disconnecting);
        channel_->disableAll();
        closeCallback_(shared_from_this());
    }

    void TcpConnection::handleError() {
//        LOG_ERROR<<"TcpConnection::handleError ["<<name_
//                <<"] - SO_ERROR = " <<sockets::getSockErr(channel_->fd())<<" ";
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

    void TcpConnection::send(std::string &message) {
        if(state_==Connected){
            if(loop_->isInloopThread())
                sendInLoop(message.data(),message.size());
            else
                loop_->runInQueenWhileAfterHandle(std::bind(
                        &TcpConnection::sendInLoop,this,message.data(),message.size()));
        }
    }
    void TcpConnection::send(Buffer *buf) {
        if (state_ == Connected)
        {
            if (loop_->isInloopThread())
            {
                sendInLoop(buf->peek(), buf->readableBytes());
                buf->retrieveAll();
            }
            else
            {
                loop_->runInLoopImmediately(
                        std::bind(&TcpConnection::sendInLoop,
                                  this,     // FIXME
                                  buf->peek(),buf->readableBytes()));
                //std::forward<string>(message)));
            }
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

    void TcpConnection::setHttpContext(const boost::any &httpContext) {
        httpContext_=httpContext;
    }

    const boost::any &TcpConnection::getContext() const {
        return httpContext_;
    }

    boost::any* TcpConnection::getMutableContext() {
        return &httpContext_;
    }



    void TcpConnection::sendInLoop(const char *data, size_t len) {
        loop_->assertInLoopThread();
        ssize_t nwrote = 0;
        size_t remaining = len;
        bool faultError = false;
        if (state_ == Disconnected)
        {
//            LOG_WARN << "disconnected, give up writing";
            return;
        }
        // if no thing in output queue, try writing directly
        if (!channel_->isWriting() && outputBuffer_.readableBytes() == 0)
        {
            nwrote = write(channel_->fd(), data, len);
            if (nwrote >= 0)
            {
                remaining = len - nwrote;
                if (remaining == 0 && writeCompleteCallback_)
                {
                    loop_->runInQueenWhileAfterHandle(std::bind(writeCompleteCallback_, shared_from_this()));
                }
            }
            else // nwrote < 0
            {
                nwrote = 0;
                if (errno != EWOULDBLOCK)
                {
//                    LOG_SYSERR << "TcpConnection::sendInLoop";
                    if (errno == EPIPE || errno == ECONNRESET) // FIXME: any others?
                    {
                        faultError = true;
                    }
                }
            }
        }

        assert(remaining <= len);
        if (!faultError && remaining > 0)
        {
            //TODO:highWaterCallback
//            size_t oldLen = outputBuffer_.readableBytes();
//            if (oldLen + remaining >= highWaterMark_
//                && oldLen < highWaterMark_
//                && highWaterMarkCallback_)
//            {
//                loop_->queueInLoop(std::bind(highWaterMarkCallback_, shared_from_this(), oldLen + remaining));
//            }

            outputBuffer_.append(data+nwrote, remaining);
            if (!channel_->isWriting())
            {
                channel_->enableWriting();
            }
        }
    }


}