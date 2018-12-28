//
// Created by arturmamedov on 28.12.18.
//

#ifndef UNTITLED_SERVLET404_H
#define UNTITLED_SERVLET404_H


#include "../servlet/Servlet.h"

class Servlet404 : public  servlet::Servlet{
public:
    void doGet(std::shared_ptr<http::Request> req, std::shared_ptr<http::Response> resp) override{
        resp->setStatusCode(404);
        resp->setStarusString("Not Found");
        resp->setHeader("Content-Type","text/html");
        resp->getBody()<<"<h2>404 page not found</h2>";
    };
};


#endif //UNTITLED_SERVLET404_H
