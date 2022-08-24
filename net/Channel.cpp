//
// Created by rain on 2022/6/12.
//

#include "Channel.h"
#include<sys/poll.h>
#include<muduo/base/Logging.h>
#include"EventLoop.h"
namespace mal{
    const int Channel::kNoneEvent = 0;
    const int Channel::kReadEvent = POLLIN | POLLPRI;
    const int Channel::kWriteEvent = POLLOUT;
    Channel::Channel(EventLoop *loop, int fd):
        fd_(fd),
        loop_(loop),
        events_(0),
        revents_(0),
        index_(-1),
        eventHanding_(false){

    }

    void Channel::handleEvent() {
        eventHanding_=true;
        if(revents_ & POLLNVAL)
            LOG_WARN <<"Channel::handleEvent() POLLNVAL";
        if(revents_ & (POLLERR | POLLNVAL))
            if(errorCallback_) errorCallback_();
        if(revents_ & (POLLNVAL | POLLIN | POLLRDHUP))
            if(readCallback_) readCallback_();
        if(revents_ & POLLOUT)
            if(writeCallback_) writeCallback_();

        eventHanding_= false;
    }

    void Channel::setReadCallback(const Channel::EventCallback &cb) {
            readCallback_=cb;
    }

    void Channel::setWriteCallback(const Channel::EventCallback &cb) {
        writeCallback_=cb;
    }

    void Channel::setErrorCallback(const Channel::EventCallback &cb) {
        errorCallback_=cb;
    }

    int Channel::fd() const {

        return fd_;
    }

    int Channel::events() const {
        return events_;
    }

    void Channel::set_revents(int revt) {
        revents_=revt;
    }

    bool Channel::isNoneEvent() const {
        return events_==kNoneEvent;
    }

    void Channel::enableReading() {
        events_ |=kReadEvent;
        update();
    }

    int Channel::index() {
        return index_;
    }

    void Channel::set_index(int idx) {
        index_=idx;
    }

    EventLoop *Channel::ownLoop() {
        return loop_;
    }

    void Channel::update() {
        loop_->updateChannel(this);
    }

    Channel::~Channel() {
        assert(!eventHanding_);
    }

    void Channel::setCloseCallback(const Channel::EventCallback &cb) {
        closeCallback_=cb;
    }

    void Channel::remove() {
        loop_->remvoeChannel(this);
    }

    void Channel::enableWriting() {
        events_ |=kWriteEvent;
        update();
    }

    void Channel::disableWriting() {
        events_ &=~kWriteEvent;
        update();
    }

    void Channel::disableReading() {
        events_ &=~kReadEvent;
        update();
    }
}