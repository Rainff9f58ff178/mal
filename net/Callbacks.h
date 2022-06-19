//
// Created by rain on 2022/6/13.
//

#ifndef LINUXNETWORKPROGRAMCHENSHUO_CALLBACKS_H
#define LINUXNETWORKPROGRAMCHENSHUO_CALLBACKS_H

#include <functional>
#include <memory>
namespace mal{
    class TcpConnection;
    class Buffer;
    typedef std::shared_ptr<TcpConnection> TcpConnectionPtr;
    typedef std::function<void(const TcpConnectionPtr&)> ConnectionCallback;
    typedef std::function<void (const TcpConnectionPtr& ,
                                Buffer*,int)> MessageCallback;
    typedef std::function<void (const TcpConnectionPtr&)> CloseCallback;
    typedef  std::function<void()> TimerCallback;
    typedef std::function<void (const TcpConnectionPtr&)> WriteCompleteCallback;
    typedef std::function<void (const TcpConnectionPtr&)> HighWaterMarkCallback;

}
#endif //LINUXNETWORKPROGRAMCHENSHUO_CALLBACKS_H
