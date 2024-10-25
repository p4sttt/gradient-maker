#ifndef CLI_PARSER_HPP
#define CLI_PARSER_HPP

#include <map>
#include <stdexcept>

#include "common/logger.hpp"
#include "input/input_utils.hpp"
#include "input/interpolation_type.hpp"

class CLIParser {
 public:
  CLIParser(int argc, char *argv[]);
  ~CLIParser();

  const InterpolationType &getInterpolationType() const;

  int **parseBilinearInterpolationColors();
  int **parseLinearInterpolationColors();

 private:
  InterpolationType command;
  int argc;
  char **argv;
  const std::map<std::string, InterpolationType> flag2type = {
      {"-bi", InterpolationType::Bilinear},
      {"-li", InterpolationType::Linear}};
};

#endif
