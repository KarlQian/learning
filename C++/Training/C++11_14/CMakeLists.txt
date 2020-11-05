#=============================================================================
# Copyright (c) 2013 Elektrobit. All rights reserved.
# This file is part of the Elektrobit C++ Training.
#=============================================================================

cmake_minimum_required(VERSION 2.8 FATAL_ERROR)

add_executable(UniquePtr
  UniquePtr.cpp
  )

add_executable(Factory
  Factory.cpp
  )

add_executable(Simpsons
  Simpsons.cpp
  )

add_executable(Observer
  Observer.cpp
  )

add_executable(Faculty
  Faculty.cpp
  )

set_target_properties(UniquePtr Factory Simpsons Observer Faculty PROPERTIES
  FOLDER "C++11_14"
  )
