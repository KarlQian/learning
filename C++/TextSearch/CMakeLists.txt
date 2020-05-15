SET(LANGUAGES CXX)
SET(QUERYSOURCE 
TextQuery.hpp
Query_result.hpp
query.cpp
)
message(${CMAKE_CURRENT_SOURCE_DIR})
include_directories(${CMAKE_CURRENT_SOURCE_DIR})
add_library(Query ${QUERYSOURCE})

add_executable(TextSearch main.cpp)
target_link_libraries(TextSearch Query)
