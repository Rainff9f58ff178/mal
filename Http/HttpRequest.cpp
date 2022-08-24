//
// Created by rain on 2022/7/7.
//

#include "HttpRequest.h"

#include<algorithm>
namespace mal{


    HttpRequest::HttpRequest():method_(Invalid),version_(Unknown){

    }

    void HttpRequest::setVersion(Version v) {
        version_=v;
    }

    HttpRequest::Version HttpRequest::getVersion() const {
        return version_;
    }

    bool HttpRequest::setMethod(const char *start, const char *end) {

        std::string m(start,end);
        if(m=="GET")
            method_=Get;
        else if (m=="POST")
            method_=Post;
        else if (m=="HEAD")
            method_==Head;
        else if (m=="PUT")
            method_=Put;
        else if (m=="DELETE")
            method_=Delete;
        else
            method_=Invalid;
        return method_!=Invalid;
    }

    HttpRequest::Method HttpRequest::getMethod() const {
        return method_;
    }
    std::string HttpRequest::getMethodAsString() const {
        const char* result="UNKNOWN";
        switch (method_) {
            case Get:
                result="GET";
                break;
            case Post:
                result="POST";
                break;
            case Put:
                result="PUT";
                break;
            case Head:
                result="HEAD";
                break;
            case Delete:
                result="DELETE";
                break;
            default:
                break;
        }
        return result;
    }
    void HttpRequest::setPath(const char *start, const char *end) {
        path_.assign(start,end);
    }

    const std::string &HttpRequest::getPath() const {
        return path_;
    }

    void HttpRequest::setQuery(const char *start, const char *end) {
        //[start,end);  eample:name=rain&key=123123&account=2213;
        const char* begin = start;
        const char* last = end;
        const char* and_position= nullptr;
        const char* equal_position= nullptr;
        while ( (and_position=std::find(begin,last,'&'))  && and_position!=last ) {
            equal_position=std::find(begin,and_position,'=');
            query_[std::string(begin,equal_position)]=std::string(equal_position+1,and_position);
            begin=and_position+1;
        }
        equal_position=std::find(begin,end,'=');
        query_[std::string(begin,equal_position)]=std::string(equal_position+1,last);

    }

    const std::string& HttpRequest::getQuery(const std::string &key) {
        return query_[key];
    }

    const std::map<std::string, std::string>& HttpRequest::getQuerys() const {
        return query_;
    }

    void HttpRequest::setReciveTime(const TimeStamp &time) {
        reciveTime_=time;
    }

    TimeStamp HttpRequest::getReciveTime() const {
        return reciveTime_;
    }

    void HttpRequest::addHeader(const char *start, const char *colon, const char *end) {
        //example: Connection:keep-alive
        std::string key(start,colon);
        ++colon;
        while(std::isspace(*colon) && colon < end){
            ++colon;
        }
        std::string value(colon,end);
        while (!value.empty() && isspace(value[value.size()-1]))
        {
            value.resize(value.size()-1);
        }
        header_[std::move(key)]=std::move(value);
    }

    std::string HttpRequest::getHeader(const std::string &key)const{
        std::map<std::string,std::string>::const_iterator it = header_.find(key);
        std::string r;
        if(it!=header_.end()){
            r=it->second;
        }
        return r;
    }

    const std::map<std::string, std::string> &HttpRequest::getHeaders() const {
        return header_;
    }

    void HttpRequest::swap(HttpRequest &that) {
        std::swap(that.method_,method_);
        std::swap(that.version_,version_);
        header_.swap(that.header_);
        path_.swap(that.path_);
        query_.swap(that.query_);
        reciveTime_.swap(that.reciveTime_);
    }


}