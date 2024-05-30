#include "GraphingCalculator.h"

#include <iostream>

wxBEGIN_EVENT_TABLE(GraphingCalculator, wxFrame)
    EVT_PAINT(GraphingCalculator::OnPaint)
    EVT_CLOSE(GraphingCalculator::OnClose)
wxEND_EVENT_TABLE()

GraphingCalculator::GraphingCalculator(SmartCalculator & calc)
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

double GraphingCalculator::evaluateExpression(const std::string & expression, double x) {
    // to do later: implement expression evaluation logic here using existing calculator functions
    // as an example, if the expression is "sin(x)", you can use the calculator's sine function
    if (expression == "sin(x)") {
        return calculator.sine(x);
    }

    return 0.0; // default value if the expression is not recognized
}
