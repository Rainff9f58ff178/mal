//
// Created by rain on 2022/7/6.
//

#ifndef LINUXNETWORKPROGRAMCHENSHUO_HTTPCONTEXT_H
#define LINUXNETWORKPROGRAMCHENSHUO_HTTPCONTEXT_H
#include"HttpRequest.h"
namespace mal{
    class Buffer;
    class HttpContext {
    public:
        enum HttpRequestParseState{
            parsingRequestLine,
            parsingRequestHeaders,
            parsingRequestBody,
            GotAll
        };
        HttpContext();
        ~HttpContext();
        void reset();
        bool parseRequestLine(const char* start,const char *end);
        const HttpRequest& getHttpRequest()const;
        HttpRequest& getHttpRequest();
        bool gotAll();
        bool parseRequest(Buffer* buffer,TimeStamp reciveTime);
        HttpRequestParseState getState();
    private:
        HttpRequestParseState state_;
        HttpRequest request_;

    };

}

#endif //LINUXNETWORKPROGRAMCHENSHUO_HTTPCONTEXT_H
