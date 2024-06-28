cmake_minimum_required(VERSION 3.22)

project(cpp_cherno)

add_subdirectory(include)
add_subdirectory(src)

option(BUILD_EXAMPLES "Option to build examples" ON)

set(CMAKE_CXX_STANDARD 17)

if (BUILD_EXAMPLES)
	message(STATUS "Building examples...")
	add_subdirectory(examples)
endif()
