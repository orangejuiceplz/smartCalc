#pragma once
#include <wx/wx.h>
#include <wx/dcbuffer.h>
#include <string>

class GraphPanel : public wxPanel {
public:
    GraphPanel(wxWindow* parent, const std::string& function);
    void OnPaint(wxPaintEvent& event);

private:
    std::string function;
    wxDECLARE_EVENT_TABLE();
};
