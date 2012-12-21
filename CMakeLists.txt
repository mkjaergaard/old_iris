cmake_minimum_required(VERSION 2.8)
project(beam)

find_package(catkin)

catkin_package(
  INCLUDE_DIRS include
  LIBRARIES beam-printf
)

include_directories(include)

add_library(beam-printf
  src/logger-printf.cpp
)

add_executable(beam_test
  src/test.cpp)

target_link_libraries(beam_test beam-printf -lstdc++)

add_executable(beam_example
  test/example.cpp)

target_link_libraries(beam_example beam-printf -lstdc++)

install(TARGETS beam-printf
  ARCHIVE DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
  LIBRARY DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION})

install(DIRECTORY include/
  DESTINATION ${CATKIN_GLOBAL_INCLUDE_DESTINATION}
  FILES_MATCHING PATTERN "*.hpp")
