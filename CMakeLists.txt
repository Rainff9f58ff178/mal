cmake_minimum_required(VERSION 3.20)
PROJECT(MAL)
set(CMAKE_CXX_STANDARD 20)
include_directories(base)
include_directories(Http)
include_directories(net)
add_subdirectory(Http)
add_subdirectory(base)
add_subdirectory(net)
add_executable(main main.cpp )
add_executable(test test.cpp)
add_executable(io_uring_test io_uring_test.cpp)
add_executable(cxx_20_coroutine_test coroutine_test.cpp)
target_link_libraries(main PRIVATE stdc++ mal_base mal_net mal_http uring)


target_link_libraries(io_uring_test uring)



