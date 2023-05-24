cmake_minimum_required(VERSION 3.2)
project(test)

find_package(add REQUIRED)

add_executable(test main.cpp)
target_link_libraries(test add::add)