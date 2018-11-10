#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_rcprofilehelper.h"

class RcProfileHelper : public QMainWindow
{
	Q_OBJECT

public:
	RcProfileHelper(QWidget *parent = Q_NULLPTR);

private:
	Ui::RcProfileHelperClass ui;
};
