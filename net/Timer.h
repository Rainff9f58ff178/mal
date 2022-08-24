//
// Created by rain on 2022/7/1.
//

#ifndef LINUXNETWORKPROGRAMCHENSHUO_TIMER_H
#define LINUXNETWORKPROGRAMCHENSHUO_TIMER_H
#include<chrono>
#include"Callbacks.h"
#include"TimeStamp.h"
#include<boost/operators.hpp>
namespace mal{


    class Timer: public boost::equality_comparable<Timer>,
        public boost::less_than_comparable<Timer> {
    public:
        Timer(const TimerCallback& cb ,TimeStamp& timeStamp,int64_t interval,int64_t sequence);
        TimeStamp getExpiration() const ;
        void run();
        bool isRepeat();
        const TimerCallback& getCallback();
        int64_t getInterval();
        int64_t getSequence();
        bool operator==(const Timer& other) const {
            return expiration_.getMicroSecondSinceEpoch() == other.getExpiration().getMicroSecondSinceEpoch();
        }
        bool operator<(const Timer& other) const {
            return expiration_.getMicroSecondSinceEpoch() < other.getExpiration().getMicroSecondSinceEpoch();
        }
    private:

        TimeStamp expiration_;
        int64_t interval_;
        TimerCallback cb_;
        bool isRepeat_;
        int64_t sequence_;
    };

}

#endif //LINUXNETWORKPROGRAMCHENSHUO_TIMER_H
