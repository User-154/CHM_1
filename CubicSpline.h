#pragma once

class CubicSpline {
private:
    std::vector<double> x, y;
    std::vector<double> a, b, c, d;
    int n;

public:
    CubicSpline(const std::vector<double>& x_, const std::vector<double>& y_);

    double eval(double X) const;
    double deriv(double X) const;
    double deriv2(double X) const;
};
