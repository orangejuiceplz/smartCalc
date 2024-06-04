#include <wx/wx.h>
#

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
    void OnExponent(wxCommandEvent& event);
    void OnNaturalLog(wxCommandEvent& event);
    void OnLogBase10(wxCommandEvent& event);
    void OnExp(wxCommandEvent& event);
    void OnComplexAdd(wxCommandEvent& event);
    void OnComplexSubtract(wxCommandEvent& event);
    void OnComplexMultiply(wxCommandEvent& event);
    void OnComplexDivide(wxCommandEvent& event);
    void OnComplexMagnitude(wxCommandEvent& event);
    void OnComplexArgument(wxCommandEvent& event);
    void OnMean(wxCommandEvent& event);
    void OnMedian(wxCommandEvent& event);
    void OnMode(wxCommandEvent& event);
    void OnVariance(wxCommandEvent& event);
    void OnIsPrime(wxCommandEvent& event);
    void OnFactorize(wxCommandEvent& event);
    void OnSurfaceAreaRectangularPrism(wxCommandEvent& event);
    void OnSurfaceAreaCylinder(wxCommandEvent& event);
    void OnSurfaceAreaCircle(wxCommandEvent& event);
    void OnArcLengthCircle(wxCommandEvent& event);

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
    ID_DegToRad,
    ID_Exponent,
    ID_NaturalLog,
    ID_LogBase10,
    ID_Exp,
    ID_ComplexAdd,
    ID_ComplexSubtract,
    ID_ComplexMultiply,
    ID_ComplexDivide,
    ID_ComplexMagnitude,
    ID_ComplexArgument,
    ID_Mean,
    ID_Median,
    ID_Mode,
    ID_Variance,
    ID_IsPrime,
    ID_Factorize,
    ID_SurfaceAreaRectangularPrism,
    ID_SurfaceAreaCylinder,
    ID_SurfaceAreaCircle,
    ID_ArcLengthCircle
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
    EVT_BUTTON(ID_Exponent, MainFrame::OnExponent)
    EVT_BUTTON(ID_NaturalLog, MainFrame::OnNaturalLog)
    EVT_BUTTON(ID_LogBase10, MainFrame::OnLogBase10)
    EVT_BUTTON(ID_Exp, MainFrame::OnExp)
    EVT_BUTTON(ID_ComplexAdd, MainFrame::OnComplexAdd)
    EVT_BUTTON(ID_ComplexSubtract, MainFrame::OnComplexSubtract)
    EVT_BUTTON(ID_ComplexMultiply, MainFrame::OnComplexMultiply)
    EVT_BUTTON(ID_ComplexDivide, MainFrame::OnComplexDivide)
    EVT_BUTTON(ID_ComplexMagnitude, MainFrame::OnComplexMagnitude)
    EVT_BUTTON(ID_ComplexArgument, MainFrame::OnComplexArgument)
    EVT_BUTTON(ID_Mean, MainFrame::OnMean)
    EVT_BUTTON(ID_Median, MainFrame::OnMedian)
    EVT_BUTTON(ID_Mode, MainFrame::OnMode)
    EVT_BUTTON(ID_Variance, MainFrame::OnVariance)
    EVT_BUTTON(ID_IsPrime, MainFrame::OnIsPrime)
    EVT_BUTTON(ID_Factorize, MainFrame::OnFactorize)
    EVT_BUTTON(ID_SurfaceAreaRectangularPrism, MainFrame::OnSurfaceAreaRectangularPrism)
    EVT_BUTTON(ID_SurfaceAreaCylinder, MainFrame::OnSurfaceAreaCylinder)
    EVT_BUTTON(ID_SurfaceAreaCircle, MainFrame::OnSurfaceAreaCircle)
    EVT_BUTTON(ID_ArcLengthCircle, MainFrame::OnArcLengthCircle)
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
    wxButton* btnExponent = new wxButton(panel, ID_Exponent, "Exponent");
    wxButton* btnNaturalLog = new wxButton(panel, ID_NaturalLog, "Natural Log");
    wxButton* btnLogBase10 = new wxButton(panel, ID_LogBase10, "Log Base 10");
    wxButton* btnExp = new wxButton(panel, ID_Exp, "Exp");
    wxButton* btnComplexAdd = new wxButton(panel, ID_ComplexAdd, "Complex Add");
    wxButton* btnComplexSubtract = new wxButton(panel, ID_ComplexSubtract, "Complex Subtract");
    wxButton* btnComplexMultiply = new wxButton(panel, ID_ComplexMultiply, "Complex Multiply");
    wxButton* btnComplexDivide = new wxButton(panel, ID_ComplexDivide, "Complex Divide");
    wxButton* btnComplexMagnitude = new wxButton(panel, ID_ComplexMagnitude, "Complex Magnitude");
    wxButton* btnComplexArgument = new wxButton(panel, ID_ComplexArgument, "Complex Argument");
    wxButton* btnMean = new wxButton(panel, ID_Mean, "Mean");
    wxButton* btnMedian = new wxButton(panel, ID_Median, "Median");
    wxButton* btnMode = new wxButton(panel, ID_Mode, "Mode");
    wxButton* btnVariance = new wxButton(panel, ID_Variance, "Variance");
    wxButton* btnIsPrime = new wxButton(panel, ID_IsPrime, "Is Prime");
    wxButton* btnFactorize = new wxButton(panel, ID_Factorize, "Factorize");
    wxButton* btnSurfaceAreaRectangularPrism = new wxButton(panel, ID_SurfaceAreaRectangularPrism, "Surface Area Rectangular Prism");
    wxButton* btnSurfaceAreaCylinder = new wxButton(panel, ID_SurfaceAreaCylinder, "Surface Area Cylinder");
    wxButton* btnSurfaceAreaCircle = new wxButton(panel, ID_SurfaceAreaCircle, "Surface Area Circle");
    wxButton* btnArcLengthCircle = new wxButton(panel, ID_ArcLengthCircle, "Arc Length Circle");
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
    hbox2->Add(btnExponent, 1);
    hbox2->Add(btnNaturalLog, 1);
    hbox2->Add(btnLogBase10, 1);
    hbox2->Add(btnExp, 1);
    hbox2->Add(btnComplexAdd, 1);
    hbox2->Add(btnComplexSubtract, 1);
    hbox2->Add(btnComplexMultiply, 1);
    hbox2->Add(btnComplexDivide, 1);
    hbox2->Add(btnComplexMagnitude, 1);
    hbox2->Add(btnComplexArgument, 1);
    hbox2->Add(btnMean, 1);
    hbox2->Add(btnMedian, 1);
    hbox2->Add(btnMode, 1);
    hbox2->Add(btnVariance, 1);
    hbox2->Add(btnIsPrime, 1);
    hbox2->Add(btnFactorize, 1);
    hbox2->Add(btnSurfaceAreaRectangularPrism, 1);
    hbox2->Add(btnSurfaceAreaCylinder, 1);
    hbox2->Add(btnSurfaceAreaCircle, 1);
    hbox2->Add(btnArcLengthCircle, 1);
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

