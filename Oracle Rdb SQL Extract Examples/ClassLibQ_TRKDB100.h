/*H**********************************************************************
* FILENAME :        CaseList_TRKDB100.h                 DESIGN REF: 
*
* DESCRIPTION :
*       This file contains implementation functions for each record that can be processed 
*       in the MANDB MANMAN R11 Rdb schema.
*
*    THIS FILE IS AN AUTO-GENERATED INCLUDE FILE
*
* PUBLIC FUNCTIONS :
*  
* Ret       Function
*====       ====================================
* void      ::initOdbcAttributes()
* void      ::initialize()
* void      ::close()
* void      ::open(const QString,const QString)
* void      ::process(int)
* void      ::run()
* int       ::rowsProcessed()
* 
* Private Functions:
* bool     ::connect()
* bool      ::prepare()
* bool      ::prepareTargetTable()
* bool      ::bindColumn()
* bool      ::bindParameter()
* bool      ::copyTable()
*
*  Setters: 
*  void     ::setCommitInterval(int)
*  void     ::setUpdateInterval(int)
*  void     ::setProfileName(const QString)
*  void     ::setRepositoryString(const QString)
*  void     ::setDropOption(enum DropOption)
*  void     ::setOdbcAttributes(const QString)
*  void     ::setReplicationOption(enum ReplicationOption)
*       
*  Set Flags: 
*   void    ::setAbortFlag()
*   void    ::setNetChange()
*  
*  signals: 
*   void    ::updateStatusFetched(QString,QString,int,int,int)
* 
*  slots: 
*    None
* NOTES :
*   
*
*       Copyright (c) Timothy Peer, eNVy Systems, Inc. 2015 -2018.  All rights reserved.
* 
* AUTHOR :    Timothy Peer        START DATE :    10 Nov 2018
*
* CHANGES :
*
* REF NO  VERSION DATE    WHO     DETAIL
*
*H*/


#pragma once
#ifndef ClassLibQ_TRKDB100_H
#define ClassLibQ_TRKDB100_H
#include <QObject>
#include <QByteArray>
#include "qsql_odbc.h"
#include "qnvstaticclass.h" 
#include "NvLib_Enumerations.h"
#include "qVtExecute.h" 
#include "nvTableOracleRdb.h" 
#include "nodbcattributesclass.h" 
#include <QtCore>
#include <QLoggingCategory>
#include <QMap>
Q_DECLARE_LOGGING_CATEGORY(category)
 
//! ODBC Define Directives
/*! The define Directives used by this library.
\def SQL_CHAR 1
\def SQL_NUMERIC 2
\def SQL_DECIMAL 3
\def SQL_INTEGER 4
\def SQL_SMALLINT 5
\def SQL_FLOAT 6
\def SQL_REAL 7
\def SQL_DOUBLE 8
\def SQL_DATETIME 9
\def SQL_TYPE_TIMESTAMP 93
\def SQL_VARCHAR 12
The ordinal used by ODBC.
*/
#define SQL_CHAR            1
#define SQL_NUMERIC         2
#define SQL_DECIMAL         3
#define SQL_INTEGER         4
#define SQL_SMALLINT        5
#define SQL_FLOAT           6
#define SQL_REAL            7
#define SQL_DOUBLE          8
#define SQL_DATETIME        9
#define SQL_TYPE_TIMESTAMP  93
#define SQL_VARCHAR         12
 
//!  TK_INTSOHSHSET class. 
/*!
*   Executed by the Qt Threading system.
*/
class TK_INTSOHSHSET : public QObject {
		Q_OBJECT 
 
 
public:
	TK_INTSOHSHSET(QObject * parent = Q_NULLPTR );
	~TK_INTSOHSHSET(); 
 
 
	 void setCommitInterval(int uCommitInterval) { commitInterval = uCommitInterval; }
	 void setUpdateInterval(int uUpdateInterval) { updateInterval = uUpdateInterval; }
	int rowsProcessed() { return rowsFetched; }
	void initOdbcAttributes(); 
	void initialize(); 
	QStringList m_OdbcAttributesList;
	QMap<int, nOdbcAttributesClass*> m_OdbcAttributes_Map;
//! void open taking two QString strings 
/*!
\param sourceDSN is a QString argument.
\param targetDSN is a  QString argument.
*/
	void close(); 
	void open(const QString sourceDSN, const QString targetDSN); 
	void createTable();
//! void setProfileName 
/*! Is a setter function. Accepts a single argument QString - denoting the ProfileName.
\param _profileName is a QString argument.
\sa profileName
*/
	void setProfileName(const QString _profileName) { profileName = _profileName; } 
//! A normal member taking one argument and returning an boolean value.
/*! Entry function for the class - all data synchronization operations are executed from the process function.
\param rowSSize an integer argument.
\param s a constant character pointer.
\return The success status of this synchronization operation.
*/
//! void setRepositoryString 
/*! Is a setter function. Accepts a single argument QString - denoting the DataSource Connection String of the eNVy SQL Repository.
\param _repoString is a QString argument.
\sa m_lpszRepositoryDSN
*/
	void setRepositoryString(const QString _repoString) { m_lpszRepositoryDSN = _repoString; } 
//! QString getTableName 
/*! Is a getter function which returns the table name that is processed by this class.
\sa tableName
*/
	bool process(int rowSSize); 
//! void setNetChange 
/*! Is a setter function. Toggles the data synchronization method from BulK_Copy to Net Change.
\sa bIsNetChange
*/
	QString			getTableName() {	return tableName;}
	void			setNetChange() { bIsNetChange = true; } 
//! void setDropOption 
/*! Is a setter function. Accepts a single argument DropOption - the method with which the table should be handled prior to Bulk_Copy is performed.
\param dropOption is a DropOption argument.
\sa DropOption
*/
	void			setDropOption(DropOption dropOption) { m_dropOption = dropOption;  }
//! void setOdbcAttributes 
/*! Is a setter function. Accepts a single argument as a QString.
/*!  ODBC Attributes are delimited by Comma
/*!  ODBC Attribute support is limited to Qt 5.9 ODBC Support
\param odbcAttr is a QString argument.
*/
	void			setOdbcAttributes(const QString odbcAttr) { m_OdbcAttributes = odbcAttr;  }
//! void setReplicationOption 
/*! Is a setter function. Accepts a single argument as a ReplicationOption. Three selection options are possible; Bulk_Copy, Net_Change, NotSet
/*!  ODBC Attributes are delimited by Comma
/*!  ODBC Attribute support is limited to Qt 5.9 ODBC Support
\param odbcAttr is a QString argument.
\sa ReplicationOption
*/
	void			 setReplicationOption(ReplicationOption xReplicationOption) {
		m_ReplicationOption = xReplicationOption; 
	}
public slots:
	void setAbortFlag(); 
	void run();
signals:
//! void setAbortFlag 
/*! Is a setter function. A toggle - initiate an abort of the running class.
/*!  A toggle - initiate an abort of the running class.
*/
	void aborted(QString tableName, int fetchCnt,int insertCnt, int updateCnt);
//! void updateStatusFetched 
/*! Is a Qt Signal - the signal sends the parameterized values after each row is fetched.
\param tableName is a QString argument.
\param rowsFetched is a int argument.
*/
	void updateStatusFetched(QString profileName, QString tableName, int rowsFetched, int rowsInserted, int rowsUpdated);
 
private:
//! A private variable.
/*!
tableName := the table that will be processed by this class.
*/
	QString		tableName;
//! A private variable.
/*!
bIsAbort := the Abort flag that will be checked during the execution of this class. The default is false.
*/
	bool	bIsAbort=false;
//! A private variable.
/*!
	rowsFetched := the rowsFetch variable - a simple counter which is incremented after each row is successfully fetched. The default is 0.
*/
	int	rowsFetched = 0;
/*!
rowsFetched := the rowsInserted variable - a simple counter which is incremented after each row is successfully inserted. The default is 0.
*/
	int	rowsInserted = 0;
	int	rowsUpdated = 0;
	int	commitInterval=1000; // Rate at which SQLTransaction are committed

// Rate at which the object notifies the parent class
// the object has processed n rows.
 
	int	updateInterval=1000; 
	SQLINTEGER	lenAary = 0;
	SQLINTEGER	IndPtrArray = 0; 
/*!
hStmt_Insert, The ODBC Statement Handle for the Insert.
*/
	SQLHANDLE	hStmt_Insert; 
/*!
hStmt_Fetch, The ODBC Statement Handle for the Fetch.
*/
	SQLHANDLE	hStmt_Fetch;
/*!
hStmt_Update, The ODBC Statement Handle for the Update.
*/
	SQLHANDLE	hStmt_Update; 
/*!
numRowsFetched, The number of rows fetched.
*/
	SQLUINTEGER	numRowsFetched;
/*!
insertSql, The SQL statement used when preparing for row insertion.
*/
	QString	insertSql;
/*!
fetchSql, The SQL statement used when preparing for row selection.
*/
	QString	fetchSql;
/*!
updateSql, The SQL statement used when preparing for row updates.
*/
	QString	updateSql;
	SQLHDBC	hDbc_source;
	SQLHDBC	hDbc_target;
	SQLHENV	hEnv_Target;
	SQLHENV	hEnv_Source;
 
	QString	profileName;
	QString	m_lpszSourceDSN; 
	QString	m_lpszTargetDSN; 
	QString	m_lpszRepositoryDSN; 
	QString	m_OdbcAttributes; 
	bool bIsNetChange;
	bool	m_bIsOpen; 
	ReplicationOption m_ReplicationOption;
	DropOption  m_dropOption;
 
	bool prepare();
	void prepareTargetTable();
	bool bindColumn();
	bool bindParameter();
	void copyTable();
	void connect(connectionHandle connectionSource);

// FieldNames 
#pragma region Field Buffers TK_INTSOHSHSET
	QByteArray	DB_ID;
	QByteArray	NVTIMESTAMP;
	QByteArray	OAREA;
	QByteArray	OPAGE;
	QByteArray	OLINE;
	QByteArray	MAREA;
	QByteArray	MPAGE;
	QByteArray	MLINE;
	SQLINTEGER	cbDB_ID;
	SQLINTEGER	cbNVTIMESTAMP;
	SQLINTEGER	cbOAREA;
	SQLINTEGER	cbOPAGE;
	SQLINTEGER	cbOLINE;
	SQLINTEGER	cbMAREA;
	SQLINTEGER	cbMPAGE;
	SQLINTEGER	cbMLINE;
#pragma endregion Field Buffers TK_INTSOHSHSET

};
//!  TK_PRTLIDSET class. 
/*!
*   Executed by the Qt Threading system.
*/
class TK_PRTLIDSET : public QObject {
		Q_OBJECT 
 
 
public:
	TK_PRTLIDSET(QObject * parent = Q_NULLPTR );
	~TK_PRTLIDSET(); 
 
 
	 void setCommitInterval(int uCommitInterval) { commitInterval = uCommitInterval; }
	 void setUpdateInterval(int uUpdateInterval) { updateInterval = uUpdateInterval; }
	int rowsProcessed() { return rowsFetched; }
	void initOdbcAttributes(); 
	void initialize(); 
	QStringList m_OdbcAttributesList;
	QMap<int, nOdbcAttributesClass*> m_OdbcAttributes_Map;
//! void open taking two QString strings 
/*!
\param sourceDSN is a QString argument.
\param targetDSN is a  QString argument.
*/
	void close(); 
	void open(const QString sourceDSN, const QString targetDSN); 
	void createTable();
//! void setProfileName 
/*! Is a setter function. Accepts a single argument QString - denoting the ProfileName.
\param _profileName is a QString argument.
\sa profileName
*/
	void setProfileName(const QString _profileName) { profileName = _profileName; } 
//! A normal member taking one argument and returning an boolean value.
/*! Entry function for the class - all data synchronization operations are executed from the process function.
\param rowSSize an integer argument.
\param s a constant character pointer.
\return The success status of this synchronization operation.
*/
//! void setRepositoryString 
/*! Is a setter function. Accepts a single argument QString - denoting the DataSource Connection String of the eNVy SQL Repository.
\param _repoString is a QString argument.
\sa m_lpszRepositoryDSN
*/
	void setRepositoryString(const QString _repoString) { m_lpszRepositoryDSN = _repoString; } 
//! QString getTableName 
/*! Is a getter function which returns the table name that is processed by this class.
\sa tableName
*/
	bool process(int rowSSize); 
//! void setNetChange 
/*! Is a setter function. Toggles the data synchronization method from BulK_Copy to Net Change.
\sa bIsNetChange
*/
	QString			getTableName() {	return tableName;}
	void			setNetChange() { bIsNetChange = true; } 
//! void setDropOption 
/*! Is a setter function. Accepts a single argument DropOption - the method with which the table should be handled prior to Bulk_Copy is performed.
\param dropOption is a DropOption argument.
\sa DropOption
*/
	void			setDropOption(DropOption dropOption) { m_dropOption = dropOption;  }
//! void setOdbcAttributes 
/*! Is a setter function. Accepts a single argument as a QString.
/*!  ODBC Attributes are delimited by Comma
/*!  ODBC Attribute support is limited to Qt 5.9 ODBC Support
\param odbcAttr is a QString argument.
*/
	void			setOdbcAttributes(const QString odbcAttr) { m_OdbcAttributes = odbcAttr;  }
//! void setReplicationOption 
/*! Is a setter function. Accepts a single argument as a ReplicationOption. Three selection options are possible; Bulk_Copy, Net_Change, NotSet
/*!  ODBC Attributes are delimited by Comma
/*!  ODBC Attribute support is limited to Qt 5.9 ODBC Support
\param odbcAttr is a QString argument.
\sa ReplicationOption
*/
	void			 setReplicationOption(ReplicationOption xReplicationOption) {
		m_ReplicationOption = xReplicationOption; 
	}
public slots:
	void setAbortFlag(); 
	void run();
signals:
//! void setAbortFlag 
/*! Is a setter function. A toggle - initiate an abort of the running class.
/*!  A toggle - initiate an abort of the running class.
*/
	void aborted(QString tableName, int fetchCnt,int insertCnt, int updateCnt);
//! void updateStatusFetched 
/*! Is a Qt Signal - the signal sends the parameterized values after each row is fetched.
\param tableName is a QString argument.
\param rowsFetched is a int argument.
*/
	void updateStatusFetched(QString profileName, QString tableName, int rowsFetched, int rowsInserted, int rowsUpdated);
 
private:
//! A private variable.
/*!
tableName := the table that will be processed by this class.
*/
	QString		tableName;
//! A private variable.
/*!
bIsAbort := the Abort flag that will be checked during the execution of this class. The default is false.
*/
	bool	bIsAbort=false;
//! A private variable.
/*!
	rowsFetched := the rowsFetch variable - a simple counter which is incremented after each row is successfully fetched. The default is 0.
*/
	int	rowsFetched = 0;
/*!
rowsFetched := the rowsInserted variable - a simple counter which is incremented after each row is successfully inserted. The default is 0.
*/
	int	rowsInserted = 0;
	int	rowsUpdated = 0;
	int	commitInterval=1000; // Rate at which SQLTransaction are committed

// Rate at which the object notifies the parent class
// the object has processed n rows.
 
	int	updateInterval=1000; 
	SQLINTEGER	lenAary = 0;
	SQLINTEGER	IndPtrArray = 0; 
/*!
hStmt_Insert, The ODBC Statement Handle for the Insert.
*/
	SQLHANDLE	hStmt_Insert; 
/*!
hStmt_Fetch, The ODBC Statement Handle for the Fetch.
*/
	SQLHANDLE	hStmt_Fetch;
/*!
hStmt_Update, The ODBC Statement Handle for the Update.
*/
	SQLHANDLE	hStmt_Update; 
/*!
numRowsFetched, The number of rows fetched.
*/
	SQLUINTEGER	numRowsFetched;
/*!
insertSql, The SQL statement used when preparing for row insertion.
*/
	QString	insertSql;
/*!
fetchSql, The SQL statement used when preparing for row selection.
*/
	QString	fetchSql;
/*!
updateSql, The SQL statement used when preparing for row updates.
*/
	QString	updateSql;
	SQLHDBC	hDbc_source;
	SQLHDBC	hDbc_target;
	SQLHENV	hEnv_Target;
	SQLHENV	hEnv_Source;
 
	QString	profileName;
	QString	m_lpszSourceDSN; 
	QString	m_lpszTargetDSN; 
	QString	m_lpszRepositoryDSN; 
	QString	m_OdbcAttributes; 
	bool bIsNetChange;
	bool	m_bIsOpen; 
	ReplicationOption m_ReplicationOption;
	DropOption  m_dropOption;
 
	bool prepare();
	void prepareTargetTable();
	bool bindColumn();
	bool bindParameter();
	void copyTable();
	void connect(connectionHandle connectionSource);

// FieldNames 
#pragma region Field Buffers TK_PRTLIDSET
	QByteArray	DB_ID;
	QByteArray	NVTIMESTAMP;
	QByteArray	OAREA;
	QByteArray	OPAGE;
	QByteArray	OLINE;
	QByteArray	MAREA;
	QByteArray	MPAGE;
	QByteArray	MLINE;
	SQLINTEGER	cbDB_ID;
	SQLINTEGER	cbNVTIMESTAMP;
	SQLINTEGER	cbOAREA;
	SQLINTEGER	cbOPAGE;
	SQLINTEGER	cbOLINE;
	SQLINTEGER	cbMAREA;
	SQLINTEGER	cbMPAGE;
	SQLINTEGER	cbMLINE;
#pragma endregion Field Buffers TK_PRTLIDSET

};
//!  TK_PRTHSHSET class. 
/*!
*   Executed by the Qt Threading system.
*/
class TK_PRTHSHSET : public QObject {
		Q_OBJECT 
 
 
public:
	TK_PRTHSHSET(QObject * parent = Q_NULLPTR );
	~TK_PRTHSHSET(); 
 
 
	 void setCommitInterval(int uCommitInterval) { commitInterval = uCommitInterval; }
	 void setUpdateInterval(int uUpdateInterval) { updateInterval = uUpdateInterval; }
	int rowsProcessed() { return rowsFetched; }
	void initOdbcAttributes(); 
	void initialize(); 
	QStringList m_OdbcAttributesList;
	QMap<int, nOdbcAttributesClass*> m_OdbcAttributes_Map;
//! void open taking two QString strings 
/*!
\param sourceDSN is a QString argument.
\param targetDSN is a  QString argument.
*/
	void close(); 
	void open(const QString sourceDSN, const QString targetDSN); 
	void createTable();
//! void setProfileName 
/*! Is a setter function. Accepts a single argument QString - denoting the ProfileName.
\param _profileName is a QString argument.
\sa profileName
*/
	void setProfileName(const QString _profileName) { profileName = _profileName; } 
//! A normal member taking one argument and returning an boolean value.
/*! Entry function for the class - all data synchronization operations are executed from the process function.
\param rowSSize an integer argument.
\param s a constant character pointer.
\return The success status of this synchronization operation.
*/
//! void setRepositoryString 
/*! Is a setter function. Accepts a single argument QString - denoting the DataSource Connection String of the eNVy SQL Repository.
\param _repoString is a QString argument.
\sa m_lpszRepositoryDSN
*/
	void setRepositoryString(const QString _repoString) { m_lpszRepositoryDSN = _repoString; } 
//! QString getTableName 
/*! Is a getter function which returns the table name that is processed by this class.
\sa tableName
*/
	bool process(int rowSSize); 
//! void setNetChange 
/*! Is a setter function. Toggles the data synchronization method from BulK_Copy to Net Change.
\sa bIsNetChange
*/
	QString			getTableName() {	return tableName;}
	void			setNetChange() { bIsNetChange = true; } 
//! void setDropOption 
/*! Is a setter function. Accepts a single argument DropOption - the method with which the table should be handled prior to Bulk_Copy is performed.
\param dropOption is a DropOption argument.
\sa DropOption
*/
	void			setDropOption(DropOption dropOption) { m_dropOption = dropOption;  }
//! void setOdbcAttributes 
/*! Is a setter function. Accepts a single argument as a QString.
/*!  ODBC Attributes are delimited by Comma
/*!  ODBC Attribute support is limited to Qt 5.9 ODBC Support
\param odbcAttr is a QString argument.
*/
	void			setOdbcAttributes(const QString odbcAttr) { m_OdbcAttributes = odbcAttr;  }
//! void setReplicationOption 
/*! Is a setter function. Accepts a single argument as a ReplicationOption. Three selection options are possible; Bulk_Copy, Net_Change, NotSet
/*!  ODBC Attributes are delimited by Comma
/*!  ODBC Attribute support is limited to Qt 5.9 ODBC Support
\param odbcAttr is a QString argument.
\sa ReplicationOption
*/
	void			 setReplicationOption(ReplicationOption xReplicationOption) {
		m_ReplicationOption = xReplicationOption; 
	}
public slots:
	void setAbortFlag(); 
	void run();
signals:
//! void setAbortFlag 
/*! Is a setter function. A toggle - initiate an abort of the running class.
/*!  A toggle - initiate an abort of the running class.
*/
	void aborted(QString tableName, int fetchCnt,int insertCnt, int updateCnt);
//! void updateStatusFetched 
/*! Is a Qt Signal - the signal sends the parameterized values after each row is fetched.
\param tableName is a QString argument.
\param rowsFetched is a int argument.
*/
	void updateStatusFetched(QString profileName, QString tableName, int rowsFetched, int rowsInserted, int rowsUpdated);
 
private:
//! A private variable.
/*!
tableName := the table that will be processed by this class.
*/
	QString		tableName;
//! A private variable.
/*!
bIsAbort := the Abort flag that will be checked during the execution of this class. The default is false.
*/
	bool	bIsAbort=false;
//! A private variable.
/*!
	rowsFetched := the rowsFetch variable - a simple counter which is incremented after each row is successfully fetched. The default is 0.
*/
	int	rowsFetched = 0;
/*!
rowsFetched := the rowsInserted variable - a simple counter which is incremented after each row is successfully inserted. The default is 0.
*/
	int	rowsInserted = 0;
	int	rowsUpdated = 0;
	int	commitInterval=1000; // Rate at which SQLTransaction are committed

// Rate at which the object notifies the parent class
// the object has processed n rows.
 
	int	updateInterval=1000; 
	SQLINTEGER	lenAary = 0;
	SQLINTEGER	IndPtrArray = 0; 
/*!
hStmt_Insert, The ODBC Statement Handle for the Insert.
*/
	SQLHANDLE	hStmt_Insert; 
/*!
hStmt_Fetch, The ODBC Statement Handle for the Fetch.
*/
	SQLHANDLE	hStmt_Fetch;
/*!
hStmt_Update, The ODBC Statement Handle for the Update.
*/
	SQLHANDLE	hStmt_Update; 
/*!
numRowsFetched, The number of rows fetched.
*/
	SQLUINTEGER	numRowsFetched;
/*!
insertSql, The SQL statement used when preparing for row insertion.
*/
	QString	insertSql;
/*!
fetchSql, The SQL statement used when preparing for row selection.
*/
	QString	fetchSql;
/*!
updateSql, The SQL statement used when preparing for row updates.
*/
	QString	updateSql;
	SQLHDBC	hDbc_source;
	SQLHDBC	hDbc_target;
	SQLHENV	hEnv_Target;
	SQLHENV	hEnv_Source;
 
	QString	profileName;
	QString	m_lpszSourceDSN; 
	QString	m_lpszTargetDSN; 
	QString	m_lpszRepositoryDSN; 
	QString	m_OdbcAttributes; 
	bool bIsNetChange;
	bool	m_bIsOpen; 
	ReplicationOption m_ReplicationOption;
	DropOption  m_dropOption;
 
	bool prepare();
	void prepareTargetTable();
	bool bindColumn();
	bool bindParameter();
	void copyTable();
	void connect(connectionHandle connectionSource);

// FieldNames 
#pragma region Field Buffers TK_PRTHSHSET
	QByteArray	DB_ID;
	QByteArray	NVTIMESTAMP;
	QByteArray	OAREA;
	QByteArray	OPAGE;
	QByteArray	OLINE;
	QByteArray	MAREA;
	QByteArray	MPAGE;
	QByteArray	MLINE;
	SQLINTEGER	cbDB_ID;
	SQLINTEGER	cbNVTIMESTAMP;
	SQLINTEGER	cbOAREA;
	SQLINTEGER	cbOPAGE;
	SQLINTEGER	cbOLINE;
	SQLINTEGER	cbMAREA;
	SQLINTEGER	cbMPAGE;
	SQLINTEGER	cbMLINE;
#pragma endregion Field Buffers TK_PRTHSHSET

};
//!  TK_TYPHSHSET class. 
/*!
*   Executed by the Qt Threading system.
*/
class TK_TYPHSHSET : public QObject {
		Q_OBJECT 
 
 
public:
	TK_TYPHSHSET(QObject * parent = Q_NULLPTR );
	~TK_TYPHSHSET(); 
 
 
	 void setCommitInterval(int uCommitInterval) { commitInterval = uCommitInterval; }
	 void setUpdateInterval(int uUpdateInterval) { updateInterval = uUpdateInterval; }
	int rowsProcessed() { return rowsFetched; }
	void initOdbcAttributes(); 
	void initialize(); 
	QStringList m_OdbcAttributesList;
	QMap<int, nOdbcAttributesClass*> m_OdbcAttributes_Map;
//! void open taking two QString strings 
/*!
\param sourceDSN is a QString argument.
\param targetDSN is a  QString argument.
*/
	void close(); 
	void open(const QString sourceDSN, const QString targetDSN); 
	void createTable();
//! void setProfileName 
/*! Is a setter function. Accepts a single argument QString - denoting the ProfileName.
\param _profileName is a QString argument.
\sa profileName
*/
	void setProfileName(const QString _profileName) { profileName = _profileName; } 
//! A normal member taking one argument and returning an boolean value.
/*! Entry function for the class - all data synchronization operations are executed from the process function.
\param rowSSize an integer argument.
\param s a constant character pointer.
\return The success status of this synchronization operation.
*/
//! void setRepositoryString 
/*! Is a setter function. Accepts a single argument QString - denoting the DataSource Connection String of the eNVy SQL Repository.
\param _repoString is a QString argument.
\sa m_lpszRepositoryDSN
*/
	void setRepositoryString(const QString _repoString) { m_lpszRepositoryDSN = _repoString; } 
//! QString getTableName 
/*! Is a getter function which returns the table name that is processed by this class.
\sa tableName
*/
	bool process(int rowSSize); 
//! void setNetChange 
/*! Is a setter function. Toggles the data synchronization method from BulK_Copy to Net Change.
\sa bIsNetChange
*/
	QString			getTableName() {	return tableName;}
	void			setNetChange() { bIsNetChange = true; } 
//! void setDropOption 
/*! Is a setter function. Accepts a single argument DropOption - the method with which the table should be handled prior to Bulk_Copy is performed.
\param dropOption is a DropOption argument.
\sa DropOption
*/
	void			setDropOption(DropOption dropOption) { m_dropOption = dropOption;  }
//! void setOdbcAttributes 
/*! Is a setter function. Accepts a single argument as a QString.
/*!  ODBC Attributes are delimited by Comma
/*!  ODBC Attribute support is limited to Qt 5.9 ODBC Support
\param odbcAttr is a QString argument.
*/
	void			setOdbcAttributes(const QString odbcAttr) { m_OdbcAttributes = odbcAttr;  }
//! void setReplicationOption 
/*! Is a setter function. Accepts a single argument as a ReplicationOption. Three selection options are possible; Bulk_Copy, Net_Change, NotSet
/*!  ODBC Attributes are delimited by Comma
/*!  ODBC Attribute support is limited to Qt 5.9 ODBC Support
\param odbcAttr is a QString argument.
\sa ReplicationOption
*/
	void			 setReplicationOption(ReplicationOption xReplicationOption) {
		m_ReplicationOption = xReplicationOption; 
	}
public slots:
	void setAbortFlag(); 
	void run();
signals:
//! void setAbortFlag 
/*! Is a setter function. A toggle - initiate an abort of the running class.
/*!  A toggle - initiate an abort of the running class.
*/
	void aborted(QString tableName, int fetchCnt,int insertCnt, int updateCnt);
//! void updateStatusFetched 
/*! Is a Qt Signal - the signal sends the parameterized values after each row is fetched.
\param tableName is a QString argument.
\param rowsFetched is a int argument.
*/
	void updateStatusFetched(QString profileName, QString tableName, int rowsFetched, int rowsInserted, int rowsUpdated);
 
private:
//! A private variable.
/*!
tableName := the table that will be processed by this class.
*/
	QString		tableName;
//! A private variable.
/*!
bIsAbort := the Abort flag that will be checked during the execution of this class. The default is false.
*/
	bool	bIsAbort=false;
//! A private variable.
/*!
	rowsFetched := the rowsFetch variable - a simple counter which is incremented after each row is successfully fetched. The default is 0.
*/
	int	rowsFetched = 0;
/*!
rowsFetched := the rowsInserted variable - a simple counter which is incremented after each row is successfully inserted. The default is 0.
*/
	int	rowsInserted = 0;
	int	rowsUpdated = 0;
	int	commitInterval=1000; // Rate at which SQLTransaction are committed

// Rate at which the object notifies the parent class
// the object has processed n rows.
 
	int	updateInterval=1000; 
	SQLINTEGER	lenAary = 0;
	SQLINTEGER	IndPtrArray = 0; 
/*!
hStmt_Insert, The ODBC Statement Handle for the Insert.
*/
	SQLHANDLE	hStmt_Insert; 
/*!
hStmt_Fetch, The ODBC Statement Handle for the Fetch.
*/
	SQLHANDLE	hStmt_Fetch;
/*!
hStmt_Update, The ODBC Statement Handle for the Update.
*/
	SQLHANDLE	hStmt_Update; 
/*!
numRowsFetched, The number of rows fetched.
*/
	SQLUINTEGER	numRowsFetched;
/*!
insertSql, The SQL statement used when preparing for row insertion.
*/
	QString	insertSql;
/*!
fetchSql, The SQL statement used when preparing for row selection.
*/
	QString	fetchSql;
/*!
updateSql, The SQL statement used when preparing for row updates.
*/
	QString	updateSql;
	SQLHDBC	hDbc_source;
	SQLHDBC	hDbc_target;
	SQLHENV	hEnv_Target;
	SQLHENV	hEnv_Source;
 
	QString	profileName;
	QString	m_lpszSourceDSN; 
	QString	m_lpszTargetDSN; 
	QString	m_lpszRepositoryDSN; 
	QString	m_OdbcAttributes; 
	bool bIsNetChange;
	bool	m_bIsOpen; 
	ReplicationOption m_ReplicationOption;
	DropOption  m_dropOption;
 
	bool prepare();
	void prepareTargetTable();
	bool bindColumn();
	bool bindParameter();
	void copyTable();
	void connect(connectionHandle connectionSource);

// FieldNames 
#pragma region Field Buffers TK_TYPHSHSET
	QByteArray	DB_ID;
	QByteArray	NVTIMESTAMP;
	QByteArray	OAREA;
	QByteArray	OPAGE;
	QByteArray	OLINE;
	QByteArray	MAREA;
	QByteArray	MPAGE;
	QByteArray	MLINE;
	SQLINTEGER	cbDB_ID;
	SQLINTEGER	cbNVTIMESTAMP;
	SQLINTEGER	cbOAREA;
	SQLINTEGER	cbOPAGE;
	SQLINTEGER	cbOLINE;
	SQLINTEGER	cbMAREA;
	SQLINTEGER	cbMPAGE;
	SQLINTEGER	cbMLINE;
#pragma endregion Field Buffers TK_TYPHSHSET

};
//!  TK_FLGREC class. 
/*!
*   Executed by the Qt Threading system.
*/
class TK_FLGREC : public QObject {
		Q_OBJECT 
 
 
public:
	TK_FLGREC(QObject * parent = Q_NULLPTR );
	~TK_FLGREC(); 
 
 
	 void setCommitInterval(int uCommitInterval) { commitInterval = uCommitInterval; }
	 void setUpdateInterval(int uUpdateInterval) { updateInterval = uUpdateInterval; }
	int rowsProcessed() { return rowsFetched; }
	void initOdbcAttributes(); 
	void initialize(); 
	QStringList m_OdbcAttributesList;
	QMap<int, nOdbcAttributesClass*> m_OdbcAttributes_Map;
//! void open taking two QString strings 
/*!
\param sourceDSN is a QString argument.
\param targetDSN is a  QString argument.
*/
	void close(); 
	void open(const QString sourceDSN, const QString targetDSN); 
	void createTable();
//! void setProfileName 
/*! Is a setter function. Accepts a single argument QString - denoting the ProfileName.
\param _profileName is a QString argument.
\sa profileName
*/
	void setProfileName(const QString _profileName) { profileName = _profileName; } 
//! A normal member taking one argument and returning an boolean value.
/*! Entry function for the class - all data synchronization operations are executed from the process function.
\param rowSSize an integer argument.
\param s a constant character pointer.
\return The success status of this synchronization operation.
*/
//! void setRepositoryString 
/*! Is a setter function. Accepts a single argument QString - denoting the DataSource Connection String of the eNVy SQL Repository.
\param _repoString is a QString argument.
\sa m_lpszRepositoryDSN
*/
	void setRepositoryString(const QString _repoString) { m_lpszRepositoryDSN = _repoString; } 
//! QString getTableName 
/*! Is a getter function which returns the table name that is processed by this class.
\sa tableName
*/
	bool process(int rowSSize); 
//! void setNetChange 
/*! Is a setter function. Toggles the data synchronization method from BulK_Copy to Net Change.
\sa bIsNetChange
*/
	QString			getTableName() {	return tableName;}
	void			setNetChange() { bIsNetChange = true; } 
//! void setDropOption 
/*! Is a setter function. Accepts a single argument DropOption - the method with which the table should be handled prior to Bulk_Copy is performed.
\param dropOption is a DropOption argument.
\sa DropOption
*/
	void			setDropOption(DropOption dropOption) { m_dropOption = dropOption;  }
//! void setOdbcAttributes 
/*! Is a setter function. Accepts a single argument as a QString.
/*!  ODBC Attributes are delimited by Comma
/*!  ODBC Attribute support is limited to Qt 5.9 ODBC Support
\param odbcAttr is a QString argument.
*/
	void			setOdbcAttributes(const QString odbcAttr) { m_OdbcAttributes = odbcAttr;  }
//! void setReplicationOption 
/*! Is a setter function. Accepts a single argument as a ReplicationOption. Three selection options are possible; Bulk_Copy, Net_Change, NotSet
/*!  ODBC Attributes are delimited by Comma
/*!  ODBC Attribute support is limited to Qt 5.9 ODBC Support
\param odbcAttr is a QString argument.
\sa ReplicationOption
*/
	void			 setReplicationOption(ReplicationOption xReplicationOption) {
		m_ReplicationOption = xReplicationOption; 
	}
public slots:
	void setAbortFlag(); 
	void run();
signals:
//! void setAbortFlag 
/*! Is a setter function. A toggle - initiate an abort of the running class.
/*!  A toggle - initiate an abort of the running class.
*/
	void aborted(QString tableName, int fetchCnt,int insertCnt, int updateCnt);
//! void updateStatusFetched 
/*! Is a Qt Signal - the signal sends the parameterized values after each row is fetched.
\param tableName is a QString argument.
\param rowsFetched is a int argument.
*/
	void updateStatusFetched(QString profileName, QString tableName, int rowsFetched, int rowsInserted, int rowsUpdated);
 
private:
//! A private variable.
/*!
tableName := the table that will be processed by this class.
*/
	QString		tableName;
//! A private variable.
/*!
bIsAbort := the Abort flag that will be checked during the execution of this class. The default is false.
*/
	bool	bIsAbort=false;
//! A private variable.
/*!
	rowsFetched := the rowsFetch variable - a simple counter which is incremented after each row is successfully fetched. The default is 0.
*/
	int	rowsFetched = 0;
/*!
rowsFetched := the rowsInserted variable - a simple counter which is incremented after each row is successfully inserted. The default is 0.
*/
	int	rowsInserted = 0;
	int	rowsUpdated = 0;
	int	commitInterval=1000; // Rate at which SQLTransaction are committed

// Rate at which the object notifies the parent class
// the object has processed n rows.
 
	int	updateInterval=1000; 
	SQLINTEGER	lenAary = 0;
	SQLINTEGER	IndPtrArray = 0; 
/*!
hStmt_Insert, The ODBC Statement Handle for the Insert.
*/
	SQLHANDLE	hStmt_Insert; 
/*!
hStmt_Fetch, The ODBC Statement Handle for the Fetch.
*/
	SQLHANDLE	hStmt_Fetch;
/*!
hStmt_Update, The ODBC Statement Handle for the Update.
*/
	SQLHANDLE	hStmt_Update; 
/*!
numRowsFetched, The number of rows fetched.
*/
	SQLUINTEGER	numRowsFetched;
/*!
insertSql, The SQL statement used when preparing for row insertion.
*/
	QString	insertSql;
/*!
fetchSql, The SQL statement used when preparing for row selection.
*/
	QString	fetchSql;
/*!
updateSql, The SQL statement used when preparing for row updates.
*/
	QString	updateSql;
	SQLHDBC	hDbc_source;
	SQLHDBC	hDbc_target;
	SQLHENV	hEnv_Target;
	SQLHENV	hEnv_Source;
 
	QString	profileName;
	QString	m_lpszSourceDSN; 
	QString	m_lpszTargetDSN; 
	QString	m_lpszRepositoryDSN; 
	QString	m_OdbcAttributes; 
	bool bIsNetChange;
	bool	m_bIsOpen; 
	ReplicationOption m_ReplicationOption;
	DropOption  m_dropOption;
 
