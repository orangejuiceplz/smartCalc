#include "GraphingCalculator.h"

#include <iostream>

GraphingCalculator::GraphingCalculator(SmartCalculator & calc): calculator(calc) {}

void GraphingCalculator::run() {
  const int width = 800;
  const int height = 600;
  double xMin = -10.0;
  double xMax = 10.0;
  double yMin = -10.0;
  double yMax = 10.0;

  sf::RenderWindow window(sf::VideoMode(width, height), "Graphing Calculator");

  std::vector < std::string > functions;
  std::string inputFunction;

  std::cout << "Enter mathematical functions to graph (enter 'done' when finished):" << std::endl;
  while (std::getline(std::cin, inputFunction) && inputFunction != "done") {
    functions.push_back(inputFunction);
  }

  while (window.isOpen()) {
    sf::Event event;
    while (window.pollEvent(event)) {
      if (event.type == sf::Event::Closed)
        window.close();
    }

    window.clear(sf::Color::White);

    sf::Vertex xAxis[] = {
      sf::Vertex(sf::Vector2f(0, height / 2), sf::Color::Black),
      sf::Vertex(sf::Vector2f(width, height / 2), sf::Color::Black)
    };
    window.draw(xAxis, 2, sf::Lines);

    sf::Vertex yAxis[] = {
      sf::Vertex(sf::Vector2f(width / 2, 0), sf::Color::Black),
      sf::Vertex(sf::Vector2f(width / 2, height), sf::Color::Black)
    };
    window.draw(yAxis, 2, sf::Lines);

    // drawing graphs
    for (const std::string & function: functions) {
      sf::VertexArray graph(sf::LineStrip);
      for (int x = 0; x < width; ++x) {
        double xCoord = xMin + (xMax - xMin) * x / width;
        double yCoord = evaluateExpression(function, xCoord);
        double yPixel = height - (yCoord - yMin) * height / (yMax - yMin);
        graph.append(sf::Vertex(sf::Vector2f(x, yPixel), sf::Color::Red));
      }
      window.draw(graph);
    }

    window.display();
  }
}

double GraphingCalculator::evaluateExpression(const std::string & expression, double x) {
  // to do later: implement  expression evaluation logic here using  existing calculator functions
  // as an example, if the expression is "sin(x)", you can use the calculator's sine function
  if (expression == "sin(x)") {
    return calculator.sine(x);
  }

  return 0.0; //  default value if the expression is not recognized
}
