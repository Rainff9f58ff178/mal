cmake_minimum_required(VERSION 3.20)
set(base_SRCS
        Thread.cpp
        TimeStamp.cpp
        log.cpp)



add_library(mal_base STATIC ${base_SRCS})
SET(LIBRARY_OUTPUT_PATH ${PROJECT_BINARY_DIR}/lib)
SET(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib)
#target_link_libraries(mal_base)

