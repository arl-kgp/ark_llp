cmake_minimum_required(VERSION 2.8.3)
project(ark_llp)
find_package(catkin REQUIRED COMPONENTS
  roscpp
  std_msgs
)
catkin_package(CATKIN_DEPENDS std_msgs roscpp
               INCLUDE_DIRS include
               LIBRARIES go2goal)
include_directories(
  include/ark_llp
  ${catkin_INCLUDE_DIRS}
)
add_library(go2goal src/go2goal.cc)
target_link_libraries(go2goal ${catkin_LIBRARIES})
install(TARGETS go2goal
        ARCHIVE DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
        LIBRARY DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION})
install(DIRECTORY include/${PROJECT_NAME}/
        DESTINATION ${CATKIN_PACKAGE_INCLUDE_DESTINATION})
