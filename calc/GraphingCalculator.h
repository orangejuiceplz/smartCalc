#ifndef GRAPHINGCALCULATOR_H
#define GRAPHINGCALCULATOR_H

#include <wx/wx.h>
#include <string>
#include <vector>
#include "SmartCalculator.h"

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

#endif
