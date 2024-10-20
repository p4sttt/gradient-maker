#include "window/window.hpp"

int main() {
  Window *window = new Window();
  bool quit = false;
  SDL_Event event;

  if (!window->isInitialized()) {
    return 1;
  }

  while (!quit) {
    SDL_PollEvent(&event);
    if (event.type == SDL_QUIT) {
      quit = true;
    }
  
    window->clear();

    SDL_SetRenderDrawColor(window->getRenderer(), 255, 0, 0, 255);
    for (int i = 0; i < 800; ++i) {
      SDL_RenderDrawPoint(window->getRenderer(), i, i);
    }

    window->present();
  }

  delete window;
  return 0;
}
