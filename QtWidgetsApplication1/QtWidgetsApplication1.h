#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_QtWidgetsApplication1.h"

class QtWidgetsApplication1 : public QMainWindow
{
    Q_OBJECT

public:
    QtWidgetsApplication1(QWidget *parent = nullptr);
    ~QtWidgetsApplication1();

private slots:
    void on_actionProject_3_triggered(); // Declare the slot to handle the button click

private:
    Ui::QtWidgetsApplication1Class ui;
};