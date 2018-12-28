//
// Created by arturmamedov on 28.12.18.
//

#ifndef UNTITLED_SERVLET_H
#define UNTITLED_SERVLET_H

#include <boost/asio/detail/shared_ptr.hpp>
#include "../http/Request.h"
#include "../http/Response.h"

namespace servlet {
    class Servlet {
    public:
        virtual void doGet(std::shared_ptr<http::Request> req,std::shared_ptr<http::Response> resp);
        virtual void doPost(std::shared_ptr<http::Request> req,std::shared_ptr<http::Response> resp);
        virtual void doDelete(std::shared_ptr<http::Request> req,std::shared_ptr<http::Response> resp);
        virtual void doPut(std::shared_ptr<http::Request> req,std::shared_ptr<http::Response> resp);
    };
}


#endif //UNTITLED_SERVLET_H
