#=============================================================================
# Copyright (c) 2013 Elektrobit. All rights reserved.
# This file is part of the Elektrobit C++ Training.
#=============================================================================

cmake_minimum_required(VERSION 2.8 FATAL_ERROR)

add_executable(Remote
  Remote.cpp
  )

add_executable(Complex
  Complex.cpp
  )

add_executable(ConstCorrectness
  ConstCorrectness.cpp
  )

set_target_properties(
    ConstCorrectness
  PROPERTIES
    EXCLUDE_FROM_ALL ON
    EXCLUDE_FROM_DEFAULT_BUILD ON
  )

set_target_properties(
    Remote
    Complex
    ConstCorrectness
  PROPERTIES
    FOLDER "4_Class_Design"
  )