void MainFrame::OnExponent(wxCommandEvent& event) {
    double base, exp;
    inputA->GetValue().ToDouble(&base);
    inputB->GetValue().ToDouble(&exp);
    double result = calculator.exponent(base, exp);
    resultLabel->SetLabel(wxString::Format("Result: %f", result));
}

void MainFrame::OnNaturalLog(wxCommandEvent& event) {
    double x;
    inputA->GetValue().ToDouble(&x);
    double result = calculator.naturalLog(x);
    resultLabel->SetLabel(wxString::Format("Result: %f", result));
}

void MainFrame::OnLogBase10(wxCommandEvent& event) {
    double x;
    inputA->GetValue().ToDouble(&x);
    double result = calculator.logBase10(x);
    resultLabel->SetLabel(wxString::Format("Result: %f", result));
}

void MainFrame::OnExp(wxCommandEvent& event) {
    double x;
    inputA->GetValue().ToDouble(&x);
    double result = calculator.exp(x);
    resultLabel->SetLabel(wxString::Format("Result: %f", result));
}

void MainFrame::OnComplexAdd(wxCommandEvent& event) {
    double realA, imagA, realB, imagB;
    inputA->GetValue().ToDouble(&realA);
    inputB->GetValue().ToDouble(&imagA);
    inputC->GetValue().ToDouble(&realB);
    wxTextCtrl* inputD = new wxTextCtrl(this, wxID_ANY);
    inputD->GetValue().ToDouble(&imagB);
    std::complex<double> a(realA, imagA);
    std::complex<double> b(realB, imagB);
    std::complex<double> result = calculator.complexAdd(a, b);
    resultLabel->SetLabel(wxString::Format("Result: %f + %fi", result.real(), result.imag()));
}

