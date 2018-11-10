#include "newprofilecreate.h"
#include "connectionstringbuilder.h"
#include "ui_newprofilecreate.h"
#include "qnvtables.h"
#include <QMessageBox>
#include <QScopedPointer>
#include <QListWidgetItem>
#include <QStringList>
#include <QFileDialog>
#include "qnvprofiles.h"
#include "modelnvprofiles.h"
#include "dbcheckobj.h"
#include "nvTableOracleRdb.h"
#include "modelnvtables.h"

newProfileCreate::newProfileCreate(QWidget *parent)
	: QWidget(parent)
{
	ui->setupUi(this);
	connectionStringBuilder buildX; //(new connectionStringBuilder);

	QString tmp1 = buildX.getConnectionStringSource();
	ui->textEdit_Source->setText(tmp1);
	ui->textEdit_Target->setText(buildX.getConnectionStringTarget());
	ui->lineEdit->setText("mandb300");
	ui->comboBox_dropTarget->addItem("Drop");
	ui->comboBox_dropTarget->addItem("Delete From");
	ui->comboBox_dropTarget->addItem("Truncate");
	ui->comboBox_loggingLevel->addItem("none");
	ui->comboBox_loggingLevel->addItem("TraceLevel");
	ui->comboBox_loggingLevel->addItem("DebugLevel");
	ui->comboBox_loggingLevel->addItem("InfoLevel");
	ui->comboBox_loggingLevel->addItem("WarnLevel");
	ui->comboBox_loggingLevel->addItem("ErrorLevel");
	ui->comboBox_loggingLevel->addItem("FatalLevel");
	ui->comboBox_loggingLevel->setCurrentIndex(0);
	ui->comboBox_dropTarget->setCurrentIndex(0);
}

newProfileCreate::~newProfileCreate()
{
	delete ui;
}

void newProfileCreate::initialize(nvProfilesClass * profClass)
{
	if (profClass)
	{
		QString title("Edit an Existing Profile's Properties");
		//setWindowTitle(title);
		system("title WhateverYouWantToNameIt");
		ui->lineEdit_LogFileName->setText(profClass->getProfileLogFileName());
		ui->lineEdit_ProfileName->setText(profClass->getProfileName());
		ui->textEdit_description->setPlainText(profClass->getProfileDescription());
		ui->comboBox_loggingLevel->setCurrentIndex(profClass->getProfileTransactionLogLevel());
		ui->checkBox_ProfileEnabled->setChecked((bool)profClass->getProfileEnabled());
		ui->checkBox_AutoCommitEnabled->setChecked((bool)profClass->getProfileAutoCommitEnabled());
		ui->checkBox_ProfileTraceEnabled->setCheckable((bool)profClass->getProfileTraceEnabled());
		ui->checkBox_ProfileTransactionLogging->setCheckable((bool)profClass->getTransactionLoggingEnabled());
		ui->spinBox_CommitThrottle->setValue(profClass->getProfileCommitThrottle());
		ui->spinBox_ExecutionThreads->setValue(profClass->getProfileExecutionThreads());
		ui->comboBox_loggingLevel->setCurrentIndex(profClass->getProfileTransactionLogLevel());
		ui->comboBox_dropTarget->setCurrentIndex(profClass->getProfileTrgDropOption());
		ui->pushButton_profileCheck->setEnabled(false);
		ui->pushButton_Generate->setEnabled(false);
		ui->pushButton_Commit->setEnabled(false);
		//ui->spinBox_NetworkPacketSize->setEnabled(profClass->getNetworkPacketSize());
	}
}

void newProfileCreate::updateGui(QString strMessage)
{
	QString msg;
	msg.append(QString("%1 : %2").arg(QDateTime::currentDateTime().toString()).arg(strMessage));
	ui->textEdit_messages->append(msg);
	QApplication::processEvents();
}

void newProfileCreate::setEditEnabled()
{
	ui->pushButton_editProfile->setEnabled(true);

	ui->pushButton_deleteProfile->setEnabled(true);
	ui->pushButton_copyProfile->setEnabled(true);

	bIsProfileEdit = true;
}

