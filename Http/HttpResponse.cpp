//
// Created by rain on 2022/7/7.
//

#include "HttpResponse.h"
#include"Buffer.h"

namespace mal{


    HttpResponse::HttpResponse(bool close):httpStatusCode_(Unknown),closeConnection_(close) {

    }

    void HttpResponse::setStatus(HttpResponse::HttpStatusCode code) {
        httpStatusCode_=code;
    }

    void HttpResponse::setStatusMessage(const std::string &msg) {
        statuMessage_=msg;
    }

    void HttpResponse::setCloseConnection(bool close) {
        closeConnection_=close;
    }

    bool HttpResponse::closeConnection() {
        return closeConnection_;
    }

    void HttpResponse::setContenyType(const std::string &contentType) {
        headers_["Content-Type"]=contentType;
    }

    void HttpResponse::addHeader(const std::string &key, const std::string& value) {
        headers_[key]= value;
    }

    void HttpResponse::setBody(std::string &body) {
        body_=body;
    }

    void HttpResponse::appendToBuffer(Buffer *output)const {

        char buf[32];
        snprintf(buf, sizeof buf, "HTTP/1.1 %d ", httpStatusCode_);

        output->append(buf);
        output->append(statuMessage_);
        output->append("\r\n");

        if (closeConnection_)
        {
            output->append("Connection: close\r\n");
        }
        else
        {
            snprintf(buf, sizeof buf, "Content-Length: %zd\r\n", body_.size());
            output->append(buf);
            output->append("Connection: Keep-Alive\r\n");
        }

        for (const auto& header : headers_)
        {
            output->append(header.first);
            output->append(": ");
            output->append(header.second);
            output->append("\r\n");
        }

        output->append("\r\n");
        output->append(body_);
    }

    void HttpResponse::setBody(std::string &&body) {
        body_=std::move(body);
    }
}