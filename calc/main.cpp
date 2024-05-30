// this file will deal with compiling both of the C++ src files (GraphingCalculator.cpp and SmartCaclulator.cpp respectively). its a work in progress.
// gcc commands would be easier to do, but like, even though i have an arch, btw, vm which i barely use, i prefer js compiling straight in vscode.
// maybe ill learn how to use vim so i can be more programmer.
// haha, no.

#include <wx/wx.h>
#include "GraphingCalculator.h"
#include "SmartCalculator.h"

class MyApp : public wxApp {
public:
    virtual bool OnInit();
};

wxIMPLEMENT_APP(MyApp);

bool MyApp::OnInit() {
    SmartCalculator calculator;
    GraphingCalculator* frame = new GraphingCalculator(calculator);
    frame->Show(true);
    return true;
}

// possible fixes. probably not going to work cause i'll have to update the run method instead of just using void run(), actually use the really long ahh selection screen i have on my pc.
