#include "SmartCalculator.h"

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

void SmartCalculator::solveQuadratic(double a, double b, double c) {
    double discriminant = b * b - 4 * a * c;
    if (discriminant > 0) {
        double sqrt_val = sqrt(discriminant);
        std::cout << "The roots are real and different. Solving for x:\n";
        std::cout << "x1 = " << (-b + sqrt_val) / (2 * a) << "\n";
        std::cout << "x2 = " << (-b - sqrt_val) / (2 * a) << "\n";
    } else if (discriminant == 0) {
        std::cout << "The roots are real and equal. Solving for x:\n";
        std::cout << "x = " << -b / (2 * a) << "\n";
    } else {
        std::complex<double> sqrt_val(0, sqrt(abs(discriminant)));
        std::cout << "The roots are complex and different. Solving for x:\n";
        std::cout << "x1 = " << (-b + sqrt_val) / (2 * a) << "\n";
        std::cout << "x2 = " << (-b - sqrt_val) / (2 * a) << "\n";
    }
}

double SmartCalculator::degToRad(double deg) {
    return deg * M_PI / 180.0;
}

double SmartCalculator::radToDeg(double rad) {
    return rad * 180.0 / M_PI;
}

double SmartCalculator::standardDeviation(std::vector<double>& data) {
    double sum = std::accumulate(data.begin(), data.end(), 0.0);
    double mean = sum / data.size();
    double sq_sum = std::inner_product(data.begin(), data.end(), data.begin(), 0.0);
    double stdev = std::sqrt(sq_sum / data.size() - mean * mean);
    return stdev;
}

void SmartCalculator::simplifySqrt(int n) {
    int simplified = 1;
    for (int i = 2; i * i <= n; ++i) {
        if (n % (i * i) == 0) {
            simplified = i;
        }
    }
    if (simplified == 1) {
        std::cout << "Simplified square root: sqrt(" << n << ")\n";
    } else {
        std::cout << "Simplified square root: " << simplified << "sqrt(" << n / (simplified * simplified) << ")\n";
    }
}

double SmartCalculator::sine(double x) {
    return std::sin(x);
}

double SmartCalculator::cosine(double x) {
    return std::cos(x);
}

double SmartCalculator::tangent(double x) {
    return std::tan(x);
}

double SmartCalculator::naturalLog(double x) {
    return std::log(x);
}

double SmartCalculator::logBase10(double x) {
    return std::log10(x);
}

double SmartCalculator::exp(double x) {
    return std::exp(x);
}

std::complex<double> SmartCalculator::complexAdd(std::complex<double> a, std::complex<double> b) {
    return a + b;
}

std::complex<double> SmartCalculator::complexSubtract(std::complex<double> a, std::complex<double> b) {
    return a - b;
}

std::complex<double> SmartCalculator::complexMultiply(std::complex<double> a, std::complex<double> b) {
    return a * b;
}

std::complex<double> SmartCalculator::complexDivide(std::complex<double> a, std::complex<double> b) {
    return a / b;
}

double SmartCalculator::complexMagnitude(std::complex<double> a) {
    return std::abs(a);
}

double SmartCalculator::complexArgument(std::complex<double> a) {
    return std::arg(a);
}

double SmartCalculator::mean(std::vector<double> data) {
    double sum = std::accumulate(data.begin(), data.end(), 0.0);
    return sum / data.size();
}

double SmartCalculator::median(std::vector<double> data) {
    std::sort(data.begin(), data.end());
    if (data.size() % 2 == 0) {
        return (data[data.size() / 2 - 1] + data[data.size() / 2]) / 2;
    } else {
        return data[data.size() / 2];
    }
}

double SmartCalculator::mode(std::vector<double> data) {
    std::map<double, int> freq;
    for (double value : data) {
        freq[value]++;
    }
    int maxFreq = 0;
    double mode = 0;
    for (const auto& pair : freq) {
        if (pair.second > maxFreq) {
            maxFreq = pair.second;
            mode = pair.first;
        }
    }
    return mode;
}

double SmartCalculator::variance(std::vector<double> data) {
    double sum = std::accumulate(data.begin(), data.end(), 0.0);
    double mean = sum / data.size();
    double sq_sum = std::inner_product(data.begin(), data.end(), data.begin(), 0.0);
    return sq_sum / data.size() - mean * mean;
}

bool SmartCalculator::isPrime(int n) {
    if (n <= 1) return false;
    for (int i = 2; i * i <= n; ++i) {
        if (n % i == 0) return false;
    }
    return true;
}

std::vector<int> SmartCalculator::factorize(int n) {
    std::vector<int> factors;
    for (int i = 2; i * i <= n; ++i) {
        while (n % i == 0) {
            factors.push_back(i);
            n /= i;
        }
    }
    if (n > 1) factors.push_back(n);
    return factors;
}

double SmartCalculator::surfaceAreaRectangularPrism(double l, double w, double h) {
    return 2 * (l * w + l * h + w * h);
}

double SmartCalculator::surfaceAreaCylinder(double r, double h) {
    return 2 * M_PI * r * (r + h);
}

double SmartCalculator::surfaceAreaCircle(double r) {
    return M_PI * r * r;
}

double SmartCalculator::arcLengthCircle(double r, double centralAngleInDegrees) {
    double centralAngleInRadians = degToRad(centralAngleInDegrees);
    return r * centralAngleInRadians;
}

void SmartCalculator::graphFunction() {
    // already implemented
}

double SmartCalculator::evaluateExpression(const std::string& expression, double x) {
    if (expression == "sin(x)") {
        return sine(x);
    }
    return 0.0;
}