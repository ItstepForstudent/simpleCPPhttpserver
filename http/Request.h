#ifndef UNTITLED_REQUEST_H
#define UNTITLED_REQUEST_H

#include <map>
#include <string>

namespace http{
    class Request {
        std::map<std::string,std::string> headers;
        std::string body="";
        std::string method;
        std::string requestUri;
    public:
        const std::string &getRequestUri() const;

        void setRequestUri(const std::string &requestUri);

    public:
        const std::string &getMethod() const;

        void setMethod(const std::string &method);

    public:
        void addHeader(std::string name,std::string value);
        std::string getHeader(std::string name) const;

        const std::string &getBody() const;

        void setBody(const std::string &body);

        const std::map<std::string, std::string> &getHeaders() const;
    };
}



#endif //UNTITLED_REQUEST_H
