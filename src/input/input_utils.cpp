#include "input/input_utils.hpp"

namespace {
int hexCharToInt(const char &c) {
  if (c >= '0' && c <= '9') {
    return c - '0';
  } else if (c >= 'A' && c <= 'F') {
    return c - 'A' + 10;
  } else if (c >= 'a' && c <= 'f') {
    return c - 'a' + 10;
  }

  Logger::warn("Can't convert hex char to int: " + c);
  return 0;
}
}  // namespace

namespace InputUtils {

const std::string
interpolationTypeToString(const InterpolationType &interpolationType) {
  switch (interpolationType) {
    case InterpolationType::Bilinear:
      return "Bilinear";
    case InterpolationType::Linear:
      return "Linear";
    default:
      return "unknown";
  }
}

void hexToRGB(const std::string &hex, int &r, int &g, int &b) {
  if (hex.length() != 6) {
    throw std::invalid_argument("Invalid hex color format: " + hex);
    r = g = b = 0;
    return;
  }
  r = (hexCharToInt(hex[0]) * 16) + hexCharToInt(hex[1]);
  g = (hexCharToInt(hex[2]) * 16) + hexCharToInt(hex[3]);
  b = (hexCharToInt(hex[4]) * 16) + hexCharToInt(hex[5]);
}

}  // namespace InputUtils