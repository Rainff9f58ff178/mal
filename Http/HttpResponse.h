//
// Created by rain on 2022/7/7.
//

#ifndef LINUXNETWORKPROGRAMCHENSHUO_HTTPRESPONSE_H
#define LINUXNETWORKPROGRAMCHENSHUO_HTTPRESPONSE_H
#include<map>
#include<string>

namespace mal{

    class Buffer;
    class HttpResponse {
    public:
        enum HttpStatusCode{
            Unknown,
            ok200=200,
            movePermanently301=301,
            BadRquest400=400,
            NotFound404=404
        };
        explicit HttpResponse(bool  close);
        void setStatus(HttpStatusCode code);
        void setStatusMessage(const std::string& msg);
        void setCloseConnection(bool close);
        bool closeConnection();
        void setContenyType(const std::string& contentType);
        void addHeader(const std::string& key,const std::string& value);
        void setBody(std::string& body);
        void setBody(std::string&& body);
        void appendToBuffer(Buffer* output)const;

    private:
        bool closeConnection_;
        std::map<std::string ,std::string > headers_;
        HttpStatusCode httpStatusCode_;
        std::string statuMessage_;
        std::string body_;

    };

}

#endif //LINUXNETWORKPROGRAMCHENSHUO_HTTPRESPONSE_H
