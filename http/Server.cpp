#include "Server.h"
#include <iostream>
#include <thread>
#include <memory>

http::Server::Server(short port, const std::shared_ptr<http::RequestProcessor> &requestProcessor)
        : requestProcessor(requestProcessor),
          acceptor(ios, boost::asio::ip::tcp::endpoint(boost::asio::ip::tcp::v4(), port)) {
}



void http::Server::run() {
    started = true;
    while (started) {
        std::shared_ptr<boost::asio::ip::tcp::socket> sock(new boost::asio::ip::tcp::socket(ios));
        acceptor.accept(*sock);
        std::thread th([=]{this->onIncomingConnection(sock);});
        th.detach();

    }


}

void http::Server::onIncomingConnection(std::shared_ptr<boost::asio::ip::tcp::socket> sock) {
    try {
        std::shared_ptr<Request> request(new Request());

        boost::asio::streambuf req;
        try {
            boost::asio::read_until(*sock, req, "\r\n");
        }catch (std::exception& e){
            return;
        }

        std::string http_method;
        std::string uri;
        std::string http_version;

        std::istream req_stream(&req);
        req_stream >> http_method;
        req_stream >> uri;
        req_stream >> http_version;


        request->setMethod(http_method);
        request->setRequestUri(uri);


        req_stream.ignore(4,'\n');

        while (!req_stream.eof()){

            std::string header;
            std::getline(req_stream,header,'\r');
            req_stream.ignore(1);
            if(header=="") break;
            std::stringstream headerstream(header);

            std::string headername;
            std::string headervalue;

            std::getline(headerstream,headername,':');
            std::getline(headerstream,headervalue);


            request->addHeader(headername,headervalue);
        }


        std::stringstream stringstream;
        while (!req_stream.eof()){
            std::string bodytmp;
            std::getline(req_stream,bodytmp,'\n');
            stringstream<<bodytmp<<"\n";
        }

        request->setBody(stringstream.str());


        auto response = this->requestProcessor->doProcessing(request);


        boost::asio::streambuf resp;
        std::ostream resp_stream(&resp);
        resp_stream << "HTTP/1.1 "<<response->getStatusCode()<<" "<<response->getStarusString() << "\r\n";
        for(auto header:response->getHeaders()){
            resp_stream <<header.first <<":" <<header.second<< "\r\n";
        }
        resp_stream << "\r\n";
        resp_stream << response->getBody().str();

        // Send the request.
        boost::asio::write(*sock, resp);

        sock->close();

    }
    catch (std::exception &e) {
        std::cerr << "Exception in thread: " << e.what() << "\n";
    }

}
