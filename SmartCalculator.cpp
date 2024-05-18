#include <iostream>
#include <cmath>
#include <complex>
#include <vector>
#include <numeric>
#include <algorithm>
#include <map>
#include <string>

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

class SmartCalculator {
public:
    // Basic arithmetic operations
    double add(double a, double b) { return a + b; }
    double subtract(double a, double b) { return a - b; }
    double multiply(double a, double b) { return a * b; }
    double divide(double a, double b) {
        if(b!= 0) return a / b;
        else {
            std::cout << "Error: Division by zero is not allowed.\n";
            return 0;
        }
    }
    double exponent(double base, double exp) { return pow(base, exp); }

    // Quadratic equation solver
    void solveQuadratic(double a, double b, double c) {
        double discriminant = b*b - 4*a*c;
        double sqrt_val = sqrt(abs(discriminant));

        if (discriminant > 0) {
            std::cout << "Roots are real and different \n";
            std::cout << "Root 1 = " << (-b + sqrt_val) / (2*a) << "\n"
                      << "Root 2 = " << (-b - sqrt_val) / (2*a) << "\n";
        }
        else if (discriminant == 0) {
            std::cout << "Roots are real and same \n";
            std::cout << "Root 1 = Root 2 =" << -b / (2*a) << "\n";
        }
        else {
            std::cout << "Roots are complex \n";
            std::cout << "Root 1 = " << -b / (2*a) << " + i" << sqrt_val << "\n"
                      << "Root 2 = " << -b / (2*a) << " - i" << sqrt_val << "\n";
        }
    }

    // Angle conversion
    double degToRad(double deg) { return deg * (M_PI / 180.0); }
    double radToDeg(double rad) { return rad * (180.0 / M_PI); }

    // Standard deviation calculation
    double standardDeviation(double data[], int n) {
        double sum = 0.0, mean, standardDeviation = 0.0;

        for(int i = 0; i < n; ++i) {
            sum += data[i];
        }

        mean = sum/n;

        for(int i = 0; i < n; ++i)
            standardDeviation += pow(data[i] - mean, 2);

        return sqrt(standardDeviation / n);
    }

    // Simplify square root
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

    // Trigonometric functions
    double sine(double x) { return sin(x); }
    double cosine(double x) { return cos(x); }
    double tangent(double x) { return tan(x); }

    // Logarithmic and exponential functions
    double naturalLog(double x) { return log(x); }
    double logBase10(double x) { return log10(x); }
    double exp(double x) { return exp(x); }

    // Complex numbers operations
    std::complex<double> complexAdd(std::complex<double> a, std::complex<double> b) { return a + b; }
    std::complex<double> complexSubtract(std::complex<double> a, std::complex<double> b) { return a - b; }
    std::complex<double> complexMultiply(std::complex<double> a, std::complex<double> b) { return a * b; }
    std::complex<double> complexDivide(std::complex<double> a, std::complex<double> b) { return a / b; }
    double complexMagnitude(std::complex<double> a) { return abs(a); }
    double complexArgument(std::complex<double> a) { return arg(a); }

    // Statistical functions
    double mean(std::vector<double> data) {
        double sum = std::accumulate(data.begin(), data.end(), 0.0);
        return sum / data.size();
    }

    double median(std::vector<double> data) {
        size_t size = data.size();
        std::sort(data.begin(), data.end());

        if (size % 2 == 0) {
            return (data[size / 2 - 1] + data[size / 2]) / 2;
        } else {
            return data[size / 2];
        }
    }

    double mode(std::vector<double> data) {
        std::map<double, int> freq;
        for(double num : data) {
            freq[num]++;
        }

        double mode = data[0];
        int max_count = 0;
        for(auto& i : freq) {
            if(i.second > max_count) {
                max_count = i.second;
                mode = i.first;
            }
        }

        return mode;
    }

    double variance(std::vector<double> data) {
        double mean_val = mean(data);
        double sq_sum = std::inner_product(data.begin(), data.end(), data.begin(), 0.0);
        return sq_sum / data.size() - mean_val * mean_val;
    }

    // Number theory functions
    bool isPrime(int n) {
        if(n <= 1)
            return false;
        if(n <= 3)
            return true;

        if(n % 2 == 0 || n % 3 == 0)
            return false;

        for(int i = 5; i * i <= n; i = i + 6)
            if(n % i == 0 || n % (i + 2) == 0)
                return false;

        return true;
    }

    std::vector<int> factorize(int n) {
        std::vector<int> factors;
        while(n % 2 == 0) {
            factors.push_back(2);
            n = n/2;
        }

        for(int i = 3; i <= sqrt(n); i = i + 2) {
            while(n % i == 0) {
                factors.push_back(i);
                n = n/i;
            }
        }

        if(n > 2)
            factors.push_back(n);

        return factors;
    }

    // Interactive operation runner
    void run() {
        std::string operation;
        double num1, num2;

        while (true) {
            std::cout << "Enter operation (add, subtract, multiply, divide, exponent, quit): ";
            std::cin >> operation;

            if (operation == "quit") {
                break;
            }

            std::cout << "Enter first number: ";
            std::cin >> num1;
            std::cout << "Enter second number: ";
            std::cin >> num2;

            if (operation == "add") {
                std::cout << "Result: " << add(num1, num2) << std::endl;
            } else if (operation == "subtract") {
                std::cout << "Result: " << subtract(num1, num2) << std::endl;
            } else if (operation == "multiply") {
                std::cout << "Result: " << multiply(num1, num2) << std::endl;
            } else if (operation == "divide") {
                std::cout << "Result: " << divide(num1, num2) << std::endl;
            } else if (operation == "exponent") {
                std::cout << "Result: " << exponent(num1, num2) << std::endl;
            } else {
                std::cout << "Invalid operation!" << std::endl;
            }
        }
    }
};

int main() {
    SmartCalculator calc;
    calc.run();
    return 0;
}
