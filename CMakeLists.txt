cmake_minimum_required(VERSION 3.8)

project(eye_tracker_app)
include_directories(${CMAKE_SOURCE_DIR}/Connector ${CMAKE_SOURCE_DIR}/Control ${CMAKE_SOURCE_DIR}/Telemetrics)
add_executable(${PROJECT_NAME}
    "main.cpp"
    "Connector/Connector.cpp"
    "Control/Control.cpp"  "Control/Robot.cpp" "Control/Keyboard.cpp"
    "Telemetrics/Telemetrics.cpp")
target_link_libraries( eye_tracker_app wiringPi wiringPiDev)
target_link_libraries( eye_tracker_app pthread rt crypt)

#target_link_libraries(${PROJECT_NAME} Connector)
