// System Includes
#include <memory>
#include <thread>

// 3rd Party Includes
#include "SDL3/SDL.h"
#include "SDL3/SDL_main.h"

namespace DSIM {
class Window {
 private:
  /// @brief Initializaiton width for the window
  int m_screenWidth;
  /// @brief  Initialization hieght for the window
  int m_screenHeight;
  /// @brief Pointer to control the window properties
  SDL_Window* m_window = NULL;
  /// @brief Pointer to control the window surface properties
  SDL_Surface* m_screenSurface = NULL;
  /// @brief Pointer to control the loadedMedia surface properties
  SDL_Surface* m_loadedMedia = NULL;

  void createWindowThread();
  std::thread m_windowThread;

 public:
  /// @brief Default constructor
  /// @param width - window width
  /// @param height - window height
  Window(int width, int height);

  /// @brief Function to load external BMP file format into the Window frame
  /// @param media_path - system path to media BMP file
  /// @return success flag
  bool loadBMP(std::string media_path);

  bool applyMedia();

  bool updateWindow();

  ~Window();
};
}  // namespace DSIM