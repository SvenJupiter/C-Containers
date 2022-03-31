

# Examample to vector container
add_executable(vector_example vector_example.c)
target_link_libraries(vector_example containers)


# example for forward list container
add_executable(forward_list_example_1 forward_list_example_1.c)
target_link_libraries(forward_list_example_1 containers)


# example for forward list container
add_executable(forward_list_example_2 forward_list_example_2.c)
target_link_libraries(forward_list_example_2 containers)


# example for list container
add_executable(list_example list_example.c)
target_link_libraries(list_example containers)


# example for circular_buffer container
find_package(Threads REQUIRED)
add_executable(circular_buffer_example circular_buffer_example.c)
target_link_libraries(circular_buffer_example containers)
target_link_libraries(circular_buffer_example Threads::Threads)