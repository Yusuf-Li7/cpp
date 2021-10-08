cmake_minimum_required(VERSION 3.20)
project(HW1_big_numbers)

set(CMAKE_CXX_STANDARD 17)

#add_library(big_integer_lib big_integer.cpp big_integer.h)

#add_executable(main main.cpp)

#target_link_libraries(main big_integer_lib)

add_executable(HW1_big_numbers main.cpp big_integer.h big_integer.cpp)
#add_definitions(-Werror)
#find_package(Threads REQUIRED)
#target_link_libraries(HW1_big_numbers Threads::Threads)


add_subdirectory(gtest1)

add_subdirectory(test)