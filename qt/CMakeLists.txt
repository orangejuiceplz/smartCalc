cmake_minimum_required(VERSION 3.1.0)

project(calculator)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

find_package(Qt6 COMPONENTS Widgets REQUIRED)

add_executable(calculator
    main.cpp
    calculator.cpp
    calculator.h
)

target_link_libraries(calculator Qt6::Widgets)