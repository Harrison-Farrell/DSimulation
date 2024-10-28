// System Includes
#include <format>
#include <stdexcept>
#include <string>

// Local Includes
#include "Window.h"

DSIM::Window::Window(int width, int height)
  : m_screenWidth(width), m_screenHeight(height) {
  // initialize SDL subsystem
  if (SDL_Init(SDL_INIT_VIDEO) < 0) {
    // attempt to initialize SDL. Throw error if failure
    std::string error =
      ("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
    throw std::runtime_error(error);
  }

  // create window
  m_window = SDL_CreateWindow("SDL Window", m_screenWidth, m_screenHeight, 0);
  // throw error if failure to create SDL Window
  if (m_window == NULL) {
    std::string error =
      ("Window could not be created. SDL_Error: %s\n", SDL_GetError());
    throw std::runtime_error(error);
  }

  // get window surface
  m_screenSurface = SDL_GetWindowSurface(m_window);

  // fill the surface white
  SDL_FillSurfaceRect(m_screenSurface, NULL,
                      SDL_MapSurfaceRGB(m_screenSurface, 0xFF, 0xFF, 0xFF));

  // update the surface
  SDL_UpdateWindowSurface(m_window);
};

DSIM::Window::~Window() {
  // destory loaded media surface
  SDL_DestroySurface(m_loadedMedia);
  m_loadedMedia = NULL;

  // destroy window
  SDL_DestroyWindow(m_window);
  m_window = NULL;

  // quit SDL subsystems
  SDL_Quit();
}

bool DSIM::Window::loadBMP(std::string media_path) {
  bool success_flag = true;

  // load BMP image
  m_loadedMedia = SDL_LoadBMP(media_path.c_str());

  // throw error on failure to load media
  if (m_loadedMedia == NULL) {
    std::string error =
      ("Unable to load image %s! SDL Error: %s\n", "AK47.bmp", SDL_GetError());
    throw std::runtime_error(error);
    success_flag = false;
  }

  return success_flag;
}

bool DSIM::Window::applyMedia() {
  return SDL_BlitSurface(m_loadedMedia, NULL, m_screenSurface, NULL);
}

bool DSIM::Window::updateWindow() { return SDL_UpdateWindowSurface(m_window); }