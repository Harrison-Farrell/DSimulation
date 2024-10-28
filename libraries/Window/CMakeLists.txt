set(library_name "DSIM_Window")

add_library(${library_name} src/Window.cpp)

target_include_directories(${library_name} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

target_link_libraries(${library_name} PRIVATE SDL3::SDL3)
