cmake_minimum_required(VERSION 3.0) 
project(SimpleSample3)
set(SOURCE_EXE simple3.c)
include_directories(print)
add_executable(simple3 ${SOURCE_EXE})	
add_subdirectory(print)
target_link_libraries(simple3 print)
