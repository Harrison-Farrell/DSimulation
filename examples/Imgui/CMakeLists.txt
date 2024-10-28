set(executable_name "Example-IMGUI")
add_executable(${executable_name} main.cpp)
target_link_libraries(${executable_name} PRIVATE imgui::imgui SDL3::SDL3)
