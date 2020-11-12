cmake_minimum_required(VERSION 3.10)

project(AbstractVM VERSION 0.1)

set(EXEC avm)

set (CMAKE_CXX_STANDARD 17)

include_directories(includes)

file(GLOB SOURCES sources/*.cpp)

add_executable(${EXEC} ${SOURCES})
