cmake_minimum_required(VERSION 3.1)

project(AbstractVM
	VERSION 0.1
	DESCRIPTION "RPN calculator virtual machine with assembly like syntax"
	LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "-Wall -Wextra -Werror")

add_library(avmlib STATIC vm/sources/exceptions.cpp
	vm/sources/operandFactory.cpp
	vm/sources/vm.cpp)
target_include_directories(avmlib PUBLIC vm/includes)

add_executable(avm src/sources/main.cpp
	src/sources/lexer.cpp
	src/sources/parser.cpp)
target_include_directories(avm PRIVATE src/includes)
target_link_libraries(avm PRIVATE avmlib)

find_package(Catch2 REQUIRED)

add_executable(unit_tests tests/sources/main.cpp
		tests/sources/basicTest.cpp)

target_link_libraries(unit_tests avmlib)
target_link_libraries(unit_tests Catch2::Catch2)

include(CTest)
include(Catch)
catch_discover_tests(unit_tests)
