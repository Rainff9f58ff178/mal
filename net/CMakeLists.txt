cmake_minimum_required(VERSION 3.20)
set(net_SRCS
        EventLoop.cpp
         Channel.cpp
         Poller.cpp
         TimerQueue.cpp
         EventLoopThread.cpp
        InetAddress.cpp
        Acceptor.cpp
        Socket.cpp
        TcpServer.cpp
        TcpConnection.cpp
        SocketsOps.cpp
        Buffer.cpp
        IgnoreSigpipe.cpp
        EventLoopThreadPool.cpp
        Connector.cpp
        Timer.cpp
        Epoller.cpp
)
include_directories(../base)
include_directories(../Http)
add_library(mal_net STATIC ${net_SRCS})
SET(LIBRARY_OUTPUT_PATH ${PROJECT_BINARY_DIR}/lib)
SET(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib)
target_link_libraries(mal_net mal_base mal_http)

