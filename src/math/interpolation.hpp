#ifndef INTERPOLATION_HPP
#define INTERPOLATION_HPP

class Interpolation {
 public:
  virtual double interpolate(double x) const = 0;
  virtual ~Interpolation() = default;
};

#endif