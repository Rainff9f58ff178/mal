//
// Created by rain on 2022/6/12.
//

#include "Poller.h"
#include<sys/poll.h>
#include"EventLoop.h"
#include"Type.h"
mal::Poller::Poller(EventLoop *loop):
    ownLoop_(loop){

}

mal::Poller::~Poller() {

}

mal::TimeStamp mal::Poller::poll(int timeoutMs,
                      mal::Poller::ChannelList *activeChannels) {
    int numEvents = ::poll(&*pollfds_.begin(),
                           pollfds_.size(),
                           timeoutMs);
    mal::TimeStamp now(mal::TimeStamp::nowMicroSecond());
    if(numEvents>0){
//        LOG_TRACE << numEvents <<" events happended";
        fillActiveChannels(numEvents,activeChannels);
    } else if(numEvents==0){
//        LOG_TRACE<<"nothing happended";
    }else{
//        LOG_SYSERR<<"Poller::poll()";
    }

    return now;
}

void mal::Poller::updateChannel(mal::Channel *channel) {
    assertInLoopThread();
//    LOG_TRACE<<"fd =" <<channel->fd() <<"events = " <<channel->events();
    if(channel->index() <0 ){
        //new one
        assert(channels_map_.find(channel->fd()) == channels_map_.end());
        struct pollfd pfd;
        pfd.fd = channel->fd();
        pfd.events=channel->events();
        pfd.revents=0;
        pollfds_.push_back(std::move(pfd));
        int idx= static_cast<int>(pollfds_.size())-1;
        channel->set_index(idx);
        channels_map_[channel->fd()]= channel;
    }else{
        //exsited already
        assert(channels_map_.find(channel->fd()) != channels_map_.end());
        assert(channels_map_[channel->fd()]==channel);
        int idx = channel->index();
        assert(idx >=0 && idx < static_cast<int>(pollfds_.size()));
        struct pollfd& pfd = pollfds_[idx];
        pfd.fd=channel->fd();
        pfd.events=static_cast<short>(channel->events());
        pfd.revents=0;
        if(channel->isNoneEvent())
            pfd.fd=-channel->fd()-1;
    }

}

void mal::Poller::assertInLoopThread() {
    ownLoop_->assertInLoopThread();
}

void mal::Poller::fillActiveChannels(int numEvents,
                                     mal::Poller::ChannelList *activeChannels) const {
    for(auto pfd_it=pollfds_.begin()
            ;pfd_it!=pollfds_.end() && numEvents>0
            ;++pfd_it){
        if(pfd_it->revents>0){
            --numEvents;
            auto ch=channels_map_.find(pfd_it->fd);
            assert(ch!=channels_map_.end());
            Channel* channel = ch->second;
            assert(channel->fd() == pfd_it->fd);
            channel->set_revents(pfd_it->revents);
            activeChannels->push_back(channel);
        }
    }
}

void mal::Poller::removeChannel(mal::Channel *channel) {
    assertInLoopThread();
    assert(channels_map_.find(channel->fd()) != channels_map_.end());
    assert(channels_map_[channel->fd()] == channel);
    assert(channel->isNoneEvent());

    int idx = channel->index();
    assert(0 <= idx && idx < static_cast<int>(pollfds_.size()));

    const struct pollfd& pfd = pollfds_[idx]; (void)pfd;
    assert(pfd.fd == -channel->fd()-1 && pfd.events == channel->events());
    size_t n = channels_map_.erase(channel->fd());
    assert(n==1);

    if (implicit_cast<size_t>(idx) == pollfds_.size()-1)
        pollfds_.pop_back();
    else
    {
        int channelAtEnd = pollfds_.back().fd;
        iter_swap(pollfds_.begin()+idx, pollfds_.end()-1);
        if (channelAtEnd < 0)
            channelAtEnd = -channelAtEnd-1;

        channels_map_[channelAtEnd]->set_index(idx);
        pollfds_.pop_back();
    }


}
