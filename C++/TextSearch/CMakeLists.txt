SET(LANGUAGES CXX)
SET(QUERYSOURCE 
TextQuery.hpp
Query_result.hpp
query.cpp
)

add_library(Query ${QUERYSOURCE})

add_executable(TextSearch main.cpp)
target_link_libraries(TextSearch Query)
