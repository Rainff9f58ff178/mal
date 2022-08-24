//
// Created by rain on 2022/7/6.
//

#ifndef LINUXNETWORKPROGRAMCHENSHUO_EPOLLER_H
#define LINUXNETWORKPROGRAMCHENSHUO_EPOLLER_H
#include"EventLoop.h"
#include"Channel.h"
#include<sys/epoll.h>
#include "TimeStamp.h"
namespace mal{
    class Epoller {
    public:
        typedef std::vector<Channel*> ChannelList;
        Epoller(EventLoop* loop);
        ~Epoller();

        TimeStamp poll(int timeoutMs,ChannelList* activeChannels);
        void fillActiveChannels(int numEvents,ChannelList* activeChannels) const;
        void updateChannel(Channel* channel);

        void assertInLoopThread();

        void removeChannel(Channel* channel);
    private:
        static const int InitEventListSize = 256;
        void update(int operation,Channel* channel);
        typedef std::vector<struct epoll_event> EventList;
        typedef std::map<int,Channel*> ChannelMap;

        EventLoop* loop_;
        int epollfd_;
        EventList events_;
        ChannelMap channels_;

    };
}


#endif //LINUXNETWORKPROGRAMCHENSHUO_EPOLLER_H
