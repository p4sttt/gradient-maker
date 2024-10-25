#ifndef INPUT_UTILS_HPP
#define INPUT_UTILS_HPP

#include <stdexcept>
#include <string>

#include "common/logger.hpp"
#include "input/interpolation_type.hpp"

namespace InputUtils {
const std::string interpolationTypeToString(const InterpolationType &interpolationType);

void hexToRGB(const std::string &hex, int &r, int &g, int &b);
}  // namespace InputUtils

#endif