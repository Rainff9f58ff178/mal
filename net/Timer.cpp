//
// Created by rain on 2022/7/1.
//

#include "Timer.h"

mal::Timer::Timer(const mal::TimerCallback &cb, mal::TimeStamp &timeStamp, int64_t interval,int64_t sequence)
    :cb_(cb), expiration_(timeStamp),interval_(interval),isRepeat_(interval>0),sequence_(sequence){

}

mal::TimeStamp mal::Timer::getExpiration() const  {
    return expiration_;
}

bool mal::Timer::isRepeat() {
    return isRepeat_;
}

int64_t mal::Timer::getInterval() {
    return interval_;
}

void mal::Timer::run() {
    cb_();
}

const mal::TimerCallback &mal::Timer::getCallback() {
    return cb_;
}

int64_t mal::Timer::getSequence() {
    return sequence_;
}
