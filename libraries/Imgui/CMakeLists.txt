add_library(
  imgui STATIC
  # Main Imgui files
  ${CMAKE_CURRENT_SOURCE_DIR}/imgui.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/imgui.h
  ${CMAKE_CURRENT_SOURCE_DIR}/imconfig.h
  ${CMAKE_CURRENT_SOURCE_DIR}/imgui_draw.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/imgui_tables.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/imgui_widgets.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/imconfig.h
  ${CMAKE_CURRENT_SOURCE_DIR}/imgui_demo.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/imgui_draw.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/imgui_internal.h
  ${CMAKE_CURRENT_SOURCE_DIR}/imgui_tables.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/imgui_widgets.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/imgui.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/imgui.h
  ${CMAKE_CURRENT_SOURCE_DIR}/imstb_rectpack.h
  ${CMAKE_CURRENT_SOURCE_DIR}/imstb_textedit.h
  ${CMAKE_CURRENT_SOURCE_DIR}/imstb_truetype.h
  ${CMAKE_CURRENT_SOURCE_DIR}/backends/imgui_impl_opengl3_loader.h
  ${CMAKE_CURRENT_SOURCE_DIR}/backends/imgui_impl_opengl3.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/backends/imgui_impl_opengl3.h
  ${CMAKE_CURRENT_SOURCE_DIR}/backends/imgui_impl_sdl3.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/backends/imgui_impl_sdl3.h
  ${CMAKE_CURRENT_SOURCE_DIR}/backends/imgui_impl_sdlrenderer3.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/backends/imgui_impl_sdlrenderer3.h
)
add_library(imgui::imgui ALIAS imgui)

find_package(OpenGL REQUIRED)
target_link_libraries(imgui PUBLIC OpenGL::GL SDL3::SDL3)
target_include_directories(
  imgui PUBLIC ${CMAKE_CURRENT_SOURCE_DIR} ${CMAKE_CURRENT_SOURCE_DIR}/backends/
)
