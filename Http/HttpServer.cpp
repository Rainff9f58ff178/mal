//
// Created by rain on 2022/7/6.
//

#include "HttpServer.h"
#include"HttpContext.h"
#include<iostream>
namespace mal{


    HttpServer::HttpServer(EventLoop *loop, const InetAddress &listenAddr, const std::string& name): tcpServer_(loop,listenAddr,name) {
        tcpServer_.setOnConnectionCallback_(std::bind(&HttpServer::onConnection,this,std::placeholders::_1));
        tcpServer_.setOnMessageCallback(std::bind(&HttpServer::onMessage,this,std::placeholders::_1,std::placeholders::_2,
                                                  std::placeholders::_3));
        httpCallbacks_[std::string("default")]=std::bind(defaultHttpCallback,std::placeholders::_1,std::placeholders::_2);
    }

    HttpServer::~HttpServer() {

    }

    void HttpServer::start() {
        tcpServer_.start();
    }

    void HttpServer::setThreadNum(int num) {
        tcpServer_.setThreadNums(num);
    }

    EventLoop *HttpServer::getLoop() {
        return tcpServer_.getLoop();
    }

    void HttpServer::setHttpCallback(const std::string &path,const HttpCallback& cb) {
        httpCallbacks_[path]=cb;
    }

    void HttpServer::onConnection(const TcpConnectionPtr& conn) {
        if(conn->connected()){
            conn->setHttpContext(HttpContext());
        }
    }

    void HttpServer::onMessage(const TcpConnectionPtr &conn, Buffer *buffer, TimeStamp timeStamp) {

        HttpContext* context=boost::any_cast<HttpContext>(conn->getMutableContext());
        if(!context->parseRequest(buffer,timeStamp)){
            std::string s ("HTTP/1.1 400 Bad Request\r\n\r\n");
            conn->send(s);   //失败，发送400
            conn->shutdown();
        }

        if(context->getState()== HttpContext::GotAll){
            //解析完成
            onRequest(conn,context->getHttpRequest());
            context->reset();
        }

    }

    void HttpServer::onRequest(const TcpConnectionPtr &conn, const HttpRequest &request) {
        const std::string& connection=request.getHeader("Connection");
        bool close = connection == "close" ||
                     (request.getVersion() == HttpRequest::Http10 && connection != "Keep-Alive");
        HttpResponse response(close);

       std::string path = request.getPath();
        std::cout<<__LINE__<<":"<<"path:"<<path<<" "<<std::endl;
        auto it = httpCallbacks_.find(path);
        if(it!=httpCallbacks_.end()){
            std::cout<<__LINE__<<":"<<"enter custom func "<<std::endl;
            it->second(request,response);
        }else{
            std::cout<<__LINE__<<":"<<"enter default func "<<std::endl;
            defaultHttpCallback(request,response);
        }
        Buffer buf;
        response.appendToBuffer(&buf);
        conn->send(&buf);
        if (response.closeConnection())  //如果关闭
        {
            conn->shutdown();  //关了它
        }

    }

    void HttpServer::setThreadInitCallback(const ThreadInitCallback &cb) {
        tcpServer_.setThreadInitCallback_(cb);
    }

    void HttpServer::bindService(const std::string& path,const HttpServer::HttpCallback &httpCallback) {
        httpCallbacks_.insert(std::make_pair(path,httpCallback));
    }

    void defaultHttpCallback(const HttpRequest &request, HttpResponse &response) {
        response.setStatus(HttpResponse::ok200);
        response.setStatusMessage("OK");
        response.setContenyType("text/html");
        response.addHeader("Server","MAL");
        response.setBody("defaultHttpCallback");
    }


}