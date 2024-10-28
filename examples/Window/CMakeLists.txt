set(executable_name "Example-Window")
add_executable(${executable_name} main.cpp)
target_link_libraries(${executable_name} PRIVATE SDL3::SDL3 DSIM_Window)
