cmake_minimum_required(VERSION 3.10)
project(calc)

set(CMAKE_CXX_STANDARD 17)

# Set build type
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Release)
endif()

# Set output directory for the executable
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# Manually set wxWidgets paths
set(wxWidgets_ROOT_DIR "C:/Users/shive/vcpkg/installed/x64-windows")
set(wxWidgets_INCLUDE_DIRS "${wxWidgets_ROOT_DIR}/include")
set(wxWidgets_LIB_DIR "${wxWidgets_ROOT_DIR}/lib")

# Add wxWidgets
find_package(wxWidgets REQUIRED COMPONENTS core base)
if(wxWidgets_FOUND)
    include(${wxWidgets_USE_FILE})
else()
    message(FATAL_ERROR "wxWidgets not found")
endif()

include_directories(${wxWidgets_INCLUDE_DIRS})
link_directories(${wxWidgets_LIB_DIR})

add_executable(calc main.cpp SmartCalculator.cpp)

# Link wxWidgets libraries
target_link_libraries(calc ${wxWidgets_LIBRARIES})