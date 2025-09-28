#include <iostream>
#include <cmath>
#include <iomanip>
#include "GridGenerator.h"
#include "CubicSpline.h"
#include "FiniteDifference.h"
#include "Research.h"

double testFunction(double x) {
    return std::sin(x) + std::cos(2 * x);
}

double testFunctionDeriv(double x) {
    return std::cos(x) - 2 * std::sin(2 * x);
}

double testFunctionDeriv2(double x) {
    return -std::sin(x) - 4 * std::cos(2 * x);
}

int main() {

    setlocale(LC_ALL, "Russian");

    double a = 0.03;
    double b = 0.24;
    double epsilon = 0.01;

    std::cout << "Параметры варианта 15:\n";
    std::cout << "a = " << a << ", b = " << b << ", eps = " << epsilon << "\n\n";

    int n = 10;
    double r = 1.3;

    std::cout << "Равномерная сетка на отрезке [" << a << ", " << b << "]:\n";
    auto uniform = GridGenerator::uniformGrid(a, b, n);
    for (double x : uniform) {
        std::cout << std::fixed << std::setprecision(6) << x << " ";
    }
    std::cout << "\n\n";

    std::cout << "Адаптивная сетка (r = " << r << "):\n";
    auto adaptive = GridGenerator::adaptiveGrid(a, b, n, r);
    for (double x : adaptive) {
        std::cout << std::fixed << std::setprecision(6) << x << " ";
    }
    std::cout << "\n\n";

    // Исследование сплайна
    Research::conductSplineResearch(a, b, testFunction, testFunctionDeriv, testFunctionDeriv2);

    // Вычисление производной в центральной точке методом конечных разностей
    double center = (a + b) / 2;
    double epsilon = 1e-8;

    double exact_deriv = testFunctionDeriv(center);
    double fd_deriv = FiniteDifference::richardsonExtrapolation(testFunction, center, 0.01, epsilon);

    std::cout << "Центральная точка: " << center << "\n";
    std::cout << "Точное значение производной: " << exact_deriv << "\n";
    std::cout << "Численное значение (конечные разности): " << fd_deriv << "\n";
    std::cout << "Ошибка: " << std::abs(exact_deriv - fd_deriv) << "\n";
    std::cout << "Требуемая точность epsilon: " << epsilon << "\n";

    return 0;
}
