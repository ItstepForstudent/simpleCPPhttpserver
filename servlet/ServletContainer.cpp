//
// Created by arturmamedov on 28.12.18.
//

#include "ServletContainer.h"
#include "../utils/string.h"

servlet::ServletContainer::ServletContainer(short port) : server(port,std::shared_ptr<http::RequestProcessor>(new RequestProcessor(this))) {}




std::shared_ptr<http::Response>
servlet::ServletContainer::executeProcessing(std::shared_ptr<http::Request> req) {
    std::shared_ptr<http::Response> resp(new http::Response());

    std::shared_ptr<Servlet> servlet = findServlet(req->getRequestUri());
    try {
        if (servlet != nullptr && req->getMethod() == "GET") servlet->doGet(req, resp);
        else if (servlet != nullptr && req->getMethod() == "PUT") servlet->doPut(req, resp);
        else if (servlet != nullptr && req->getMethod() == "POST") servlet->doPost(req, resp);
        else if (servlet != nullptr && req->getMethod() == "DELETE") servlet->doDelete(req, resp);
        else {
            resp->setStatusCode(301);
            resp->setStarusString("Moved Permanently");
            resp->setHeader("Location","/404");
        }
    }catch (std::exception &e){
        resp->setStatusCode(301);
        resp->setStarusString("Moved Permanently");
        resp->setHeader("Location","/404");
    }

    return resp;
}

void servlet::ServletContainer::registerServlet(std::string pattern, std::shared_ptr<servlet::Servlet> servlet) {
    servlerRegisetry[pattern] = servlet;
}

std::shared_ptr<servlet::Servlet> servlet::ServletContainer::findServlet(std::string url) {
    for(auto p:servlerRegisetry){
        if(util::string::endsWith(p.first,"/*")){
            std::string cmpstr = p.first.substr(0,p.first.length()-2);
            if(util::string::startsWith(url,cmpstr)) return p.second;
        }
        else if(url==p.first) return p.second;
    }
    return std::shared_ptr<servlet::Servlet>();
}

void servlet::ServletContainer::start() {
    server.run();
}


std::shared_ptr<http::Response>
servlet::ServletContainer::RequestProcessor::doProcessing(std::shared_ptr<http::Request> req) {
    return pContainer->executeProcessing(req);
}

servlet::ServletContainer::RequestProcessor::RequestProcessor(servlet::ServletContainer *pContainer) :pContainer(pContainer){

}
