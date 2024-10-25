#include "common/logger.hpp"
#include "input/cli_parser.hpp"
#include "input/input_utils.hpp"

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

  return 0;
}