	bool prepare();
	void prepareTargetTable();
	bool bindColumn();
	bool bindParameter();
	void copyTable();
	void connect(connectionHandle connectionSource);

// FieldNames 
#pragma region Field Buffers TK_FLGREC
	QByteArray	DB_ID;
	QByteArray	NVTIMESTAMP;
	QByteArray	AREA;
	QByteArray	PAGE;
	QByteArray	LINE;
	QByteArray	TK_FLGNO;
	QByteArray	TK_FLGVALU;
	SQLINTEGER	cbDB_ID;
	SQLINTEGER	cbNVTIMESTAMP;
	SQLINTEGER	cbAREA;
	SQLINTEGER	cbPAGE;
	SQLINTEGER	cbLINE;
	SQLINTEGER	cbTK_FLGNO;
	SQLINTEGER	cbTK_FLGVALU;
#pragma endregion Field Buffers TK_FLGREC

};
//!  TK_LTFREC class. 
/*!
*   Executed by the Qt Threading system.
*/
class TK_LTFREC : public QObject {
		Q_OBJECT 
 
 
public:
	TK_LTFREC(QObject * parent = Q_NULLPTR );
	~TK_LTFREC(); 
 
 
	 void setCommitInterval(int uCommitInterval) { commitInterval = uCommitInterval; }
	 void setUpdateInterval(int uUpdateInterval) { updateInterval = uUpdateInterval; }
	int rowsProcessed() { return rowsFetched; }
	void initOdbcAttributes(); 
	void initialize(); 
	QStringList m_OdbcAttributesList;
	QMap<int, nOdbcAttributesClass*> m_OdbcAttributes_Map;
//! void open taking two QString strings 
/*!
\param sourceDSN is a QString argument.
\param targetDSN is a  QString argument.
*/
	void close(); 
	void open(const QString sourceDSN, const QString targetDSN); 
	void createTable();
//! void setProfileName 
/*! Is a setter function. Accepts a single argument QString - denoting the ProfileName.
\param _profileName is a QString argument.
\sa profileName
*/
	void setProfileName(const QString _profileName) { profileName = _profileName; } 
//! A normal member taking one argument and returning an boolean value.
/*! Entry function for the class - all data synchronization operations are executed from the process function.
\param rowSSize an integer argument.
\param s a constant character pointer.
\return The success status of this synchronization operation.
*/
//! void setRepositoryString 
/*! Is a setter function. Accepts a single argument QString - denoting the DataSource Connection String of the eNVy SQL Repository.
\param _repoString is a QString argument.
\sa m_lpszRepositoryDSN
*/
	void setRepositoryString(const QString _repoString) { m_lpszRepositoryDSN = _repoString; } 
//! QString getTableName 
/*! Is a getter function which returns the table name that is processed by this class.
\sa tableName
*/
	bool process(int rowSSize); 
//! void setNetChange 
/*! Is a setter function. Toggles the data synchronization method from BulK_Copy to Net Change.
\sa bIsNetChange
*/
	QString			getTableName() {	return tableName;}
	void			setNetChange() { bIsNetChange = true; } 
//! void setDropOption 
/*! Is a setter function. Accepts a single argument DropOption - the method with which the table should be handled prior to Bulk_Copy is performed.
\param dropOption is a DropOption argument.
\sa DropOption
*/
	void			setDropOption(DropOption dropOption) { m_dropOption = dropOption;  }
//! void setOdbcAttributes 
/*! Is a setter function. Accepts a single argument as a QString.
/*!  ODBC Attributes are delimited by Comma
/*!  ODBC Attribute support is limited to Qt 5.9 ODBC Support
\param odbcAttr is a QString argument.
*/
	void			setOdbcAttributes(const QString odbcAttr) { m_OdbcAttributes = odbcAttr;  }
//! void setReplicationOption 
/*! Is a setter function. Accepts a single argument as a ReplicationOption. Three selection options are possible; Bulk_Copy, Net_Change, NotSet
/*!  ODBC Attributes are delimited by Comma
/*!  ODBC Attribute support is limited to Qt 5.9 ODBC Support
\param odbcAttr is a QString argument.
\sa ReplicationOption
*/
	void			 setReplicationOption(ReplicationOption xReplicationOption) {
		m_ReplicationOption = xReplicationOption; 
	}
public slots:
	void setAbortFlag(); 
	void run();
signals:
//! void setAbortFlag 
/*! Is a setter function. A toggle - initiate an abort of the running class.
/*!  A toggle - initiate an abort of the running class.
*/
	void aborted(QString tableName, int fetchCnt,int insertCnt, int updateCnt);
//! void updateStatusFetched 
/*! Is a Qt Signal - the signal sends the parameterized values after each row is fetched.
\param tableName is a QString argument.
\param rowsFetched is a int argument.
*/
	void updateStatusFetched(QString profileName, QString tableName, int rowsFetched, int rowsInserted, int rowsUpdated);
 
private:
//! A private variable.
/*!
tableName := the table that will be processed by this class.
*/
	QString		tableName;
//! A private variable.
/*!
bIsAbort := the Abort flag that will be checked during the execution of this class. The default is false.
*/
	bool	bIsAbort=false;
//! A private variable.
/*!
	rowsFetched := the rowsFetch variable - a simple counter which is incremented after each row is successfully fetched. The default is 0.
*/
	int	rowsFetched = 0;
/*!
rowsFetched := the rowsInserted variable - a simple counter which is incremented after each row is successfully inserted. The default is 0.
*/
	int	rowsInserted = 0;
	int	rowsUpdated = 0;
	int	commitInterval=1000; // Rate at which SQLTransaction are committed

// Rate at which the object notifies the parent class
// the object has processed n rows.
 
	int	updateInterval=1000; 
	SQLINTEGER	lenAary = 0;
	SQLINTEGER	IndPtrArray = 0; 
/*!
hStmt_Insert, The ODBC Statement Handle for the Insert.
*/
	SQLHANDLE	hStmt_Insert; 
/*!
hStmt_Fetch, The ODBC Statement Handle for the Fetch.
*/
	SQLHANDLE	hStmt_Fetch;
/*!
hStmt_Update, The ODBC Statement Handle for the Update.
*/
	SQLHANDLE	hStmt_Update; 
/*!
numRowsFetched, The number of rows fetched.
*/
	SQLUINTEGER	numRowsFetched;
/*!
insertSql, The SQL statement used when preparing for row insertion.
*/
	QString	insertSql;
/*!
fetchSql, The SQL statement used when preparing for row selection.
*/
	QString	fetchSql;
/*!
updateSql, The SQL statement used when preparing for row updates.
*/
	QString	updateSql;
	SQLHDBC	hDbc_source;
	SQLHDBC	hDbc_target;
	SQLHENV	hEnv_Target;
	SQLHENV	hEnv_Source;
 
	QString	profileName;
	QString	m_lpszSourceDSN; 
	QString	m_lpszTargetDSN; 
	QString	m_lpszRepositoryDSN; 
	QString	m_OdbcAttributes; 
	bool bIsNetChange;
	bool	m_bIsOpen; 
	ReplicationOption m_ReplicationOption;
	DropOption  m_dropOption;
 
	bool prepare();
	void prepareTargetTable();
	bool bindColumn();
	bool bindParameter();
	void copyTable();
	void connect(connectionHandle connectionSource);

// FieldNames 
#pragma region Field Buffers TK_LTFREC
	QByteArray	DB_ID;
	QByteArray	NVTIMESTAMP;
	QByteArray	AREA;
	QByteArray	PAGE;
	QByteArray	LINE;
	QByteArray	TK_LTFVALUE;
	QByteArray	TK_LTFUSR;
	QByteArray	TK_LTFDAT;
	QByteArray	TK_LTFTIM;
	QByteArray	TK_LTFCMD;
	QByteArray	TK_PRTNO;
	SQLINTEGER	cbDB_ID;
	SQLINTEGER	cbNVTIMESTAMP;
	SQLINTEGER	cbAREA;
	SQLINTEGER	cbPAGE;
	SQLINTEGER	cbLINE;
	SQLINTEGER	cbTK_LTFVALUE;
	SQLINTEGER	cbTK_LTFUSR;
	SQLINTEGER	cbTK_LTFDAT;
	SQLINTEGER	cbTK_LTFTIM;
	SQLINTEGER	cbTK_LTFCMD;
	SQLINTEGER	cbTK_PRTNO;
#pragma endregion Field Buffers TK_LTFREC

};
//!  TK_PRCHSHSET class. 
/*!
*   Executed by the Qt Threading system.
*/
class TK_PRCHSHSET : public QObject {
		Q_OBJECT 
 
 
public:
	TK_PRCHSHSET(QObject * parent = Q_NULLPTR );
	~TK_PRCHSHSET(); 
 
 
	 void setCommitInterval(int uCommitInterval) { commitInterval = uCommitInterval; }
	 void setUpdateInterval(int uUpdateInterval) { updateInterval = uUpdateInterval; }
	int rowsProcessed() { return rowsFetched; }
	void initOdbcAttributes(); 
	void initialize(); 
	QStringList m_OdbcAttributesList;
	QMap<int, nOdbcAttributesClass*> m_OdbcAttributes_Map;
//! void open taking two QString strings 
/*!
\param sourceDSN is a QString argument.
\param targetDSN is a  QString argument.
*/
	void close(); 
	void open(const QString sourceDSN, const QString targetDSN); 
	void createTable();
//! void setProfileName 
/*! Is a setter function. Accepts a single argument QString - denoting the ProfileName.
\param _profileName is a QString argument.
\sa profileName
*/
	void setProfileName(const QString _profileName) { profileName = _profileName; } 
//! A normal member taking one argument and returning an boolean value.
/*! Entry function for the class - all data synchronization operations are executed from the process function.
\param rowSSize an integer argument.
\param s a constant character pointer.
\return The success status of this synchronization operation.
*/
//! void setRepositoryString 
/*! Is a setter function. Accepts a single argument QString - denoting the DataSource Connection String of the eNVy SQL Repository.
\param _repoString is a QString argument.
\sa m_lpszRepositoryDSN
*/
	void setRepositoryString(const QString _repoString) { m_lpszRepositoryDSN = _repoString; } 
//! QString getTableName 
/*! Is a getter function which returns the table name that is processed by this class.
\sa tableName
*/
	bool process(int rowSSize); 
//! void setNetChange 
/*! Is a setter function. Toggles the data synchronization method from BulK_Copy to Net Change.
\sa bIsNetChange
*/
	QString			getTableName() {	return tableName;}
	void			setNetChange() { bIsNetChange = true; } 
//! void setDropOption 
/*! Is a setter function. Accepts a single argument DropOption - the method with which the table should be handled prior to Bulk_Copy is performed.
\param dropOption is a DropOption argument.
\sa DropOption
*/
	void			setDropOption(DropOption dropOption) { m_dropOption = dropOption;  }
//! void setOdbcAttributes 
/*! Is a setter function. Accepts a single argument as a QString.
/*!  ODBC Attributes are delimited by Comma
/*!  ODBC Attribute support is limited to Qt 5.9 ODBC Support
\param odbcAttr is a QString argument.
*/
	void			setOdbcAttributes(const QString odbcAttr) { m_OdbcAttributes = odbcAttr;  }
//! void setReplicationOption 
/*! Is a setter function. Accepts a single argument as a ReplicationOption. Three selection options are possible; Bulk_Copy, Net_Change, NotSet
/*!  ODBC Attributes are delimited by Comma
/*!  ODBC Attribute support is limited to Qt 5.9 ODBC Support
\param odbcAttr is a QString argument.
\sa ReplicationOption
*/
	void			 setReplicationOption(ReplicationOption xReplicationOption) {
		m_ReplicationOption = xReplicationOption; 
	}
public slots:
	void setAbortFlag(); 
	void run();
signals:
//! void setAbortFlag 
/*! Is a setter function. A toggle - initiate an abort of the running class.
/*!  A toggle - initiate an abort of the running class.
*/
	void aborted(QString tableName, int fetchCnt,int insertCnt, int updateCnt);
//! void updateStatusFetched 
/*! Is a Qt Signal - the signal sends the parameterized values after each row is fetched.
\param tableName is a QString argument.
\param rowsFetched is a int argument.
*/
	void updateStatusFetched(QString profileName, QString tableName, int rowsFetched, int rowsInserted, int rowsUpdated);
 
private:
//! A private variable.
/*!
tableName := the table that will be processed by this class.
*/
	QString		tableName;
//! A private variable.
/*!
bIsAbort := the Abort flag that will be checked during the execution of this class. The default is false.
*/
	bool	bIsAbort=false;
//! A private variable.
/*!
	rowsFetched := the rowsFetch variable - a simple counter which is incremented after each row is successfully fetched. The default is 0.
*/
	int	rowsFetched = 0;
/*!
rowsFetched := the rowsInserted variable - a simple counter which is incremented after each row is successfully inserted. The default is 0.
*/
	int	rowsInserted = 0;
	int	rowsUpdated = 0;
	int	commitInterval=1000; // Rate at which SQLTransaction are committed

// Rate at which the object notifies the parent class
// the object has processed n rows.
 
	int	updateInterval=1000; 
	SQLINTEGER	lenAary = 0;
	SQLINTEGER	IndPtrArray = 0; 
/*!
hStmt_Insert, The ODBC Statement Handle for the Insert.
*/
	SQLHANDLE	hStmt_Insert; 
/*!
hStmt_Fetch, The ODBC Statement Handle for the Fetch.
*/
	SQLHANDLE	hStmt_Fetch;
/*!
hStmt_Update, The ODBC Statement Handle for the Update.
*/
	SQLHANDLE	hStmt_Update; 
/*!
numRowsFetched, The number of rows fetched.
*/
	SQLUINTEGER	numRowsFetched;
/*!
insertSql, The SQL statement used when preparing for row insertion.
*/
	QString	insertSql;
/*!
fetchSql, The SQL statement used when preparing for row selection.
*/
	QString	fetchSql;
/*!
updateSql, The SQL statement used when preparing for row updates.
*/
	QString	updateSql;
	SQLHDBC	hDbc_source;
	SQLHDBC	hDbc_target;
	SQLHENV	hEnv_Target;
	SQLHENV	hEnv_Source;
 
	QString	profileName;
	QString	m_lpszSourceDSN; 
	QString	m_lpszTargetDSN; 
	QString	m_lpszRepositoryDSN; 
	QString	m_OdbcAttributes; 
	bool bIsNetChange;
	bool	m_bIsOpen; 
	ReplicationOption m_ReplicationOption;
	DropOption  m_dropOption;
 
	bool prepare();
	void prepareTargetTable();
	bool bindColumn();
	bool bindParameter();
	void copyTable();
	void connect(connectionHandle connectionSource);

// FieldNames 
#pragma region Field Buffers TK_PRCHSHSET
	QByteArray	DB_ID;
	QByteArray	NVTIMESTAMP;
	QByteArray	OAREA;
	QByteArray	OPAGE;
	QByteArray	OLINE;
	QByteArray	MAREA;
	QByteArray	MPAGE;
	QByteArray	MLINE;
	SQLINTEGER	cbDB_ID;
	SQLINTEGER	cbNVTIMESTAMP;
	SQLINTEGER	cbOAREA;
	SQLINTEGER	cbOPAGE;
	SQLINTEGER	cbOLINE;
	SQLINTEGER	cbMAREA;
	SQLINTEGER	cbMPAGE;
	SQLINTEGER	cbMLINE;
#pragma endregion Field Buffers TK_PRCHSHSET

};
//!  TK_NOTREC class. 
/*!
*   Executed by the Qt Threading system.
*/
class TK_NOTREC : public QObject {
		Q_OBJECT 
 
 
public:
	TK_NOTREC(QObject * parent = Q_NULLPTR );
	~TK_NOTREC(); 
 
 
	 void setCommitInterval(int uCommitInterval) { commitInterval = uCommitInterval; }
	 void setUpdateInterval(int uUpdateInterval) { updateInterval = uUpdateInterval; }
	int rowsProcessed() { return rowsFetched; }
	void initOdbcAttributes(); 
	void initialize(); 
	QStringList m_OdbcAttributesList;
	QMap<int, nOdbcAttributesClass*> m_OdbcAttributes_Map;
//! void open taking two QString strings 
/*!
\param sourceDSN is a QString argument.
\param targetDSN is a  QString argument.
*/
	void close(); 
	void open(const QString sourceDSN, const QString targetDSN); 
	void createTable();
//! void setProfileName 
/*! Is a setter function. Accepts a single argument QString - denoting the ProfileName.
\param _profileName is a QString argument.
\sa profileName
*/
	void setProfileName(const QString _profileName) { profileName = _profileName; } 
//! A normal member taking one argument and returning an boolean value.
/*! Entry function for the class - all data synchronization operations are executed from the process function.
\param rowSSize an integer argument.
\param s a constant character pointer.
\return The success status of this synchronization operation.
*/
//! void setRepositoryString 
/*! Is a setter function. Accepts a single argument QString - denoting the DataSource Connection String of the eNVy SQL Repository.
\param _repoString is a QString argument.
\sa m_lpszRepositoryDSN
*/
	void setRepositoryString(const QString _repoString) { m_lpszRepositoryDSN = _repoString; } 
//! QString getTableName 
/*! Is a getter function which returns the table name that is processed by this class.
\sa tableName
*/
	bool process(int rowSSize); 
//! void setNetChange 
/*! Is a setter function. Toggles the data synchronization method from BulK_Copy to Net Change.
\sa bIsNetChange
*/
	QString			getTableName() {	return tableName;}
	void			setNetChange() { bIsNetChange = true; } 
//! void setDropOption 
/*! Is a setter function. Accepts a single argument DropOption - the method with which the table should be handled prior to Bulk_Copy is performed.
\param dropOption is a DropOption argument.
\sa DropOption
*/
	void			setDropOption(DropOption dropOption) { m_dropOption = dropOption;  }
//! void setOdbcAttributes 
/*! Is a setter function. Accepts a single argument as a QString.
/*!  ODBC Attributes are delimited by Comma
/*!  ODBC Attribute support is limited to Qt 5.9 ODBC Support
\param odbcAttr is a QString argument.
*/
	void			setOdbcAttributes(const QString odbcAttr) { m_OdbcAttributes = odbcAttr;  }
//! void setReplicationOption 
/*! Is a setter function. Accepts a single argument as a ReplicationOption. Three selection options are possible; Bulk_Copy, Net_Change, NotSet
/*!  ODBC Attributes are delimited by Comma
/*!  ODBC Attribute support is limited to Qt 5.9 ODBC Support
\param odbcAttr is a QString argument.
\sa ReplicationOption
*/
	void			 setReplicationOption(ReplicationOption xReplicationOption) {
		m_ReplicationOption = xReplicationOption; 
	}
public slots:
	void setAbortFlag(); 
	void run();
signals:
//! void setAbortFlag 
/*! Is a setter function. A toggle - initiate an abort of the running class.
/*!  A toggle - initiate an abort of the running class.
*/
	void aborted(QString tableName, int fetchCnt,int insertCnt, int updateCnt);
//! void updateStatusFetched 
/*! Is a Qt Signal - the signal sends the parameterized values after each row is fetched.
\param tableName is a QString argument.
\param rowsFetched is a int argument.
*/
	void updateStatusFetched(QString profileName, QString tableName, int rowsFetched, int rowsInserted, int rowsUpdated);
 
private:
//! A private variable.
/*!
tableName := the table that will be processed by this class.
*/
	QString		tableName;
//! A private variable.
/*!
bIsAbort := the Abort flag that will be checked during the execution of this class. The default is false.
*/
	bool	bIsAbort=false;
//! A private variable.
/*!
	rowsFetched := the rowsFetch variable - a simple counter which is incremented after each row is successfully fetched. The default is 0.
*/
	int	rowsFetched = 0;
/*!
rowsFetched := the rowsInserted variable - a simple counter which is incremented after each row is successfully inserted. The default is 0.
*/
	int	rowsInserted = 0;
	int	rowsUpdated = 0;
	int	commitInterval=1000; // Rate at which SQLTransaction are committed

// Rate at which the object notifies the parent class
// the object has processed n rows.
 
	int	updateInterval=1000; 
	SQLINTEGER	lenAary = 0;
	SQLINTEGER	IndPtrArray = 0; 
/*!
hStmt_Insert, The ODBC Statement Handle for the Insert.
*/
	SQLHANDLE	hStmt_Insert; 
/*!
hStmt_Fetch, The ODBC Statement Handle for the Fetch.
*/
	SQLHANDLE	hStmt_Fetch;
/*!
hStmt_Update, The ODBC Statement Handle for the Update.
*/
	SQLHANDLE	hStmt_Update; 
/*!
numRowsFetched, The number of rows fetched.
*/
	SQLUINTEGER	numRowsFetched;
/*!
insertSql, The SQL statement used when preparing for row insertion.
*/
	QString	insertSql;
/*!
fetchSql, The SQL statement used when preparing for row selection.
*/
	QString	fetchSql;
/*!
updateSql, The SQL statement used when preparing for row updates.
*/
	QString	updateSql;
	SQLHDBC	hDbc_source;
	SQLHDBC	hDbc_target;
	SQLHENV	hEnv_Target;
	SQLHENV	hEnv_Source;
 
	QString	profileName;
	QString	m_lpszSourceDSN; 
	QString	m_lpszTargetDSN; 
	QString	m_lpszRepositoryDSN; 
	QString	m_OdbcAttributes; 
	bool bIsNetChange;
	bool	m_bIsOpen; 
	ReplicationOption m_ReplicationOption;
	DropOption  m_dropOption;
 
	bool prepare();
	void prepareTargetTable();
	bool bindColumn();
	bool bindParameter();
	void copyTable();
	void connect(connectionHandle connectionSource);

// FieldNames 
#pragma region Field Buffers TK_NOTREC
	QByteArray	DB_ID;
	QByteArray	NVTIMESTAMP;
	QByteArray	AREA;
	QByteArray	PAGE;
	QByteArray	LINE;
	QByteArray	TK_NOTDESC;
	QByteArray	TK_NOTCODE;
	QByteArray	TK_LIDLOT;
	SQLINTEGER	cbDB_ID;
	SQLINTEGER	cbNVTIMESTAMP;
	SQLINTEGER	cbAREA;
	SQLINTEGER	cbPAGE;
	SQLINTEGER	cbLINE;
	SQLINTEGER	cbTK_NOTDESC;
	SQLINTEGER	cbTK_NOTCODE;
	SQLINTEGER	cbTK_LIDLOT;
#pragma endregion Field Buffers TK_NOTREC

};
//!  TK_UPRTREC class. 
/*!
*   Executed by the Qt Threading system.
*/
class TK_UPRTREC : public QObject {
		Q_OBJECT 
 
 
public:
	TK_UPRTREC(QObject * parent = Q_NULLPTR );
	~TK_UPRTREC(); 
 
 
	 void setCommitInterval(int uCommitInterval) { commitInterval = uCommitInterval; }
	 void setUpdateInterval(int uUpdateInterval) { updateInterval = uUpdateInterval; }
	int rowsProcessed() { return rowsFetched; }
	void initOdbcAttributes(); 
	void initialize(); 
	QStringList m_OdbcAttributesList;
	QMap<int, nOdbcAttributesClass*> m_OdbcAttributes_Map;
//! void open taking two QString strings 
/*!
\param sourceDSN is a QString argument.
\param targetDSN is a  QString argument.
*/
	void close(); 
	void open(const QString sourceDSN, const QString targetDSN); 
	void createTable();
//! void setProfileName 
/*! Is a setter function. Accepts a single argument QString - denoting the ProfileName.
\param _profileName is a QString argument.
\sa profileName
*/
	void setProfileName(const QString _profileName) { profileName = _profileName; } 
//! A normal member taking one argument and returning an boolean value.
/*! Entry function for the class - all data synchronization operations are executed from the process function.
\param rowSSize an integer argument.
\param s a constant character pointer.
\return The success status of this synchronization operation.
*/
//! void setRepositoryString 
/*! Is a setter function. Accepts a single argument QString - denoting the DataSource Connection String of the eNVy SQL Repository.
\param _repoString is a QString argument.
\sa m_lpszRepositoryDSN
*/
	void setRepositoryString(const QString _repoString) { m_lpszRepositoryDSN = _repoString; } 
//! QString getTableName 
/*! Is a getter function which returns the table name that is processed by this class.
\sa tableName
*/
	bool process(int rowSSize); 
//! void setNetChange 
/*! Is a setter function. Toggles the data synchronization method from BulK_Copy to Net Change.
\sa bIsNetChange
*/
	QString			getTableName() {	return tableName;}
	void			setNetChange() { bIsNetChange = true; } 
//! void setDropOption 
/*! Is a setter function. Accepts a single argument DropOption - the method with which the table should be handled prior to Bulk_Copy is performed.
\param dropOption is a DropOption argument.
\sa DropOption
*/
	void			setDropOption(DropOption dropOption) { m_dropOption = dropOption;  }
//! void setOdbcAttributes 
/*! Is a setter function. Accepts a single argument as a QString.
/*!  ODBC Attributes are delimited by Comma
/*!  ODBC Attribute support is limited to Qt 5.9 ODBC Support
\param odbcAttr is a QString argument.
*/
	void			setOdbcAttributes(const QString odbcAttr) { m_OdbcAttributes = odbcAttr;  }
//! void setReplicationOption 
/*! Is a setter function. Accepts a single argument as a ReplicationOption. Three selection options are possible; Bulk_Copy, Net_Change, NotSet
/*!  ODBC Attributes are delimited by Comma
/*!  ODBC Attribute support is limited to Qt 5.9 ODBC Support
\param odbcAttr is a QString argument.
\sa ReplicationOption
*/
	void			 setReplicationOption(ReplicationOption xReplicationOption) {
		m_ReplicationOption = xReplicationOption; 
	}
public slots:
	void setAbortFlag(); 
	void run();
signals:
//! void setAbortFlag 
/*! Is a setter function. A toggle - initiate an abort of the running class.
/*!  A toggle - initiate an abort of the running class.
*/
	void aborted(QString tableName, int fetchCnt,int insertCnt, int updateCnt);
//! void updateStatusFetched 
/*! Is a Qt Signal - the signal sends the parameterized values after each row is fetched.
\param tableName is a QString argument.
\param rowsFetched is a int argument.
*/
	void updateStatusFetched(QString profileName, QString tableName, int rowsFetched, int rowsInserted, int rowsUpdated);
 
private:
//! A private variable.
/*!
tableName := the table that will be processed by this class.
*/
	QString		tableName;
//! A private variable.
/*!
bIsAbort := the Abort flag that will be checked during the execution of this class. The default is false.
*/
	bool	bIsAbort=false;
//! A private variable.
/*!
	rowsFetched := the rowsFetch variable - a simple counter which is incremented after each row is successfully fetched. The default is 0.
*/
	int	rowsFetched = 0;
/*!
rowsFetched := the rowsInserted variable - a simple counter which is incremented after each row is successfully inserted. The default is 0.
*/
	int	rowsInserted = 0;
	int	rowsUpdated = 0;
	int	commitInterval=1000; // Rate at which SQLTransaction are committed

// Rate at which the object notifies the parent class
// the object has processed n rows.
 
	int	updateInterval=1000; 
	SQLINTEGER	lenAary = 0;
	SQLINTEGER	IndPtrArray = 0; 
/*!
hStmt_Insert, The ODBC Statement Handle for the Insert.
*/
	SQLHANDLE	hStmt_Insert; 
/*!
hStmt_Fetch, The ODBC Statement Handle for the Fetch.
*/
	SQLHANDLE	hStmt_Fetch;
/*!
hStmt_Update, The ODBC Statement Handle for the Update.
*/
	SQLHANDLE	hStmt_Update; 
/*!
numRowsFetched, The number of rows fetched.
*/
	SQLUINTEGER	numRowsFetched;
/*!
insertSql, The SQL statement used when preparing for row insertion.
*/
	QString	insertSql;
/*!
fetchSql, The SQL statement used when preparing for row selection.
*/
	QString	fetchSql;
/*!
updateSql, The SQL statement used when preparing for row updates.
*/
	QString	updateSql;
	SQLHDBC	hDbc_source;
	SQLHDBC	hDbc_target;
	SQLHENV	hEnv_Target;
	SQLHENV	hEnv_Source;
 
	QString	profileName;
	QString	m_lpszSourceDSN; 
	QString	m_lpszTargetDSN; 
	QString	m_lpszRepositoryDSN; 
	QString	m_OdbcAttributes; 
	bool bIsNetChange;
	bool	m_bIsOpen; 
	ReplicationOption m_ReplicationOption;
	DropOption  m_dropOption;
 
	bool prepare();
	void prepareTargetTable();
	bool bindColumn();
	bool bindParameter();
	void copyTable();
	void connect(connectionHandle connectionSource);

// FieldNames 
#pragma region Field Buffers TK_UPRTREC
	QByteArray	DB_ID;
	QByteArray	NVTIMESTAMP;
	QByteArray	AREA;
	QByteArray	PAGE;
	QByteArray	LINE;
	QByteArray	TK_UPRTNO;
	SQLINTEGER	cbDB_ID;
	SQLINTEGER	cbNVTIMESTAMP;
	SQLINTEGER	cbAREA;
	SQLINTEGER	cbPAGE;
	SQLINTEGER	cbLINE;
	SQLINTEGER	cbTK_UPRTNO;
#pragma endregion Field Buffers TK_UPRTREC

};
//!  TK_UPRTULSTSET class. 
/*!
*   Executed by the Qt Threading system.
*/
class TK_UPRTULSTSET : public QObject {
		Q_OBJECT 
 
 
public:
	TK_UPRTULSTSET(QObject * parent = Q_NULLPTR );
	~TK_UPRTULSTSET(); 
 
 
	 void setCommitInterval(int uCommitInterval) { commitInterval = uCommitInterval; }
	 void setUpdateInterval(int uUpdateInterval) { updateInterval = uUpdateInterval; }
	int rowsProcessed() { return rowsFetched; }
	void initOdbcAttributes(); 
	void initialize(); 
	QStringList m_OdbcAttributesList;
	QMap<int, nOdbcAttributesClass*> m_OdbcAttributes_Map;
//! void open taking two QString strings 
/*!
\param sourceDSN is a QString argument.
\param targetDSN is a  QString argument.
*/
	void close(); 
	void open(const QString sourceDSN, const QString targetDSN); 
	void createTable();
//! void setProfileName 
/*! Is a setter function. Accepts a single argument QString - denoting the ProfileName.
\param _profileName is a QString argument.
\sa profileName
*/
	void setProfileName(const QString _profileName) { profileName = _profileName; } 
//! A normal member taking one argument and returning an boolean value.
/*! Entry function for the class - all data synchronization operations are executed from the process function.
\param rowSSize an integer argument.
\param s a constant character pointer.
\return The success status of this synchronization operation.
*/
//! void setRepositoryString 
/*! Is a setter function. Accepts a single argument QString - denoting the DataSource Connection String of the eNVy SQL Repository.
\param _repoString is a QString argument.
\sa m_lpszRepositoryDSN
*/
	void setRepositoryString(const QString _repoString) { m_lpszRepositoryDSN = _repoString; } 
//! QString getTableName 
/*! Is a getter function which returns the table name that is processed by this class.
\sa tableName
*/
	bool process(int rowSSize); 
//! void setNetChange 
/*! Is a setter function. Toggles the data synchronization method from BulK_Copy to Net Change.
\sa bIsNetChange
*/
	QString			getTableName() {	return tableName;}
	void			setNetChange() { bIsNetChange = true; } 
//! void setDropOption 
/*! Is a setter function. Accepts a single argument DropOption - the method with which the table should be handled prior to Bulk_Copy is performed.
\param dropOption is a DropOption argument.
\sa DropOption
*/
	void			setDropOption(DropOption dropOption) { m_dropOption = dropOption;  }
//! void setOdbcAttributes 
/*! Is a setter function. Accepts a single argument as a QString.
/*!  ODBC Attributes are delimited by Comma
/*!  ODBC Attribute support is limited to Qt 5.9 ODBC Support
\param odbcAttr is a QString argument.
*/
	void			setOdbcAttributes(const QString odbcAttr) { m_OdbcAttributes = odbcAttr;  }
//! void setReplicationOption 
/*! Is a setter function. Accepts a single argument as a ReplicationOption. Three selection options are possible; Bulk_Copy, Net_Change, NotSet
/*!  ODBC Attributes are delimited by Comma
/*!  ODBC Attribute support is limited to Qt 5.9 ODBC Support
\param odbcAttr is a QString argument.
\sa ReplicationOption
*/
	void			 setReplicationOption(ReplicationOption xReplicationOption) {
		m_ReplicationOption = xReplicationOption; 
	}
public slots:
	void setAbortFlag(); 
	void run();
signals:
//! void setAbortFlag 
/*! Is a setter function. A toggle - initiate an abort of the running class.
/*!  A toggle - initiate an abort of the running class.
*/
	void aborted(QString tableName, int fetchCnt,int insertCnt, int updateCnt);
//! void updateStatusFetched 
/*! Is a Qt Signal - the signal sends the parameterized values after each row is fetched.
\param tableName is a QString argument.
\param rowsFetched is a int argument.
*/
	void updateStatusFetched(QString profileName, QString tableName, int rowsFetched, int rowsInserted, int rowsUpdated);
 
private:
//! A private variable.
/*!
tableName := the table that will be processed by this class.
*/
	QString		tableName;
//! A private variable.
/*!
bIsAbort := the Abort flag that will be checked during the execution of this class. The default is false.
*/
	bool	bIsAbort=false;
//! A private variable.
/*!
	rowsFetched := the rowsFetch variable - a simple counter which is incremented after each row is successfully fetched. The default is 0.
*/
	int	rowsFetched = 0;
/*!
rowsFetched := the rowsInserted variable - a simple counter which is incremented after each row is successfully inserted. The default is 0.
*/
	int	rowsInserted = 0;
	int	rowsUpdated = 0;
	int	commitInterval=1000; // Rate at which SQLTransaction are committed

// Rate at which the object notifies the parent class
// the object has processed n rows.
 
	int	updateInterval=1000; 
	SQLINTEGER	lenAary = 0;
	SQLINTEGER	IndPtrArray = 0; 
/*!
hStmt_Insert, The ODBC Statement Handle for the Insert.
*/
	SQLHANDLE	hStmt_Insert; 
/*!
hStmt_Fetch, The ODBC Statement Handle for the Fetch.
*/
	SQLHANDLE	hStmt_Fetch;
/*!
hStmt_Update, The ODBC Statement Handle for the Update.
*/
	SQLHANDLE	hStmt_Update; 
/*!
numRowsFetched, The number of rows fetched.
*/
	SQLUINTEGER	numRowsFetched;
/*!
insertSql, The SQL statement used when preparing for row insertion.
*/
	QString	insertSql;
/*!
fetchSql, The SQL statement used when preparing for row selection.
*/
	QString	fetchSql;
/*!
updateSql, The SQL statement used when preparing for row updates.
*/
	QString	updateSql;
	SQLHDBC	hDbc_source;
	SQLHDBC	hDbc_target;
	SQLHENV	hEnv_Target;
	SQLHENV	hEnv_Source;
 
	QString	profileName;
	QString	m_lpszSourceDSN; 
	QString	m_lpszTargetDSN; 
	QString	m_lpszRepositoryDSN; 
	QString	m_OdbcAttributes; 
	bool bIsNetChange;
	bool	m_bIsOpen; 
	ReplicationOption m_ReplicationOption;
	DropOption  m_dropOption;
 
	bool prepare();
	void prepareTargetTable();
	bool bindColumn();
	bool bindParameter();
	void copyTable();
	void connect(connectionHandle connectionSource);

// FieldNames 
#pragma region Field Buffers TK_UPRTULSTSET
	QByteArray	DB_ID;
	QByteArray	NVTIMESTAMP;
	QByteArray	OAREA;
	QByteArray	OPAGE;
	QByteArray	OLINE;
	QByteArray	MAREA;
	QByteArray	MPAGE;
	QByteArray	MLINE;
	SQLINTEGER	cbDB_ID;
	SQLINTEGER	cbNVTIMESTAMP;
	SQLINTEGER	cbOAREA;
	SQLINTEGER	cbOPAGE;
	SQLINTEGER	cbOLINE;
	SQLINTEGER	cbMAREA;
	SQLINTEGER	cbMPAGE;
	SQLINTEGER	cbMLINE;
#pragma endregion Field Buffers TK_UPRTULSTSET

};
//!  TK_LIDREC class. 
/*!
*   Executed by the Qt Threading system.
*/
class TK_LIDREC : public QObject {
		Q_OBJECT 
 
 
public:
	TK_LIDREC(QObject * parent = Q_NULLPTR );
	~TK_LIDREC(); 
 
 
	 void setCommitInterval(int uCommitInterval) { commitInterval = uCommitInterval; }
	 void setUpdateInterval(int uUpdateInterval) { updateInterval = uUpdateInterval; }
	int rowsProcessed() { return rowsFetched; }
	void initOdbcAttributes(); 
	void initialize(); 
	QStringList m_OdbcAttributesList;
	QMap<int, nOdbcAttributesClass*> m_OdbcAttributes_Map;
//! void open taking two QString strings 
/*!
\param sourceDSN is a QString argument.
\param targetDSN is a  QString argument.
*/
	void close(); 
	void open(const QString sourceDSN, const QString targetDSN); 
	void createTable();
//! void setProfileName 
/*! Is a setter function. Accepts a single argument QString - denoting the ProfileName.
\param _profileName is a QString argument.
\sa profileName
*/
	void setProfileName(const QString _profileName) { profileName = _profileName; } 
//! A normal member taking one argument and returning an boolean value.
/*! Entry function for the class - all data synchronization operations are executed from the process function.
\param rowSSize an integer argument.
\param s a constant character pointer.
\return The success status of this synchronization operation.
*/
//! void setRepositoryString 
/*! Is a setter function. Accepts a single argument QString - denoting the DataSource Connection String of the eNVy SQL Repository.
\param _repoString is a QString argument.
\sa m_lpszRepositoryDSN
*/
	void setRepositoryString(const QString _repoString) { m_lpszRepositoryDSN = _repoString; } 
//! QString getTableName 
/*! Is a getter function which returns the table name that is processed by this class.
\sa tableName
*/
	bool process(int rowSSize); 
//! void setNetChange 
/*! Is a setter function. Toggles the data synchronization method from BulK_Copy to Net Change.
\sa bIsNetChange
*/
	QString			getTableName() {	return tableName;}
	void			setNetChange() { bIsNetChange = true; } 
//! void setDropOption 
/*! Is a setter function. Accepts a single argument DropOption - the method with which the table should be handled prior to Bulk_Copy is performed.
\param dropOption is a DropOption argument.
\sa DropOption
*/
	void			setDropOption(DropOption dropOption) { m_dropOption = dropOption;  }
//! void setOdbcAttributes 
/*! Is a setter function. Accepts a single argument as a QString.
/*!  ODBC Attributes are delimited by Comma
/*!  ODBC Attribute support is limited to Qt 5.9 ODBC Support
\param odbcAttr is a QString argument.
*/
	void			setOdbcAttributes(const QString odbcAttr) { m_OdbcAttributes = odbcAttr;  }
//! void setReplicationOption 
/*! Is a setter function. Accepts a single argument as a ReplicationOption. Three selection options are possible; Bulk_Copy, Net_Change, NotSet
/*!  ODBC Attributes are delimited by Comma
/*!  ODBC Attribute support is limited to Qt 5.9 ODBC Support
\param odbcAttr is a QString argument.
\sa ReplicationOption
*/
	void			 setReplicationOption(ReplicationOption xReplicationOption) {
		m_ReplicationOption = xReplicationOption; 
	}
public slots:
	void setAbortFlag(); 
	void run();
signals:
//! void setAbortFlag 
/*! Is a setter function. A toggle - initiate an abort of the running class.
/*!  A toggle - initiate an abort of the running class.
*/
	void aborted(QString tableName, int fetchCnt,int insertCnt, int updateCnt);
//! void updateStatusFetched 
/*! Is a Qt Signal - the signal sends the parameterized values after each row is fetched.
\param tableName is a QString argument.
\param rowsFetched is a int argument.
*/
	void updateStatusFetched(QString profileName, QString tableName, int rowsFetched, int rowsInserted, int rowsUpdated);
 
private:
//! A private variable.
/*!
tableName := the table that will be processed by this class.
*/
	QString		tableName;
//! A private variable.
/*!
bIsAbort := the Abort flag that will be checked during the execution of this class. The default is false.
*/
	bool	bIsAbort=false;
//! A private variable.
/*!
	rowsFetched := the rowsFetch variable - a simple counter which is incremented after each row is successfully fetched. The default is 0.
*/
	int	rowsFetched = 0;
/*!
rowsFetched := the rowsInserted variable - a simple counter which is incremented after each row is successfully inserted. The default is 0.
*/
	int	rowsInserted = 0;
	int	rowsUpdated = 0;
	int	commitInterval=1000; // Rate at which SQLTransaction are committed

// Rate at which the object notifies the parent class
// the object has processed n rows.
 
