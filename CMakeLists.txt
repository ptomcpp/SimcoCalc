cmake_minimum_required(VERSION 3.12) # version can be different

project(SimcoCalc) #name of your project

add_subdirectory(googletest) # add googletest subdirectory

include_directories(googletest/googletest/include) # this is so we can #include <gtest/gtest.h>

add_executable(simcotests main.cpp) # add this executable

target_link_libraries(simcotests PRIVATE gtest) # link google test to this executable
