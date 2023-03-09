//
// Created by rain on 2022/6/13.
//

#ifndef LINUXNETWORKPROGRAMCHENSHUO_TIMERQUEUE_H
#define LINUXNETWORKPROGRAMCHENSHUO_TIMERQUEUE_H
#include <boost/noncopyable.hpp>
#include<functional>
#include<memory>
#include<set>
#include"Channel.h"
#include "Callbacks.h"
#include<memory>
#include<queue>
#include"TimeStamp.h"
#include"Timer.h"
#include<atomic>
#include<map>
namespace mal{
    class EventLoop;
    class TimerQueue:boost::noncopyable_::noncopyable {
    public:
        typedef std::pair<TimeStamp,std::shared_ptr<Timer>> Entry;
        TimerQueue(EventLoop* loop);
        ~TimerQueue();

        int64_t addTimer(const TimerCallback& cb ,
                         TimeStamp when);

        int64_t addTimerRepeat(const TimerCallback& cb,TimeStamp when,double interval);

        void handleRead();
        std::vector<std::shared_ptr<Timer>> getExpired(int64_t milliTime);

        void handleReadRepeat(int timerfd,std::shared_ptr<Timer> timer);
        void cancel(int64_t sequence_);
        void cancelRepeat(int64_t sequence_);
        void update(std::shared_ptr<Timer> timer,int timerfd);

        bool insert(Timer* timer);


    private:
        void cancelRepeatLater(int64_t sequence);
        void cancelLater(int64_t sequence);
    class custom_priority_queue : public std::priority_queue<Entry ,std::vector<Entry>,std::greater<Entry>> {
    public:
        bool remove(const int64_t& sequence) {
            for(auto it = this->c.begin(); it!=this->c.end(); ++it){
                if(it->second->getSequence()==sequence){
                    this->c.erase(it);
                    return true;
                }
            }
            return false;
        }

    };
        void addTimerInLoop(Timer *timer);
        void addTimerRepeatInLoop(Timer* timer);
        int createNonBlockTimerFd();

        EventLoop* loop_;

        const int timerfd_;

        std::unique_ptr<Channel> timerfdChannel_;
        custom_priority_queue queue;
        std::map<std::shared_ptr<Timer>,std::unique_ptr<Channel>> repeatTimer_;
        std::atomic<int64_t> seuqence_;



    };
}


#endif //LINUXNETWORKPROGRAMCHENSHUO_TIMERQUEUE_H
