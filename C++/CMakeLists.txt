#add_library(lib,.cpp)

#target_link_libraries(exe, lib)
add_subdirectory(TextSearch)

add_library(file file.cpp)

#add_executable(Message testMessage.cpp)
#target_link_libraries(Message file)

#add_executable(friendTemplate friendTemplate.cpp)
add_executable(dangling_pointer dangling_pointer.cpp)
add_executable(move move.cpp)
add_executable(unique_ptr_test unique_ptr_test.cpp)
add_executable(singleton singleton.cpp test_singleton.cpp)
add_executable(pthread_once pthread_once_example.cpp)




