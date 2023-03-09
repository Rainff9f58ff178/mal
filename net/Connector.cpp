//
// Created by rain on 2022/6/29.
//

#include "Connector.h"
#include"EventLoop.h"
#include"Channel.h"
#include"InetAddress.h"
namespace mal{

    Connector::Connector(EventLoop *loop,
                         const InetAddress &serverAddr):
                         loop_(loop),
                         serverAddr_(serverAddr),
                         state_(Disconnected),
                         relayMs_(kInitRetryDelayMs){

    }

    Connector::~Connector() {

    }

    void Connector::setNewConnectionCallback(
            const Connector::NewConnectionCallback &cb) {
        newConnectionCallback_=cb;
    }
    void Connector::restart() {

    }

    void Connector::stop() {

    }
    void Connector::start()
    {
        connect_ = true;
        loop_->runInLoopImmediately(std::bind(&Connector::startInLoop, this)); // FIXME: unsafe
    }

    void Connector::startInLoop()
    {
        loop_->assertInLoopThread();
        assert(state_ == Disconnected);
        if (connect_)
        {
            connect();
        }
        else
        {
//            LOG_DEBUG << "do not connect";
        }
    }

    void Connector::connect()
    {
        int sockfd =sockets::createNonBlockSocket(serverAddr_.family());
        int ret = sockets::connect(sockfd,serverAddr_.addr());
        int savedErrno = (ret == 0) ? 0 : errno;
        switch (savedErrno)
        {
            case 0:
            case EINPROGRESS:
            case EINTR:
            case EISCONN:
//                TODO:connecting(sockfd);
                break;

            case EAGAIN:
            case EADDRINUSE:
            case EADDRNOTAVAIL:
            case ECONNREFUSED:
            case ENETUNREACH:
//TODO:                retry(sockfd);
                break;

            case EACCES:
            case EPERM:
            case EAFNOSUPPORT:
            case EALREADY:
            case EBADF:
            case EFAULT:
            case ENOTSOCK:
//                LOG_SYSERR << "connect error in Connector::startInLoop " << savedErrno;
                close(sockfd);
                break;

            default:
//                LOG_SYSERR << "Unexpected error in Connector::startInLoop " << savedErrno;
                close(sockfd);
                // connectErrorCallback_();
                break;
        }
    }
}