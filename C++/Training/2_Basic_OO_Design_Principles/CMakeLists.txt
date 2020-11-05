#=============================================================================
# Copyright (c) 2013 Elektrobit. All rights reserved.
# This file is part of the Elektrobit C++ Training.
#=============================================================================

add_executable(LSP
  LSP.cpp
  )

add_executable(OCP
  OCP.cpp
  )

set_target_properties(LSP PROPERTIES
  EXCLUDE_FROM_ALL ON
  EXCLUDE_FROM_DEFAULT_BUILD ON
  )

set_target_properties(LSP OCP PROPERTIES
  FOLDER "2_Basic_OO_Design_Principles"
  )
