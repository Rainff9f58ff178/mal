
cmake_minimum_required(VERSION 3.22)

set(http_SRCS
        HttpServer.cpp
        HttpContext.cpp
        HttpRequest.cpp
        HttpResponse.cpp)

add_library(mal_http STATIC ${http_SRCS})

SET(LIBRARY_OUTPUT_PATH ${PROJECT_BINARY_DIR}/lib)
SET(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib)
include_directories(/home/rain/muduo/build/release-install-cpp11/include)
link_directories(/home/rain/muduo/build/release-install-cpp11/lib)
include_directories(../net)
include_directories(../base)
target_link_libraries(mal_base mal_net
        libmuduo_base.a
        libmuduo_http.a
        libmuduo_inspect.a
        libmuduo_net.a)