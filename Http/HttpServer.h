//
// Created by rain on 2022/7/6.
//

#ifndef LINUXNETWORKPROGRAMCHENSHUO_HTTPSERVER_H
#define LINUXNETWORKPROGRAMCHENSHUO_HTTPSERVER_H
#include "TcpServer.h"
#include"HttpRequest.h"
#include"HttpResponse.h"
namespace mal{
    void defaultHttpCallback(const HttpRequest& request,HttpResponse& response);
    class HttpServer{
    public:
        typedef std::function<void(const HttpRequest&,HttpResponse&)> HttpCallback;
        HttpServer(EventLoop* loop,const InetAddress& listenAddr,const std::string& name);
        ~HttpServer();
        void start();
        void setThreadNum(int num);
        void bindService(const std::string& path,const HttpCallback& httpCallback);
        EventLoop* getLoop();
        void setHttpCallback(const std::string& path,const HttpCallback& cb);
        void setThreadInitCallback(const ThreadInitCallback& cb);


    private:
        void onConnection(const TcpConnectionPtr& conn);
        void onMessage(const TcpConnectionPtr& conn,Buffer* buffer,TimeStamp timeStamp);
        void onRequest(const TcpConnectionPtr& conn,const HttpRequest& request);
        TcpServer tcpServer_;

        std::map<std::string ,HttpCallback > httpCallbacks_;

    };
}

#endif //LINUXNETWORKPROGRAMCHENSHUO_HTTPSERVER_H
