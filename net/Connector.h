//
// Created by rain on 2022/6/29.
//

#ifndef LINUXNETWORKPROGRAMCHENSHUO_CONNECTOR_H
#define LINUXNETWORKPROGRAMCHENSHUO_CONNECTOR_H

#include<boost/noncopyable.hpp>
#include<functional>
#include "InetAddress.h"
#include<memory>
namespace mal{
    class EventLoop;
    class InetAddress;
    class Channel;
    class Connector:boost::noncopyable {

    public:
        typedef std::function<void (int)> NewConnectionCallback;
        Connector(EventLoop* loop,
                  const InetAddress& serverAddr);
        ~Connector();
        void setNewConnectionCallback(
                const NewConnectionCallback& cb);
        void start();
        void restart();
        void stop();
    private:
        void connect();
        void startInLoop();

        static const int kMaxRetryDelayMs = 30*1000;
        static const int kInitRetryDelayMs = 500;

        enum State{Disconnected,Connecting,Connected};
        NewConnectionCallback newConnectionCallback_;

        EventLoop* loop_;
        InetAddress serverAddr_;

        std::unique_ptr<Channel> channel_;

        State state_;
        bool connect_;
        int relayMs_;

    };


}

#endif //LINUXNETWORKPROGRAMCHENSHUO_CONNECTOR_H
