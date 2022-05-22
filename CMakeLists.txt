cmake_minimum_required(VERSION 3.16)
project(orgchart_b)

set(CMAKE_CXX_STANDARD 14)

add_executable(orgchart_b main.cpp sources/Node.cpp sources/Node.hpp  sources/OrgChart.cpp sources/OrgChart.hpp sources/Iterator.cpp)
