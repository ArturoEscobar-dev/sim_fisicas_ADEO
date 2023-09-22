cmake_minimum_required(VERSION 3.26)
project(Tarea2_Disparo)

set(CMAKE_CXX_STANDARD 17)

add_executable(Tarea2_Disparo main.cpp)
find_package(box2d CONFIG REQUIRED)
target_link_libraries(Tarea2_Disparo PRIVATE box2d::box2d)
