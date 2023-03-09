//
// Created by rain on 23-2-28.
//
#include <iostream>
#include "log.h"
#include <Acceptor.h>
#include "EventLoop.h"
#include "HttpServer.h"
#include "InetAddress.h"
#include <functional>
#include<HttpRequest.h>
#include<HttpResponse.h>
using namespace std;
using namespace mal;
void testFunc(const HttpRequest& request,HttpResponse& response){
    response.setStatus(HttpResponse::ok200);
    response.setStatusMessage("OK");
    response.setContenyType("text/html");
    response.addHeader("Server","MAL");
    response.setBody("defaultHttpCallback");
}
void http_server(){
    using namespace mal;
    EventLoop loop;
    HttpServer server(&loop,InetAddress(8080),"myBlog");
    server.setThreadNum(15);
    server.bindService("/test",std::bind(&testFunc,std::placeholders::_1,std::placeholders::_2));
    server.start();
    loop.loop();
}
void func(){

    cout<<"func() "<<TimeStamp::nowSecond()<<endl;
}
int main(){
    http_server();
    return 0;
}