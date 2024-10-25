set(executable_name "hello-sdl")

add_executable(${executable_name} hello_SDL.cpp)

target_link_libraries(${executable_name} PRIVATE 
	SDL3::SDL3
)