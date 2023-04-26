cmake_minimum_required(VERSION 3.22)
project(_CLion)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wconversion -Wall -Wextra -pedantic -std=c++20")

add_executable(_CLion
        main.cpp
)

set_target_properties(
        ${PROJECT_NAME}
        PROPERTIES OUTPUT_NAME ../APP.app
)

