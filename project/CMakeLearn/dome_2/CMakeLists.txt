cmake_minimum_required(VERSION 3.5)

project(dome LANGUAGES CXX VERSION 0.3)

set(CMAKE_CXX_STANDARD 11)

set(CMAKE_CXX_STANDARD_REQUIRED on)

add_subdirectory("./myfunc")

# configure_file(domeConfig.hpp.in domeConfig.hpp)

add_executable(${PROJECT_NAME} "dome.cpp")

target_link_libraries(${PROJECT_NAME} "myfunc")

target_include_directories(${PROJECT_NAME} PUBLIC 
                            "./myfunc/")

# target_include_directories(${PROJECT_NAME} PUBLIC
                            # ${PROJECT_BINARY_DIR})