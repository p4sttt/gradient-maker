#include "window/Window.hpp"
#include "utils/ColorUtils.hpp"
#include "math/LinearInterpolation.hpp"
#include "constants.hpp"
#include <string>

int main(int argc, char *argv[]) {
  int width = constants::WINDOW_WIDTH;
  int height = constants::WINDOW_HEIGHT;
  int redStart, greenStart, blueStart;
  int redEnd, greenEnd, blueEnd;
  Window *window = new Window();

  if (!window->isInitialized()) {
    return 1;
  }

  // pring all programs arguments
  for (int i = 0; i < argc; ++i) {
    std::string arg = std::string(argv[i]);
    std::cout << i << ": " << arg << std::endl;
  }

  // initialize start color and interpolation function for each color
  std::string hexStart = std::string(argv[1]);
  std::string hexEnd = std::string(argv[2]);
  ColorUtils::hexToRGB(hexStart, redStart, greenStart, blueStart);
  ColorUtils::hexToRGB(hexEnd, redEnd, greenEnd, blueEnd);
  LinearInterpolation *redInterpolation = new LinearInterpolation(0, redStart, width, redEnd);
  LinearInterpolation *greenInterpolation = new LinearInterpolation(0, greenStart, width, greenEnd);
  LinearInterpolation *blueInterpolation = new LinearInterpolation(0, blueStart, width, blueEnd);

  SDL_Event event;
  bool quit = false;
  while (!quit) {
    SDL_PollEvent(&event);
    if (event.type == SDL_QUIT) {
      quit = true;
    }
  
    window->clear();

    for (int x = 0; x < width; ++x) {
      Uint8 red = static_cast<Uint8>(redInterpolation->interpolate(x));
      Uint8 green = static_cast<Uint8>(greenInterpolation->interpolate(x));
      Uint8 blue = static_cast<Uint8>(blueInterpolation->interpolate(x)); 
      SDL_SetRenderDrawColor(window->getRenderer(), red, green, blue, 255);
      for (int y = 0; y < height; ++y) {
        SDL_RenderDrawPoint(window->getRenderer(), x, y);
      }
    }

    window->present();
  }

  delete window;
  delete redInterpolation;
  delete greenInterpolation;
  delete blueInterpolation;

  return 0;
}
