cmake_minimum_required(VERSION 3.22)
set(base_SRCS
    Thread.cpp
        )

include_directories(/home/rain/muduo/build/release-install-cpp11/include)
link_directories(/home/rain/muduo/build/release-install-cpp11/lib)
add_library(mal_base STATIC ${base_SRCS})
SET(LIBRARY_OUTPUT_PATH ${PROJECT_BINARY_DIR}/lib)
SET(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib)
target_link_libraries(mal_base
        libmuduo_base.a
        libmuduo_http.a
        libmuduo_inspect.a
        libmuduo_net.a)

