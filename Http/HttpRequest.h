//
// Created by rain on 2022/7/7.
//

#ifndef LINUXNETWORKPROGRAMCHENSHUO_HTTPREQUEST_H
#define LINUXNETWORKPROGRAMCHENSHUO_HTTPREQUEST_H

#include<string>
#include<map>
#include "TimeStamp.h"
namespace mal{
    class HttpRequest {


    public:
        enum Method{
            Invalid,
            Get,
            Post,
            Head,
            Put,
            Delete
        };
        enum Version{
            Unknown,
            Http10,
            Http11,
            Http20
        };
        HttpRequest();
        void setVersion(Version v);
        Version getVersion() const;
        bool setMethod(const char* start,const char* end);

        Method getMethod()const;
        std::string getMethodAsString()const;
        void setPath(const char* start ,const char* end);

        const std::string& getPath()const;

        void setQuery(const char* start ,const char* end);
        const std::string& getQuery(const std::string& key);
        const std::map<std::string,std::string >& getQuerys() const;
        void setReciveTime(const TimeStamp& time);
        TimeStamp getReciveTime()const;
        void addHeader(const char* start ,const char* colon,const char* end);
        std::string getHeader(const std::string& key) const;
        void setBody(const std::string& body);
        const std::map<std::string,std::string>& getHeaders()const;
        void swap(HttpRequest& that);


    private:
        Method method_;
        Version version_;

        std::string path_;

        TimeStamp reciveTime_;
        std::map<std::string ,std::string> query_;
        std::map<std::string,std::string> header_;
        std::string body;
    };
}


#endif //LINUXNETWORKPROGRAMCHENSHUO_HTTPREQUEST_H
