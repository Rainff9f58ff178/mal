//
// Created by rain on 2022/6/11.
//
#pragma once

#include<boost/noncopyable.hpp>
#include<boost/scoped_ptr.hpp>
#include<thread>
#include<vector>
#include"Channel.h"
#include "Poller.h"
#include<memory>
#include<mutex>
#include<liburing.h>
namespace mal{
    /*
         * one loop per thread 顾名思义就是每个线程只能有一个EventLoop对象 ，因此EventLoop的构造函数会检查当前线程是否已经创建了其他EventLoop对象
         * 遇到错误就终止程序
         * 创建了EventLoop对象的线程就是IO线程，其主要功能是运行事件循环EventLoop：：loop（）
         * 他不必是heap对象
         * */
    class Poller;
    class Epoller;
    class Channel;
    class EventLoop :boost::noncopyable {
    public:
        typedef std::function<void()> Functor;
        EventLoop();
        ~EventLoop();

        bool isIsLooping() const;
        void loop();
        void assertInLoopThread();
        bool isInloopThread() const{
            return threadId__ == std::this_thread::get_id();
        }

        /// Runs callback immediately in the loop thread.
        /// It wakes up the loop, and run the cb.
        /// If in the same loop thread, cb is run within the function.
        /// Safe to call from other threads.
        void runInLoopImmediately(const Functor& cb);
        void runInQueenWhileAfterHandle(const Functor& cb);
        void remvoeChannel(Channel* channel);
        void updateChannel(Channel* channel);
        void quit();
        static EventLoop* getEventLoopOfCurrentThread();




        struct ::io_uring read_ring_;
        const int IO_URING_QUEUE_ENTRY_NUM;
    private:
        void abortNotInLoopThread();
        void callPendingFunction();
    private:


        typedef std::vector<Channel*> ChannelList;
        std::vector<Functor> pendingFunctors_;
        bool callingPendingFunctor_;
        bool looping_;
        bool quit_;
        const std::thread::id threadId__;
        bool eventHanding_;
        boost::scoped_ptr<Epoller> poller_;
        ChannelList activeChannels_;


        std::mutex mutex_;

    }; //class EventLoop

    extern  __thread EventLoop* t_loopInThisThread;

} //namespace mal;


