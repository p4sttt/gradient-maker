#include "math/linear_interpolation.hpp"

LinearInterpolation::LinearInterpolation(const double &x1, const double &y1,
                                         const double &x2, const double &y2)
    : x1(x1), y1(y1), x2(x2), y2(y2) {
  Logger::debug("LinearInterpolation successfully created");
}

LinearInterpolation::~LinearInterpolation() {}

double LinearInterpolation::interpolate(double x) const {
  return y1 + ((y2 - y1) / (x2 - x1)) * (x - x1);
}