	int	updateInterval=1000; 
	SQLINTEGER	lenAary = 0;
	SQLINTEGER	IndPtrArray = 0; 
/*!
hStmt_Insert, The ODBC Statement Handle for the Insert.
*/
	SQLHANDLE	hStmt_Insert; 
/*!
hStmt_Fetch, The ODBC Statement Handle for the Fetch.
*/
	SQLHANDLE	hStmt_Fetch;
/*!
hStmt_Update, The ODBC Statement Handle for the Update.
*/
	SQLHANDLE	hStmt_Update; 
/*!
numRowsFetched, The number of rows fetched.
*/
	SQLUINTEGER	numRowsFetched;
/*!
insertSql, The SQL statement used when preparing for row insertion.
*/
	QString	insertSql;
/*!
fetchSql, The SQL statement used when preparing for row selection.
*/
	QString	fetchSql;
/*!
updateSql, The SQL statement used when preparing for row updates.
*/
	QString	updateSql;
	SQLHDBC	hDbc_source;
	SQLHDBC	hDbc_target;
	SQLHENV	hEnv_Target;
	SQLHENV	hEnv_Source;
 
	QString	profileName;
	QString	m_lpszSourceDSN; 
	QString	m_lpszTargetDSN; 
	QString	m_lpszRepositoryDSN; 
	QString	m_OdbcAttributes; 
	bool bIsNetChange;
	bool	m_bIsOpen; 
	ReplicationOption m_ReplicationOption;
	DropOption  m_dropOption;
 
	bool prepare();
	void prepareTargetTable();
	bool bindColumn();
	bool bindParameter();
	void copyTable();
	void connect(connectionHandle connectionSource);

// FieldNames 
#pragma region Field Buffers TK_LIDREC
	QByteArray	DB_ID;
	QByteArray	NVTIMESTAMP;
	QByteArray	AREA;
	QByteArray	PAGE;
	QByteArray	LINE;
	QByteArray	TK_LIDLOT;
	QByteArray	TK_LIDPRT;
	QByteArray	TK_LIDLOTDESC;
	QByteArray	TK_LIDPRTDESC;
	QByteArray	TK_LIDPRTREV;
	QByteArray	TK_LIDPRTSC;
	QByteArray	TK_LIDPRTUOM;
	QByteArray	TK_LIDACCCODE;
	QByteArray	TK_LIDACCTYPE;
	QByteArray	TK_LIDEXPDAT;
	QByteArray	QTY;
	QByteArray	TK_LIDISSQTY;
	QByteArray	TK_LIDSCRPQTY;
	QByteArray	TK_LIDRTVQTY;
	QByteArray	TK_LIDCRDAT;
	QByteArray	TK_LIDISSDAT;
	QByteArray	DAT;
	QByteArray	TK_LIDARCDAT;
	QByteArray	TK_LIDARCISSQTY;
	QByteArray	TK_LIDARCRECQTY;
	QByteArray	TK_LIDUSRFLD1;
	QByteArray	TK_LIDUSRFLD2;
	QByteArray	TK_LIDUSRFLD3;
	QByteArray	TK_LIDUSRFLD4;
	QByteArray	TK_LIDARCCODDESC;
	QByteArray	TK_LIDPOT;
	QByteArray	TK_LIDMUQ;
	QByteArray	TK_LIDLOTUOM;
	QByteArray	TK_LIDACTCOD1;
	QByteArray	TK_LIDACTDAT1;
	QByteArray	TK_LIDACTCOD2;
	QByteArray	TK_LIDACTDAT2;
	QByteArray	TK_LOTNO;
	QByteArray	TK_PRTNO;
	SQLINTEGER	cbDB_ID;
	SQLINTEGER	cbNVTIMESTAMP;
	SQLINTEGER	cbAREA;
	SQLINTEGER	cbPAGE;
	SQLINTEGER	cbLINE;
	SQLINTEGER	cbTK_LIDLOT;
	SQLINTEGER	cbTK_LIDPRT;
	SQLINTEGER	cbTK_LIDLOTDESC;
	SQLINTEGER	cbTK_LIDPRTDESC;
	SQLINTEGER	cbTK_LIDPRTREV;
	SQLINTEGER	cbTK_LIDPRTSC;
	SQLINTEGER	cbTK_LIDPRTUOM;
	SQLINTEGER	cbTK_LIDACCCODE;
	SQLINTEGER	cbTK_LIDACCTYPE;
	SQLINTEGER	cbTK_LIDEXPDAT;
	SQLINTEGER	cbQTY;
	SQLINTEGER	cbTK_LIDISSQTY;
	SQLINTEGER	cbTK_LIDSCRPQTY;
	SQLINTEGER	cbTK_LIDRTVQTY;
	SQLINTEGER	cbTK_LIDCRDAT;
	SQLINTEGER	cbTK_LIDISSDAT;
	SQLINTEGER	cbDAT;
	SQLINTEGER	cbTK_LIDARCDAT;
	SQLINTEGER	cbTK_LIDARCISSQTY;
	SQLINTEGER	cbTK_LIDARCRECQTY;
	SQLINTEGER	cbTK_LIDUSRFLD1;
	SQLINTEGER	cbTK_LIDUSRFLD2;
	SQLINTEGER	cbTK_LIDUSRFLD3;
	SQLINTEGER	cbTK_LIDUSRFLD4;
	SQLINTEGER	cbTK_LIDARCCODDESC;
	SQLINTEGER	cbTK_LIDPOT;
	SQLINTEGER	cbTK_LIDMUQ;
	SQLINTEGER	cbTK_LIDLOTUOM;
	SQLINTEGER	cbTK_LIDACTCOD1;
	SQLINTEGER	cbTK_LIDACTDAT1;
	SQLINTEGER	cbTK_LIDACTCOD2;
	SQLINTEGER	cbTK_LIDACTDAT2;
	SQLINTEGER	cbTK_LOTNO;
	SQLINTEGER	cbTK_PRTNO;
#pragma endregion Field Buffers TK_LIDREC

};
//!  TK_LTPBOMSET class. 
/*!
*   Executed by the Qt Threading system.
*/
class TK_LTPBOMSET : public QObject {
		Q_OBJECT 
 
 
public:
	TK_LTPBOMSET(QObject * parent = Q_NULLPTR );
	~TK_LTPBOMSET(); 
 
 
	 void setCommitInterval(int uCommitInterval) { commitInterval = uCommitInterval; }
	 void setUpdateInterval(int uUpdateInterval) { updateInterval = uUpdateInterval; }
	int rowsProcessed() { return rowsFetched; }
	void initOdbcAttributes(); 
	void initialize(); 
	QStringList m_OdbcAttributesList;
	QMap<int, nOdbcAttributesClass*> m_OdbcAttributes_Map;
//! void open taking two QString strings 
/*!
\param sourceDSN is a QString argument.
\param targetDSN is a  QString argument.
*/
	void close(); 
	void open(const QString sourceDSN, const QString targetDSN); 
	void createTable();
//! void setProfileName 
/*! Is a setter function. Accepts a single argument QString - denoting the ProfileName.
\param _profileName is a QString argument.
\sa profileName
*/
	void setProfileName(const QString _profileName) { profileName = _profileName; } 
//! A normal member taking one argument and returning an boolean value.
/*! Entry function for the class - all data synchronization operations are executed from the process function.
\param rowSSize an integer argument.
\param s a constant character pointer.
\return The success status of this synchronization operation.
*/
//! void setRepositoryString 
/*! Is a setter function. Accepts a single argument QString - denoting the DataSource Connection String of the eNVy SQL Repository.
\param _repoString is a QString argument.
\sa m_lpszRepositoryDSN
*/
	void setRepositoryString(const QString _repoString) { m_lpszRepositoryDSN = _repoString; } 
//! QString getTableName 
/*! Is a getter function which returns the table name that is processed by this class.
\sa tableName
*/
	bool process(int rowSSize); 
//! void setNetChange 
/*! Is a setter function. Toggles the data synchronization method from BulK_Copy to Net Change.
\sa bIsNetChange
*/
	QString			getTableName() {	return tableName;}
	void			setNetChange() { bIsNetChange = true; } 
//! void setDropOption 
/*! Is a setter function. Accepts a single argument DropOption - the method with which the table should be handled prior to Bulk_Copy is performed.
\param dropOption is a DropOption argument.
\sa DropOption
*/
	void			setDropOption(DropOption dropOption) { m_dropOption = dropOption;  }
//! void setOdbcAttributes 
/*! Is a setter function. Accepts a single argument as a QString.
/*!  ODBC Attributes are delimited by Comma
/*!  ODBC Attribute support is limited to Qt 5.9 ODBC Support
\param odbcAttr is a QString argument.
*/
	void			setOdbcAttributes(const QString odbcAttr) { m_OdbcAttributes = odbcAttr;  }
//! void setReplicationOption 
/*! Is a setter function. Accepts a single argument as a ReplicationOption. Three selection options are possible; Bulk_Copy, Net_Change, NotSet
/*!  ODBC Attributes are delimited by Comma
/*!  ODBC Attribute support is limited to Qt 5.9 ODBC Support
\param odbcAttr is a QString argument.
\sa ReplicationOption
*/
	void			 setReplicationOption(ReplicationOption xReplicationOption) {
		m_ReplicationOption = xReplicationOption; 
	}
public slots:
	void setAbortFlag(); 
	void run();
signals:
//! void setAbortFlag 
/*! Is a setter function. A toggle - initiate an abort of the running class.
/*!  A toggle - initiate an abort of the running class.
*/
	void aborted(QString tableName, int fetchCnt,int insertCnt, int updateCnt);
//! void updateStatusFetched 
/*! Is a Qt Signal - the signal sends the parameterized values after each row is fetched.
\param tableName is a QString argument.
\param rowsFetched is a int argument.
*/
	void updateStatusFetched(QString profileName, QString tableName, int rowsFetched, int rowsInserted, int rowsUpdated);
 
private:
//! A private variable.
/*!
tableName := the table that will be processed by this class.
*/
	QString		tableName;
//! A private variable.
/*!
bIsAbort := the Abort flag that will be checked during the execution of this class. The default is false.
*/
	bool	bIsAbort=false;
//! A private variable.
/*!
	rowsFetched := the rowsFetch variable - a simple counter which is incremented after each row is successfully fetched. The default is 0.
*/
	int	rowsFetched = 0;
/*!
rowsFetched := the rowsInserted variable - a simple counter which is incremented after each row is successfully inserted. The default is 0.
*/
	int	rowsInserted = 0;
	int	rowsUpdated = 0;
	int	commitInterval=1000; // Rate at which SQLTransaction are committed

// Rate at which the object notifies the parent class
// the object has processed n rows.
 
	int	updateInterval=1000; 
	SQLINTEGER	lenAary = 0;
	SQLINTEGER	IndPtrArray = 0; 
/*!
hStmt_Insert, The ODBC Statement Handle for the Insert.
*/
	SQLHANDLE	hStmt_Insert; 
/*!
hStmt_Fetch, The ODBC Statement Handle for the Fetch.
*/
	SQLHANDLE	hStmt_Fetch;
/*!
hStmt_Update, The ODBC Statement Handle for the Update.
*/
	SQLHANDLE	hStmt_Update; 
/*!
numRowsFetched, The number of rows fetched.
*/
	SQLUINTEGER	numRowsFetched;
/*!
insertSql, The SQL statement used when preparing for row insertion.
*/
	QString	insertSql;
/*!
fetchSql, The SQL statement used when preparing for row selection.
*/
	QString	fetchSql;
/*!
updateSql, The SQL statement used when preparing for row updates.
*/
	QString	updateSql;
	SQLHDBC	hDbc_source;
	SQLHDBC	hDbc_target;
	SQLHENV	hEnv_Target;
	SQLHENV	hEnv_Source;
 
	QString	profileName;
	QString	m_lpszSourceDSN; 
	QString	m_lpszTargetDSN; 
	QString	m_lpszRepositoryDSN; 
	QString	m_OdbcAttributes; 
	bool bIsNetChange;
	bool	m_bIsOpen; 
	ReplicationOption m_ReplicationOption;
	DropOption  m_dropOption;
 
	bool prepare();
	void prepareTargetTable();
	bool bindColumn();
	bool bindParameter();
	void copyTable();
	void connect(connectionHandle connectionSource);

// FieldNames 
#pragma region Field Buffers TK_LTPBOMSET
	QByteArray	DB_ID;
	QByteArray	NVTIMESTAMP;
	QByteArray	OAREA;
	QByteArray	OPAGE;
	QByteArray	OLINE;
	QByteArray	MAREA;
	QByteArray	MPAGE;
	QByteArray	MLINE;
	SQLINTEGER	cbDB_ID;
	SQLINTEGER	cbNVTIMESTAMP;
	SQLINTEGER	cbOAREA;
	SQLINTEGER	cbOPAGE;
	SQLINTEGER	cbOLINE;
	SQLINTEGER	cbMAREA;
	SQLINTEGER	cbMPAGE;
	SQLINTEGER	cbMLINE;
#pragma endregion Field Buffers TK_LTPBOMSET

};
//!  TK_LIDHSHSET class. 
/*!
*   Executed by the Qt Threading system.
*/
class TK_LIDHSHSET : public QObject {
		Q_OBJECT 
 
 
public:
	TK_LIDHSHSET(QObject * parent = Q_NULLPTR );
	~TK_LIDHSHSET(); 
 
 
	 void setCommitInterval(int uCommitInterval) { commitInterval = uCommitInterval; }
	 void setUpdateInterval(int uUpdateInterval) { updateInterval = uUpdateInterval; }
	int rowsProcessed() { return rowsFetched; }
	void initOdbcAttributes(); 
	void initialize(); 
	QStringList m_OdbcAttributesList;
	QMap<int, nOdbcAttributesClass*> m_OdbcAttributes_Map;
//! void open taking two QString strings 
/*!
\param sourceDSN is a QString argument.
\param targetDSN is a  QString argument.
*/
	void close(); 
	void open(const QString sourceDSN, const QString targetDSN); 
	void createTable();
//! void setProfileName 
/*! Is a setter function. Accepts a single argument QString - denoting the ProfileName.
\param _profileName is a QString argument.
\sa profileName
*/
	void setProfileName(const QString _profileName) { profileName = _profileName; } 
//! A normal member taking one argument and returning an boolean value.
/*! Entry function for the class - all data synchronization operations are executed from the process function.
\param rowSSize an integer argument.
\param s a constant character pointer.
\return The success status of this synchronization operation.
*/
//! void setRepositoryString 
/*! Is a setter function. Accepts a single argument QString - denoting the DataSource Connection String of the eNVy SQL Repository.
\param _repoString is a QString argument.
\sa m_lpszRepositoryDSN
*/
	void setRepositoryString(const QString _repoString) { m_lpszRepositoryDSN = _repoString; } 
//! QString getTableName 
/*! Is a getter function which returns the table name that is processed by this class.
\sa tableName
*/
	bool process(int rowSSize); 
//! void setNetChange 
/*! Is a setter function. Toggles the data synchronization method from BulK_Copy to Net Change.
\sa bIsNetChange
*/
	QString			getTableName() {	return tableName;}
	void			setNetChange() { bIsNetChange = true; } 
//! void setDropOption 
/*! Is a setter function. Accepts a single argument DropOption - the method with which the table should be handled prior to Bulk_Copy is performed.
\param dropOption is a DropOption argument.
\sa DropOption
*/
	void			setDropOption(DropOption dropOption) { m_dropOption = dropOption;  }
//! void setOdbcAttributes 
/*! Is a setter function. Accepts a single argument as a QString.
/*!  ODBC Attributes are delimited by Comma
/*!  ODBC Attribute support is limited to Qt 5.9 ODBC Support
\param odbcAttr is a QString argument.
*/
	void			setOdbcAttributes(const QString odbcAttr) { m_OdbcAttributes = odbcAttr;  }
//! void setReplicationOption 
/*! Is a setter function. Accepts a single argument as a ReplicationOption. Three selection options are possible; Bulk_Copy, Net_Change, NotSet
/*!  ODBC Attributes are delimited by Comma
/*!  ODBC Attribute support is limited to Qt 5.9 ODBC Support
\param odbcAttr is a QString argument.
\sa ReplicationOption
*/
	void			 setReplicationOption(ReplicationOption xReplicationOption) {
		m_ReplicationOption = xReplicationOption; 
	}
public slots:
	void setAbortFlag(); 
	void run();
signals:
//! void setAbortFlag 
/*! Is a setter function. A toggle - initiate an abort of the running class.
/*!  A toggle - initiate an abort of the running class.
*/
	void aborted(QString tableName, int fetchCnt,int insertCnt, int updateCnt);
//! void updateStatusFetched 
/*! Is a Qt Signal - the signal sends the parameterized values after each row is fetched.
\param tableName is a QString argument.
\param rowsFetched is a int argument.
*/
	void updateStatusFetched(QString profileName, QString tableName, int rowsFetched, int rowsInserted, int rowsUpdated);
 
private:
//! A private variable.
/*!
tableName := the table that will be processed by this class.
*/
	QString		tableName;
//! A private variable.
/*!
bIsAbort := the Abort flag that will be checked during the execution of this class. The default is false.
*/
	bool	bIsAbort=false;
//! A private variable.
/*!
	rowsFetched := the rowsFetch variable - a simple counter which is incremented after each row is successfully fetched. The default is 0.
*/
	int	rowsFetched = 0;
/*!
rowsFetched := the rowsInserted variable - a simple counter which is incremented after each row is successfully inserted. The default is 0.
*/
	int	rowsInserted = 0;
	int	rowsUpdated = 0;
	int	commitInterval=1000; // Rate at which SQLTransaction are committed

// Rate at which the object notifies the parent class
// the object has processed n rows.
 
	int	updateInterval=1000; 
	SQLINTEGER	lenAary = 0;
	SQLINTEGER	IndPtrArray = 0; 
/*!
hStmt_Insert, The ODBC Statement Handle for the Insert.
*/
	SQLHANDLE	hStmt_Insert; 
/*!
hStmt_Fetch, The ODBC Statement Handle for the Fetch.
*/
	SQLHANDLE	hStmt_Fetch;
/*!
hStmt_Update, The ODBC Statement Handle for the Update.
*/
	SQLHANDLE	hStmt_Update; 
/*!
numRowsFetched, The number of rows fetched.
*/
	SQLUINTEGER	numRowsFetched;
/*!
insertSql, The SQL statement used when preparing for row insertion.
*/
	QString	insertSql;
/*!
fetchSql, The SQL statement used when preparing for row selection.
*/
	QString	fetchSql;
/*!
updateSql, The SQL statement used when preparing for row updates.
*/
	QString	updateSql;
	SQLHDBC	hDbc_source;
	SQLHDBC	hDbc_target;
	SQLHENV	hEnv_Target;
	SQLHENV	hEnv_Source;
 
	QString	profileName;
	QString	m_lpszSourceDSN; 
	QString	m_lpszTargetDSN; 
	QString	m_lpszRepositoryDSN; 
	QString	m_OdbcAttributes; 
	bool bIsNetChange;
	bool	m_bIsOpen; 
	ReplicationOption m_ReplicationOption;
	DropOption  m_dropOption;
 
	bool prepare();
	void prepareTargetTable();
	bool bindColumn();
	bool bindParameter();
	void copyTable();
	void connect(connectionHandle connectionSource);

// FieldNames 
#pragma region Field Buffers TK_LIDHSHSET
	QByteArray	DB_ID;
	QByteArray	NVTIMESTAMP;
	QByteArray	OAREA;
	QByteArray	OPAGE;
	QByteArray	OLINE;
	QByteArray	MAREA;
	QByteArray	MPAGE;
	QByteArray	MLINE;
	SQLINTEGER	cbDB_ID;
	SQLINTEGER	cbNVTIMESTAMP;
	SQLINTEGER	cbOAREA;
	SQLINTEGER	cbOPAGE;
	SQLINTEGER	cbOLINE;
	SQLINTEGER	cbMAREA;
	SQLINTEGER	cbMPAGE;
	SQLINTEGER	cbMLINE;
#pragma endregion Field Buffers TK_LIDHSHSET

};
//!  TK_LIDLTPSET class. 
/*!
*   Executed by the Qt Threading system.
*/
class TK_LIDLTPSET : public QObject {
		Q_OBJECT 
 
 
public:
	TK_LIDLTPSET(QObject * parent = Q_NULLPTR );
	~TK_LIDLTPSET(); 
 
 
	 void setCommitInterval(int uCommitInterval) { commitInterval = uCommitInterval; }
	 void setUpdateInterval(int uUpdateInterval) { updateInterval = uUpdateInterval; }
	int rowsProcessed() { return rowsFetched; }
	void initOdbcAttributes(); 
	void initialize(); 
	QStringList m_OdbcAttributesList;
	QMap<int, nOdbcAttributesClass*> m_OdbcAttributes_Map;
//! void open taking two QString strings 
/*!
\param sourceDSN is a QString argument.
\param targetDSN is a  QString argument.
*/
	void close(); 
	void open(const QString sourceDSN, const QString targetDSN); 
	void createTable();
//! void setProfileName 
/*! Is a setter function. Accepts a single argument QString - denoting the ProfileName.
\param _profileName is a QString argument.
\sa profileName
*/
	void setProfileName(const QString _profileName) { profileName = _profileName; } 
//! A normal member taking one argument and returning an boolean value.
/*! Entry function for the class - all data synchronization operations are executed from the process function.
\param rowSSize an integer argument.
\param s a constant character pointer.
\return The success status of this synchronization operation.
*/
//! void setRepositoryString 
/*! Is a setter function. Accepts a single argument QString - denoting the DataSource Connection String of the eNVy SQL Repository.
\param _repoString is a QString argument.
\sa m_lpszRepositoryDSN
*/
	void setRepositoryString(const QString _repoString) { m_lpszRepositoryDSN = _repoString; } 
//! QString getTableName 
/*! Is a getter function which returns the table name that is processed by this class.
\sa tableName
*/
	bool process(int rowSSize); 
//! void setNetChange 
/*! Is a setter function. Toggles the data synchronization method from BulK_Copy to Net Change.
\sa bIsNetChange
*/
	QString			getTableName() {	return tableName;}
	void			setNetChange() { bIsNetChange = true; } 
//! void setDropOption 
/*! Is a setter function. Accepts a single argument DropOption - the method with which the table should be handled prior to Bulk_Copy is performed.
\param dropOption is a DropOption argument.
\sa DropOption
*/
	void			setDropOption(DropOption dropOption) { m_dropOption = dropOption;  }
//! void setOdbcAttributes 
/*! Is a setter function. Accepts a single argument as a QString.
/*!  ODBC Attributes are delimited by Comma
/*!  ODBC Attribute support is limited to Qt 5.9 ODBC Support
\param odbcAttr is a QString argument.
*/
	void			setOdbcAttributes(const QString odbcAttr) { m_OdbcAttributes = odbcAttr;  }
//! void setReplicationOption 
/*! Is a setter function. Accepts a single argument as a ReplicationOption. Three selection options are possible; Bulk_Copy, Net_Change, NotSet
/*!  ODBC Attributes are delimited by Comma
/*!  ODBC Attribute support is limited to Qt 5.9 ODBC Support
\param odbcAttr is a QString argument.
\sa ReplicationOption
*/
	void			 setReplicationOption(ReplicationOption xReplicationOption) {
		m_ReplicationOption = xReplicationOption; 
	}
public slots:
	void setAbortFlag(); 
	void run();
signals:
//! void setAbortFlag 
/*! Is a setter function. A toggle - initiate an abort of the running class.
/*!  A toggle - initiate an abort of the running class.
*/
	void aborted(QString tableName, int fetchCnt,int insertCnt, int updateCnt);
//! void updateStatusFetched 
/*! Is a Qt Signal - the signal sends the parameterized values after each row is fetched.
\param tableName is a QString argument.
\param rowsFetched is a int argument.
*/
	void updateStatusFetched(QString profileName, QString tableName, int rowsFetched, int rowsInserted, int rowsUpdated);
 
private:
//! A private variable.
/*!
tableName := the table that will be processed by this class.
*/
	QString		tableName;
//! A private variable.
/*!
bIsAbort := the Abort flag that will be checked during the execution of this class. The default is false.
*/
	bool	bIsAbort=false;
//! A private variable.
/*!
	rowsFetched := the rowsFetch variable - a simple counter which is incremented after each row is successfully fetched. The default is 0.
*/
	int	rowsFetched = 0;
/*!
rowsFetched := the rowsInserted variable - a simple counter which is incremented after each row is successfully inserted. The default is 0.
*/
	int	rowsInserted = 0;
	int	rowsUpdated = 0;
	int	commitInterval=1000; // Rate at which SQLTransaction are committed

// Rate at which the object notifies the parent class
// the object has processed n rows.
 
	int	updateInterval=1000; 
	SQLINTEGER	lenAary = 0;
	SQLINTEGER	IndPtrArray = 0; 
/*!
hStmt_Insert, The ODBC Statement Handle for the Insert.
*/
	SQLHANDLE	hStmt_Insert; 
/*!
hStmt_Fetch, The ODBC Statement Handle for the Fetch.
*/
	SQLHANDLE	hStmt_Fetch;
/*!
hStmt_Update, The ODBC Statement Handle for the Update.
*/
	SQLHANDLE	hStmt_Update; 
/*!
numRowsFetched, The number of rows fetched.
*/
	SQLUINTEGER	numRowsFetched;
/*!
insertSql, The SQL statement used when preparing for row insertion.
*/
	QString	insertSql;
/*!
fetchSql, The SQL statement used when preparing for row selection.
*/
	QString	fetchSql;
/*!
updateSql, The SQL statement used when preparing for row updates.
*/
	QString	updateSql;
	SQLHDBC	hDbc_source;
	SQLHDBC	hDbc_target;
	SQLHENV	hEnv_Target;
	SQLHENV	hEnv_Source;
 
	QString	profileName;
	QString	m_lpszSourceDSN; 
	QString	m_lpszTargetDSN; 
	QString	m_lpszRepositoryDSN; 
	QString	m_OdbcAttributes; 
	bool bIsNetChange;
	bool	m_bIsOpen; 
	ReplicationOption m_ReplicationOption;
	DropOption  m_dropOption;
 
	bool prepare();
	void prepareTargetTable();
	bool bindColumn();
	bool bindParameter();
	void copyTable();
	void connect(connectionHandle connectionSource);

// FieldNames 
#pragma region Field Buffers TK_LIDLTPSET
	QByteArray	DB_ID;
	QByteArray	NVTIMESTAMP;
	QByteArray	OAREA;
	QByteArray	OPAGE;
	QByteArray	OLINE;
	QByteArray	MAREA;
	QByteArray	MPAGE;
	QByteArray	MLINE;
	SQLINTEGER	cbDB_ID;
	SQLINTEGER	cbNVTIMESTAMP;
	SQLINTEGER	cbOAREA;
	SQLINTEGER	cbOPAGE;
	SQLINTEGER	cbOLINE;
	SQLINTEGER	cbMAREA;
	SQLINTEGER	cbMPAGE;
	SQLINTEGER	cbMLINE;
#pragma endregion Field Buffers TK_LIDLTPSET

};
//!  TK_INTREC class. 
/*!
*   Executed by the Qt Threading system.
*/
class TK_INTREC : public QObject {
		Q_OBJECT 
 
 
public:
	TK_INTREC(QObject * parent = Q_NULLPTR );
	~TK_INTREC(); 
 
 
	 void setCommitInterval(int uCommitInterval) { commitInterval = uCommitInterval; }
	 void setUpdateInterval(int uUpdateInterval) { updateInterval = uUpdateInterval; }
	int rowsProcessed() { return rowsFetched; }
	void initOdbcAttributes(); 
	void initialize(); 
	QStringList m_OdbcAttributesList;
	QMap<int, nOdbcAttributesClass*> m_OdbcAttributes_Map;
//! void open taking two QString strings 
/*!
\param sourceDSN is a QString argument.
\param targetDSN is a  QString argument.
*/
	void close(); 
	void open(const QString sourceDSN, const QString targetDSN); 
	void createTable();
//! void setProfileName 
/*! Is a setter function. Accepts a single argument QString - denoting the ProfileName.
\param _profileName is a QString argument.
\sa profileName
*/
	void setProfileName(const QString _profileName) { profileName = _profileName; } 
//! A normal member taking one argument and returning an boolean value.
/*! Entry function for the class - all data synchronization operations are executed from the process function.
\param rowSSize an integer argument.
\param s a constant character pointer.
\return The success status of this synchronization operation.
*/
//! void setRepositoryString 
/*! Is a setter function. Accepts a single argument QString - denoting the DataSource Connection String of the eNVy SQL Repository.
\param _repoString is a QString argument.
\sa m_lpszRepositoryDSN
*/
	void setRepositoryString(const QString _repoString) { m_lpszRepositoryDSN = _repoString; } 
//! QString getTableName 
/*! Is a getter function which returns the table name that is processed by this class.
\sa tableName
*/
	bool process(int rowSSize); 
//! void setNetChange 
/*! Is a setter function. Toggles the data synchronization method from BulK_Copy to Net Change.
\sa bIsNetChange
*/
	QString			getTableName() {	return tableName;}
	void			setNetChange() { bIsNetChange = true; } 
//! void setDropOption 
/*! Is a setter function. Accepts a single argument DropOption - the method with which the table should be handled prior to Bulk_Copy is performed.
\param dropOption is a DropOption argument.
\sa DropOption
*/
	void			setDropOption(DropOption dropOption) { m_dropOption = dropOption;  }
//! void setOdbcAttributes 
/*! Is a setter function. Accepts a single argument as a QString.
/*!  ODBC Attributes are delimited by Comma
/*!  ODBC Attribute support is limited to Qt 5.9 ODBC Support
\param odbcAttr is a QString argument.
*/
	void			setOdbcAttributes(const QString odbcAttr) { m_OdbcAttributes = odbcAttr;  }
//! void setReplicationOption 
/*! Is a setter function. Accepts a single argument as a ReplicationOption. Three selection options are possible; Bulk_Copy, Net_Change, NotSet
/*!  ODBC Attributes are delimited by Comma
/*!  ODBC Attribute support is limited to Qt 5.9 ODBC Support
\param odbcAttr is a QString argument.
\sa ReplicationOption
*/
	void			 setReplicationOption(ReplicationOption xReplicationOption) {
		m_ReplicationOption = xReplicationOption; 
	}
public slots:
	void setAbortFlag(); 
	void run();
signals:
//! void setAbortFlag 
/*! Is a setter function. A toggle - initiate an abort of the running class.
/*!  A toggle - initiate an abort of the running class.
*/
	void aborted(QString tableName, int fetchCnt,int insertCnt, int updateCnt);
//! void updateStatusFetched 
/*! Is a Qt Signal - the signal sends the parameterized values after each row is fetched.
\param tableName is a QString argument.
\param rowsFetched is a int argument.
*/
	void updateStatusFetched(QString profileName, QString tableName, int rowsFetched, int rowsInserted, int rowsUpdated);
 
private:
//! A private variable.
/*!
tableName := the table that will be processed by this class.
*/
	QString		tableName;
//! A private variable.
/*!
bIsAbort := the Abort flag that will be checked during the execution of this class. The default is false.
*/
	bool	bIsAbort=false;
//! A private variable.
/*!
	rowsFetched := the rowsFetch variable - a simple counter which is incremented after each row is successfully fetched. The default is 0.
*/
	int	rowsFetched = 0;
/*!
rowsFetched := the rowsInserted variable - a simple counter which is incremented after each row is successfully inserted. The default is 0.
*/
	int	rowsInserted = 0;
	int	rowsUpdated = 0;
	int	commitInterval=1000; // Rate at which SQLTransaction are committed

// Rate at which the object notifies the parent class
// the object has processed n rows.
 
	int	updateInterval=1000; 
	SQLINTEGER	lenAary = 0;
	SQLINTEGER	IndPtrArray = 0; 
/*!
hStmt_Insert, The ODBC Statement Handle for the Insert.
*/
	SQLHANDLE	hStmt_Insert; 
/*!
hStmt_Fetch, The ODBC Statement Handle for the Fetch.
*/
	SQLHANDLE	hStmt_Fetch;
/*!
hStmt_Update, The ODBC Statement Handle for the Update.
*/
	SQLHANDLE	hStmt_Update; 
/*!
numRowsFetched, The number of rows fetched.
*/
	SQLUINTEGER	numRowsFetched;
/*!
insertSql, The SQL statement used when preparing for row insertion.
*/
	QString	insertSql;
/*!
fetchSql, The SQL statement used when preparing for row selection.
*/
	QString	fetchSql;
/*!
updateSql, The SQL statement used when preparing for row updates.
*/
	QString	updateSql;
	SQLHDBC	hDbc_source;
	SQLHDBC	hDbc_target;
	SQLHENV	hEnv_Target;
	SQLHENV	hEnv_Source;
 
	QString	profileName;
	QString	m_lpszSourceDSN; 
	QString	m_lpszTargetDSN; 
	QString	m_lpszRepositoryDSN; 
	QString	m_OdbcAttributes; 
	bool bIsNetChange;
	bool	m_bIsOpen; 
	ReplicationOption m_ReplicationOption;
	DropOption  m_dropOption;
 
	bool prepare();
	void prepareTargetTable();
	bool bindColumn();
	bool bindParameter();
	void copyTable();
	void connect(connectionHandle connectionSource);

// FieldNames 
#pragma region Field Buffers TK_INTREC
	QByteArray	DB_ID;
	QByteArray	NVTIMESTAMP;
	QByteArray	AREA;
	QByteArray	PAGE;
	QByteArray	LINE;
	QByteArray	TK_INTFLOT;
	QByteArray	TK_INTFPRT;
	QByteArray	TK_INTFLOTTYPE;
	QByteArray	TK_INTFWAR;
	QByteArray	TK_INTFLOC;
	QByteArray	TK_INTFQTY;
	QByteArray	TK_INTTLOT;
	QByteArray	TK_INTTPRT;
	QByteArray	TK_INTTLOTTYPE;
	QByteArray	TK_INTTWAR;
	QByteArray	TK_INTTLOC;
	QByteArray	TK_INTTQTY;
	QByteArray	TK_INTDAT;
	QByteArray	TK_INTCMD;
	QByteArray	TK_INTORDNO;
	QByteArray	TK_INTSUBORDNO;
	QByteArray	TK_INTCODE;
	QByteArray	TK_INTNAME;
	QByteArray	TK_INTTIME;
	QByteArray	TK_INTPOLINE;
	QByteArray	TK_INTCHNSET;
	QByteArray	TK_INTTOHSHSET;
	QByteArray	TK_INTFMHSHSET;
	QByteArray	TK_INTPOSRTSET;
	QByteArray	TK_INTSOHSHSET;
	SQLINTEGER	cbDB_ID;
	SQLINTEGER	cbNVTIMESTAMP;
	SQLINTEGER	cbAREA;
	SQLINTEGER	cbPAGE;
	SQLINTEGER	cbLINE;
	SQLINTEGER	cbTK_INTFLOT;
	SQLINTEGER	cbTK_INTFPRT;
	SQLINTEGER	cbTK_INTFLOTTYPE;
	SQLINTEGER	cbTK_INTFWAR;
	SQLINTEGER	cbTK_INTFLOC;
	SQLINTEGER	cbTK_INTFQTY;
	SQLINTEGER	cbTK_INTTLOT;
	SQLINTEGER	cbTK_INTTPRT;
	SQLINTEGER	cbTK_INTTLOTTYPE;
	SQLINTEGER	cbTK_INTTWAR;
	SQLINTEGER	cbTK_INTTLOC;
	SQLINTEGER	cbTK_INTTQTY;
	SQLINTEGER	cbTK_INTDAT;
	SQLINTEGER	cbTK_INTCMD;
	SQLINTEGER	cbTK_INTORDNO;
	SQLINTEGER	cbTK_INTSUBORDNO;
	SQLINTEGER	cbTK_INTCODE;
	SQLINTEGER	cbTK_INTNAME;
	SQLINTEGER	cbTK_INTTIME;
	SQLINTEGER	cbTK_INTPOLINE;
	SQLINTEGER	cbTK_INTCHNSET;
	SQLINTEGER	cbTK_INTTOHSHSET;
	SQLINTEGER	cbTK_INTFMHSHSET;
	SQLINTEGER	cbTK_INTPOSRTSET;
	SQLINTEGER	cbTK_INTSOHSHSET;
#pragma endregion Field Buffers TK_INTREC

};
//!  TK_LTPCOMSET class. 
/*!
*   Executed by the Qt Threading system.
*/
class TK_LTPCOMSET : public QObject {
		Q_OBJECT 
 
 
public:
	TK_LTPCOMSET(QObject * parent = Q_NULLPTR );
	~TK_LTPCOMSET(); 
 
 
	 void setCommitInterval(int uCommitInterval) { commitInterval = uCommitInterval; }
	 void setUpdateInterval(int uUpdateInterval) { updateInterval = uUpdateInterval; }
	int rowsProcessed() { return rowsFetched; }
	void initOdbcAttributes(); 
	void initialize(); 
	QStringList m_OdbcAttributesList;
	QMap<int, nOdbcAttributesClass*> m_OdbcAttributes_Map;
//! void open taking two QString strings 
/*!
\param sourceDSN is a QString argument.
\param targetDSN is a  QString argument.
*/
	void close(); 
	void open(const QString sourceDSN, const QString targetDSN); 
	void createTable();
//! void setProfileName 
/*! Is a setter function. Accepts a single argument QString - denoting the ProfileName.
\param _profileName is a QString argument.
\sa profileName
*/
	void setProfileName(const QString _profileName) { profileName = _profileName; } 
//! A normal member taking one argument and returning an boolean value.
/*! Entry function for the class - all data synchronization operations are executed from the process function.
\param rowSSize an integer argument.
\param s a constant character pointer.
\return The success status of this synchronization operation.
*/
//! void setRepositoryString 
/*! Is a setter function. Accepts a single argument QString - denoting the DataSource Connection String of the eNVy SQL Repository.
\param _repoString is a QString argument.
\sa m_lpszRepositoryDSN
*/
	void setRepositoryString(const QString _repoString) { m_lpszRepositoryDSN = _repoString; } 
//! QString getTableName 
/*! Is a getter function which returns the table name that is processed by this class.
\sa tableName
*/
	bool process(int rowSSize); 
//! void setNetChange 
/*! Is a setter function. Toggles the data synchronization method from BulK_Copy to Net Change.
\sa bIsNetChange
*/
	QString			getTableName() {	return tableName;}
	void			setNetChange() { bIsNetChange = true; } 
//! void setDropOption 
/*! Is a setter function. Accepts a single argument DropOption - the method with which the table should be handled prior to Bulk_Copy is performed.
\param dropOption is a DropOption argument.
\sa DropOption
*/
	void			setDropOption(DropOption dropOption) { m_dropOption = dropOption;  }
//! void setOdbcAttributes 
/*! Is a setter function. Accepts a single argument as a QString.
/*!  ODBC Attributes are delimited by Comma
/*!  ODBC Attribute support is limited to Qt 5.9 ODBC Support
\param odbcAttr is a QString argument.
*/
	void			setOdbcAttributes(const QString odbcAttr) { m_OdbcAttributes = odbcAttr;  }
//! void setReplicationOption 
/*! Is a setter function. Accepts a single argument as a ReplicationOption. Three selection options are possible; Bulk_Copy, Net_Change, NotSet
/*!  ODBC Attributes are delimited by Comma
/*!  ODBC Attribute support is limited to Qt 5.9 ODBC Support
\param odbcAttr is a QString argument.
\sa ReplicationOption
*/
	void			 setReplicationOption(ReplicationOption xReplicationOption) {
		m_ReplicationOption = xReplicationOption; 
	}
public slots:
	void setAbortFlag(); 
	void run();
signals:
//! void setAbortFlag 
/*! Is a setter function. A toggle - initiate an abort of the running class.
/*!  A toggle - initiate an abort of the running class.
*/
	void aborted(QString tableName, int fetchCnt,int insertCnt, int updateCnt);
//! void updateStatusFetched 
/*! Is a Qt Signal - the signal sends the parameterized values after each row is fetched.
\param tableName is a QString argument.
\param rowsFetched is a int argument.
*/
	void updateStatusFetched(QString profileName, QString tableName, int rowsFetched, int rowsInserted, int rowsUpdated);
 
private:
//! A private variable.
/*!
tableName := the table that will be processed by this class.
*/
	QString		tableName;
//! A private variable.
/*!
bIsAbort := the Abort flag that will be checked during the execution of this class. The default is false.
*/
	bool	bIsAbort=false;
//! A private variable.
/*!
	rowsFetched := the rowsFetch variable - a simple counter which is incremented after each row is successfully fetched. The default is 0.
*/
	int	rowsFetched = 0;
/*!
rowsFetched := the rowsInserted variable - a simple counter which is incremented after each row is successfully inserted. The default is 0.
*/
	int	rowsInserted = 0;
	int	rowsUpdated = 0;
	int	commitInterval=1000; // Rate at which SQLTransaction are committed

// Rate at which the object notifies the parent class
// the object has processed n rows.
 
