cmake_minimum_required(VERSION 3.20)
project(PR2)

set(CMAKE_CXX_STANDARD 17)

add_executable(Pro2 main.cpp TestFramework.cpp TestFramework.h UnitTest.cpp UnitTest.h Time.cpp Time.h DataRecorder.cpp DataRecorder.h Signal.cpp Signal.h MonitoringSystem.cpp MonitoringSystem.h Sensor.cpp Sensor.h)
