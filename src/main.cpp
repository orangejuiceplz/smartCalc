#include <iostream>
#include <vector>
#include <complex>
#include <cmath>
#include <numeric>
#include <algorithm>
#include <map>
#include <string>
#include <fstream>
#include <cstdio>
#include <wx/wx.h>

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
        if (b != 0) return a / b;
        else {
            std::cout << "Error: Division by zero is not allowed.\n";
            return 0;
        }
    }
    double exponent(double base, double exp) { return pow(base, exp); }

    // Quadratic equation solver
    void solveQuadratic(double a, double b, double c) {
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

    // Angle conversion
    double degToRad(double deg) { return deg * M_PI / 180.0; }
    double radToDeg(double rad) { return rad * 180.0 / M_PI; }

    // Standard deviation calculation
    double standardDeviation(std::vector<double>& data) {
        double sum = std::accumulate(data.begin(), data.end(), 0.0);
        double mean = sum / data.size();
        double sq_sum = std::inner_product(data.begin(), data.end(), data.begin(), 0.0);
        double stdev = std::sqrt(sq_sum / data.size() - mean * mean);
        return stdev;
    }

    // Simplifying square roots
    void simplifySqrt(int n) {
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

    // Trigonometric functions
    double sine(double x) { return std::sin(x); }
    double cosine(double x) { return std::cos(x); }
    double tangent(double x) { return std::tan(x); }

    // Logarithmic and exponential functions
    double naturalLog(double x) { return std::log(x); }
    double logBase10(double x) { return std::log10(x); }
    double exp(double x) { return std::exp(x); }

    // Complex number operations
    std::complex<double> complexAdd(std::complex<double> a, std::complex<double> b) { return a + b; }
    std::complex<double> complexSubtract(std::complex<double> a, std::complex<double> b) { return a - b; }
    std::complex<double> complexMultiply(std::complex<double> a, std::complex<double> b) { return a * b; }
    std::complex<double> complexDivide(std::complex<double> a, std::complex<double> b) { return a / b; }
    double complexMagnitude(std::complex<double> a) { return std::abs(a); }
    double complexArgument(std::complex<double> a) { return std::arg(a); }

    // Statistical functions
    double mean(std::vector<double> data) {
        double sum = std::accumulate(data.begin(), data.end(), 0.0);
        return sum / data.size();
    }
    double median(std::vector<double> data) {
        std::sort(data.begin(), data.end());
        if (data.size() % 2 == 0) {
            return (data[data.size() / 2 - 1] + data[data.size() / 2]) / 2;
        } else {
            return data[data.size() / 2];
        }
    }
    double mode(std::vector<double> data) {
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
    double variance(std::vector<double> data) {
        double sum = std::accumulate(data.begin(), data.end(), 0.0);
        double mean = sum / data.size();
        double sq_sum = std::inner_product(data.begin(), data.end(), data.begin(), 0.0);
        return sq_sum / data.size() - mean * mean;
    }

    // Number theory functions
    bool isPrime(int n) {
        if (n <= 1) return false;
        for (int i = 2; i * i <= n; ++i) {
            if (n % i == 0) return false;
        }
        return true;
    }
    std::vector<int> factorize(int n) {
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

    // Surface area calculations
    double surfaceAreaRectangularPrism(double l, double w, double h) { return 2 * (l * w + l * h + w * h); }
    double surfaceAreaCylinder(double r, double h) { return 2 * M_PI * r * (r + h); }
    double surfaceAreaCircle(double r) { return M_PI * r * r; }
    double arcLengthCircle(double r, double centralAngleInDegrees) {
        double centralAngleInRadians = degToRad(centralAngleInDegrees);
        return r * centralAngleInRadians;
    }

    // Graphing function
    void graphFunction() {
        std::string function;
        double xMin, xMax, yMin, yMax;
        int width, height;

        std::cout << "Enter the function to graph (e.g., sin(x)): ";
        std::cin >> function;
        std::cout << "Enter the range for x (xMin xMax): ";
        std::cin >> xMin >> xMax;
        std::cout << "Enter the range for y (yMin yMax): ";
        std::cin >> yMin >> yMax;
        std::cout << "Enter the width and height of the graph: ";
        std::cin >> width >> height;

        std::vector<std::vector<char>> graph(height, std::vector<char>(width, ' '));

        for (int i = 0; i < width; ++i) {
            double x = xMin + (xMax - xMin) * i / (width - 1);
            double y = evaluateExpression(function, x);
            int j = (int)((y - yMin) / (yMax - yMin) * (height - 1));
            if (j >= 0 && j < height) {
                graph[j][i] = '*';
            }
        }

        for (int j = height - 1; j >= 0; --j) {
            for (int i = 0; i < width; ++i) {
                std::cout << graph[j][i];
            }
            std::cout << "\n";
        }
    }

    double evaluateExpression(const std::string& expression, double x) {
        if (expression == "sin(x)") {
            return sine(x);
        }
        return 0.0;
    }
};

class GraphingCalculator : public wxFrame {
public:
    GraphingCalculator(SmartCalculator& calc)
        : wxFrame(nullptr, wxID_ANY, "Graphing Calculator", wxDefaultPosition, wxSize(800, 600)), calculator(calc) {
        std::cout << "Enter mathematical functions to graph (enter 'done' when finished):" << std::endl;
        std::string inputFunction;
        while (std::getline(std::cin, inputFunction) && inputFunction != "done") {
            functions.push_back(inputFunction);
        }
    }

    void OnPaint(wxPaintEvent& event) {
        wxPaintDC dc(this);
        int width, height;
        GetClientSize(&width, &height);

        double xMin = -10.0;
        double xMax = 10.0;
        double yMin = -10.0;
        double yMax = 10.0;

        dc.SetPen(*wxBLACK_PEN);

        // Draw x-axis
        dc.DrawLine(0, height / 2, width, height / 2);

        // Draw y-axis
        dc.DrawLine(width / 2, 0, width / 2, height);

        // Draw graphs
        dc.SetPen(wxPen(wxColour(255, 0, 0)));
        for (const std::string& function : functions) {
            wxPointList* points = new wxPointList();
            for (int x = 0; x < width; ++x) {
                double xCoord = xMin + (xMax - xMin) * x / width;
                double yCoord = evaluateExpression(function, xCoord);
                double yPixel = height - (yCoord - yMin) * height / (yMax - yMin);
                points->Append(new wxPoint(x, yPixel));
            }
            dc.DrawLines(points);
            delete points;
        }
    }

    void OnClose(wxCloseEvent& event) {
        Destroy();
    }

private:
    double evaluateExpression(const std::string& expression, double x) {
        if (expression == "sin(x)") {
            return calculator.sine(x);
        }
        return 0.0;
    }

    SmartCalculator& calculator;
    std::vector<std::string> functions;

    wxDECLARE_EVENT_TABLE();
};

wxBEGIN_EVENT_TABLE(GraphingCalculator, wxFrame)
    EVT_PAINT(GraphingCalculator::OnPaint)
    EVT_CLOSE(GraphingCalculator::OnClose)
wxEND_EVENT_TABLE()

class MyApp : public wxApp {
public:
    virtual bool OnInit();
};

wxIMPLEMENT_APP_NO_MAIN(MyApp);

bool MyApp::OnInit() {
    return true;
}

int main(int argc, char** argv) {
    wxDISABLE_DEBUG_SUPPORT();

    SmartCalculator smartCalculator;
    GraphingCalculator* graphingCalculator = nullptr;

    int choice;
    char cont = 'y';

    while (cont == 'y') {
        std::cout << "\nWelcome to the Smart Calculator!\n";
        std::cout << "Choose an operation:\n";
        std::cout << "1. Addition\n";
        std::cout << "2. Subtraction\n";
        std::cout << "3. Multiplication\n";
        std::cout << "4. Division\n";
        std::cout << "5. Exponentiation\n";
        std::cout << "6. Solve Quadratic Equation\n";
        std::cout << "7. Degree to Radian Conversion\n";
        std::cout << "8. Radian to Degree Conversion\n";
        std::cout << "9. Standard Deviation Calculation\n";
        std::cout << "10. Simplify Square Root\n";
        std::cout << "11. Sine Function\n";
        std::cout << "12. Cosine Function\n";
        std::cout << "13. Tangent Function\n";
        std::cout << "14. Natural Logarithm\n";
        std::cout << "15. Base 10 Logarithm\n";
        std::cout << "16. Exponential Function\n";
        std::cout << "17. Complex Addition\n";
        std::cout << "18. Complex Subtraction\n";
        std::cout << "19. Complex Multiplication\n";
        std::cout << "20. Complex Division\n";
        std::cout << "21. Complex Magnitude\n";
        std::cout << "22. Complex Argument\n";
        std::cout << "23. Mean Calculation\n";
        std::cout << "24. Median Calculation\n";
        std::cout << "25. Mode Calculation\n";
        std::cout << "26. Variance Calculation\n";
        std::cout << "27. Prime Check\n";
        std::cout << "28. Factorization\n";
        std::cout << "29. Surface Area of Rectangular Prism\n";
        std::cout << "30. Surface Area of Cylinder\n";
        std::cout << "31. Surface Area of Circle\n";
        std::cout << "32. Arc Length of Circle\n";
        std::cout << "33. Graph Function\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1: {
                double a, b;
                std::cout << "Enter two numbers: ";
                std::cin >> a >> b;
                std::cout << "Result: " << smartCalculator.add(a, b) << "\n";
                break;
            }
            case 2: {
                double a, b;
                std::cout << "Enter two numbers: ";
                std::cin >> a >> b;
                std::cout << "Result: " << smartCalculator.subtract(a, b) << "\n";
                break;
            }
            case 3: {
                double a, b;
                std::cout << "Enter two numbers: ";
                std::cin >> a >> b;
                std::cout << "Result: " << smartCalculator.multiply(a, b) << "\n";
                break;
            }
            case 4: {
                double a, b;
                std::cout << "Enter two numbers: ";
                std::cin >> a >> b;
                std::cout << "Result: " << smartCalculator.divide(a, b) << "\n";
                break;
            }
            case 5: {
                double base, exp;
                std::cout << "Enter base and exponent: ";
                std::cin >> base >> exp;
                std::cout << "Result: " << smartCalculator.exponent(base, exp) << "\n";
                break;
            }
            case 6: {
                double a, b, c;
                std::cout << "Enter coefficients a, b, and c: ";
                std::cin >> a >> b >> c;
                smartCalculator.solveQuadratic(a, b, c);
                break;
            }
            case 7: {
                double deg;
                std::cout << "Enter degrees: ";
                std::cin >> deg;
                std::cout << "Result: " << smartCalculator.degToRad(deg) << " radians\n";
                break;
            }
            case 8: {
                double rad;
                std::cout << "Enter radians: ";
                std::cin >> rad;
                std::cout << "Result: " << smartCalculator.radToDeg(rad) << " degrees\n";
                break;
            }
            case 9: {
                int n;
                std::cout << "Enter number of data points: ";
                std::cin >> n;
                std::vector<double> data(n);
                std::cout << "Enter data points: ";
                for (int i = 0; i < n; ++i) {
                    std::cin >> data[i];
                }
                std::cout << "Result: " << smartCalculator.standardDeviation(data) << "\n";
                break;
            }
            case 10: {
                int n;
                std::cout << "Enter a number: ";
                std::cin >> n;
                smartCalculator.simplifySqrt(n);
                break;
            }
            case 11: {
                double x;
                std::cout << "Enter an angle in radians: ";
                std::cin >> x;
                std::cout << "Result: " << smartCalculator.sine(x) << "\n";
                break;
            }
            case 12: {
                double x;
                std::cout << "Enter an angle in radians: ";
                std::cin >> x;
                std::cout << "Result: " << smartCalculator.cosine(x) << "\n";
                break;
            }
            case 13: {
                double x;
                std::cout << "Enter an angle in radians: ";
                std::cin >> x;
                std::cout << "Result: " << smartCalculator.tangent(x) << "\n";
                break;
            }
            case 14: {
                double x;
                std::cout << "Enter a number: ";
                std::cin >> x;
                std::cout << "Result: " << smartCalculator.naturalLog(x) << "\n";
                break;
            }
            case 15: {
                double x;
                std::cout << "Enter a number: ";
                std::cin >> x;
                std::cout << "Result: " << smartCalculator.logBase10(x) << "\n";
                break;
            }
            case 16: {
                double x;
                std::cout << "Enter a number: ";
                std::cin >> x;
                               std::cout << "Result: " << smartCalculator.exp(x) << "\n";
                break;
            }
            case 17: {
                std::complex<double> a, b;
                std::cout << "Enter two complex numbers (real and imaginary parts): ";
                std::cin >> a >> b;
                std::cout << "Result: " << smartCalculator.complexAdd(a, b) << "\n";
                break;
            }
            case 18: {
                std::complex<double> a, b;
                std::cout << "Enter two complex numbers (real and imaginary parts): ";
                std::cin >> a >> b;
                std::cout << "Result: " << smartCalculator.complexSubtract(a, b) << "\n";
                break;
            }
            case 19: {
                std::complex<double> a, b;
                std::cout << "Enter two complex numbers (real and imaginary parts): ";
                std::cin >> a >> b;
                std::cout << "Result: " << smartCalculator.complexMultiply(a, b) << "\n";
                break;
            }
            case 20: {
                std::complex<double> a, b;
                std::cout << "Enter two complex numbers (real and imaginary parts): ";
                std::cin >> a >> b;
                std::cout << "Result: " << smartCalculator.complexDivide(a, b) << "\n";
                break;
            }
            case 21: {
                std::complex<double> a;
                std::cout << "Enter a complex number (real and imaginary parts): ";
                std::cin >> a;
                std::cout << "Result: " << smartCalculator.complexMagnitude(a) << "\n";
                break;
            }
            case 22: {
                std::complex<double> a;
                std::cout << "Enter a complex number (real and imaginary parts): ";
                std::cin >> a;
                std::cout << "Result: " << smartCalculator.complexArgument(a) << "\n";
                break;
            }
            case 23: {
                int n;
                std::cout << "Enter number of data points: ";
                std::cin >> n;
                std::vector<double> data(n);
                std::cout << "Enter data points: ";
                for (int i = 0; i < n; ++i) {
                    std::cin >> data[i];
                }
                std::cout << "Result: " << smartCalculator.mean(data) << "\n";
                break;
            }
            case 24: {
                int n;
                std::cout << "Enter number of data points: ";
                std::cin >> n;
                std::vector<double> data(n);
                std::cout << "Enter data points: ";
                for (int i = 0; i < n; ++i) {
                    std::cin >> data[i];
                }
                std::cout << "Result: " << smartCalculator.median(data) << "\n";
                break;
            }
            case 25: {
                int n;
                std::cout << "Enter number of data points: ";
                std::cin >> n;
                std::vector<double> data(n);
                std::cout << "Enter data points: ";
                for (int i = 0; i < n; ++i) {
                    std::cin >> data[i];
                }
                std::cout << "Result: " << smartCalculator.mode(data) << "\n";
                break;
            }
            case 26: {
                int n;
                std::cout << "Enter number of data points: ";
                std::cin >> n;
                std::vector<double> data(n);
                std::cout << "Enter data points: ";
                for (int i = 0; i < n; ++i) {
                    std::cin >> data[i];
                }
                std::cout << "Result: " << smartCalculator.variance(data) << "\n";
                break;
            }
            case 27: {
                int n;
                std::cout << "Enter a number: ";
                std::cin >> n;
                std::cout << "Result: " << (smartCalculator.isPrime(n) ? "Prime" : "Not Prime") << "\n";
                break;
            }
            case 28: {
                int n;
                std::cout << "Enter a number: ";
                std::cin >> n;
                std::vector<int> factors = smartCalculator.factorize(n);
                std::cout << "Factors: ";
                for (int factor : factors) {
                    std::cout << factor << " ";
                }
                std::cout << "\n";
                break;
            }
            case 29: {
                double l, w, h;
                std::cout << "Enter length, width, and height: ";
                std::cin >> l >> w >> h;
                std::cout << "Result: " << smartCalculator.surfaceAreaRectangularPrism(l, w, h) << "\n";
                break;
            }
            case 30: {
                double r, h;
                std::cout << "Enter radius and height: ";
                std::cin >> r >> h;
                std::cout << "Result: " << smartCalculator.surfaceAreaCylinder(r, h) << "\n";
                break;
            }
            case 31: {
                double r;
                std::cout << "Enter radius: ";
                std::cin >> r;
                std::cout << "Result: " << smartCalculator.surfaceAreaCircle(r) << "\n";
                break;
            }
            case 32: {
                double r, angle;
                std::cout << "Enter radius and central angle in degrees: ";
                std::cin >> r >> angle;
                std::cout << "Result: " << smartCalculator.arcLengthCircle(r, angle) << "\n";
                break;
            }
            case 33: {
                wxEntryStart(argc, argv);
                graphingCalculator = new GraphingCalculator(smartCalculator);
                graphingCalculator->Show(true);
                wxTheApp->OnRun();
                wxEntryCleanup();
                break;
            }
            default:
                std::cout << "Invalid choice. Please try again.\n";
                break;
        }

        std::cout << "Do you want to perform another operation? (y/n): ";
        std::cin >> cont;
    }

    return 0;
}
