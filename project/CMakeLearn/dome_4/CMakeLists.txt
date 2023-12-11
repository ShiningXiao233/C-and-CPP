cmake_minimum_required(VERSION 3.15)

project(dome LANGUAGES CXX VERSION 0.3)

set(gcc_like_cxx "$<COMPILE_LANG_AND_ID:CXX,ARMClang,AppleClang,Clang,GNU,LCC>")
set(msvc_cxx "$<COMPILE_LANG_AND_ID:CXX,MSCV>")

# set(gcc_like_cxx "$<COMPILE_LANG_AND_ID:CXX,ARMClang,AppleClang,Clang,GNU,LCC>")
# set(msvc_cxx "$<COMPILE_LANG_AND_ID:CXX,MSVC>")

add_library(cp_flag INTERFACE)

target_compile_features(cp_flag INTERFACE cxx_std_11)

add_subdirectory("./myfunc")

add_executable(${PROJECT_NAME} "dome.cpp")

# target_link_libraries(${PROJECT_NAME} PUBLIC cp_flag)

target_link_libraries(${PROJECT_NAME} PUBLIC "myfunc" cp_flag)

target_compile_options(cp_flag INTERFACE 
    "$<${gcc_like_cxx}:$<BUILD_INTERFACE:-Wall;-Wextra;-Wshadow;-Wformat=2;-Wunused>>"   
    "$<${msvc_cxx}:$<BUILD_INTERFACE:-W3>>" 
    "-std=c++11"
)