//
// Created by rain on 2022/7/6.
//

#include "Epoller.h"
#include "Type.h"
namespace mal{
    const int NEW = -1;
    const int ADDED = 1;

    Epoller::Epoller(EventLoop *loop):loop_(loop),
    epollfd_(::epoll_create1(EPOLL_CLOEXEC)),events_(InitEventListSize) {

    }

    Epoller::~Epoller() {

    }

    TimeStamp Epoller::poll(int timeoutMs, Epoller::ChannelList *activeChannels) {
        int numEvents =::epoll_wait(epollfd_,&*events_.begin(),static_cast<int>(events_.size()),timeoutMs);
        if(numEvents > 0){
//            LOG_TRACE <<  numEvents << "events happended";
            fillActiveChannels(numEvents,activeChannels);
            if(implicit_cast<size_t>(numEvents)==events_.size() && events_.size()<INT16_MAX);
            if(events_.size()*2<=INT16_MAX){
                events_.resize(events_.size()*2);
            }else{
                events_.resize(INT16_MAX);
            }
        }
        return TimeStamp(0);
    }

    void Epoller::fillActiveChannels(int numEvents, Epoller::ChannelList *activeChannels) const {
        assert(implicit_cast<size_t>(numEvents) <= events_.size());
        for(int i=0 ; i< numEvents; ++i){
            Channel* channel = static_cast<Channel*>(events_[i].data.ptr);
            int fd = channel->fd();
            ChannelMap::const_iterator it = channels_.find(fd);
            assert(it!=channels_.end());
            assert(it->second == channel);
            channel->set_revents(events_[i].events);
            activeChannels->push_back(channel);
        }
    }

    void Epoller::updateChannel(Channel *channel) {
        assertInLoopThread();
        if(channel->index()<0){
            //create new one
            struct epoll_event event;
            bzero(&event,sizeof event);
            channel->set_index(ADDED);
            channels_[channel->fd()]=channel;
            update(EPOLL_CTL_ADD,channel);
        }else{
            //update (index > 0);
            assert(channel == channels_[channel->fd()]);
            assert(channels_.find(channel->fd())!=channels_.end());
            channel->set_revents(0);
            update(EPOLL_CTL_MOD,channel);
        }

    }

    void Epoller::update(int operation, Channel *channel) {

        epoll_event e;
        e.events=channel->events();
        e.data.ptr=channel;
        if(epoll_ctl(epollfd_,operation,channel->fd(),&e) < 0){
//            LOG_FATAL<<" void Epoller::update(int operation, Channel *channel) fali ";
        }
    }
    void Epoller::assertInLoopThread() {
        loop_->assertInLoopThread();
    }

    void Epoller::removeChannel(Channel *channel) {
        size_t n =channels_.erase(channel->fd());
        assert(n==1);
        if(channel->index()==ADDED)
            update(EPOLL_CTL_DEL,channel);
        channel->set_index(NEW);
    }

}