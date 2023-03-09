//
// Created by rain on 2022/7/6.
//

#include "HttpServer.h"
#include"HttpContext.h"
#include<iostream>
#include "MIME_map.h"
#include <regex>
#include <filesystem>
#include"log.h"
#include<fstream>
#include"TimerQueue.h"
namespace mal{


    HttpServer::HttpServer(EventLoop *loop, const InetAddress &listenAddr, const std::string& name):
    tcpServer_(loop,listenAddr,name),
    queue(loop){
        tcpServer_.setOnConnectionCallback_(std::bind(&HttpServer::onConnection,this,std::placeholders::_1));
        tcpServer_.setOnMessageCallback(std::bind(&HttpServer::onMessage,this,std::placeholders::_1,std::placeholders::_2,
                                                  std::placeholders::_3));
        httpCallbacks_[std::string("default")]=std::bind(defaultHttpCallback,std::placeholders::_1,std::placeholders::_2);
        queue.addTimerRepeat(std::bind(&HttpServer::findFile,this,"."),TimeStamp(1),600000);

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
        if(RequestStaticFile(path)){
            showRequestHeader(request);
            responseStaticFile(path,response);

        }else{
            auto it = httpCallbacks_.find(path);
            if(it!=httpCallbacks_.end()){
                std::cout<<__LINE__<<":"<<"enter custom func "<<std::endl;
                showRequestHeader(request);
                it->second(request,response);
            }else{
                showRequestHeader(request);
                std::cout<<__LINE__<<":"<<"enter default func "<<std::endl;
                defaultHttpCallback(request,response);
            }
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

    bool HttpServer::RequestStaticFile(const std::string &path) {
        //check if src folder
//        std::regex src_match("")
        std::regex regex1("\\.[a-zA-z]+$");
        auto begin = std::sregex_iterator (path.begin(),path.end(),regex1);
        auto end = std::sregex_iterator ();
        if(begin!=end){
            return true;
        }
        return false;
    }

    void HttpServer::showRequestHeader(const HttpRequest &request) {
        std::cout<<"=================================================="<<std::endl;
        std::cout<<request.getMethod()<<" "<<request.getPath() <<" "<<request.getVersion()<<std::endl;
        auto map = request.getHeaders();
        for(auto const& x:map){
            std::cout<<x.first<<":"<<x.second<<std::endl;
        }
        std::cout<<"=================================================="<<std::endl;
    }

    std::pair<std::string, std::string> HttpServer::getDirNameAndMIME(const std::string &path) {
        auto file_name =  std::find(path.rbegin(),path.rend(),'/');
        auto back_name =std::find(path.rbegin(),path.rend(),'.');

        return std::pair<std::string, std::string>(std::string(path.data(),&(*(file_name))),global_mime_map_table[std::string(&(*(back_name-1)))]);
    }

    void HttpServer::findFile(const std::string& path_name){
        try{
            for (const auto & entry : std::filesystem::directory_iterator(path_name)){
                if(entry.is_regular_file()){
                    std::string file_path (std::move(entry.path().string()),1,entry.path().string().size()-1);
                    if(std::find(file_cache_.begin(),file_cache_.end(),file_path)==file_cache_.end())
                        file_cache_.push_back(file_path);
                }else if(entry.is_directory()){
                    findFile(entry.path().string());
                }
            }
        }catch(std::filesystem::filesystem_error const& ex){
            CONSOLE_ERROR( ex.path1().c_str());
        }
    }
    void HttpServer::responseStaticFile(std::string& path, HttpResponse& response) {
        //request file
        CONSOLE_INFO("requesting a static file");
        std::pair<std::string,std::string> pair = std::move(getDirNameAndMIME(path));
        std::string dir_name=pair.first;
        std::string MIME=std::move(pair.second);
        if(std::find(file_cache_.begin(),file_cache_.end(),path)==file_cache_.end()){
            CONSOLE_DEBUG("not find request file");
            std::stringstream s;
            s<<"no such things\n";
            response.setBody(s.str());
            response.setStatus(HttpResponse::NotFound404);
            return;
        }

        if(std::find(file_cache_.begin(),file_cache_.end(),path)!=file_cache_.end()){
            CONSOLE_INFO("returning file\n");
            std::fstream file;
            file.open(std::string(".")+path);
            std::string line;
            std::string body;
            if(file.is_open()){
                while(getline(file,line)){
                    body.append(line+"\n");
                }
                response.setBody(std::move(body));
            }
            response.setContenyType(global_mime_map_table[MIME]);
            response.setStatus(HttpResponse::ok200);
            response.setStatusMessage("OK");
            response.addHeader("Server","MAL");
        }else{
            std::stringstream s;
            s<<"no such things\n";
            response.setBody(s.str());
        }

    }

    void defaultHttpCallback(const HttpRequest &request, HttpResponse &response) {
        response.setStatus(HttpResponse::ok200);
        response.setStatusMessage("OK");
        response.setContenyType("text/html");
        response.addHeader("Server","MAL");
        response.setBody("nice to see you");
    }


}