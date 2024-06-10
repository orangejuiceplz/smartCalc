#include <wx/wx.h>
#include <wx/tokenzr.h>
#include "SmartCalculator.h"
#include <wx/statline.h>
#include <locale>
#include <codecvt>
#include "GraphPanel.h"


class MyPanel : public wxPanel {
public:
    MyPanel(wxWindow* parent) : wxPanel(parent) {}

    void OnPaint(wxPaintEvent& event) {
        wxPaintDC dc(this);
        wxRect rect = GetClientRect();

        // Create a gradient background
        wxColour startColor(0, 0, 0);
        wxColour endColor(64, 64, 64);
        dc.GradientFillLinear(rect, startColor, endColor, wxSOUTH);
    }

    wxDECLARE_EVENT_TABLE();
};

wxBEGIN_EVENT_TABLE(MyPanel, wxPanel)
EVT_PAINT(MyPanel::OnPaint)
wxEND_EVENT_TABLE()

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
    void OnConvertCurrency(wxCommandEvent& event);
    void OnIntToBinary(wxCommandEvent& event);
    void OnIntToHex(wxCommandEvent& event);
    void OnBinaryToInt(wxCommandEvent& event);
    void OnHexToInt(wxCommandEvent& event);
    void OnCelsiusToFahrenheit(wxCommandEvent& event);
    void OnFahrenheitToCelsius(wxCommandEvent& event);
    void OnMetersToFeet(wxCommandEvent& event);
    void OnFeetToMeters(wxCommandEvent& event);
    void OnKilogramsToPounds(wxCommandEvent& event);
    void OnPoundsToKilograms(wxCommandEvent& event);

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
    ID_ArcLengthCircle,
    ID_Convert_Currency,
    ID_IntToBinary,
    ID_IntToHex,
    ID_BinaryToInt,
    ID_HexToInt,
    ID_CelsiusToFahrenheit,
    ID_FahrenheitToCelsius,
    ID_MetersToFeet,
    ID_FeetToMeters,
    ID_KilogramsToPounds,
    ID_PoundsToKilograms
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
EVT_BUTTON(ID_Convert_Currency, MainFrame::OnConvertCurrency)
EVT_BUTTON(ID_IntToBinary, MainFrame::OnIntToBinary)
EVT_BUTTON(ID_IntToHex, MainFrame::OnIntToHex)
EVT_BUTTON(ID_BinaryToInt, MainFrame::OnBinaryToInt)
EVT_BUTTON(ID_HexToInt, MainFrame::OnHexToInt)
EVT_BUTTON(ID_CelsiusToFahrenheit, MainFrame::OnCelsiusToFahrenheit)
EVT_BUTTON(ID_FahrenheitToCelsius, MainFrame::OnFahrenheitToCelsius)
EVT_BUTTON(ID_MetersToFeet, MainFrame::OnMetersToFeet)
EVT_BUTTON(ID_FeetToMeters, MainFrame::OnFeetToMeters)
EVT_BUTTON(ID_KilogramsToPounds, MainFrame::OnKilogramsToPounds)
EVT_BUTTON(ID_PoundsToKilograms, MainFrame::OnPoundsToKilograms)
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
    SetBackgroundColour(wxColour(0, 0, 0)); // Set black background for the main window

    wxMenu* menuFile = new wxMenu;
    menuFile->Append(wxID_EXIT);

    wxMenu* menuHelp = new wxMenu;
    wxMenuBar* menuBar = new wxMenuBar;
    menuBar->Append(menuFile, "&File");
    menuBar->Append(menuHelp, "&Help");

    SetMenuBar(menuBar);

    CreateStatusBar();
    SetStatusText("Welcome to Smart Calculator! Developed by orangejuiceplz!");

    MyPanel* panel = new MyPanel(this);

    wxBoxSizer* vbox = new wxBoxSizer(wxVERTICAL);

    wxBoxSizer* hbox1 = new wxBoxSizer(wxHORIZONTAL);
    inputA = new wxTextCtrl(panel, wxID_ANY);
    inputB = new wxTextCtrl(panel, wxID_ANY);
    inputC = new wxTextCtrl(panel, wxID_ANY); // For quadratic solver
    hbox1->Add(inputA, 1, wxEXPAND | wxALL, 10);
    hbox1->Add(inputB, 1, wxEXPAND | wxALL, 10);
    hbox1->Add(inputC, 1, wxEXPAND | wxALL, 10); // For quadratic solver
    vbox->Add(hbox1, 0, wxEXPAND);

    wxFont font(12, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, "Segoe UI");

    wxStaticText* basicOperationsLabel = new wxStaticText(panel, wxID_ANY, "Basic Operations");
    basicOperationsLabel->SetForegroundColour(wxColour(255, 255, 255)); // White text color
    basicOperationsLabel->SetFont(font);
    vbox->Add(basicOperationsLabel, 0, wxALIGN_CENTER | wxTOP | wxBOTTOM, 10);

    wxGridSizer* basicGridSizer = new wxGridSizer(2, 2, 5, 5);
    wxButton* btnAdd = new wxButton(panel, ID_Add, "Add", wxDefaultPosition, wxDefaultSize, wxBORDER_NONE);
    btnAdd->SetBackgroundColour(wxColour(64, 64, 64));
    btnAdd->SetForegroundColour(wxColour(255, 255, 255));
    btnAdd->SetFont(font);
    wxButton* btnSubtract = new wxButton(panel, ID_Subtract, "Subtract", wxDefaultPosition, wxDefaultSize, wxBORDER_NONE);
    btnSubtract->SetBackgroundColour(wxColour(64, 64, 64));
    btnSubtract->SetForegroundColour(wxColour(255, 255, 255));
    btnSubtract->SetFont(font);
    wxButton* btnMultiply = new wxButton(panel, ID_Multiply, "Multiply", wxDefaultPosition, wxDefaultSize, wxBORDER_NONE);
    btnMultiply->SetBackgroundColour(wxColour(64, 64, 64));
    btnMultiply->SetForegroundColour(wxColour(255, 255, 255));
    btnMultiply->SetFont(font);
    wxButton* btnDivide = new wxButton(panel, ID_Divide, "Divide", wxDefaultPosition, wxDefaultSize, wxBORDER_NONE);
    btnDivide->SetBackgroundColour(wxColour(64, 64, 64));
    btnDivide->SetForegroundColour(wxColour(255, 255, 255));
    btnDivide->SetFont(font);
    basicGridSizer->Add(btnAdd, 1, wxEXPAND);
    basicGridSizer->Add(btnSubtract, 1, wxEXPAND);
    basicGridSizer->Add(btnMultiply, 1, wxEXPAND);
    basicGridSizer->Add(btnDivide, 1, wxEXPAND);
    vbox->Add(basicGridSizer, 0, wxEXPAND | wxALL, 10);

    wxStaticLine* separator1 = new wxStaticLine(panel, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL);
    vbox->Add(separator1, 0, wxEXPAND | wxLEFT | wxRIGHT, 10);

    wxStaticText* trigonometryLabel = new wxStaticText(panel, wxID_ANY, "Trigonometry");
    trigonometryLabel->SetForegroundColour(wxColour(255, 255, 255));
    trigonometryLabel->SetFont(font);
    vbox->Add(trigonometryLabel, 0, wxALIGN_CENTER | wxTOP | wxBOTTOM, 10);

    wxGridSizer* trigGridSizer = new wxGridSizer(2, 3, 5, 5);
    wxButton* btnSine = new wxButton(panel, ID_Sine, "Sine", wxDefaultPosition, wxDefaultSize, wxBORDER_NONE);
    btnSine->SetBackgroundColour(wxColour(64, 64, 64));
    btnSine->SetForegroundColour(wxColour(255, 255, 255));
    btnSine->SetFont(font);
    wxButton* btnCosine = new wxButton(panel, ID_Cosine, "Cosine", wxDefaultPosition, wxDefaultSize, wxBORDER_NONE);
    btnCosine->SetBackgroundColour(wxColour(64, 64, 64));
    btnCosine->SetForegroundColour(wxColour(255, 255, 255));
    btnCosine->SetFont(font);
    wxButton* btnTangent = new wxButton(panel, ID_Tangent, "Tangent", wxDefaultPosition, wxDefaultSize, wxBORDER_NONE);
    btnTangent->SetBackgroundColour(wxColour(64, 64, 64));
    btnTangent->SetForegroundColour(wxColour(255, 255, 255));
    btnTangent->SetFont(font);
    wxButton* btnDegToRad = new wxButton(panel, ID_DegToRad, "Deg to Rad", wxDefaultPosition, wxDefaultSize, wxBORDER_NONE);
    btnDegToRad->SetBackgroundColour(wxColour(64, 64, 64));
    btnDegToRad->SetForegroundColour(wxColour(255, 255, 255));
    btnDegToRad->SetFont(font);
    trigGridSizer->Add(btnSine, 1, wxEXPAND);
    trigGridSizer->Add(btnCosine, 1, wxEXPAND);
    trigGridSizer->Add(btnTangent, 1, wxEXPAND);
    trigGridSizer->Add(btnDegToRad, 1, wxEXPAND);
    vbox->Add(trigGridSizer, 0, wxEXPAND | wxALL, 10);

    wxStaticLine* separator2 = new wxStaticLine(panel, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL);
    vbox->Add(separator2, 0, wxEXPAND | wxLEFT | wxRIGHT, 10);

    wxStaticText* exponentialLabel = new wxStaticText(panel, wxID_ANY, "Exponential and Logarithmic");
    exponentialLabel->SetForegroundColour(wxColour(255, 255, 255));
    exponentialLabel->SetFont(font);
    vbox->Add(exponentialLabel, 0, wxALIGN_CENTER | wxTOP | wxBOTTOM, 10);

    wxGridSizer* expLogGridSizer = new wxGridSizer(2, 3, 5, 5);
    wxButton* btnExponent = new wxButton(panel, ID_Exponent, "Exponent", wxDefaultPosition, wxDefaultSize, wxBORDER_NONE);
    btnExponent->SetBackgroundColour(wxColour(64, 64, 64));
    btnExponent->SetForegroundColour(wxColour(255, 255, 255));
    btnExponent->SetFont(font);
    wxButton* btnNaturalLog = new wxButton(panel, ID_NaturalLog, "Natural Log", wxDefaultPosition, wxDefaultSize, wxBORDER_NONE);
    btnNaturalLog->SetBackgroundColour(wxColour(64, 64, 64));
    btnNaturalLog->SetForegroundColour(wxColour(255, 255, 255));
    btnNaturalLog->SetFont(font);
    wxButton* btnLogBase10 = new wxButton(panel, ID_LogBase10, "Log Base 10", wxDefaultPosition, wxDefaultSize, wxBORDER_NONE);
    btnLogBase10->SetBackgroundColour(wxColour(64, 64, 64));
    btnLogBase10->SetForegroundColour(wxColour(255, 255, 255));
    btnLogBase10->SetFont(font);
    wxButton* btnExp = new wxButton(panel, ID_Exp, "Exp", wxDefaultPosition, wxDefaultSize, wxBORDER_NONE);
    btnExp->SetBackgroundColour(wxColour(64, 64, 64));
    btnExp->SetForegroundColour(wxColour(255, 255, 255));
    btnExp->SetFont(font);
    expLogGridSizer->Add(btnExponent, 1, wxEXPAND);
    expLogGridSizer->Add(btnNaturalLog, 1, wxEXPAND);
    expLogGridSizer->Add(btnLogBase10, 1, wxEXPAND);
    expLogGridSizer->Add(btnExp, 1, wxEXPAND);
    vbox->Add(expLogGridSizer, 0, wxEXPAND | wxALL, 10);

    wxStaticLine* separator3 = new wxStaticLine(panel, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL);
    vbox->Add(separator3, 0, wxEXPAND | wxLEFT | wxRIGHT, 10);

    wxStaticText* complexLabel = new wxStaticText(panel, wxID_ANY, "Complex Numbers");
    complexLabel->SetForegroundColour(wxColour(255, 255, 255));
    complexLabel->SetFont(font);
    vbox->Add(complexLabel, 0, wxALIGN_CENTER | wxTOP | wxBOTTOM, 10);

    wxGridSizer* complexGridSizer = new wxGridSizer(3, 2, 5, 5);
    wxButton* btnComplexAdd = new wxButton(panel, ID_ComplexAdd, "Complex Add", wxDefaultPosition, wxDefaultSize, wxBORDER_NONE);
    btnComplexAdd->SetBackgroundColour(wxColour(64, 64, 64));
    btnComplexAdd->SetForegroundColour(wxColour(255, 255, 255));
    btnComplexAdd->SetFont(font);
    wxButton* btnComplexSubtract = new wxButton(panel, ID_ComplexSubtract, "Complex Subtract", wxDefaultPosition, wxDefaultSize, wxBORDER_NONE);
    btnComplexSubtract->SetBackgroundColour(wxColour(64, 64, 64));
    btnComplexSubtract->SetForegroundColour(wxColour(255, 255, 255));
    btnComplexSubtract->SetFont(font);
    wxButton* btnComplexMultiply = new wxButton(panel, ID_ComplexMultiply, "Complex Multiply", wxDefaultPosition, wxDefaultSize, wxBORDER_NONE);
    btnComplexMultiply->SetBackgroundColour(wxColour(64, 64, 64));
    btnComplexMultiply->SetForegroundColour(wxColour(255, 255, 255));
    btnComplexMultiply->SetFont(font);
    wxButton* btnComplexDivide = new wxButton(panel, ID_ComplexDivide, "Complex Divide", wxDefaultPosition, wxDefaultSize, wxBORDER_NONE);
    btnComplexDivide->SetBackgroundColour(wxColour(64, 64, 64));
    btnComplexDivide->SetForegroundColour(wxColour(255, 255, 255));
    btnComplexDivide->SetFont(font);
    wxButton* btnComplexMagnitude = new wxButton(panel, ID_ComplexMagnitude, "Complex Magnitude", wxDefaultPosition, wxDefaultSize, wxBORDER_NONE);
    btnComplexMagnitude->SetBackgroundColour(wxColour(64, 64, 64));
    btnComplexMagnitude->SetForegroundColour(wxColour(255, 255, 255));
    btnComplexMagnitude->SetFont(font);
    wxButton* btnComplexArgument = new wxButton(panel, ID_ComplexArgument, "Complex Argument", wxDefaultPosition, wxDefaultSize, wxBORDER_NONE);
    btnComplexArgument->SetBackgroundColour(wxColour(64, 64, 64));
    btnComplexArgument->SetForegroundColour(wxColour(255, 255, 255));
    btnComplexArgument->SetFont(font);
    complexGridSizer->Add(btnComplexAdd, 1, wxEXPAND);
    complexGridSizer->Add(btnComplexSubtract, 1, wxEXPAND);
    complexGridSizer->Add(btnComplexMultiply, 1, wxEXPAND);
    complexGridSizer->Add(btnComplexDivide, 1, wxEXPAND);
    complexGridSizer->Add(btnComplexMagnitude, 1, wxEXPAND);
    complexGridSizer->Add(btnComplexArgument, 1, wxEXPAND);
    vbox->Add(complexGridSizer, 0, wxEXPAND | wxALL, 10);

    wxStaticLine* separator4 = new wxStaticLine(panel, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL);
    vbox->Add(separator4, 0, wxEXPAND | wxLEFT | wxRIGHT, 10);

    wxStaticText* statisticsLabel = new wxStaticText(panel, wxID_ANY, "Statistics");
    statisticsLabel->SetForegroundColour(wxColour(255, 255, 255));
    statisticsLabel->SetFont(font);
    vbox->Add(statisticsLabel, 0, wxALIGN_CENTER | wxTOP | wxBOTTOM, 10);

    wxGridSizer* statisticsGridSizer = new wxGridSizer(3, 2, 5, 5);
    wxButton* btnMean = new wxButton(panel, ID_Mean, "Mean", wxDefaultPosition, wxDefaultSize, wxBORDER_NONE);
    btnMean->SetBackgroundColour(wxColour(64, 64, 64));
    btnMean->SetForegroundColour(wxColour(255, 255, 255));
    btnMean->SetFont(font);
    wxButton* btnMedian = new wxButton(panel, ID_Median, "Median", wxDefaultPosition, wxDefaultSize, wxBORDER_NONE);
    btnMedian->SetBackgroundColour(wxColour(64, 64, 64));
    btnMedian->SetForegroundColour(wxColour(255, 255, 255));
    btnMedian->SetFont(font);
    wxButton* btnMode = new wxButton(panel, ID_Mode, "Mode", wxDefaultPosition, wxDefaultSize, wxBORDER_NONE);
    btnMode->SetBackgroundColour(wxColour(64, 64, 64));
    btnMode->SetForegroundColour(wxColour(255, 255, 255));
    btnMode->SetFont(font);
    wxButton* btnVariance = new wxButton(panel, ID_Variance, "Variance", wxDefaultPosition, wxDefaultSize, wxBORDER_NONE);
    btnVariance->SetBackgroundColour(wxColour(64, 64, 64));
    btnVariance->SetForegroundColour(wxColour(255, 255, 255));
    btnVariance->SetFont(font);
    wxButton* btnStandardDeviation = new wxButton(panel, ID_StandardDeviation, "Standard Deviation", wxDefaultPosition, wxDefaultSize, wxBORDER_NONE);
    btnStandardDeviation->SetBackgroundColour(wxColour(64, 64, 64));
    btnStandardDeviation->SetForegroundColour(wxColour(255, 255, 255));
    btnStandardDeviation->SetFont(font);
    statisticsGridSizer->Add(btnMean, 1, wxEXPAND);
    statisticsGridSizer->Add(btnMedian, 1, wxEXPAND);
    statisticsGridSizer->Add(btnMode, 1, wxEXPAND);
    statisticsGridSizer->Add(btnVariance, 1, wxEXPAND);
    statisticsGridSizer->Add(btnStandardDeviation, 1, wxEXPAND);
    vbox->Add(statisticsGridSizer, 0, wxEXPAND | wxALL, 10);

    wxStaticLine* separator5 = new wxStaticLine(panel, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL);
    vbox->Add(separator5, 0, wxEXPAND | wxLEFT | wxRIGHT, 10);

    wxStaticText* miscLabel = new wxStaticText(panel, wxID_ANY, "Miscellaneous");
    miscLabel->SetForegroundColour(wxColour(255, 255, 255));
    miscLabel->SetFont(font);
    vbox->Add(miscLabel, 0, wxALIGN_CENTER | wxTOP | wxBOTTOM, 10);

    wxGridSizer* miscGridSizer = new wxGridSizer(3, 3, 5, 5);
    wxButton* btnIsPrime = new wxButton(panel, ID_IsPrime, "Is Prime", wxDefaultPosition, wxDefaultSize, wxBORDER_NONE);
    btnIsPrime->SetBackgroundColour(wxColour(64, 64, 64));
    btnIsPrime->SetForegroundColour(wxColour(255, 255, 255));
    btnIsPrime->SetFont(font);
    wxButton* btnFactorize = new wxButton(panel, ID_Factorize, "Factorize", wxDefaultPosition, wxDefaultSize, wxBORDER_NONE);
    btnFactorize->SetBackgroundColour(wxColour(64, 64, 64));
    btnFactorize->SetForegroundColour(wxColour(255, 255, 255));
    btnFactorize->SetFont(font);
    wxButton* btnSurfaceAreaRectangularPrism = new wxButton(panel, ID_SurfaceAreaRectangularPrism, "Surface Area Rectangular Prism", wxDefaultPosition, wxDefaultSize, wxBORDER_NONE);
    btnSurfaceAreaRectangularPrism->SetBackgroundColour(wxColour(64, 64, 64));
    btnSurfaceAreaRectangularPrism->SetForegroundColour(wxColour(255, 255, 255));
    btnSurfaceAreaRectangularPrism->SetFont(font);
    wxButton* btnSurfaceAreaCylinder = new wxButton(panel, ID_SurfaceAreaCylinder, "Surface Area Cylinder", wxDefaultPosition, wxDefaultSize, wxBORDER_NONE);
    btnSurfaceAreaCylinder->SetBackgroundColour(wxColour(64, 64, 64));
    btnSurfaceAreaCylinder->SetForegroundColour(wxColour(255, 255, 255));
    btnSurfaceAreaCylinder->SetFont(font);
    wxButton* btnSurfaceAreaCircle = new wxButton(panel, ID_SurfaceAreaCircle, "Surface Area Circle", wxDefaultPosition, wxDefaultSize, wxBORDER_NONE);
    btnSurfaceAreaCircle->SetBackgroundColour(wxColour(64, 64, 64));
    btnSurfaceAreaCircle->SetForegroundColour(wxColour(255, 255, 255));
    btnSurfaceAreaCircle->SetFont(font);
    wxButton* btnArcLengthCircle = new wxButton(panel, ID_ArcLengthCircle, "Arc Length Circle", wxDefaultPosition, wxDefaultSize, wxBORDER_NONE);
    btnArcLengthCircle->SetBackgroundColour(wxColour(64, 64, 64));
    btnArcLengthCircle->SetForegroundColour(wxColour(255, 255, 255));
    btnArcLengthCircle->SetFont(font);
    wxButton* btnConvertCurrency = new wxButton(panel, ID_Convert_Currency, "Convert Currency", wxDefaultPosition, wxDefaultSize, wxBORDER_NONE);
    btnConvertCurrency->SetBackgroundColour(wxColour(64, 64, 64));
    btnConvertCurrency->SetForegroundColour(wxColour(255, 255, 255));
    btnConvertCurrency->SetFont(font);
    miscGridSizer->Add(btnConvertCurrency, 1, wxEXPAND);
    wxStaticText* dataConversionsLabel = new wxStaticText(panel, wxID_ANY, "Data Conversions");
    dataConversionsLabel->SetForegroundColour(wxColour(255, 255, 255));
    dataConversionsLabel->SetFont(font);
    vbox->Add(dataConversionsLabel, 0, wxALIGN_CENTER | wxTOP | wxBOTTOM, 10);
    wxButton* btnGraph = new wxButton(panel, ID_Graph, "Graph", wxDefaultPosition, wxDefaultSize, wxBORDER_NONE);
    btnGraph->SetBackgroundColour(wxColour(64, 64, 64));
    btnGraph->SetForegroundColour(wxColour(255, 255, 255));
    btnGraph->SetFont(font);
    miscGridSizer->Add(btnGraph, 1, wxEXPAND);
    wxGridSizer* dataConversionsGridSizer = new wxGridSizer(2, 2, 5, 5);
    wxButton* btnIntToBinary = new wxButton(panel, ID_IntToBinary, "Int to Binary", wxDefaultPosition, wxDefaultSize, wxBORDER_NONE);
    btnIntToBinary->SetBackgroundColour(wxColour(64, 64, 64));
    btnIntToBinary->SetForegroundColour(wxColour(255, 255, 255));
    btnIntToBinary->SetFont(font);
    wxButton* btnIntToHex = new wxButton(panel, ID_IntToHex, "Int to Hex", wxDefaultPosition, wxDefaultSize, wxBORDER_NONE);
    btnIntToHex->SetBackgroundColour(wxColour(64, 64, 64));
    btnIntToHex->SetForegroundColour(wxColour(255, 255, 255));
    btnIntToHex->SetFont(font);
    wxButton* btnBinaryToInt = new wxButton(panel, ID_BinaryToInt, "Binary to Int", wxDefaultPosition, wxDefaultSize, wxBORDER_NONE);
    btnBinaryToInt->SetBackgroundColour(wxColour(64, 64, 64));
    btnBinaryToInt->SetForegroundColour(wxColour(255, 255, 255));
    btnBinaryToInt->SetFont(font);
    wxButton* btnHexToInt = new wxButton(panel, ID_HexToInt, "Hex to Int", wxDefaultPosition, wxDefaultSize, wxBORDER_NONE);
    btnHexToInt->SetBackgroundColour(wxColour(64, 64, 64));
    btnHexToInt->SetForegroundColour(wxColour(255, 255, 255));
    btnHexToInt->SetFont(font);
    dataConversionsGridSizer->Add(btnIntToBinary, 1, wxEXPAND);
    dataConversionsGridSizer->Add(btnIntToHex, 1, wxEXPAND);
    dataConversionsGridSizer->Add(btnBinaryToInt, 1, wxEXPAND);
    dataConversionsGridSizer->Add(btnHexToInt, 1, wxEXPAND);
    vbox->Add(dataConversionsGridSizer, 0, wxEXPAND | wxALL, 10);

    wxStaticText* unitConversionsLabel = new wxStaticText(panel, wxID_ANY, "Unit Conversions");
    unitConversionsLabel->SetForegroundColour(wxColour(255, 255, 255));
    unitConversionsLabel->SetFont(font);
    vbox->Add(unitConversionsLabel, 0, wxALIGN_CENTER | wxTOP | wxBOTTOM, 10);

    wxGridSizer* unitConversionsGridSizer = new wxGridSizer(2, 3, 5, 5);
    wxButton* btnCelsiusToFahrenheit = new wxButton(panel, ID_CelsiusToFahrenheit, "Celsius to Fahrenheit", wxDefaultPosition, wxDefaultSize, wxBORDER_NONE);
    btnCelsiusToFahrenheit->SetBackgroundColour(wxColour(64, 64, 64));
    btnCelsiusToFahrenheit->SetForegroundColour(wxColour(255, 255, 255));
    btnCelsiusToFahrenheit->SetFont(font);
    wxButton* btnFahrenheitToCelsius = new wxButton(panel, ID_FahrenheitToCelsius, "Fahrenheit to Celsius", wxDefaultPosition, wxDefaultSize, wxBORDER_NONE);
    btnFahrenheitToCelsius->SetBackgroundColour(wxColour(64, 64, 64));
    btnFahrenheitToCelsius->SetForegroundColour(wxColour(255, 255, 255));
    btnFahrenheitToCelsius->SetFont(font);
    wxButton* btnMetersToFeet = new wxButton(panel, ID_MetersToFeet, "Meters to Feet", wxDefaultPosition, wxDefaultSize, wxBORDER_NONE);
    btnMetersToFeet->SetBackgroundColour(wxColour(64, 64, 64));
    btnMetersToFeet->SetForegroundColour(wxColour(255, 255, 255));
    btnMetersToFeet->SetFont(font);
    wxButton* btnFeetToMeters = new wxButton(panel, ID_FeetToMeters, "Feet to Meters", wxDefaultPosition, wxDefaultSize, wxBORDER_NONE);
    btnFeetToMeters->SetBackgroundColour(wxColour(64, 64, 64));
    btnFeetToMeters->SetForegroundColour(wxColour(255, 255, 255));
    btnFeetToMeters->SetFont(font);
    wxButton* btnKilogramsToPounds = new wxButton(panel, ID_KilogramsToPounds, "Kilograms to Pounds", wxDefaultPosition, wxDefaultSize, wxBORDER_NONE);
    btnKilogramsToPounds->SetBackgroundColour(wxColour(64, 64, 64));
    btnKilogramsToPounds->SetForegroundColour(wxColour(255, 255, 255));
    btnKilogramsToPounds->SetFont(font);
    wxButton* btnPoundsToKilograms = new wxButton(panel, ID_PoundsToKilograms, "Pounds to Kilograms", wxDefaultPosition, wxDefaultSize, wxBORDER_NONE);
    btnPoundsToKilograms->SetBackgroundColour(wxColour(64, 64, 64));
    btnPoundsToKilograms->SetForegroundColour(wxColour(255, 255, 255));
    btnPoundsToKilograms->SetFont(font);
    unitConversionsGridSizer->Add(btnCelsiusToFahrenheit, 1, wxEXPAND);
    unitConversionsGridSizer->Add(btnFahrenheitToCelsius, 1, wxEXPAND);
    unitConversionsGridSizer->Add(btnMetersToFeet, 1, wxEXPAND);
    unitConversionsGridSizer->Add(btnFeetToMeters, 1, wxEXPAND);
    unitConversionsGridSizer->Add(btnKilogramsToPounds, 1, wxEXPAND);
    unitConversionsGridSizer->Add(btnPoundsToKilograms, 1, wxEXPAND);
    vbox->Add(unitConversionsGridSizer, 0, wxEXPAND | wxALL, 10);
    miscGridSizer->Add(btnIsPrime, 1, wxEXPAND);
    miscGridSizer->Add(btnFactorize, 1, wxEXPAND);
    miscGridSizer->Add(btnSurfaceAreaRectangularPrism, 1, wxEXPAND);
    miscGridSizer->Add(btnSurfaceAreaCylinder, 1, wxEXPAND);
    miscGridSizer->Add(btnSurfaceAreaCircle, 1, wxEXPAND);
    miscGridSizer->Add(btnArcLengthCircle, 1, wxEXPAND);
    vbox->Add(miscGridSizer, 0, wxEXPAND | wxALL, 10);

    wxBoxSizer* hbox3 = new wxBoxSizer(wxHORIZONTAL);
    resultLabel = new wxStaticText(panel, wxID_ANY, "Result: ");
    resultLabel->SetForegroundColour(wxColour(255, 255, 255));
    resultLabel->SetFont(font);
    hbox3->Add(resultLabel, 1, wxEXPAND | wxALL, 10);
    vbox->Add(hbox3, 0, wxEXPAND);

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
        GraphPanel* graphPanel = new GraphPanel(graphFrame, function.ToStdString());
        graphFrame->Show(true);
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
    long n;
    inputA->GetValue().ToLong(&n);
    bool result = calculator.isPrime(n);
    resultLabel->SetLabel(wxString::Format("Is Prime: %s", result ? "true" : "false"));
}

