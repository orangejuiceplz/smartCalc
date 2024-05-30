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
#include <wx/wx.h>

#ifndef M_PI
#define M_PI 3.14159265358979323846 // approximation for pi
#endif

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
    double standardDeviation(std::vector<double>& data);

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
    std::complex<double> complexAdd(std::complex<double> a, std::complex<double> b);
    std::complex<double> complexSubtract(std::complex<double> a, std::complex<double> b);
    std::complex<double> complexMultiply(std::complex<double> a, std::complex<double> b);
    std::complex<double> complexDivide(std::complex<double> a, std::complex<double> b);
    double complexMagnitude(std::complex<double> a);
    double complexArgument(std::complex<double> a);

    // Statistical functions
    double mean(std::vector<double> data);
    double median(std::vector<double> data);
    double mode(std::vector<double> data);
    double variance(std::vector<double> data);

    // Number theory functions
    bool isPrime(int n);
    std::vector<int> factorize(int n);

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

// Implement other functions as needed...

class GraphingCalculator : public wxFrame {
public:
    GraphingCalculator(SmartCalculator& calc);
    void OnPaint(wxPaintEvent& event);
    void OnClose(wxCloseEvent& event);

private:
    double evaluateExpression(const std::string& expression, double x);
    SmartCalculator& calculator;
    std::vector<std::string> functions;

    wxDECLARE_EVENT_TABLE();
};

wxBEGIN_EVENT_TABLE(GraphingCalculator, wxFrame)
    EVT_PAINT(GraphingCalculator::OnPaint)
    EVT_CLOSE(GraphingCalculator::OnClose)
wxEND_EVENT_TABLE()

GraphingCalculator::GraphingCalculator(SmartCalculator& calc)
    : wxFrame(nullptr, wxID_ANY, "Graphing Calculator", wxDefaultPosition, wxSize(800, 600)), calculator(calc) {
    std::cout << "Enter mathematical functions to graph (enter 'done' when finished):" << std::endl;
    std::string inputFunction;
    while (std::getline(std::cin, inputFunction) && inputFunction != "done") {
        functions.push_back(inputFunction);
    }
}

void GraphingCalculator::OnPaint(wxPaintEvent& event) {
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

void GraphingCalculator::OnClose(wxCloseEvent& event) {
    Destroy();
}

double GraphingCalculator::evaluateExpression(const std::string& expression, double x) {
    // to do later: implement expression evaluation logic here using existing calculator functions
    // as an example, if the expression is "sin(x)", you can use the calculator's sine function
    if (expression == "sin(x)") {
        return calculator.sine(x);
    }

    return 0.0; // default value if the expression is not recognized
}