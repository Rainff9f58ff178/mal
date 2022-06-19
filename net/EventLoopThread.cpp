//
// Created by rain on 2022/6/13.
//

#include "EventLoopThread.h"


mal::EventLoopThread::EventLoopThread(
        const mal::ThreadInitCallback &cb,
        const std::string &name):
        cb_(cb),
        t_(std::bind(&EventLoopThread::threadFunc,this),name),
        name_(name),
        loop_(nullptr){

}

mal::EventLoop* mal::EventLoopThread::start() {
    std::unique_lock<std::mutex> lock(mutex_);
    t_.start();
    while (loop_== nullptr){
        cv_.wait(lock);
    }
    return loop_;
}

void mal::EventLoopThread::threadFunc() {
    EventLoop loop;
    loop_=&loop;
    if(cb_)
        cb_(&loop);
    cv_.notify_one();


    loop.loop();
}
