//
// Created by rain on 2022/6/15.
//

#ifndef LINUXNETWORKPROGRAMCHENSHUO_TCPCONNECTION_H
#define LINUXNETWORKPROGRAMCHENSHUO_TCPCONNECTION_H
#include <memory>
#include<boost/noncopyable.hpp>
#include<boost/enable_shared_from_this.hpp>
#include<memory>
#include"InetAddress.h"
#include"Callbacks.h"
#include "Buffer.h"
#include<boost/any.hpp>
namespace mal{
    class Socket;
    class Channel;
    class EventLoop;
    class HttpContext;
    class TcpConnection: boost::noncopyable,
            public std::enable_shared_from_this<TcpConnection> {
    public:
        TcpConnection(EventLoop* loop,
                      std::string name,
                      int sockfd,
                      const InetAddress& localAddr,
                      const InetAddress& peerAddr);

        ~TcpConnection();
        void setConnectionCallback(ConnectionCallback& cb);
        void setMessageCallback(MessageCallback& cb);
        void setCloseCallback(const CloseCallback& cb);
        void setWriteCompleteCallback(WriteCompleteCallback& cb);
        void setHighWaterMarkCallback(HighWaterMarkCallback& cb);
        void setHttpContext(const boost::any& httpContext);
        const boost::any& getContext() const;
        boost::any* getMutableContext();


        void connectEstablished();
        void connectDestroyed();
        void handleRead();
        void handleWrite();
        void handleClose();
        void handleError();
        std::string name(){ return name_;}


        void setTcpNoDelay(bool on);
        void send(std::string& message);
        void send(Buffer* buf);
        void shutdown();
        bool connected(){return  state_ == Connected;}
        EventLoop* getLoop(){return loop_;}
    private:
        void shutdownInLoop();
        void sendInLoop(const char* data,size_t len);

    private:

        EventLoop* loop_;
        std::string name_;
        enum StateE { Connecting,Connected,Disconnected,Disconnecting };
        void setState(StateE state){state_ =state; }
        StateE state_;

        std::unique_ptr<Socket> socket_;
        std::unique_ptr<Channel> channel_;


        boost::any httpContext_;

        InetAddress localAddr_;
        InetAddress peerAddr_;
        Buffer inputBuffer_;
        Buffer outputBuffer_;
        MessageCallback messageCallback_;
        ConnectionCallback connectionCallback_; //call once
        CloseCallback closeCallback_; //call once
        HighWaterMarkCallback highWaterMarkCallback_;
        WriteCompleteCallback writeCompleteCallback_;

    };
    typedef std::shared_ptr<TcpConnection> TcpConnectionPtr;
}


#endif //LINUXNETWORKPROGRAMCHENSHUO_TCPCONNECTION_H
