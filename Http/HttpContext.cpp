//
// Created by rain on 2022/7/6.
//

#include "HttpContext.h"

#include"Buffer.h"
#include<cassert>
#include<algorithm>
#include"log.h"
namespace mal{

    HttpContext::HttpContext():state_(parsingRequestLine) {

    }

    HttpContext::~HttpContext() {

    }

    void HttpContext::reset() {
        state_=parsingRequestLine;
        HttpRequest dummy;
        request_.swap(dummy);
    }

    bool HttpContext::parseRequestLine(const char *start, const char *end) {
        //example :GET /book/index HTTP/1.1
        const char* begin = start;
        const char* last = end;
        const char* space= std::find(start,end,' ');

        if(space!=end)
            request_.setMethod(begin,space);
        else
            return false;
        begin=space +1;
        space = std::find(begin,end,' ');
        if(space!=end){
            const char* qz_position = std::find(begin,end,'?');
            if(qz_position!=end){
                request_.setQuery(qz_position+1,space);
                request_.setPath(begin,qz_position);
            }
            request_.setPath(begin,space);
        }else
            return false;
        const char* last_backsplash = std::find(space+1,end,'/');
        if(last_backsplash!=end){
            std::string s(last_backsplash+1,end);
            if(s=="1.1")
                request_.setVersion(HttpRequest::Http11);
            if(s=="1.0")
                request_.setVersion(HttpRequest::Http10);
            if(s=="2.0")
                request_.setVersion(HttpRequest::Http20);
        }else
            return false;

        return true;
    }

    const HttpRequest &HttpContext::getHttpRequest() const {
        return request_;
    }

    HttpRequest &HttpContext::getHttpRequest() {
        return request_;
    }

    bool HttpContext::gotAll() {
        return state_==GotAll;
    }

    bool HttpContext::parseRequest(Buffer *buffer, TimeStamp reciveTime) {
        //TODO:
        assert(buffer!= nullptr);
        bool hasMore = true;
        bool ok=true;
        while(hasMore){
            if(state_==parsingRequestLine){
                const char* crlf = buffer->findCRLF();
                if(crlf){
                    //crlf pointer to \r
                    ok=parseRequestLine(buffer->peek(),crlf);
                    if(ok){
                        request_.setReciveTime(reciveTime);
                        buffer->retrieveUntil(crlf+2);
                        state_=parsingRequestHeaders;
                    }
                }else{
                    hasMore= false;
                }

            }
            else if(state_==parsingRequestHeaders){
                const char* crlf = buffer->findCRLF();
                if(crlf){
                    const char* colon = std::find(buffer->peek(),crlf,':');
                    if(colon!=crlf){
                        request_.addHeader(buffer->peek(),colon,crlf);
                    }else{
                        state_=parsingRequestBody;
                    }
                    buffer->retrieveUntil(crlf+2);
                }else{
                    hasMore= false;
                }
            }
            else if(state_==parsingRequestBody){
                std::string len_s=request_.getHeader("Content-Length");
                if(!len_s.empty()){
                    int len=std::stoi(len_s);
                    if(static_cast<int>(buffer->readableBytes()) >= len){
                        std::string body=buffer->retrieveAsString(len);
                        CONSOLE_INFO("BODY:");
                        CONSOLE_INFO(body.data());
                        state_=GotAll;
                    }else
                        hasMore= false;
                }else{
                    state_=GotAll;
                    hasMore= false;
                }
            }
        }
        return ok;
    }

    HttpContext::HttpRequestParseState HttpContext::getState() {
        return state_;
    }
}