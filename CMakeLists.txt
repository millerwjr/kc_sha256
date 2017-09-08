cmake_minimum_required(VERSION 3.6)
project(kc_sha256)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp kc_sha256.h kc_sha256.cpp)
add_executable(kc_sha256 ${SOURCE_FILES})