cmake_minimum_required(VERSION 3.17)
project(TEI_ImageMP)

find_library(CImg CImg.h)

set(CMAKE_CXX_STANDARD 20)

add_executable(TEI_ImageMP jasnau.cpp)