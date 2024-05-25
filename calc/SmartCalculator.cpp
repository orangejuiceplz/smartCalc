#include "SmartCalculator.h"

// Basic arithmetic operations
double SmartCalculator::add(double a, double b) {
  return a + b;
}

double SmartCalculator::subtract(double a, double b) {
  return a - b;
}

double SmartCalculator::multiply(double a, double b) {
  return a * b;
}

double SmartCalculator::divide(double a, double b) {
  if (b != 0) return a / b;
  else {
    std::cout << "Error: Division by zero is not allowed.\n";
    return 0;
  }
}

double SmartCalculator::exponent(double base, double exp) {
  return pow(base, exp);
}

// Quadratic equation solver
void SmartCalculator::solveQuadratic(double a, double b, double c) {
  double discriminant = b * b - 4 * a * c;
  double sqrt_val = sqrt(abs(discriminant));

  if (discriminant > 0) {
    std::cout << "The roots are real and different. Solving for x:\n";
    std::cout << "x1 = " << (-b + sqrt_val) / (2 * a) << "\n";
    std::cout << "x2 = " << (-b - sqrt_val) / (2 * a) << "\n";
  } else if (discriminant == 0) {
    std::cout << "The roots are real and equal. Solving for x:\n";
    std::cout << "x = " << -b / (2 * a) << "\n";
  } else {
    std::cout << "The roots are complex and different. Solving for x:\n";
    std::cout << "x1 = " << (-b + sqrt_val * 1 i) / (2 * a) << "\n";
    std::cout << "x2 = " << (-b - sqrt_val * 1 i) / (2 * a) << "\n";
  }
}
