#include "common/logger.hpp"
#include "input/cli_parser.hpp"
#include "input/input_utils.hpp"
#include "math/interpolation.hpp"
#include "math/linear_interpolation.hpp"
#include "window/window.hpp"
#include "window/window_config.hpp"

int main(int argc, char *argv[]) {
  CLIParser *cliParser = nullptr;
  try {
    cliParser = new CLIParser(argc, argv);

  } catch (const std::exception &e) {
    Logger::error(e.what());
    return 1;
  }

  Logger::debug(
      "Input Interpolation Type: " +
      InputUtils::interpolationTypeToString((*cliParser).getInterpolationType()));

  int **colors = nullptr;
  int colorsCount;

  try {
    switch ((*cliParser).getInterpolationType()) {
      case InterpolationType::Bilinear:
        colors = (*cliParser).parseBilinearInterpolationColors();
        colorsCount = 4;
        break;

      case InterpolationType::Linear:
        colors = (*cliParser).parseLinearInterpolationColors();
        colorsCount = 2;
        break;
    }
  } catch (const std::exception &e) {
    Logger::error(e.what());
    return 1;
  }

  for (int i = 0; i < colorsCount; i++) {
    Logger::debug("Color " + std::to_string(i) + ": " + std::to_string(colors[i][0]) + " " +
                  std::to_string(colors[i][1]) + " " + std::to_string(colors[i][2]));
  }

  Window window(WindowConfig::WIDTH, WindowConfig::HEIGHT, WindowConfig::TITLE);
  SDL_Event event;
  Interpolation *interpolation[3];
  bool running = true;

  switch ((*cliParser).getInterpolationType()) {
    case InterpolationType::Bilinear:
      Logger::error("Bilinear interpolation is not implemented yet");
      return 1;
      break;

    case InterpolationType::Linear:
      for (int i = 0; i < 3; i++) {
        interpolation[i] = new LinearInterpolation(0, colors[0][i], WindowConfig::WIDTH, colors[1][i]);
      }
      break;
  }

  while (running) {
    while (SDL_PollEvent(&event)) {
      if (event.type == SDL_QUIT) {
        running = false;
      }
    }

    window.clear();
    for (int x = 0; x < WindowConfig::WIDTH; x++) {
      Uint8 red = static_cast<Uint8>(interpolation[0]->interpolate(x));
      Uint8 green = static_cast<Uint8>(interpolation[1]->interpolate(x));
      Uint8 blue = static_cast<Uint8>(interpolation[2]->interpolate(x));
      for (int y = 0; y < WindowConfig::HEIGHT; y++) {
        SDL_SetRenderDrawColor(&window.getRenderer(), red, green, blue, 255);
        SDL_RenderDrawPoint(&window.getRenderer(), x, y);
      }
    }
    window.present();
  }

  return 0;
}
