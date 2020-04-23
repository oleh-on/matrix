cmake_minimum_required(VERSION 3.4)
project(matrix)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCES src/sources/main.cpp src/sources/Matrix.cpp)

add_executable(matrix ${SOURCES})

target_link_libraries(${PROJECT_NAME} PRIVATE -pthread)
target_include_directories(${PROJECT_NAME} PRIVATE src/headers)