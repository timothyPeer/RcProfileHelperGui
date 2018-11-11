/*!
*  PROGRAM:  nvNewProfileCreate
*  CREATED:  Tim Peer, eNVy Systems, Inc.
*  DATE:     NOV 2015
*  DESCRIP:  The application loads a QDialog within which, the programmer may load
*            an Oracle Rdb SQL Extract file to permit parsing and, generation of
*            C++ source code.
*            The documentation for this program is referenced <todo> here.
*
*  Considerations: 
*     Most class private properties are referenced via the eNVy Repository SQL Server database.  The NVLibQ class library
*     references this library to maintain / configure the run-time for a data replication task. 
*/



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
	QString profileName;				/**<Profile Name */
	QString profileDescription;		/**< The description of the replication profile. */
    QString profileNameCopied;		/**< Should a copy be cloned to a new replication profile, this is the name of the cloned profile. */
	int profileCommitThrottle;	/**< The commit throttle that should be used when inserting records.  Every CommitThrottle count of insert operations are followed by a Commit. */
	int profileExecutionThreads; /**< The number of threads to be used during replication. */
	bool profileEnabled;		/**< Retain the profile status - enabled (ok to execute) or disable (do not execute).  */
	bool profileTrace; /**< Enable Trace of the transaction.  */
	bool profileAutocommit; /**< perform an ODBC (SQL_COMMIT) auto commit after each insert.  */
	bool profileLoggingEnabled; /**< Enable Logging for the replication operation.  */
	void  updateGui(QString strMessage);
	int profileTrgDropTarget; /**< DropTarget configures the SQL DML to execute on an existing table prior to starting a replication. (Truncate Table/Drop Table/Delete From Table)  */
	int profileLoggingLevel; /**< Default Logging Level */
	QString strLogFileName; /**< Log file is logging is used. The fully qualified log file name.  */
	bool  bIsProfileCopy;	/**< Application Property - copy/clone an existing profile. */
	bool  bIsProfileEdit;	/**< Edit an existing profile.  */
	void initialize(nvProfilesClass * profClass);
	void setEnabled();
};

#endif // DLGNEWPROFILECREATE_H
