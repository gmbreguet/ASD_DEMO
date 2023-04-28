cmake_minimum_required(VERSION 3.22)
project(ForwardList)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wconversion -Wall -Wextra -pedantic -std=c++20")

add_executable(ForwardList
        main.cpp
        ForwardList.hpp
        ForwardList_Impl.hpp
)

set_target_properties(
        ${PROJECT_NAME}
        PROPERTIES OUTPUT_NAME ../APP.app
)

