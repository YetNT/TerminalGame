cmake_minimum_required(VERSION 3.10)
project(tge)

set(CMAKE_CXX_STANDARD 17)

# Include directories
include_directories(include)

# Source files
file(GLOB SOURCES "src/*.cpp")

# Create a static library from the source files
add_library(tge STATIC ${SOURCES})

# Example executable
add_executable(example examples/example.cpp)
target_link_libraries(example tge)

# Optionally, add tests
# add_executable(test tests/test.cpp)
# target_link_libraries(test MyGameEngine)
