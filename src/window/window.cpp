#include "window/window.hpp"

Window::Window(const int &width, const int &height, const char *title) {
  if (SDL_Init(SDL_INIT_VIDEO) < 0) {
    Logger::error("SDL Initialization error: " + static_cast<std::string>(SDL_GetError()));
    throw std::runtime_error("Failed to initialize SDL");
    return;
  }

  window =
      SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
                       width, height, SDL_WINDOW_SHOWN);

  if (window == nullptr) {
    Logger::error("SDL Window Creation Error: " + static_cast<std::string>(SDL_GetError()));
    throw std::runtime_error("Failed to create SDL window");
    return;
  }

  renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

  if (renderer == nullptr) {
    Logger::error("SDL Renderer Creation Error: " + static_cast<std::string>(SDL_GetError()));
    throw std::runtime_error("Failed to create SDL renderer");
    return;
  }

  Logger::debug("window has been successfully initialized");
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
}

void Window::clear() const {
  if (initialized) {
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);
  }
}

void Window::present() const {
  if (initialized) {
    SDL_RenderPresent(renderer);
  }
}

const SDL_Renderer &Window::getRenderer() const { return *renderer; }

const SDL_Window &Window::getWindow() const { return *window; }

const bool Window::isInitialized() const { return initialized; }