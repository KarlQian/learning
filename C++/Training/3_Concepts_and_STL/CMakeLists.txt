#=============================================================================
# Copyright (c) 2013 Elektrobit. All rights reserved.
# This file is part of the Elektrobit C++ Training.
#=============================================================================

cmake_minimum_required(VERSION 2.8 FATAL_ERROR)

add_executable(Accumulate
  Accumulate.cpp
  )

add_executable(BadCopy
  BadCopy.cpp
  )

add_executable(BadTransform
  BadTransform.cpp
  )

add_executable(Table
  Table.cpp
  )

add_executable(IsPunct
  IsPunct.cpp
  )

set_target_properties(Accumulate BadCopy BadTransform Table IsPunct PROPERTIES
  FOLDER "3_Concepts_and_STL"
  )
