#ifndef DLGNEWPROFILECREATE_H
#define DLGNEWPROFILECREATE_H

#include <QDialog>
#include "nvprofilesclass.h"

namespace Ui {
class dlgNewProfileCreate;
}

class dlgNewProfileCreate : public QDialog
{

	Q_OBJECT
public:
    explicit dlgNewProfileCreate(QWidget *parent = nullptr);
    ~dlgNewProfileCreate();

private slots:
    void on_lineEdit_profileName_textChanged(const QString &arg1);

    void on_pushButton_check_clicked();

    void on_pushButton_generate_clicked();

    void on_pushButton_commit_clicked();

    void on_pushButton_edit_clicked();

    void on_pushButton_delete_clicked();

    void on_pushButton_copy_clicked();

    void on_buttonBox_accepted();

    void on_buttonBox_rejected();

    void on_comboBox_dropTarget_currentIndexChanged(const QString &arg1);

    void on_comboBox_loggingLevel_currentIndexChanged(const QString &arg1);


    void on_spinBox_ExecutionThreads_valueChanged(int arg1);

    void on_lineEdit_LogFileName_textChanged(const QString &arg1);

    void on_lineEdit_copyProfileName_textChanged(const QString &arg1);

    void on_checkBox_autoCommitEnabled_stateChanged(int arg1);

    void on_checkBox_profileEnabled_stateChanged(int arg1);

    void on_comboBox_dropTarget_currentIndexChanged(int index);

    void on_lineEdit_copyProfileName_textEdited(const QString &arg1);

private:
    Ui::dlgNewProfileCreate *ui;
	QString profileName;
	QString profileDescription;
    QString profileNameCopied;
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
	void initialize(nvProfilesClass * profClass);
	void setEnabled();
};

#endif // DLGNEWPROFILECREATE_H
