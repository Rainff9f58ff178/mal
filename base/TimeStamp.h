//
// Created by rain on 2022/7/1.
//

#ifndef LINUXNETWORKPROGRAMCHENSHUO_TIMESTAMP_H
#define LINUXNETWORKPROGRAMCHENSHUO_TIMESTAMP_H
#include<stdint.h>
#include<boost/operators.hpp>
namespace mal{

class TimeStamp:public boost::less_than_comparable<TimeStamp>,
                public boost::equality_comparable<TimeStamp> {
public:
    TimeStamp(const int64_t& time);
    TimeStamp();
    int64_t getMicroSecondSinceEpoch() const  ;
    int64_t getSecondSinceEpoch()const ;
    int64_t getMillionSecond()const;
    void swap(TimeStamp& that);
    bool operator==(const TimeStamp& other) const ;
    bool operator<(const TimeStamp& other) const;
    static int64_t nowMilli();
    static int64_t nowSecond();
    static int64_t nowNanoSecond();
    static int64_t nowMicroSecond();
private:
    int64_t microSecond_;
};


}
#endif //LINUXNETWORKPROGRAMCHENSHUO_TIMESTAMP_H
