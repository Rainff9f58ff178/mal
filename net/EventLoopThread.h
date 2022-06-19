//
// Created by rain on 2022/6/13.
//

#ifndef LINUXNETWORKPROGRAMCHENSHUO_EVENTLOOPTHREAD_H
#define LINUXNETWORKPROGRAMCHENSHUO_EVENTLOOPTHREAD_H

#include<condition_variable>
#include"EventLoop.h"
#include "Thread.h"
#include<string>
namespace mal{
    typedef std::function<void(EventLoop*)> ThreadInitCallback;
    class EventLoopThread {
    public:
        EventLoopThread(const ThreadInitCallback& cb,
                        const  std::string& name);

        EventLoop* start();
        void threadFunc();
    private:
        std::string name_;
        ThreadInitCallback cb_;
        EventLoop* loop_;
        Thread t_;
        std::condition_variable cv_;
        std::mutex mutex_;
    };

}

#endif //LINUXNETWORKPROGRAMCHENSHUO_EVENTLOOPTHREAD_H
