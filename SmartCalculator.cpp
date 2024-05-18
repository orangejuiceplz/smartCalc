#include <iostream>
#include <cmath>
#include <complex>
#include <vector>
#include <numeric>
#include <algorithm>
#include <map>
#include <string>

#ifndef M_PI
#define M_PI 3.14159265358979323846 // approximation for pi
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
        std::cout << "The roots are real and different. Solving for x:\n";
        std::cout << "x1 = " << (-b + sqrt_val) / (2*a) << "\n";
        std::cout << "x2 = " << (-b - sqrt_val) / (2*a) << "\n";
    }
    else if (discriminant == 0) {
        std::cout << "The roots are real and the same. Solving for x:\n";
        std::cout << "x = " << -b / (2*a) << "\n"; // only one solution since the roots are equal
    }
    else {
        std::cout << "The roots are complex. Solving for x:\n";
        std::cout << "x1 = " << -b / (2*a) << " + i" << sqrt_val << "\n";
        std::cout << "x2 = " << -b / (2*a) << " - i" << sqrt_val << "\n";
    }
}


    // angle conversion built in with C++
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
    double sine(double x) { return sin(x); }
    double cosine(double x) { return cos(x); }
    double tangent(double x) { return tan(x); }

    // log and e^x
    double naturalLog(double x) { return log(x); }
    double logBase10(double x) { return log10(x); }
    double exp(double x) { return exp(x); }

    // comp # oper
    std::complex<double> complexAdd(std::complex<double> a, std::complex<double> b) { return a + b; }
    std::complex<double> complexSubtract(std::complex<double> a, std::complex<double> b) { return a - b; }
    std::complex<double> complexMultiply(std::complex<double> a, std::complex<double> b) { return a * b; }
    std::complex<double> complexDivide(std::complex<double> a, std::complex<double> b) { return a / b; }
    double complexMagnitude(std::complex<double> a) { return abs(a); }
    double complexArgument(std::complex<double> a) { return arg(a); }

    // stat func
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

    // num theory
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

    // operations runner
    void run() {
    std::string operation;
    double num1, num2;

    while (true) {
        std::cout << "Enter operation (add, subtract, multiply, divide, exponent, solveQuadratic, convertAngle, calculateStdDev, simplifySqrt, trigFunction, logExpFunction, complexOperation, statisticalFunction, numberTheoryFunction, quit): ";
        std::cin >> operation;

        if (operation == "quit") {
            break;
        }

        if (operation == "add" || operation == "subtract" || operation == "multiply" || operation == "divide" || operation == "exponent") {
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
            }
        } else if (operation == "solveQuadratic") {
            double a, b, c;
            std::cout << "Enter coefficients a, b, and c: ";
            std::cin >> a >> b >> c;
            solveQuadratic(a, b, c);
        } else if (operation == "convertAngle") {
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
        } else if (operation == "calculateStdDev") {
            int n;
            std::cout << "Enter the number of elements: ";
            std::cin >> n;
            double* data = new double[n];
            std::cout << "Enter the elements: ";
            for (int i = 0; i < n; ++i) {
                std::cin >> data[i];
            }
            std::cout << "Standard Deviation: " << standardDeviation(data, n) << std::endl;
            delete[] data;
        } else if (operation == "simplifySqrt") {
            int n;
            std::cout << "Enter the number to simplify: ";
            std::cin >> n;
            simplifySqrt(n);
        } else if (operation == "trigFunction") {
            double angle;
            std::cout << "Enter the angle in degrees: ";
            std::cin >> angle;
            std::cout << "Sin: " << sine(degToRad(angle)) << ", Cos: " << cosine(degToRad(angle)) << ", Tan: " << tangent(degToRad(angle)) << std::endl;
        } else if (operation == "logExpFunction") {
            double x;
            std::cout << "Enter the value for logarithm/exponential calculation: ";
            std::cin >> x;
            std::cout << "Natural Log: " << naturalLog(x) << ", Log Base 10: " << logBase10(x) << ", Exponential: " << exp(x) << std::endl;
        } else if (operation == "complexOperation") {
            // Assuming operations on complex numbers are handled elsewhere or simplified here
            std::cout << "Complex number operations are not fully implemented in this example." << std::endl;
        } else if (operation == "statisticalFunction") {
            // Assuming statistical functions are handled elsewhere or simplified here
            std::cout << "Statistical functions are not fully implemented in this example." << std::endl;
        } else if (operation == "numberTheoryFunction") {
            int n;
            std::cout << "Enter a number to check if it's prime: ";
            std::cin >> n;
            if (isPrime(n)) {
                std::cout << n << " is a prime number." << std::endl;
            } else {
                std::cout << n << " is not a prime number." << std::endl;
            }
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
