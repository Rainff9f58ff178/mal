//
// Created by rain on 2022/6/18.
//

#ifndef LINUXNETWORKPROGRAMCHENSHUO_EVENTLOOPTHREADPOOL_H
#define LINUXNETWORKPROGRAMCHENSHUO_EVENTLOOPTHREADPOOL_H
#include <vector>
#include<boost/ptr_container/ptr_vector.hpp>
#include"EventLoopThread.h"
namespace mal{
    class EventLoopThreadPool {
    public:
        EventLoopThreadPool(EventLoop* loop,
                            const std::string& name);
        ~EventLoopThreadPool();

        void setNumThreads(int n);
        void start(const ThreadInitCallback& cb);
        EventLoop* getNextLoop();
    private:
        EventLoop* baseLoop_;
        boost::ptr_vector<EventLoopThread> threads_;
        std::vector<EventLoop*> loops_;
        std::string name_;
        int numThreads_;
        int next_;

    };

}

#endif //LINUXNETWORKPROGRAMCHENSHUO_EVENTLOOPTHREADPOOL_H
