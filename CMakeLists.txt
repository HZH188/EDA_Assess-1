cmake_minimum_required(VERSION 3.10)
project(EDA_Assess)

set(CMAKE_CXX_STANDARD 11)

include_directories(include)

add_executable(EDA_Assess
    src/main.cpp
    src/parser.cpp
    src/place.cpp
    src/exporter.cpp
)

# Google Test setup
enable_testing()
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

add_executable(test_main test/test_main.cpp src/parser.cpp)
target_link_libraries(test_main ${GTEST_LIBRARIES} pthread)
add_test(NAME ParserTest COMMAND test_main)


