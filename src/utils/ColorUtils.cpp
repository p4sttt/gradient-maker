#include "utils/ColorUtils.hpp"

namespace {
  int hexCharToInt(char c) {
    if (c >= '0' && c <= '9') {
      return c - '0';
    } else if (c >= 'A' && c <= 'F') {
      return c - 'A' + 10;
    } else if (c >= 'a' && c <= 'f') {
      return c - 'a' + 10;
    }
    return 0;
  }
}

namespace ColorUtils {
  void hexToRGB(const std::string &hex, int &r, int &g, int &b) {
    if (hex[0] != '#' || hex.length() != 7) {
      std::cerr << "Invalid hex color format" << std::endl;
      r = g = b = 0;
      return;
    }
    r = (hexCharToInt(hex[1]) * 16) + hexCharToInt(hex[2]);
    g = (hexCharToInt(hex[3]) * 16) + hexCharToInt(hex[4]);
    b = (hexCharToInt(hex[5]) * 16) + hexCharToInt(hex[6]);
  }
}
