// System Includes
#include <stdio.h>

// Project Includes
#include "SDL3/SDL.h"
#include "SDL3/SDL_main.h"

// Screen dimension constants
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

int main(int argc, char* argv[])
{
	// The window we'll be rendering to
	SDL_Window* window = NULL;

	// The surface contained by the window
	SDL_Surface* screenSurface = NULL;

	// Initialize SDL
	if(SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
	}
	else 
	{
		// Create window
		window = SDL_CreateWindow("SDL Tutorial", 
				SCREEN_WIDTH,
				SCREEN_HEIGHT,
				0
		);
		
		if(window == NULL)
		{
			printf("Window could not be create! SDL_Error: %s\n", SDL_GetError());
		}
		else
		{
			// Get window surface
			screenSurface = SDL_GetWindowSurface(window);

			//Fill the surface white
			SDL_FillSurfaceRect( screenSurface, NULL, SDL_MapSurfaceRGB( screenSurface, 0xFF, 0xFF, 0xFF ) );

			//Update the surface
            SDL_UpdateWindowSurface( window );

            //Hack to get window to stay up
            SDL_Event e; 
			bool quit = false; 
			while( quit == false ){ while( SDL_PollEvent( &e ) ){ if( e.type == SDL_EVENT_QUIT ) quit = true; } }

		}
	}

    //Destroy window
    SDL_DestroyWindow( window );

    //Quit SDL subsystems
    SDL_Quit();

    return 0;
}
