#include "Request.h"

const std::string &http::Request::getBody() const {
    return body;
}

void http::Request::setBody(const std::string &body) {
    Request::body = body;
}

void http::Request::addHeader(std::string name, std::string value) {
    headers[name]= std::move(value);
}

std::string http::Request::getHeader(std::string name) const{
    return headers.at(name);
}

const std::map<std::string, std::string> &http::Request::getHeaders() const {
    return headers;
}

const std::string &http::Request::getMethod() const {
    return method;
}

void http::Request::setMethod(const std::string &method) {
    Request::method = method;
}

const std::string &http::Request::getRequestUri() const {
    return requestUri;
}

void http::Request::setRequestUri(const std::string &requestUri) {
    Request::requestUri = requestUri;
}
