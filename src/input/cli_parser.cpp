#include "input/cli_parser.hpp"

CLIParser::CLIParser(int argc, char *argv[]) : argc(argc), argv(argv) {
  if (argc < 2) {
    Logger::error("Parsing failed! Too few arguments passed: " + std::to_string(argc - 1));
    throw std::invalid_argument(
        "Illegal arguments count! You must use -bi or -li flags for "
        "bilinear and linear interpolation.");
    return;
  }

  auto it = flag2type.find(argv[1]);
  if (it != flag2type.end()) {
    command = it->second;
  } else {
    Logger::debug("Unknown flag: " + std::string(argv[1]));
    throw std::invalid_argument("Unknown flag passed! You can use -bi or -li flags.");
  }
}

CLIParser::~CLIParser() {}

const InterpolationType &CLIParser::getInterpolationType() const {
  return command;
}

int **CLIParser::parseBilinearInterpolationColors() {
  if (argc != 6) {
    Logger::error("Parsing bilinear interpolation colors failed! Passed colors count: " +
                  std::to_string(argc - 2));
    throw std::invalid_argument(
        "Illegal arguments count! You must use -bi flag with 4 "
        "arguments: left-top, right-top, right-bottom, left-bottom edges colors in hex format.");
    return nullptr;
  }

  int **colors = new int *[4];
  for (int i = 0; i < 4; i++) {
    colors[i] = new int[3];
    Logger::debug("Parsing color: " + std::string(argv[i + 2]));
    InputUtils::hexToRGB(argv[i + 2], colors[i][0], colors[i][1], colors[i][2]);
    Logger::debug("Parsed color: " + std::to_string(colors[i][0]) + " " +
                  std::to_string(colors[i][1]) + " " + std::to_string(colors[i][2]));
  }

  return colors;
}

int **CLIParser::parseLinearInterpolationColors() {
  if (argc != 4) {
    Logger::error("Parsing linear interpolation colors failed! Passed colors count: " +
                  std::to_string(argc - 2));
    throw std::invalid_argument(
        "Illegal arguments count! You must use -li flag with 2 "
        "arguments: left and right colors in hex format.");
    return nullptr;
  }

  int **colors = new int *[2];
  for (int i = 0; i < 2; i++) {
    colors[i] = new int[3];
    InputUtils::hexToRGB(argv[i + 2], colors[i][0], colors[i][1], colors[i][2]);
  }

  return colors;
}