cmake_minimum_required(VERSION 3.13)
project(untitled)

set(CMAKE_CXX_STANDARD 14)
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14 -pthread")



set(BOOST_ROOT "/usr/include/boost/")
SET(PLATFORM_SPECIFIC_LIBS "-lpthread")

find_package(Boost 1.65.1 COMPONENTS system filesystem REQUIRED)

if(NOT Boost_FOUND)
    message(FATAL_ERROR "Could not find boost!")
endif()
message(STATUS "Boost_INCLUDE_DIRS: ${Boost_INCLUDE_DIRS}")
message(STATUS "Boost_LIBRARIES: ${Boost_LIBRARIES}")
message(STATUS "Boost_VERSION: ${Boost_VERSION}")



add_executable(untitled main.cpp http/Server.cpp http/Server.h http/Request.cpp http/Request.h http/RequestProcessor.h http/Response.cpp http/Response.h servlet/ServletContainer.cpp servlet/ServletContainer.h servlet/Servlet.cpp servlet/Servlet.h utils/string.h utils/string.cpp app/MainServlet.hpp app/Page2Servlet.hpp app/StaticResourcesServlet.hpp app/Servlet404.h)

target_include_directories(untitled PRIVATE ${Boost_INCLUDE_DIRS})
target_link_libraries(untitled ${Boost_LIBRARIES})
