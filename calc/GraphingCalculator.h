#ifndef GRAPHINGCALCULATOR_H
#define GRAPHINGCALCULATOR_H

#include <SFML/Graphics.hpp>
#include <string>
#include <vector>
#include "SmartCalculator.h"

class GraphingCalculator {
public:
    GraphingCalculator(SmartCalculator& calc);
    void run();

private:
    double evaluateExpression(const std::string& expression, double x);
    SmartCalculator& calculator;
};

#endif
