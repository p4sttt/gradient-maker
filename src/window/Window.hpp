#ifndef WINDOW_HPP
#define WINDOW_HPP

#include "SDL.h"
#include <string>
#include <iostream>
#include "constants.hpp"

class Window {
  public:
    Window();
    ~Window();

    void clear();
    void present();

    SDL_Renderer *getRenderer() const;

    bool isInitialized() const;

  private:
    SDL_Window *window = nullptr;
    SDL_Renderer *renderer = nullptr;
    bool initialized = false;
};

#endif
