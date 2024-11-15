#include "calculator.h"
#include <QGridLayout>
#include <QWidget>
#include <QRegularExpression>
#include <QMessageBox>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QScrollArea>
#include <QtMath>        
#include <cmath>         

AnimatedButton::AnimatedButton(const QString &text, QWidget *parent) 
    : QPushButton(text, parent)
{
    animation = new QPropertyAnimation(this, "geometry");
    animation->setDuration(100);
}

void AnimatedButton::mousePressEvent(QMouseEvent *e)
{
    QRect geometryRect = geometry();
    animation->setStartValue(geometryRect);
    animation->setEndValue(geometryRect.adjusted(2, 2, -2, -2));
    animation->start();
    QPushButton::mousePressEvent(e);
}

void AnimatedButton::mouseReleaseEvent(QMouseEvent *e)
{
    QRect geometryRect = geometry();
    animation->setStartValue(geometryRect);
    animation->setEndValue(geometryRect.adjusted(-2, -2, 2, 2));
    animation->start();
    QPushButton::mouseReleaseEvent(e);
}

Calculator::Calculator(QWidget *parent)
    : QMainWindow(parent)
    , firstNum(0)
    , userIsTypingSecondNumber(false)
    , isScientificMode(false)
    , parenthesesCount(0)
{
    setupUI();
    setupStyle();
}

Calculator::~Calculator()
{
}

void Calculator::setupUI()
{
    centralWidget = new QWidget(this);
    setCentralWidget(centralWidget);
    
    mainLayout = new QGridLayout;
    
    display = new QLineEdit("0");
    display->setReadOnly(true);
    display->setAlignment(Qt::AlignRight);
    display->setMaxLength(25);
    
    QFont font = display->font();
    font.setPointSize(24);
    display->setFont(font);
    
    mainLayout->addWidget(display, 0, 0, 1, 8);
    
    historyWidget = new QListWidget(this);
    historyWidget->setMaximumWidth(200);
    historyWidget->setHidden(true);
    
    createBasicButtons();
    createScientificButtons();
    createMemoryButtons();
    
    AnimatedButton *toggleButton = new AnimatedButton("≡");
    connect(toggleButton, &AnimatedButton::clicked, this, &Calculator::ToggleScientificMode);
    mainLayout->addWidget(toggleButton, 1, 7);
    
    centralWidget->setLayout(mainLayout);
    setMinimumSize(400, 600);
}

void Calculator::setupStyle()
{
    QString styleSheet = R"(
        QMainWindow {
            background-color: #1e1e1e;
        }
        QLineEdit {
            background-color: #2d2d2d;
            color: #ffffff;
            border: none;
            border-radius: 5px;
            padding: 10px;
            margin: 10px;
        }
        QPushButton {
            background-color: #3d3d3d;
            color: #ffffff;
            border: none;
            border-radius: 25px;
            min-width: 50px;
            min-height: 50px;
            font-size: 16px;
            margin: 2px;
        }
        QPushButton:hover {
            background-color: #4d4d4d;
        }
        QPushButton:pressed {
            background-color: #5d5d5d;
        }
        QPushButton[class='operator'] {
            background-color: #ff9500;
        }
        QPushButton[class='operator']:hover {
            background-color: #ffaa33;
        }
        QListWidget {
            background-color: #2d2d2d;
            color: #ffffff;
            border: none;
            border-radius: 5px;
            padding: 5px;
        }
    )";
    
    setStyleSheet(styleSheet);
}

void Calculator::createBasicButtons()
{
    const char* buttonLabels[5][4] = {
        {"C", "←", "()", "/"},
        {"7", "8", "9", "*"},
        {"4", "5", "6", "-"},
        {"1", "2", "3", "+"},
        {"0", ".", "=", ""}
    };

    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 4; ++j) {
            if (QString(buttonLabels[i][j]).isEmpty()) continue;
            
            AnimatedButton *button = new AnimatedButton(buttonLabels[i][j]);
            
            if (QString(buttonLabels[i][j]) == "=") {
                button->setProperty("class", "operator");
                connect(button, &AnimatedButton::clicked, this, &Calculator::EqualButtonPressed);
            }
            else if (QString(buttonLabels[i][j]) == "C") {
                connect(button, &AnimatedButton::clicked, this, &Calculator::ClearButton);
            }
            else if (QString(buttonLabels[i][j]) == "←") {
                connect(button, &AnimatedButton::clicked, this, &Calculator::BackspacePressed);
            }
            else if (QString(buttonLabels[i][j]) == "()") {
                connect(button, &AnimatedButton::clicked, this, &Calculator::ParenthesesPressed);
            }
            else if (QString(buttonLabels[i][j]).contains(QRegularExpression("[0-9.]"))) {
                connect(button, &AnimatedButton::clicked, this, &Calculator::NumPressed);
            }
            else {
                button->setProperty("class", "operator");
                connect(button, &AnimatedButton::clicked, this, &Calculator::MathButtonPressed);
            }
            
            mainLayout->addWidget(button, i + 1, j);
        }
    }
}

