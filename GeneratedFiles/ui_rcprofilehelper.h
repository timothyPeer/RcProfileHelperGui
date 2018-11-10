/********************************************************************************
** Form generated from reading UI file 'rcprofilehelper.ui'
**
** Created by: Qt User Interface Compiler version 5.11.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RCPROFILEHELPER_H
#define UI_RCPROFILEHELPER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_RcProfileHelperClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *RcProfileHelperClass)
    {
        if (RcProfileHelperClass->objectName().isEmpty())
            RcProfileHelperClass->setObjectName(QStringLiteral("RcProfileHelperClass"));
        RcProfileHelperClass->resize(600, 400);
        menuBar = new QMenuBar(RcProfileHelperClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        RcProfileHelperClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(RcProfileHelperClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        RcProfileHelperClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(RcProfileHelperClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        RcProfileHelperClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(RcProfileHelperClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        RcProfileHelperClass->setStatusBar(statusBar);

        retranslateUi(RcProfileHelperClass);

        QMetaObject::connectSlotsByName(RcProfileHelperClass);
    } // setupUi

    void retranslateUi(QMainWindow *RcProfileHelperClass)
    {
        RcProfileHelperClass->setWindowTitle(QApplication::translate("RcProfileHelperClass", "RcProfileHelper", nullptr));
    } // retranslateUi

};

namespace Ui {
    class RcProfileHelperClass: public Ui_RcProfileHelperClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RCPROFILEHELPER_H
