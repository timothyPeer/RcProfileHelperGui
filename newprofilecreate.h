#ifndef newprofilecreate_h__
#define newprofilecreate_h__

#pragma once

#include <QWidget>
//#include "ui_createnewprofile.h"
#include "nvprofilesclass.h"

class newProfileCreate : public QWidget
{
	Q_OBJECT



public:
	newProfileCreate(QWidget *parent = Q_NULLPTR);
	~newProfileCreate();
	void setEditEnabled();
	void on_pushButton_profileCheck_clicked();
	void on_pushButton_Generate_clicked();
	void on_pushButton_Commit_clicked();
	void on_pushButton_editProfile_clicked();
	void on_pushButton_deleteProfile_clicked();
	void on_pushButton_copyProfile_clicked();
	void on_comboBox_loggingLevel_currentTextChanged(const QString &arg1);
	void on_comboBox_dropTarget_currentTextChanged(const QString &arg1);
	void on_lineEdit_textChanged(const QString &arg1);
	void on_lineEdit_copyProfileName_textChanged(const QString &arg1);
	void on_lineEdit_LogFileName_textChanged(const QString &arg1);
	void on_pushButton_LogFilebrowse_clicked();
	void on_comboBox_dropTarget_currentIndexChanged(int index);
	void on_textEdit_description_textChanged();
	void on_spinBox_ExecutionThreads_valueChanged(int arg1);
	void on_spinBox_CommitThrottle_valueChanged(int arg1);
	void on_checkBox_ProfileTransactionLogging_stateChanged(int arg1);
	void on_checkBox_ProfileTraceEnabled_stateChanged(int arg1);
	void on_checkBox_AutoCommitEnabled_stateChanged(int arg1);
	void on_checkBox_ProfileEnabled_stateChanged(int arg1);
	void on_lineEdit_selectionChanged();

	void on_buttonBox_accepted();

	void on_buttonBox_rejected();

private:

	void initialize(nvProfilesClass * profClass);

	//Ui::newProfileCreate * ui;
	QString profileName;
	QString profileDescription;
	int profileCommitThrottle;
	int profileExecutionThreads;
	bool profileEnabled;
	bool profileTrace;
	bool profileAutocommit;
	bool profileLoggingEnabled;
	void  updateGui(QString strMessage);
	int profileTrgDropTarget;
	int profileLoggingLevel;
	QString strLogFileName;
	bool  bIsProfileCopy;
	bool  bIsProfileEdit;

};
#endif // newprofilecreate_h__
