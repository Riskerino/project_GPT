cmake_minimum_required(VERSION 3.10)

# Set the project name
project(FastaParser)

# Specify the C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add an executable
add_executable(fasta_parser
    src/main.cpp
    src/FastaParser.cpp
)

# Include directories
target_include_directories(fasta_parser PRIVATE ${CMAKE_SOURCE_DIR}/src)

