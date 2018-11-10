/********************************************************************************
** Form generated from reading UI file 'dlgnewprofilecreate.ui'
**
** Created by: Qt User Interface Compiler version 5.11.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DLGNEWPROFILECREATE_H
#define UI_DLGNEWPROFILECREATE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_dlgNewProfileCreate
{
public:
    QHBoxLayout *horizontalLayout_16;
    QVBoxLayout *verticalLayout_12;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *lineEdit_ProfileName;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_11;
    QLineEdit *lineEdit_copyProfileName;
    QHBoxLayout *horizontalLayout_5;
    QTabWidget *tabWidget;
    QWidget *tab_sourceDSN;
    QHBoxLayout *horizontalLayout_2;
    QTextEdit *textEdit_sourceDSN;
    QWidget *tab_targetDSN;
    QHBoxLayout *horizontalLayout_3;
    QTextEdit *textEdit_targetDSN;
    QWidget *tab_Properties;
    QVBoxLayout *verticalLayout_6;
    QGroupBox *groupBox_4;
    QVBoxLayout *verticalLayout_7;
    QHBoxLayout *horizontalLayout_13;
    QLabel *label_8;
    QTextEdit *textEdit_description;
    QHBoxLayout *horizontalLayout_15;
    QLabel *label_10;
    QSpinBox *spinBox_networkPacketSize;
    QHBoxLayout *horizontalLayout_14;
    QLabel *label_9;
    QSpinBox *spinBox_commitThrottle;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_2;
    QComboBox *comboBox_dropTarget;
    QHBoxLayout *horizontalLayout_8;
    QLabel *label_3;
    QComboBox *comboBox_loggingLevel;
    QHBoxLayout *horizontalLayout_9;
    QLabel *label_7;
    QCheckBox *checkBox_profileEnabled;
    QHBoxLayout *horizontalLayout_10;
    QLabel *label_6;
    QCheckBox *checkBox_autoCommitEnabled;
    QHBoxLayout *horizontalLayout_11;
    QLabel *label_5;
    QSpinBox *spinBox_ExecutionThreads;
    QHBoxLayout *horizontalLayout_12;
    QLabel *label_4;
    QLineEdit *lineEdit_logFileName;
    QSpacerItem *verticalSpacer_2;
    QWidget *tab_tables;
    QHBoxLayout *horizontalLayout_4;
    QListWidget *listWidget_tables;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout;
    QPushButton *pushButton_check;
    QPushButton *pushButton_generate;
    QPushButton *pushButton_commit;
    QPushButton *pushButton_edit;
    QPushButton *pushButton_delete;
    QPushButton *pushButton_copy;
    QSpacerItem *verticalSpacer;
    QVBoxLayout *verticalLayout_5;
    QGroupBox *groupBox_3;
    QVBoxLayout *verticalLayout_4;
    QDialogButtonBox *buttonBox;
    QGroupBox *groupBox_2;
    QVBoxLayout *verticalLayout_2;
    QTabWidget *tabWidget_2;
    QWidget *table_fetch;
    QVBoxLayout *verticalLayout_8;
    QListWidget *listWidget_fetchStatements;
    QWidget *tab_insert;
    QVBoxLayout *verticalLayout_9;
    QListWidget *listWidget_insertStatements;
    QWidget *tab_update;
    QVBoxLayout *verticalLayout_10;
    QListWidget *listWidget_updateStatements;
    QWidget *tab_createstatements;
    QVBoxLayout *verticalLayout_11;
    QListWidget *listWidget_createStatements;

    void setupUi(QDialog *dlgNewProfileCreate)
    {
        if (dlgNewProfileCreate->objectName().isEmpty())
            dlgNewProfileCreate->setObjectName(QStringLiteral("dlgNewProfileCreate"));
        dlgNewProfileCreate->resize(1070, 834);
        horizontalLayout_16 = new QHBoxLayout(dlgNewProfileCreate);
        horizontalLayout_16->setObjectName(QStringLiteral("horizontalLayout_16"));
        verticalLayout_12 = new QVBoxLayout();
        verticalLayout_12->setObjectName(QStringLiteral("verticalLayout_12"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(dlgNewProfileCreate);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout->addWidget(label);

        lineEdit_ProfileName = new QLineEdit(dlgNewProfileCreate);
        lineEdit_ProfileName->setObjectName(QStringLiteral("lineEdit_ProfileName"));

        horizontalLayout->addWidget(lineEdit_ProfileName);


        verticalLayout_3->addLayout(horizontalLayout);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        label_11 = new QLabel(dlgNewProfileCreate);
        label_11->setObjectName(QStringLiteral("label_11"));

        horizontalLayout_6->addWidget(label_11);

        lineEdit_copyProfileName = new QLineEdit(dlgNewProfileCreate);
        lineEdit_copyProfileName->setObjectName(QStringLiteral("lineEdit_copyProfileName"));

        horizontalLayout_6->addWidget(lineEdit_copyProfileName);


        verticalLayout_3->addLayout(horizontalLayout_6);


        verticalLayout_12->addLayout(verticalLayout_3);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        horizontalLayout_5->setSizeConstraint(QLayout::SetDefaultConstraint);
        tabWidget = new QTabWidget(dlgNewProfileCreate);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(tabWidget->sizePolicy().hasHeightForWidth());
        tabWidget->setSizePolicy(sizePolicy);
        tab_sourceDSN = new QWidget();
        tab_sourceDSN->setObjectName(QStringLiteral("tab_sourceDSN"));
        horizontalLayout_2 = new QHBoxLayout(tab_sourceDSN);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        textEdit_sourceDSN = new QTextEdit(tab_sourceDSN);
        textEdit_sourceDSN->setObjectName(QStringLiteral("textEdit_sourceDSN"));

        horizontalLayout_2->addWidget(textEdit_sourceDSN);

        tabWidget->addTab(tab_sourceDSN, QString());
        tab_targetDSN = new QWidget();
        tab_targetDSN->setObjectName(QStringLiteral("tab_targetDSN"));
        horizontalLayout_3 = new QHBoxLayout(tab_targetDSN);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        textEdit_targetDSN = new QTextEdit(tab_targetDSN);
        textEdit_targetDSN->setObjectName(QStringLiteral("textEdit_targetDSN"));

        horizontalLayout_3->addWidget(textEdit_targetDSN);

        tabWidget->addTab(tab_targetDSN, QString());
        tab_Properties = new QWidget();
        tab_Properties->setObjectName(QStringLiteral("tab_Properties"));
        verticalLayout_6 = new QVBoxLayout(tab_Properties);
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        groupBox_4 = new QGroupBox(tab_Properties);
        groupBox_4->setObjectName(QStringLiteral("groupBox_4"));
        verticalLayout_7 = new QVBoxLayout(groupBox_4);
        verticalLayout_7->setObjectName(QStringLiteral("verticalLayout_7"));
        horizontalLayout_13 = new QHBoxLayout();
        horizontalLayout_13->setObjectName(QStringLiteral("horizontalLayout_13"));
        label_8 = new QLabel(groupBox_4);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);

        horizontalLayout_13->addWidget(label_8);

        textEdit_description = new QTextEdit(groupBox_4);
        textEdit_description->setObjectName(QStringLiteral("textEdit_description"));

        horizontalLayout_13->addWidget(textEdit_description);


        verticalLayout_7->addLayout(horizontalLayout_13);

        horizontalLayout_15 = new QHBoxLayout();
        horizontalLayout_15->setObjectName(QStringLiteral("horizontalLayout_15"));
        label_10 = new QLabel(groupBox_4);
        label_10->setObjectName(QStringLiteral("label_10"));

        horizontalLayout_15->addWidget(label_10);

        spinBox_networkPacketSize = new QSpinBox(groupBox_4);
        spinBox_networkPacketSize->setObjectName(QStringLiteral("spinBox_networkPacketSize"));

        horizontalLayout_15->addWidget(spinBox_networkPacketSize);


        verticalLayout_7->addLayout(horizontalLayout_15);

        horizontalLayout_14 = new QHBoxLayout();
        horizontalLayout_14->setObjectName(QStringLiteral("horizontalLayout_14"));
        label_9 = new QLabel(groupBox_4);
        label_9->setObjectName(QStringLiteral("label_9"));

        horizontalLayout_14->addWidget(label_9);

        spinBox_commitThrottle = new QSpinBox(groupBox_4);
        spinBox_commitThrottle->setObjectName(QStringLiteral("spinBox_commitThrottle"));

        horizontalLayout_14->addWidget(spinBox_commitThrottle);


        verticalLayout_7->addLayout(horizontalLayout_14);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        label_2 = new QLabel(groupBox_4);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout_7->addWidget(label_2);

        comboBox_dropTarget = new QComboBox(groupBox_4);
        comboBox_dropTarget->addItem(QString());
        comboBox_dropTarget->addItem(QString());
        comboBox_dropTarget->addItem(QString());
        comboBox_dropTarget->setObjectName(QStringLiteral("comboBox_dropTarget"));

        horizontalLayout_7->addWidget(comboBox_dropTarget);


        verticalLayout_7->addLayout(horizontalLayout_7);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        label_3 = new QLabel(groupBox_4);
        label_3->setObjectName(QStringLiteral("label_3"));

        horizontalLayout_8->addWidget(label_3);

        comboBox_loggingLevel = new QComboBox(groupBox_4);
        comboBox_loggingLevel->addItem(QString());
        comboBox_loggingLevel->addItem(QString());
        comboBox_loggingLevel->addItem(QString());
        comboBox_loggingLevel->addItem(QString());
        comboBox_loggingLevel->setObjectName(QStringLiteral("comboBox_loggingLevel"));

        horizontalLayout_8->addWidget(comboBox_loggingLevel);


        verticalLayout_7->addLayout(horizontalLayout_8);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName(QStringLiteral("horizontalLayout_9"));
        label_7 = new QLabel(groupBox_4);
        label_7->setObjectName(QStringLiteral("label_7"));

        horizontalLayout_9->addWidget(label_7);

        checkBox_profileEnabled = new QCheckBox(groupBox_4);
        checkBox_profileEnabled->setObjectName(QStringLiteral("checkBox_profileEnabled"));

        horizontalLayout_9->addWidget(checkBox_profileEnabled);


        verticalLayout_7->addLayout(horizontalLayout_9);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setObjectName(QStringLiteral("horizontalLayout_10"));
        label_6 = new QLabel(groupBox_4);
        label_6->setObjectName(QStringLiteral("label_6"));

        horizontalLayout_10->addWidget(label_6);

        checkBox_autoCommitEnabled = new QCheckBox(groupBox_4);
        checkBox_autoCommitEnabled->setObjectName(QStringLiteral("checkBox_autoCommitEnabled"));

        horizontalLayout_10->addWidget(checkBox_autoCommitEnabled);


        verticalLayout_7->addLayout(horizontalLayout_10);

        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setObjectName(QStringLiteral("horizontalLayout_11"));
        label_5 = new QLabel(groupBox_4);
        label_5->setObjectName(QStringLiteral("label_5"));

        horizontalLayout_11->addWidget(label_5);

        spinBox_ExecutionThreads = new QSpinBox(groupBox_4);
        spinBox_ExecutionThreads->setObjectName(QStringLiteral("spinBox_ExecutionThreads"));

        horizontalLayout_11->addWidget(spinBox_ExecutionThreads);


        verticalLayout_7->addLayout(horizontalLayout_11);

        horizontalLayout_12 = new QHBoxLayout();
        horizontalLayout_12->setObjectName(QStringLiteral("horizontalLayout_12"));
        label_4 = new QLabel(groupBox_4);
        label_4->setObjectName(QStringLiteral("label_4"));

        horizontalLayout_12->addWidget(label_4);

        lineEdit_logFileName = new QLineEdit(groupBox_4);
        lineEdit_logFileName->setObjectName(QStringLiteral("lineEdit_logFileName"));

        horizontalLayout_12->addWidget(lineEdit_logFileName);


        verticalLayout_7->addLayout(horizontalLayout_12);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_7->addItem(verticalSpacer_2);


        verticalLayout_6->addWidget(groupBox_4);

        tabWidget->addTab(tab_Properties, QString());
        tab_tables = new QWidget();
        tab_tables->setObjectName(QStringLiteral("tab_tables"));
        horizontalLayout_4 = new QHBoxLayout(tab_tables);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        listWidget_tables = new QListWidget(tab_tables);
        listWidget_tables->setObjectName(QStringLiteral("listWidget_tables"));

        horizontalLayout_4->addWidget(listWidget_tables);

        tabWidget->addTab(tab_tables, QString());

        horizontalLayout_5->addWidget(tabWidget);

        groupBox = new QGroupBox(dlgNewProfileCreate);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        verticalLayout = new QVBoxLayout(groupBox);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        pushButton_check = new QPushButton(groupBox);
        pushButton_check->setObjectName(QStringLiteral("pushButton_check"));

        verticalLayout->addWidget(pushButton_check);

        pushButton_generate = new QPushButton(groupBox);
        pushButton_generate->setObjectName(QStringLiteral("pushButton_generate"));

        verticalLayout->addWidget(pushButton_generate);

        pushButton_commit = new QPushButton(groupBox);
        pushButton_commit->setObjectName(QStringLiteral("pushButton_commit"));

        verticalLayout->addWidget(pushButton_commit);

        pushButton_edit = new QPushButton(groupBox);
        pushButton_edit->setObjectName(QStringLiteral("pushButton_edit"));

        verticalLayout->addWidget(pushButton_edit);

        pushButton_delete = new QPushButton(groupBox);
        pushButton_delete->setObjectName(QStringLiteral("pushButton_delete"));

        verticalLayout->addWidget(pushButton_delete);

        pushButton_copy = new QPushButton(groupBox);
        pushButton_copy->setObjectName(QStringLiteral("pushButton_copy"));

        verticalLayout->addWidget(pushButton_copy);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);


        horizontalLayout_5->addWidget(groupBox);


        verticalLayout_12->addLayout(horizontalLayout_5);


        horizontalLayout_16->addLayout(verticalLayout_12);

        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        groupBox_3 = new QGroupBox(dlgNewProfileCreate);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        groupBox_3->setLayoutDirection(Qt::RightToLeft);
        verticalLayout_4 = new QVBoxLayout(groupBox_3);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        buttonBox = new QDialogButtonBox(groupBox_3);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(buttonBox->sizePolicy().hasHeightForWidth());
        buttonBox->setSizePolicy(sizePolicy1);
        buttonBox->setOrientation(Qt::Vertical);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout_4->addWidget(buttonBox);


        verticalLayout_5->addWidget(groupBox_3);

        groupBox_2 = new QGroupBox(dlgNewProfileCreate);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(groupBox_2->sizePolicy().hasHeightForWidth());
        groupBox_2->setSizePolicy(sizePolicy2);
        verticalLayout_2 = new QVBoxLayout(groupBox_2);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        tabWidget_2 = new QTabWidget(groupBox_2);
        tabWidget_2->setObjectName(QStringLiteral("tabWidget_2"));
        table_fetch = new QWidget();
        table_fetch->setObjectName(QStringLiteral("table_fetch"));
        verticalLayout_8 = new QVBoxLayout(table_fetch);
        verticalLayout_8->setObjectName(QStringLiteral("verticalLayout_8"));
        listWidget_fetchStatements = new QListWidget(table_fetch);
        listWidget_fetchStatements->setObjectName(QStringLiteral("listWidget_fetchStatements"));

        verticalLayout_8->addWidget(listWidget_fetchStatements);

        tabWidget_2->addTab(table_fetch, QString());
        tab_insert = new QWidget();
        tab_insert->setObjectName(QStringLiteral("tab_insert"));
        verticalLayout_9 = new QVBoxLayout(tab_insert);
        verticalLayout_9->setObjectName(QStringLiteral("verticalLayout_9"));
        listWidget_insertStatements = new QListWidget(tab_insert);
        listWidget_insertStatements->setObjectName(QStringLiteral("listWidget_insertStatements"));

        verticalLayout_9->addWidget(listWidget_insertStatements);

        tabWidget_2->addTab(tab_insert, QString());
        tab_update = new QWidget();
        tab_update->setObjectName(QStringLiteral("tab_update"));
        verticalLayout_10 = new QVBoxLayout(tab_update);
        verticalLayout_10->setObjectName(QStringLiteral("verticalLayout_10"));
        listWidget_updateStatements = new QListWidget(tab_update);
        listWidget_updateStatements->setObjectName(QStringLiteral("listWidget_updateStatements"));

        verticalLayout_10->addWidget(listWidget_updateStatements);

        tabWidget_2->addTab(tab_update, QString());
        tab_createstatements = new QWidget();
        tab_createstatements->setObjectName(QStringLiteral("tab_createstatements"));
        verticalLayout_11 = new QVBoxLayout(tab_createstatements);
        verticalLayout_11->setObjectName(QStringLiteral("verticalLayout_11"));
        listWidget_createStatements = new QListWidget(tab_createstatements);
        listWidget_createStatements->setObjectName(QStringLiteral("listWidget_createStatements"));

        verticalLayout_11->addWidget(listWidget_createStatements);

        tabWidget_2->addTab(tab_createstatements, QString());

        verticalLayout_2->addWidget(tabWidget_2);


        verticalLayout_5->addWidget(groupBox_2);


        horizontalLayout_16->addLayout(verticalLayout_5);

#ifndef QT_NO_SHORTCUT
        label->setBuddy(lineEdit_ProfileName);
        label_2->setBuddy(comboBox_dropTarget);
#endif // QT_NO_SHORTCUT

        retranslateUi(dlgNewProfileCreate);
        QObject::connect(buttonBox, SIGNAL(accepted()), dlgNewProfileCreate, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), dlgNewProfileCreate, SLOT(reject()));

        tabWidget->setCurrentIndex(2);
        tabWidget_2->setCurrentIndex(3);


        QMetaObject::connectSlotsByName(dlgNewProfileCreate);
    } // setupUi

    void retranslateUi(QDialog *dlgNewProfileCreate)
    {
        dlgNewProfileCreate->setWindowTitle(QApplication::translate("dlgNewProfileCreate", "Dialog", nullptr));
        label->setText(QApplication::translate("dlgNewProfileCreate", "Profile Name:", nullptr));
        label_11->setText(QApplication::translate("dlgNewProfileCreate", "Copy Profile Name:", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_sourceDSN), QApplication::translate("dlgNewProfileCreate", "Source", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_targetDSN), QApplication::translate("dlgNewProfileCreate", "Target", nullptr));
        groupBox_4->setTitle(QApplication::translate("dlgNewProfileCreate", "Profile Properties", nullptr));
        label_8->setText(QApplication::translate("dlgNewProfileCreate", "Description:", nullptr));
        label_10->setText(QApplication::translate("dlgNewProfileCreate", "Network Packet Size:", nullptr));
        label_9->setText(QApplication::translate("dlgNewProfileCreate", "Commit Throttle:", nullptr));
        label_2->setText(QApplication::translate("dlgNewProfileCreate", "Drop Target:", nullptr));
        comboBox_dropTarget->setItemText(0, QApplication::translate("dlgNewProfileCreate", "Drop", nullptr));
        comboBox_dropTarget->setItemText(1, QApplication::translate("dlgNewProfileCreate", "Truncate", nullptr));
        comboBox_dropTarget->setItemText(2, QApplication::translate("dlgNewProfileCreate", "Delete From", nullptr));

        label_3->setText(QApplication::translate("dlgNewProfileCreate", "Logging Level:", nullptr));
        comboBox_loggingLevel->setItemText(0, QApplication::translate("dlgNewProfileCreate", "Info", nullptr));
        comboBox_loggingLevel->setItemText(1, QApplication::translate("dlgNewProfileCreate", "Debug", nullptr));
        comboBox_loggingLevel->setItemText(2, QApplication::translate("dlgNewProfileCreate", "Trace", nullptr));
        comboBox_loggingLevel->setItemText(3, QApplication::translate("dlgNewProfileCreate", "Warn", nullptr));

        label_7->setText(QApplication::translate("dlgNewProfileCreate", "Profile Enabled:", nullptr));
        checkBox_profileEnabled->setText(QApplication::translate("dlgNewProfileCreate", "Yes/No", nullptr));
        label_6->setText(QApplication::translate("dlgNewProfileCreate", "AutoCommit  Enabled:", nullptr));
        checkBox_autoCommitEnabled->setText(QApplication::translate("dlgNewProfileCreate", "Yes/No", nullptr));
        label_5->setText(QApplication::translate("dlgNewProfileCreate", "Max Execution Threads:", nullptr));
        label_4->setText(QApplication::translate("dlgNewProfileCreate", "Log File Name:", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_Properties), QApplication::translate("dlgNewProfileCreate", "Properties", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_tables), QApplication::translate("dlgNewProfileCreate", "Tables", nullptr));
        groupBox->setTitle(QApplication::translate("dlgNewProfileCreate", "Actions", nullptr));
        pushButton_check->setText(QApplication::translate("dlgNewProfileCreate", "Check", nullptr));
        pushButton_generate->setText(QApplication::translate("dlgNewProfileCreate", "Generate", nullptr));
        pushButton_commit->setText(QApplication::translate("dlgNewProfileCreate", "Commit", nullptr));
        pushButton_edit->setText(QApplication::translate("dlgNewProfileCreate", "Edit", nullptr));
        pushButton_delete->setText(QApplication::translate("dlgNewProfileCreate", "Delete", nullptr));
        pushButton_copy->setText(QApplication::translate("dlgNewProfileCreate", "Copy", nullptr));
        groupBox_3->setTitle(QString());
        groupBox_2->setTitle(QApplication::translate("dlgNewProfileCreate", "SQL Statements", nullptr));
        tabWidget_2->setTabText(tabWidget_2->indexOf(table_fetch), QApplication::translate("dlgNewProfileCreate", "Fetch", nullptr));
        tabWidget_2->setTabText(tabWidget_2->indexOf(tab_insert), QApplication::translate("dlgNewProfileCreate", "Insert", nullptr));
        tabWidget_2->setTabText(tabWidget_2->indexOf(tab_update), QApplication::translate("dlgNewProfileCreate", "Update", nullptr));
        tabWidget_2->setTabText(tabWidget_2->indexOf(tab_createstatements), QApplication::translate("dlgNewProfileCreate", "Create", nullptr));
    } // retranslateUi

};

namespace Ui {
    class dlgNewProfileCreate: public Ui_dlgNewProfileCreate {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DLGNEWPROFILECREATE_H
