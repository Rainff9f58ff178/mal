//
// Created by rain on 2022/6/12.
//

#ifndef LINUXNETWORKPROGRAMCHENSHUO_POLLER_H
#define LINUXNETWORKPROGRAMCHENSHUO_POLLER_H

#include<sys/poll.h>
#include"Channel.h"
#include<boost/noncopyable.hpp>
#include<chrono>
#include<map>
#include<muduo/base/Timestamp.h>
namespace mal{

    class Channel;

    class Poller:boost::noncopyable {
    public:
        typedef std::vector<Channel*> ChannelList;
        Poller(EventLoop* loop);
        ~Poller();
        muduo::Timestamp poll(
                int timeoutMs,
                ChannelList* activeChannels);
        void updateChannel(Channel* channel);

        void assertInLoopThread();

        void removeChannel(Channel* channel);
    private:
        void fillActiveChannels(int numEvents,
                                ChannelList* activeChannels) const;

        typedef std::vector<struct pollfd> PollFdList;
        typedef std::map<int,Channel*> ChannelMap;

        EventLoop* ownLoop_;
        PollFdList pollfds_;
        ChannelMap channels_map_;
    };

}
#endif //LINUXNETWORKPROGRAMCHENSHUO_POLLER_H


