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

class SmartCalculator {
  public:
    // Basic arithmetic operations
    double add(double a, double b) {
      return a + b;
    }
  double subtract(double a, double b) {
    return a - b;
  }
  double multiply(double a, double b) {
    return a * b;
  }
  double divide(double a, double b) {
    if (b != 0) return a / b;
    else {
      std::cout << "Error: Division by zero is not allowed.\n";
      return 0;
    }
  }
  double exponent(double base, double exp) {
    return pow(base, exp);
  }

  // Quadratic equation solver
  void solveQuadratic(double a, double b, double c) {
    double discriminant = b * b - 4 * a * c;
    double sqrt_val = sqrt(abs(discriminant));

    if (discriminant > 0) {
      std::cout << "The roots are real and different. Solving for x:\n";
      std::cout << "x1 = " << (-b + sqrt_val) / (2 * a) << "\n";
      std::cout << "x2 = " << (-b - sqrt_val) / (2 * a) << "\n";
    } else if (discriminant == 0) {
      std::cout << "The roots are real and the same. Solving for x:\n";
      std::cout << "x = " << -b / (2 * a) << "\n"; // only one solution since the roots are equal
    } else {
      std::cout << "The roots are complex. Solving for x:\n";
      std::cout << "x1 = " << -b / (2 * a) << " + i" << sqrt_val << "\n";
      std::cout << "x2 = " << -b / (2 * a) << " - i" << sqrt_val << "\n";
    }
  }

  // angle conversion built in with C++
  double degToRad(double deg) {
    return deg * (M_PI / 180.0);
  }
  double radToDeg(double rad) {
    return rad * (180.0 / M_PI);
  }

  // Standard deviation calculation
  double standardDeviation(double data[], int n) {
    double sum = 0.0, mean, standardDeviation = 0.0;

    for (int i = 0; i < n; ++i) {
      sum += data[i];
    }

    mean = sum / n;

    for (int i = 0; i < n; ++i)
      standardDeviation += pow(data[i] - mean, 2);

    return sqrt(standardDeviation / n);
  }

  // simplfying sqRTS
  void simplifySqrt(int n) {
    int outside_root = 1;
    int inside_root = n;
    int d = 2;

    while (d * d <= inside_root) {
      if (inside_root % (d * d) == 0) {
        inside_root = inside_root / (d * d);
        outside_root = outside_root * d;
      } else {
        d = d + 1;
      }
    }

    std::cout << "Simplified form: " << outside_root << " sqrt(" << inside_root << ")" << std::endl;
  }

  // trig func c++
  double sine(double x) {
    return sin(x);
  }
  double cosine(double x) {
    return cos(x);
  }
  double tangent(double x) {
    return tan(x);
  }

  // log and e^x
  double naturalLog(double x) {
    return log(x);
  }
  double logBase10(double x) {
    return log10(x);
  }
  double exp(double x) {
    return exp(x);
  }

  // comp # oper
  std::complex < double > complexAdd(std::complex < double > a, std::complex < double > b) {
    return a + b;
  }
  std::complex < double > complexSubtract(std::complex < double > a, std::complex < double > b) {
    return a - b;
  }
  std::complex < double > complexMultiply(std::complex < double > a, std::complex < double > b) {
    return a * b;
  }
  std::complex < double > complexDivide(std::complex < double > a, std::complex < double > b) {
    return a / b;
  }
  double complexMagnitude(std::complex < double > a) {
    return abs(a);
  }
  double complexArgument(std::complex < double > a) {
    return arg(a);
  }

  // stat func
  double mean(std::vector < double > data) {
    double sum = std::accumulate(data.begin(), data.end(), 0.0);
    return sum / data.size();
  }

  double median(std::vector < double > data) {
    size_t size = data.size();
    std::sort(data.begin(), data.end());

    if (size % 2 == 0) {
      return (data[size / 2 - 1] + data[size / 2]) / 2;
    } else {
      return data[size / 2];
    }
  }

  double mode(std::vector < double > data) {
    std::map < double, int > freq;
    for (double num: data) {
      freq[num]++;
    }

    double mode = data[0];
    int max_count = 0;
    for (auto & i: freq) {
      if (i.second > max_count) {
        max_count = i.second;
        mode = i.first;
      }
    }

    return mode;
  }

