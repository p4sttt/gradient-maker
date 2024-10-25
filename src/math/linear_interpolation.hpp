#ifndef LINEAR_INTERPOLATION_HPP
#define LINEAR_INTERPOLATION_HPP

#include "common/logger.hpp"
#include "math/interpolation.hpp"

class LinearInterpolation : public Interpolation {
 public:
  LinearInterpolation();
  LinearInterpolation(const double &x1, const double &y1, const double &x2, const double &y2);
  ~LinearInterpolation();

  double interpolate(double x) const override;

 private:
  const double x1, y1, x2, y2;
};

#endif
