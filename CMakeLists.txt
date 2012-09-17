cmake_minimum_required(VERSION 2.8)
project(beam)

find_package(catkin)
catkin_stack()

catkin_project(beam
  INCLUDE_DIRS include
  LIBRARIES beam beam-printf
)

include_directories(include)

add_library(beam-printf
  src/logger-printf.cpp
)

add_executable(beam_test
  src/test.cpp)

target_link_libraries(beam_test beam-printf -lstdc++)
