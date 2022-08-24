//
// Created by rain on 2022/7/1.
//
#include "TimeStamp.h"
#include<iostream>
#include<chrono>
#include<muduo/base/Logging.h>
mal::TimeStamp::TimeStamp(const int64_t &time){

    std::chrono::time_point<std::chrono::system_clock> now =std::chrono::system_clock::now();
    std::chrono::duration<double> since = now.time_since_epoch();
    microSecond_= std::chrono::duration_cast<std::chrono::microseconds>(since).count()+(time*1000);


}



int64_t mal::TimeStamp::getMicroSecondSinceEpoch() const  {
    return microSecond_;
}


bool mal::TimeStamp::operator==(const mal::TimeStamp &other) const {
    return other.microSecond_==microSecond_;
}

bool mal::TimeStamp::operator<(const mal::TimeStamp &other)const {
    return microSecond_<other.microSecond_;
}

int64_t mal::TimeStamp::getSecondSinceEpoch() const {
    return microSecond_/1000000;
}

int64_t mal::TimeStamp::nowMilli() {
    std::chrono::time_point<std::chrono::system_clock> now =std::chrono::system_clock::now();
    std::chrono::duration<double> since = now.time_since_epoch();
    return  std::chrono::duration_cast<std::chrono::milliseconds>(since).count();;
}

int64_t mal::TimeStamp::nowSecond() {
    std::chrono::time_point<std::chrono::system_clock> now =std::chrono::system_clock::now();
    std::chrono::duration<double> since = now.time_since_epoch();
    return  std::chrono::duration_cast<std::chrono::seconds>(since).count();
}

int64_t mal::TimeStamp::nowNanoSecond() {
    std::chrono::time_point<std::chrono::system_clock> now =std::chrono::system_clock::now();
    std::chrono::duration<double> since = now.time_since_epoch();
    return std::chrono::duration_cast<std::chrono::nanoseconds>(since).count();
}

int64_t mal::TimeStamp::nowMicroSecond() {
    std::chrono::time_point<std::chrono::system_clock> now =std::chrono::system_clock::now();
    std::chrono::duration<double> since = now.time_since_epoch();
    return std::chrono::duration_cast<std::chrono::microseconds>(since).count();
}

int64_t mal::TimeStamp::getMillionSecond() const {
    return microSecond_/1000;
}

mal::TimeStamp::TimeStamp() {
    std::chrono::time_point<std::chrono::system_clock> now =std::chrono::system_clock::now();
    std::chrono::duration<double> since=now.time_since_epoch();
    microSecond_=std::chrono::duration_cast<std::chrono::microseconds>(since).count();;
}

void mal::TimeStamp::swap(mal::TimeStamp &that) {
    std::swap(microSecond_,that.microSecond_);
}
