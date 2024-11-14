#include "GraphPanel.h"
#include <cmath>
#include <sstream>

wxBEGIN_EVENT_TABLE(GraphPanel, wxPanel)
EVT_PAINT(GraphPanel::OnPaint)
wxEND_EVENT_TABLE()

GraphPanel::GraphPanel(wxWindow* parent, const std::string& function)
    : wxPanel(parent), function(function) {
    SetBackgroundStyle(wxBG_STYLE_PAINT);
}

void GraphPanel::OnPaint(wxPaintEvent& event) {
    wxAutoBufferedPaintDC dc(this);
    dc.Clear();

    int width, height;
    GetClientSize(&width, &height);

    double xMin = -10.0;
    double xMax = 10.0;
    double yMin = -10.0;
    double yMax = 10.0;

    // Draw x-axis
    dc.DrawLine(0, height / 2, width, height / 2);

    // Draw y-axis
    dc.DrawLine(width / 2, 0, width / 2, height);

    // Draw graph
    dc.SetPen(wxPen(wxColour(255, 0, 0)));
    wxPointList* points = new wxPointList();
    for (int x = 0; x < width; ++x) {
        double xCoord = xMin + (xMax - xMin) * x / width;
        double yCoord = std::sin(xCoord); // Replace with actual function evaluation
        double yPixel = height - (yCoord - yMin) * height / (yMax - yMin);
        points->Append(new wxPoint(x, yPixel));
    }
    dc.DrawLines(points);
    delete points;
}
