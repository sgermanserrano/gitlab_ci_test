cmake_minimum_required(VERSION 2.8.3)
project(basic)

## Compile as C++11, supported in ROS Kinetic and newer
add_compile_options(-std=c++11)

## Find catkin macros and libraries
## if COMPONENTS list like find_package(catkin REQUIRED COMPONENTS xyz)
## is used, also find other catkin packages
find_package(catkin REQUIRED COMPONENTS
  roscpp
  std_msgs
)

set(COVERAGE "OFF" CACHE STRING "Enable coverage generation.")

message(STATUS "Using COVERAGE: ${COVERAGE}")
if("${COVERAGE}" STREQUAL "ON")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fprofile-arcs -ftest-coverage")
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -fprofile-arcs -ftest-coverage")
endif()

## System dependencies are found with CMake's conventions
# find_package(Boost REQUIRED COMPONENTS system)


catkin_package(
  INCLUDE_DIRS include
  LIBRARIES beginner_tutorials
  CATKIN_DEPENDS roscpp std_msgs
)

include_directories(
  include
  ${catkin_INCLUDE_DIRS}
)

## Declare a C++ library
add_library(testing_talker
  src/talker.cpp
)
target_link_libraries(testing_talker
  ${catkin_LIBRARIES}
)

add_executable(talker_node 
    src/talker_node.cpp)

target_link_libraries(talker_node
  ${catkin_LIBRARIES}
  testing_talker
)


add_library(testing_listener
  src/listener.cpp
)
target_link_libraries(testing_listener
  ${catkin_LIBRARIES}
)

add_executable(listener_node 
    src/listener_node.cpp)

target_link_libraries(listener_node
  ${catkin_LIBRARIES}
  testing_listener
)

#add_executable(test_listener_node 
#    tests/test_listener.cpp)
#target_link_libraries(test_listener_node
#  ${catkin_LIBRARIES}
#  testing_listener
#)
   
#install(TARGETS testing
#  ARCHIVE DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
#  LIBRARY DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
#  RUNTIME DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION}
#)

#install(DIRECTORY include/${PROJECT_NAME}/
#  DESTINATION ${CATKIN_PACKAGE_INCLUDE_DESTINATION}
#  FILES_MATCHING PATTERN "*.h"
#  PATTERN ".svn" EXCLUDE
#)


if(CATKIN_ENABLE_TESTING)
  find_package(rostest REQUIRED)
  add_rostest_gtest(testing-test tests/gtest.test tests/unit_tests.cpp tests/unit_tests_talker.cpp tests/unit_tests_listener.cpp)
  target_link_libraries(testing-test ${catkin_LIBRARIES} testing_talker testing_listener)
      
  add_rostest(tests/talkerHz.test)
  add_rostest_gtest(test_listener_node tests/testListener.test tests/test_listener.cpp)
  target_link_libraries(test_listener_node ${catkin_LIBRARIES})
endif()