void newProfileCreate::on_pushButton_profileCheck_clicked()
{
	this->setCursor(Qt::WaitCursor);
	updateGui(QString("Checking Validity - %1").arg(profileName));
	bool bIsValid = true;
	if (ui->lineEdit->text().isEmpty())
	{
		// ProfileName is not set in GUI

		//ui->textEdit_messages->append(QString("The profile name is not set."));
		updateGui(QString("The profile name is not set."));
		int ret = QMessageBox::warning(this, tr("MyRcHelper"),
			tr("The profile name is not set.\n"
				"Please set the profile name."),
			QMessageBox::Ok,
			QMessageBox::Ok);
		ui->lineEdit->setFocus();
		ui->pushButton_Commit->setEnabled(false);
		ui->pushButton_profileCheck->setEnabled(false);
		return;
		// does the profile exist.
		QScopedPointer<qNvProfiles> ptrProf(new qNvProfiles(this));
		QString profileName(ui->lineEdit->text().trimmed());
		ptrProf->initialize(profileName);
		if (ptrProf->exists()) // the profile exists
		{
			updateGui(QString("Profile Exists - %1").arg(profileName));
			//ui->textEdit_messages->append(QString("Profile Exists - %1").arg(profileName));
			QMessageBox::StandardButton ret = QMessageBox::question(this, tr("MyRcHelper"),
				tr("The profile name exists.\n"
					"Do you want to Proceed."),
				QMessageBox::No | QMessageBox::Yes,
				QMessageBox::Yes);
			updateGui("Profile name exists in the eNVy database.");
			if (ret == QMessageBox::No)
			{

				this->setCursor(Qt::ArrowCursor);
				updateGui("Profile name exists in the eNVy database- not overridden");
				return;
			}
			else
			{
				updateGui("Profile name exists in the eNVy database- preparing to delete");
				auto * pClass = new nvProfilesClass(this);
				pClass->setProfileName(profileName);
				auto * model = new modelNvProfiles();
				model->deleteRow(pClass);
				delete pClass;
				delete model;
				updateGui(QString("Profile Deleted - %1").arg(profileName));
			}
			ui->pushButton_profileCheck->setEnabled(true);
			// check the connection strings to ensure they are well formed.

			//ui->textEdit_messages->append();
			updateGui(QString("Checking Connection DSNs - %1").arg(profileName));
			QScopedPointer<dbCheckObj> ptrObj(new dbCheckObj(this));
			ptrObj->initialize(ui->textEdit_Target->toPlainText());
			if (!ptrObj->isValidConnection())
			{
				bIsValid = false;
				//ui->textEdit_messages->append (QDateTime::currentDateTime().toString () + " : Source DSN Malformed.");
				updateGui(QDateTime::currentDateTime().toString() + " : Source DSN Malformed.");
			}
			ptrObj->initialize(ui->textEdit_Source->toPlainText());
			if (!ptrObj->isValidConnection())
			{
				//        ui->textEdit_messages->append (QDateTime::currentDateTime().toString () + " : Target DSN Malformed.");
				updateGui(QDateTime::currentDateTime().toString() + " : Target DSN Malformed.");
				bIsValid = false;
			}
			if (!bIsValid)
			{

				int ret = QMessageBox::warning(this, tr("MyRcHelper"),
					tr("A DSN connection string is malformed.\n"
						"Please correct and rerun the DSN check"),
					QMessageBox::Ok,
					QMessageBox::Ok);
				ui->pushButton_Commit->setEnabled(false);

				return;
			}
			//QStringList lst = ptrObj->sqlTables();

			updateGui(QString("Retrieving Source DSN Table List - %1").arg(profileName));
			ui->listWidget->addItems(ptrObj->sqlTables());
			if (ui->listWidget->count() == 0)
			{
				//ui->textEdit_messages->append (QDateTime::currentDateTime().toString () + " : Error Occurred when loading tables.");
				updateGui(QString(" : Error Occurred when loading tables."));
				return;
			}
			updateGui(QString("Tables Retrieved - %1").arg(profileName));
			ui->tabTables->setFocus();
			ui->pushButton_profileCheck->setEnabled(true);

			connectionStringBuilder builder;

			QScopedPointer<qNvTables> ptr(new qNvTables(this));

			ui->listWidget->sortItems(Qt::AscendingOrder);

			this->setCursor(Qt::ArrowCursor);

			ui->lineEdit_LogFileName->setText(QString("RcLog-%1.txt").arg(profileName.trimmed()));
			QApplication::processEvents();
			ui->pushButton_profileCheck->setEnabled(false);
		}
	}
}

void newProfileCreate::on_pushButton_Generate_clicked()
{
	ui->lineEdit->text().toUpper();
	updateGui(QString("Generating SQL for Profile - %1").arg(profileName));
	this->setCursor(Qt::WaitCursor);
	QApplication::processEvents();
	ui->listWidget_createStatements->clear();
	ui->listWidget_insertStatements->clear();
	ui->listWidget_SqlStatements->clear();
	ui->listWidget_updateStatements->clear();

	const QString& dsn = ui->textEdit_Source->toPlainText();
	for (int x = 0; x < ui->listWidget->count(); x++)
	{
		QListWidgetItem *item = ui->listWidget->item(x);

		QString tableName = item->text();
		{
			if (x % 5 == 0) QApplication::processEvents();

			updateGui(QString("Processed - %1").arg(tableName));
			QScopedPointer<nvTableOracleRdb> tbl(new nvTableOracleRdb(this));
			tbl->initialize(tableName, dsn);
			//ui->list->appendPlainText( tbl->getInsertSQL());
			ui->listWidget_updateStatements->addItem(tbl->getUpdateSQL());
			ui->listWidget_createStatements->addItem(tbl->getCreateTableSQL());
			ui->listWidget_insertStatements->addItem(tbl->getInsertSQL());
			ui->listWidget_SqlStatements->addItem(tbl->getSelectSQL());
		}
	}
	this->setCursor(Qt::ArrowCursor);
	ui->pushButton_Generate->setEnabled(false);
	QApplication::processEvents();
}

