//
// Created by arturmamedov on 27.12.18.
//

#include "Response.h"

const std::map<std::string, std::string> &http::Response::getHeaders() const {
    return headers;
}

void http::Response::setHeaders(const std::map<std::string, std::string> &headers) {
    Response::headers = headers;
}

std::stringstream &http::Response::getBody() {
    return body;
}


const std::string &http::Response::getStarusString() const {
    return starusString;
}

void http::Response::setStarusString(const std::string &starusString) {
    Response::starusString = starusString;
}

short http::Response::getStatusCode() const {
    return statusCode;
}

void http::Response::setStatusCode(short statusCode) {
    Response::statusCode = statusCode;
}

void http::Response::setHeader(std::string header, std::string value) {
    headers[header]=value;
}
