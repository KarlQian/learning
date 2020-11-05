#=============================================================================
# Copyright (c) 2013 Elektrobit. All rights reserved.
# This file is part of the Elektrobit C++ Training.
#=============================================================================

add_executable(ConcreteObserver
  ConcreteObserver.cpp
)


add_custom_target(Includes1 SOURCES
  Includes1.h
)

add_custom_target(Includes2 SOURCES
  Includes2.h
)

add_custom_target(Includes3 SOURCES
  Includes3.h
)


set_target_properties(
  ConcreteObserver
  Includes1 Includes2 Includes3
  PROPERTIES
  FOLDER "7_Dependency_Breaking_Techniques"
)

include_directories(SYSTEM
  ../boost_1_60_0
)