	int	updateInterval=1000; 
	SQLINTEGER	lenAary = 0;
	SQLINTEGER	IndPtrArray = 0; 
/*!
hStmt_Insert, The ODBC Statement Handle for the Insert.
*/
	SQLHANDLE	hStmt_Insert; 
/*!
hStmt_Fetch, The ODBC Statement Handle for the Fetch.
*/
	SQLHANDLE	hStmt_Fetch;
/*!
hStmt_Update, The ODBC Statement Handle for the Update.
*/
	SQLHANDLE	hStmt_Update; 
/*!
numRowsFetched, The number of rows fetched.
*/
	SQLUINTEGER	numRowsFetched;
/*!
insertSql, The SQL statement used when preparing for row insertion.
*/
	QString	insertSql;
/*!
fetchSql, The SQL statement used when preparing for row selection.
*/
	QString	fetchSql;
/*!
updateSql, The SQL statement used when preparing for row updates.
*/
	QString	updateSql;
	SQLHDBC	hDbc_source;
	SQLHDBC	hDbc_target;
	SQLHENV	hEnv_Target;
	SQLHENV	hEnv_Source;
 
	QString	profileName;
	QString	m_lpszSourceDSN; 
	QString	m_lpszTargetDSN; 
	QString	m_lpszRepositoryDSN; 
	QString	m_OdbcAttributes; 
	bool bIsNetChange;
	bool	m_bIsOpen; 
	ReplicationOption m_ReplicationOption;
	DropOption  m_dropOption;
 
	bool prepare();
	void prepareTargetTable();
	bool bindColumn();
	bool bindParameter();
	void copyTable();
	void connect(connectionHandle connectionSource);

// FieldNames 
#pragma region Field Buffers TK_LTPCOMSET
	QByteArray	DB_ID;
	QByteArray	NVTIMESTAMP;
	QByteArray	OAREA;
	QByteArray	OPAGE;
	QByteArray	OLINE;
	QByteArray	MAREA;
	QByteArray	MPAGE;
	QByteArray	MLINE;
	SQLINTEGER	cbDB_ID;
	SQLINTEGER	cbNVTIMESTAMP;
	SQLINTEGER	cbOAREA;
	SQLINTEGER	cbOPAGE;
	SQLINTEGER	cbOLINE;
	SQLINTEGER	cbMAREA;
	SQLINTEGER	cbMPAGE;
	SQLINTEGER	cbMLINE;
#pragma endregion Field Buffers TK_LTPCOMSET

};
//!  TK_HDRREC class. 
/*!
*   Executed by the Qt Threading system.
*/
class TK_HDRREC : public QObject {
		Q_OBJECT 
 
 
public:
	TK_HDRREC(QObject * parent = Q_NULLPTR );
	~TK_HDRREC(); 
 
 
	 void setCommitInterval(int uCommitInterval) { commitInterval = uCommitInterval; }
	 void setUpdateInterval(int uUpdateInterval) { updateInterval = uUpdateInterval; }
	int rowsProcessed() { return rowsFetched; }
	void initOdbcAttributes(); 
	void initialize(); 
	QStringList m_OdbcAttributesList;
	QMap<int, nOdbcAttributesClass*> m_OdbcAttributes_Map;
//! void open taking two QString strings 
/*!
\param sourceDSN is a QString argument.
\param targetDSN is a  QString argument.
*/
	void close(); 
	void open(const QString sourceDSN, const QString targetDSN); 
	void createTable();
//! void setProfileName 
/*! Is a setter function. Accepts a single argument QString - denoting the ProfileName.
\param _profileName is a QString argument.
\sa profileName
*/
	void setProfileName(const QString _profileName) { profileName = _profileName; } 
//! A normal member taking one argument and returning an boolean value.
/*! Entry function for the class - all data synchronization operations are executed from the process function.
\param rowSSize an integer argument.
\param s a constant character pointer.
\return The success status of this synchronization operation.
*/
//! void setRepositoryString 
/*! Is a setter function. Accepts a single argument QString - denoting the DataSource Connection String of the eNVy SQL Repository.
\param _repoString is a QString argument.
\sa m_lpszRepositoryDSN
*/
	void setRepositoryString(const QString _repoString) { m_lpszRepositoryDSN = _repoString; } 
//! QString getTableName 
/*! Is a getter function which returns the table name that is processed by this class.
\sa tableName
*/
	bool process(int rowSSize); 
//! void setNetChange 
/*! Is a setter function. Toggles the data synchronization method from BulK_Copy to Net Change.
\sa bIsNetChange
*/
	QString			getTableName() {	return tableName;}
	void			setNetChange() { bIsNetChange = true; } 
//! void setDropOption 
/*! Is a setter function. Accepts a single argument DropOption - the method with which the table should be handled prior to Bulk_Copy is performed.
\param dropOption is a DropOption argument.
\sa DropOption
*/
	void			setDropOption(DropOption dropOption) { m_dropOption = dropOption;  }
//! void setOdbcAttributes 
/*! Is a setter function. Accepts a single argument as a QString.
/*!  ODBC Attributes are delimited by Comma
/*!  ODBC Attribute support is limited to Qt 5.9 ODBC Support
\param odbcAttr is a QString argument.
*/
	void			setOdbcAttributes(const QString odbcAttr) { m_OdbcAttributes = odbcAttr;  }
//! void setReplicationOption 
/*! Is a setter function. Accepts a single argument as a ReplicationOption. Three selection options are possible; Bulk_Copy, Net_Change, NotSet
/*!  ODBC Attributes are delimited by Comma
/*!  ODBC Attribute support is limited to Qt 5.9 ODBC Support
\param odbcAttr is a QString argument.
\sa ReplicationOption
*/
	void			 setReplicationOption(ReplicationOption xReplicationOption) {
		m_ReplicationOption = xReplicationOption; 
	}
public slots:
	void setAbortFlag(); 
	void run();
signals:
//! void setAbortFlag 
/*! Is a setter function. A toggle - initiate an abort of the running class.
/*!  A toggle - initiate an abort of the running class.
*/
	void aborted(QString tableName, int fetchCnt,int insertCnt, int updateCnt);
//! void updateStatusFetched 
/*! Is a Qt Signal - the signal sends the parameterized values after each row is fetched.
\param tableName is a QString argument.
\param rowsFetched is a int argument.
*/
	void updateStatusFetched(QString profileName, QString tableName, int rowsFetched, int rowsInserted, int rowsUpdated);
 
private:
//! A private variable.
/*!
tableName := the table that will be processed by this class.
*/
	QString		tableName;
//! A private variable.
/*!
bIsAbort := the Abort flag that will be checked during the execution of this class. The default is false.
*/
	bool	bIsAbort=false;
//! A private variable.
/*!
	rowsFetched := the rowsFetch variable - a simple counter which is incremented after each row is successfully fetched. The default is 0.
*/
	int	rowsFetched = 0;
/*!
rowsFetched := the rowsInserted variable - a simple counter which is incremented after each row is successfully inserted. The default is 0.
*/
	int	rowsInserted = 0;
	int	rowsUpdated = 0;
	int	commitInterval=1000; // Rate at which SQLTransaction are committed

// Rate at which the object notifies the parent class
// the object has processed n rows.
 
	int	updateInterval=1000; 
	SQLINTEGER	lenAary = 0;
	SQLINTEGER	IndPtrArray = 0; 
/*!
hStmt_Insert, The ODBC Statement Handle for the Insert.
*/
	SQLHANDLE	hStmt_Insert; 
/*!
hStmt_Fetch, The ODBC Statement Handle for the Fetch.
*/
	SQLHANDLE	hStmt_Fetch;
/*!
hStmt_Update, The ODBC Statement Handle for the Update.
*/
	SQLHANDLE	hStmt_Update; 
/*!
numRowsFetched, The number of rows fetched.
*/
	SQLUINTEGER	numRowsFetched;
/*!
insertSql, The SQL statement used when preparing for row insertion.
*/
	QString	insertSql;
/*!
fetchSql, The SQL statement used when preparing for row selection.
*/
	QString	fetchSql;
/*!
updateSql, The SQL statement used when preparing for row updates.
*/
	QString	updateSql;
	SQLHDBC	hDbc_source;
	SQLHDBC	hDbc_target;
	SQLHENV	hEnv_Target;
	SQLHENV	hEnv_Source;
 
	QString	profileName;
	QString	m_lpszSourceDSN; 
	QString	m_lpszTargetDSN; 
	QString	m_lpszRepositoryDSN; 
	QString	m_OdbcAttributes; 
	bool bIsNetChange;
	bool	m_bIsOpen; 
	ReplicationOption m_ReplicationOption;
	DropOption  m_dropOption;
 
	bool prepare();
	void prepareTargetTable();
	bool bindColumn();
	bool bindParameter();
	void copyTable();
	void connect(connectionHandle connectionSource);

// FieldNames 
#pragma region Field Buffers TK_HDRREC
	QByteArray	DB_ID;
	QByteArray	NVTIMESTAMP;
	QByteArray	AREA;
	QByteArray	PAGE;
	QByteArray	LINE;
	QByteArray	TK_HDRCODE;
	QByteArray	TK_HDRNO;
	QByteArray	TK_HDRKEY1;
	QByteArray	TK_TYPCODE;
	SQLINTEGER	cbDB_ID;
	SQLINTEGER	cbNVTIMESTAMP;
	SQLINTEGER	cbAREA;
	SQLINTEGER	cbPAGE;
	SQLINTEGER	cbLINE;
	SQLINTEGER	cbTK_HDRCODE;
	SQLINTEGER	cbTK_HDRNO;
	SQLINTEGER	cbTK_HDRKEY1;
	SQLINTEGER	cbTK_TYPCODE;
#pragma endregion Field Buffers TK_HDRREC

};
//!  TK_CNVREC class. 
/*!
*   Executed by the Qt Threading system.
*/
class TK_CNVREC : public QObject {
		Q_OBJECT 
 
 
public:
	TK_CNVREC(QObject * parent = Q_NULLPTR );
	~TK_CNVREC(); 
 
 
	 void setCommitInterval(int uCommitInterval) { commitInterval = uCommitInterval; }
	 void setUpdateInterval(int uUpdateInterval) { updateInterval = uUpdateInterval; }
	int rowsProcessed() { return rowsFetched; }
	void initOdbcAttributes(); 
	void initialize(); 
	QStringList m_OdbcAttributesList;
	QMap<int, nOdbcAttributesClass*> m_OdbcAttributes_Map;
//! void open taking two QString strings 
/*!
\param sourceDSN is a QString argument.
\param targetDSN is a  QString argument.
*/
	void close(); 
	void open(const QString sourceDSN, const QString targetDSN); 
	void createTable();
//! void setProfileName 
/*! Is a setter function. Accepts a single argument QString - denoting the ProfileName.
\param _profileName is a QString argument.
\sa profileName
*/
	void setProfileName(const QString _profileName) { profileName = _profileName; } 
//! A normal member taking one argument and returning an boolean value.
/*! Entry function for the class - all data synchronization operations are executed from the process function.
\param rowSSize an integer argument.
\param s a constant character pointer.
\return The success status of this synchronization operation.
*/
//! void setRepositoryString 
/*! Is a setter function. Accepts a single argument QString - denoting the DataSource Connection String of the eNVy SQL Repository.
\param _repoString is a QString argument.
\sa m_lpszRepositoryDSN
*/
	void setRepositoryString(const QString _repoString) { m_lpszRepositoryDSN = _repoString; } 
//! QString getTableName 
/*! Is a getter function which returns the table name that is processed by this class.
\sa tableName
*/
	bool process(int rowSSize); 
//! void setNetChange 
/*! Is a setter function. Toggles the data synchronization method from BulK_Copy to Net Change.
\sa bIsNetChange
*/
	QString			getTableName() {	return tableName;}
	void			setNetChange() { bIsNetChange = true; } 
//! void setDropOption 
/*! Is a setter function. Accepts a single argument DropOption - the method with which the table should be handled prior to Bulk_Copy is performed.
\param dropOption is a DropOption argument.
\sa DropOption
*/
	void			setDropOption(DropOption dropOption) { m_dropOption = dropOption;  }
//! void setOdbcAttributes 
/*! Is a setter function. Accepts a single argument as a QString.
/*!  ODBC Attributes are delimited by Comma
/*!  ODBC Attribute support is limited to Qt 5.9 ODBC Support
\param odbcAttr is a QString argument.
*/
	void			setOdbcAttributes(const QString odbcAttr) { m_OdbcAttributes = odbcAttr;  }
//! void setReplicationOption 
/*! Is a setter function. Accepts a single argument as a ReplicationOption. Three selection options are possible; Bulk_Copy, Net_Change, NotSet
/*!  ODBC Attributes are delimited by Comma
/*!  ODBC Attribute support is limited to Qt 5.9 ODBC Support
\param odbcAttr is a QString argument.
\sa ReplicationOption
*/
	void			 setReplicationOption(ReplicationOption xReplicationOption) {
		m_ReplicationOption = xReplicationOption; 
	}
public slots:
	void setAbortFlag(); 
	void run();
signals:
//! void setAbortFlag 
/*! Is a setter function. A toggle - initiate an abort of the running class.
/*!  A toggle - initiate an abort of the running class.
*/
	void aborted(QString tableName, int fetchCnt,int insertCnt, int updateCnt);
//! void updateStatusFetched 
/*! Is a Qt Signal - the signal sends the parameterized values after each row is fetched.
\param tableName is a QString argument.
\param rowsFetched is a int argument.
*/
	void updateStatusFetched(QString profileName, QString tableName, int rowsFetched, int rowsInserted, int rowsUpdated);
 
private:
//! A private variable.
/*!
tableName := the table that will be processed by this class.
*/
	QString		tableName;
//! A private variable.
/*!
bIsAbort := the Abort flag that will be checked during the execution of this class. The default is false.
*/
	bool	bIsAbort=false;
//! A private variable.
/*!
	rowsFetched := the rowsFetch variable - a simple counter which is incremented after each row is successfully fetched. The default is 0.
*/
	int	rowsFetched = 0;
/*!
rowsFetched := the rowsInserted variable - a simple counter which is incremented after each row is successfully inserted. The default is 0.
*/
	int	rowsInserted = 0;
	int	rowsUpdated = 0;
	int	commitInterval=1000; // Rate at which SQLTransaction are committed

// Rate at which the object notifies the parent class
// the object has processed n rows.
 
	int	updateInterval=1000; 
	SQLINTEGER	lenAary = 0;
	SQLINTEGER	IndPtrArray = 0; 
/*!
hStmt_Insert, The ODBC Statement Handle for the Insert.
*/
	SQLHANDLE	hStmt_Insert; 
/*!
hStmt_Fetch, The ODBC Statement Handle for the Fetch.
*/
	SQLHANDLE	hStmt_Fetch;
/*!
hStmt_Update, The ODBC Statement Handle for the Update.
*/
	SQLHANDLE	hStmt_Update; 
/*!
numRowsFetched, The number of rows fetched.
*/
	SQLUINTEGER	numRowsFetched;
/*!
insertSql, The SQL statement used when preparing for row insertion.
*/
	QString	insertSql;
/*!
fetchSql, The SQL statement used when preparing for row selection.
*/
	QString	fetchSql;
/*!
updateSql, The SQL statement used when preparing for row updates.
*/
	QString	updateSql;
	SQLHDBC	hDbc_source;
	SQLHDBC	hDbc_target;
	SQLHENV	hEnv_Target;
	SQLHENV	hEnv_Source;
 
	QString	profileName;
	QString	m_lpszSourceDSN; 
	QString	m_lpszTargetDSN; 
	QString	m_lpszRepositoryDSN; 
	QString	m_OdbcAttributes; 
	bool bIsNetChange;
	bool	m_bIsOpen; 
	ReplicationOption m_ReplicationOption;
	DropOption  m_dropOption;
 
	bool prepare();
	void prepareTargetTable();
	bool bindColumn();
	bool bindParameter();
	void copyTable();
	void connect(connectionHandle connectionSource);

// FieldNames 
#pragma region Field Buffers TK_CNVREC
	QByteArray	DB_ID;
	QByteArray	NVTIMESTAMP;
	QByteArray	AREA;
	QByteArray	PAGE;
	QByteArray	LINE;
	QByteArray	TK_CNVPRT;
	QByteArray	TK_CNVFUOM;
	QByteArray	TK_CNVTUOM;
	QByteArray	TK_CNVFCTR;
	QByteArray	TK_CNVRCP;
	QByteArray	TK_CNVTYP;
	SQLINTEGER	cbDB_ID;
	SQLINTEGER	cbNVTIMESTAMP;
	SQLINTEGER	cbAREA;
	SQLINTEGER	cbPAGE;
	SQLINTEGER	cbLINE;
	SQLINTEGER	cbTK_CNVPRT;
	SQLINTEGER	cbTK_CNVFUOM;
	SQLINTEGER	cbTK_CNVTUOM;
	SQLINTEGER	cbTK_CNVFCTR;
	SQLINTEGER	cbTK_CNVRCP;
	SQLINTEGER	cbTK_CNVTYP;
#pragma endregion Field Buffers TK_CNVREC

};
//!  TK_UHSTREC class. 
/*!
*   Executed by the Qt Threading system.
*/
class TK_UHSTREC : public QObject {
		Q_OBJECT 
 
 
public:
	TK_UHSTREC(QObject * parent = Q_NULLPTR );
	~TK_UHSTREC(); 
 
 
	 void setCommitInterval(int uCommitInterval) { commitInterval = uCommitInterval; }
	 void setUpdateInterval(int uUpdateInterval) { updateInterval = uUpdateInterval; }
	int rowsProcessed() { return rowsFetched; }
	void initOdbcAttributes(); 
	void initialize(); 
	QStringList m_OdbcAttributesList;
	QMap<int, nOdbcAttributesClass*> m_OdbcAttributes_Map;
//! void open taking two QString strings 
/*!
\param sourceDSN is a QString argument.
\param targetDSN is a  QString argument.
*/
	void close(); 
	void open(const QString sourceDSN, const QString targetDSN); 
	void createTable();
//! void setProfileName 
/*! Is a setter function. Accepts a single argument QString - denoting the ProfileName.
\param _profileName is a QString argument.
\sa profileName
*/
	void setProfileName(const QString _profileName) { profileName = _profileName; } 
//! A normal member taking one argument and returning an boolean value.
/*! Entry function for the class - all data synchronization operations are executed from the process function.
\param rowSSize an integer argument.
\param s a constant character pointer.
\return The success status of this synchronization operation.
*/
//! void setRepositoryString 
/*! Is a setter function. Accepts a single argument QString - denoting the DataSource Connection String of the eNVy SQL Repository.
\param _repoString is a QString argument.
\sa m_lpszRepositoryDSN
*/
	void setRepositoryString(const QString _repoString) { m_lpszRepositoryDSN = _repoString; } 
//! QString getTableName 
/*! Is a getter function which returns the table name that is processed by this class.
\sa tableName
*/
	bool process(int rowSSize); 
//! void setNetChange 
/*! Is a setter function. Toggles the data synchronization method from BulK_Copy to Net Change.
\sa bIsNetChange
*/
	QString			getTableName() {	return tableName;}
	void			setNetChange() { bIsNetChange = true; } 
//! void setDropOption 
/*! Is a setter function. Accepts a single argument DropOption - the method with which the table should be handled prior to Bulk_Copy is performed.
\param dropOption is a DropOption argument.
\sa DropOption
*/
	void			setDropOption(DropOption dropOption) { m_dropOption = dropOption;  }
//! void setOdbcAttributes 
/*! Is a setter function. Accepts a single argument as a QString.
/*!  ODBC Attributes are delimited by Comma
/*!  ODBC Attribute support is limited to Qt 5.9 ODBC Support
\param odbcAttr is a QString argument.
*/
	void			setOdbcAttributes(const QString odbcAttr) { m_OdbcAttributes = odbcAttr;  }
//! void setReplicationOption 
/*! Is a setter function. Accepts a single argument as a ReplicationOption. Three selection options are possible; Bulk_Copy, Net_Change, NotSet
/*!  ODBC Attributes are delimited by Comma
/*!  ODBC Attribute support is limited to Qt 5.9 ODBC Support
\param odbcAttr is a QString argument.
\sa ReplicationOption
*/
	void			 setReplicationOption(ReplicationOption xReplicationOption) {
		m_ReplicationOption = xReplicationOption; 
	}
public slots:
	void setAbortFlag(); 
	void run();
signals:
//! void setAbortFlag 
/*! Is a setter function. A toggle - initiate an abort of the running class.
/*!  A toggle - initiate an abort of the running class.
*/
	void aborted(QString tableName, int fetchCnt,int insertCnt, int updateCnt);
//! void updateStatusFetched 
/*! Is a Qt Signal - the signal sends the parameterized values after each row is fetched.
\param tableName is a QString argument.
\param rowsFetched is a int argument.
*/
	void updateStatusFetched(QString profileName, QString tableName, int rowsFetched, int rowsInserted, int rowsUpdated);
 
private:
//! A private variable.
/*!
tableName := the table that will be processed by this class.
*/
	QString		tableName;
//! A private variable.
/*!
bIsAbort := the Abort flag that will be checked during the execution of this class. The default is false.
*/
	bool	bIsAbort=false;
//! A private variable.
/*!
	rowsFetched := the rowsFetch variable - a simple counter which is incremented after each row is successfully fetched. The default is 0.
*/
	int	rowsFetched = 0;
/*!
rowsFetched := the rowsInserted variable - a simple counter which is incremented after each row is successfully inserted. The default is 0.
*/
	int	rowsInserted = 0;
	int	rowsUpdated = 0;
	int	commitInterval=1000; // Rate at which SQLTransaction are committed

// Rate at which the object notifies the parent class
// the object has processed n rows.
 
	int	updateInterval=1000; 
	SQLINTEGER	lenAary = 0;
	SQLINTEGER	IndPtrArray = 0; 
/*!
hStmt_Insert, The ODBC Statement Handle for the Insert.
*/
	SQLHANDLE	hStmt_Insert; 
/*!
hStmt_Fetch, The ODBC Statement Handle for the Fetch.
*/
	SQLHANDLE	hStmt_Fetch;
/*!
hStmt_Update, The ODBC Statement Handle for the Update.
*/
	SQLHANDLE	hStmt_Update; 
/*!
numRowsFetched, The number of rows fetched.
*/
	SQLUINTEGER	numRowsFetched;
/*!
insertSql, The SQL statement used when preparing for row insertion.
*/
	QString	insertSql;
/*!
fetchSql, The SQL statement used when preparing for row selection.
*/
	QString	fetchSql;
/*!
updateSql, The SQL statement used when preparing for row updates.
*/
	QString	updateSql;
	SQLHDBC	hDbc_source;
	SQLHDBC	hDbc_target;
	SQLHENV	hEnv_Target;
	SQLHENV	hEnv_Source;
 
	QString	profileName;
	QString	m_lpszSourceDSN; 
	QString	m_lpszTargetDSN; 
	QString	m_lpszRepositoryDSN; 
	QString	m_OdbcAttributes; 
	bool bIsNetChange;
	bool	m_bIsOpen; 
	ReplicationOption m_ReplicationOption;
	DropOption  m_dropOption;
 
	bool prepare();
	void prepareTargetTable();
	bool bindColumn();
	bool bindParameter();
	void copyTable();
	void connect(connectionHandle connectionSource);

// FieldNames 
#pragma region Field Buffers TK_UHSTREC
	QByteArray	DB_ID;
	QByteArray	NVTIMESTAMP;
	QByteArray	AREA;
	QByteArray	PAGE;
	QByteArray	LINE;
	QByteArray	TK_UHSTDATE;
	QByteArray	TK_UHSTTIME;
	QByteArray	TK_UHSTUSER;
	QByteArray	TK_UHSTCMD;
	QByteArray	TK_UHSTOLDPRT;
	QByteArray	TK_UHSTNEWPRT;
	QByteArray	TK_UHSTOLDFUOM;
	QByteArray	TK_UHSTNEWFUOM;
	QByteArray	TK_UHSTOLDTUOM;
	QByteArray	TK_UHSTNEWTUOM;
	QByteArray	TK_UHSTOLDFCTR;
	QByteArray	TK_UHSTNEWFCTR;
	SQLINTEGER	cbDB_ID;
	SQLINTEGER	cbNVTIMESTAMP;
	SQLINTEGER	cbAREA;
	SQLINTEGER	cbPAGE;
	SQLINTEGER	cbLINE;
	SQLINTEGER	cbTK_UHSTDATE;
	SQLINTEGER	cbTK_UHSTTIME;
	SQLINTEGER	cbTK_UHSTUSER;
	SQLINTEGER	cbTK_UHSTCMD;
	SQLINTEGER	cbTK_UHSTOLDPRT;
	SQLINTEGER	cbTK_UHSTNEWPRT;
	SQLINTEGER	cbTK_UHSTOLDFUOM;
	SQLINTEGER	cbTK_UHSTNEWFUOM;
	SQLINTEGER	cbTK_UHSTOLDTUOM;
	SQLINTEGER	cbTK_UHSTNEWTUOM;
	SQLINTEGER	cbTK_UHSTOLDFCTR;
	SQLINTEGER	cbTK_UHSTNEWFCTR;
#pragma endregion Field Buffers TK_UHSTREC

};
//!  TK_INTFMHSHSET class. 
/*!
*   Executed by the Qt Threading system.
*/
class TK_INTFMHSHSET : public QObject {
		Q_OBJECT 
 
 
public:
	TK_INTFMHSHSET(QObject * parent = Q_NULLPTR );
	~TK_INTFMHSHSET(); 
 
 
	 void setCommitInterval(int uCommitInterval) { commitInterval = uCommitInterval; }
	 void setUpdateInterval(int uUpdateInterval) { updateInterval = uUpdateInterval; }
	int rowsProcessed() { return rowsFetched; }
	void initOdbcAttributes(); 
	void initialize(); 
	QStringList m_OdbcAttributesList;
	QMap<int, nOdbcAttributesClass*> m_OdbcAttributes_Map;
//! void open taking two QString strings 
/*!
\param sourceDSN is a QString argument.
\param targetDSN is a  QString argument.
*/
	void close(); 
	void open(const QString sourceDSN, const QString targetDSN); 
	void createTable();
//! void setProfileName 
/*! Is a setter function. Accepts a single argument QString - denoting the ProfileName.
\param _profileName is a QString argument.
\sa profileName
*/
	void setProfileName(const QString _profileName) { profileName = _profileName; } 
//! A normal member taking one argument and returning an boolean value.
/*! Entry function for the class - all data synchronization operations are executed from the process function.
\param rowSSize an integer argument.
\param s a constant character pointer.
\return The success status of this synchronization operation.
*/
//! void setRepositoryString 
/*! Is a setter function. Accepts a single argument QString - denoting the DataSource Connection String of the eNVy SQL Repository.
\param _repoString is a QString argument.
\sa m_lpszRepositoryDSN
*/
	void setRepositoryString(const QString _repoString) { m_lpszRepositoryDSN = _repoString; } 
//! QString getTableName 
/*! Is a getter function which returns the table name that is processed by this class.
\sa tableName
*/
	bool process(int rowSSize); 
//! void setNetChange 
/*! Is a setter function. Toggles the data synchronization method from BulK_Copy to Net Change.
\sa bIsNetChange
*/
	QString			getTableName() {	return tableName;}
	void			setNetChange() { bIsNetChange = true; } 
//! void setDropOption 
/*! Is a setter function. Accepts a single argument DropOption - the method with which the table should be handled prior to Bulk_Copy is performed.
\param dropOption is a DropOption argument.
\sa DropOption
*/
	void			setDropOption(DropOption dropOption) { m_dropOption = dropOption;  }
//! void setOdbcAttributes 
/*! Is a setter function. Accepts a single argument as a QString.
/*!  ODBC Attributes are delimited by Comma
/*!  ODBC Attribute support is limited to Qt 5.9 ODBC Support
\param odbcAttr is a QString argument.
*/
	void			setOdbcAttributes(const QString odbcAttr) { m_OdbcAttributes = odbcAttr;  }
//! void setReplicationOption 
/*! Is a setter function. Accepts a single argument as a ReplicationOption. Three selection options are possible; Bulk_Copy, Net_Change, NotSet
/*!  ODBC Attributes are delimited by Comma
/*!  ODBC Attribute support is limited to Qt 5.9 ODBC Support
\param odbcAttr is a QString argument.
\sa ReplicationOption
*/
	void			 setReplicationOption(ReplicationOption xReplicationOption) {
		m_ReplicationOption = xReplicationOption; 
	}
public slots:
	void setAbortFlag(); 
	void run();
signals:
//! void setAbortFlag 
/*! Is a setter function. A toggle - initiate an abort of the running class.
/*!  A toggle - initiate an abort of the running class.
*/
	void aborted(QString tableName, int fetchCnt,int insertCnt, int updateCnt);
//! void updateStatusFetched 
/*! Is a Qt Signal - the signal sends the parameterized values after each row is fetched.
\param tableName is a QString argument.
\param rowsFetched is a int argument.
*/
	void updateStatusFetched(QString profileName, QString tableName, int rowsFetched, int rowsInserted, int rowsUpdated);
 
private:
//! A private variable.
/*!
tableName := the table that will be processed by this class.
*/
	QString		tableName;
//! A private variable.
/*!
bIsAbort := the Abort flag that will be checked during the execution of this class. The default is false.
*/
	bool	bIsAbort=false;
//! A private variable.
/*!
	rowsFetched := the rowsFetch variable - a simple counter which is incremented after each row is successfully fetched. The default is 0.
*/
	int	rowsFetched = 0;
/*!
rowsFetched := the rowsInserted variable - a simple counter which is incremented after each row is successfully inserted. The default is 0.
*/
	int	rowsInserted = 0;
	int	rowsUpdated = 0;
	int	commitInterval=1000; // Rate at which SQLTransaction are committed

// Rate at which the object notifies the parent class
// the object has processed n rows.
 
	int	updateInterval=1000; 
	SQLINTEGER	lenAary = 0;
	SQLINTEGER	IndPtrArray = 0; 
/*!
hStmt_Insert, The ODBC Statement Handle for the Insert.
*/
	SQLHANDLE	hStmt_Insert; 
/*!
hStmt_Fetch, The ODBC Statement Handle for the Fetch.
*/
	SQLHANDLE	hStmt_Fetch;
/*!
hStmt_Update, The ODBC Statement Handle for the Update.
*/
	SQLHANDLE	hStmt_Update; 
/*!
numRowsFetched, The number of rows fetched.
*/
	SQLUINTEGER	numRowsFetched;
/*!
insertSql, The SQL statement used when preparing for row insertion.
*/
	QString	insertSql;
/*!
fetchSql, The SQL statement used when preparing for row selection.
*/
	QString	fetchSql;
/*!
updateSql, The SQL statement used when preparing for row updates.
*/
	QString	updateSql;
	SQLHDBC	hDbc_source;
	SQLHDBC	hDbc_target;
	SQLHENV	hEnv_Target;
	SQLHENV	hEnv_Source;
 
	QString	profileName;
	QString	m_lpszSourceDSN; 
	QString	m_lpszTargetDSN; 
	QString	m_lpszRepositoryDSN; 
	QString	m_OdbcAttributes; 
	bool bIsNetChange;
	bool	m_bIsOpen; 
	ReplicationOption m_ReplicationOption;
	DropOption  m_dropOption;
 
	bool prepare();
	void prepareTargetTable();
	bool bindColumn();
	bool bindParameter();
	void copyTable();
	void connect(connectionHandle connectionSource);

// FieldNames 
#pragma region Field Buffers TK_INTFMHSHSET
	QByteArray	DB_ID;
	QByteArray	NVTIMESTAMP;
	QByteArray	OAREA;
	QByteArray	OPAGE;
	QByteArray	OLINE;
	QByteArray	MAREA;
	QByteArray	MPAGE;
	QByteArray	MLINE;
	SQLINTEGER	cbDB_ID;
	SQLINTEGER	cbNVTIMESTAMP;
	SQLINTEGER	cbOAREA;
	SQLINTEGER	cbOPAGE;
	SQLINTEGER	cbOLINE;
	SQLINTEGER	cbMAREA;
	SQLINTEGER	cbMPAGE;
	SQLINTEGER	cbMLINE;
#pragma endregion Field Buffers TK_INTFMHSHSET

};
//!  TK_LTDREC class. 
/*!
*   Executed by the Qt Threading system.
*/
class TK_LTDREC : public QObject {
		Q_OBJECT 
 
 
public:
	TK_LTDREC(QObject * parent = Q_NULLPTR );
	~TK_LTDREC(); 
 
 
	 void setCommitInterval(int uCommitInterval) { commitInterval = uCommitInterval; }
	 void setUpdateInterval(int uUpdateInterval) { updateInterval = uUpdateInterval; }
	int rowsProcessed() { return rowsFetched; }
	void initOdbcAttributes(); 
	void initialize(); 
	QStringList m_OdbcAttributesList;
	QMap<int, nOdbcAttributesClass*> m_OdbcAttributes_Map;
//! void open taking two QString strings 
/*!
\param sourceDSN is a QString argument.
\param targetDSN is a  QString argument.
*/
	void close(); 
	void open(const QString sourceDSN, const QString targetDSN); 
	void createTable();
//! void setProfileName 
/*! Is a setter function. Accepts a single argument QString - denoting the ProfileName.
\param _profileName is a QString argument.
\sa profileName
*/
	void setProfileName(const QString _profileName) { profileName = _profileName; } 
//! A normal member taking one argument and returning an boolean value.
/*! Entry function for the class - all data synchronization operations are executed from the process function.
\param rowSSize an integer argument.
\param s a constant character pointer.
\return The success status of this synchronization operation.
*/
//! void setRepositoryString 
/*! Is a setter function. Accepts a single argument QString - denoting the DataSource Connection String of the eNVy SQL Repository.
\param _repoString is a QString argument.
\sa m_lpszRepositoryDSN
*/
	void setRepositoryString(const QString _repoString) { m_lpszRepositoryDSN = _repoString; } 
//! QString getTableName 
/*! Is a getter function which returns the table name that is processed by this class.
\sa tableName
*/
	bool process(int rowSSize); 
//! void setNetChange 
/*! Is a setter function. Toggles the data synchronization method from BulK_Copy to Net Change.
\sa bIsNetChange
*/
	QString			getTableName() {	return tableName;}
	void			setNetChange() { bIsNetChange = true; } 
//! void setDropOption 
/*! Is a setter function. Accepts a single argument DropOption - the method with which the table should be handled prior to Bulk_Copy is performed.
\param dropOption is a DropOption argument.
\sa DropOption
*/
	void			setDropOption(DropOption dropOption) { m_dropOption = dropOption;  }
//! void setOdbcAttributes 
/*! Is a setter function. Accepts a single argument as a QString.
/*!  ODBC Attributes are delimited by Comma
/*!  ODBC Attribute support is limited to Qt 5.9 ODBC Support
\param odbcAttr is a QString argument.
*/
	void			setOdbcAttributes(const QString odbcAttr) { m_OdbcAttributes = odbcAttr;  }
//! void setReplicationOption 
/*! Is a setter function. Accepts a single argument as a ReplicationOption. Three selection options are possible; Bulk_Copy, Net_Change, NotSet
/*!  ODBC Attributes are delimited by Comma
/*!  ODBC Attribute support is limited to Qt 5.9 ODBC Support
\param odbcAttr is a QString argument.
\sa ReplicationOption
*/
	void			 setReplicationOption(ReplicationOption xReplicationOption) {
		m_ReplicationOption = xReplicationOption; 
	}
public slots:
	void setAbortFlag(); 
	void run();
signals:
//! void setAbortFlag 
/*! Is a setter function. A toggle - initiate an abort of the running class.
/*!  A toggle - initiate an abort of the running class.
*/
	void aborted(QString tableName, int fetchCnt,int insertCnt, int updateCnt);
//! void updateStatusFetched 
/*! Is a Qt Signal - the signal sends the parameterized values after each row is fetched.
\param tableName is a QString argument.
\param rowsFetched is a int argument.
*/
	void updateStatusFetched(QString profileName, QString tableName, int rowsFetched, int rowsInserted, int rowsUpdated);
 
private:
//! A private variable.
/*!
tableName := the table that will be processed by this class.
*/
	QString		tableName;
//! A private variable.
/*!
bIsAbort := the Abort flag that will be checked during the execution of this class. The default is false.
*/
	bool	bIsAbort=false;
//! A private variable.
/*!
	rowsFetched := the rowsFetch variable - a simple counter which is incremented after each row is successfully fetched. The default is 0.
*/
	int	rowsFetched = 0;
/*!
rowsFetched := the rowsInserted variable - a simple counter which is incremented after each row is successfully inserted. The default is 0.
*/
	int	rowsInserted = 0;
	int	rowsUpdated = 0;
	int	commitInterval=1000; // Rate at which SQLTransaction are committed

// Rate at which the object notifies the parent class
// the object has processed n rows.
 
