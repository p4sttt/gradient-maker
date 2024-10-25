#ifndef WINDOW_HPP
#define WINDOW_HPP

#include <string>
#include <stdexcept>

#include "SDL.h"
#include "window/window_config.hpp"
#include "common/logger.hpp"

class Window {
 public:
  Window(const int &width, const int &height, const char *title);
  ~Window();

  void clear() const;
  void present() const;

  const SDL_Renderer &getRenderer() const;
  const SDL_Window &getWindow() const;

  const bool isInitialized() const;

 private:
  SDL_Window *window;
  SDL_Renderer *renderer;
  bool initialized = false;
};

#endif