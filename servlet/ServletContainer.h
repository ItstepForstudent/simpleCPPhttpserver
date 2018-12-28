//
// Created by arturmamedov on 28.12.18.
//

#ifndef UNTITLED_SERVLETCONTAINER_H
#define UNTITLED_SERVLETCONTAINER_H

#include "../http/Server.h"
#include "Servlet.h"

namespace servlet {
    class ServletContainer {
        http::Server server;
        std::map<std::string,std::shared_ptr<Servlet>> servlerRegisetry;
        class RequestProcessor: public http::RequestProcessor{
            servlet::ServletContainer *pContainer;
        public:
            RequestProcessor(ServletContainer *pContainer);
            std::shared_ptr<http::Response> doProcessing(std::shared_ptr<http::Request> ptr) override;
        };
    public:
        ServletContainer(short port);

        std::shared_ptr<http::Response> executeProcessing(std::shared_ptr<http::Request> shared_ptr);
        void registerServlet(std::string pattern,std::shared_ptr<Servlet> servlet);
        void start();

    private:
        std::shared_ptr<Servlet> findServlet(std::string url);
    };

}


#endif //UNTITLED_SERVLETCONTAINER_H
