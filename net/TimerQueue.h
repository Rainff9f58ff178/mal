//
// Created by rain on 2022/6/13.
//

#ifndef LINUXNETWORKPROGRAMCHENSHUO_TIMERQUEUE_H
#define LINUXNETWORKPROGRAMCHENSHUO_TIMERQUEUE_H
#include <boost/noncopyable.hpp>
#include<muduo/base/Timestamp.h>
#include<functional>
#include<memory>
#include<set>
#include"Channel.h"
#include "Callbacks.h"

namespace mal{
    class EventLoop;
    class TimerId;
    class Timer;
    class TimerQueue:boost::noncopyable_::noncopyable {
    public:
        TimerQueue(EventLoop* loop);
        ~TimerQueue();

        TimerId addTimer(const TimerCallback& cb ,
                         muduo::Timestamp when,
                         double interval);


        typedef
        std::pair<muduo::Timestamp,std::unique_ptr<Timer>>
        Entry;
        typedef std::set<Entry > TimerList;
        void handleRead();
        std::vector<Entry> getExpired(muduo::Timestamp now);

        void reset(const std::vector<Entry>& expired
                   ,muduo::Timestamp now);

        bool insert(Timer* timer);


    private:

        EventLoop* loop_;
        const int timerfd_;


        Channel timerfdChannel;

        TimerList timers_;

    };
}


#endif //LINUXNETWORKPROGRAMCHENSHUO_TIMERQUEUE_H