void MainFrame::OnComplexSubtract(wxCommandEvent& event) {
    double realA, imagA, realB, imagB;
    inputA->GetValue().ToDouble(&realA);
    inputB->GetValue().ToDouble(&imagA);
    inputC->GetValue().ToDouble(&realB);
    wxTextCtrl* inputD = new wxTextCtrl(this, wxID_ANY);
    inputD->GetValue().ToDouble(&imagB);
    std::complex<double> a(realA, imagA);
    std::complex<double> b(realB, imagB);
    std::complex<double> result = calculator.complexSubtract(a, b);
    resultLabel->SetLabel(wxString::Format("Result: %f + %fi", result.real(), result.imag()));
}

void MainFrame::OnComplexMultiply(wxCommandEvent& event) {
    double realA, imagA, realB, imagB;
    inputA->GetValue().ToDouble(&realA);
    inputB->GetValue().ToDouble(&imagA);
    inputC->GetValue().ToDouble(&realB);
    wxTextCtrl* inputD = new wxTextCtrl(this, wxID_ANY);
    inputD->GetValue().ToDouble(&imagB);
    std::complex<double> a(realA, imagA);
    std::complex<double> b(realB, imagB);
    std::complex<double> result = calculator.complexMultiply(a, b);
    resultLabel->SetLabel(wxString::Format("Result: %f + %fi", result.real(), result.imag()));
}

void MainFrame::OnComplexDivide(wxCommandEvent& event) {
    double realA, imagA, realB, imagB;
    inputA->GetValue().ToDouble(&realA);
    inputB->GetValue().ToDouble(&imagA);
    inputC->GetValue().ToDouble(&realB);
    wxTextCtrl* inputD = new wxTextCtrl(this, wxID_ANY);
    inputD->GetValue().ToDouble(&imagB);
        std::complex<double> a(realA, imagA);
    std::complex<double> b(realB, imagB);
    std::complex<double> result = calculator.complexDivide(a, b);
    resultLabel->SetLabel(wxString::Format("Result: %f + %fi", result.real(), result.imag()));
}

void MainFrame::OnComplexMagnitude(wxCommandEvent& event) {
    double real, imag;
    inputA->GetValue().ToDouble(&real);
    inputB->GetValue().ToDouble(&imag);
    std::complex<double> a(real, imag);
    double result = calculator.complexMagnitude(a);
    resultLabel->SetLabel(wxString::Format("Result: %f", result));
}

void MainFrame::OnComplexArgument(wxCommandEvent& event) {
    double real, imag;
    inputA->GetValue().ToDouble(&real);
    inputB->GetValue().ToDouble(&imag);
    std::complex<double> a(real, imag);
    double result = calculator.complexArgument(a);
    resultLabel->SetLabel(wxString::Format("Result: %f", result));
}

void MainFrame::OnMean(wxCommandEvent& event) {
    wxString dataStr = wxGetTextFromUser("Enter the data points separated by commas:", "Mean");
    if (!dataStr.IsEmpty()) {
        std::vector<double> data;
        wxStringTokenizer tokenizer(dataStr, ",");
        while (tokenizer.HasMoreTokens()) {
            double value;
            tokenizer.GetNextToken().ToDouble(&value);
            data.push_back(value);
        }
        double result = calculator.mean(data);
        resultLabel->SetLabel(wxString::Format("Mean: %f", result));
    }
}

