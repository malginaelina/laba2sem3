cmake_minimum_required(VERSION 3.20)
project(laba2sem3)

set(CMAKE_CXX_STANDARD 14)
add_subdirectory(googletest)
add_executable(laba2sem3 main.cpp SparceVector.h Histogram.h Person.h Dictionary.h BinaryTree.h ArraySequence.h Sequence.h LinkedListSequence.h LinkedList.h DynamicArray.h AlphabetIndex.h Interface.h Tests.cpp)
include_directories(googletest/googletest/include)
target_link_libraries(laba2sem3 gtest gtest_main)