cmake_minimum_required(VERSION 3.7)

project(SDL3_Tutorials)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)
set(CMAKE_CXX_EXTENSIONS FALSE)

include(FetchContent)
FetchContent_Declare(
	SDL2
	GIT_REPOSITORY https://github.com/libsdl-org/SDL.git
	GIT_TAG 344546b4ea79a070e8b6bcccab542551ab5bdf55 # latest main 25/Oct/24
)
FetchContent_MakeAvailable(SDL2)


add_executable(${PROJECT_NAME} main.cpp)
target_link_libraries(${PROJECT_NAME} PRIVATE 
	SDL3::SDL3
)