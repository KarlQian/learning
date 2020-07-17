#add_library(lib,.cpp)

#target_link_libraries(exe, lib)

add_executable(server server.c)
add_executable(client client.c)

add_executable(msgclient msgclient.c)
add_executable(msgserv msgserv.c)



set_target_properties(client PROPERTIES
COMPILE_FLAGS "-pthread"
LINK_FLAGS "-pthread"
)

set_target_properties(msgclient PROPERTIES
COMPILE_FLAGS "-pthread"
LINK_FLAGS "-pthread"
)