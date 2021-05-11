cmake_minimum_required(VERSION 2.8)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


project(CSVParseFinal)

add_executable(CSVParser src/CsvParser.cpp)
include_directories(.)

set(MAIN_FILE src/CsvParser.cpp)
