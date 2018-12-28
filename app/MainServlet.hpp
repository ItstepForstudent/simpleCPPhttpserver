//
// Created by arturmamedov on 28.12.18.
//

#ifndef UNTITLED_EXAMPLESERVLET_H
#define UNTITLED_EXAMPLESERVLET_H


#include <iostream>
#include "../libs/json-develop/single_include/nlohmann/json.hpp"
#include "../servlet/Servlet.h"

using json = nlohmann::json;

class MainServlet :public servlet::Servlet{
public:
    void doGet(std::shared_ptr<http::Request> req, std::shared_ptr<http::Response> resp) override {
        resp->setHeader("Content-Type","text/html; charset=utf-8");
        resp->setHeader("Server","Apache");


        std::stringstream& b = resp->getBody();

        b<<"<!DOCTYPE html>"<<std::endl;
        b<<"<html>"<<std::endl;
        b<<"    <head></head>"<<std::endl;
        b<<"    <body>"<<std::endl;
        b<<"        <h1>Hello world</h1>"<<std::endl;
        b<<"        <h2>headers:</h2>"<<std::endl;

        b<<"        <ul>"<<std::endl;
        for(auto header:req->getHeaders()){
            b<<"            <li><b>"<<header.first<<"</b>: "<<header.second<<std::endl;
        }
        b<<"        </ul>"<<std::endl;

        b<<"    </body>"<<std::endl;
        b<<"</html>"<<std::endl;




    };


    void doPost(std::shared_ptr<http::Request> req, std::shared_ptr<http::Response> resp) override {

            json j;
            j["user"]={
                    {"name","Vasia"},
                    {"surname","Pupkin"}
            };

            resp->setHeader("Content-Type","application/json");
            resp->getBody()<<j.dump();
    }

};


#endif //UNTITLED_EXAMPLESERVLET_H
