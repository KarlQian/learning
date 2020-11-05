#=============================================================================
# Copyright (c) 2013 Elektrobit. All rights reserved.
# This file is part of the Elektrobit C++ Training.
#=============================================================================

cmake_minimum_required(VERSION 2.8 FATAL_ERROR)

add_executable(LockGuard
	LockGuard.cpp
)


set_target_properties(LockGuard PROPERTIES
	FOLDER "5_Exception_Safety"
)
