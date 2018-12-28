//
// Created by arturmamedov on 27.12.18.
//

#ifndef UNTITLED_RESPONSE_H
#define UNTITLED_RESPONSE_H

#include <string>
#include <map>
#include <sstream>

namespace http {
    class Response {
        std::map<std::string,std::string> headers;
        std::stringstream body;
        std::string starusString = "OK";
        short statusCode = 200;
    public:
        const std::map<std::string, std::string> &getHeaders() const;

        void setHeaders(const std::map<std::string, std::string> &headers);
        void setHeader(std::string header,std::string value);

        std::stringstream  &getBody();

        const std::string &getStarusString() const;

        void setStarusString(const std::string &starusString);

        short getStatusCode() const;

        void setStatusCode(short statusCode);
    };
}


#endif //UNTITLED_RESPONSE_H
