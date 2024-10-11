cmake_minimum_required(VERSION 3.5)

project(algo)

set(CMAKE_CXX_STANDARD 17)

add_executable(binaryTree binaryTree/binaryTree.cpp)
add_executable(2016 2016.cpp
        binaryTree/treeDepth.h)
add_executable(2021 2021.cpp)
add_executable(test test.cpp)