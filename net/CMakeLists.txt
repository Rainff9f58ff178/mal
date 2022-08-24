cmake_minimum_required(VERSION 3.22)
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

include_directories(/home/rain/muduo/build/release-install-cpp11/include)
include_directories(../base)
include_directories(../Http)
link_directories(/home/rain/muduo/build/release-install-cpp11/lib)
add_library(mal_net STATIC ${net_SRCS})
SET(LIBRARY_OUTPUT_PATH ${PROJECT_BINARY_DIR}/lib)
SET(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib)
target_link_libraries(mal_net mal_base mal_http
        libmuduo_base.a
        libmuduo_http.a
        libmuduo_inspect.a
        libmuduo_net.a)