void MainFrame::OnFactorize(wxCommandEvent& event) {
    long n;
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
void MainFrame::OnConvertCurrency(wxCommandEvent& event) {
    double amount;
    std::string fromCurrency = wxGetTextFromUser("Enter the source currency code (e.g., USD):", "Convert Currency").ToStdString();
    std::string toCurrency = wxGetTextFromUser("Enter the target currency code (e.g., EUR):", "Convert Currency").ToStdString();
    inputA->GetValue().ToDouble(&amount);
    double result = calculator.convertCurrency(amount, fromCurrency, toCurrency);
    resultLabel->SetLabel(wxString::Format("Result: %f", result));
}

void MainFrame::OnIntToBinary(wxCommandEvent& event) {
    long n;
    inputA->GetValue().ToLong(&n);
    std::string result = calculator.intToBinary(n);
    resultLabel->SetLabel(wxString::Format("Binary: %s", result));
}

void MainFrame::OnIntToHex(wxCommandEvent& event) {
    long n;
    inputA->GetValue().ToLong(&n);
    std::string result = calculator.intToHex(n);
    resultLabel->SetLabel(wxString::Format("Hex: %s", result));
}

void MainFrame::OnBinaryToInt(wxCommandEvent& event) {
    wxString binary = inputA->GetValue();
    int result = calculator.binaryToInt(binary.ToStdString());
    resultLabel->SetLabel(wxString::Format("Integer: %d", result));
}

void MainFrame::OnHexToInt(wxCommandEvent& event) {
    wxString hex = inputA->GetValue();
    int result = calculator.hexToInt(hex.ToStdString());
    resultLabel->SetLabel(wxString::Format("Integer: %d", result));
}

void MainFrame::OnCelsiusToFahrenheit(wxCommandEvent& event) {
    double celsius;
    inputA->GetValue().ToDouble(&celsius);
    double result = calculator.celsiusToFahrenheit(celsius);
    resultLabel->SetLabel(wxString::Format("Fahrenheit: %f", result));
}

void MainFrame::OnFahrenheitToCelsius(wxCommandEvent& event) {
    double fahrenheit;
    inputA->GetValue().ToDouble(&fahrenheit);
    double result = calculator.fahrenheitToCelsius(fahrenheit);
    resultLabel->SetLabel(wxString::Format("Celsius: %f", result));
}

void MainFrame::OnMetersToFeet(wxCommandEvent& event) {
    double meters;
    inputA->GetValue().ToDouble(&meters);
    double result = calculator.metersToFeet(meters);
    resultLabel->SetLabel(wxString::Format("Feet: %f", result));
}

void MainFrame::OnFeetToMeters(wxCommandEvent& event) {
    double feet;
    inputA->GetValue().ToDouble(&feet);
    double result = calculator.feetToMeters(feet);
    resultLabel->SetLabel(wxString::Format("Meters: %f", result));
}

void MainFrame::OnKilogramsToPounds(wxCommandEvent& event) {
    double kilograms;
    inputA->GetValue().ToDouble(&kilograms);
    double result = calculator.kilogramsToPounds(kilograms);
    resultLabel->SetLabel(wxString::Format("Pounds: %f", result));
}

void MainFrame::OnPoundsToKilograms(wxCommandEvent& event) {
    double pounds;
    inputA->GetValue().ToDouble(&pounds);
    double result = calculator.poundsToKilograms(pounds);
    resultLabel->SetLabel(wxString::Format("Kilograms: %f", result));
}
