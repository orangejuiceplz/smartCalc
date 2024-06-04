#include <wx/wx.h>
#include "SmartCalculator.h"

class MainFrame : public wxFrame {
public:
    MainFrame(const wxString& title);

private:
    void OnExit(wxCommandEvent& event);
    void OnAbout(wxCommandEvent& event);
    void OnAdd(wxCommandEvent& event);
    void OnSubtract(wxCommandEvent& event);
    void OnMultiply(wxCommandEvent& event);
    void OnDivide(wxCommandEvent& event);
    void OnSine(wxCommandEvent& event);
    void OnCosine(wxCommandEvent& event);
    void OnTangent(wxCommandEvent& event);
    void OnSolveQuadratic(wxCommandEvent& event);
    void OnGraph(wxCommandEvent& event);
    void OnStandardDeviation(wxCommandEvent& event);
    void OnDegToRad(wxCommandEvent& event);

    SmartCalculator calculator;

    wxTextCtrl* inputA;
    wxTextCtrl* inputB;
    wxTextCtrl* inputC; // For quadratic solver
    wxStaticText* resultLabel;

    wxDECLARE_EVENT_TABLE();
};

enum {
    ID_Add = 1,
    ID_Subtract,
    ID_Multiply,
    ID_Divide,
    ID_Sine,
    ID_Cosine,
    ID_Tangent,
    ID_SolveQuadratic,
    ID_Graph,
    ID_StandardDeviation,
    ID_DegToRad
};

wxBEGIN_EVENT_TABLE(MainFrame, wxFrame)
    EVT_MENU(wxID_EXIT, MainFrame::OnExit)
    EVT_MENU(wxID_ABOUT, MainFrame::OnAbout)
    EVT_BUTTON(ID_Add, MainFrame::OnAdd)
    EVT_BUTTON(ID_Subtract, MainFrame::OnSubtract)
    EVT_BUTTON(ID_Multiply, MainFrame::OnMultiply)
    EVT_BUTTON(ID_Divide, MainFrame::OnDivide)
    EVT_BUTTON(ID_Sine, MainFrame::OnSine)
    EVT_BUTTON(ID_Cosine, MainFrame::OnCosine)
    EVT_BUTTON(ID_Tangent, MainFrame::OnTangent)
    EVT_BUTTON(ID_SolveQuadratic, MainFrame::OnSolveQuadratic)
    EVT_BUTTON(ID_Graph, MainFrame::OnGraph)
    EVT_BUTTON(ID_StandardDeviation, MainFrame::OnStandardDeviation)
    EVT_BUTTON(ID_DegToRad, MainFrame::OnDegToRad)
wxEND_EVENT_TABLE()

class MyApp : public wxApp {
public:
    virtual bool OnInit();
};

wxIMPLEMENT_APP(MyApp);

bool MyApp::OnInit() {
    MainFrame* frame = new MainFrame("Smart Calculator");
    frame->Show(true);
    return true;
}

MainFrame::MainFrame(const wxString& title)
    : wxFrame(NULL, wxID_ANY, title, wxDefaultPosition, wxSize(800, 600)) {
    wxMenu* menuFile = new wxMenu;
    menuFile->Append(wxID_EXIT);

    wxMenu* menuHelp = new wxMenu;
    menuHelp->Append(wxID_ABOUT);

    wxMenuBar* menuBar = new wxMenuBar;
    menuBar->Append(menuFile, "&File");
    menuBar->Append(menuHelp, "&Help");

    SetMenuBar(menuBar);

    CreateStatusBar();
    SetStatusText("Welcome to Smart Calculator!");

    wxPanel* panel = new wxPanel(this, wxID_ANY);

    wxBoxSizer* vbox = new wxBoxSizer(wxVERTICAL);

    wxBoxSizer* hbox1 = new wxBoxSizer(wxHORIZONTAL);
    inputA = new wxTextCtrl(panel, wxID_ANY);
    inputB = new wxTextCtrl(panel, wxID_ANY);
    inputC = new wxTextCtrl(panel, wxID_ANY); // For quadratic solver
    hbox1->Add(inputA, 1);
    hbox1->Add(inputB, 1);
    hbox1->Add(inputC, 1); // For quadratic solver
    vbox->Add(hbox1, 0, wxEXPAND | wxALL, 10);

    wxBoxSizer* hbox2 = new wxBoxSizer(wxHORIZONTAL);
    wxButton* btnAdd = new wxButton(panel, ID_Add, "Add");
    wxButton* btnSubtract = new wxButton(panel, ID_Subtract, "Subtract");
    wxButton* btnMultiply = new wxButton(panel, ID_Multiply, "Multiply");
    wxButton* btnDivide = new wxButton(panel, ID_Divide, "Divide");
    wxButton* btnSine = new wxButton(panel, ID_Sine, "Sine");
    wxButton* btnCosine = new wxButton(panel, ID_Cosine, "Cosine");
    wxButton* btnTangent = new wxButton(panel, ID_Tangent, "Tangent");
    wxButton* btnSolveQuadratic = new wxButton(panel, ID_SolveQuadratic, "Solve Quadratic");
    wxButton* btnGraph = new wxButton(panel, ID_Graph, "Graph");
    wxButton* btnStandardDeviation = new wxButton(panel, ID_StandardDeviation, "Standard Deviation");
    wxButton* btnDegToRad = new wxButton(panel, ID_DegToRad, "Deg to Rad");
    hbox2->Add(btnAdd, 1);
    hbox2->Add(btnSubtract, 1);
    hbox2->Add(btnMultiply, 1);
    hbox2->Add(btnDivide, 1);
    hbox2->Add(btnSine, 1);
    hbox2->Add(btnCosine, 1);
    hbox2->Add(btnTangent, 1);
    hbox2->Add(btnSolveQuadratic, 1);
    hbox2->Add(btnGraph, 1);
    hbox2->Add(btnStandardDeviation, 1);
    hbox2->Add(btnDegToRad, 1);
    vbox->Add(hbox2, 0, wxEXPAND | wxALL, 10);

    wxBoxSizer* hbox3 = new wxBoxSizer(wxHORIZONTAL);
    resultLabel = new wxStaticText(panel, wxID_ANY, "Result: ");
    hbox3->Add(resultLabel, 1);
    vbox->Add(hbox3, 0, wxEXPAND | wxALL, 10);

    panel->SetSizer(vbox);
}

