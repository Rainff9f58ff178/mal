//
// Created by rain on 2022/6/12.
//

#ifndef LINUXNETWORKPROGRAMCHENSHUO_CHANNEL_H
#define LINUXNETWORKPROGRAMCHENSHUO_CHANNEL_H


#include <boost/noncopyable.hpp>
#include<functional>
#include"EventLoop.h"
#include<liburing.h>
namespace mal{
    class EventLoop;
    class Channel:boost::noncopyable {
        /*
         * 每个Channel自始至终只负责一个fd的IO事件分发
         *
         *
         * This class doesn't own the file descriptor
         * The file descriptor could be a socket,
         * eventfd,a timerfd,signalfd
         * */
    public:
        typedef std::function<void()> EventCallback;
        typedef std::function<void(::io_uring& read_ring)> ReadEventCallback;
        Channel(EventLoop* loop,int fd);
        ~Channel();
        void handleEvent();
        void setReadCallback(const ReadEventCallback & cb);
        void setWriteCallback(const EventCallback& cb);
        void setErrorCallback(const EventCallback& cb);
        void setCloseCallback(const EventCallback& cb);
        int fd()const;
        int events() const;
        void set_revents(int revt);
        void remove();
        bool isNoneEvent()const;
        bool isWriting(){return events_ & kWriteEvent;}
        bool isReading(){return events_ & kReadEvent;}
        void enableReading();
        void disableReading();
        void enableWriting();
        void disableWriting();
        void disableAll() { events_ = kNoneEvent; update(); }
        int index();

        void set_index(int idx);
        EventLoop* ownLoop();

    private:
        void update();


        static const int kNoneEvent;
        static const int kReadEvent;
        static const int kWriteEvent;
        EventLoop* loop_;
        const int fd_;
        int events_; //interested event
        int revents_;//current active event
        int index_;

        bool eventHanding_;
        ReadEventCallback readCallback_;
        EventCallback writeCallback_;
        EventCallback errorCallback_;
        EventCallback closeCallback_;
    };
}

#endif //LINUXNETWORKPROGRAMCHENSHUO_CHANNEL_H
