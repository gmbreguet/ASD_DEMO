cmake_minimum_required(VERSION 3.18)
project(04_Structures_Lineaires)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wconversion -Wall -Wextra -pedantic -std=c++20")

add_executable(04_Structures_Lineaires
        Tableau.hpp
        Tab_Iterateur.hpp "main.cpp")

set_target_properties(
        ${PROJECT_NAME}
        PROPERTIES OUTPUT_NAME ../APP.out
        )

