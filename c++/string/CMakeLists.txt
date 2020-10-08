cmake_minimum_required(VERSION 3.10)

# set the project name
project(UnitTest VERSION 1.0)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# add the executable
add_executable(UnitTest unittest.cpp)

target_include_directories(UnitTest PUBLIC
                           "../../googletest-master/googletest/include/"
                           )

ADD_LIBRARY(gtest STATIC IMPORTED)
SET_TARGET_PROPERTIES(gtest PROPERTIES IMPORTED_LOCATION ../../googletest-master/lib/libgtest.a)
target_link_libraries(UnitTest PUBLIC gtest)
ADD_LIBRARY(gtest_main STATIC IMPORTED)
SET_TARGET_PROPERTIES(gtest_main PROPERTIES IMPORTED_LOCATION ../../googletest-master/lib/libgtest_main.a)
target_link_libraries(UnitTest PUBLIC gtest_main)
target_link_libraries(UnitTest PUBLIC -lpthread)


