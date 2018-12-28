//
// Created by arturmamedov on 28.12.18.
//

#ifndef UNTITLED_STATICRESOURCESSERVLET_H
#define UNTITLED_STATICRESOURCESSERVLET_H


#include <fstream>
#include "../servlet/Servlet.h"

class StaticResourcesServlet: public servlet::Servlet {
public:
    void doGet(std::shared_ptr<http::Request> req, std::shared_ptr<http::Response> resp) override{
        std::string uri = req->getRequestUri();
        std::string path = "."+uri;

        std::ifstream fi(path,std::stringstream::in|std::ios::binary);
        if (!fi.eof()){
            fi.seekg (0, std::ios::end);
            auto length = fi.tellg();
            fi.seekg (0, std::ios::beg);
            char * buffer = new char [length];
            fi.read (buffer,length);
            fi.close();

            resp->getBody().write(buffer,length);
            delete[] buffer;
        }
    };
};


#endif //UNTITLED_STATICRESOURCESSERVLET_H
