#include "SmartCalculator.cpp"
#include <iostream>
#include <vector>
#include <complex>
#include <wx/wx.h>

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