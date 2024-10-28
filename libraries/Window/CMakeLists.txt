set(library_name "DSIM_Window")

add_library(${library_name} src/Window.cpp)

target_include_directories(${library_name} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

target_link_libraries(${library_name} PRIVATE SDL3::SDL3)

add_custom_command(
  TARGET ${library_name}
  POST_BUILD
  COMMAND ${CMAKE_COMMAND} -E copy_if_different ${CMAKE_CURRENT_SOURCE_DIR}/artifacts/AK47.bmp
          $<TARGET_FILE_DIR:${library_name}>
)
