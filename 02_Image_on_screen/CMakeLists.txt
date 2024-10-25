set(executable_name "image-on-screen")

add_executable(${executable_name} image_on_screen.cpp)

target_link_libraries(${executable_name} PRIVATE 
	SDL3::SDL3
)

add_custom_command(TARGET ${executable_name} POST_BUILD
                   COMMAND ${CMAKE_COMMAND} -E copy_if_different
                       ${CMAKE_CURRENT_SOURCE_DIR}/AK47.bmp
                       $<TARGET_FILE_DIR:${executable_name}>
                   )

# install(FILES ${CMAKE_CURRENT_SOURCE_DIR}/AK47.bmp DESTINATION ${CMAKE_BINARY_DIR}/bin)