cmake_minimum_required(VERSION 3.10)

project(AbstractVM
	VERSION 0.1
	DESCRIPTION "RPN calculator virtual machine with assembly like syntax"
	LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "-Wall -Wextra -Werror")

add_executable(avm	sources/main.cpp
					sources/lexer.cpp
					sources/parser.cpp
					sources/operandFactory.cpp
					sources/vm.cpp
					sources/exceptions.cpp)

target_include_directories(avm PRIVATE includes)