	int	updateInterval=1000; 
	SQLINTEGER	lenAary = 0;
	SQLINTEGER	IndPtrArray = 0; 
/*!
hStmt_Insert, The ODBC Statement Handle for the Insert.
*/
	SQLHANDLE	hStmt_Insert; 
/*!
hStmt_Fetch, The ODBC Statement Handle for the Fetch.
*/
	SQLHANDLE	hStmt_Fetch;
/*!
hStmt_Update, The ODBC Statement Handle for the Update.
*/
	SQLHANDLE	hStmt_Update; 
/*!
numRowsFetched, The number of rows fetched.
*/
	SQLUINTEGER	numRowsFetched;
/*!
insertSql, The SQL statement used when preparing for row insertion.
*/
	QString	insertSql;
/*!
fetchSql, The SQL statement used when preparing for row selection.
*/
	QString	fetchSql;
/*!
updateSql, The SQL statement used when preparing for row updates.
*/
	QString	updateSql;
	SQLHDBC	hDbc_source;
	SQLHDBC	hDbc_target;
	SQLHENV	hEnv_Target;
	SQLHENV	hEnv_Source;
 
	QString	profileName;
	QString	m_lpszSourceDSN; 
	QString	m_lpszTargetDSN; 
	QString	m_lpszRepositoryDSN; 
	QString	m_OdbcAttributes; 
	bool bIsNetChange;
	bool	m_bIsOpen; 
	ReplicationOption m_ReplicationOption;
	DropOption  m_dropOption;
 
	bool prepare();
	void prepareTargetTable();
	bool bindColumn();
	bool bindParameter();
	void copyTable();
	void connect(connectionHandle connectionSource);

// FieldNames 
#pragma region Field Buffers TK_LTDREC
	QByteArray	DB_ID;
	QByteArray	NVTIMESTAMP;
	QByteArray	AREA;
	QByteArray	PAGE;
	QByteArray	LINE;
	QByteArray	TK_LTDISSQTY;
	QByteArray	TK_LTDDAT;
	QByteArray	TK_LTDCMD;
	QByteArray	TK_LTDARCFLG;
	QByteArray	TK_LTPLOT;
	QByteArray	TK_LTPLOT15;
	SQLINTEGER	cbDB_ID;
	SQLINTEGER	cbNVTIMESTAMP;
	SQLINTEGER	cbAREA;
	SQLINTEGER	cbPAGE;
	SQLINTEGER	cbLINE;
	SQLINTEGER	cbTK_LTDISSQTY;
	SQLINTEGER	cbTK_LTDDAT;
	SQLINTEGER	cbTK_LTDCMD;
	SQLINTEGER	cbTK_LTDARCFLG;
	SQLINTEGER	cbTK_LTPLOT;
	SQLINTEGER	cbTK_LTPLOT15;
#pragma endregion Field Buffers TK_LTDREC

};
//!  TK_HDRHSHSET class. 
/*!
*   Executed by the Qt Threading system.
*/
class TK_HDRHSHSET : public QObject {
		Q_OBJECT 
 
 
public:
	TK_HDRHSHSET(QObject * parent = Q_NULLPTR );
	~TK_HDRHSHSET(); 
 
 
	 void setCommitInterval(int uCommitInterval) { commitInterval = uCommitInterval; }
	 void setUpdateInterval(int uUpdateInterval) { updateInterval = uUpdateInterval; }
	int rowsProcessed() { return rowsFetched; }
	void initOdbcAttributes(); 
	void initialize(); 
	QStringList m_OdbcAttributesList;
	QMap<int, nOdbcAttributesClass*> m_OdbcAttributes_Map;
//! void open taking two QString strings 
/*!
\param sourceDSN is a QString argument.
\param targetDSN is a  QString argument.
*/
	void close(); 
	void open(const QString sourceDSN, const QString targetDSN); 
	void createTable();
//! void setProfileName 
/*! Is a setter function. Accepts a single argument QString - denoting the ProfileName.
\param _profileName is a QString argument.
\sa profileName
*/
	void setProfileName(const QString _profileName) { profileName = _profileName; } 
//! A normal member taking one argument and returning an boolean value.
/*! Entry function for the class - all data synchronization operations are executed from the process function.
\param rowSSize an integer argument.
\param s a constant character pointer.
\return The success status of this synchronization operation.
*/
//! void setRepositoryString 
/*! Is a setter function. Accepts a single argument QString - denoting the DataSource Connection String of the eNVy SQL Repository.
\param _repoString is a QString argument.
\sa m_lpszRepositoryDSN
*/
	void setRepositoryString(const QString _repoString) { m_lpszRepositoryDSN = _repoString; } 
//! QString getTableName 
/*! Is a getter function which returns the table name that is processed by this class.
\sa tableName
*/
	bool process(int rowSSize); 
//! void setNetChange 
/*! Is a setter function. Toggles the data synchronization method from BulK_Copy to Net Change.
\sa bIsNetChange
*/
	QString			getTableName() {	return tableName;}
	void			setNetChange() { bIsNetChange = true; } 
//! void setDropOption 
/*! Is a setter function. Accepts a single argument DropOption - the method with which the table should be handled prior to Bulk_Copy is performed.
\param dropOption is a DropOption argument.
\sa DropOption
*/
	void			setDropOption(DropOption dropOption) { m_dropOption = dropOption;  }
//! void setOdbcAttributes 
/*! Is a setter function. Accepts a single argument as a QString.
/*!  ODBC Attributes are delimited by Comma
/*!  ODBC Attribute support is limited to Qt 5.9 ODBC Support
\param odbcAttr is a QString argument.
*/
	void			setOdbcAttributes(const QString odbcAttr) { m_OdbcAttributes = odbcAttr;  }
//! void setReplicationOption 
/*! Is a setter function. Accepts a single argument as a ReplicationOption. Three selection options are possible; Bulk_Copy, Net_Change, NotSet
/*!  ODBC Attributes are delimited by Comma
/*!  ODBC Attribute support is limited to Qt 5.9 ODBC Support
\param odbcAttr is a QString argument.
\sa ReplicationOption
*/
	void			 setReplicationOption(ReplicationOption xReplicationOption) {
		m_ReplicationOption = xReplicationOption; 
	}
public slots:
	void setAbortFlag(); 
	void run();
signals:
//! void setAbortFlag 
/*! Is a setter function. A toggle - initiate an abort of the running class.
/*!  A toggle - initiate an abort of the running class.
*/
	void aborted(QString tableName, int fetchCnt,int insertCnt, int updateCnt);
//! void updateStatusFetched 
/*! Is a Qt Signal - the signal sends the parameterized values after each row is fetched.
\param tableName is a QString argument.
\param rowsFetched is a int argument.
*/
	void updateStatusFetched(QString profileName, QString tableName, int rowsFetched, int rowsInserted, int rowsUpdated);
 
private:
//! A private variable.
/*!
tableName := the table that will be processed by this class.
*/
	QString		tableName;
//! A private variable.
/*!
bIsAbort := the Abort flag that will be checked during the execution of this class. The default is false.
*/
	bool	bIsAbort=false;
//! A private variable.
/*!
	rowsFetched := the rowsFetch variable - a simple counter which is incremented after each row is successfully fetched. The default is 0.
*/
	int	rowsFetched = 0;
/*!
rowsFetched := the rowsInserted variable - a simple counter which is incremented after each row is successfully inserted. The default is 0.
*/
	int	rowsInserted = 0;
	int	rowsUpdated = 0;
	int	commitInterval=1000; // Rate at which SQLTransaction are committed

// Rate at which the object notifies the parent class
// the object has processed n rows.
 
	int	updateInterval=1000; 
	SQLINTEGER	lenAary = 0;
	SQLINTEGER	IndPtrArray = 0; 
/*!
hStmt_Insert, The ODBC Statement Handle for the Insert.
*/
	SQLHANDLE	hStmt_Insert; 
/*!
hStmt_Fetch, The ODBC Statement Handle for the Fetch.
*/
	SQLHANDLE	hStmt_Fetch;
/*!
hStmt_Update, The ODBC Statement Handle for the Update.
*/
	SQLHANDLE	hStmt_Update; 
/*!
numRowsFetched, The number of rows fetched.
*/
	SQLUINTEGER	numRowsFetched;
/*!
insertSql, The SQL statement used when preparing for row insertion.
*/
	QString	insertSql;
/*!
fetchSql, The SQL statement used when preparing for row selection.
*/
	QString	fetchSql;
/*!
updateSql, The SQL statement used when preparing for row updates.
*/
	QString	updateSql;
	SQLHDBC	hDbc_source;
	SQLHDBC	hDbc_target;
	SQLHENV	hEnv_Target;
	SQLHENV	hEnv_Source;
 
	QString	profileName;
	QString	m_lpszSourceDSN; 
	QString	m_lpszTargetDSN; 
	QString	m_lpszRepositoryDSN; 
	QString	m_OdbcAttributes; 
	bool bIsNetChange;
	bool	m_bIsOpen; 
	ReplicationOption m_ReplicationOption;
	DropOption  m_dropOption;
 
	bool prepare();
	void prepareTargetTable();
	bool bindColumn();
	bool bindParameter();
	void copyTable();
	void connect(connectionHandle connectionSource);

// FieldNames 
#pragma region Field Buffers TK_HDRHSHSET
	QByteArray	DB_ID;
	QByteArray	NVTIMESTAMP;
	QByteArray	OAREA;
	QByteArray	OPAGE;
	QByteArray	OLINE;
	QByteArray	MAREA;
	QByteArray	MPAGE;
	QByteArray	MLINE;
	SQLINTEGER	cbDB_ID;
	SQLINTEGER	cbNVTIMESTAMP;
	SQLINTEGER	cbOAREA;
	SQLINTEGER	cbOPAGE;
	SQLINTEGER	cbOLINE;
	SQLINTEGER	cbMAREA;
	SQLINTEGER	cbMPAGE;
	SQLINTEGER	cbMLINE;
#pragma endregion Field Buffers TK_HDRHSHSET

};
//!  TK_HDRLTPSET class. 
/*!
*   Executed by the Qt Threading system.
*/
class TK_HDRLTPSET : public QObject {
		Q_OBJECT 
 
 
public:
	TK_HDRLTPSET(QObject * parent = Q_NULLPTR );
	~TK_HDRLTPSET(); 
 
 
	 void setCommitInterval(int uCommitInterval) { commitInterval = uCommitInterval; }
	 void setUpdateInterval(int uUpdateInterval) { updateInterval = uUpdateInterval; }
	int rowsProcessed() { return rowsFetched; }
	void initOdbcAttributes(); 
	void initialize(); 
	QStringList m_OdbcAttributesList;
	QMap<int, nOdbcAttributesClass*> m_OdbcAttributes_Map;
//! void open taking two QString strings 
/*!
\param sourceDSN is a QString argument.
\param targetDSN is a  QString argument.
*/
	void close(); 
	void open(const QString sourceDSN, const QString targetDSN); 
	void createTable();
//! void setProfileName 
/*! Is a setter function. Accepts a single argument QString - denoting the ProfileName.
\param _profileName is a QString argument.
\sa profileName
*/
	void setProfileName(const QString _profileName) { profileName = _profileName; } 
//! A normal member taking one argument and returning an boolean value.
/*! Entry function for the class - all data synchronization operations are executed from the process function.
\param rowSSize an integer argument.
\param s a constant character pointer.
\return The success status of this synchronization operation.
*/
//! void setRepositoryString 
/*! Is a setter function. Accepts a single argument QString - denoting the DataSource Connection String of the eNVy SQL Repository.
\param _repoString is a QString argument.
\sa m_lpszRepositoryDSN
*/
	void setRepositoryString(const QString _repoString) { m_lpszRepositoryDSN = _repoString; } 
//! QString getTableName 
/*! Is a getter function which returns the table name that is processed by this class.
\sa tableName
*/
	bool process(int rowSSize); 
//! void setNetChange 
/*! Is a setter function. Toggles the data synchronization method from BulK_Copy to Net Change.
\sa bIsNetChange
*/
	QString			getTableName() {	return tableName;}
	void			setNetChange() { bIsNetChange = true; } 
//! void setDropOption 
/*! Is a setter function. Accepts a single argument DropOption - the method with which the table should be handled prior to Bulk_Copy is performed.
\param dropOption is a DropOption argument.
\sa DropOption
*/
	void			setDropOption(DropOption dropOption) { m_dropOption = dropOption;  }
//! void setOdbcAttributes 
/*! Is a setter function. Accepts a single argument as a QString.
/*!  ODBC Attributes are delimited by Comma
/*!  ODBC Attribute support is limited to Qt 5.9 ODBC Support
\param odbcAttr is a QString argument.
*/
	void			setOdbcAttributes(const QString odbcAttr) { m_OdbcAttributes = odbcAttr;  }
//! void setReplicationOption 
/*! Is a setter function. Accepts a single argument as a ReplicationOption. Three selection options are possible; Bulk_Copy, Net_Change, NotSet
/*!  ODBC Attributes are delimited by Comma
/*!  ODBC Attribute support is limited to Qt 5.9 ODBC Support
\param odbcAttr is a QString argument.
\sa ReplicationOption
*/
	void			 setReplicationOption(ReplicationOption xReplicationOption) {
		m_ReplicationOption = xReplicationOption; 
	}
public slots:
	void setAbortFlag(); 
	void run();
signals:
//! void setAbortFlag 
/*! Is a setter function. A toggle - initiate an abort of the running class.
/*!  A toggle - initiate an abort of the running class.
*/
	void aborted(QString tableName, int fetchCnt,int insertCnt, int updateCnt);
//! void updateStatusFetched 
/*! Is a Qt Signal - the signal sends the parameterized values after each row is fetched.
\param tableName is a QString argument.
\param rowsFetched is a int argument.
*/
	void updateStatusFetched(QString profileName, QString tableName, int rowsFetched, int rowsInserted, int rowsUpdated);
 
private:
//! A private variable.
/*!
tableName := the table that will be processed by this class.
*/
	QString		tableName;
//! A private variable.
/*!
bIsAbort := the Abort flag that will be checked during the execution of this class. The default is false.
*/
	bool	bIsAbort=false;
//! A private variable.
/*!
	rowsFetched := the rowsFetch variable - a simple counter which is incremented after each row is successfully fetched. The default is 0.
*/
	int	rowsFetched = 0;
/*!
rowsFetched := the rowsInserted variable - a simple counter which is incremented after each row is successfully inserted. The default is 0.
*/
	int	rowsInserted = 0;
	int	rowsUpdated = 0;
	int	commitInterval=1000; // Rate at which SQLTransaction are committed

// Rate at which the object notifies the parent class
// the object has processed n rows.
 
	int	updateInterval=1000; 
	SQLINTEGER	lenAary = 0;
	SQLINTEGER	IndPtrArray = 0; 
/*!
hStmt_Insert, The ODBC Statement Handle for the Insert.
*/
	SQLHANDLE	hStmt_Insert; 
/*!
hStmt_Fetch, The ODBC Statement Handle for the Fetch.
*/
	SQLHANDLE	hStmt_Fetch;
/*!
hStmt_Update, The ODBC Statement Handle for the Update.
*/
	SQLHANDLE	hStmt_Update; 
/*!
numRowsFetched, The number of rows fetched.
*/
	SQLUINTEGER	numRowsFetched;
/*!
insertSql, The SQL statement used when preparing for row insertion.
*/
	QString	insertSql;
/*!
fetchSql, The SQL statement used when preparing for row selection.
*/
	QString	fetchSql;
/*!
updateSql, The SQL statement used when preparing for row updates.
*/
	QString	updateSql;
	SQLHDBC	hDbc_source;
	SQLHDBC	hDbc_target;
	SQLHENV	hEnv_Target;
	SQLHENV	hEnv_Source;
 
	QString	profileName;
	QString	m_lpszSourceDSN; 
	QString	m_lpszTargetDSN; 
	QString	m_lpszRepositoryDSN; 
	QString	m_OdbcAttributes; 
	bool bIsNetChange;
	bool	m_bIsOpen; 
	ReplicationOption m_ReplicationOption;
	DropOption  m_dropOption;
 
	bool prepare();
	void prepareTargetTable();
	bool bindColumn();
	bool bindParameter();
	void copyTable();
	void connect(connectionHandle connectionSource);

// FieldNames 
#pragma region Field Buffers TK_HDRLTPSET
	QByteArray	DB_ID;
	QByteArray	NVTIMESTAMP;
	QByteArray	OAREA;
	QByteArray	OPAGE;
	QByteArray	OLINE;
	QByteArray	MAREA;
	QByteArray	MPAGE;
	QByteArray	MLINE;
	SQLINTEGER	cbDB_ID;
	SQLINTEGER	cbNVTIMESTAMP;
	SQLINTEGER	cbOAREA;
	SQLINTEGER	cbOPAGE;
	SQLINTEGER	cbOLINE;
	SQLINTEGER	cbMAREA;
	SQLINTEGER	cbMPAGE;
	SQLINTEGER	cbMLINE;
#pragma endregion Field Buffers TK_HDRLTPSET

};
//!  TK_CNVHSHSET class. 
/*!
*   Executed by the Qt Threading system.
*/
class TK_CNVHSHSET : public QObject {
		Q_OBJECT 
 
 
public:
	TK_CNVHSHSET(QObject * parent = Q_NULLPTR );
	~TK_CNVHSHSET(); 
 
 
	 void setCommitInterval(int uCommitInterval) { commitInterval = uCommitInterval; }
	 void setUpdateInterval(int uUpdateInterval) { updateInterval = uUpdateInterval; }
	int rowsProcessed() { return rowsFetched; }
	void initOdbcAttributes(); 
	void initialize(); 
	QStringList m_OdbcAttributesList;
	QMap<int, nOdbcAttributesClass*> m_OdbcAttributes_Map;
//! void open taking two QString strings 
/*!
\param sourceDSN is a QString argument.
\param targetDSN is a  QString argument.
*/
	void close(); 
	void open(const QString sourceDSN, const QString targetDSN); 
	void createTable();
//! void setProfileName 
/*! Is a setter function. Accepts a single argument QString - denoting the ProfileName.
\param _profileName is a QString argument.
\sa profileName
*/
	void setProfileName(const QString _profileName) { profileName = _profileName; } 
//! A normal member taking one argument and returning an boolean value.
/*! Entry function for the class - all data synchronization operations are executed from the process function.
\param rowSSize an integer argument.
\param s a constant character pointer.
\return The success status of this synchronization operation.
*/
//! void setRepositoryString 
/*! Is a setter function. Accepts a single argument QString - denoting the DataSource Connection String of the eNVy SQL Repository.
\param _repoString is a QString argument.
\sa m_lpszRepositoryDSN
*/
	void setRepositoryString(const QString _repoString) { m_lpszRepositoryDSN = _repoString; } 
//! QString getTableName 
/*! Is a getter function which returns the table name that is processed by this class.
\sa tableName
*/
	bool process(int rowSSize); 
//! void setNetChange 
/*! Is a setter function. Toggles the data synchronization method from BulK_Copy to Net Change.
\sa bIsNetChange
*/
	QString			getTableName() {	return tableName;}
	void			setNetChange() { bIsNetChange = true; } 
//! void setDropOption 
/*! Is a setter function. Accepts a single argument DropOption - the method with which the table should be handled prior to Bulk_Copy is performed.
\param dropOption is a DropOption argument.
\sa DropOption
*/
	void			setDropOption(DropOption dropOption) { m_dropOption = dropOption;  }
//! void setOdbcAttributes 
/*! Is a setter function. Accepts a single argument as a QString.
/*!  ODBC Attributes are delimited by Comma
/*!  ODBC Attribute support is limited to Qt 5.9 ODBC Support
\param odbcAttr is a QString argument.
*/
	void			setOdbcAttributes(const QString odbcAttr) { m_OdbcAttributes = odbcAttr;  }
//! void setReplicationOption 
/*! Is a setter function. Accepts a single argument as a ReplicationOption. Three selection options are possible; Bulk_Copy, Net_Change, NotSet
/*!  ODBC Attributes are delimited by Comma
/*!  ODBC Attribute support is limited to Qt 5.9 ODBC Support
\param odbcAttr is a QString argument.
\sa ReplicationOption
*/
	void			 setReplicationOption(ReplicationOption xReplicationOption) {
		m_ReplicationOption = xReplicationOption; 
	}
public slots:
	void setAbortFlag(); 
	void run();
signals:
//! void setAbortFlag 
/*! Is a setter function. A toggle - initiate an abort of the running class.
/*!  A toggle - initiate an abort of the running class.
*/
	void aborted(QString tableName, int fetchCnt,int insertCnt, int updateCnt);
//! void updateStatusFetched 
/*! Is a Qt Signal - the signal sends the parameterized values after each row is fetched.
\param tableName is a QString argument.
\param rowsFetched is a int argument.
*/
	void updateStatusFetched(QString profileName, QString tableName, int rowsFetched, int rowsInserted, int rowsUpdated);
 
private:
//! A private variable.
/*!
tableName := the table that will be processed by this class.
*/
	QString		tableName;
//! A private variable.
/*!
bIsAbort := the Abort flag that will be checked during the execution of this class. The default is false.
*/
	bool	bIsAbort=false;
//! A private variable.
/*!
	rowsFetched := the rowsFetch variable - a simple counter which is incremented after each row is successfully fetched. The default is 0.
*/
	int	rowsFetched = 0;
/*!
rowsFetched := the rowsInserted variable - a simple counter which is incremented after each row is successfully inserted. The default is 0.
*/
	int	rowsInserted = 0;
	int	rowsUpdated = 0;
	int	commitInterval=1000; // Rate at which SQLTransaction are committed

// Rate at which the object notifies the parent class
// the object has processed n rows.
 
	int	updateInterval=1000; 
	SQLINTEGER	lenAary = 0;
	SQLINTEGER	IndPtrArray = 0; 
/*!
hStmt_Insert, The ODBC Statement Handle for the Insert.
*/
	SQLHANDLE	hStmt_Insert; 
/*!
hStmt_Fetch, The ODBC Statement Handle for the Fetch.
*/
	SQLHANDLE	hStmt_Fetch;
/*!
hStmt_Update, The ODBC Statement Handle for the Update.
*/
	SQLHANDLE	hStmt_Update; 
/*!
numRowsFetched, The number of rows fetched.
*/
	SQLUINTEGER	numRowsFetched;
/*!
insertSql, The SQL statement used when preparing for row insertion.
*/
	QString	insertSql;
/*!
fetchSql, The SQL statement used when preparing for row selection.
*/
	QString	fetchSql;
/*!
updateSql, The SQL statement used when preparing for row updates.
*/
	QString	updateSql;
	SQLHDBC	hDbc_source;
	SQLHDBC	hDbc_target;
	SQLHENV	hEnv_Target;
	SQLHENV	hEnv_Source;
 
	QString	profileName;
	QString	m_lpszSourceDSN; 
	QString	m_lpszTargetDSN; 
	QString	m_lpszRepositoryDSN; 
	QString	m_OdbcAttributes; 
	bool bIsNetChange;
	bool	m_bIsOpen; 
	ReplicationOption m_ReplicationOption;
	DropOption  m_dropOption;
 
	bool prepare();
	void prepareTargetTable();
	bool bindColumn();
	bool bindParameter();
	void copyTable();
	void connect(connectionHandle connectionSource);

// FieldNames 
#pragma region Field Buffers TK_CNVHSHSET
	QByteArray	DB_ID;
	QByteArray	NVTIMESTAMP;
	QByteArray	OAREA;
	QByteArray	OPAGE;
	QByteArray	OLINE;
	QByteArray	MAREA;
	QByteArray	MPAGE;
	QByteArray	MLINE;
	SQLINTEGER	cbDB_ID;
	SQLINTEGER	cbNVTIMESTAMP;
	SQLINTEGER	cbOAREA;
	SQLINTEGER	cbOPAGE;
	SQLINTEGER	cbOLINE;
	SQLINTEGER	cbMAREA;
	SQLINTEGER	cbMPAGE;
	SQLINTEGER	cbMLINE;
#pragma endregion Field Buffers TK_CNVHSHSET

};
//!  TK_LTPHSHSET class. 
/*!
*   Executed by the Qt Threading system.
*/
class TK_LTPHSHSET : public QObject {
		Q_OBJECT 
 
 
public:
	TK_LTPHSHSET(QObject * parent = Q_NULLPTR );
	~TK_LTPHSHSET(); 
 
 
	 void setCommitInterval(int uCommitInterval) { commitInterval = uCommitInterval; }
	 void setUpdateInterval(int uUpdateInterval) { updateInterval = uUpdateInterval; }
	int rowsProcessed() { return rowsFetched; }
	void initOdbcAttributes(); 
	void initialize(); 
	QStringList m_OdbcAttributesList;
	QMap<int, nOdbcAttributesClass*> m_OdbcAttributes_Map;
//! void open taking two QString strings 
/*!
\param sourceDSN is a QString argument.
\param targetDSN is a  QString argument.
*/
	void close(); 
	void open(const QString sourceDSN, const QString targetDSN); 
	void createTable();
//! void setProfileName 
/*! Is a setter function. Accepts a single argument QString - denoting the ProfileName.
\param _profileName is a QString argument.
\sa profileName
*/
	void setProfileName(const QString _profileName) { profileName = _profileName; } 
//! A normal member taking one argument and returning an boolean value.
/*! Entry function for the class - all data synchronization operations are executed from the process function.
\param rowSSize an integer argument.
\param s a constant character pointer.
\return The success status of this synchronization operation.
*/
//! void setRepositoryString 
/*! Is a setter function. Accepts a single argument QString - denoting the DataSource Connection String of the eNVy SQL Repository.
\param _repoString is a QString argument.
\sa m_lpszRepositoryDSN
*/
	void setRepositoryString(const QString _repoString) { m_lpszRepositoryDSN = _repoString; } 
//! QString getTableName 
/*! Is a getter function which returns the table name that is processed by this class.
\sa tableName
*/
	bool process(int rowSSize); 
//! void setNetChange 
/*! Is a setter function. Toggles the data synchronization method from BulK_Copy to Net Change.
\sa bIsNetChange
*/
	QString			getTableName() {	return tableName;}
	void			setNetChange() { bIsNetChange = true; } 
//! void setDropOption 
/*! Is a setter function. Accepts a single argument DropOption - the method with which the table should be handled prior to Bulk_Copy is performed.
\param dropOption is a DropOption argument.
\sa DropOption
*/
	void			setDropOption(DropOption dropOption) { m_dropOption = dropOption;  }
//! void setOdbcAttributes 
/*! Is a setter function. Accepts a single argument as a QString.
/*!  ODBC Attributes are delimited by Comma
/*!  ODBC Attribute support is limited to Qt 5.9 ODBC Support
\param odbcAttr is a QString argument.
*/
	void			setOdbcAttributes(const QString odbcAttr) { m_OdbcAttributes = odbcAttr;  }
//! void setReplicationOption 
/*! Is a setter function. Accepts a single argument as a ReplicationOption. Three selection options are possible; Bulk_Copy, Net_Change, NotSet
/*!  ODBC Attributes are delimited by Comma
/*!  ODBC Attribute support is limited to Qt 5.9 ODBC Support
\param odbcAttr is a QString argument.
\sa ReplicationOption
*/
	void			 setReplicationOption(ReplicationOption xReplicationOption) {
		m_ReplicationOption = xReplicationOption; 
	}
public slots:
	void setAbortFlag(); 
	void run();
signals:
//! void setAbortFlag 
/*! Is a setter function. A toggle - initiate an abort of the running class.
/*!  A toggle - initiate an abort of the running class.
*/
	void aborted(QString tableName, int fetchCnt,int insertCnt, int updateCnt);
//! void updateStatusFetched 
/*! Is a Qt Signal - the signal sends the parameterized values after each row is fetched.
\param tableName is a QString argument.
\param rowsFetched is a int argument.
*/
	void updateStatusFetched(QString profileName, QString tableName, int rowsFetched, int rowsInserted, int rowsUpdated);
 
private:
//! A private variable.
/*!
tableName := the table that will be processed by this class.
*/
	QString		tableName;
//! A private variable.
/*!
bIsAbort := the Abort flag that will be checked during the execution of this class. The default is false.
*/
	bool	bIsAbort=false;
//! A private variable.
/*!
	rowsFetched := the rowsFetch variable - a simple counter which is incremented after each row is successfully fetched. The default is 0.
*/
	int	rowsFetched = 0;
/*!
rowsFetched := the rowsInserted variable - a simple counter which is incremented after each row is successfully inserted. The default is 0.
*/
	int	rowsInserted = 0;
	int	rowsUpdated = 0;
	int	commitInterval=1000; // Rate at which SQLTransaction are committed

// Rate at which the object notifies the parent class
// the object has processed n rows.
 
	int	updateInterval=1000; 
	SQLINTEGER	lenAary = 0;
	SQLINTEGER	IndPtrArray = 0; 
/*!
hStmt_Insert, The ODBC Statement Handle for the Insert.
*/
	SQLHANDLE	hStmt_Insert; 
/*!
hStmt_Fetch, The ODBC Statement Handle for the Fetch.
*/
	SQLHANDLE	hStmt_Fetch;
/*!
hStmt_Update, The ODBC Statement Handle for the Update.
*/
	SQLHANDLE	hStmt_Update; 
/*!
numRowsFetched, The number of rows fetched.
*/
	SQLUINTEGER	numRowsFetched;
/*!
insertSql, The SQL statement used when preparing for row insertion.
*/
	QString	insertSql;
/*!
fetchSql, The SQL statement used when preparing for row selection.
*/
	QString	fetchSql;
/*!
updateSql, The SQL statement used when preparing for row updates.
*/
	QString	updateSql;
	SQLHDBC	hDbc_source;
	SQLHDBC	hDbc_target;
	SQLHENV	hEnv_Target;
	SQLHENV	hEnv_Source;
 
	QString	profileName;
	QString	m_lpszSourceDSN; 
	QString	m_lpszTargetDSN; 
	QString	m_lpszRepositoryDSN; 
	QString	m_OdbcAttributes; 
	bool bIsNetChange;
	bool	m_bIsOpen; 
	ReplicationOption m_ReplicationOption;
	DropOption  m_dropOption;
 
	bool prepare();
	void prepareTargetTable();
	bool bindColumn();
	bool bindParameter();
	void copyTable();
	void connect(connectionHandle connectionSource);

// FieldNames 
#pragma region Field Buffers TK_LTPHSHSET
	QByteArray	DB_ID;
	QByteArray	NVTIMESTAMP;
	QByteArray	OAREA;
	QByteArray	OPAGE;
	QByteArray	OLINE;
	QByteArray	MAREA;
	QByteArray	MPAGE;
	QByteArray	MLINE;
	SQLINTEGER	cbDB_ID;
	SQLINTEGER	cbNVTIMESTAMP;
	SQLINTEGER	cbOAREA;
	SQLINTEGER	cbOPAGE;
	SQLINTEGER	cbOLINE;
	SQLINTEGER	cbMAREA;
	SQLINTEGER	cbMPAGE;
	SQLINTEGER	cbMLINE;
#pragma endregion Field Buffers TK_LTPHSHSET

};
//!  TK_INTPOSRTSET class. 
/*!
*   Executed by the Qt Threading system.
*/
class TK_INTPOSRTSET : public QObject {
		Q_OBJECT 
 
 
public:
	TK_INTPOSRTSET(QObject * parent = Q_NULLPTR );
	~TK_INTPOSRTSET(); 
 
 
	 void setCommitInterval(int uCommitInterval) { commitInterval = uCommitInterval; }
	 void setUpdateInterval(int uUpdateInterval) { updateInterval = uUpdateInterval; }
	int rowsProcessed() { return rowsFetched; }
	void initOdbcAttributes(); 
	void initialize(); 
	QStringList m_OdbcAttributesList;
	QMap<int, nOdbcAttributesClass*> m_OdbcAttributes_Map;
//! void open taking two QString strings 
/*!
\param sourceDSN is a QString argument.
\param targetDSN is a  QString argument.
*/
	void close(); 
	void open(const QString sourceDSN, const QString targetDSN); 
	void createTable();
//! void setProfileName 
/*! Is a setter function. Accepts a single argument QString - denoting the ProfileName.
\param _profileName is a QString argument.
\sa profileName
*/
	void setProfileName(const QString _profileName) { profileName = _profileName; } 
//! A normal member taking one argument and returning an boolean value.
/*! Entry function for the class - all data synchronization operations are executed from the process function.
\param rowSSize an integer argument.
\param s a constant character pointer.
\return The success status of this synchronization operation.
*/
//! void setRepositoryString 
/*! Is a setter function. Accepts a single argument QString - denoting the DataSource Connection String of the eNVy SQL Repository.
\param _repoString is a QString argument.
\sa m_lpszRepositoryDSN
*/
	void setRepositoryString(const QString _repoString) { m_lpszRepositoryDSN = _repoString; } 
//! QString getTableName 
/*! Is a getter function which returns the table name that is processed by this class.
\sa tableName
*/
	bool process(int rowSSize); 
//! void setNetChange 
/*! Is a setter function. Toggles the data synchronization method from BulK_Copy to Net Change.
\sa bIsNetChange
*/
	QString			getTableName() {	return tableName;}
	void			setNetChange() { bIsNetChange = true; } 
//! void setDropOption 
/*! Is a setter function. Accepts a single argument DropOption - the method with which the table should be handled prior to Bulk_Copy is performed.
\param dropOption is a DropOption argument.
\sa DropOption
*/
	void			setDropOption(DropOption dropOption) { m_dropOption = dropOption;  }
//! void setOdbcAttributes 
/*! Is a setter function. Accepts a single argument as a QString.
/*!  ODBC Attributes are delimited by Comma
/*!  ODBC Attribute support is limited to Qt 5.9 ODBC Support
\param odbcAttr is a QString argument.
*/
	void			setOdbcAttributes(const QString odbcAttr) { m_OdbcAttributes = odbcAttr;  }
//! void setReplicationOption 
/*! Is a setter function. Accepts a single argument as a ReplicationOption. Three selection options are possible; Bulk_Copy, Net_Change, NotSet
/*!  ODBC Attributes are delimited by Comma
/*!  ODBC Attribute support is limited to Qt 5.9 ODBC Support
\param odbcAttr is a QString argument.
\sa ReplicationOption
*/
	void			 setReplicationOption(ReplicationOption xReplicationOption) {
		m_ReplicationOption = xReplicationOption; 
	}
public slots:
	void setAbortFlag(); 
	void run();
signals:
//! void setAbortFlag 
/*! Is a setter function. A toggle - initiate an abort of the running class.
/*!  A toggle - initiate an abort of the running class.
*/
	void aborted(QString tableName, int fetchCnt,int insertCnt, int updateCnt);
//! void updateStatusFetched 
/*! Is a Qt Signal - the signal sends the parameterized values after each row is fetched.
\param tableName is a QString argument.
\param rowsFetched is a int argument.
*/
	void updateStatusFetched(QString profileName, QString tableName, int rowsFetched, int rowsInserted, int rowsUpdated);
 
private:
//! A private variable.
/*!
tableName := the table that will be processed by this class.
*/
	QString		tableName;
//! A private variable.
/*!
bIsAbort := the Abort flag that will be checked during the execution of this class. The default is false.
*/
	bool	bIsAbort=false;
//! A private variable.
/*!
	rowsFetched := the rowsFetch variable - a simple counter which is incremented after each row is successfully fetched. The default is 0.
*/
	int	rowsFetched = 0;
/*!
rowsFetched := the rowsInserted variable - a simple counter which is incremented after each row is successfully inserted. The default is 0.
*/
	int	rowsInserted = 0;
	int	rowsUpdated = 0;
	int	commitInterval=1000; // Rate at which SQLTransaction are committed

// Rate at which the object notifies the parent class
// the object has processed n rows.
 
	int	updateInterval=1000; 
	SQLINTEGER	lenAary = 0;
	SQLINTEGER	IndPtrArray = 0; 
/*!
hStmt_Insert, The ODBC Statement Handle for the Insert.
*/
	SQLHANDLE	hStmt_Insert; 
/*!
hStmt_Fetch, The ODBC Statement Handle for the Fetch.
*/
	SQLHANDLE	hStmt_Fetch;
/*!
hStmt_Update, The ODBC Statement Handle for the Update.
*/
	SQLHANDLE	hStmt_Update; 
/*!
numRowsFetched, The number of rows fetched.
*/
	SQLUINTEGER	numRowsFetched;
/*!
insertSql, The SQL statement used when preparing for row insertion.
*/
	QString	insertSql;
/*!
fetchSql, The SQL statement used when preparing for row selection.
*/
	QString	fetchSql;
/*!
updateSql, The SQL statement used when preparing for row updates.
*/
	QString	updateSql;
	SQLHDBC	hDbc_source;
	SQLHDBC	hDbc_target;
	SQLHENV	hEnv_Target;
	SQLHENV	hEnv_Source;
 
