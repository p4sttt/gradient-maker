#ifndef WINDOW_HPP
#define WINDOW_HPP

#include <stdexcept>
#include <string>

#include "SDL.h"
#include "common/logger.hpp"
#include "window/window_config.hpp"

class Window {
 public:
  Window(const int &width, const int &height, const char *title);
  ~Window();

  void clear() const;
  void present() const;

  SDL_Renderer &getRenderer() const;
  SDL_Window &getWindow() const;

  const bool isInitialized() const;

 private:
  SDL_Window *window;
  SDL_Renderer *renderer;
  bool initialized = false;
};

#endif