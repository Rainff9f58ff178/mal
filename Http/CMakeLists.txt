
cmake_minimum_required(VERSION 3.20)

set(http_SRCS
        HttpServer.cpp
        HttpContext.cpp
        HttpRequest.cpp
        HttpResponse.cpp MIME_map.h MIME_map.cpp)

add_library(mal_http STATIC ${http_SRCS})

SET(LIBRARY_OUTPUT_PATH ${PROJECT_BINARY_DIR}/lib)
SET(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib)
include_directories(../net)
include_directories(../base)
target_link_libraries(mal_http mal_base mal_net)