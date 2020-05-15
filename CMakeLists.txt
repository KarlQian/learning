cmake_minimum_required(VERSION 3.2)
project(Learning
# Sets project's version
  VERSION 0.0.1
# Sets project's language
  LANGUAGES CXX C
)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CXX_FLAGS
        -g
        # -DVALGRIND
        -DCHECK_PTHREAD_RETURN_VALUE
        -D_FILE_OFFSET_BITS=64
        -Wall
        -Wextra
        #-Werror
        -Wconversion
        -Wno-unused-parameter
        -Wold-style-cast
        -Woverloaded-virtual
        -Wpointer-arith
        -Wshadow
        -Wwrite-strings
        -march=native
        # -MMD
        -rdynamic
        -pthread
        )
 
#string(TOUPPER ${CMAKE_BUILD_TYPE} BUILD_TYPE)
#CMAKE_CXX_FLAGS
#string(REPLACE ";" " " CMAKE_CXX_FLAGS "${CXX_FLAGS}")
string(REPLACE ";" " " CMAKE_CXX_FLAGS "${CXX_FLAGS}")

#find_package(Boost REQUIRED)
#include_directories(${Boost_INCLUDE_DIRS})

add_subdirectory(C++)
add_subdirectory(os)
add_subdirectory(algorithm)

