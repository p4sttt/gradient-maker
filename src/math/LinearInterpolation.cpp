#include "LinearInterpolation.hpp"

LinearInterpolation::LinearInterpolation(double x1, double y1, double x2, double y2) {
  this->x1 = x1;
  this->y1 = y1;
  this->x2 = x2;
  this->y2 = y2;
}

LinearInterpolation::~LinearInterpolation() {
}

double LinearInterpolation::interpolate(double x) const {
  return y1 + ((y2-y1)/(x2-x1))*(x-x1);
}
