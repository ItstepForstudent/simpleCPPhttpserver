//
// Created by arturmamedov on 28.12.18.
//

#ifndef UNTITLED_SERVLET2_H
#define UNTITLED_SERVLET2_H


#include "../servlet/Servlet.h"

class Page2Servlet: public servlet::Servlet {
public:
    void doGet(std::shared_ptr<http::Request> req, std::shared_ptr<http::Response> resp) override{
        resp->getBody()<<"page 2";
    };
};


#endif //UNTITLED_SERVLET2_H