void newProfileCreate::on_pushButton_Commit_clicked()
{
	this->setCursor(Qt::WaitCursor);
	ui->pushButton_Commit->setEnabled(false);
	QApplication::processEvents();
	QString copiedDescription;
	auto * pClass = new nvProfilesClass(this);
	if (bIsProfileCopy)
	{
		QString profileName = ui->lineEdit_copyProfileName->text();
		pClass->setProfileName(profileName);
		copiedDescription = QString("Copied from %1").arg(this->profileName.toUpper());
		copiedDescription.append(ui->textEdit_description->toPlainText());
	}
	else
	{
		pClass->setProfileName(this->profileName.toUpper());
	}

	pClass->setProfileDescription(copiedDescription);
	pClass->setProfileEnabled(ui->checkBox_ProfileEnabled->checkState() == Qt::Checked);
	pClass->setProfileLogFile(strLogFileName);
	pClass->setProfileTransactionLogLevel(profileLoggingLevel);
	pClass->setProfileTrgDropOption(profileTrgDropTarget);
	pClass->setExecutionThreads(ui->spinBox_ExecutionThreads->value());
	pClass->setCommitThrottle(ui->spinBox_CommitThrottle->value());
	pClass->setProfileAutoCommitEnabled(ui->checkBox_AutoCommitEnabled->checkState() == Qt::Checked);
	pClass->setProfileTargetDSNString(ui->textEdit_Target->toPlainText());
	pClass->setProfileSourceDSNString(ui->textEdit_Source->toPlainText());
	//pClass->setProfileLogFile(this->strLogFileName);
	pClass->setProfileTraceEnabled(ui->checkBox_ProfileTraceEnabled->checkState() == Qt::Checked);
	//int xxx = ui->spinBox_NetworkPacketSize->value();
	pClass->setProfileNetworkPacketSize(4096);

	QScopedPointer<modelNvProfiles> proFile(new modelNvProfiles());
	if (bIsProfileEdit) {
		proFile->setEditOnly();
		proFile->updateRow(pClass);
	}
	else proFile->InsertRow(pClass);

	QScopedPointer<modelNvTables> modTable(new modelNvTables());
	int countOfSqlStatements = ui->listWidget_SqlStatements->count();
	//if (!bIsProfileEdit)
	{
		for (int i = 0; i < countOfSqlStatements; i++)
		{
			//QListWidgetItem *item = ui->listWidget->item(i);

			QListWidgetItem *preferredInsert = ui->listWidget_insertStatements->item(i);
			QListWidgetItem *preferredUpdate = ui->listWidget_updateStatements->item(i);
			//TODO Add Create Statement to the nvProfiles table
			QListWidgetItem *preferredCreate = ui->listWidget_createStatements->item(i);
			QListWidgetItem *preferredSelect = ui->listWidget_SqlStatements->item(i);
			QStringList tableSpace = preferredSelect->text().split("from");
			QString tableName = tableSpace.value(1); // should always contain the string to the left of the FROM clause
			{
				nvTablesClass * tableClass = new nvTablesClass(this);
				tableClass->setProfileName(pClass->getProfileName());
				tableClass->setTableName(tableName);
				tableClass->setPreferredInsert(preferredInsert->text());
				tableClass->setPreferredSelect(preferredSelect->text());
				tableClass->setPreferredUpdate(preferredUpdate->text());
				tableClass->setFetchSql(preferredSelect->text());
				tableClass->setInsertSql(preferredInsert->text());
				tableClass->setPreferredInsert(preferredInsert->text());
				tableClass->setCreateTable(preferredCreate->text());
				QStringList lstCnt = preferredSelect->text().split(",");
				int cntOfList = lstCnt.count();

				tableClass->setFieldCnt(cntOfList);

				modTable->InsertRow(tableClass);
				if (i % 25 == 0)
				{
					updateGui(QString("Loaded %1 tables").arg(i));
				}
			}
		}
		updateGui(QString("Loaded %1 tables").arg(countOfSqlStatements));
	}
	delete pClass;
	ui->pushButton_Commit->setEnabled(false);
}

