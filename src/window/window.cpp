#include "window/window.hpp"

Window::Window() {
  if (SDL_Init(SDL_INIT_VIDEO) < 0) {
    std::cerr << "Failed to initialize SDL" << std::endl;
    return;
  } 

  window = SDL_CreateWindow("www", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, SDL_WINDOW_SHOWN);
  if (window == nullptr) {
    std::cerr << "Failed to create SDL window" << std::endl;
    return;
  }

  renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
  if (renderer == nullptr) {
    std::cerr << "Failed to create SDL renderer" << std::endl;
    return;
  }

  std::cout << "window has been successfully initialized" << std::endl;
  initialized = true;
}

Window::~Window() {
  if (window) {
    SDL_DestroyWindow(window);
  }
  if (renderer) {
    SDL_DestroyRenderer(renderer);
  }
  SDL_Quit();
  std::cout << "window has been destroyd" << std::endl;
}

void Window::clear() {
  if (initialized) {
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);
  }
}

void Window::present() {
  if (initialized) {
    SDL_RenderPresent(renderer);
  }
}

SDL_Renderer *Window::getRenderer() const {
  return renderer;
}

bool Window::isInitialized() const {
  return initialized;
}
