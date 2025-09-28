#pragma once
#ifndef FINITEDIFFERENCE_H
#define FINITEDIFFERENCE_H

class FiniteDifference {
public:
    static double centralDifference(double (*f)(double), double x, double h);
    static double richardsonExtrapolation(double (*f)(double), double x, double h, double epsilon);
};

#endif
