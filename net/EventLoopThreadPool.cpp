//
// Created by rain on 2022/6/18.
//

#include "EventLoopThreadPool.h"

namespace mal{

    EventLoopThreadPool::EventLoopThreadPool(EventLoop *loop,
                                             const std::string& name):
        baseLoop_(loop),numThreads_(0),
        name_(name),next_(0){

    }

    EventLoopThreadPool::~EventLoopThreadPool() {

    }

    void EventLoopThreadPool::setNumThreads(int n) {
        numThreads_=n;
    }
    void EventLoopThreadPool::start(const ThreadInitCallback& cb) {
        baseLoop_->assertInLoopThread();
        for(int n=0;n<numThreads_;++n){
            char buf[name_.size() + 32];
            snprintf(buf, sizeof buf, "%s%d", name_.c_str(), n);
            EventLoopThread* p=new EventLoopThread(cb,buf);
            threads_.push_back(std::unique_ptr<EventLoopThread>(p));
            loops_.push_back(p->start());
        }
        if(numThreads_==0){
            cb(baseLoop_);
        }
    }

    EventLoop *EventLoopThreadPool::getNextLoop() {
        baseLoop_->assertInLoopThread();
        EventLoop* loop = baseLoop_;
        if(!loops_.empty()){
            loop  = loops_[next_];
            ++next_;
            if(muduo::implicit_cast<size_t>(next_) >= loops_.size())
                next_=0;
        }
        return loop;
    }
}