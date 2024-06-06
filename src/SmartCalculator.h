#pragma once
#ifndef SMARTCALCULATOR_H
#define SMARTCALCULATOR_H

#include <vector>
#include <complex>
#include <cmath>
#include <numeric>
#include <algorithm>
#include <map>
#include <string>
#include <iostream>

#ifndef M_PI
#define M_PI 3.14159265358979323846 // approximation for pi
#endif

class SmartCalculator {
public:
    double add(double a, double b);
    double subtract(double a, double b);
    double multiply(double a, double b);
    double divide(double a, double b);
    double exponent(double base, double exp);
    void solveQuadratic(double a, double b, double c);
    double degToRad(double deg);
    double radToDeg(double rad);
    double standardDeviation(std::vector<double>& data);
    void simplifySqrt(int n);
    double sine(double x);
    double cosine(double x);
    double tangent(double x);
    double naturalLog(double x);
    double logBase10(double x);
    double exp(double x);
    std::complex<double> complexAdd(std::complex<double> a, std::complex<double> b);
    std::complex<double> complexSubtract(std::complex<double> a, std::complex<double> b);
    std::complex<double> complexMultiply(std::complex<double> a, std::complex<double> b);
    std::complex<double> complexDivide(std::complex<double> a, std::complex<double> b);
    double complexMagnitude(std::complex<double> a);
    double complexArgument(std::complex<double> a);
    double mean(std::vector<double> data);
    double median(std::vector<double> data);
    double mode(std::vector<double> data);
    double variance(std::vector<double> data);
    bool isPrime(int n);
    std::vector<int> factorize(int n);
    double surfaceAreaRectangularPrism(double l, double w, double h);
    double surfaceAreaCylinder(double r, double h);
    double surfaceAreaCircle(double r);
    double arcLengthCircle(double r, double centralAngleInDegrees);
    void graphFunction();
    double evaluateExpression(const std::string& expression, double x);
    double convertCurrency(double amount, const std::string& fromCurrency, const std::string& toCurrency);
};

// Declare the WriteCallback function
static size_t WriteCallback(void* contents, size_t size, size_t nmemb, void* userp);

#endif // SMARTCALCULATOR_H