void MainFrame::OnMedian(wxCommandEvent& event) {
    wxString dataStr = wxGetTextFromUser("Enter the data points separated by commas:", "Median");
    if (!dataStr.IsEmpty()) {
        std::vector<double> data;
        wxStringTokenizer tokenizer(dataStr, ",");
        while (tokenizer.HasMoreTokens()) {
            double value;
            tokenizer.GetNextToken().ToDouble(&value);
            data.push_back(value);
        }
        double result = calculator.median(data);
        resultLabel->SetLabel(wxString::Format("Median: %f", result));
    }
}

void MainFrame::OnMode(wxCommandEvent& event) {
    wxString dataStr = wxGetTextFromUser("Enter the data points separated by commas:", "Mode");
    if (!dataStr.IsEmpty()) {
        std::vector<double> data;
        wxStringTokenizer tokenizer(dataStr, ",");
        while (tokenizer.HasMoreTokens()) {
            double value;
            tokenizer.GetNextToken().ToDouble(&value);
            data.push_back(value);
        }
        double result = calculator.mode(data);
        resultLabel->SetLabel(wxString::Format("Mode: %f", result));
    }
}

void MainFrame::OnVariance(wxCommandEvent& event) {
    wxString dataStr = wxGetTextFromUser("Enter the data points separated by commas:", "Variance");
    if (!dataStr.IsEmpty()) {
        std::vector<double> data;
        wxStringTokenizer tokenizer(dataStr, ",");
        while (tokenizer.HasMoreTokens()) {
            double value;
            tokenizer.GetNextToken().ToDouble(&value);
            data.push_back(value);
        }
        double result = calculator.variance(data);
        resultLabel->SetLabel(wxString::Format("Variance: %f", result));
    }
}

void MainFrame::OnIsPrime(wxCommandEvent& event) {
    int n;
    inputA->GetValue().ToLong(&n);
    bool result = calculator.isPrime(n);
    resultLabel->SetLabel(wxString::Format("Is Prime: %s", result ? "true" : "false"));
}

void MainFrame::OnFactorize(wxCommandEvent& event) {
    int n;
    inputA->GetValue().ToLong(&n);
    std::vector<int> factors = calculator.factorize(n);
    wxString factorsStr;
    for (int factor : factors) {
        factorsStr += wxString::Format("%d ", factor);
    }
    resultLabel->SetLabel(wxString::Format("Factors: %s", factorsStr));
}

void MainFrame::OnSurfaceAreaRectangularPrism(wxCommandEvent& event) {
    double l, w, h;
    inputA->GetValue().ToDouble(&l);
    inputB->GetValue().ToDouble(&w);
    inputC->GetValue().ToDouble(&h);
    double result = calculator.surfaceAreaRectangularPrism(l, w, h);
    resultLabel->SetLabel(wxString::Format("Surface Area: %f", result));
}

void MainFrame::OnSurfaceAreaCylinder(wxCommandEvent& event) {
    double r, h;
    inputA->GetValue().ToDouble(&r);
    inputB->GetValue().ToDouble(&h);
    double result = calculator.surfaceAreaCylinder(r, h);
    resultLabel->SetLabel(wxString::Format("Surface Area: %f", result));
}

void MainFrame::OnSurfaceAreaCircle(wxCommandEvent& event) {
    double r;
    inputA->GetValue().ToDouble(&r);
    double result = calculator.surfaceAreaCircle(r);
    resultLabel->SetLabel(wxString::Format("Surface Area: %f", result));
}

void MainFrame::OnArcLengthCircle(wxCommandEvent& event) {
    double r, centralAngleInDegrees;
    inputA->GetValue().ToDouble(&r);
    inputB->GetValue().ToDouble(&centralAngleInDegrees);
    double result = calculator.arcLengthCircle(r, centralAngleInDegrees);
    resultLabel->SetLabel(wxString::Format("Arc Length: %f", result));
}

