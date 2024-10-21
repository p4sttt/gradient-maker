#ifndef LINEAR_INTERPOLATION_HPP
#define LINEAR_INTERPOLATION_HPP

class LinearInterpolation {
  public:
    LinearInterpolation(double x1, double y1, double x2, double y2);
    ~LinearInterpolation();

    double interpolate(double x) const;

  private:
    double x1, y1, x2, y2;
};

#endif
