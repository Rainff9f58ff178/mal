//
// Created by rain on 2022/6/11.
//

#include "EventLoop.h"
#include <muduo/base/Logging.h>
#include<assert.h>
#include "Poller.h"
#include"Epoller.h"
namespace mal{
    const int kPollTimeMs = 10;
    __thread EventLoop* t_loopInThisThread=0;
    EventLoop::EventLoop()
        :looping_(false),
        threadId__(std::this_thread::get_id()),
        poller_(new Epoller(this)),
        callingPendingFunctor_(false){
        LOG_TRACE<<"EventLoop create" <<this<<"in thread";
        if(t_loopInThisThread){
            LOG_FATAL<<"Another EventLoop"<<t_loopInThisThread
                    <<"exists in this thread";
        }else{
            t_loopInThisThread=this;
        }
    }
    EventLoop::~EventLoop() {
        assert(!looping_);
        t_loopInThisThread= nullptr;
    }

    void EventLoop::loop() {
        assert(!looping_);
        assertInLoopThread();
        looping_= true;
        quit_= false;

        while (!quit_){
            activeChannels_.clear();
            TimeStamp timestamp=
                    poller_->poll(kPollTimeMs,&activeChannels_);

            eventHanding_= true;
            for (auto it=activeChannels_.begin()
                    ;  it!=activeChannels_.end()
                    ; ++it )
                (*it)->handleEvent();
            eventHanding_= false;
            callPendingFunction();
        }
        LOG_TRACE<<"EventLoop " <<this<<" stop looping ";
        looping_= false;

    }


    bool EventLoop::isIsLooping() const {
        return looping_;
    }



    void EventLoop::abortNotInLoopThread() {

        LOG_FATAL<<"EVENTLOOP OBJECT NOT IN LOOP THREAD";
        std::exit(1);
    }

    void EventLoop::assertInLoopThread() {
        if(!isInloopThread()){
            abortNotInLoopThread();
        }
    }

    EventLoop *EventLoop::getEventLoopOfCurrentThread() {
        return t_loopInThisThread;
    }

    void EventLoop::updateChannel(Channel *channel) {

        assert(this == channel->ownLoop());
        assertInLoopThread();
        poller_->updateChannel(channel);
    }

    void EventLoop::quit() {
        quit_= true;
    }

    void EventLoop::remvoeChannel(Channel *channel) {
        assert(this == channel->ownLoop());
        assertInLoopThread();
        poller_->removeChannel(channel);
    }

    void EventLoop::runInLoopImmediately(const EventLoop::Functor &cb) {
        if(isInloopThread())
            cb();
        else
            runInQueenWhileAfterHandle(cb);
    }

    void EventLoop::runInQueenWhileAfterHandle(
            const EventLoop::Functor &cb) {
        std::unique_lock<std::mutex> lock(mutex_);
        pendingFunctors_.push_back(cb);
    }

    void EventLoop::callPendingFunction() {
        std::vector<Functor > functors;
        callingPendingFunctor_= true;

        //for quicker
        std::unique_lock<std::mutex> lock(mutex_);
        functors.swap(pendingFunctors_);
        lock.unlock();
        //for quicker

        for(auto it =functors.begin(); it!=functors.end(); ++it){
            (*it)();
        }
        callingPendingFunctor_= false;
    }

}