	QString	profileName;
	QString	m_lpszSourceDSN; 
	QString	m_lpszTargetDSN; 
	QString	m_lpszRepositoryDSN; 
	QString	m_OdbcAttributes; 
	bool bIsNetChange;
	bool	m_bIsOpen; 
	ReplicationOption m_ReplicationOption;
	DropOption  m_dropOption;
 
	bool prepare();
	void prepareTargetTable();
	bool bindColumn();
	bool bindParameter();
	void copyTable();
	void connect(connectionHandle connectionSource);

// FieldNames 
#pragma region Field Buffers TK_INTPOSRTSET
	QByteArray	DB_ID;
	QByteArray	NVTIMESTAMP;
	QByteArray	OAREA;
	QByteArray	OPAGE;
	QByteArray	OLINE;
	QByteArray	MAREA;
	QByteArray	MPAGE;
	QByteArray	MLINE;
	SQLINTEGER	cbDB_ID;
	SQLINTEGER	cbNVTIMESTAMP;
	SQLINTEGER	cbOAREA;
	SQLINTEGER	cbOPAGE;
	SQLINTEGER	cbOLINE;
	SQLINTEGER	cbMAREA;
	SQLINTEGER	cbMPAGE;
	SQLINTEGER	cbMLINE;
#pragma endregion Field Buffers TK_INTPOSRTSET

};
//!  TK_UPRTHSHSET class. 
/*!
*   Executed by the Qt Threading system.
*/
class TK_UPRTHSHSET : public QObject {
		Q_OBJECT 
 
 
public:
	TK_UPRTHSHSET(QObject * parent = Q_NULLPTR );
	~TK_UPRTHSHSET(); 
 
 
	 void setCommitInterval(int uCommitInterval) { commitInterval = uCommitInterval; }
	 void setUpdateInterval(int uUpdateInterval) { updateInterval = uUpdateInterval; }
	int rowsProcessed() { return rowsFetched; }
	void initOdbcAttributes(); 
	void initialize(); 
	QStringList m_OdbcAttributesList;
	QMap<int, nOdbcAttributesClass*> m_OdbcAttributes_Map;
//! void open taking two QString strings 
/*!
\param sourceDSN is a QString argument.
\param targetDSN is a  QString argument.
*/
	void close(); 
	void open(const QString sourceDSN, const QString targetDSN); 
	void createTable();
//! void setProfileName 
/*! Is a setter function. Accepts a single argument QString - denoting the ProfileName.
\param _profileName is a QString argument.
\sa profileName
*/
	void setProfileName(const QString _profileName) { profileName = _profileName; } 
//! A normal member taking one argument and returning an boolean value.
/*! Entry function for the class - all data synchronization operations are executed from the process function.
\param rowSSize an integer argument.
\param s a constant character pointer.
\return The success status of this synchronization operation.
*/
//! void setRepositoryString 
/*! Is a setter function. Accepts a single argument QString - denoting the DataSource Connection String of the eNVy SQL Repository.
\param _repoString is a QString argument.
\sa m_lpszRepositoryDSN
*/
	void setRepositoryString(const QString _repoString) { m_lpszRepositoryDSN = _repoString; } 
//! QString getTableName 
/*! Is a getter function which returns the table name that is processed by this class.
\sa tableName
*/
	bool process(int rowSSize); 
//! void setNetChange 
/*! Is a setter function. Toggles the data synchronization method from BulK_Copy to Net Change.
\sa bIsNetChange
*/
	QString			getTableName() {	return tableName;}
	void			setNetChange() { bIsNetChange = true; } 
//! void setDropOption 
/*! Is a setter function. Accepts a single argument DropOption - the method with which the table should be handled prior to Bulk_Copy is performed.
\param dropOption is a DropOption argument.
\sa DropOption
*/
	void			setDropOption(DropOption dropOption) { m_dropOption = dropOption;  }
//! void setOdbcAttributes 
/*! Is a setter function. Accepts a single argument as a QString.
/*!  ODBC Attributes are delimited by Comma
/*!  ODBC Attribute support is limited to Qt 5.9 ODBC Support
\param odbcAttr is a QString argument.
*/
	void			setOdbcAttributes(const QString odbcAttr) { m_OdbcAttributes = odbcAttr;  }
//! void setReplicationOption 
/*! Is a setter function. Accepts a single argument as a ReplicationOption. Three selection options are possible; Bulk_Copy, Net_Change, NotSet
/*!  ODBC Attributes are delimited by Comma
/*!  ODBC Attribute support is limited to Qt 5.9 ODBC Support
\param odbcAttr is a QString argument.
\sa ReplicationOption
*/
	void			 setReplicationOption(ReplicationOption xReplicationOption) {
		m_ReplicationOption = xReplicationOption; 
	}
public slots:
	void setAbortFlag(); 
	void run();
signals:
//! void setAbortFlag 
/*! Is a setter function. A toggle - initiate an abort of the running class.
/*!  A toggle - initiate an abort of the running class.
*/
	void aborted(QString tableName, int fetchCnt,int insertCnt, int updateCnt);
//! void updateStatusFetched 
/*! Is a Qt Signal - the signal sends the parameterized values after each row is fetched.
\param tableName is a QString argument.
\param rowsFetched is a int argument.
*/
	void updateStatusFetched(QString profileName, QString tableName, int rowsFetched, int rowsInserted, int rowsUpdated);
 
private:
//! A private variable.
/*!
tableName := the table that will be processed by this class.
*/
	QString		tableName;
//! A private variable.
/*!
bIsAbort := the Abort flag that will be checked during the execution of this class. The default is false.
*/
	bool	bIsAbort=false;
//! A private variable.
/*!
	rowsFetched := the rowsFetch variable - a simple counter which is incremented after each row is successfully fetched. The default is 0.
*/
	int	rowsFetched = 0;
/*!
rowsFetched := the rowsInserted variable - a simple counter which is incremented after each row is successfully inserted. The default is 0.
*/
	int	rowsInserted = 0;
	int	rowsUpdated = 0;
	int	commitInterval=1000; // Rate at which SQLTransaction are committed

// Rate at which the object notifies the parent class
// the object has processed n rows.
 
	int	updateInterval=1000; 
	SQLINTEGER	lenAary = 0;
	SQLINTEGER	IndPtrArray = 0; 
/*!
hStmt_Insert, The ODBC Statement Handle for the Insert.
*/
	SQLHANDLE	hStmt_Insert; 
/*!
hStmt_Fetch, The ODBC Statement Handle for the Fetch.
*/
	SQLHANDLE	hStmt_Fetch;
/*!
hStmt_Update, The ODBC Statement Handle for the Update.
*/
	SQLHANDLE	hStmt_Update; 
/*!
numRowsFetched, The number of rows fetched.
*/
	SQLUINTEGER	numRowsFetched;
/*!
insertSql, The SQL statement used when preparing for row insertion.
*/
	QString	insertSql;
/*!
fetchSql, The SQL statement used when preparing for row selection.
*/
	QString	fetchSql;
/*!
updateSql, The SQL statement used when preparing for row updates.
*/
	QString	updateSql;
	SQLHDBC	hDbc_source;
	SQLHDBC	hDbc_target;
	SQLHENV	hEnv_Target;
	SQLHENV	hEnv_Source;
 
	QString	profileName;
	QString	m_lpszSourceDSN; 
	QString	m_lpszTargetDSN; 
	QString	m_lpszRepositoryDSN; 
	QString	m_OdbcAttributes; 
	bool bIsNetChange;
	bool	m_bIsOpen; 
	ReplicationOption m_ReplicationOption;
	DropOption  m_dropOption;
 
	bool prepare();
	void prepareTargetTable();
	bool bindColumn();
	bool bindParameter();
	void copyTable();
	void connect(connectionHandle connectionSource);

// FieldNames 
#pragma region Field Buffers TK_UPRTHSHSET
	QByteArray	DB_ID;
	QByteArray	NVTIMESTAMP;
	QByteArray	OAREA;
	QByteArray	OPAGE;
	QByteArray	OLINE;
	QByteArray	MAREA;
	QByteArray	MPAGE;
	QByteArray	MLINE;
	SQLINTEGER	cbDB_ID;
	SQLINTEGER	cbNVTIMESTAMP;
	SQLINTEGER	cbOAREA;
	SQLINTEGER	cbOPAGE;
	SQLINTEGER	cbOLINE;
	SQLINTEGER	cbMAREA;
	SQLINTEGER	cbMPAGE;
	SQLINTEGER	cbMLINE;
#pragma endregion Field Buffers TK_UPRTHSHSET

};
//!  TK_LIDNOTSET class. 
/*!
*   Executed by the Qt Threading system.
*/
class TK_LIDNOTSET : public QObject {
		Q_OBJECT 
 
 
public:
	TK_LIDNOTSET(QObject * parent = Q_NULLPTR );
	~TK_LIDNOTSET(); 
 
 
	 void setCommitInterval(int uCommitInterval) { commitInterval = uCommitInterval; }
	 void setUpdateInterval(int uUpdateInterval) { updateInterval = uUpdateInterval; }
	int rowsProcessed() { return rowsFetched; }
	void initOdbcAttributes(); 
	void initialize(); 
	QStringList m_OdbcAttributesList;
	QMap<int, nOdbcAttributesClass*> m_OdbcAttributes_Map;
//! void open taking two QString strings 
/*!
\param sourceDSN is a QString argument.
\param targetDSN is a  QString argument.
*/
	void close(); 
	void open(const QString sourceDSN, const QString targetDSN); 
	void createTable();
//! void setProfileName 
/*! Is a setter function. Accepts a single argument QString - denoting the ProfileName.
\param _profileName is a QString argument.
\sa profileName
*/
	void setProfileName(const QString _profileName) { profileName = _profileName; } 
//! A normal member taking one argument and returning an boolean value.
/*! Entry function for the class - all data synchronization operations are executed from the process function.
\param rowSSize an integer argument.
\param s a constant character pointer.
\return The success status of this synchronization operation.
*/
//! void setRepositoryString 
/*! Is a setter function. Accepts a single argument QString - denoting the DataSource Connection String of the eNVy SQL Repository.
\param _repoString is a QString argument.
\sa m_lpszRepositoryDSN
*/
	void setRepositoryString(const QString _repoString) { m_lpszRepositoryDSN = _repoString; } 
//! QString getTableName 
/*! Is a getter function which returns the table name that is processed by this class.
\sa tableName
*/
	bool process(int rowSSize); 
//! void setNetChange 
/*! Is a setter function. Toggles the data synchronization method from BulK_Copy to Net Change.
\sa bIsNetChange
*/
	QString			getTableName() {	return tableName;}
	void			setNetChange() { bIsNetChange = true; } 
//! void setDropOption 
/*! Is a setter function. Accepts a single argument DropOption - the method with which the table should be handled prior to Bulk_Copy is performed.
\param dropOption is a DropOption argument.
\sa DropOption
*/
	void			setDropOption(DropOption dropOption) { m_dropOption = dropOption;  }
//! void setOdbcAttributes 
/*! Is a setter function. Accepts a single argument as a QString.
/*!  ODBC Attributes are delimited by Comma
/*!  ODBC Attribute support is limited to Qt 5.9 ODBC Support
\param odbcAttr is a QString argument.
*/
	void			setOdbcAttributes(const QString odbcAttr) { m_OdbcAttributes = odbcAttr;  }
//! void setReplicationOption 
/*! Is a setter function. Accepts a single argument as a ReplicationOption. Three selection options are possible; Bulk_Copy, Net_Change, NotSet
/*!  ODBC Attributes are delimited by Comma
/*!  ODBC Attribute support is limited to Qt 5.9 ODBC Support
\param odbcAttr is a QString argument.
\sa ReplicationOption
*/
	void			 setReplicationOption(ReplicationOption xReplicationOption) {
		m_ReplicationOption = xReplicationOption; 
	}
public slots:
	void setAbortFlag(); 
	void run();
signals:
//! void setAbortFlag 
/*! Is a setter function. A toggle - initiate an abort of the running class.
/*!  A toggle - initiate an abort of the running class.
*/
	void aborted(QString tableName, int fetchCnt,int insertCnt, int updateCnt);
//! void updateStatusFetched 
/*! Is a Qt Signal - the signal sends the parameterized values after each row is fetched.
\param tableName is a QString argument.
\param rowsFetched is a int argument.
*/
	void updateStatusFetched(QString profileName, QString tableName, int rowsFetched, int rowsInserted, int rowsUpdated);
 
private:
//! A private variable.
/*!
tableName := the table that will be processed by this class.
*/
	QString		tableName;
//! A private variable.
/*!
bIsAbort := the Abort flag that will be checked during the execution of this class. The default is false.
*/
	bool	bIsAbort=false;
//! A private variable.
/*!
	rowsFetched := the rowsFetch variable - a simple counter which is incremented after each row is successfully fetched. The default is 0.
*/
	int	rowsFetched = 0;
/*!
rowsFetched := the rowsInserted variable - a simple counter which is incremented after each row is successfully inserted. The default is 0.
*/
	int	rowsInserted = 0;
	int	rowsUpdated = 0;
	int	commitInterval=1000; // Rate at which SQLTransaction are committed

// Rate at which the object notifies the parent class
// the object has processed n rows.
 
	int	updateInterval=1000; 
	SQLINTEGER	lenAary = 0;
	SQLINTEGER	IndPtrArray = 0; 
/*!
hStmt_Insert, The ODBC Statement Handle for the Insert.
*/
	SQLHANDLE	hStmt_Insert; 
/*!
hStmt_Fetch, The ODBC Statement Handle for the Fetch.
*/
	SQLHANDLE	hStmt_Fetch;
/*!
hStmt_Update, The ODBC Statement Handle for the Update.
*/
	SQLHANDLE	hStmt_Update; 
/*!
numRowsFetched, The number of rows fetched.
*/
	SQLUINTEGER	numRowsFetched;
/*!
insertSql, The SQL statement used when preparing for row insertion.
*/
	QString	insertSql;
/*!
fetchSql, The SQL statement used when preparing for row selection.
*/
	QString	fetchSql;
/*!
updateSql, The SQL statement used when preparing for row updates.
*/
	QString	updateSql;
	SQLHDBC	hDbc_source;
	SQLHDBC	hDbc_target;
	SQLHENV	hEnv_Target;
	SQLHENV	hEnv_Source;
 
	QString	profileName;
	QString	m_lpszSourceDSN; 
	QString	m_lpszTargetDSN; 
	QString	m_lpszRepositoryDSN; 
	QString	m_OdbcAttributes; 
	bool bIsNetChange;
	bool	m_bIsOpen; 
	ReplicationOption m_ReplicationOption;
	DropOption  m_dropOption;
 
	bool prepare();
	void prepareTargetTable();
	bool bindColumn();
	bool bindParameter();
	void copyTable();
	void connect(connectionHandle connectionSource);

// FieldNames 
#pragma region Field Buffers TK_LIDNOTSET
	QByteArray	DB_ID;
	QByteArray	NVTIMESTAMP;
	QByteArray	OAREA;
	QByteArray	OPAGE;
	QByteArray	OLINE;
	QByteArray	MAREA;
	QByteArray	MPAGE;
	QByteArray	MLINE;
	SQLINTEGER	cbDB_ID;
	SQLINTEGER	cbNVTIMESTAMP;
	SQLINTEGER	cbOAREA;
	SQLINTEGER	cbOPAGE;
	SQLINTEGER	cbOLINE;
	SQLINTEGER	cbMAREA;
	SQLINTEGER	cbMPAGE;
	SQLINTEGER	cbMLINE;
#pragma endregion Field Buffers TK_LIDNOTSET

};
//!  TK_INTTOHSHSET class. 
/*!
*   Executed by the Qt Threading system.
*/
class TK_INTTOHSHSET : public QObject {
		Q_OBJECT 
 
 
public:
	TK_INTTOHSHSET(QObject * parent = Q_NULLPTR );
	~TK_INTTOHSHSET(); 
 
 
	 void setCommitInterval(int uCommitInterval) { commitInterval = uCommitInterval; }
	 void setUpdateInterval(int uUpdateInterval) { updateInterval = uUpdateInterval; }
	int rowsProcessed() { return rowsFetched; }
	void initOdbcAttributes(); 
	void initialize(); 
	QStringList m_OdbcAttributesList;
	QMap<int, nOdbcAttributesClass*> m_OdbcAttributes_Map;
//! void open taking two QString strings 
/*!
\param sourceDSN is a QString argument.
\param targetDSN is a  QString argument.
*/
	void close(); 
	void open(const QString sourceDSN, const QString targetDSN); 
	void createTable();
//! void setProfileName 
/*! Is a setter function. Accepts a single argument QString - denoting the ProfileName.
\param _profileName is a QString argument.
\sa profileName
*/
	void setProfileName(const QString _profileName) { profileName = _profileName; } 
//! A normal member taking one argument and returning an boolean value.
/*! Entry function for the class - all data synchronization operations are executed from the process function.
\param rowSSize an integer argument.
\param s a constant character pointer.
\return The success status of this synchronization operation.
*/
//! void setRepositoryString 
/*! Is a setter function. Accepts a single argument QString - denoting the DataSource Connection String of the eNVy SQL Repository.
\param _repoString is a QString argument.
\sa m_lpszRepositoryDSN
*/
	void setRepositoryString(const QString _repoString) { m_lpszRepositoryDSN = _repoString; } 
//! QString getTableName 
/*! Is a getter function which returns the table name that is processed by this class.
\sa tableName
*/
	bool process(int rowSSize); 
//! void setNetChange 
/*! Is a setter function. Toggles the data synchronization method from BulK_Copy to Net Change.
\sa bIsNetChange
*/
	QString			getTableName() {	return tableName;}
	void			setNetChange() { bIsNetChange = true; } 
//! void setDropOption 
/*! Is a setter function. Accepts a single argument DropOption - the method with which the table should be handled prior to Bulk_Copy is performed.
\param dropOption is a DropOption argument.
\sa DropOption
*/
	void			setDropOption(DropOption dropOption) { m_dropOption = dropOption;  }
//! void setOdbcAttributes 
/*! Is a setter function. Accepts a single argument as a QString.
/*!  ODBC Attributes are delimited by Comma
/*!  ODBC Attribute support is limited to Qt 5.9 ODBC Support
\param odbcAttr is a QString argument.
*/
	void			setOdbcAttributes(const QString odbcAttr) { m_OdbcAttributes = odbcAttr;  }
//! void setReplicationOption 
/*! Is a setter function. Accepts a single argument as a ReplicationOption. Three selection options are possible; Bulk_Copy, Net_Change, NotSet
/*!  ODBC Attributes are delimited by Comma
/*!  ODBC Attribute support is limited to Qt 5.9 ODBC Support
\param odbcAttr is a QString argument.
\sa ReplicationOption
*/
	void			 setReplicationOption(ReplicationOption xReplicationOption) {
		m_ReplicationOption = xReplicationOption; 
	}
public slots:
	void setAbortFlag(); 
	void run();
signals:
//! void setAbortFlag 
/*! Is a setter function. A toggle - initiate an abort of the running class.
/*!  A toggle - initiate an abort of the running class.
*/
	void aborted(QString tableName, int fetchCnt,int insertCnt, int updateCnt);
//! void updateStatusFetched 
/*! Is a Qt Signal - the signal sends the parameterized values after each row is fetched.
\param tableName is a QString argument.
\param rowsFetched is a int argument.
*/
	void updateStatusFetched(QString profileName, QString tableName, int rowsFetched, int rowsInserted, int rowsUpdated);
 
private:
//! A private variable.
/*!
tableName := the table that will be processed by this class.
*/
	QString		tableName;
//! A private variable.
/*!
bIsAbort := the Abort flag that will be checked during the execution of this class. The default is false.
*/
	bool	bIsAbort=false;
//! A private variable.
/*!
	rowsFetched := the rowsFetch variable - a simple counter which is incremented after each row is successfully fetched. The default is 0.
*/
	int	rowsFetched = 0;
/*!
rowsFetched := the rowsInserted variable - a simple counter which is incremented after each row is successfully inserted. The default is 0.
*/
	int	rowsInserted = 0;
	int	rowsUpdated = 0;
	int	commitInterval=1000; // Rate at which SQLTransaction are committed

// Rate at which the object notifies the parent class
// the object has processed n rows.
 
	int	updateInterval=1000; 
	SQLINTEGER	lenAary = 0;
	SQLINTEGER	IndPtrArray = 0; 
/*!
hStmt_Insert, The ODBC Statement Handle for the Insert.
*/
	SQLHANDLE	hStmt_Insert; 
/*!
hStmt_Fetch, The ODBC Statement Handle for the Fetch.
*/
	SQLHANDLE	hStmt_Fetch;
/*!
hStmt_Update, The ODBC Statement Handle for the Update.
*/
	SQLHANDLE	hStmt_Update; 
/*!
numRowsFetched, The number of rows fetched.
*/
	SQLUINTEGER	numRowsFetched;
/*!
insertSql, The SQL statement used when preparing for row insertion.
*/
	QString	insertSql;
/*!
fetchSql, The SQL statement used when preparing for row selection.
*/
	QString	fetchSql;
/*!
updateSql, The SQL statement used when preparing for row updates.
*/
	QString	updateSql;
	SQLHDBC	hDbc_source;
	SQLHDBC	hDbc_target;
	SQLHENV	hEnv_Target;
	SQLHENV	hEnv_Source;
 
	QString	profileName;
	QString	m_lpszSourceDSN; 
	QString	m_lpszTargetDSN; 
	QString	m_lpszRepositoryDSN; 
	QString	m_OdbcAttributes; 
	bool bIsNetChange;
	bool	m_bIsOpen; 
	ReplicationOption m_ReplicationOption;
	DropOption  m_dropOption;
 
	bool prepare();
	void prepareTargetTable();
	bool bindColumn();
	bool bindParameter();
	void copyTable();
	void connect(connectionHandle connectionSource);

// FieldNames 
#pragma region Field Buffers TK_INTTOHSHSET
	QByteArray	DB_ID;
	QByteArray	NVTIMESTAMP;
	QByteArray	OAREA;
	QByteArray	OPAGE;
	QByteArray	OLINE;
	QByteArray	MAREA;
	QByteArray	MPAGE;
	QByteArray	MLINE;
	SQLINTEGER	cbDB_ID;
	SQLINTEGER	cbNVTIMESTAMP;
	SQLINTEGER	cbOAREA;
	SQLINTEGER	cbOPAGE;
	SQLINTEGER	cbOLINE;
	SQLINTEGER	cbMAREA;
	SQLINTEGER	cbMPAGE;
	SQLINTEGER	cbMLINE;
#pragma endregion Field Buffers TK_INTTOHSHSET

};
//!  TK_FLGHSHSET class. 
/*!
*   Executed by the Qt Threading system.
*/
class TK_FLGHSHSET : public QObject {
		Q_OBJECT 
 
 
public:
	TK_FLGHSHSET(QObject * parent = Q_NULLPTR );
	~TK_FLGHSHSET(); 
 
 
	 void setCommitInterval(int uCommitInterval) { commitInterval = uCommitInterval; }
	 void setUpdateInterval(int uUpdateInterval) { updateInterval = uUpdateInterval; }
	int rowsProcessed() { return rowsFetched; }
	void initOdbcAttributes(); 
	void initialize(); 
	QStringList m_OdbcAttributesList;
	QMap<int, nOdbcAttributesClass*> m_OdbcAttributes_Map;
//! void open taking two QString strings 
/*!
\param sourceDSN is a QString argument.
\param targetDSN is a  QString argument.
*/
	void close(); 
	void open(const QString sourceDSN, const QString targetDSN); 
	void createTable();
//! void setProfileName 
/*! Is a setter function. Accepts a single argument QString - denoting the ProfileName.
\param _profileName is a QString argument.
\sa profileName
*/
	void setProfileName(const QString _profileName) { profileName = _profileName; } 
//! A normal member taking one argument and returning an boolean value.
/*! Entry function for the class - all data synchronization operations are executed from the process function.
\param rowSSize an integer argument.
\param s a constant character pointer.
\return The success status of this synchronization operation.
*/
//! void setRepositoryString 
/*! Is a setter function. Accepts a single argument QString - denoting the DataSource Connection String of the eNVy SQL Repository.
\param _repoString is a QString argument.
\sa m_lpszRepositoryDSN
*/
	void setRepositoryString(const QString _repoString) { m_lpszRepositoryDSN = _repoString; } 
//! QString getTableName 
/*! Is a getter function which returns the table name that is processed by this class.
\sa tableName
*/
	bool process(int rowSSize); 
//! void setNetChange 
/*! Is a setter function. Toggles the data synchronization method from BulK_Copy to Net Change.
\sa bIsNetChange
*/
	QString			getTableName() {	return tableName;}
	void			setNetChange() { bIsNetChange = true; } 
//! void setDropOption 
/*! Is a setter function. Accepts a single argument DropOption - the method with which the table should be handled prior to Bulk_Copy is performed.
\param dropOption is a DropOption argument.
\sa DropOption
*/
	void			setDropOption(DropOption dropOption) { m_dropOption = dropOption;  }
//! void setOdbcAttributes 
/*! Is a setter function. Accepts a single argument as a QString.
/*!  ODBC Attributes are delimited by Comma
/*!  ODBC Attribute support is limited to Qt 5.9 ODBC Support
\param odbcAttr is a QString argument.
*/
	void			setOdbcAttributes(const QString odbcAttr) { m_OdbcAttributes = odbcAttr;  }
//! void setReplicationOption 
/*! Is a setter function. Accepts a single argument as a ReplicationOption. Three selection options are possible; Bulk_Copy, Net_Change, NotSet
/*!  ODBC Attributes are delimited by Comma
/*!  ODBC Attribute support is limited to Qt 5.9 ODBC Support
\param odbcAttr is a QString argument.
\sa ReplicationOption
*/
	void			 setReplicationOption(ReplicationOption xReplicationOption) {
		m_ReplicationOption = xReplicationOption; 
	}
public slots:
	void setAbortFlag(); 
	void run();
signals:
//! void setAbortFlag 
/*! Is a setter function. A toggle - initiate an abort of the running class.
/*!  A toggle - initiate an abort of the running class.
*/
	void aborted(QString tableName, int fetchCnt,int insertCnt, int updateCnt);
//! void updateStatusFetched 
/*! Is a Qt Signal - the signal sends the parameterized values after each row is fetched.
\param tableName is a QString argument.
\param rowsFetched is a int argument.
*/
	void updateStatusFetched(QString profileName, QString tableName, int rowsFetched, int rowsInserted, int rowsUpdated);
 
private:
//! A private variable.
/*!
tableName := the table that will be processed by this class.
*/
	QString		tableName;
//! A private variable.
/*!
bIsAbort := the Abort flag that will be checked during the execution of this class. The default is false.
*/
	bool	bIsAbort=false;
//! A private variable.
/*!
	rowsFetched := the rowsFetch variable - a simple counter which is incremented after each row is successfully fetched. The default is 0.
*/
	int	rowsFetched = 0;
/*!
rowsFetched := the rowsInserted variable - a simple counter which is incremented after each row is successfully inserted. The default is 0.
*/
	int	rowsInserted = 0;
	int	rowsUpdated = 0;
	int	commitInterval=1000; // Rate at which SQLTransaction are committed

// Rate at which the object notifies the parent class
// the object has processed n rows.
 
	int	updateInterval=1000; 
	SQLINTEGER	lenAary = 0;
	SQLINTEGER	IndPtrArray = 0; 
/*!
hStmt_Insert, The ODBC Statement Handle for the Insert.
*/
	SQLHANDLE	hStmt_Insert; 
/*!
hStmt_Fetch, The ODBC Statement Handle for the Fetch.
*/
	SQLHANDLE	hStmt_Fetch;
/*!
hStmt_Update, The ODBC Statement Handle for the Update.
*/
	SQLHANDLE	hStmt_Update; 
/*!
numRowsFetched, The number of rows fetched.
*/
	SQLUINTEGER	numRowsFetched;
/*!
insertSql, The SQL statement used when preparing for row insertion.
*/
	QString	insertSql;
/*!
fetchSql, The SQL statement used when preparing for row selection.
*/
	QString	fetchSql;
/*!
updateSql, The SQL statement used when preparing for row updates.
*/
	QString	updateSql;
	SQLHDBC	hDbc_source;
	SQLHDBC	hDbc_target;
	SQLHENV	hEnv_Target;
	SQLHENV	hEnv_Source;
 
	QString	profileName;
	QString	m_lpszSourceDSN; 
	QString	m_lpszTargetDSN; 
	QString	m_lpszRepositoryDSN; 
	QString	m_OdbcAttributes; 
	bool bIsNetChange;
	bool	m_bIsOpen; 
	ReplicationOption m_ReplicationOption;
	DropOption  m_dropOption;
 
	bool prepare();
	void prepareTargetTable();
	bool bindColumn();
	bool bindParameter();
	void copyTable();
	void connect(connectionHandle connectionSource);

// FieldNames 
#pragma region Field Buffers TK_FLGHSHSET
	QByteArray	DB_ID;
	QByteArray	NVTIMESTAMP;
	QByteArray	OAREA;
	QByteArray	OPAGE;
	QByteArray	OLINE;
	QByteArray	MAREA;
	QByteArray	MPAGE;
	QByteArray	MLINE;
	SQLINTEGER	cbDB_ID;
	SQLINTEGER	cbNVTIMESTAMP;
	SQLINTEGER	cbOAREA;
	SQLINTEGER	cbOPAGE;
	SQLINTEGER	cbOLINE;
	SQLINTEGER	cbMAREA;
	SQLINTEGER	cbMPAGE;
	SQLINTEGER	cbMLINE;
#pragma endregion Field Buffers TK_FLGHSHSET

};
//!  TK_INTCHNSET class. 
/*!
*   Executed by the Qt Threading system.
*/
class TK_INTCHNSET : public QObject {
		Q_OBJECT 
 
 
public:
	TK_INTCHNSET(QObject * parent = Q_NULLPTR );
	~TK_INTCHNSET(); 
 
 
	 void setCommitInterval(int uCommitInterval) { commitInterval = uCommitInterval; }
	 void setUpdateInterval(int uUpdateInterval) { updateInterval = uUpdateInterval; }
	int rowsProcessed() { return rowsFetched; }
	void initOdbcAttributes(); 
	void initialize(); 
	QStringList m_OdbcAttributesList;
	QMap<int, nOdbcAttributesClass*> m_OdbcAttributes_Map;
//! void open taking two QString strings 
/*!
\param sourceDSN is a QString argument.
\param targetDSN is a  QString argument.
*/
	void close(); 
	void open(const QString sourceDSN, const QString targetDSN); 
	void createTable();
//! void setProfileName 
/*! Is a setter function. Accepts a single argument QString - denoting the ProfileName.
\param _profileName is a QString argument.
\sa profileName
*/
	void setProfileName(const QString _profileName) { profileName = _profileName; } 
//! A normal member taking one argument and returning an boolean value.
/*! Entry function for the class - all data synchronization operations are executed from the process function.
\param rowSSize an integer argument.
\param s a constant character pointer.
\return The success status of this synchronization operation.
*/
//! void setRepositoryString 
/*! Is a setter function. Accepts a single argument QString - denoting the DataSource Connection String of the eNVy SQL Repository.
\param _repoString is a QString argument.
\sa m_lpszRepositoryDSN
*/
	void setRepositoryString(const QString _repoString) { m_lpszRepositoryDSN = _repoString; } 
//! QString getTableName 
/*! Is a getter function which returns the table name that is processed by this class.
\sa tableName
*/
	bool process(int rowSSize); 
//! void setNetChange 
/*! Is a setter function. Toggles the data synchronization method from BulK_Copy to Net Change.
\sa bIsNetChange
*/
	QString			getTableName() {	return tableName;}
	void			setNetChange() { bIsNetChange = true; } 
//! void setDropOption 
/*! Is a setter function. Accepts a single argument DropOption - the method with which the table should be handled prior to Bulk_Copy is performed.
\param dropOption is a DropOption argument.
\sa DropOption
*/
	void			setDropOption(DropOption dropOption) { m_dropOption = dropOption;  }
//! void setOdbcAttributes 
/*! Is a setter function. Accepts a single argument as a QString.
/*!  ODBC Attributes are delimited by Comma
/*!  ODBC Attribute support is limited to Qt 5.9 ODBC Support
\param odbcAttr is a QString argument.
*/
	void			setOdbcAttributes(const QString odbcAttr) { m_OdbcAttributes = odbcAttr;  }
//! void setReplicationOption 
/*! Is a setter function. Accepts a single argument as a ReplicationOption. Three selection options are possible; Bulk_Copy, Net_Change, NotSet
/*!  ODBC Attributes are delimited by Comma
/*!  ODBC Attribute support is limited to Qt 5.9 ODBC Support
\param odbcAttr is a QString argument.
\sa ReplicationOption
*/
	void			 setReplicationOption(ReplicationOption xReplicationOption) {
		m_ReplicationOption = xReplicationOption; 
	}
public slots:
	void setAbortFlag(); 
	void run();
signals:
//! void setAbortFlag 
/*! Is a setter function. A toggle - initiate an abort of the running class.
/*!  A toggle - initiate an abort of the running class.
*/
	void aborted(QString tableName, int fetchCnt,int insertCnt, int updateCnt);
//! void updateStatusFetched 
/*! Is a Qt Signal - the signal sends the parameterized values after each row is fetched.
\param tableName is a QString argument.
\param rowsFetched is a int argument.
*/
	void updateStatusFetched(QString profileName, QString tableName, int rowsFetched, int rowsInserted, int rowsUpdated);
 
private:
//! A private variable.
/*!
tableName := the table that will be processed by this class.
*/
	QString		tableName;
//! A private variable.
/*!
bIsAbort := the Abort flag that will be checked during the execution of this class. The default is false.
*/
	bool	bIsAbort=false;
//! A private variable.
/*!
	rowsFetched := the rowsFetch variable - a simple counter which is incremented after each row is successfully fetched. The default is 0.
*/
	int	rowsFetched = 0;
/*!
rowsFetched := the rowsInserted variable - a simple counter which is incremented after each row is successfully inserted. The default is 0.
*/
	int	rowsInserted = 0;
	int	rowsUpdated = 0;
	int	commitInterval=1000; // Rate at which SQLTransaction are committed

// Rate at which the object notifies the parent class
// the object has processed n rows.
 
	int	updateInterval=1000; 
	SQLINTEGER	lenAary = 0;
	SQLINTEGER	IndPtrArray = 0; 
/*!
hStmt_Insert, The ODBC Statement Handle for the Insert.
*/
	SQLHANDLE	hStmt_Insert; 
/*!
hStmt_Fetch, The ODBC Statement Handle for the Fetch.
*/
	SQLHANDLE	hStmt_Fetch;
/*!
hStmt_Update, The ODBC Statement Handle for the Update.
*/
	SQLHANDLE	hStmt_Update; 
/*!
numRowsFetched, The number of rows fetched.
*/
	SQLUINTEGER	numRowsFetched;
/*!
insertSql, The SQL statement used when preparing for row insertion.
*/
	QString	insertSql;
/*!
fetchSql, The SQL statement used when preparing for row selection.
*/
	QString	fetchSql;
/*!
updateSql, The SQL statement used when preparing for row updates.
*/
	QString	updateSql;
	SQLHDBC	hDbc_source;
	SQLHDBC	hDbc_target;
	SQLHENV	hEnv_Target;
	SQLHENV	hEnv_Source;
 
	QString	profileName;
	QString	m_lpszSourceDSN; 
	QString	m_lpszTargetDSN; 
	QString	m_lpszRepositoryDSN; 
	QString	m_OdbcAttributes; 
	bool bIsNetChange;
	bool	m_bIsOpen; 
	ReplicationOption m_ReplicationOption;
	DropOption  m_dropOption;
 
	bool prepare();
	void prepareTargetTable();
	bool bindColumn();
	bool bindParameter();
	void copyTable();
	void connect(connectionHandle connectionSource);

// FieldNames 
#pragma region Field Buffers TK_INTCHNSET
	QByteArray	DB_ID;
	QByteArray	NVTIMESTAMP;
	QByteArray	OAREA;
	QByteArray	OPAGE;
	QByteArray	OLINE;
	QByteArray	MAREA;
	QByteArray	MPAGE;
	QByteArray	MLINE;
	SQLINTEGER	cbDB_ID;
	SQLINTEGER	cbNVTIMESTAMP;
	SQLINTEGER	cbOAREA;
	SQLINTEGER	cbOPAGE;
	SQLINTEGER	cbOLINE;
	SQLINTEGER	cbMAREA;
	SQLINTEGER	cbMPAGE;
	SQLINTEGER	cbMLINE;
#pragma endregion Field Buffers TK_INTCHNSET

};
//!  TK_LOTREC class. 
/*!
*   Executed by the Qt Threading system.
*/
class TK_LOTREC : public QObject {
		Q_OBJECT 
 
 
public:
	TK_LOTREC(QObject * parent = Q_NULLPTR );
	~TK_LOTREC(); 
 
 
	 void setCommitInterval(int uCommitInterval) { commitInterval = uCommitInterval; }
	 void setUpdateInterval(int uUpdateInterval) { updateInterval = uUpdateInterval; }
	int rowsProcessed() { return rowsFetched; }
	void initOdbcAttributes(); 
	void initialize(); 
	QStringList m_OdbcAttributesList;
	QMap<int, nOdbcAttributesClass*> m_OdbcAttributes_Map;
//! void open taking two QString strings 
/*!
\param sourceDSN is a QString argument.
\param targetDSN is a  QString argument.
*/
	void close(); 
	void open(const QString sourceDSN, const QString targetDSN); 
	void createTable();
//! void setProfileName 
/*! Is a setter function. Accepts a single argument QString - denoting the ProfileName.
\param _profileName is a QString argument.
\sa profileName
*/
	void setProfileName(const QString _profileName) { profileName = _profileName; } 
//! A normal member taking one argument and returning an boolean value.
/*! Entry function for the class - all data synchronization operations are executed from the process function.
\param rowSSize an integer argument.
\param s a constant character pointer.
\return The success status of this synchronization operation.
*/
//! void setRepositoryString 
/*! Is a setter function. Accepts a single argument QString - denoting the DataSource Connection String of the eNVy SQL Repository.
\param _repoString is a QString argument.
\sa m_lpszRepositoryDSN
*/
	void setRepositoryString(const QString _repoString) { m_lpszRepositoryDSN = _repoString; } 
//! QString getTableName 
/*! Is a getter function which returns the table name that is processed by this class.
\sa tableName
*/
	bool process(int rowSSize); 
//! void setNetChange 
/*! Is a setter function. Toggles the data synchronization method from BulK_Copy to Net Change.
\sa bIsNetChange
*/
	QString			getTableName() {	return tableName;}
	void			setNetChange() { bIsNetChange = true; } 
//! void setDropOption 
/*! Is a setter function. Accepts a single argument DropOption - the method with which the table should be handled prior to Bulk_Copy is performed.
\param dropOption is a DropOption argument.
\sa DropOption
*/
	void			setDropOption(DropOption dropOption) { m_dropOption = dropOption;  }
//! void setOdbcAttributes 
/*! Is a setter function. Accepts a single argument as a QString.
/*!  ODBC Attributes are delimited by Comma
/*!  ODBC Attribute support is limited to Qt 5.9 ODBC Support
\param odbcAttr is a QString argument.
*/
	void			setOdbcAttributes(const QString odbcAttr) { m_OdbcAttributes = odbcAttr;  }
//! void setReplicationOption 
/*! Is a setter function. Accepts a single argument as a ReplicationOption. Three selection options are possible; Bulk_Copy, Net_Change, NotSet
/*!  ODBC Attributes are delimited by Comma
/*!  ODBC Attribute support is limited to Qt 5.9 ODBC Support
\param odbcAttr is a QString argument.
\sa ReplicationOption
*/
	void			 setReplicationOption(ReplicationOption xReplicationOption) {
		m_ReplicationOption = xReplicationOption; 
	}
public slots:
	void setAbortFlag(); 
	void run();
signals:
//! void setAbortFlag 
/*! Is a setter function. A toggle - initiate an abort of the running class.
/*!  A toggle - initiate an abort of the running class.
*/
	void aborted(QString tableName, int fetchCnt,int insertCnt, int updateCnt);
//! void updateStatusFetched 
/*! Is a Qt Signal - the signal sends the parameterized values after each row is fetched.
\param tableName is a QString argument.
\param rowsFetched is a int argument.
*/
	void updateStatusFetched(QString profileName, QString tableName, int rowsFetched, int rowsInserted, int rowsUpdated);
 
private:
//! A private variable.
/*!
tableName := the table that will be processed by this class.
*/
	QString		tableName;
//! A private variable.
/*!
bIsAbort := the Abort flag that will be checked during the execution of this class. The default is false.
*/
	bool	bIsAbort=false;
//! A private variable.
/*!
	rowsFetched := the rowsFetch variable - a simple counter which is incremented after each row is successfully fetched. The default is 0.
*/
	int	rowsFetched = 0;
/*!
rowsFetched := the rowsInserted variable - a simple counter which is incremented after each row is successfully inserted. The default is 0.
*/
	int	rowsInserted = 0;
	int	rowsUpdated = 0;
	int	commitInterval=1000; // Rate at which SQLTransaction are committed

// Rate at which the object notifies the parent class
// the object has processed n rows.
 
