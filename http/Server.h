//
// Created by arturmamedov on 27.12.18.
//

#ifndef UNTITLED_SERVER_H
#define UNTITLED_SERVER_H


#include <boost/asio.hpp>
#include "RequestProcessor.h"


namespace http{
    
    class Server {
        std::shared_ptr<RequestProcessor> requestProcessor;
        boost::asio::io_service ios;
        boost::asio::ip::tcp::acceptor acceptor;
        bool started = false;
    public:
        Server(short port,const std::shared_ptr<RequestProcessor> &requestProcessor);
        void run();
    private:
        void onIncomingConnection(std::shared_ptr<boost::asio::ip::tcp::socket> sock);

    };
}



#endif //UNTITLED_SERVER_H
