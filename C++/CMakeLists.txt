#add_library(lib,.cpp)

#target_link_libraries(exe, lib)
add_subdirectory(TextSearch)
add_executable(file file.cpp)
add_executable(friendTemplate friendTemplate.cpp)
add_executable(dangling_pointer dangling_pointer.cpp)
add_executable(move move.cpp)
add_executable(unique_ptr_test unique_ptr_test.cpp)



