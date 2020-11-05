#=============================================================================
# Copyright (c) 2013 Elektrobit. All rights reserved.
# This file is part of the Elektrobit C++ Training.
#=============================================================================

add_executable(Curl
  Curl.cpp
  )


add_executable(DesignByContract
  DesignByContract.cpp
  )

set_target_properties(
    Curl
    DesignByContract
  PROPERTIES
    EXCLUDE_FROM_ALL ON
    EXCLUDE_FROM_DEFAULT_BUILD ON
  )

set_target_properties(
    Curl
    DesignByContract
  PROPERTIES
    FOLDER "B_Test_Driven_Class_Design"
  )
