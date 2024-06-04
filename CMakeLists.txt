cmake_minimum_required(VERSION 3.10)
project(SmartCalculator)

# Set the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Find wxWidgets package
find_package(wxWidgets REQUIRED COMPONENTS core base)

if(NOT wxWidgets_FOUND)
    message(FATAL_ERROR "wxWidgets not found.")
endif()

# Include wxWidgets
include(${wxWidgets_USE_FILE})
include_directories(${wxWidgets_INCLUDE_DIRS})

# Add source files
add_executable(SmartCalculator main.cpp SmartCalculator.cpp SmartCalculator.h)

# Link wxWidgets libraries
target_link_libraries(SmartCalculator ${wxWidgets_LIBRARIES})