void newProfileCreate::on_pushButton_editProfile_clicked()
{
	this->bIsProfileEdit = true;
	on_pushButton_Commit_clicked();
	this->bIsProfileEdit = false;
}

void newProfileCreate::on_pushButton_deleteProfile_clicked()
{
	auto * pClass = new nvProfilesClass(this);
	pClass->setProfileName(profileName);
	{
		QScopedPointer<modelNvProfiles> proFile(new modelNvProfiles());
		proFile->deleteRow(pClass);
	}
}

void newProfileCreate::on_pushButton_copyProfile_clicked()
{
	on_lineEdit_copyProfileName_textChanged(ui->lineEdit_ProfileName->text());


	QMessageBox::StandardButton ret = QMessageBox::question(this, tr("MyRcHelper"),
		tr("Copy Profile.\n"
			"Do you want to Proceed."),
		QMessageBox::No | QMessageBox::Yes,
		QMessageBox::Yes);
	if (ret == QMessageBox::No)
	{

		this->setCursor(Qt::ArrowCursor);
		updateGui("Copy Not Performed.");
		return;
	}
	else
	{
		this->setCursor(Qt::WaitCursor);
		updateGui(QString("Copy Profile Started from - %1 to %2").arg(profileName).arg(ui->lineEdit_ProfileName->text()));
		profileName = ui->lineEdit_ProfileName->text();
		ui->lineEdit_copyProfileName->setText(profileName);
		ui->lineEdit->setText(profileName);
		on_pushButton_profileCheck_clicked();
		on_pushButton_Generate_clicked();
		on_pushButton_Commit_clicked();
		ui->pushButton_copyProfile->setEnabled(false);
		this->setCursor(Qt::ArrowCursor);
		//ui->pushButton_Commit->setEnabled(true);
		updateGui(QString("Copy Profile Complete from - %1 to %2").arg(profileName).arg(ui->lineEdit_ProfileName->text()));
	}
}

void newProfileCreate::on_comboBox_loggingLevel_currentTextChanged(const QString &arg1)
{

}

void newProfileCreate::on_comboBox_dropTarget_currentTextChanged(const QString &arg1)
{

}

void newProfileCreate::on_lineEdit_textChanged(const QString &arg1)
{
	arg1.toUpper();
	ui->lineEdit_ProfileName->setText(arg1);
	this->profileName = arg1;
}

void newProfileCreate::on_lineEdit_copyProfileName_textChanged(const QString &arg1)
{
	QString copiedProfileName;
	if (arg1 == profileName)
	{
		copiedProfileName = QString("Copy_%1").arg(arg1.toUpper());
	}
	else
	{
		copiedProfileName = arg1;
	}
	ui->lineEdit_ProfileName->setText(copiedProfileName);
	bIsProfileCopy = true;
	//profileName = copiedProfileName;
}

void newProfileCreate::on_lineEdit_LogFileName_textChanged(const QString &arg1)
{
	this->strLogFileName = arg1;
}

void newProfileCreate::on_pushButton_LogFilebrowse_clicked()
{
	QString fileName = QFileDialog::getSaveFileName(
		this,
		"Set the log file name",
		"c:/envy/", "Log Files (*.log);;Text files (*.txt)",
		new QString("Text files (*.txt)"));
	ui->lineEdit_LogFileName->setText(fileName);
}

void newProfileCreate::on_comboBox_dropTarget_currentIndexChanged(int index)
{
	this->profileTrgDropTarget = index;
}

void newProfileCreate::on_textEdit_description_textChanged()
{
	this->profileDescription = ui->textEdit_description->toPlainText();
}

void newProfileCreate::on_spinBox_ExecutionThreads_valueChanged(int arg1)
{
	this->profileExecutionThreads = arg1;
}

void newProfileCreate::on_spinBox_CommitThrottle_valueChanged(int arg1)
{
	this->profileCommitThrottle = arg1;
}

void newProfileCreate::on_checkBox_ProfileTransactionLogging_stateChanged(int arg1)
{
	this->profileLoggingEnabled = (bool)arg1;
}

void newProfileCreate::on_checkBox_ProfileTraceEnabled_stateChanged(int arg1)
{
	this->profileTrace = (bool)arg1;
}

void newProfileCreate::on_checkBox_AutoCommitEnabled_stateChanged(int arg1)
{
	this->profileAutocommit = (bool)arg1;
}

void newProfileCreate::on_checkBox_ProfileEnabled_stateChanged(int arg1)
{
	this->profileEnabled = (bool)arg1;
}

void newProfileCreate::on_lineEdit_selectionChanged()
{

}

void newProfileCreate::on_buttonBox_accepted()
{
	this->close();
}

void newProfileCreate::on_buttonBox_rejected()
{
	close();
}
