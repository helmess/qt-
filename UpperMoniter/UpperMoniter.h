#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_UpperMoniter.h"

class UpperMoniter : public QMainWindow
{
    Q_OBJECT

public:
    UpperMoniter(QWidget *parent = Q_NULLPTR);

private:
    Ui::UpperMoniterClass ui;
};
