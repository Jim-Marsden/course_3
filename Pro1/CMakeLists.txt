cmake_minimum_required(VERSION 3.20)
project(HW3)

set(CMAKE_CXX_STANDARD 17)

add_executable(project1 Coin.cpp Coin.h DeliveryChute.cpp DeliveryChute.h main.cpp Product.cpp Product.h
        ProductButton.cpp ProductButton.h ProductRack.h ProductRack.cpp StatusPanel.cpp StatusPanel.h TestFramework.cpp
        TestFramework.h UnitTest.cpp UnitTest.h VendingMachine.cpp VendingMachine.h)
