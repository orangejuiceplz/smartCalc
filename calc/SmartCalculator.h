#ifndef SMARTCALCULATOR_H
#define SMARTCALCULATOR_H

#include <iostream>

#include <cmath>

#include <complex>

#include <vector>

#include <numeric>

#include <algorithm>

#include <map>

#include <string>

#include <fstream>

#include <cstdio>

#ifndef M_PI
#define M_PI 3.14159265358979323846 // approximation for pi
#endif

#include "GraphingCalculator.h"

class SmartCalculator {
  public:
    // Basic arithmetic operations
    double add(double a, double b);
  double subtract(double a, double b);
  double multiply(double a, double b);
  double divide(double a, double b);
  double exponent(double base, double exp);

  // Quadratic equation solver
  void solveQuadratic(double a, double b, double c);

  // Angle conversion
  double degToRad(double deg);
  double radToDeg(double rad);

  // Standard deviation calculation
  double standardDeviation(double data[], int n);

  // Simplifying square roots
  void simplifySqrt(int n);

  // Trigonometric functions
  double sine(double x);
  double cosine(double x);
  double tangent(double x);

  // Logarithmic and exponential functions
  double naturalLog(double x);
  double logBase10(double x);
  double exp(double x);

  // Complex number operations
  std::complex < double > complexAdd(std::complex < double > a, std::complex < double > b);
  std::complex < double > complexSubtract(std::complex < double > a, std::complex < double > b);
  std::complex < double > complexMultiply(std::complex < double > a, std::complex < double > b);
  std::complex < double > complexDivide(std::complex < double > a, std::complex < double > b);
  double complexMagnitude(std::complex < double > a);
  double complexArgument(std::complex < double > a);

  // Statistical functions
  double mean(std::vector < double > data);
  double median(std::vector < double > data);
  double mode(std::vector < double > data);
  double variance(std::vector < double > data);

  // Number theory functions
  bool isPrime(int n);
  std::vector < int > factorize(int n);

  // Surface area calculations
  double surfaceAreaRectangularPrism(double l, double w, double h);
  double surfaceAreaCylinder(double r, double h);
  double surfaceAreaCircle(double r);
  double arcLengthCircle(double r, double centralAngleInDegrees);

  // Operations runner
  void run();

  // Graphing function
  void graphFunction();
};

#endif