	int	updateInterval=1000; 
	SQLINTEGER	lenAary = 0;
	SQLINTEGER	IndPtrArray = 0; 
/*!
hStmt_Insert, The ODBC Statement Handle for the Insert.
*/
	SQLHANDLE	hStmt_Insert; 
/*!
hStmt_Fetch, The ODBC Statement Handle for the Fetch.
*/
	SQLHANDLE	hStmt_Fetch;
/*!
hStmt_Update, The ODBC Statement Handle for the Update.
*/
	SQLHANDLE	hStmt_Update; 
/*!
numRowsFetched, The number of rows fetched.
*/
	SQLUINTEGER	numRowsFetched;
/*!
insertSql, The SQL statement used when preparing for row insertion.
*/
	QString	insertSql;
/*!
fetchSql, The SQL statement used when preparing for row selection.
*/
	QString	fetchSql;
/*!
updateSql, The SQL statement used when preparing for row updates.
*/
	QString	updateSql;
	SQLHDBC	hDbc_source;
	SQLHDBC	hDbc_target;
	SQLHENV	hEnv_Target;
	SQLHENV	hEnv_Source;
 
	QString	profileName;
	QString	m_lpszSourceDSN; 
	QString	m_lpszTargetDSN; 
	QString	m_lpszRepositoryDSN; 
	QString	m_OdbcAttributes; 
	bool bIsNetChange;
	bool	m_bIsOpen; 
	ReplicationOption m_ReplicationOption;
	DropOption  m_dropOption;
 
	bool prepare();
	void prepareTargetTable();
	bool bindColumn();
	bool bindParameter();
	void copyTable();
	void connect(connectionHandle connectionSource);

// FieldNames 
#pragma region Field Buffers TK_LOTREC
	QByteArray	DB_ID;
	QByteArray	NVTIMESTAMP;
	QByteArray	AREA;
	QByteArray	PAGE;
	QByteArray	LINE;
	QByteArray	TK_LOTNO;
	SQLINTEGER	cbDB_ID;
	SQLINTEGER	cbNVTIMESTAMP;
	SQLINTEGER	cbAREA;
	SQLINTEGER	cbPAGE;
	SQLINTEGER	cbLINE;
	SQLINTEGER	cbTK_LOTNO;
#pragma endregion Field Buffers TK_LOTREC

};
//!  TK_TYPHDRSET class. 
/*!
*   Executed by the Qt Threading system.
*/
class TK_TYPHDRSET : public QObject {
		Q_OBJECT 
 
 
public:
	TK_TYPHDRSET(QObject * parent = Q_NULLPTR );
	~TK_TYPHDRSET(); 
 
 
	 void setCommitInterval(int uCommitInterval) { commitInterval = uCommitInterval; }
	 void setUpdateInterval(int uUpdateInterval) { updateInterval = uUpdateInterval; }
	int rowsProcessed() { return rowsFetched; }
	void initOdbcAttributes(); 
	void initialize(); 
	QStringList m_OdbcAttributesList;
	QMap<int, nOdbcAttributesClass*> m_OdbcAttributes_Map;
//! void open taking two QString strings 
/*!
\param sourceDSN is a QString argument.
\param targetDSN is a  QString argument.
*/
	void close(); 
	void open(const QString sourceDSN, const QString targetDSN); 
	void createTable();
//! void setProfileName 
/*! Is a setter function. Accepts a single argument QString - denoting the ProfileName.
\param _profileName is a QString argument.
\sa profileName
*/
	void setProfileName(const QString _profileName) { profileName = _profileName; } 
//! A normal member taking one argument and returning an boolean value.
/*! Entry function for the class - all data synchronization operations are executed from the process function.
\param rowSSize an integer argument.
\param s a constant character pointer.
\return The success status of this synchronization operation.
*/
//! void setRepositoryString 
/*! Is a setter function. Accepts a single argument QString - denoting the DataSource Connection String of the eNVy SQL Repository.
\param _repoString is a QString argument.
\sa m_lpszRepositoryDSN
*/
	void setRepositoryString(const QString _repoString) { m_lpszRepositoryDSN = _repoString; } 
//! QString getTableName 
/*! Is a getter function which returns the table name that is processed by this class.
\sa tableName
*/
	bool process(int rowSSize); 
//! void setNetChange 
/*! Is a setter function. Toggles the data synchronization method from BulK_Copy to Net Change.
\sa bIsNetChange
*/
	QString			getTableName() {	return tableName;}
	void			setNetChange() { bIsNetChange = true; } 
//! void setDropOption 
/*! Is a setter function. Accepts a single argument DropOption - the method with which the table should be handled prior to Bulk_Copy is performed.
\param dropOption is a DropOption argument.
\sa DropOption
*/
	void			setDropOption(DropOption dropOption) { m_dropOption = dropOption;  }
//! void setOdbcAttributes 
/*! Is a setter function. Accepts a single argument as a QString.
/*!  ODBC Attributes are delimited by Comma
/*!  ODBC Attribute support is limited to Qt 5.9 ODBC Support
\param odbcAttr is a QString argument.
*/
	void			setOdbcAttributes(const QString odbcAttr) { m_OdbcAttributes = odbcAttr;  }
//! void setReplicationOption 
/*! Is a setter function. Accepts a single argument as a ReplicationOption. Three selection options are possible; Bulk_Copy, Net_Change, NotSet
/*!  ODBC Attributes are delimited by Comma
/*!  ODBC Attribute support is limited to Qt 5.9 ODBC Support
\param odbcAttr is a QString argument.
\sa ReplicationOption
*/
	void			 setReplicationOption(ReplicationOption xReplicationOption) {
		m_ReplicationOption = xReplicationOption; 
	}
public slots:
	void setAbortFlag(); 
	void run();
signals:
//! void setAbortFlag 
/*! Is a setter function. A toggle - initiate an abort of the running class.
/*!  A toggle - initiate an abort of the running class.
*/
	void aborted(QString tableName, int fetchCnt,int insertCnt, int updateCnt);
//! void updateStatusFetched 
/*! Is a Qt Signal - the signal sends the parameterized values after each row is fetched.
\param tableName is a QString argument.
\param rowsFetched is a int argument.
*/
	void updateStatusFetched(QString profileName, QString tableName, int rowsFetched, int rowsInserted, int rowsUpdated);
 
private:
//! A private variable.
/*!
tableName := the table that will be processed by this class.
*/
	QString		tableName;
//! A private variable.
/*!
bIsAbort := the Abort flag that will be checked during the execution of this class. The default is false.
*/
	bool	bIsAbort=false;
//! A private variable.
/*!
	rowsFetched := the rowsFetch variable - a simple counter which is incremented after each row is successfully fetched. The default is 0.
*/
	int	rowsFetched = 0;
/*!
rowsFetched := the rowsInserted variable - a simple counter which is incremented after each row is successfully inserted. The default is 0.
*/
	int	rowsInserted = 0;
	int	rowsUpdated = 0;
	int	commitInterval=1000; // Rate at which SQLTransaction are committed

// Rate at which the object notifies the parent class
// the object has processed n rows.
 
	int	updateInterval=1000; 
	SQLINTEGER	lenAary = 0;
	SQLINTEGER	IndPtrArray = 0; 
/*!
hStmt_Insert, The ODBC Statement Handle for the Insert.
*/
	SQLHANDLE	hStmt_Insert; 
/*!
hStmt_Fetch, The ODBC Statement Handle for the Fetch.
*/
	SQLHANDLE	hStmt_Fetch;
/*!
hStmt_Update, The ODBC Statement Handle for the Update.
*/
	SQLHANDLE	hStmt_Update; 
/*!
numRowsFetched, The number of rows fetched.
*/
	SQLUINTEGER	numRowsFetched;
/*!
insertSql, The SQL statement used when preparing for row insertion.
*/
	QString	insertSql;
/*!
fetchSql, The SQL statement used when preparing for row selection.
*/
	QString	fetchSql;
/*!
updateSql, The SQL statement used when preparing for row updates.
*/
	QString	updateSql;
	SQLHDBC	hDbc_source;
	SQLHDBC	hDbc_target;
	SQLHENV	hEnv_Target;
	SQLHENV	hEnv_Source;
 
	QString	profileName;
	QString	m_lpszSourceDSN; 
	QString	m_lpszTargetDSN; 
	QString	m_lpszRepositoryDSN; 
	QString	m_OdbcAttributes; 
	bool bIsNetChange;
	bool	m_bIsOpen; 
	ReplicationOption m_ReplicationOption;
	DropOption  m_dropOption;
 
	bool prepare();
	void prepareTargetTable();
	bool bindColumn();
	bool bindParameter();
	void copyTable();
	void connect(connectionHandle connectionSource);

// FieldNames 
#pragma region Field Buffers TK_TYPHDRSET
	QByteArray	DB_ID;
	QByteArray	NVTIMESTAMP;
	QByteArray	OAREA;
	QByteArray	OPAGE;
	QByteArray	OLINE;
	QByteArray	MAREA;
	QByteArray	MPAGE;
	QByteArray	MLINE;
	SQLINTEGER	cbDB_ID;
	SQLINTEGER	cbNVTIMESTAMP;
	SQLINTEGER	cbOAREA;
	SQLINTEGER	cbOPAGE;
	SQLINTEGER	cbOLINE;
	SQLINTEGER	cbMAREA;
	SQLINTEGER	cbMPAGE;
	SQLINTEGER	cbMLINE;
#pragma endregion Field Buffers TK_TYPHDRSET

};
//!  TK_PRCREC class. 
/*!
*   Executed by the Qt Threading system.
*/
class TK_PRCREC : public QObject {
		Q_OBJECT 
 
 
public:
	TK_PRCREC(QObject * parent = Q_NULLPTR );
	~TK_PRCREC(); 
 
 
	 void setCommitInterval(int uCommitInterval) { commitInterval = uCommitInterval; }
	 void setUpdateInterval(int uUpdateInterval) { updateInterval = uUpdateInterval; }
	int rowsProcessed() { return rowsFetched; }
	void initOdbcAttributes(); 
	void initialize(); 
	QStringList m_OdbcAttributesList;
	QMap<int, nOdbcAttributesClass*> m_OdbcAttributes_Map;
//! void open taking two QString strings 
/*!
\param sourceDSN is a QString argument.
\param targetDSN is a  QString argument.
*/
	void close(); 
	void open(const QString sourceDSN, const QString targetDSN); 
	void createTable();
//! void setProfileName 
/*! Is a setter function. Accepts a single argument QString - denoting the ProfileName.
\param _profileName is a QString argument.
\sa profileName
*/
	void setProfileName(const QString _profileName) { profileName = _profileName; } 
//! A normal member taking one argument and returning an boolean value.
/*! Entry function for the class - all data synchronization operations are executed from the process function.
\param rowSSize an integer argument.
\param s a constant character pointer.
\return The success status of this synchronization operation.
*/
//! void setRepositoryString 
/*! Is a setter function. Accepts a single argument QString - denoting the DataSource Connection String of the eNVy SQL Repository.
\param _repoString is a QString argument.
\sa m_lpszRepositoryDSN
*/
	void setRepositoryString(const QString _repoString) { m_lpszRepositoryDSN = _repoString; } 
//! QString getTableName 
/*! Is a getter function which returns the table name that is processed by this class.
\sa tableName
*/
	bool process(int rowSSize); 
//! void setNetChange 
/*! Is a setter function. Toggles the data synchronization method from BulK_Copy to Net Change.
\sa bIsNetChange
*/
	QString			getTableName() {	return tableName;}
	void			setNetChange() { bIsNetChange = true; } 
//! void setDropOption 
/*! Is a setter function. Accepts a single argument DropOption - the method with which the table should be handled prior to Bulk_Copy is performed.
\param dropOption is a DropOption argument.
\sa DropOption
*/
	void			setDropOption(DropOption dropOption) { m_dropOption = dropOption;  }
//! void setOdbcAttributes 
/*! Is a setter function. Accepts a single argument as a QString.
/*!  ODBC Attributes are delimited by Comma
/*!  ODBC Attribute support is limited to Qt 5.9 ODBC Support
\param odbcAttr is a QString argument.
*/
	void			setOdbcAttributes(const QString odbcAttr) { m_OdbcAttributes = odbcAttr;  }
//! void setReplicationOption 
/*! Is a setter function. Accepts a single argument as a ReplicationOption. Three selection options are possible; Bulk_Copy, Net_Change, NotSet
/*!  ODBC Attributes are delimited by Comma
/*!  ODBC Attribute support is limited to Qt 5.9 ODBC Support
\param odbcAttr is a QString argument.
\sa ReplicationOption
*/
	void			 setReplicationOption(ReplicationOption xReplicationOption) {
		m_ReplicationOption = xReplicationOption; 
	}
public slots:
	void setAbortFlag(); 
	void run();
signals:
//! void setAbortFlag 
/*! Is a setter function. A toggle - initiate an abort of the running class.
/*!  A toggle - initiate an abort of the running class.
*/
	void aborted(QString tableName, int fetchCnt,int insertCnt, int updateCnt);
//! void updateStatusFetched 
/*! Is a Qt Signal - the signal sends the parameterized values after each row is fetched.
\param tableName is a QString argument.
\param rowsFetched is a int argument.
*/
	void updateStatusFetched(QString profileName, QString tableName, int rowsFetched, int rowsInserted, int rowsUpdated);
 
private:
//! A private variable.
/*!
tableName := the table that will be processed by this class.
*/
	QString		tableName;
//! A private variable.
/*!
bIsAbort := the Abort flag that will be checked during the execution of this class. The default is false.
*/
	bool	bIsAbort=false;
//! A private variable.
/*!
	rowsFetched := the rowsFetch variable - a simple counter which is incremented after each row is successfully fetched. The default is 0.
*/
	int	rowsFetched = 0;
/*!
rowsFetched := the rowsInserted variable - a simple counter which is incremented after each row is successfully inserted. The default is 0.
*/
	int	rowsInserted = 0;
	int	rowsUpdated = 0;
	int	commitInterval=1000; // Rate at which SQLTransaction are committed

// Rate at which the object notifies the parent class
// the object has processed n rows.
 
	int	updateInterval=1000; 
	SQLINTEGER	lenAary = 0;
	SQLINTEGER	IndPtrArray = 0; 
/*!
hStmt_Insert, The ODBC Statement Handle for the Insert.
*/
	SQLHANDLE	hStmt_Insert; 
/*!
hStmt_Fetch, The ODBC Statement Handle for the Fetch.
*/
	SQLHANDLE	hStmt_Fetch;
/*!
hStmt_Update, The ODBC Statement Handle for the Update.
*/
	SQLHANDLE	hStmt_Update; 
/*!
numRowsFetched, The number of rows fetched.
*/
	SQLUINTEGER	numRowsFetched;
/*!
insertSql, The SQL statement used when preparing for row insertion.
*/
	QString	insertSql;
/*!
fetchSql, The SQL statement used when preparing for row selection.
*/
	QString	fetchSql;
/*!
updateSql, The SQL statement used when preparing for row updates.
*/
	QString	updateSql;
	SQLHDBC	hDbc_source;
	SQLHDBC	hDbc_target;
	SQLHENV	hEnv_Target;
	SQLHENV	hEnv_Source;
 
	QString	profileName;
	QString	m_lpszSourceDSN; 
	QString	m_lpszTargetDSN; 
	QString	m_lpszRepositoryDSN; 
	QString	m_OdbcAttributes; 
	bool bIsNetChange;
	bool	m_bIsOpen; 
	ReplicationOption m_ReplicationOption;
	DropOption  m_dropOption;
 
	bool prepare();
	void prepareTargetTable();
	bool bindColumn();
	bool bindParameter();
	void copyTable();
	void connect(connectionHandle connectionSource);

// FieldNames 
#pragma region Field Buffers TK_PRCREC
	QByteArray	DB_ID;
	QByteArray	NVTIMESTAMP;
	QByteArray	AREA;
	QByteArray	PAGE;
	QByteArray	LINE;
	QByteArray	TK_PRCUOM;
	QByteArray	TK_PRCRND;
	SQLINTEGER	cbDB_ID;
	SQLINTEGER	cbNVTIMESTAMP;
	SQLINTEGER	cbAREA;
	SQLINTEGER	cbPAGE;
	SQLINTEGER	cbLINE;
	SQLINTEGER	cbTK_PRCUOM;
	SQLINTEGER	cbTK_PRCRND;
#pragma endregion Field Buffers TK_PRCREC

};
//!  TK_LOTHSHSET class. 
/*!
*   Executed by the Qt Threading system.
*/
class TK_LOTHSHSET : public QObject {
		Q_OBJECT 
 
 
public:
	TK_LOTHSHSET(QObject * parent = Q_NULLPTR );
	~TK_LOTHSHSET(); 
 
 
	 void setCommitInterval(int uCommitInterval) { commitInterval = uCommitInterval; }
	 void setUpdateInterval(int uUpdateInterval) { updateInterval = uUpdateInterval; }
	int rowsProcessed() { return rowsFetched; }
	void initOdbcAttributes(); 
	void initialize(); 
	QStringList m_OdbcAttributesList;
	QMap<int, nOdbcAttributesClass*> m_OdbcAttributes_Map;
//! void open taking two QString strings 
/*!
\param sourceDSN is a QString argument.
\param targetDSN is a  QString argument.
*/
	void close(); 
	void open(const QString sourceDSN, const QString targetDSN); 
	void createTable();
//! void setProfileName 
/*! Is a setter function. Accepts a single argument QString - denoting the ProfileName.
\param _profileName is a QString argument.
\sa profileName
*/
	void setProfileName(const QString _profileName) { profileName = _profileName; } 
//! A normal member taking one argument and returning an boolean value.
/*! Entry function for the class - all data synchronization operations are executed from the process function.
\param rowSSize an integer argument.
\param s a constant character pointer.
\return The success status of this synchronization operation.
*/
//! void setRepositoryString 
/*! Is a setter function. Accepts a single argument QString - denoting the DataSource Connection String of the eNVy SQL Repository.
\param _repoString is a QString argument.
\sa m_lpszRepositoryDSN
*/
	void setRepositoryString(const QString _repoString) { m_lpszRepositoryDSN = _repoString; } 
//! QString getTableName 
/*! Is a getter function which returns the table name that is processed by this class.
\sa tableName
*/
	bool process(int rowSSize); 
//! void setNetChange 
/*! Is a setter function. Toggles the data synchronization method from BulK_Copy to Net Change.
\sa bIsNetChange
*/
	QString			getTableName() {	return tableName;}
	void			setNetChange() { bIsNetChange = true; } 
//! void setDropOption 
/*! Is a setter function. Accepts a single argument DropOption - the method with which the table should be handled prior to Bulk_Copy is performed.
\param dropOption is a DropOption argument.
\sa DropOption
*/
	void			setDropOption(DropOption dropOption) { m_dropOption = dropOption;  }
//! void setOdbcAttributes 
/*! Is a setter function. Accepts a single argument as a QString.
/*!  ODBC Attributes are delimited by Comma
/*!  ODBC Attribute support is limited to Qt 5.9 ODBC Support
\param odbcAttr is a QString argument.
*/
	void			setOdbcAttributes(const QString odbcAttr) { m_OdbcAttributes = odbcAttr;  }
//! void setReplicationOption 
/*! Is a setter function. Accepts a single argument as a ReplicationOption. Three selection options are possible; Bulk_Copy, Net_Change, NotSet
/*!  ODBC Attributes are delimited by Comma
/*!  ODBC Attribute support is limited to Qt 5.9 ODBC Support
\param odbcAttr is a QString argument.
\sa ReplicationOption
*/
	void			 setReplicationOption(ReplicationOption xReplicationOption) {
		m_ReplicationOption = xReplicationOption; 
	}
public slots:
	void setAbortFlag(); 
	void run();
signals:
//! void setAbortFlag 
/*! Is a setter function. A toggle - initiate an abort of the running class.
/*!  A toggle - initiate an abort of the running class.
*/
	void aborted(QString tableName, int fetchCnt,int insertCnt, int updateCnt);
//! void updateStatusFetched 
/*! Is a Qt Signal - the signal sends the parameterized values after each row is fetched.
\param tableName is a QString argument.
\param rowsFetched is a int argument.
*/
	void updateStatusFetched(QString profileName, QString tableName, int rowsFetched, int rowsInserted, int rowsUpdated);
 
private:
//! A private variable.
/*!
tableName := the table that will be processed by this class.
*/
	QString		tableName;
//! A private variable.
/*!
bIsAbort := the Abort flag that will be checked during the execution of this class. The default is false.
*/
	bool	bIsAbort=false;
//! A private variable.
/*!
	rowsFetched := the rowsFetch variable - a simple counter which is incremented after each row is successfully fetched. The default is 0.
*/
	int	rowsFetched = 0;
/*!
rowsFetched := the rowsInserted variable - a simple counter which is incremented after each row is successfully inserted. The default is 0.
*/
	int	rowsInserted = 0;
	int	rowsUpdated = 0;
	int	commitInterval=1000; // Rate at which SQLTransaction are committed

// Rate at which the object notifies the parent class
// the object has processed n rows.
 
	int	updateInterval=1000; 
	SQLINTEGER	lenAary = 0;
	SQLINTEGER	IndPtrArray = 0; 
/*!
hStmt_Insert, The ODBC Statement Handle for the Insert.
*/
	SQLHANDLE	hStmt_Insert; 
/*!
hStmt_Fetch, The ODBC Statement Handle for the Fetch.
*/
	SQLHANDLE	hStmt_Fetch;
/*!
hStmt_Update, The ODBC Statement Handle for the Update.
*/
	SQLHANDLE	hStmt_Update; 
/*!
numRowsFetched, The number of rows fetched.
*/
	SQLUINTEGER	numRowsFetched;
/*!
insertSql, The SQL statement used when preparing for row insertion.
*/
	QString	insertSql;
/*!
fetchSql, The SQL statement used when preparing for row selection.
*/
	QString	fetchSql;
/*!
updateSql, The SQL statement used when preparing for row updates.
*/
	QString	updateSql;
	SQLHDBC	hDbc_source;
	SQLHDBC	hDbc_target;
	SQLHENV	hEnv_Target;
	SQLHENV	hEnv_Source;
 
	QString	profileName;
	QString	m_lpszSourceDSN; 
	QString	m_lpszTargetDSN; 
	QString	m_lpszRepositoryDSN; 
	QString	m_OdbcAttributes; 
	bool bIsNetChange;
	bool	m_bIsOpen; 
	ReplicationOption m_ReplicationOption;
	DropOption  m_dropOption;
 
	bool prepare();
	void prepareTargetTable();
	bool bindColumn();
	bool bindParameter();
	void copyTable();
	void connect(connectionHandle connectionSource);

// FieldNames 
#pragma region Field Buffers TK_LOTHSHSET
	QByteArray	DB_ID;
	QByteArray	NVTIMESTAMP;
	QByteArray	OAREA;
	QByteArray	OPAGE;
	QByteArray	OLINE;
	QByteArray	MAREA;
	QByteArray	MPAGE;
	QByteArray	MLINE;
	SQLINTEGER	cbDB_ID;
	SQLINTEGER	cbNVTIMESTAMP;
	SQLINTEGER	cbOAREA;
	SQLINTEGER	cbOPAGE;
	SQLINTEGER	cbOLINE;
	SQLINTEGER	cbMAREA;
	SQLINTEGER	cbMPAGE;
	SQLINTEGER	cbMLINE;
#pragma endregion Field Buffers TK_LOTHSHSET

};
//!  TK_PRTLTFSET class. 
/*!
*   Executed by the Qt Threading system.
*/
class TK_PRTLTFSET : public QObject {
		Q_OBJECT 
 
 
public:
	TK_PRTLTFSET(QObject * parent = Q_NULLPTR );
	~TK_PRTLTFSET(); 
 
 
	 void setCommitInterval(int uCommitInterval) { commitInterval = uCommitInterval; }
	 void setUpdateInterval(int uUpdateInterval) { updateInterval = uUpdateInterval; }
	int rowsProcessed() { return rowsFetched; }
	void initOdbcAttributes(); 
	void initialize(); 
	QStringList m_OdbcAttributesList;
	QMap<int, nOdbcAttributesClass*> m_OdbcAttributes_Map;
//! void open taking two QString strings 
/*!
\param sourceDSN is a QString argument.
\param targetDSN is a  QString argument.
*/
	void close(); 
	void open(const QString sourceDSN, const QString targetDSN); 
	void createTable();
//! void setProfileName 
/*! Is a setter function. Accepts a single argument QString - denoting the ProfileName.
\param _profileName is a QString argument.
\sa profileName
*/
	void setProfileName(const QString _profileName) { profileName = _profileName; } 
//! A normal member taking one argument and returning an boolean value.
/*! Entry function for the class - all data synchronization operations are executed from the process function.
\param rowSSize an integer argument.
\param s a constant character pointer.
\return The success status of this synchronization operation.
*/
//! void setRepositoryString 
/*! Is a setter function. Accepts a single argument QString - denoting the DataSource Connection String of the eNVy SQL Repository.
\param _repoString is a QString argument.
\sa m_lpszRepositoryDSN
*/
	void setRepositoryString(const QString _repoString) { m_lpszRepositoryDSN = _repoString; } 
//! QString getTableName 
/*! Is a getter function which returns the table name that is processed by this class.
\sa tableName
*/
	bool process(int rowSSize); 
//! void setNetChange 
/*! Is a setter function. Toggles the data synchronization method from BulK_Copy to Net Change.
\sa bIsNetChange
*/
	QString			getTableName() {	return tableName;}
	void			setNetChange() { bIsNetChange = true; } 
//! void setDropOption 
/*! Is a setter function. Accepts a single argument DropOption - the method with which the table should be handled prior to Bulk_Copy is performed.
\param dropOption is a DropOption argument.
\sa DropOption
*/
	void			setDropOption(DropOption dropOption) { m_dropOption = dropOption;  }
//! void setOdbcAttributes 
/*! Is a setter function. Accepts a single argument as a QString.
/*!  ODBC Attributes are delimited by Comma
/*!  ODBC Attribute support is limited to Qt 5.9 ODBC Support
\param odbcAttr is a QString argument.
*/
	void			setOdbcAttributes(const QString odbcAttr) { m_OdbcAttributes = odbcAttr;  }
//! void setReplicationOption 
/*! Is a setter function. Accepts a single argument as a ReplicationOption. Three selection options are possible; Bulk_Copy, Net_Change, NotSet
/*!  ODBC Attributes are delimited by Comma
/*!  ODBC Attribute support is limited to Qt 5.9 ODBC Support
\param odbcAttr is a QString argument.
\sa ReplicationOption
*/
	void			 setReplicationOption(ReplicationOption xReplicationOption) {
		m_ReplicationOption = xReplicationOption; 
	}
public slots:
	void setAbortFlag(); 
	void run();
signals:
//! void setAbortFlag 
/*! Is a setter function. A toggle - initiate an abort of the running class.
/*!  A toggle - initiate an abort of the running class.
*/
	void aborted(QString tableName, int fetchCnt,int insertCnt, int updateCnt);
//! void updateStatusFetched 
/*! Is a Qt Signal - the signal sends the parameterized values after each row is fetched.
\param tableName is a QString argument.
\param rowsFetched is a int argument.
*/
	void updateStatusFetched(QString profileName, QString tableName, int rowsFetched, int rowsInserted, int rowsUpdated);
 
private:
//! A private variable.
/*!
tableName := the table that will be processed by this class.
*/
	QString		tableName;
//! A private variable.
/*!
bIsAbort := the Abort flag that will be checked during the execution of this class. The default is false.
*/
	bool	bIsAbort=false;
//! A private variable.
/*!
	rowsFetched := the rowsFetch variable - a simple counter which is incremented after each row is successfully fetched. The default is 0.
*/
	int	rowsFetched = 0;
/*!
rowsFetched := the rowsInserted variable - a simple counter which is incremented after each row is successfully inserted. The default is 0.
*/
	int	rowsInserted = 0;
	int	rowsUpdated = 0;
	int	commitInterval=1000; // Rate at which SQLTransaction are committed

// Rate at which the object notifies the parent class
// the object has processed n rows.
 
	int	updateInterval=1000; 
	SQLINTEGER	lenAary = 0;
	SQLINTEGER	IndPtrArray = 0; 
/*!
hStmt_Insert, The ODBC Statement Handle for the Insert.
*/
	SQLHANDLE	hStmt_Insert; 
/*!
hStmt_Fetch, The ODBC Statement Handle for the Fetch.
*/
	SQLHANDLE	hStmt_Fetch;
/*!
hStmt_Update, The ODBC Statement Handle for the Update.
*/
	SQLHANDLE	hStmt_Update; 
/*!
numRowsFetched, The number of rows fetched.
*/
	SQLUINTEGER	numRowsFetched;
/*!
insertSql, The SQL statement used when preparing for row insertion.
*/
	QString	insertSql;
/*!
fetchSql, The SQL statement used when preparing for row selection.
*/
	QString	fetchSql;
/*!
updateSql, The SQL statement used when preparing for row updates.
*/
	QString	updateSql;
	SQLHDBC	hDbc_source;
	SQLHDBC	hDbc_target;
	SQLHENV	hEnv_Target;
	SQLHENV	hEnv_Source;
 
	QString	profileName;
	QString	m_lpszSourceDSN; 
	QString	m_lpszTargetDSN; 
	QString	m_lpszRepositoryDSN; 
	QString	m_OdbcAttributes; 
	bool bIsNetChange;
	bool	m_bIsOpen; 
	ReplicationOption m_ReplicationOption;
	DropOption  m_dropOption;
 
	bool prepare();
	void prepareTargetTable();
	bool bindColumn();
	bool bindParameter();
	void copyTable();
	void connect(connectionHandle connectionSource);

// FieldNames 
#pragma region Field Buffers TK_PRTLTFSET
	QByteArray	DB_ID;
	QByteArray	NVTIMESTAMP;
	QByteArray	OAREA;
	QByteArray	OPAGE;
	QByteArray	OLINE;
	QByteArray	MAREA;
	QByteArray	MPAGE;
	QByteArray	MLINE;
	SQLINTEGER	cbDB_ID;
	SQLINTEGER	cbNVTIMESTAMP;
	SQLINTEGER	cbOAREA;
	SQLINTEGER	cbOPAGE;
	SQLINTEGER	cbOLINE;
	SQLINTEGER	cbMAREA;
	SQLINTEGER	cbMPAGE;
	SQLINTEGER	cbMLINE;
#pragma endregion Field Buffers TK_PRTLTFSET

};
//!  TK_PRTREC class. 
/*!
*   Executed by the Qt Threading system.
*/
class TK_PRTREC : public QObject {
		Q_OBJECT 
 
 
public:
	TK_PRTREC(QObject * parent = Q_NULLPTR );
	~TK_PRTREC(); 
 
 
	 void setCommitInterval(int uCommitInterval) { commitInterval = uCommitInterval; }
	 void setUpdateInterval(int uUpdateInterval) { updateInterval = uUpdateInterval; }
	int rowsProcessed() { return rowsFetched; }
	void initOdbcAttributes(); 
	void initialize(); 
	QStringList m_OdbcAttributesList;
	QMap<int, nOdbcAttributesClass*> m_OdbcAttributes_Map;
//! void open taking two QString strings 
/*!
\param sourceDSN is a QString argument.
\param targetDSN is a  QString argument.
*/
	void close(); 
	void open(const QString sourceDSN, const QString targetDSN); 
	void createTable();
//! void setProfileName 
/*! Is a setter function. Accepts a single argument QString - denoting the ProfileName.
\param _profileName is a QString argument.
\sa profileName
*/
	void setProfileName(const QString _profileName) { profileName = _profileName; } 
//! A normal member taking one argument and returning an boolean value.
/*! Entry function for the class - all data synchronization operations are executed from the process function.
\param rowSSize an integer argument.
\param s a constant character pointer.
\return The success status of this synchronization operation.
*/
//! void setRepositoryString 
/*! Is a setter function. Accepts a single argument QString - denoting the DataSource Connection String of the eNVy SQL Repository.
\param _repoString is a QString argument.
\sa m_lpszRepositoryDSN
*/
	void setRepositoryString(const QString _repoString) { m_lpszRepositoryDSN = _repoString; } 
//! QString getTableName 
/*! Is a getter function which returns the table name that is processed by this class.
\sa tableName
*/
	bool process(int rowSSize); 
//! void setNetChange 
/*! Is a setter function. Toggles the data synchronization method from BulK_Copy to Net Change.
\sa bIsNetChange
*/
	QString			getTableName() {	return tableName;}
	void			setNetChange() { bIsNetChange = true; } 
//! void setDropOption 
/*! Is a setter function. Accepts a single argument DropOption - the method with which the table should be handled prior to Bulk_Copy is performed.
\param dropOption is a DropOption argument.
\sa DropOption
*/
	void			setDropOption(DropOption dropOption) { m_dropOption = dropOption;  }
//! void setOdbcAttributes 
/*! Is a setter function. Accepts a single argument as a QString.
/*!  ODBC Attributes are delimited by Comma
/*!  ODBC Attribute support is limited to Qt 5.9 ODBC Support
\param odbcAttr is a QString argument.
*/
	void			setOdbcAttributes(const QString odbcAttr) { m_OdbcAttributes = odbcAttr;  }
//! void setReplicationOption 
/*! Is a setter function. Accepts a single argument as a ReplicationOption. Three selection options are possible; Bulk_Copy, Net_Change, NotSet
/*!  ODBC Attributes are delimited by Comma
/*!  ODBC Attribute support is limited to Qt 5.9 ODBC Support
\param odbcAttr is a QString argument.
\sa ReplicationOption
*/
	void			 setReplicationOption(ReplicationOption xReplicationOption) {
		m_ReplicationOption = xReplicationOption; 
	}
public slots:
	void setAbortFlag(); 
	void run();
signals:
//! void setAbortFlag 
/*! Is a setter function. A toggle - initiate an abort of the running class.
/*!  A toggle - initiate an abort of the running class.
*/
	void aborted(QString tableName, int fetchCnt,int insertCnt, int updateCnt);
//! void updateStatusFetched 
/*! Is a Qt Signal - the signal sends the parameterized values after each row is fetched.
\param tableName is a QString argument.
\param rowsFetched is a int argument.
*/
	void updateStatusFetched(QString profileName, QString tableName, int rowsFetched, int rowsInserted, int rowsUpdated);
 
private:
//! A private variable.
/*!
tableName := the table that will be processed by this class.
*/
	QString		tableName;
//! A private variable.
/*!
bIsAbort := the Abort flag that will be checked during the execution of this class. The default is false.
*/
	bool	bIsAbort=false;
//! A private variable.
/*!
	rowsFetched := the rowsFetch variable - a simple counter which is incremented after each row is successfully fetched. The default is 0.
*/
	int	rowsFetched = 0;
/*!
rowsFetched := the rowsInserted variable - a simple counter which is incremented after each row is successfully inserted. The default is 0.
*/
	int	rowsInserted = 0;
	int	rowsUpdated = 0;
	int	commitInterval=1000; // Rate at which SQLTransaction are committed

// Rate at which the object notifies the parent class
// the object has processed n rows.
 
	int	updateInterval=1000; 
	SQLINTEGER	lenAary = 0;
	SQLINTEGER	IndPtrArray = 0; 
/*!
hStmt_Insert, The ODBC Statement Handle for the Insert.
*/
	SQLHANDLE	hStmt_Insert; 
/*!
hStmt_Fetch, The ODBC Statement Handle for the Fetch.
*/
	SQLHANDLE	hStmt_Fetch;
/*!
hStmt_Update, The ODBC Statement Handle for the Update.
*/
	SQLHANDLE	hStmt_Update; 
/*!
numRowsFetched, The number of rows fetched.
*/
	SQLUINTEGER	numRowsFetched;
/*!
insertSql, The SQL statement used when preparing for row insertion.
*/
	QString	insertSql;
/*!
fetchSql, The SQL statement used when preparing for row selection.
*/
	QString	fetchSql;
/*!
updateSql, The SQL statement used when preparing for row updates.
*/
	QString	updateSql;
	SQLHDBC	hDbc_source;
	SQLHDBC	hDbc_target;
	SQLHENV	hEnv_Target;
	SQLHENV	hEnv_Source;
 