  double variance(std::vector < double > data) {
    double mean_val = mean(data);
    double sq_sum = std::inner_product(data.begin(), data.end(), data.begin(), 0.0);
    return sq_sum / data.size() - mean_val * mean_val;
  }

  // num theory
  bool isPrime(int n) {
    if (n <= 1)
      return false;
    if (n <= 3)
      return true;

    if (n % 2 == 0 || n % 3 == 0)
      return false;

    for (int i = 5; i * i <= n; i = i + 6)
      if (n % i == 0 || n % (i + 2) == 0)
        return false;

    return true;
  }

  std::vector < int > factorize(int n) {
    std::vector < int > factors;
    while (n % 2 == 0) {
      factors.push_back(2);
      n = n / 2;
    }

    for (int i = 3; i <= sqrt(n); i = i + 2) {
      while (n % i == 0) {
        factors.push_back(i);
        n = n / i;
      }
    }

    if (n > 2)
      factors.push_back(n);

    return factors;
  }

  double surfaceAreaRectangularPrism(double l, double w, double h) {
    return 2 * l * w + 2 * l * h + 2 * w * h;
  }

  double surfaceAreaCylinder(double r, double h) {
    return 2 * M_PI * r * (h + r);
  }

  double surfaceAreaCircle(double r) {
    return M_PI * r * r;
  }

  double arcLengthCircle(double r, double centralAngleInDegrees) {
    return 2 * M_PI * r * (centralAngleInDegrees / 360.0);
  }

