cmake_minimum_required(VERSION 3.26)
project(sim_fisicas_ADEO)

set(CMAKE_CXX_STANDARD 17)

add_executable(sim_fisicas_ADEO main.cpp)
find_package(box2d CONFIG REQUIRED)
target_link_libraries(sim_fisicas_ADEO PRIVATE box2d::box2d)