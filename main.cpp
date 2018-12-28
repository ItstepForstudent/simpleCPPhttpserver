

#include "http/Server.h"
#include "servlet/ServletContainer.h"
#include "app/MainServlet.hpp"
#include "app/Page2Servlet.hpp"
#include "app/StaticResourcesServlet.hpp"
#include "libs/json-develop/single_include/nlohmann/json.hpp"
#include "app/Servlet404.h"
#include <iostream>






int main() {

    servlet::ServletContainer container(8080);

    container.registerServlet("/404",std::shared_ptr<servlet::Servlet>(new Servlet404));
    container.registerServlet("/res/*",std::shared_ptr<servlet::Servlet>(new StaticResourcesServlet));
    container.registerServlet("/",std::shared_ptr<servlet::Servlet>(new MainServlet));
    container.registerServlet("/page2/*",std::shared_ptr<servlet::Servlet>(new Page2Servlet));

    container.start();



    return 0;
}