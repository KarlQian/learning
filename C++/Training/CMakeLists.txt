#=============================================================================
# Copyright (c) 2013 Elektrobit. All rights reserved.
# This file is part of the Elektrobit C++ Training.
#=============================================================================

cmake_minimum_required(VERSION 3.1 FATAL_ERROR)
project(Solutions CXX)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

SET(EXECUTABLE_OUTPUT_PATH ${Tasks_BINARY_DIR})

# use solution folders in Visual Studio
set_property(GLOBAL PROPERTY USE_FOLDERS ON)

enable_testing()

add_subdirectory(2_Basic_OO_Design_Principles)
add_subdirectory(3_Concepts_and_STL)
add_subdirectory(4_Class_Design)
add_subdirectory(5_Exception_Safety)
add_subdirectory(6_Proper_Use_of_Dynamic_Polymorphism)
add_subdirectory(7_Dependency_Breaking_Techniques)
add_subdirectory(8_Non-Intrusive-Design)
#add_subdirectory(B_Test_Driven_Class_Design)
#add_subdirectory(C_Templates)
#add_subdirectory(C++11_14)
