#include "QtWidgetsApplication2.h"
#include <QMessageBox>
using namespace std;


QtWidgetsApplication2::QtWidgetsApplication2(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
    connect(ui.substractionButton, SIGNAL(clicked()), this,
        SLOT(substractionButton_clicked()));
}

QtWidgetsApplication2::~QtWidgetsApplication2()
{}

void QtWidgetsApplication2::substractionButton_clicked()
{
    QMessageBox msgBox;
    msgBox.setText("Wszystko ok");
    msgBox.setWindowTitle("Odejmowanie jest ok ");
    msgBox.exec();
}

void QtWidgetsApplication2::addButton_clicked()
{
    auto numberOne = ui.numberOneTextEdit->toPlainText().toStdString();
    auto numberTwo = ui.numberTwoTextEdit->toPlainText().toStdString();
    double convertedNumberOne;
    double convertedNumberTwo;
    bool conversionCorrect = true;
    try
    {
        convertedNumberOne = stod(numberOne);
    }
    catch (invalid_argument&)
    {
        QMessageBox msgBox;
        msgBox.setText("Blad konwersji pierwszej liczby");
        msgBox.setWindowTitle("Blad konwersji pierwszej liczby");
        msgBox.exec();
        conversionCorrect = false;
    }
    try
    {
        convertedNumberTwo = stod(numberTwo);
    }
    catch (invalid_argument&)
    {
        QMessageBox msgBox;
        msgBox.setText("Blad konwersji drugiej liczby");
        msgBox.setWindowTitle("Blad konwersji drugiej liczby");
        msgBox.exec();
        conversionCorrect = false;
    }
    if (conversionCorrect)
    {
        auto result = convertedNumberOne + convertedNumberTwo;
        ui.resultLabel->setText(QString::number(result));
    }
}