void Calculator::createScientificButtons()
{
    QStringList scientificFunctions = {
        "sin", "cos", "tan",
        "log", "ln", "√",
        "x²", "x³", "xʸ",
        "π", "e", "MOD"
    };
    
    int row = 1;
    for (const QString &func : scientificFunctions) {
        AnimatedButton *button = new AnimatedButton(func);
        connect(button, &AnimatedButton::clicked, this, &Calculator::ScientificButtonPressed);
        button->setHidden(true);
        mainLayout->addWidget(button, row, 4);
        scientificButtons.append(button);
        row = (row % 5) + 1;
    }
}

void Calculator::createMemoryButtons()
{
    QStringList memoryCommands = {"M+", "M-", "MR"};
    int col = 5;
    for (const QString &cmd : memoryCommands) {
        AnimatedButton *button = new AnimatedButton(cmd);
        connect(button, &AnimatedButton::clicked, this, &Calculator::MemoryButtonPressed);
        mainLayout->addWidget(button, 1, col++);
    }
}

void Calculator::NumPressed()
{
    AnimatedButton *button = qobject_cast<AnimatedButton*>(sender());
    QString butVal = button->text();
    
    if (display->text() == "0" || userIsTypingSecondNumber) {
        display->setText(butVal);
        userIsTypingSecondNumber = false;
    } else {
        display->setText(display->text() + butVal);
    }
}

void Calculator::MathButtonPressed()
{
    userIsTypingSecondNumber = true;
    AnimatedButton *button = qobject_cast<AnimatedButton*>(sender());
    firstNum = display->text().toDouble();
    operation = button->text();
}

void Calculator::ScientificButtonPressed()
{
    AnimatedButton *button = qobject_cast<AnimatedButton*>(sender());
    QString func = button->text();
    double value = display->text().toDouble();
    double result = evaluateScientificFunction(func, value);
    display->setText(QString::number(result));
}

double Calculator::evaluateScientificFunction(const QString &func, double value)
{
    if (func == "sin") return qSin(value);
    if (func == "cos") return qCos(value);
    if (func == "tan") return qTan(value);
    if (func == "log") return std::log10(value);  
    if (func == "ln") return std::log(value);     
    if (func == "√") return qSqrt(value);
    if (func == "x²") return value * value;
    if (func == "x³") return value * value * value;
    if (func == "π") return M_PI;
    if (func == "e") return M_E;
    
    return value;
}

void Calculator::EqualButtonPressed()
{
    double secondNum = display->text().toDouble();
    double result = 0.0;

    if (operation == "+") {
        result = firstNum + secondNum;
    } else if (operation == "-") {
        result = firstNum - secondNum;
    } else if (operation == "*") {
        result = firstNum * secondNum;
    } else if (operation == "/") {
        if (secondNum != 0) {
            result = firstNum / secondNum;
        } else {
            display->setText("Error");
            return;
        }
    }

    display->setText(QString::number(result));
    addToHistory(QString("%1 %2 %3").arg(QString::number(firstNum), operation, QString::number(secondNum)),
                QString::number(result));
}

void Calculator::ClearButton()
{
    display->setText("0");
    firstNum = 0;
    userIsTypingSecondNumber = false;
    operation = "";
    parenthesesCount = 0;
}

void Calculator::BackspacePressed()
{
    QString text = display->text();
    text.chop(1);
    if (text.isEmpty()) {
        text = "0";
    }
    display->setText(text);
}

void Calculator::ParenthesesPressed()
{
    QString text = display->text();
    if (parenthesesCount == 0 || text.count('(') == text.count(')')) {
        display->setText(text + "(");
        parenthesesCount++;
    } else {
        display->setText(text + ")");
        parenthesesCount--;
    }
}

void Calculator::ToggleScientificMode()
{
    isScientificMode = !isScientificMode;
    for (AnimatedButton* button : scientificButtons) {
        button->setHidden(!isScientificMode);
    }
    historyWidget->setHidden(!isScientificMode);
    
    if (isScientificMode) {
        setMinimumWidth(600);
    } else {
        setMinimumWidth(400);
    }
}

void Calculator::MemoryButtonPressed()
{
    AnimatedButton *button = qobject_cast<AnimatedButton*>(sender());
    QString command = button->text();
    
    if (command == "M+") {
        memory.push(display->text().toDouble());
    } else if (command == "M-") {
        if (!memory.isEmpty()) {
            memory.pop();
        }
    } else if (command == "MR") {
        if (!memory.isEmpty()) {
            display->setText(QString::number(memory.top()));
        }
    }
}

void Calculator::addToHistory(const QString &expression, const QString &result)
{
    QString historyEntry = QString("%1 = %2").arg(expression, result);
    history.append(historyEntry);
    historyWidget->addItem(historyEntry);
    historyWidget->scrollToBottom();
}