	QString	profileName;
	QString	m_lpszSourceDSN; 
	QString	m_lpszTargetDSN; 
	QString	m_lpszRepositoryDSN; 
	QString	m_OdbcAttributes; 
	bool bIsNetChange;
	bool	m_bIsOpen; 
	ReplicationOption m_ReplicationOption;
	DropOption  m_dropOption;
 
	bool prepare();
	void prepareTargetTable();
	bool bindColumn();
	bool bindParameter();
	void copyTable();
	void connect(connectionHandle connectionSource);

// FieldNames 
#pragma region Field Buffers TK_PRTREC
	QByteArray	DB_ID;
	QByteArray	NVTIMESTAMP;
	QByteArray	AREA;
	QByteArray	PAGE;
	QByteArray	LINE;
	QByteArray	TK_PRTNO;
	QByteArray	TK_PRTMUQ;
	QByteArray	TK_PRTLCFLG;
	SQLINTEGER	cbDB_ID;
	SQLINTEGER	cbNVTIMESTAMP;
	SQLINTEGER	cbAREA;
	SQLINTEGER	cbPAGE;
	SQLINTEGER	cbLINE;
	SQLINTEGER	cbTK_PRTNO;
	SQLINTEGER	cbTK_PRTMUQ;
	SQLINTEGER	cbTK_PRTLCFLG;
#pragma endregion Field Buffers TK_PRTREC

};
//!  TK_UHSTCHNSET class. 
/*!
*   Executed by the Qt Threading system.
*/
class TK_UHSTCHNSET : public QObject {
		Q_OBJECT 
 
 
public:
	TK_UHSTCHNSET(QObject * parent = Q_NULLPTR );
	~TK_UHSTCHNSET(); 
 
 
	 void setCommitInterval(int uCommitInterval) { commitInterval = uCommitInterval; }
	 void setUpdateInterval(int uUpdateInterval) { updateInterval = uUpdateInterval; }
	int rowsProcessed() { return rowsFetched; }
	void initOdbcAttributes(); 
	void initialize(); 
	QStringList m_OdbcAttributesList;
	QMap<int, nOdbcAttributesClass*> m_OdbcAttributes_Map;
//! void open taking two QString strings 
/*!
\param sourceDSN is a QString argument.
\param targetDSN is a  QString argument.
*/
	void close(); 
	void open(const QString sourceDSN, const QString targetDSN); 
	void createTable();
//! void setProfileName 
/*! Is a setter function. Accepts a single argument QString - denoting the ProfileName.
\param _profileName is a QString argument.
\sa profileName
*/
	void setProfileName(const QString _profileName) { profileName = _profileName; } 
//! A normal member taking one argument and returning an boolean value.
/*! Entry function for the class - all data synchronization operations are executed from the process function.
\param rowSSize an integer argument.
\param s a constant character pointer.
\return The success status of this synchronization operation.
*/
//! void setRepositoryString 
/*! Is a setter function. Accepts a single argument QString - denoting the DataSource Connection String of the eNVy SQL Repository.
\param _repoString is a QString argument.
\sa m_lpszRepositoryDSN
*/
	void setRepositoryString(const QString _repoString) { m_lpszRepositoryDSN = _repoString; } 
//! QString getTableName 
/*! Is a getter function which returns the table name that is processed by this class.
\sa tableName
*/
	bool process(int rowSSize); 
//! void setNetChange 
/*! Is a setter function. Toggles the data synchronization method from BulK_Copy to Net Change.
\sa bIsNetChange
*/
	QString			getTableName() {	return tableName;}
	void			setNetChange() { bIsNetChange = true; } 
//! void setDropOption 
/*! Is a setter function. Accepts a single argument DropOption - the method with which the table should be handled prior to Bulk_Copy is performed.
\param dropOption is a DropOption argument.
\sa DropOption
*/
	void			setDropOption(DropOption dropOption) { m_dropOption = dropOption;  }
//! void setOdbcAttributes 
/*! Is a setter function. Accepts a single argument as a QString.
/*!  ODBC Attributes are delimited by Comma
/*!  ODBC Attribute support is limited to Qt 5.9 ODBC Support
\param odbcAttr is a QString argument.
*/
	void			setOdbcAttributes(const QString odbcAttr) { m_OdbcAttributes = odbcAttr;  }
//! void setReplicationOption 
/*! Is a setter function. Accepts a single argument as a ReplicationOption. Three selection options are possible; Bulk_Copy, Net_Change, NotSet
/*!  ODBC Attributes are delimited by Comma
/*!  ODBC Attribute support is limited to Qt 5.9 ODBC Support
\param odbcAttr is a QString argument.
\sa ReplicationOption
*/
	void			 setReplicationOption(ReplicationOption xReplicationOption) {
		m_ReplicationOption = xReplicationOption; 
	}
public slots:
	void setAbortFlag(); 
	void run();
signals:
//! void setAbortFlag 
/*! Is a setter function. A toggle - initiate an abort of the running class.
/*!  A toggle - initiate an abort of the running class.
*/
	void aborted(QString tableName, int fetchCnt,int insertCnt, int updateCnt);
//! void updateStatusFetched 
/*! Is a Qt Signal - the signal sends the parameterized values after each row is fetched.
\param tableName is a QString argument.
\param rowsFetched is a int argument.
*/
	void updateStatusFetched(QString profileName, QString tableName, int rowsFetched, int rowsInserted, int rowsUpdated);
 
private:
//! A private variable.
/*!
tableName := the table that will be processed by this class.
*/
	QString		tableName;
//! A private variable.
/*!
bIsAbort := the Abort flag that will be checked during the execution of this class. The default is false.
*/
	bool	bIsAbort=false;
//! A private variable.
/*!
	rowsFetched := the rowsFetch variable - a simple counter which is incremented after each row is successfully fetched. The default is 0.
*/
	int	rowsFetched = 0;
/*!
rowsFetched := the rowsInserted variable - a simple counter which is incremented after each row is successfully inserted. The default is 0.
*/
	int	rowsInserted = 0;
	int	rowsUpdated = 0;
	int	commitInterval=1000; // Rate at which SQLTransaction are committed

// Rate at which the object notifies the parent class
// the object has processed n rows.
 
	int	updateInterval=1000; 
	SQLINTEGER	lenAary = 0;
	SQLINTEGER	IndPtrArray = 0; 
/*!
hStmt_Insert, The ODBC Statement Handle for the Insert.
*/
	SQLHANDLE	hStmt_Insert; 
/*!
hStmt_Fetch, The ODBC Statement Handle for the Fetch.
*/
	SQLHANDLE	hStmt_Fetch;
/*!
hStmt_Update, The ODBC Statement Handle for the Update.
*/
	SQLHANDLE	hStmt_Update; 
/*!
numRowsFetched, The number of rows fetched.
*/
	SQLUINTEGER	numRowsFetched;
/*!
insertSql, The SQL statement used when preparing for row insertion.
*/
	QString	insertSql;
/*!
fetchSql, The SQL statement used when preparing for row selection.
*/
	QString	fetchSql;
/*!
updateSql, The SQL statement used when preparing for row updates.
*/
	QString	updateSql;
	SQLHDBC	hDbc_source;
	SQLHDBC	hDbc_target;
	SQLHENV	hEnv_Target;
	SQLHENV	hEnv_Source;
 
	QString	profileName;
	QString	m_lpszSourceDSN; 
	QString	m_lpszTargetDSN; 
	QString	m_lpszRepositoryDSN; 
	QString	m_OdbcAttributes; 
	bool bIsNetChange;
	bool	m_bIsOpen; 
	ReplicationOption m_ReplicationOption;
	DropOption  m_dropOption;
 
	bool prepare();
	void prepareTargetTable();
	bool bindColumn();
	bool bindParameter();
	void copyTable();
	void connect(connectionHandle connectionSource);

// FieldNames 
#pragma region Field Buffers TK_UHSTCHNSET
	QByteArray	DB_ID;
	QByteArray	NVTIMESTAMP;
	QByteArray	OAREA;
	QByteArray	OPAGE;
	QByteArray	OLINE;
	QByteArray	MAREA;
	QByteArray	MPAGE;
	QByteArray	MLINE;
	SQLINTEGER	cbDB_ID;
	SQLINTEGER	cbNVTIMESTAMP;
	SQLINTEGER	cbOAREA;
	SQLINTEGER	cbOPAGE;
	SQLINTEGER	cbOLINE;
	SQLINTEGER	cbMAREA;
	SQLINTEGER	cbMPAGE;
	SQLINTEGER	cbMLINE;
#pragma endregion Field Buffers TK_UHSTCHNSET

};
//!  TK_LOTLIDSET class. 
/*!
*   Executed by the Qt Threading system.
*/
class TK_LOTLIDSET : public QObject {
		Q_OBJECT 
 
 
public:
	TK_LOTLIDSET(QObject * parent = Q_NULLPTR );
	~TK_LOTLIDSET(); 
 
 
	 void setCommitInterval(int uCommitInterval) { commitInterval = uCommitInterval; }
	 void setUpdateInterval(int uUpdateInterval) { updateInterval = uUpdateInterval; }
	int rowsProcessed() { return rowsFetched; }
	void initOdbcAttributes(); 
	void initialize(); 
	QStringList m_OdbcAttributesList;
	QMap<int, nOdbcAttributesClass*> m_OdbcAttributes_Map;
//! void open taking two QString strings 
/*!
\param sourceDSN is a QString argument.
\param targetDSN is a  QString argument.
*/
	void close(); 
	void open(const QString sourceDSN, const QString targetDSN); 
	void createTable();
//! void setProfileName 
/*! Is a setter function. Accepts a single argument QString - denoting the ProfileName.
\param _profileName is a QString argument.
\sa profileName
*/
	void setProfileName(const QString _profileName) { profileName = _profileName; } 
//! A normal member taking one argument and returning an boolean value.
/*! Entry function for the class - all data synchronization operations are executed from the process function.
\param rowSSize an integer argument.
\param s a constant character pointer.
\return The success status of this synchronization operation.
*/
//! void setRepositoryString 
/*! Is a setter function. Accepts a single argument QString - denoting the DataSource Connection String of the eNVy SQL Repository.
\param _repoString is a QString argument.
\sa m_lpszRepositoryDSN
*/
	void setRepositoryString(const QString _repoString) { m_lpszRepositoryDSN = _repoString; } 
//! QString getTableName 
/*! Is a getter function which returns the table name that is processed by this class.
\sa tableName
*/
	bool process(int rowSSize); 
//! void setNetChange 
/*! Is a setter function. Toggles the data synchronization method from BulK_Copy to Net Change.
\sa bIsNetChange
*/
	QString			getTableName() {	return tableName;}
	void			setNetChange() { bIsNetChange = true; } 
//! void setDropOption 
/*! Is a setter function. Accepts a single argument DropOption - the method with which the table should be handled prior to Bulk_Copy is performed.
\param dropOption is a DropOption argument.
\sa DropOption
*/
	void			setDropOption(DropOption dropOption) { m_dropOption = dropOption;  }
//! void setOdbcAttributes 
/*! Is a setter function. Accepts a single argument as a QString.
/*!  ODBC Attributes are delimited by Comma
/*!  ODBC Attribute support is limited to Qt 5.9 ODBC Support
\param odbcAttr is a QString argument.
*/
	void			setOdbcAttributes(const QString odbcAttr) { m_OdbcAttributes = odbcAttr;  }
//! void setReplicationOption 
/*! Is a setter function. Accepts a single argument as a ReplicationOption. Three selection options are possible; Bulk_Copy, Net_Change, NotSet
/*!  ODBC Attributes are delimited by Comma
/*!  ODBC Attribute support is limited to Qt 5.9 ODBC Support
\param odbcAttr is a QString argument.
\sa ReplicationOption
*/
	void			 setReplicationOption(ReplicationOption xReplicationOption) {
		m_ReplicationOption = xReplicationOption; 
	}
public slots:
	void setAbortFlag(); 
	void run();
signals:
//! void setAbortFlag 
/*! Is a setter function. A toggle - initiate an abort of the running class.
/*!  A toggle - initiate an abort of the running class.
*/
	void aborted(QString tableName, int fetchCnt,int insertCnt, int updateCnt);
//! void updateStatusFetched 
/*! Is a Qt Signal - the signal sends the parameterized values after each row is fetched.
\param tableName is a QString argument.
\param rowsFetched is a int argument.
*/
	void updateStatusFetched(QString profileName, QString tableName, int rowsFetched, int rowsInserted, int rowsUpdated);
 
private:
//! A private variable.
/*!
tableName := the table that will be processed by this class.
*/
	QString		tableName;
//! A private variable.
/*!
bIsAbort := the Abort flag that will be checked during the execution of this class. The default is false.
*/
	bool	bIsAbort=false;
//! A private variable.
/*!
	rowsFetched := the rowsFetch variable - a simple counter which is incremented after each row is successfully fetched. The default is 0.
*/
	int	rowsFetched = 0;
/*!
rowsFetched := the rowsInserted variable - a simple counter which is incremented after each row is successfully inserted. The default is 0.
*/
	int	rowsInserted = 0;
	int	rowsUpdated = 0;
	int	commitInterval=1000; // Rate at which SQLTransaction are committed

// Rate at which the object notifies the parent class
// the object has processed n rows.
 
	int	updateInterval=1000; 
	SQLINTEGER	lenAary = 0;
	SQLINTEGER	IndPtrArray = 0; 
/*!
hStmt_Insert, The ODBC Statement Handle for the Insert.
*/
	SQLHANDLE	hStmt_Insert; 
/*!
hStmt_Fetch, The ODBC Statement Handle for the Fetch.
*/
	SQLHANDLE	hStmt_Fetch;
/*!
hStmt_Update, The ODBC Statement Handle for the Update.
*/
	SQLHANDLE	hStmt_Update; 
/*!
numRowsFetched, The number of rows fetched.
*/
	SQLUINTEGER	numRowsFetched;
/*!
insertSql, The SQL statement used when preparing for row insertion.
*/
	QString	insertSql;
/*!
fetchSql, The SQL statement used when preparing for row selection.
*/
	QString	fetchSql;
/*!
updateSql, The SQL statement used when preparing for row updates.
*/
	QString	updateSql;
	SQLHDBC	hDbc_source;
	SQLHDBC	hDbc_target;
	SQLHENV	hEnv_Target;
	SQLHENV	hEnv_Source;
 
	QString	profileName;
	QString	m_lpszSourceDSN; 
	QString	m_lpszTargetDSN; 
	QString	m_lpszRepositoryDSN; 
	QString	m_OdbcAttributes; 
	bool bIsNetChange;
	bool	m_bIsOpen; 
	ReplicationOption m_ReplicationOption;
	DropOption  m_dropOption;
 
	bool prepare();
	void prepareTargetTable();
	bool bindColumn();
	bool bindParameter();
	void copyTable();
	void connect(connectionHandle connectionSource);

// FieldNames 
#pragma region Field Buffers TK_LOTLIDSET
	QByteArray	DB_ID;
	QByteArray	NVTIMESTAMP;
	QByteArray	OAREA;
	QByteArray	OPAGE;
	QByteArray	OLINE;
	QByteArray	MAREA;
	QByteArray	MPAGE;
	QByteArray	MLINE;
	SQLINTEGER	cbDB_ID;
	SQLINTEGER	cbNVTIMESTAMP;
	SQLINTEGER	cbOAREA;
	SQLINTEGER	cbOPAGE;
	SQLINTEGER	cbOLINE;
	SQLINTEGER	cbMAREA;
	SQLINTEGER	cbMPAGE;
	SQLINTEGER	cbMLINE;
#pragma endregion Field Buffers TK_LOTLIDSET

};
//!  TK_LTPREC class. 
/*!
*   Executed by the Qt Threading system.
*/
class TK_LTPREC : public QObject {
		Q_OBJECT 
 
 
public:
	TK_LTPREC(QObject * parent = Q_NULLPTR );
	~TK_LTPREC(); 
 
 
	 void setCommitInterval(int uCommitInterval) { commitInterval = uCommitInterval; }
	 void setUpdateInterval(int uUpdateInterval) { updateInterval = uUpdateInterval; }
	int rowsProcessed() { return rowsFetched; }
	void initOdbcAttributes(); 
	void initialize(); 
	QStringList m_OdbcAttributesList;
	QMap<int, nOdbcAttributesClass*> m_OdbcAttributes_Map;
//! void open taking two QString strings 
/*!
\param sourceDSN is a QString argument.
\param targetDSN is a  QString argument.
*/
	void close(); 
	void open(const QString sourceDSN, const QString targetDSN); 
	void createTable();
//! void setProfileName 
/*! Is a setter function. Accepts a single argument QString - denoting the ProfileName.
\param _profileName is a QString argument.
\sa profileName
*/
	void setProfileName(const QString _profileName) { profileName = _profileName; } 
//! A normal member taking one argument and returning an boolean value.
/*! Entry function for the class - all data synchronization operations are executed from the process function.
\param rowSSize an integer argument.
\param s a constant character pointer.
\return The success status of this synchronization operation.
*/
//! void setRepositoryString 
/*! Is a setter function. Accepts a single argument QString - denoting the DataSource Connection String of the eNVy SQL Repository.
\param _repoString is a QString argument.
\sa m_lpszRepositoryDSN
*/
	void setRepositoryString(const QString _repoString) { m_lpszRepositoryDSN = _repoString; } 
//! QString getTableName 
/*! Is a getter function which returns the table name that is processed by this class.
\sa tableName
*/
	bool process(int rowSSize); 
//! void setNetChange 
/*! Is a setter function. Toggles the data synchronization method from BulK_Copy to Net Change.
\sa bIsNetChange
*/
	QString			getTableName() {	return tableName;}
	void			setNetChange() { bIsNetChange = true; } 
//! void setDropOption 
/*! Is a setter function. Accepts a single argument DropOption - the method with which the table should be handled prior to Bulk_Copy is performed.
\param dropOption is a DropOption argument.
\sa DropOption
*/
	void			setDropOption(DropOption dropOption) { m_dropOption = dropOption;  }
//! void setOdbcAttributes 
/*! Is a setter function. Accepts a single argument as a QString.
/*!  ODBC Attributes are delimited by Comma
/*!  ODBC Attribute support is limited to Qt 5.9 ODBC Support
\param odbcAttr is a QString argument.
*/
	void			setOdbcAttributes(const QString odbcAttr) { m_OdbcAttributes = odbcAttr;  }
//! void setReplicationOption 
/*! Is a setter function. Accepts a single argument as a ReplicationOption. Three selection options are possible; Bulk_Copy, Net_Change, NotSet
/*!  ODBC Attributes are delimited by Comma
/*!  ODBC Attribute support is limited to Qt 5.9 ODBC Support
\param odbcAttr is a QString argument.
\sa ReplicationOption
*/
	void			 setReplicationOption(ReplicationOption xReplicationOption) {
		m_ReplicationOption = xReplicationOption; 
	}
public slots:
	void setAbortFlag(); 
	void run();
signals:
//! void setAbortFlag 
/*! Is a setter function. A toggle - initiate an abort of the running class.
/*!  A toggle - initiate an abort of the running class.
*/
	void aborted(QString tableName, int fetchCnt,int insertCnt, int updateCnt);
//! void updateStatusFetched 
/*! Is a Qt Signal - the signal sends the parameterized values after each row is fetched.
\param tableName is a QString argument.
\param rowsFetched is a int argument.
*/
	void updateStatusFetched(QString profileName, QString tableName, int rowsFetched, int rowsInserted, int rowsUpdated);
 
private:
//! A private variable.
/*!
tableName := the table that will be processed by this class.
*/
	QString		tableName;
//! A private variable.
/*!
bIsAbort := the Abort flag that will be checked during the execution of this class. The default is false.
*/
	bool	bIsAbort=false;
//! A private variable.
/*!
	rowsFetched := the rowsFetch variable - a simple counter which is incremented after each row is successfully fetched. The default is 0.
*/
	int	rowsFetched = 0;
/*!
rowsFetched := the rowsInserted variable - a simple counter which is incremented after each row is successfully inserted. The default is 0.
*/
	int	rowsInserted = 0;
	int	rowsUpdated = 0;
	int	commitInterval=1000; // Rate at which SQLTransaction are committed

// Rate at which the object notifies the parent class
// the object has processed n rows.
 
	int	updateInterval=1000; 
	SQLINTEGER	lenAary = 0;
	SQLINTEGER	IndPtrArray = 0; 
/*!
hStmt_Insert, The ODBC Statement Handle for the Insert.
*/
	SQLHANDLE	hStmt_Insert; 
/*!
hStmt_Fetch, The ODBC Statement Handle for the Fetch.
*/
	SQLHANDLE	hStmt_Fetch;
/*!
hStmt_Update, The ODBC Statement Handle for the Update.
*/
	SQLHANDLE	hStmt_Update; 
/*!
numRowsFetched, The number of rows fetched.
*/
	SQLUINTEGER	numRowsFetched;
/*!
insertSql, The SQL statement used when preparing for row insertion.
*/
	QString	insertSql;
/*!
fetchSql, The SQL statement used when preparing for row selection.
*/
	QString	fetchSql;
/*!
updateSql, The SQL statement used when preparing for row updates.
*/
	QString	updateSql;
	SQLHDBC	hDbc_source;
	SQLHDBC	hDbc_target;
	SQLHENV	hEnv_Target;
	SQLHENV	hEnv_Source;
 
	QString	profileName;
	QString	m_lpszSourceDSN; 
	QString	m_lpszTargetDSN; 
	QString	m_lpszRepositoryDSN; 
	QString	m_OdbcAttributes; 
	bool bIsNetChange;
	bool	m_bIsOpen; 
	ReplicationOption m_ReplicationOption;
	DropOption  m_dropOption;
 
	bool prepare();
	void prepareTargetTable();
	bool bindColumn();
	bool bindParameter();
	void copyTable();
	void connect(connectionHandle connectionSource);

// FieldNames 
#pragma region Field Buffers TK_LTPREC
	QByteArray	DB_ID;
	QByteArray	NVTIMESTAMP;
	QByteArray	AREA;
	QByteArray	PAGE;
	QByteArray	LINE;
	QByteArray	TK_LTPLOT;
	QByteArray	TK_LTPPRT;
	QByteArray	TK_LTPTYPE;
	QByteArray	TK_LTPKEY1;
	QByteArray	TK_LTPKEY2;
	QByteArray	TK_LTPKEY3;
	QByteArray	TK_LTPSUBTYPE;
	QByteArray	QTY;
	QByteArray	TK_LTPISSQTY;
	QByteArray	TK_LTPSCRPQTY;
	QByteArray	TK_LTPRTVQTY;
	QByteArray	TK_LTPCRDAT;
	QByteArray	TK_LTPISSDAT;
	QByteArray	DAT;
	QByteArray	TK_LTPARCISSQTY;
	QByteArray	TK_LTPARCRECQTY;
	QByteArray	TK_LTPARCSCRPQTY;
	QByteArray	TK_LTPARCRTVQTY;
	QByteArray	TK_LTPPOLINE;
	QByteArray	TK_LIDLOT;
	QByteArray	TK_HDRCODE;
	SQLINTEGER	cbDB_ID;
	SQLINTEGER	cbNVTIMESTAMP;
	SQLINTEGER	cbAREA;
	SQLINTEGER	cbPAGE;
	SQLINTEGER	cbLINE;
	SQLINTEGER	cbTK_LTPLOT;
	SQLINTEGER	cbTK_LTPPRT;
	SQLINTEGER	cbTK_LTPTYPE;
	SQLINTEGER	cbTK_LTPKEY1;
	SQLINTEGER	cbTK_LTPKEY2;
	SQLINTEGER	cbTK_LTPKEY3;
	SQLINTEGER	cbTK_LTPSUBTYPE;
	SQLINTEGER	cbQTY;
	SQLINTEGER	cbTK_LTPISSQTY;
	SQLINTEGER	cbTK_LTPSCRPQTY;
	SQLINTEGER	cbTK_LTPRTVQTY;
	SQLINTEGER	cbTK_LTPCRDAT;
	SQLINTEGER	cbTK_LTPISSDAT;
	SQLINTEGER	cbDAT;
	SQLINTEGER	cbTK_LTPARCISSQTY;
	SQLINTEGER	cbTK_LTPARCRECQTY;
	SQLINTEGER	cbTK_LTPARCSCRPQTY;
	SQLINTEGER	cbTK_LTPARCRTVQTY;
	SQLINTEGER	cbTK_LTPPOLINE;
	SQLINTEGER	cbTK_LIDLOT;
	SQLINTEGER	cbTK_HDRCODE;
#pragma endregion Field Buffers TK_LTPREC

};
//!  TK_TYPREC class. 
/*!
*   Executed by the Qt Threading system.
*/
class TK_TYPREC : public QObject {
		Q_OBJECT 
 
 
public:
	TK_TYPREC(QObject * parent = Q_NULLPTR );
	~TK_TYPREC(); 
 
 
	 void setCommitInterval(int uCommitInterval) { commitInterval = uCommitInterval; }
	 void setUpdateInterval(int uUpdateInterval) { updateInterval = uUpdateInterval; }
	int rowsProcessed() { return rowsFetched; }
	void initOdbcAttributes(); 
	void initialize(); 
	QStringList m_OdbcAttributesList;
	QMap<int, nOdbcAttributesClass*> m_OdbcAttributes_Map;
//! void open taking two QString strings 
/*!
\param sourceDSN is a QString argument.
\param targetDSN is a  QString argument.
*/
	void close(); 
	void open(const QString sourceDSN, const QString targetDSN); 
	void createTable();
//! void setProfileName 
/*! Is a setter function. Accepts a single argument QString - denoting the ProfileName.
\param _profileName is a QString argument.
\sa profileName
*/
	void setProfileName(const QString _profileName) { profileName = _profileName; } 
//! A normal member taking one argument and returning an boolean value.
/*! Entry function for the class - all data synchronization operations are executed from the process function.
\param rowSSize an integer argument.
\param s a constant character pointer.
\return The success status of this synchronization operation.
*/
//! void setRepositoryString 
/*! Is a setter function. Accepts a single argument QString - denoting the DataSource Connection String of the eNVy SQL Repository.
\param _repoString is a QString argument.
\sa m_lpszRepositoryDSN
*/
	void setRepositoryString(const QString _repoString) { m_lpszRepositoryDSN = _repoString; } 
//! QString getTableName 
/*! Is a getter function which returns the table name that is processed by this class.
\sa tableName
*/
	bool process(int rowSSize); 
//! void setNetChange 
/*! Is a setter function. Toggles the data synchronization method from BulK_Copy to Net Change.
\sa bIsNetChange
*/
	QString			getTableName() {	return tableName;}
	void			setNetChange() { bIsNetChange = true; } 
//! void setDropOption 
/*! Is a setter function. Accepts a single argument DropOption - the method with which the table should be handled prior to Bulk_Copy is performed.
\param dropOption is a DropOption argument.
\sa DropOption
*/
	void			setDropOption(DropOption dropOption) { m_dropOption = dropOption;  }
//! void setOdbcAttributes 
/*! Is a setter function. Accepts a single argument as a QString.
/*!  ODBC Attributes are delimited by Comma
/*!  ODBC Attribute support is limited to Qt 5.9 ODBC Support
\param odbcAttr is a QString argument.
*/
	void			setOdbcAttributes(const QString odbcAttr) { m_OdbcAttributes = odbcAttr;  }
//! void setReplicationOption 
/*! Is a setter function. Accepts a single argument as a ReplicationOption. Three selection options are possible; Bulk_Copy, Net_Change, NotSet
/*!  ODBC Attributes are delimited by Comma
/*!  ODBC Attribute support is limited to Qt 5.9 ODBC Support
\param odbcAttr is a QString argument.
\sa ReplicationOption
*/
	void			 setReplicationOption(ReplicationOption xReplicationOption) {
		m_ReplicationOption = xReplicationOption; 
	}
public slots:
	void setAbortFlag(); 
	void run();
signals:
//! void setAbortFlag 
/*! Is a setter function. A toggle - initiate an abort of the running class.
/*!  A toggle - initiate an abort of the running class.
*/
	void aborted(QString tableName, int fetchCnt,int insertCnt, int updateCnt);
//! void updateStatusFetched 
/*! Is a Qt Signal - the signal sends the parameterized values after each row is fetched.
\param tableName is a QString argument.
\param rowsFetched is a int argument.
*/
	void updateStatusFetched(QString profileName, QString tableName, int rowsFetched, int rowsInserted, int rowsUpdated);
 
private:
//! A private variable.
/*!
tableName := the table that will be processed by this class.
*/
	QString		tableName;
//! A private variable.
/*!
bIsAbort := the Abort flag that will be checked during the execution of this class. The default is false.
*/
	bool	bIsAbort=false;
//! A private variable.
/*!
	rowsFetched := the rowsFetch variable - a simple counter which is incremented after each row is successfully fetched. The default is 0.
*/
	int	rowsFetched = 0;
/*!
rowsFetched := the rowsInserted variable - a simple counter which is incremented after each row is successfully inserted. The default is 0.
*/
	int	rowsInserted = 0;
	int	rowsUpdated = 0;
	int	commitInterval=1000; // Rate at which SQLTransaction are committed

// Rate at which the object notifies the parent class
// the object has processed n rows.
 
	int	updateInterval=1000; 
	SQLINTEGER	lenAary = 0;
	SQLINTEGER	IndPtrArray = 0; 
/*!
hStmt_Insert, The ODBC Statement Handle for the Insert.
*/
	SQLHANDLE	hStmt_Insert; 
/*!
hStmt_Fetch, The ODBC Statement Handle for the Fetch.
*/
	SQLHANDLE	hStmt_Fetch;
/*!
hStmt_Update, The ODBC Statement Handle for the Update.
*/
	SQLHANDLE	hStmt_Update; 
/*!
numRowsFetched, The number of rows fetched.
*/
	SQLUINTEGER	numRowsFetched;
/*!
insertSql, The SQL statement used when preparing for row insertion.
*/
	QString	insertSql;
/*!
fetchSql, The SQL statement used when preparing for row selection.
*/
	QString	fetchSql;
/*!
updateSql, The SQL statement used when preparing for row updates.
*/
	QString	updateSql;
	SQLHDBC	hDbc_source;
	SQLHDBC	hDbc_target;
	SQLHENV	hEnv_Target;
	SQLHENV	hEnv_Source;
 
	QString	profileName;
	QString	m_lpszSourceDSN; 
	QString	m_lpszTargetDSN; 
	QString	m_lpszRepositoryDSN; 
	QString	m_OdbcAttributes; 
	bool bIsNetChange;
	bool	m_bIsOpen; 
	ReplicationOption m_ReplicationOption;
	DropOption  m_dropOption;
 
	bool prepare();
	void prepareTargetTable();
	bool bindColumn();
	bool bindParameter();
	void copyTable();
	void connect(connectionHandle connectionSource);

// FieldNames 
#pragma region Field Buffers TK_TYPREC
	QByteArray	DB_ID;
	QByteArray	NVTIMESTAMP;
	QByteArray	AREA;
	QByteArray	PAGE;
	QByteArray	LINE;
	QByteArray	TK_TYPCODE;
	QByteArray	TK_TYPNO;
	QByteArray	TK_TYPNAME;
	QByteArray	TK_TYPCUSNO;
	SQLINTEGER	cbDB_ID;
	SQLINTEGER	cbNVTIMESTAMP;
	SQLINTEGER	cbAREA;
	SQLINTEGER	cbPAGE;
	SQLINTEGER	cbLINE;
	SQLINTEGER	cbTK_TYPCODE;
	SQLINTEGER	cbTK_TYPNO;
	SQLINTEGER	cbTK_TYPNAME;
	SQLINTEGER	cbTK_TYPCUSNO;
#pragma endregion Field Buffers TK_TYPREC

};
//!  TK_ULSTREC class. 
/*!
*   Executed by the Qt Threading system.
*/
class TK_ULSTREC : public QObject {
		Q_OBJECT 
 
 
public:
	TK_ULSTREC(QObject * parent = Q_NULLPTR );
	~TK_ULSTREC(); 
 
 
	 void setCommitInterval(int uCommitInterval) { commitInterval = uCommitInterval; }
	 void setUpdateInterval(int uUpdateInterval) { updateInterval = uUpdateInterval; }
	int rowsProcessed() { return rowsFetched; }
	void initOdbcAttributes(); 
	void initialize(); 
	QStringList m_OdbcAttributesList;
	QMap<int, nOdbcAttributesClass*> m_OdbcAttributes_Map;
//! void open taking two QString strings 
/*!
\param sourceDSN is a QString argument.
\param targetDSN is a  QString argument.
*/
	void close(); 
	void open(const QString sourceDSN, const QString targetDSN); 
	void createTable();
//! void setProfileName 
/*! Is a setter function. Accepts a single argument QString - denoting the ProfileName.
\param _profileName is a QString argument.
\sa profileName
*/
	void setProfileName(const QString _profileName) { profileName = _profileName; } 
//! A normal member taking one argument and returning an boolean value.
/*! Entry function for the class - all data synchronization operations are executed from the process function.
\param rowSSize an integer argument.
\param s a constant character pointer.
\return The success status of this synchronization operation.
*/
//! void setRepositoryString 
/*! Is a setter function. Accepts a single argument QString - denoting the DataSource Connection String of the eNVy SQL Repository.
\param _repoString is a QString argument.
\sa m_lpszRepositoryDSN
*/
	void setRepositoryString(const QString _repoString) { m_lpszRepositoryDSN = _repoString; } 
//! QString getTableName 
/*! Is a getter function which returns the table name that is processed by this class.
\sa tableName
*/
	bool process(int rowSSize); 
//! void setNetChange 
/*! Is a setter function. Toggles the data synchronization method from BulK_Copy to Net Change.
\sa bIsNetChange
*/
	QString			getTableName() {	return tableName;}
	void			setNetChange() { bIsNetChange = true; } 
//! void setDropOption 
/*! Is a setter function. Accepts a single argument DropOption - the method with which the table should be handled prior to Bulk_Copy is performed.
\param dropOption is a DropOption argument.
\sa DropOption
*/
	void			setDropOption(DropOption dropOption) { m_dropOption = dropOption;  }
//! void setOdbcAttributes 
/*! Is a setter function. Accepts a single argument as a QString.
/*!  ODBC Attributes are delimited by Comma
/*!  ODBC Attribute support is limited to Qt 5.9 ODBC Support
\param odbcAttr is a QString argument.
*/
	void			setOdbcAttributes(const QString odbcAttr) { m_OdbcAttributes = odbcAttr;  }
//! void setReplicationOption 
/*! Is a setter function. Accepts a single argument as a ReplicationOption. Three selection options are possible; Bulk_Copy, Net_Change, NotSet
/*!  ODBC Attributes are delimited by Comma
/*!  ODBC Attribute support is limited to Qt 5.9 ODBC Support
\param odbcAttr is a QString argument.
\sa ReplicationOption
*/
	void			 setReplicationOption(ReplicationOption xReplicationOption) {
		m_ReplicationOption = xReplicationOption; 
	}
public slots:
	void setAbortFlag(); 
	void run();
signals:
//! void setAbortFlag 
/*! Is a setter function. A toggle - initiate an abort of the running class.
/*!  A toggle - initiate an abort of the running class.
*/
	void aborted(QString tableName, int fetchCnt,int insertCnt, int updateCnt);
//! void updateStatusFetched 
/*! Is a Qt Signal - the signal sends the parameterized values after each row is fetched.
\param tableName is a QString argument.
\param rowsFetched is a int argument.
*/
	void updateStatusFetched(QString profileName, QString tableName, int rowsFetched, int rowsInserted, int rowsUpdated);
 
private:
//! A private variable.
/*!
tableName := the table that will be processed by this class.
*/
	QString		tableName;
//! A private variable.
/*!
bIsAbort := the Abort flag that will be checked during the execution of this class. The default is false.
*/
	bool	bIsAbort=false;
//! A private variable.
/*!
	rowsFetched := the rowsFetch variable - a simple counter which is incremented after each row is successfully fetched. The default is 0.
*/
	int	rowsFetched = 0;
/*!
rowsFetched := the rowsInserted variable - a simple counter which is incremented after each row is successfully inserted. The default is 0.
*/
	int	rowsInserted = 0;
	int	rowsUpdated = 0;
	int	commitInterval=1000; // Rate at which SQLTransaction are committed

// Rate at which the object notifies the parent class
// the object has processed n rows.
 
	int	updateInterval=1000; 
	SQLINTEGER	lenAary = 0;
	SQLINTEGER	IndPtrArray = 0; 
/*!
hStmt_Insert, The ODBC Statement Handle for the Insert.
*/
	SQLHANDLE	hStmt_Insert; 
/*!
hStmt_Fetch, The ODBC Statement Handle for the Fetch.
*/
	SQLHANDLE	hStmt_Fetch;
/*!
hStmt_Update, The ODBC Statement Handle for the Update.
*/
	SQLHANDLE	hStmt_Update; 
/*!
numRowsFetched, The number of rows fetched.
*/
	SQLUINTEGER	numRowsFetched;
/*!
insertSql, The SQL statement used when preparing for row insertion.
*/
	QString	insertSql;
/*!
fetchSql, The SQL statement used when preparing for row selection.
*/
	QString	fetchSql;
/*!
updateSql, The SQL statement used when preparing for row updates.
*/
	QString	updateSql;
	SQLHDBC	hDbc_source;
	SQLHDBC	hDbc_target;
	SQLHENV	hEnv_Target;
	SQLHENV	hEnv_Source;
 
	QString	profileName;
	QString	m_lpszSourceDSN; 
	QString	m_lpszTargetDSN; 
	QString	m_lpszRepositoryDSN; 
	QString	m_OdbcAttributes; 
	bool bIsNetChange;
	bool	m_bIsOpen; 
	ReplicationOption m_ReplicationOption;
	DropOption  m_dropOption;
 
	bool prepare();
	void prepareTargetTable();
	bool bindColumn();
	bool bindParameter();
	void copyTable();
	void connect(connectionHandle connectionSource);

// FieldNames 
#pragma region Field Buffers TK_ULSTREC
	QByteArray	DB_ID;
	QByteArray	NVTIMESTAMP;
	QByteArray	AREA;
	QByteArray	PAGE;
	QByteArray	LINE;
	QByteArray	TK_ULSTUOM;
	QByteArray	TK_UPRTNO;
	SQLINTEGER	cbDB_ID;
	SQLINTEGER	cbNVTIMESTAMP;
	SQLINTEGER	cbAREA;
	SQLINTEGER	cbPAGE;
	SQLINTEGER	cbLINE;
	SQLINTEGER	cbTK_ULSTUOM;
	SQLINTEGER	cbTK_UPRTNO;
#pragma endregion Field Buffers TK_ULSTREC

};
#endif // TRKDB100H
