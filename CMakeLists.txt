cmake_minimum_required(VERSION 3.2)
project(CLRS VERSION 0.0.0.1 LANGUAGES CXX)

include(cmake/colorize.cmake)
include(cmake/catch.cmake)

set(CMAKE_CXX_STANDARD 14)
set(PROJECT_INCLUDE_DIR ${PROJECT_SOURCE_DIR}/include)
include_directories(${PROJECT_INCLUDE_DIR})

set(CATCH_VERSION 1.9.1)
set(CATCH_SHA224  3f02ddea8ca9b18ef9256068a7098a7b18d4ce357ca1e18561e81ac6)
download_catch()

enable_testing()
file(GLOB TEST_FILES test/*.cpp test/*/*.cpp)
add_executable(unittest ${TEST_FILES})
add_test(NAME overall COMMAND unittest)
