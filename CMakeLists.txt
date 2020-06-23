cmake_minimum_required(VERSION 3.8)

project(eye_tracker_server)
include_directories(${CMAKE_SOURCE_DIR}/Connector ${CMAKE_SOURCE_DIR}/Control)
add_executable(${PROJECT_NAME} "main.cpp" "Connector/Connector.cpp" "Control/Control.cpp")
#target_link_libraries(${PROJECT_NAME} Connector)
