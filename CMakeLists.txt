project(survive-the-map)
cmake_minimum_required(VERSION 2.8)

set(CMAKE_CXX_FLAGS "-std=c++14")

find_library(LIBSFML_GRAPHICS sfml-graphics)
find_library(LIBSFML_SYSTEM sfml-system)
find_library(LIBSFML_WINDOW sfml-window)

include_directories(${PROJECT_SOURCE_DIR}/include)
include_directories(${PROJECT_SOURCE_DIR})
file(GLOB SRC ${PROJECT_SOURCE_DIR}/src/* ${PROJECT_SOURCE_DIR}/main.cpp ${PROJECT_SOURCE_DIR}/include/*)

add_executable(${PROJECT_NAME} ${SRC})
target_link_libraries(${PROJECT_NAME} ${LIBSFML_GRAPHICS})
target_link_libraries(${PROJECT_NAME} ${LIBSFML_SYSTEM})
target_link_libraries(${PROJECT_NAME} ${LIBSFML_WINDOW})