  // operations runner
  void run() {
    std::string operation;
    double num1, num2;

    while (true) {
      std::cout << "Enter operation (add, subtract, multiply, divide, exponent, solveQuadratic, convertAngle, calculateStdDev, simplifySqrt, trigFunction, logExpFunction, complexOperation, statisticalFunction, numberTheoryFunction, surfaceAreaRectangularPrism, surfaceAreaCylinder, surfaceAreaCircle, arcLengthCircle, quit): ";
      std::cin >> operation;

      if (operation == "quit") {
        
        std::cout << "thamks for using!" << std::endl;

        break;
      }

      if (operation.find("add") == 0 || operation.find("subtract") == 0 || operation.find("multiply") == 0 || operation.find("divide") == 0 || operation.find("exponent") == 0) {
        std::cout << "Enter first number: ";
        std::cin >> num1;
        std::cout << "Enter second number: ";
        std::cin >> num2;

        if (operation.find("add") == 0) {
          std::cout << "Result: " << add(num1, num2) << std::endl;
        } else if (operation.find("subtract") == 0) {
          std::cout << "Result: " << subtract(num1, num2) << std::endl;
        } else if (operation.find("multiply") == 0) {
          std::cout << "Result: " << multiply(num1, num2) << std::endl;
        } else if (operation.find("divide") == 0) {
          std::cout << "Result: " << divide(num1, num2) << std::endl;
        } else if (operation.find("exponent") == 0) {
          std::cout << "Result: " << exponent(num1, num2) << std::endl;
        }
      } else if (operation.find("solveQuadratic") == 0) {
        double a, b, c;
        std::cout << "Enter coefficients a, b, and c: ";
        std::cin >> a >> b >> c;
        solveQuadratic(a, b, c);
      } else if (operation.find("convertAngle") == 0) {
        double angle;
        char unit;
        std::cout << "Enter angle value and unit (r for radians, d for degrees): ";
        std::cin >> angle >> unit;
        if (unit == 'r') {
          std::cout << "Degrees: " << radToDeg(angle) << std::endl;
        } else if (unit == 'd') {
          std::cout << "Radians: " << degToRad(angle) << std::endl;
        } else {
          std::cout << "Invalid unit!" << std::endl;
        }
      } else if (operation.find("calculateStdDev") == 0) {
        int n;
        std::cout << "Enter the number of elements: ";
        std::cin >> n;
        double * data = new double[n];
        std::cout << "Enter the elements: ";
        for (int i = 0; i < n; ++i) {
          std::cin >> data[i];
        }
        std::cout << "Standard Deviation: " << standardDeviation(data, n) << std::endl;
        delete[] data;
      } else if (operation.find("simplifySqrt") == 0) {
        int n;
        std::cout << "Enter the number to simplify: ";
        std::cin >> n;
        simplifySqrt(n);
      } else if (operation.find("trigFunction") == 0) {
        double angle;
        std::cout << "Enter the angle in degrees: ";
        std::cin >> angle;
        std::cout << "Sin: " << sine(degToRad(angle)) << ", Cos: " << cosine(degToRad(angle)) << ", Tan: " << tangent(degToRad(angle)) << std::endl;
      } else if (operation.find("logExpFunction") == 0) {
        double x;
        std::cout << "Enter the value for logarithm/exponential calculation: ";
        std::cin >> x;
        std::cout << "Natural Log: " << naturalLog(x) << ", Log Base 10: " << log10(x) << std::endl;
      } else if (operation.find("complexOperation") == 0) {
        std::complex < double > a, b;
        double tempReal, tempImaginary;
        std::cout << "Enter the real and imaginary part of the first complex number: ";
        std::cin >> tempReal >> tempImaginary;
        a = std::complex < double > (tempReal, tempImaginary);

        std::cout << "Enter the real and imaginary part of the second complex number: ";
        std::cin >> tempReal >> tempImaginary;
        b = std::complex < double > (tempReal, tempImaginary);

        std::cout << "Addition: " << complexAdd(a, b).real() << " + " << complexAdd(a, b).imag() << "i" << std::endl;
        std::cout << "Subtraction: " << complexSubtract(a, b).real() << " + " << complexSubtract(a, b).imag() << "i" << std::endl;
        std::cout << "Multiplication: " << complexMultiply(a, b).real() << " + " << complexMultiply(a, b).imag() << "i" << std::endl;
        std::cout << "Division: " << complexDivide(a, b).real() << " + " << complexDivide(a, b).imag() << "i" << std::endl;
        std::cout << "Magnitude: " << complexMagnitude(complexMultiply(a, b)) << std::endl;
        std::cout << "Argument: " << complexArgument(complexMultiply(a, b)) << std::endl;
      } else if (operation.find("statisticalFunction") == 0) {
        std::vector < double > data;
        std::string inputStr;
        std::cout << "Enter the numbers for statistical analysis (enter 'done' when finished): ";
        while (std::cin >> inputStr && inputStr != "done") {
          data.push_back(std::stod(inputStr));
        }
        std::cout << "Mean: " << mean(data) << std::endl;
        std::cout << "Median: " << median(data) << std::endl;
        std::cout << "Mode: " << mode(data) << std::endl;
        std::cout << "Variance: " << variance(data) << std::endl;
      } else if (operation.find("numberTheoryFunction") == 0) {
        int n;
        std::cout << "Enter a number to check if it's prime: ";
        std::cin >> n;
        if (isPrime(n)) {
          std::cout << n << " is a prime number." << std::endl;
        } else {
          std::cout << n << " is not a prime number." << std::endl;
        }

        std::cout << "Factors of " << n << ": ";
        for (auto f: factorize(n)) {
          std::cout << f << " ";
        }
        std::cout << std::endl;
      } else if (operation.find("surfaceAreaRectangularPrism") == 0) {
        double l, w, h;
        std::cout << "Enter length, width, and height of the rectangular prism: ";
        std::cin >> l >> w >> h;
        std::cout << "Surface Area: " << surfaceAreaRectangularPrism(l, w, h) << std::endl;
      } else if (operation.find("surfaceAreaCylinder") == 0) {
        double r, h;
        std::cout << "Enter radius and height of the cylinder: ";
        std::cin >> r >> h;
        std::cout << "Surface Area: " << surfaceAreaCylinder(r, h) << std::endl;
      } else if (operation.find("surfaceAreaCircle") == 0) {
        double r;
        std::cout << "Enter radius of the circle: ";
        std::cin >> r;
        std::cout << "Surface Area: " << surfaceAreaCircle(r) << std::endl;
      } else {
        std::cout << "Unknown operation." << std::endl;
      }
    }
  }

};

int main() {
  SmartCalculator calc;
  calc.run();
  return 0;
}