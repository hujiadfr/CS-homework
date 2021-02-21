cmake_minimum_required(VERSION 3.16)
project(MAX_HEAP)
file(GLOB SOURCES
        heap.h						//*号对应具体的文件名
        heap.cpp
        main.cpp
        )
set(CMAKE_CXX_STANDARD 14)

add_executable(MAX_HEAP main.cpp ${SOURCE_FILES} ${SOURCES})