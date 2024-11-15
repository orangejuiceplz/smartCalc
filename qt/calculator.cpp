#include "calculator.h"
#include <QGridLayout>
#include <QWidget>
#include <QRegularExpression>

Calculator::Calculator(QWidget *parent)
    : QMainWindow(parent), firstNum(0), userIsTypingSecondNumber(false)
{
    QWidget *centralWidget = new QWidget(this);
    setCentralWidget(centralWidget);

    display = new QLineEdit("0");
    display->setReadOnly(true);
    display->setAlignment(Qt::AlignRight);
    display->setMaxLength(15);
    
    QFont font = display->font();
    font.setPointSize(18);
    display->setFont(font);

    const char* buttonLabels[4][4] = {
        {"7", "8", "9", "/"},
        {"4", "5", "6", "*"},
        {"1", "2", "3", "-"},
        {"0", ".", "=", "+"}
    };

    QGridLayout *layout = new QGridLayout;
    layout->addWidget(display, 0, 0, 1, 4);

    QPushButton *clearButton = new QPushButton("C", this);
    layout->addWidget(clearButton, 1, 0, 1, 4);
    connect(clearButton, &QPushButton::clicked, this, &Calculator::ClearButton);

    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            QPushButton *button = new QPushButton(buttonLabels[i][j]);
            button->setMinimumSize(50, 50);
            
            if (QString(buttonLabels[i][j]) == "=") {
                connect(button, &QPushButton::clicked, this, &Calculator::EqualButtonPressed);
            }
            else if (QString(buttonLabels[i][j]).contains(QRegularExpression("[0-9.]"))) {
                connect(button, &QPushButton::clicked, this, &Calculator::NumPressed);
            }
            else {
                connect(button, &QPushButton::clicked, this, &Calculator::MathButtonPressed);
            }
            
            layout->addWidget(button, i + 2, j);
        }
    }

    centralWidget->setLayout(layout);
    setFixedSize(300, 400);
    setWindowTitle("Calculator");
}

Calculator::~Calculator()
{
}

void Calculator::NumPressed()
{
    QPushButton *button = qobject_cast<QPushButton*>(sender());
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
    QPushButton *button = qobject_cast<QPushButton*>(sender());
    firstNum = display->text().toDouble();
    operation = button->text();
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
}

void Calculator::ClearButton()
{
    display->setText("0");
    firstNum = 0;
    userIsTypingSecondNumber = false;
    operation = "";
}