void MainFrame::OnExit(wxCommandEvent& event) {
    Close(true);
}

void MainFrame::OnAbout(wxCommandEvent& event) {
    wxMessageBox("This is a Smart Calculator application",
                 "About Smart Calculator", wxOK | wxICON_INFORMATION);
}

void MainFrame::OnAdd(wxCommandEvent& event) {
    double a, b;
    inputA->GetValue().ToDouble(&a);
    inputB->GetValue().ToDouble(&b);
    double result = calculator.add(a, b);
    resultLabel->SetLabel(wxString::Format("Result: %f", result));
}

void MainFrame::OnSubtract(wxCommandEvent& event) {
    double a, b;
    inputA->GetValue().ToDouble(&a);
    inputB->GetValue().ToDouble(&b);
    double result = calculator.subtract(a, b);
    resultLabel->SetLabel(wxString::Format("Result: %f", result));
}

void MainFrame::OnMultiply(wxCommandEvent& event) {
    double a, b;
    inputA->GetValue().ToDouble(&a);
    inputB->GetValue().ToDouble(&b);
    double result = calculator.multiply(a, b);
    resultLabel->SetLabel(wxString::Format("Result: %f", result));
}

void MainFrame::OnDivide(wxCommandEvent& event) {
    double a, b;
    inputA->GetValue().ToDouble(&a);
    inputB->GetValue().ToDouble(&b);
    double result = calculator.divide(a, b);
    resultLabel->SetLabel(wxString::Format("Result: %f", result));
}

void MainFrame::OnSine(wxCommandEvent& event) {
    double a;
    inputA->GetValue().ToDouble(&a);
    double result = calculator.sine(a);
    resultLabel->SetLabel(wxString::Format("Result: %f", result));
}

void MainFrame::OnCosine(wxCommandEvent& event) {
    double a;
    inputA->GetValue().ToDouble(&a);
    double result = calculator.cosine(a);
    resultLabel->SetLabel(wxString::Format("Result: %f", result));
}

void MainFrame::OnTangent(wxCommandEvent& event) {
    double a;
    inputA->GetValue().ToDouble(&a);
    double result = calculator.tangent(a);
    resultLabel->SetLabel(wxString::Format("Result: %f", result));
}

void MainFrame::OnSolveQuadratic(wxCommandEvent& event) {
    double a, b, c;
    inputA->GetValue().ToDouble(&a);
    inputB->GetValue().ToDouble(&b);
    inputC->GetValue().ToDouble(&c);
    calculator.solveQuadratic(a, b, c);
}

void MainFrame::OnGraph(wxCommandEvent& event) {
    wxString function = wxGetTextFromUser("Enter the function to graph (e.g., sin(x)):", "Graph Function");
    if (!function.IsEmpty()) {
        wxFrame* graphFrame = new wxFrame(this, wxID_ANY, "Graph", wxDefaultPosition, wxSize(800, 600));
        wxPanel* graphPanel = new wxPanel(graphFrame, wxID_ANY);
        graphFrame->Show(true);

        wxClientDC dc(graphPanel);
        dc.SetPen(*wxBLACK_PEN);

        int width, height;
        graphPanel->GetClientSize(&width, &height);

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
            double yCoord = calculator.evaluateExpression(function.ToStdString(), xCoord);
            double yPixel = height - (yCoord - yMin) * height / (yMax - yMin);
            points->Append(new wxPoint(x, yPixel));
        }
        dc.DrawLines(points);
        delete points;
    }
}

void MainFrame::OnStandardDeviation(wxCommandEvent& event) {
    wxString dataStr = wxGetTextFromUser("Enter the data points separated by commas:", "Standard Deviation");
    if (!dataStr.IsEmpty()) {
        std::vector<double> data;
        wxStringTokenizer tokenizer(dataStr, ",");
        while (tokenizer.HasMoreTokens()) {
            double value;
            tokenizer.GetNextToken().ToDouble(&value);
            data.push_back(value);
        }
        double result = calculator.standardDeviation(data);
        resultLabel->SetLabel(wxString::Format("Standard Deviation: %f", result));
    }
}

void MainFrame::OnDegToRad(wxCommandEvent& event) {
    double degrees;
    inputA->GetValue().ToDouble(&degrees);
    double result = calculator.degToRad(degrees);
    resultLabel->SetLabel(wxString::Format("Radians: %f", result));
}

