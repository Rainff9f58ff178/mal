//
// Created by rain on 2022/6/18.
//

#include "Thread.h"

mal::Thread::Thread(const mal::ThreadFunc &cb,
                    std::string name):
                    threadFunc_(cb),
                    name_(name){

}

void mal::Thread::start() {
    t_=std::move(std::jthread(threadFunc_));
}

auto mal::Thread::get_id() {
    return t_.get_id();
}
