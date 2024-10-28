cmake_minimum_required(VERSION 3.7)

project(DSIM)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)
set(CMAKE_CXX_EXTENSIONS FALSE)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

include(FetchContent)

FetchContent_Declare(
  SDL3
  GIT_REPOSITORY https://github.com/libsdl-org/SDL.git
  GIT_TAG 344546b4ea79a070e8b6bcccab542551ab5bdf55 # latest main 25/Oct/24
)
FetchContent_MakeAvailable(SDL3)

add_subdirectory(libraries)

add_executable(${PROJECT_NAME} main.cpp)
target_link_libraries(
  ${PROJECT_NAME}
  PRIVATE # 3rd party libraries
          SDL3::SDL3 imgui::imgui
          # Local libraries
          DSIM_Window
)
