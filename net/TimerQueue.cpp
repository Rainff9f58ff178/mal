


#include"TimerQueue.h"
#include<sys/timerfd.h>

#include<muduo/base/Logging.h>
#include"Channel.h"
#include"EventLoop.h"
#include<memory>
#include <iostream>
namespace mal{

    TimerQueue::TimerQueue(EventLoop *loop) :loop_(loop),timerfd_(createNonBlockTimerFd()), timerfdChannel_(new Channel(loop,timerfd_))
    ,seuqence_(0){
        timerfdChannel_->setReadCallback(std::bind(&TimerQueue::handleRead,this));
        timerfdChannel_->enableReading();
    }

    TimerQueue::~TimerQueue() {

    }

    int64_t TimerQueue::addTimer(const TimerCallback &cb, TimeStamp when) {
        Timer* timer = new Timer(cb,when,0,seuqence_++);
        loop_->runInLoopImmediately(
                std::bind(&TimerQueue::addTimerInLoop, this,timer));
        return  seuqence_;
    }
    int64_t TimerQueue::addTimerRepeat(const TimerCallback &cb, TimeStamp when, double interval) {
        Timer* timer = new Timer(cb,when,interval,seuqence_++);
        loop_->runInLoopImmediately(
                std::bind(&TimerQueue::addTimerRepeatInLoop,this,timer));
        return 0;
    }
    void TimerQueue::addTimerRepeatInLoop(Timer *timer) {
        loop_->assertInLoopThread();
        int timerfd = timerfd_create(CLOCK_MONOTONIC,TFD_NONBLOCK | TFD_CLOEXEC);
        std::shared_ptr<Timer> timer_p (timer);
        update(timer_p,timerfd);
        std::unique_ptr<Channel> channel (new Channel(loop_,timerfd));
        channel->setReadCallback(
                std::bind(&TimerQueue::handleReadRepeat,this,timerfd,timer_p)
                );
        channel->enableReading();
        repeatTimer_[std::move(timer_p)] = std::move(channel);
    }
    void TimerQueue::addTimerInLoop(Timer *timer) {
        loop_->assertInLoopThread();
        bool queueChanged=insert(timer);
        if(queueChanged) {

            std::shared_ptr<Timer> timer = queue.top().second;
            update(timer,timerfd_);
        }
    }

    void TimerQueue::handleRead() {
//        std::cout<<"this is handleRead"<<std::endl;
        char buf[16];
        read(timerfd_,buf,sizeof buf);
        cancelRepeat(1);
        std::vector<std::shared_ptr<Timer>> v = getExpired(TimeStamp::nowMilli());
        //TODO:maybe it cloud be youhua ?
//        std::cout<<"v.size() : "<<v.size()<<std::endl;
        for(auto it =v.begin(); it !=v.end(); ++it )
            (*it)->run();

        if(!queue.empty()){
            std::shared_ptr<Timer> timer = queue.top().second;
            update(timer,timerfd_);
        }

    }

    void TimerQueue::handleReadRepeat(int timerfd,std::shared_ptr<Timer> timer) {
//        std::cout<<"this is handleReadRepeat"<<std::endl;
        char buf[16];
        read(timerfd,buf,sizeof buf);
        timer->run();
    }

    std::vector<std::shared_ptr<Timer>> TimerQueue::getExpired(int64_t milliTime) {
        std::vector<std::shared_ptr<Timer>> timer_v;
        while(queue.top().first.getMillionSecond() <= milliTime ){

            timer_v.push_back(std::move(queue.top().second));
            queue.pop();
            if(queue.empty())
                break;
        }
        return timer_v;
    }

    bool TimerQueue::insert(Timer *timer) {
        queue.push(std::make_pair(timer->getExpiration(),std::unique_ptr<Timer>(timer)));
        return true;
    }

    int TimerQueue::createNonBlockTimerFd() {
        int  fd=timerfd_create(CLOCK_MONOTONIC,TFD_CLOEXEC |TFD_NONBLOCK);
        if(fd < 0){
            LOG_SYSFATAL << " TimerQueue::createNonBlockTimerFd() fail ";
        }
        return fd;
    }

    void TimerQueue::update(std::shared_ptr<Timer> timer, int timerfd) {
        TimeStamp stamp=timer->getExpiration();
        itimerspec newValue;
        itimerspec oldValue;
        bzero(&newValue,sizeof newValue);
        bzero(&oldValue,sizeof oldValue);
        newValue.it_value.tv_sec=(stamp.getMillionSecond()-TimeStamp::nowMilli()) /1000;;
        newValue.it_value.tv_nsec= ((stamp.getMillionSecond()-TimeStamp::nowMilli()) % 1000) *1000000;;
        if(timer->getInterval()!=0){
            newValue.it_interval.tv_sec=(stamp.getMillionSecond()-TimeStamp::nowMilli()) /1000;
            newValue.it_interval.tv_nsec=((stamp.getMillionSecond()-TimeStamp::nowMilli()) % 1000) *1000000;;
        }
        timerfd_settime(timerfd,0,&newValue,&oldValue);
    }

    void TimerQueue::cancel(int64_t sequence) {
        loop_->runInQueenWhileAfterHandle(std::bind(&TimerQueue::cancelLater,this,sequence));
    }

    void TimerQueue::cancelRepeat(int64_t sequence) {

        loop_->runInQueenWhileAfterHandle(
                std::bind(&TimerQueue::cancelRepeatLater,this,sequence)
                );
    }

    void TimerQueue::cancelRepeatLater(int64_t sequence) {

        for(auto it = repeatTimer_.begin(); it!=repeatTimer_.end(); ++it){
            if(it->first->getSequence() == sequence){
                it->second->disableAll();
                it->second->remove();
                repeatTimer_.erase(it);
                return;
            }
        }
    }

    void TimerQueue::cancelLater(int64_t sequence) {
        queue.remove(sequence);
    }


}