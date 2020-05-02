cmake_minimum_required(VERSION 2.6)

# Locate GTest
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})


# Link runTests with what we want to test and the GTest and pthread library
add_library(ValidParensLib source.cpp)
add_executable(runTests tests.cpp)
target_link_libraries(runTests ValidParensLib ${GTEST_LIBRARIES} pthread)
