#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <QMainWindow>
#include <QGridLayout>
#include <QPushButton>
#include <QLineEdit>
#include <QPropertyAnimation>
#include <QStack>
#include <QtMath>
#include <QListWidget>

class AnimatedButton : public QPushButton
{
    Q_OBJECT
public:
    AnimatedButton(const QString &text, QWidget *parent = nullptr);

protected:
    void mousePressEvent(QMouseEvent *e) override;
    void mouseReleaseEvent(QMouseEvent *e) override;

private:
    QPropertyAnimation *animation;
};

class Calculator : public QMainWindow
{
    Q_OBJECT

public:
    Calculator(QWidget *parent = nullptr);
    ~Calculator();

private slots:
    void NumPressed();
    void MathButtonPressed();
    void EqualButtonPressed();
    void ClearButton();
    void ScientificButtonPressed();
    void MemoryButtonPressed();
    void ToggleScientificMode();
    void BackspacePressed();
    void ParenthesesPressed();

private:
    void setupUI();
    void setupStyle();
    void createBasicButtons();
    void createScientificButtons();
    void createMemoryButtons();
    void addToHistory(const QString &expression, const QString &result);
    double evaluateScientificFunction(const QString &func, double value);
    
    QWidget *centralWidget;
    QGridLayout *mainLayout;
    QLineEdit *display;
    QListWidget *historyWidget;
    
    double firstNum;
    QString operation;
    bool userIsTypingSecondNumber;
    bool isScientificMode;
    
    QStack<double> memory;
    QList<QString> history;
    int parenthesesCount;
    
    QList<AnimatedButton*> scientificButtons;
};

#endif