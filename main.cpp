// System Includes
#include <iostream>
#include <stdexcept>

// Local Includes
#include "Window.h"

int main() {
  // main loop flag
  bool main_loop_flag = false;

  // event handler e;
  SDL_Event e;

  try {
    DSIM::Window newWindow(640, 480);
    newWindow.loadBMP("AK47.bmp");

    // main function loop
    while (!main_loop_flag) {
      while (SDL_PollEvent(&e) != 0) {
        // user request quit
        if (e.type == SDL_EVENT_QUIT) {
          main_loop_flag = true;
        }
      }
      newWindow.applyMedia();
      newWindow.updateWindow();
    }
  } catch (const std::exception& e) {
    std::cout << "Exception: " << e.what() << std::endl;
  };

  // exit status of 0 stands for success
  return 0;
}