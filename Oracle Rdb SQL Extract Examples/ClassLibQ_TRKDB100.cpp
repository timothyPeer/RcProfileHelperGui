/*H**********************************************************************
* FILENAME :        CaseList_TRKDB100.cpp             DESIGN REF: 
*
* DESCRIPTION :
*       This file contains implementation functions for each record that can be processed 
*       in the TRKDB MANMAN R11 Rdb schema.
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

#include "ClassLibQ_TRKDB100.h"
#include "qnvstaticclass.h"
#include "NvLib_Enumerations.h"
#include "qVtExecute.h" 
#include "nvTableOracleRdb.h" 
Q_DECLARE_LOGGING_CATEGORY(category)


TK_INTSOHSHSET::TK_INTSOHSHSET(QObject * parent) : QObject(parent) 
,tableName("TK_INTSOHSHSET")
,m_dropOption(DropOption::DropTable) { 
	numRowsFetched = 0;
}

#pragma region ~CTOR TK_INTSOHSHSET 
TK_INTSOHSHSET::~TK_INTSOHSHSET() { 

#pragma region Buffers - Clear 
	DB_ID.clear();
	NVTIMESTAMP.clear();
	OAREA.clear();
	OPAGE.clear();
	OLINE.clear();
	MAREA.clear();
	MPAGE.clear();
	MLINE.clear();
#pragma endregion Buffers - Clear 
}
#pragma endregion Destructor_TK_INTSOHSHSET

// begin method functions
void TK_INTSOHSHSET::setAbortFlag() { 
	QLoggingCategory category("classLibQ");
	qCInfo(category) << "isAbort was set to True";
	bIsAbort = true;
}

void TK_INTSOHSHSET::run() { 
	process(1);
	QLoggingCategory category("classLibQ");
	qDebug(category) << "Entered;";
}

void	TK_INTSOHSHSET::initOdbcAttributes()
{
	QLoggingCategory category("classLibQ");
	this->setProfileName(profileName);
	qDebug(category) << "Processing - TRKDB100"; 
	m_OdbcAttributesList = m_OdbcAttributes.split(","); 
	foreach(QString m, m_OdbcAttributesList)
	{
		QStringList keyValue = m.split("=");
		nOdbcAttributesClass * oM = new nOdbcAttributesClass(this);
		if (oM->loadToOdbc(keyValue.value(0), keyValue.value(1)))
		{
			m_OdbcAttributes_Map.insert(oM->odbcKey, oM);
		}
	}
}
void	TK_INTSOHSHSET::initialize()
{
	QLoggingCategory category("classLibQ");
	RETCODE r;
	this->setProfileName(profileName);
	qDebug(category) << "Processing - TRKDB100"; 
//SQL Statements
//--------------------------------------------------

#pragma region Sql Statements_TK_INTSOHSHSET

	fetchSql = "select  DB_ID, NVTIMESTAMP, OAREA, OPAGE, OLINE, MAREA, MPAGE, MLINE from TK_INTSOHSHSET";
		if (m_ReplicationOption == ReplicationOption::NetChange)
		{
			fetchSql.append(" p1, nv_transfers p2 WHERE  p2.table_name = 'TK_INTSOHSHSET' AND p1.nvtimestamp > p2.last_completed");
		}
	insertSql = "insert into TK_INTSOHSHSET ( PLANT_CODE, NVTIMESTAMP, OAREA, OPAGE, OLINE, MAREA, MPAGE, MLINE ) values ( ?, ?, ?, ?, ?, ?, ?, ?)";
	updateSql = "update TK_INTSOHSHSET set  PLANT_CODE = ?, NVTIMESTAMP = ?, OAREA = ?, OPAGE = ?, OLINE = ?, MAREA = ?, MPAGE = ?, MLINE = ?  where area = ? and page = ? line = ? ";

	qDebug(category) << "insertSQL - insert into TK_INTSOHSHSET ( PLANT_CODE, NVTIMESTAMP, OAREA, OPAGE, OLINE, MAREA, MPAGE, MLINE ) values ( ?, ?, ?, ?, ?, ?, ?, ?)";
	qDebug(category) << "fetchSQL - select  DB_ID, NVTIMESTAMP, OAREA, OPAGE, OLINE, MAREA, MPAGE, MLINE from TK_INTSOHSHSET";
	qDebug(category) << "unsertSQL - update TK_INTSOHSHSET set  PLANT_CODE = ?, NVTIMESTAMP = ?, OAREA = ?, OPAGE = ?, OLINE = ?, MAREA = ?, MPAGE = ?, MLINE = ?  where area = ? and page = ? line = ? ";

#pragma endregion Sql Statements_TK_INTSOHSHSET
	SQLHANDLE		insert_hStmt = SQL_NULL_HANDLE;
	SQLHANDLE		fetch_hStmt = SQL_NULL_HANDLE; 
	SQLHANDLE		update_hStmt = SQL_NULL_HANDLE; 
 
	r = ::SQLAllocHandle(SQL_HANDLE_STMT, hDbc_source, &fetch_hStmt);
	if (r != SQL_SUCCESS) {
		 qCCritical(category) << QString("Error  hDbc_Source SQLCode : %1 is %2").arg(QString::number( (long)hDbc_source)).arg(QString::number(r));
		return; 
	}
	r = ::SQLAllocHandle(SQL_HANDLE_STMT, hDbc_target, &insert_hStmt);
	if (r != SQL_SUCCESS) {
		 qCCritical(category) << QString("Error hDbc_Source -SQLCode: %1 is %2").arg(QString::number( (long)hDbc_target)).arg(QString::number(r));
		return; 
	}
	r = ::SQLAllocHandle(SQL_HANDLE_STMT, hDbc_target, &update_hStmt);
	if (r != SQL_SUCCESS) {
		 qCCritical(category) << QString("Error hDbc_Source +SQLCode: %1 is %2").arg(QString::number( (long)hDbc_target)).arg(QString::number(r));
		return; 
	}
 
	hStmt_Fetch = fetch_hStmt;
	hStmt_Insert = insert_hStmt;
	hStmt_Update = update_hStmt;
 
	SQLSetStmtAttr(hStmt_Fetch, SQL_ATTR_USE_BOOKMARKS, (SQLPOINTER)SQL_UB_OFF, 0);
	SQLSetStmtAttr(hStmt_Fetch, SQL_ATTR_ROW_BIND_TYPE, (SQLPOINTER)SQL_BIND_BY_COLUMN, 0);
	SQLSetStmtAttr(hStmt_Fetch, SQL_ATTR_ROW_ARRAY_SIZE, (SQLPOINTER)1, 0);
	SQLSetStmtAttr(hStmt_Fetch, SQL_ATTR_ROWS_FETCHED_PTR, &numRowsFetched, 0);

// Fields used by this class 
// ---------------------------------------------------

#pragma region Resize Fields TK_INTSOHSHSET
	qDebug(category) << "Malloc - DB_ID[2]";
	DB_ID.resize(2);
	qDebug(category) << "Malloc - NVTIMESTAMP[23]";
	NVTIMESTAMP.resize(23);
	qDebug(category) << "Malloc - OAREA[2]";
	OAREA.resize(2);
	qDebug(category) << "Malloc - OPAGE[4]";
	OPAGE.resize(4);
	qDebug(category) << "Malloc - OLINE[2]";
	OLINE.resize(2);
	qDebug(category) << "Malloc - MAREA[2]";
	MAREA.resize(2);
	qDebug(category) << "Malloc - MPAGE[4]";
	MPAGE.resize(4);
	qDebug(category) << "Malloc - MLINE[2]";
	MLINE.resize(2);

#pragma endregion Resize Fields TK_INTSOHSHSET
}
void TK_INTSOHSHSET::close()
{
	QLoggingCategory category("classLibQ");
	if (m_bIsOpen)
	{
	qDebug(category) << "database is Open";
		SQLHANDLE source_hStmt = hStmt_Fetch;
		SQLHANDLE insert_hStmt = hStmt_Insert;
		SQLHANDLE hDb_S = this->hDbc_source;
		SQLHANDLE hDb_T = hDbc_target;
		SQLHANDLE hEnvS = hEnv_Source;
		SQLHANDLE hEnvT = hEnv_Target;
		RETCODE r;

		r = ::SQLFreeHandle(SQL_HANDLE_STMT, hStmt_Fetch);
		r = ::SQLFreeHandle(SQL_HANDLE_STMT, hStmt_Insert);
		r = ::SQLFreeHandle(SQL_HANDLE_STMT, hStmt_Update);
		if (hDbc_source != SQL_NULL_HANDLE) 		r = ::SQLDisconnect(hDb_S);
		if (hDbc_target != SQL_NULL_HANDLE) 		r = ::SQLDisconnect(hDb_T);

		r = ::SQLFreeHandle(SQL_HANDLE_DBC, hDb_S);
		r = ::SQLFreeHandle(SQL_HANDLE_DBC, hDb_T);
		r = ::SQLFreeHandle(SQL_HANDLE_ENV, hEnvS);
		r = ::SQLFreeHandle(SQL_HANDLE_ENV, hEnvT);
	}

	hEnv_Source = SQL_NULL_HANDLE;
	hEnv_Target = SQL_NULL_HANDLE;
	hEnv_Source = SQL_NULL_HANDLE;
	hEnv_Target = SQL_NULL_HANDLE;
	hStmt_Fetch = SQL_NULL_HANDLE;
	hStmt_Insert = SQL_NULL_HANDLE;
	hStmt_Update = SQL_NULL_HANDLE;
}

void TK_INTSOHSHSET::open(const QString sourceDSN, const QString targetDSN)
{
	QLoggingCategory category("classLibQ");
	m_lpszTargetDSN = targetDSN;
	m_lpszSourceDSN = sourceDSN;
	qDebug(category) << QString("Source - %1[%2]").arg(sourceDSN);
	qDebug(category) << QString("Target - %1[%2]").arg(targetDSN);
}

void TK_INTSOHSHSET::createTable()
{
	QLoggingCategory category("classLibQ");
	{
		QScopedPointer<nvTableOracleRdb> tbl(new nvTableOracleRdb(nullptr));
		tbl->initialize("TK_INTSOHSHSET", this->m_lpszSourceDSN);
		QString newTbl = tbl->getCreateTableSQL();
		QScopedPointer<qVtExecute> vExec(new qVtExecute(nullptr));
		{
			vExec->initialize(m_lpszTargetDSN, " ", true);
			vExec->setOdbcAttributes(m_OdbcAttributes);
			vExec->ExecuteDirect(newTbl);
		}
	 qDebug(category) << QString("End Create Table %1 ").arg(tableName); 
	}
}

bool TK_INTSOHSHSET::prepare()
{
	RETCODE r;
	QString check;
	QLoggingCategory category("classLibQ");
	 qDebug(category) << fetchSql;
	 qDebug(category) << insertSql;
#ifdef UNICODE
	r = SQLPrepare(hStmt_Insert,toSQLTCHAR(insertSql).data(),(SQLINTEGER)insertSql.length()); 
	if (r != SQL_SUCCESS) {
		check = qWarnODBCHandle(SQL_HANDLE_STMT, hStmt_Insert);
		 qCCritical(category) << QString("Prepare Statement-Insert : %1 is %2").arg(insertSql).arg(check);
		return false; 
	}
	r = SQLPrepare(hStmt_Update,toSQLTCHAR(updateSql).data(),(SQLINTEGER)updateSql.length()); 
	if (r != SQL_SUCCESS) {
		check = qWarnODBCHandle(SQL_HANDLE_STMT, hStmt_Update);
		 qCCritical(category) << QString("Prepare Statement-Update : %1 is %2").arg(updateSql).arg(check);
		return false; 
	}
	r = SQLPrepare(hStmt_Fetch,toSQLTCHAR(fetchSql).data(),(SQLINTEGER)fetchSql.length());
	if (r != SQL_SUCCESS) {
		check = qWarnODBCHandle(SQL_HANDLE_STMT, hStmt_Fetch);
		 qCCritical(category) << QString("Prepare Statement-Insert : %1 is %2").arg(fetchSql).arg(check);
		return false; 
	}
#else
	QByteArray queryI8 = insertSql.toUtf8();
	r = SQLPrepare(insert_hStmt,SQLCHAR*)queryI8.data(),(SQLINTEGER)queryI8.length());
	QByteArray queryU8 = fetchSql.toUtf8();
	r = SQLPrepare(hStmt_Fetch,(SQLCHAR*)queryU8.data(),(SQLINTEGER)queryU8.length());
#endif
	return true;

}

void TK_INTSOHSHSET::prepareTargetTable()
{
	QLoggingCategory category("classLibQ");
	if (this->m_ReplicationOption == ReplicationOption::BulkCopy)
	{
		QScopedPointer<qVtExecute> execSql(new qVtExecute(nullptr));
		DropOption option = this->m_dropOption;
		switch (option)
		{
			case DropOption::DeleteFromTable:
			{
				QLoggingCategory category("classLibQ");
				execSql->initialize(this->m_lpszTargetDSN, "delete from TK_INTSOHSHSET", true);
				execSql->setOdbcAttributes(this->m_OdbcAttributes);
				execSql->ExecuteDirect("delete from TK_INTSOHSHSET");
			}break;
			case DropOption::TruncateTable:
			{
				execSql->initialize(this->m_lpszTargetDSN, "truncate table TK_INTSOHSHSET", true);
				execSql->setOdbcAttributes(this->m_OdbcAttributes);
				execSql->ExecuteDirect("truncate table TK_INTSOHSHSET");
			}break;
			case DropOption::DropTable:
			{
				execSql->initialize(this->m_lpszTargetDSN, "drop table TK_INTSOHSHSET", true);
				execSql->setOdbcAttributes(this->m_OdbcAttributes);
				execSql->ExecuteDirect("drop table TK_INTSOHSHSET");
				createTable();
			}break;
		}
	}
}

bool TK_INTSOHSHSET::bindColumn()
{
	QLoggingCategory category("classLibQ");
	RETCODE r;
	bool isValid=true;
		 qDebug(category) << " Bindings: Ordinal [1] Type: 5 Buffer Size: 2 FieldName: DB_ID ";
		r = ::SQLBindCol(hStmt_Fetch, 1, 5, DB_ID.data(), 2, &cbDB_ID);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Bindings: Ordinal [2] Type: 93 Buffer Size: 23 FieldName: NVTIMESTAMP ";
		r = ::SQLBindCol(hStmt_Fetch, 2, 93, NVTIMESTAMP.data(), 23, &cbNVTIMESTAMP);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Bindings: Ordinal [3] Type: 5 Buffer Size: 2 FieldName: OAREA ";
		r = ::SQLBindCol(hStmt_Fetch, 3, 5, OAREA.data(), 2, &cbOAREA);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Bindings: Ordinal [4] Type: 4 Buffer Size: 4 FieldName: OPAGE ";
		r = ::SQLBindCol(hStmt_Fetch, 4, 4, OPAGE.data(), 4, &cbOPAGE);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Bindings: Ordinal [5] Type: 5 Buffer Size: 2 FieldName: OLINE ";
		r = ::SQLBindCol(hStmt_Fetch, 5, 5, OLINE.data(), 2, &cbOLINE);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Bindings: Ordinal [6] Type: 5 Buffer Size: 2 FieldName: MAREA ";
		r = ::SQLBindCol(hStmt_Fetch, 6, 5, MAREA.data(), 2, &cbMAREA);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Bindings: Ordinal [7] Type: 4 Buffer Size: 4 FieldName: MPAGE ";
		r = ::SQLBindCol(hStmt_Fetch, 7, 4, MPAGE.data(), 4, &cbMPAGE);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Bindings: Ordinal [8] Type: 5 Buffer Size: 2 FieldName: MLINE ";
		r = ::SQLBindCol(hStmt_Fetch, 8, 5, MLINE.data(), 2, &cbMLINE);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
	return isValid;
}

bool TK_INTSOHSHSET::bindParameter()
{
	QLoggingCategory category("classLibQ");
	RETCODE r;
	bool isValid=true;
	{
		 qDebug(category) << " Parameters: Ordinal [1] Type: 5 Buffer Size: 2 FieldName: DB_ID ";
		r = SQLBindParameter(hStmt_Insert, 1, SQL_PARAM_INPUT, SQL_C_DEFAULT, 5, 0, 0, (SQLPOINTER)DB_ID.constData(), 0, &cbDB_ID);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Parameters: Ordinal [2] Type: 93 Buffer Size: 23 FieldName: NVTIMESTAMP ";
		r = SQLBindParameter(hStmt_Insert, 2, SQL_PARAM_INPUT, SQL_C_DEFAULT, 93, 23, 0, (SQLPOINTER)NVTIMESTAMP.constData(), 0, &cbNVTIMESTAMP);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Parameters: Ordinal [3] Type: 5 Buffer Size: 2 FieldName: OAREA ";
		r = SQLBindParameter(hStmt_Insert, 3, SQL_PARAM_INPUT, SQL_C_DEFAULT, 5, 0, 0, (SQLPOINTER)OAREA.constData(), 0, &cbOAREA);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Parameters: Ordinal [4] Type: 4 Buffer Size: 4 FieldName: OPAGE ";
		r = SQLBindParameter(hStmt_Insert, 4, SQL_PARAM_INPUT, SQL_C_DEFAULT, 4, 0, 0, (SQLPOINTER)OPAGE.constData(), 0, &cbOPAGE);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Parameters: Ordinal [5] Type: 5 Buffer Size: 2 FieldName: OLINE ";
		r = SQLBindParameter(hStmt_Insert, 5, SQL_PARAM_INPUT, SQL_C_DEFAULT, 5, 0, 0, (SQLPOINTER)OLINE.constData(), 0, &cbOLINE);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Parameters: Ordinal [6] Type: 5 Buffer Size: 2 FieldName: MAREA ";
		r = SQLBindParameter(hStmt_Insert, 6, SQL_PARAM_INPUT, SQL_C_DEFAULT, 5, 0, 0, (SQLPOINTER)MAREA.constData(), 0, &cbMAREA);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Parameters: Ordinal [7] Type: 4 Buffer Size: 4 FieldName: MPAGE ";
		r = SQLBindParameter(hStmt_Insert, 7, SQL_PARAM_INPUT, SQL_C_DEFAULT, 4, 0, 0, (SQLPOINTER)MPAGE.constData(), 0, &cbMPAGE);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Parameters: Ordinal [8] Type: 5 Buffer Size: 2 FieldName: MLINE ";
		r = SQLBindParameter(hStmt_Insert, 8, SQL_PARAM_INPUT, SQL_C_DEFAULT, 5, 0, 0, (SQLPOINTER)MLINE.constData(), 0, &cbMLINE);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
	}
	if (m_ReplicationOption == ReplicationOption::NetChange)
	{
		r = SQLBindParameter(hStmt_Update, 9, SQL_PARAM_INPUT, SQL_C_DEFAULT, 6, 0, 0, (SQLPOINTER)MAREA.constData(), 0, &cbMAREA);
		if (r == SQL_SUCCESS) { isValid=true; }
		r = SQLBindParameter(hStmt_Update, 10, SQL_PARAM_INPUT, SQL_C_DEFAULT, 7, 0, 0, (SQLPOINTER)MPAGE.constData(), 0, &cbMPAGE);
		if (r == SQL_SUCCESS) { isValid=true; }
		r = SQLBindParameter(hStmt_Update, 11, SQL_PARAM_INPUT, SQL_C_DEFAULT, 8, 0, 0, (SQLPOINTER)MLINE.constData(), 0, &cbMLINE);
		if (r == SQL_SUCCESS) { isValid=true; }
	// TK_INTSOHSHSET is a well formed table for eNVy Replication 
		 qDebug(category) << " Parameters: Ordinal [6] 00 00 FieldName: MAREA ";
		 qDebug(category) << " Parameters: Ordinal [7] 00 00  FieldName: MPAGE ";
		 qDebug(category) << " Parameters: Ordinal [8] 00 00 FieldName:  MLINE ";
	} // 	if (m_ReplicationOption == ReplicationOption::NetChange)
	return isValid;
}

bool TK_INTSOHSHSET::process(int rowSize)
{
	QLoggingCategory category("classLibQ");
	initOdbcAttributes();
	connect(Source);
	connect(Target);
	initialize();
	prepareTargetTable();
	prepare();
	bindColumn();
	bindParameter();
	copyTable();
	close();
	return false;
}

void TK_INTSOHSHSET::copyTable()
{
	QLoggingCategory category("classLibQ");
	RETCODE r;
	QString check;
	r = SQLExecute(hStmt_Fetch);
		if (bIsAbort) {
			emit aborted(tableName, rowsFetched, rowsInserted, rowsUpdated);
			return;
		}
		while((r = SQLFetch(hStmt_Fetch)) != SQL_NO_DATA) {
		if (r != SQL_SUCCESS) {
			check = qWarnODBCHandle(SQL_HANDLE_STMT, hStmt_Fetch);
			qCCritical(category) << QString("SqlFetch - Error : %1 is %2").arg(fetchSql).arg(check);
			return;
		} 
		rowsFetched++;
		if (m_ReplicationOption == ReplicationOption::BulkCopy)
		{
			r = SQLExecute(hStmt_Insert);
			if (r == SQL_ERROR) {
				check = qWarnODBCHandle(SQL_HANDLE_STMT, hStmt_Insert);
				 qCCritical(category) << QString("SqlExecute:Insert - Error : %1 is %2").arg(insertSql).arg(check);
				return;
			}
			rowsInserted++;
			if ((rowsFetched % updateInterval) == 0) {
				qCInfo(category) << QString("[%1.%2]	Insertion: %3	Updates : %4	Fetched : %5").arg(profileName).arg(tableName).arg(rowsInserted).arg(rowsUpdated).arg(rowsFetched);
				emit updateStatusFetched(profileName, tableName, rowsFetched,rowsInserted,rowsUpdated);
			}
			if (m_ReplicationOption == ReplicationOption::NetChange)
			{
			r = SQLExecute(hStmt_Update);
			if (r != SQL_SUCCESS) {
				check = qWarnODBCHandle(SQL_HANDLE_STMT, hStmt_Update);
				 qCInfo(category)  << QString("SqlExecute:Update - Error : %1 is %2").arg(updateSql).arg(check);
				r = SQLExecute(hStmt_Insert);
				if (r != SQL_SUCCESS) {
					check = qWarnODBCHandle(SQL_HANDLE_STMT, hStmt_Insert);
					 qCritical(category) << QString("SqlExecute:Insert - Error : %1 is %2").arg(insertSql).arg(check);
					return;
				}
				else 	rowsInserted++;
				}
				else	rowsUpdated++;
			}
			emit updateStatusFetched(profileName, tableName, rowsFetched,rowsInserted,rowsUpdated);
		}
	} 
qCInfo(category) << QString("[%1.%2]	Insertion: %3	Updates : %4	Fetched : %5").arg(profileName).arg(tableName).arg(rowsInserted).arg(rowsUpdated).arg(rowsFetched);
}

void TK_INTSOHSHSET::connect(connectionHandle connectionSource)
{

	QLoggingCategory category("classLibQ");
	RETCODE r;

	bool isValid = false;
	HWND	hWnd = nullptr;
	hWnd = ::GetDesktopWindow(); 
	SQLSMALLINT nResult = 0;

	SQLSMALLINT cb;
	UWORD wConnectOption = SQL_DRIVER_COMPLETE; //SQL_DRIVER_NOPROMPT;
	QVarLengthArray<SQLTCHAR> connOut(1024);
	memset(connOut.data(), 0, connOut.size() * sizeof(SQLTCHAR));

	switch (connectionSource)
	{
		case Source:
			{// environment
				SQLHANDLE hEnv = SQL_NULL_HANDLE;
				SQLHANDLE hDbc = SQL_NULL_HANDLE;
				r = ::SQLAllocHandle(SQL_HANDLE_ENV, SQL_NULL_HANDLE, &hEnv);
				if (r == SQL_SUCCESS) isValid = true;

				foreach(nOdbcAttributesClass * k, this->m_OdbcAttributes_Map)
				{
					if (k->attributeType == enumAttributeType::hEnv)
					{
						r = ::SQLSetEnvAttr(hEnv, (SQLINTEGER) k->odbcKey, (SQLPOINTER)k->odbcValue, 0);
						if (r == SQL_SUCCESS) isValid = true;
					}
				}
				hEnv_Source = hEnv;

				r = SQLAllocHandle(SQL_HANDLE_DBC, hEnv, &hDbc);
				if (r == SQL_SUCCESS) isValid = true;
				foreach(nOdbcAttributesClass * k, this->m_OdbcAttributes_Map)
				{
					if (k->attributeType == enumAttributeType::hDbc)
					{
					r = ::SQLSetConnectAttr(hDbc, k->odbcKey, (SQLPOINTER)k->odbcValue, 0);
					if (k->odbcKey == SQL_ATTR_CONNECTION_POOLING && k->odbcValue == SQL_CP_ONE_PER_DRIVER) wConnectOption = SQL_DRIVER_NOPROMPT;
					if (k->odbcKey == SQL_ATTR_CONNECTION_POOLING && k->odbcValue == SQL_CP_ONE_PER_HENV) wConnectOption = SQL_DRIVER_NOPROMPT;
					if (k->odbcKey == SQL_ATTR_CONNECTION_POOLING && k->odbcValue == SQL_CP_DRIVER_AWARE) wConnectOption = SQL_DRIVER_NOPROMPT;
					if (r == SQL_SUCCESS) isValid = true;
					}
				}
				hDbc_source = hDbc;
				if (isValid)
				{
					r = ::SQLDriverConnect(
						hDbc,
						hWnd,
#ifdef UNICODE
						toSQLTCHAR(m_lpszSourceDSN).data(),
#else
						(SQLCHAR*)dsnSource.toUtf8().data(),
#endif
						(SQLSMALLINT)m_lpszSourceDSN.length(),
						connOut.data(),
						1024,
						&cb, 
						wConnectOption); 
					int colSize = cb / sizeof(SQLTCHAR);
					if (r != SQL_SUCCESS && r != SQL_SUCCESS_WITH_INFO)
					{
						QString check = qWarnODBCHandle(SQL_HANDLE_DBC, hDbc);
						qCritical(category) <<  check;
						m_bIsOpen = false;
					}
					m_bIsOpen = true;
				}
			} break;
		case Target:
			{
				SQLHANDLE hEnv = SQL_NULL_HANDLE;
				SQLHANDLE hDbc = SQL_NULL_HANDLE;
				r = ::SQLAllocHandle(SQL_HANDLE_ENV, SQL_NULL_HANDLE, &hEnv);
				if (r == SQL_SUCCESS) isValid = true;

				foreach(nOdbcAttributesClass * k, this->m_OdbcAttributes_Map)
				{
					if (k->attributeType == enumAttributeType::hEnv)
					{
						r = ::SQLSetEnvAttr(hEnv, (SQLINTEGER) k->odbcKey, (SQLPOINTER)k->odbcValue, 0);
						if (r == SQL_SUCCESS) isValid = true;
					}
				}
				hEnv_Target = hEnv;

				r = SQLAllocHandle(SQL_HANDLE_DBC, hEnv, &hDbc);
				if (r == SQL_SUCCESS) isValid = true;
				foreach(nOdbcAttributesClass * k, this->m_OdbcAttributes_Map)
				{
				if (k->attributeType == enumAttributeType::hDbc)
					{
					r = ::SQLSetConnectAttr(hDbc, k->odbcKey, (SQLPOINTER)k->odbcValue, 0);
					if (k->odbcKey == SQL_ATTR_CONNECTION_POOLING && k->odbcValue == SQL_CP_ONE_PER_DRIVER) wConnectOption = SQL_DRIVER_NOPROMPT;
					if (k->odbcKey == SQL_ATTR_CONNECTION_POOLING && k->odbcValue == SQL_CP_ONE_PER_HENV) wConnectOption = SQL_DRIVER_NOPROMPT;
					if (k->odbcKey == SQL_ATTR_CONNECTION_POOLING && k->odbcValue == SQL_CP_DRIVER_AWARE) wConnectOption = SQL_DRIVER_NOPROMPT;
					if (r == SQL_SUCCESS) isValid = true;
					}
				}
				hDbc_target = hDbc;
				if (isValid) {
					r = ::SQLDriverConnect(
						hDbc,
						hWnd,
#ifdef UNICODE
						toSQLTCHAR(m_lpszTargetDSN).data(),
#else
						(SQLCHAR*)m_lpszTargetDSN.toUtf8().data(),
#endif
						(SQLSMALLINT)m_lpszTargetDSN.length(),
						connOut.data(),
						1024,
						&cb, 
						wConnectOption); 
						int colSize = cb / sizeof(SQLTCHAR);
					if (r != SQL_SUCCESS && r != SQL_SUCCESS_WITH_INFO)
						{
							QString check = qWarnODBCHandle(SQL_HANDLE_DBC, hDbc);
							qCritical(category) <<  check;
							m_bIsOpen = false;
						}
							m_bIsOpen = true;
					}
			} break;
			default: break;
	}
}
TK_PRTLIDSET::TK_PRTLIDSET(QObject * parent) : QObject(parent) 
,tableName("TK_PRTLIDSET")
,m_dropOption(DropOption::DropTable) { 
	numRowsFetched = 0;
}

#pragma region ~CTOR TK_PRTLIDSET 
TK_PRTLIDSET::~TK_PRTLIDSET() { 

#pragma region Buffers - Clear 
	DB_ID.clear();
	NVTIMESTAMP.clear();
	OAREA.clear();
	OPAGE.clear();
	OLINE.clear();
	MAREA.clear();
	MPAGE.clear();
	MLINE.clear();
#pragma endregion Buffers - Clear 
}
#pragma endregion Destructor_TK_PRTLIDSET

// begin method functions
void TK_PRTLIDSET::setAbortFlag() { 
	QLoggingCategory category("classLibQ");
	qCInfo(category) << "isAbort was set to True";
	bIsAbort = true;
}

void TK_PRTLIDSET::run() { 
	process(1);
	QLoggingCategory category("classLibQ");
	qDebug(category) << "Entered;";
}

void	TK_PRTLIDSET::initOdbcAttributes()
{
	QLoggingCategory category("classLibQ");
	this->setProfileName(profileName);
	qDebug(category) << "Processing - TRKDB100"; 
	m_OdbcAttributesList = m_OdbcAttributes.split(","); 
	foreach(QString m, m_OdbcAttributesList)
	{
		QStringList keyValue = m.split("=");
		nOdbcAttributesClass * oM = new nOdbcAttributesClass(this);
		if (oM->loadToOdbc(keyValue.value(0), keyValue.value(1)))
		{
			m_OdbcAttributes_Map.insert(oM->odbcKey, oM);
		}
	}
}
void	TK_PRTLIDSET::initialize()
{
	QLoggingCategory category("classLibQ");
	RETCODE r;
	this->setProfileName(profileName);
	qDebug(category) << "Processing - TRKDB100"; 
//SQL Statements
//--------------------------------------------------

#pragma region Sql Statements_TK_PRTLIDSET

	fetchSql = "select  DB_ID, NVTIMESTAMP, OAREA, OPAGE, OLINE, MAREA, MPAGE, MLINE from TK_PRTLIDSET";
		if (m_ReplicationOption == ReplicationOption::NetChange)
		{
			fetchSql.append(" p1, nv_transfers p2 WHERE  p2.table_name = 'TK_PRTLIDSET' AND p1.nvtimestamp > p2.last_completed");
		}
	insertSql = "insert into TK_PRTLIDSET ( PLANT_CODE, NVTIMESTAMP, OAREA, OPAGE, OLINE, MAREA, MPAGE, MLINE ) values ( ?, ?, ?, ?, ?, ?, ?, ?)";
	updateSql = "update TK_PRTLIDSET set  PLANT_CODE = ?, NVTIMESTAMP = ?, OAREA = ?, OPAGE = ?, OLINE = ?, MAREA = ?, MPAGE = ?, MLINE = ?  where area = ? and page = ? line = ? ";

	qDebug(category) << "insertSQL - insert into TK_PRTLIDSET ( PLANT_CODE, NVTIMESTAMP, OAREA, OPAGE, OLINE, MAREA, MPAGE, MLINE ) values ( ?, ?, ?, ?, ?, ?, ?, ?)";
	qDebug(category) << "fetchSQL - select  DB_ID, NVTIMESTAMP, OAREA, OPAGE, OLINE, MAREA, MPAGE, MLINE from TK_PRTLIDSET";
	qDebug(category) << "unsertSQL - update TK_PRTLIDSET set  PLANT_CODE = ?, NVTIMESTAMP = ?, OAREA = ?, OPAGE = ?, OLINE = ?, MAREA = ?, MPAGE = ?, MLINE = ?  where area = ? and page = ? line = ? ";

#pragma endregion Sql Statements_TK_PRTLIDSET
	SQLHANDLE		insert_hStmt = SQL_NULL_HANDLE;
	SQLHANDLE		fetch_hStmt = SQL_NULL_HANDLE; 
	SQLHANDLE		update_hStmt = SQL_NULL_HANDLE; 
 
	r = ::SQLAllocHandle(SQL_HANDLE_STMT, hDbc_source, &fetch_hStmt);
	if (r != SQL_SUCCESS) {
		 qCCritical(category) << QString("Error  hDbc_Source SQLCode : %1 is %2").arg(QString::number( (long)hDbc_source)).arg(QString::number(r));
		return; 
	}
	r = ::SQLAllocHandle(SQL_HANDLE_STMT, hDbc_target, &insert_hStmt);
	if (r != SQL_SUCCESS) {
		 qCCritical(category) << QString("Error hDbc_Source -SQLCode: %1 is %2").arg(QString::number( (long)hDbc_target)).arg(QString::number(r));
		return; 
	}
	r = ::SQLAllocHandle(SQL_HANDLE_STMT, hDbc_target, &update_hStmt);
	if (r != SQL_SUCCESS) {
		 qCCritical(category) << QString("Error hDbc_Source +SQLCode: %1 is %2").arg(QString::number( (long)hDbc_target)).arg(QString::number(r));
		return; 
	}
 
	hStmt_Fetch = fetch_hStmt;
	hStmt_Insert = insert_hStmt;
	hStmt_Update = update_hStmt;
 
	SQLSetStmtAttr(hStmt_Fetch, SQL_ATTR_USE_BOOKMARKS, (SQLPOINTER)SQL_UB_OFF, 0);
	SQLSetStmtAttr(hStmt_Fetch, SQL_ATTR_ROW_BIND_TYPE, (SQLPOINTER)SQL_BIND_BY_COLUMN, 0);
	SQLSetStmtAttr(hStmt_Fetch, SQL_ATTR_ROW_ARRAY_SIZE, (SQLPOINTER)1, 0);
	SQLSetStmtAttr(hStmt_Fetch, SQL_ATTR_ROWS_FETCHED_PTR, &numRowsFetched, 0);

// Fields used by this class 
// ---------------------------------------------------

#pragma region Resize Fields TK_PRTLIDSET
	qDebug(category) << "Malloc - DB_ID[2]";
	DB_ID.resize(2);
	qDebug(category) << "Malloc - NVTIMESTAMP[23]";
	NVTIMESTAMP.resize(23);
	qDebug(category) << "Malloc - OAREA[2]";
	OAREA.resize(2);
	qDebug(category) << "Malloc - OPAGE[4]";
	OPAGE.resize(4);
	qDebug(category) << "Malloc - OLINE[2]";
	OLINE.resize(2);
	qDebug(category) << "Malloc - MAREA[2]";
	MAREA.resize(2);
	qDebug(category) << "Malloc - MPAGE[4]";
	MPAGE.resize(4);
	qDebug(category) << "Malloc - MLINE[2]";
	MLINE.resize(2);

#pragma endregion Resize Fields TK_PRTLIDSET
}
void TK_PRTLIDSET::close()
{
	QLoggingCategory category("classLibQ");
	if (m_bIsOpen)
	{
	qDebug(category) << "database is Open";
		SQLHANDLE source_hStmt = hStmt_Fetch;
		SQLHANDLE insert_hStmt = hStmt_Insert;
		SQLHANDLE hDb_S = this->hDbc_source;
		SQLHANDLE hDb_T = hDbc_target;
		SQLHANDLE hEnvS = hEnv_Source;
		SQLHANDLE hEnvT = hEnv_Target;
		RETCODE r;

		r = ::SQLFreeHandle(SQL_HANDLE_STMT, hStmt_Fetch);
		r = ::SQLFreeHandle(SQL_HANDLE_STMT, hStmt_Insert);
		r = ::SQLFreeHandle(SQL_HANDLE_STMT, hStmt_Update);
		if (hDbc_source != SQL_NULL_HANDLE) 		r = ::SQLDisconnect(hDb_S);
		if (hDbc_target != SQL_NULL_HANDLE) 		r = ::SQLDisconnect(hDb_T);

		r = ::SQLFreeHandle(SQL_HANDLE_DBC, hDb_S);
		r = ::SQLFreeHandle(SQL_HANDLE_DBC, hDb_T);
		r = ::SQLFreeHandle(SQL_HANDLE_ENV, hEnvS);
		r = ::SQLFreeHandle(SQL_HANDLE_ENV, hEnvT);
	}

	hEnv_Source = SQL_NULL_HANDLE;
	hEnv_Target = SQL_NULL_HANDLE;
	hEnv_Source = SQL_NULL_HANDLE;
	hEnv_Target = SQL_NULL_HANDLE;
	hStmt_Fetch = SQL_NULL_HANDLE;
	hStmt_Insert = SQL_NULL_HANDLE;
	hStmt_Update = SQL_NULL_HANDLE;
}

void TK_PRTLIDSET::open(const QString sourceDSN, const QString targetDSN)
{
	QLoggingCategory category("classLibQ");
	m_lpszTargetDSN = targetDSN;
	m_lpszSourceDSN = sourceDSN;
	qDebug(category) << QString("Source - %1[%2]").arg(sourceDSN);
	qDebug(category) << QString("Target - %1[%2]").arg(targetDSN);
}

void TK_PRTLIDSET::createTable()
{
	QLoggingCategory category("classLibQ");
	{
		QScopedPointer<nvTableOracleRdb> tbl(new nvTableOracleRdb(nullptr));
		tbl->initialize("TK_PRTLIDSET", this->m_lpszSourceDSN);
		QString newTbl = tbl->getCreateTableSQL();
		QScopedPointer<qVtExecute> vExec(new qVtExecute(nullptr));
		{
			vExec->initialize(m_lpszTargetDSN, " ", true);
			vExec->setOdbcAttributes(m_OdbcAttributes);
			vExec->ExecuteDirect(newTbl);
		}
	 qDebug(category) << QString("End Create Table %1 ").arg(tableName); 
	}
}

bool TK_PRTLIDSET::prepare()
{
	RETCODE r;
	QString check;
	QLoggingCategory category("classLibQ");
	 qDebug(category) << fetchSql;
	 qDebug(category) << insertSql;
#ifdef UNICODE
	r = SQLPrepare(hStmt_Insert,toSQLTCHAR(insertSql).data(),(SQLINTEGER)insertSql.length()); 
	if (r != SQL_SUCCESS) {
		check = qWarnODBCHandle(SQL_HANDLE_STMT, hStmt_Insert);
		 qCCritical(category) << QString("Prepare Statement-Insert : %1 is %2").arg(insertSql).arg(check);
		return false; 
	}
	r = SQLPrepare(hStmt_Update,toSQLTCHAR(updateSql).data(),(SQLINTEGER)updateSql.length()); 
	if (r != SQL_SUCCESS) {
		check = qWarnODBCHandle(SQL_HANDLE_STMT, hStmt_Update);
		 qCCritical(category) << QString("Prepare Statement-Update : %1 is %2").arg(updateSql).arg(check);
		return false; 
	}
	r = SQLPrepare(hStmt_Fetch,toSQLTCHAR(fetchSql).data(),(SQLINTEGER)fetchSql.length());
	if (r != SQL_SUCCESS) {
		check = qWarnODBCHandle(SQL_HANDLE_STMT, hStmt_Fetch);
		 qCCritical(category) << QString("Prepare Statement-Insert : %1 is %2").arg(fetchSql).arg(check);
		return false; 
	}
#else
	QByteArray queryI8 = insertSql.toUtf8();
	r = SQLPrepare(insert_hStmt,SQLCHAR*)queryI8.data(),(SQLINTEGER)queryI8.length());
	QByteArray queryU8 = fetchSql.toUtf8();
	r = SQLPrepare(hStmt_Fetch,(SQLCHAR*)queryU8.data(),(SQLINTEGER)queryU8.length());
#endif
	return true;

}

void TK_PRTLIDSET::prepareTargetTable()
{
	QLoggingCategory category("classLibQ");
	if (this->m_ReplicationOption == ReplicationOption::BulkCopy)
	{
		QScopedPointer<qVtExecute> execSql(new qVtExecute(nullptr));
		DropOption option = this->m_dropOption;
		switch (option)
		{
			case DropOption::DeleteFromTable:
			{
				QLoggingCategory category("classLibQ");
				execSql->initialize(this->m_lpszTargetDSN, "delete from TK_PRTLIDSET", true);
				execSql->setOdbcAttributes(this->m_OdbcAttributes);
				execSql->ExecuteDirect("delete from TK_PRTLIDSET");
			}break;
			case DropOption::TruncateTable:
			{
				execSql->initialize(this->m_lpszTargetDSN, "truncate table TK_PRTLIDSET", true);
				execSql->setOdbcAttributes(this->m_OdbcAttributes);
				execSql->ExecuteDirect("truncate table TK_PRTLIDSET");
			}break;
			case DropOption::DropTable:
			{
				execSql->initialize(this->m_lpszTargetDSN, "drop table TK_PRTLIDSET", true);
				execSql->setOdbcAttributes(this->m_OdbcAttributes);
				execSql->ExecuteDirect("drop table TK_PRTLIDSET");
				createTable();
			}break;
		}
	}
}

bool TK_PRTLIDSET::bindColumn()
{
	QLoggingCategory category("classLibQ");
	RETCODE r;
	bool isValid=true;
		 qDebug(category) << " Bindings: Ordinal [1] Type: 5 Buffer Size: 2 FieldName: DB_ID ";
		r = ::SQLBindCol(hStmt_Fetch, 1, 5, DB_ID.data(), 2, &cbDB_ID);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Bindings: Ordinal [2] Type: 93 Buffer Size: 23 FieldName: NVTIMESTAMP ";
		r = ::SQLBindCol(hStmt_Fetch, 2, 93, NVTIMESTAMP.data(), 23, &cbNVTIMESTAMP);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Bindings: Ordinal [3] Type: 5 Buffer Size: 2 FieldName: OAREA ";
		r = ::SQLBindCol(hStmt_Fetch, 3, 5, OAREA.data(), 2, &cbOAREA);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Bindings: Ordinal [4] Type: 4 Buffer Size: 4 FieldName: OPAGE ";
		r = ::SQLBindCol(hStmt_Fetch, 4, 4, OPAGE.data(), 4, &cbOPAGE);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Bindings: Ordinal [5] Type: 5 Buffer Size: 2 FieldName: OLINE ";
		r = ::SQLBindCol(hStmt_Fetch, 5, 5, OLINE.data(), 2, &cbOLINE);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Bindings: Ordinal [6] Type: 5 Buffer Size: 2 FieldName: MAREA ";
		r = ::SQLBindCol(hStmt_Fetch, 6, 5, MAREA.data(), 2, &cbMAREA);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Bindings: Ordinal [7] Type: 4 Buffer Size: 4 FieldName: MPAGE ";
		r = ::SQLBindCol(hStmt_Fetch, 7, 4, MPAGE.data(), 4, &cbMPAGE);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Bindings: Ordinal [8] Type: 5 Buffer Size: 2 FieldName: MLINE ";
		r = ::SQLBindCol(hStmt_Fetch, 8, 5, MLINE.data(), 2, &cbMLINE);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
	return isValid;
}

bool TK_PRTLIDSET::bindParameter()
{
	QLoggingCategory category("classLibQ");
	RETCODE r;
	bool isValid=true;
	{
		 qDebug(category) << " Parameters: Ordinal [1] Type: 5 Buffer Size: 2 FieldName: DB_ID ";
		r = SQLBindParameter(hStmt_Insert, 1, SQL_PARAM_INPUT, SQL_C_DEFAULT, 5, 0, 0, (SQLPOINTER)DB_ID.constData(), 0, &cbDB_ID);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Parameters: Ordinal [2] Type: 93 Buffer Size: 23 FieldName: NVTIMESTAMP ";
		r = SQLBindParameter(hStmt_Insert, 2, SQL_PARAM_INPUT, SQL_C_DEFAULT, 93, 23, 0, (SQLPOINTER)NVTIMESTAMP.constData(), 0, &cbNVTIMESTAMP);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Parameters: Ordinal [3] Type: 5 Buffer Size: 2 FieldName: OAREA ";
		r = SQLBindParameter(hStmt_Insert, 3, SQL_PARAM_INPUT, SQL_C_DEFAULT, 5, 0, 0, (SQLPOINTER)OAREA.constData(), 0, &cbOAREA);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Parameters: Ordinal [4] Type: 4 Buffer Size: 4 FieldName: OPAGE ";
		r = SQLBindParameter(hStmt_Insert, 4, SQL_PARAM_INPUT, SQL_C_DEFAULT, 4, 0, 0, (SQLPOINTER)OPAGE.constData(), 0, &cbOPAGE);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Parameters: Ordinal [5] Type: 5 Buffer Size: 2 FieldName: OLINE ";
		r = SQLBindParameter(hStmt_Insert, 5, SQL_PARAM_INPUT, SQL_C_DEFAULT, 5, 0, 0, (SQLPOINTER)OLINE.constData(), 0, &cbOLINE);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Parameters: Ordinal [6] Type: 5 Buffer Size: 2 FieldName: MAREA ";
		r = SQLBindParameter(hStmt_Insert, 6, SQL_PARAM_INPUT, SQL_C_DEFAULT, 5, 0, 0, (SQLPOINTER)MAREA.constData(), 0, &cbMAREA);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Parameters: Ordinal [7] Type: 4 Buffer Size: 4 FieldName: MPAGE ";
		r = SQLBindParameter(hStmt_Insert, 7, SQL_PARAM_INPUT, SQL_C_DEFAULT, 4, 0, 0, (SQLPOINTER)MPAGE.constData(), 0, &cbMPAGE);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Parameters: Ordinal [8] Type: 5 Buffer Size: 2 FieldName: MLINE ";
		r = SQLBindParameter(hStmt_Insert, 8, SQL_PARAM_INPUT, SQL_C_DEFAULT, 5, 0, 0, (SQLPOINTER)MLINE.constData(), 0, &cbMLINE);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
	}
	if (m_ReplicationOption == ReplicationOption::NetChange)
	{
		r = SQLBindParameter(hStmt_Update, 9, SQL_PARAM_INPUT, SQL_C_DEFAULT, 6, 0, 0, (SQLPOINTER)MAREA.constData(), 0, &cbMAREA);
		if (r == SQL_SUCCESS) { isValid=true; }
		r = SQLBindParameter(hStmt_Update, 10, SQL_PARAM_INPUT, SQL_C_DEFAULT, 7, 0, 0, (SQLPOINTER)MPAGE.constData(), 0, &cbMPAGE);
		if (r == SQL_SUCCESS) { isValid=true; }
		r = SQLBindParameter(hStmt_Update, 11, SQL_PARAM_INPUT, SQL_C_DEFAULT, 8, 0, 0, (SQLPOINTER)MLINE.constData(), 0, &cbMLINE);
		if (r == SQL_SUCCESS) { isValid=true; }
	// TK_PRTLIDSET is a well formed table for eNVy Replication 
		 qDebug(category) << " Parameters: Ordinal [6] 00 00 FieldName: MAREA ";
		 qDebug(category) << " Parameters: Ordinal [7] 00 00  FieldName: MPAGE ";
		 qDebug(category) << " Parameters: Ordinal [8] 00 00 FieldName:  MLINE ";
	} // 	if (m_ReplicationOption == ReplicationOption::NetChange)
	return isValid;
}

bool TK_PRTLIDSET::process(int rowSize)
{
	QLoggingCategory category("classLibQ");
	initOdbcAttributes();
	connect(Source);
	connect(Target);
	initialize();
	prepareTargetTable();
	prepare();
	bindColumn();
	bindParameter();
	copyTable();
	close();
	return false;
}

void TK_PRTLIDSET::copyTable()
{
	QLoggingCategory category("classLibQ");
	RETCODE r;
	QString check;
	r = SQLExecute(hStmt_Fetch);
		if (bIsAbort) {
			emit aborted(tableName, rowsFetched, rowsInserted, rowsUpdated);
			return;
		}
		while((r = SQLFetch(hStmt_Fetch)) != SQL_NO_DATA) {
		if (r != SQL_SUCCESS) {
			check = qWarnODBCHandle(SQL_HANDLE_STMT, hStmt_Fetch);
			qCCritical(category) << QString("SqlFetch - Error : %1 is %2").arg(fetchSql).arg(check);
			return;
		} 
		rowsFetched++;
		if (m_ReplicationOption == ReplicationOption::BulkCopy)
		{
			r = SQLExecute(hStmt_Insert);
			if (r == SQL_ERROR) {
				check = qWarnODBCHandle(SQL_HANDLE_STMT, hStmt_Insert);
				 qCCritical(category) << QString("SqlExecute:Insert - Error : %1 is %2").arg(insertSql).arg(check);
				return;
			}
			rowsInserted++;
			if ((rowsFetched % updateInterval) == 0) {
				qCInfo(category) << QString("[%1.%2]	Insertion: %3	Updates : %4	Fetched : %5").arg(profileName).arg(tableName).arg(rowsInserted).arg(rowsUpdated).arg(rowsFetched);
				emit updateStatusFetched(profileName, tableName, rowsFetched,rowsInserted,rowsUpdated);
			}
			if (m_ReplicationOption == ReplicationOption::NetChange)
			{
			r = SQLExecute(hStmt_Update);
			if (r != SQL_SUCCESS) {
				check = qWarnODBCHandle(SQL_HANDLE_STMT, hStmt_Update);
				 qCInfo(category)  << QString("SqlExecute:Update - Error : %1 is %2").arg(updateSql).arg(check);
				r = SQLExecute(hStmt_Insert);
				if (r != SQL_SUCCESS) {
					check = qWarnODBCHandle(SQL_HANDLE_STMT, hStmt_Insert);
					 qCritical(category) << QString("SqlExecute:Insert - Error : %1 is %2").arg(insertSql).arg(check);
					return;
				}
				else 	rowsInserted++;
				}
				else	rowsUpdated++;
			}
			emit updateStatusFetched(profileName, tableName, rowsFetched,rowsInserted,rowsUpdated);
		}
	} 
qCInfo(category) << QString("[%1.%2]	Insertion: %3	Updates : %4	Fetched : %5").arg(profileName).arg(tableName).arg(rowsInserted).arg(rowsUpdated).arg(rowsFetched);
}

void TK_PRTLIDSET::connect(connectionHandle connectionSource)
{

	QLoggingCategory category("classLibQ");
	RETCODE r;

	bool isValid = false;
	HWND	hWnd = nullptr;
	hWnd = ::GetDesktopWindow(); 
	SQLSMALLINT nResult = 0;

	SQLSMALLINT cb;
	UWORD wConnectOption = SQL_DRIVER_COMPLETE; //SQL_DRIVER_NOPROMPT;
	QVarLengthArray<SQLTCHAR> connOut(1024);
	memset(connOut.data(), 0, connOut.size() * sizeof(SQLTCHAR));

	switch (connectionSource)
	{
		case Source:
			{// environment
				SQLHANDLE hEnv = SQL_NULL_HANDLE;
				SQLHANDLE hDbc = SQL_NULL_HANDLE;
				r = ::SQLAllocHandle(SQL_HANDLE_ENV, SQL_NULL_HANDLE, &hEnv);
				if (r == SQL_SUCCESS) isValid = true;

				foreach(nOdbcAttributesClass * k, this->m_OdbcAttributes_Map)
				{
					if (k->attributeType == enumAttributeType::hEnv)
					{
						r = ::SQLSetEnvAttr(hEnv, (SQLINTEGER) k->odbcKey, (SQLPOINTER)k->odbcValue, 0);
						if (r == SQL_SUCCESS) isValid = true;
					}
				}
				hEnv_Source = hEnv;

				r = SQLAllocHandle(SQL_HANDLE_DBC, hEnv, &hDbc);
				if (r == SQL_SUCCESS) isValid = true;
				foreach(nOdbcAttributesClass * k, this->m_OdbcAttributes_Map)
				{
					if (k->attributeType == enumAttributeType::hDbc)
					{
					r = ::SQLSetConnectAttr(hDbc, k->odbcKey, (SQLPOINTER)k->odbcValue, 0);
					if (k->odbcKey == SQL_ATTR_CONNECTION_POOLING && k->odbcValue == SQL_CP_ONE_PER_DRIVER) wConnectOption = SQL_DRIVER_NOPROMPT;
					if (k->odbcKey == SQL_ATTR_CONNECTION_POOLING && k->odbcValue == SQL_CP_ONE_PER_HENV) wConnectOption = SQL_DRIVER_NOPROMPT;
					if (k->odbcKey == SQL_ATTR_CONNECTION_POOLING && k->odbcValue == SQL_CP_DRIVER_AWARE) wConnectOption = SQL_DRIVER_NOPROMPT;
					if (r == SQL_SUCCESS) isValid = true;
					}
				}
				hDbc_source = hDbc;
				if (isValid)
				{
					r = ::SQLDriverConnect(
						hDbc,
						hWnd,
#ifdef UNICODE
						toSQLTCHAR(m_lpszSourceDSN).data(),
#else
						(SQLCHAR*)dsnSource.toUtf8().data(),
#endif
						(SQLSMALLINT)m_lpszSourceDSN.length(),
						connOut.data(),
						1024,
						&cb, 
						wConnectOption); 
					int colSize = cb / sizeof(SQLTCHAR);
					if (r != SQL_SUCCESS && r != SQL_SUCCESS_WITH_INFO)
					{
						QString check = qWarnODBCHandle(SQL_HANDLE_DBC, hDbc);
						qCritical(category) <<  check;
						m_bIsOpen = false;
					}
					m_bIsOpen = true;
				}
			} break;
		case Target:
			{
				SQLHANDLE hEnv = SQL_NULL_HANDLE;
				SQLHANDLE hDbc = SQL_NULL_HANDLE;
				r = ::SQLAllocHandle(SQL_HANDLE_ENV, SQL_NULL_HANDLE, &hEnv);
				if (r == SQL_SUCCESS) isValid = true;

				foreach(nOdbcAttributesClass * k, this->m_OdbcAttributes_Map)
				{
					if (k->attributeType == enumAttributeType::hEnv)
					{
						r = ::SQLSetEnvAttr(hEnv, (SQLINTEGER) k->odbcKey, (SQLPOINTER)k->odbcValue, 0);
						if (r == SQL_SUCCESS) isValid = true;
					}
				}
				hEnv_Target = hEnv;

				r = SQLAllocHandle(SQL_HANDLE_DBC, hEnv, &hDbc);
				if (r == SQL_SUCCESS) isValid = true;
				foreach(nOdbcAttributesClass * k, this->m_OdbcAttributes_Map)
				{
				if (k->attributeType == enumAttributeType::hDbc)
					{
					r = ::SQLSetConnectAttr(hDbc, k->odbcKey, (SQLPOINTER)k->odbcValue, 0);
					if (k->odbcKey == SQL_ATTR_CONNECTION_POOLING && k->odbcValue == SQL_CP_ONE_PER_DRIVER) wConnectOption = SQL_DRIVER_NOPROMPT;
					if (k->odbcKey == SQL_ATTR_CONNECTION_POOLING && k->odbcValue == SQL_CP_ONE_PER_HENV) wConnectOption = SQL_DRIVER_NOPROMPT;
					if (k->odbcKey == SQL_ATTR_CONNECTION_POOLING && k->odbcValue == SQL_CP_DRIVER_AWARE) wConnectOption = SQL_DRIVER_NOPROMPT;
					if (r == SQL_SUCCESS) isValid = true;
					}
				}
				hDbc_target = hDbc;
				if (isValid) {
					r = ::SQLDriverConnect(
						hDbc,
						hWnd,
#ifdef UNICODE
						toSQLTCHAR(m_lpszTargetDSN).data(),
#else
						(SQLCHAR*)m_lpszTargetDSN.toUtf8().data(),
#endif
						(SQLSMALLINT)m_lpszTargetDSN.length(),
						connOut.data(),
						1024,
						&cb, 
						wConnectOption); 
						int colSize = cb / sizeof(SQLTCHAR);
					if (r != SQL_SUCCESS && r != SQL_SUCCESS_WITH_INFO)
						{
							QString check = qWarnODBCHandle(SQL_HANDLE_DBC, hDbc);
							qCritical(category) <<  check;
							m_bIsOpen = false;
						}
							m_bIsOpen = true;
					}
			} break;
			default: break;
	}
}
TK_PRTHSHSET::TK_PRTHSHSET(QObject * parent) : QObject(parent) 
,tableName("TK_PRTHSHSET")
,m_dropOption(DropOption::DropTable) { 
	numRowsFetched = 0;
}

#pragma region ~CTOR TK_PRTHSHSET 
TK_PRTHSHSET::~TK_PRTHSHSET() { 

#pragma region Buffers - Clear 
	DB_ID.clear();
	NVTIMESTAMP.clear();
	OAREA.clear();
	OPAGE.clear();
	OLINE.clear();
	MAREA.clear();
	MPAGE.clear();
	MLINE.clear();
#pragma endregion Buffers - Clear 
}
#pragma endregion Destructor_TK_PRTHSHSET

// begin method functions
void TK_PRTHSHSET::setAbortFlag() { 
	QLoggingCategory category("classLibQ");
	qCInfo(category) << "isAbort was set to True";
	bIsAbort = true;
}

void TK_PRTHSHSET::run() { 
	process(1);
	QLoggingCategory category("classLibQ");
	qDebug(category) << "Entered;";
}

void	TK_PRTHSHSET::initOdbcAttributes()
{
	QLoggingCategory category("classLibQ");
	this->setProfileName(profileName);
	qDebug(category) << "Processing - TRKDB100"; 
	m_OdbcAttributesList = m_OdbcAttributes.split(","); 
	foreach(QString m, m_OdbcAttributesList)
	{
		QStringList keyValue = m.split("=");
		nOdbcAttributesClass * oM = new nOdbcAttributesClass(this);
		if (oM->loadToOdbc(keyValue.value(0), keyValue.value(1)))
		{
			m_OdbcAttributes_Map.insert(oM->odbcKey, oM);
		}
	}
}
void	TK_PRTHSHSET::initialize()
{
	QLoggingCategory category("classLibQ");
	RETCODE r;
	this->setProfileName(profileName);
	qDebug(category) << "Processing - TRKDB100"; 
//SQL Statements
//--------------------------------------------------

#pragma region Sql Statements_TK_PRTHSHSET

	fetchSql = "select  DB_ID, NVTIMESTAMP, OAREA, OPAGE, OLINE, MAREA, MPAGE, MLINE from TK_PRTHSHSET";
		if (m_ReplicationOption == ReplicationOption::NetChange)
		{
			fetchSql.append(" p1, nv_transfers p2 WHERE  p2.table_name = 'TK_PRTHSHSET' AND p1.nvtimestamp > p2.last_completed");
		}
	insertSql = "insert into TK_PRTHSHSET ( PLANT_CODE, NVTIMESTAMP, OAREA, OPAGE, OLINE, MAREA, MPAGE, MLINE ) values ( ?, ?, ?, ?, ?, ?, ?, ?)";
	updateSql = "update TK_PRTHSHSET set  PLANT_CODE = ?, NVTIMESTAMP = ?, OAREA = ?, OPAGE = ?, OLINE = ?, MAREA = ?, MPAGE = ?, MLINE = ?  where area = ? and page = ? line = ? ";

	qDebug(category) << "insertSQL - insert into TK_PRTHSHSET ( PLANT_CODE, NVTIMESTAMP, OAREA, OPAGE, OLINE, MAREA, MPAGE, MLINE ) values ( ?, ?, ?, ?, ?, ?, ?, ?)";
	qDebug(category) << "fetchSQL - select  DB_ID, NVTIMESTAMP, OAREA, OPAGE, OLINE, MAREA, MPAGE, MLINE from TK_PRTHSHSET";
	qDebug(category) << "unsertSQL - update TK_PRTHSHSET set  PLANT_CODE = ?, NVTIMESTAMP = ?, OAREA = ?, OPAGE = ?, OLINE = ?, MAREA = ?, MPAGE = ?, MLINE = ?  where area = ? and page = ? line = ? ";

#pragma endregion Sql Statements_TK_PRTHSHSET
	SQLHANDLE		insert_hStmt = SQL_NULL_HANDLE;
	SQLHANDLE		fetch_hStmt = SQL_NULL_HANDLE; 
	SQLHANDLE		update_hStmt = SQL_NULL_HANDLE; 
 
	r = ::SQLAllocHandle(SQL_HANDLE_STMT, hDbc_source, &fetch_hStmt);
	if (r != SQL_SUCCESS) {
		 qCCritical(category) << QString("Error  hDbc_Source SQLCode : %1 is %2").arg(QString::number( (long)hDbc_source)).arg(QString::number(r));
		return; 
	}
	r = ::SQLAllocHandle(SQL_HANDLE_STMT, hDbc_target, &insert_hStmt);
	if (r != SQL_SUCCESS) {
		 qCCritical(category) << QString("Error hDbc_Source -SQLCode: %1 is %2").arg(QString::number( (long)hDbc_target)).arg(QString::number(r));
		return; 
	}
	r = ::SQLAllocHandle(SQL_HANDLE_STMT, hDbc_target, &update_hStmt);
	if (r != SQL_SUCCESS) {
		 qCCritical(category) << QString("Error hDbc_Source +SQLCode: %1 is %2").arg(QString::number( (long)hDbc_target)).arg(QString::number(r));
		return; 
	}
 
	hStmt_Fetch = fetch_hStmt;
	hStmt_Insert = insert_hStmt;
	hStmt_Update = update_hStmt;
 
	SQLSetStmtAttr(hStmt_Fetch, SQL_ATTR_USE_BOOKMARKS, (SQLPOINTER)SQL_UB_OFF, 0);
	SQLSetStmtAttr(hStmt_Fetch, SQL_ATTR_ROW_BIND_TYPE, (SQLPOINTER)SQL_BIND_BY_COLUMN, 0);
	SQLSetStmtAttr(hStmt_Fetch, SQL_ATTR_ROW_ARRAY_SIZE, (SQLPOINTER)1, 0);
	SQLSetStmtAttr(hStmt_Fetch, SQL_ATTR_ROWS_FETCHED_PTR, &numRowsFetched, 0);

// Fields used by this class 
// ---------------------------------------------------

#pragma region Resize Fields TK_PRTHSHSET
	qDebug(category) << "Malloc - DB_ID[2]";
	DB_ID.resize(2);
	qDebug(category) << "Malloc - NVTIMESTAMP[23]";
	NVTIMESTAMP.resize(23);
	qDebug(category) << "Malloc - OAREA[2]";
	OAREA.resize(2);
	qDebug(category) << "Malloc - OPAGE[4]";
	OPAGE.resize(4);
	qDebug(category) << "Malloc - OLINE[2]";
	OLINE.resize(2);
	qDebug(category) << "Malloc - MAREA[2]";
	MAREA.resize(2);
	qDebug(category) << "Malloc - MPAGE[4]";
	MPAGE.resize(4);
	qDebug(category) << "Malloc - MLINE[2]";
	MLINE.resize(2);

#pragma endregion Resize Fields TK_PRTHSHSET
}
void TK_PRTHSHSET::close()
{
	QLoggingCategory category("classLibQ");
	if (m_bIsOpen)
	{
	qDebug(category) << "database is Open";
		SQLHANDLE source_hStmt = hStmt_Fetch;
		SQLHANDLE insert_hStmt = hStmt_Insert;
		SQLHANDLE hDb_S = this->hDbc_source;
		SQLHANDLE hDb_T = hDbc_target;
		SQLHANDLE hEnvS = hEnv_Source;
		SQLHANDLE hEnvT = hEnv_Target;
		RETCODE r;

		r = ::SQLFreeHandle(SQL_HANDLE_STMT, hStmt_Fetch);
		r = ::SQLFreeHandle(SQL_HANDLE_STMT, hStmt_Insert);
		r = ::SQLFreeHandle(SQL_HANDLE_STMT, hStmt_Update);
		if (hDbc_source != SQL_NULL_HANDLE) 		r = ::SQLDisconnect(hDb_S);
		if (hDbc_target != SQL_NULL_HANDLE) 		r = ::SQLDisconnect(hDb_T);

		r = ::SQLFreeHandle(SQL_HANDLE_DBC, hDb_S);
		r = ::SQLFreeHandle(SQL_HANDLE_DBC, hDb_T);
		r = ::SQLFreeHandle(SQL_HANDLE_ENV, hEnvS);
		r = ::SQLFreeHandle(SQL_HANDLE_ENV, hEnvT);
	}

	hEnv_Source = SQL_NULL_HANDLE;
	hEnv_Target = SQL_NULL_HANDLE;
	hEnv_Source = SQL_NULL_HANDLE;
	hEnv_Target = SQL_NULL_HANDLE;
	hStmt_Fetch = SQL_NULL_HANDLE;
	hStmt_Insert = SQL_NULL_HANDLE;
	hStmt_Update = SQL_NULL_HANDLE;
}

void TK_PRTHSHSET::open(const QString sourceDSN, const QString targetDSN)
{
	QLoggingCategory category("classLibQ");
	m_lpszTargetDSN = targetDSN;
	m_lpszSourceDSN = sourceDSN;
	qDebug(category) << QString("Source - %1[%2]").arg(sourceDSN);
	qDebug(category) << QString("Target - %1[%2]").arg(targetDSN);
}

void TK_PRTHSHSET::createTable()
{
	QLoggingCategory category("classLibQ");
	{
		QScopedPointer<nvTableOracleRdb> tbl(new nvTableOracleRdb(nullptr));
		tbl->initialize("TK_PRTHSHSET", this->m_lpszSourceDSN);
		QString newTbl = tbl->getCreateTableSQL();
		QScopedPointer<qVtExecute> vExec(new qVtExecute(nullptr));
		{
			vExec->initialize(m_lpszTargetDSN, " ", true);
			vExec->setOdbcAttributes(m_OdbcAttributes);
			vExec->ExecuteDirect(newTbl);
		}
	 qDebug(category) << QString("End Create Table %1 ").arg(tableName); 
	}
}

bool TK_PRTHSHSET::prepare()
{
	RETCODE r;
	QString check;
	QLoggingCategory category("classLibQ");
	 qDebug(category) << fetchSql;
	 qDebug(category) << insertSql;
#ifdef UNICODE
	r = SQLPrepare(hStmt_Insert,toSQLTCHAR(insertSql).data(),(SQLINTEGER)insertSql.length()); 
	if (r != SQL_SUCCESS) {
		check = qWarnODBCHandle(SQL_HANDLE_STMT, hStmt_Insert);
		 qCCritical(category) << QString("Prepare Statement-Insert : %1 is %2").arg(insertSql).arg(check);
		return false; 
	}
	r = SQLPrepare(hStmt_Update,toSQLTCHAR(updateSql).data(),(SQLINTEGER)updateSql.length()); 
	if (r != SQL_SUCCESS) {
		check = qWarnODBCHandle(SQL_HANDLE_STMT, hStmt_Update);
		 qCCritical(category) << QString("Prepare Statement-Update : %1 is %2").arg(updateSql).arg(check);
		return false; 
	}
	r = SQLPrepare(hStmt_Fetch,toSQLTCHAR(fetchSql).data(),(SQLINTEGER)fetchSql.length());
	if (r != SQL_SUCCESS) {
		check = qWarnODBCHandle(SQL_HANDLE_STMT, hStmt_Fetch);
		 qCCritical(category) << QString("Prepare Statement-Insert : %1 is %2").arg(fetchSql).arg(check);
		return false; 
	}
#else
	QByteArray queryI8 = insertSql.toUtf8();
	r = SQLPrepare(insert_hStmt,SQLCHAR*)queryI8.data(),(SQLINTEGER)queryI8.length());
	QByteArray queryU8 = fetchSql.toUtf8();
	r = SQLPrepare(hStmt_Fetch,(SQLCHAR*)queryU8.data(),(SQLINTEGER)queryU8.length());
#endif
	return true;

}

void TK_PRTHSHSET::prepareTargetTable()
{
	QLoggingCategory category("classLibQ");
	if (this->m_ReplicationOption == ReplicationOption::BulkCopy)
	{
		QScopedPointer<qVtExecute> execSql(new qVtExecute(nullptr));
		DropOption option = this->m_dropOption;
		switch (option)
		{
			case DropOption::DeleteFromTable:
			{
				QLoggingCategory category("classLibQ");
				execSql->initialize(this->m_lpszTargetDSN, "delete from TK_PRTHSHSET", true);
				execSql->setOdbcAttributes(this->m_OdbcAttributes);
				execSql->ExecuteDirect("delete from TK_PRTHSHSET");
			}break;
			case DropOption::TruncateTable:
			{
				execSql->initialize(this->m_lpszTargetDSN, "truncate table TK_PRTHSHSET", true);
				execSql->setOdbcAttributes(this->m_OdbcAttributes);
				execSql->ExecuteDirect("truncate table TK_PRTHSHSET");
			}break;
			case DropOption::DropTable:
			{
				execSql->initialize(this->m_lpszTargetDSN, "drop table TK_PRTHSHSET", true);
				execSql->setOdbcAttributes(this->m_OdbcAttributes);
				execSql->ExecuteDirect("drop table TK_PRTHSHSET");
				createTable();
			}break;
		}
	}
}

bool TK_PRTHSHSET::bindColumn()
{
	QLoggingCategory category("classLibQ");
	RETCODE r;
	bool isValid=true;
		 qDebug(category) << " Bindings: Ordinal [1] Type: 5 Buffer Size: 2 FieldName: DB_ID ";
		r = ::SQLBindCol(hStmt_Fetch, 1, 5, DB_ID.data(), 2, &cbDB_ID);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Bindings: Ordinal [2] Type: 93 Buffer Size: 23 FieldName: NVTIMESTAMP ";
		r = ::SQLBindCol(hStmt_Fetch, 2, 93, NVTIMESTAMP.data(), 23, &cbNVTIMESTAMP);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Bindings: Ordinal [3] Type: 5 Buffer Size: 2 FieldName: OAREA ";
		r = ::SQLBindCol(hStmt_Fetch, 3, 5, OAREA.data(), 2, &cbOAREA);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Bindings: Ordinal [4] Type: 4 Buffer Size: 4 FieldName: OPAGE ";
		r = ::SQLBindCol(hStmt_Fetch, 4, 4, OPAGE.data(), 4, &cbOPAGE);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Bindings: Ordinal [5] Type: 5 Buffer Size: 2 FieldName: OLINE ";
		r = ::SQLBindCol(hStmt_Fetch, 5, 5, OLINE.data(), 2, &cbOLINE);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Bindings: Ordinal [6] Type: 5 Buffer Size: 2 FieldName: MAREA ";
		r = ::SQLBindCol(hStmt_Fetch, 6, 5, MAREA.data(), 2, &cbMAREA);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Bindings: Ordinal [7] Type: 4 Buffer Size: 4 FieldName: MPAGE ";
		r = ::SQLBindCol(hStmt_Fetch, 7, 4, MPAGE.data(), 4, &cbMPAGE);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Bindings: Ordinal [8] Type: 5 Buffer Size: 2 FieldName: MLINE ";
		r = ::SQLBindCol(hStmt_Fetch, 8, 5, MLINE.data(), 2, &cbMLINE);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
	return isValid;
}

bool TK_PRTHSHSET::bindParameter()
{
	QLoggingCategory category("classLibQ");
	RETCODE r;
	bool isValid=true;
	{
		 qDebug(category) << " Parameters: Ordinal [1] Type: 5 Buffer Size: 2 FieldName: DB_ID ";
		r = SQLBindParameter(hStmt_Insert, 1, SQL_PARAM_INPUT, SQL_C_DEFAULT, 5, 0, 0, (SQLPOINTER)DB_ID.constData(), 0, &cbDB_ID);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Parameters: Ordinal [2] Type: 93 Buffer Size: 23 FieldName: NVTIMESTAMP ";
		r = SQLBindParameter(hStmt_Insert, 2, SQL_PARAM_INPUT, SQL_C_DEFAULT, 93, 23, 0, (SQLPOINTER)NVTIMESTAMP.constData(), 0, &cbNVTIMESTAMP);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Parameters: Ordinal [3] Type: 5 Buffer Size: 2 FieldName: OAREA ";
		r = SQLBindParameter(hStmt_Insert, 3, SQL_PARAM_INPUT, SQL_C_DEFAULT, 5, 0, 0, (SQLPOINTER)OAREA.constData(), 0, &cbOAREA);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Parameters: Ordinal [4] Type: 4 Buffer Size: 4 FieldName: OPAGE ";
		r = SQLBindParameter(hStmt_Insert, 4, SQL_PARAM_INPUT, SQL_C_DEFAULT, 4, 0, 0, (SQLPOINTER)OPAGE.constData(), 0, &cbOPAGE);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Parameters: Ordinal [5] Type: 5 Buffer Size: 2 FieldName: OLINE ";
		r = SQLBindParameter(hStmt_Insert, 5, SQL_PARAM_INPUT, SQL_C_DEFAULT, 5, 0, 0, (SQLPOINTER)OLINE.constData(), 0, &cbOLINE);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Parameters: Ordinal [6] Type: 5 Buffer Size: 2 FieldName: MAREA ";
		r = SQLBindParameter(hStmt_Insert, 6, SQL_PARAM_INPUT, SQL_C_DEFAULT, 5, 0, 0, (SQLPOINTER)MAREA.constData(), 0, &cbMAREA);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Parameters: Ordinal [7] Type: 4 Buffer Size: 4 FieldName: MPAGE ";
		r = SQLBindParameter(hStmt_Insert, 7, SQL_PARAM_INPUT, SQL_C_DEFAULT, 4, 0, 0, (SQLPOINTER)MPAGE.constData(), 0, &cbMPAGE);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Parameters: Ordinal [8] Type: 5 Buffer Size: 2 FieldName: MLINE ";
		r = SQLBindParameter(hStmt_Insert, 8, SQL_PARAM_INPUT, SQL_C_DEFAULT, 5, 0, 0, (SQLPOINTER)MLINE.constData(), 0, &cbMLINE);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
	}
	if (m_ReplicationOption == ReplicationOption::NetChange)
	{
		r = SQLBindParameter(hStmt_Update, 9, SQL_PARAM_INPUT, SQL_C_DEFAULT, 6, 0, 0, (SQLPOINTER)MAREA.constData(), 0, &cbMAREA);
		if (r == SQL_SUCCESS) { isValid=true; }
		r = SQLBindParameter(hStmt_Update, 10, SQL_PARAM_INPUT, SQL_C_DEFAULT, 7, 0, 0, (SQLPOINTER)MPAGE.constData(), 0, &cbMPAGE);
		if (r == SQL_SUCCESS) { isValid=true; }
		r = SQLBindParameter(hStmt_Update, 11, SQL_PARAM_INPUT, SQL_C_DEFAULT, 8, 0, 0, (SQLPOINTER)MLINE.constData(), 0, &cbMLINE);
		if (r == SQL_SUCCESS) { isValid=true; }
	// TK_PRTHSHSET is a well formed table for eNVy Replication 
		 qDebug(category) << " Parameters: Ordinal [6] 00 00 FieldName: MAREA ";
		 qDebug(category) << " Parameters: Ordinal [7] 00 00  FieldName: MPAGE ";
		 qDebug(category) << " Parameters: Ordinal [8] 00 00 FieldName:  MLINE ";
	} // 	if (m_ReplicationOption == ReplicationOption::NetChange)
	return isValid;
}

bool TK_PRTHSHSET::process(int rowSize)
{
	QLoggingCategory category("classLibQ");
	initOdbcAttributes();
	connect(Source);
	connect(Target);
	initialize();
	prepareTargetTable();
	prepare();
	bindColumn();
	bindParameter();
	copyTable();
	close();
	return false;
}

void TK_PRTHSHSET::copyTable()
{
	QLoggingCategory category("classLibQ");
	RETCODE r;
	QString check;
	r = SQLExecute(hStmt_Fetch);
		if (bIsAbort) {
			emit aborted(tableName, rowsFetched, rowsInserted, rowsUpdated);
			return;
		}
		while((r = SQLFetch(hStmt_Fetch)) != SQL_NO_DATA) {
		if (r != SQL_SUCCESS) {
			check = qWarnODBCHandle(SQL_HANDLE_STMT, hStmt_Fetch);
			qCCritical(category) << QString("SqlFetch - Error : %1 is %2").arg(fetchSql).arg(check);
			return;
		} 
		rowsFetched++;
		if (m_ReplicationOption == ReplicationOption::BulkCopy)
		{
			r = SQLExecute(hStmt_Insert);
			if (r == SQL_ERROR) {
				check = qWarnODBCHandle(SQL_HANDLE_STMT, hStmt_Insert);
				 qCCritical(category) << QString("SqlExecute:Insert - Error : %1 is %2").arg(insertSql).arg(check);
				return;
			}
			rowsInserted++;
			if ((rowsFetched % updateInterval) == 0) {
				qCInfo(category) << QString("[%1.%2]	Insertion: %3	Updates : %4	Fetched : %5").arg(profileName).arg(tableName).arg(rowsInserted).arg(rowsUpdated).arg(rowsFetched);
				emit updateStatusFetched(profileName, tableName, rowsFetched,rowsInserted,rowsUpdated);
			}
			if (m_ReplicationOption == ReplicationOption::NetChange)
			{
			r = SQLExecute(hStmt_Update);
			if (r != SQL_SUCCESS) {
				check = qWarnODBCHandle(SQL_HANDLE_STMT, hStmt_Update);
				 qCInfo(category)  << QString("SqlExecute:Update - Error : %1 is %2").arg(updateSql).arg(check);
				r = SQLExecute(hStmt_Insert);
				if (r != SQL_SUCCESS) {
					check = qWarnODBCHandle(SQL_HANDLE_STMT, hStmt_Insert);
					 qCritical(category) << QString("SqlExecute:Insert - Error : %1 is %2").arg(insertSql).arg(check);
					return;
				}
				else 	rowsInserted++;
				}
				else	rowsUpdated++;
			}
			emit updateStatusFetched(profileName, tableName, rowsFetched,rowsInserted,rowsUpdated);
		}
	} 
qCInfo(category) << QString("[%1.%2]	Insertion: %3	Updates : %4	Fetched : %5").arg(profileName).arg(tableName).arg(rowsInserted).arg(rowsUpdated).arg(rowsFetched);
}

void TK_PRTHSHSET::connect(connectionHandle connectionSource)
{

	QLoggingCategory category("classLibQ");
	RETCODE r;

	bool isValid = false;
	HWND	hWnd = nullptr;
	hWnd = ::GetDesktopWindow(); 
	SQLSMALLINT nResult = 0;

	SQLSMALLINT cb;
	UWORD wConnectOption = SQL_DRIVER_COMPLETE; //SQL_DRIVER_NOPROMPT;
	QVarLengthArray<SQLTCHAR> connOut(1024);
	memset(connOut.data(), 0, connOut.size() * sizeof(SQLTCHAR));

	switch (connectionSource)
	{
		case Source:
			{// environment
				SQLHANDLE hEnv = SQL_NULL_HANDLE;
				SQLHANDLE hDbc = SQL_NULL_HANDLE;
				r = ::SQLAllocHandle(SQL_HANDLE_ENV, SQL_NULL_HANDLE, &hEnv);
				if (r == SQL_SUCCESS) isValid = true;

				foreach(nOdbcAttributesClass * k, this->m_OdbcAttributes_Map)
				{
					if (k->attributeType == enumAttributeType::hEnv)
					{
						r = ::SQLSetEnvAttr(hEnv, (SQLINTEGER) k->odbcKey, (SQLPOINTER)k->odbcValue, 0);
						if (r == SQL_SUCCESS) isValid = true;
					}
				}
				hEnv_Source = hEnv;

				r = SQLAllocHandle(SQL_HANDLE_DBC, hEnv, &hDbc);
				if (r == SQL_SUCCESS) isValid = true;
				foreach(nOdbcAttributesClass * k, this->m_OdbcAttributes_Map)
				{
					if (k->attributeType == enumAttributeType::hDbc)
					{
					r = ::SQLSetConnectAttr(hDbc, k->odbcKey, (SQLPOINTER)k->odbcValue, 0);
					if (k->odbcKey == SQL_ATTR_CONNECTION_POOLING && k->odbcValue == SQL_CP_ONE_PER_DRIVER) wConnectOption = SQL_DRIVER_NOPROMPT;
					if (k->odbcKey == SQL_ATTR_CONNECTION_POOLING && k->odbcValue == SQL_CP_ONE_PER_HENV) wConnectOption = SQL_DRIVER_NOPROMPT;
					if (k->odbcKey == SQL_ATTR_CONNECTION_POOLING && k->odbcValue == SQL_CP_DRIVER_AWARE) wConnectOption = SQL_DRIVER_NOPROMPT;
					if (r == SQL_SUCCESS) isValid = true;
					}
				}
				hDbc_source = hDbc;
				if (isValid)
				{
					r = ::SQLDriverConnect(
						hDbc,
						hWnd,
#ifdef UNICODE
						toSQLTCHAR(m_lpszSourceDSN).data(),
#else
						(SQLCHAR*)dsnSource.toUtf8().data(),
#endif
						(SQLSMALLINT)m_lpszSourceDSN.length(),
						connOut.data(),
						1024,
						&cb, 
						wConnectOption); 
					int colSize = cb / sizeof(SQLTCHAR);
					if (r != SQL_SUCCESS && r != SQL_SUCCESS_WITH_INFO)
					{
						QString check = qWarnODBCHandle(SQL_HANDLE_DBC, hDbc);
						qCritical(category) <<  check;
						m_bIsOpen = false;
					}
					m_bIsOpen = true;
				}
			} break;
		case Target:
			{
				SQLHANDLE hEnv = SQL_NULL_HANDLE;
				SQLHANDLE hDbc = SQL_NULL_HANDLE;
				r = ::SQLAllocHandle(SQL_HANDLE_ENV, SQL_NULL_HANDLE, &hEnv);
				if (r == SQL_SUCCESS) isValid = true;

				foreach(nOdbcAttributesClass * k, this->m_OdbcAttributes_Map)
				{
					if (k->attributeType == enumAttributeType::hEnv)
					{
						r = ::SQLSetEnvAttr(hEnv, (SQLINTEGER) k->odbcKey, (SQLPOINTER)k->odbcValue, 0);
						if (r == SQL_SUCCESS) isValid = true;
					}
				}
				hEnv_Target = hEnv;

				r = SQLAllocHandle(SQL_HANDLE_DBC, hEnv, &hDbc);
				if (r == SQL_SUCCESS) isValid = true;
				foreach(nOdbcAttributesClass * k, this->m_OdbcAttributes_Map)
				{
				if (k->attributeType == enumAttributeType::hDbc)
					{
					r = ::SQLSetConnectAttr(hDbc, k->odbcKey, (SQLPOINTER)k->odbcValue, 0);
					if (k->odbcKey == SQL_ATTR_CONNECTION_POOLING && k->odbcValue == SQL_CP_ONE_PER_DRIVER) wConnectOption = SQL_DRIVER_NOPROMPT;
					if (k->odbcKey == SQL_ATTR_CONNECTION_POOLING && k->odbcValue == SQL_CP_ONE_PER_HENV) wConnectOption = SQL_DRIVER_NOPROMPT;
					if (k->odbcKey == SQL_ATTR_CONNECTION_POOLING && k->odbcValue == SQL_CP_DRIVER_AWARE) wConnectOption = SQL_DRIVER_NOPROMPT;
					if (r == SQL_SUCCESS) isValid = true;
					}
				}
				hDbc_target = hDbc;
				if (isValid) {
					r = ::SQLDriverConnect(
						hDbc,
						hWnd,
#ifdef UNICODE
						toSQLTCHAR(m_lpszTargetDSN).data(),
#else
						(SQLCHAR*)m_lpszTargetDSN.toUtf8().data(),
#endif
						(SQLSMALLINT)m_lpszTargetDSN.length(),
						connOut.data(),
						1024,
						&cb, 
						wConnectOption); 
						int colSize = cb / sizeof(SQLTCHAR);
					if (r != SQL_SUCCESS && r != SQL_SUCCESS_WITH_INFO)
						{
							QString check = qWarnODBCHandle(SQL_HANDLE_DBC, hDbc);
							qCritical(category) <<  check;
							m_bIsOpen = false;
						}
							m_bIsOpen = true;
					}
			} break;
			default: break;
	}
}
TK_TYPHSHSET::TK_TYPHSHSET(QObject * parent) : QObject(parent) 
,tableName("TK_TYPHSHSET")
,m_dropOption(DropOption::DropTable) { 
	numRowsFetched = 0;
}

#pragma region ~CTOR TK_TYPHSHSET 
TK_TYPHSHSET::~TK_TYPHSHSET() { 

#pragma region Buffers - Clear 
	DB_ID.clear();
	NVTIMESTAMP.clear();
	OAREA.clear();
	OPAGE.clear();
	OLINE.clear();
	MAREA.clear();
	MPAGE.clear();
	MLINE.clear();
#pragma endregion Buffers - Clear 
}
#pragma endregion Destructor_TK_TYPHSHSET

// begin method functions
void TK_TYPHSHSET::setAbortFlag() { 
	QLoggingCategory category("classLibQ");
	qCInfo(category) << "isAbort was set to True";
	bIsAbort = true;
}

void TK_TYPHSHSET::run() { 
	process(1);
	QLoggingCategory category("classLibQ");
	qDebug(category) << "Entered;";
}

void	TK_TYPHSHSET::initOdbcAttributes()
{
	QLoggingCategory category("classLibQ");
	this->setProfileName(profileName);
	qDebug(category) << "Processing - TRKDB100"; 
	m_OdbcAttributesList = m_OdbcAttributes.split(","); 
	foreach(QString m, m_OdbcAttributesList)
	{
		QStringList keyValue = m.split("=");
		nOdbcAttributesClass * oM = new nOdbcAttributesClass(this);
		if (oM->loadToOdbc(keyValue.value(0), keyValue.value(1)))
		{
			m_OdbcAttributes_Map.insert(oM->odbcKey, oM);
		}
	}
}
void	TK_TYPHSHSET::initialize()
{
	QLoggingCategory category("classLibQ");
	RETCODE r;
	this->setProfileName(profileName);
	qDebug(category) << "Processing - TRKDB100"; 
//SQL Statements
//--------------------------------------------------

#pragma region Sql Statements_TK_TYPHSHSET

	fetchSql = "select  DB_ID, NVTIMESTAMP, OAREA, OPAGE, OLINE, MAREA, MPAGE, MLINE from TK_TYPHSHSET";
		if (m_ReplicationOption == ReplicationOption::NetChange)
		{
			fetchSql.append(" p1, nv_transfers p2 WHERE  p2.table_name = 'TK_TYPHSHSET' AND p1.nvtimestamp > p2.last_completed");
		}
	insertSql = "insert into TK_TYPHSHSET ( PLANT_CODE, NVTIMESTAMP, OAREA, OPAGE, OLINE, MAREA, MPAGE, MLINE ) values ( ?, ?, ?, ?, ?, ?, ?, ?)";
	updateSql = "update TK_TYPHSHSET set  PLANT_CODE = ?, NVTIMESTAMP = ?, OAREA = ?, OPAGE = ?, OLINE = ?, MAREA = ?, MPAGE = ?, MLINE = ?  where area = ? and page = ? line = ? ";

	qDebug(category) << "insertSQL - insert into TK_TYPHSHSET ( PLANT_CODE, NVTIMESTAMP, OAREA, OPAGE, OLINE, MAREA, MPAGE, MLINE ) values ( ?, ?, ?, ?, ?, ?, ?, ?)";
	qDebug(category) << "fetchSQL - select  DB_ID, NVTIMESTAMP, OAREA, OPAGE, OLINE, MAREA, MPAGE, MLINE from TK_TYPHSHSET";
	qDebug(category) << "unsertSQL - update TK_TYPHSHSET set  PLANT_CODE = ?, NVTIMESTAMP = ?, OAREA = ?, OPAGE = ?, OLINE = ?, MAREA = ?, MPAGE = ?, MLINE = ?  where area = ? and page = ? line = ? ";

#pragma endregion Sql Statements_TK_TYPHSHSET
	SQLHANDLE		insert_hStmt = SQL_NULL_HANDLE;
	SQLHANDLE		fetch_hStmt = SQL_NULL_HANDLE; 
	SQLHANDLE		update_hStmt = SQL_NULL_HANDLE; 
 
	r = ::SQLAllocHandle(SQL_HANDLE_STMT, hDbc_source, &fetch_hStmt);
	if (r != SQL_SUCCESS) {
		 qCCritical(category) << QString("Error  hDbc_Source SQLCode : %1 is %2").arg(QString::number( (long)hDbc_source)).arg(QString::number(r));
		return; 
	}
	r = ::SQLAllocHandle(SQL_HANDLE_STMT, hDbc_target, &insert_hStmt);
	if (r != SQL_SUCCESS) {
		 qCCritical(category) << QString("Error hDbc_Source -SQLCode: %1 is %2").arg(QString::number( (long)hDbc_target)).arg(QString::number(r));
		return; 
	}
	r = ::SQLAllocHandle(SQL_HANDLE_STMT, hDbc_target, &update_hStmt);
	if (r != SQL_SUCCESS) {
		 qCCritical(category) << QString("Error hDbc_Source +SQLCode: %1 is %2").arg(QString::number( (long)hDbc_target)).arg(QString::number(r));
		return; 
	}
 
	hStmt_Fetch = fetch_hStmt;
	hStmt_Insert = insert_hStmt;
	hStmt_Update = update_hStmt;
 
	SQLSetStmtAttr(hStmt_Fetch, SQL_ATTR_USE_BOOKMARKS, (SQLPOINTER)SQL_UB_OFF, 0);
	SQLSetStmtAttr(hStmt_Fetch, SQL_ATTR_ROW_BIND_TYPE, (SQLPOINTER)SQL_BIND_BY_COLUMN, 0);
	SQLSetStmtAttr(hStmt_Fetch, SQL_ATTR_ROW_ARRAY_SIZE, (SQLPOINTER)1, 0);
	SQLSetStmtAttr(hStmt_Fetch, SQL_ATTR_ROWS_FETCHED_PTR, &numRowsFetched, 0);

// Fields used by this class 
// ---------------------------------------------------

#pragma region Resize Fields TK_TYPHSHSET
	qDebug(category) << "Malloc - DB_ID[2]";
	DB_ID.resize(2);
	qDebug(category) << "Malloc - NVTIMESTAMP[23]";
	NVTIMESTAMP.resize(23);
	qDebug(category) << "Malloc - OAREA[2]";
	OAREA.resize(2);
	qDebug(category) << "Malloc - OPAGE[4]";
	OPAGE.resize(4);
	qDebug(category) << "Malloc - OLINE[2]";
	OLINE.resize(2);
	qDebug(category) << "Malloc - MAREA[2]";
	MAREA.resize(2);
	qDebug(category) << "Malloc - MPAGE[4]";
	MPAGE.resize(4);
	qDebug(category) << "Malloc - MLINE[2]";
	MLINE.resize(2);

#pragma endregion Resize Fields TK_TYPHSHSET
}
void TK_TYPHSHSET::close()
{
	QLoggingCategory category("classLibQ");
	if (m_bIsOpen)
	{
	qDebug(category) << "database is Open";
		SQLHANDLE source_hStmt = hStmt_Fetch;
		SQLHANDLE insert_hStmt = hStmt_Insert;
		SQLHANDLE hDb_S = this->hDbc_source;
		SQLHANDLE hDb_T = hDbc_target;
		SQLHANDLE hEnvS = hEnv_Source;
		SQLHANDLE hEnvT = hEnv_Target;
		RETCODE r;

		r = ::SQLFreeHandle(SQL_HANDLE_STMT, hStmt_Fetch);
		r = ::SQLFreeHandle(SQL_HANDLE_STMT, hStmt_Insert);
		r = ::SQLFreeHandle(SQL_HANDLE_STMT, hStmt_Update);
		if (hDbc_source != SQL_NULL_HANDLE) 		r = ::SQLDisconnect(hDb_S);
		if (hDbc_target != SQL_NULL_HANDLE) 		r = ::SQLDisconnect(hDb_T);

		r = ::SQLFreeHandle(SQL_HANDLE_DBC, hDb_S);
		r = ::SQLFreeHandle(SQL_HANDLE_DBC, hDb_T);
		r = ::SQLFreeHandle(SQL_HANDLE_ENV, hEnvS);
		r = ::SQLFreeHandle(SQL_HANDLE_ENV, hEnvT);
	}

	hEnv_Source = SQL_NULL_HANDLE;
	hEnv_Target = SQL_NULL_HANDLE;
	hEnv_Source = SQL_NULL_HANDLE;
	hEnv_Target = SQL_NULL_HANDLE;
	hStmt_Fetch = SQL_NULL_HANDLE;
	hStmt_Insert = SQL_NULL_HANDLE;
	hStmt_Update = SQL_NULL_HANDLE;
}

void TK_TYPHSHSET::open(const QString sourceDSN, const QString targetDSN)
{
	QLoggingCategory category("classLibQ");
	m_lpszTargetDSN = targetDSN;
	m_lpszSourceDSN = sourceDSN;
	qDebug(category) << QString("Source - %1[%2]").arg(sourceDSN);
	qDebug(category) << QString("Target - %1[%2]").arg(targetDSN);
}

void TK_TYPHSHSET::createTable()
{
	QLoggingCategory category("classLibQ");
	{
		QScopedPointer<nvTableOracleRdb> tbl(new nvTableOracleRdb(nullptr));
		tbl->initialize("TK_TYPHSHSET", this->m_lpszSourceDSN);
		QString newTbl = tbl->getCreateTableSQL();
		QScopedPointer<qVtExecute> vExec(new qVtExecute(nullptr));
		{
			vExec->initialize(m_lpszTargetDSN, " ", true);
			vExec->setOdbcAttributes(m_OdbcAttributes);
			vExec->ExecuteDirect(newTbl);
		}
	 qDebug(category) << QString("End Create Table %1 ").arg(tableName); 
	}
}

bool TK_TYPHSHSET::prepare()
{
	RETCODE r;
	QString check;
	QLoggingCategory category("classLibQ");
	 qDebug(category) << fetchSql;
	 qDebug(category) << insertSql;
#ifdef UNICODE
	r = SQLPrepare(hStmt_Insert,toSQLTCHAR(insertSql).data(),(SQLINTEGER)insertSql.length()); 
	if (r != SQL_SUCCESS) {
		check = qWarnODBCHandle(SQL_HANDLE_STMT, hStmt_Insert);
		 qCCritical(category) << QString("Prepare Statement-Insert : %1 is %2").arg(insertSql).arg(check);
		return false; 
	}
	r = SQLPrepare(hStmt_Update,toSQLTCHAR(updateSql).data(),(SQLINTEGER)updateSql.length()); 
	if (r != SQL_SUCCESS) {
		check = qWarnODBCHandle(SQL_HANDLE_STMT, hStmt_Update);
		 qCCritical(category) << QString("Prepare Statement-Update : %1 is %2").arg(updateSql).arg(check);
		return false; 
	}
	r = SQLPrepare(hStmt_Fetch,toSQLTCHAR(fetchSql).data(),(SQLINTEGER)fetchSql.length());
	if (r != SQL_SUCCESS) {
		check = qWarnODBCHandle(SQL_HANDLE_STMT, hStmt_Fetch);
		 qCCritical(category) << QString("Prepare Statement-Insert : %1 is %2").arg(fetchSql).arg(check);
		return false; 
	}
#else
	QByteArray queryI8 = insertSql.toUtf8();
	r = SQLPrepare(insert_hStmt,SQLCHAR*)queryI8.data(),(SQLINTEGER)queryI8.length());
	QByteArray queryU8 = fetchSql.toUtf8();
	r = SQLPrepare(hStmt_Fetch,(SQLCHAR*)queryU8.data(),(SQLINTEGER)queryU8.length());
#endif
	return true;

}

void TK_TYPHSHSET::prepareTargetTable()
{
	QLoggingCategory category("classLibQ");
	if (this->m_ReplicationOption == ReplicationOption::BulkCopy)
	{
		QScopedPointer<qVtExecute> execSql(new qVtExecute(nullptr));
		DropOption option = this->m_dropOption;
		switch (option)
		{
			case DropOption::DeleteFromTable:
			{
				QLoggingCategory category("classLibQ");
				execSql->initialize(this->m_lpszTargetDSN, "delete from TK_TYPHSHSET", true);
				execSql->setOdbcAttributes(this->m_OdbcAttributes);
				execSql->ExecuteDirect("delete from TK_TYPHSHSET");
			}break;
			case DropOption::TruncateTable:
			{
				execSql->initialize(this->m_lpszTargetDSN, "truncate table TK_TYPHSHSET", true);
				execSql->setOdbcAttributes(this->m_OdbcAttributes);
				execSql->ExecuteDirect("truncate table TK_TYPHSHSET");
			}break;
			case DropOption::DropTable:
			{
				execSql->initialize(this->m_lpszTargetDSN, "drop table TK_TYPHSHSET", true);
				execSql->setOdbcAttributes(this->m_OdbcAttributes);
				execSql->ExecuteDirect("drop table TK_TYPHSHSET");
				createTable();
			}break;
		}
	}
}

bool TK_TYPHSHSET::bindColumn()
{
	QLoggingCategory category("classLibQ");
	RETCODE r;
	bool isValid=true;
		 qDebug(category) << " Bindings: Ordinal [1] Type: 5 Buffer Size: 2 FieldName: DB_ID ";
		r = ::SQLBindCol(hStmt_Fetch, 1, 5, DB_ID.data(), 2, &cbDB_ID);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Bindings: Ordinal [2] Type: 93 Buffer Size: 23 FieldName: NVTIMESTAMP ";
		r = ::SQLBindCol(hStmt_Fetch, 2, 93, NVTIMESTAMP.data(), 23, &cbNVTIMESTAMP);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Bindings: Ordinal [3] Type: 5 Buffer Size: 2 FieldName: OAREA ";
		r = ::SQLBindCol(hStmt_Fetch, 3, 5, OAREA.data(), 2, &cbOAREA);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Bindings: Ordinal [4] Type: 4 Buffer Size: 4 FieldName: OPAGE ";
		r = ::SQLBindCol(hStmt_Fetch, 4, 4, OPAGE.data(), 4, &cbOPAGE);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Bindings: Ordinal [5] Type: 5 Buffer Size: 2 FieldName: OLINE ";
		r = ::SQLBindCol(hStmt_Fetch, 5, 5, OLINE.data(), 2, &cbOLINE);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Bindings: Ordinal [6] Type: 5 Buffer Size: 2 FieldName: MAREA ";
		r = ::SQLBindCol(hStmt_Fetch, 6, 5, MAREA.data(), 2, &cbMAREA);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Bindings: Ordinal [7] Type: 4 Buffer Size: 4 FieldName: MPAGE ";
		r = ::SQLBindCol(hStmt_Fetch, 7, 4, MPAGE.data(), 4, &cbMPAGE);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Bindings: Ordinal [8] Type: 5 Buffer Size: 2 FieldName: MLINE ";
		r = ::SQLBindCol(hStmt_Fetch, 8, 5, MLINE.data(), 2, &cbMLINE);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
	return isValid;
}

bool TK_TYPHSHSET::bindParameter()
{
	QLoggingCategory category("classLibQ");
	RETCODE r;
	bool isValid=true;
	{
		 qDebug(category) << " Parameters: Ordinal [1] Type: 5 Buffer Size: 2 FieldName: DB_ID ";
		r = SQLBindParameter(hStmt_Insert, 1, SQL_PARAM_INPUT, SQL_C_DEFAULT, 5, 0, 0, (SQLPOINTER)DB_ID.constData(), 0, &cbDB_ID);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Parameters: Ordinal [2] Type: 93 Buffer Size: 23 FieldName: NVTIMESTAMP ";
		r = SQLBindParameter(hStmt_Insert, 2, SQL_PARAM_INPUT, SQL_C_DEFAULT, 93, 23, 0, (SQLPOINTER)NVTIMESTAMP.constData(), 0, &cbNVTIMESTAMP);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Parameters: Ordinal [3] Type: 5 Buffer Size: 2 FieldName: OAREA ";
		r = SQLBindParameter(hStmt_Insert, 3, SQL_PARAM_INPUT, SQL_C_DEFAULT, 5, 0, 0, (SQLPOINTER)OAREA.constData(), 0, &cbOAREA);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Parameters: Ordinal [4] Type: 4 Buffer Size: 4 FieldName: OPAGE ";
		r = SQLBindParameter(hStmt_Insert, 4, SQL_PARAM_INPUT, SQL_C_DEFAULT, 4, 0, 0, (SQLPOINTER)OPAGE.constData(), 0, &cbOPAGE);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Parameters: Ordinal [5] Type: 5 Buffer Size: 2 FieldName: OLINE ";
		r = SQLBindParameter(hStmt_Insert, 5, SQL_PARAM_INPUT, SQL_C_DEFAULT, 5, 0, 0, (SQLPOINTER)OLINE.constData(), 0, &cbOLINE);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Parameters: Ordinal [6] Type: 5 Buffer Size: 2 FieldName: MAREA ";
		r = SQLBindParameter(hStmt_Insert, 6, SQL_PARAM_INPUT, SQL_C_DEFAULT, 5, 0, 0, (SQLPOINTER)MAREA.constData(), 0, &cbMAREA);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Parameters: Ordinal [7] Type: 4 Buffer Size: 4 FieldName: MPAGE ";
		r = SQLBindParameter(hStmt_Insert, 7, SQL_PARAM_INPUT, SQL_C_DEFAULT, 4, 0, 0, (SQLPOINTER)MPAGE.constData(), 0, &cbMPAGE);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Parameters: Ordinal [8] Type: 5 Buffer Size: 2 FieldName: MLINE ";
		r = SQLBindParameter(hStmt_Insert, 8, SQL_PARAM_INPUT, SQL_C_DEFAULT, 5, 0, 0, (SQLPOINTER)MLINE.constData(), 0, &cbMLINE);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
	}
	if (m_ReplicationOption == ReplicationOption::NetChange)
	{
		r = SQLBindParameter(hStmt_Update, 9, SQL_PARAM_INPUT, SQL_C_DEFAULT, 6, 0, 0, (SQLPOINTER)MAREA.constData(), 0, &cbMAREA);
		if (r == SQL_SUCCESS) { isValid=true; }
		r = SQLBindParameter(hStmt_Update, 10, SQL_PARAM_INPUT, SQL_C_DEFAULT, 7, 0, 0, (SQLPOINTER)MPAGE.constData(), 0, &cbMPAGE);
		if (r == SQL_SUCCESS) { isValid=true; }
		r = SQLBindParameter(hStmt_Update, 11, SQL_PARAM_INPUT, SQL_C_DEFAULT, 8, 0, 0, (SQLPOINTER)MLINE.constData(), 0, &cbMLINE);
		if (r == SQL_SUCCESS) { isValid=true; }
	// TK_TYPHSHSET is a well formed table for eNVy Replication 
		 qDebug(category) << " Parameters: Ordinal [6] 00 00 FieldName: MAREA ";
		 qDebug(category) << " Parameters: Ordinal [7] 00 00  FieldName: MPAGE ";
		 qDebug(category) << " Parameters: Ordinal [8] 00 00 FieldName:  MLINE ";
	} // 	if (m_ReplicationOption == ReplicationOption::NetChange)
	return isValid;
}

bool TK_TYPHSHSET::process(int rowSize)
{
	QLoggingCategory category("classLibQ");
	initOdbcAttributes();
	connect(Source);
	connect(Target);
	initialize();
	prepareTargetTable();
	prepare();
	bindColumn();
	bindParameter();
	copyTable();
	close();
	return false;
}

void TK_TYPHSHSET::copyTable()
{
	QLoggingCategory category("classLibQ");
	RETCODE r;
	QString check;
	r = SQLExecute(hStmt_Fetch);
		if (bIsAbort) {
			emit aborted(tableName, rowsFetched, rowsInserted, rowsUpdated);
			return;
		}
		while((r = SQLFetch(hStmt_Fetch)) != SQL_NO_DATA) {
		if (r != SQL_SUCCESS) {
			check = qWarnODBCHandle(SQL_HANDLE_STMT, hStmt_Fetch);
			qCCritical(category) << QString("SqlFetch - Error : %1 is %2").arg(fetchSql).arg(check);
			return;
		} 
		rowsFetched++;
		if (m_ReplicationOption == ReplicationOption::BulkCopy)
		{
			r = SQLExecute(hStmt_Insert);
			if (r == SQL_ERROR) {
				check = qWarnODBCHandle(SQL_HANDLE_STMT, hStmt_Insert);
				 qCCritical(category) << QString("SqlExecute:Insert - Error : %1 is %2").arg(insertSql).arg(check);
				return;
			}
			rowsInserted++;
			if ((rowsFetched % updateInterval) == 0) {
				qCInfo(category) << QString("[%1.%2]	Insertion: %3	Updates : %4	Fetched : %5").arg(profileName).arg(tableName).arg(rowsInserted).arg(rowsUpdated).arg(rowsFetched);
				emit updateStatusFetched(profileName, tableName, rowsFetched,rowsInserted,rowsUpdated);
			}
			if (m_ReplicationOption == ReplicationOption::NetChange)
			{
			r = SQLExecute(hStmt_Update);
			if (r != SQL_SUCCESS) {
				check = qWarnODBCHandle(SQL_HANDLE_STMT, hStmt_Update);
				 qCInfo(category)  << QString("SqlExecute:Update - Error : %1 is %2").arg(updateSql).arg(check);
				r = SQLExecute(hStmt_Insert);
				if (r != SQL_SUCCESS) {
					check = qWarnODBCHandle(SQL_HANDLE_STMT, hStmt_Insert);
					 qCritical(category) << QString("SqlExecute:Insert - Error : %1 is %2").arg(insertSql).arg(check);
					return;
				}
				else 	rowsInserted++;
				}
				else	rowsUpdated++;
			}
			emit updateStatusFetched(profileName, tableName, rowsFetched,rowsInserted,rowsUpdated);
		}
	} 
qCInfo(category) << QString("[%1.%2]	Insertion: %3	Updates : %4	Fetched : %5").arg(profileName).arg(tableName).arg(rowsInserted).arg(rowsUpdated).arg(rowsFetched);
}

void TK_TYPHSHSET::connect(connectionHandle connectionSource)
{

	QLoggingCategory category("classLibQ");
	RETCODE r;

	bool isValid = false;
	HWND	hWnd = nullptr;
	hWnd = ::GetDesktopWindow(); 
	SQLSMALLINT nResult = 0;

	SQLSMALLINT cb;
	UWORD wConnectOption = SQL_DRIVER_COMPLETE; //SQL_DRIVER_NOPROMPT;
	QVarLengthArray<SQLTCHAR> connOut(1024);
	memset(connOut.data(), 0, connOut.size() * sizeof(SQLTCHAR));

	switch (connectionSource)
	{
		case Source:
			{// environment
				SQLHANDLE hEnv = SQL_NULL_HANDLE;
				SQLHANDLE hDbc = SQL_NULL_HANDLE;
				r = ::SQLAllocHandle(SQL_HANDLE_ENV, SQL_NULL_HANDLE, &hEnv);
				if (r == SQL_SUCCESS) isValid = true;

				foreach(nOdbcAttributesClass * k, this->m_OdbcAttributes_Map)
				{
					if (k->attributeType == enumAttributeType::hEnv)
					{
						r = ::SQLSetEnvAttr(hEnv, (SQLINTEGER) k->odbcKey, (SQLPOINTER)k->odbcValue, 0);
						if (r == SQL_SUCCESS) isValid = true;
					}
				}
				hEnv_Source = hEnv;

				r = SQLAllocHandle(SQL_HANDLE_DBC, hEnv, &hDbc);
				if (r == SQL_SUCCESS) isValid = true;
				foreach(nOdbcAttributesClass * k, this->m_OdbcAttributes_Map)
				{
					if (k->attributeType == enumAttributeType::hDbc)
					{
					r = ::SQLSetConnectAttr(hDbc, k->odbcKey, (SQLPOINTER)k->odbcValue, 0);
					if (k->odbcKey == SQL_ATTR_CONNECTION_POOLING && k->odbcValue == SQL_CP_ONE_PER_DRIVER) wConnectOption = SQL_DRIVER_NOPROMPT;
					if (k->odbcKey == SQL_ATTR_CONNECTION_POOLING && k->odbcValue == SQL_CP_ONE_PER_HENV) wConnectOption = SQL_DRIVER_NOPROMPT;
					if (k->odbcKey == SQL_ATTR_CONNECTION_POOLING && k->odbcValue == SQL_CP_DRIVER_AWARE) wConnectOption = SQL_DRIVER_NOPROMPT;
					if (r == SQL_SUCCESS) isValid = true;
					}
				}
				hDbc_source = hDbc;
				if (isValid)
				{
					r = ::SQLDriverConnect(
						hDbc,
						hWnd,
#ifdef UNICODE
						toSQLTCHAR(m_lpszSourceDSN).data(),
#else
						(SQLCHAR*)dsnSource.toUtf8().data(),
#endif
						(SQLSMALLINT)m_lpszSourceDSN.length(),
						connOut.data(),
						1024,
						&cb, 
						wConnectOption); 
					int colSize = cb / sizeof(SQLTCHAR);
					if (r != SQL_SUCCESS && r != SQL_SUCCESS_WITH_INFO)
					{
						QString check = qWarnODBCHandle(SQL_HANDLE_DBC, hDbc);
						qCritical(category) <<  check;
						m_bIsOpen = false;
					}
					m_bIsOpen = true;
				}
			} break;
		case Target:
			{
				SQLHANDLE hEnv = SQL_NULL_HANDLE;
				SQLHANDLE hDbc = SQL_NULL_HANDLE;
				r = ::SQLAllocHandle(SQL_HANDLE_ENV, SQL_NULL_HANDLE, &hEnv);
				if (r == SQL_SUCCESS) isValid = true;

				foreach(nOdbcAttributesClass * k, this->m_OdbcAttributes_Map)
				{
					if (k->attributeType == enumAttributeType::hEnv)
					{
						r = ::SQLSetEnvAttr(hEnv, (SQLINTEGER) k->odbcKey, (SQLPOINTER)k->odbcValue, 0);
						if (r == SQL_SUCCESS) isValid = true;
					}
				}
				hEnv_Target = hEnv;

				r = SQLAllocHandle(SQL_HANDLE_DBC, hEnv, &hDbc);
				if (r == SQL_SUCCESS) isValid = true;
				foreach(nOdbcAttributesClass * k, this->m_OdbcAttributes_Map)
				{
				if (k->attributeType == enumAttributeType::hDbc)
					{
					r = ::SQLSetConnectAttr(hDbc, k->odbcKey, (SQLPOINTER)k->odbcValue, 0);
					if (k->odbcKey == SQL_ATTR_CONNECTION_POOLING && k->odbcValue == SQL_CP_ONE_PER_DRIVER) wConnectOption = SQL_DRIVER_NOPROMPT;
					if (k->odbcKey == SQL_ATTR_CONNECTION_POOLING && k->odbcValue == SQL_CP_ONE_PER_HENV) wConnectOption = SQL_DRIVER_NOPROMPT;
					if (k->odbcKey == SQL_ATTR_CONNECTION_POOLING && k->odbcValue == SQL_CP_DRIVER_AWARE) wConnectOption = SQL_DRIVER_NOPROMPT;
					if (r == SQL_SUCCESS) isValid = true;
					}
				}
				hDbc_target = hDbc;
				if (isValid) {
					r = ::SQLDriverConnect(
						hDbc,
						hWnd,
#ifdef UNICODE
						toSQLTCHAR(m_lpszTargetDSN).data(),
#else
						(SQLCHAR*)m_lpszTargetDSN.toUtf8().data(),
#endif
						(SQLSMALLINT)m_lpszTargetDSN.length(),
						connOut.data(),
						1024,
						&cb, 
						wConnectOption); 
						int colSize = cb / sizeof(SQLTCHAR);
					if (r != SQL_SUCCESS && r != SQL_SUCCESS_WITH_INFO)
						{
							QString check = qWarnODBCHandle(SQL_HANDLE_DBC, hDbc);
							qCritical(category) <<  check;
							m_bIsOpen = false;
						}
							m_bIsOpen = true;
					}
			} break;
			default: break;
	}
}
TK_FLGREC::TK_FLGREC(QObject * parent) : QObject(parent) 
,tableName("TK_FLGREC")
,m_dropOption(DropOption::DropTable) { 
	numRowsFetched = 0;
}

#pragma region ~CTOR TK_FLGREC 
TK_FLGREC::~TK_FLGREC() { 

#pragma region Buffers - Clear 
	DB_ID.clear();
	NVTIMESTAMP.clear();
	AREA.clear();
	PAGE.clear();
	LINE.clear();
	TK_FLGNO.clear();
	TK_FLGVALU.clear();
#pragma endregion Buffers - Clear 
}
#pragma endregion Destructor_TK_FLGREC

// begin method functions
void TK_FLGREC::setAbortFlag() { 
	QLoggingCategory category("classLibQ");
	qCInfo(category) << "isAbort was set to True";
	bIsAbort = true;
}

void TK_FLGREC::run() { 
	process(1);
	QLoggingCategory category("classLibQ");
	qDebug(category) << "Entered;";
}

void	TK_FLGREC::initOdbcAttributes()
{
	QLoggingCategory category("classLibQ");
	this->setProfileName(profileName);
	qDebug(category) << "Processing - TRKDB100"; 
	m_OdbcAttributesList = m_OdbcAttributes.split(","); 
	foreach(QString m, m_OdbcAttributesList)
	{
		QStringList keyValue = m.split("=");
		nOdbcAttributesClass * oM = new nOdbcAttributesClass(this);
		if (oM->loadToOdbc(keyValue.value(0), keyValue.value(1)))
		{
			m_OdbcAttributes_Map.insert(oM->odbcKey, oM);
		}
	}
}
void	TK_FLGREC::initialize()
{
	QLoggingCategory category("classLibQ");
	RETCODE r;
	this->setProfileName(profileName);
	qDebug(category) << "Processing - TRKDB100"; 
//SQL Statements
//--------------------------------------------------

#pragma region Sql Statements_TK_FLGREC

	fetchSql = "select  DB_ID, NVTIMESTAMP, AREA, PAGE, LINE, TK_FLGNO, TK_FLGVALU from TK_FLGREC";
		if (m_ReplicationOption == ReplicationOption::NetChange)
		{
			fetchSql.append(" p1, nv_transfers p2 WHERE  p2.table_name = 'TK_FLGREC' AND p1.nvtimestamp > p2.last_completed");
		}
	insertSql = "insert into TK_FLGREC ( PLANT_CODE, NVTIMESTAMP, AREA, PAGE, LINE, TK_FLGNO, TK_FLGVALU ) values ( ?, ?, ?, ?, ?, ?, ?)";
	updateSql = "update TK_FLGREC set  PLANT_CODE = ?, NVTIMESTAMP = ?, AREA = ?, PAGE = ?, LINE = ?, TK_FLGNO = ?, TK_FLGVALU = ?  where area = ? and page = ? line = ? ";

	qDebug(category) << "insertSQL - insert into TK_FLGREC ( PLANT_CODE, NVTIMESTAMP, AREA, PAGE, LINE, TK_FLGNO, TK_FLGVALU ) values ( ?, ?, ?, ?, ?, ?, ?)";
	qDebug(category) << "fetchSQL - select  DB_ID, NVTIMESTAMP, AREA, PAGE, LINE, TK_FLGNO, TK_FLGVALU from TK_FLGREC";
	qDebug(category) << "unsertSQL - update TK_FLGREC set  PLANT_CODE = ?, NVTIMESTAMP = ?, AREA = ?, PAGE = ?, LINE = ?, TK_FLGNO = ?, TK_FLGVALU = ?  where area = ? and page = ? line = ? ";

#pragma endregion Sql Statements_TK_FLGREC
	SQLHANDLE		insert_hStmt = SQL_NULL_HANDLE;
	SQLHANDLE		fetch_hStmt = SQL_NULL_HANDLE; 
	SQLHANDLE		update_hStmt = SQL_NULL_HANDLE; 
 
	r = ::SQLAllocHandle(SQL_HANDLE_STMT, hDbc_source, &fetch_hStmt);
	if (r != SQL_SUCCESS) {
		 qCCritical(category) << QString("Error  hDbc_Source SQLCode : %1 is %2").arg(QString::number( (long)hDbc_source)).arg(QString::number(r));
		return; 
	}
	r = ::SQLAllocHandle(SQL_HANDLE_STMT, hDbc_target, &insert_hStmt);
	if (r != SQL_SUCCESS) {
		 qCCritical(category) << QString("Error hDbc_Source -SQLCode: %1 is %2").arg(QString::number( (long)hDbc_target)).arg(QString::number(r));
		return; 
	}
	r = ::SQLAllocHandle(SQL_HANDLE_STMT, hDbc_target, &update_hStmt);
	if (r != SQL_SUCCESS) {
		 qCCritical(category) << QString("Error hDbc_Source +SQLCode: %1 is %2").arg(QString::number( (long)hDbc_target)).arg(QString::number(r));
		return; 
	}
 
	hStmt_Fetch = fetch_hStmt;
	hStmt_Insert = insert_hStmt;
	hStmt_Update = update_hStmt;
 
	SQLSetStmtAttr(hStmt_Fetch, SQL_ATTR_USE_BOOKMARKS, (SQLPOINTER)SQL_UB_OFF, 0);
	SQLSetStmtAttr(hStmt_Fetch, SQL_ATTR_ROW_BIND_TYPE, (SQLPOINTER)SQL_BIND_BY_COLUMN, 0);
	SQLSetStmtAttr(hStmt_Fetch, SQL_ATTR_ROW_ARRAY_SIZE, (SQLPOINTER)1, 0);
	SQLSetStmtAttr(hStmt_Fetch, SQL_ATTR_ROWS_FETCHED_PTR, &numRowsFetched, 0);

// Fields used by this class 
// ---------------------------------------------------

#pragma region Resize Fields TK_FLGREC
	qDebug(category) << "Malloc - DB_ID[2]";
	DB_ID.resize(2);
	qDebug(category) << "Malloc - NVTIMESTAMP[23]";
	NVTIMESTAMP.resize(23);
	qDebug(category) << "Malloc - AREA[2]";
	AREA.resize(2);
	qDebug(category) << "Malloc - PAGE[4]";
	PAGE.resize(4);
	qDebug(category) << "Malloc - LINE[2]";
	LINE.resize(2);
	qDebug(category) << "Malloc - TK_FLGNO[2]";
	TK_FLGNO.resize(2);
	qDebug(category) << "Malloc - TK_FLGVALU[30]";
	TK_FLGVALU.resize(30);

#pragma endregion Resize Fields TK_FLGREC
}
void TK_FLGREC::close()
{
	QLoggingCategory category("classLibQ");
	if (m_bIsOpen)
	{
	qDebug(category) << "database is Open";
		SQLHANDLE source_hStmt = hStmt_Fetch;
		SQLHANDLE insert_hStmt = hStmt_Insert;
		SQLHANDLE hDb_S = this->hDbc_source;
		SQLHANDLE hDb_T = hDbc_target;
		SQLHANDLE hEnvS = hEnv_Source;
		SQLHANDLE hEnvT = hEnv_Target;
		RETCODE r;

		r = ::SQLFreeHandle(SQL_HANDLE_STMT, hStmt_Fetch);
		r = ::SQLFreeHandle(SQL_HANDLE_STMT, hStmt_Insert);
		r = ::SQLFreeHandle(SQL_HANDLE_STMT, hStmt_Update);
		if (hDbc_source != SQL_NULL_HANDLE) 		r = ::SQLDisconnect(hDb_S);
		if (hDbc_target != SQL_NULL_HANDLE) 		r = ::SQLDisconnect(hDb_T);

		r = ::SQLFreeHandle(SQL_HANDLE_DBC, hDb_S);
		r = ::SQLFreeHandle(SQL_HANDLE_DBC, hDb_T);
		r = ::SQLFreeHandle(SQL_HANDLE_ENV, hEnvS);
		r = ::SQLFreeHandle(SQL_HANDLE_ENV, hEnvT);
	}

	hEnv_Source = SQL_NULL_HANDLE;
	hEnv_Target = SQL_NULL_HANDLE;
	hEnv_Source = SQL_NULL_HANDLE;
	hEnv_Target = SQL_NULL_HANDLE;
	hStmt_Fetch = SQL_NULL_HANDLE;
	hStmt_Insert = SQL_NULL_HANDLE;
	hStmt_Update = SQL_NULL_HANDLE;
}

void TK_FLGREC::open(const QString sourceDSN, const QString targetDSN)
{
	QLoggingCategory category("classLibQ");
	m_lpszTargetDSN = targetDSN;
	m_lpszSourceDSN = sourceDSN;
	qDebug(category) << QString("Source - %1[%2]").arg(sourceDSN);
	qDebug(category) << QString("Target - %1[%2]").arg(targetDSN);
}

void TK_FLGREC::createTable()
{
	QLoggingCategory category("classLibQ");
	{
		QScopedPointer<nvTableOracleRdb> tbl(new nvTableOracleRdb(nullptr));
		tbl->initialize("TK_FLGREC", this->m_lpszSourceDSN);
		QString newTbl = tbl->getCreateTableSQL();
		QScopedPointer<qVtExecute> vExec(new qVtExecute(nullptr));
		{
			vExec->initialize(m_lpszTargetDSN, " ", true);
			vExec->setOdbcAttributes(m_OdbcAttributes);
			vExec->ExecuteDirect(newTbl);
		}
	 qDebug(category) << QString("End Create Table %1 ").arg(tableName); 
	}
}

bool TK_FLGREC::prepare()
{
	RETCODE r;
	QString check;
	QLoggingCategory category("classLibQ");
	 qDebug(category) << fetchSql;
	 qDebug(category) << insertSql;
#ifdef UNICODE
	r = SQLPrepare(hStmt_Insert,toSQLTCHAR(insertSql).data(),(SQLINTEGER)insertSql.length()); 
	if (r != SQL_SUCCESS) {
		check = qWarnODBCHandle(SQL_HANDLE_STMT, hStmt_Insert);
		 qCCritical(category) << QString("Prepare Statement-Insert : %1 is %2").arg(insertSql).arg(check);
		return false; 
	}
	r = SQLPrepare(hStmt_Update,toSQLTCHAR(updateSql).data(),(SQLINTEGER)updateSql.length()); 
	if (r != SQL_SUCCESS) {
		check = qWarnODBCHandle(SQL_HANDLE_STMT, hStmt_Update);
		 qCCritical(category) << QString("Prepare Statement-Update : %1 is %2").arg(updateSql).arg(check);
		return false; 
	}
	r = SQLPrepare(hStmt_Fetch,toSQLTCHAR(fetchSql).data(),(SQLINTEGER)fetchSql.length());
	if (r != SQL_SUCCESS) {
		check = qWarnODBCHandle(SQL_HANDLE_STMT, hStmt_Fetch);
		 qCCritical(category) << QString("Prepare Statement-Insert : %1 is %2").arg(fetchSql).arg(check);
		return false; 
	}
#else
	QByteArray queryI8 = insertSql.toUtf8();
	r = SQLPrepare(insert_hStmt,SQLCHAR*)queryI8.data(),(SQLINTEGER)queryI8.length());
	QByteArray queryU8 = fetchSql.toUtf8();
	r = SQLPrepare(hStmt_Fetch,(SQLCHAR*)queryU8.data(),(SQLINTEGER)queryU8.length());
#endif
	return true;

}

void TK_FLGREC::prepareTargetTable()
{
	QLoggingCategory category("classLibQ");
	if (this->m_ReplicationOption == ReplicationOption::BulkCopy)
	{
		QScopedPointer<qVtExecute> execSql(new qVtExecute(nullptr));
		DropOption option = this->m_dropOption;
		switch (option)
		{
			case DropOption::DeleteFromTable:
			{
				QLoggingCategory category("classLibQ");
				execSql->initialize(this->m_lpszTargetDSN, "delete from TK_FLGREC", true);
				execSql->setOdbcAttributes(this->m_OdbcAttributes);
				execSql->ExecuteDirect("delete from TK_FLGREC");
			}break;
			case DropOption::TruncateTable:
			{
				execSql->initialize(this->m_lpszTargetDSN, "truncate table TK_FLGREC", true);
				execSql->setOdbcAttributes(this->m_OdbcAttributes);
				execSql->ExecuteDirect("truncate table TK_FLGREC");
			}break;
			case DropOption::DropTable:
			{
				execSql->initialize(this->m_lpszTargetDSN, "drop table TK_FLGREC", true);
				execSql->setOdbcAttributes(this->m_OdbcAttributes);
				execSql->ExecuteDirect("drop table TK_FLGREC");
				createTable();
			}break;
		}
	}
}

bool TK_FLGREC::bindColumn()
{
	QLoggingCategory category("classLibQ");
	RETCODE r;
	bool isValid=true;
		 qDebug(category) << " Bindings: Ordinal [1] Type: 5 Buffer Size: 2 FieldName: DB_ID ";
		r = ::SQLBindCol(hStmt_Fetch, 1, 5, DB_ID.data(), 2, &cbDB_ID);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Bindings: Ordinal [2] Type: 93 Buffer Size: 23 FieldName: NVTIMESTAMP ";
		r = ::SQLBindCol(hStmt_Fetch, 2, 93, NVTIMESTAMP.data(), 23, &cbNVTIMESTAMP);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Bindings: Ordinal [3] Type: 5 Buffer Size: 2 FieldName: AREA ";
		r = ::SQLBindCol(hStmt_Fetch, 3, 5, AREA.data(), 2, &cbAREA);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Bindings: Ordinal [4] Type: 4 Buffer Size: 4 FieldName: PAGE ";
		r = ::SQLBindCol(hStmt_Fetch, 4, 4, PAGE.data(), 4, &cbPAGE);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Bindings: Ordinal [5] Type: 5 Buffer Size: 2 FieldName: LINE ";
		r = ::SQLBindCol(hStmt_Fetch, 5, 5, LINE.data(), 2, &cbLINE);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Bindings: Ordinal [6] Type: 5 Buffer Size: 2 FieldName: TK_FLGNO ";
		r = ::SQLBindCol(hStmt_Fetch, 6, 5, TK_FLGNO.data(), 2, &cbTK_FLGNO);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Bindings: Ordinal [7] Type: 1 Buffer Size: 30 FieldName: TK_FLGVALU ";
		r = ::SQLBindCol(hStmt_Fetch, 7, 1, TK_FLGVALU.data(), 30, &cbTK_FLGVALU);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
	return isValid;
}

bool TK_FLGREC::bindParameter()
{
	QLoggingCategory category("classLibQ");
	RETCODE r;
	bool isValid=true;
	{
		 qDebug(category) << " Parameters: Ordinal [1] Type: 5 Buffer Size: 2 FieldName: DB_ID ";
		r = SQLBindParameter(hStmt_Insert, 1, SQL_PARAM_INPUT, SQL_C_DEFAULT, 5, 0, 0, (SQLPOINTER)DB_ID.constData(), 0, &cbDB_ID);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Parameters: Ordinal [2] Type: 93 Buffer Size: 23 FieldName: NVTIMESTAMP ";
		r = SQLBindParameter(hStmt_Insert, 2, SQL_PARAM_INPUT, SQL_C_DEFAULT, 93, 23, 0, (SQLPOINTER)NVTIMESTAMP.constData(), 0, &cbNVTIMESTAMP);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Parameters: Ordinal [3] Type: 5 Buffer Size: 2 FieldName: AREA ";
		r = SQLBindParameter(hStmt_Insert, 3, SQL_PARAM_INPUT, SQL_C_DEFAULT, 5, 0, 0, (SQLPOINTER)AREA.constData(), 0, &cbAREA);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Parameters: Ordinal [4] Type: 4 Buffer Size: 4 FieldName: PAGE ";
		r = SQLBindParameter(hStmt_Insert, 4, SQL_PARAM_INPUT, SQL_C_DEFAULT, 4, 0, 0, (SQLPOINTER)PAGE.constData(), 0, &cbPAGE);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Parameters: Ordinal [5] Type: 5 Buffer Size: 2 FieldName: LINE ";
		r = SQLBindParameter(hStmt_Insert, 5, SQL_PARAM_INPUT, SQL_C_DEFAULT, 5, 0, 0, (SQLPOINTER)LINE.constData(), 0, &cbLINE);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Parameters: Ordinal [6] Type: 5 Buffer Size: 2 FieldName: TK_FLGNO ";
		r = SQLBindParameter(hStmt_Insert, 6, SQL_PARAM_INPUT, SQL_C_DEFAULT, 5, 0, 0, (SQLPOINTER)TK_FLGNO.constData(), 0, &cbTK_FLGNO);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Parameters: Ordinal [7] Type: 1 Buffer Size: 30 FieldName: TK_FLGVALU ";
		r = SQLBindParameter(hStmt_Insert, 7, SQL_PARAM_INPUT, SQL_C_DEFAULT, 1, 30, 0, (SQLPOINTER)TK_FLGVALU.constData(), 0, &cbTK_FLGVALU);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
	}
	if (m_ReplicationOption == ReplicationOption::NetChange)
	{
		r = SQLBindParameter(hStmt_Update, 8, SQL_PARAM_INPUT, SQL_C_DEFAULT, 3, 0, 0, (SQLPOINTER)AREA.constData(), 0, &cbAREA);
		if (r == SQL_SUCCESS) { isValid=true; }
		r = SQLBindParameter(hStmt_Update, 9, SQL_PARAM_INPUT, SQL_C_DEFAULT, 4, 0, 0, (SQLPOINTER)PAGE.constData(), 0, &cbPAGE);
		if (r == SQL_SUCCESS) { isValid=true; }
		r = SQLBindParameter(hStmt_Update, 10, SQL_PARAM_INPUT, SQL_C_DEFAULT, 5, 0, 0, (SQLPOINTER)LINE.constData(), 0, &cbLINE);
		if (r == SQL_SUCCESS) { isValid=true; }
	// TK_FLGREC is a well formed table for eNVy Replication 
		 qDebug(category) << " Parameters: Ordinal [3] 00 00 FieldName: AREA ";
		 qDebug(category) << " Parameters: Ordinal [4] 00 00  FieldName: PAGE ";
		 qDebug(category) << " Parameters: Ordinal [5] 00 00 FieldName:  LINE ";
	} // 	if (m_ReplicationOption == ReplicationOption::NetChange)
	return isValid;
}

bool TK_FLGREC::process(int rowSize)
{
	QLoggingCategory category("classLibQ");
	initOdbcAttributes();
	connect(Source);
	connect(Target);
	initialize();
	prepareTargetTable();
	prepare();
	bindColumn();
	bindParameter();
	copyTable();
	close();
	return false;
}

void TK_FLGREC::copyTable()
{
	QLoggingCategory category("classLibQ");
	RETCODE r;
	QString check;
	r = SQLExecute(hStmt_Fetch);
		if (bIsAbort) {
			emit aborted(tableName, rowsFetched, rowsInserted, rowsUpdated);
			return;
		}
		while((r = SQLFetch(hStmt_Fetch)) != SQL_NO_DATA) {
		if (r != SQL_SUCCESS) {
			check = qWarnODBCHandle(SQL_HANDLE_STMT, hStmt_Fetch);
			qCCritical(category) << QString("SqlFetch - Error : %1 is %2").arg(fetchSql).arg(check);
			return;
		} 
		rowsFetched++;
		if (m_ReplicationOption == ReplicationOption::BulkCopy)
		{
			r = SQLExecute(hStmt_Insert);
			if (r == SQL_ERROR) {
				check = qWarnODBCHandle(SQL_HANDLE_STMT, hStmt_Insert);
				 qCCritical(category) << QString("SqlExecute:Insert - Error : %1 is %2").arg(insertSql).arg(check);
				return;
			}
			rowsInserted++;
			if ((rowsFetched % updateInterval) == 0) {
				qCInfo(category) << QString("[%1.%2]	Insertion: %3	Updates : %4	Fetched : %5").arg(profileName).arg(tableName).arg(rowsInserted).arg(rowsUpdated).arg(rowsFetched);
				emit updateStatusFetched(profileName, tableName, rowsFetched,rowsInserted,rowsUpdated);
			}
			if (m_ReplicationOption == ReplicationOption::NetChange)
			{
			r = SQLExecute(hStmt_Update);
			if (r != SQL_SUCCESS) {
				check = qWarnODBCHandle(SQL_HANDLE_STMT, hStmt_Update);
				 qCInfo(category)  << QString("SqlExecute:Update - Error : %1 is %2").arg(updateSql).arg(check);
				r = SQLExecute(hStmt_Insert);
				if (r != SQL_SUCCESS) {
					check = qWarnODBCHandle(SQL_HANDLE_STMT, hStmt_Insert);
					 qCritical(category) << QString("SqlExecute:Insert - Error : %1 is %2").arg(insertSql).arg(check);
					return;
				}
				else 	rowsInserted++;
				}
				else	rowsUpdated++;
			}
			emit updateStatusFetched(profileName, tableName, rowsFetched,rowsInserted,rowsUpdated);
		}
	} 
qCInfo(category) << QString("[%1.%2]	Insertion: %3	Updates : %4	Fetched : %5").arg(profileName).arg(tableName).arg(rowsInserted).arg(rowsUpdated).arg(rowsFetched);
}

void TK_FLGREC::connect(connectionHandle connectionSource)
{

	QLoggingCategory category("classLibQ");
	RETCODE r;

	bool isValid = false;
	HWND	hWnd = nullptr;
	hWnd = ::GetDesktopWindow(); 
	SQLSMALLINT nResult = 0;

	SQLSMALLINT cb;
	UWORD wConnectOption = SQL_DRIVER_COMPLETE; //SQL_DRIVER_NOPROMPT;
	QVarLengthArray<SQLTCHAR> connOut(1024);
	memset(connOut.data(), 0, connOut.size() * sizeof(SQLTCHAR));

	switch (connectionSource)
	{
		case Source:
			{// environment
				SQLHANDLE hEnv = SQL_NULL_HANDLE;
				SQLHANDLE hDbc = SQL_NULL_HANDLE;
				r = ::SQLAllocHandle(SQL_HANDLE_ENV, SQL_NULL_HANDLE, &hEnv);
				if (r == SQL_SUCCESS) isValid = true;

				foreach(nOdbcAttributesClass * k, this->m_OdbcAttributes_Map)
				{
					if (k->attributeType == enumAttributeType::hEnv)
					{
						r = ::SQLSetEnvAttr(hEnv, (SQLINTEGER) k->odbcKey, (SQLPOINTER)k->odbcValue, 0);
						if (r == SQL_SUCCESS) isValid = true;
					}
				}
				hEnv_Source = hEnv;

				r = SQLAllocHandle(SQL_HANDLE_DBC, hEnv, &hDbc);
				if (r == SQL_SUCCESS) isValid = true;
				foreach(nOdbcAttributesClass * k, this->m_OdbcAttributes_Map)
				{
					if (k->attributeType == enumAttributeType::hDbc)
					{
					r = ::SQLSetConnectAttr(hDbc, k->odbcKey, (SQLPOINTER)k->odbcValue, 0);
					if (k->odbcKey == SQL_ATTR_CONNECTION_POOLING && k->odbcValue == SQL_CP_ONE_PER_DRIVER) wConnectOption = SQL_DRIVER_NOPROMPT;
					if (k->odbcKey == SQL_ATTR_CONNECTION_POOLING && k->odbcValue == SQL_CP_ONE_PER_HENV) wConnectOption = SQL_DRIVER_NOPROMPT;
					if (k->odbcKey == SQL_ATTR_CONNECTION_POOLING && k->odbcValue == SQL_CP_DRIVER_AWARE) wConnectOption = SQL_DRIVER_NOPROMPT;
					if (r == SQL_SUCCESS) isValid = true;
					}
				}
				hDbc_source = hDbc;
				if (isValid)
				{
					r = ::SQLDriverConnect(
						hDbc,
						hWnd,
#ifdef UNICODE
						toSQLTCHAR(m_lpszSourceDSN).data(),
#else
						(SQLCHAR*)dsnSource.toUtf8().data(),
#endif
						(SQLSMALLINT)m_lpszSourceDSN.length(),
						connOut.data(),
						1024,
						&cb, 
						wConnectOption); 
					int colSize = cb / sizeof(SQLTCHAR);
					if (r != SQL_SUCCESS && r != SQL_SUCCESS_WITH_INFO)
					{
						QString check = qWarnODBCHandle(SQL_HANDLE_DBC, hDbc);
						qCritical(category) <<  check;
						m_bIsOpen = false;
					}
					m_bIsOpen = true;
				}
			} break;
		case Target:
			{
				SQLHANDLE hEnv = SQL_NULL_HANDLE;
				SQLHANDLE hDbc = SQL_NULL_HANDLE;
				r = ::SQLAllocHandle(SQL_HANDLE_ENV, SQL_NULL_HANDLE, &hEnv);
				if (r == SQL_SUCCESS) isValid = true;

				foreach(nOdbcAttributesClass * k, this->m_OdbcAttributes_Map)
				{
					if (k->attributeType == enumAttributeType::hEnv)
					{
						r = ::SQLSetEnvAttr(hEnv, (SQLINTEGER) k->odbcKey, (SQLPOINTER)k->odbcValue, 0);
						if (r == SQL_SUCCESS) isValid = true;
					}
				}
				hEnv_Target = hEnv;

				r = SQLAllocHandle(SQL_HANDLE_DBC, hEnv, &hDbc);
				if (r == SQL_SUCCESS) isValid = true;
				foreach(nOdbcAttributesClass * k, this->m_OdbcAttributes_Map)
				{
				if (k->attributeType == enumAttributeType::hDbc)
					{
					r = ::SQLSetConnectAttr(hDbc, k->odbcKey, (SQLPOINTER)k->odbcValue, 0);
					if (k->odbcKey == SQL_ATTR_CONNECTION_POOLING && k->odbcValue == SQL_CP_ONE_PER_DRIVER) wConnectOption = SQL_DRIVER_NOPROMPT;
					if (k->odbcKey == SQL_ATTR_CONNECTION_POOLING && k->odbcValue == SQL_CP_ONE_PER_HENV) wConnectOption = SQL_DRIVER_NOPROMPT;
					if (k->odbcKey == SQL_ATTR_CONNECTION_POOLING && k->odbcValue == SQL_CP_DRIVER_AWARE) wConnectOption = SQL_DRIVER_NOPROMPT;
					if (r == SQL_SUCCESS) isValid = true;
					}
				}
				hDbc_target = hDbc;
				if (isValid) {
					r = ::SQLDriverConnect(
						hDbc,
						hWnd,
#ifdef UNICODE
						toSQLTCHAR(m_lpszTargetDSN).data(),
#else
						(SQLCHAR*)m_lpszTargetDSN.toUtf8().data(),
#endif
						(SQLSMALLINT)m_lpszTargetDSN.length(),
						connOut.data(),
						1024,
						&cb, 
						wConnectOption); 
						int colSize = cb / sizeof(SQLTCHAR);
					if (r != SQL_SUCCESS && r != SQL_SUCCESS_WITH_INFO)
						{
							QString check = qWarnODBCHandle(SQL_HANDLE_DBC, hDbc);
							qCritical(category) <<  check;
							m_bIsOpen = false;
						}
							m_bIsOpen = true;
					}
			} break;
			default: break;
	}
}
TK_LTFREC::TK_LTFREC(QObject * parent) : QObject(parent) 
,tableName("TK_LTFREC")
,m_dropOption(DropOption::DropTable) { 
	numRowsFetched = 0;
}

#pragma region ~CTOR TK_LTFREC 
TK_LTFREC::~TK_LTFREC() { 

#pragma region Buffers - Clear 
	DB_ID.clear();
	NVTIMESTAMP.clear();
	AREA.clear();
	PAGE.clear();
	LINE.clear();
	TK_LTFVALUE.clear();
	TK_LTFUSR.clear();
	TK_LTFDAT.clear();
	TK_LTFTIM.clear();
	TK_LTFCMD.clear();
	TK_PRTNO.clear();
#pragma endregion Buffers - Clear 
}
#pragma endregion Destructor_TK_LTFREC

// begin method functions
void TK_LTFREC::setAbortFlag() { 
	QLoggingCategory category("classLibQ");
	qCInfo(category) << "isAbort was set to True";
	bIsAbort = true;
}

void TK_LTFREC::run() { 
	process(1);
	QLoggingCategory category("classLibQ");
	qDebug(category) << "Entered;";
}

void	TK_LTFREC::initOdbcAttributes()
{
	QLoggingCategory category("classLibQ");
	this->setProfileName(profileName);
	qDebug(category) << "Processing - TRKDB100"; 
	m_OdbcAttributesList = m_OdbcAttributes.split(","); 
	foreach(QString m, m_OdbcAttributesList)
	{
		QStringList keyValue = m.split("=");
		nOdbcAttributesClass * oM = new nOdbcAttributesClass(this);
		if (oM->loadToOdbc(keyValue.value(0), keyValue.value(1)))
		{
			m_OdbcAttributes_Map.insert(oM->odbcKey, oM);
		}
	}
}
void	TK_LTFREC::initialize()
{
	QLoggingCategory category("classLibQ");
	RETCODE r;
	this->setProfileName(profileName);
	qDebug(category) << "Processing - TRKDB100"; 
//SQL Statements
//--------------------------------------------------

#pragma region Sql Statements_TK_LTFREC

	fetchSql = "select  DB_ID, NVTIMESTAMP, AREA, PAGE, LINE, TK_LTFVALUE, TK_LTFUSR, TK_LTFDAT, TK_LTFTIM, TK_LTFCMD, TK_PRTNO from TK_LTFREC";
		if (m_ReplicationOption == ReplicationOption::NetChange)
		{
			fetchSql.append(" p1, nv_transfers p2 WHERE  p2.table_name = 'TK_LTFREC' AND p1.nvtimestamp > p2.last_completed");
		}
	insertSql = "insert into TK_LTFREC ( PLANT_CODE, NVTIMESTAMP, AREA, PAGE, LINE, TK_LTFVALUE, TK_LTFUSR, TK_LTFDAT, TK_LTFTIM, TK_LTFCMD, TK_PRTNO ) values ( ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?)";
	updateSql = "update TK_LTFREC set  PLANT_CODE = ?, NVTIMESTAMP = ?, AREA = ?, PAGE = ?, LINE = ?, TK_LTFVALUE = ?, TK_LTFUSR = ?, TK_LTFDAT = ?, TK_LTFTIM = ?, TK_LTFCMD = ?, TK_PRTNO = ?  where area = ? and page = ? line = ? ";

	qDebug(category) << "insertSQL - insert into TK_LTFREC ( PLANT_CODE, NVTIMESTAMP, AREA, PAGE, LINE, TK_LTFVALUE, TK_LTFUSR, TK_LTFDAT, TK_LTFTIM, TK_LTFCMD, TK_PRTNO ) values ( ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?)";
	qDebug(category) << "fetchSQL - select  DB_ID, NVTIMESTAMP, AREA, PAGE, LINE, TK_LTFVALUE, TK_LTFUSR, TK_LTFDAT, TK_LTFTIM, TK_LTFCMD, TK_PRTNO from TK_LTFREC";
	qDebug(category) << "unsertSQL - update TK_LTFREC set  PLANT_CODE = ?, NVTIMESTAMP = ?, AREA = ?, PAGE = ?, LINE = ?, TK_LTFVALUE = ?, TK_LTFUSR = ?, TK_LTFDAT = ?, TK_LTFTIM = ?, TK_LTFCMD = ?, TK_PRTNO = ?  where area = ? and page = ? line = ? ";

#pragma endregion Sql Statements_TK_LTFREC
	SQLHANDLE		insert_hStmt = SQL_NULL_HANDLE;
	SQLHANDLE		fetch_hStmt = SQL_NULL_HANDLE; 
	SQLHANDLE		update_hStmt = SQL_NULL_HANDLE; 
 
	r = ::SQLAllocHandle(SQL_HANDLE_STMT, hDbc_source, &fetch_hStmt);
	if (r != SQL_SUCCESS) {
		 qCCritical(category) << QString("Error  hDbc_Source SQLCode : %1 is %2").arg(QString::number( (long)hDbc_source)).arg(QString::number(r));
		return; 
	}
	r = ::SQLAllocHandle(SQL_HANDLE_STMT, hDbc_target, &insert_hStmt);
	if (r != SQL_SUCCESS) {
		 qCCritical(category) << QString("Error hDbc_Source -SQLCode: %1 is %2").arg(QString::number( (long)hDbc_target)).arg(QString::number(r));
		return; 
	}
	r = ::SQLAllocHandle(SQL_HANDLE_STMT, hDbc_target, &update_hStmt);
	if (r != SQL_SUCCESS) {
		 qCCritical(category) << QString("Error hDbc_Source +SQLCode: %1 is %2").arg(QString::number( (long)hDbc_target)).arg(QString::number(r));
		return; 
	}
 
	hStmt_Fetch = fetch_hStmt;
	hStmt_Insert = insert_hStmt;
	hStmt_Update = update_hStmt;
 
	SQLSetStmtAttr(hStmt_Fetch, SQL_ATTR_USE_BOOKMARKS, (SQLPOINTER)SQL_UB_OFF, 0);
	SQLSetStmtAttr(hStmt_Fetch, SQL_ATTR_ROW_BIND_TYPE, (SQLPOINTER)SQL_BIND_BY_COLUMN, 0);
	SQLSetStmtAttr(hStmt_Fetch, SQL_ATTR_ROW_ARRAY_SIZE, (SQLPOINTER)1, 0);
	SQLSetStmtAttr(hStmt_Fetch, SQL_ATTR_ROWS_FETCHED_PTR, &numRowsFetched, 0);

// Fields used by this class 
// ---------------------------------------------------

#pragma region Resize Fields TK_LTFREC
	qDebug(category) << "Malloc - DB_ID[2]";
	DB_ID.resize(2);
	qDebug(category) << "Malloc - NVTIMESTAMP[23]";
	NVTIMESTAMP.resize(23);
	qDebug(category) << "Malloc - AREA[2]";
	AREA.resize(2);
	qDebug(category) << "Malloc - PAGE[4]";
	PAGE.resize(4);
	qDebug(category) << "Malloc - LINE[2]";
	LINE.resize(2);
	qDebug(category) << "Malloc - TK_LTFVALUE[4]";
	TK_LTFVALUE.resize(4);
	qDebug(category) << "Malloc - TK_LTFUSR[12]";
	TK_LTFUSR.resize(12);
	qDebug(category) << "Malloc - TK_LTFDAT[4]";
	TK_LTFDAT.resize(4);
	qDebug(category) << "Malloc - TK_LTFTIM[8]";
	TK_LTFTIM.resize(8);
	qDebug(category) << "Malloc - TK_LTFCMD[6]";
	TK_LTFCMD.resize(6);
	qDebug(category) << "Malloc - TK_PRTNO[18]";
	TK_PRTNO.resize(18);

#pragma endregion Resize Fields TK_LTFREC
}
void TK_LTFREC::close()
{
	QLoggingCategory category("classLibQ");
	if (m_bIsOpen)
	{
	qDebug(category) << "database is Open";
		SQLHANDLE source_hStmt = hStmt_Fetch;
		SQLHANDLE insert_hStmt = hStmt_Insert;
		SQLHANDLE hDb_S = this->hDbc_source;
		SQLHANDLE hDb_T = hDbc_target;
		SQLHANDLE hEnvS = hEnv_Source;
		SQLHANDLE hEnvT = hEnv_Target;
		RETCODE r;

		r = ::SQLFreeHandle(SQL_HANDLE_STMT, hStmt_Fetch);
		r = ::SQLFreeHandle(SQL_HANDLE_STMT, hStmt_Insert);
		r = ::SQLFreeHandle(SQL_HANDLE_STMT, hStmt_Update);
		if (hDbc_source != SQL_NULL_HANDLE) 		r = ::SQLDisconnect(hDb_S);
		if (hDbc_target != SQL_NULL_HANDLE) 		r = ::SQLDisconnect(hDb_T);

		r = ::SQLFreeHandle(SQL_HANDLE_DBC, hDb_S);
		r = ::SQLFreeHandle(SQL_HANDLE_DBC, hDb_T);
		r = ::SQLFreeHandle(SQL_HANDLE_ENV, hEnvS);
		r = ::SQLFreeHandle(SQL_HANDLE_ENV, hEnvT);
	}

	hEnv_Source = SQL_NULL_HANDLE;
	hEnv_Target = SQL_NULL_HANDLE;
	hEnv_Source = SQL_NULL_HANDLE;
	hEnv_Target = SQL_NULL_HANDLE;
	hStmt_Fetch = SQL_NULL_HANDLE;
	hStmt_Insert = SQL_NULL_HANDLE;
	hStmt_Update = SQL_NULL_HANDLE;
}

void TK_LTFREC::open(const QString sourceDSN, const QString targetDSN)
{
	QLoggingCategory category("classLibQ");
	m_lpszTargetDSN = targetDSN;
	m_lpszSourceDSN = sourceDSN;
	qDebug(category) << QString("Source - %1[%2]").arg(sourceDSN);
	qDebug(category) << QString("Target - %1[%2]").arg(targetDSN);
}

void TK_LTFREC::createTable()
{
	QLoggingCategory category("classLibQ");
	{
		QScopedPointer<nvTableOracleRdb> tbl(new nvTableOracleRdb(nullptr));
		tbl->initialize("TK_LTFREC", this->m_lpszSourceDSN);
		QString newTbl = tbl->getCreateTableSQL();
		QScopedPointer<qVtExecute> vExec(new qVtExecute(nullptr));
		{
			vExec->initialize(m_lpszTargetDSN, " ", true);
			vExec->setOdbcAttributes(m_OdbcAttributes);
			vExec->ExecuteDirect(newTbl);
		}
	 qDebug(category) << QString("End Create Table %1 ").arg(tableName); 
	}
}

bool TK_LTFREC::prepare()
{
	RETCODE r;
	QString check;
	QLoggingCategory category("classLibQ");
	 qDebug(category) << fetchSql;
	 qDebug(category) << insertSql;
#ifdef UNICODE
	r = SQLPrepare(hStmt_Insert,toSQLTCHAR(insertSql).data(),(SQLINTEGER)insertSql.length()); 
	if (r != SQL_SUCCESS) {
		check = qWarnODBCHandle(SQL_HANDLE_STMT, hStmt_Insert);
		 qCCritical(category) << QString("Prepare Statement-Insert : %1 is %2").arg(insertSql).arg(check);
		return false; 
	}
	r = SQLPrepare(hStmt_Update,toSQLTCHAR(updateSql).data(),(SQLINTEGER)updateSql.length()); 
	if (r != SQL_SUCCESS) {
		check = qWarnODBCHandle(SQL_HANDLE_STMT, hStmt_Update);
		 qCCritical(category) << QString("Prepare Statement-Update : %1 is %2").arg(updateSql).arg(check);
		return false; 
	}
	r = SQLPrepare(hStmt_Fetch,toSQLTCHAR(fetchSql).data(),(SQLINTEGER)fetchSql.length());
	if (r != SQL_SUCCESS) {
		check = qWarnODBCHandle(SQL_HANDLE_STMT, hStmt_Fetch);
		 qCCritical(category) << QString("Prepare Statement-Insert : %1 is %2").arg(fetchSql).arg(check);
		return false; 
	}
#else
	QByteArray queryI8 = insertSql.toUtf8();
	r = SQLPrepare(insert_hStmt,SQLCHAR*)queryI8.data(),(SQLINTEGER)queryI8.length());
	QByteArray queryU8 = fetchSql.toUtf8();
	r = SQLPrepare(hStmt_Fetch,(SQLCHAR*)queryU8.data(),(SQLINTEGER)queryU8.length());
#endif
	return true;

}

void TK_LTFREC::prepareTargetTable()
{
	QLoggingCategory category("classLibQ");
	if (this->m_ReplicationOption == ReplicationOption::BulkCopy)
	{
		QScopedPointer<qVtExecute> execSql(new qVtExecute(nullptr));
		DropOption option = this->m_dropOption;
		switch (option)
		{
			case DropOption::DeleteFromTable:
			{
				QLoggingCategory category("classLibQ");
				execSql->initialize(this->m_lpszTargetDSN, "delete from TK_LTFREC", true);
				execSql->setOdbcAttributes(this->m_OdbcAttributes);
				execSql->ExecuteDirect("delete from TK_LTFREC");
			}break;
			case DropOption::TruncateTable:
			{
				execSql->initialize(this->m_lpszTargetDSN, "truncate table TK_LTFREC", true);
				execSql->setOdbcAttributes(this->m_OdbcAttributes);
				execSql->ExecuteDirect("truncate table TK_LTFREC");
			}break;
			case DropOption::DropTable:
			{
				execSql->initialize(this->m_lpszTargetDSN, "drop table TK_LTFREC", true);
				execSql->setOdbcAttributes(this->m_OdbcAttributes);
				execSql->ExecuteDirect("drop table TK_LTFREC");
				createTable();
			}break;
		}
	}
}

bool TK_LTFREC::bindColumn()
{
	QLoggingCategory category("classLibQ");
	RETCODE r;
	bool isValid=true;
		 qDebug(category) << " Bindings: Ordinal [1] Type: 5 Buffer Size: 2 FieldName: DB_ID ";
		r = ::SQLBindCol(hStmt_Fetch, 1, 5, DB_ID.data(), 2, &cbDB_ID);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Bindings: Ordinal [2] Type: 93 Buffer Size: 23 FieldName: NVTIMESTAMP ";
		r = ::SQLBindCol(hStmt_Fetch, 2, 93, NVTIMESTAMP.data(), 23, &cbNVTIMESTAMP);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Bindings: Ordinal [3] Type: 5 Buffer Size: 2 FieldName: AREA ";
		r = ::SQLBindCol(hStmt_Fetch, 3, 5, AREA.data(), 2, &cbAREA);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Bindings: Ordinal [4] Type: 4 Buffer Size: 4 FieldName: PAGE ";
		r = ::SQLBindCol(hStmt_Fetch, 4, 4, PAGE.data(), 4, &cbPAGE);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Bindings: Ordinal [5] Type: 5 Buffer Size: 2 FieldName: LINE ";
		r = ::SQLBindCol(hStmt_Fetch, 5, 5, LINE.data(), 2, &cbLINE);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Bindings: Ordinal [6] Type: 1 Buffer Size: 4 FieldName: TK_LTFVALUE ";
		r = ::SQLBindCol(hStmt_Fetch, 6, 1, TK_LTFVALUE.data(), 4, &cbTK_LTFVALUE);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Bindings: Ordinal [7] Type: 1 Buffer Size: 12 FieldName: TK_LTFUSR ";
		r = ::SQLBindCol(hStmt_Fetch, 7, 1, TK_LTFUSR.data(), 12, &cbTK_LTFUSR);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Bindings: Ordinal [8] Type: 4 Buffer Size: 4 FieldName: TK_LTFDAT ";
		r = ::SQLBindCol(hStmt_Fetch, 8, 4, TK_LTFDAT.data(), 4, &cbTK_LTFDAT);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Bindings: Ordinal [9] Type: 1 Buffer Size: 8 FieldName: TK_LTFTIM ";
		r = ::SQLBindCol(hStmt_Fetch, 9, 1, TK_LTFTIM.data(), 8, &cbTK_LTFTIM);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Bindings: Ordinal [10] Type: 1 Buffer Size: 6 FieldName: TK_LTFCMD ";
		r = ::SQLBindCol(hStmt_Fetch, 10, 1, TK_LTFCMD.data(), 6, &cbTK_LTFCMD);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Bindings: Ordinal [11] Type: 1 Buffer Size: 18 FieldName: TK_PRTNO ";
		r = ::SQLBindCol(hStmt_Fetch, 11, 1, TK_PRTNO.data(), 18, &cbTK_PRTNO);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
	return isValid;
}

bool TK_LTFREC::bindParameter()
{
	QLoggingCategory category("classLibQ");
	RETCODE r;
	bool isValid=true;
	{
		 qDebug(category) << " Parameters: Ordinal [1] Type: 5 Buffer Size: 2 FieldName: DB_ID ";
		r = SQLBindParameter(hStmt_Insert, 1, SQL_PARAM_INPUT, SQL_C_DEFAULT, 5, 0, 0, (SQLPOINTER)DB_ID.constData(), 0, &cbDB_ID);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Parameters: Ordinal [2] Type: 93 Buffer Size: 23 FieldName: NVTIMESTAMP ";
		r = SQLBindParameter(hStmt_Insert, 2, SQL_PARAM_INPUT, SQL_C_DEFAULT, 93, 23, 0, (SQLPOINTER)NVTIMESTAMP.constData(), 0, &cbNVTIMESTAMP);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Parameters: Ordinal [3] Type: 5 Buffer Size: 2 FieldName: AREA ";
		r = SQLBindParameter(hStmt_Insert, 3, SQL_PARAM_INPUT, SQL_C_DEFAULT, 5, 0, 0, (SQLPOINTER)AREA.constData(), 0, &cbAREA);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Parameters: Ordinal [4] Type: 4 Buffer Size: 4 FieldName: PAGE ";
		r = SQLBindParameter(hStmt_Insert, 4, SQL_PARAM_INPUT, SQL_C_DEFAULT, 4, 0, 0, (SQLPOINTER)PAGE.constData(), 0, &cbPAGE);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Parameters: Ordinal [5] Type: 5 Buffer Size: 2 FieldName: LINE ";
		r = SQLBindParameter(hStmt_Insert, 5, SQL_PARAM_INPUT, SQL_C_DEFAULT, 5, 0, 0, (SQLPOINTER)LINE.constData(), 0, &cbLINE);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Parameters: Ordinal [6] Type: 1 Buffer Size: 4 FieldName: TK_LTFVALUE ";
		r = SQLBindParameter(hStmt_Insert, 6, SQL_PARAM_INPUT, SQL_C_DEFAULT, 1, 4, 0, (SQLPOINTER)TK_LTFVALUE.constData(), 0, &cbTK_LTFVALUE);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Parameters: Ordinal [7] Type: 1 Buffer Size: 12 FieldName: TK_LTFUSR ";
		r = SQLBindParameter(hStmt_Insert, 7, SQL_PARAM_INPUT, SQL_C_DEFAULT, 1, 12, 0, (SQLPOINTER)TK_LTFUSR.constData(), 0, &cbTK_LTFUSR);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Parameters: Ordinal [8] Type: 4 Buffer Size: 4 FieldName: TK_LTFDAT ";
		r = SQLBindParameter(hStmt_Insert, 8, SQL_PARAM_INPUT, SQL_C_DEFAULT, 4, 0, 0, (SQLPOINTER)TK_LTFDAT.constData(), 0, &cbTK_LTFDAT);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Parameters: Ordinal [9] Type: 1 Buffer Size: 8 FieldName: TK_LTFTIM ";
		r = SQLBindParameter(hStmt_Insert, 9, SQL_PARAM_INPUT, SQL_C_DEFAULT, 1, 8, 0, (SQLPOINTER)TK_LTFTIM.constData(), 0, &cbTK_LTFTIM);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Parameters: Ordinal [10] Type: 1 Buffer Size: 6 FieldName: TK_LTFCMD ";
		r = SQLBindParameter(hStmt_Insert, 10, SQL_PARAM_INPUT, SQL_C_DEFAULT, 1, 6, 0, (SQLPOINTER)TK_LTFCMD.constData(), 0, &cbTK_LTFCMD);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Parameters: Ordinal [11] Type: 1 Buffer Size: 18 FieldName: TK_PRTNO ";
		r = SQLBindParameter(hStmt_Insert, 11, SQL_PARAM_INPUT, SQL_C_DEFAULT, 1, 18, 0, (SQLPOINTER)TK_PRTNO.constData(), 0, &cbTK_PRTNO);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
	}
	if (m_ReplicationOption == ReplicationOption::NetChange)
	{
		r = SQLBindParameter(hStmt_Update, 12, SQL_PARAM_INPUT, SQL_C_DEFAULT, 3, 0, 0, (SQLPOINTER)AREA.constData(), 0, &cbAREA);
		if (r == SQL_SUCCESS) { isValid=true; }
		r = SQLBindParameter(hStmt_Update, 13, SQL_PARAM_INPUT, SQL_C_DEFAULT, 4, 0, 0, (SQLPOINTER)PAGE.constData(), 0, &cbPAGE);
		if (r == SQL_SUCCESS) { isValid=true; }
		r = SQLBindParameter(hStmt_Update, 14, SQL_PARAM_INPUT, SQL_C_DEFAULT, 5, 0, 0, (SQLPOINTER)LINE.constData(), 0, &cbLINE);
		if (r == SQL_SUCCESS) { isValid=true; }
	// TK_LTFREC is a well formed table for eNVy Replication 
		 qDebug(category) << " Parameters: Ordinal [3] 00 00 FieldName: AREA ";
		 qDebug(category) << " Parameters: Ordinal [4] 00 00  FieldName: PAGE ";
		 qDebug(category) << " Parameters: Ordinal [5] 00 00 FieldName:  LINE ";
	} // 	if (m_ReplicationOption == ReplicationOption::NetChange)
	return isValid;
}

bool TK_LTFREC::process(int rowSize)
{
	QLoggingCategory category("classLibQ");
	initOdbcAttributes();
	connect(Source);
	connect(Target);
	initialize();
	prepareTargetTable();
	prepare();
	bindColumn();
	bindParameter();
	copyTable();
	close();
	return false;
}

void TK_LTFREC::copyTable()
{
	QLoggingCategory category("classLibQ");
	RETCODE r;
	QString check;
	r = SQLExecute(hStmt_Fetch);
		if (bIsAbort) {
			emit aborted(tableName, rowsFetched, rowsInserted, rowsUpdated);
			return;
		}
		while((r = SQLFetch(hStmt_Fetch)) != SQL_NO_DATA) {
		if (r != SQL_SUCCESS) {
			check = qWarnODBCHandle(SQL_HANDLE_STMT, hStmt_Fetch);
			qCCritical(category) << QString("SqlFetch - Error : %1 is %2").arg(fetchSql).arg(check);
			return;
		} 
		rowsFetched++;
		if (m_ReplicationOption == ReplicationOption::BulkCopy)
		{
			r = SQLExecute(hStmt_Insert);
			if (r == SQL_ERROR) {
				check = qWarnODBCHandle(SQL_HANDLE_STMT, hStmt_Insert);
				 qCCritical(category) << QString("SqlExecute:Insert - Error : %1 is %2").arg(insertSql).arg(check);
				return;
			}
			rowsInserted++;
			if ((rowsFetched % updateInterval) == 0) {
				qCInfo(category) << QString("[%1.%2]	Insertion: %3	Updates : %4	Fetched : %5").arg(profileName).arg(tableName).arg(rowsInserted).arg(rowsUpdated).arg(rowsFetched);
				emit updateStatusFetched(profileName, tableName, rowsFetched,rowsInserted,rowsUpdated);
			}
			if (m_ReplicationOption == ReplicationOption::NetChange)
			{
			r = SQLExecute(hStmt_Update);
			if (r != SQL_SUCCESS) {
				check = qWarnODBCHandle(SQL_HANDLE_STMT, hStmt_Update);
				 qCInfo(category)  << QString("SqlExecute:Update - Error : %1 is %2").arg(updateSql).arg(check);
				r = SQLExecute(hStmt_Insert);
				if (r != SQL_SUCCESS) {
					check = qWarnODBCHandle(SQL_HANDLE_STMT, hStmt_Insert);
					 qCritical(category) << QString("SqlExecute:Insert - Error : %1 is %2").arg(insertSql).arg(check);
					return;
				}
				else 	rowsInserted++;
				}
				else	rowsUpdated++;
			}
			emit updateStatusFetched(profileName, tableName, rowsFetched,rowsInserted,rowsUpdated);
		}
	} 
qCInfo(category) << QString("[%1.%2]	Insertion: %3	Updates : %4	Fetched : %5").arg(profileName).arg(tableName).arg(rowsInserted).arg(rowsUpdated).arg(rowsFetched);
}

void TK_LTFREC::connect(connectionHandle connectionSource)
{

	QLoggingCategory category("classLibQ");
	RETCODE r;

	bool isValid = false;
	HWND	hWnd = nullptr;
	hWnd = ::GetDesktopWindow(); 
	SQLSMALLINT nResult = 0;

	SQLSMALLINT cb;
	UWORD wConnectOption = SQL_DRIVER_COMPLETE; //SQL_DRIVER_NOPROMPT;
	QVarLengthArray<SQLTCHAR> connOut(1024);
	memset(connOut.data(), 0, connOut.size() * sizeof(SQLTCHAR));

	switch (connectionSource)
	{
		case Source:
			{// environment
				SQLHANDLE hEnv = SQL_NULL_HANDLE;
				SQLHANDLE hDbc = SQL_NULL_HANDLE;
				r = ::SQLAllocHandle(SQL_HANDLE_ENV, SQL_NULL_HANDLE, &hEnv);
				if (r == SQL_SUCCESS) isValid = true;

				foreach(nOdbcAttributesClass * k, this->m_OdbcAttributes_Map)
				{
					if (k->attributeType == enumAttributeType::hEnv)
					{
						r = ::SQLSetEnvAttr(hEnv, (SQLINTEGER) k->odbcKey, (SQLPOINTER)k->odbcValue, 0);
						if (r == SQL_SUCCESS) isValid = true;
					}
				}
				hEnv_Source = hEnv;

				r = SQLAllocHandle(SQL_HANDLE_DBC, hEnv, &hDbc);
				if (r == SQL_SUCCESS) isValid = true;
				foreach(nOdbcAttributesClass * k, this->m_OdbcAttributes_Map)
				{
					if (k->attributeType == enumAttributeType::hDbc)
					{
					r = ::SQLSetConnectAttr(hDbc, k->odbcKey, (SQLPOINTER)k->odbcValue, 0);
					if (k->odbcKey == SQL_ATTR_CONNECTION_POOLING && k->odbcValue == SQL_CP_ONE_PER_DRIVER) wConnectOption = SQL_DRIVER_NOPROMPT;
					if (k->odbcKey == SQL_ATTR_CONNECTION_POOLING && k->odbcValue == SQL_CP_ONE_PER_HENV) wConnectOption = SQL_DRIVER_NOPROMPT;
					if (k->odbcKey == SQL_ATTR_CONNECTION_POOLING && k->odbcValue == SQL_CP_DRIVER_AWARE) wConnectOption = SQL_DRIVER_NOPROMPT;
					if (r == SQL_SUCCESS) isValid = true;
					}
				}
				hDbc_source = hDbc;
				if (isValid)
				{
					r = ::SQLDriverConnect(
						hDbc,
						hWnd,
#ifdef UNICODE
						toSQLTCHAR(m_lpszSourceDSN).data(),
#else
						(SQLCHAR*)dsnSource.toUtf8().data(),
#endif
						(SQLSMALLINT)m_lpszSourceDSN.length(),
						connOut.data(),
						1024,
						&cb, 
						wConnectOption); 
					int colSize = cb / sizeof(SQLTCHAR);
					if (r != SQL_SUCCESS && r != SQL_SUCCESS_WITH_INFO)
					{
						QString check = qWarnODBCHandle(SQL_HANDLE_DBC, hDbc);
						qCritical(category) <<  check;
						m_bIsOpen = false;
					}
					m_bIsOpen = true;
				}
			} break;
		case Target:
			{
				SQLHANDLE hEnv = SQL_NULL_HANDLE;
				SQLHANDLE hDbc = SQL_NULL_HANDLE;
				r = ::SQLAllocHandle(SQL_HANDLE_ENV, SQL_NULL_HANDLE, &hEnv);
				if (r == SQL_SUCCESS) isValid = true;

				foreach(nOdbcAttributesClass * k, this->m_OdbcAttributes_Map)
				{
					if (k->attributeType == enumAttributeType::hEnv)
					{
						r = ::SQLSetEnvAttr(hEnv, (SQLINTEGER) k->odbcKey, (SQLPOINTER)k->odbcValue, 0);
						if (r == SQL_SUCCESS) isValid = true;
					}
				}
				hEnv_Target = hEnv;

				r = SQLAllocHandle(SQL_HANDLE_DBC, hEnv, &hDbc);
				if (r == SQL_SUCCESS) isValid = true;
				foreach(nOdbcAttributesClass * k, this->m_OdbcAttributes_Map)
				{
				if (k->attributeType == enumAttributeType::hDbc)
					{
					r = ::SQLSetConnectAttr(hDbc, k->odbcKey, (SQLPOINTER)k->odbcValue, 0);
					if (k->odbcKey == SQL_ATTR_CONNECTION_POOLING && k->odbcValue == SQL_CP_ONE_PER_DRIVER) wConnectOption = SQL_DRIVER_NOPROMPT;
					if (k->odbcKey == SQL_ATTR_CONNECTION_POOLING && k->odbcValue == SQL_CP_ONE_PER_HENV) wConnectOption = SQL_DRIVER_NOPROMPT;
					if (k->odbcKey == SQL_ATTR_CONNECTION_POOLING && k->odbcValue == SQL_CP_DRIVER_AWARE) wConnectOption = SQL_DRIVER_NOPROMPT;
					if (r == SQL_SUCCESS) isValid = true;
					}
				}
				hDbc_target = hDbc;
				if (isValid) {
					r = ::SQLDriverConnect(
						hDbc,
						hWnd,
#ifdef UNICODE
						toSQLTCHAR(m_lpszTargetDSN).data(),
#else
						(SQLCHAR*)m_lpszTargetDSN.toUtf8().data(),
#endif
						(SQLSMALLINT)m_lpszTargetDSN.length(),
						connOut.data(),
						1024,
						&cb, 
						wConnectOption); 
						int colSize = cb / sizeof(SQLTCHAR);
					if (r != SQL_SUCCESS && r != SQL_SUCCESS_WITH_INFO)
						{
							QString check = qWarnODBCHandle(SQL_HANDLE_DBC, hDbc);
							qCritical(category) <<  check;
							m_bIsOpen = false;
						}
							m_bIsOpen = true;
					}
			} break;
			default: break;
	}
}
TK_PRCHSHSET::TK_PRCHSHSET(QObject * parent) : QObject(parent) 
,tableName("TK_PRCHSHSET")
,m_dropOption(DropOption::DropTable) { 
	numRowsFetched = 0;
}

#pragma region ~CTOR TK_PRCHSHSET 
TK_PRCHSHSET::~TK_PRCHSHSET() { 

#pragma region Buffers - Clear 
	DB_ID.clear();
	NVTIMESTAMP.clear();
	OAREA.clear();
	OPAGE.clear();
	OLINE.clear();
	MAREA.clear();
	MPAGE.clear();
	MLINE.clear();
#pragma endregion Buffers - Clear 
}
#pragma endregion Destructor_TK_PRCHSHSET

// begin method functions
void TK_PRCHSHSET::setAbortFlag() { 
	QLoggingCategory category("classLibQ");
	qCInfo(category) << "isAbort was set to True";
	bIsAbort = true;
}

void TK_PRCHSHSET::run() { 
	process(1);
	QLoggingCategory category("classLibQ");
	qDebug(category) << "Entered;";
}

void	TK_PRCHSHSET::initOdbcAttributes()
{
	QLoggingCategory category("classLibQ");
	this->setProfileName(profileName);
	qDebug(category) << "Processing - TRKDB100"; 
	m_OdbcAttributesList = m_OdbcAttributes.split(","); 
	foreach(QString m, m_OdbcAttributesList)
	{
		QStringList keyValue = m.split("=");
		nOdbcAttributesClass * oM = new nOdbcAttributesClass(this);
		if (oM->loadToOdbc(keyValue.value(0), keyValue.value(1)))
		{
			m_OdbcAttributes_Map.insert(oM->odbcKey, oM);
		}
	}
}
void	TK_PRCHSHSET::initialize()
{
	QLoggingCategory category("classLibQ");
	RETCODE r;
	this->setProfileName(profileName);
	qDebug(category) << "Processing - TRKDB100"; 
//SQL Statements
//--------------------------------------------------

#pragma region Sql Statements_TK_PRCHSHSET

	fetchSql = "select  DB_ID, NVTIMESTAMP, OAREA, OPAGE, OLINE, MAREA, MPAGE, MLINE from TK_PRCHSHSET";
		if (m_ReplicationOption == ReplicationOption::NetChange)
		{
			fetchSql.append(" p1, nv_transfers p2 WHERE  p2.table_name = 'TK_PRCHSHSET' AND p1.nvtimestamp > p2.last_completed");
		}
	insertSql = "insert into TK_PRCHSHSET ( PLANT_CODE, NVTIMESTAMP, OAREA, OPAGE, OLINE, MAREA, MPAGE, MLINE ) values ( ?, ?, ?, ?, ?, ?, ?, ?)";
	updateSql = "update TK_PRCHSHSET set  PLANT_CODE = ?, NVTIMESTAMP = ?, OAREA = ?, OPAGE = ?, OLINE = ?, MAREA = ?, MPAGE = ?, MLINE = ?  where area = ? and page = ? line = ? ";

	qDebug(category) << "insertSQL - insert into TK_PRCHSHSET ( PLANT_CODE, NVTIMESTAMP, OAREA, OPAGE, OLINE, MAREA, MPAGE, MLINE ) values ( ?, ?, ?, ?, ?, ?, ?, ?)";
	qDebug(category) << "fetchSQL - select  DB_ID, NVTIMESTAMP, OAREA, OPAGE, OLINE, MAREA, MPAGE, MLINE from TK_PRCHSHSET";
	qDebug(category) << "unsertSQL - update TK_PRCHSHSET set  PLANT_CODE = ?, NVTIMESTAMP = ?, OAREA = ?, OPAGE = ?, OLINE = ?, MAREA = ?, MPAGE = ?, MLINE = ?  where area = ? and page = ? line = ? ";

#pragma endregion Sql Statements_TK_PRCHSHSET
	SQLHANDLE		insert_hStmt = SQL_NULL_HANDLE;
	SQLHANDLE		fetch_hStmt = SQL_NULL_HANDLE; 
	SQLHANDLE		update_hStmt = SQL_NULL_HANDLE; 
 
	r = ::SQLAllocHandle(SQL_HANDLE_STMT, hDbc_source, &fetch_hStmt);
	if (r != SQL_SUCCESS) {
		 qCCritical(category) << QString("Error  hDbc_Source SQLCode : %1 is %2").arg(QString::number( (long)hDbc_source)).arg(QString::number(r));
		return; 
	}
	r = ::SQLAllocHandle(SQL_HANDLE_STMT, hDbc_target, &insert_hStmt);
	if (r != SQL_SUCCESS) {
		 qCCritical(category) << QString("Error hDbc_Source -SQLCode: %1 is %2").arg(QString::number( (long)hDbc_target)).arg(QString::number(r));
		return; 
	}
	r = ::SQLAllocHandle(SQL_HANDLE_STMT, hDbc_target, &update_hStmt);
	if (r != SQL_SUCCESS) {
		 qCCritical(category) << QString("Error hDbc_Source +SQLCode: %1 is %2").arg(QString::number( (long)hDbc_target)).arg(QString::number(r));
		return; 
	}
 
	hStmt_Fetch = fetch_hStmt;
	hStmt_Insert = insert_hStmt;
	hStmt_Update = update_hStmt;
 
	SQLSetStmtAttr(hStmt_Fetch, SQL_ATTR_USE_BOOKMARKS, (SQLPOINTER)SQL_UB_OFF, 0);
	SQLSetStmtAttr(hStmt_Fetch, SQL_ATTR_ROW_BIND_TYPE, (SQLPOINTER)SQL_BIND_BY_COLUMN, 0);
	SQLSetStmtAttr(hStmt_Fetch, SQL_ATTR_ROW_ARRAY_SIZE, (SQLPOINTER)1, 0);
	SQLSetStmtAttr(hStmt_Fetch, SQL_ATTR_ROWS_FETCHED_PTR, &numRowsFetched, 0);

// Fields used by this class 
// ---------------------------------------------------

#pragma region Resize Fields TK_PRCHSHSET
	qDebug(category) << "Malloc - DB_ID[2]";
	DB_ID.resize(2);
	qDebug(category) << "Malloc - NVTIMESTAMP[23]";
	NVTIMESTAMP.resize(23);
	qDebug(category) << "Malloc - OAREA[2]";
	OAREA.resize(2);
	qDebug(category) << "Malloc - OPAGE[4]";
	OPAGE.resize(4);
	qDebug(category) << "Malloc - OLINE[2]";
	OLINE.resize(2);
	qDebug(category) << "Malloc - MAREA[2]";
	MAREA.resize(2);
	qDebug(category) << "Malloc - MPAGE[4]";
	MPAGE.resize(4);
	qDebug(category) << "Malloc - MLINE[2]";
	MLINE.resize(2);

#pragma endregion Resize Fields TK_PRCHSHSET
}
void TK_PRCHSHSET::close()
{
	QLoggingCategory category("classLibQ");
	if (m_bIsOpen)
	{
	qDebug(category) << "database is Open";
		SQLHANDLE source_hStmt = hStmt_Fetch;
		SQLHANDLE insert_hStmt = hStmt_Insert;
		SQLHANDLE hDb_S = this->hDbc_source;
		SQLHANDLE hDb_T = hDbc_target;
		SQLHANDLE hEnvS = hEnv_Source;
		SQLHANDLE hEnvT = hEnv_Target;
		RETCODE r;

		r = ::SQLFreeHandle(SQL_HANDLE_STMT, hStmt_Fetch);
		r = ::SQLFreeHandle(SQL_HANDLE_STMT, hStmt_Insert);
		r = ::SQLFreeHandle(SQL_HANDLE_STMT, hStmt_Update);
		if (hDbc_source != SQL_NULL_HANDLE) 		r = ::SQLDisconnect(hDb_S);
		if (hDbc_target != SQL_NULL_HANDLE) 		r = ::SQLDisconnect(hDb_T);

		r = ::SQLFreeHandle(SQL_HANDLE_DBC, hDb_S);
		r = ::SQLFreeHandle(SQL_HANDLE_DBC, hDb_T);
		r = ::SQLFreeHandle(SQL_HANDLE_ENV, hEnvS);
		r = ::SQLFreeHandle(SQL_HANDLE_ENV, hEnvT);
	}

	hEnv_Source = SQL_NULL_HANDLE;
	hEnv_Target = SQL_NULL_HANDLE;
	hEnv_Source = SQL_NULL_HANDLE;
	hEnv_Target = SQL_NULL_HANDLE;
	hStmt_Fetch = SQL_NULL_HANDLE;
	hStmt_Insert = SQL_NULL_HANDLE;
	hStmt_Update = SQL_NULL_HANDLE;
}

void TK_PRCHSHSET::open(const QString sourceDSN, const QString targetDSN)
{
	QLoggingCategory category("classLibQ");
	m_lpszTargetDSN = targetDSN;
	m_lpszSourceDSN = sourceDSN;
	qDebug(category) << QString("Source - %1[%2]").arg(sourceDSN);
	qDebug(category) << QString("Target - %1[%2]").arg(targetDSN);
}

void TK_PRCHSHSET::createTable()
{
	QLoggingCategory category("classLibQ");
	{
		QScopedPointer<nvTableOracleRdb> tbl(new nvTableOracleRdb(nullptr));
		tbl->initialize("TK_PRCHSHSET", this->m_lpszSourceDSN);
		QString newTbl = tbl->getCreateTableSQL();
		QScopedPointer<qVtExecute> vExec(new qVtExecute(nullptr));
		{
			vExec->initialize(m_lpszTargetDSN, " ", true);
			vExec->setOdbcAttributes(m_OdbcAttributes);
			vExec->ExecuteDirect(newTbl);
		}
	 qDebug(category) << QString("End Create Table %1 ").arg(tableName); 
	}
}

bool TK_PRCHSHSET::prepare()
{
	RETCODE r;
	QString check;
	QLoggingCategory category("classLibQ");
	 qDebug(category) << fetchSql;
	 qDebug(category) << insertSql;
#ifdef UNICODE
	r = SQLPrepare(hStmt_Insert,toSQLTCHAR(insertSql).data(),(SQLINTEGER)insertSql.length()); 
	if (r != SQL_SUCCESS) {
		check = qWarnODBCHandle(SQL_HANDLE_STMT, hStmt_Insert);
		 qCCritical(category) << QString("Prepare Statement-Insert : %1 is %2").arg(insertSql).arg(check);
		return false; 
	}
	r = SQLPrepare(hStmt_Update,toSQLTCHAR(updateSql).data(),(SQLINTEGER)updateSql.length()); 
	if (r != SQL_SUCCESS) {
		check = qWarnODBCHandle(SQL_HANDLE_STMT, hStmt_Update);
		 qCCritical(category) << QString("Prepare Statement-Update : %1 is %2").arg(updateSql).arg(check);
		return false; 
	}
	r = SQLPrepare(hStmt_Fetch,toSQLTCHAR(fetchSql).data(),(SQLINTEGER)fetchSql.length());
	if (r != SQL_SUCCESS) {
		check = qWarnODBCHandle(SQL_HANDLE_STMT, hStmt_Fetch);
		 qCCritical(category) << QString("Prepare Statement-Insert : %1 is %2").arg(fetchSql).arg(check);
		return false; 
	}
#else
	QByteArray queryI8 = insertSql.toUtf8();
	r = SQLPrepare(insert_hStmt,SQLCHAR*)queryI8.data(),(SQLINTEGER)queryI8.length());
	QByteArray queryU8 = fetchSql.toUtf8();
	r = SQLPrepare(hStmt_Fetch,(SQLCHAR*)queryU8.data(),(SQLINTEGER)queryU8.length());
#endif
	return true;

}

void TK_PRCHSHSET::prepareTargetTable()
{
	QLoggingCategory category("classLibQ");
	if (this->m_ReplicationOption == ReplicationOption::BulkCopy)
	{
		QScopedPointer<qVtExecute> execSql(new qVtExecute(nullptr));
		DropOption option = this->m_dropOption;
		switch (option)
		{
			case DropOption::DeleteFromTable:
			{
				QLoggingCategory category("classLibQ");
				execSql->initialize(this->m_lpszTargetDSN, "delete from TK_PRCHSHSET", true);
				execSql->setOdbcAttributes(this->m_OdbcAttributes);
				execSql->ExecuteDirect("delete from TK_PRCHSHSET");
			}break;
			case DropOption::TruncateTable:
			{
				execSql->initialize(this->m_lpszTargetDSN, "truncate table TK_PRCHSHSET", true);
				execSql->setOdbcAttributes(this->m_OdbcAttributes);
				execSql->ExecuteDirect("truncate table TK_PRCHSHSET");
			}break;
			case DropOption::DropTable:
			{
				execSql->initialize(this->m_lpszTargetDSN, "drop table TK_PRCHSHSET", true);
				execSql->setOdbcAttributes(this->m_OdbcAttributes);
				execSql->ExecuteDirect("drop table TK_PRCHSHSET");
				createTable();
			}break;
		}
	}
}

bool TK_PRCHSHSET::bindColumn()
{
	QLoggingCategory category("classLibQ");
	RETCODE r;
	bool isValid=true;
		 qDebug(category) << " Bindings: Ordinal [1] Type: 5 Buffer Size: 2 FieldName: DB_ID ";
		r = ::SQLBindCol(hStmt_Fetch, 1, 5, DB_ID.data(), 2, &cbDB_ID);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Bindings: Ordinal [2] Type: 93 Buffer Size: 23 FieldName: NVTIMESTAMP ";
		r = ::SQLBindCol(hStmt_Fetch, 2, 93, NVTIMESTAMP.data(), 23, &cbNVTIMESTAMP);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Bindings: Ordinal [3] Type: 5 Buffer Size: 2 FieldName: OAREA ";
		r = ::SQLBindCol(hStmt_Fetch, 3, 5, OAREA.data(), 2, &cbOAREA);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Bindings: Ordinal [4] Type: 4 Buffer Size: 4 FieldName: OPAGE ";
		r = ::SQLBindCol(hStmt_Fetch, 4, 4, OPAGE.data(), 4, &cbOPAGE);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Bindings: Ordinal [5] Type: 5 Buffer Size: 2 FieldName: OLINE ";
		r = ::SQLBindCol(hStmt_Fetch, 5, 5, OLINE.data(), 2, &cbOLINE);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Bindings: Ordinal [6] Type: 5 Buffer Size: 2 FieldName: MAREA ";
		r = ::SQLBindCol(hStmt_Fetch, 6, 5, MAREA.data(), 2, &cbMAREA);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Bindings: Ordinal [7] Type: 4 Buffer Size: 4 FieldName: MPAGE ";
		r = ::SQLBindCol(hStmt_Fetch, 7, 4, MPAGE.data(), 4, &cbMPAGE);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Bindings: Ordinal [8] Type: 5 Buffer Size: 2 FieldName: MLINE ";
		r = ::SQLBindCol(hStmt_Fetch, 8, 5, MLINE.data(), 2, &cbMLINE);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
	return isValid;
}

bool TK_PRCHSHSET::bindParameter()
{
	QLoggingCategory category("classLibQ");
	RETCODE r;
	bool isValid=true;
	{
		 qDebug(category) << " Parameters: Ordinal [1] Type: 5 Buffer Size: 2 FieldName: DB_ID ";
		r = SQLBindParameter(hStmt_Insert, 1, SQL_PARAM_INPUT, SQL_C_DEFAULT, 5, 0, 0, (SQLPOINTER)DB_ID.constData(), 0, &cbDB_ID);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Parameters: Ordinal [2] Type: 93 Buffer Size: 23 FieldName: NVTIMESTAMP ";
		r = SQLBindParameter(hStmt_Insert, 2, SQL_PARAM_INPUT, SQL_C_DEFAULT, 93, 23, 0, (SQLPOINTER)NVTIMESTAMP.constData(), 0, &cbNVTIMESTAMP);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Parameters: Ordinal [3] Type: 5 Buffer Size: 2 FieldName: OAREA ";
		r = SQLBindParameter(hStmt_Insert, 3, SQL_PARAM_INPUT, SQL_C_DEFAULT, 5, 0, 0, (SQLPOINTER)OAREA.constData(), 0, &cbOAREA);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Parameters: Ordinal [4] Type: 4 Buffer Size: 4 FieldName: OPAGE ";
		r = SQLBindParameter(hStmt_Insert, 4, SQL_PARAM_INPUT, SQL_C_DEFAULT, 4, 0, 0, (SQLPOINTER)OPAGE.constData(), 0, &cbOPAGE);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Parameters: Ordinal [5] Type: 5 Buffer Size: 2 FieldName: OLINE ";
		r = SQLBindParameter(hStmt_Insert, 5, SQL_PARAM_INPUT, SQL_C_DEFAULT, 5, 0, 0, (SQLPOINTER)OLINE.constData(), 0, &cbOLINE);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Parameters: Ordinal [6] Type: 5 Buffer Size: 2 FieldName: MAREA ";
		r = SQLBindParameter(hStmt_Insert, 6, SQL_PARAM_INPUT, SQL_C_DEFAULT, 5, 0, 0, (SQLPOINTER)MAREA.constData(), 0, &cbMAREA);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Parameters: Ordinal [7] Type: 4 Buffer Size: 4 FieldName: MPAGE ";
		r = SQLBindParameter(hStmt_Insert, 7, SQL_PARAM_INPUT, SQL_C_DEFAULT, 4, 0, 0, (SQLPOINTER)MPAGE.constData(), 0, &cbMPAGE);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Parameters: Ordinal [8] Type: 5 Buffer Size: 2 FieldName: MLINE ";
		r = SQLBindParameter(hStmt_Insert, 8, SQL_PARAM_INPUT, SQL_C_DEFAULT, 5, 0, 0, (SQLPOINTER)MLINE.constData(), 0, &cbMLINE);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
	}
	if (m_ReplicationOption == ReplicationOption::NetChange)
	{
		r = SQLBindParameter(hStmt_Update, 9, SQL_PARAM_INPUT, SQL_C_DEFAULT, 6, 0, 0, (SQLPOINTER)MAREA.constData(), 0, &cbMAREA);
		if (r == SQL_SUCCESS) { isValid=true; }
		r = SQLBindParameter(hStmt_Update, 10, SQL_PARAM_INPUT, SQL_C_DEFAULT, 7, 0, 0, (SQLPOINTER)MPAGE.constData(), 0, &cbMPAGE);
		if (r == SQL_SUCCESS) { isValid=true; }
		r = SQLBindParameter(hStmt_Update, 11, SQL_PARAM_INPUT, SQL_C_DEFAULT, 8, 0, 0, (SQLPOINTER)MLINE.constData(), 0, &cbMLINE);
		if (r == SQL_SUCCESS) { isValid=true; }
	// TK_PRCHSHSET is a well formed table for eNVy Replication 
		 qDebug(category) << " Parameters: Ordinal [6] 00 00 FieldName: MAREA ";
		 qDebug(category) << " Parameters: Ordinal [7] 00 00  FieldName: MPAGE ";
		 qDebug(category) << " Parameters: Ordinal [8] 00 00 FieldName:  MLINE ";
	} // 	if (m_ReplicationOption == ReplicationOption::NetChange)
	return isValid;
}

bool TK_PRCHSHSET::process(int rowSize)
{
	QLoggingCategory category("classLibQ");
	initOdbcAttributes();
	connect(Source);
	connect(Target);
	initialize();
	prepareTargetTable();
	prepare();
	bindColumn();
	bindParameter();
	copyTable();
	close();
	return false;
}

void TK_PRCHSHSET::copyTable()
{
	QLoggingCategory category("classLibQ");
	RETCODE r;
	QString check;
	r = SQLExecute(hStmt_Fetch);
		if (bIsAbort) {
			emit aborted(tableName, rowsFetched, rowsInserted, rowsUpdated);
			return;
		}
		while((r = SQLFetch(hStmt_Fetch)) != SQL_NO_DATA) {
		if (r != SQL_SUCCESS) {
			check = qWarnODBCHandle(SQL_HANDLE_STMT, hStmt_Fetch);
			qCCritical(category) << QString("SqlFetch - Error : %1 is %2").arg(fetchSql).arg(check);
			return;
		} 
		rowsFetched++;
		if (m_ReplicationOption == ReplicationOption::BulkCopy)
		{
			r = SQLExecute(hStmt_Insert);
			if (r == SQL_ERROR) {
				check = qWarnODBCHandle(SQL_HANDLE_STMT, hStmt_Insert);
				 qCCritical(category) << QString("SqlExecute:Insert - Error : %1 is %2").arg(insertSql).arg(check);
				return;
			}
			rowsInserted++;
			if ((rowsFetched % updateInterval) == 0) {
				qCInfo(category) << QString("[%1.%2]	Insertion: %3	Updates : %4	Fetched : %5").arg(profileName).arg(tableName).arg(rowsInserted).arg(rowsUpdated).arg(rowsFetched);
				emit updateStatusFetched(profileName, tableName, rowsFetched,rowsInserted,rowsUpdated);
			}
			if (m_ReplicationOption == ReplicationOption::NetChange)
			{
			r = SQLExecute(hStmt_Update);
			if (r != SQL_SUCCESS) {
				check = qWarnODBCHandle(SQL_HANDLE_STMT, hStmt_Update);
				 qCInfo(category)  << QString("SqlExecute:Update - Error : %1 is %2").arg(updateSql).arg(check);
				r = SQLExecute(hStmt_Insert);
				if (r != SQL_SUCCESS) {
					check = qWarnODBCHandle(SQL_HANDLE_STMT, hStmt_Insert);
					 qCritical(category) << QString("SqlExecute:Insert - Error : %1 is %2").arg(insertSql).arg(check);
					return;
				}
				else 	rowsInserted++;
				}
				else	rowsUpdated++;
			}
			emit updateStatusFetched(profileName, tableName, rowsFetched,rowsInserted,rowsUpdated);
		}
	} 
qCInfo(category) << QString("[%1.%2]	Insertion: %3	Updates : %4	Fetched : %5").arg(profileName).arg(tableName).arg(rowsInserted).arg(rowsUpdated).arg(rowsFetched);
}

void TK_PRCHSHSET::connect(connectionHandle connectionSource)
{

	QLoggingCategory category("classLibQ");
	RETCODE r;

	bool isValid = false;
	HWND	hWnd = nullptr;
	hWnd = ::GetDesktopWindow(); 
	SQLSMALLINT nResult = 0;

	SQLSMALLINT cb;
	UWORD wConnectOption = SQL_DRIVER_COMPLETE; //SQL_DRIVER_NOPROMPT;
	QVarLengthArray<SQLTCHAR> connOut(1024);
	memset(connOut.data(), 0, connOut.size() * sizeof(SQLTCHAR));

	switch (connectionSource)
	{
		case Source:
			{// environment
				SQLHANDLE hEnv = SQL_NULL_HANDLE;
				SQLHANDLE hDbc = SQL_NULL_HANDLE;
				r = ::SQLAllocHandle(SQL_HANDLE_ENV, SQL_NULL_HANDLE, &hEnv);
				if (r == SQL_SUCCESS) isValid = true;

				foreach(nOdbcAttributesClass * k, this->m_OdbcAttributes_Map)
				{
					if (k->attributeType == enumAttributeType::hEnv)
					{
						r = ::SQLSetEnvAttr(hEnv, (SQLINTEGER) k->odbcKey, (SQLPOINTER)k->odbcValue, 0);
						if (r == SQL_SUCCESS) isValid = true;
					}
				}
				hEnv_Source = hEnv;

				r = SQLAllocHandle(SQL_HANDLE_DBC, hEnv, &hDbc);
				if (r == SQL_SUCCESS) isValid = true;
				foreach(nOdbcAttributesClass * k, this->m_OdbcAttributes_Map)
				{
					if (k->attributeType == enumAttributeType::hDbc)
					{
					r = ::SQLSetConnectAttr(hDbc, k->odbcKey, (SQLPOINTER)k->odbcValue, 0);
					if (k->odbcKey == SQL_ATTR_CONNECTION_POOLING && k->odbcValue == SQL_CP_ONE_PER_DRIVER) wConnectOption = SQL_DRIVER_NOPROMPT;
					if (k->odbcKey == SQL_ATTR_CONNECTION_POOLING && k->odbcValue == SQL_CP_ONE_PER_HENV) wConnectOption = SQL_DRIVER_NOPROMPT;
					if (k->odbcKey == SQL_ATTR_CONNECTION_POOLING && k->odbcValue == SQL_CP_DRIVER_AWARE) wConnectOption = SQL_DRIVER_NOPROMPT;
					if (r == SQL_SUCCESS) isValid = true;
					}
				}
				hDbc_source = hDbc;
				if (isValid)
				{
					r = ::SQLDriverConnect(
						hDbc,
						hWnd,
#ifdef UNICODE
						toSQLTCHAR(m_lpszSourceDSN).data(),
#else
						(SQLCHAR*)dsnSource.toUtf8().data(),
#endif
						(SQLSMALLINT)m_lpszSourceDSN.length(),
						connOut.data(),
						1024,
						&cb, 
						wConnectOption); 
					int colSize = cb / sizeof(SQLTCHAR);
					if (r != SQL_SUCCESS && r != SQL_SUCCESS_WITH_INFO)
					{
						QString check = qWarnODBCHandle(SQL_HANDLE_DBC, hDbc);
						qCritical(category) <<  check;
						m_bIsOpen = false;
					}
					m_bIsOpen = true;
				}
			} break;
		case Target:
			{
				SQLHANDLE hEnv = SQL_NULL_HANDLE;
				SQLHANDLE hDbc = SQL_NULL_HANDLE;
				r = ::SQLAllocHandle(SQL_HANDLE_ENV, SQL_NULL_HANDLE, &hEnv);
				if (r == SQL_SUCCESS) isValid = true;

				foreach(nOdbcAttributesClass * k, this->m_OdbcAttributes_Map)
				{
					if (k->attributeType == enumAttributeType::hEnv)
					{
						r = ::SQLSetEnvAttr(hEnv, (SQLINTEGER) k->odbcKey, (SQLPOINTER)k->odbcValue, 0);
						if (r == SQL_SUCCESS) isValid = true;
					}
				}
				hEnv_Target = hEnv;

				r = SQLAllocHandle(SQL_HANDLE_DBC, hEnv, &hDbc);
				if (r == SQL_SUCCESS) isValid = true;
				foreach(nOdbcAttributesClass * k, this->m_OdbcAttributes_Map)
				{
				if (k->attributeType == enumAttributeType::hDbc)
					{
					r = ::SQLSetConnectAttr(hDbc, k->odbcKey, (SQLPOINTER)k->odbcValue, 0);
					if (k->odbcKey == SQL_ATTR_CONNECTION_POOLING && k->odbcValue == SQL_CP_ONE_PER_DRIVER) wConnectOption = SQL_DRIVER_NOPROMPT;
					if (k->odbcKey == SQL_ATTR_CONNECTION_POOLING && k->odbcValue == SQL_CP_ONE_PER_HENV) wConnectOption = SQL_DRIVER_NOPROMPT;
					if (k->odbcKey == SQL_ATTR_CONNECTION_POOLING && k->odbcValue == SQL_CP_DRIVER_AWARE) wConnectOption = SQL_DRIVER_NOPROMPT;
					if (r == SQL_SUCCESS) isValid = true;
					}
				}
				hDbc_target = hDbc;
				if (isValid) {
					r = ::SQLDriverConnect(
						hDbc,
						hWnd,
#ifdef UNICODE
						toSQLTCHAR(m_lpszTargetDSN).data(),
#else
						(SQLCHAR*)m_lpszTargetDSN.toUtf8().data(),
#endif
						(SQLSMALLINT)m_lpszTargetDSN.length(),
						connOut.data(),
						1024,
						&cb, 
						wConnectOption); 
						int colSize = cb / sizeof(SQLTCHAR);
					if (r != SQL_SUCCESS && r != SQL_SUCCESS_WITH_INFO)
						{
							QString check = qWarnODBCHandle(SQL_HANDLE_DBC, hDbc);
							qCritical(category) <<  check;
							m_bIsOpen = false;
						}
							m_bIsOpen = true;
					}
			} break;
			default: break;
	}
}
TK_NOTREC::TK_NOTREC(QObject * parent) : QObject(parent) 
,tableName("TK_NOTREC")
,m_dropOption(DropOption::DropTable) { 
	numRowsFetched = 0;
}

#pragma region ~CTOR TK_NOTREC 
TK_NOTREC::~TK_NOTREC() { 

#pragma region Buffers - Clear 
	DB_ID.clear();
	NVTIMESTAMP.clear();
	AREA.clear();
	PAGE.clear();
	LINE.clear();
	TK_NOTDESC.clear();
	TK_NOTCODE.clear();
	TK_LIDLOT.clear();
#pragma endregion Buffers - Clear 
}
#pragma endregion Destructor_TK_NOTREC

// begin method functions
void TK_NOTREC::setAbortFlag() { 
	QLoggingCategory category("classLibQ");
	qCInfo(category) << "isAbort was set to True";
	bIsAbort = true;
}

void TK_NOTREC::run() { 
	process(1);
	QLoggingCategory category("classLibQ");
	qDebug(category) << "Entered;";
}

void	TK_NOTREC::initOdbcAttributes()
{
	QLoggingCategory category("classLibQ");
	this->setProfileName(profileName);
	qDebug(category) << "Processing - TRKDB100"; 
	m_OdbcAttributesList = m_OdbcAttributes.split(","); 
	foreach(QString m, m_OdbcAttributesList)
	{
		QStringList keyValue = m.split("=");
		nOdbcAttributesClass * oM = new nOdbcAttributesClass(this);
		if (oM->loadToOdbc(keyValue.value(0), keyValue.value(1)))
		{
			m_OdbcAttributes_Map.insert(oM->odbcKey, oM);
		}
	}
}
void	TK_NOTREC::initialize()
{
	QLoggingCategory category("classLibQ");
	RETCODE r;
	this->setProfileName(profileName);
	qDebug(category) << "Processing - TRKDB100"; 
//SQL Statements
//--------------------------------------------------

#pragma region Sql Statements_TK_NOTREC

	fetchSql = "select  DB_ID, NVTIMESTAMP, AREA, PAGE, LINE, TK_NOTDESC, TK_NOTCODE, TK_LIDLOT from TK_NOTREC";
		if (m_ReplicationOption == ReplicationOption::NetChange)
		{
			fetchSql.append(" p1, nv_transfers p2 WHERE  p2.table_name = 'TK_NOTREC' AND p1.nvtimestamp > p2.last_completed");
		}
	insertSql = "insert into TK_NOTREC ( PLANT_CODE, NVTIMESTAMP, AREA, PAGE, LINE, TK_NOTDESC, TK_NOTCODE, TK_LIDLOT ) values ( ?, ?, ?, ?, ?, ?, ?, ?)";
	updateSql = "update TK_NOTREC set  PLANT_CODE = ?, NVTIMESTAMP = ?, AREA = ?, PAGE = ?, LINE = ?, TK_NOTDESC = ?, TK_NOTCODE = ?, TK_LIDLOT = ?  where area = ? and page = ? line = ? ";

	qDebug(category) << "insertSQL - insert into TK_NOTREC ( PLANT_CODE, NVTIMESTAMP, AREA, PAGE, LINE, TK_NOTDESC, TK_NOTCODE, TK_LIDLOT ) values ( ?, ?, ?, ?, ?, ?, ?, ?)";
	qDebug(category) << "fetchSQL - select  DB_ID, NVTIMESTAMP, AREA, PAGE, LINE, TK_NOTDESC, TK_NOTCODE, TK_LIDLOT from TK_NOTREC";
	qDebug(category) << "unsertSQL - update TK_NOTREC set  PLANT_CODE = ?, NVTIMESTAMP = ?, AREA = ?, PAGE = ?, LINE = ?, TK_NOTDESC = ?, TK_NOTCODE = ?, TK_LIDLOT = ?  where area = ? and page = ? line = ? ";

#pragma endregion Sql Statements_TK_NOTREC
	SQLHANDLE		insert_hStmt = SQL_NULL_HANDLE;
	SQLHANDLE		fetch_hStmt = SQL_NULL_HANDLE; 
	SQLHANDLE		update_hStmt = SQL_NULL_HANDLE; 
 
	r = ::SQLAllocHandle(SQL_HANDLE_STMT, hDbc_source, &fetch_hStmt);
	if (r != SQL_SUCCESS) {
		 qCCritical(category) << QString("Error  hDbc_Source SQLCode : %1 is %2").arg(QString::number( (long)hDbc_source)).arg(QString::number(r));
		return; 
	}
	r = ::SQLAllocHandle(SQL_HANDLE_STMT, hDbc_target, &insert_hStmt);
	if (r != SQL_SUCCESS) {
		 qCCritical(category) << QString("Error hDbc_Source -SQLCode: %1 is %2").arg(QString::number( (long)hDbc_target)).arg(QString::number(r));
		return; 
	}
	r = ::SQLAllocHandle(SQL_HANDLE_STMT, hDbc_target, &update_hStmt);
	if (r != SQL_SUCCESS) {
		 qCCritical(category) << QString("Error hDbc_Source +SQLCode: %1 is %2").arg(QString::number( (long)hDbc_target)).arg(QString::number(r));
		return; 
	}
 
	hStmt_Fetch = fetch_hStmt;
	hStmt_Insert = insert_hStmt;
	hStmt_Update = update_hStmt;
 
	SQLSetStmtAttr(hStmt_Fetch, SQL_ATTR_USE_BOOKMARKS, (SQLPOINTER)SQL_UB_OFF, 0);
	SQLSetStmtAttr(hStmt_Fetch, SQL_ATTR_ROW_BIND_TYPE, (SQLPOINTER)SQL_BIND_BY_COLUMN, 0);
	SQLSetStmtAttr(hStmt_Fetch, SQL_ATTR_ROW_ARRAY_SIZE, (SQLPOINTER)1, 0);
	SQLSetStmtAttr(hStmt_Fetch, SQL_ATTR_ROWS_FETCHED_PTR, &numRowsFetched, 0);

// Fields used by this class 
// ---------------------------------------------------

#pragma region Resize Fields TK_NOTREC
	qDebug(category) << "Malloc - DB_ID[2]";
	DB_ID.resize(2);
	qDebug(category) << "Malloc - NVTIMESTAMP[23]";
	NVTIMESTAMP.resize(23);
	qDebug(category) << "Malloc - AREA[2]";
	AREA.resize(2);
	qDebug(category) << "Malloc - PAGE[4]";
	PAGE.resize(4);
	qDebug(category) << "Malloc - LINE[2]";
	LINE.resize(2);
	qDebug(category) << "Malloc - TK_NOTDESC[70]";
	TK_NOTDESC.resize(70);
	qDebug(category) << "Malloc - TK_NOTCODE[2]";
	TK_NOTCODE.resize(2);
	qDebug(category) << "Malloc - TK_LIDLOT[24]";
	TK_LIDLOT.resize(24);

#pragma endregion Resize Fields TK_NOTREC
}
void TK_NOTREC::close()
{
	QLoggingCategory category("classLibQ");
	if (m_bIsOpen)
	{
	qDebug(category) << "database is Open";
		SQLHANDLE source_hStmt = hStmt_Fetch;
		SQLHANDLE insert_hStmt = hStmt_Insert;
		SQLHANDLE hDb_S = this->hDbc_source;
		SQLHANDLE hDb_T = hDbc_target;
		SQLHANDLE hEnvS = hEnv_Source;
		SQLHANDLE hEnvT = hEnv_Target;
		RETCODE r;

		r = ::SQLFreeHandle(SQL_HANDLE_STMT, hStmt_Fetch);
		r = ::SQLFreeHandle(SQL_HANDLE_STMT, hStmt_Insert);
		r = ::SQLFreeHandle(SQL_HANDLE_STMT, hStmt_Update);
		if (hDbc_source != SQL_NULL_HANDLE) 		r = ::SQLDisconnect(hDb_S);
		if (hDbc_target != SQL_NULL_HANDLE) 		r = ::SQLDisconnect(hDb_T);

		r = ::SQLFreeHandle(SQL_HANDLE_DBC, hDb_S);
		r = ::SQLFreeHandle(SQL_HANDLE_DBC, hDb_T);
		r = ::SQLFreeHandle(SQL_HANDLE_ENV, hEnvS);
		r = ::SQLFreeHandle(SQL_HANDLE_ENV, hEnvT);
	}

	hEnv_Source = SQL_NULL_HANDLE;
	hEnv_Target = SQL_NULL_HANDLE;
	hEnv_Source = SQL_NULL_HANDLE;
	hEnv_Target = SQL_NULL_HANDLE;
	hStmt_Fetch = SQL_NULL_HANDLE;
	hStmt_Insert = SQL_NULL_HANDLE;
	hStmt_Update = SQL_NULL_HANDLE;
}

void TK_NOTREC::open(const QString sourceDSN, const QString targetDSN)
{
	QLoggingCategory category("classLibQ");
	m_lpszTargetDSN = targetDSN;
	m_lpszSourceDSN = sourceDSN;
	qDebug(category) << QString("Source - %1[%2]").arg(sourceDSN);
	qDebug(category) << QString("Target - %1[%2]").arg(targetDSN);
}

void TK_NOTREC::createTable()
{
	QLoggingCategory category("classLibQ");
	{
		QScopedPointer<nvTableOracleRdb> tbl(new nvTableOracleRdb(nullptr));
		tbl->initialize("TK_NOTREC", this->m_lpszSourceDSN);
		QString newTbl = tbl->getCreateTableSQL();
		QScopedPointer<qVtExecute> vExec(new qVtExecute(nullptr));
		{
			vExec->initialize(m_lpszTargetDSN, " ", true);
			vExec->setOdbcAttributes(m_OdbcAttributes);
			vExec->ExecuteDirect(newTbl);
		}
	 qDebug(category) << QString("End Create Table %1 ").arg(tableName); 
	}
}

bool TK_NOTREC::prepare()
{
	RETCODE r;
	QString check;
	QLoggingCategory category("classLibQ");
	 qDebug(category) << fetchSql;
	 qDebug(category) << insertSql;
#ifdef UNICODE
	r = SQLPrepare(hStmt_Insert,toSQLTCHAR(insertSql).data(),(SQLINTEGER)insertSql.length()); 
	if (r != SQL_SUCCESS) {
		check = qWarnODBCHandle(SQL_HANDLE_STMT, hStmt_Insert);
		 qCCritical(category) << QString("Prepare Statement-Insert : %1 is %2").arg(insertSql).arg(check);
		return false; 
	}
	r = SQLPrepare(hStmt_Update,toSQLTCHAR(updateSql).data(),(SQLINTEGER)updateSql.length()); 
	if (r != SQL_SUCCESS) {
		check = qWarnODBCHandle(SQL_HANDLE_STMT, hStmt_Update);
		 qCCritical(category) << QString("Prepare Statement-Update : %1 is %2").arg(updateSql).arg(check);
		return false; 
	}
	r = SQLPrepare(hStmt_Fetch,toSQLTCHAR(fetchSql).data(),(SQLINTEGER)fetchSql.length());
	if (r != SQL_SUCCESS) {
		check = qWarnODBCHandle(SQL_HANDLE_STMT, hStmt_Fetch);
		 qCCritical(category) << QString("Prepare Statement-Insert : %1 is %2").arg(fetchSql).arg(check);
		return false; 
	}
#else
	QByteArray queryI8 = insertSql.toUtf8();
	r = SQLPrepare(insert_hStmt,SQLCHAR*)queryI8.data(),(SQLINTEGER)queryI8.length());
	QByteArray queryU8 = fetchSql.toUtf8();
	r = SQLPrepare(hStmt_Fetch,(SQLCHAR*)queryU8.data(),(SQLINTEGER)queryU8.length());
#endif
	return true;

}

void TK_NOTREC::prepareTargetTable()
{
	QLoggingCategory category("classLibQ");
	if (this->m_ReplicationOption == ReplicationOption::BulkCopy)
	{
		QScopedPointer<qVtExecute> execSql(new qVtExecute(nullptr));
		DropOption option = this->m_dropOption;
		switch (option)
		{
			case DropOption::DeleteFromTable:
			{
				QLoggingCategory category("classLibQ");
				execSql->initialize(this->m_lpszTargetDSN, "delete from TK_NOTREC", true);
				execSql->setOdbcAttributes(this->m_OdbcAttributes);
				execSql->ExecuteDirect("delete from TK_NOTREC");
			}break;
			case DropOption::TruncateTable:
			{
				execSql->initialize(this->m_lpszTargetDSN, "truncate table TK_NOTREC", true);
				execSql->setOdbcAttributes(this->m_OdbcAttributes);
				execSql->ExecuteDirect("truncate table TK_NOTREC");
			}break;
			case DropOption::DropTable:
			{
				execSql->initialize(this->m_lpszTargetDSN, "drop table TK_NOTREC", true);
				execSql->setOdbcAttributes(this->m_OdbcAttributes);
				execSql->ExecuteDirect("drop table TK_NOTREC");
				createTable();
			}break;
		}
	}
}

bool TK_NOTREC::bindColumn()
{
	QLoggingCategory category("classLibQ");
	RETCODE r;
	bool isValid=true;
		 qDebug(category) << " Bindings: Ordinal [1] Type: 5 Buffer Size: 2 FieldName: DB_ID ";
		r = ::SQLBindCol(hStmt_Fetch, 1, 5, DB_ID.data(), 2, &cbDB_ID);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Bindings: Ordinal [2] Type: 93 Buffer Size: 23 FieldName: NVTIMESTAMP ";
		r = ::SQLBindCol(hStmt_Fetch, 2, 93, NVTIMESTAMP.data(), 23, &cbNVTIMESTAMP);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Bindings: Ordinal [3] Type: 5 Buffer Size: 2 FieldName: AREA ";
		r = ::SQLBindCol(hStmt_Fetch, 3, 5, AREA.data(), 2, &cbAREA);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Bindings: Ordinal [4] Type: 4 Buffer Size: 4 FieldName: PAGE ";
		r = ::SQLBindCol(hStmt_Fetch, 4, 4, PAGE.data(), 4, &cbPAGE);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Bindings: Ordinal [5] Type: 5 Buffer Size: 2 FieldName: LINE ";
		r = ::SQLBindCol(hStmt_Fetch, 5, 5, LINE.data(), 2, &cbLINE);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Bindings: Ordinal [6] Type: 1 Buffer Size: 70 FieldName: TK_NOTDESC ";
		r = ::SQLBindCol(hStmt_Fetch, 6, 1, TK_NOTDESC.data(), 70, &cbTK_NOTDESC);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Bindings: Ordinal [7] Type: 5 Buffer Size: 2 FieldName: TK_NOTCODE ";
		r = ::SQLBindCol(hStmt_Fetch, 7, 5, TK_NOTCODE.data(), 2, &cbTK_NOTCODE);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Bindings: Ordinal [8] Type: 1 Buffer Size: 24 FieldName: TK_LIDLOT ";
		r = ::SQLBindCol(hStmt_Fetch, 8, 1, TK_LIDLOT.data(), 24, &cbTK_LIDLOT);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
	return isValid;
}

bool TK_NOTREC::bindParameter()
{
	QLoggingCategory category("classLibQ");
	RETCODE r;
	bool isValid=true;
	{
		 qDebug(category) << " Parameters: Ordinal [1] Type: 5 Buffer Size: 2 FieldName: DB_ID ";
		r = SQLBindParameter(hStmt_Insert, 1, SQL_PARAM_INPUT, SQL_C_DEFAULT, 5, 0, 0, (SQLPOINTER)DB_ID.constData(), 0, &cbDB_ID);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Parameters: Ordinal [2] Type: 93 Buffer Size: 23 FieldName: NVTIMESTAMP ";
		r = SQLBindParameter(hStmt_Insert, 2, SQL_PARAM_INPUT, SQL_C_DEFAULT, 93, 23, 0, (SQLPOINTER)NVTIMESTAMP.constData(), 0, &cbNVTIMESTAMP);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Parameters: Ordinal [3] Type: 5 Buffer Size: 2 FieldName: AREA ";
		r = SQLBindParameter(hStmt_Insert, 3, SQL_PARAM_INPUT, SQL_C_DEFAULT, 5, 0, 0, (SQLPOINTER)AREA.constData(), 0, &cbAREA);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Parameters: Ordinal [4] Type: 4 Buffer Size: 4 FieldName: PAGE ";
		r = SQLBindParameter(hStmt_Insert, 4, SQL_PARAM_INPUT, SQL_C_DEFAULT, 4, 0, 0, (SQLPOINTER)PAGE.constData(), 0, &cbPAGE);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Parameters: Ordinal [5] Type: 5 Buffer Size: 2 FieldName: LINE ";
		r = SQLBindParameter(hStmt_Insert, 5, SQL_PARAM_INPUT, SQL_C_DEFAULT, 5, 0, 0, (SQLPOINTER)LINE.constData(), 0, &cbLINE);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Parameters: Ordinal [6] Type: 1 Buffer Size: 70 FieldName: TK_NOTDESC ";
		r = SQLBindParameter(hStmt_Insert, 6, SQL_PARAM_INPUT, SQL_C_DEFAULT, 1, 70, 0, (SQLPOINTER)TK_NOTDESC.constData(), 0, &cbTK_NOTDESC);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Parameters: Ordinal [7] Type: 5 Buffer Size: 2 FieldName: TK_NOTCODE ";
		r = SQLBindParameter(hStmt_Insert, 7, SQL_PARAM_INPUT, SQL_C_DEFAULT, 5, 0, 0, (SQLPOINTER)TK_NOTCODE.constData(), 0, &cbTK_NOTCODE);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Parameters: Ordinal [8] Type: 1 Buffer Size: 24 FieldName: TK_LIDLOT ";
		r = SQLBindParameter(hStmt_Insert, 8, SQL_PARAM_INPUT, SQL_C_DEFAULT, 1, 24, 0, (SQLPOINTER)TK_LIDLOT.constData(), 0, &cbTK_LIDLOT);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
	}
	if (m_ReplicationOption == ReplicationOption::NetChange)
	{
		r = SQLBindParameter(hStmt_Update, 9, SQL_PARAM_INPUT, SQL_C_DEFAULT, 3, 0, 0, (SQLPOINTER)AREA.constData(), 0, &cbAREA);
		if (r == SQL_SUCCESS) { isValid=true; }
		r = SQLBindParameter(hStmt_Update, 10, SQL_PARAM_INPUT, SQL_C_DEFAULT, 4, 0, 0, (SQLPOINTER)PAGE.constData(), 0, &cbPAGE);
		if (r == SQL_SUCCESS) { isValid=true; }
		r = SQLBindParameter(hStmt_Update, 11, SQL_PARAM_INPUT, SQL_C_DEFAULT, 5, 0, 0, (SQLPOINTER)LINE.constData(), 0, &cbLINE);
		if (r == SQL_SUCCESS) { isValid=true; }
	// TK_NOTREC is a well formed table for eNVy Replication 
		 qDebug(category) << " Parameters: Ordinal [3] 00 00 FieldName: AREA ";
		 qDebug(category) << " Parameters: Ordinal [4] 00 00  FieldName: PAGE ";
		 qDebug(category) << " Parameters: Ordinal [5] 00 00 FieldName:  LINE ";
	} // 	if (m_ReplicationOption == ReplicationOption::NetChange)
	return isValid;
}

bool TK_NOTREC::process(int rowSize)
{
	QLoggingCategory category("classLibQ");
	initOdbcAttributes();
	connect(Source);
	connect(Target);
	initialize();
	prepareTargetTable();
	prepare();
	bindColumn();
	bindParameter();
	copyTable();
	close();
	return false;
}

void TK_NOTREC::copyTable()
{
	QLoggingCategory category("classLibQ");
	RETCODE r;
	QString check;
	r = SQLExecute(hStmt_Fetch);
		if (bIsAbort) {
			emit aborted(tableName, rowsFetched, rowsInserted, rowsUpdated);
			return;
		}
		while((r = SQLFetch(hStmt_Fetch)) != SQL_NO_DATA) {
		if (r != SQL_SUCCESS) {
			check = qWarnODBCHandle(SQL_HANDLE_STMT, hStmt_Fetch);
			qCCritical(category) << QString("SqlFetch - Error : %1 is %2").arg(fetchSql).arg(check);
			return;
		} 
		rowsFetched++;
		if (m_ReplicationOption == ReplicationOption::BulkCopy)
		{
			r = SQLExecute(hStmt_Insert);
			if (r == SQL_ERROR) {
				check = qWarnODBCHandle(SQL_HANDLE_STMT, hStmt_Insert);
				 qCCritical(category) << QString("SqlExecute:Insert - Error : %1 is %2").arg(insertSql).arg(check);
				return;
			}
			rowsInserted++;
			if ((rowsFetched % updateInterval) == 0) {
				qCInfo(category) << QString("[%1.%2]	Insertion: %3	Updates : %4	Fetched : %5").arg(profileName).arg(tableName).arg(rowsInserted).arg(rowsUpdated).arg(rowsFetched);
				emit updateStatusFetched(profileName, tableName, rowsFetched,rowsInserted,rowsUpdated);
			}
			if (m_ReplicationOption == ReplicationOption::NetChange)
			{
			r = SQLExecute(hStmt_Update);
			if (r != SQL_SUCCESS) {
				check = qWarnODBCHandle(SQL_HANDLE_STMT, hStmt_Update);
				 qCInfo(category)  << QString("SqlExecute:Update - Error : %1 is %2").arg(updateSql).arg(check);
				r = SQLExecute(hStmt_Insert);
				if (r != SQL_SUCCESS) {
					check = qWarnODBCHandle(SQL_HANDLE_STMT, hStmt_Insert);
					 qCritical(category) << QString("SqlExecute:Insert - Error : %1 is %2").arg(insertSql).arg(check);
					return;
				}
				else 	rowsInserted++;
				}
				else	rowsUpdated++;
			}
			emit updateStatusFetched(profileName, tableName, rowsFetched,rowsInserted,rowsUpdated);
		}
	} 
qCInfo(category) << QString("[%1.%2]	Insertion: %3	Updates : %4	Fetched : %5").arg(profileName).arg(tableName).arg(rowsInserted).arg(rowsUpdated).arg(rowsFetched);
}

void TK_NOTREC::connect(connectionHandle connectionSource)
{

	QLoggingCategory category("classLibQ");
	RETCODE r;

	bool isValid = false;
	HWND	hWnd = nullptr;
	hWnd = ::GetDesktopWindow(); 
	SQLSMALLINT nResult = 0;

	SQLSMALLINT cb;
	UWORD wConnectOption = SQL_DRIVER_COMPLETE; //SQL_DRIVER_NOPROMPT;
	QVarLengthArray<SQLTCHAR> connOut(1024);
	memset(connOut.data(), 0, connOut.size() * sizeof(SQLTCHAR));

	switch (connectionSource)
	{
		case Source:
			{// environment
				SQLHANDLE hEnv = SQL_NULL_HANDLE;
				SQLHANDLE hDbc = SQL_NULL_HANDLE;
				r = ::SQLAllocHandle(SQL_HANDLE_ENV, SQL_NULL_HANDLE, &hEnv);
				if (r == SQL_SUCCESS) isValid = true;

				foreach(nOdbcAttributesClass * k, this->m_OdbcAttributes_Map)
				{
					if (k->attributeType == enumAttributeType::hEnv)
					{
						r = ::SQLSetEnvAttr(hEnv, (SQLINTEGER) k->odbcKey, (SQLPOINTER)k->odbcValue, 0);
						if (r == SQL_SUCCESS) isValid = true;
					}
				}
				hEnv_Source = hEnv;

				r = SQLAllocHandle(SQL_HANDLE_DBC, hEnv, &hDbc);
				if (r == SQL_SUCCESS) isValid = true;
				foreach(nOdbcAttributesClass * k, this->m_OdbcAttributes_Map)
				{
					if (k->attributeType == enumAttributeType::hDbc)
					{
					r = ::SQLSetConnectAttr(hDbc, k->odbcKey, (SQLPOINTER)k->odbcValue, 0);
					if (k->odbcKey == SQL_ATTR_CONNECTION_POOLING && k->odbcValue == SQL_CP_ONE_PER_DRIVER) wConnectOption = SQL_DRIVER_NOPROMPT;
					if (k->odbcKey == SQL_ATTR_CONNECTION_POOLING && k->odbcValue == SQL_CP_ONE_PER_HENV) wConnectOption = SQL_DRIVER_NOPROMPT;
					if (k->odbcKey == SQL_ATTR_CONNECTION_POOLING && k->odbcValue == SQL_CP_DRIVER_AWARE) wConnectOption = SQL_DRIVER_NOPROMPT;
					if (r == SQL_SUCCESS) isValid = true;
					}
				}
				hDbc_source = hDbc;
				if (isValid)
				{
					r = ::SQLDriverConnect(
						hDbc,
						hWnd,
#ifdef UNICODE
						toSQLTCHAR(m_lpszSourceDSN).data(),
#else
						(SQLCHAR*)dsnSource.toUtf8().data(),
#endif
						(SQLSMALLINT)m_lpszSourceDSN.length(),
						connOut.data(),
						1024,
						&cb, 
						wConnectOption); 
					int colSize = cb / sizeof(SQLTCHAR);
					if (r != SQL_SUCCESS && r != SQL_SUCCESS_WITH_INFO)
					{
						QString check = qWarnODBCHandle(SQL_HANDLE_DBC, hDbc);
						qCritical(category) <<  check;
						m_bIsOpen = false;
					}
					m_bIsOpen = true;
				}
			} break;
		case Target:
			{
				SQLHANDLE hEnv = SQL_NULL_HANDLE;
				SQLHANDLE hDbc = SQL_NULL_HANDLE;
				r = ::SQLAllocHandle(SQL_HANDLE_ENV, SQL_NULL_HANDLE, &hEnv);
				if (r == SQL_SUCCESS) isValid = true;

				foreach(nOdbcAttributesClass * k, this->m_OdbcAttributes_Map)
				{
					if (k->attributeType == enumAttributeType::hEnv)
					{
						r = ::SQLSetEnvAttr(hEnv, (SQLINTEGER) k->odbcKey, (SQLPOINTER)k->odbcValue, 0);
						if (r == SQL_SUCCESS) isValid = true;
					}
				}
				hEnv_Target = hEnv;

				r = SQLAllocHandle(SQL_HANDLE_DBC, hEnv, &hDbc);
				if (r == SQL_SUCCESS) isValid = true;
				foreach(nOdbcAttributesClass * k, this->m_OdbcAttributes_Map)
				{
				if (k->attributeType == enumAttributeType::hDbc)
					{
					r = ::SQLSetConnectAttr(hDbc, k->odbcKey, (SQLPOINTER)k->odbcValue, 0);
					if (k->odbcKey == SQL_ATTR_CONNECTION_POOLING && k->odbcValue == SQL_CP_ONE_PER_DRIVER) wConnectOption = SQL_DRIVER_NOPROMPT;
					if (k->odbcKey == SQL_ATTR_CONNECTION_POOLING && k->odbcValue == SQL_CP_ONE_PER_HENV) wConnectOption = SQL_DRIVER_NOPROMPT;
					if (k->odbcKey == SQL_ATTR_CONNECTION_POOLING && k->odbcValue == SQL_CP_DRIVER_AWARE) wConnectOption = SQL_DRIVER_NOPROMPT;
					if (r == SQL_SUCCESS) isValid = true;
					}
				}
				hDbc_target = hDbc;
				if (isValid) {
					r = ::SQLDriverConnect(
						hDbc,
						hWnd,
#ifdef UNICODE
						toSQLTCHAR(m_lpszTargetDSN).data(),
#else
						(SQLCHAR*)m_lpszTargetDSN.toUtf8().data(),
#endif
						(SQLSMALLINT)m_lpszTargetDSN.length(),
						connOut.data(),
						1024,
						&cb, 
						wConnectOption); 
						int colSize = cb / sizeof(SQLTCHAR);
					if (r != SQL_SUCCESS && r != SQL_SUCCESS_WITH_INFO)
						{
							QString check = qWarnODBCHandle(SQL_HANDLE_DBC, hDbc);
							qCritical(category) <<  check;
							m_bIsOpen = false;
						}
							m_bIsOpen = true;
					}
			} break;
			default: break;
	}
}
TK_UPRTREC::TK_UPRTREC(QObject * parent) : QObject(parent) 
,tableName("TK_UPRTREC")
,m_dropOption(DropOption::DropTable) { 
	numRowsFetched = 0;
}

#pragma region ~CTOR TK_UPRTREC 
TK_UPRTREC::~TK_UPRTREC() { 

#pragma region Buffers - Clear 
	DB_ID.clear();
	NVTIMESTAMP.clear();
	AREA.clear();
	PAGE.clear();
	LINE.clear();
	TK_UPRTNO.clear();
#pragma endregion Buffers - Clear 
}
#pragma endregion Destructor_TK_UPRTREC

// begin method functions
void TK_UPRTREC::setAbortFlag() { 
	QLoggingCategory category("classLibQ");
	qCInfo(category) << "isAbort was set to True";
	bIsAbort = true;
}

void TK_UPRTREC::run() { 
	process(1);
	QLoggingCategory category("classLibQ");
	qDebug(category) << "Entered;";
}

void	TK_UPRTREC::initOdbcAttributes()
{
	QLoggingCategory category("classLibQ");
	this->setProfileName(profileName);
	qDebug(category) << "Processing - TRKDB100"; 
	m_OdbcAttributesList = m_OdbcAttributes.split(","); 
	foreach(QString m, m_OdbcAttributesList)
	{
		QStringList keyValue = m.split("=");
		nOdbcAttributesClass * oM = new nOdbcAttributesClass(this);
		if (oM->loadToOdbc(keyValue.value(0), keyValue.value(1)))
		{
			m_OdbcAttributes_Map.insert(oM->odbcKey, oM);
		}
	}
}
void	TK_UPRTREC::initialize()
{
	QLoggingCategory category("classLibQ");
	RETCODE r;
	this->setProfileName(profileName);
	qDebug(category) << "Processing - TRKDB100"; 
//SQL Statements
//--------------------------------------------------

#pragma region Sql Statements_TK_UPRTREC

	fetchSql = "select  DB_ID, NVTIMESTAMP, AREA, PAGE, LINE, TK_UPRTNO from TK_UPRTREC";
		if (m_ReplicationOption == ReplicationOption::NetChange)
		{
			fetchSql.append(" p1, nv_transfers p2 WHERE  p2.table_name = 'TK_UPRTREC' AND p1.nvtimestamp > p2.last_completed");
		}
	insertSql = "insert into TK_UPRTREC ( PLANT_CODE, NVTIMESTAMP, AREA, PAGE, LINE, TK_UPRTNO ) values ( ?, ?, ?, ?, ?, ?)";
	updateSql = "update TK_UPRTREC set  PLANT_CODE = ?, NVTIMESTAMP = ?, AREA = ?, PAGE = ?, LINE = ?, TK_UPRTNO = ?  where area = ? and page = ? line = ? ";

	qDebug(category) << "insertSQL - insert into TK_UPRTREC ( PLANT_CODE, NVTIMESTAMP, AREA, PAGE, LINE, TK_UPRTNO ) values ( ?, ?, ?, ?, ?, ?)";
	qDebug(category) << "fetchSQL - select  DB_ID, NVTIMESTAMP, AREA, PAGE, LINE, TK_UPRTNO from TK_UPRTREC";
	qDebug(category) << "unsertSQL - update TK_UPRTREC set  PLANT_CODE = ?, NVTIMESTAMP = ?, AREA = ?, PAGE = ?, LINE = ?, TK_UPRTNO = ?  where area = ? and page = ? line = ? ";

#pragma endregion Sql Statements_TK_UPRTREC
	SQLHANDLE		insert_hStmt = SQL_NULL_HANDLE;
	SQLHANDLE		fetch_hStmt = SQL_NULL_HANDLE; 
	SQLHANDLE		update_hStmt = SQL_NULL_HANDLE; 
 
	r = ::SQLAllocHandle(SQL_HANDLE_STMT, hDbc_source, &fetch_hStmt);
	if (r != SQL_SUCCESS) {
		 qCCritical(category) << QString("Error  hDbc_Source SQLCode : %1 is %2").arg(QString::number( (long)hDbc_source)).arg(QString::number(r));
		return; 
	}
	r = ::SQLAllocHandle(SQL_HANDLE_STMT, hDbc_target, &insert_hStmt);
	if (r != SQL_SUCCESS) {
		 qCCritical(category) << QString("Error hDbc_Source -SQLCode: %1 is %2").arg(QString::number( (long)hDbc_target)).arg(QString::number(r));
		return; 
	}
	r = ::SQLAllocHandle(SQL_HANDLE_STMT, hDbc_target, &update_hStmt);
	if (r != SQL_SUCCESS) {
		 qCCritical(category) << QString("Error hDbc_Source +SQLCode: %1 is %2").arg(QString::number( (long)hDbc_target)).arg(QString::number(r));
		return; 
	}
 
	hStmt_Fetch = fetch_hStmt;
	hStmt_Insert = insert_hStmt;
	hStmt_Update = update_hStmt;
 
	SQLSetStmtAttr(hStmt_Fetch, SQL_ATTR_USE_BOOKMARKS, (SQLPOINTER)SQL_UB_OFF, 0);
	SQLSetStmtAttr(hStmt_Fetch, SQL_ATTR_ROW_BIND_TYPE, (SQLPOINTER)SQL_BIND_BY_COLUMN, 0);
	SQLSetStmtAttr(hStmt_Fetch, SQL_ATTR_ROW_ARRAY_SIZE, (SQLPOINTER)1, 0);
	SQLSetStmtAttr(hStmt_Fetch, SQL_ATTR_ROWS_FETCHED_PTR, &numRowsFetched, 0);

// Fields used by this class 
// ---------------------------------------------------

#pragma region Resize Fields TK_UPRTREC
	qDebug(category) << "Malloc - DB_ID[2]";
	DB_ID.resize(2);
	qDebug(category) << "Malloc - NVTIMESTAMP[23]";
	NVTIMESTAMP.resize(23);
	qDebug(category) << "Malloc - AREA[2]";
	AREA.resize(2);
	qDebug(category) << "Malloc - PAGE[4]";
	PAGE.resize(4);
	qDebug(category) << "Malloc - LINE[2]";
	LINE.resize(2);
	qDebug(category) << "Malloc - TK_UPRTNO[18]";
	TK_UPRTNO.resize(18);

#pragma endregion Resize Fields TK_UPRTREC
}
void TK_UPRTREC::close()
{
	QLoggingCategory category("classLibQ");
	if (m_bIsOpen)
	{
	qDebug(category) << "database is Open";
		SQLHANDLE source_hStmt = hStmt_Fetch;
		SQLHANDLE insert_hStmt = hStmt_Insert;
		SQLHANDLE hDb_S = this->hDbc_source;
		SQLHANDLE hDb_T = hDbc_target;
		SQLHANDLE hEnvS = hEnv_Source;
		SQLHANDLE hEnvT = hEnv_Target;
		RETCODE r;

		r = ::SQLFreeHandle(SQL_HANDLE_STMT, hStmt_Fetch);
		r = ::SQLFreeHandle(SQL_HANDLE_STMT, hStmt_Insert);
		r = ::SQLFreeHandle(SQL_HANDLE_STMT, hStmt_Update);
		if (hDbc_source != SQL_NULL_HANDLE) 		r = ::SQLDisconnect(hDb_S);
		if (hDbc_target != SQL_NULL_HANDLE) 		r = ::SQLDisconnect(hDb_T);

		r = ::SQLFreeHandle(SQL_HANDLE_DBC, hDb_S);
		r = ::SQLFreeHandle(SQL_HANDLE_DBC, hDb_T);
		r = ::SQLFreeHandle(SQL_HANDLE_ENV, hEnvS);
		r = ::SQLFreeHandle(SQL_HANDLE_ENV, hEnvT);
	}

	hEnv_Source = SQL_NULL_HANDLE;
	hEnv_Target = SQL_NULL_HANDLE;
	hEnv_Source = SQL_NULL_HANDLE;
	hEnv_Target = SQL_NULL_HANDLE;
	hStmt_Fetch = SQL_NULL_HANDLE;
	hStmt_Insert = SQL_NULL_HANDLE;
	hStmt_Update = SQL_NULL_HANDLE;
}

void TK_UPRTREC::open(const QString sourceDSN, const QString targetDSN)
{
	QLoggingCategory category("classLibQ");
	m_lpszTargetDSN = targetDSN;
	m_lpszSourceDSN = sourceDSN;
	qDebug(category) << QString("Source - %1[%2]").arg(sourceDSN);
	qDebug(category) << QString("Target - %1[%2]").arg(targetDSN);
}

void TK_UPRTREC::createTable()
{
	QLoggingCategory category("classLibQ");
	{
		QScopedPointer<nvTableOracleRdb> tbl(new nvTableOracleRdb(nullptr));
		tbl->initialize("TK_UPRTREC", this->m_lpszSourceDSN);
		QString newTbl = tbl->getCreateTableSQL();
		QScopedPointer<qVtExecute> vExec(new qVtExecute(nullptr));
		{
			vExec->initialize(m_lpszTargetDSN, " ", true);
			vExec->setOdbcAttributes(m_OdbcAttributes);
			vExec->ExecuteDirect(newTbl);
		}
	 qDebug(category) << QString("End Create Table %1 ").arg(tableName); 
	}
}

bool TK_UPRTREC::prepare()
{
	RETCODE r;
	QString check;
	QLoggingCategory category("classLibQ");
	 qDebug(category) << fetchSql;
	 qDebug(category) << insertSql;
#ifdef UNICODE
	r = SQLPrepare(hStmt_Insert,toSQLTCHAR(insertSql).data(),(SQLINTEGER)insertSql.length()); 
	if (r != SQL_SUCCESS) {
		check = qWarnODBCHandle(SQL_HANDLE_STMT, hStmt_Insert);
		 qCCritical(category) << QString("Prepare Statement-Insert : %1 is %2").arg(insertSql).arg(check);
		return false; 
	}
	r = SQLPrepare(hStmt_Update,toSQLTCHAR(updateSql).data(),(SQLINTEGER)updateSql.length()); 
	if (r != SQL_SUCCESS) {
		check = qWarnODBCHandle(SQL_HANDLE_STMT, hStmt_Update);
		 qCCritical(category) << QString("Prepare Statement-Update : %1 is %2").arg(updateSql).arg(check);
		return false; 
	}
	r = SQLPrepare(hStmt_Fetch,toSQLTCHAR(fetchSql).data(),(SQLINTEGER)fetchSql.length());
	if (r != SQL_SUCCESS) {
		check = qWarnODBCHandle(SQL_HANDLE_STMT, hStmt_Fetch);
		 qCCritical(category) << QString("Prepare Statement-Insert : %1 is %2").arg(fetchSql).arg(check);
		return false; 
	}
#else
	QByteArray queryI8 = insertSql.toUtf8();
	r = SQLPrepare(insert_hStmt,SQLCHAR*)queryI8.data(),(SQLINTEGER)queryI8.length());
	QByteArray queryU8 = fetchSql.toUtf8();
	r = SQLPrepare(hStmt_Fetch,(SQLCHAR*)queryU8.data(),(SQLINTEGER)queryU8.length());
#endif
	return true;

}

void TK_UPRTREC::prepareTargetTable()
{
	QLoggingCategory category("classLibQ");
	if (this->m_ReplicationOption == ReplicationOption::BulkCopy)
	{
		QScopedPointer<qVtExecute> execSql(new qVtExecute(nullptr));
		DropOption option = this->m_dropOption;
		switch (option)
		{
			case DropOption::DeleteFromTable:
			{
				QLoggingCategory category("classLibQ");
				execSql->initialize(this->m_lpszTargetDSN, "delete from TK_UPRTREC", true);
				execSql->setOdbcAttributes(this->m_OdbcAttributes);
				execSql->ExecuteDirect("delete from TK_UPRTREC");
			}break;
			case DropOption::TruncateTable:
			{
				execSql->initialize(this->m_lpszTargetDSN, "truncate table TK_UPRTREC", true);
				execSql->setOdbcAttributes(this->m_OdbcAttributes);
				execSql->ExecuteDirect("truncate table TK_UPRTREC");
			}break;
			case DropOption::DropTable:
			{
				execSql->initialize(this->m_lpszTargetDSN, "drop table TK_UPRTREC", true);
				execSql->setOdbcAttributes(this->m_OdbcAttributes);
				execSql->ExecuteDirect("drop table TK_UPRTREC");
				createTable();
			}break;
		}
	}
}

bool TK_UPRTREC::bindColumn()
{
	QLoggingCategory category("classLibQ");
	RETCODE r;
	bool isValid=true;
		 qDebug(category) << " Bindings: Ordinal [1] Type: 5 Buffer Size: 2 FieldName: DB_ID ";
		r = ::SQLBindCol(hStmt_Fetch, 1, 5, DB_ID.data(), 2, &cbDB_ID);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Bindings: Ordinal [2] Type: 93 Buffer Size: 23 FieldName: NVTIMESTAMP ";
		r = ::SQLBindCol(hStmt_Fetch, 2, 93, NVTIMESTAMP.data(), 23, &cbNVTIMESTAMP);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Bindings: Ordinal [3] Type: 5 Buffer Size: 2 FieldName: AREA ";
		r = ::SQLBindCol(hStmt_Fetch, 3, 5, AREA.data(), 2, &cbAREA);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Bindings: Ordinal [4] Type: 4 Buffer Size: 4 FieldName: PAGE ";
		r = ::SQLBindCol(hStmt_Fetch, 4, 4, PAGE.data(), 4, &cbPAGE);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Bindings: Ordinal [5] Type: 5 Buffer Size: 2 FieldName: LINE ";
		r = ::SQLBindCol(hStmt_Fetch, 5, 5, LINE.data(), 2, &cbLINE);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Bindings: Ordinal [6] Type: 1 Buffer Size: 18 FieldName: TK_UPRTNO ";
		r = ::SQLBindCol(hStmt_Fetch, 6, 1, TK_UPRTNO.data(), 18, &cbTK_UPRTNO);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
	return isValid;
}

bool TK_UPRTREC::bindParameter()
{
	QLoggingCategory category("classLibQ");
	RETCODE r;
	bool isValid=true;
	{
		 qDebug(category) << " Parameters: Ordinal [1] Type: 5 Buffer Size: 2 FieldName: DB_ID ";
		r = SQLBindParameter(hStmt_Insert, 1, SQL_PARAM_INPUT, SQL_C_DEFAULT, 5, 0, 0, (SQLPOINTER)DB_ID.constData(), 0, &cbDB_ID);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Parameters: Ordinal [2] Type: 93 Buffer Size: 23 FieldName: NVTIMESTAMP ";
		r = SQLBindParameter(hStmt_Insert, 2, SQL_PARAM_INPUT, SQL_C_DEFAULT, 93, 23, 0, (SQLPOINTER)NVTIMESTAMP.constData(), 0, &cbNVTIMESTAMP);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Parameters: Ordinal [3] Type: 5 Buffer Size: 2 FieldName: AREA ";
		r = SQLBindParameter(hStmt_Insert, 3, SQL_PARAM_INPUT, SQL_C_DEFAULT, 5, 0, 0, (SQLPOINTER)AREA.constData(), 0, &cbAREA);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Parameters: Ordinal [4] Type: 4 Buffer Size: 4 FieldName: PAGE ";
		r = SQLBindParameter(hStmt_Insert, 4, SQL_PARAM_INPUT, SQL_C_DEFAULT, 4, 0, 0, (SQLPOINTER)PAGE.constData(), 0, &cbPAGE);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Parameters: Ordinal [5] Type: 5 Buffer Size: 2 FieldName: LINE ";
		r = SQLBindParameter(hStmt_Insert, 5, SQL_PARAM_INPUT, SQL_C_DEFAULT, 5, 0, 0, (SQLPOINTER)LINE.constData(), 0, &cbLINE);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Parameters: Ordinal [6] Type: 1 Buffer Size: 18 FieldName: TK_UPRTNO ";
		r = SQLBindParameter(hStmt_Insert, 6, SQL_PARAM_INPUT, SQL_C_DEFAULT, 1, 18, 0, (SQLPOINTER)TK_UPRTNO.constData(), 0, &cbTK_UPRTNO);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
	}
	if (m_ReplicationOption == ReplicationOption::NetChange)
	{
		r = SQLBindParameter(hStmt_Update, 7, SQL_PARAM_INPUT, SQL_C_DEFAULT, 3, 0, 0, (SQLPOINTER)AREA.constData(), 0, &cbAREA);
		if (r == SQL_SUCCESS) { isValid=true; }
		r = SQLBindParameter(hStmt_Update, 8, SQL_PARAM_INPUT, SQL_C_DEFAULT, 4, 0, 0, (SQLPOINTER)PAGE.constData(), 0, &cbPAGE);
		if (r == SQL_SUCCESS) { isValid=true; }
		r = SQLBindParameter(hStmt_Update, 9, SQL_PARAM_INPUT, SQL_C_DEFAULT, 5, 0, 0, (SQLPOINTER)LINE.constData(), 0, &cbLINE);
		if (r == SQL_SUCCESS) { isValid=true; }
	// TK_UPRTREC is a well formed table for eNVy Replication 
		 qDebug(category) << " Parameters: Ordinal [3] 00 00 FieldName: AREA ";
		 qDebug(category) << " Parameters: Ordinal [4] 00 00  FieldName: PAGE ";
		 qDebug(category) << " Parameters: Ordinal [5] 00 00 FieldName:  LINE ";
	} // 	if (m_ReplicationOption == ReplicationOption::NetChange)
	return isValid;
}

bool TK_UPRTREC::process(int rowSize)
{
	QLoggingCategory category("classLibQ");
	initOdbcAttributes();
	connect(Source);
	connect(Target);
	initialize();
	prepareTargetTable();
	prepare();
	bindColumn();
	bindParameter();
	copyTable();
	close();
	return false;
}

void TK_UPRTREC::copyTable()
{
	QLoggingCategory category("classLibQ");
	RETCODE r;
	QString check;
	r = SQLExecute(hStmt_Fetch);
		if (bIsAbort) {
			emit aborted(tableName, rowsFetched, rowsInserted, rowsUpdated);
			return;
		}
		while((r = SQLFetch(hStmt_Fetch)) != SQL_NO_DATA) {
		if (r != SQL_SUCCESS) {
			check = qWarnODBCHandle(SQL_HANDLE_STMT, hStmt_Fetch);
			qCCritical(category) << QString("SqlFetch - Error : %1 is %2").arg(fetchSql).arg(check);
			return;
		} 
		rowsFetched++;
		if (m_ReplicationOption == ReplicationOption::BulkCopy)
		{
			r = SQLExecute(hStmt_Insert);
			if (r == SQL_ERROR) {
				check = qWarnODBCHandle(SQL_HANDLE_STMT, hStmt_Insert);
				 qCCritical(category) << QString("SqlExecute:Insert - Error : %1 is %2").arg(insertSql).arg(check);
				return;
			}
			rowsInserted++;
			if ((rowsFetched % updateInterval) == 0) {
				qCInfo(category) << QString("[%1.%2]	Insertion: %3	Updates : %4	Fetched : %5").arg(profileName).arg(tableName).arg(rowsInserted).arg(rowsUpdated).arg(rowsFetched);
				emit updateStatusFetched(profileName, tableName, rowsFetched,rowsInserted,rowsUpdated);
			}
			if (m_ReplicationOption == ReplicationOption::NetChange)
			{
			r = SQLExecute(hStmt_Update);
			if (r != SQL_SUCCESS) {
				check = qWarnODBCHandle(SQL_HANDLE_STMT, hStmt_Update);
				 qCInfo(category)  << QString("SqlExecute:Update - Error : %1 is %2").arg(updateSql).arg(check);
				r = SQLExecute(hStmt_Insert);
				if (r != SQL_SUCCESS) {
					check = qWarnODBCHandle(SQL_HANDLE_STMT, hStmt_Insert);
					 qCritical(category) << QString("SqlExecute:Insert - Error : %1 is %2").arg(insertSql).arg(check);
					return;
				}
				else 	rowsInserted++;
				}
				else	rowsUpdated++;
			}
			emit updateStatusFetched(profileName, tableName, rowsFetched,rowsInserted,rowsUpdated);
		}
	} 
qCInfo(category) << QString("[%1.%2]	Insertion: %3	Updates : %4	Fetched : %5").arg(profileName).arg(tableName).arg(rowsInserted).arg(rowsUpdated).arg(rowsFetched);
}

void TK_UPRTREC::connect(connectionHandle connectionSource)
{

	QLoggingCategory category("classLibQ");
	RETCODE r;

	bool isValid = false;
	HWND	hWnd = nullptr;
	hWnd = ::GetDesktopWindow(); 
	SQLSMALLINT nResult = 0;

	SQLSMALLINT cb;
	UWORD wConnectOption = SQL_DRIVER_COMPLETE; //SQL_DRIVER_NOPROMPT;
	QVarLengthArray<SQLTCHAR> connOut(1024);
	memset(connOut.data(), 0, connOut.size() * sizeof(SQLTCHAR));

	switch (connectionSource)
	{
		case Source:
			{// environment
				SQLHANDLE hEnv = SQL_NULL_HANDLE;
				SQLHANDLE hDbc = SQL_NULL_HANDLE;
				r = ::SQLAllocHandle(SQL_HANDLE_ENV, SQL_NULL_HANDLE, &hEnv);
				if (r == SQL_SUCCESS) isValid = true;

				foreach(nOdbcAttributesClass * k, this->m_OdbcAttributes_Map)
				{
					if (k->attributeType == enumAttributeType::hEnv)
					{
						r = ::SQLSetEnvAttr(hEnv, (SQLINTEGER) k->odbcKey, (SQLPOINTER)k->odbcValue, 0);
						if (r == SQL_SUCCESS) isValid = true;
					}
				}
				hEnv_Source = hEnv;

				r = SQLAllocHandle(SQL_HANDLE_DBC, hEnv, &hDbc);
				if (r == SQL_SUCCESS) isValid = true;
				foreach(nOdbcAttributesClass * k, this->m_OdbcAttributes_Map)
				{
					if (k->attributeType == enumAttributeType::hDbc)
					{
					r = ::SQLSetConnectAttr(hDbc, k->odbcKey, (SQLPOINTER)k->odbcValue, 0);
					if (k->odbcKey == SQL_ATTR_CONNECTION_POOLING && k->odbcValue == SQL_CP_ONE_PER_DRIVER) wConnectOption = SQL_DRIVER_NOPROMPT;
					if (k->odbcKey == SQL_ATTR_CONNECTION_POOLING && k->odbcValue == SQL_CP_ONE_PER_HENV) wConnectOption = SQL_DRIVER_NOPROMPT;
					if (k->odbcKey == SQL_ATTR_CONNECTION_POOLING && k->odbcValue == SQL_CP_DRIVER_AWARE) wConnectOption = SQL_DRIVER_NOPROMPT;
					if (r == SQL_SUCCESS) isValid = true;
					}
				}
				hDbc_source = hDbc;
				if (isValid)
				{
					r = ::SQLDriverConnect(
						hDbc,
						hWnd,
#ifdef UNICODE
						toSQLTCHAR(m_lpszSourceDSN).data(),
#else
						(SQLCHAR*)dsnSource.toUtf8().data(),
#endif
						(SQLSMALLINT)m_lpszSourceDSN.length(),
						connOut.data(),
						1024,
						&cb, 
						wConnectOption); 
					int colSize = cb / sizeof(SQLTCHAR);
					if (r != SQL_SUCCESS && r != SQL_SUCCESS_WITH_INFO)
					{
						QString check = qWarnODBCHandle(SQL_HANDLE_DBC, hDbc);
						qCritical(category) <<  check;
						m_bIsOpen = false;
					}
					m_bIsOpen = true;
				}
			} break;
		case Target:
			{
				SQLHANDLE hEnv = SQL_NULL_HANDLE;
				SQLHANDLE hDbc = SQL_NULL_HANDLE;
				r = ::SQLAllocHandle(SQL_HANDLE_ENV, SQL_NULL_HANDLE, &hEnv);
				if (r == SQL_SUCCESS) isValid = true;

				foreach(nOdbcAttributesClass * k, this->m_OdbcAttributes_Map)
				{
					if (k->attributeType == enumAttributeType::hEnv)
					{
						r = ::SQLSetEnvAttr(hEnv, (SQLINTEGER) k->odbcKey, (SQLPOINTER)k->odbcValue, 0);
						if (r == SQL_SUCCESS) isValid = true;
					}
				}
				hEnv_Target = hEnv;

				r = SQLAllocHandle(SQL_HANDLE_DBC, hEnv, &hDbc);
				if (r == SQL_SUCCESS) isValid = true;
				foreach(nOdbcAttributesClass * k, this->m_OdbcAttributes_Map)
				{
				if (k->attributeType == enumAttributeType::hDbc)
					{
					r = ::SQLSetConnectAttr(hDbc, k->odbcKey, (SQLPOINTER)k->odbcValue, 0);
					if (k->odbcKey == SQL_ATTR_CONNECTION_POOLING && k->odbcValue == SQL_CP_ONE_PER_DRIVER) wConnectOption = SQL_DRIVER_NOPROMPT;
					if (k->odbcKey == SQL_ATTR_CONNECTION_POOLING && k->odbcValue == SQL_CP_ONE_PER_HENV) wConnectOption = SQL_DRIVER_NOPROMPT;
					if (k->odbcKey == SQL_ATTR_CONNECTION_POOLING && k->odbcValue == SQL_CP_DRIVER_AWARE) wConnectOption = SQL_DRIVER_NOPROMPT;
					if (r == SQL_SUCCESS) isValid = true;
					}
				}
				hDbc_target = hDbc;
				if (isValid) {
					r = ::SQLDriverConnect(
						hDbc,
						hWnd,
#ifdef UNICODE
						toSQLTCHAR(m_lpszTargetDSN).data(),
#else
						(SQLCHAR*)m_lpszTargetDSN.toUtf8().data(),
#endif
						(SQLSMALLINT)m_lpszTargetDSN.length(),
						connOut.data(),
						1024,
						&cb, 
						wConnectOption); 
						int colSize = cb / sizeof(SQLTCHAR);
					if (r != SQL_SUCCESS && r != SQL_SUCCESS_WITH_INFO)
						{
							QString check = qWarnODBCHandle(SQL_HANDLE_DBC, hDbc);
							qCritical(category) <<  check;
							m_bIsOpen = false;
						}
							m_bIsOpen = true;
					}
			} break;
			default: break;
	}
}
TK_UPRTULSTSET::TK_UPRTULSTSET(QObject * parent) : QObject(parent) 
,tableName("TK_UPRTULSTSET")
,m_dropOption(DropOption::DropTable) { 
	numRowsFetched = 0;
}

#pragma region ~CTOR TK_UPRTULSTSET 
TK_UPRTULSTSET::~TK_UPRTULSTSET() { 

#pragma region Buffers - Clear 
	DB_ID.clear();
	NVTIMESTAMP.clear();
	OAREA.clear();
	OPAGE.clear();
	OLINE.clear();
	MAREA.clear();
	MPAGE.clear();
	MLINE.clear();
#pragma endregion Buffers - Clear 
}
#pragma endregion Destructor_TK_UPRTULSTSET

// begin method functions
void TK_UPRTULSTSET::setAbortFlag() { 
	QLoggingCategory category("classLibQ");
	qCInfo(category) << "isAbort was set to True";
	bIsAbort = true;
}

void TK_UPRTULSTSET::run() { 
	process(1);
	QLoggingCategory category("classLibQ");
	qDebug(category) << "Entered;";
}

void	TK_UPRTULSTSET::initOdbcAttributes()
{
	QLoggingCategory category("classLibQ");
	this->setProfileName(profileName);
	qDebug(category) << "Processing - TRKDB100"; 
	m_OdbcAttributesList = m_OdbcAttributes.split(","); 
	foreach(QString m, m_OdbcAttributesList)
	{
		QStringList keyValue = m.split("=");
		nOdbcAttributesClass * oM = new nOdbcAttributesClass(this);
		if (oM->loadToOdbc(keyValue.value(0), keyValue.value(1)))
		{
			m_OdbcAttributes_Map.insert(oM->odbcKey, oM);
		}
	}
}
void	TK_UPRTULSTSET::initialize()
{
	QLoggingCategory category("classLibQ");
	RETCODE r;
	this->setProfileName(profileName);
	qDebug(category) << "Processing - TRKDB100"; 
//SQL Statements
//--------------------------------------------------

#pragma region Sql Statements_TK_UPRTULSTSET

	fetchSql = "select  DB_ID, NVTIMESTAMP, OAREA, OPAGE, OLINE, MAREA, MPAGE, MLINE from TK_UPRTULSTSET";
		if (m_ReplicationOption == ReplicationOption::NetChange)
		{
			fetchSql.append(" p1, nv_transfers p2 WHERE  p2.table_name = 'TK_UPRTULSTSET' AND p1.nvtimestamp > p2.last_completed");
		}
	insertSql = "insert into TK_UPRTULSTSET ( PLANT_CODE, NVTIMESTAMP, OAREA, OPAGE, OLINE, MAREA, MPAGE, MLINE ) values ( ?, ?, ?, ?, ?, ?, ?, ?)";
	updateSql = "update TK_UPRTULSTSET set  PLANT_CODE = ?, NVTIMESTAMP = ?, OAREA = ?, OPAGE = ?, OLINE = ?, MAREA = ?, MPAGE = ?, MLINE = ?  where area = ? and page = ? line = ? ";

	qDebug(category) << "insertSQL - insert into TK_UPRTULSTSET ( PLANT_CODE, NVTIMESTAMP, OAREA, OPAGE, OLINE, MAREA, MPAGE, MLINE ) values ( ?, ?, ?, ?, ?, ?, ?, ?)";
	qDebug(category) << "fetchSQL - select  DB_ID, NVTIMESTAMP, OAREA, OPAGE, OLINE, MAREA, MPAGE, MLINE from TK_UPRTULSTSET";
	qDebug(category) << "unsertSQL - update TK_UPRTULSTSET set  PLANT_CODE = ?, NVTIMESTAMP = ?, OAREA = ?, OPAGE = ?, OLINE = ?, MAREA = ?, MPAGE = ?, MLINE = ?  where area = ? and page = ? line = ? ";

#pragma endregion Sql Statements_TK_UPRTULSTSET
	SQLHANDLE		insert_hStmt = SQL_NULL_HANDLE;
	SQLHANDLE		fetch_hStmt = SQL_NULL_HANDLE; 
	SQLHANDLE		update_hStmt = SQL_NULL_HANDLE; 
 
	r = ::SQLAllocHandle(SQL_HANDLE_STMT, hDbc_source, &fetch_hStmt);
	if (r != SQL_SUCCESS) {
		 qCCritical(category) << QString("Error  hDbc_Source SQLCode : %1 is %2").arg(QString::number( (long)hDbc_source)).arg(QString::number(r));
		return; 
	}
	r = ::SQLAllocHandle(SQL_HANDLE_STMT, hDbc_target, &insert_hStmt);
	if (r != SQL_SUCCESS) {
		 qCCritical(category) << QString("Error hDbc_Source -SQLCode: %1 is %2").arg(QString::number( (long)hDbc_target)).arg(QString::number(r));
		return; 
	}
	r = ::SQLAllocHandle(SQL_HANDLE_STMT, hDbc_target, &update_hStmt);
	if (r != SQL_SUCCESS) {
		 qCCritical(category) << QString("Error hDbc_Source +SQLCode: %1 is %2").arg(QString::number( (long)hDbc_target)).arg(QString::number(r));
		return; 
	}
 
	hStmt_Fetch = fetch_hStmt;
	hStmt_Insert = insert_hStmt;
	hStmt_Update = update_hStmt;
 
	SQLSetStmtAttr(hStmt_Fetch, SQL_ATTR_USE_BOOKMARKS, (SQLPOINTER)SQL_UB_OFF, 0);
	SQLSetStmtAttr(hStmt_Fetch, SQL_ATTR_ROW_BIND_TYPE, (SQLPOINTER)SQL_BIND_BY_COLUMN, 0);
	SQLSetStmtAttr(hStmt_Fetch, SQL_ATTR_ROW_ARRAY_SIZE, (SQLPOINTER)1, 0);
	SQLSetStmtAttr(hStmt_Fetch, SQL_ATTR_ROWS_FETCHED_PTR, &numRowsFetched, 0);

// Fields used by this class 
// ---------------------------------------------------

#pragma region Resize Fields TK_UPRTULSTSET
	qDebug(category) << "Malloc - DB_ID[2]";
	DB_ID.resize(2);
	qDebug(category) << "Malloc - NVTIMESTAMP[23]";
	NVTIMESTAMP.resize(23);
	qDebug(category) << "Malloc - OAREA[2]";
	OAREA.resize(2);
	qDebug(category) << "Malloc - OPAGE[4]";
	OPAGE.resize(4);
	qDebug(category) << "Malloc - OLINE[2]";
	OLINE.resize(2);
	qDebug(category) << "Malloc - MAREA[2]";
	MAREA.resize(2);
	qDebug(category) << "Malloc - MPAGE[4]";
	MPAGE.resize(4);
	qDebug(category) << "Malloc - MLINE[2]";
	MLINE.resize(2);

#pragma endregion Resize Fields TK_UPRTULSTSET
}
void TK_UPRTULSTSET::close()
{
	QLoggingCategory category("classLibQ");
	if (m_bIsOpen)
	{
	qDebug(category) << "database is Open";
		SQLHANDLE source_hStmt = hStmt_Fetch;
		SQLHANDLE insert_hStmt = hStmt_Insert;
		SQLHANDLE hDb_S = this->hDbc_source;
		SQLHANDLE hDb_T = hDbc_target;
		SQLHANDLE hEnvS = hEnv_Source;
		SQLHANDLE hEnvT = hEnv_Target;
		RETCODE r;

		r = ::SQLFreeHandle(SQL_HANDLE_STMT, hStmt_Fetch);
		r = ::SQLFreeHandle(SQL_HANDLE_STMT, hStmt_Insert);
		r = ::SQLFreeHandle(SQL_HANDLE_STMT, hStmt_Update);
		if (hDbc_source != SQL_NULL_HANDLE) 		r = ::SQLDisconnect(hDb_S);
		if (hDbc_target != SQL_NULL_HANDLE) 		r = ::SQLDisconnect(hDb_T);

		r = ::SQLFreeHandle(SQL_HANDLE_DBC, hDb_S);
		r = ::SQLFreeHandle(SQL_HANDLE_DBC, hDb_T);
		r = ::SQLFreeHandle(SQL_HANDLE_ENV, hEnvS);
		r = ::SQLFreeHandle(SQL_HANDLE_ENV, hEnvT);
	}

	hEnv_Source = SQL_NULL_HANDLE;
	hEnv_Target = SQL_NULL_HANDLE;
	hEnv_Source = SQL_NULL_HANDLE;
	hEnv_Target = SQL_NULL_HANDLE;
	hStmt_Fetch = SQL_NULL_HANDLE;
	hStmt_Insert = SQL_NULL_HANDLE;
	hStmt_Update = SQL_NULL_HANDLE;
}

void TK_UPRTULSTSET::open(const QString sourceDSN, const QString targetDSN)
{
	QLoggingCategory category("classLibQ");
	m_lpszTargetDSN = targetDSN;
	m_lpszSourceDSN = sourceDSN;
	qDebug(category) << QString("Source - %1[%2]").arg(sourceDSN);
	qDebug(category) << QString("Target - %1[%2]").arg(targetDSN);
}

void TK_UPRTULSTSET::createTable()
{
	QLoggingCategory category("classLibQ");
	{
		QScopedPointer<nvTableOracleRdb> tbl(new nvTableOracleRdb(nullptr));
		tbl->initialize("TK_UPRTULSTSET", this->m_lpszSourceDSN);
		QString newTbl = tbl->getCreateTableSQL();
		QScopedPointer<qVtExecute> vExec(new qVtExecute(nullptr));
		{
			vExec->initialize(m_lpszTargetDSN, " ", true);
			vExec->setOdbcAttributes(m_OdbcAttributes);
			vExec->ExecuteDirect(newTbl);
		}
	 qDebug(category) << QString("End Create Table %1 ").arg(tableName); 
	}
}

bool TK_UPRTULSTSET::prepare()
{
	RETCODE r;
	QString check;
	QLoggingCategory category("classLibQ");
	 qDebug(category) << fetchSql;
	 qDebug(category) << insertSql;
#ifdef UNICODE
	r = SQLPrepare(hStmt_Insert,toSQLTCHAR(insertSql).data(),(SQLINTEGER)insertSql.length()); 
	if (r != SQL_SUCCESS) {
		check = qWarnODBCHandle(SQL_HANDLE_STMT, hStmt_Insert);
		 qCCritical(category) << QString("Prepare Statement-Insert : %1 is %2").arg(insertSql).arg(check);
		return false; 
	}
	r = SQLPrepare(hStmt_Update,toSQLTCHAR(updateSql).data(),(SQLINTEGER)updateSql.length()); 
	if (r != SQL_SUCCESS) {
		check = qWarnODBCHandle(SQL_HANDLE_STMT, hStmt_Update);
		 qCCritical(category) << QString("Prepare Statement-Update : %1 is %2").arg(updateSql).arg(check);
		return false; 
	}
	r = SQLPrepare(hStmt_Fetch,toSQLTCHAR(fetchSql).data(),(SQLINTEGER)fetchSql.length());
	if (r != SQL_SUCCESS) {
		check = qWarnODBCHandle(SQL_HANDLE_STMT, hStmt_Fetch);
		 qCCritical(category) << QString("Prepare Statement-Insert : %1 is %2").arg(fetchSql).arg(check);
		return false; 
	}
#else
	QByteArray queryI8 = insertSql.toUtf8();
	r = SQLPrepare(insert_hStmt,SQLCHAR*)queryI8.data(),(SQLINTEGER)queryI8.length());
	QByteArray queryU8 = fetchSql.toUtf8();
	r = SQLPrepare(hStmt_Fetch,(SQLCHAR*)queryU8.data(),(SQLINTEGER)queryU8.length());
#endif
	return true;

}

void TK_UPRTULSTSET::prepareTargetTable()
{
	QLoggingCategory category("classLibQ");
	if (this->m_ReplicationOption == ReplicationOption::BulkCopy)
	{
		QScopedPointer<qVtExecute> execSql(new qVtExecute(nullptr));
		DropOption option = this->m_dropOption;
		switch (option)
		{
			case DropOption::DeleteFromTable:
			{
				QLoggingCategory category("classLibQ");
				execSql->initialize(this->m_lpszTargetDSN, "delete from TK_UPRTULSTSET", true);
				execSql->setOdbcAttributes(this->m_OdbcAttributes);
				execSql->ExecuteDirect("delete from TK_UPRTULSTSET");
			}break;
			case DropOption::TruncateTable:
			{
				execSql->initialize(this->m_lpszTargetDSN, "truncate table TK_UPRTULSTSET", true);
				execSql->setOdbcAttributes(this->m_OdbcAttributes);
				execSql->ExecuteDirect("truncate table TK_UPRTULSTSET");
			}break;
			case DropOption::DropTable:
			{
				execSql->initialize(this->m_lpszTargetDSN, "drop table TK_UPRTULSTSET", true);
				execSql->setOdbcAttributes(this->m_OdbcAttributes);
				execSql->ExecuteDirect("drop table TK_UPRTULSTSET");
				createTable();
			}break;
		}
	}
}

bool TK_UPRTULSTSET::bindColumn()
{
	QLoggingCategory category("classLibQ");
	RETCODE r;
	bool isValid=true;
		 qDebug(category) << " Bindings: Ordinal [1] Type: 5 Buffer Size: 2 FieldName: DB_ID ";
		r = ::SQLBindCol(hStmt_Fetch, 1, 5, DB_ID.data(), 2, &cbDB_ID);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Bindings: Ordinal [2] Type: 93 Buffer Size: 23 FieldName: NVTIMESTAMP ";
		r = ::SQLBindCol(hStmt_Fetch, 2, 93, NVTIMESTAMP.data(), 23, &cbNVTIMESTAMP);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Bindings: Ordinal [3] Type: 5 Buffer Size: 2 FieldName: OAREA ";
		r = ::SQLBindCol(hStmt_Fetch, 3, 5, OAREA.data(), 2, &cbOAREA);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Bindings: Ordinal [4] Type: 4 Buffer Size: 4 FieldName: OPAGE ";
		r = ::SQLBindCol(hStmt_Fetch, 4, 4, OPAGE.data(), 4, &cbOPAGE);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Bindings: Ordinal [5] Type: 5 Buffer Size: 2 FieldName: OLINE ";
		r = ::SQLBindCol(hStmt_Fetch, 5, 5, OLINE.data(), 2, &cbOLINE);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Bindings: Ordinal [6] Type: 5 Buffer Size: 2 FieldName: MAREA ";
		r = ::SQLBindCol(hStmt_Fetch, 6, 5, MAREA.data(), 2, &cbMAREA);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Bindings: Ordinal [7] Type: 4 Buffer Size: 4 FieldName: MPAGE ";
		r = ::SQLBindCol(hStmt_Fetch, 7, 4, MPAGE.data(), 4, &cbMPAGE);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Bindings: Ordinal [8] Type: 5 Buffer Size: 2 FieldName: MLINE ";
		r = ::SQLBindCol(hStmt_Fetch, 8, 5, MLINE.data(), 2, &cbMLINE);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
	return isValid;
}

bool TK_UPRTULSTSET::bindParameter()
{
	QLoggingCategory category("classLibQ");
	RETCODE r;
	bool isValid=true;
	{
		 qDebug(category) << " Parameters: Ordinal [1] Type: 5 Buffer Size: 2 FieldName: DB_ID ";
		r = SQLBindParameter(hStmt_Insert, 1, SQL_PARAM_INPUT, SQL_C_DEFAULT, 5, 0, 0, (SQLPOINTER)DB_ID.constData(), 0, &cbDB_ID);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Parameters: Ordinal [2] Type: 93 Buffer Size: 23 FieldName: NVTIMESTAMP ";
		r = SQLBindParameter(hStmt_Insert, 2, SQL_PARAM_INPUT, SQL_C_DEFAULT, 93, 23, 0, (SQLPOINTER)NVTIMESTAMP.constData(), 0, &cbNVTIMESTAMP);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Parameters: Ordinal [3] Type: 5 Buffer Size: 2 FieldName: OAREA ";
		r = SQLBindParameter(hStmt_Insert, 3, SQL_PARAM_INPUT, SQL_C_DEFAULT, 5, 0, 0, (SQLPOINTER)OAREA.constData(), 0, &cbOAREA);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Parameters: Ordinal [4] Type: 4 Buffer Size: 4 FieldName: OPAGE ";
		r = SQLBindParameter(hStmt_Insert, 4, SQL_PARAM_INPUT, SQL_C_DEFAULT, 4, 0, 0, (SQLPOINTER)OPAGE.constData(), 0, &cbOPAGE);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Parameters: Ordinal [5] Type: 5 Buffer Size: 2 FieldName: OLINE ";
		r = SQLBindParameter(hStmt_Insert, 5, SQL_PARAM_INPUT, SQL_C_DEFAULT, 5, 0, 0, (SQLPOINTER)OLINE.constData(), 0, &cbOLINE);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Parameters: Ordinal [6] Type: 5 Buffer Size: 2 FieldName: MAREA ";
		r = SQLBindParameter(hStmt_Insert, 6, SQL_PARAM_INPUT, SQL_C_DEFAULT, 5, 0, 0, (SQLPOINTER)MAREA.constData(), 0, &cbMAREA);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Parameters: Ordinal [7] Type: 4 Buffer Size: 4 FieldName: MPAGE ";
		r = SQLBindParameter(hStmt_Insert, 7, SQL_PARAM_INPUT, SQL_C_DEFAULT, 4, 0, 0, (SQLPOINTER)MPAGE.constData(), 0, &cbMPAGE);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Parameters: Ordinal [8] Type: 5 Buffer Size: 2 FieldName: MLINE ";
		r = SQLBindParameter(hStmt_Insert, 8, SQL_PARAM_INPUT, SQL_C_DEFAULT, 5, 0, 0, (SQLPOINTER)MLINE.constData(), 0, &cbMLINE);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
	}
	if (m_ReplicationOption == ReplicationOption::NetChange)
	{
		r = SQLBindParameter(hStmt_Update, 9, SQL_PARAM_INPUT, SQL_C_DEFAULT, 6, 0, 0, (SQLPOINTER)MAREA.constData(), 0, &cbMAREA);
		if (r == SQL_SUCCESS) { isValid=true; }
		r = SQLBindParameter(hStmt_Update, 10, SQL_PARAM_INPUT, SQL_C_DEFAULT, 7, 0, 0, (SQLPOINTER)MPAGE.constData(), 0, &cbMPAGE);
		if (r == SQL_SUCCESS) { isValid=true; }
		r = SQLBindParameter(hStmt_Update, 11, SQL_PARAM_INPUT, SQL_C_DEFAULT, 8, 0, 0, (SQLPOINTER)MLINE.constData(), 0, &cbMLINE);
		if (r == SQL_SUCCESS) { isValid=true; }
	// TK_UPRTULSTSET is a well formed table for eNVy Replication 
		 qDebug(category) << " Parameters: Ordinal [6] 00 00 FieldName: MAREA ";
		 qDebug(category) << " Parameters: Ordinal [7] 00 00  FieldName: MPAGE ";
		 qDebug(category) << " Parameters: Ordinal [8] 00 00 FieldName:  MLINE ";
	} // 	if (m_ReplicationOption == ReplicationOption::NetChange)
	return isValid;
}

bool TK_UPRTULSTSET::process(int rowSize)
{
	QLoggingCategory category("classLibQ");
	initOdbcAttributes();
	connect(Source);
	connect(Target);
	initialize();
	prepareTargetTable();
	prepare();
	bindColumn();
	bindParameter();
	copyTable();
	close();
	return false;
}

void TK_UPRTULSTSET::copyTable()
{
	QLoggingCategory category("classLibQ");
	RETCODE r;
	QString check;
	r = SQLExecute(hStmt_Fetch);
		if (bIsAbort) {
			emit aborted(tableName, rowsFetched, rowsInserted, rowsUpdated);
			return;
		}
		while((r = SQLFetch(hStmt_Fetch)) != SQL_NO_DATA) {
		if (r != SQL_SUCCESS) {
			check = qWarnODBCHandle(SQL_HANDLE_STMT, hStmt_Fetch);
			qCCritical(category) << QString("SqlFetch - Error : %1 is %2").arg(fetchSql).arg(check);
			return;
		} 
		rowsFetched++;
		if (m_ReplicationOption == ReplicationOption::BulkCopy)
		{
			r = SQLExecute(hStmt_Insert);
			if (r == SQL_ERROR) {
				check = qWarnODBCHandle(SQL_HANDLE_STMT, hStmt_Insert);
				 qCCritical(category) << QString("SqlExecute:Insert - Error : %1 is %2").arg(insertSql).arg(check);
				return;
			}
			rowsInserted++;
			if ((rowsFetched % updateInterval) == 0) {
				qCInfo(category) << QString("[%1.%2]	Insertion: %3	Updates : %4	Fetched : %5").arg(profileName).arg(tableName).arg(rowsInserted).arg(rowsUpdated).arg(rowsFetched);
				emit updateStatusFetched(profileName, tableName, rowsFetched,rowsInserted,rowsUpdated);
			}
			if (m_ReplicationOption == ReplicationOption::NetChange)
			{
			r = SQLExecute(hStmt_Update);
			if (r != SQL_SUCCESS) {
				check = qWarnODBCHandle(SQL_HANDLE_STMT, hStmt_Update);
				 qCInfo(category)  << QString("SqlExecute:Update - Error : %1 is %2").arg(updateSql).arg(check);
				r = SQLExecute(hStmt_Insert);
				if (r != SQL_SUCCESS) {
					check = qWarnODBCHandle(SQL_HANDLE_STMT, hStmt_Insert);
					 qCritical(category) << QString("SqlExecute:Insert - Error : %1 is %2").arg(insertSql).arg(check);
					return;
				}
				else 	rowsInserted++;
				}
				else	rowsUpdated++;
			}
			emit updateStatusFetched(profileName, tableName, rowsFetched,rowsInserted,rowsUpdated);
		}
	} 
qCInfo(category) << QString("[%1.%2]	Insertion: %3	Updates : %4	Fetched : %5").arg(profileName).arg(tableName).arg(rowsInserted).arg(rowsUpdated).arg(rowsFetched);
}

void TK_UPRTULSTSET::connect(connectionHandle connectionSource)
{

	QLoggingCategory category("classLibQ");
	RETCODE r;

	bool isValid = false;
	HWND	hWnd = nullptr;
	hWnd = ::GetDesktopWindow(); 
	SQLSMALLINT nResult = 0;

	SQLSMALLINT cb;
	UWORD wConnectOption = SQL_DRIVER_COMPLETE; //SQL_DRIVER_NOPROMPT;
	QVarLengthArray<SQLTCHAR> connOut(1024);
	memset(connOut.data(), 0, connOut.size() * sizeof(SQLTCHAR));

	switch (connectionSource)
	{
		case Source:
			{// environment
				SQLHANDLE hEnv = SQL_NULL_HANDLE;
				SQLHANDLE hDbc = SQL_NULL_HANDLE;
				r = ::SQLAllocHandle(SQL_HANDLE_ENV, SQL_NULL_HANDLE, &hEnv);
				if (r == SQL_SUCCESS) isValid = true;

				foreach(nOdbcAttributesClass * k, this->m_OdbcAttributes_Map)
				{
					if (k->attributeType == enumAttributeType::hEnv)
					{
						r = ::SQLSetEnvAttr(hEnv, (SQLINTEGER) k->odbcKey, (SQLPOINTER)k->odbcValue, 0);
						if (r == SQL_SUCCESS) isValid = true;
					}
				}
				hEnv_Source = hEnv;

				r = SQLAllocHandle(SQL_HANDLE_DBC, hEnv, &hDbc);
				if (r == SQL_SUCCESS) isValid = true;
				foreach(nOdbcAttributesClass * k, this->m_OdbcAttributes_Map)
				{
					if (k->attributeType == enumAttributeType::hDbc)
					{
					r = ::SQLSetConnectAttr(hDbc, k->odbcKey, (SQLPOINTER)k->odbcValue, 0);
					if (k->odbcKey == SQL_ATTR_CONNECTION_POOLING && k->odbcValue == SQL_CP_ONE_PER_DRIVER) wConnectOption = SQL_DRIVER_NOPROMPT;
					if (k->odbcKey == SQL_ATTR_CONNECTION_POOLING && k->odbcValue == SQL_CP_ONE_PER_HENV) wConnectOption = SQL_DRIVER_NOPROMPT;
					if (k->odbcKey == SQL_ATTR_CONNECTION_POOLING && k->odbcValue == SQL_CP_DRIVER_AWARE) wConnectOption = SQL_DRIVER_NOPROMPT;
					if (r == SQL_SUCCESS) isValid = true;
					}
				}
				hDbc_source = hDbc;
				if (isValid)
				{
					r = ::SQLDriverConnect(
						hDbc,
						hWnd,
#ifdef UNICODE
						toSQLTCHAR(m_lpszSourceDSN).data(),
#else
						(SQLCHAR*)dsnSource.toUtf8().data(),
#endif
						(SQLSMALLINT)m_lpszSourceDSN.length(),
						connOut.data(),
						1024,
						&cb, 
						wConnectOption); 
					int colSize = cb / sizeof(SQLTCHAR);
					if (r != SQL_SUCCESS && r != SQL_SUCCESS_WITH_INFO)
					{
						QString check = qWarnODBCHandle(SQL_HANDLE_DBC, hDbc);
						qCritical(category) <<  check;
						m_bIsOpen = false;
					}
					m_bIsOpen = true;
				}
			} break;
		case Target:
			{
				SQLHANDLE hEnv = SQL_NULL_HANDLE;
				SQLHANDLE hDbc = SQL_NULL_HANDLE;
				r = ::SQLAllocHandle(SQL_HANDLE_ENV, SQL_NULL_HANDLE, &hEnv);
				if (r == SQL_SUCCESS) isValid = true;

				foreach(nOdbcAttributesClass * k, this->m_OdbcAttributes_Map)
				{
					if (k->attributeType == enumAttributeType::hEnv)
					{
						r = ::SQLSetEnvAttr(hEnv, (SQLINTEGER) k->odbcKey, (SQLPOINTER)k->odbcValue, 0);
						if (r == SQL_SUCCESS) isValid = true;
					}
				}
				hEnv_Target = hEnv;

				r = SQLAllocHandle(SQL_HANDLE_DBC, hEnv, &hDbc);
				if (r == SQL_SUCCESS) isValid = true;
				foreach(nOdbcAttributesClass * k, this->m_OdbcAttributes_Map)
				{
				if (k->attributeType == enumAttributeType::hDbc)
					{
					r = ::SQLSetConnectAttr(hDbc, k->odbcKey, (SQLPOINTER)k->odbcValue, 0);
					if (k->odbcKey == SQL_ATTR_CONNECTION_POOLING && k->odbcValue == SQL_CP_ONE_PER_DRIVER) wConnectOption = SQL_DRIVER_NOPROMPT;
					if (k->odbcKey == SQL_ATTR_CONNECTION_POOLING && k->odbcValue == SQL_CP_ONE_PER_HENV) wConnectOption = SQL_DRIVER_NOPROMPT;
					if (k->odbcKey == SQL_ATTR_CONNECTION_POOLING && k->odbcValue == SQL_CP_DRIVER_AWARE) wConnectOption = SQL_DRIVER_NOPROMPT;
					if (r == SQL_SUCCESS) isValid = true;
					}
				}
				hDbc_target = hDbc;
				if (isValid) {
					r = ::SQLDriverConnect(
						hDbc,
						hWnd,
#ifdef UNICODE
						toSQLTCHAR(m_lpszTargetDSN).data(),
#else
						(SQLCHAR*)m_lpszTargetDSN.toUtf8().data(),
#endif
						(SQLSMALLINT)m_lpszTargetDSN.length(),
						connOut.data(),
						1024,
						&cb, 
						wConnectOption); 
						int colSize = cb / sizeof(SQLTCHAR);
					if (r != SQL_SUCCESS && r != SQL_SUCCESS_WITH_INFO)
						{
							QString check = qWarnODBCHandle(SQL_HANDLE_DBC, hDbc);
							qCritical(category) <<  check;
							m_bIsOpen = false;
						}
							m_bIsOpen = true;
					}
			} break;
			default: break;
	}
}
TK_LIDREC::TK_LIDREC(QObject * parent) : QObject(parent) 
,tableName("TK_LIDREC")
,m_dropOption(DropOption::DropTable) { 
	numRowsFetched = 0;
}

#pragma region ~CTOR TK_LIDREC 
TK_LIDREC::~TK_LIDREC() { 

#pragma region Buffers - Clear 
	DB_ID.clear();
	NVTIMESTAMP.clear();
	AREA.clear();
	PAGE.clear();
	LINE.clear();
	TK_LIDLOT.clear();
	TK_LIDPRT.clear();
	TK_LIDLOTDESC.clear();
	TK_LIDPRTDESC.clear();
	TK_LIDPRTREV.clear();
	TK_LIDPRTSC.clear();
	TK_LIDPRTUOM.clear();
	TK_LIDACCCODE.clear();
	TK_LIDACCTYPE.clear();
	TK_LIDEXPDAT.clear();
	QTY.clear();
	TK_LIDISSQTY.clear();
	TK_LIDSCRPQTY.clear();
	TK_LIDRTVQTY.clear();
	TK_LIDCRDAT.clear();
	TK_LIDISSDAT.clear();
	DAT.clear();
	TK_LIDARCDAT.clear();
	TK_LIDARCISSQTY.clear();
	TK_LIDARCRECQTY.clear();
	TK_LIDUSRFLD1.clear();
	TK_LIDUSRFLD2.clear();
	TK_LIDUSRFLD3.clear();
	TK_LIDUSRFLD4.clear();
	TK_LIDARCCODDESC.clear();
	TK_LIDPOT.clear();
	TK_LIDMUQ.clear();
	TK_LIDLOTUOM.clear();
	TK_LIDACTCOD1.clear();
	TK_LIDACTDAT1.clear();
	TK_LIDACTCOD2.clear();
	TK_LIDACTDAT2.clear();
	TK_LOTNO.clear();
	TK_PRTNO.clear();
#pragma endregion Buffers - Clear 
}
#pragma endregion Destructor_TK_LIDREC

// begin method functions
void TK_LIDREC::setAbortFlag() { 
	QLoggingCategory category("classLibQ");
	qCInfo(category) << "isAbort was set to True";
	bIsAbort = true;
}

void TK_LIDREC::run() { 
	process(1);
	QLoggingCategory category("classLibQ");
	qDebug(category) << "Entered;";
}

void	TK_LIDREC::initOdbcAttributes()
{
	QLoggingCategory category("classLibQ");
	this->setProfileName(profileName);
	qDebug(category) << "Processing - TRKDB100"; 
	m_OdbcAttributesList = m_OdbcAttributes.split(","); 
	foreach(QString m, m_OdbcAttributesList)
	{
		QStringList keyValue = m.split("=");
		nOdbcAttributesClass * oM = new nOdbcAttributesClass(this);
		if (oM->loadToOdbc(keyValue.value(0), keyValue.value(1)))
		{
			m_OdbcAttributes_Map.insert(oM->odbcKey, oM);
		}
	}
}
void	TK_LIDREC::initialize()
{
	QLoggingCategory category("classLibQ");
	RETCODE r;
	this->setProfileName(profileName);
	qDebug(category) << "Processing - TRKDB100"; 
//SQL Statements
//--------------------------------------------------

#pragma region Sql Statements_TK_LIDREC

	fetchSql = "select  DB_ID, NVTIMESTAMP, AREA, PAGE, LINE, TK_LIDLOT, TK_LIDPRT, TK_LIDLOTDESC, TK_LIDPRTDESC, TK_LIDPRTREV, TK_LIDPRTSC, TK_LIDPRTUOM, TK_LIDACCCODE, TK_LIDACCTYPE, TK_LIDEXPDAT, QTY, TK_LIDISSQTY, TK_LIDSCRPQTY, TK_LIDRTVQTY, TK_LIDCRDAT, TK_LIDISSDAT, DAT, TK_LIDARCDAT, TK_LIDARCISSQTY, TK_LIDARCRECQTY, TK_LIDUSRFLD1, TK_LIDUSRFLD2, TK_LIDUSRFLD3, TK_LIDUSRFLD4, TK_LIDARCCODDESC, TK_LIDPOT, TK_LIDMUQ, TK_LIDLOTUOM, TK_LIDACTCOD1, TK_LIDACTDAT1, TK_LIDACTCOD2, TK_LIDACTDAT2, TK_LOTNO, TK_PRTNO from TK_LIDREC";
		if (m_ReplicationOption == ReplicationOption::NetChange)
		{
			fetchSql.append(" p1, nv_transfers p2 WHERE  p2.table_name = 'TK_LIDREC' AND p1.nvtimestamp > p2.last_completed");
		}
	insertSql = "insert into TK_LIDREC ( PLANT_CODE, NVTIMESTAMP, AREA, PAGE, LINE, TK_LIDLOT, TK_LIDPRT, TK_LIDLOTDESC, TK_LIDPRTDESC, TK_LIDPRTREV, TK_LIDPRTSC, TK_LIDPRTUOM, TK_LIDACCCODE, TK_LIDACCTYPE, TK_LIDEXPDAT, QTY, TK_LIDISSQTY, TK_LIDSCRPQTY, TK_LIDRTVQTY, TK_LIDCRDAT, TK_LIDISSDAT, DAT, TK_LIDARCDAT, TK_LIDARCISSQTY, TK_LIDARCRECQTY, TK_LIDUSRFLD1, TK_LIDUSRFLD2, TK_LIDUSRFLD3, TK_LIDUSRFLD4, TK_LIDARCCODDESC, TK_LIDPOT, TK_LIDMUQ, TK_LIDLOTUOM, TK_LIDACTCOD1, TK_LIDACTDAT1, TK_LIDACTCOD2, TK_LIDACTDAT2, TK_LOTNO, TK_PRTNO ) values ( ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?)";
	updateSql = "update TK_LIDREC set  PLANT_CODE = ?, NVTIMESTAMP = ?, AREA = ?, PAGE = ?, LINE = ?, TK_LIDLOT = ?, TK_LIDPRT = ?, TK_LIDLOTDESC = ?, TK_LIDPRTDESC = ?, TK_LIDPRTREV = ?, TK_LIDPRTSC = ?, TK_LIDPRTUOM = ?, TK_LIDACCCODE = ?, TK_LIDACCTYPE = ?, TK_LIDEXPDAT = ?, QTY = ?, TK_LIDISSQTY = ?, TK_LIDSCRPQTY = ?, TK_LIDRTVQTY = ?, TK_LIDCRDAT = ?, TK_LIDISSDAT = ?, DAT = ?, TK_LIDARCDAT = ?, TK_LIDARCISSQTY = ?, TK_LIDARCRECQTY = ?, TK_LIDUSRFLD1 = ?, TK_LIDUSRFLD2 = ?, TK_LIDUSRFLD3 = ?, TK_LIDUSRFLD4 = ?, TK_LIDARCCODDESC = ?, TK_LIDPOT = ?, TK_LIDMUQ = ?, TK_LIDLOTUOM = ?, TK_LIDACTCOD1 = ?, TK_LIDACTDAT1 = ?, TK_LIDACTCOD2 = ?, TK_LIDACTDAT2 = ?, TK_LOTNO = ?, TK_PRTNO = ?  where area = ? and page = ? line = ? ";

	qDebug(category) << "insertSQL - insert into TK_LIDREC ( PLANT_CODE, NVTIMESTAMP, AREA, PAGE, LINE, TK_LIDLOT, TK_LIDPRT, TK_LIDLOTDESC, TK_LIDPRTDESC, TK_LIDPRTREV, TK_LIDPRTSC, TK_LIDPRTUOM, TK_LIDACCCODE, TK_LIDACCTYPE, TK_LIDEXPDAT, QTY, TK_LIDISSQTY, TK_LIDSCRPQTY, TK_LIDRTVQTY, TK_LIDCRDAT, TK_LIDISSDAT, DAT, TK_LIDARCDAT, TK_LIDARCISSQTY, TK_LIDARCRECQTY, TK_LIDUSRFLD1, TK_LIDUSRFLD2, TK_LIDUSRFLD3, TK_LIDUSRFLD4, TK_LIDARCCODDESC, TK_LIDPOT, TK_LIDMUQ, TK_LIDLOTUOM, TK_LIDACTCOD1, TK_LIDACTDAT1, TK_LIDACTCOD2, TK_LIDACTDAT2, TK_LOTNO, TK_PRTNO ) values ( ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?)";
	qDebug(category) << "fetchSQL - select  DB_ID, NVTIMESTAMP, AREA, PAGE, LINE, TK_LIDLOT, TK_LIDPRT, TK_LIDLOTDESC, TK_LIDPRTDESC, TK_LIDPRTREV, TK_LIDPRTSC, TK_LIDPRTUOM, TK_LIDACCCODE, TK_LIDACCTYPE, TK_LIDEXPDAT, QTY, TK_LIDISSQTY, TK_LIDSCRPQTY, TK_LIDRTVQTY, TK_LIDCRDAT, TK_LIDISSDAT, DAT, TK_LIDARCDAT, TK_LIDARCISSQTY, TK_LIDARCRECQTY, TK_LIDUSRFLD1, TK_LIDUSRFLD2, TK_LIDUSRFLD3, TK_LIDUSRFLD4, TK_LIDARCCODDESC, TK_LIDPOT, TK_LIDMUQ, TK_LIDLOTUOM, TK_LIDACTCOD1, TK_LIDACTDAT1, TK_LIDACTCOD2, TK_LIDACTDAT2, TK_LOTNO, TK_PRTNO from TK_LIDREC";
	qDebug(category) << "unsertSQL - update TK_LIDREC set  PLANT_CODE = ?, NVTIMESTAMP = ?, AREA = ?, PAGE = ?, LINE = ?, TK_LIDLOT = ?, TK_LIDPRT = ?, TK_LIDLOTDESC = ?, TK_LIDPRTDESC = ?, TK_LIDPRTREV = ?, TK_LIDPRTSC = ?, TK_LIDPRTUOM = ?, TK_LIDACCCODE = ?, TK_LIDACCTYPE = ?, TK_LIDEXPDAT = ?, QTY = ?, TK_LIDISSQTY = ?, TK_LIDSCRPQTY = ?, TK_LIDRTVQTY = ?, TK_LIDCRDAT = ?, TK_LIDISSDAT = ?, DAT = ?, TK_LIDARCDAT = ?, TK_LIDARCISSQTY = ?, TK_LIDARCRECQTY = ?, TK_LIDUSRFLD1 = ?, TK_LIDUSRFLD2 = ?, TK_LIDUSRFLD3 = ?, TK_LIDUSRFLD4 = ?, TK_LIDARCCODDESC = ?, TK_LIDPOT = ?, TK_LIDMUQ = ?, TK_LIDLOTUOM = ?, TK_LIDACTCOD1 = ?, TK_LIDACTDAT1 = ?, TK_LIDACTCOD2 = ?, TK_LIDACTDAT2 = ?, TK_LOTNO = ?, TK_PRTNO = ?  where area = ? and page = ? line = ? ";

#pragma endregion Sql Statements_TK_LIDREC
	SQLHANDLE		insert_hStmt = SQL_NULL_HANDLE;
	SQLHANDLE		fetch_hStmt = SQL_NULL_HANDLE; 
	SQLHANDLE		update_hStmt = SQL_NULL_HANDLE; 
 
	r = ::SQLAllocHandle(SQL_HANDLE_STMT, hDbc_source, &fetch_hStmt);
	if (r != SQL_SUCCESS) {
		 qCCritical(category) << QString("Error  hDbc_Source SQLCode : %1 is %2").arg(QString::number( (long)hDbc_source)).arg(QString::number(r));
		return; 
	}
	r = ::SQLAllocHandle(SQL_HANDLE_STMT, hDbc_target, &insert_hStmt);
	if (r != SQL_SUCCESS) {
		 qCCritical(category) << QString("Error hDbc_Source -SQLCode: %1 is %2").arg(QString::number( (long)hDbc_target)).arg(QString::number(r));
		return; 
	}
	r = ::SQLAllocHandle(SQL_HANDLE_STMT, hDbc_target, &update_hStmt);
	if (r != SQL_SUCCESS) {
		 qCCritical(category) << QString("Error hDbc_Source +SQLCode: %1 is %2").arg(QString::number( (long)hDbc_target)).arg(QString::number(r));
		return; 
	}
 
	hStmt_Fetch = fetch_hStmt;
	hStmt_Insert = insert_hStmt;
	hStmt_Update = update_hStmt;
 
	SQLSetStmtAttr(hStmt_Fetch, SQL_ATTR_USE_BOOKMARKS, (SQLPOINTER)SQL_UB_OFF, 0);
	SQLSetStmtAttr(hStmt_Fetch, SQL_ATTR_ROW_BIND_TYPE, (SQLPOINTER)SQL_BIND_BY_COLUMN, 0);
	SQLSetStmtAttr(hStmt_Fetch, SQL_ATTR_ROW_ARRAY_SIZE, (SQLPOINTER)1, 0);
	SQLSetStmtAttr(hStmt_Fetch, SQL_ATTR_ROWS_FETCHED_PTR, &numRowsFetched, 0);

// Fields used by this class 
// ---------------------------------------------------

#pragma region Resize Fields TK_LIDREC
	qDebug(category) << "Malloc - DB_ID[2]";
	DB_ID.resize(2);
	qDebug(category) << "Malloc - NVTIMESTAMP[23]";
	NVTIMESTAMP.resize(23);
	qDebug(category) << "Malloc - AREA[2]";
	AREA.resize(2);
	qDebug(category) << "Malloc - PAGE[4]";
	PAGE.resize(4);
	qDebug(category) << "Malloc - LINE[2]";
	LINE.resize(2);
	qDebug(category) << "Malloc - TK_LIDLOT[24]";
	TK_LIDLOT.resize(24);
	qDebug(category) << "Malloc - TK_LIDPRT[18]";
	TK_LIDPRT.resize(18);
	qDebug(category) << "Malloc - TK_LIDLOTDESC[30]";
	TK_LIDLOTDESC.resize(30);
	qDebug(category) << "Malloc - TK_LIDPRTDESC[30]";
	TK_LIDPRTDESC.resize(30);
	qDebug(category) << "Malloc - TK_LIDPRTREV[2]";
	TK_LIDPRTREV.resize(2);
	qDebug(category) << "Malloc - TK_LIDPRTSC[2]";
	TK_LIDPRTSC.resize(2);
	qDebug(category) << "Malloc - TK_LIDPRTUOM[2]";
	TK_LIDPRTUOM.resize(2);
	qDebug(category) << "Malloc - TK_LIDACCCODE[2]";
	TK_LIDACCCODE.resize(2);
	qDebug(category) << "Malloc - TK_LIDACCTYPE[2]";
	TK_LIDACCTYPE.resize(2);
	qDebug(category) << "Malloc - TK_LIDEXPDAT[4]";
	TK_LIDEXPDAT.resize(4);
	qDebug(category) << "Malloc - QTY[8]";
	QTY.resize(8);
	qDebug(category) << "Malloc - TK_LIDISSQTY[8]";
	TK_LIDISSQTY.resize(8);
	qDebug(category) << "Malloc - TK_LIDSCRPQTY[8]";
	TK_LIDSCRPQTY.resize(8);
	qDebug(category) << "Malloc - TK_LIDRTVQTY[8]";
	TK_LIDRTVQTY.resize(8);
	qDebug(category) << "Malloc - TK_LIDCRDAT[4]";
	TK_LIDCRDAT.resize(4);
	qDebug(category) << "Malloc - TK_LIDISSDAT[4]";
	TK_LIDISSDAT.resize(4);
	qDebug(category) << "Malloc - DAT[4]";
	DAT.resize(4);
	qDebug(category) << "Malloc - TK_LIDARCDAT[4]";
	TK_LIDARCDAT.resize(4);
	qDebug(category) << "Malloc - TK_LIDARCISSQTY[8]";
	TK_LIDARCISSQTY.resize(8);
	qDebug(category) << "Malloc - TK_LIDARCRECQTY[8]";
	TK_LIDARCRECQTY.resize(8);
	qDebug(category) << "Malloc - TK_LIDUSRFLD1[30]";
	TK_LIDUSRFLD1.resize(30);
	qDebug(category) << "Malloc - TK_LIDUSRFLD2[30]";
	TK_LIDUSRFLD2.resize(30);
	qDebug(category) << "Malloc - TK_LIDUSRFLD3[30]";
	TK_LIDUSRFLD3.resize(30);
	qDebug(category) << "Malloc - TK_LIDUSRFLD4[30]";
	TK_LIDUSRFLD4.resize(30);
	qDebug(category) << "Malloc - TK_LIDARCCODDESC[30]";
	TK_LIDARCCODDESC.resize(30);
	qDebug(category) << "Malloc - TK_LIDPOT[2]";
	TK_LIDPOT.resize(2);
	qDebug(category) << "Malloc - TK_LIDMUQ[8]";
	TK_LIDMUQ.resize(8);
	qDebug(category) << "Malloc - TK_LIDLOTUOM[2]";
	TK_LIDLOTUOM.resize(2);
	qDebug(category) << "Malloc - TK_LIDACTCOD1[2]";
	TK_LIDACTCOD1.resize(2);
	qDebug(category) << "Malloc - TK_LIDACTDAT1[4]";
	TK_LIDACTDAT1.resize(4);
	qDebug(category) << "Malloc - TK_LIDACTCOD2[2]";
	TK_LIDACTCOD2.resize(2);
	qDebug(category) << "Malloc - TK_LIDACTDAT2[4]";
	TK_LIDACTDAT2.resize(4);
	qDebug(category) << "Malloc - TK_LOTNO[24]";
	TK_LOTNO.resize(24);
	qDebug(category) << "Malloc - TK_PRTNO[18]";
	TK_PRTNO.resize(18);

#pragma endregion Resize Fields TK_LIDREC
}
void TK_LIDREC::close()
{
	QLoggingCategory category("classLibQ");
	if (m_bIsOpen)
	{
	qDebug(category) << "database is Open";
		SQLHANDLE source_hStmt = hStmt_Fetch;
		SQLHANDLE insert_hStmt = hStmt_Insert;
		SQLHANDLE hDb_S = this->hDbc_source;
		SQLHANDLE hDb_T = hDbc_target;
		SQLHANDLE hEnvS = hEnv_Source;
		SQLHANDLE hEnvT = hEnv_Target;
		RETCODE r;

		r = ::SQLFreeHandle(SQL_HANDLE_STMT, hStmt_Fetch);
		r = ::SQLFreeHandle(SQL_HANDLE_STMT, hStmt_Insert);
		r = ::SQLFreeHandle(SQL_HANDLE_STMT, hStmt_Update);
		if (hDbc_source != SQL_NULL_HANDLE) 		r = ::SQLDisconnect(hDb_S);
		if (hDbc_target != SQL_NULL_HANDLE) 		r = ::SQLDisconnect(hDb_T);

		r = ::SQLFreeHandle(SQL_HANDLE_DBC, hDb_S);
		r = ::SQLFreeHandle(SQL_HANDLE_DBC, hDb_T);
		r = ::SQLFreeHandle(SQL_HANDLE_ENV, hEnvS);
		r = ::SQLFreeHandle(SQL_HANDLE_ENV, hEnvT);
	}

	hEnv_Source = SQL_NULL_HANDLE;
	hEnv_Target = SQL_NULL_HANDLE;
	hEnv_Source = SQL_NULL_HANDLE;
	hEnv_Target = SQL_NULL_HANDLE;
	hStmt_Fetch = SQL_NULL_HANDLE;
	hStmt_Insert = SQL_NULL_HANDLE;
	hStmt_Update = SQL_NULL_HANDLE;
}

void TK_LIDREC::open(const QString sourceDSN, const QString targetDSN)
{
	QLoggingCategory category("classLibQ");
	m_lpszTargetDSN = targetDSN;
	m_lpszSourceDSN = sourceDSN;
	qDebug(category) << QString("Source - %1[%2]").arg(sourceDSN);
	qDebug(category) << QString("Target - %1[%2]").arg(targetDSN);
}

void TK_LIDREC::createTable()
{
	QLoggingCategory category("classLibQ");
	{
		QScopedPointer<nvTableOracleRdb> tbl(new nvTableOracleRdb(nullptr));
		tbl->initialize("TK_LIDREC", this->m_lpszSourceDSN);
		QString newTbl = tbl->getCreateTableSQL();
		QScopedPointer<qVtExecute> vExec(new qVtExecute(nullptr));
		{
			vExec->initialize(m_lpszTargetDSN, " ", true);
			vExec->setOdbcAttributes(m_OdbcAttributes);
			vExec->ExecuteDirect(newTbl);
		}
	 qDebug(category) << QString("End Create Table %1 ").arg(tableName); 
	}
}

bool TK_LIDREC::prepare()
{
	RETCODE r;
	QString check;
	QLoggingCategory category("classLibQ");
	 qDebug(category) << fetchSql;
	 qDebug(category) << insertSql;
#ifdef UNICODE
	r = SQLPrepare(hStmt_Insert,toSQLTCHAR(insertSql).data(),(SQLINTEGER)insertSql.length()); 
	if (r != SQL_SUCCESS) {
		check = qWarnODBCHandle(SQL_HANDLE_STMT, hStmt_Insert);
		 qCCritical(category) << QString("Prepare Statement-Insert : %1 is %2").arg(insertSql).arg(check);
		return false; 
	}
	r = SQLPrepare(hStmt_Update,toSQLTCHAR(updateSql).data(),(SQLINTEGER)updateSql.length()); 
	if (r != SQL_SUCCESS) {
		check = qWarnODBCHandle(SQL_HANDLE_STMT, hStmt_Update);
		 qCCritical(category) << QString("Prepare Statement-Update : %1 is %2").arg(updateSql).arg(check);
		return false; 
	}
	r = SQLPrepare(hStmt_Fetch,toSQLTCHAR(fetchSql).data(),(SQLINTEGER)fetchSql.length());
	if (r != SQL_SUCCESS) {
		check = qWarnODBCHandle(SQL_HANDLE_STMT, hStmt_Fetch);
		 qCCritical(category) << QString("Prepare Statement-Insert : %1 is %2").arg(fetchSql).arg(check);
		return false; 
	}
#else
	QByteArray queryI8 = insertSql.toUtf8();
	r = SQLPrepare(insert_hStmt,SQLCHAR*)queryI8.data(),(SQLINTEGER)queryI8.length());
	QByteArray queryU8 = fetchSql.toUtf8();
	r = SQLPrepare(hStmt_Fetch,(SQLCHAR*)queryU8.data(),(SQLINTEGER)queryU8.length());
#endif
	return true;

}

void TK_LIDREC::prepareTargetTable()
{
	QLoggingCategory category("classLibQ");
	if (this->m_ReplicationOption == ReplicationOption::BulkCopy)
	{
		QScopedPointer<qVtExecute> execSql(new qVtExecute(nullptr));
		DropOption option = this->m_dropOption;
		switch (option)
		{
			case DropOption::DeleteFromTable:
			{
				QLoggingCategory category("classLibQ");
				execSql->initialize(this->m_lpszTargetDSN, "delete from TK_LIDREC", true);
				execSql->setOdbcAttributes(this->m_OdbcAttributes);
				execSql->ExecuteDirect("delete from TK_LIDREC");
			}break;
			case DropOption::TruncateTable:
			{
				execSql->initialize(this->m_lpszTargetDSN, "truncate table TK_LIDREC", true);
				execSql->setOdbcAttributes(this->m_OdbcAttributes);
				execSql->ExecuteDirect("truncate table TK_LIDREC");
			}break;
			case DropOption::DropTable:
			{
				execSql->initialize(this->m_lpszTargetDSN, "drop table TK_LIDREC", true);
				execSql->setOdbcAttributes(this->m_OdbcAttributes);
				execSql->ExecuteDirect("drop table TK_LIDREC");
				createTable();
			}break;
		}
	}
}

bool TK_LIDREC::bindColumn()
{
	QLoggingCategory category("classLibQ");
	RETCODE r;
	bool isValid=true;
		 qDebug(category) << " Bindings: Ordinal [1] Type: 5 Buffer Size: 2 FieldName: DB_ID ";
		r = ::SQLBindCol(hStmt_Fetch, 1, 5, DB_ID.data(), 2, &cbDB_ID);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Bindings: Ordinal [2] Type: 93 Buffer Size: 23 FieldName: NVTIMESTAMP ";
		r = ::SQLBindCol(hStmt_Fetch, 2, 93, NVTIMESTAMP.data(), 23, &cbNVTIMESTAMP);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Bindings: Ordinal [3] Type: 5 Buffer Size: 2 FieldName: AREA ";
		r = ::SQLBindCol(hStmt_Fetch, 3, 5, AREA.data(), 2, &cbAREA);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Bindings: Ordinal [4] Type: 4 Buffer Size: 4 FieldName: PAGE ";
		r = ::SQLBindCol(hStmt_Fetch, 4, 4, PAGE.data(), 4, &cbPAGE);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Bindings: Ordinal [5] Type: 5 Buffer Size: 2 FieldName: LINE ";
		r = ::SQLBindCol(hStmt_Fetch, 5, 5, LINE.data(), 2, &cbLINE);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Bindings: Ordinal [6] Type: 1 Buffer Size: 24 FieldName: TK_LIDLOT ";
		r = ::SQLBindCol(hStmt_Fetch, 6, 1, TK_LIDLOT.data(), 24, &cbTK_LIDLOT);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Bindings: Ordinal [7] Type: 1 Buffer Size: 18 FieldName: TK_LIDPRT ";
		r = ::SQLBindCol(hStmt_Fetch, 7, 1, TK_LIDPRT.data(), 18, &cbTK_LIDPRT);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Bindings: Ordinal [8] Type: 1 Buffer Size: 30 FieldName: TK_LIDLOTDESC ";
		r = ::SQLBindCol(hStmt_Fetch, 8, 1, TK_LIDLOTDESC.data(), 30, &cbTK_LIDLOTDESC);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Bindings: Ordinal [9] Type: 1 Buffer Size: 30 FieldName: TK_LIDPRTDESC ";
		r = ::SQLBindCol(hStmt_Fetch, 9, 1, TK_LIDPRTDESC.data(), 30, &cbTK_LIDPRTDESC);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Bindings: Ordinal [10] Type: 1 Buffer Size: 2 FieldName: TK_LIDPRTREV ";
		r = ::SQLBindCol(hStmt_Fetch, 10, 1, TK_LIDPRTREV.data(), 2, &cbTK_LIDPRTREV);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Bindings: Ordinal [11] Type: 1 Buffer Size: 2 FieldName: TK_LIDPRTSC ";
		r = ::SQLBindCol(hStmt_Fetch, 11, 1, TK_LIDPRTSC.data(), 2, &cbTK_LIDPRTSC);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Bindings: Ordinal [12] Type: 1 Buffer Size: 2 FieldName: TK_LIDPRTUOM ";
		r = ::SQLBindCol(hStmt_Fetch, 12, 1, TK_LIDPRTUOM.data(), 2, &cbTK_LIDPRTUOM);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Bindings: Ordinal [13] Type: 5 Buffer Size: 2 FieldName: TK_LIDACCCODE ";
		r = ::SQLBindCol(hStmt_Fetch, 13, 5, TK_LIDACCCODE.data(), 2, &cbTK_LIDACCCODE);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Bindings: Ordinal [14] Type: 5 Buffer Size: 2 FieldName: TK_LIDACCTYPE ";
		r = ::SQLBindCol(hStmt_Fetch, 14, 5, TK_LIDACCTYPE.data(), 2, &cbTK_LIDACCTYPE);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Bindings: Ordinal [15] Type: 4 Buffer Size: 4 FieldName: TK_LIDEXPDAT ";
		r = ::SQLBindCol(hStmt_Fetch, 15, 4, TK_LIDEXPDAT.data(), 4, &cbTK_LIDEXPDAT);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Bindings: Ordinal [16] Type: 8 Buffer Size: 8 FieldName: QTY ";
		r = ::SQLBindCol(hStmt_Fetch, 16, 8, QTY.data(), 8, &cbQTY);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Bindings: Ordinal [17] Type: 8 Buffer Size: 8 FieldName: TK_LIDISSQTY ";
		r = ::SQLBindCol(hStmt_Fetch, 17, 8, TK_LIDISSQTY.data(), 8, &cbTK_LIDISSQTY);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Bindings: Ordinal [18] Type: 8 Buffer Size: 8 FieldName: TK_LIDSCRPQTY ";
		r = ::SQLBindCol(hStmt_Fetch, 18, 8, TK_LIDSCRPQTY.data(), 8, &cbTK_LIDSCRPQTY);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Bindings: Ordinal [19] Type: 8 Buffer Size: 8 FieldName: TK_LIDRTVQTY ";
		r = ::SQLBindCol(hStmt_Fetch, 19, 8, TK_LIDRTVQTY.data(), 8, &cbTK_LIDRTVQTY);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Bindings: Ordinal [20] Type: 4 Buffer Size: 4 FieldName: TK_LIDCRDAT ";
		r = ::SQLBindCol(hStmt_Fetch, 20, 4, TK_LIDCRDAT.data(), 4, &cbTK_LIDCRDAT);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Bindings: Ordinal [21] Type: 4 Buffer Size: 4 FieldName: TK_LIDISSDAT ";
		r = ::SQLBindCol(hStmt_Fetch, 21, 4, TK_LIDISSDAT.data(), 4, &cbTK_LIDISSDAT);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Bindings: Ordinal [22] Type: 4 Buffer Size: 4 FieldName: DAT ";
		r = ::SQLBindCol(hStmt_Fetch, 22, 4, DAT.data(), 4, &cbDAT);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Bindings: Ordinal [23] Type: 4 Buffer Size: 4 FieldName: TK_LIDARCDAT ";
		r = ::SQLBindCol(hStmt_Fetch, 23, 4, TK_LIDARCDAT.data(), 4, &cbTK_LIDARCDAT);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Bindings: Ordinal [24] Type: 8 Buffer Size: 8 FieldName: TK_LIDARCISSQTY ";
		r = ::SQLBindCol(hStmt_Fetch, 24, 8, TK_LIDARCISSQTY.data(), 8, &cbTK_LIDARCISSQTY);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Bindings: Ordinal [25] Type: 8 Buffer Size: 8 FieldName: TK_LIDARCRECQTY ";
		r = ::SQLBindCol(hStmt_Fetch, 25, 8, TK_LIDARCRECQTY.data(), 8, &cbTK_LIDARCRECQTY);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Bindings: Ordinal [26] Type: 1 Buffer Size: 30 FieldName: TK_LIDUSRFLD1 ";
		r = ::SQLBindCol(hStmt_Fetch, 26, 1, TK_LIDUSRFLD1.data(), 30, &cbTK_LIDUSRFLD1);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Bindings: Ordinal [27] Type: 1 Buffer Size: 30 FieldName: TK_LIDUSRFLD2 ";
		r = ::SQLBindCol(hStmt_Fetch, 27, 1, TK_LIDUSRFLD2.data(), 30, &cbTK_LIDUSRFLD2);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Bindings: Ordinal [28] Type: 1 Buffer Size: 30 FieldName: TK_LIDUSRFLD3 ";
		r = ::SQLBindCol(hStmt_Fetch, 28, 1, TK_LIDUSRFLD3.data(), 30, &cbTK_LIDUSRFLD3);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Bindings: Ordinal [29] Type: 1 Buffer Size: 30 FieldName: TK_LIDUSRFLD4 ";
		r = ::SQLBindCol(hStmt_Fetch, 29, 1, TK_LIDUSRFLD4.data(), 30, &cbTK_LIDUSRFLD4);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Bindings: Ordinal [30] Type: 1 Buffer Size: 30 FieldName: TK_LIDARCCODDESC ";
		r = ::SQLBindCol(hStmt_Fetch, 30, 1, TK_LIDARCCODDESC.data(), 30, &cbTK_LIDARCCODDESC);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Bindings: Ordinal [31] Type: 5 Buffer Size: 2 FieldName: TK_LIDPOT ";
		r = ::SQLBindCol(hStmt_Fetch, 31, 5, TK_LIDPOT.data(), 2, &cbTK_LIDPOT);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Bindings: Ordinal [32] Type: 8 Buffer Size: 8 FieldName: TK_LIDMUQ ";
		r = ::SQLBindCol(hStmt_Fetch, 32, 8, TK_LIDMUQ.data(), 8, &cbTK_LIDMUQ);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Bindings: Ordinal [33] Type: 1 Buffer Size: 2 FieldName: TK_LIDLOTUOM ";
		r = ::SQLBindCol(hStmt_Fetch, 33, 1, TK_LIDLOTUOM.data(), 2, &cbTK_LIDLOTUOM);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Bindings: Ordinal [34] Type: 5 Buffer Size: 2 FieldName: TK_LIDACTCOD1 ";
		r = ::SQLBindCol(hStmt_Fetch, 34, 5, TK_LIDACTCOD1.data(), 2, &cbTK_LIDACTCOD1);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Bindings: Ordinal [35] Type: 4 Buffer Size: 4 FieldName: TK_LIDACTDAT1 ";
		r = ::SQLBindCol(hStmt_Fetch, 35, 4, TK_LIDACTDAT1.data(), 4, &cbTK_LIDACTDAT1);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Bindings: Ordinal [36] Type: 5 Buffer Size: 2 FieldName: TK_LIDACTCOD2 ";
		r = ::SQLBindCol(hStmt_Fetch, 36, 5, TK_LIDACTCOD2.data(), 2, &cbTK_LIDACTCOD2);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Bindings: Ordinal [37] Type: 4 Buffer Size: 4 FieldName: TK_LIDACTDAT2 ";
		r = ::SQLBindCol(hStmt_Fetch, 37, 4, TK_LIDACTDAT2.data(), 4, &cbTK_LIDACTDAT2);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Bindings: Ordinal [38] Type: 1 Buffer Size: 24 FieldName: TK_LOTNO ";
		r = ::SQLBindCol(hStmt_Fetch, 38, 1, TK_LOTNO.data(), 24, &cbTK_LOTNO);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Bindings: Ordinal [39] Type: 1 Buffer Size: 18 FieldName: TK_PRTNO ";
		r = ::SQLBindCol(hStmt_Fetch, 39, 1, TK_PRTNO.data(), 18, &cbTK_PRTNO);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
	return isValid;
}

bool TK_LIDREC::bindParameter()
{
	QLoggingCategory category("classLibQ");
	RETCODE r;
	bool isValid=true;
	{
		 qDebug(category) << " Parameters: Ordinal [1] Type: 5 Buffer Size: 2 FieldName: DB_ID ";
		r = SQLBindParameter(hStmt_Insert, 1, SQL_PARAM_INPUT, SQL_C_DEFAULT, 5, 0, 0, (SQLPOINTER)DB_ID.constData(), 0, &cbDB_ID);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Parameters: Ordinal [2] Type: 93 Buffer Size: 23 FieldName: NVTIMESTAMP ";
		r = SQLBindParameter(hStmt_Insert, 2, SQL_PARAM_INPUT, SQL_C_DEFAULT, 93, 23, 0, (SQLPOINTER)NVTIMESTAMP.constData(), 0, &cbNVTIMESTAMP);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Parameters: Ordinal [3] Type: 5 Buffer Size: 2 FieldName: AREA ";
		r = SQLBindParameter(hStmt_Insert, 3, SQL_PARAM_INPUT, SQL_C_DEFAULT, 5, 0, 0, (SQLPOINTER)AREA.constData(), 0, &cbAREA);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Parameters: Ordinal [4] Type: 4 Buffer Size: 4 FieldName: PAGE ";
		r = SQLBindParameter(hStmt_Insert, 4, SQL_PARAM_INPUT, SQL_C_DEFAULT, 4, 0, 0, (SQLPOINTER)PAGE.constData(), 0, &cbPAGE);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Parameters: Ordinal [5] Type: 5 Buffer Size: 2 FieldName: LINE ";
		r = SQLBindParameter(hStmt_Insert, 5, SQL_PARAM_INPUT, SQL_C_DEFAULT, 5, 0, 0, (SQLPOINTER)LINE.constData(), 0, &cbLINE);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Parameters: Ordinal [6] Type: 1 Buffer Size: 24 FieldName: TK_LIDLOT ";
		r = SQLBindParameter(hStmt_Insert, 6, SQL_PARAM_INPUT, SQL_C_DEFAULT, 1, 24, 0, (SQLPOINTER)TK_LIDLOT.constData(), 0, &cbTK_LIDLOT);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Parameters: Ordinal [7] Type: 1 Buffer Size: 18 FieldName: TK_LIDPRT ";
		r = SQLBindParameter(hStmt_Insert, 7, SQL_PARAM_INPUT, SQL_C_DEFAULT, 1, 18, 0, (SQLPOINTER)TK_LIDPRT.constData(), 0, &cbTK_LIDPRT);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Parameters: Ordinal [8] Type: 1 Buffer Size: 30 FieldName: TK_LIDLOTDESC ";
		r = SQLBindParameter(hStmt_Insert, 8, SQL_PARAM_INPUT, SQL_C_DEFAULT, 1, 30, 0, (SQLPOINTER)TK_LIDLOTDESC.constData(), 0, &cbTK_LIDLOTDESC);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Parameters: Ordinal [9] Type: 1 Buffer Size: 30 FieldName: TK_LIDPRTDESC ";
		r = SQLBindParameter(hStmt_Insert, 9, SQL_PARAM_INPUT, SQL_C_DEFAULT, 1, 30, 0, (SQLPOINTER)TK_LIDPRTDESC.constData(), 0, &cbTK_LIDPRTDESC);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Parameters: Ordinal [10] Type: 1 Buffer Size: 2 FieldName: TK_LIDPRTREV ";
		r = SQLBindParameter(hStmt_Insert, 10, SQL_PARAM_INPUT, SQL_C_DEFAULT, 1, 2, 0, (SQLPOINTER)TK_LIDPRTREV.constData(), 0, &cbTK_LIDPRTREV);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Parameters: Ordinal [11] Type: 1 Buffer Size: 2 FieldName: TK_LIDPRTSC ";
		r = SQLBindParameter(hStmt_Insert, 11, SQL_PARAM_INPUT, SQL_C_DEFAULT, 1, 2, 0, (SQLPOINTER)TK_LIDPRTSC.constData(), 0, &cbTK_LIDPRTSC);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Parameters: Ordinal [12] Type: 1 Buffer Size: 2 FieldName: TK_LIDPRTUOM ";
		r = SQLBindParameter(hStmt_Insert, 12, SQL_PARAM_INPUT, SQL_C_DEFAULT, 1, 2, 0, (SQLPOINTER)TK_LIDPRTUOM.constData(), 0, &cbTK_LIDPRTUOM);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Parameters: Ordinal [13] Type: 5 Buffer Size: 2 FieldName: TK_LIDACCCODE ";
		r = SQLBindParameter(hStmt_Insert, 13, SQL_PARAM_INPUT, SQL_C_DEFAULT, 5, 0, 0, (SQLPOINTER)TK_LIDACCCODE.constData(), 0, &cbTK_LIDACCCODE);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Parameters: Ordinal [14] Type: 5 Buffer Size: 2 FieldName: TK_LIDACCTYPE ";
		r = SQLBindParameter(hStmt_Insert, 14, SQL_PARAM_INPUT, SQL_C_DEFAULT, 5, 0, 0, (SQLPOINTER)TK_LIDACCTYPE.constData(), 0, &cbTK_LIDACCTYPE);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Parameters: Ordinal [15] Type: 4 Buffer Size: 4 FieldName: TK_LIDEXPDAT ";
		r = SQLBindParameter(hStmt_Insert, 15, SQL_PARAM_INPUT, SQL_C_DEFAULT, 4, 0, 0, (SQLPOINTER)TK_LIDEXPDAT.constData(), 0, &cbTK_LIDEXPDAT);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Parameters: Ordinal [16] Type: 8 Buffer Size: 8 FieldName: QTY ";
		r = SQLBindParameter(hStmt_Insert, 16, SQL_PARAM_INPUT, SQL_C_DEFAULT, 8, 0, 0, (SQLPOINTER)QTY.constData(), 0, &cbQTY);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Parameters: Ordinal [17] Type: 8 Buffer Size: 8 FieldName: TK_LIDISSQTY ";
		r = SQLBindParameter(hStmt_Insert, 17, SQL_PARAM_INPUT, SQL_C_DEFAULT, 8, 0, 0, (SQLPOINTER)TK_LIDISSQTY.constData(), 0, &cbTK_LIDISSQTY);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Parameters: Ordinal [18] Type: 8 Buffer Size: 8 FieldName: TK_LIDSCRPQTY ";
		r = SQLBindParameter(hStmt_Insert, 18, SQL_PARAM_INPUT, SQL_C_DEFAULT, 8, 0, 0, (SQLPOINTER)TK_LIDSCRPQTY.constData(), 0, &cbTK_LIDSCRPQTY);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Parameters: Ordinal [19] Type: 8 Buffer Size: 8 FieldName: TK_LIDRTVQTY ";
		r = SQLBindParameter(hStmt_Insert, 19, SQL_PARAM_INPUT, SQL_C_DEFAULT, 8, 0, 0, (SQLPOINTER)TK_LIDRTVQTY.constData(), 0, &cbTK_LIDRTVQTY);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Parameters: Ordinal [20] Type: 4 Buffer Size: 4 FieldName: TK_LIDCRDAT ";
		r = SQLBindParameter(hStmt_Insert, 20, SQL_PARAM_INPUT, SQL_C_DEFAULT, 4, 0, 0, (SQLPOINTER)TK_LIDCRDAT.constData(), 0, &cbTK_LIDCRDAT);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Parameters: Ordinal [21] Type: 4 Buffer Size: 4 FieldName: TK_LIDISSDAT ";
		r = SQLBindParameter(hStmt_Insert, 21, SQL_PARAM_INPUT, SQL_C_DEFAULT, 4, 0, 0, (SQLPOINTER)TK_LIDISSDAT.constData(), 0, &cbTK_LIDISSDAT);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Parameters: Ordinal [22] Type: 4 Buffer Size: 4 FieldName: DAT ";
		r = SQLBindParameter(hStmt_Insert, 22, SQL_PARAM_INPUT, SQL_C_DEFAULT, 4, 0, 0, (SQLPOINTER)DAT.constData(), 0, &cbDAT);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Parameters: Ordinal [23] Type: 4 Buffer Size: 4 FieldName: TK_LIDARCDAT ";
		r = SQLBindParameter(hStmt_Insert, 23, SQL_PARAM_INPUT, SQL_C_DEFAULT, 4, 0, 0, (SQLPOINTER)TK_LIDARCDAT.constData(), 0, &cbTK_LIDARCDAT);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Parameters: Ordinal [24] Type: 8 Buffer Size: 8 FieldName: TK_LIDARCISSQTY ";
		r = SQLBindParameter(hStmt_Insert, 24, SQL_PARAM_INPUT, SQL_C_DEFAULT, 8, 0, 0, (SQLPOINTER)TK_LIDARCISSQTY.constData(), 0, &cbTK_LIDARCISSQTY);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Parameters: Ordinal [25] Type: 8 Buffer Size: 8 FieldName: TK_LIDARCRECQTY ";
		r = SQLBindParameter(hStmt_Insert, 25, SQL_PARAM_INPUT, SQL_C_DEFAULT, 8, 0, 0, (SQLPOINTER)TK_LIDARCRECQTY.constData(), 0, &cbTK_LIDARCRECQTY);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Parameters: Ordinal [26] Type: 1 Buffer Size: 30 FieldName: TK_LIDUSRFLD1 ";
		r = SQLBindParameter(hStmt_Insert, 26, SQL_PARAM_INPUT, SQL_C_DEFAULT, 1, 30, 0, (SQLPOINTER)TK_LIDUSRFLD1.constData(), 0, &cbTK_LIDUSRFLD1);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Parameters: Ordinal [27] Type: 1 Buffer Size: 30 FieldName: TK_LIDUSRFLD2 ";
		r = SQLBindParameter(hStmt_Insert, 27, SQL_PARAM_INPUT, SQL_C_DEFAULT, 1, 30, 0, (SQLPOINTER)TK_LIDUSRFLD2.constData(), 0, &cbTK_LIDUSRFLD2);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Parameters: Ordinal [28] Type: 1 Buffer Size: 30 FieldName: TK_LIDUSRFLD3 ";
		r = SQLBindParameter(hStmt_Insert, 28, SQL_PARAM_INPUT, SQL_C_DEFAULT, 1, 30, 0, (SQLPOINTER)TK_LIDUSRFLD3.constData(), 0, &cbTK_LIDUSRFLD3);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Parameters: Ordinal [29] Type: 1 Buffer Size: 30 FieldName: TK_LIDUSRFLD4 ";
		r = SQLBindParameter(hStmt_Insert, 29, SQL_PARAM_INPUT, SQL_C_DEFAULT, 1, 30, 0, (SQLPOINTER)TK_LIDUSRFLD4.constData(), 0, &cbTK_LIDUSRFLD4);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Parameters: Ordinal [30] Type: 1 Buffer Size: 30 FieldName: TK_LIDARCCODDESC ";
		r = SQLBindParameter(hStmt_Insert, 30, SQL_PARAM_INPUT, SQL_C_DEFAULT, 1, 30, 0, (SQLPOINTER)TK_LIDARCCODDESC.constData(), 0, &cbTK_LIDARCCODDESC);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Parameters: Ordinal [31] Type: 5 Buffer Size: 2 FieldName: TK_LIDPOT ";
		r = SQLBindParameter(hStmt_Insert, 31, SQL_PARAM_INPUT, SQL_C_DEFAULT, 5, 0, 0, (SQLPOINTER)TK_LIDPOT.constData(), 0, &cbTK_LIDPOT);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Parameters: Ordinal [32] Type: 8 Buffer Size: 8 FieldName: TK_LIDMUQ ";
		r = SQLBindParameter(hStmt_Insert, 32, SQL_PARAM_INPUT, SQL_C_DEFAULT, 8, 0, 0, (SQLPOINTER)TK_LIDMUQ.constData(), 0, &cbTK_LIDMUQ);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Parameters: Ordinal [33] Type: 1 Buffer Size: 2 FieldName: TK_LIDLOTUOM ";
		r = SQLBindParameter(hStmt_Insert, 33, SQL_PARAM_INPUT, SQL_C_DEFAULT, 1, 2, 0, (SQLPOINTER)TK_LIDLOTUOM.constData(), 0, &cbTK_LIDLOTUOM);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Parameters: Ordinal [34] Type: 5 Buffer Size: 2 FieldName: TK_LIDACTCOD1 ";
		r = SQLBindParameter(hStmt_Insert, 34, SQL_PARAM_INPUT, SQL_C_DEFAULT, 5, 0, 0, (SQLPOINTER)TK_LIDACTCOD1.constData(), 0, &cbTK_LIDACTCOD1);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Parameters: Ordinal [35] Type: 4 Buffer Size: 4 FieldName: TK_LIDACTDAT1 ";
		r = SQLBindParameter(hStmt_Insert, 35, SQL_PARAM_INPUT, SQL_C_DEFAULT, 4, 0, 0, (SQLPOINTER)TK_LIDACTDAT1.constData(), 0, &cbTK_LIDACTDAT1);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Parameters: Ordinal [36] Type: 5 Buffer Size: 2 FieldName: TK_LIDACTCOD2 ";
		r = SQLBindParameter(hStmt_Insert, 36, SQL_PARAM_INPUT, SQL_C_DEFAULT, 5, 0, 0, (SQLPOINTER)TK_LIDACTCOD2.constData(), 0, &cbTK_LIDACTCOD2);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Parameters: Ordinal [37] Type: 4 Buffer Size: 4 FieldName: TK_LIDACTDAT2 ";
		r = SQLBindParameter(hStmt_Insert, 37, SQL_PARAM_INPUT, SQL_C_DEFAULT, 4, 0, 0, (SQLPOINTER)TK_LIDACTDAT2.constData(), 0, &cbTK_LIDACTDAT2);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Parameters: Ordinal [38] Type: 1 Buffer Size: 24 FieldName: TK_LOTNO ";
		r = SQLBindParameter(hStmt_Insert, 38, SQL_PARAM_INPUT, SQL_C_DEFAULT, 1, 24, 0, (SQLPOINTER)TK_LOTNO.constData(), 0, &cbTK_LOTNO);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Parameters: Ordinal [39] Type: 1 Buffer Size: 18 FieldName: TK_PRTNO ";
		r = SQLBindParameter(hStmt_Insert, 39, SQL_PARAM_INPUT, SQL_C_DEFAULT, 1, 18, 0, (SQLPOINTER)TK_PRTNO.constData(), 0, &cbTK_PRTNO);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
	}
	if (m_ReplicationOption == ReplicationOption::NetChange)
	{
		r = SQLBindParameter(hStmt_Update, 40, SQL_PARAM_INPUT, SQL_C_DEFAULT, 3, 0, 0, (SQLPOINTER)AREA.constData(), 0, &cbAREA);
		if (r == SQL_SUCCESS) { isValid=true; }
		r = SQLBindParameter(hStmt_Update, 41, SQL_PARAM_INPUT, SQL_C_DEFAULT, 4, 0, 0, (SQLPOINTER)PAGE.constData(), 0, &cbPAGE);
		if (r == SQL_SUCCESS) { isValid=true; }
		r = SQLBindParameter(hStmt_Update, 42, SQL_PARAM_INPUT, SQL_C_DEFAULT, 5, 0, 0, (SQLPOINTER)LINE.constData(), 0, &cbLINE);
		if (r == SQL_SUCCESS) { isValid=true; }
	// TK_LIDREC is a well formed table for eNVy Replication 
		 qDebug(category) << " Parameters: Ordinal [3] 00 00 FieldName: AREA ";
		 qDebug(category) << " Parameters: Ordinal [4] 00 00  FieldName: PAGE ";
		 qDebug(category) << " Parameters: Ordinal [5] 00 00 FieldName:  LINE ";
	} // 	if (m_ReplicationOption == ReplicationOption::NetChange)
	return isValid;
}

bool TK_LIDREC::process(int rowSize)
{
	QLoggingCategory category("classLibQ");
	initOdbcAttributes();
	connect(Source);
	connect(Target);
	initialize();
	prepareTargetTable();
	prepare();
	bindColumn();
	bindParameter();
	copyTable();
	close();
	return false;
}

void TK_LIDREC::copyTable()
{
	QLoggingCategory category("classLibQ");
	RETCODE r;
	QString check;
	r = SQLExecute(hStmt_Fetch);
		if (bIsAbort) {
			emit aborted(tableName, rowsFetched, rowsInserted, rowsUpdated);
			return;
		}
		while((r = SQLFetch(hStmt_Fetch)) != SQL_NO_DATA) {
		if (r != SQL_SUCCESS) {
			check = qWarnODBCHandle(SQL_HANDLE_STMT, hStmt_Fetch);
			qCCritical(category) << QString("SqlFetch - Error : %1 is %2").arg(fetchSql).arg(check);
			return;
		} 
		rowsFetched++;
		if (m_ReplicationOption == ReplicationOption::BulkCopy)
		{
			r = SQLExecute(hStmt_Insert);
			if (r == SQL_ERROR) {
				check = qWarnODBCHandle(SQL_HANDLE_STMT, hStmt_Insert);
				 qCCritical(category) << QString("SqlExecute:Insert - Error : %1 is %2").arg(insertSql).arg(check);
				return;
			}
			rowsInserted++;
			if ((rowsFetched % updateInterval) == 0) {
				qCInfo(category) << QString("[%1.%2]	Insertion: %3	Updates : %4	Fetched : %5").arg(profileName).arg(tableName).arg(rowsInserted).arg(rowsUpdated).arg(rowsFetched);
				emit updateStatusFetched(profileName, tableName, rowsFetched,rowsInserted,rowsUpdated);
			}
			if (m_ReplicationOption == ReplicationOption::NetChange)
			{
			r = SQLExecute(hStmt_Update);
			if (r != SQL_SUCCESS) {
				check = qWarnODBCHandle(SQL_HANDLE_STMT, hStmt_Update);
				 qCInfo(category)  << QString("SqlExecute:Update - Error : %1 is %2").arg(updateSql).arg(check);
				r = SQLExecute(hStmt_Insert);
				if (r != SQL_SUCCESS) {
					check = qWarnODBCHandle(SQL_HANDLE_STMT, hStmt_Insert);
					 qCritical(category) << QString("SqlExecute:Insert - Error : %1 is %2").arg(insertSql).arg(check);
					return;
				}
				else 	rowsInserted++;
				}
				else	rowsUpdated++;
			}
			emit updateStatusFetched(profileName, tableName, rowsFetched,rowsInserted,rowsUpdated);
		}
	} 
qCInfo(category) << QString("[%1.%2]	Insertion: %3	Updates : %4	Fetched : %5").arg(profileName).arg(tableName).arg(rowsInserted).arg(rowsUpdated).arg(rowsFetched);
}

void TK_LIDREC::connect(connectionHandle connectionSource)
{

	QLoggingCategory category("classLibQ");
	RETCODE r;

	bool isValid = false;
	HWND	hWnd = nullptr;
	hWnd = ::GetDesktopWindow(); 
	SQLSMALLINT nResult = 0;

	SQLSMALLINT cb;
	UWORD wConnectOption = SQL_DRIVER_COMPLETE; //SQL_DRIVER_NOPROMPT;
	QVarLengthArray<SQLTCHAR> connOut(1024);
	memset(connOut.data(), 0, connOut.size() * sizeof(SQLTCHAR));

	switch (connectionSource)
	{
		case Source:
			{// environment
				SQLHANDLE hEnv = SQL_NULL_HANDLE;
				SQLHANDLE hDbc = SQL_NULL_HANDLE;
				r = ::SQLAllocHandle(SQL_HANDLE_ENV, SQL_NULL_HANDLE, &hEnv);
				if (r == SQL_SUCCESS) isValid = true;

				foreach(nOdbcAttributesClass * k, this->m_OdbcAttributes_Map)
				{
					if (k->attributeType == enumAttributeType::hEnv)
					{
						r = ::SQLSetEnvAttr(hEnv, (SQLINTEGER) k->odbcKey, (SQLPOINTER)k->odbcValue, 0);
						if (r == SQL_SUCCESS) isValid = true;
					}
				}
				hEnv_Source = hEnv;

				r = SQLAllocHandle(SQL_HANDLE_DBC, hEnv, &hDbc);
				if (r == SQL_SUCCESS) isValid = true;
				foreach(nOdbcAttributesClass * k, this->m_OdbcAttributes_Map)
				{
					if (k->attributeType == enumAttributeType::hDbc)
					{
					r = ::SQLSetConnectAttr(hDbc, k->odbcKey, (SQLPOINTER)k->odbcValue, 0);
					if (k->odbcKey == SQL_ATTR_CONNECTION_POOLING && k->odbcValue == SQL_CP_ONE_PER_DRIVER) wConnectOption = SQL_DRIVER_NOPROMPT;
					if (k->odbcKey == SQL_ATTR_CONNECTION_POOLING && k->odbcValue == SQL_CP_ONE_PER_HENV) wConnectOption = SQL_DRIVER_NOPROMPT;
					if (k->odbcKey == SQL_ATTR_CONNECTION_POOLING && k->odbcValue == SQL_CP_DRIVER_AWARE) wConnectOption = SQL_DRIVER_NOPROMPT;
					if (r == SQL_SUCCESS) isValid = true;
					}
				}
				hDbc_source = hDbc;
				if (isValid)
				{
					r = ::SQLDriverConnect(
						hDbc,
						hWnd,
#ifdef UNICODE
						toSQLTCHAR(m_lpszSourceDSN).data(),
#else
						(SQLCHAR*)dsnSource.toUtf8().data(),
#endif
						(SQLSMALLINT)m_lpszSourceDSN.length(),
						connOut.data(),
						1024,
						&cb, 
						wConnectOption); 
					int colSize = cb / sizeof(SQLTCHAR);
					if (r != SQL_SUCCESS && r != SQL_SUCCESS_WITH_INFO)
					{
						QString check = qWarnODBCHandle(SQL_HANDLE_DBC, hDbc);
						qCritical(category) <<  check;
						m_bIsOpen = false;
					}
					m_bIsOpen = true;
				}
			} break;
		case Target:
			{
				SQLHANDLE hEnv = SQL_NULL_HANDLE;
				SQLHANDLE hDbc = SQL_NULL_HANDLE;
				r = ::SQLAllocHandle(SQL_HANDLE_ENV, SQL_NULL_HANDLE, &hEnv);
				if (r == SQL_SUCCESS) isValid = true;

				foreach(nOdbcAttributesClass * k, this->m_OdbcAttributes_Map)
				{
					if (k->attributeType == enumAttributeType::hEnv)
					{
						r = ::SQLSetEnvAttr(hEnv, (SQLINTEGER) k->odbcKey, (SQLPOINTER)k->odbcValue, 0);
						if (r == SQL_SUCCESS) isValid = true;
					}
				}
				hEnv_Target = hEnv;

				r = SQLAllocHandle(SQL_HANDLE_DBC, hEnv, &hDbc);
				if (r == SQL_SUCCESS) isValid = true;
				foreach(nOdbcAttributesClass * k, this->m_OdbcAttributes_Map)
				{
				if (k->attributeType == enumAttributeType::hDbc)
					{
					r = ::SQLSetConnectAttr(hDbc, k->odbcKey, (SQLPOINTER)k->odbcValue, 0);
					if (k->odbcKey == SQL_ATTR_CONNECTION_POOLING && k->odbcValue == SQL_CP_ONE_PER_DRIVER) wConnectOption = SQL_DRIVER_NOPROMPT;
					if (k->odbcKey == SQL_ATTR_CONNECTION_POOLING && k->odbcValue == SQL_CP_ONE_PER_HENV) wConnectOption = SQL_DRIVER_NOPROMPT;
					if (k->odbcKey == SQL_ATTR_CONNECTION_POOLING && k->odbcValue == SQL_CP_DRIVER_AWARE) wConnectOption = SQL_DRIVER_NOPROMPT;
					if (r == SQL_SUCCESS) isValid = true;
					}
				}
				hDbc_target = hDbc;
				if (isValid) {
					r = ::SQLDriverConnect(
						hDbc,
						hWnd,
#ifdef UNICODE
						toSQLTCHAR(m_lpszTargetDSN).data(),
#else
						(SQLCHAR*)m_lpszTargetDSN.toUtf8().data(),
#endif
						(SQLSMALLINT)m_lpszTargetDSN.length(),
						connOut.data(),
						1024,
						&cb, 
						wConnectOption); 
						int colSize = cb / sizeof(SQLTCHAR);
					if (r != SQL_SUCCESS && r != SQL_SUCCESS_WITH_INFO)
						{
							QString check = qWarnODBCHandle(SQL_HANDLE_DBC, hDbc);
							qCritical(category) <<  check;
							m_bIsOpen = false;
						}
							m_bIsOpen = true;
					}
			} break;
			default: break;
	}
}
TK_LTPBOMSET::TK_LTPBOMSET(QObject * parent) : QObject(parent) 
,tableName("TK_LTPBOMSET")
,m_dropOption(DropOption::DropTable) { 
	numRowsFetched = 0;
}

#pragma region ~CTOR TK_LTPBOMSET 
TK_LTPBOMSET::~TK_LTPBOMSET() { 

#pragma region Buffers - Clear 
	DB_ID.clear();
	NVTIMESTAMP.clear();
	OAREA.clear();
	OPAGE.clear();
	OLINE.clear();
	MAREA.clear();
	MPAGE.clear();
	MLINE.clear();
#pragma endregion Buffers - Clear 
}
#pragma endregion Destructor_TK_LTPBOMSET

// begin method functions
void TK_LTPBOMSET::setAbortFlag() { 
	QLoggingCategory category("classLibQ");
	qCInfo(category) << "isAbort was set to True";
	bIsAbort = true;
}

void TK_LTPBOMSET::run() { 
	process(1);
	QLoggingCategory category("classLibQ");
	qDebug(category) << "Entered;";
}

void	TK_LTPBOMSET::initOdbcAttributes()
{
	QLoggingCategory category("classLibQ");
	this->setProfileName(profileName);
	qDebug(category) << "Processing - TRKDB100"; 
	m_OdbcAttributesList = m_OdbcAttributes.split(","); 
	foreach(QString m, m_OdbcAttributesList)
	{
		QStringList keyValue = m.split("=");
		nOdbcAttributesClass * oM = new nOdbcAttributesClass(this);
		if (oM->loadToOdbc(keyValue.value(0), keyValue.value(1)))
		{
			m_OdbcAttributes_Map.insert(oM->odbcKey, oM);
		}
	}
}
void	TK_LTPBOMSET::initialize()
{
	QLoggingCategory category("classLibQ");
	RETCODE r;
	this->setProfileName(profileName);
	qDebug(category) << "Processing - TRKDB100"; 
//SQL Statements
//--------------------------------------------------

#pragma region Sql Statements_TK_LTPBOMSET

	fetchSql = "select  DB_ID, NVTIMESTAMP, OAREA, OPAGE, OLINE, MAREA, MPAGE, MLINE from TK_LTPBOMSET";
		if (m_ReplicationOption == ReplicationOption::NetChange)
		{
			fetchSql.append(" p1, nv_transfers p2 WHERE  p2.table_name = 'TK_LTPBOMSET' AND p1.nvtimestamp > p2.last_completed");
		}
	insertSql = "insert into TK_LTPBOMSET ( PLANT_CODE, NVTIMESTAMP, OAREA, OPAGE, OLINE, MAREA, MPAGE, MLINE ) values ( ?, ?, ?, ?, ?, ?, ?, ?)";
	updateSql = "update TK_LTPBOMSET set  PLANT_CODE = ?, NVTIMESTAMP = ?, OAREA = ?, OPAGE = ?, OLINE = ?, MAREA = ?, MPAGE = ?, MLINE = ?  where area = ? and page = ? line = ? ";

	qDebug(category) << "insertSQL - insert into TK_LTPBOMSET ( PLANT_CODE, NVTIMESTAMP, OAREA, OPAGE, OLINE, MAREA, MPAGE, MLINE ) values ( ?, ?, ?, ?, ?, ?, ?, ?)";
	qDebug(category) << "fetchSQL - select  DB_ID, NVTIMESTAMP, OAREA, OPAGE, OLINE, MAREA, MPAGE, MLINE from TK_LTPBOMSET";
	qDebug(category) << "unsertSQL - update TK_LTPBOMSET set  PLANT_CODE = ?, NVTIMESTAMP = ?, OAREA = ?, OPAGE = ?, OLINE = ?, MAREA = ?, MPAGE = ?, MLINE = ?  where area = ? and page = ? line = ? ";

#pragma endregion Sql Statements_TK_LTPBOMSET
	SQLHANDLE		insert_hStmt = SQL_NULL_HANDLE;
	SQLHANDLE		fetch_hStmt = SQL_NULL_HANDLE; 
	SQLHANDLE		update_hStmt = SQL_NULL_HANDLE; 
 
	r = ::SQLAllocHandle(SQL_HANDLE_STMT, hDbc_source, &fetch_hStmt);
	if (r != SQL_SUCCESS) {
		 qCCritical(category) << QString("Error  hDbc_Source SQLCode : %1 is %2").arg(QString::number( (long)hDbc_source)).arg(QString::number(r));
		return; 
	}
	r = ::SQLAllocHandle(SQL_HANDLE_STMT, hDbc_target, &insert_hStmt);
	if (r != SQL_SUCCESS) {
		 qCCritical(category) << QString("Error hDbc_Source -SQLCode: %1 is %2").arg(QString::number( (long)hDbc_target)).arg(QString::number(r));
		return; 
	}
	r = ::SQLAllocHandle(SQL_HANDLE_STMT, hDbc_target, &update_hStmt);
	if (r != SQL_SUCCESS) {
		 qCCritical(category) << QString("Error hDbc_Source +SQLCode: %1 is %2").arg(QString::number( (long)hDbc_target)).arg(QString::number(r));
		return; 
	}
 
	hStmt_Fetch = fetch_hStmt;
	hStmt_Insert = insert_hStmt;
	hStmt_Update = update_hStmt;
 
	SQLSetStmtAttr(hStmt_Fetch, SQL_ATTR_USE_BOOKMARKS, (SQLPOINTER)SQL_UB_OFF, 0);
	SQLSetStmtAttr(hStmt_Fetch, SQL_ATTR_ROW_BIND_TYPE, (SQLPOINTER)SQL_BIND_BY_COLUMN, 0);
	SQLSetStmtAttr(hStmt_Fetch, SQL_ATTR_ROW_ARRAY_SIZE, (SQLPOINTER)1, 0);
	SQLSetStmtAttr(hStmt_Fetch, SQL_ATTR_ROWS_FETCHED_PTR, &numRowsFetched, 0);

// Fields used by this class 
// ---------------------------------------------------

#pragma region Resize Fields TK_LTPBOMSET
	qDebug(category) << "Malloc - DB_ID[2]";
	DB_ID.resize(2);
	qDebug(category) << "Malloc - NVTIMESTAMP[23]";
	NVTIMESTAMP.resize(23);
	qDebug(category) << "Malloc - OAREA[2]";
	OAREA.resize(2);
	qDebug(category) << "Malloc - OPAGE[4]";
	OPAGE.resize(4);
	qDebug(category) << "Malloc - OLINE[2]";
	OLINE.resize(2);
	qDebug(category) << "Malloc - MAREA[2]";
	MAREA.resize(2);
	qDebug(category) << "Malloc - MPAGE[4]";
	MPAGE.resize(4);
	qDebug(category) << "Malloc - MLINE[2]";
	MLINE.resize(2);

#pragma endregion Resize Fields TK_LTPBOMSET
}
void TK_LTPBOMSET::close()
{
	QLoggingCategory category("classLibQ");
	if (m_bIsOpen)
	{
	qDebug(category) << "database is Open";
		SQLHANDLE source_hStmt = hStmt_Fetch;
		SQLHANDLE insert_hStmt = hStmt_Insert;
		SQLHANDLE hDb_S = this->hDbc_source;
		SQLHANDLE hDb_T = hDbc_target;
		SQLHANDLE hEnvS = hEnv_Source;
		SQLHANDLE hEnvT = hEnv_Target;
		RETCODE r;

		r = ::SQLFreeHandle(SQL_HANDLE_STMT, hStmt_Fetch);
		r = ::SQLFreeHandle(SQL_HANDLE_STMT, hStmt_Insert);
		r = ::SQLFreeHandle(SQL_HANDLE_STMT, hStmt_Update);
		if (hDbc_source != SQL_NULL_HANDLE) 		r = ::SQLDisconnect(hDb_S);
		if (hDbc_target != SQL_NULL_HANDLE) 		r = ::SQLDisconnect(hDb_T);

		r = ::SQLFreeHandle(SQL_HANDLE_DBC, hDb_S);
		r = ::SQLFreeHandle(SQL_HANDLE_DBC, hDb_T);
		r = ::SQLFreeHandle(SQL_HANDLE_ENV, hEnvS);
		r = ::SQLFreeHandle(SQL_HANDLE_ENV, hEnvT);
	}

	hEnv_Source = SQL_NULL_HANDLE;
	hEnv_Target = SQL_NULL_HANDLE;
	hEnv_Source = SQL_NULL_HANDLE;
	hEnv_Target = SQL_NULL_HANDLE;
	hStmt_Fetch = SQL_NULL_HANDLE;
	hStmt_Insert = SQL_NULL_HANDLE;
	hStmt_Update = SQL_NULL_HANDLE;
}

void TK_LTPBOMSET::open(const QString sourceDSN, const QString targetDSN)
{
	QLoggingCategory category("classLibQ");
	m_lpszTargetDSN = targetDSN;
	m_lpszSourceDSN = sourceDSN;
	qDebug(category) << QString("Source - %1[%2]").arg(sourceDSN);
	qDebug(category) << QString("Target - %1[%2]").arg(targetDSN);
}

void TK_LTPBOMSET::createTable()
{
	QLoggingCategory category("classLibQ");
	{
		QScopedPointer<nvTableOracleRdb> tbl(new nvTableOracleRdb(nullptr));
		tbl->initialize("TK_LTPBOMSET", this->m_lpszSourceDSN);
		QString newTbl = tbl->getCreateTableSQL();
		QScopedPointer<qVtExecute> vExec(new qVtExecute(nullptr));
		{
			vExec->initialize(m_lpszTargetDSN, " ", true);
			vExec->setOdbcAttributes(m_OdbcAttributes);
			vExec->ExecuteDirect(newTbl);
		}
	 qDebug(category) << QString("End Create Table %1 ").arg(tableName); 
	}
}

bool TK_LTPBOMSET::prepare()
{
	RETCODE r;
	QString check;
	QLoggingCategory category("classLibQ");
	 qDebug(category) << fetchSql;
	 qDebug(category) << insertSql;
#ifdef UNICODE
	r = SQLPrepare(hStmt_Insert,toSQLTCHAR(insertSql).data(),(SQLINTEGER)insertSql.length()); 
	if (r != SQL_SUCCESS) {
		check = qWarnODBCHandle(SQL_HANDLE_STMT, hStmt_Insert);
		 qCCritical(category) << QString("Prepare Statement-Insert : %1 is %2").arg(insertSql).arg(check);
		return false; 
	}
	r = SQLPrepare(hStmt_Update,toSQLTCHAR(updateSql).data(),(SQLINTEGER)updateSql.length()); 
	if (r != SQL_SUCCESS) {
		check = qWarnODBCHandle(SQL_HANDLE_STMT, hStmt_Update);
		 qCCritical(category) << QString("Prepare Statement-Update : %1 is %2").arg(updateSql).arg(check);
		return false; 
	}
	r = SQLPrepare(hStmt_Fetch,toSQLTCHAR(fetchSql).data(),(SQLINTEGER)fetchSql.length());
	if (r != SQL_SUCCESS) {
		check = qWarnODBCHandle(SQL_HANDLE_STMT, hStmt_Fetch);
		 qCCritical(category) << QString("Prepare Statement-Insert : %1 is %2").arg(fetchSql).arg(check);
		return false; 
	}
#else
	QByteArray queryI8 = insertSql.toUtf8();
	r = SQLPrepare(insert_hStmt,SQLCHAR*)queryI8.data(),(SQLINTEGER)queryI8.length());
	QByteArray queryU8 = fetchSql.toUtf8();
	r = SQLPrepare(hStmt_Fetch,(SQLCHAR*)queryU8.data(),(SQLINTEGER)queryU8.length());
#endif
	return true;

}

void TK_LTPBOMSET::prepareTargetTable()
{
	QLoggingCategory category("classLibQ");
	if (this->m_ReplicationOption == ReplicationOption::BulkCopy)
	{
		QScopedPointer<qVtExecute> execSql(new qVtExecute(nullptr));
		DropOption option = this->m_dropOption;
		switch (option)
		{
			case DropOption::DeleteFromTable:
			{
				QLoggingCategory category("classLibQ");
				execSql->initialize(this->m_lpszTargetDSN, "delete from TK_LTPBOMSET", true);
				execSql->setOdbcAttributes(this->m_OdbcAttributes);
				execSql->ExecuteDirect("delete from TK_LTPBOMSET");
			}break;
			case DropOption::TruncateTable:
			{
				execSql->initialize(this->m_lpszTargetDSN, "truncate table TK_LTPBOMSET", true);
				execSql->setOdbcAttributes(this->m_OdbcAttributes);
				execSql->ExecuteDirect("truncate table TK_LTPBOMSET");
			}break;
			case DropOption::DropTable:
			{
				execSql->initialize(this->m_lpszTargetDSN, "drop table TK_LTPBOMSET", true);
				execSql->setOdbcAttributes(this->m_OdbcAttributes);
				execSql->ExecuteDirect("drop table TK_LTPBOMSET");
				createTable();
			}break;
		}
	}
}

bool TK_LTPBOMSET::bindColumn()
{
	QLoggingCategory category("classLibQ");
	RETCODE r;
	bool isValid=true;
		 qDebug(category) << " Bindings: Ordinal [1] Type: 5 Buffer Size: 2 FieldName: DB_ID ";
		r = ::SQLBindCol(hStmt_Fetch, 1, 5, DB_ID.data(), 2, &cbDB_ID);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Bindings: Ordinal [2] Type: 93 Buffer Size: 23 FieldName: NVTIMESTAMP ";
		r = ::SQLBindCol(hStmt_Fetch, 2, 93, NVTIMESTAMP.data(), 23, &cbNVTIMESTAMP);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Bindings: Ordinal [3] Type: 5 Buffer Size: 2 FieldName: OAREA ";
		r = ::SQLBindCol(hStmt_Fetch, 3, 5, OAREA.data(), 2, &cbOAREA);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Bindings: Ordinal [4] Type: 4 Buffer Size: 4 FieldName: OPAGE ";
		r = ::SQLBindCol(hStmt_Fetch, 4, 4, OPAGE.data(), 4, &cbOPAGE);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Bindings: Ordinal [5] Type: 5 Buffer Size: 2 FieldName: OLINE ";
		r = ::SQLBindCol(hStmt_Fetch, 5, 5, OLINE.data(), 2, &cbOLINE);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Bindings: Ordinal [6] Type: 5 Buffer Size: 2 FieldName: MAREA ";
		r = ::SQLBindCol(hStmt_Fetch, 6, 5, MAREA.data(), 2, &cbMAREA);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Bindings: Ordinal [7] Type: 4 Buffer Size: 4 FieldName: MPAGE ";
		r = ::SQLBindCol(hStmt_Fetch, 7, 4, MPAGE.data(), 4, &cbMPAGE);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Bindings: Ordinal [8] Type: 5 Buffer Size: 2 FieldName: MLINE ";
		r = ::SQLBindCol(hStmt_Fetch, 8, 5, MLINE.data(), 2, &cbMLINE);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
	return isValid;
}

bool TK_LTPBOMSET::bindParameter()
{
	QLoggingCategory category("classLibQ");
	RETCODE r;
	bool isValid=true;
	{
		 qDebug(category) << " Parameters: Ordinal [1] Type: 5 Buffer Size: 2 FieldName: DB_ID ";
		r = SQLBindParameter(hStmt_Insert, 1, SQL_PARAM_INPUT, SQL_C_DEFAULT, 5, 0, 0, (SQLPOINTER)DB_ID.constData(), 0, &cbDB_ID);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Parameters: Ordinal [2] Type: 93 Buffer Size: 23 FieldName: NVTIMESTAMP ";
		r = SQLBindParameter(hStmt_Insert, 2, SQL_PARAM_INPUT, SQL_C_DEFAULT, 93, 23, 0, (SQLPOINTER)NVTIMESTAMP.constData(), 0, &cbNVTIMESTAMP);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Parameters: Ordinal [3] Type: 5 Buffer Size: 2 FieldName: OAREA ";
		r = SQLBindParameter(hStmt_Insert, 3, SQL_PARAM_INPUT, SQL_C_DEFAULT, 5, 0, 0, (SQLPOINTER)OAREA.constData(), 0, &cbOAREA);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Parameters: Ordinal [4] Type: 4 Buffer Size: 4 FieldName: OPAGE ";
		r = SQLBindParameter(hStmt_Insert, 4, SQL_PARAM_INPUT, SQL_C_DEFAULT, 4, 0, 0, (SQLPOINTER)OPAGE.constData(), 0, &cbOPAGE);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Parameters: Ordinal [5] Type: 5 Buffer Size: 2 FieldName: OLINE ";
		r = SQLBindParameter(hStmt_Insert, 5, SQL_PARAM_INPUT, SQL_C_DEFAULT, 5, 0, 0, (SQLPOINTER)OLINE.constData(), 0, &cbOLINE);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Parameters: Ordinal [6] Type: 5 Buffer Size: 2 FieldName: MAREA ";
		r = SQLBindParameter(hStmt_Insert, 6, SQL_PARAM_INPUT, SQL_C_DEFAULT, 5, 0, 0, (SQLPOINTER)MAREA.constData(), 0, &cbMAREA);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Parameters: Ordinal [7] Type: 4 Buffer Size: 4 FieldName: MPAGE ";
		r = SQLBindParameter(hStmt_Insert, 7, SQL_PARAM_INPUT, SQL_C_DEFAULT, 4, 0, 0, (SQLPOINTER)MPAGE.constData(), 0, &cbMPAGE);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Parameters: Ordinal [8] Type: 5 Buffer Size: 2 FieldName: MLINE ";
		r = SQLBindParameter(hStmt_Insert, 8, SQL_PARAM_INPUT, SQL_C_DEFAULT, 5, 0, 0, (SQLPOINTER)MLINE.constData(), 0, &cbMLINE);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
	}
	if (m_ReplicationOption == ReplicationOption::NetChange)
	{
		r = SQLBindParameter(hStmt_Update, 9, SQL_PARAM_INPUT, SQL_C_DEFAULT, 6, 0, 0, (SQLPOINTER)MAREA.constData(), 0, &cbMAREA);
		if (r == SQL_SUCCESS) { isValid=true; }
		r = SQLBindParameter(hStmt_Update, 10, SQL_PARAM_INPUT, SQL_C_DEFAULT, 7, 0, 0, (SQLPOINTER)MPAGE.constData(), 0, &cbMPAGE);
		if (r == SQL_SUCCESS) { isValid=true; }
		r = SQLBindParameter(hStmt_Update, 11, SQL_PARAM_INPUT, SQL_C_DEFAULT, 8, 0, 0, (SQLPOINTER)MLINE.constData(), 0, &cbMLINE);
		if (r == SQL_SUCCESS) { isValid=true; }
	// TK_LTPBOMSET is a well formed table for eNVy Replication 
		 qDebug(category) << " Parameters: Ordinal [6] 00 00 FieldName: MAREA ";
		 qDebug(category) << " Parameters: Ordinal [7] 00 00  FieldName: MPAGE ";
		 qDebug(category) << " Parameters: Ordinal [8] 00 00 FieldName:  MLINE ";
	} // 	if (m_ReplicationOption == ReplicationOption::NetChange)
	return isValid;
}

bool TK_LTPBOMSET::process(int rowSize)
{
	QLoggingCategory category("classLibQ");
	initOdbcAttributes();
	connect(Source);
	connect(Target);
	initialize();
	prepareTargetTable();
	prepare();
	bindColumn();
	bindParameter();
	copyTable();
	close();
	return false;
}

void TK_LTPBOMSET::copyTable()
{
	QLoggingCategory category("classLibQ");
	RETCODE r;
	QString check;
	r = SQLExecute(hStmt_Fetch);
		if (bIsAbort) {
			emit aborted(tableName, rowsFetched, rowsInserted, rowsUpdated);
			return;
		}
		while((r = SQLFetch(hStmt_Fetch)) != SQL_NO_DATA) {
		if (r != SQL_SUCCESS) {
			check = qWarnODBCHandle(SQL_HANDLE_STMT, hStmt_Fetch);
			qCCritical(category) << QString("SqlFetch - Error : %1 is %2").arg(fetchSql).arg(check);
			return;
		} 
		rowsFetched++;
		if (m_ReplicationOption == ReplicationOption::BulkCopy)
		{
			r = SQLExecute(hStmt_Insert);
			if (r == SQL_ERROR) {
				check = qWarnODBCHandle(SQL_HANDLE_STMT, hStmt_Insert);
				 qCCritical(category) << QString("SqlExecute:Insert - Error : %1 is %2").arg(insertSql).arg(check);
				return;
			}
			rowsInserted++;
			if ((rowsFetched % updateInterval) == 0) {
				qCInfo(category) << QString("[%1.%2]	Insertion: %3	Updates : %4	Fetched : %5").arg(profileName).arg(tableName).arg(rowsInserted).arg(rowsUpdated).arg(rowsFetched);
				emit updateStatusFetched(profileName, tableName, rowsFetched,rowsInserted,rowsUpdated);
			}
			if (m_ReplicationOption == ReplicationOption::NetChange)
			{
			r = SQLExecute(hStmt_Update);
			if (r != SQL_SUCCESS) {
				check = qWarnODBCHandle(SQL_HANDLE_STMT, hStmt_Update);
				 qCInfo(category)  << QString("SqlExecute:Update - Error : %1 is %2").arg(updateSql).arg(check);
				r = SQLExecute(hStmt_Insert);
				if (r != SQL_SUCCESS) {
					check = qWarnODBCHandle(SQL_HANDLE_STMT, hStmt_Insert);
					 qCritical(category) << QString("SqlExecute:Insert - Error : %1 is %2").arg(insertSql).arg(check);
					return;
				}
				else 	rowsInserted++;
				}
				else	rowsUpdated++;
			}
			emit updateStatusFetched(profileName, tableName, rowsFetched,rowsInserted,rowsUpdated);
		}
	} 
qCInfo(category) << QString("[%1.%2]	Insertion: %3	Updates : %4	Fetched : %5").arg(profileName).arg(tableName).arg(rowsInserted).arg(rowsUpdated).arg(rowsFetched);
}

void TK_LTPBOMSET::connect(connectionHandle connectionSource)
{

	QLoggingCategory category("classLibQ");
	RETCODE r;

	bool isValid = false;
	HWND	hWnd = nullptr;
	hWnd = ::GetDesktopWindow(); 
	SQLSMALLINT nResult = 0;

	SQLSMALLINT cb;
	UWORD wConnectOption = SQL_DRIVER_COMPLETE; //SQL_DRIVER_NOPROMPT;
	QVarLengthArray<SQLTCHAR> connOut(1024);
	memset(connOut.data(), 0, connOut.size() * sizeof(SQLTCHAR));

	switch (connectionSource)
	{
		case Source:
			{// environment
				SQLHANDLE hEnv = SQL_NULL_HANDLE;
				SQLHANDLE hDbc = SQL_NULL_HANDLE;
				r = ::SQLAllocHandle(SQL_HANDLE_ENV, SQL_NULL_HANDLE, &hEnv);
				if (r == SQL_SUCCESS) isValid = true;

				foreach(nOdbcAttributesClass * k, this->m_OdbcAttributes_Map)
				{
					if (k->attributeType == enumAttributeType::hEnv)
					{
						r = ::SQLSetEnvAttr(hEnv, (SQLINTEGER) k->odbcKey, (SQLPOINTER)k->odbcValue, 0);
						if (r == SQL_SUCCESS) isValid = true;
					}
				}
				hEnv_Source = hEnv;

				r = SQLAllocHandle(SQL_HANDLE_DBC, hEnv, &hDbc);
				if (r == SQL_SUCCESS) isValid = true;
				foreach(nOdbcAttributesClass * k, this->m_OdbcAttributes_Map)
				{
					if (k->attributeType == enumAttributeType::hDbc)
					{
					r = ::SQLSetConnectAttr(hDbc, k->odbcKey, (SQLPOINTER)k->odbcValue, 0);
					if (k->odbcKey == SQL_ATTR_CONNECTION_POOLING && k->odbcValue == SQL_CP_ONE_PER_DRIVER) wConnectOption = SQL_DRIVER_NOPROMPT;
					if (k->odbcKey == SQL_ATTR_CONNECTION_POOLING && k->odbcValue == SQL_CP_ONE_PER_HENV) wConnectOption = SQL_DRIVER_NOPROMPT;
					if (k->odbcKey == SQL_ATTR_CONNECTION_POOLING && k->odbcValue == SQL_CP_DRIVER_AWARE) wConnectOption = SQL_DRIVER_NOPROMPT;
					if (r == SQL_SUCCESS) isValid = true;
					}
				}
				hDbc_source = hDbc;
				if (isValid)
				{
					r = ::SQLDriverConnect(
						hDbc,
						hWnd,
#ifdef UNICODE
						toSQLTCHAR(m_lpszSourceDSN).data(),
#else
						(SQLCHAR*)dsnSource.toUtf8().data(),
#endif
						(SQLSMALLINT)m_lpszSourceDSN.length(),
						connOut.data(),
						1024,
						&cb, 
						wConnectOption); 
					int colSize = cb / sizeof(SQLTCHAR);
					if (r != SQL_SUCCESS && r != SQL_SUCCESS_WITH_INFO)
					{
						QString check = qWarnODBCHandle(SQL_HANDLE_DBC, hDbc);
						qCritical(category) <<  check;
						m_bIsOpen = false;
					}
					m_bIsOpen = true;
				}
			} break;
		case Target:
			{
				SQLHANDLE hEnv = SQL_NULL_HANDLE;
				SQLHANDLE hDbc = SQL_NULL_HANDLE;
				r = ::SQLAllocHandle(SQL_HANDLE_ENV, SQL_NULL_HANDLE, &hEnv);
				if (r == SQL_SUCCESS) isValid = true;

				foreach(nOdbcAttributesClass * k, this->m_OdbcAttributes_Map)
				{
					if (k->attributeType == enumAttributeType::hEnv)
					{
						r = ::SQLSetEnvAttr(hEnv, (SQLINTEGER) k->odbcKey, (SQLPOINTER)k->odbcValue, 0);
						if (r == SQL_SUCCESS) isValid = true;
					}
				}
				hEnv_Target = hEnv;

				r = SQLAllocHandle(SQL_HANDLE_DBC, hEnv, &hDbc);
				if (r == SQL_SUCCESS) isValid = true;
				foreach(nOdbcAttributesClass * k, this->m_OdbcAttributes_Map)
				{
				if (k->attributeType == enumAttributeType::hDbc)
					{
					r = ::SQLSetConnectAttr(hDbc, k->odbcKey, (SQLPOINTER)k->odbcValue, 0);
					if (k->odbcKey == SQL_ATTR_CONNECTION_POOLING && k->odbcValue == SQL_CP_ONE_PER_DRIVER) wConnectOption = SQL_DRIVER_NOPROMPT;
					if (k->odbcKey == SQL_ATTR_CONNECTION_POOLING && k->odbcValue == SQL_CP_ONE_PER_HENV) wConnectOption = SQL_DRIVER_NOPROMPT;
					if (k->odbcKey == SQL_ATTR_CONNECTION_POOLING && k->odbcValue == SQL_CP_DRIVER_AWARE) wConnectOption = SQL_DRIVER_NOPROMPT;
					if (r == SQL_SUCCESS) isValid = true;
					}
				}
				hDbc_target = hDbc;
				if (isValid) {
					r = ::SQLDriverConnect(
						hDbc,
						hWnd,
#ifdef UNICODE
						toSQLTCHAR(m_lpszTargetDSN).data(),
#else
						(SQLCHAR*)m_lpszTargetDSN.toUtf8().data(),
#endif
						(SQLSMALLINT)m_lpszTargetDSN.length(),
						connOut.data(),
						1024,
						&cb, 
						wConnectOption); 
						int colSize = cb / sizeof(SQLTCHAR);
					if (r != SQL_SUCCESS && r != SQL_SUCCESS_WITH_INFO)
						{
							QString check = qWarnODBCHandle(SQL_HANDLE_DBC, hDbc);
							qCritical(category) <<  check;
							m_bIsOpen = false;
						}
							m_bIsOpen = true;
					}
			} break;
			default: break;
	}
}
TK_LIDHSHSET::TK_LIDHSHSET(QObject * parent) : QObject(parent) 
,tableName("TK_LIDHSHSET")
,m_dropOption(DropOption::DropTable) { 
	numRowsFetched = 0;
}

#pragma region ~CTOR TK_LIDHSHSET 
TK_LIDHSHSET::~TK_LIDHSHSET() { 

#pragma region Buffers - Clear 
	DB_ID.clear();
	NVTIMESTAMP.clear();
	OAREA.clear();
	OPAGE.clear();
	OLINE.clear();
	MAREA.clear();
	MPAGE.clear();
	MLINE.clear();
#pragma endregion Buffers - Clear 
}
#pragma endregion Destructor_TK_LIDHSHSET

// begin method functions
void TK_LIDHSHSET::setAbortFlag() { 
	QLoggingCategory category("classLibQ");
	qCInfo(category) << "isAbort was set to True";
	bIsAbort = true;
}

void TK_LIDHSHSET::run() { 
	process(1);
	QLoggingCategory category("classLibQ");
	qDebug(category) << "Entered;";
}

void	TK_LIDHSHSET::initOdbcAttributes()
{
	QLoggingCategory category("classLibQ");
	this->setProfileName(profileName);
	qDebug(category) << "Processing - TRKDB100"; 
	m_OdbcAttributesList = m_OdbcAttributes.split(","); 
	foreach(QString m, m_OdbcAttributesList)
	{
		QStringList keyValue = m.split("=");
		nOdbcAttributesClass * oM = new nOdbcAttributesClass(this);
		if (oM->loadToOdbc(keyValue.value(0), keyValue.value(1)))
		{
			m_OdbcAttributes_Map.insert(oM->odbcKey, oM);
		}
	}
}
void	TK_LIDHSHSET::initialize()
{
	QLoggingCategory category("classLibQ");
	RETCODE r;
	this->setProfileName(profileName);
	qDebug(category) << "Processing - TRKDB100"; 
//SQL Statements
//--------------------------------------------------

#pragma region Sql Statements_TK_LIDHSHSET

	fetchSql = "select  DB_ID, NVTIMESTAMP, OAREA, OPAGE, OLINE, MAREA, MPAGE, MLINE from TK_LIDHSHSET";
		if (m_ReplicationOption == ReplicationOption::NetChange)
		{
			fetchSql.append(" p1, nv_transfers p2 WHERE  p2.table_name = 'TK_LIDHSHSET' AND p1.nvtimestamp > p2.last_completed");
		}
	insertSql = "insert into TK_LIDHSHSET ( PLANT_CODE, NVTIMESTAMP, OAREA, OPAGE, OLINE, MAREA, MPAGE, MLINE ) values ( ?, ?, ?, ?, ?, ?, ?, ?)";
	updateSql = "update TK_LIDHSHSET set  PLANT_CODE = ?, NVTIMESTAMP = ?, OAREA = ?, OPAGE = ?, OLINE = ?, MAREA = ?, MPAGE = ?, MLINE = ?  where area = ? and page = ? line = ? ";

	qDebug(category) << "insertSQL - insert into TK_LIDHSHSET ( PLANT_CODE, NVTIMESTAMP, OAREA, OPAGE, OLINE, MAREA, MPAGE, MLINE ) values ( ?, ?, ?, ?, ?, ?, ?, ?)";
	qDebug(category) << "fetchSQL - select  DB_ID, NVTIMESTAMP, OAREA, OPAGE, OLINE, MAREA, MPAGE, MLINE from TK_LIDHSHSET";
	qDebug(category) << "unsertSQL - update TK_LIDHSHSET set  PLANT_CODE = ?, NVTIMESTAMP = ?, OAREA = ?, OPAGE = ?, OLINE = ?, MAREA = ?, MPAGE = ?, MLINE = ?  where area = ? and page = ? line = ? ";

#pragma endregion Sql Statements_TK_LIDHSHSET
	SQLHANDLE		insert_hStmt = SQL_NULL_HANDLE;
	SQLHANDLE		fetch_hStmt = SQL_NULL_HANDLE; 
	SQLHANDLE		update_hStmt = SQL_NULL_HANDLE; 
 
	r = ::SQLAllocHandle(SQL_HANDLE_STMT, hDbc_source, &fetch_hStmt);
	if (r != SQL_SUCCESS) {
		 qCCritical(category) << QString("Error  hDbc_Source SQLCode : %1 is %2").arg(QString::number( (long)hDbc_source)).arg(QString::number(r));
		return; 
	}
	r = ::SQLAllocHandle(SQL_HANDLE_STMT, hDbc_target, &insert_hStmt);
	if (r != SQL_SUCCESS) {
		 qCCritical(category) << QString("Error hDbc_Source -SQLCode: %1 is %2").arg(QString::number( (long)hDbc_target)).arg(QString::number(r));
		return; 
	}
	r = ::SQLAllocHandle(SQL_HANDLE_STMT, hDbc_target, &update_hStmt);
	if (r != SQL_SUCCESS) {
		 qCCritical(category) << QString("Error hDbc_Source +SQLCode: %1 is %2").arg(QString::number( (long)hDbc_target)).arg(QString::number(r));
		return; 
	}
 
	hStmt_Fetch = fetch_hStmt;
	hStmt_Insert = insert_hStmt;
	hStmt_Update = update_hStmt;
 
	SQLSetStmtAttr(hStmt_Fetch, SQL_ATTR_USE_BOOKMARKS, (SQLPOINTER)SQL_UB_OFF, 0);
	SQLSetStmtAttr(hStmt_Fetch, SQL_ATTR_ROW_BIND_TYPE, (SQLPOINTER)SQL_BIND_BY_COLUMN, 0);
	SQLSetStmtAttr(hStmt_Fetch, SQL_ATTR_ROW_ARRAY_SIZE, (SQLPOINTER)1, 0);
	SQLSetStmtAttr(hStmt_Fetch, SQL_ATTR_ROWS_FETCHED_PTR, &numRowsFetched, 0);

// Fields used by this class 
// ---------------------------------------------------

#pragma region Resize Fields TK_LIDHSHSET
	qDebug(category) << "Malloc - DB_ID[2]";
	DB_ID.resize(2);
	qDebug(category) << "Malloc - NVTIMESTAMP[23]";
	NVTIMESTAMP.resize(23);
	qDebug(category) << "Malloc - OAREA[2]";
	OAREA.resize(2);
	qDebug(category) << "Malloc - OPAGE[4]";
	OPAGE.resize(4);
	qDebug(category) << "Malloc - OLINE[2]";
	OLINE.resize(2);
	qDebug(category) << "Malloc - MAREA[2]";
	MAREA.resize(2);
	qDebug(category) << "Malloc - MPAGE[4]";
	MPAGE.resize(4);
	qDebug(category) << "Malloc - MLINE[2]";
	MLINE.resize(2);

#pragma endregion Resize Fields TK_LIDHSHSET
}
void TK_LIDHSHSET::close()
{
	QLoggingCategory category("classLibQ");
	if (m_bIsOpen)
	{
	qDebug(category) << "database is Open";
		SQLHANDLE source_hStmt = hStmt_Fetch;
		SQLHANDLE insert_hStmt = hStmt_Insert;
		SQLHANDLE hDb_S = this->hDbc_source;
		SQLHANDLE hDb_T = hDbc_target;
		SQLHANDLE hEnvS = hEnv_Source;
		SQLHANDLE hEnvT = hEnv_Target;
		RETCODE r;

		r = ::SQLFreeHandle(SQL_HANDLE_STMT, hStmt_Fetch);
		r = ::SQLFreeHandle(SQL_HANDLE_STMT, hStmt_Insert);
		r = ::SQLFreeHandle(SQL_HANDLE_STMT, hStmt_Update);
		if (hDbc_source != SQL_NULL_HANDLE) 		r = ::SQLDisconnect(hDb_S);
		if (hDbc_target != SQL_NULL_HANDLE) 		r = ::SQLDisconnect(hDb_T);

		r = ::SQLFreeHandle(SQL_HANDLE_DBC, hDb_S);
		r = ::SQLFreeHandle(SQL_HANDLE_DBC, hDb_T);
		r = ::SQLFreeHandle(SQL_HANDLE_ENV, hEnvS);
		r = ::SQLFreeHandle(SQL_HANDLE_ENV, hEnvT);
	}

	hEnv_Source = SQL_NULL_HANDLE;
	hEnv_Target = SQL_NULL_HANDLE;
	hEnv_Source = SQL_NULL_HANDLE;
	hEnv_Target = SQL_NULL_HANDLE;
	hStmt_Fetch = SQL_NULL_HANDLE;
	hStmt_Insert = SQL_NULL_HANDLE;
	hStmt_Update = SQL_NULL_HANDLE;
}

void TK_LIDHSHSET::open(const QString sourceDSN, const QString targetDSN)
{
	QLoggingCategory category("classLibQ");
	m_lpszTargetDSN = targetDSN;
	m_lpszSourceDSN = sourceDSN;
	qDebug(category) << QString("Source - %1[%2]").arg(sourceDSN);
	qDebug(category) << QString("Target - %1[%2]").arg(targetDSN);
}

void TK_LIDHSHSET::createTable()
{
	QLoggingCategory category("classLibQ");
	{
		QScopedPointer<nvTableOracleRdb> tbl(new nvTableOracleRdb(nullptr));
		tbl->initialize("TK_LIDHSHSET", this->m_lpszSourceDSN);
		QString newTbl = tbl->getCreateTableSQL();
		QScopedPointer<qVtExecute> vExec(new qVtExecute(nullptr));
		{
			vExec->initialize(m_lpszTargetDSN, " ", true);
			vExec->setOdbcAttributes(m_OdbcAttributes);
			vExec->ExecuteDirect(newTbl);
		}
	 qDebug(category) << QString("End Create Table %1 ").arg(tableName); 
	}
}

bool TK_LIDHSHSET::prepare()
{
	RETCODE r;
	QString check;
	QLoggingCategory category("classLibQ");
	 qDebug(category) << fetchSql;
	 qDebug(category) << insertSql;
#ifdef UNICODE
	r = SQLPrepare(hStmt_Insert,toSQLTCHAR(insertSql).data(),(SQLINTEGER)insertSql.length()); 
	if (r != SQL_SUCCESS) {
		check = qWarnODBCHandle(SQL_HANDLE_STMT, hStmt_Insert);
		 qCCritical(category) << QString("Prepare Statement-Insert : %1 is %2").arg(insertSql).arg(check);
		return false; 
	}
	r = SQLPrepare(hStmt_Update,toSQLTCHAR(updateSql).data(),(SQLINTEGER)updateSql.length()); 
	if (r != SQL_SUCCESS) {
		check = qWarnODBCHandle(SQL_HANDLE_STMT, hStmt_Update);
		 qCCritical(category) << QString("Prepare Statement-Update : %1 is %2").arg(updateSql).arg(check);
		return false; 
	}
	r = SQLPrepare(hStmt_Fetch,toSQLTCHAR(fetchSql).data(),(SQLINTEGER)fetchSql.length());
	if (r != SQL_SUCCESS) {
		check = qWarnODBCHandle(SQL_HANDLE_STMT, hStmt_Fetch);
		 qCCritical(category) << QString("Prepare Statement-Insert : %1 is %2").arg(fetchSql).arg(check);
		return false; 
	}
#else
	QByteArray queryI8 = insertSql.toUtf8();
	r = SQLPrepare(insert_hStmt,SQLCHAR*)queryI8.data(),(SQLINTEGER)queryI8.length());
	QByteArray queryU8 = fetchSql.toUtf8();
	r = SQLPrepare(hStmt_Fetch,(SQLCHAR*)queryU8.data(),(SQLINTEGER)queryU8.length());
#endif
	return true;

}

void TK_LIDHSHSET::prepareTargetTable()
{
	QLoggingCategory category("classLibQ");
	if (this->m_ReplicationOption == ReplicationOption::BulkCopy)
	{
		QScopedPointer<qVtExecute> execSql(new qVtExecute(nullptr));
		DropOption option = this->m_dropOption;
		switch (option)
		{
			case DropOption::DeleteFromTable:
			{
				QLoggingCategory category("classLibQ");
				execSql->initialize(this->m_lpszTargetDSN, "delete from TK_LIDHSHSET", true);
				execSql->setOdbcAttributes(this->m_OdbcAttributes);
				execSql->ExecuteDirect("delete from TK_LIDHSHSET");
			}break;
			case DropOption::TruncateTable:
			{
				execSql->initialize(this->m_lpszTargetDSN, "truncate table TK_LIDHSHSET", true);
				execSql->setOdbcAttributes(this->m_OdbcAttributes);
				execSql->ExecuteDirect("truncate table TK_LIDHSHSET");
			}break;
			case DropOption::DropTable:
			{
				execSql->initialize(this->m_lpszTargetDSN, "drop table TK_LIDHSHSET", true);
				execSql->setOdbcAttributes(this->m_OdbcAttributes);
				execSql->ExecuteDirect("drop table TK_LIDHSHSET");
				createTable();
			}break;
		}
	}
}

bool TK_LIDHSHSET::bindColumn()
{
	QLoggingCategory category("classLibQ");
	RETCODE r;
	bool isValid=true;
		 qDebug(category) << " Bindings: Ordinal [1] Type: 5 Buffer Size: 2 FieldName: DB_ID ";
		r = ::SQLBindCol(hStmt_Fetch, 1, 5, DB_ID.data(), 2, &cbDB_ID);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Bindings: Ordinal [2] Type: 93 Buffer Size: 23 FieldName: NVTIMESTAMP ";
		r = ::SQLBindCol(hStmt_Fetch, 2, 93, NVTIMESTAMP.data(), 23, &cbNVTIMESTAMP);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Bindings: Ordinal [3] Type: 5 Buffer Size: 2 FieldName: OAREA ";
		r = ::SQLBindCol(hStmt_Fetch, 3, 5, OAREA.data(), 2, &cbOAREA);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Bindings: Ordinal [4] Type: 4 Buffer Size: 4 FieldName: OPAGE ";
		r = ::SQLBindCol(hStmt_Fetch, 4, 4, OPAGE.data(), 4, &cbOPAGE);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Bindings: Ordinal [5] Type: 5 Buffer Size: 2 FieldName: OLINE ";
		r = ::SQLBindCol(hStmt_Fetch, 5, 5, OLINE.data(), 2, &cbOLINE);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Bindings: Ordinal [6] Type: 5 Buffer Size: 2 FieldName: MAREA ";
		r = ::SQLBindCol(hStmt_Fetch, 6, 5, MAREA.data(), 2, &cbMAREA);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Bindings: Ordinal [7] Type: 4 Buffer Size: 4 FieldName: MPAGE ";
		r = ::SQLBindCol(hStmt_Fetch, 7, 4, MPAGE.data(), 4, &cbMPAGE);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Bindings: Ordinal [8] Type: 5 Buffer Size: 2 FieldName: MLINE ";
		r = ::SQLBindCol(hStmt_Fetch, 8, 5, MLINE.data(), 2, &cbMLINE);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
	return isValid;
}

bool TK_LIDHSHSET::bindParameter()
{
	QLoggingCategory category("classLibQ");
	RETCODE r;
	bool isValid=true;
	{
		 qDebug(category) << " Parameters: Ordinal [1] Type: 5 Buffer Size: 2 FieldName: DB_ID ";
		r = SQLBindParameter(hStmt_Insert, 1, SQL_PARAM_INPUT, SQL_C_DEFAULT, 5, 0, 0, (SQLPOINTER)DB_ID.constData(), 0, &cbDB_ID);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Parameters: Ordinal [2] Type: 93 Buffer Size: 23 FieldName: NVTIMESTAMP ";
		r = SQLBindParameter(hStmt_Insert, 2, SQL_PARAM_INPUT, SQL_C_DEFAULT, 93, 23, 0, (SQLPOINTER)NVTIMESTAMP.constData(), 0, &cbNVTIMESTAMP);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Parameters: Ordinal [3] Type: 5 Buffer Size: 2 FieldName: OAREA ";
		r = SQLBindParameter(hStmt_Insert, 3, SQL_PARAM_INPUT, SQL_C_DEFAULT, 5, 0, 0, (SQLPOINTER)OAREA.constData(), 0, &cbOAREA);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Parameters: Ordinal [4] Type: 4 Buffer Size: 4 FieldName: OPAGE ";
		r = SQLBindParameter(hStmt_Insert, 4, SQL_PARAM_INPUT, SQL_C_DEFAULT, 4, 0, 0, (SQLPOINTER)OPAGE.constData(), 0, &cbOPAGE);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Parameters: Ordinal [5] Type: 5 Buffer Size: 2 FieldName: OLINE ";
		r = SQLBindParameter(hStmt_Insert, 5, SQL_PARAM_INPUT, SQL_C_DEFAULT, 5, 0, 0, (SQLPOINTER)OLINE.constData(), 0, &cbOLINE);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Parameters: Ordinal [6] Type: 5 Buffer Size: 2 FieldName: MAREA ";
		r = SQLBindParameter(hStmt_Insert, 6, SQL_PARAM_INPUT, SQL_C_DEFAULT, 5, 0, 0, (SQLPOINTER)MAREA.constData(), 0, &cbMAREA);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Parameters: Ordinal [7] Type: 4 Buffer Size: 4 FieldName: MPAGE ";
		r = SQLBindParameter(hStmt_Insert, 7, SQL_PARAM_INPUT, SQL_C_DEFAULT, 4, 0, 0, (SQLPOINTER)MPAGE.constData(), 0, &cbMPAGE);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Parameters: Ordinal [8] Type: 5 Buffer Size: 2 FieldName: MLINE ";
		r = SQLBindParameter(hStmt_Insert, 8, SQL_PARAM_INPUT, SQL_C_DEFAULT, 5, 0, 0, (SQLPOINTER)MLINE.constData(), 0, &cbMLINE);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
	}
	if (m_ReplicationOption == ReplicationOption::NetChange)
	{
		r = SQLBindParameter(hStmt_Update, 9, SQL_PARAM_INPUT, SQL_C_DEFAULT, 6, 0, 0, (SQLPOINTER)MAREA.constData(), 0, &cbMAREA);
		if (r == SQL_SUCCESS) { isValid=true; }
		r = SQLBindParameter(hStmt_Update, 10, SQL_PARAM_INPUT, SQL_C_DEFAULT, 7, 0, 0, (SQLPOINTER)MPAGE.constData(), 0, &cbMPAGE);
		if (r == SQL_SUCCESS) { isValid=true; }
		r = SQLBindParameter(hStmt_Update, 11, SQL_PARAM_INPUT, SQL_C_DEFAULT, 8, 0, 0, (SQLPOINTER)MLINE.constData(), 0, &cbMLINE);
		if (r == SQL_SUCCESS) { isValid=true; }
	// TK_LIDHSHSET is a well formed table for eNVy Replication 
		 qDebug(category) << " Parameters: Ordinal [6] 00 00 FieldName: MAREA ";
		 qDebug(category) << " Parameters: Ordinal [7] 00 00  FieldName: MPAGE ";
		 qDebug(category) << " Parameters: Ordinal [8] 00 00 FieldName:  MLINE ";
	} // 	if (m_ReplicationOption == ReplicationOption::NetChange)
	return isValid;
}

bool TK_LIDHSHSET::process(int rowSize)
{
	QLoggingCategory category("classLibQ");
	initOdbcAttributes();
	connect(Source);
	connect(Target);
	initialize();
	prepareTargetTable();
	prepare();
	bindColumn();
	bindParameter();
	copyTable();
	close();
	return false;
}

void TK_LIDHSHSET::copyTable()
{
	QLoggingCategory category("classLibQ");
	RETCODE r;
	QString check;
	r = SQLExecute(hStmt_Fetch);
		if (bIsAbort) {
			emit aborted(tableName, rowsFetched, rowsInserted, rowsUpdated);
			return;
		}
		while((r = SQLFetch(hStmt_Fetch)) != SQL_NO_DATA) {
		if (r != SQL_SUCCESS) {
			check = qWarnODBCHandle(SQL_HANDLE_STMT, hStmt_Fetch);
			qCCritical(category) << QString("SqlFetch - Error : %1 is %2").arg(fetchSql).arg(check);
			return;
		} 
		rowsFetched++;
		if (m_ReplicationOption == ReplicationOption::BulkCopy)
		{
			r = SQLExecute(hStmt_Insert);
			if (r == SQL_ERROR) {
				check = qWarnODBCHandle(SQL_HANDLE_STMT, hStmt_Insert);
				 qCCritical(category) << QString("SqlExecute:Insert - Error : %1 is %2").arg(insertSql).arg(check);
				return;
			}
			rowsInserted++;
			if ((rowsFetched % updateInterval) == 0) {
				qCInfo(category) << QString("[%1.%2]	Insertion: %3	Updates : %4	Fetched : %5").arg(profileName).arg(tableName).arg(rowsInserted).arg(rowsUpdated).arg(rowsFetched);
				emit updateStatusFetched(profileName, tableName, rowsFetched,rowsInserted,rowsUpdated);
			}
			if (m_ReplicationOption == ReplicationOption::NetChange)
			{
			r = SQLExecute(hStmt_Update);
			if (r != SQL_SUCCESS) {
				check = qWarnODBCHandle(SQL_HANDLE_STMT, hStmt_Update);
				 qCInfo(category)  << QString("SqlExecute:Update - Error : %1 is %2").arg(updateSql).arg(check);
				r = SQLExecute(hStmt_Insert);
				if (r != SQL_SUCCESS) {
					check = qWarnODBCHandle(SQL_HANDLE_STMT, hStmt_Insert);
					 qCritical(category) << QString("SqlExecute:Insert - Error : %1 is %2").arg(insertSql).arg(check);
					return;
				}
				else 	rowsInserted++;
				}
				else	rowsUpdated++;
			}
			emit updateStatusFetched(profileName, tableName, rowsFetched,rowsInserted,rowsUpdated);
		}
	} 
qCInfo(category) << QString("[%1.%2]	Insertion: %3	Updates : %4	Fetched : %5").arg(profileName).arg(tableName).arg(rowsInserted).arg(rowsUpdated).arg(rowsFetched);
}

void TK_LIDHSHSET::connect(connectionHandle connectionSource)
{

	QLoggingCategory category("classLibQ");
	RETCODE r;

	bool isValid = false;
	HWND	hWnd = nullptr;
	hWnd = ::GetDesktopWindow(); 
	SQLSMALLINT nResult = 0;

	SQLSMALLINT cb;
	UWORD wConnectOption = SQL_DRIVER_COMPLETE; //SQL_DRIVER_NOPROMPT;
	QVarLengthArray<SQLTCHAR> connOut(1024);
	memset(connOut.data(), 0, connOut.size() * sizeof(SQLTCHAR));

	switch (connectionSource)
	{
		case Source:
			{// environment
				SQLHANDLE hEnv = SQL_NULL_HANDLE;
				SQLHANDLE hDbc = SQL_NULL_HANDLE;
				r = ::SQLAllocHandle(SQL_HANDLE_ENV, SQL_NULL_HANDLE, &hEnv);
				if (r == SQL_SUCCESS) isValid = true;

				foreach(nOdbcAttributesClass * k, this->m_OdbcAttributes_Map)
				{
					if (k->attributeType == enumAttributeType::hEnv)
					{
						r = ::SQLSetEnvAttr(hEnv, (SQLINTEGER) k->odbcKey, (SQLPOINTER)k->odbcValue, 0);
						if (r == SQL_SUCCESS) isValid = true;
					}
				}
				hEnv_Source = hEnv;

				r = SQLAllocHandle(SQL_HANDLE_DBC, hEnv, &hDbc);
				if (r == SQL_SUCCESS) isValid = true;
				foreach(nOdbcAttributesClass * k, this->m_OdbcAttributes_Map)
				{
					if (k->attributeType == enumAttributeType::hDbc)
					{
					r = ::SQLSetConnectAttr(hDbc, k->odbcKey, (SQLPOINTER)k->odbcValue, 0);
					if (k->odbcKey == SQL_ATTR_CONNECTION_POOLING && k->odbcValue == SQL_CP_ONE_PER_DRIVER) wConnectOption = SQL_DRIVER_NOPROMPT;
					if (k->odbcKey == SQL_ATTR_CONNECTION_POOLING && k->odbcValue == SQL_CP_ONE_PER_HENV) wConnectOption = SQL_DRIVER_NOPROMPT;
					if (k->odbcKey == SQL_ATTR_CONNECTION_POOLING && k->odbcValue == SQL_CP_DRIVER_AWARE) wConnectOption = SQL_DRIVER_NOPROMPT;
					if (r == SQL_SUCCESS) isValid = true;
					}
				}
				hDbc_source = hDbc;
				if (isValid)
				{
					r = ::SQLDriverConnect(
						hDbc,
						hWnd,
#ifdef UNICODE
						toSQLTCHAR(m_lpszSourceDSN).data(),
#else
						(SQLCHAR*)dsnSource.toUtf8().data(),
#endif
						(SQLSMALLINT)m_lpszSourceDSN.length(),
						connOut.data(),
						1024,
						&cb, 
						wConnectOption); 
					int colSize = cb / sizeof(SQLTCHAR);
					if (r != SQL_SUCCESS && r != SQL_SUCCESS_WITH_INFO)
					{
						QString check = qWarnODBCHandle(SQL_HANDLE_DBC, hDbc);
						qCritical(category) <<  check;
						m_bIsOpen = false;
					}
					m_bIsOpen = true;
				}
			} break;
		case Target:
			{
				SQLHANDLE hEnv = SQL_NULL_HANDLE;
				SQLHANDLE hDbc = SQL_NULL_HANDLE;
				r = ::SQLAllocHandle(SQL_HANDLE_ENV, SQL_NULL_HANDLE, &hEnv);
				if (r == SQL_SUCCESS) isValid = true;

				foreach(nOdbcAttributesClass * k, this->m_OdbcAttributes_Map)
				{
					if (k->attributeType == enumAttributeType::hEnv)
					{
						r = ::SQLSetEnvAttr(hEnv, (SQLINTEGER) k->odbcKey, (SQLPOINTER)k->odbcValue, 0);
						if (r == SQL_SUCCESS) isValid = true;
					}
				}
				hEnv_Target = hEnv;

				r = SQLAllocHandle(SQL_HANDLE_DBC, hEnv, &hDbc);
				if (r == SQL_SUCCESS) isValid = true;
				foreach(nOdbcAttributesClass * k, this->m_OdbcAttributes_Map)
				{
				if (k->attributeType == enumAttributeType::hDbc)
					{
					r = ::SQLSetConnectAttr(hDbc, k->odbcKey, (SQLPOINTER)k->odbcValue, 0);
					if (k->odbcKey == SQL_ATTR_CONNECTION_POOLING && k->odbcValue == SQL_CP_ONE_PER_DRIVER) wConnectOption = SQL_DRIVER_NOPROMPT;
					if (k->odbcKey == SQL_ATTR_CONNECTION_POOLING && k->odbcValue == SQL_CP_ONE_PER_HENV) wConnectOption = SQL_DRIVER_NOPROMPT;
					if (k->odbcKey == SQL_ATTR_CONNECTION_POOLING && k->odbcValue == SQL_CP_DRIVER_AWARE) wConnectOption = SQL_DRIVER_NOPROMPT;
					if (r == SQL_SUCCESS) isValid = true;
					}
				}
				hDbc_target = hDbc;
				if (isValid) {
					r = ::SQLDriverConnect(
						hDbc,
						hWnd,
#ifdef UNICODE
						toSQLTCHAR(m_lpszTargetDSN).data(),
#else
						(SQLCHAR*)m_lpszTargetDSN.toUtf8().data(),
#endif
						(SQLSMALLINT)m_lpszTargetDSN.length(),
						connOut.data(),
						1024,
						&cb, 
						wConnectOption); 
						int colSize = cb / sizeof(SQLTCHAR);
					if (r != SQL_SUCCESS && r != SQL_SUCCESS_WITH_INFO)
						{
							QString check = qWarnODBCHandle(SQL_HANDLE_DBC, hDbc);
							qCritical(category) <<  check;
							m_bIsOpen = false;
						}
							m_bIsOpen = true;
					}
			} break;
			default: break;
	}
}
TK_LIDLTPSET::TK_LIDLTPSET(QObject * parent) : QObject(parent) 
,tableName("TK_LIDLTPSET")
,m_dropOption(DropOption::DropTable) { 
	numRowsFetched = 0;
}

#pragma region ~CTOR TK_LIDLTPSET 
TK_LIDLTPSET::~TK_LIDLTPSET() { 

#pragma region Buffers - Clear 
	DB_ID.clear();
	NVTIMESTAMP.clear();
	OAREA.clear();
	OPAGE.clear();
	OLINE.clear();
	MAREA.clear();
	MPAGE.clear();
	MLINE.clear();
#pragma endregion Buffers - Clear 
}
#pragma endregion Destructor_TK_LIDLTPSET

// begin method functions
void TK_LIDLTPSET::setAbortFlag() { 
	QLoggingCategory category("classLibQ");
	qCInfo(category) << "isAbort was set to True";
	bIsAbort = true;
}

void TK_LIDLTPSET::run() { 
	process(1);
	QLoggingCategory category("classLibQ");
	qDebug(category) << "Entered;";
}

void	TK_LIDLTPSET::initOdbcAttributes()
{
	QLoggingCategory category("classLibQ");
	this->setProfileName(profileName);
	qDebug(category) << "Processing - TRKDB100"; 
	m_OdbcAttributesList = m_OdbcAttributes.split(","); 
	foreach(QString m, m_OdbcAttributesList)
	{
		QStringList keyValue = m.split("=");
		nOdbcAttributesClass * oM = new nOdbcAttributesClass(this);
		if (oM->loadToOdbc(keyValue.value(0), keyValue.value(1)))
		{
			m_OdbcAttributes_Map.insert(oM->odbcKey, oM);
		}
	}
}
void	TK_LIDLTPSET::initialize()
{
	QLoggingCategory category("classLibQ");
	RETCODE r;
	this->setProfileName(profileName);
	qDebug(category) << "Processing - TRKDB100"; 
//SQL Statements
//--------------------------------------------------

#pragma region Sql Statements_TK_LIDLTPSET

	fetchSql = "select  DB_ID, NVTIMESTAMP, OAREA, OPAGE, OLINE, MAREA, MPAGE, MLINE from TK_LIDLTPSET";
		if (m_ReplicationOption == ReplicationOption::NetChange)
		{
			fetchSql.append(" p1, nv_transfers p2 WHERE  p2.table_name = 'TK_LIDLTPSET' AND p1.nvtimestamp > p2.last_completed");
		}
	insertSql = "insert into TK_LIDLTPSET ( PLANT_CODE, NVTIMESTAMP, OAREA, OPAGE, OLINE, MAREA, MPAGE, MLINE ) values ( ?, ?, ?, ?, ?, ?, ?, ?)";
	updateSql = "update TK_LIDLTPSET set  PLANT_CODE = ?, NVTIMESTAMP = ?, OAREA = ?, OPAGE = ?, OLINE = ?, MAREA = ?, MPAGE = ?, MLINE = ?  where area = ? and page = ? line = ? ";

	qDebug(category) << "insertSQL - insert into TK_LIDLTPSET ( PLANT_CODE, NVTIMESTAMP, OAREA, OPAGE, OLINE, MAREA, MPAGE, MLINE ) values ( ?, ?, ?, ?, ?, ?, ?, ?)";
	qDebug(category) << "fetchSQL - select  DB_ID, NVTIMESTAMP, OAREA, OPAGE, OLINE, MAREA, MPAGE, MLINE from TK_LIDLTPSET";
	qDebug(category) << "unsertSQL - update TK_LIDLTPSET set  PLANT_CODE = ?, NVTIMESTAMP = ?, OAREA = ?, OPAGE = ?, OLINE = ?, MAREA = ?, MPAGE = ?, MLINE = ?  where area = ? and page = ? line = ? ";

#pragma endregion Sql Statements_TK_LIDLTPSET
	SQLHANDLE		insert_hStmt = SQL_NULL_HANDLE;
	SQLHANDLE		fetch_hStmt = SQL_NULL_HANDLE; 
	SQLHANDLE		update_hStmt = SQL_NULL_HANDLE; 
 
	r = ::SQLAllocHandle(SQL_HANDLE_STMT, hDbc_source, &fetch_hStmt);
	if (r != SQL_SUCCESS) {
		 qCCritical(category) << QString("Error  hDbc_Source SQLCode : %1 is %2").arg(QString::number( (long)hDbc_source)).arg(QString::number(r));
		return; 
	}
	r = ::SQLAllocHandle(SQL_HANDLE_STMT, hDbc_target, &insert_hStmt);
	if (r != SQL_SUCCESS) {
		 qCCritical(category) << QString("Error hDbc_Source -SQLCode: %1 is %2").arg(QString::number( (long)hDbc_target)).arg(QString::number(r));
		return; 
	}
	r = ::SQLAllocHandle(SQL_HANDLE_STMT, hDbc_target, &update_hStmt);
	if (r != SQL_SUCCESS) {
		 qCCritical(category) << QString("Error hDbc_Source +SQLCode: %1 is %2").arg(QString::number( (long)hDbc_target)).arg(QString::number(r));
		return; 
	}
 
	hStmt_Fetch = fetch_hStmt;
	hStmt_Insert = insert_hStmt;
	hStmt_Update = update_hStmt;
 
	SQLSetStmtAttr(hStmt_Fetch, SQL_ATTR_USE_BOOKMARKS, (SQLPOINTER)SQL_UB_OFF, 0);
	SQLSetStmtAttr(hStmt_Fetch, SQL_ATTR_ROW_BIND_TYPE, (SQLPOINTER)SQL_BIND_BY_COLUMN, 0);
	SQLSetStmtAttr(hStmt_Fetch, SQL_ATTR_ROW_ARRAY_SIZE, (SQLPOINTER)1, 0);
	SQLSetStmtAttr(hStmt_Fetch, SQL_ATTR_ROWS_FETCHED_PTR, &numRowsFetched, 0);

// Fields used by this class 
// ---------------------------------------------------

#pragma region Resize Fields TK_LIDLTPSET
	qDebug(category) << "Malloc - DB_ID[2]";
	DB_ID.resize(2);
	qDebug(category) << "Malloc - NVTIMESTAMP[23]";
	NVTIMESTAMP.resize(23);
	qDebug(category) << "Malloc - OAREA[2]";
	OAREA.resize(2);
	qDebug(category) << "Malloc - OPAGE[4]";
	OPAGE.resize(4);
	qDebug(category) << "Malloc - OLINE[2]";
	OLINE.resize(2);
	qDebug(category) << "Malloc - MAREA[2]";
	MAREA.resize(2);
	qDebug(category) << "Malloc - MPAGE[4]";
	MPAGE.resize(4);
	qDebug(category) << "Malloc - MLINE[2]";
	MLINE.resize(2);

#pragma endregion Resize Fields TK_LIDLTPSET
}
void TK_LIDLTPSET::close()
{
	QLoggingCategory category("classLibQ");
	if (m_bIsOpen)
	{
	qDebug(category) << "database is Open";
		SQLHANDLE source_hStmt = hStmt_Fetch;
		SQLHANDLE insert_hStmt = hStmt_Insert;
		SQLHANDLE hDb_S = this->hDbc_source;
		SQLHANDLE hDb_T = hDbc_target;
		SQLHANDLE hEnvS = hEnv_Source;
		SQLHANDLE hEnvT = hEnv_Target;
		RETCODE r;

		r = ::SQLFreeHandle(SQL_HANDLE_STMT, hStmt_Fetch);
		r = ::SQLFreeHandle(SQL_HANDLE_STMT, hStmt_Insert);
		r = ::SQLFreeHandle(SQL_HANDLE_STMT, hStmt_Update);
		if (hDbc_source != SQL_NULL_HANDLE) 		r = ::SQLDisconnect(hDb_S);
		if (hDbc_target != SQL_NULL_HANDLE) 		r = ::SQLDisconnect(hDb_T);

		r = ::SQLFreeHandle(SQL_HANDLE_DBC, hDb_S);
		r = ::SQLFreeHandle(SQL_HANDLE_DBC, hDb_T);
		r = ::SQLFreeHandle(SQL_HANDLE_ENV, hEnvS);
		r = ::SQLFreeHandle(SQL_HANDLE_ENV, hEnvT);
	}

	hEnv_Source = SQL_NULL_HANDLE;
	hEnv_Target = SQL_NULL_HANDLE;
	hEnv_Source = SQL_NULL_HANDLE;
	hEnv_Target = SQL_NULL_HANDLE;
	hStmt_Fetch = SQL_NULL_HANDLE;
	hStmt_Insert = SQL_NULL_HANDLE;
	hStmt_Update = SQL_NULL_HANDLE;
}

void TK_LIDLTPSET::open(const QString sourceDSN, const QString targetDSN)
{
	QLoggingCategory category("classLibQ");
	m_lpszTargetDSN = targetDSN;
	m_lpszSourceDSN = sourceDSN;
	qDebug(category) << QString("Source - %1[%2]").arg(sourceDSN);
	qDebug(category) << QString("Target - %1[%2]").arg(targetDSN);
}

void TK_LIDLTPSET::createTable()
{
	QLoggingCategory category("classLibQ");
	{
		QScopedPointer<nvTableOracleRdb> tbl(new nvTableOracleRdb(nullptr));
		tbl->initialize("TK_LIDLTPSET", this->m_lpszSourceDSN);
		QString newTbl = tbl->getCreateTableSQL();
		QScopedPointer<qVtExecute> vExec(new qVtExecute(nullptr));
		{
			vExec->initialize(m_lpszTargetDSN, " ", true);
			vExec->setOdbcAttributes(m_OdbcAttributes);
			vExec->ExecuteDirect(newTbl);
		}
	 qDebug(category) << QString("End Create Table %1 ").arg(tableName); 
	}
}

bool TK_LIDLTPSET::prepare()
{
	RETCODE r;
	QString check;
	QLoggingCategory category("classLibQ");
	 qDebug(category) << fetchSql;
	 qDebug(category) << insertSql;
#ifdef UNICODE
	r = SQLPrepare(hStmt_Insert,toSQLTCHAR(insertSql).data(),(SQLINTEGER)insertSql.length()); 
	if (r != SQL_SUCCESS) {
		check = qWarnODBCHandle(SQL_HANDLE_STMT, hStmt_Insert);
		 qCCritical(category) << QString("Prepare Statement-Insert : %1 is %2").arg(insertSql).arg(check);
		return false; 
	}
	r = SQLPrepare(hStmt_Update,toSQLTCHAR(updateSql).data(),(SQLINTEGER)updateSql.length()); 
	if (r != SQL_SUCCESS) {
		check = qWarnODBCHandle(SQL_HANDLE_STMT, hStmt_Update);
		 qCCritical(category) << QString("Prepare Statement-Update : %1 is %2").arg(updateSql).arg(check);
		return false; 
	}
	r = SQLPrepare(hStmt_Fetch,toSQLTCHAR(fetchSql).data(),(SQLINTEGER)fetchSql.length());
	if (r != SQL_SUCCESS) {
		check = qWarnODBCHandle(SQL_HANDLE_STMT, hStmt_Fetch);
		 qCCritical(category) << QString("Prepare Statement-Insert : %1 is %2").arg(fetchSql).arg(check);
		return false; 
	}
#else
	QByteArray queryI8 = insertSql.toUtf8();
	r = SQLPrepare(insert_hStmt,SQLCHAR*)queryI8.data(),(SQLINTEGER)queryI8.length());
	QByteArray queryU8 = fetchSql.toUtf8();
	r = SQLPrepare(hStmt_Fetch,(SQLCHAR*)queryU8.data(),(SQLINTEGER)queryU8.length());
#endif
	return true;

}

void TK_LIDLTPSET::prepareTargetTable()
{
	QLoggingCategory category("classLibQ");
	if (this->m_ReplicationOption == ReplicationOption::BulkCopy)
	{
		QScopedPointer<qVtExecute> execSql(new qVtExecute(nullptr));
		DropOption option = this->m_dropOption;
		switch (option)
		{
			case DropOption::DeleteFromTable:
			{
				QLoggingCategory category("classLibQ");
				execSql->initialize(this->m_lpszTargetDSN, "delete from TK_LIDLTPSET", true);
				execSql->setOdbcAttributes(this->m_OdbcAttributes);
				execSql->ExecuteDirect("delete from TK_LIDLTPSET");
			}break;
			case DropOption::TruncateTable:
			{
				execSql->initialize(this->m_lpszTargetDSN, "truncate table TK_LIDLTPSET", true);
				execSql->setOdbcAttributes(this->m_OdbcAttributes);
				execSql->ExecuteDirect("truncate table TK_LIDLTPSET");
			}break;
			case DropOption::DropTable:
			{
				execSql->initialize(this->m_lpszTargetDSN, "drop table TK_LIDLTPSET", true);
				execSql->setOdbcAttributes(this->m_OdbcAttributes);
				execSql->ExecuteDirect("drop table TK_LIDLTPSET");
				createTable();
			}break;
		}
	}
}

bool TK_LIDLTPSET::bindColumn()
{
	QLoggingCategory category("classLibQ");
	RETCODE r;
	bool isValid=true;
		 qDebug(category) << " Bindings: Ordinal [1] Type: 5 Buffer Size: 2 FieldName: DB_ID ";
		r = ::SQLBindCol(hStmt_Fetch, 1, 5, DB_ID.data(), 2, &cbDB_ID);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Bindings: Ordinal [2] Type: 93 Buffer Size: 23 FieldName: NVTIMESTAMP ";
		r = ::SQLBindCol(hStmt_Fetch, 2, 93, NVTIMESTAMP.data(), 23, &cbNVTIMESTAMP);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Bindings: Ordinal [3] Type: 5 Buffer Size: 2 FieldName: OAREA ";
		r = ::SQLBindCol(hStmt_Fetch, 3, 5, OAREA.data(), 2, &cbOAREA);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Bindings: Ordinal [4] Type: 4 Buffer Size: 4 FieldName: OPAGE ";
		r = ::SQLBindCol(hStmt_Fetch, 4, 4, OPAGE.data(), 4, &cbOPAGE);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Bindings: Ordinal [5] Type: 5 Buffer Size: 2 FieldName: OLINE ";
		r = ::SQLBindCol(hStmt_Fetch, 5, 5, OLINE.data(), 2, &cbOLINE);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Bindings: Ordinal [6] Type: 5 Buffer Size: 2 FieldName: MAREA ";
		r = ::SQLBindCol(hStmt_Fetch, 6, 5, MAREA.data(), 2, &cbMAREA);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Bindings: Ordinal [7] Type: 4 Buffer Size: 4 FieldName: MPAGE ";
		r = ::SQLBindCol(hStmt_Fetch, 7, 4, MPAGE.data(), 4, &cbMPAGE);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Bindings: Ordinal [8] Type: 5 Buffer Size: 2 FieldName: MLINE ";
		r = ::SQLBindCol(hStmt_Fetch, 8, 5, MLINE.data(), 2, &cbMLINE);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
	return isValid;
}

bool TK_LIDLTPSET::bindParameter()
{
	QLoggingCategory category("classLibQ");
	RETCODE r;
	bool isValid=true;
	{
		 qDebug(category) << " Parameters: Ordinal [1] Type: 5 Buffer Size: 2 FieldName: DB_ID ";
		r = SQLBindParameter(hStmt_Insert, 1, SQL_PARAM_INPUT, SQL_C_DEFAULT, 5, 0, 0, (SQLPOINTER)DB_ID.constData(), 0, &cbDB_ID);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Parameters: Ordinal [2] Type: 93 Buffer Size: 23 FieldName: NVTIMESTAMP ";
		r = SQLBindParameter(hStmt_Insert, 2, SQL_PARAM_INPUT, SQL_C_DEFAULT, 93, 23, 0, (SQLPOINTER)NVTIMESTAMP.constData(), 0, &cbNVTIMESTAMP);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Parameters: Ordinal [3] Type: 5 Buffer Size: 2 FieldName: OAREA ";
		r = SQLBindParameter(hStmt_Insert, 3, SQL_PARAM_INPUT, SQL_C_DEFAULT, 5, 0, 0, (SQLPOINTER)OAREA.constData(), 0, &cbOAREA);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Parameters: Ordinal [4] Type: 4 Buffer Size: 4 FieldName: OPAGE ";
		r = SQLBindParameter(hStmt_Insert, 4, SQL_PARAM_INPUT, SQL_C_DEFAULT, 4, 0, 0, (SQLPOINTER)OPAGE.constData(), 0, &cbOPAGE);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Parameters: Ordinal [5] Type: 5 Buffer Size: 2 FieldName: OLINE ";
		r = SQLBindParameter(hStmt_Insert, 5, SQL_PARAM_INPUT, SQL_C_DEFAULT, 5, 0, 0, (SQLPOINTER)OLINE.constData(), 0, &cbOLINE);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Parameters: Ordinal [6] Type: 5 Buffer Size: 2 FieldName: MAREA ";
		r = SQLBindParameter(hStmt_Insert, 6, SQL_PARAM_INPUT, SQL_C_DEFAULT, 5, 0, 0, (SQLPOINTER)MAREA.constData(), 0, &cbMAREA);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Parameters: Ordinal [7] Type: 4 Buffer Size: 4 FieldName: MPAGE ";
		r = SQLBindParameter(hStmt_Insert, 7, SQL_PARAM_INPUT, SQL_C_DEFAULT, 4, 0, 0, (SQLPOINTER)MPAGE.constData(), 0, &cbMPAGE);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Parameters: Ordinal [8] Type: 5 Buffer Size: 2 FieldName: MLINE ";
		r = SQLBindParameter(hStmt_Insert, 8, SQL_PARAM_INPUT, SQL_C_DEFAULT, 5, 0, 0, (SQLPOINTER)MLINE.constData(), 0, &cbMLINE);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
	}
	if (m_ReplicationOption == ReplicationOption::NetChange)
	{
		r = SQLBindParameter(hStmt_Update, 9, SQL_PARAM_INPUT, SQL_C_DEFAULT, 6, 0, 0, (SQLPOINTER)MAREA.constData(), 0, &cbMAREA);
		if (r == SQL_SUCCESS) { isValid=true; }
		r = SQLBindParameter(hStmt_Update, 10, SQL_PARAM_INPUT, SQL_C_DEFAULT, 7, 0, 0, (SQLPOINTER)MPAGE.constData(), 0, &cbMPAGE);
		if (r == SQL_SUCCESS) { isValid=true; }
		r = SQLBindParameter(hStmt_Update, 11, SQL_PARAM_INPUT, SQL_C_DEFAULT, 8, 0, 0, (SQLPOINTER)MLINE.constData(), 0, &cbMLINE);
		if (r == SQL_SUCCESS) { isValid=true; }
	// TK_LIDLTPSET is a well formed table for eNVy Replication 
		 qDebug(category) << " Parameters: Ordinal [6] 00 00 FieldName: MAREA ";
		 qDebug(category) << " Parameters: Ordinal [7] 00 00  FieldName: MPAGE ";
		 qDebug(category) << " Parameters: Ordinal [8] 00 00 FieldName:  MLINE ";
	} // 	if (m_ReplicationOption == ReplicationOption::NetChange)
	return isValid;
}

bool TK_LIDLTPSET::process(int rowSize)
{
	QLoggingCategory category("classLibQ");
	initOdbcAttributes();
	connect(Source);
	connect(Target);
	initialize();
	prepareTargetTable();
	prepare();
	bindColumn();
	bindParameter();
	copyTable();
	close();
	return false;
}

void TK_LIDLTPSET::copyTable()
{
	QLoggingCategory category("classLibQ");
	RETCODE r;
	QString check;
	r = SQLExecute(hStmt_Fetch);
		if (bIsAbort) {
			emit aborted(tableName, rowsFetched, rowsInserted, rowsUpdated);
			return;
		}
		while((r = SQLFetch(hStmt_Fetch)) != SQL_NO_DATA) {
		if (r != SQL_SUCCESS) {
			check = qWarnODBCHandle(SQL_HANDLE_STMT, hStmt_Fetch);
			qCCritical(category) << QString("SqlFetch - Error : %1 is %2").arg(fetchSql).arg(check);
			return;
		} 
		rowsFetched++;
		if (m_ReplicationOption == ReplicationOption::BulkCopy)
		{
			r = SQLExecute(hStmt_Insert);
			if (r == SQL_ERROR) {
				check = qWarnODBCHandle(SQL_HANDLE_STMT, hStmt_Insert);
				 qCCritical(category) << QString("SqlExecute:Insert - Error : %1 is %2").arg(insertSql).arg(check);
				return;
			}
			rowsInserted++;
			if ((rowsFetched % updateInterval) == 0) {
				qCInfo(category) << QString("[%1.%2]	Insertion: %3	Updates : %4	Fetched : %5").arg(profileName).arg(tableName).arg(rowsInserted).arg(rowsUpdated).arg(rowsFetched);
				emit updateStatusFetched(profileName, tableName, rowsFetched,rowsInserted,rowsUpdated);
			}
			if (m_ReplicationOption == ReplicationOption::NetChange)
			{
			r = SQLExecute(hStmt_Update);
			if (r != SQL_SUCCESS) {
				check = qWarnODBCHandle(SQL_HANDLE_STMT, hStmt_Update);
				 qCInfo(category)  << QString("SqlExecute:Update - Error : %1 is %2").arg(updateSql).arg(check);
				r = SQLExecute(hStmt_Insert);
				if (r != SQL_SUCCESS) {
					check = qWarnODBCHandle(SQL_HANDLE_STMT, hStmt_Insert);
					 qCritical(category) << QString("SqlExecute:Insert - Error : %1 is %2").arg(insertSql).arg(check);
					return;
				}
				else 	rowsInserted++;
				}
				else	rowsUpdated++;
			}
			emit updateStatusFetched(profileName, tableName, rowsFetched,rowsInserted,rowsUpdated);
		}
	} 
qCInfo(category) << QString("[%1.%2]	Insertion: %3	Updates : %4	Fetched : %5").arg(profileName).arg(tableName).arg(rowsInserted).arg(rowsUpdated).arg(rowsFetched);
}

void TK_LIDLTPSET::connect(connectionHandle connectionSource)
{

	QLoggingCategory category("classLibQ");
	RETCODE r;

	bool isValid = false;
	HWND	hWnd = nullptr;
	hWnd = ::GetDesktopWindow(); 
	SQLSMALLINT nResult = 0;

	SQLSMALLINT cb;
	UWORD wConnectOption = SQL_DRIVER_COMPLETE; //SQL_DRIVER_NOPROMPT;
	QVarLengthArray<SQLTCHAR> connOut(1024);
	memset(connOut.data(), 0, connOut.size() * sizeof(SQLTCHAR));

	switch (connectionSource)
	{
		case Source:
			{// environment
				SQLHANDLE hEnv = SQL_NULL_HANDLE;
				SQLHANDLE hDbc = SQL_NULL_HANDLE;
				r = ::SQLAllocHandle(SQL_HANDLE_ENV, SQL_NULL_HANDLE, &hEnv);
				if (r == SQL_SUCCESS) isValid = true;

				foreach(nOdbcAttributesClass * k, this->m_OdbcAttributes_Map)
				{
					if (k->attributeType == enumAttributeType::hEnv)
					{
						r = ::SQLSetEnvAttr(hEnv, (SQLINTEGER) k->odbcKey, (SQLPOINTER)k->odbcValue, 0);
						if (r == SQL_SUCCESS) isValid = true;
					}
				}
				hEnv_Source = hEnv;

				r = SQLAllocHandle(SQL_HANDLE_DBC, hEnv, &hDbc);
				if (r == SQL_SUCCESS) isValid = true;
				foreach(nOdbcAttributesClass * k, this->m_OdbcAttributes_Map)
				{
					if (k->attributeType == enumAttributeType::hDbc)
					{
					r = ::SQLSetConnectAttr(hDbc, k->odbcKey, (SQLPOINTER)k->odbcValue, 0);
					if (k->odbcKey == SQL_ATTR_CONNECTION_POOLING && k->odbcValue == SQL_CP_ONE_PER_DRIVER) wConnectOption = SQL_DRIVER_NOPROMPT;
					if (k->odbcKey == SQL_ATTR_CONNECTION_POOLING && k->odbcValue == SQL_CP_ONE_PER_HENV) wConnectOption = SQL_DRIVER_NOPROMPT;
					if (k->odbcKey == SQL_ATTR_CONNECTION_POOLING && k->odbcValue == SQL_CP_DRIVER_AWARE) wConnectOption = SQL_DRIVER_NOPROMPT;
					if (r == SQL_SUCCESS) isValid = true;
					}
				}
				hDbc_source = hDbc;
				if (isValid)
				{
					r = ::SQLDriverConnect(
						hDbc,
						hWnd,
#ifdef UNICODE
						toSQLTCHAR(m_lpszSourceDSN).data(),
#else
						(SQLCHAR*)dsnSource.toUtf8().data(),
#endif
						(SQLSMALLINT)m_lpszSourceDSN.length(),
						connOut.data(),
						1024,
						&cb, 
						wConnectOption); 
					int colSize = cb / sizeof(SQLTCHAR);
					if (r != SQL_SUCCESS && r != SQL_SUCCESS_WITH_INFO)
					{
						QString check = qWarnODBCHandle(SQL_HANDLE_DBC, hDbc);
						qCritical(category) <<  check;
						m_bIsOpen = false;
					}
					m_bIsOpen = true;
				}
			} break;
		case Target:
			{
				SQLHANDLE hEnv = SQL_NULL_HANDLE;
				SQLHANDLE hDbc = SQL_NULL_HANDLE;
				r = ::SQLAllocHandle(SQL_HANDLE_ENV, SQL_NULL_HANDLE, &hEnv);
				if (r == SQL_SUCCESS) isValid = true;

				foreach(nOdbcAttributesClass * k, this->m_OdbcAttributes_Map)
				{
					if (k->attributeType == enumAttributeType::hEnv)
					{
						r = ::SQLSetEnvAttr(hEnv, (SQLINTEGER) k->odbcKey, (SQLPOINTER)k->odbcValue, 0);
						if (r == SQL_SUCCESS) isValid = true;
					}
				}
				hEnv_Target = hEnv;

				r = SQLAllocHandle(SQL_HANDLE_DBC, hEnv, &hDbc);
				if (r == SQL_SUCCESS) isValid = true;
				foreach(nOdbcAttributesClass * k, this->m_OdbcAttributes_Map)
				{
				if (k->attributeType == enumAttributeType::hDbc)
					{
					r = ::SQLSetConnectAttr(hDbc, k->odbcKey, (SQLPOINTER)k->odbcValue, 0);
					if (k->odbcKey == SQL_ATTR_CONNECTION_POOLING && k->odbcValue == SQL_CP_ONE_PER_DRIVER) wConnectOption = SQL_DRIVER_NOPROMPT;
					if (k->odbcKey == SQL_ATTR_CONNECTION_POOLING && k->odbcValue == SQL_CP_ONE_PER_HENV) wConnectOption = SQL_DRIVER_NOPROMPT;
					if (k->odbcKey == SQL_ATTR_CONNECTION_POOLING && k->odbcValue == SQL_CP_DRIVER_AWARE) wConnectOption = SQL_DRIVER_NOPROMPT;
					if (r == SQL_SUCCESS) isValid = true;
					}
				}
				hDbc_target = hDbc;
				if (isValid) {
					r = ::SQLDriverConnect(
						hDbc,
						hWnd,
#ifdef UNICODE
						toSQLTCHAR(m_lpszTargetDSN).data(),
#else
						(SQLCHAR*)m_lpszTargetDSN.toUtf8().data(),
#endif
						(SQLSMALLINT)m_lpszTargetDSN.length(),
						connOut.data(),
						1024,
						&cb, 
						wConnectOption); 
						int colSize = cb / sizeof(SQLTCHAR);
					if (r != SQL_SUCCESS && r != SQL_SUCCESS_WITH_INFO)
						{
							QString check = qWarnODBCHandle(SQL_HANDLE_DBC, hDbc);
							qCritical(category) <<  check;
							m_bIsOpen = false;
						}
							m_bIsOpen = true;
					}
			} break;
			default: break;
	}
}
TK_INTREC::TK_INTREC(QObject * parent) : QObject(parent) 
,tableName("TK_INTREC")
,m_dropOption(DropOption::DropTable) { 
	numRowsFetched = 0;
}

#pragma region ~CTOR TK_INTREC 
TK_INTREC::~TK_INTREC() { 

#pragma region Buffers - Clear 
	DB_ID.clear();
	NVTIMESTAMP.clear();
	AREA.clear();
	PAGE.clear();
	LINE.clear();
	TK_INTFLOT.clear();
	TK_INTFPRT.clear();
	TK_INTFLOTTYPE.clear();
	TK_INTFWAR.clear();
	TK_INTFLOC.clear();
	TK_INTFQTY.clear();
	TK_INTTLOT.clear();
	TK_INTTPRT.clear();
	TK_INTTLOTTYPE.clear();
	TK_INTTWAR.clear();
	TK_INTTLOC.clear();
	TK_INTTQTY.clear();
	TK_INTDAT.clear();
	TK_INTCMD.clear();
	TK_INTORDNO.clear();
	TK_INTSUBORDNO.clear();
	TK_INTCODE.clear();
	TK_INTNAME.clear();
	TK_INTTIME.clear();
	TK_INTPOLINE.clear();
	TK_INTCHNSET.clear();
	TK_INTTOHSHSET.clear();
	TK_INTFMHSHSET.clear();
	TK_INTPOSRTSET.clear();
	TK_INTSOHSHSET.clear();
#pragma endregion Buffers - Clear 
}
#pragma endregion Destructor_TK_INTREC

// begin method functions
void TK_INTREC::setAbortFlag() { 
	QLoggingCategory category("classLibQ");
	qCInfo(category) << "isAbort was set to True";
	bIsAbort = true;
}

void TK_INTREC::run() { 
	process(1);
	QLoggingCategory category("classLibQ");
	qDebug(category) << "Entered;";
}

void	TK_INTREC::initOdbcAttributes()
{
	QLoggingCategory category("classLibQ");
	this->setProfileName(profileName);
	qDebug(category) << "Processing - TRKDB100"; 
	m_OdbcAttributesList = m_OdbcAttributes.split(","); 
	foreach(QString m, m_OdbcAttributesList)
	{
		QStringList keyValue = m.split("=");
		nOdbcAttributesClass * oM = new nOdbcAttributesClass(this);
		if (oM->loadToOdbc(keyValue.value(0), keyValue.value(1)))
		{
			m_OdbcAttributes_Map.insert(oM->odbcKey, oM);
		}
	}
}
void	TK_INTREC::initialize()
{
	QLoggingCategory category("classLibQ");
	RETCODE r;
	this->setProfileName(profileName);
	qDebug(category) << "Processing - TRKDB100"; 
//SQL Statements
//--------------------------------------------------

#pragma region Sql Statements_TK_INTREC

	fetchSql = "select  DB_ID, NVTIMESTAMP, AREA, PAGE, LINE, TK_INTFLOT, TK_INTFPRT, TK_INTFLOTTYPE, TK_INTFWAR, TK_INTFLOC, TK_INTFQTY, TK_INTTLOT, TK_INTTPRT, TK_INTTLOTTYPE, TK_INTTWAR, TK_INTTLOC, TK_INTTQTY, TK_INTDAT, TK_INTCMD, TK_INTORDNO, TK_INTSUBORDNO, TK_INTCODE, TK_INTNAME, TK_INTTIME, TK_INTPOLINE, TK_INTCHNSET, TK_INTTOHSHSET, TK_INTFMHSHSET, TK_INTPOSRTSET, TK_INTSOHSHSET from TK_INTREC";
		if (m_ReplicationOption == ReplicationOption::NetChange)
		{
			fetchSql.append(" p1, nv_transfers p2 WHERE  p2.table_name = 'TK_INTREC' AND p1.nvtimestamp > p2.last_completed");
		}
	insertSql = "insert into TK_INTREC ( PLANT_CODE, NVTIMESTAMP, AREA, PAGE, LINE, TK_INTFLOT, TK_INTFPRT, TK_INTFLOTTYPE, TK_INTFWAR, TK_INTFLOC, TK_INTFQTY, TK_INTTLOT, TK_INTTPRT, TK_INTTLOTTYPE, TK_INTTWAR, TK_INTTLOC, TK_INTTQTY, TK_INTDAT, TK_INTCMD, TK_INTORDNO, TK_INTSUBORDNO, TK_INTCODE, TK_INTNAME, TK_INTTIME, TK_INTPOLINE, TK_INTCHNSET, TK_INTTOHSHSET, TK_INTFMHSHSET, TK_INTPOSRTSET, TK_INTSOHSHSET ) values ( ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?)";
	updateSql = "update TK_INTREC set  PLANT_CODE = ?, NVTIMESTAMP = ?, AREA = ?, PAGE = ?, LINE = ?, TK_INTFLOT = ?, TK_INTFPRT = ?, TK_INTFLOTTYPE = ?, TK_INTFWAR = ?, TK_INTFLOC = ?, TK_INTFQTY = ?, TK_INTTLOT = ?, TK_INTTPRT = ?, TK_INTTLOTTYPE = ?, TK_INTTWAR = ?, TK_INTTLOC = ?, TK_INTTQTY = ?, TK_INTDAT = ?, TK_INTCMD = ?, TK_INTORDNO = ?, TK_INTSUBORDNO = ?, TK_INTCODE = ?, TK_INTNAME = ?, TK_INTTIME = ?, TK_INTPOLINE = ?, TK_INTCHNSET = ?, TK_INTTOHSHSET = ?, TK_INTFMHSHSET = ?, TK_INTPOSRTSET = ?, TK_INTSOHSHSET = ?  where area = ? and page = ? line = ? ";

	qDebug(category) << "insertSQL - insert into TK_INTREC ( PLANT_CODE, NVTIMESTAMP, AREA, PAGE, LINE, TK_INTFLOT, TK_INTFPRT, TK_INTFLOTTYPE, TK_INTFWAR, TK_INTFLOC, TK_INTFQTY, TK_INTTLOT, TK_INTTPRT, TK_INTTLOTTYPE, TK_INTTWAR, TK_INTTLOC, TK_INTTQTY, TK_INTDAT, TK_INTCMD, TK_INTORDNO, TK_INTSUBORDNO, TK_INTCODE, TK_INTNAME, TK_INTTIME, TK_INTPOLINE, TK_INTCHNSET, TK_INTTOHSHSET, TK_INTFMHSHSET, TK_INTPOSRTSET, TK_INTSOHSHSET ) values ( ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?)";
	qDebug(category) << "fetchSQL - select  DB_ID, NVTIMESTAMP, AREA, PAGE, LINE, TK_INTFLOT, TK_INTFPRT, TK_INTFLOTTYPE, TK_INTFWAR, TK_INTFLOC, TK_INTFQTY, TK_INTTLOT, TK_INTTPRT, TK_INTTLOTTYPE, TK_INTTWAR, TK_INTTLOC, TK_INTTQTY, TK_INTDAT, TK_INTCMD, TK_INTORDNO, TK_INTSUBORDNO, TK_INTCODE, TK_INTNAME, TK_INTTIME, TK_INTPOLINE, TK_INTCHNSET, TK_INTTOHSHSET, TK_INTFMHSHSET, TK_INTPOSRTSET, TK_INTSOHSHSET from TK_INTREC";
	qDebug(category) << "unsertSQL - update TK_INTREC set  PLANT_CODE = ?, NVTIMESTAMP = ?, AREA = ?, PAGE = ?, LINE = ?, TK_INTFLOT = ?, TK_INTFPRT = ?, TK_INTFLOTTYPE = ?, TK_INTFWAR = ?, TK_INTFLOC = ?, TK_INTFQTY = ?, TK_INTTLOT = ?, TK_INTTPRT = ?, TK_INTTLOTTYPE = ?, TK_INTTWAR = ?, TK_INTTLOC = ?, TK_INTTQTY = ?, TK_INTDAT = ?, TK_INTCMD = ?, TK_INTORDNO = ?, TK_INTSUBORDNO = ?, TK_INTCODE = ?, TK_INTNAME = ?, TK_INTTIME = ?, TK_INTPOLINE = ?, TK_INTCHNSET = ?, TK_INTTOHSHSET = ?, TK_INTFMHSHSET = ?, TK_INTPOSRTSET = ?, TK_INTSOHSHSET = ?  where area = ? and page = ? line = ? ";

#pragma endregion Sql Statements_TK_INTREC
	SQLHANDLE		insert_hStmt = SQL_NULL_HANDLE;
	SQLHANDLE		fetch_hStmt = SQL_NULL_HANDLE; 
	SQLHANDLE		update_hStmt = SQL_NULL_HANDLE; 
 
	r = ::SQLAllocHandle(SQL_HANDLE_STMT, hDbc_source, &fetch_hStmt);
	if (r != SQL_SUCCESS) {
		 qCCritical(category) << QString("Error  hDbc_Source SQLCode : %1 is %2").arg(QString::number( (long)hDbc_source)).arg(QString::number(r));
		return; 
	}
	r = ::SQLAllocHandle(SQL_HANDLE_STMT, hDbc_target, &insert_hStmt);
	if (r != SQL_SUCCESS) {
		 qCCritical(category) << QString("Error hDbc_Source -SQLCode: %1 is %2").arg(QString::number( (long)hDbc_target)).arg(QString::number(r));
		return; 
	}
	r = ::SQLAllocHandle(SQL_HANDLE_STMT, hDbc_target, &update_hStmt);
	if (r != SQL_SUCCESS) {
		 qCCritical(category) << QString("Error hDbc_Source +SQLCode: %1 is %2").arg(QString::number( (long)hDbc_target)).arg(QString::number(r));
		return; 
	}
 
	hStmt_Fetch = fetch_hStmt;
	hStmt_Insert = insert_hStmt;
	hStmt_Update = update_hStmt;
 
	SQLSetStmtAttr(hStmt_Fetch, SQL_ATTR_USE_BOOKMARKS, (SQLPOINTER)SQL_UB_OFF, 0);
	SQLSetStmtAttr(hStmt_Fetch, SQL_ATTR_ROW_BIND_TYPE, (SQLPOINTER)SQL_BIND_BY_COLUMN, 0);
	SQLSetStmtAttr(hStmt_Fetch, SQL_ATTR_ROW_ARRAY_SIZE, (SQLPOINTER)1, 0);
	SQLSetStmtAttr(hStmt_Fetch, SQL_ATTR_ROWS_FETCHED_PTR, &numRowsFetched, 0);

// Fields used by this class 
// ---------------------------------------------------

#pragma region Resize Fields TK_INTREC
	qDebug(category) << "Malloc - DB_ID[2]";
	DB_ID.resize(2);
	qDebug(category) << "Malloc - NVTIMESTAMP[23]";
	NVTIMESTAMP.resize(23);
	qDebug(category) << "Malloc - AREA[2]";
	AREA.resize(2);
	qDebug(category) << "Malloc - PAGE[4]";
	PAGE.resize(4);
	qDebug(category) << "Malloc - LINE[2]";
	LINE.resize(2);
	qDebug(category) << "Malloc - TK_INTFLOT[24]";
	TK_INTFLOT.resize(24);
	qDebug(category) << "Malloc - TK_INTFPRT[18]";
	TK_INTFPRT.resize(18);
	qDebug(category) << "Malloc - TK_INTFLOTTYPE[2]";
	TK_INTFLOTTYPE.resize(2);
	qDebug(category) << "Malloc - TK_INTFWAR[10]";
	TK_INTFWAR.resize(10);
	qDebug(category) << "Malloc - TK_INTFLOC[10]";
	TK_INTFLOC.resize(10);
	qDebug(category) << "Malloc - TK_INTFQTY[8]";
	TK_INTFQTY.resize(8);
	qDebug(category) << "Malloc - TK_INTTLOT[24]";
	TK_INTTLOT.resize(24);
	qDebug(category) << "Malloc - TK_INTTPRT[18]";
	TK_INTTPRT.resize(18);
	qDebug(category) << "Malloc - TK_INTTLOTTYPE[2]";
	TK_INTTLOTTYPE.resize(2);
	qDebug(category) << "Malloc - TK_INTTWAR[10]";
	TK_INTTWAR.resize(10);
	qDebug(category) << "Malloc - TK_INTTLOC[10]";
	TK_INTTLOC.resize(10);
	qDebug(category) << "Malloc - TK_INTTQTY[8]";
	TK_INTTQTY.resize(8);
	qDebug(category) << "Malloc - TK_INTDAT[4]";
	TK_INTDAT.resize(4);
	qDebug(category) << "Malloc - TK_INTCMD[6]";
	TK_INTCMD.resize(6);
	qDebug(category) << "Malloc - TK_INTORDNO[10]";
	TK_INTORDNO.resize(10);
	qDebug(category) << "Malloc - TK_INTSUBORDNO[10]";
	TK_INTSUBORDNO.resize(10);
	qDebug(category) << "Malloc - TK_INTCODE[10]";
	TK_INTCODE.resize(10);
	qDebug(category) << "Malloc - TK_INTNAME[30]";
	TK_INTNAME.resize(30);
	qDebug(category) << "Malloc - TK_INTTIME[8]";
	TK_INTTIME.resize(8);
	qDebug(category) << "Malloc - TK_INTPOLINE[4]";
	TK_INTPOLINE.resize(4);
	qDebug(category) << "Malloc - TK_INTCHNSET[2]";
	TK_INTCHNSET.resize(2);
	qDebug(category) << "Malloc - TK_INTTOHSHSET[2]";
	TK_INTTOHSHSET.resize(2);
	qDebug(category) << "Malloc - TK_INTFMHSHSET[2]";
	TK_INTFMHSHSET.resize(2);
	qDebug(category) << "Malloc - TK_INTPOSRTSET[2]";
	TK_INTPOSRTSET.resize(2);
	qDebug(category) << "Malloc - TK_INTSOHSHSET[2]";
	TK_INTSOHSHSET.resize(2);

#pragma endregion Resize Fields TK_INTREC
}
void TK_INTREC::close()
{
	QLoggingCategory category("classLibQ");
	if (m_bIsOpen)
	{
	qDebug(category) << "database is Open";
		SQLHANDLE source_hStmt = hStmt_Fetch;
		SQLHANDLE insert_hStmt = hStmt_Insert;
		SQLHANDLE hDb_S = this->hDbc_source;
		SQLHANDLE hDb_T = hDbc_target;
		SQLHANDLE hEnvS = hEnv_Source;
		SQLHANDLE hEnvT = hEnv_Target;
		RETCODE r;

		r = ::SQLFreeHandle(SQL_HANDLE_STMT, hStmt_Fetch);
		r = ::SQLFreeHandle(SQL_HANDLE_STMT, hStmt_Insert);
		r = ::SQLFreeHandle(SQL_HANDLE_STMT, hStmt_Update);
		if (hDbc_source != SQL_NULL_HANDLE) 		r = ::SQLDisconnect(hDb_S);
		if (hDbc_target != SQL_NULL_HANDLE) 		r = ::SQLDisconnect(hDb_T);

		r = ::SQLFreeHandle(SQL_HANDLE_DBC, hDb_S);
		r = ::SQLFreeHandle(SQL_HANDLE_DBC, hDb_T);
		r = ::SQLFreeHandle(SQL_HANDLE_ENV, hEnvS);
		r = ::SQLFreeHandle(SQL_HANDLE_ENV, hEnvT);
	}

	hEnv_Source = SQL_NULL_HANDLE;
	hEnv_Target = SQL_NULL_HANDLE;
	hEnv_Source = SQL_NULL_HANDLE;
	hEnv_Target = SQL_NULL_HANDLE;
	hStmt_Fetch = SQL_NULL_HANDLE;
	hStmt_Insert = SQL_NULL_HANDLE;
	hStmt_Update = SQL_NULL_HANDLE;
}

void TK_INTREC::open(const QString sourceDSN, const QString targetDSN)
{
	QLoggingCategory category("classLibQ");
	m_lpszTargetDSN = targetDSN;
	m_lpszSourceDSN = sourceDSN;
	qDebug(category) << QString("Source - %1[%2]").arg(sourceDSN);
	qDebug(category) << QString("Target - %1[%2]").arg(targetDSN);
}

void TK_INTREC::createTable()
{
	QLoggingCategory category("classLibQ");
	{
		QScopedPointer<nvTableOracleRdb> tbl(new nvTableOracleRdb(nullptr));
		tbl->initialize("TK_INTREC", this->m_lpszSourceDSN);
		QString newTbl = tbl->getCreateTableSQL();
		QScopedPointer<qVtExecute> vExec(new qVtExecute(nullptr));
		{
			vExec->initialize(m_lpszTargetDSN, " ", true);
			vExec->setOdbcAttributes(m_OdbcAttributes);
			vExec->ExecuteDirect(newTbl);
		}
	 qDebug(category) << QString("End Create Table %1 ").arg(tableName); 
	}
}

bool TK_INTREC::prepare()
{
	RETCODE r;
	QString check;
	QLoggingCategory category("classLibQ");
	 qDebug(category) << fetchSql;
	 qDebug(category) << insertSql;
#ifdef UNICODE
	r = SQLPrepare(hStmt_Insert,toSQLTCHAR(insertSql).data(),(SQLINTEGER)insertSql.length()); 
	if (r != SQL_SUCCESS) {
		check = qWarnODBCHandle(SQL_HANDLE_STMT, hStmt_Insert);
		 qCCritical(category) << QString("Prepare Statement-Insert : %1 is %2").arg(insertSql).arg(check);
		return false; 
	}
	r = SQLPrepare(hStmt_Update,toSQLTCHAR(updateSql).data(),(SQLINTEGER)updateSql.length()); 
	if (r != SQL_SUCCESS) {
		check = qWarnODBCHandle(SQL_HANDLE_STMT, hStmt_Update);
		 qCCritical(category) << QString("Prepare Statement-Update : %1 is %2").arg(updateSql).arg(check);
		return false; 
	}
	r = SQLPrepare(hStmt_Fetch,toSQLTCHAR(fetchSql).data(),(SQLINTEGER)fetchSql.length());
	if (r != SQL_SUCCESS) {
		check = qWarnODBCHandle(SQL_HANDLE_STMT, hStmt_Fetch);
		 qCCritical(category) << QString("Prepare Statement-Insert : %1 is %2").arg(fetchSql).arg(check);
		return false; 
	}
#else
	QByteArray queryI8 = insertSql.toUtf8();
	r = SQLPrepare(insert_hStmt,SQLCHAR*)queryI8.data(),(SQLINTEGER)queryI8.length());
	QByteArray queryU8 = fetchSql.toUtf8();
	r = SQLPrepare(hStmt_Fetch,(SQLCHAR*)queryU8.data(),(SQLINTEGER)queryU8.length());
#endif
	return true;

}

void TK_INTREC::prepareTargetTable()
{
	QLoggingCategory category("classLibQ");
	if (this->m_ReplicationOption == ReplicationOption::BulkCopy)
	{
		QScopedPointer<qVtExecute> execSql(new qVtExecute(nullptr));
		DropOption option = this->m_dropOption;
		switch (option)
		{
			case DropOption::DeleteFromTable:
			{
				QLoggingCategory category("classLibQ");
				execSql->initialize(this->m_lpszTargetDSN, "delete from TK_INTREC", true);
				execSql->setOdbcAttributes(this->m_OdbcAttributes);
				execSql->ExecuteDirect("delete from TK_INTREC");
			}break;
			case DropOption::TruncateTable:
			{
				execSql->initialize(this->m_lpszTargetDSN, "truncate table TK_INTREC", true);
				execSql->setOdbcAttributes(this->m_OdbcAttributes);
				execSql->ExecuteDirect("truncate table TK_INTREC");
			}break;
			case DropOption::DropTable:
			{
				execSql->initialize(this->m_lpszTargetDSN, "drop table TK_INTREC", true);
				execSql->setOdbcAttributes(this->m_OdbcAttributes);
				execSql->ExecuteDirect("drop table TK_INTREC");
				createTable();
			}break;
		}
	}
}

bool TK_INTREC::bindColumn()
{
	QLoggingCategory category("classLibQ");
	RETCODE r;
	bool isValid=true;
		 qDebug(category) << " Bindings: Ordinal [1] Type: 5 Buffer Size: 2 FieldName: DB_ID ";
		r = ::SQLBindCol(hStmt_Fetch, 1, 5, DB_ID.data(), 2, &cbDB_ID);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Bindings: Ordinal [2] Type: 93 Buffer Size: 23 FieldName: NVTIMESTAMP ";
		r = ::SQLBindCol(hStmt_Fetch, 2, 93, NVTIMESTAMP.data(), 23, &cbNVTIMESTAMP);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Bindings: Ordinal [3] Type: 5 Buffer Size: 2 FieldName: AREA ";
		r = ::SQLBindCol(hStmt_Fetch, 3, 5, AREA.data(), 2, &cbAREA);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Bindings: Ordinal [4] Type: 4 Buffer Size: 4 FieldName: PAGE ";
		r = ::SQLBindCol(hStmt_Fetch, 4, 4, PAGE.data(), 4, &cbPAGE);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Bindings: Ordinal [5] Type: 5 Buffer Size: 2 FieldName: LINE ";
		r = ::SQLBindCol(hStmt_Fetch, 5, 5, LINE.data(), 2, &cbLINE);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Bindings: Ordinal [6] Type: 1 Buffer Size: 24 FieldName: TK_INTFLOT ";
		r = ::SQLBindCol(hStmt_Fetch, 6, 1, TK_INTFLOT.data(), 24, &cbTK_INTFLOT);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Bindings: Ordinal [7] Type: 1 Buffer Size: 18 FieldName: TK_INTFPRT ";
		r = ::SQLBindCol(hStmt_Fetch, 7, 1, TK_INTFPRT.data(), 18, &cbTK_INTFPRT);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Bindings: Ordinal [8] Type: 5 Buffer Size: 2 FieldName: TK_INTFLOTTYPE ";
		r = ::SQLBindCol(hStmt_Fetch, 8, 5, TK_INTFLOTTYPE.data(), 2, &cbTK_INTFLOTTYPE);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Bindings: Ordinal [9] Type: 1 Buffer Size: 10 FieldName: TK_INTFWAR ";
		r = ::SQLBindCol(hStmt_Fetch, 9, 1, TK_INTFWAR.data(), 10, &cbTK_INTFWAR);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Bindings: Ordinal [10] Type: 1 Buffer Size: 10 FieldName: TK_INTFLOC ";
		r = ::SQLBindCol(hStmt_Fetch, 10, 1, TK_INTFLOC.data(), 10, &cbTK_INTFLOC);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Bindings: Ordinal [11] Type: 8 Buffer Size: 8 FieldName: TK_INTFQTY ";
		r = ::SQLBindCol(hStmt_Fetch, 11, 8, TK_INTFQTY.data(), 8, &cbTK_INTFQTY);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Bindings: Ordinal [12] Type: 1 Buffer Size: 24 FieldName: TK_INTTLOT ";
		r = ::SQLBindCol(hStmt_Fetch, 12, 1, TK_INTTLOT.data(), 24, &cbTK_INTTLOT);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Bindings: Ordinal [13] Type: 1 Buffer Size: 18 FieldName: TK_INTTPRT ";
		r = ::SQLBindCol(hStmt_Fetch, 13, 1, TK_INTTPRT.data(), 18, &cbTK_INTTPRT);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Bindings: Ordinal [14] Type: 5 Buffer Size: 2 FieldName: TK_INTTLOTTYPE ";
		r = ::SQLBindCol(hStmt_Fetch, 14, 5, TK_INTTLOTTYPE.data(), 2, &cbTK_INTTLOTTYPE);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Bindings: Ordinal [15] Type: 1 Buffer Size: 10 FieldName: TK_INTTWAR ";
		r = ::SQLBindCol(hStmt_Fetch, 15, 1, TK_INTTWAR.data(), 10, &cbTK_INTTWAR);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Bindings: Ordinal [16] Type: 1 Buffer Size: 10 FieldName: TK_INTTLOC ";
		r = ::SQLBindCol(hStmt_Fetch, 16, 1, TK_INTTLOC.data(), 10, &cbTK_INTTLOC);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Bindings: Ordinal [17] Type: 8 Buffer Size: 8 FieldName: TK_INTTQTY ";
		r = ::SQLBindCol(hStmt_Fetch, 17, 8, TK_INTTQTY.data(), 8, &cbTK_INTTQTY);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Bindings: Ordinal [18] Type: 4 Buffer Size: 4 FieldName: TK_INTDAT ";
		r = ::SQLBindCol(hStmt_Fetch, 18, 4, TK_INTDAT.data(), 4, &cbTK_INTDAT);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Bindings: Ordinal [19] Type: 1 Buffer Size: 6 FieldName: TK_INTCMD ";
		r = ::SQLBindCol(hStmt_Fetch, 19, 1, TK_INTCMD.data(), 6, &cbTK_INTCMD);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Bindings: Ordinal [20] Type: 1 Buffer Size: 10 FieldName: TK_INTORDNO ";
		r = ::SQLBindCol(hStmt_Fetch, 20, 1, TK_INTORDNO.data(), 10, &cbTK_INTORDNO);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Bindings: Ordinal [21] Type: 1 Buffer Size: 10 FieldName: TK_INTSUBORDNO ";
		r = ::SQLBindCol(hStmt_Fetch, 21, 1, TK_INTSUBORDNO.data(), 10, &cbTK_INTSUBORDNO);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Bindings: Ordinal [22] Type: 1 Buffer Size: 10 FieldName: TK_INTCODE ";
		r = ::SQLBindCol(hStmt_Fetch, 22, 1, TK_INTCODE.data(), 10, &cbTK_INTCODE);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Bindings: Ordinal [23] Type: 1 Buffer Size: 30 FieldName: TK_INTNAME ";
		r = ::SQLBindCol(hStmt_Fetch, 23, 1, TK_INTNAME.data(), 30, &cbTK_INTNAME);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Bindings: Ordinal [24] Type: 1 Buffer Size: 8 FieldName: TK_INTTIME ";
		r = ::SQLBindCol(hStmt_Fetch, 24, 1, TK_INTTIME.data(), 8, &cbTK_INTTIME);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Bindings: Ordinal [25] Type: 4 Buffer Size: 4 FieldName: TK_INTPOLINE ";
		r = ::SQLBindCol(hStmt_Fetch, 25, 4, TK_INTPOLINE.data(), 4, &cbTK_INTPOLINE);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Bindings: Ordinal [26] Type: 5 Buffer Size: 2 FieldName: TK_INTCHNSET ";
		r = ::SQLBindCol(hStmt_Fetch, 26, 5, TK_INTCHNSET.data(), 2, &cbTK_INTCHNSET);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Bindings: Ordinal [27] Type: 5 Buffer Size: 2 FieldName: TK_INTTOHSHSET ";
		r = ::SQLBindCol(hStmt_Fetch, 27, 5, TK_INTTOHSHSET.data(), 2, &cbTK_INTTOHSHSET);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Bindings: Ordinal [28] Type: 5 Buffer Size: 2 FieldName: TK_INTFMHSHSET ";
		r = ::SQLBindCol(hStmt_Fetch, 28, 5, TK_INTFMHSHSET.data(), 2, &cbTK_INTFMHSHSET);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Bindings: Ordinal [29] Type: 5 Buffer Size: 2 FieldName: TK_INTPOSRTSET ";
		r = ::SQLBindCol(hStmt_Fetch, 29, 5, TK_INTPOSRTSET.data(), 2, &cbTK_INTPOSRTSET);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Bindings: Ordinal [30] Type: 5 Buffer Size: 2 FieldName: TK_INTSOHSHSET ";
		r = ::SQLBindCol(hStmt_Fetch, 30, 5, TK_INTSOHSHSET.data(), 2, &cbTK_INTSOHSHSET);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
	return isValid;
}

bool TK_INTREC::bindParameter()
{
	QLoggingCategory category("classLibQ");
	RETCODE r;
	bool isValid=true;
	{
		 qDebug(category) << " Parameters: Ordinal [1] Type: 5 Buffer Size: 2 FieldName: DB_ID ";
		r = SQLBindParameter(hStmt_Insert, 1, SQL_PARAM_INPUT, SQL_C_DEFAULT, 5, 0, 0, (SQLPOINTER)DB_ID.constData(), 0, &cbDB_ID);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Parameters: Ordinal [2] Type: 93 Buffer Size: 23 FieldName: NVTIMESTAMP ";
		r = SQLBindParameter(hStmt_Insert, 2, SQL_PARAM_INPUT, SQL_C_DEFAULT, 93, 23, 0, (SQLPOINTER)NVTIMESTAMP.constData(), 0, &cbNVTIMESTAMP);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Parameters: Ordinal [3] Type: 5 Buffer Size: 2 FieldName: AREA ";
		r = SQLBindParameter(hStmt_Insert, 3, SQL_PARAM_INPUT, SQL_C_DEFAULT, 5, 0, 0, (SQLPOINTER)AREA.constData(), 0, &cbAREA);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Parameters: Ordinal [4] Type: 4 Buffer Size: 4 FieldName: PAGE ";
		r = SQLBindParameter(hStmt_Insert, 4, SQL_PARAM_INPUT, SQL_C_DEFAULT, 4, 0, 0, (SQLPOINTER)PAGE.constData(), 0, &cbPAGE);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Parameters: Ordinal [5] Type: 5 Buffer Size: 2 FieldName: LINE ";
		r = SQLBindParameter(hStmt_Insert, 5, SQL_PARAM_INPUT, SQL_C_DEFAULT, 5, 0, 0, (SQLPOINTER)LINE.constData(), 0, &cbLINE);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Parameters: Ordinal [6] Type: 1 Buffer Size: 24 FieldName: TK_INTFLOT ";
		r = SQLBindParameter(hStmt_Insert, 6, SQL_PARAM_INPUT, SQL_C_DEFAULT, 1, 24, 0, (SQLPOINTER)TK_INTFLOT.constData(), 0, &cbTK_INTFLOT);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Parameters: Ordinal [7] Type: 1 Buffer Size: 18 FieldName: TK_INTFPRT ";
		r = SQLBindParameter(hStmt_Insert, 7, SQL_PARAM_INPUT, SQL_C_DEFAULT, 1, 18, 0, (SQLPOINTER)TK_INTFPRT.constData(), 0, &cbTK_INTFPRT);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Parameters: Ordinal [8] Type: 5 Buffer Size: 2 FieldName: TK_INTFLOTTYPE ";
		r = SQLBindParameter(hStmt_Insert, 8, SQL_PARAM_INPUT, SQL_C_DEFAULT, 5, 0, 0, (SQLPOINTER)TK_INTFLOTTYPE.constData(), 0, &cbTK_INTFLOTTYPE);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Parameters: Ordinal [9] Type: 1 Buffer Size: 10 FieldName: TK_INTFWAR ";
		r = SQLBindParameter(hStmt_Insert, 9, SQL_PARAM_INPUT, SQL_C_DEFAULT, 1, 10, 0, (SQLPOINTER)TK_INTFWAR.constData(), 0, &cbTK_INTFWAR);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Parameters: Ordinal [10] Type: 1 Buffer Size: 10 FieldName: TK_INTFLOC ";
		r = SQLBindParameter(hStmt_Insert, 10, SQL_PARAM_INPUT, SQL_C_DEFAULT, 1, 10, 0, (SQLPOINTER)TK_INTFLOC.constData(), 0, &cbTK_INTFLOC);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Parameters: Ordinal [11] Type: 8 Buffer Size: 8 FieldName: TK_INTFQTY ";
		r = SQLBindParameter(hStmt_Insert, 11, SQL_PARAM_INPUT, SQL_C_DEFAULT, 8, 0, 0, (SQLPOINTER)TK_INTFQTY.constData(), 0, &cbTK_INTFQTY);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Parameters: Ordinal [12] Type: 1 Buffer Size: 24 FieldName: TK_INTTLOT ";
		r = SQLBindParameter(hStmt_Insert, 12, SQL_PARAM_INPUT, SQL_C_DEFAULT, 1, 24, 0, (SQLPOINTER)TK_INTTLOT.constData(), 0, &cbTK_INTTLOT);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Parameters: Ordinal [13] Type: 1 Buffer Size: 18 FieldName: TK_INTTPRT ";
		r = SQLBindParameter(hStmt_Insert, 13, SQL_PARAM_INPUT, SQL_C_DEFAULT, 1, 18, 0, (SQLPOINTER)TK_INTTPRT.constData(), 0, &cbTK_INTTPRT);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Parameters: Ordinal [14] Type: 5 Buffer Size: 2 FieldName: TK_INTTLOTTYPE ";
		r = SQLBindParameter(hStmt_Insert, 14, SQL_PARAM_INPUT, SQL_C_DEFAULT, 5, 0, 0, (SQLPOINTER)TK_INTTLOTTYPE.constData(), 0, &cbTK_INTTLOTTYPE);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Parameters: Ordinal [15] Type: 1 Buffer Size: 10 FieldName: TK_INTTWAR ";
		r = SQLBindParameter(hStmt_Insert, 15, SQL_PARAM_INPUT, SQL_C_DEFAULT, 1, 10, 0, (SQLPOINTER)TK_INTTWAR.constData(), 0, &cbTK_INTTWAR);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Parameters: Ordinal [16] Type: 1 Buffer Size: 10 FieldName: TK_INTTLOC ";
		r = SQLBindParameter(hStmt_Insert, 16, SQL_PARAM_INPUT, SQL_C_DEFAULT, 1, 10, 0, (SQLPOINTER)TK_INTTLOC.constData(), 0, &cbTK_INTTLOC);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Parameters: Ordinal [17] Type: 8 Buffer Size: 8 FieldName: TK_INTTQTY ";
		r = SQLBindParameter(hStmt_Insert, 17, SQL_PARAM_INPUT, SQL_C_DEFAULT, 8, 0, 0, (SQLPOINTER)TK_INTTQTY.constData(), 0, &cbTK_INTTQTY);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Parameters: Ordinal [18] Type: 4 Buffer Size: 4 FieldName: TK_INTDAT ";
		r = SQLBindParameter(hStmt_Insert, 18, SQL_PARAM_INPUT, SQL_C_DEFAULT, 4, 0, 0, (SQLPOINTER)TK_INTDAT.constData(), 0, &cbTK_INTDAT);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Parameters: Ordinal [19] Type: 1 Buffer Size: 6 FieldName: TK_INTCMD ";
		r = SQLBindParameter(hStmt_Insert, 19, SQL_PARAM_INPUT, SQL_C_DEFAULT, 1, 6, 0, (SQLPOINTER)TK_INTCMD.constData(), 0, &cbTK_INTCMD);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Parameters: Ordinal [20] Type: 1 Buffer Size: 10 FieldName: TK_INTORDNO ";
		r = SQLBindParameter(hStmt_Insert, 20, SQL_PARAM_INPUT, SQL_C_DEFAULT, 1, 10, 0, (SQLPOINTER)TK_INTORDNO.constData(), 0, &cbTK_INTORDNO);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Parameters: Ordinal [21] Type: 1 Buffer Size: 10 FieldName: TK_INTSUBORDNO ";
		r = SQLBindParameter(hStmt_Insert, 21, SQL_PARAM_INPUT, SQL_C_DEFAULT, 1, 10, 0, (SQLPOINTER)TK_INTSUBORDNO.constData(), 0, &cbTK_INTSUBORDNO);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Parameters: Ordinal [22] Type: 1 Buffer Size: 10 FieldName: TK_INTCODE ";
		r = SQLBindParameter(hStmt_Insert, 22, SQL_PARAM_INPUT, SQL_C_DEFAULT, 1, 10, 0, (SQLPOINTER)TK_INTCODE.constData(), 0, &cbTK_INTCODE);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Parameters: Ordinal [23] Type: 1 Buffer Size: 30 FieldName: TK_INTNAME ";
		r = SQLBindParameter(hStmt_Insert, 23, SQL_PARAM_INPUT, SQL_C_DEFAULT, 1, 30, 0, (SQLPOINTER)TK_INTNAME.constData(), 0, &cbTK_INTNAME);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Parameters: Ordinal [24] Type: 1 Buffer Size: 8 FieldName: TK_INTTIME ";
		r = SQLBindParameter(hStmt_Insert, 24, SQL_PARAM_INPUT, SQL_C_DEFAULT, 1, 8, 0, (SQLPOINTER)TK_INTTIME.constData(), 0, &cbTK_INTTIME);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Parameters: Ordinal [25] Type: 4 Buffer Size: 4 FieldName: TK_INTPOLINE ";
		r = SQLBindParameter(hStmt_Insert, 25, SQL_PARAM_INPUT, SQL_C_DEFAULT, 4, 0, 0, (SQLPOINTER)TK_INTPOLINE.constData(), 0, &cbTK_INTPOLINE);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Parameters: Ordinal [26] Type: 5 Buffer Size: 2 FieldName: TK_INTCHNSET ";
		r = SQLBindParameter(hStmt_Insert, 26, SQL_PARAM_INPUT, SQL_C_DEFAULT, 5, 0, 0, (SQLPOINTER)TK_INTCHNSET.constData(), 0, &cbTK_INTCHNSET);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Parameters: Ordinal [27] Type: 5 Buffer Size: 2 FieldName: TK_INTTOHSHSET ";
		r = SQLBindParameter(hStmt_Insert, 27, SQL_PARAM_INPUT, SQL_C_DEFAULT, 5, 0, 0, (SQLPOINTER)TK_INTTOHSHSET.constData(), 0, &cbTK_INTTOHSHSET);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Parameters: Ordinal [28] Type: 5 Buffer Size: 2 FieldName: TK_INTFMHSHSET ";
		r = SQLBindParameter(hStmt_Insert, 28, SQL_PARAM_INPUT, SQL_C_DEFAULT, 5, 0, 0, (SQLPOINTER)TK_INTFMHSHSET.constData(), 0, &cbTK_INTFMHSHSET);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Parameters: Ordinal [29] Type: 5 Buffer Size: 2 FieldName: TK_INTPOSRTSET ";
		r = SQLBindParameter(hStmt_Insert, 29, SQL_PARAM_INPUT, SQL_C_DEFAULT, 5, 0, 0, (SQLPOINTER)TK_INTPOSRTSET.constData(), 0, &cbTK_INTPOSRTSET);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Parameters: Ordinal [30] Type: 5 Buffer Size: 2 FieldName: TK_INTSOHSHSET ";
		r = SQLBindParameter(hStmt_Insert, 30, SQL_PARAM_INPUT, SQL_C_DEFAULT, 5, 0, 0, (SQLPOINTER)TK_INTSOHSHSET.constData(), 0, &cbTK_INTSOHSHSET);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
	}
	if (m_ReplicationOption == ReplicationOption::NetChange)
	{
		r = SQLBindParameter(hStmt_Update, 31, SQL_PARAM_INPUT, SQL_C_DEFAULT, 3, 0, 0, (SQLPOINTER)AREA.constData(), 0, &cbAREA);
		if (r == SQL_SUCCESS) { isValid=true; }
		r = SQLBindParameter(hStmt_Update, 32, SQL_PARAM_INPUT, SQL_C_DEFAULT, 4, 0, 0, (SQLPOINTER)PAGE.constData(), 0, &cbPAGE);
		if (r == SQL_SUCCESS) { isValid=true; }
		r = SQLBindParameter(hStmt_Update, 33, SQL_PARAM_INPUT, SQL_C_DEFAULT, 25, 0, 0, (SQLPOINTER)TK_INTPOLINE.constData(), 0, &cbTK_INTPOLINE);
		if (r == SQL_SUCCESS) { isValid=true; }
	// TK_INTREC is a well formed table for eNVy Replication 
		 qDebug(category) << " Parameters: Ordinal [3] 00 00 FieldName: AREA ";
		 qDebug(category) << " Parameters: Ordinal [4] 00 00  FieldName: PAGE ";
		 qDebug(category) << " Parameters: Ordinal [25] 00 00 FieldName:  TK_INTPOLINE ";
	} // 	if (m_ReplicationOption == ReplicationOption::NetChange)
	return isValid;
}

bool TK_INTREC::process(int rowSize)
{
	QLoggingCategory category("classLibQ");
	initOdbcAttributes();
	connect(Source);
	connect(Target);
	initialize();
	prepareTargetTable();
	prepare();
	bindColumn();
	bindParameter();
	copyTable();
	close();
	return false;
}

void TK_INTREC::copyTable()
{
	QLoggingCategory category("classLibQ");
	RETCODE r;
	QString check;
	r = SQLExecute(hStmt_Fetch);
		if (bIsAbort) {
			emit aborted(tableName, rowsFetched, rowsInserted, rowsUpdated);
			return;
		}
		while((r = SQLFetch(hStmt_Fetch)) != SQL_NO_DATA) {
		if (r != SQL_SUCCESS) {
			check = qWarnODBCHandle(SQL_HANDLE_STMT, hStmt_Fetch);
			qCCritical(category) << QString("SqlFetch - Error : %1 is %2").arg(fetchSql).arg(check);
			return;
		} 
		rowsFetched++;
		if (m_ReplicationOption == ReplicationOption::BulkCopy)
		{
			r = SQLExecute(hStmt_Insert);
			if (r == SQL_ERROR) {
				check = qWarnODBCHandle(SQL_HANDLE_STMT, hStmt_Insert);
				 qCCritical(category) << QString("SqlExecute:Insert - Error : %1 is %2").arg(insertSql).arg(check);
				return;
			}
			rowsInserted++;
			if ((rowsFetched % updateInterval) == 0) {
				qCInfo(category) << QString("[%1.%2]	Insertion: %3	Updates : %4	Fetched : %5").arg(profileName).arg(tableName).arg(rowsInserted).arg(rowsUpdated).arg(rowsFetched);
				emit updateStatusFetched(profileName, tableName, rowsFetched,rowsInserted,rowsUpdated);
			}
			if (m_ReplicationOption == ReplicationOption::NetChange)
			{
			r = SQLExecute(hStmt_Update);
			if (r != SQL_SUCCESS) {
				check = qWarnODBCHandle(SQL_HANDLE_STMT, hStmt_Update);
				 qCInfo(category)  << QString("SqlExecute:Update - Error : %1 is %2").arg(updateSql).arg(check);
				r = SQLExecute(hStmt_Insert);
				if (r != SQL_SUCCESS) {
					check = qWarnODBCHandle(SQL_HANDLE_STMT, hStmt_Insert);
					 qCritical(category) << QString("SqlExecute:Insert - Error : %1 is %2").arg(insertSql).arg(check);
					return;
				}
				else 	rowsInserted++;
				}
				else	rowsUpdated++;
			}
			emit updateStatusFetched(profileName, tableName, rowsFetched,rowsInserted,rowsUpdated);
		}
	} 
qCInfo(category) << QString("[%1.%2]	Insertion: %3	Updates : %4	Fetched : %5").arg(profileName).arg(tableName).arg(rowsInserted).arg(rowsUpdated).arg(rowsFetched);
}

void TK_INTREC::connect(connectionHandle connectionSource)
{

	QLoggingCategory category("classLibQ");
	RETCODE r;

	bool isValid = false;
	HWND	hWnd = nullptr;
	hWnd = ::GetDesktopWindow(); 
	SQLSMALLINT nResult = 0;

	SQLSMALLINT cb;
	UWORD wConnectOption = SQL_DRIVER_COMPLETE; //SQL_DRIVER_NOPROMPT;
	QVarLengthArray<SQLTCHAR> connOut(1024);
	memset(connOut.data(), 0, connOut.size() * sizeof(SQLTCHAR));

	switch (connectionSource)
	{
		case Source:
			{// environment
				SQLHANDLE hEnv = SQL_NULL_HANDLE;
				SQLHANDLE hDbc = SQL_NULL_HANDLE;
				r = ::SQLAllocHandle(SQL_HANDLE_ENV, SQL_NULL_HANDLE, &hEnv);
				if (r == SQL_SUCCESS) isValid = true;

				foreach(nOdbcAttributesClass * k, this->m_OdbcAttributes_Map)
				{
					if (k->attributeType == enumAttributeType::hEnv)
					{
						r = ::SQLSetEnvAttr(hEnv, (SQLINTEGER) k->odbcKey, (SQLPOINTER)k->odbcValue, 0);
						if (r == SQL_SUCCESS) isValid = true;
					}
				}
				hEnv_Source = hEnv;

				r = SQLAllocHandle(SQL_HANDLE_DBC, hEnv, &hDbc);
				if (r == SQL_SUCCESS) isValid = true;
				foreach(nOdbcAttributesClass * k, this->m_OdbcAttributes_Map)
				{
					if (k->attributeType == enumAttributeType::hDbc)
					{
					r = ::SQLSetConnectAttr(hDbc, k->odbcKey, (SQLPOINTER)k->odbcValue, 0);
					if (k->odbcKey == SQL_ATTR_CONNECTION_POOLING && k->odbcValue == SQL_CP_ONE_PER_DRIVER) wConnectOption = SQL_DRIVER_NOPROMPT;
					if (k->odbcKey == SQL_ATTR_CONNECTION_POOLING && k->odbcValue == SQL_CP_ONE_PER_HENV) wConnectOption = SQL_DRIVER_NOPROMPT;
					if (k->odbcKey == SQL_ATTR_CONNECTION_POOLING && k->odbcValue == SQL_CP_DRIVER_AWARE) wConnectOption = SQL_DRIVER_NOPROMPT;
					if (r == SQL_SUCCESS) isValid = true;
					}
				}
				hDbc_source = hDbc;
				if (isValid)
				{
					r = ::SQLDriverConnect(
						hDbc,
						hWnd,
#ifdef UNICODE
						toSQLTCHAR(m_lpszSourceDSN).data(),
#else
						(SQLCHAR*)dsnSource.toUtf8().data(),
#endif
						(SQLSMALLINT)m_lpszSourceDSN.length(),
						connOut.data(),
						1024,
						&cb, 
						wConnectOption); 
					int colSize = cb / sizeof(SQLTCHAR);
					if (r != SQL_SUCCESS && r != SQL_SUCCESS_WITH_INFO)
					{
						QString check = qWarnODBCHandle(SQL_HANDLE_DBC, hDbc);
						qCritical(category) <<  check;
						m_bIsOpen = false;
					}
					m_bIsOpen = true;
				}
			} break;
		case Target:
			{
				SQLHANDLE hEnv = SQL_NULL_HANDLE;
				SQLHANDLE hDbc = SQL_NULL_HANDLE;
				r = ::SQLAllocHandle(SQL_HANDLE_ENV, SQL_NULL_HANDLE, &hEnv);
				if (r == SQL_SUCCESS) isValid = true;

				foreach(nOdbcAttributesClass * k, this->m_OdbcAttributes_Map)
				{
					if (k->attributeType == enumAttributeType::hEnv)
					{
						r = ::SQLSetEnvAttr(hEnv, (SQLINTEGER) k->odbcKey, (SQLPOINTER)k->odbcValue, 0);
						if (r == SQL_SUCCESS) isValid = true;
					}
				}
				hEnv_Target = hEnv;

				r = SQLAllocHandle(SQL_HANDLE_DBC, hEnv, &hDbc);
				if (r == SQL_SUCCESS) isValid = true;
				foreach(nOdbcAttributesClass * k, this->m_OdbcAttributes_Map)
				{
				if (k->attributeType == enumAttributeType::hDbc)
					{
					r = ::SQLSetConnectAttr(hDbc, k->odbcKey, (SQLPOINTER)k->odbcValue, 0);
					if (k->odbcKey == SQL_ATTR_CONNECTION_POOLING && k->odbcValue == SQL_CP_ONE_PER_DRIVER) wConnectOption = SQL_DRIVER_NOPROMPT;
					if (k->odbcKey == SQL_ATTR_CONNECTION_POOLING && k->odbcValue == SQL_CP_ONE_PER_HENV) wConnectOption = SQL_DRIVER_NOPROMPT;
					if (k->odbcKey == SQL_ATTR_CONNECTION_POOLING && k->odbcValue == SQL_CP_DRIVER_AWARE) wConnectOption = SQL_DRIVER_NOPROMPT;
					if (r == SQL_SUCCESS) isValid = true;
					}
				}
				hDbc_target = hDbc;
				if (isValid) {
					r = ::SQLDriverConnect(
						hDbc,
						hWnd,
#ifdef UNICODE
						toSQLTCHAR(m_lpszTargetDSN).data(),
#else
						(SQLCHAR*)m_lpszTargetDSN.toUtf8().data(),
#endif
						(SQLSMALLINT)m_lpszTargetDSN.length(),
						connOut.data(),
						1024,
						&cb, 
						wConnectOption); 
						int colSize = cb / sizeof(SQLTCHAR);
					if (r != SQL_SUCCESS && r != SQL_SUCCESS_WITH_INFO)
						{
							QString check = qWarnODBCHandle(SQL_HANDLE_DBC, hDbc);
							qCritical(category) <<  check;
							m_bIsOpen = false;
						}
							m_bIsOpen = true;
					}
			} break;
			default: break;
	}
}
TK_LTPCOMSET::TK_LTPCOMSET(QObject * parent) : QObject(parent) 
,tableName("TK_LTPCOMSET")
,m_dropOption(DropOption::DropTable) { 
	numRowsFetched = 0;
}

#pragma region ~CTOR TK_LTPCOMSET 
TK_LTPCOMSET::~TK_LTPCOMSET() { 

#pragma region Buffers - Clear 
	DB_ID.clear();
	NVTIMESTAMP.clear();
	OAREA.clear();
	OPAGE.clear();
	OLINE.clear();
	MAREA.clear();
	MPAGE.clear();
	MLINE.clear();
#pragma endregion Buffers - Clear 
}
#pragma endregion Destructor_TK_LTPCOMSET

// begin method functions
void TK_LTPCOMSET::setAbortFlag() { 
	QLoggingCategory category("classLibQ");
	qCInfo(category) << "isAbort was set to True";
	bIsAbort = true;
}

void TK_LTPCOMSET::run() { 
	process(1);
	QLoggingCategory category("classLibQ");
	qDebug(category) << "Entered;";
}

void	TK_LTPCOMSET::initOdbcAttributes()
{
	QLoggingCategory category("classLibQ");
	this->setProfileName(profileName);
	qDebug(category) << "Processing - TRKDB100"; 
	m_OdbcAttributesList = m_OdbcAttributes.split(","); 
	foreach(QString m, m_OdbcAttributesList)
	{
		QStringList keyValue = m.split("=");
		nOdbcAttributesClass * oM = new nOdbcAttributesClass(this);
		if (oM->loadToOdbc(keyValue.value(0), keyValue.value(1)))
		{
			m_OdbcAttributes_Map.insert(oM->odbcKey, oM);
		}
	}
}
void	TK_LTPCOMSET::initialize()
{
	QLoggingCategory category("classLibQ");
	RETCODE r;
	this->setProfileName(profileName);
	qDebug(category) << "Processing - TRKDB100"; 
//SQL Statements
//--------------------------------------------------

#pragma region Sql Statements_TK_LTPCOMSET

	fetchSql = "select  DB_ID, NVTIMESTAMP, OAREA, OPAGE, OLINE, MAREA, MPAGE, MLINE from TK_LTPCOMSET";
		if (m_ReplicationOption == ReplicationOption::NetChange)
		{
			fetchSql.append(" p1, nv_transfers p2 WHERE  p2.table_name = 'TK_LTPCOMSET' AND p1.nvtimestamp > p2.last_completed");
		}
	insertSql = "insert into TK_LTPCOMSET ( PLANT_CODE, NVTIMESTAMP, OAREA, OPAGE, OLINE, MAREA, MPAGE, MLINE ) values ( ?, ?, ?, ?, ?, ?, ?, ?)";
	updateSql = "update TK_LTPCOMSET set  PLANT_CODE = ?, NVTIMESTAMP = ?, OAREA = ?, OPAGE = ?, OLINE = ?, MAREA = ?, MPAGE = ?, MLINE = ?  where area = ? and page = ? line = ? ";

	qDebug(category) << "insertSQL - insert into TK_LTPCOMSET ( PLANT_CODE, NVTIMESTAMP, OAREA, OPAGE, OLINE, MAREA, MPAGE, MLINE ) values ( ?, ?, ?, ?, ?, ?, ?, ?)";
	qDebug(category) << "fetchSQL - select  DB_ID, NVTIMESTAMP, OAREA, OPAGE, OLINE, MAREA, MPAGE, MLINE from TK_LTPCOMSET";
	qDebug(category) << "unsertSQL - update TK_LTPCOMSET set  PLANT_CODE = ?, NVTIMESTAMP = ?, OAREA = ?, OPAGE = ?, OLINE = ?, MAREA = ?, MPAGE = ?, MLINE = ?  where area = ? and page = ? line = ? ";

#pragma endregion Sql Statements_TK_LTPCOMSET
	SQLHANDLE		insert_hStmt = SQL_NULL_HANDLE;
	SQLHANDLE		fetch_hStmt = SQL_NULL_HANDLE; 
	SQLHANDLE		update_hStmt = SQL_NULL_HANDLE; 
 
	r = ::SQLAllocHandle(SQL_HANDLE_STMT, hDbc_source, &fetch_hStmt);
	if (r != SQL_SUCCESS) {
		 qCCritical(category) << QString("Error  hDbc_Source SQLCode : %1 is %2").arg(QString::number( (long)hDbc_source)).arg(QString::number(r));
		return; 
	}
	r = ::SQLAllocHandle(SQL_HANDLE_STMT, hDbc_target, &insert_hStmt);
	if (r != SQL_SUCCESS) {
		 qCCritical(category) << QString("Error hDbc_Source -SQLCode: %1 is %2").arg(QString::number( (long)hDbc_target)).arg(QString::number(r));
		return; 
	}
	r = ::SQLAllocHandle(SQL_HANDLE_STMT, hDbc_target, &update_hStmt);
	if (r != SQL_SUCCESS) {
		 qCCritical(category) << QString("Error hDbc_Source +SQLCode: %1 is %2").arg(QString::number( (long)hDbc_target)).arg(QString::number(r));
		return; 
	}
 
	hStmt_Fetch = fetch_hStmt;
	hStmt_Insert = insert_hStmt;
	hStmt_Update = update_hStmt;
 
	SQLSetStmtAttr(hStmt_Fetch, SQL_ATTR_USE_BOOKMARKS, (SQLPOINTER)SQL_UB_OFF, 0);
	SQLSetStmtAttr(hStmt_Fetch, SQL_ATTR_ROW_BIND_TYPE, (SQLPOINTER)SQL_BIND_BY_COLUMN, 0);
	SQLSetStmtAttr(hStmt_Fetch, SQL_ATTR_ROW_ARRAY_SIZE, (SQLPOINTER)1, 0);
	SQLSetStmtAttr(hStmt_Fetch, SQL_ATTR_ROWS_FETCHED_PTR, &numRowsFetched, 0);

// Fields used by this class 
// ---------------------------------------------------

#pragma region Resize Fields TK_LTPCOMSET
	qDebug(category) << "Malloc - DB_ID[2]";
	DB_ID.resize(2);
	qDebug(category) << "Malloc - NVTIMESTAMP[23]";
	NVTIMESTAMP.resize(23);
	qDebug(category) << "Malloc - OAREA[2]";
	OAREA.resize(2);
	qDebug(category) << "Malloc - OPAGE[4]";
	OPAGE.resize(4);
	qDebug(category) << "Malloc - OLINE[2]";
	OLINE.resize(2);
	qDebug(category) << "Malloc - MAREA[2]";
	MAREA.resize(2);
	qDebug(category) << "Malloc - MPAGE[4]";
	MPAGE.resize(4);
	qDebug(category) << "Malloc - MLINE[2]";
	MLINE.resize(2);

#pragma endregion Resize Fields TK_LTPCOMSET
}
void TK_LTPCOMSET::close()
{
	QLoggingCategory category("classLibQ");
	if (m_bIsOpen)
	{
	qDebug(category) << "database is Open";
		SQLHANDLE source_hStmt = hStmt_Fetch;
		SQLHANDLE insert_hStmt = hStmt_Insert;
		SQLHANDLE hDb_S = this->hDbc_source;
		SQLHANDLE hDb_T = hDbc_target;
		SQLHANDLE hEnvS = hEnv_Source;
		SQLHANDLE hEnvT = hEnv_Target;
		RETCODE r;

		r = ::SQLFreeHandle(SQL_HANDLE_STMT, hStmt_Fetch);
		r = ::SQLFreeHandle(SQL_HANDLE_STMT, hStmt_Insert);
		r = ::SQLFreeHandle(SQL_HANDLE_STMT, hStmt_Update);
		if (hDbc_source != SQL_NULL_HANDLE) 		r = ::SQLDisconnect(hDb_S);
		if (hDbc_target != SQL_NULL_HANDLE) 		r = ::SQLDisconnect(hDb_T);

		r = ::SQLFreeHandle(SQL_HANDLE_DBC, hDb_S);
		r = ::SQLFreeHandle(SQL_HANDLE_DBC, hDb_T);
		r = ::SQLFreeHandle(SQL_HANDLE_ENV, hEnvS);
		r = ::SQLFreeHandle(SQL_HANDLE_ENV, hEnvT);
	}

	hEnv_Source = SQL_NULL_HANDLE;
	hEnv_Target = SQL_NULL_HANDLE;
	hEnv_Source = SQL_NULL_HANDLE;
	hEnv_Target = SQL_NULL_HANDLE;
	hStmt_Fetch = SQL_NULL_HANDLE;
	hStmt_Insert = SQL_NULL_HANDLE;
	hStmt_Update = SQL_NULL_HANDLE;
}

void TK_LTPCOMSET::open(const QString sourceDSN, const QString targetDSN)
{
	QLoggingCategory category("classLibQ");
	m_lpszTargetDSN = targetDSN;
	m_lpszSourceDSN = sourceDSN;
	qDebug(category) << QString("Source - %1[%2]").arg(sourceDSN);
	qDebug(category) << QString("Target - %1[%2]").arg(targetDSN);
}

void TK_LTPCOMSET::createTable()
{
	QLoggingCategory category("classLibQ");
	{
		QScopedPointer<nvTableOracleRdb> tbl(new nvTableOracleRdb(nullptr));
		tbl->initialize("TK_LTPCOMSET", this->m_lpszSourceDSN);
		QString newTbl = tbl->getCreateTableSQL();
		QScopedPointer<qVtExecute> vExec(new qVtExecute(nullptr));
		{
			vExec->initialize(m_lpszTargetDSN, " ", true);
			vExec->setOdbcAttributes(m_OdbcAttributes);
			vExec->ExecuteDirect(newTbl);
		}
	 qDebug(category) << QString("End Create Table %1 ").arg(tableName); 
	}
}

bool TK_LTPCOMSET::prepare()
{
	RETCODE r;
	QString check;
	QLoggingCategory category("classLibQ");
	 qDebug(category) << fetchSql;
	 qDebug(category) << insertSql;
#ifdef UNICODE
	r = SQLPrepare(hStmt_Insert,toSQLTCHAR(insertSql).data(),(SQLINTEGER)insertSql.length()); 
	if (r != SQL_SUCCESS) {
		check = qWarnODBCHandle(SQL_HANDLE_STMT, hStmt_Insert);
		 qCCritical(category) << QString("Prepare Statement-Insert : %1 is %2").arg(insertSql).arg(check);
		return false; 
	}
	r = SQLPrepare(hStmt_Update,toSQLTCHAR(updateSql).data(),(SQLINTEGER)updateSql.length()); 
	if (r != SQL_SUCCESS) {
		check = qWarnODBCHandle(SQL_HANDLE_STMT, hStmt_Update);
		 qCCritical(category) << QString("Prepare Statement-Update : %1 is %2").arg(updateSql).arg(check);
		return false; 
	}
	r = SQLPrepare(hStmt_Fetch,toSQLTCHAR(fetchSql).data(),(SQLINTEGER)fetchSql.length());
	if (r != SQL_SUCCESS) {
		check = qWarnODBCHandle(SQL_HANDLE_STMT, hStmt_Fetch);
		 qCCritical(category) << QString("Prepare Statement-Insert : %1 is %2").arg(fetchSql).arg(check);
		return false; 
	}
#else
	QByteArray queryI8 = insertSql.toUtf8();
	r = SQLPrepare(insert_hStmt,SQLCHAR*)queryI8.data(),(SQLINTEGER)queryI8.length());
	QByteArray queryU8 = fetchSql.toUtf8();
	r = SQLPrepare(hStmt_Fetch,(SQLCHAR*)queryU8.data(),(SQLINTEGER)queryU8.length());
#endif
	return true;

}

void TK_LTPCOMSET::prepareTargetTable()
{
	QLoggingCategory category("classLibQ");
	if (this->m_ReplicationOption == ReplicationOption::BulkCopy)
	{
		QScopedPointer<qVtExecute> execSql(new qVtExecute(nullptr));
		DropOption option = this->m_dropOption;
		switch (option)
		{
			case DropOption::DeleteFromTable:
			{
				QLoggingCategory category("classLibQ");
				execSql->initialize(this->m_lpszTargetDSN, "delete from TK_LTPCOMSET", true);
				execSql->setOdbcAttributes(this->m_OdbcAttributes);
				execSql->ExecuteDirect("delete from TK_LTPCOMSET");
			}break;
			case DropOption::TruncateTable:
			{
				execSql->initialize(this->m_lpszTargetDSN, "truncate table TK_LTPCOMSET", true);
				execSql->setOdbcAttributes(this->m_OdbcAttributes);
				execSql->ExecuteDirect("truncate table TK_LTPCOMSET");
			}break;
			case DropOption::DropTable:
			{
				execSql->initialize(this->m_lpszTargetDSN, "drop table TK_LTPCOMSET", true);
				execSql->setOdbcAttributes(this->m_OdbcAttributes);
				execSql->ExecuteDirect("drop table TK_LTPCOMSET");
				createTable();
			}break;
		}
	}
}

bool TK_LTPCOMSET::bindColumn()
{
	QLoggingCategory category("classLibQ");
	RETCODE r;
	bool isValid=true;
		 qDebug(category) << " Bindings: Ordinal [1] Type: 5 Buffer Size: 2 FieldName: DB_ID ";
		r = ::SQLBindCol(hStmt_Fetch, 1, 5, DB_ID.data(), 2, &cbDB_ID);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Bindings: Ordinal [2] Type: 93 Buffer Size: 23 FieldName: NVTIMESTAMP ";
		r = ::SQLBindCol(hStmt_Fetch, 2, 93, NVTIMESTAMP.data(), 23, &cbNVTIMESTAMP);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Bindings: Ordinal [3] Type: 5 Buffer Size: 2 FieldName: OAREA ";
		r = ::SQLBindCol(hStmt_Fetch, 3, 5, OAREA.data(), 2, &cbOAREA);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Bindings: Ordinal [4] Type: 4 Buffer Size: 4 FieldName: OPAGE ";
		r = ::SQLBindCol(hStmt_Fetch, 4, 4, OPAGE.data(), 4, &cbOPAGE);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Bindings: Ordinal [5] Type: 5 Buffer Size: 2 FieldName: OLINE ";
		r = ::SQLBindCol(hStmt_Fetch, 5, 5, OLINE.data(), 2, &cbOLINE);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Bindings: Ordinal [6] Type: 5 Buffer Size: 2 FieldName: MAREA ";
		r = ::SQLBindCol(hStmt_Fetch, 6, 5, MAREA.data(), 2, &cbMAREA);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Bindings: Ordinal [7] Type: 4 Buffer Size: 4 FieldName: MPAGE ";
		r = ::SQLBindCol(hStmt_Fetch, 7, 4, MPAGE.data(), 4, &cbMPAGE);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Bindings: Ordinal [8] Type: 5 Buffer Size: 2 FieldName: MLINE ";
		r = ::SQLBindCol(hStmt_Fetch, 8, 5, MLINE.data(), 2, &cbMLINE);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
	return isValid;
}

bool TK_LTPCOMSET::bindParameter()
{
	QLoggingCategory category("classLibQ");
	RETCODE r;
	bool isValid=true;
	{
		 qDebug(category) << " Parameters: Ordinal [1] Type: 5 Buffer Size: 2 FieldName: DB_ID ";
		r = SQLBindParameter(hStmt_Insert, 1, SQL_PARAM_INPUT, SQL_C_DEFAULT, 5, 0, 0, (SQLPOINTER)DB_ID.constData(), 0, &cbDB_ID);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Parameters: Ordinal [2] Type: 93 Buffer Size: 23 FieldName: NVTIMESTAMP ";
		r = SQLBindParameter(hStmt_Insert, 2, SQL_PARAM_INPUT, SQL_C_DEFAULT, 93, 23, 0, (SQLPOINTER)NVTIMESTAMP.constData(), 0, &cbNVTIMESTAMP);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Parameters: Ordinal [3] Type: 5 Buffer Size: 2 FieldName: OAREA ";
		r = SQLBindParameter(hStmt_Insert, 3, SQL_PARAM_INPUT, SQL_C_DEFAULT, 5, 0, 0, (SQLPOINTER)OAREA.constData(), 0, &cbOAREA);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Parameters: Ordinal [4] Type: 4 Buffer Size: 4 FieldName: OPAGE ";
		r = SQLBindParameter(hStmt_Insert, 4, SQL_PARAM_INPUT, SQL_C_DEFAULT, 4, 0, 0, (SQLPOINTER)OPAGE.constData(), 0, &cbOPAGE);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Parameters: Ordinal [5] Type: 5 Buffer Size: 2 FieldName: OLINE ";
		r = SQLBindParameter(hStmt_Insert, 5, SQL_PARAM_INPUT, SQL_C_DEFAULT, 5, 0, 0, (SQLPOINTER)OLINE.constData(), 0, &cbOLINE);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Parameters: Ordinal [6] Type: 5 Buffer Size: 2 FieldName: MAREA ";
		r = SQLBindParameter(hStmt_Insert, 6, SQL_PARAM_INPUT, SQL_C_DEFAULT, 5, 0, 0, (SQLPOINTER)MAREA.constData(), 0, &cbMAREA);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Parameters: Ordinal [7] Type: 4 Buffer Size: 4 FieldName: MPAGE ";
		r = SQLBindParameter(hStmt_Insert, 7, SQL_PARAM_INPUT, SQL_C_DEFAULT, 4, 0, 0, (SQLPOINTER)MPAGE.constData(), 0, &cbMPAGE);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Parameters: Ordinal [8] Type: 5 Buffer Size: 2 FieldName: MLINE ";
		r = SQLBindParameter(hStmt_Insert, 8, SQL_PARAM_INPUT, SQL_C_DEFAULT, 5, 0, 0, (SQLPOINTER)MLINE.constData(), 0, &cbMLINE);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
	}
	if (m_ReplicationOption == ReplicationOption::NetChange)
	{
		r = SQLBindParameter(hStmt_Update, 9, SQL_PARAM_INPUT, SQL_C_DEFAULT, 6, 0, 0, (SQLPOINTER)MAREA.constData(), 0, &cbMAREA);
		if (r == SQL_SUCCESS) { isValid=true; }
		r = SQLBindParameter(hStmt_Update, 10, SQL_PARAM_INPUT, SQL_C_DEFAULT, 7, 0, 0, (SQLPOINTER)MPAGE.constData(), 0, &cbMPAGE);
		if (r == SQL_SUCCESS) { isValid=true; }
		r = SQLBindParameter(hStmt_Update, 11, SQL_PARAM_INPUT, SQL_C_DEFAULT, 8, 0, 0, (SQLPOINTER)MLINE.constData(), 0, &cbMLINE);
		if (r == SQL_SUCCESS) { isValid=true; }
	// TK_LTPCOMSET is a well formed table for eNVy Replication 
		 qDebug(category) << " Parameters: Ordinal [6] 00 00 FieldName: MAREA ";
		 qDebug(category) << " Parameters: Ordinal [7] 00 00  FieldName: MPAGE ";
		 qDebug(category) << " Parameters: Ordinal [8] 00 00 FieldName:  MLINE ";
	} // 	if (m_ReplicationOption == ReplicationOption::NetChange)
	return isValid;
}

bool TK_LTPCOMSET::process(int rowSize)
{
	QLoggingCategory category("classLibQ");
	initOdbcAttributes();
	connect(Source);
	connect(Target);
	initialize();
	prepareTargetTable();
	prepare();
	bindColumn();
	bindParameter();
	copyTable();
	close();
	return false;
}

void TK_LTPCOMSET::copyTable()
{
	QLoggingCategory category("classLibQ");
	RETCODE r;
	QString check;
	r = SQLExecute(hStmt_Fetch);
		if (bIsAbort) {
			emit aborted(tableName, rowsFetched, rowsInserted, rowsUpdated);
			return;
		}
		while((r = SQLFetch(hStmt_Fetch)) != SQL_NO_DATA) {
		if (r != SQL_SUCCESS) {
			check = qWarnODBCHandle(SQL_HANDLE_STMT, hStmt_Fetch);
			qCCritical(category) << QString("SqlFetch - Error : %1 is %2").arg(fetchSql).arg(check);
			return;
		} 
		rowsFetched++;
		if (m_ReplicationOption == ReplicationOption::BulkCopy)
		{
			r = SQLExecute(hStmt_Insert);
			if (r == SQL_ERROR) {
				check = qWarnODBCHandle(SQL_HANDLE_STMT, hStmt_Insert);
				 qCCritical(category) << QString("SqlExecute:Insert - Error : %1 is %2").arg(insertSql).arg(check);
				return;
			}
			rowsInserted++;
			if ((rowsFetched % updateInterval) == 0) {
				qCInfo(category) << QString("[%1.%2]	Insertion: %3	Updates : %4	Fetched : %5").arg(profileName).arg(tableName).arg(rowsInserted).arg(rowsUpdated).arg(rowsFetched);
				emit updateStatusFetched(profileName, tableName, rowsFetched,rowsInserted,rowsUpdated);
			}
			if (m_ReplicationOption == ReplicationOption::NetChange)
			{
			r = SQLExecute(hStmt_Update);
			if (r != SQL_SUCCESS) {
				check = qWarnODBCHandle(SQL_HANDLE_STMT, hStmt_Update);
				 qCInfo(category)  << QString("SqlExecute:Update - Error : %1 is %2").arg(updateSql).arg(check);
				r = SQLExecute(hStmt_Insert);
				if (r != SQL_SUCCESS) {
					check = qWarnODBCHandle(SQL_HANDLE_STMT, hStmt_Insert);
					 qCritical(category) << QString("SqlExecute:Insert - Error : %1 is %2").arg(insertSql).arg(check);
					return;
				}
				else 	rowsInserted++;
				}
				else	rowsUpdated++;
			}
			emit updateStatusFetched(profileName, tableName, rowsFetched,rowsInserted,rowsUpdated);
		}
	} 
qCInfo(category) << QString("[%1.%2]	Insertion: %3	Updates : %4	Fetched : %5").arg(profileName).arg(tableName).arg(rowsInserted).arg(rowsUpdated).arg(rowsFetched);
}

void TK_LTPCOMSET::connect(connectionHandle connectionSource)
{

	QLoggingCategory category("classLibQ");
	RETCODE r;

	bool isValid = false;
	HWND	hWnd = nullptr;
	hWnd = ::GetDesktopWindow(); 
	SQLSMALLINT nResult = 0;

	SQLSMALLINT cb;
	UWORD wConnectOption = SQL_DRIVER_COMPLETE; //SQL_DRIVER_NOPROMPT;
	QVarLengthArray<SQLTCHAR> connOut(1024);
	memset(connOut.data(), 0, connOut.size() * sizeof(SQLTCHAR));

	switch (connectionSource)
	{
		case Source:
			{// environment
				SQLHANDLE hEnv = SQL_NULL_HANDLE;
				SQLHANDLE hDbc = SQL_NULL_HANDLE;
				r = ::SQLAllocHandle(SQL_HANDLE_ENV, SQL_NULL_HANDLE, &hEnv);
				if (r == SQL_SUCCESS) isValid = true;

				foreach(nOdbcAttributesClass * k, this->m_OdbcAttributes_Map)
				{
					if (k->attributeType == enumAttributeType::hEnv)
					{
						r = ::SQLSetEnvAttr(hEnv, (SQLINTEGER) k->odbcKey, (SQLPOINTER)k->odbcValue, 0);
						if (r == SQL_SUCCESS) isValid = true;
					}
				}
				hEnv_Source = hEnv;

				r = SQLAllocHandle(SQL_HANDLE_DBC, hEnv, &hDbc);
				if (r == SQL_SUCCESS) isValid = true;
				foreach(nOdbcAttributesClass * k, this->m_OdbcAttributes_Map)
				{
					if (k->attributeType == enumAttributeType::hDbc)
					{
					r = ::SQLSetConnectAttr(hDbc, k->odbcKey, (SQLPOINTER)k->odbcValue, 0);
					if (k->odbcKey == SQL_ATTR_CONNECTION_POOLING && k->odbcValue == SQL_CP_ONE_PER_DRIVER) wConnectOption = SQL_DRIVER_NOPROMPT;
					if (k->odbcKey == SQL_ATTR_CONNECTION_POOLING && k->odbcValue == SQL_CP_ONE_PER_HENV) wConnectOption = SQL_DRIVER_NOPROMPT;
					if (k->odbcKey == SQL_ATTR_CONNECTION_POOLING && k->odbcValue == SQL_CP_DRIVER_AWARE) wConnectOption = SQL_DRIVER_NOPROMPT;
					if (r == SQL_SUCCESS) isValid = true;
					}
				}
				hDbc_source = hDbc;
				if (isValid)
				{
					r = ::SQLDriverConnect(
						hDbc,
						hWnd,
#ifdef UNICODE
						toSQLTCHAR(m_lpszSourceDSN).data(),
#else
						(SQLCHAR*)dsnSource.toUtf8().data(),
#endif
						(SQLSMALLINT)m_lpszSourceDSN.length(),
						connOut.data(),
						1024,
						&cb, 
						wConnectOption); 
					int colSize = cb / sizeof(SQLTCHAR);
					if (r != SQL_SUCCESS && r != SQL_SUCCESS_WITH_INFO)
					{
						QString check = qWarnODBCHandle(SQL_HANDLE_DBC, hDbc);
						qCritical(category) <<  check;
						m_bIsOpen = false;
					}
					m_bIsOpen = true;
				}
			} break;
		case Target:
			{
				SQLHANDLE hEnv = SQL_NULL_HANDLE;
				SQLHANDLE hDbc = SQL_NULL_HANDLE;
				r = ::SQLAllocHandle(SQL_HANDLE_ENV, SQL_NULL_HANDLE, &hEnv);
				if (r == SQL_SUCCESS) isValid = true;

				foreach(nOdbcAttributesClass * k, this->m_OdbcAttributes_Map)
				{
					if (k->attributeType == enumAttributeType::hEnv)
					{
						r = ::SQLSetEnvAttr(hEnv, (SQLINTEGER) k->odbcKey, (SQLPOINTER)k->odbcValue, 0);
						if (r == SQL_SUCCESS) isValid = true;
					}
				}
				hEnv_Target = hEnv;

				r = SQLAllocHandle(SQL_HANDLE_DBC, hEnv, &hDbc);
				if (r == SQL_SUCCESS) isValid = true;
				foreach(nOdbcAttributesClass * k, this->m_OdbcAttributes_Map)
				{
				if (k->attributeType == enumAttributeType::hDbc)
					{
					r = ::SQLSetConnectAttr(hDbc, k->odbcKey, (SQLPOINTER)k->odbcValue, 0);
					if (k->odbcKey == SQL_ATTR_CONNECTION_POOLING && k->odbcValue == SQL_CP_ONE_PER_DRIVER) wConnectOption = SQL_DRIVER_NOPROMPT;
					if (k->odbcKey == SQL_ATTR_CONNECTION_POOLING && k->odbcValue == SQL_CP_ONE_PER_HENV) wConnectOption = SQL_DRIVER_NOPROMPT;
					if (k->odbcKey == SQL_ATTR_CONNECTION_POOLING && k->odbcValue == SQL_CP_DRIVER_AWARE) wConnectOption = SQL_DRIVER_NOPROMPT;
					if (r == SQL_SUCCESS) isValid = true;
					}
				}
				hDbc_target = hDbc;
				if (isValid) {
					r = ::SQLDriverConnect(
						hDbc,
						hWnd,
#ifdef UNICODE
						toSQLTCHAR(m_lpszTargetDSN).data(),
#else
						(SQLCHAR*)m_lpszTargetDSN.toUtf8().data(),
#endif
						(SQLSMALLINT)m_lpszTargetDSN.length(),
						connOut.data(),
						1024,
						&cb, 
						wConnectOption); 
						int colSize = cb / sizeof(SQLTCHAR);
					if (r != SQL_SUCCESS && r != SQL_SUCCESS_WITH_INFO)
						{
							QString check = qWarnODBCHandle(SQL_HANDLE_DBC, hDbc);
							qCritical(category) <<  check;
							m_bIsOpen = false;
						}
							m_bIsOpen = true;
					}
			} break;
			default: break;
	}
}
TK_HDRREC::TK_HDRREC(QObject * parent) : QObject(parent) 
,tableName("TK_HDRREC")
,m_dropOption(DropOption::DropTable) { 
	numRowsFetched = 0;
}

#pragma region ~CTOR TK_HDRREC 
TK_HDRREC::~TK_HDRREC() { 

#pragma region Buffers - Clear 
	DB_ID.clear();
	NVTIMESTAMP.clear();
	AREA.clear();
	PAGE.clear();
	LINE.clear();
	TK_HDRCODE.clear();
	TK_HDRNO.clear();
	TK_HDRKEY1.clear();
	TK_TYPCODE.clear();
#pragma endregion Buffers - Clear 
}
#pragma endregion Destructor_TK_HDRREC

// begin method functions
void TK_HDRREC::setAbortFlag() { 
	QLoggingCategory category("classLibQ");
	qCInfo(category) << "isAbort was set to True";
	bIsAbort = true;
}

void TK_HDRREC::run() { 
	process(1);
	QLoggingCategory category("classLibQ");
	qDebug(category) << "Entered;";
}

void	TK_HDRREC::initOdbcAttributes()
{
	QLoggingCategory category("classLibQ");
	this->setProfileName(profileName);
	qDebug(category) << "Processing - TRKDB100"; 
	m_OdbcAttributesList = m_OdbcAttributes.split(","); 
	foreach(QString m, m_OdbcAttributesList)
	{
		QStringList keyValue = m.split("=");
		nOdbcAttributesClass * oM = new nOdbcAttributesClass(this);
		if (oM->loadToOdbc(keyValue.value(0), keyValue.value(1)))
		{
			m_OdbcAttributes_Map.insert(oM->odbcKey, oM);
		}
	}
}
void	TK_HDRREC::initialize()
{
	QLoggingCategory category("classLibQ");
	RETCODE r;
	this->setProfileName(profileName);
	qDebug(category) << "Processing - TRKDB100"; 
//SQL Statements
//--------------------------------------------------

#pragma region Sql Statements_TK_HDRREC

	fetchSql = "select  DB_ID, NVTIMESTAMP, AREA, PAGE, LINE, TK_HDRCODE, TK_HDRNO, TK_HDRKEY1, TK_TYPCODE from TK_HDRREC";
		if (m_ReplicationOption == ReplicationOption::NetChange)
		{
			fetchSql.append(" p1, nv_transfers p2 WHERE  p2.table_name = 'TK_HDRREC' AND p1.nvtimestamp > p2.last_completed");
		}
	insertSql = "insert into TK_HDRREC ( PLANT_CODE, NVTIMESTAMP, AREA, PAGE, LINE, TK_HDRCODE, TK_HDRNO, TK_HDRKEY1, TK_TYPCODE ) values ( ?, ?, ?, ?, ?, ?, ?, ?, ?)";
	updateSql = "update TK_HDRREC set  PLANT_CODE = ?, NVTIMESTAMP = ?, AREA = ?, PAGE = ?, LINE = ?, TK_HDRCODE = ?, TK_HDRNO = ?, TK_HDRKEY1 = ?, TK_TYPCODE = ?  where area = ? and page = ? line = ? ";

	qDebug(category) << "insertSQL - insert into TK_HDRREC ( PLANT_CODE, NVTIMESTAMP, AREA, PAGE, LINE, TK_HDRCODE, TK_HDRNO, TK_HDRKEY1, TK_TYPCODE ) values ( ?, ?, ?, ?, ?, ?, ?, ?, ?)";
	qDebug(category) << "fetchSQL - select  DB_ID, NVTIMESTAMP, AREA, PAGE, LINE, TK_HDRCODE, TK_HDRNO, TK_HDRKEY1, TK_TYPCODE from TK_HDRREC";
	qDebug(category) << "unsertSQL - update TK_HDRREC set  PLANT_CODE = ?, NVTIMESTAMP = ?, AREA = ?, PAGE = ?, LINE = ?, TK_HDRCODE = ?, TK_HDRNO = ?, TK_HDRKEY1 = ?, TK_TYPCODE = ?  where area = ? and page = ? line = ? ";

#pragma endregion Sql Statements_TK_HDRREC
	SQLHANDLE		insert_hStmt = SQL_NULL_HANDLE;
	SQLHANDLE		fetch_hStmt = SQL_NULL_HANDLE; 
	SQLHANDLE		update_hStmt = SQL_NULL_HANDLE; 
 
	r = ::SQLAllocHandle(SQL_HANDLE_STMT, hDbc_source, &fetch_hStmt);
	if (r != SQL_SUCCESS) {
		 qCCritical(category) << QString("Error  hDbc_Source SQLCode : %1 is %2").arg(QString::number( (long)hDbc_source)).arg(QString::number(r));
		return; 
	}
	r = ::SQLAllocHandle(SQL_HANDLE_STMT, hDbc_target, &insert_hStmt);
	if (r != SQL_SUCCESS) {
		 qCCritical(category) << QString("Error hDbc_Source -SQLCode: %1 is %2").arg(QString::number( (long)hDbc_target)).arg(QString::number(r));
		return; 
	}
	r = ::SQLAllocHandle(SQL_HANDLE_STMT, hDbc_target, &update_hStmt);
	if (r != SQL_SUCCESS) {
		 qCCritical(category) << QString("Error hDbc_Source +SQLCode: %1 is %2").arg(QString::number( (long)hDbc_target)).arg(QString::number(r));
		return; 
	}
 
	hStmt_Fetch = fetch_hStmt;
	hStmt_Insert = insert_hStmt;
	hStmt_Update = update_hStmt;
 
	SQLSetStmtAttr(hStmt_Fetch, SQL_ATTR_USE_BOOKMARKS, (SQLPOINTER)SQL_UB_OFF, 0);
	SQLSetStmtAttr(hStmt_Fetch, SQL_ATTR_ROW_BIND_TYPE, (SQLPOINTER)SQL_BIND_BY_COLUMN, 0);
	SQLSetStmtAttr(hStmt_Fetch, SQL_ATTR_ROW_ARRAY_SIZE, (SQLPOINTER)1, 0);
	SQLSetStmtAttr(hStmt_Fetch, SQL_ATTR_ROWS_FETCHED_PTR, &numRowsFetched, 0);

// Fields used by this class 
// ---------------------------------------------------

#pragma region Resize Fields TK_HDRREC
	qDebug(category) << "Malloc - DB_ID[2]";
	DB_ID.resize(2);
	qDebug(category) << "Malloc - NVTIMESTAMP[23]";
	NVTIMESTAMP.resize(23);
	qDebug(category) << "Malloc - AREA[2]";
	AREA.resize(2);
	qDebug(category) << "Malloc - PAGE[4]";
	PAGE.resize(4);
	qDebug(category) << "Malloc - LINE[2]";
	LINE.resize(2);
	qDebug(category) << "Malloc - TK_HDRCODE[2]";
	TK_HDRCODE.resize(2);
	qDebug(category) << "Malloc - TK_HDRNO[24]";
	TK_HDRNO.resize(24);
	qDebug(category) << "Malloc - TK_HDRKEY1[10]";
	TK_HDRKEY1.resize(10);
	qDebug(category) << "Malloc - TK_TYPCODE[2]";
	TK_TYPCODE.resize(2);

#pragma endregion Resize Fields TK_HDRREC
}
void TK_HDRREC::close()
{
	QLoggingCategory category("classLibQ");
	if (m_bIsOpen)
	{
	qDebug(category) << "database is Open";
		SQLHANDLE source_hStmt = hStmt_Fetch;
		SQLHANDLE insert_hStmt = hStmt_Insert;
		SQLHANDLE hDb_S = this->hDbc_source;
		SQLHANDLE hDb_T = hDbc_target;
		SQLHANDLE hEnvS = hEnv_Source;
		SQLHANDLE hEnvT = hEnv_Target;
		RETCODE r;

		r = ::SQLFreeHandle(SQL_HANDLE_STMT, hStmt_Fetch);
		r = ::SQLFreeHandle(SQL_HANDLE_STMT, hStmt_Insert);
		r = ::SQLFreeHandle(SQL_HANDLE_STMT, hStmt_Update);
		if (hDbc_source != SQL_NULL_HANDLE) 		r = ::SQLDisconnect(hDb_S);
		if (hDbc_target != SQL_NULL_HANDLE) 		r = ::SQLDisconnect(hDb_T);

		r = ::SQLFreeHandle(SQL_HANDLE_DBC, hDb_S);
		r = ::SQLFreeHandle(SQL_HANDLE_DBC, hDb_T);
		r = ::SQLFreeHandle(SQL_HANDLE_ENV, hEnvS);
		r = ::SQLFreeHandle(SQL_HANDLE_ENV, hEnvT);
	}

	hEnv_Source = SQL_NULL_HANDLE;
	hEnv_Target = SQL_NULL_HANDLE;
	hEnv_Source = SQL_NULL_HANDLE;
	hEnv_Target = SQL_NULL_HANDLE;
	hStmt_Fetch = SQL_NULL_HANDLE;
	hStmt_Insert = SQL_NULL_HANDLE;
	hStmt_Update = SQL_NULL_HANDLE;
}

void TK_HDRREC::open(const QString sourceDSN, const QString targetDSN)
{
	QLoggingCategory category("classLibQ");
	m_lpszTargetDSN = targetDSN;
	m_lpszSourceDSN = sourceDSN;
	qDebug(category) << QString("Source - %1[%2]").arg(sourceDSN);
	qDebug(category) << QString("Target - %1[%2]").arg(targetDSN);
}

void TK_HDRREC::createTable()
{
	QLoggingCategory category("classLibQ");
	{
		QScopedPointer<nvTableOracleRdb> tbl(new nvTableOracleRdb(nullptr));
		tbl->initialize("TK_HDRREC", this->m_lpszSourceDSN);
		QString newTbl = tbl->getCreateTableSQL();
		QScopedPointer<qVtExecute> vExec(new qVtExecute(nullptr));
		{
			vExec->initialize(m_lpszTargetDSN, " ", true);
			vExec->setOdbcAttributes(m_OdbcAttributes);
			vExec->ExecuteDirect(newTbl);
		}
	 qDebug(category) << QString("End Create Table %1 ").arg(tableName); 
	}
}

bool TK_HDRREC::prepare()
{
	RETCODE r;
	QString check;
	QLoggingCategory category("classLibQ");
	 qDebug(category) << fetchSql;
	 qDebug(category) << insertSql;
#ifdef UNICODE
	r = SQLPrepare(hStmt_Insert,toSQLTCHAR(insertSql).data(),(SQLINTEGER)insertSql.length()); 
	if (r != SQL_SUCCESS) {
		check = qWarnODBCHandle(SQL_HANDLE_STMT, hStmt_Insert);
		 qCCritical(category) << QString("Prepare Statement-Insert : %1 is %2").arg(insertSql).arg(check);
		return false; 
	}
	r = SQLPrepare(hStmt_Update,toSQLTCHAR(updateSql).data(),(SQLINTEGER)updateSql.length()); 
	if (r != SQL_SUCCESS) {
		check = qWarnODBCHandle(SQL_HANDLE_STMT, hStmt_Update);
		 qCCritical(category) << QString("Prepare Statement-Update : %1 is %2").arg(updateSql).arg(check);
		return false; 
	}
	r = SQLPrepare(hStmt_Fetch,toSQLTCHAR(fetchSql).data(),(SQLINTEGER)fetchSql.length());
	if (r != SQL_SUCCESS) {
		check = qWarnODBCHandle(SQL_HANDLE_STMT, hStmt_Fetch);
		 qCCritical(category) << QString("Prepare Statement-Insert : %1 is %2").arg(fetchSql).arg(check);
		return false; 
	}
#else
	QByteArray queryI8 = insertSql.toUtf8();
	r = SQLPrepare(insert_hStmt,SQLCHAR*)queryI8.data(),(SQLINTEGER)queryI8.length());
	QByteArray queryU8 = fetchSql.toUtf8();
	r = SQLPrepare(hStmt_Fetch,(SQLCHAR*)queryU8.data(),(SQLINTEGER)queryU8.length());
#endif
	return true;

}

void TK_HDRREC::prepareTargetTable()
{
	QLoggingCategory category("classLibQ");
	if (this->m_ReplicationOption == ReplicationOption::BulkCopy)
	{
		QScopedPointer<qVtExecute> execSql(new qVtExecute(nullptr));
		DropOption option = this->m_dropOption;
		switch (option)
		{
			case DropOption::DeleteFromTable:
			{
				QLoggingCategory category("classLibQ");
				execSql->initialize(this->m_lpszTargetDSN, "delete from TK_HDRREC", true);
				execSql->setOdbcAttributes(this->m_OdbcAttributes);
				execSql->ExecuteDirect("delete from TK_HDRREC");
			}break;
			case DropOption::TruncateTable:
			{
				execSql->initialize(this->m_lpszTargetDSN, "truncate table TK_HDRREC", true);
				execSql->setOdbcAttributes(this->m_OdbcAttributes);
				execSql->ExecuteDirect("truncate table TK_HDRREC");
			}break;
			case DropOption::DropTable:
			{
				execSql->initialize(this->m_lpszTargetDSN, "drop table TK_HDRREC", true);
				execSql->setOdbcAttributes(this->m_OdbcAttributes);
				execSql->ExecuteDirect("drop table TK_HDRREC");
				createTable();
			}break;
		}
	}
}

bool TK_HDRREC::bindColumn()
{
	QLoggingCategory category("classLibQ");
	RETCODE r;
	bool isValid=true;
		 qDebug(category) << " Bindings: Ordinal [1] Type: 5 Buffer Size: 2 FieldName: DB_ID ";
		r = ::SQLBindCol(hStmt_Fetch, 1, 5, DB_ID.data(), 2, &cbDB_ID);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Bindings: Ordinal [2] Type: 93 Buffer Size: 23 FieldName: NVTIMESTAMP ";
		r = ::SQLBindCol(hStmt_Fetch, 2, 93, NVTIMESTAMP.data(), 23, &cbNVTIMESTAMP);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Bindings: Ordinal [3] Type: 5 Buffer Size: 2 FieldName: AREA ";
		r = ::SQLBindCol(hStmt_Fetch, 3, 5, AREA.data(), 2, &cbAREA);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Bindings: Ordinal [4] Type: 4 Buffer Size: 4 FieldName: PAGE ";
		r = ::SQLBindCol(hStmt_Fetch, 4, 4, PAGE.data(), 4, &cbPAGE);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Bindings: Ordinal [5] Type: 5 Buffer Size: 2 FieldName: LINE ";
		r = ::SQLBindCol(hStmt_Fetch, 5, 5, LINE.data(), 2, &cbLINE);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Bindings: Ordinal [6] Type: 5 Buffer Size: 2 FieldName: TK_HDRCODE ";
		r = ::SQLBindCol(hStmt_Fetch, 6, 5, TK_HDRCODE.data(), 2, &cbTK_HDRCODE);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Bindings: Ordinal [7] Type: 1 Buffer Size: 24 FieldName: TK_HDRNO ";
		r = ::SQLBindCol(hStmt_Fetch, 7, 1, TK_HDRNO.data(), 24, &cbTK_HDRNO);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Bindings: Ordinal [8] Type: 1 Buffer Size: 10 FieldName: TK_HDRKEY1 ";
		r = ::SQLBindCol(hStmt_Fetch, 8, 1, TK_HDRKEY1.data(), 10, &cbTK_HDRKEY1);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Bindings: Ordinal [9] Type: 5 Buffer Size: 2 FieldName: TK_TYPCODE ";
		r = ::SQLBindCol(hStmt_Fetch, 9, 5, TK_TYPCODE.data(), 2, &cbTK_TYPCODE);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
	return isValid;
}

bool TK_HDRREC::bindParameter()
{
	QLoggingCategory category("classLibQ");
	RETCODE r;
	bool isValid=true;
	{
		 qDebug(category) << " Parameters: Ordinal [1] Type: 5 Buffer Size: 2 FieldName: DB_ID ";
		r = SQLBindParameter(hStmt_Insert, 1, SQL_PARAM_INPUT, SQL_C_DEFAULT, 5, 0, 0, (SQLPOINTER)DB_ID.constData(), 0, &cbDB_ID);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Parameters: Ordinal [2] Type: 93 Buffer Size: 23 FieldName: NVTIMESTAMP ";
		r = SQLBindParameter(hStmt_Insert, 2, SQL_PARAM_INPUT, SQL_C_DEFAULT, 93, 23, 0, (SQLPOINTER)NVTIMESTAMP.constData(), 0, &cbNVTIMESTAMP);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Parameters: Ordinal [3] Type: 5 Buffer Size: 2 FieldName: AREA ";
		r = SQLBindParameter(hStmt_Insert, 3, SQL_PARAM_INPUT, SQL_C_DEFAULT, 5, 0, 0, (SQLPOINTER)AREA.constData(), 0, &cbAREA);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Parameters: Ordinal [4] Type: 4 Buffer Size: 4 FieldName: PAGE ";
		r = SQLBindParameter(hStmt_Insert, 4, SQL_PARAM_INPUT, SQL_C_DEFAULT, 4, 0, 0, (SQLPOINTER)PAGE.constData(), 0, &cbPAGE);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Parameters: Ordinal [5] Type: 5 Buffer Size: 2 FieldName: LINE ";
		r = SQLBindParameter(hStmt_Insert, 5, SQL_PARAM_INPUT, SQL_C_DEFAULT, 5, 0, 0, (SQLPOINTER)LINE.constData(), 0, &cbLINE);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Parameters: Ordinal [6] Type: 5 Buffer Size: 2 FieldName: TK_HDRCODE ";
		r = SQLBindParameter(hStmt_Insert, 6, SQL_PARAM_INPUT, SQL_C_DEFAULT, 5, 0, 0, (SQLPOINTER)TK_HDRCODE.constData(), 0, &cbTK_HDRCODE);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Parameters: Ordinal [7] Type: 1 Buffer Size: 24 FieldName: TK_HDRNO ";
		r = SQLBindParameter(hStmt_Insert, 7, SQL_PARAM_INPUT, SQL_C_DEFAULT, 1, 24, 0, (SQLPOINTER)TK_HDRNO.constData(), 0, &cbTK_HDRNO);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Parameters: Ordinal [8] Type: 1 Buffer Size: 10 FieldName: TK_HDRKEY1 ";
		r = SQLBindParameter(hStmt_Insert, 8, SQL_PARAM_INPUT, SQL_C_DEFAULT, 1, 10, 0, (SQLPOINTER)TK_HDRKEY1.constData(), 0, &cbTK_HDRKEY1);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Parameters: Ordinal [9] Type: 5 Buffer Size: 2 FieldName: TK_TYPCODE ";
		r = SQLBindParameter(hStmt_Insert, 9, SQL_PARAM_INPUT, SQL_C_DEFAULT, 5, 0, 0, (SQLPOINTER)TK_TYPCODE.constData(), 0, &cbTK_TYPCODE);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
	}
	if (m_ReplicationOption == ReplicationOption::NetChange)
	{
		r = SQLBindParameter(hStmt_Update, 10, SQL_PARAM_INPUT, SQL_C_DEFAULT, 3, 0, 0, (SQLPOINTER)AREA.constData(), 0, &cbAREA);
		if (r == SQL_SUCCESS) { isValid=true; }
		r = SQLBindParameter(hStmt_Update, 11, SQL_PARAM_INPUT, SQL_C_DEFAULT, 4, 0, 0, (SQLPOINTER)PAGE.constData(), 0, &cbPAGE);
		if (r == SQL_SUCCESS) { isValid=true; }
		r = SQLBindParameter(hStmt_Update, 12, SQL_PARAM_INPUT, SQL_C_DEFAULT, 5, 0, 0, (SQLPOINTER)LINE.constData(), 0, &cbLINE);
		if (r == SQL_SUCCESS) { isValid=true; }
	// TK_HDRREC is a well formed table for eNVy Replication 
		 qDebug(category) << " Parameters: Ordinal [3] 00 00 FieldName: AREA ";
		 qDebug(category) << " Parameters: Ordinal [4] 00 00  FieldName: PAGE ";
		 qDebug(category) << " Parameters: Ordinal [5] 00 00 FieldName:  LINE ";
	} // 	if (m_ReplicationOption == ReplicationOption::NetChange)
	return isValid;
}

bool TK_HDRREC::process(int rowSize)
{
	QLoggingCategory category("classLibQ");
	initOdbcAttributes();
	connect(Source);
	connect(Target);
	initialize();
	prepareTargetTable();
	prepare();
	bindColumn();
	bindParameter();
	copyTable();
	close();
	return false;
}

void TK_HDRREC::copyTable()
{
	QLoggingCategory category("classLibQ");
	RETCODE r;
	QString check;
	r = SQLExecute(hStmt_Fetch);
		if (bIsAbort) {
			emit aborted(tableName, rowsFetched, rowsInserted, rowsUpdated);
			return;
		}
		while((r = SQLFetch(hStmt_Fetch)) != SQL_NO_DATA) {
		if (r != SQL_SUCCESS) {
			check = qWarnODBCHandle(SQL_HANDLE_STMT, hStmt_Fetch);
			qCCritical(category) << QString("SqlFetch - Error : %1 is %2").arg(fetchSql).arg(check);
			return;
		} 
		rowsFetched++;
		if (m_ReplicationOption == ReplicationOption::BulkCopy)
		{
			r = SQLExecute(hStmt_Insert);
			if (r == SQL_ERROR) {
				check = qWarnODBCHandle(SQL_HANDLE_STMT, hStmt_Insert);
				 qCCritical(category) << QString("SqlExecute:Insert - Error : %1 is %2").arg(insertSql).arg(check);
				return;
			}
			rowsInserted++;
			if ((rowsFetched % updateInterval) == 0) {
				qCInfo(category) << QString("[%1.%2]	Insertion: %3	Updates : %4	Fetched : %5").arg(profileName).arg(tableName).arg(rowsInserted).arg(rowsUpdated).arg(rowsFetched);
				emit updateStatusFetched(profileName, tableName, rowsFetched,rowsInserted,rowsUpdated);
			}
			if (m_ReplicationOption == ReplicationOption::NetChange)
			{
			r = SQLExecute(hStmt_Update);
			if (r != SQL_SUCCESS) {
				check = qWarnODBCHandle(SQL_HANDLE_STMT, hStmt_Update);
				 qCInfo(category)  << QString("SqlExecute:Update - Error : %1 is %2").arg(updateSql).arg(check);
				r = SQLExecute(hStmt_Insert);
				if (r != SQL_SUCCESS) {
					check = qWarnODBCHandle(SQL_HANDLE_STMT, hStmt_Insert);
					 qCritical(category) << QString("SqlExecute:Insert - Error : %1 is %2").arg(insertSql).arg(check);
					return;
				}
				else 	rowsInserted++;
				}
				else	rowsUpdated++;
			}
			emit updateStatusFetched(profileName, tableName, rowsFetched,rowsInserted,rowsUpdated);
		}
	} 
qCInfo(category) << QString("[%1.%2]	Insertion: %3	Updates : %4	Fetched : %5").arg(profileName).arg(tableName).arg(rowsInserted).arg(rowsUpdated).arg(rowsFetched);
}

void TK_HDRREC::connect(connectionHandle connectionSource)
{

	QLoggingCategory category("classLibQ");
	RETCODE r;

	bool isValid = false;
	HWND	hWnd = nullptr;
	hWnd = ::GetDesktopWindow(); 
	SQLSMALLINT nResult = 0;

	SQLSMALLINT cb;
	UWORD wConnectOption = SQL_DRIVER_COMPLETE; //SQL_DRIVER_NOPROMPT;
	QVarLengthArray<SQLTCHAR> connOut(1024);
	memset(connOut.data(), 0, connOut.size() * sizeof(SQLTCHAR));

	switch (connectionSource)
	{
		case Source:
			{// environment
				SQLHANDLE hEnv = SQL_NULL_HANDLE;
				SQLHANDLE hDbc = SQL_NULL_HANDLE;
				r = ::SQLAllocHandle(SQL_HANDLE_ENV, SQL_NULL_HANDLE, &hEnv);
				if (r == SQL_SUCCESS) isValid = true;

				foreach(nOdbcAttributesClass * k, this->m_OdbcAttributes_Map)
				{
					if (k->attributeType == enumAttributeType::hEnv)
					{
						r = ::SQLSetEnvAttr(hEnv, (SQLINTEGER) k->odbcKey, (SQLPOINTER)k->odbcValue, 0);
						if (r == SQL_SUCCESS) isValid = true;
					}
				}
				hEnv_Source = hEnv;

				r = SQLAllocHandle(SQL_HANDLE_DBC, hEnv, &hDbc);
				if (r == SQL_SUCCESS) isValid = true;
				foreach(nOdbcAttributesClass * k, this->m_OdbcAttributes_Map)
				{
					if (k->attributeType == enumAttributeType::hDbc)
					{
					r = ::SQLSetConnectAttr(hDbc, k->odbcKey, (SQLPOINTER)k->odbcValue, 0);
					if (k->odbcKey == SQL_ATTR_CONNECTION_POOLING && k->odbcValue == SQL_CP_ONE_PER_DRIVER) wConnectOption = SQL_DRIVER_NOPROMPT;
					if (k->odbcKey == SQL_ATTR_CONNECTION_POOLING && k->odbcValue == SQL_CP_ONE_PER_HENV) wConnectOption = SQL_DRIVER_NOPROMPT;
					if (k->odbcKey == SQL_ATTR_CONNECTION_POOLING && k->odbcValue == SQL_CP_DRIVER_AWARE) wConnectOption = SQL_DRIVER_NOPROMPT;
					if (r == SQL_SUCCESS) isValid = true;
					}
				}
				hDbc_source = hDbc;
				if (isValid)
				{
					r = ::SQLDriverConnect(
						hDbc,
						hWnd,
#ifdef UNICODE
						toSQLTCHAR(m_lpszSourceDSN).data(),
#else
						(SQLCHAR*)dsnSource.toUtf8().data(),
#endif
						(SQLSMALLINT)m_lpszSourceDSN.length(),
						connOut.data(),
						1024,
						&cb, 
						wConnectOption); 
					int colSize = cb / sizeof(SQLTCHAR);
					if (r != SQL_SUCCESS && r != SQL_SUCCESS_WITH_INFO)
					{
						QString check = qWarnODBCHandle(SQL_HANDLE_DBC, hDbc);
						qCritical(category) <<  check;
						m_bIsOpen = false;
					}
					m_bIsOpen = true;
				}
			} break;
		case Target:
			{
				SQLHANDLE hEnv = SQL_NULL_HANDLE;
				SQLHANDLE hDbc = SQL_NULL_HANDLE;
				r = ::SQLAllocHandle(SQL_HANDLE_ENV, SQL_NULL_HANDLE, &hEnv);
				if (r == SQL_SUCCESS) isValid = true;

				foreach(nOdbcAttributesClass * k, this->m_OdbcAttributes_Map)
				{
					if (k->attributeType == enumAttributeType::hEnv)
					{
						r = ::SQLSetEnvAttr(hEnv, (SQLINTEGER) k->odbcKey, (SQLPOINTER)k->odbcValue, 0);
						if (r == SQL_SUCCESS) isValid = true;
					}
				}
				hEnv_Target = hEnv;

				r = SQLAllocHandle(SQL_HANDLE_DBC, hEnv, &hDbc);
				if (r == SQL_SUCCESS) isValid = true;
				foreach(nOdbcAttributesClass * k, this->m_OdbcAttributes_Map)
				{
				if (k->attributeType == enumAttributeType::hDbc)
					{
					r = ::SQLSetConnectAttr(hDbc, k->odbcKey, (SQLPOINTER)k->odbcValue, 0);
					if (k->odbcKey == SQL_ATTR_CONNECTION_POOLING && k->odbcValue == SQL_CP_ONE_PER_DRIVER) wConnectOption = SQL_DRIVER_NOPROMPT;
					if (k->odbcKey == SQL_ATTR_CONNECTION_POOLING && k->odbcValue == SQL_CP_ONE_PER_HENV) wConnectOption = SQL_DRIVER_NOPROMPT;
					if (k->odbcKey == SQL_ATTR_CONNECTION_POOLING && k->odbcValue == SQL_CP_DRIVER_AWARE) wConnectOption = SQL_DRIVER_NOPROMPT;
					if (r == SQL_SUCCESS) isValid = true;
					}
				}
				hDbc_target = hDbc;
				if (isValid) {
					r = ::SQLDriverConnect(
						hDbc,
						hWnd,
#ifdef UNICODE
						toSQLTCHAR(m_lpszTargetDSN).data(),
#else
						(SQLCHAR*)m_lpszTargetDSN.toUtf8().data(),
#endif
						(SQLSMALLINT)m_lpszTargetDSN.length(),
						connOut.data(),
						1024,
						&cb, 
						wConnectOption); 
						int colSize = cb / sizeof(SQLTCHAR);
					if (r != SQL_SUCCESS && r != SQL_SUCCESS_WITH_INFO)
						{
							QString check = qWarnODBCHandle(SQL_HANDLE_DBC, hDbc);
							qCritical(category) <<  check;
							m_bIsOpen = false;
						}
							m_bIsOpen = true;
					}
			} break;
			default: break;
	}
}
TK_CNVREC::TK_CNVREC(QObject * parent) : QObject(parent) 
,tableName("TK_CNVREC")
,m_dropOption(DropOption::DropTable) { 
	numRowsFetched = 0;
}

#pragma region ~CTOR TK_CNVREC 
TK_CNVREC::~TK_CNVREC() { 

#pragma region Buffers - Clear 
	DB_ID.clear();
	NVTIMESTAMP.clear();
	AREA.clear();
	PAGE.clear();
	LINE.clear();
	TK_CNVPRT.clear();
	TK_CNVFUOM.clear();
	TK_CNVTUOM.clear();
	TK_CNVFCTR.clear();
	TK_CNVRCP.clear();
	TK_CNVTYP.clear();
#pragma endregion Buffers - Clear 
}
#pragma endregion Destructor_TK_CNVREC

// begin method functions
void TK_CNVREC::setAbortFlag() { 
	QLoggingCategory category("classLibQ");
	qCInfo(category) << "isAbort was set to True";
	bIsAbort = true;
}

void TK_CNVREC::run() { 
	process(1);
	QLoggingCategory category("classLibQ");
	qDebug(category) << "Entered;";
}

void	TK_CNVREC::initOdbcAttributes()
{
	QLoggingCategory category("classLibQ");
	this->setProfileName(profileName);
	qDebug(category) << "Processing - TRKDB100"; 
	m_OdbcAttributesList = m_OdbcAttributes.split(","); 
	foreach(QString m, m_OdbcAttributesList)
	{
		QStringList keyValue = m.split("=");
		nOdbcAttributesClass * oM = new nOdbcAttributesClass(this);
		if (oM->loadToOdbc(keyValue.value(0), keyValue.value(1)))
		{
			m_OdbcAttributes_Map.insert(oM->odbcKey, oM);
		}
	}
}
void	TK_CNVREC::initialize()
{
	QLoggingCategory category("classLibQ");
	RETCODE r;
	this->setProfileName(profileName);
	qDebug(category) << "Processing - TRKDB100"; 
//SQL Statements
//--------------------------------------------------

#pragma region Sql Statements_TK_CNVREC

	fetchSql = "select  DB_ID, NVTIMESTAMP, AREA, PAGE, LINE, TK_CNVPRT, TK_CNVFUOM, TK_CNVTUOM, TK_CNVFCTR, TK_CNVRCP, TK_CNVTYP from TK_CNVREC";
		if (m_ReplicationOption == ReplicationOption::NetChange)
		{
			fetchSql.append(" p1, nv_transfers p2 WHERE  p2.table_name = 'TK_CNVREC' AND p1.nvtimestamp > p2.last_completed");
		}
	insertSql = "insert into TK_CNVREC ( PLANT_CODE, NVTIMESTAMP, AREA, PAGE, LINE, TK_CNVPRT, TK_CNVFUOM, TK_CNVTUOM, TK_CNVFCTR, TK_CNVRCP, TK_CNVTYP ) values ( ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?)";
	updateSql = "update TK_CNVREC set  PLANT_CODE = ?, NVTIMESTAMP = ?, AREA = ?, PAGE = ?, LINE = ?, TK_CNVPRT = ?, TK_CNVFUOM = ?, TK_CNVTUOM = ?, TK_CNVFCTR = ?, TK_CNVRCP = ?, TK_CNVTYP = ?  where area = ? and page = ? line = ? ";

	qDebug(category) << "insertSQL - insert into TK_CNVREC ( PLANT_CODE, NVTIMESTAMP, AREA, PAGE, LINE, TK_CNVPRT, TK_CNVFUOM, TK_CNVTUOM, TK_CNVFCTR, TK_CNVRCP, TK_CNVTYP ) values ( ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?)";
	qDebug(category) << "fetchSQL - select  DB_ID, NVTIMESTAMP, AREA, PAGE, LINE, TK_CNVPRT, TK_CNVFUOM, TK_CNVTUOM, TK_CNVFCTR, TK_CNVRCP, TK_CNVTYP from TK_CNVREC";
	qDebug(category) << "unsertSQL - update TK_CNVREC set  PLANT_CODE = ?, NVTIMESTAMP = ?, AREA = ?, PAGE = ?, LINE = ?, TK_CNVPRT = ?, TK_CNVFUOM = ?, TK_CNVTUOM = ?, TK_CNVFCTR = ?, TK_CNVRCP = ?, TK_CNVTYP = ?  where area = ? and page = ? line = ? ";

#pragma endregion Sql Statements_TK_CNVREC
	SQLHANDLE		insert_hStmt = SQL_NULL_HANDLE;
	SQLHANDLE		fetch_hStmt = SQL_NULL_HANDLE; 
	SQLHANDLE		update_hStmt = SQL_NULL_HANDLE; 
 
	r = ::SQLAllocHandle(SQL_HANDLE_STMT, hDbc_source, &fetch_hStmt);
	if (r != SQL_SUCCESS) {
		 qCCritical(category) << QString("Error  hDbc_Source SQLCode : %1 is %2").arg(QString::number( (long)hDbc_source)).arg(QString::number(r));
		return; 
	}
	r = ::SQLAllocHandle(SQL_HANDLE_STMT, hDbc_target, &insert_hStmt);
	if (r != SQL_SUCCESS) {
		 qCCritical(category) << QString("Error hDbc_Source -SQLCode: %1 is %2").arg(QString::number( (long)hDbc_target)).arg(QString::number(r));
		return; 
	}
	r = ::SQLAllocHandle(SQL_HANDLE_STMT, hDbc_target, &update_hStmt);
	if (r != SQL_SUCCESS) {
		 qCCritical(category) << QString("Error hDbc_Source +SQLCode: %1 is %2").arg(QString::number( (long)hDbc_target)).arg(QString::number(r));
		return; 
	}
 
	hStmt_Fetch = fetch_hStmt;
	hStmt_Insert = insert_hStmt;
	hStmt_Update = update_hStmt;
 
	SQLSetStmtAttr(hStmt_Fetch, SQL_ATTR_USE_BOOKMARKS, (SQLPOINTER)SQL_UB_OFF, 0);
	SQLSetStmtAttr(hStmt_Fetch, SQL_ATTR_ROW_BIND_TYPE, (SQLPOINTER)SQL_BIND_BY_COLUMN, 0);
	SQLSetStmtAttr(hStmt_Fetch, SQL_ATTR_ROW_ARRAY_SIZE, (SQLPOINTER)1, 0);
	SQLSetStmtAttr(hStmt_Fetch, SQL_ATTR_ROWS_FETCHED_PTR, &numRowsFetched, 0);

// Fields used by this class 
// ---------------------------------------------------

#pragma region Resize Fields TK_CNVREC
	qDebug(category) << "Malloc - DB_ID[2]";
	DB_ID.resize(2);
	qDebug(category) << "Malloc - NVTIMESTAMP[23]";
	NVTIMESTAMP.resize(23);
	qDebug(category) << "Malloc - AREA[2]";
	AREA.resize(2);
	qDebug(category) << "Malloc - PAGE[4]";
	PAGE.resize(4);
	qDebug(category) << "Malloc - LINE[2]";
	LINE.resize(2);
	qDebug(category) << "Malloc - TK_CNVPRT[18]";
	TK_CNVPRT.resize(18);
	qDebug(category) << "Malloc - TK_CNVFUOM[2]";
	TK_CNVFUOM.resize(2);
	qDebug(category) << "Malloc - TK_CNVTUOM[2]";
	TK_CNVTUOM.resize(2);
	qDebug(category) << "Malloc - TK_CNVFCTR[8]";
	TK_CNVFCTR.resize(8);
	qDebug(category) << "Malloc - TK_CNVRCP[8]";
	TK_CNVRCP.resize(8);
	qDebug(category) << "Malloc - TK_CNVTYP[2]";
	TK_CNVTYP.resize(2);

#pragma endregion Resize Fields TK_CNVREC
}
void TK_CNVREC::close()
{
	QLoggingCategory category("classLibQ");
	if (m_bIsOpen)
	{
	qDebug(category) << "database is Open";
		SQLHANDLE source_hStmt = hStmt_Fetch;
		SQLHANDLE insert_hStmt = hStmt_Insert;
		SQLHANDLE hDb_S = this->hDbc_source;
		SQLHANDLE hDb_T = hDbc_target;
		SQLHANDLE hEnvS = hEnv_Source;
		SQLHANDLE hEnvT = hEnv_Target;
		RETCODE r;

		r = ::SQLFreeHandle(SQL_HANDLE_STMT, hStmt_Fetch);
		r = ::SQLFreeHandle(SQL_HANDLE_STMT, hStmt_Insert);
		r = ::SQLFreeHandle(SQL_HANDLE_STMT, hStmt_Update);
		if (hDbc_source != SQL_NULL_HANDLE) 		r = ::SQLDisconnect(hDb_S);
		if (hDbc_target != SQL_NULL_HANDLE) 		r = ::SQLDisconnect(hDb_T);

		r = ::SQLFreeHandle(SQL_HANDLE_DBC, hDb_S);
		r = ::SQLFreeHandle(SQL_HANDLE_DBC, hDb_T);
		r = ::SQLFreeHandle(SQL_HANDLE_ENV, hEnvS);
		r = ::SQLFreeHandle(SQL_HANDLE_ENV, hEnvT);
	}

	hEnv_Source = SQL_NULL_HANDLE;
	hEnv_Target = SQL_NULL_HANDLE;
	hEnv_Source = SQL_NULL_HANDLE;
	hEnv_Target = SQL_NULL_HANDLE;
	hStmt_Fetch = SQL_NULL_HANDLE;
	hStmt_Insert = SQL_NULL_HANDLE;
	hStmt_Update = SQL_NULL_HANDLE;
}

void TK_CNVREC::open(const QString sourceDSN, const QString targetDSN)
{
	QLoggingCategory category("classLibQ");
	m_lpszTargetDSN = targetDSN;
	m_lpszSourceDSN = sourceDSN;
	qDebug(category) << QString("Source - %1[%2]").arg(sourceDSN);
	qDebug(category) << QString("Target - %1[%2]").arg(targetDSN);
}

void TK_CNVREC::createTable()
{
	QLoggingCategory category("classLibQ");
	{
		QScopedPointer<nvTableOracleRdb> tbl(new nvTableOracleRdb(nullptr));
		tbl->initialize("TK_CNVREC", this->m_lpszSourceDSN);
		QString newTbl = tbl->getCreateTableSQL();
		QScopedPointer<qVtExecute> vExec(new qVtExecute(nullptr));
		{
			vExec->initialize(m_lpszTargetDSN, " ", true);
			vExec->setOdbcAttributes(m_OdbcAttributes);
			vExec->ExecuteDirect(newTbl);
		}
	 qDebug(category) << QString("End Create Table %1 ").arg(tableName); 
	}
}

bool TK_CNVREC::prepare()
{
	RETCODE r;
	QString check;
	QLoggingCategory category("classLibQ");
	 qDebug(category) << fetchSql;
	 qDebug(category) << insertSql;
#ifdef UNICODE
	r = SQLPrepare(hStmt_Insert,toSQLTCHAR(insertSql).data(),(SQLINTEGER)insertSql.length()); 
	if (r != SQL_SUCCESS) {
		check = qWarnODBCHandle(SQL_HANDLE_STMT, hStmt_Insert);
		 qCCritical(category) << QString("Prepare Statement-Insert : %1 is %2").arg(insertSql).arg(check);
		return false; 
	}
	r = SQLPrepare(hStmt_Update,toSQLTCHAR(updateSql).data(),(SQLINTEGER)updateSql.length()); 
	if (r != SQL_SUCCESS) {
		check = qWarnODBCHandle(SQL_HANDLE_STMT, hStmt_Update);
		 qCCritical(category) << QString("Prepare Statement-Update : %1 is %2").arg(updateSql).arg(check);
		return false; 
	}
	r = SQLPrepare(hStmt_Fetch,toSQLTCHAR(fetchSql).data(),(SQLINTEGER)fetchSql.length());
	if (r != SQL_SUCCESS) {
		check = qWarnODBCHandle(SQL_HANDLE_STMT, hStmt_Fetch);
		 qCCritical(category) << QString("Prepare Statement-Insert : %1 is %2").arg(fetchSql).arg(check);
		return false; 
	}
#else
	QByteArray queryI8 = insertSql.toUtf8();
	r = SQLPrepare(insert_hStmt,SQLCHAR*)queryI8.data(),(SQLINTEGER)queryI8.length());
	QByteArray queryU8 = fetchSql.toUtf8();
	r = SQLPrepare(hStmt_Fetch,(SQLCHAR*)queryU8.data(),(SQLINTEGER)queryU8.length());
#endif
	return true;

}

void TK_CNVREC::prepareTargetTable()
{
	QLoggingCategory category("classLibQ");
	if (this->m_ReplicationOption == ReplicationOption::BulkCopy)
	{
		QScopedPointer<qVtExecute> execSql(new qVtExecute(nullptr));
		DropOption option = this->m_dropOption;
		switch (option)
		{
			case DropOption::DeleteFromTable:
			{
				QLoggingCategory category("classLibQ");
				execSql->initialize(this->m_lpszTargetDSN, "delete from TK_CNVREC", true);
				execSql->setOdbcAttributes(this->m_OdbcAttributes);
				execSql->ExecuteDirect("delete from TK_CNVREC");
			}break;
			case DropOption::TruncateTable:
			{
				execSql->initialize(this->m_lpszTargetDSN, "truncate table TK_CNVREC", true);
				execSql->setOdbcAttributes(this->m_OdbcAttributes);
				execSql->ExecuteDirect("truncate table TK_CNVREC");
			}break;
			case DropOption::DropTable:
			{
				execSql->initialize(this->m_lpszTargetDSN, "drop table TK_CNVREC", true);
				execSql->setOdbcAttributes(this->m_OdbcAttributes);
				execSql->ExecuteDirect("drop table TK_CNVREC");
				createTable();
			}break;
		}
	}
}

bool TK_CNVREC::bindColumn()
{
	QLoggingCategory category("classLibQ");
	RETCODE r;
	bool isValid=true;
		 qDebug(category) << " Bindings: Ordinal [1] Type: 5 Buffer Size: 2 FieldName: DB_ID ";
		r = ::SQLBindCol(hStmt_Fetch, 1, 5, DB_ID.data(), 2, &cbDB_ID);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Bindings: Ordinal [2] Type: 93 Buffer Size: 23 FieldName: NVTIMESTAMP ";
		r = ::SQLBindCol(hStmt_Fetch, 2, 93, NVTIMESTAMP.data(), 23, &cbNVTIMESTAMP);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Bindings: Ordinal [3] Type: 5 Buffer Size: 2 FieldName: AREA ";
		r = ::SQLBindCol(hStmt_Fetch, 3, 5, AREA.data(), 2, &cbAREA);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Bindings: Ordinal [4] Type: 4 Buffer Size: 4 FieldName: PAGE ";
		r = ::SQLBindCol(hStmt_Fetch, 4, 4, PAGE.data(), 4, &cbPAGE);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Bindings: Ordinal [5] Type: 5 Buffer Size: 2 FieldName: LINE ";
		r = ::SQLBindCol(hStmt_Fetch, 5, 5, LINE.data(), 2, &cbLINE);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Bindings: Ordinal [6] Type: 1 Buffer Size: 18 FieldName: TK_CNVPRT ";
		r = ::SQLBindCol(hStmt_Fetch, 6, 1, TK_CNVPRT.data(), 18, &cbTK_CNVPRT);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Bindings: Ordinal [7] Type: 1 Buffer Size: 2 FieldName: TK_CNVFUOM ";
		r = ::SQLBindCol(hStmt_Fetch, 7, 1, TK_CNVFUOM.data(), 2, &cbTK_CNVFUOM);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Bindings: Ordinal [8] Type: 1 Buffer Size: 2 FieldName: TK_CNVTUOM ";
		r = ::SQLBindCol(hStmt_Fetch, 8, 1, TK_CNVTUOM.data(), 2, &cbTK_CNVTUOM);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Bindings: Ordinal [9] Type: 8 Buffer Size: 8 FieldName: TK_CNVFCTR ";
		r = ::SQLBindCol(hStmt_Fetch, 9, 8, TK_CNVFCTR.data(), 8, &cbTK_CNVFCTR);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Bindings: Ordinal [10] Type: 8 Buffer Size: 8 FieldName: TK_CNVRCP ";
		r = ::SQLBindCol(hStmt_Fetch, 10, 8, TK_CNVRCP.data(), 8, &cbTK_CNVRCP);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Bindings: Ordinal [11] Type: 5 Buffer Size: 2 FieldName: TK_CNVTYP ";
		r = ::SQLBindCol(hStmt_Fetch, 11, 5, TK_CNVTYP.data(), 2, &cbTK_CNVTYP);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
	return isValid;
}

bool TK_CNVREC::bindParameter()
{
	QLoggingCategory category("classLibQ");
	RETCODE r;
	bool isValid=true;
	{
		 qDebug(category) << " Parameters: Ordinal [1] Type: 5 Buffer Size: 2 FieldName: DB_ID ";
		r = SQLBindParameter(hStmt_Insert, 1, SQL_PARAM_INPUT, SQL_C_DEFAULT, 5, 0, 0, (SQLPOINTER)DB_ID.constData(), 0, &cbDB_ID);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Parameters: Ordinal [2] Type: 93 Buffer Size: 23 FieldName: NVTIMESTAMP ";
		r = SQLBindParameter(hStmt_Insert, 2, SQL_PARAM_INPUT, SQL_C_DEFAULT, 93, 23, 0, (SQLPOINTER)NVTIMESTAMP.constData(), 0, &cbNVTIMESTAMP);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Parameters: Ordinal [3] Type: 5 Buffer Size: 2 FieldName: AREA ";
		r = SQLBindParameter(hStmt_Insert, 3, SQL_PARAM_INPUT, SQL_C_DEFAULT, 5, 0, 0, (SQLPOINTER)AREA.constData(), 0, &cbAREA);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Parameters: Ordinal [4] Type: 4 Buffer Size: 4 FieldName: PAGE ";
		r = SQLBindParameter(hStmt_Insert, 4, SQL_PARAM_INPUT, SQL_C_DEFAULT, 4, 0, 0, (SQLPOINTER)PAGE.constData(), 0, &cbPAGE);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Parameters: Ordinal [5] Type: 5 Buffer Size: 2 FieldName: LINE ";
		r = SQLBindParameter(hStmt_Insert, 5, SQL_PARAM_INPUT, SQL_C_DEFAULT, 5, 0, 0, (SQLPOINTER)LINE.constData(), 0, &cbLINE);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Parameters: Ordinal [6] Type: 1 Buffer Size: 18 FieldName: TK_CNVPRT ";
		r = SQLBindParameter(hStmt_Insert, 6, SQL_PARAM_INPUT, SQL_C_DEFAULT, 1, 18, 0, (SQLPOINTER)TK_CNVPRT.constData(), 0, &cbTK_CNVPRT);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Parameters: Ordinal [7] Type: 1 Buffer Size: 2 FieldName: TK_CNVFUOM ";
		r = SQLBindParameter(hStmt_Insert, 7, SQL_PARAM_INPUT, SQL_C_DEFAULT, 1, 2, 0, (SQLPOINTER)TK_CNVFUOM.constData(), 0, &cbTK_CNVFUOM);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Parameters: Ordinal [8] Type: 1 Buffer Size: 2 FieldName: TK_CNVTUOM ";
		r = SQLBindParameter(hStmt_Insert, 8, SQL_PARAM_INPUT, SQL_C_DEFAULT, 1, 2, 0, (SQLPOINTER)TK_CNVTUOM.constData(), 0, &cbTK_CNVTUOM);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Parameters: Ordinal [9] Type: 8 Buffer Size: 8 FieldName: TK_CNVFCTR ";
		r = SQLBindParameter(hStmt_Insert, 9, SQL_PARAM_INPUT, SQL_C_DEFAULT, 8, 0, 0, (SQLPOINTER)TK_CNVFCTR.constData(), 0, &cbTK_CNVFCTR);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Parameters: Ordinal [10] Type: 8 Buffer Size: 8 FieldName: TK_CNVRCP ";
		r = SQLBindParameter(hStmt_Insert, 10, SQL_PARAM_INPUT, SQL_C_DEFAULT, 8, 0, 0, (SQLPOINTER)TK_CNVRCP.constData(), 0, &cbTK_CNVRCP);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Parameters: Ordinal [11] Type: 5 Buffer Size: 2 FieldName: TK_CNVTYP ";
		r = SQLBindParameter(hStmt_Insert, 11, SQL_PARAM_INPUT, SQL_C_DEFAULT, 5, 0, 0, (SQLPOINTER)TK_CNVTYP.constData(), 0, &cbTK_CNVTYP);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
	}
	if (m_ReplicationOption == ReplicationOption::NetChange)
	{
		r = SQLBindParameter(hStmt_Update, 12, SQL_PARAM_INPUT, SQL_C_DEFAULT, 3, 0, 0, (SQLPOINTER)AREA.constData(), 0, &cbAREA);
		if (r == SQL_SUCCESS) { isValid=true; }
		r = SQLBindParameter(hStmt_Update, 13, SQL_PARAM_INPUT, SQL_C_DEFAULT, 4, 0, 0, (SQLPOINTER)PAGE.constData(), 0, &cbPAGE);
		if (r == SQL_SUCCESS) { isValid=true; }
		r = SQLBindParameter(hStmt_Update, 14, SQL_PARAM_INPUT, SQL_C_DEFAULT, 5, 0, 0, (SQLPOINTER)LINE.constData(), 0, &cbLINE);
		if (r == SQL_SUCCESS) { isValid=true; }
	// TK_CNVREC is a well formed table for eNVy Replication 
		 qDebug(category) << " Parameters: Ordinal [3] 00 00 FieldName: AREA ";
		 qDebug(category) << " Parameters: Ordinal [4] 00 00  FieldName: PAGE ";
		 qDebug(category) << " Parameters: Ordinal [5] 00 00 FieldName:  LINE ";
	} // 	if (m_ReplicationOption == ReplicationOption::NetChange)
	return isValid;
}

bool TK_CNVREC::process(int rowSize)
{
	QLoggingCategory category("classLibQ");
	initOdbcAttributes();
	connect(Source);
	connect(Target);
	initialize();
	prepareTargetTable();
	prepare();
	bindColumn();
	bindParameter();
	copyTable();
	close();
	return false;
}

void TK_CNVREC::copyTable()
{
	QLoggingCategory category("classLibQ");
	RETCODE r;
	QString check;
	r = SQLExecute(hStmt_Fetch);
		if (bIsAbort) {
			emit aborted(tableName, rowsFetched, rowsInserted, rowsUpdated);
			return;
		}
		while((r = SQLFetch(hStmt_Fetch)) != SQL_NO_DATA) {
		if (r != SQL_SUCCESS) {
			check = qWarnODBCHandle(SQL_HANDLE_STMT, hStmt_Fetch);
			qCCritical(category) << QString("SqlFetch - Error : %1 is %2").arg(fetchSql).arg(check);
			return;
		} 
		rowsFetched++;
		if (m_ReplicationOption == ReplicationOption::BulkCopy)
		{
			r = SQLExecute(hStmt_Insert);
			if (r == SQL_ERROR) {
				check = qWarnODBCHandle(SQL_HANDLE_STMT, hStmt_Insert);
				 qCCritical(category) << QString("SqlExecute:Insert - Error : %1 is %2").arg(insertSql).arg(check);
				return;
			}
			rowsInserted++;
			if ((rowsFetched % updateInterval) == 0) {
				qCInfo(category) << QString("[%1.%2]	Insertion: %3	Updates : %4	Fetched : %5").arg(profileName).arg(tableName).arg(rowsInserted).arg(rowsUpdated).arg(rowsFetched);
				emit updateStatusFetched(profileName, tableName, rowsFetched,rowsInserted,rowsUpdated);
			}
			if (m_ReplicationOption == ReplicationOption::NetChange)
			{
			r = SQLExecute(hStmt_Update);
			if (r != SQL_SUCCESS) {
				check = qWarnODBCHandle(SQL_HANDLE_STMT, hStmt_Update);
				 qCInfo(category)  << QString("SqlExecute:Update - Error : %1 is %2").arg(updateSql).arg(check);
				r = SQLExecute(hStmt_Insert);
				if (r != SQL_SUCCESS) {
					check = qWarnODBCHandle(SQL_HANDLE_STMT, hStmt_Insert);
					 qCritical(category) << QString("SqlExecute:Insert - Error : %1 is %2").arg(insertSql).arg(check);
					return;
				}
				else 	rowsInserted++;
				}
				else	rowsUpdated++;
			}
			emit updateStatusFetched(profileName, tableName, rowsFetched,rowsInserted,rowsUpdated);
		}
	} 
qCInfo(category) << QString("[%1.%2]	Insertion: %3	Updates : %4	Fetched : %5").arg(profileName).arg(tableName).arg(rowsInserted).arg(rowsUpdated).arg(rowsFetched);
}

void TK_CNVREC::connect(connectionHandle connectionSource)
{

	QLoggingCategory category("classLibQ");
	RETCODE r;

	bool isValid = false;
	HWND	hWnd = nullptr;
	hWnd = ::GetDesktopWindow(); 
	SQLSMALLINT nResult = 0;

	SQLSMALLINT cb;
	UWORD wConnectOption = SQL_DRIVER_COMPLETE; //SQL_DRIVER_NOPROMPT;
	QVarLengthArray<SQLTCHAR> connOut(1024);
	memset(connOut.data(), 0, connOut.size() * sizeof(SQLTCHAR));

	switch (connectionSource)
	{
		case Source:
			{// environment
				SQLHANDLE hEnv = SQL_NULL_HANDLE;
				SQLHANDLE hDbc = SQL_NULL_HANDLE;
				r = ::SQLAllocHandle(SQL_HANDLE_ENV, SQL_NULL_HANDLE, &hEnv);
				if (r == SQL_SUCCESS) isValid = true;

				foreach(nOdbcAttributesClass * k, this->m_OdbcAttributes_Map)
				{
					if (k->attributeType == enumAttributeType::hEnv)
					{
						r = ::SQLSetEnvAttr(hEnv, (SQLINTEGER) k->odbcKey, (SQLPOINTER)k->odbcValue, 0);
						if (r == SQL_SUCCESS) isValid = true;
					}
				}
				hEnv_Source = hEnv;

				r = SQLAllocHandle(SQL_HANDLE_DBC, hEnv, &hDbc);
				if (r == SQL_SUCCESS) isValid = true;
				foreach(nOdbcAttributesClass * k, this->m_OdbcAttributes_Map)
				{
					if (k->attributeType == enumAttributeType::hDbc)
					{
					r = ::SQLSetConnectAttr(hDbc, k->odbcKey, (SQLPOINTER)k->odbcValue, 0);
					if (k->odbcKey == SQL_ATTR_CONNECTION_POOLING && k->odbcValue == SQL_CP_ONE_PER_DRIVER) wConnectOption = SQL_DRIVER_NOPROMPT;
					if (k->odbcKey == SQL_ATTR_CONNECTION_POOLING && k->odbcValue == SQL_CP_ONE_PER_HENV) wConnectOption = SQL_DRIVER_NOPROMPT;
					if (k->odbcKey == SQL_ATTR_CONNECTION_POOLING && k->odbcValue == SQL_CP_DRIVER_AWARE) wConnectOption = SQL_DRIVER_NOPROMPT;
					if (r == SQL_SUCCESS) isValid = true;
					}
				}
				hDbc_source = hDbc;
				if (isValid)
				{
					r = ::SQLDriverConnect(
						hDbc,
						hWnd,
#ifdef UNICODE
						toSQLTCHAR(m_lpszSourceDSN).data(),
#else
						(SQLCHAR*)dsnSource.toUtf8().data(),
#endif
						(SQLSMALLINT)m_lpszSourceDSN.length(),
						connOut.data(),
						1024,
						&cb, 
						wConnectOption); 
					int colSize = cb / sizeof(SQLTCHAR);
					if (r != SQL_SUCCESS && r != SQL_SUCCESS_WITH_INFO)
					{
						QString check = qWarnODBCHandle(SQL_HANDLE_DBC, hDbc);
						qCritical(category) <<  check;
						m_bIsOpen = false;
					}
					m_bIsOpen = true;
				}
			} break;
		case Target:
			{
				SQLHANDLE hEnv = SQL_NULL_HANDLE;
				SQLHANDLE hDbc = SQL_NULL_HANDLE;
				r = ::SQLAllocHandle(SQL_HANDLE_ENV, SQL_NULL_HANDLE, &hEnv);
				if (r == SQL_SUCCESS) isValid = true;

				foreach(nOdbcAttributesClass * k, this->m_OdbcAttributes_Map)
				{
					if (k->attributeType == enumAttributeType::hEnv)
					{
						r = ::SQLSetEnvAttr(hEnv, (SQLINTEGER) k->odbcKey, (SQLPOINTER)k->odbcValue, 0);
						if (r == SQL_SUCCESS) isValid = true;
					}
				}
				hEnv_Target = hEnv;

				r = SQLAllocHandle(SQL_HANDLE_DBC, hEnv, &hDbc);
				if (r == SQL_SUCCESS) isValid = true;
				foreach(nOdbcAttributesClass * k, this->m_OdbcAttributes_Map)
				{
				if (k->attributeType == enumAttributeType::hDbc)
					{
					r = ::SQLSetConnectAttr(hDbc, k->odbcKey, (SQLPOINTER)k->odbcValue, 0);
					if (k->odbcKey == SQL_ATTR_CONNECTION_POOLING && k->odbcValue == SQL_CP_ONE_PER_DRIVER) wConnectOption = SQL_DRIVER_NOPROMPT;
					if (k->odbcKey == SQL_ATTR_CONNECTION_POOLING && k->odbcValue == SQL_CP_ONE_PER_HENV) wConnectOption = SQL_DRIVER_NOPROMPT;
					if (k->odbcKey == SQL_ATTR_CONNECTION_POOLING && k->odbcValue == SQL_CP_DRIVER_AWARE) wConnectOption = SQL_DRIVER_NOPROMPT;
					if (r == SQL_SUCCESS) isValid = true;
					}
				}
				hDbc_target = hDbc;
				if (isValid) {
					r = ::SQLDriverConnect(
						hDbc,
						hWnd,
#ifdef UNICODE
						toSQLTCHAR(m_lpszTargetDSN).data(),
#else
						(SQLCHAR*)m_lpszTargetDSN.toUtf8().data(),
#endif
						(SQLSMALLINT)m_lpszTargetDSN.length(),
						connOut.data(),
						1024,
						&cb, 
						wConnectOption); 
						int colSize = cb / sizeof(SQLTCHAR);
					if (r != SQL_SUCCESS && r != SQL_SUCCESS_WITH_INFO)
						{
							QString check = qWarnODBCHandle(SQL_HANDLE_DBC, hDbc);
							qCritical(category) <<  check;
							m_bIsOpen = false;
						}
							m_bIsOpen = true;
					}
			} break;
			default: break;
	}
}
TK_UHSTREC::TK_UHSTREC(QObject * parent) : QObject(parent) 
,tableName("TK_UHSTREC")
,m_dropOption(DropOption::DropTable) { 
	numRowsFetched = 0;
}

#pragma region ~CTOR TK_UHSTREC 
TK_UHSTREC::~TK_UHSTREC() { 

#pragma region Buffers - Clear 
	DB_ID.clear();
	NVTIMESTAMP.clear();
	AREA.clear();
	PAGE.clear();
	LINE.clear();
	TK_UHSTDATE.clear();
	TK_UHSTTIME.clear();
	TK_UHSTUSER.clear();
	TK_UHSTCMD.clear();
	TK_UHSTOLDPRT.clear();
	TK_UHSTNEWPRT.clear();
	TK_UHSTOLDFUOM.clear();
	TK_UHSTNEWFUOM.clear();
	TK_UHSTOLDTUOM.clear();
	TK_UHSTNEWTUOM.clear();
	TK_UHSTOLDFCTR.clear();
	TK_UHSTNEWFCTR.clear();
#pragma endregion Buffers - Clear 
}
#pragma endregion Destructor_TK_UHSTREC

// begin method functions
void TK_UHSTREC::setAbortFlag() { 
	QLoggingCategory category("classLibQ");
	qCInfo(category) << "isAbort was set to True";
	bIsAbort = true;
}

void TK_UHSTREC::run() { 
	process(1);
	QLoggingCategory category("classLibQ");
	qDebug(category) << "Entered;";
}

void	TK_UHSTREC::initOdbcAttributes()
{
	QLoggingCategory category("classLibQ");
	this->setProfileName(profileName);
	qDebug(category) << "Processing - TRKDB100"; 
	m_OdbcAttributesList = m_OdbcAttributes.split(","); 
	foreach(QString m, m_OdbcAttributesList)
	{
		QStringList keyValue = m.split("=");
		nOdbcAttributesClass * oM = new nOdbcAttributesClass(this);
		if (oM->loadToOdbc(keyValue.value(0), keyValue.value(1)))
		{
			m_OdbcAttributes_Map.insert(oM->odbcKey, oM);
		}
	}
}
void	TK_UHSTREC::initialize()
{
	QLoggingCategory category("classLibQ");
	RETCODE r;
	this->setProfileName(profileName);
	qDebug(category) << "Processing - TRKDB100"; 
//SQL Statements
//--------------------------------------------------

#pragma region Sql Statements_TK_UHSTREC

	fetchSql = "select  DB_ID, NVTIMESTAMP, AREA, PAGE, LINE, TK_UHSTDATE, TK_UHSTTIME, TK_UHSTUSER, TK_UHSTCMD, TK_UHSTOLDPRT, TK_UHSTNEWPRT, TK_UHSTOLDFUOM, TK_UHSTNEWFUOM, TK_UHSTOLDTUOM, TK_UHSTNEWTUOM, TK_UHSTOLDFCTR, TK_UHSTNEWFCTR from TK_UHSTREC";
		if (m_ReplicationOption == ReplicationOption::NetChange)
		{
			fetchSql.append(" p1, nv_transfers p2 WHERE  p2.table_name = 'TK_UHSTREC' AND p1.nvtimestamp > p2.last_completed");
		}
	insertSql = "insert into TK_UHSTREC ( PLANT_CODE, NVTIMESTAMP, AREA, PAGE, LINE, TK_UHSTDATE, TK_UHSTTIME, TK_UHSTUSER, TK_UHSTCMD, TK_UHSTOLDPRT, TK_UHSTNEWPRT, TK_UHSTOLDFUOM, TK_UHSTNEWFUOM, TK_UHSTOLDTUOM, TK_UHSTNEWTUOM, TK_UHSTOLDFCTR, TK_UHSTNEWFCTR ) values ( ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?)";
	updateSql = "update TK_UHSTREC set  PLANT_CODE = ?, NVTIMESTAMP = ?, AREA = ?, PAGE = ?, LINE = ?, TK_UHSTDATE = ?, TK_UHSTTIME = ?, TK_UHSTUSER = ?, TK_UHSTCMD = ?, TK_UHSTOLDPRT = ?, TK_UHSTNEWPRT = ?, TK_UHSTOLDFUOM = ?, TK_UHSTNEWFUOM = ?, TK_UHSTOLDTUOM = ?, TK_UHSTNEWTUOM = ?, TK_UHSTOLDFCTR = ?, TK_UHSTNEWFCTR = ?  where area = ? and page = ? line = ? ";

	qDebug(category) << "insertSQL - insert into TK_UHSTREC ( PLANT_CODE, NVTIMESTAMP, AREA, PAGE, LINE, TK_UHSTDATE, TK_UHSTTIME, TK_UHSTUSER, TK_UHSTCMD, TK_UHSTOLDPRT, TK_UHSTNEWPRT, TK_UHSTOLDFUOM, TK_UHSTNEWFUOM, TK_UHSTOLDTUOM, TK_UHSTNEWTUOM, TK_UHSTOLDFCTR, TK_UHSTNEWFCTR ) values ( ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?)";
	qDebug(category) << "fetchSQL - select  DB_ID, NVTIMESTAMP, AREA, PAGE, LINE, TK_UHSTDATE, TK_UHSTTIME, TK_UHSTUSER, TK_UHSTCMD, TK_UHSTOLDPRT, TK_UHSTNEWPRT, TK_UHSTOLDFUOM, TK_UHSTNEWFUOM, TK_UHSTOLDTUOM, TK_UHSTNEWTUOM, TK_UHSTOLDFCTR, TK_UHSTNEWFCTR from TK_UHSTREC";
	qDebug(category) << "unsertSQL - update TK_UHSTREC set  PLANT_CODE = ?, NVTIMESTAMP = ?, AREA = ?, PAGE = ?, LINE = ?, TK_UHSTDATE = ?, TK_UHSTTIME = ?, TK_UHSTUSER = ?, TK_UHSTCMD = ?, TK_UHSTOLDPRT = ?, TK_UHSTNEWPRT = ?, TK_UHSTOLDFUOM = ?, TK_UHSTNEWFUOM = ?, TK_UHSTOLDTUOM = ?, TK_UHSTNEWTUOM = ?, TK_UHSTOLDFCTR = ?, TK_UHSTNEWFCTR = ?  where area = ? and page = ? line = ? ";

#pragma endregion Sql Statements_TK_UHSTREC
	SQLHANDLE		insert_hStmt = SQL_NULL_HANDLE;
	SQLHANDLE		fetch_hStmt = SQL_NULL_HANDLE; 
	SQLHANDLE		update_hStmt = SQL_NULL_HANDLE; 
 
	r = ::SQLAllocHandle(SQL_HANDLE_STMT, hDbc_source, &fetch_hStmt);
	if (r != SQL_SUCCESS) {
		 qCCritical(category) << QString("Error  hDbc_Source SQLCode : %1 is %2").arg(QString::number( (long)hDbc_source)).arg(QString::number(r));
		return; 
	}
	r = ::SQLAllocHandle(SQL_HANDLE_STMT, hDbc_target, &insert_hStmt);
	if (r != SQL_SUCCESS) {
		 qCCritical(category) << QString("Error hDbc_Source -SQLCode: %1 is %2").arg(QString::number( (long)hDbc_target)).arg(QString::number(r));
		return; 
	}
	r = ::SQLAllocHandle(SQL_HANDLE_STMT, hDbc_target, &update_hStmt);
	if (r != SQL_SUCCESS) {
		 qCCritical(category) << QString("Error hDbc_Source +SQLCode: %1 is %2").arg(QString::number( (long)hDbc_target)).arg(QString::number(r));
		return; 
	}
 
	hStmt_Fetch = fetch_hStmt;
	hStmt_Insert = insert_hStmt;
	hStmt_Update = update_hStmt;
 
	SQLSetStmtAttr(hStmt_Fetch, SQL_ATTR_USE_BOOKMARKS, (SQLPOINTER)SQL_UB_OFF, 0);
	SQLSetStmtAttr(hStmt_Fetch, SQL_ATTR_ROW_BIND_TYPE, (SQLPOINTER)SQL_BIND_BY_COLUMN, 0);
	SQLSetStmtAttr(hStmt_Fetch, SQL_ATTR_ROW_ARRAY_SIZE, (SQLPOINTER)1, 0);
	SQLSetStmtAttr(hStmt_Fetch, SQL_ATTR_ROWS_FETCHED_PTR, &numRowsFetched, 0);

// Fields used by this class 
// ---------------------------------------------------

#pragma region Resize Fields TK_UHSTREC
	qDebug(category) << "Malloc - DB_ID[2]";
	DB_ID.resize(2);
	qDebug(category) << "Malloc - NVTIMESTAMP[23]";
	NVTIMESTAMP.resize(23);
	qDebug(category) << "Malloc - AREA[2]";
	AREA.resize(2);
	qDebug(category) << "Malloc - PAGE[4]";
	PAGE.resize(4);
	qDebug(category) << "Malloc - LINE[2]";
	LINE.resize(2);
	qDebug(category) << "Malloc - TK_UHSTDATE[4]";
	TK_UHSTDATE.resize(4);
	qDebug(category) << "Malloc - TK_UHSTTIME[8]";
	TK_UHSTTIME.resize(8);
	qDebug(category) << "Malloc - TK_UHSTUSER[12]";
	TK_UHSTUSER.resize(12);
	qDebug(category) << "Malloc - TK_UHSTCMD[6]";
	TK_UHSTCMD.resize(6);
	qDebug(category) << "Malloc - TK_UHSTOLDPRT[18]";
	TK_UHSTOLDPRT.resize(18);
	qDebug(category) << "Malloc - TK_UHSTNEWPRT[18]";
	TK_UHSTNEWPRT.resize(18);
	qDebug(category) << "Malloc - TK_UHSTOLDFUOM[2]";
	TK_UHSTOLDFUOM.resize(2);
	qDebug(category) << "Malloc - TK_UHSTNEWFUOM[2]";
	TK_UHSTNEWFUOM.resize(2);
	qDebug(category) << "Malloc - TK_UHSTOLDTUOM[2]";
	TK_UHSTOLDTUOM.resize(2);
	qDebug(category) << "Malloc - TK_UHSTNEWTUOM[2]";
	TK_UHSTNEWTUOM.resize(2);
	qDebug(category) << "Malloc - TK_UHSTOLDFCTR[8]";
	TK_UHSTOLDFCTR.resize(8);
	qDebug(category) << "Malloc - TK_UHSTNEWFCTR[8]";
	TK_UHSTNEWFCTR.resize(8);

#pragma endregion Resize Fields TK_UHSTREC
}
void TK_UHSTREC::close()
{
	QLoggingCategory category("classLibQ");
	if (m_bIsOpen)
	{
	qDebug(category) << "database is Open";
		SQLHANDLE source_hStmt = hStmt_Fetch;
		SQLHANDLE insert_hStmt = hStmt_Insert;
		SQLHANDLE hDb_S = this->hDbc_source;
		SQLHANDLE hDb_T = hDbc_target;
		SQLHANDLE hEnvS = hEnv_Source;
		SQLHANDLE hEnvT = hEnv_Target;
		RETCODE r;

		r = ::SQLFreeHandle(SQL_HANDLE_STMT, hStmt_Fetch);
		r = ::SQLFreeHandle(SQL_HANDLE_STMT, hStmt_Insert);
		r = ::SQLFreeHandle(SQL_HANDLE_STMT, hStmt_Update);
		if (hDbc_source != SQL_NULL_HANDLE) 		r = ::SQLDisconnect(hDb_S);
		if (hDbc_target != SQL_NULL_HANDLE) 		r = ::SQLDisconnect(hDb_T);

		r = ::SQLFreeHandle(SQL_HANDLE_DBC, hDb_S);
		r = ::SQLFreeHandle(SQL_HANDLE_DBC, hDb_T);
		r = ::SQLFreeHandle(SQL_HANDLE_ENV, hEnvS);
		r = ::SQLFreeHandle(SQL_HANDLE_ENV, hEnvT);
	}

	hEnv_Source = SQL_NULL_HANDLE;
	hEnv_Target = SQL_NULL_HANDLE;
	hEnv_Source = SQL_NULL_HANDLE;
	hEnv_Target = SQL_NULL_HANDLE;
	hStmt_Fetch = SQL_NULL_HANDLE;
	hStmt_Insert = SQL_NULL_HANDLE;
	hStmt_Update = SQL_NULL_HANDLE;
}

void TK_UHSTREC::open(const QString sourceDSN, const QString targetDSN)
{
	QLoggingCategory category("classLibQ");
	m_lpszTargetDSN = targetDSN;
	m_lpszSourceDSN = sourceDSN;
	qDebug(category) << QString("Source - %1[%2]").arg(sourceDSN);
	qDebug(category) << QString("Target - %1[%2]").arg(targetDSN);
}

void TK_UHSTREC::createTable()
{
	QLoggingCategory category("classLibQ");
	{
		QScopedPointer<nvTableOracleRdb> tbl(new nvTableOracleRdb(nullptr));
		tbl->initialize("TK_UHSTREC", this->m_lpszSourceDSN);
		QString newTbl = tbl->getCreateTableSQL();
		QScopedPointer<qVtExecute> vExec(new qVtExecute(nullptr));
		{
			vExec->initialize(m_lpszTargetDSN, " ", true);
			vExec->setOdbcAttributes(m_OdbcAttributes);
			vExec->ExecuteDirect(newTbl);
		}
	 qDebug(category) << QString("End Create Table %1 ").arg(tableName); 
	}
}

bool TK_UHSTREC::prepare()
{
	RETCODE r;
	QString check;
	QLoggingCategory category("classLibQ");
	 qDebug(category) << fetchSql;
	 qDebug(category) << insertSql;
#ifdef UNICODE
	r = SQLPrepare(hStmt_Insert,toSQLTCHAR(insertSql).data(),(SQLINTEGER)insertSql.length()); 
	if (r != SQL_SUCCESS) {
		check = qWarnODBCHandle(SQL_HANDLE_STMT, hStmt_Insert);
		 qCCritical(category) << QString("Prepare Statement-Insert : %1 is %2").arg(insertSql).arg(check);
		return false; 
	}
	r = SQLPrepare(hStmt_Update,toSQLTCHAR(updateSql).data(),(SQLINTEGER)updateSql.length()); 
	if (r != SQL_SUCCESS) {
		check = qWarnODBCHandle(SQL_HANDLE_STMT, hStmt_Update);
		 qCCritical(category) << QString("Prepare Statement-Update : %1 is %2").arg(updateSql).arg(check);
		return false; 
	}
	r = SQLPrepare(hStmt_Fetch,toSQLTCHAR(fetchSql).data(),(SQLINTEGER)fetchSql.length());
	if (r != SQL_SUCCESS) {
		check = qWarnODBCHandle(SQL_HANDLE_STMT, hStmt_Fetch);
		 qCCritical(category) << QString("Prepare Statement-Insert : %1 is %2").arg(fetchSql).arg(check);
		return false; 
	}
#else
	QByteArray queryI8 = insertSql.toUtf8();
	r = SQLPrepare(insert_hStmt,SQLCHAR*)queryI8.data(),(SQLINTEGER)queryI8.length());
	QByteArray queryU8 = fetchSql.toUtf8();
	r = SQLPrepare(hStmt_Fetch,(SQLCHAR*)queryU8.data(),(SQLINTEGER)queryU8.length());
#endif
	return true;

}

void TK_UHSTREC::prepareTargetTable()
{
	QLoggingCategory category("classLibQ");
	if (this->m_ReplicationOption == ReplicationOption::BulkCopy)
	{
		QScopedPointer<qVtExecute> execSql(new qVtExecute(nullptr));
		DropOption option = this->m_dropOption;
		switch (option)
		{
			case DropOption::DeleteFromTable:
			{
				QLoggingCategory category("classLibQ");
				execSql->initialize(this->m_lpszTargetDSN, "delete from TK_UHSTREC", true);
				execSql->setOdbcAttributes(this->m_OdbcAttributes);
				execSql->ExecuteDirect("delete from TK_UHSTREC");
			}break;
			case DropOption::TruncateTable:
			{
				execSql->initialize(this->m_lpszTargetDSN, "truncate table TK_UHSTREC", true);
				execSql->setOdbcAttributes(this->m_OdbcAttributes);
				execSql->ExecuteDirect("truncate table TK_UHSTREC");
			}break;
			case DropOption::DropTable:
			{
				execSql->initialize(this->m_lpszTargetDSN, "drop table TK_UHSTREC", true);
				execSql->setOdbcAttributes(this->m_OdbcAttributes);
				execSql->ExecuteDirect("drop table TK_UHSTREC");
				createTable();
			}break;
		}
	}
}

bool TK_UHSTREC::bindColumn()
{
	QLoggingCategory category("classLibQ");
	RETCODE r;
	bool isValid=true;
		 qDebug(category) << " Bindings: Ordinal [1] Type: 5 Buffer Size: 2 FieldName: DB_ID ";
		r = ::SQLBindCol(hStmt_Fetch, 1, 5, DB_ID.data(), 2, &cbDB_ID);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Bindings: Ordinal [2] Type: 93 Buffer Size: 23 FieldName: NVTIMESTAMP ";
		r = ::SQLBindCol(hStmt_Fetch, 2, 93, NVTIMESTAMP.data(), 23, &cbNVTIMESTAMP);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Bindings: Ordinal [3] Type: 5 Buffer Size: 2 FieldName: AREA ";
		r = ::SQLBindCol(hStmt_Fetch, 3, 5, AREA.data(), 2, &cbAREA);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Bindings: Ordinal [4] Type: 4 Buffer Size: 4 FieldName: PAGE ";
		r = ::SQLBindCol(hStmt_Fetch, 4, 4, PAGE.data(), 4, &cbPAGE);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Bindings: Ordinal [5] Type: 5 Buffer Size: 2 FieldName: LINE ";
		r = ::SQLBindCol(hStmt_Fetch, 5, 5, LINE.data(), 2, &cbLINE);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Bindings: Ordinal [6] Type: 4 Buffer Size: 4 FieldName: TK_UHSTDATE ";
		r = ::SQLBindCol(hStmt_Fetch, 6, 4, TK_UHSTDATE.data(), 4, &cbTK_UHSTDATE);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Bindings: Ordinal [7] Type: 1 Buffer Size: 8 FieldName: TK_UHSTTIME ";
		r = ::SQLBindCol(hStmt_Fetch, 7, 1, TK_UHSTTIME.data(), 8, &cbTK_UHSTTIME);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Bindings: Ordinal [8] Type: 1 Buffer Size: 12 FieldName: TK_UHSTUSER ";
		r = ::SQLBindCol(hStmt_Fetch, 8, 1, TK_UHSTUSER.data(), 12, &cbTK_UHSTUSER);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Bindings: Ordinal [9] Type: 1 Buffer Size: 6 FieldName: TK_UHSTCMD ";
		r = ::SQLBindCol(hStmt_Fetch, 9, 1, TK_UHSTCMD.data(), 6, &cbTK_UHSTCMD);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Bindings: Ordinal [10] Type: 1 Buffer Size: 18 FieldName: TK_UHSTOLDPRT ";
		r = ::SQLBindCol(hStmt_Fetch, 10, 1, TK_UHSTOLDPRT.data(), 18, &cbTK_UHSTOLDPRT);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Bindings: Ordinal [11] Type: 1 Buffer Size: 18 FieldName: TK_UHSTNEWPRT ";
		r = ::SQLBindCol(hStmt_Fetch, 11, 1, TK_UHSTNEWPRT.data(), 18, &cbTK_UHSTNEWPRT);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Bindings: Ordinal [12] Type: 1 Buffer Size: 2 FieldName: TK_UHSTOLDFUOM ";
		r = ::SQLBindCol(hStmt_Fetch, 12, 1, TK_UHSTOLDFUOM.data(), 2, &cbTK_UHSTOLDFUOM);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Bindings: Ordinal [13] Type: 1 Buffer Size: 2 FieldName: TK_UHSTNEWFUOM ";
		r = ::SQLBindCol(hStmt_Fetch, 13, 1, TK_UHSTNEWFUOM.data(), 2, &cbTK_UHSTNEWFUOM);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Bindings: Ordinal [14] Type: 1 Buffer Size: 2 FieldName: TK_UHSTOLDTUOM ";
		r = ::SQLBindCol(hStmt_Fetch, 14, 1, TK_UHSTOLDTUOM.data(), 2, &cbTK_UHSTOLDTUOM);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Bindings: Ordinal [15] Type: 1 Buffer Size: 2 FieldName: TK_UHSTNEWTUOM ";
		r = ::SQLBindCol(hStmt_Fetch, 15, 1, TK_UHSTNEWTUOM.data(), 2, &cbTK_UHSTNEWTUOM);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Bindings: Ordinal [16] Type: 8 Buffer Size: 8 FieldName: TK_UHSTOLDFCTR ";
		r = ::SQLBindCol(hStmt_Fetch, 16, 8, TK_UHSTOLDFCTR.data(), 8, &cbTK_UHSTOLDFCTR);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Bindings: Ordinal [17] Type: 8 Buffer Size: 8 FieldName: TK_UHSTNEWFCTR ";
		r = ::SQLBindCol(hStmt_Fetch, 17, 8, TK_UHSTNEWFCTR.data(), 8, &cbTK_UHSTNEWFCTR);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
	return isValid;
}

bool TK_UHSTREC::bindParameter()
{
	QLoggingCategory category("classLibQ");
	RETCODE r;
	bool isValid=true;
	{
		 qDebug(category) << " Parameters: Ordinal [1] Type: 5 Buffer Size: 2 FieldName: DB_ID ";
		r = SQLBindParameter(hStmt_Insert, 1, SQL_PARAM_INPUT, SQL_C_DEFAULT, 5, 0, 0, (SQLPOINTER)DB_ID.constData(), 0, &cbDB_ID);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Parameters: Ordinal [2] Type: 93 Buffer Size: 23 FieldName: NVTIMESTAMP ";
		r = SQLBindParameter(hStmt_Insert, 2, SQL_PARAM_INPUT, SQL_C_DEFAULT, 93, 23, 0, (SQLPOINTER)NVTIMESTAMP.constData(), 0, &cbNVTIMESTAMP);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Parameters: Ordinal [3] Type: 5 Buffer Size: 2 FieldName: AREA ";
		r = SQLBindParameter(hStmt_Insert, 3, SQL_PARAM_INPUT, SQL_C_DEFAULT, 5, 0, 0, (SQLPOINTER)AREA.constData(), 0, &cbAREA);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Parameters: Ordinal [4] Type: 4 Buffer Size: 4 FieldName: PAGE ";
		r = SQLBindParameter(hStmt_Insert, 4, SQL_PARAM_INPUT, SQL_C_DEFAULT, 4, 0, 0, (SQLPOINTER)PAGE.constData(), 0, &cbPAGE);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Parameters: Ordinal [5] Type: 5 Buffer Size: 2 FieldName: LINE ";
		r = SQLBindParameter(hStmt_Insert, 5, SQL_PARAM_INPUT, SQL_C_DEFAULT, 5, 0, 0, (SQLPOINTER)LINE.constData(), 0, &cbLINE);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Parameters: Ordinal [6] Type: 4 Buffer Size: 4 FieldName: TK_UHSTDATE ";
		r = SQLBindParameter(hStmt_Insert, 6, SQL_PARAM_INPUT, SQL_C_DEFAULT, 4, 0, 0, (SQLPOINTER)TK_UHSTDATE.constData(), 0, &cbTK_UHSTDATE);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Parameters: Ordinal [7] Type: 1 Buffer Size: 8 FieldName: TK_UHSTTIME ";
		r = SQLBindParameter(hStmt_Insert, 7, SQL_PARAM_INPUT, SQL_C_DEFAULT, 1, 8, 0, (SQLPOINTER)TK_UHSTTIME.constData(), 0, &cbTK_UHSTTIME);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Parameters: Ordinal [8] Type: 1 Buffer Size: 12 FieldName: TK_UHSTUSER ";
		r = SQLBindParameter(hStmt_Insert, 8, SQL_PARAM_INPUT, SQL_C_DEFAULT, 1, 12, 0, (SQLPOINTER)TK_UHSTUSER.constData(), 0, &cbTK_UHSTUSER);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Parameters: Ordinal [9] Type: 1 Buffer Size: 6 FieldName: TK_UHSTCMD ";
		r = SQLBindParameter(hStmt_Insert, 9, SQL_PARAM_INPUT, SQL_C_DEFAULT, 1, 6, 0, (SQLPOINTER)TK_UHSTCMD.constData(), 0, &cbTK_UHSTCMD);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Parameters: Ordinal [10] Type: 1 Buffer Size: 18 FieldName: TK_UHSTOLDPRT ";
		r = SQLBindParameter(hStmt_Insert, 10, SQL_PARAM_INPUT, SQL_C_DEFAULT, 1, 18, 0, (SQLPOINTER)TK_UHSTOLDPRT.constData(), 0, &cbTK_UHSTOLDPRT);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Parameters: Ordinal [11] Type: 1 Buffer Size: 18 FieldName: TK_UHSTNEWPRT ";
		r = SQLBindParameter(hStmt_Insert, 11, SQL_PARAM_INPUT, SQL_C_DEFAULT, 1, 18, 0, (SQLPOINTER)TK_UHSTNEWPRT.constData(), 0, &cbTK_UHSTNEWPRT);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Parameters: Ordinal [12] Type: 1 Buffer Size: 2 FieldName: TK_UHSTOLDFUOM ";
		r = SQLBindParameter(hStmt_Insert, 12, SQL_PARAM_INPUT, SQL_C_DEFAULT, 1, 2, 0, (SQLPOINTER)TK_UHSTOLDFUOM.constData(), 0, &cbTK_UHSTOLDFUOM);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Parameters: Ordinal [13] Type: 1 Buffer Size: 2 FieldName: TK_UHSTNEWFUOM ";
		r = SQLBindParameter(hStmt_Insert, 13, SQL_PARAM_INPUT, SQL_C_DEFAULT, 1, 2, 0, (SQLPOINTER)TK_UHSTNEWFUOM.constData(), 0, &cbTK_UHSTNEWFUOM);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Parameters: Ordinal [14] Type: 1 Buffer Size: 2 FieldName: TK_UHSTOLDTUOM ";
		r = SQLBindParameter(hStmt_Insert, 14, SQL_PARAM_INPUT, SQL_C_DEFAULT, 1, 2, 0, (SQLPOINTER)TK_UHSTOLDTUOM.constData(), 0, &cbTK_UHSTOLDTUOM);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Parameters: Ordinal [15] Type: 1 Buffer Size: 2 FieldName: TK_UHSTNEWTUOM ";
		r = SQLBindParameter(hStmt_Insert, 15, SQL_PARAM_INPUT, SQL_C_DEFAULT, 1, 2, 0, (SQLPOINTER)TK_UHSTNEWTUOM.constData(), 0, &cbTK_UHSTNEWTUOM);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Parameters: Ordinal [16] Type: 8 Buffer Size: 8 FieldName: TK_UHSTOLDFCTR ";
		r = SQLBindParameter(hStmt_Insert, 16, SQL_PARAM_INPUT, SQL_C_DEFAULT, 8, 0, 0, (SQLPOINTER)TK_UHSTOLDFCTR.constData(), 0, &cbTK_UHSTOLDFCTR);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Parameters: Ordinal [17] Type: 8 Buffer Size: 8 FieldName: TK_UHSTNEWFCTR ";
		r = SQLBindParameter(hStmt_Insert, 17, SQL_PARAM_INPUT, SQL_C_DEFAULT, 8, 0, 0, (SQLPOINTER)TK_UHSTNEWFCTR.constData(), 0, &cbTK_UHSTNEWFCTR);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
	}
	if (m_ReplicationOption == ReplicationOption::NetChange)
	{
		r = SQLBindParameter(hStmt_Update, 18, SQL_PARAM_INPUT, SQL_C_DEFAULT, 3, 0, 0, (SQLPOINTER)AREA.constData(), 0, &cbAREA);
		if (r == SQL_SUCCESS) { isValid=true; }
		r = SQLBindParameter(hStmt_Update, 19, SQL_PARAM_INPUT, SQL_C_DEFAULT, 4, 0, 0, (SQLPOINTER)PAGE.constData(), 0, &cbPAGE);
		if (r == SQL_SUCCESS) { isValid=true; }
		r = SQLBindParameter(hStmt_Update, 20, SQL_PARAM_INPUT, SQL_C_DEFAULT, 5, 0, 0, (SQLPOINTER)LINE.constData(), 0, &cbLINE);
		if (r == SQL_SUCCESS) { isValid=true; }
	// TK_UHSTREC is a well formed table for eNVy Replication 
		 qDebug(category) << " Parameters: Ordinal [3] 00 00 FieldName: AREA ";
		 qDebug(category) << " Parameters: Ordinal [4] 00 00  FieldName: PAGE ";
		 qDebug(category) << " Parameters: Ordinal [5] 00 00 FieldName:  LINE ";
	} // 	if (m_ReplicationOption == ReplicationOption::NetChange)
	return isValid;
}

bool TK_UHSTREC::process(int rowSize)
{
	QLoggingCategory category("classLibQ");
	initOdbcAttributes();
	connect(Source);
	connect(Target);
	initialize();
	prepareTargetTable();
	prepare();
	bindColumn();
	bindParameter();
	copyTable();
	close();
	return false;
}

void TK_UHSTREC::copyTable()
{
	QLoggingCategory category("classLibQ");
	RETCODE r;
	QString check;
	r = SQLExecute(hStmt_Fetch);
		if (bIsAbort) {
			emit aborted(tableName, rowsFetched, rowsInserted, rowsUpdated);
			return;
		}
		while((r = SQLFetch(hStmt_Fetch)) != SQL_NO_DATA) {
		if (r != SQL_SUCCESS) {
			check = qWarnODBCHandle(SQL_HANDLE_STMT, hStmt_Fetch);
			qCCritical(category) << QString("SqlFetch - Error : %1 is %2").arg(fetchSql).arg(check);
			return;
		} 
		rowsFetched++;
		if (m_ReplicationOption == ReplicationOption::BulkCopy)
		{
			r = SQLExecute(hStmt_Insert);
			if (r == SQL_ERROR) {
				check = qWarnODBCHandle(SQL_HANDLE_STMT, hStmt_Insert);
				 qCCritical(category) << QString("SqlExecute:Insert - Error : %1 is %2").arg(insertSql).arg(check);
				return;
			}
			rowsInserted++;
			if ((rowsFetched % updateInterval) == 0) {
				qCInfo(category) << QString("[%1.%2]	Insertion: %3	Updates : %4	Fetched : %5").arg(profileName).arg(tableName).arg(rowsInserted).arg(rowsUpdated).arg(rowsFetched);
				emit updateStatusFetched(profileName, tableName, rowsFetched,rowsInserted,rowsUpdated);
			}
			if (m_ReplicationOption == ReplicationOption::NetChange)
			{
			r = SQLExecute(hStmt_Update);
			if (r != SQL_SUCCESS) {
				check = qWarnODBCHandle(SQL_HANDLE_STMT, hStmt_Update);
				 qCInfo(category)  << QString("SqlExecute:Update - Error : %1 is %2").arg(updateSql).arg(check);
				r = SQLExecute(hStmt_Insert);
				if (r != SQL_SUCCESS) {
					check = qWarnODBCHandle(SQL_HANDLE_STMT, hStmt_Insert);
					 qCritical(category) << QString("SqlExecute:Insert - Error : %1 is %2").arg(insertSql).arg(check);
					return;
				}
				else 	rowsInserted++;
				}
				else	rowsUpdated++;
			}
			emit updateStatusFetched(profileName, tableName, rowsFetched,rowsInserted,rowsUpdated);
		}
	} 
qCInfo(category) << QString("[%1.%2]	Insertion: %3	Updates : %4	Fetched : %5").arg(profileName).arg(tableName).arg(rowsInserted).arg(rowsUpdated).arg(rowsFetched);
}

void TK_UHSTREC::connect(connectionHandle connectionSource)
{

	QLoggingCategory category("classLibQ");
	RETCODE r;

	bool isValid = false;
	HWND	hWnd = nullptr;
	hWnd = ::GetDesktopWindow(); 
	SQLSMALLINT nResult = 0;

	SQLSMALLINT cb;
	UWORD wConnectOption = SQL_DRIVER_COMPLETE; //SQL_DRIVER_NOPROMPT;
	QVarLengthArray<SQLTCHAR> connOut(1024);
	memset(connOut.data(), 0, connOut.size() * sizeof(SQLTCHAR));

	switch (connectionSource)
	{
		case Source:
			{// environment
				SQLHANDLE hEnv = SQL_NULL_HANDLE;
				SQLHANDLE hDbc = SQL_NULL_HANDLE;
				r = ::SQLAllocHandle(SQL_HANDLE_ENV, SQL_NULL_HANDLE, &hEnv);
				if (r == SQL_SUCCESS) isValid = true;

				foreach(nOdbcAttributesClass * k, this->m_OdbcAttributes_Map)
				{
					if (k->attributeType == enumAttributeType::hEnv)
					{
						r = ::SQLSetEnvAttr(hEnv, (SQLINTEGER) k->odbcKey, (SQLPOINTER)k->odbcValue, 0);
						if (r == SQL_SUCCESS) isValid = true;
					}
				}
				hEnv_Source = hEnv;

				r = SQLAllocHandle(SQL_HANDLE_DBC, hEnv, &hDbc);
				if (r == SQL_SUCCESS) isValid = true;
				foreach(nOdbcAttributesClass * k, this->m_OdbcAttributes_Map)
				{
					if (k->attributeType == enumAttributeType::hDbc)
					{
					r = ::SQLSetConnectAttr(hDbc, k->odbcKey, (SQLPOINTER)k->odbcValue, 0);
					if (k->odbcKey == SQL_ATTR_CONNECTION_POOLING && k->odbcValue == SQL_CP_ONE_PER_DRIVER) wConnectOption = SQL_DRIVER_NOPROMPT;
					if (k->odbcKey == SQL_ATTR_CONNECTION_POOLING && k->odbcValue == SQL_CP_ONE_PER_HENV) wConnectOption = SQL_DRIVER_NOPROMPT;
					if (k->odbcKey == SQL_ATTR_CONNECTION_POOLING && k->odbcValue == SQL_CP_DRIVER_AWARE) wConnectOption = SQL_DRIVER_NOPROMPT;
					if (r == SQL_SUCCESS) isValid = true;
					}
				}
				hDbc_source = hDbc;
				if (isValid)
				{
					r = ::SQLDriverConnect(
						hDbc,
						hWnd,
#ifdef UNICODE
						toSQLTCHAR(m_lpszSourceDSN).data(),
#else
						(SQLCHAR*)dsnSource.toUtf8().data(),
#endif
						(SQLSMALLINT)m_lpszSourceDSN.length(),
						connOut.data(),
						1024,
						&cb, 
						wConnectOption); 
					int colSize = cb / sizeof(SQLTCHAR);
					if (r != SQL_SUCCESS && r != SQL_SUCCESS_WITH_INFO)
					{
						QString check = qWarnODBCHandle(SQL_HANDLE_DBC, hDbc);
						qCritical(category) <<  check;
						m_bIsOpen = false;
					}
					m_bIsOpen = true;
				}
			} break;
		case Target:
			{
				SQLHANDLE hEnv = SQL_NULL_HANDLE;
				SQLHANDLE hDbc = SQL_NULL_HANDLE;
				r = ::SQLAllocHandle(SQL_HANDLE_ENV, SQL_NULL_HANDLE, &hEnv);
				if (r == SQL_SUCCESS) isValid = true;

				foreach(nOdbcAttributesClass * k, this->m_OdbcAttributes_Map)
				{
					if (k->attributeType == enumAttributeType::hEnv)
					{
						r = ::SQLSetEnvAttr(hEnv, (SQLINTEGER) k->odbcKey, (SQLPOINTER)k->odbcValue, 0);
						if (r == SQL_SUCCESS) isValid = true;
					}
				}
				hEnv_Target = hEnv;

				r = SQLAllocHandle(SQL_HANDLE_DBC, hEnv, &hDbc);
				if (r == SQL_SUCCESS) isValid = true;
				foreach(nOdbcAttributesClass * k, this->m_OdbcAttributes_Map)
				{
				if (k->attributeType == enumAttributeType::hDbc)
					{
					r = ::SQLSetConnectAttr(hDbc, k->odbcKey, (SQLPOINTER)k->odbcValue, 0);
					if (k->odbcKey == SQL_ATTR_CONNECTION_POOLING && k->odbcValue == SQL_CP_ONE_PER_DRIVER) wConnectOption = SQL_DRIVER_NOPROMPT;
					if (k->odbcKey == SQL_ATTR_CONNECTION_POOLING && k->odbcValue == SQL_CP_ONE_PER_HENV) wConnectOption = SQL_DRIVER_NOPROMPT;
					if (k->odbcKey == SQL_ATTR_CONNECTION_POOLING && k->odbcValue == SQL_CP_DRIVER_AWARE) wConnectOption = SQL_DRIVER_NOPROMPT;
					if (r == SQL_SUCCESS) isValid = true;
					}
				}
				hDbc_target = hDbc;
				if (isValid) {
					r = ::SQLDriverConnect(
						hDbc,
						hWnd,
#ifdef UNICODE
						toSQLTCHAR(m_lpszTargetDSN).data(),
#else
						(SQLCHAR*)m_lpszTargetDSN.toUtf8().data(),
#endif
						(SQLSMALLINT)m_lpszTargetDSN.length(),
						connOut.data(),
						1024,
						&cb, 
						wConnectOption); 
						int colSize = cb / sizeof(SQLTCHAR);
					if (r != SQL_SUCCESS && r != SQL_SUCCESS_WITH_INFO)
						{
							QString check = qWarnODBCHandle(SQL_HANDLE_DBC, hDbc);
							qCritical(category) <<  check;
							m_bIsOpen = false;
						}
							m_bIsOpen = true;
					}
			} break;
			default: break;
	}
}
TK_INTFMHSHSET::TK_INTFMHSHSET(QObject * parent) : QObject(parent) 
,tableName("TK_INTFMHSHSET")
,m_dropOption(DropOption::DropTable) { 
	numRowsFetched = 0;
}

#pragma region ~CTOR TK_INTFMHSHSET 
TK_INTFMHSHSET::~TK_INTFMHSHSET() { 

#pragma region Buffers - Clear 
	DB_ID.clear();
	NVTIMESTAMP.clear();
	OAREA.clear();
	OPAGE.clear();
	OLINE.clear();
	MAREA.clear();
	MPAGE.clear();
	MLINE.clear();
#pragma endregion Buffers - Clear 
}
#pragma endregion Destructor_TK_INTFMHSHSET

// begin method functions
void TK_INTFMHSHSET::setAbortFlag() { 
	QLoggingCategory category("classLibQ");
	qCInfo(category) << "isAbort was set to True";
	bIsAbort = true;
}

void TK_INTFMHSHSET::run() { 
	process(1);
	QLoggingCategory category("classLibQ");
	qDebug(category) << "Entered;";
}

void	TK_INTFMHSHSET::initOdbcAttributes()
{
	QLoggingCategory category("classLibQ");
	this->setProfileName(profileName);
	qDebug(category) << "Processing - TRKDB100"; 
	m_OdbcAttributesList = m_OdbcAttributes.split(","); 
	foreach(QString m, m_OdbcAttributesList)
	{
		QStringList keyValue = m.split("=");
		nOdbcAttributesClass * oM = new nOdbcAttributesClass(this);
		if (oM->loadToOdbc(keyValue.value(0), keyValue.value(1)))
		{
			m_OdbcAttributes_Map.insert(oM->odbcKey, oM);
		}
	}
}
void	TK_INTFMHSHSET::initialize()
{
	QLoggingCategory category("classLibQ");
	RETCODE r;
	this->setProfileName(profileName);
	qDebug(category) << "Processing - TRKDB100"; 
//SQL Statements
//--------------------------------------------------

#pragma region Sql Statements_TK_INTFMHSHSET

	fetchSql = "select  DB_ID, NVTIMESTAMP, OAREA, OPAGE, OLINE, MAREA, MPAGE, MLINE from TK_INTFMHSHSET";
		if (m_ReplicationOption == ReplicationOption::NetChange)
		{
			fetchSql.append(" p1, nv_transfers p2 WHERE  p2.table_name = 'TK_INTFMHSHSET' AND p1.nvtimestamp > p2.last_completed");
		}
	insertSql = "insert into TK_INTFMHSHSET ( PLANT_CODE, NVTIMESTAMP, OAREA, OPAGE, OLINE, MAREA, MPAGE, MLINE ) values ( ?, ?, ?, ?, ?, ?, ?, ?)";
	updateSql = "update TK_INTFMHSHSET set  PLANT_CODE = ?, NVTIMESTAMP = ?, OAREA = ?, OPAGE = ?, OLINE = ?, MAREA = ?, MPAGE = ?, MLINE = ?  where area = ? and page = ? line = ? ";

	qDebug(category) << "insertSQL - insert into TK_INTFMHSHSET ( PLANT_CODE, NVTIMESTAMP, OAREA, OPAGE, OLINE, MAREA, MPAGE, MLINE ) values ( ?, ?, ?, ?, ?, ?, ?, ?)";
	qDebug(category) << "fetchSQL - select  DB_ID, NVTIMESTAMP, OAREA, OPAGE, OLINE, MAREA, MPAGE, MLINE from TK_INTFMHSHSET";
	qDebug(category) << "unsertSQL - update TK_INTFMHSHSET set  PLANT_CODE = ?, NVTIMESTAMP = ?, OAREA = ?, OPAGE = ?, OLINE = ?, MAREA = ?, MPAGE = ?, MLINE = ?  where area = ? and page = ? line = ? ";

#pragma endregion Sql Statements_TK_INTFMHSHSET
	SQLHANDLE		insert_hStmt = SQL_NULL_HANDLE;
	SQLHANDLE		fetch_hStmt = SQL_NULL_HANDLE; 
	SQLHANDLE		update_hStmt = SQL_NULL_HANDLE; 
 
	r = ::SQLAllocHandle(SQL_HANDLE_STMT, hDbc_source, &fetch_hStmt);
	if (r != SQL_SUCCESS) {
		 qCCritical(category) << QString("Error  hDbc_Source SQLCode : %1 is %2").arg(QString::number( (long)hDbc_source)).arg(QString::number(r));
		return; 
	}
	r = ::SQLAllocHandle(SQL_HANDLE_STMT, hDbc_target, &insert_hStmt);
	if (r != SQL_SUCCESS) {
		 qCCritical(category) << QString("Error hDbc_Source -SQLCode: %1 is %2").arg(QString::number( (long)hDbc_target)).arg(QString::number(r));
		return; 
	}
	r = ::SQLAllocHandle(SQL_HANDLE_STMT, hDbc_target, &update_hStmt);
	if (r != SQL_SUCCESS) {
		 qCCritical(category) << QString("Error hDbc_Source +SQLCode: %1 is %2").arg(QString::number( (long)hDbc_target)).arg(QString::number(r));
		return; 
	}
 
	hStmt_Fetch = fetch_hStmt;
	hStmt_Insert = insert_hStmt;
	hStmt_Update = update_hStmt;
 
	SQLSetStmtAttr(hStmt_Fetch, SQL_ATTR_USE_BOOKMARKS, (SQLPOINTER)SQL_UB_OFF, 0);
	SQLSetStmtAttr(hStmt_Fetch, SQL_ATTR_ROW_BIND_TYPE, (SQLPOINTER)SQL_BIND_BY_COLUMN, 0);
	SQLSetStmtAttr(hStmt_Fetch, SQL_ATTR_ROW_ARRAY_SIZE, (SQLPOINTER)1, 0);
	SQLSetStmtAttr(hStmt_Fetch, SQL_ATTR_ROWS_FETCHED_PTR, &numRowsFetched, 0);

// Fields used by this class 
// ---------------------------------------------------

#pragma region Resize Fields TK_INTFMHSHSET
	qDebug(category) << "Malloc - DB_ID[2]";
	DB_ID.resize(2);
	qDebug(category) << "Malloc - NVTIMESTAMP[23]";
	NVTIMESTAMP.resize(23);
	qDebug(category) << "Malloc - OAREA[2]";
	OAREA.resize(2);
	qDebug(category) << "Malloc - OPAGE[4]";
	OPAGE.resize(4);
	qDebug(category) << "Malloc - OLINE[2]";
	OLINE.resize(2);
	qDebug(category) << "Malloc - MAREA[2]";
	MAREA.resize(2);
	qDebug(category) << "Malloc - MPAGE[4]";
	MPAGE.resize(4);
	qDebug(category) << "Malloc - MLINE[2]";
	MLINE.resize(2);

#pragma endregion Resize Fields TK_INTFMHSHSET
}
void TK_INTFMHSHSET::close()
{
	QLoggingCategory category("classLibQ");
	if (m_bIsOpen)
	{
	qDebug(category) << "database is Open";
		SQLHANDLE source_hStmt = hStmt_Fetch;
		SQLHANDLE insert_hStmt = hStmt_Insert;
		SQLHANDLE hDb_S = this->hDbc_source;
		SQLHANDLE hDb_T = hDbc_target;
		SQLHANDLE hEnvS = hEnv_Source;
		SQLHANDLE hEnvT = hEnv_Target;
		RETCODE r;

		r = ::SQLFreeHandle(SQL_HANDLE_STMT, hStmt_Fetch);
		r = ::SQLFreeHandle(SQL_HANDLE_STMT, hStmt_Insert);
		r = ::SQLFreeHandle(SQL_HANDLE_STMT, hStmt_Update);
		if (hDbc_source != SQL_NULL_HANDLE) 		r = ::SQLDisconnect(hDb_S);
		if (hDbc_target != SQL_NULL_HANDLE) 		r = ::SQLDisconnect(hDb_T);

		r = ::SQLFreeHandle(SQL_HANDLE_DBC, hDb_S);
		r = ::SQLFreeHandle(SQL_HANDLE_DBC, hDb_T);
		r = ::SQLFreeHandle(SQL_HANDLE_ENV, hEnvS);
		r = ::SQLFreeHandle(SQL_HANDLE_ENV, hEnvT);
	}

	hEnv_Source = SQL_NULL_HANDLE;
	hEnv_Target = SQL_NULL_HANDLE;
	hEnv_Source = SQL_NULL_HANDLE;
	hEnv_Target = SQL_NULL_HANDLE;
	hStmt_Fetch = SQL_NULL_HANDLE;
	hStmt_Insert = SQL_NULL_HANDLE;
	hStmt_Update = SQL_NULL_HANDLE;
}

void TK_INTFMHSHSET::open(const QString sourceDSN, const QString targetDSN)
{
	QLoggingCategory category("classLibQ");
	m_lpszTargetDSN = targetDSN;
	m_lpszSourceDSN = sourceDSN;
	qDebug(category) << QString("Source - %1[%2]").arg(sourceDSN);
	qDebug(category) << QString("Target - %1[%2]").arg(targetDSN);
}

void TK_INTFMHSHSET::createTable()
{
	QLoggingCategory category("classLibQ");
	{
		QScopedPointer<nvTableOracleRdb> tbl(new nvTableOracleRdb(nullptr));
		tbl->initialize("TK_INTFMHSHSET", this->m_lpszSourceDSN);
		QString newTbl = tbl->getCreateTableSQL();
		QScopedPointer<qVtExecute> vExec(new qVtExecute(nullptr));
		{
			vExec->initialize(m_lpszTargetDSN, " ", true);
			vExec->setOdbcAttributes(m_OdbcAttributes);
			vExec->ExecuteDirect(newTbl);
		}
	 qDebug(category) << QString("End Create Table %1 ").arg(tableName); 
	}
}

bool TK_INTFMHSHSET::prepare()
{
	RETCODE r;
	QString check;
	QLoggingCategory category("classLibQ");
	 qDebug(category) << fetchSql;
	 qDebug(category) << insertSql;
#ifdef UNICODE
	r = SQLPrepare(hStmt_Insert,toSQLTCHAR(insertSql).data(),(SQLINTEGER)insertSql.length()); 
	if (r != SQL_SUCCESS) {
		check = qWarnODBCHandle(SQL_HANDLE_STMT, hStmt_Insert);
		 qCCritical(category) << QString("Prepare Statement-Insert : %1 is %2").arg(insertSql).arg(check);
		return false; 
	}
	r = SQLPrepare(hStmt_Update,toSQLTCHAR(updateSql).data(),(SQLINTEGER)updateSql.length()); 
	if (r != SQL_SUCCESS) {
		check = qWarnODBCHandle(SQL_HANDLE_STMT, hStmt_Update);
		 qCCritical(category) << QString("Prepare Statement-Update : %1 is %2").arg(updateSql).arg(check);
		return false; 
	}
	r = SQLPrepare(hStmt_Fetch,toSQLTCHAR(fetchSql).data(),(SQLINTEGER)fetchSql.length());
	if (r != SQL_SUCCESS) {
		check = qWarnODBCHandle(SQL_HANDLE_STMT, hStmt_Fetch);
		 qCCritical(category) << QString("Prepare Statement-Insert : %1 is %2").arg(fetchSql).arg(check);
		return false; 
	}
#else
	QByteArray queryI8 = insertSql.toUtf8();
	r = SQLPrepare(insert_hStmt,SQLCHAR*)queryI8.data(),(SQLINTEGER)queryI8.length());
	QByteArray queryU8 = fetchSql.toUtf8();
	r = SQLPrepare(hStmt_Fetch,(SQLCHAR*)queryU8.data(),(SQLINTEGER)queryU8.length());
#endif
	return true;

}

void TK_INTFMHSHSET::prepareTargetTable()
{
	QLoggingCategory category("classLibQ");
	if (this->m_ReplicationOption == ReplicationOption::BulkCopy)
	{
		QScopedPointer<qVtExecute> execSql(new qVtExecute(nullptr));
		DropOption option = this->m_dropOption;
		switch (option)
		{
			case DropOption::DeleteFromTable:
			{
				QLoggingCategory category("classLibQ");
				execSql->initialize(this->m_lpszTargetDSN, "delete from TK_INTFMHSHSET", true);
				execSql->setOdbcAttributes(this->m_OdbcAttributes);
				execSql->ExecuteDirect("delete from TK_INTFMHSHSET");
			}break;
			case DropOption::TruncateTable:
			{
				execSql->initialize(this->m_lpszTargetDSN, "truncate table TK_INTFMHSHSET", true);
				execSql->setOdbcAttributes(this->m_OdbcAttributes);
				execSql->ExecuteDirect("truncate table TK_INTFMHSHSET");
			}break;
			case DropOption::DropTable:
			{
				execSql->initialize(this->m_lpszTargetDSN, "drop table TK_INTFMHSHSET", true);
				execSql->setOdbcAttributes(this->m_OdbcAttributes);
				execSql->ExecuteDirect("drop table TK_INTFMHSHSET");
				createTable();
			}break;
		}
	}
}

bool TK_INTFMHSHSET::bindColumn()
{
	QLoggingCategory category("classLibQ");
	RETCODE r;
	bool isValid=true;
		 qDebug(category) << " Bindings: Ordinal [1] Type: 5 Buffer Size: 2 FieldName: DB_ID ";
		r = ::SQLBindCol(hStmt_Fetch, 1, 5, DB_ID.data(), 2, &cbDB_ID);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Bindings: Ordinal [2] Type: 93 Buffer Size: 23 FieldName: NVTIMESTAMP ";
		r = ::SQLBindCol(hStmt_Fetch, 2, 93, NVTIMESTAMP.data(), 23, &cbNVTIMESTAMP);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Bindings: Ordinal [3] Type: 5 Buffer Size: 2 FieldName: OAREA ";
		r = ::SQLBindCol(hStmt_Fetch, 3, 5, OAREA.data(), 2, &cbOAREA);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Bindings: Ordinal [4] Type: 4 Buffer Size: 4 FieldName: OPAGE ";
		r = ::SQLBindCol(hStmt_Fetch, 4, 4, OPAGE.data(), 4, &cbOPAGE);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Bindings: Ordinal [5] Type: 5 Buffer Size: 2 FieldName: OLINE ";
		r = ::SQLBindCol(hStmt_Fetch, 5, 5, OLINE.data(), 2, &cbOLINE);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Bindings: Ordinal [6] Type: 5 Buffer Size: 2 FieldName: MAREA ";
		r = ::SQLBindCol(hStmt_Fetch, 6, 5, MAREA.data(), 2, &cbMAREA);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Bindings: Ordinal [7] Type: 4 Buffer Size: 4 FieldName: MPAGE ";
		r = ::SQLBindCol(hStmt_Fetch, 7, 4, MPAGE.data(), 4, &cbMPAGE);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Bindings: Ordinal [8] Type: 5 Buffer Size: 2 FieldName: MLINE ";
		r = ::SQLBindCol(hStmt_Fetch, 8, 5, MLINE.data(), 2, &cbMLINE);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
	return isValid;
}

bool TK_INTFMHSHSET::bindParameter()
{
	QLoggingCategory category("classLibQ");
	RETCODE r;
	bool isValid=true;
	{
		 qDebug(category) << " Parameters: Ordinal [1] Type: 5 Buffer Size: 2 FieldName: DB_ID ";
		r = SQLBindParameter(hStmt_Insert, 1, SQL_PARAM_INPUT, SQL_C_DEFAULT, 5, 0, 0, (SQLPOINTER)DB_ID.constData(), 0, &cbDB_ID);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Parameters: Ordinal [2] Type: 93 Buffer Size: 23 FieldName: NVTIMESTAMP ";
		r = SQLBindParameter(hStmt_Insert, 2, SQL_PARAM_INPUT, SQL_C_DEFAULT, 93, 23, 0, (SQLPOINTER)NVTIMESTAMP.constData(), 0, &cbNVTIMESTAMP);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Parameters: Ordinal [3] Type: 5 Buffer Size: 2 FieldName: OAREA ";
		r = SQLBindParameter(hStmt_Insert, 3, SQL_PARAM_INPUT, SQL_C_DEFAULT, 5, 0, 0, (SQLPOINTER)OAREA.constData(), 0, &cbOAREA);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Parameters: Ordinal [4] Type: 4 Buffer Size: 4 FieldName: OPAGE ";
		r = SQLBindParameter(hStmt_Insert, 4, SQL_PARAM_INPUT, SQL_C_DEFAULT, 4, 0, 0, (SQLPOINTER)OPAGE.constData(), 0, &cbOPAGE);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Parameters: Ordinal [5] Type: 5 Buffer Size: 2 FieldName: OLINE ";
		r = SQLBindParameter(hStmt_Insert, 5, SQL_PARAM_INPUT, SQL_C_DEFAULT, 5, 0, 0, (SQLPOINTER)OLINE.constData(), 0, &cbOLINE);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Parameters: Ordinal [6] Type: 5 Buffer Size: 2 FieldName: MAREA ";
		r = SQLBindParameter(hStmt_Insert, 6, SQL_PARAM_INPUT, SQL_C_DEFAULT, 5, 0, 0, (SQLPOINTER)MAREA.constData(), 0, &cbMAREA);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Parameters: Ordinal [7] Type: 4 Buffer Size: 4 FieldName: MPAGE ";
		r = SQLBindParameter(hStmt_Insert, 7, SQL_PARAM_INPUT, SQL_C_DEFAULT, 4, 0, 0, (SQLPOINTER)MPAGE.constData(), 0, &cbMPAGE);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Parameters: Ordinal [8] Type: 5 Buffer Size: 2 FieldName: MLINE ";
		r = SQLBindParameter(hStmt_Insert, 8, SQL_PARAM_INPUT, SQL_C_DEFAULT, 5, 0, 0, (SQLPOINTER)MLINE.constData(), 0, &cbMLINE);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
	}
	if (m_ReplicationOption == ReplicationOption::NetChange)
	{
		r = SQLBindParameter(hStmt_Update, 9, SQL_PARAM_INPUT, SQL_C_DEFAULT, 6, 0, 0, (SQLPOINTER)MAREA.constData(), 0, &cbMAREA);
		if (r == SQL_SUCCESS) { isValid=true; }
		r = SQLBindParameter(hStmt_Update, 10, SQL_PARAM_INPUT, SQL_C_DEFAULT, 7, 0, 0, (SQLPOINTER)MPAGE.constData(), 0, &cbMPAGE);
		if (r == SQL_SUCCESS) { isValid=true; }
		r = SQLBindParameter(hStmt_Update, 11, SQL_PARAM_INPUT, SQL_C_DEFAULT, 8, 0, 0, (SQLPOINTER)MLINE.constData(), 0, &cbMLINE);
		if (r == SQL_SUCCESS) { isValid=true; }
	// TK_INTFMHSHSET is a well formed table for eNVy Replication 
		 qDebug(category) << " Parameters: Ordinal [6] 00 00 FieldName: MAREA ";
		 qDebug(category) << " Parameters: Ordinal [7] 00 00  FieldName: MPAGE ";
		 qDebug(category) << " Parameters: Ordinal [8] 00 00 FieldName:  MLINE ";
	} // 	if (m_ReplicationOption == ReplicationOption::NetChange)
	return isValid;
}

bool TK_INTFMHSHSET::process(int rowSize)
{
	QLoggingCategory category("classLibQ");
	initOdbcAttributes();
	connect(Source);
	connect(Target);
	initialize();
	prepareTargetTable();
	prepare();
	bindColumn();
	bindParameter();
	copyTable();
	close();
	return false;
}

void TK_INTFMHSHSET::copyTable()
{
	QLoggingCategory category("classLibQ");
	RETCODE r;
	QString check;
	r = SQLExecute(hStmt_Fetch);
		if (bIsAbort) {
			emit aborted(tableName, rowsFetched, rowsInserted, rowsUpdated);
			return;
		}
		while((r = SQLFetch(hStmt_Fetch)) != SQL_NO_DATA) {
		if (r != SQL_SUCCESS) {
			check = qWarnODBCHandle(SQL_HANDLE_STMT, hStmt_Fetch);
			qCCritical(category) << QString("SqlFetch - Error : %1 is %2").arg(fetchSql).arg(check);
			return;
		} 
		rowsFetched++;
		if (m_ReplicationOption == ReplicationOption::BulkCopy)
		{
			r = SQLExecute(hStmt_Insert);
			if (r == SQL_ERROR) {
				check = qWarnODBCHandle(SQL_HANDLE_STMT, hStmt_Insert);
				 qCCritical(category) << QString("SqlExecute:Insert - Error : %1 is %2").arg(insertSql).arg(check);
				return;
			}
			rowsInserted++;
			if ((rowsFetched % updateInterval) == 0) {
				qCInfo(category) << QString("[%1.%2]	Insertion: %3	Updates : %4	Fetched : %5").arg(profileName).arg(tableName).arg(rowsInserted).arg(rowsUpdated).arg(rowsFetched);
				emit updateStatusFetched(profileName, tableName, rowsFetched,rowsInserted,rowsUpdated);
			}
			if (m_ReplicationOption == ReplicationOption::NetChange)
			{
			r = SQLExecute(hStmt_Update);
			if (r != SQL_SUCCESS) {
				check = qWarnODBCHandle(SQL_HANDLE_STMT, hStmt_Update);
				 qCInfo(category)  << QString("SqlExecute:Update - Error : %1 is %2").arg(updateSql).arg(check);
				r = SQLExecute(hStmt_Insert);
				if (r != SQL_SUCCESS) {
					check = qWarnODBCHandle(SQL_HANDLE_STMT, hStmt_Insert);
					 qCritical(category) << QString("SqlExecute:Insert - Error : %1 is %2").arg(insertSql).arg(check);
					return;
				}
				else 	rowsInserted++;
				}
				else	rowsUpdated++;
			}
			emit updateStatusFetched(profileName, tableName, rowsFetched,rowsInserted,rowsUpdated);
		}
	} 
qCInfo(category) << QString("[%1.%2]	Insertion: %3	Updates : %4	Fetched : %5").arg(profileName).arg(tableName).arg(rowsInserted).arg(rowsUpdated).arg(rowsFetched);
}

void TK_INTFMHSHSET::connect(connectionHandle connectionSource)
{

	QLoggingCategory category("classLibQ");
	RETCODE r;

	bool isValid = false;
	HWND	hWnd = nullptr;
	hWnd = ::GetDesktopWindow(); 
	SQLSMALLINT nResult = 0;

	SQLSMALLINT cb;
	UWORD wConnectOption = SQL_DRIVER_COMPLETE; //SQL_DRIVER_NOPROMPT;
	QVarLengthArray<SQLTCHAR> connOut(1024);
	memset(connOut.data(), 0, connOut.size() * sizeof(SQLTCHAR));

	switch (connectionSource)
	{
		case Source:
			{// environment
				SQLHANDLE hEnv = SQL_NULL_HANDLE;
				SQLHANDLE hDbc = SQL_NULL_HANDLE;
				r = ::SQLAllocHandle(SQL_HANDLE_ENV, SQL_NULL_HANDLE, &hEnv);
				if (r == SQL_SUCCESS) isValid = true;

				foreach(nOdbcAttributesClass * k, this->m_OdbcAttributes_Map)
				{
					if (k->attributeType == enumAttributeType::hEnv)
					{
						r = ::SQLSetEnvAttr(hEnv, (SQLINTEGER) k->odbcKey, (SQLPOINTER)k->odbcValue, 0);
						if (r == SQL_SUCCESS) isValid = true;
					}
				}
				hEnv_Source = hEnv;

				r = SQLAllocHandle(SQL_HANDLE_DBC, hEnv, &hDbc);
				if (r == SQL_SUCCESS) isValid = true;
				foreach(nOdbcAttributesClass * k, this->m_OdbcAttributes_Map)
				{
					if (k->attributeType == enumAttributeType::hDbc)
					{
					r = ::SQLSetConnectAttr(hDbc, k->odbcKey, (SQLPOINTER)k->odbcValue, 0);
					if (k->odbcKey == SQL_ATTR_CONNECTION_POOLING && k->odbcValue == SQL_CP_ONE_PER_DRIVER) wConnectOption = SQL_DRIVER_NOPROMPT;
					if (k->odbcKey == SQL_ATTR_CONNECTION_POOLING && k->odbcValue == SQL_CP_ONE_PER_HENV) wConnectOption = SQL_DRIVER_NOPROMPT;
					if (k->odbcKey == SQL_ATTR_CONNECTION_POOLING && k->odbcValue == SQL_CP_DRIVER_AWARE) wConnectOption = SQL_DRIVER_NOPROMPT;
					if (r == SQL_SUCCESS) isValid = true;
					}
				}
				hDbc_source = hDbc;
				if (isValid)
				{
					r = ::SQLDriverConnect(
						hDbc,
						hWnd,
#ifdef UNICODE
						toSQLTCHAR(m_lpszSourceDSN).data(),
#else
						(SQLCHAR*)dsnSource.toUtf8().data(),
#endif
						(SQLSMALLINT)m_lpszSourceDSN.length(),
						connOut.data(),
						1024,
						&cb, 
						wConnectOption); 
					int colSize = cb / sizeof(SQLTCHAR);
					if (r != SQL_SUCCESS && r != SQL_SUCCESS_WITH_INFO)
					{
						QString check = qWarnODBCHandle(SQL_HANDLE_DBC, hDbc);
						qCritical(category) <<  check;
						m_bIsOpen = false;
					}
					m_bIsOpen = true;
				}
			} break;
		case Target:
			{
				SQLHANDLE hEnv = SQL_NULL_HANDLE;
				SQLHANDLE hDbc = SQL_NULL_HANDLE;
				r = ::SQLAllocHandle(SQL_HANDLE_ENV, SQL_NULL_HANDLE, &hEnv);
				if (r == SQL_SUCCESS) isValid = true;

				foreach(nOdbcAttributesClass * k, this->m_OdbcAttributes_Map)
				{
					if (k->attributeType == enumAttributeType::hEnv)
					{
						r = ::SQLSetEnvAttr(hEnv, (SQLINTEGER) k->odbcKey, (SQLPOINTER)k->odbcValue, 0);
						if (r == SQL_SUCCESS) isValid = true;
					}
				}
				hEnv_Target = hEnv;

				r = SQLAllocHandle(SQL_HANDLE_DBC, hEnv, &hDbc);
				if (r == SQL_SUCCESS) isValid = true;
				foreach(nOdbcAttributesClass * k, this->m_OdbcAttributes_Map)
				{
				if (k->attributeType == enumAttributeType::hDbc)
					{
					r = ::SQLSetConnectAttr(hDbc, k->odbcKey, (SQLPOINTER)k->odbcValue, 0);
					if (k->odbcKey == SQL_ATTR_CONNECTION_POOLING && k->odbcValue == SQL_CP_ONE_PER_DRIVER) wConnectOption = SQL_DRIVER_NOPROMPT;
					if (k->odbcKey == SQL_ATTR_CONNECTION_POOLING && k->odbcValue == SQL_CP_ONE_PER_HENV) wConnectOption = SQL_DRIVER_NOPROMPT;
					if (k->odbcKey == SQL_ATTR_CONNECTION_POOLING && k->odbcValue == SQL_CP_DRIVER_AWARE) wConnectOption = SQL_DRIVER_NOPROMPT;
					if (r == SQL_SUCCESS) isValid = true;
					}
				}
				hDbc_target = hDbc;
				if (isValid) {
					r = ::SQLDriverConnect(
						hDbc,
						hWnd,
#ifdef UNICODE
						toSQLTCHAR(m_lpszTargetDSN).data(),
#else
						(SQLCHAR*)m_lpszTargetDSN.toUtf8().data(),
#endif
						(SQLSMALLINT)m_lpszTargetDSN.length(),
						connOut.data(),
						1024,
						&cb, 
						wConnectOption); 
						int colSize = cb / sizeof(SQLTCHAR);
					if (r != SQL_SUCCESS && r != SQL_SUCCESS_WITH_INFO)
						{
							QString check = qWarnODBCHandle(SQL_HANDLE_DBC, hDbc);
							qCritical(category) <<  check;
							m_bIsOpen = false;
						}
							m_bIsOpen = true;
					}
			} break;
			default: break;
	}
}
TK_LTDREC::TK_LTDREC(QObject * parent) : QObject(parent) 
,tableName("TK_LTDREC")
,m_dropOption(DropOption::DropTable) { 
	numRowsFetched = 0;
}

#pragma region ~CTOR TK_LTDREC 
TK_LTDREC::~TK_LTDREC() { 

#pragma region Buffers - Clear 
	DB_ID.clear();
	NVTIMESTAMP.clear();
	AREA.clear();
	PAGE.clear();
	LINE.clear();
	TK_LTDISSQTY.clear();
	TK_LTDDAT.clear();
	TK_LTDCMD.clear();
	TK_LTDARCFLG.clear();
	TK_LTPLOT.clear();
	TK_LTPLOT15.clear();
#pragma endregion Buffers - Clear 
}
#pragma endregion Destructor_TK_LTDREC

// begin method functions
void TK_LTDREC::setAbortFlag() { 
	QLoggingCategory category("classLibQ");
	qCInfo(category) << "isAbort was set to True";
	bIsAbort = true;
}

void TK_LTDREC::run() { 
	process(1);
	QLoggingCategory category("classLibQ");
	qDebug(category) << "Entered;";
}

void	TK_LTDREC::initOdbcAttributes()
{
	QLoggingCategory category("classLibQ");
	this->setProfileName(profileName);
	qDebug(category) << "Processing - TRKDB100"; 
	m_OdbcAttributesList = m_OdbcAttributes.split(","); 
	foreach(QString m, m_OdbcAttributesList)
	{
		QStringList keyValue = m.split("=");
		nOdbcAttributesClass * oM = new nOdbcAttributesClass(this);
		if (oM->loadToOdbc(keyValue.value(0), keyValue.value(1)))
		{
			m_OdbcAttributes_Map.insert(oM->odbcKey, oM);
		}
	}
}
void	TK_LTDREC::initialize()
{
	QLoggingCategory category("classLibQ");
	RETCODE r;
	this->setProfileName(profileName);
	qDebug(category) << "Processing - TRKDB100"; 
//SQL Statements
//--------------------------------------------------

#pragma region Sql Statements_TK_LTDREC

	fetchSql = "select  DB_ID, NVTIMESTAMP, AREA, PAGE, LINE, TK_LTDISSQTY, TK_LTDDAT, TK_LTDCMD, TK_LTDARCFLG, TK_LTPLOT, TK_LTPLOT15 from TK_LTDREC";
		if (m_ReplicationOption == ReplicationOption::NetChange)
		{
			fetchSql.append(" p1, nv_transfers p2 WHERE  p2.table_name = 'TK_LTDREC' AND p1.nvtimestamp > p2.last_completed");
		}
	insertSql = "insert into TK_LTDREC ( PLANT_CODE, NVTIMESTAMP, AREA, PAGE, LINE, TK_LTDISSQTY, TK_LTDDAT, TK_LTDCMD, TK_LTDARCFLG, TK_LTPLOT, TK_LTPLOT15 ) values ( ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?)";
	updateSql = "update TK_LTDREC set  PLANT_CODE = ?, NVTIMESTAMP = ?, AREA = ?, PAGE = ?, LINE = ?, TK_LTDISSQTY = ?, TK_LTDDAT = ?, TK_LTDCMD = ?, TK_LTDARCFLG = ?, TK_LTPLOT = ?, TK_LTPLOT15 = ?  where area = ? and page = ? line = ? ";

	qDebug(category) << "insertSQL - insert into TK_LTDREC ( PLANT_CODE, NVTIMESTAMP, AREA, PAGE, LINE, TK_LTDISSQTY, TK_LTDDAT, TK_LTDCMD, TK_LTDARCFLG, TK_LTPLOT, TK_LTPLOT15 ) values ( ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?)";
	qDebug(category) << "fetchSQL - select  DB_ID, NVTIMESTAMP, AREA, PAGE, LINE, TK_LTDISSQTY, TK_LTDDAT, TK_LTDCMD, TK_LTDARCFLG, TK_LTPLOT, TK_LTPLOT15 from TK_LTDREC";
	qDebug(category) << "unsertSQL - update TK_LTDREC set  PLANT_CODE = ?, NVTIMESTAMP = ?, AREA = ?, PAGE = ?, LINE = ?, TK_LTDISSQTY = ?, TK_LTDDAT = ?, TK_LTDCMD = ?, TK_LTDARCFLG = ?, TK_LTPLOT = ?, TK_LTPLOT15 = ?  where area = ? and page = ? line = ? ";

#pragma endregion Sql Statements_TK_LTDREC
	SQLHANDLE		insert_hStmt = SQL_NULL_HANDLE;
	SQLHANDLE		fetch_hStmt = SQL_NULL_HANDLE; 
	SQLHANDLE		update_hStmt = SQL_NULL_HANDLE; 
 
	r = ::SQLAllocHandle(SQL_HANDLE_STMT, hDbc_source, &fetch_hStmt);
	if (r != SQL_SUCCESS) {
		 qCCritical(category) << QString("Error  hDbc_Source SQLCode : %1 is %2").arg(QString::number( (long)hDbc_source)).arg(QString::number(r));
		return; 
	}
	r = ::SQLAllocHandle(SQL_HANDLE_STMT, hDbc_target, &insert_hStmt);
	if (r != SQL_SUCCESS) {
		 qCCritical(category) << QString("Error hDbc_Source -SQLCode: %1 is %2").arg(QString::number( (long)hDbc_target)).arg(QString::number(r));
		return; 
	}
	r = ::SQLAllocHandle(SQL_HANDLE_STMT, hDbc_target, &update_hStmt);
	if (r != SQL_SUCCESS) {
		 qCCritical(category) << QString("Error hDbc_Source +SQLCode: %1 is %2").arg(QString::number( (long)hDbc_target)).arg(QString::number(r));
		return; 
	}
 
	hStmt_Fetch = fetch_hStmt;
	hStmt_Insert = insert_hStmt;
	hStmt_Update = update_hStmt;
 
	SQLSetStmtAttr(hStmt_Fetch, SQL_ATTR_USE_BOOKMARKS, (SQLPOINTER)SQL_UB_OFF, 0);
	SQLSetStmtAttr(hStmt_Fetch, SQL_ATTR_ROW_BIND_TYPE, (SQLPOINTER)SQL_BIND_BY_COLUMN, 0);
	SQLSetStmtAttr(hStmt_Fetch, SQL_ATTR_ROW_ARRAY_SIZE, (SQLPOINTER)1, 0);
	SQLSetStmtAttr(hStmt_Fetch, SQL_ATTR_ROWS_FETCHED_PTR, &numRowsFetched, 0);

// Fields used by this class 
// ---------------------------------------------------

#pragma region Resize Fields TK_LTDREC
	qDebug(category) << "Malloc - DB_ID[2]";
	DB_ID.resize(2);
	qDebug(category) << "Malloc - NVTIMESTAMP[23]";
	NVTIMESTAMP.resize(23);
	qDebug(category) << "Malloc - AREA[2]";
	AREA.resize(2);
	qDebug(category) << "Malloc - PAGE[4]";
	PAGE.resize(4);
	qDebug(category) << "Malloc - LINE[2]";
	LINE.resize(2);
	qDebug(category) << "Malloc - TK_LTDISSQTY[8]";
	TK_LTDISSQTY.resize(8);
	qDebug(category) << "Malloc - TK_LTDDAT[4]";
	TK_LTDDAT.resize(4);
	qDebug(category) << "Malloc - TK_LTDCMD[6]";
	TK_LTDCMD.resize(6);
	qDebug(category) << "Malloc - TK_LTDARCFLG[2]";
	TK_LTDARCFLG.resize(2);
	qDebug(category) << "Malloc - TK_LTPLOT[24]";
	TK_LTPLOT.resize(24);
	qDebug(category) << "Malloc - TK_LTPLOT15[24]";
	TK_LTPLOT15.resize(24);

#pragma endregion Resize Fields TK_LTDREC
}
void TK_LTDREC::close()
{
	QLoggingCategory category("classLibQ");
	if (m_bIsOpen)
	{
	qDebug(category) << "database is Open";
		SQLHANDLE source_hStmt = hStmt_Fetch;
		SQLHANDLE insert_hStmt = hStmt_Insert;
		SQLHANDLE hDb_S = this->hDbc_source;
		SQLHANDLE hDb_T = hDbc_target;
		SQLHANDLE hEnvS = hEnv_Source;
		SQLHANDLE hEnvT = hEnv_Target;
		RETCODE r;

		r = ::SQLFreeHandle(SQL_HANDLE_STMT, hStmt_Fetch);
		r = ::SQLFreeHandle(SQL_HANDLE_STMT, hStmt_Insert);
		r = ::SQLFreeHandle(SQL_HANDLE_STMT, hStmt_Update);
		if (hDbc_source != SQL_NULL_HANDLE) 		r = ::SQLDisconnect(hDb_S);
		if (hDbc_target != SQL_NULL_HANDLE) 		r = ::SQLDisconnect(hDb_T);

		r = ::SQLFreeHandle(SQL_HANDLE_DBC, hDb_S);
		r = ::SQLFreeHandle(SQL_HANDLE_DBC, hDb_T);
		r = ::SQLFreeHandle(SQL_HANDLE_ENV, hEnvS);
		r = ::SQLFreeHandle(SQL_HANDLE_ENV, hEnvT);
	}

	hEnv_Source = SQL_NULL_HANDLE;
	hEnv_Target = SQL_NULL_HANDLE;
	hEnv_Source = SQL_NULL_HANDLE;
	hEnv_Target = SQL_NULL_HANDLE;
	hStmt_Fetch = SQL_NULL_HANDLE;
	hStmt_Insert = SQL_NULL_HANDLE;
	hStmt_Update = SQL_NULL_HANDLE;
}

void TK_LTDREC::open(const QString sourceDSN, const QString targetDSN)
{
	QLoggingCategory category("classLibQ");
	m_lpszTargetDSN = targetDSN;
	m_lpszSourceDSN = sourceDSN;
	qDebug(category) << QString("Source - %1[%2]").arg(sourceDSN);
	qDebug(category) << QString("Target - %1[%2]").arg(targetDSN);
}

void TK_LTDREC::createTable()
{
	QLoggingCategory category("classLibQ");
	{
		QScopedPointer<nvTableOracleRdb> tbl(new nvTableOracleRdb(nullptr));
		tbl->initialize("TK_LTDREC", this->m_lpszSourceDSN);
		QString newTbl = tbl->getCreateTableSQL();
		QScopedPointer<qVtExecute> vExec(new qVtExecute(nullptr));
		{
			vExec->initialize(m_lpszTargetDSN, " ", true);
			vExec->setOdbcAttributes(m_OdbcAttributes);
			vExec->ExecuteDirect(newTbl);
		}
	 qDebug(category) << QString("End Create Table %1 ").arg(tableName); 
	}
}

bool TK_LTDREC::prepare()
{
	RETCODE r;
	QString check;
	QLoggingCategory category("classLibQ");
	 qDebug(category) << fetchSql;
	 qDebug(category) << insertSql;
#ifdef UNICODE
	r = SQLPrepare(hStmt_Insert,toSQLTCHAR(insertSql).data(),(SQLINTEGER)insertSql.length()); 
	if (r != SQL_SUCCESS) {
		check = qWarnODBCHandle(SQL_HANDLE_STMT, hStmt_Insert);
		 qCCritical(category) << QString("Prepare Statement-Insert : %1 is %2").arg(insertSql).arg(check);
		return false; 
	}
	r = SQLPrepare(hStmt_Update,toSQLTCHAR(updateSql).data(),(SQLINTEGER)updateSql.length()); 
	if (r != SQL_SUCCESS) {
		check = qWarnODBCHandle(SQL_HANDLE_STMT, hStmt_Update);
		 qCCritical(category) << QString("Prepare Statement-Update : %1 is %2").arg(updateSql).arg(check);
		return false; 
	}
	r = SQLPrepare(hStmt_Fetch,toSQLTCHAR(fetchSql).data(),(SQLINTEGER)fetchSql.length());
	if (r != SQL_SUCCESS) {
		check = qWarnODBCHandle(SQL_HANDLE_STMT, hStmt_Fetch);
		 qCCritical(category) << QString("Prepare Statement-Insert : %1 is %2").arg(fetchSql).arg(check);
		return false; 
	}
#else
	QByteArray queryI8 = insertSql.toUtf8();
	r = SQLPrepare(insert_hStmt,SQLCHAR*)queryI8.data(),(SQLINTEGER)queryI8.length());
	QByteArray queryU8 = fetchSql.toUtf8();
	r = SQLPrepare(hStmt_Fetch,(SQLCHAR*)queryU8.data(),(SQLINTEGER)queryU8.length());
#endif
	return true;

}

void TK_LTDREC::prepareTargetTable()
{
	QLoggingCategory category("classLibQ");
	if (this->m_ReplicationOption == ReplicationOption::BulkCopy)
	{
		QScopedPointer<qVtExecute> execSql(new qVtExecute(nullptr));
		DropOption option = this->m_dropOption;
		switch (option)
		{
			case DropOption::DeleteFromTable:
			{
				QLoggingCategory category("classLibQ");
				execSql->initialize(this->m_lpszTargetDSN, "delete from TK_LTDREC", true);
				execSql->setOdbcAttributes(this->m_OdbcAttributes);
				execSql->ExecuteDirect("delete from TK_LTDREC");
			}break;
			case DropOption::TruncateTable:
			{
				execSql->initialize(this->m_lpszTargetDSN, "truncate table TK_LTDREC", true);
				execSql->setOdbcAttributes(this->m_OdbcAttributes);
				execSql->ExecuteDirect("truncate table TK_LTDREC");
			}break;
			case DropOption::DropTable:
			{
				execSql->initialize(this->m_lpszTargetDSN, "drop table TK_LTDREC", true);
				execSql->setOdbcAttributes(this->m_OdbcAttributes);
				execSql->ExecuteDirect("drop table TK_LTDREC");
				createTable();
			}break;
		}
	}
}

bool TK_LTDREC::bindColumn()
{
	QLoggingCategory category("classLibQ");
	RETCODE r;
	bool isValid=true;
		 qDebug(category) << " Bindings: Ordinal [1] Type: 5 Buffer Size: 2 FieldName: DB_ID ";
		r = ::SQLBindCol(hStmt_Fetch, 1, 5, DB_ID.data(), 2, &cbDB_ID);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Bindings: Ordinal [2] Type: 93 Buffer Size: 23 FieldName: NVTIMESTAMP ";
		r = ::SQLBindCol(hStmt_Fetch, 2, 93, NVTIMESTAMP.data(), 23, &cbNVTIMESTAMP);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Bindings: Ordinal [3] Type: 5 Buffer Size: 2 FieldName: AREA ";
		r = ::SQLBindCol(hStmt_Fetch, 3, 5, AREA.data(), 2, &cbAREA);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Bindings: Ordinal [4] Type: 4 Buffer Size: 4 FieldName: PAGE ";
		r = ::SQLBindCol(hStmt_Fetch, 4, 4, PAGE.data(), 4, &cbPAGE);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Bindings: Ordinal [5] Type: 5 Buffer Size: 2 FieldName: LINE ";
		r = ::SQLBindCol(hStmt_Fetch, 5, 5, LINE.data(), 2, &cbLINE);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Bindings: Ordinal [6] Type: 8 Buffer Size: 8 FieldName: TK_LTDISSQTY ";
		r = ::SQLBindCol(hStmt_Fetch, 6, 8, TK_LTDISSQTY.data(), 8, &cbTK_LTDISSQTY);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Bindings: Ordinal [7] Type: 4 Buffer Size: 4 FieldName: TK_LTDDAT ";
		r = ::SQLBindCol(hStmt_Fetch, 7, 4, TK_LTDDAT.data(), 4, &cbTK_LTDDAT);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Bindings: Ordinal [8] Type: 1 Buffer Size: 6 FieldName: TK_LTDCMD ";
		r = ::SQLBindCol(hStmt_Fetch, 8, 1, TK_LTDCMD.data(), 6, &cbTK_LTDCMD);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Bindings: Ordinal [9] Type: 5 Buffer Size: 2 FieldName: TK_LTDARCFLG ";
		r = ::SQLBindCol(hStmt_Fetch, 9, 5, TK_LTDARCFLG.data(), 2, &cbTK_LTDARCFLG);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Bindings: Ordinal [10] Type: 1 Buffer Size: 24 FieldName: TK_LTPLOT ";
		r = ::SQLBindCol(hStmt_Fetch, 10, 1, TK_LTPLOT.data(), 24, &cbTK_LTPLOT);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Bindings: Ordinal [11] Type: 1 Buffer Size: 24 FieldName: TK_LTPLOT15 ";
		r = ::SQLBindCol(hStmt_Fetch, 11, 1, TK_LTPLOT15.data(), 24, &cbTK_LTPLOT15);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
	return isValid;
}

bool TK_LTDREC::bindParameter()
{
	QLoggingCategory category("classLibQ");
	RETCODE r;
	bool isValid=true;
	{
		 qDebug(category) << " Parameters: Ordinal [1] Type: 5 Buffer Size: 2 FieldName: DB_ID ";
		r = SQLBindParameter(hStmt_Insert, 1, SQL_PARAM_INPUT, SQL_C_DEFAULT, 5, 0, 0, (SQLPOINTER)DB_ID.constData(), 0, &cbDB_ID);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Parameters: Ordinal [2] Type: 93 Buffer Size: 23 FieldName: NVTIMESTAMP ";
		r = SQLBindParameter(hStmt_Insert, 2, SQL_PARAM_INPUT, SQL_C_DEFAULT, 93, 23, 0, (SQLPOINTER)NVTIMESTAMP.constData(), 0, &cbNVTIMESTAMP);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Parameters: Ordinal [3] Type: 5 Buffer Size: 2 FieldName: AREA ";
		r = SQLBindParameter(hStmt_Insert, 3, SQL_PARAM_INPUT, SQL_C_DEFAULT, 5, 0, 0, (SQLPOINTER)AREA.constData(), 0, &cbAREA);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Parameters: Ordinal [4] Type: 4 Buffer Size: 4 FieldName: PAGE ";
		r = SQLBindParameter(hStmt_Insert, 4, SQL_PARAM_INPUT, SQL_C_DEFAULT, 4, 0, 0, (SQLPOINTER)PAGE.constData(), 0, &cbPAGE);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Parameters: Ordinal [5] Type: 5 Buffer Size: 2 FieldName: LINE ";
		r = SQLBindParameter(hStmt_Insert, 5, SQL_PARAM_INPUT, SQL_C_DEFAULT, 5, 0, 0, (SQLPOINTER)LINE.constData(), 0, &cbLINE);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Parameters: Ordinal [6] Type: 8 Buffer Size: 8 FieldName: TK_LTDISSQTY ";
		r = SQLBindParameter(hStmt_Insert, 6, SQL_PARAM_INPUT, SQL_C_DEFAULT, 8, 0, 0, (SQLPOINTER)TK_LTDISSQTY.constData(), 0, &cbTK_LTDISSQTY);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Parameters: Ordinal [7] Type: 4 Buffer Size: 4 FieldName: TK_LTDDAT ";
		r = SQLBindParameter(hStmt_Insert, 7, SQL_PARAM_INPUT, SQL_C_DEFAULT, 4, 0, 0, (SQLPOINTER)TK_LTDDAT.constData(), 0, &cbTK_LTDDAT);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Parameters: Ordinal [8] Type: 1 Buffer Size: 6 FieldName: TK_LTDCMD ";
		r = SQLBindParameter(hStmt_Insert, 8, SQL_PARAM_INPUT, SQL_C_DEFAULT, 1, 6, 0, (SQLPOINTER)TK_LTDCMD.constData(), 0, &cbTK_LTDCMD);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Parameters: Ordinal [9] Type: 5 Buffer Size: 2 FieldName: TK_LTDARCFLG ";
		r = SQLBindParameter(hStmt_Insert, 9, SQL_PARAM_INPUT, SQL_C_DEFAULT, 5, 0, 0, (SQLPOINTER)TK_LTDARCFLG.constData(), 0, &cbTK_LTDARCFLG);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Parameters: Ordinal [10] Type: 1 Buffer Size: 24 FieldName: TK_LTPLOT ";
		r = SQLBindParameter(hStmt_Insert, 10, SQL_PARAM_INPUT, SQL_C_DEFAULT, 1, 24, 0, (SQLPOINTER)TK_LTPLOT.constData(), 0, &cbTK_LTPLOT);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Parameters: Ordinal [11] Type: 1 Buffer Size: 24 FieldName: TK_LTPLOT15 ";
		r = SQLBindParameter(hStmt_Insert, 11, SQL_PARAM_INPUT, SQL_C_DEFAULT, 1, 24, 0, (SQLPOINTER)TK_LTPLOT15.constData(), 0, &cbTK_LTPLOT15);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
	}
	if (m_ReplicationOption == ReplicationOption::NetChange)
	{
		r = SQLBindParameter(hStmt_Update, 12, SQL_PARAM_INPUT, SQL_C_DEFAULT, 3, 0, 0, (SQLPOINTER)AREA.constData(), 0, &cbAREA);
		if (r == SQL_SUCCESS) { isValid=true; }
		r = SQLBindParameter(hStmt_Update, 13, SQL_PARAM_INPUT, SQL_C_DEFAULT, 4, 0, 0, (SQLPOINTER)PAGE.constData(), 0, &cbPAGE);
		if (r == SQL_SUCCESS) { isValid=true; }
		r = SQLBindParameter(hStmt_Update, 14, SQL_PARAM_INPUT, SQL_C_DEFAULT, 5, 0, 0, (SQLPOINTER)LINE.constData(), 0, &cbLINE);
		if (r == SQL_SUCCESS) { isValid=true; }
	// TK_LTDREC is a well formed table for eNVy Replication 
		 qDebug(category) << " Parameters: Ordinal [3] 00 00 FieldName: AREA ";
		 qDebug(category) << " Parameters: Ordinal [4] 00 00  FieldName: PAGE ";
		 qDebug(category) << " Parameters: Ordinal [5] 00 00 FieldName:  LINE ";
	} // 	if (m_ReplicationOption == ReplicationOption::NetChange)
	return isValid;
}

bool TK_LTDREC::process(int rowSize)
{
	QLoggingCategory category("classLibQ");
	initOdbcAttributes();
	connect(Source);
	connect(Target);
	initialize();
	prepareTargetTable();
	prepare();
	bindColumn();
	bindParameter();
	copyTable();
	close();
	return false;
}

void TK_LTDREC::copyTable()
{
	QLoggingCategory category("classLibQ");
	RETCODE r;
	QString check;
	r = SQLExecute(hStmt_Fetch);
		if (bIsAbort) {
			emit aborted(tableName, rowsFetched, rowsInserted, rowsUpdated);
			return;
		}
		while((r = SQLFetch(hStmt_Fetch)) != SQL_NO_DATA) {
		if (r != SQL_SUCCESS) {
			check = qWarnODBCHandle(SQL_HANDLE_STMT, hStmt_Fetch);
			qCCritical(category) << QString("SqlFetch - Error : %1 is %2").arg(fetchSql).arg(check);
			return;
		} 
		rowsFetched++;
		if (m_ReplicationOption == ReplicationOption::BulkCopy)
		{
			r = SQLExecute(hStmt_Insert);
			if (r == SQL_ERROR) {
				check = qWarnODBCHandle(SQL_HANDLE_STMT, hStmt_Insert);
				 qCCritical(category) << QString("SqlExecute:Insert - Error : %1 is %2").arg(insertSql).arg(check);
				return;
			}
			rowsInserted++;
			if ((rowsFetched % updateInterval) == 0) {
				qCInfo(category) << QString("[%1.%2]	Insertion: %3	Updates : %4	Fetched : %5").arg(profileName).arg(tableName).arg(rowsInserted).arg(rowsUpdated).arg(rowsFetched);
				emit updateStatusFetched(profileName, tableName, rowsFetched,rowsInserted,rowsUpdated);
			}
			if (m_ReplicationOption == ReplicationOption::NetChange)
			{
			r = SQLExecute(hStmt_Update);
			if (r != SQL_SUCCESS) {
				check = qWarnODBCHandle(SQL_HANDLE_STMT, hStmt_Update);
				 qCInfo(category)  << QString("SqlExecute:Update - Error : %1 is %2").arg(updateSql).arg(check);
				r = SQLExecute(hStmt_Insert);
				if (r != SQL_SUCCESS) {
					check = qWarnODBCHandle(SQL_HANDLE_STMT, hStmt_Insert);
					 qCritical(category) << QString("SqlExecute:Insert - Error : %1 is %2").arg(insertSql).arg(check);
					return;
				}
				else 	rowsInserted++;
				}
				else	rowsUpdated++;
			}
			emit updateStatusFetched(profileName, tableName, rowsFetched,rowsInserted,rowsUpdated);
		}
	} 
qCInfo(category) << QString("[%1.%2]	Insertion: %3	Updates : %4	Fetched : %5").arg(profileName).arg(tableName).arg(rowsInserted).arg(rowsUpdated).arg(rowsFetched);
}

void TK_LTDREC::connect(connectionHandle connectionSource)
{

	QLoggingCategory category("classLibQ");
	RETCODE r;

	bool isValid = false;
	HWND	hWnd = nullptr;
	hWnd = ::GetDesktopWindow(); 
	SQLSMALLINT nResult = 0;

	SQLSMALLINT cb;
	UWORD wConnectOption = SQL_DRIVER_COMPLETE; //SQL_DRIVER_NOPROMPT;
	QVarLengthArray<SQLTCHAR> connOut(1024);
	memset(connOut.data(), 0, connOut.size() * sizeof(SQLTCHAR));

	switch (connectionSource)
	{
		case Source:
			{// environment
				SQLHANDLE hEnv = SQL_NULL_HANDLE;
				SQLHANDLE hDbc = SQL_NULL_HANDLE;
				r = ::SQLAllocHandle(SQL_HANDLE_ENV, SQL_NULL_HANDLE, &hEnv);
				if (r == SQL_SUCCESS) isValid = true;

				foreach(nOdbcAttributesClass * k, this->m_OdbcAttributes_Map)
				{
					if (k->attributeType == enumAttributeType::hEnv)
					{
						r = ::SQLSetEnvAttr(hEnv, (SQLINTEGER) k->odbcKey, (SQLPOINTER)k->odbcValue, 0);
						if (r == SQL_SUCCESS) isValid = true;
					}
				}
				hEnv_Source = hEnv;

				r = SQLAllocHandle(SQL_HANDLE_DBC, hEnv, &hDbc);
				if (r == SQL_SUCCESS) isValid = true;
				foreach(nOdbcAttributesClass * k, this->m_OdbcAttributes_Map)
				{
					if (k->attributeType == enumAttributeType::hDbc)
					{
					r = ::SQLSetConnectAttr(hDbc, k->odbcKey, (SQLPOINTER)k->odbcValue, 0);
					if (k->odbcKey == SQL_ATTR_CONNECTION_POOLING && k->odbcValue == SQL_CP_ONE_PER_DRIVER) wConnectOption = SQL_DRIVER_NOPROMPT;
					if (k->odbcKey == SQL_ATTR_CONNECTION_POOLING && k->odbcValue == SQL_CP_ONE_PER_HENV) wConnectOption = SQL_DRIVER_NOPROMPT;
					if (k->odbcKey == SQL_ATTR_CONNECTION_POOLING && k->odbcValue == SQL_CP_DRIVER_AWARE) wConnectOption = SQL_DRIVER_NOPROMPT;
					if (r == SQL_SUCCESS) isValid = true;
					}
				}
				hDbc_source = hDbc;
				if (isValid)
				{
					r = ::SQLDriverConnect(
						hDbc,
						hWnd,
#ifdef UNICODE
						toSQLTCHAR(m_lpszSourceDSN).data(),
#else
						(SQLCHAR*)dsnSource.toUtf8().data(),
#endif
						(SQLSMALLINT)m_lpszSourceDSN.length(),
						connOut.data(),
						1024,
						&cb, 
						wConnectOption); 
					int colSize = cb / sizeof(SQLTCHAR);
					if (r != SQL_SUCCESS && r != SQL_SUCCESS_WITH_INFO)
					{
						QString check = qWarnODBCHandle(SQL_HANDLE_DBC, hDbc);
						qCritical(category) <<  check;
						m_bIsOpen = false;
					}
					m_bIsOpen = true;
				}
			} break;
		case Target:
			{
				SQLHANDLE hEnv = SQL_NULL_HANDLE;
				SQLHANDLE hDbc = SQL_NULL_HANDLE;
				r = ::SQLAllocHandle(SQL_HANDLE_ENV, SQL_NULL_HANDLE, &hEnv);
				if (r == SQL_SUCCESS) isValid = true;

				foreach(nOdbcAttributesClass * k, this->m_OdbcAttributes_Map)
				{
					if (k->attributeType == enumAttributeType::hEnv)
					{
						r = ::SQLSetEnvAttr(hEnv, (SQLINTEGER) k->odbcKey, (SQLPOINTER)k->odbcValue, 0);
						if (r == SQL_SUCCESS) isValid = true;
					}
				}
				hEnv_Target = hEnv;

				r = SQLAllocHandle(SQL_HANDLE_DBC, hEnv, &hDbc);
				if (r == SQL_SUCCESS) isValid = true;
				foreach(nOdbcAttributesClass * k, this->m_OdbcAttributes_Map)
				{
				if (k->attributeType == enumAttributeType::hDbc)
					{
					r = ::SQLSetConnectAttr(hDbc, k->odbcKey, (SQLPOINTER)k->odbcValue, 0);
					if (k->odbcKey == SQL_ATTR_CONNECTION_POOLING && k->odbcValue == SQL_CP_ONE_PER_DRIVER) wConnectOption = SQL_DRIVER_NOPROMPT;
					if (k->odbcKey == SQL_ATTR_CONNECTION_POOLING && k->odbcValue == SQL_CP_ONE_PER_HENV) wConnectOption = SQL_DRIVER_NOPROMPT;
					if (k->odbcKey == SQL_ATTR_CONNECTION_POOLING && k->odbcValue == SQL_CP_DRIVER_AWARE) wConnectOption = SQL_DRIVER_NOPROMPT;
					if (r == SQL_SUCCESS) isValid = true;
					}
				}
				hDbc_target = hDbc;
				if (isValid) {
					r = ::SQLDriverConnect(
						hDbc,
						hWnd,
#ifdef UNICODE
						toSQLTCHAR(m_lpszTargetDSN).data(),
#else
						(SQLCHAR*)m_lpszTargetDSN.toUtf8().data(),
#endif
						(SQLSMALLINT)m_lpszTargetDSN.length(),
						connOut.data(),
						1024,
						&cb, 
						wConnectOption); 
						int colSize = cb / sizeof(SQLTCHAR);
					if (r != SQL_SUCCESS && r != SQL_SUCCESS_WITH_INFO)
						{
							QString check = qWarnODBCHandle(SQL_HANDLE_DBC, hDbc);
							qCritical(category) <<  check;
							m_bIsOpen = false;
						}
							m_bIsOpen = true;
					}
			} break;
			default: break;
	}
}
TK_HDRHSHSET::TK_HDRHSHSET(QObject * parent) : QObject(parent) 
,tableName("TK_HDRHSHSET")
,m_dropOption(DropOption::DropTable) { 
	numRowsFetched = 0;
}

#pragma region ~CTOR TK_HDRHSHSET 
TK_HDRHSHSET::~TK_HDRHSHSET() { 

#pragma region Buffers - Clear 
	DB_ID.clear();
	NVTIMESTAMP.clear();
	OAREA.clear();
	OPAGE.clear();
	OLINE.clear();
	MAREA.clear();
	MPAGE.clear();
	MLINE.clear();
#pragma endregion Buffers - Clear 
}
#pragma endregion Destructor_TK_HDRHSHSET

// begin method functions
void TK_HDRHSHSET::setAbortFlag() { 
	QLoggingCategory category("classLibQ");
	qCInfo(category) << "isAbort was set to True";
	bIsAbort = true;
}

void TK_HDRHSHSET::run() { 
	process(1);
	QLoggingCategory category("classLibQ");
	qDebug(category) << "Entered;";
}

void	TK_HDRHSHSET::initOdbcAttributes()
{
	QLoggingCategory category("classLibQ");
	this->setProfileName(profileName);
	qDebug(category) << "Processing - TRKDB100"; 
	m_OdbcAttributesList = m_OdbcAttributes.split(","); 
	foreach(QString m, m_OdbcAttributesList)
	{
		QStringList keyValue = m.split("=");
		nOdbcAttributesClass * oM = new nOdbcAttributesClass(this);
		if (oM->loadToOdbc(keyValue.value(0), keyValue.value(1)))
		{
			m_OdbcAttributes_Map.insert(oM->odbcKey, oM);
		}
	}
}
void	TK_HDRHSHSET::initialize()
{
	QLoggingCategory category("classLibQ");
	RETCODE r;
	this->setProfileName(profileName);
	qDebug(category) << "Processing - TRKDB100"; 
//SQL Statements
//--------------------------------------------------

#pragma region Sql Statements_TK_HDRHSHSET

	fetchSql = "select  DB_ID, NVTIMESTAMP, OAREA, OPAGE, OLINE, MAREA, MPAGE, MLINE from TK_HDRHSHSET";
		if (m_ReplicationOption == ReplicationOption::NetChange)
		{
			fetchSql.append(" p1, nv_transfers p2 WHERE  p2.table_name = 'TK_HDRHSHSET' AND p1.nvtimestamp > p2.last_completed");
		}
	insertSql = "insert into TK_HDRHSHSET ( PLANT_CODE, NVTIMESTAMP, OAREA, OPAGE, OLINE, MAREA, MPAGE, MLINE ) values ( ?, ?, ?, ?, ?, ?, ?, ?)";
	updateSql = "update TK_HDRHSHSET set  PLANT_CODE = ?, NVTIMESTAMP = ?, OAREA = ?, OPAGE = ?, OLINE = ?, MAREA = ?, MPAGE = ?, MLINE = ?  where area = ? and page = ? line = ? ";

	qDebug(category) << "insertSQL - insert into TK_HDRHSHSET ( PLANT_CODE, NVTIMESTAMP, OAREA, OPAGE, OLINE, MAREA, MPAGE, MLINE ) values ( ?, ?, ?, ?, ?, ?, ?, ?)";
	qDebug(category) << "fetchSQL - select  DB_ID, NVTIMESTAMP, OAREA, OPAGE, OLINE, MAREA, MPAGE, MLINE from TK_HDRHSHSET";
	qDebug(category) << "unsertSQL - update TK_HDRHSHSET set  PLANT_CODE = ?, NVTIMESTAMP = ?, OAREA = ?, OPAGE = ?, OLINE = ?, MAREA = ?, MPAGE = ?, MLINE = ?  where area = ? and page = ? line = ? ";

#pragma endregion Sql Statements_TK_HDRHSHSET
	SQLHANDLE		insert_hStmt = SQL_NULL_HANDLE;
	SQLHANDLE		fetch_hStmt = SQL_NULL_HANDLE; 
	SQLHANDLE		update_hStmt = SQL_NULL_HANDLE; 
 
	r = ::SQLAllocHandle(SQL_HANDLE_STMT, hDbc_source, &fetch_hStmt);
	if (r != SQL_SUCCESS) {
		 qCCritical(category) << QString("Error  hDbc_Source SQLCode : %1 is %2").arg(QString::number( (long)hDbc_source)).arg(QString::number(r));
		return; 
	}
	r = ::SQLAllocHandle(SQL_HANDLE_STMT, hDbc_target, &insert_hStmt);
	if (r != SQL_SUCCESS) {
		 qCCritical(category) << QString("Error hDbc_Source -SQLCode: %1 is %2").arg(QString::number( (long)hDbc_target)).arg(QString::number(r));
		return; 
	}
	r = ::SQLAllocHandle(SQL_HANDLE_STMT, hDbc_target, &update_hStmt);
	if (r != SQL_SUCCESS) {
		 qCCritical(category) << QString("Error hDbc_Source +SQLCode: %1 is %2").arg(QString::number( (long)hDbc_target)).arg(QString::number(r));
		return; 
	}
 
	hStmt_Fetch = fetch_hStmt;
	hStmt_Insert = insert_hStmt;
	hStmt_Update = update_hStmt;
 
	SQLSetStmtAttr(hStmt_Fetch, SQL_ATTR_USE_BOOKMARKS, (SQLPOINTER)SQL_UB_OFF, 0);
	SQLSetStmtAttr(hStmt_Fetch, SQL_ATTR_ROW_BIND_TYPE, (SQLPOINTER)SQL_BIND_BY_COLUMN, 0);
	SQLSetStmtAttr(hStmt_Fetch, SQL_ATTR_ROW_ARRAY_SIZE, (SQLPOINTER)1, 0);
	SQLSetStmtAttr(hStmt_Fetch, SQL_ATTR_ROWS_FETCHED_PTR, &numRowsFetched, 0);

// Fields used by this class 
// ---------------------------------------------------

#pragma region Resize Fields TK_HDRHSHSET
	qDebug(category) << "Malloc - DB_ID[2]";
	DB_ID.resize(2);
	qDebug(category) << "Malloc - NVTIMESTAMP[23]";
	NVTIMESTAMP.resize(23);
	qDebug(category) << "Malloc - OAREA[2]";
	OAREA.resize(2);
	qDebug(category) << "Malloc - OPAGE[4]";
	OPAGE.resize(4);
	qDebug(category) << "Malloc - OLINE[2]";
	OLINE.resize(2);
	qDebug(category) << "Malloc - MAREA[2]";
	MAREA.resize(2);
	qDebug(category) << "Malloc - MPAGE[4]";
	MPAGE.resize(4);
	qDebug(category) << "Malloc - MLINE[2]";
	MLINE.resize(2);

#pragma endregion Resize Fields TK_HDRHSHSET
}
void TK_HDRHSHSET::close()
{
	QLoggingCategory category("classLibQ");
	if (m_bIsOpen)
	{
	qDebug(category) << "database is Open";
		SQLHANDLE source_hStmt = hStmt_Fetch;
		SQLHANDLE insert_hStmt = hStmt_Insert;
		SQLHANDLE hDb_S = this->hDbc_source;
		SQLHANDLE hDb_T = hDbc_target;
		SQLHANDLE hEnvS = hEnv_Source;
		SQLHANDLE hEnvT = hEnv_Target;
		RETCODE r;

		r = ::SQLFreeHandle(SQL_HANDLE_STMT, hStmt_Fetch);
		r = ::SQLFreeHandle(SQL_HANDLE_STMT, hStmt_Insert);
		r = ::SQLFreeHandle(SQL_HANDLE_STMT, hStmt_Update);
		if (hDbc_source != SQL_NULL_HANDLE) 		r = ::SQLDisconnect(hDb_S);
		if (hDbc_target != SQL_NULL_HANDLE) 		r = ::SQLDisconnect(hDb_T);

		r = ::SQLFreeHandle(SQL_HANDLE_DBC, hDb_S);
		r = ::SQLFreeHandle(SQL_HANDLE_DBC, hDb_T);
		r = ::SQLFreeHandle(SQL_HANDLE_ENV, hEnvS);
		r = ::SQLFreeHandle(SQL_HANDLE_ENV, hEnvT);
	}

	hEnv_Source = SQL_NULL_HANDLE;
	hEnv_Target = SQL_NULL_HANDLE;
	hEnv_Source = SQL_NULL_HANDLE;
	hEnv_Target = SQL_NULL_HANDLE;
	hStmt_Fetch = SQL_NULL_HANDLE;
	hStmt_Insert = SQL_NULL_HANDLE;
	hStmt_Update = SQL_NULL_HANDLE;
}

void TK_HDRHSHSET::open(const QString sourceDSN, const QString targetDSN)
{
	QLoggingCategory category("classLibQ");
	m_lpszTargetDSN = targetDSN;
	m_lpszSourceDSN = sourceDSN;
	qDebug(category) << QString("Source - %1[%2]").arg(sourceDSN);
	qDebug(category) << QString("Target - %1[%2]").arg(targetDSN);
}

void TK_HDRHSHSET::createTable()
{
	QLoggingCategory category("classLibQ");
	{
		QScopedPointer<nvTableOracleRdb> tbl(new nvTableOracleRdb(nullptr));
		tbl->initialize("TK_HDRHSHSET", this->m_lpszSourceDSN);
		QString newTbl = tbl->getCreateTableSQL();
		QScopedPointer<qVtExecute> vExec(new qVtExecute(nullptr));
		{
			vExec->initialize(m_lpszTargetDSN, " ", true);
			vExec->setOdbcAttributes(m_OdbcAttributes);
			vExec->ExecuteDirect(newTbl);
		}
	 qDebug(category) << QString("End Create Table %1 ").arg(tableName); 
	}
}

bool TK_HDRHSHSET::prepare()
{
	RETCODE r;
	QString check;
	QLoggingCategory category("classLibQ");
	 qDebug(category) << fetchSql;
	 qDebug(category) << insertSql;
#ifdef UNICODE
	r = SQLPrepare(hStmt_Insert,toSQLTCHAR(insertSql).data(),(SQLINTEGER)insertSql.length()); 
	if (r != SQL_SUCCESS) {
		check = qWarnODBCHandle(SQL_HANDLE_STMT, hStmt_Insert);
		 qCCritical(category) << QString("Prepare Statement-Insert : %1 is %2").arg(insertSql).arg(check);
		return false; 
	}
	r = SQLPrepare(hStmt_Update,toSQLTCHAR(updateSql).data(),(SQLINTEGER)updateSql.length()); 
	if (r != SQL_SUCCESS) {
		check = qWarnODBCHandle(SQL_HANDLE_STMT, hStmt_Update);
		 qCCritical(category) << QString("Prepare Statement-Update : %1 is %2").arg(updateSql).arg(check);
		return false; 
	}
	r = SQLPrepare(hStmt_Fetch,toSQLTCHAR(fetchSql).data(),(SQLINTEGER)fetchSql.length());
	if (r != SQL_SUCCESS) {
		check = qWarnODBCHandle(SQL_HANDLE_STMT, hStmt_Fetch);
		 qCCritical(category) << QString("Prepare Statement-Insert : %1 is %2").arg(fetchSql).arg(check);
		return false; 
	}
#else
	QByteArray queryI8 = insertSql.toUtf8();
	r = SQLPrepare(insert_hStmt,SQLCHAR*)queryI8.data(),(SQLINTEGER)queryI8.length());
	QByteArray queryU8 = fetchSql.toUtf8();
	r = SQLPrepare(hStmt_Fetch,(SQLCHAR*)queryU8.data(),(SQLINTEGER)queryU8.length());
#endif
	return true;

}

void TK_HDRHSHSET::prepareTargetTable()
{
	QLoggingCategory category("classLibQ");
	if (this->m_ReplicationOption == ReplicationOption::BulkCopy)
	{
		QScopedPointer<qVtExecute> execSql(new qVtExecute(nullptr));
		DropOption option = this->m_dropOption;
		switch (option)
		{
			case DropOption::DeleteFromTable:
			{
				QLoggingCategory category("classLibQ");
				execSql->initialize(this->m_lpszTargetDSN, "delete from TK_HDRHSHSET", true);
				execSql->setOdbcAttributes(this->m_OdbcAttributes);
				execSql->ExecuteDirect("delete from TK_HDRHSHSET");
			}break;
			case DropOption::TruncateTable:
			{
				execSql->initialize(this->m_lpszTargetDSN, "truncate table TK_HDRHSHSET", true);
				execSql->setOdbcAttributes(this->m_OdbcAttributes);
				execSql->ExecuteDirect("truncate table TK_HDRHSHSET");
			}break;
			case DropOption::DropTable:
			{
				execSql->initialize(this->m_lpszTargetDSN, "drop table TK_HDRHSHSET", true);
				execSql->setOdbcAttributes(this->m_OdbcAttributes);
				execSql->ExecuteDirect("drop table TK_HDRHSHSET");
				createTable();
			}break;
		}
	}
}

bool TK_HDRHSHSET::bindColumn()
{
	QLoggingCategory category("classLibQ");
	RETCODE r;
	bool isValid=true;
		 qDebug(category) << " Bindings: Ordinal [1] Type: 5 Buffer Size: 2 FieldName: DB_ID ";
		r = ::SQLBindCol(hStmt_Fetch, 1, 5, DB_ID.data(), 2, &cbDB_ID);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Bindings: Ordinal [2] Type: 93 Buffer Size: 23 FieldName: NVTIMESTAMP ";
		r = ::SQLBindCol(hStmt_Fetch, 2, 93, NVTIMESTAMP.data(), 23, &cbNVTIMESTAMP);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Bindings: Ordinal [3] Type: 5 Buffer Size: 2 FieldName: OAREA ";
		r = ::SQLBindCol(hStmt_Fetch, 3, 5, OAREA.data(), 2, &cbOAREA);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Bindings: Ordinal [4] Type: 4 Buffer Size: 4 FieldName: OPAGE ";
		r = ::SQLBindCol(hStmt_Fetch, 4, 4, OPAGE.data(), 4, &cbOPAGE);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Bindings: Ordinal [5] Type: 5 Buffer Size: 2 FieldName: OLINE ";
		r = ::SQLBindCol(hStmt_Fetch, 5, 5, OLINE.data(), 2, &cbOLINE);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Bindings: Ordinal [6] Type: 5 Buffer Size: 2 FieldName: MAREA ";
		r = ::SQLBindCol(hStmt_Fetch, 6, 5, MAREA.data(), 2, &cbMAREA);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Bindings: Ordinal [7] Type: 4 Buffer Size: 4 FieldName: MPAGE ";
		r = ::SQLBindCol(hStmt_Fetch, 7, 4, MPAGE.data(), 4, &cbMPAGE);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Bindings: Ordinal [8] Type: 5 Buffer Size: 2 FieldName: MLINE ";
		r = ::SQLBindCol(hStmt_Fetch, 8, 5, MLINE.data(), 2, &cbMLINE);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
	return isValid;
}

bool TK_HDRHSHSET::bindParameter()
{
	QLoggingCategory category("classLibQ");
	RETCODE r;
	bool isValid=true;
	{
		 qDebug(category) << " Parameters: Ordinal [1] Type: 5 Buffer Size: 2 FieldName: DB_ID ";
		r = SQLBindParameter(hStmt_Insert, 1, SQL_PARAM_INPUT, SQL_C_DEFAULT, 5, 0, 0, (SQLPOINTER)DB_ID.constData(), 0, &cbDB_ID);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Parameters: Ordinal [2] Type: 93 Buffer Size: 23 FieldName: NVTIMESTAMP ";
		r = SQLBindParameter(hStmt_Insert, 2, SQL_PARAM_INPUT, SQL_C_DEFAULT, 93, 23, 0, (SQLPOINTER)NVTIMESTAMP.constData(), 0, &cbNVTIMESTAMP);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Parameters: Ordinal [3] Type: 5 Buffer Size: 2 FieldName: OAREA ";
		r = SQLBindParameter(hStmt_Insert, 3, SQL_PARAM_INPUT, SQL_C_DEFAULT, 5, 0, 0, (SQLPOINTER)OAREA.constData(), 0, &cbOAREA);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Parameters: Ordinal [4] Type: 4 Buffer Size: 4 FieldName: OPAGE ";
		r = SQLBindParameter(hStmt_Insert, 4, SQL_PARAM_INPUT, SQL_C_DEFAULT, 4, 0, 0, (SQLPOINTER)OPAGE.constData(), 0, &cbOPAGE);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Parameters: Ordinal [5] Type: 5 Buffer Size: 2 FieldName: OLINE ";
		r = SQLBindParameter(hStmt_Insert, 5, SQL_PARAM_INPUT, SQL_C_DEFAULT, 5, 0, 0, (SQLPOINTER)OLINE.constData(), 0, &cbOLINE);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Parameters: Ordinal [6] Type: 5 Buffer Size: 2 FieldName: MAREA ";
		r = SQLBindParameter(hStmt_Insert, 6, SQL_PARAM_INPUT, SQL_C_DEFAULT, 5, 0, 0, (SQLPOINTER)MAREA.constData(), 0, &cbMAREA);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Parameters: Ordinal [7] Type: 4 Buffer Size: 4 FieldName: MPAGE ";
		r = SQLBindParameter(hStmt_Insert, 7, SQL_PARAM_INPUT, SQL_C_DEFAULT, 4, 0, 0, (SQLPOINTER)MPAGE.constData(), 0, &cbMPAGE);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Parameters: Ordinal [8] Type: 5 Buffer Size: 2 FieldName: MLINE ";
		r = SQLBindParameter(hStmt_Insert, 8, SQL_PARAM_INPUT, SQL_C_DEFAULT, 5, 0, 0, (SQLPOINTER)MLINE.constData(), 0, &cbMLINE);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
	}
	if (m_ReplicationOption == ReplicationOption::NetChange)
	{
		r = SQLBindParameter(hStmt_Update, 9, SQL_PARAM_INPUT, SQL_C_DEFAULT, 6, 0, 0, (SQLPOINTER)MAREA.constData(), 0, &cbMAREA);
		if (r == SQL_SUCCESS) { isValid=true; }
		r = SQLBindParameter(hStmt_Update, 10, SQL_PARAM_INPUT, SQL_C_DEFAULT, 7, 0, 0, (SQLPOINTER)MPAGE.constData(), 0, &cbMPAGE);
		if (r == SQL_SUCCESS) { isValid=true; }
		r = SQLBindParameter(hStmt_Update, 11, SQL_PARAM_INPUT, SQL_C_DEFAULT, 8, 0, 0, (SQLPOINTER)MLINE.constData(), 0, &cbMLINE);
		if (r == SQL_SUCCESS) { isValid=true; }
	// TK_HDRHSHSET is a well formed table for eNVy Replication 
		 qDebug(category) << " Parameters: Ordinal [6] 00 00 FieldName: MAREA ";
		 qDebug(category) << " Parameters: Ordinal [7] 00 00  FieldName: MPAGE ";
		 qDebug(category) << " Parameters: Ordinal [8] 00 00 FieldName:  MLINE ";
	} // 	if (m_ReplicationOption == ReplicationOption::NetChange)
	return isValid;
}

bool TK_HDRHSHSET::process(int rowSize)
{
	QLoggingCategory category("classLibQ");
	initOdbcAttributes();
	connect(Source);
	connect(Target);
	initialize();
	prepareTargetTable();
	prepare();
	bindColumn();
	bindParameter();
	copyTable();
	close();
	return false;
}

void TK_HDRHSHSET::copyTable()
{
	QLoggingCategory category("classLibQ");
	RETCODE r;
	QString check;
	r = SQLExecute(hStmt_Fetch);
		if (bIsAbort) {
			emit aborted(tableName, rowsFetched, rowsInserted, rowsUpdated);
			return;
		}
		while((r = SQLFetch(hStmt_Fetch)) != SQL_NO_DATA) {
		if (r != SQL_SUCCESS) {
			check = qWarnODBCHandle(SQL_HANDLE_STMT, hStmt_Fetch);
			qCCritical(category) << QString("SqlFetch - Error : %1 is %2").arg(fetchSql).arg(check);
			return;
		} 
		rowsFetched++;
		if (m_ReplicationOption == ReplicationOption::BulkCopy)
		{
			r = SQLExecute(hStmt_Insert);
			if (r == SQL_ERROR) {
				check = qWarnODBCHandle(SQL_HANDLE_STMT, hStmt_Insert);
				 qCCritical(category) << QString("SqlExecute:Insert - Error : %1 is %2").arg(insertSql).arg(check);
				return;
			}
			rowsInserted++;
			if ((rowsFetched % updateInterval) == 0) {
				qCInfo(category) << QString("[%1.%2]	Insertion: %3	Updates : %4	Fetched : %5").arg(profileName).arg(tableName).arg(rowsInserted).arg(rowsUpdated).arg(rowsFetched);
				emit updateStatusFetched(profileName, tableName, rowsFetched,rowsInserted,rowsUpdated);
			}
			if (m_ReplicationOption == ReplicationOption::NetChange)
			{
			r = SQLExecute(hStmt_Update);
			if (r != SQL_SUCCESS) {
				check = qWarnODBCHandle(SQL_HANDLE_STMT, hStmt_Update);
				 qCInfo(category)  << QString("SqlExecute:Update - Error : %1 is %2").arg(updateSql).arg(check);
				r = SQLExecute(hStmt_Insert);
				if (r != SQL_SUCCESS) {
					check = qWarnODBCHandle(SQL_HANDLE_STMT, hStmt_Insert);
					 qCritical(category) << QString("SqlExecute:Insert - Error : %1 is %2").arg(insertSql).arg(check);
					return;
				}
				else 	rowsInserted++;
				}
				else	rowsUpdated++;
			}
			emit updateStatusFetched(profileName, tableName, rowsFetched,rowsInserted,rowsUpdated);
		}
	} 
qCInfo(category) << QString("[%1.%2]	Insertion: %3	Updates : %4	Fetched : %5").arg(profileName).arg(tableName).arg(rowsInserted).arg(rowsUpdated).arg(rowsFetched);
}

void TK_HDRHSHSET::connect(connectionHandle connectionSource)
{

	QLoggingCategory category("classLibQ");
	RETCODE r;

	bool isValid = false;
	HWND	hWnd = nullptr;
	hWnd = ::GetDesktopWindow(); 
	SQLSMALLINT nResult = 0;

	SQLSMALLINT cb;
	UWORD wConnectOption = SQL_DRIVER_COMPLETE; //SQL_DRIVER_NOPROMPT;
	QVarLengthArray<SQLTCHAR> connOut(1024);
	memset(connOut.data(), 0, connOut.size() * sizeof(SQLTCHAR));

	switch (connectionSource)
	{
		case Source:
			{// environment
				SQLHANDLE hEnv = SQL_NULL_HANDLE;
				SQLHANDLE hDbc = SQL_NULL_HANDLE;
				r = ::SQLAllocHandle(SQL_HANDLE_ENV, SQL_NULL_HANDLE, &hEnv);
				if (r == SQL_SUCCESS) isValid = true;

				foreach(nOdbcAttributesClass * k, this->m_OdbcAttributes_Map)
				{
					if (k->attributeType == enumAttributeType::hEnv)
					{
						r = ::SQLSetEnvAttr(hEnv, (SQLINTEGER) k->odbcKey, (SQLPOINTER)k->odbcValue, 0);
						if (r == SQL_SUCCESS) isValid = true;
					}
				}
				hEnv_Source = hEnv;

				r = SQLAllocHandle(SQL_HANDLE_DBC, hEnv, &hDbc);
				if (r == SQL_SUCCESS) isValid = true;
				foreach(nOdbcAttributesClass * k, this->m_OdbcAttributes_Map)
				{
					if (k->attributeType == enumAttributeType::hDbc)
					{
					r = ::SQLSetConnectAttr(hDbc, k->odbcKey, (SQLPOINTER)k->odbcValue, 0);
					if (k->odbcKey == SQL_ATTR_CONNECTION_POOLING && k->odbcValue == SQL_CP_ONE_PER_DRIVER) wConnectOption = SQL_DRIVER_NOPROMPT;
					if (k->odbcKey == SQL_ATTR_CONNECTION_POOLING && k->odbcValue == SQL_CP_ONE_PER_HENV) wConnectOption = SQL_DRIVER_NOPROMPT;
					if (k->odbcKey == SQL_ATTR_CONNECTION_POOLING && k->odbcValue == SQL_CP_DRIVER_AWARE) wConnectOption = SQL_DRIVER_NOPROMPT;
					if (r == SQL_SUCCESS) isValid = true;
					}
				}
				hDbc_source = hDbc;
				if (isValid)
				{
					r = ::SQLDriverConnect(
						hDbc,
						hWnd,
#ifdef UNICODE
						toSQLTCHAR(m_lpszSourceDSN).data(),
#else
						(SQLCHAR*)dsnSource.toUtf8().data(),
#endif
						(SQLSMALLINT)m_lpszSourceDSN.length(),
						connOut.data(),
						1024,
						&cb, 
						wConnectOption); 
					int colSize = cb / sizeof(SQLTCHAR);
					if (r != SQL_SUCCESS && r != SQL_SUCCESS_WITH_INFO)
					{
						QString check = qWarnODBCHandle(SQL_HANDLE_DBC, hDbc);
						qCritical(category) <<  check;
						m_bIsOpen = false;
					}
					m_bIsOpen = true;
				}
			} break;
		case Target:
			{
				SQLHANDLE hEnv = SQL_NULL_HANDLE;
				SQLHANDLE hDbc = SQL_NULL_HANDLE;
				r = ::SQLAllocHandle(SQL_HANDLE_ENV, SQL_NULL_HANDLE, &hEnv);
				if (r == SQL_SUCCESS) isValid = true;

				foreach(nOdbcAttributesClass * k, this->m_OdbcAttributes_Map)
				{
					if (k->attributeType == enumAttributeType::hEnv)
					{
						r = ::SQLSetEnvAttr(hEnv, (SQLINTEGER) k->odbcKey, (SQLPOINTER)k->odbcValue, 0);
						if (r == SQL_SUCCESS) isValid = true;
					}
				}
				hEnv_Target = hEnv;

				r = SQLAllocHandle(SQL_HANDLE_DBC, hEnv, &hDbc);
				if (r == SQL_SUCCESS) isValid = true;
				foreach(nOdbcAttributesClass * k, this->m_OdbcAttributes_Map)
				{
				if (k->attributeType == enumAttributeType::hDbc)
					{
					r = ::SQLSetConnectAttr(hDbc, k->odbcKey, (SQLPOINTER)k->odbcValue, 0);
					if (k->odbcKey == SQL_ATTR_CONNECTION_POOLING && k->odbcValue == SQL_CP_ONE_PER_DRIVER) wConnectOption = SQL_DRIVER_NOPROMPT;
					if (k->odbcKey == SQL_ATTR_CONNECTION_POOLING && k->odbcValue == SQL_CP_ONE_PER_HENV) wConnectOption = SQL_DRIVER_NOPROMPT;
					if (k->odbcKey == SQL_ATTR_CONNECTION_POOLING && k->odbcValue == SQL_CP_DRIVER_AWARE) wConnectOption = SQL_DRIVER_NOPROMPT;
					if (r == SQL_SUCCESS) isValid = true;
					}
				}
				hDbc_target = hDbc;
				if (isValid) {
					r = ::SQLDriverConnect(
						hDbc,
						hWnd,
#ifdef UNICODE
						toSQLTCHAR(m_lpszTargetDSN).data(),
#else
						(SQLCHAR*)m_lpszTargetDSN.toUtf8().data(),
#endif
						(SQLSMALLINT)m_lpszTargetDSN.length(),
						connOut.data(),
						1024,
						&cb, 
						wConnectOption); 
						int colSize = cb / sizeof(SQLTCHAR);
					if (r != SQL_SUCCESS && r != SQL_SUCCESS_WITH_INFO)
						{
							QString check = qWarnODBCHandle(SQL_HANDLE_DBC, hDbc);
							qCritical(category) <<  check;
							m_bIsOpen = false;
						}
							m_bIsOpen = true;
					}
			} break;
			default: break;
	}
}
TK_HDRLTPSET::TK_HDRLTPSET(QObject * parent) : QObject(parent) 
,tableName("TK_HDRLTPSET")
,m_dropOption(DropOption::DropTable) { 
	numRowsFetched = 0;
}

#pragma region ~CTOR TK_HDRLTPSET 
TK_HDRLTPSET::~TK_HDRLTPSET() { 

#pragma region Buffers - Clear 
	DB_ID.clear();
	NVTIMESTAMP.clear();
	OAREA.clear();
	OPAGE.clear();
	OLINE.clear();
	MAREA.clear();
	MPAGE.clear();
	MLINE.clear();
#pragma endregion Buffers - Clear 
}
#pragma endregion Destructor_TK_HDRLTPSET

// begin method functions
void TK_HDRLTPSET::setAbortFlag() { 
	QLoggingCategory category("classLibQ");
	qCInfo(category) << "isAbort was set to True";
	bIsAbort = true;
}

void TK_HDRLTPSET::run() { 
	process(1);
	QLoggingCategory category("classLibQ");
	qDebug(category) << "Entered;";
}

void	TK_HDRLTPSET::initOdbcAttributes()
{
	QLoggingCategory category("classLibQ");
	this->setProfileName(profileName);
	qDebug(category) << "Processing - TRKDB100"; 
	m_OdbcAttributesList = m_OdbcAttributes.split(","); 
	foreach(QString m, m_OdbcAttributesList)
	{
		QStringList keyValue = m.split("=");
		nOdbcAttributesClass * oM = new nOdbcAttributesClass(this);
		if (oM->loadToOdbc(keyValue.value(0), keyValue.value(1)))
		{
			m_OdbcAttributes_Map.insert(oM->odbcKey, oM);
		}
	}
}
void	TK_HDRLTPSET::initialize()
{
	QLoggingCategory category("classLibQ");
	RETCODE r;
	this->setProfileName(profileName);
	qDebug(category) << "Processing - TRKDB100"; 
//SQL Statements
//--------------------------------------------------

#pragma region Sql Statements_TK_HDRLTPSET

	fetchSql = "select  DB_ID, NVTIMESTAMP, OAREA, OPAGE, OLINE, MAREA, MPAGE, MLINE from TK_HDRLTPSET";
		if (m_ReplicationOption == ReplicationOption::NetChange)
		{
			fetchSql.append(" p1, nv_transfers p2 WHERE  p2.table_name = 'TK_HDRLTPSET' AND p1.nvtimestamp > p2.last_completed");
		}
	insertSql = "insert into TK_HDRLTPSET ( PLANT_CODE, NVTIMESTAMP, OAREA, OPAGE, OLINE, MAREA, MPAGE, MLINE ) values ( ?, ?, ?, ?, ?, ?, ?, ?)";
	updateSql = "update TK_HDRLTPSET set  PLANT_CODE = ?, NVTIMESTAMP = ?, OAREA = ?, OPAGE = ?, OLINE = ?, MAREA = ?, MPAGE = ?, MLINE = ?  where area = ? and page = ? line = ? ";

	qDebug(category) << "insertSQL - insert into TK_HDRLTPSET ( PLANT_CODE, NVTIMESTAMP, OAREA, OPAGE, OLINE, MAREA, MPAGE, MLINE ) values ( ?, ?, ?, ?, ?, ?, ?, ?)";
	qDebug(category) << "fetchSQL - select  DB_ID, NVTIMESTAMP, OAREA, OPAGE, OLINE, MAREA, MPAGE, MLINE from TK_HDRLTPSET";
	qDebug(category) << "unsertSQL - update TK_HDRLTPSET set  PLANT_CODE = ?, NVTIMESTAMP = ?, OAREA = ?, OPAGE = ?, OLINE = ?, MAREA = ?, MPAGE = ?, MLINE = ?  where area = ? and page = ? line = ? ";

#pragma endregion Sql Statements_TK_HDRLTPSET
	SQLHANDLE		insert_hStmt = SQL_NULL_HANDLE;
	SQLHANDLE		fetch_hStmt = SQL_NULL_HANDLE; 
	SQLHANDLE		update_hStmt = SQL_NULL_HANDLE; 
 
	r = ::SQLAllocHandle(SQL_HANDLE_STMT, hDbc_source, &fetch_hStmt);
	if (r != SQL_SUCCESS) {
		 qCCritical(category) << QString("Error  hDbc_Source SQLCode : %1 is %2").arg(QString::number( (long)hDbc_source)).arg(QString::number(r));
		return; 
	}
	r = ::SQLAllocHandle(SQL_HANDLE_STMT, hDbc_target, &insert_hStmt);
	if (r != SQL_SUCCESS) {
		 qCCritical(category) << QString("Error hDbc_Source -SQLCode: %1 is %2").arg(QString::number( (long)hDbc_target)).arg(QString::number(r));
		return; 
	}
	r = ::SQLAllocHandle(SQL_HANDLE_STMT, hDbc_target, &update_hStmt);
	if (r != SQL_SUCCESS) {
		 qCCritical(category) << QString("Error hDbc_Source +SQLCode: %1 is %2").arg(QString::number( (long)hDbc_target)).arg(QString::number(r));
		return; 
	}
 
	hStmt_Fetch = fetch_hStmt;
	hStmt_Insert = insert_hStmt;
	hStmt_Update = update_hStmt;
 
	SQLSetStmtAttr(hStmt_Fetch, SQL_ATTR_USE_BOOKMARKS, (SQLPOINTER)SQL_UB_OFF, 0);
	SQLSetStmtAttr(hStmt_Fetch, SQL_ATTR_ROW_BIND_TYPE, (SQLPOINTER)SQL_BIND_BY_COLUMN, 0);
	SQLSetStmtAttr(hStmt_Fetch, SQL_ATTR_ROW_ARRAY_SIZE, (SQLPOINTER)1, 0);
	SQLSetStmtAttr(hStmt_Fetch, SQL_ATTR_ROWS_FETCHED_PTR, &numRowsFetched, 0);

// Fields used by this class 
// ---------------------------------------------------

#pragma region Resize Fields TK_HDRLTPSET
	qDebug(category) << "Malloc - DB_ID[2]";
	DB_ID.resize(2);
	qDebug(category) << "Malloc - NVTIMESTAMP[23]";
	NVTIMESTAMP.resize(23);
	qDebug(category) << "Malloc - OAREA[2]";
	OAREA.resize(2);
	qDebug(category) << "Malloc - OPAGE[4]";
	OPAGE.resize(4);
	qDebug(category) << "Malloc - OLINE[2]";
	OLINE.resize(2);
	qDebug(category) << "Malloc - MAREA[2]";
	MAREA.resize(2);
	qDebug(category) << "Malloc - MPAGE[4]";
	MPAGE.resize(4);
	qDebug(category) << "Malloc - MLINE[2]";
	MLINE.resize(2);

#pragma endregion Resize Fields TK_HDRLTPSET
}
void TK_HDRLTPSET::close()
{
	QLoggingCategory category("classLibQ");
	if (m_bIsOpen)
	{
	qDebug(category) << "database is Open";
		SQLHANDLE source_hStmt = hStmt_Fetch;
		SQLHANDLE insert_hStmt = hStmt_Insert;
		SQLHANDLE hDb_S = this->hDbc_source;
		SQLHANDLE hDb_T = hDbc_target;
		SQLHANDLE hEnvS = hEnv_Source;
		SQLHANDLE hEnvT = hEnv_Target;
		RETCODE r;

		r = ::SQLFreeHandle(SQL_HANDLE_STMT, hStmt_Fetch);
		r = ::SQLFreeHandle(SQL_HANDLE_STMT, hStmt_Insert);
		r = ::SQLFreeHandle(SQL_HANDLE_STMT, hStmt_Update);
		if (hDbc_source != SQL_NULL_HANDLE) 		r = ::SQLDisconnect(hDb_S);
		if (hDbc_target != SQL_NULL_HANDLE) 		r = ::SQLDisconnect(hDb_T);

		r = ::SQLFreeHandle(SQL_HANDLE_DBC, hDb_S);
		r = ::SQLFreeHandle(SQL_HANDLE_DBC, hDb_T);
		r = ::SQLFreeHandle(SQL_HANDLE_ENV, hEnvS);
		r = ::SQLFreeHandle(SQL_HANDLE_ENV, hEnvT);
	}

	hEnv_Source = SQL_NULL_HANDLE;
	hEnv_Target = SQL_NULL_HANDLE;
	hEnv_Source = SQL_NULL_HANDLE;
	hEnv_Target = SQL_NULL_HANDLE;
	hStmt_Fetch = SQL_NULL_HANDLE;
	hStmt_Insert = SQL_NULL_HANDLE;
	hStmt_Update = SQL_NULL_HANDLE;
}

void TK_HDRLTPSET::open(const QString sourceDSN, const QString targetDSN)
{
	QLoggingCategory category("classLibQ");
	m_lpszTargetDSN = targetDSN;
	m_lpszSourceDSN = sourceDSN;
	qDebug(category) << QString("Source - %1[%2]").arg(sourceDSN);
	qDebug(category) << QString("Target - %1[%2]").arg(targetDSN);
}

void TK_HDRLTPSET::createTable()
{
	QLoggingCategory category("classLibQ");
	{
		QScopedPointer<nvTableOracleRdb> tbl(new nvTableOracleRdb(nullptr));
		tbl->initialize("TK_HDRLTPSET", this->m_lpszSourceDSN);
		QString newTbl = tbl->getCreateTableSQL();
		QScopedPointer<qVtExecute> vExec(new qVtExecute(nullptr));
		{
			vExec->initialize(m_lpszTargetDSN, " ", true);
			vExec->setOdbcAttributes(m_OdbcAttributes);
			vExec->ExecuteDirect(newTbl);
		}
	 qDebug(category) << QString("End Create Table %1 ").arg(tableName); 
	}
}

bool TK_HDRLTPSET::prepare()
{
	RETCODE r;
	QString check;
	QLoggingCategory category("classLibQ");
	 qDebug(category) << fetchSql;
	 qDebug(category) << insertSql;
#ifdef UNICODE
	r = SQLPrepare(hStmt_Insert,toSQLTCHAR(insertSql).data(),(SQLINTEGER)insertSql.length()); 
	if (r != SQL_SUCCESS) {
		check = qWarnODBCHandle(SQL_HANDLE_STMT, hStmt_Insert);
		 qCCritical(category) << QString("Prepare Statement-Insert : %1 is %2").arg(insertSql).arg(check);
		return false; 
	}
	r = SQLPrepare(hStmt_Update,toSQLTCHAR(updateSql).data(),(SQLINTEGER)updateSql.length()); 
	if (r != SQL_SUCCESS) {
		check = qWarnODBCHandle(SQL_HANDLE_STMT, hStmt_Update);
		 qCCritical(category) << QString("Prepare Statement-Update : %1 is %2").arg(updateSql).arg(check);
		return false; 
	}
	r = SQLPrepare(hStmt_Fetch,toSQLTCHAR(fetchSql).data(),(SQLINTEGER)fetchSql.length());
	if (r != SQL_SUCCESS) {
		check = qWarnODBCHandle(SQL_HANDLE_STMT, hStmt_Fetch);
		 qCCritical(category) << QString("Prepare Statement-Insert : %1 is %2").arg(fetchSql).arg(check);
		return false; 
	}
#else
	QByteArray queryI8 = insertSql.toUtf8();
	r = SQLPrepare(insert_hStmt,SQLCHAR*)queryI8.data(),(SQLINTEGER)queryI8.length());
	QByteArray queryU8 = fetchSql.toUtf8();
	r = SQLPrepare(hStmt_Fetch,(SQLCHAR*)queryU8.data(),(SQLINTEGER)queryU8.length());
#endif
	return true;

}

void TK_HDRLTPSET::prepareTargetTable()
{
	QLoggingCategory category("classLibQ");
	if (this->m_ReplicationOption == ReplicationOption::BulkCopy)
	{
		QScopedPointer<qVtExecute> execSql(new qVtExecute(nullptr));
		DropOption option = this->m_dropOption;
		switch (option)
		{
			case DropOption::DeleteFromTable:
			{
				QLoggingCategory category("classLibQ");
				execSql->initialize(this->m_lpszTargetDSN, "delete from TK_HDRLTPSET", true);
				execSql->setOdbcAttributes(this->m_OdbcAttributes);
				execSql->ExecuteDirect("delete from TK_HDRLTPSET");
			}break;
			case DropOption::TruncateTable:
			{
				execSql->initialize(this->m_lpszTargetDSN, "truncate table TK_HDRLTPSET", true);
				execSql->setOdbcAttributes(this->m_OdbcAttributes);
				execSql->ExecuteDirect("truncate table TK_HDRLTPSET");
			}break;
			case DropOption::DropTable:
			{
				execSql->initialize(this->m_lpszTargetDSN, "drop table TK_HDRLTPSET", true);
				execSql->setOdbcAttributes(this->m_OdbcAttributes);
				execSql->ExecuteDirect("drop table TK_HDRLTPSET");
				createTable();
			}break;
		}
	}
}

bool TK_HDRLTPSET::bindColumn()
{
	QLoggingCategory category("classLibQ");
	RETCODE r;
	bool isValid=true;
		 qDebug(category) << " Bindings: Ordinal [1] Type: 5 Buffer Size: 2 FieldName: DB_ID ";
		r = ::SQLBindCol(hStmt_Fetch, 1, 5, DB_ID.data(), 2, &cbDB_ID);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Bindings: Ordinal [2] Type: 93 Buffer Size: 23 FieldName: NVTIMESTAMP ";
		r = ::SQLBindCol(hStmt_Fetch, 2, 93, NVTIMESTAMP.data(), 23, &cbNVTIMESTAMP);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Bindings: Ordinal [3] Type: 5 Buffer Size: 2 FieldName: OAREA ";
		r = ::SQLBindCol(hStmt_Fetch, 3, 5, OAREA.data(), 2, &cbOAREA);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Bindings: Ordinal [4] Type: 4 Buffer Size: 4 FieldName: OPAGE ";
		r = ::SQLBindCol(hStmt_Fetch, 4, 4, OPAGE.data(), 4, &cbOPAGE);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Bindings: Ordinal [5] Type: 5 Buffer Size: 2 FieldName: OLINE ";
		r = ::SQLBindCol(hStmt_Fetch, 5, 5, OLINE.data(), 2, &cbOLINE);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Bindings: Ordinal [6] Type: 5 Buffer Size: 2 FieldName: MAREA ";
		r = ::SQLBindCol(hStmt_Fetch, 6, 5, MAREA.data(), 2, &cbMAREA);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Bindings: Ordinal [7] Type: 4 Buffer Size: 4 FieldName: MPAGE ";
		r = ::SQLBindCol(hStmt_Fetch, 7, 4, MPAGE.data(), 4, &cbMPAGE);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Bindings: Ordinal [8] Type: 5 Buffer Size: 2 FieldName: MLINE ";
		r = ::SQLBindCol(hStmt_Fetch, 8, 5, MLINE.data(), 2, &cbMLINE);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
	return isValid;
}

bool TK_HDRLTPSET::bindParameter()
{
	QLoggingCategory category("classLibQ");
	RETCODE r;
	bool isValid=true;
	{
		 qDebug(category) << " Parameters: Ordinal [1] Type: 5 Buffer Size: 2 FieldName: DB_ID ";
		r = SQLBindParameter(hStmt_Insert, 1, SQL_PARAM_INPUT, SQL_C_DEFAULT, 5, 0, 0, (SQLPOINTER)DB_ID.constData(), 0, &cbDB_ID);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Parameters: Ordinal [2] Type: 93 Buffer Size: 23 FieldName: NVTIMESTAMP ";
		r = SQLBindParameter(hStmt_Insert, 2, SQL_PARAM_INPUT, SQL_C_DEFAULT, 93, 23, 0, (SQLPOINTER)NVTIMESTAMP.constData(), 0, &cbNVTIMESTAMP);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Parameters: Ordinal [3] Type: 5 Buffer Size: 2 FieldName: OAREA ";
		r = SQLBindParameter(hStmt_Insert, 3, SQL_PARAM_INPUT, SQL_C_DEFAULT, 5, 0, 0, (SQLPOINTER)OAREA.constData(), 0, &cbOAREA);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Parameters: Ordinal [4] Type: 4 Buffer Size: 4 FieldName: OPAGE ";
		r = SQLBindParameter(hStmt_Insert, 4, SQL_PARAM_INPUT, SQL_C_DEFAULT, 4, 0, 0, (SQLPOINTER)OPAGE.constData(), 0, &cbOPAGE);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Parameters: Ordinal [5] Type: 5 Buffer Size: 2 FieldName: OLINE ";
		r = SQLBindParameter(hStmt_Insert, 5, SQL_PARAM_INPUT, SQL_C_DEFAULT, 5, 0, 0, (SQLPOINTER)OLINE.constData(), 0, &cbOLINE);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Parameters: Ordinal [6] Type: 5 Buffer Size: 2 FieldName: MAREA ";
		r = SQLBindParameter(hStmt_Insert, 6, SQL_PARAM_INPUT, SQL_C_DEFAULT, 5, 0, 0, (SQLPOINTER)MAREA.constData(), 0, &cbMAREA);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Parameters: Ordinal [7] Type: 4 Buffer Size: 4 FieldName: MPAGE ";
		r = SQLBindParameter(hStmt_Insert, 7, SQL_PARAM_INPUT, SQL_C_DEFAULT, 4, 0, 0, (SQLPOINTER)MPAGE.constData(), 0, &cbMPAGE);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Parameters: Ordinal [8] Type: 5 Buffer Size: 2 FieldName: MLINE ";
		r = SQLBindParameter(hStmt_Insert, 8, SQL_PARAM_INPUT, SQL_C_DEFAULT, 5, 0, 0, (SQLPOINTER)MLINE.constData(), 0, &cbMLINE);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
	}
	if (m_ReplicationOption == ReplicationOption::NetChange)
	{
		r = SQLBindParameter(hStmt_Update, 9, SQL_PARAM_INPUT, SQL_C_DEFAULT, 6, 0, 0, (SQLPOINTER)MAREA.constData(), 0, &cbMAREA);
		if (r == SQL_SUCCESS) { isValid=true; }
		r = SQLBindParameter(hStmt_Update, 10, SQL_PARAM_INPUT, SQL_C_DEFAULT, 7, 0, 0, (SQLPOINTER)MPAGE.constData(), 0, &cbMPAGE);
		if (r == SQL_SUCCESS) { isValid=true; }
		r = SQLBindParameter(hStmt_Update, 11, SQL_PARAM_INPUT, SQL_C_DEFAULT, 8, 0, 0, (SQLPOINTER)MLINE.constData(), 0, &cbMLINE);
		if (r == SQL_SUCCESS) { isValid=true; }
	// TK_HDRLTPSET is a well formed table for eNVy Replication 
		 qDebug(category) << " Parameters: Ordinal [6] 00 00 FieldName: MAREA ";
		 qDebug(category) << " Parameters: Ordinal [7] 00 00  FieldName: MPAGE ";
		 qDebug(category) << " Parameters: Ordinal [8] 00 00 FieldName:  MLINE ";
	} // 	if (m_ReplicationOption == ReplicationOption::NetChange)
	return isValid;
}

bool TK_HDRLTPSET::process(int rowSize)
{
	QLoggingCategory category("classLibQ");
	initOdbcAttributes();
	connect(Source);
	connect(Target);
	initialize();
	prepareTargetTable();
	prepare();
	bindColumn();
	bindParameter();
	copyTable();
	close();
	return false;
}

void TK_HDRLTPSET::copyTable()
{
	QLoggingCategory category("classLibQ");
	RETCODE r;
	QString check;
	r = SQLExecute(hStmt_Fetch);
		if (bIsAbort) {
			emit aborted(tableName, rowsFetched, rowsInserted, rowsUpdated);
			return;
		}
		while((r = SQLFetch(hStmt_Fetch)) != SQL_NO_DATA) {
		if (r != SQL_SUCCESS) {
			check = qWarnODBCHandle(SQL_HANDLE_STMT, hStmt_Fetch);
			qCCritical(category) << QString("SqlFetch - Error : %1 is %2").arg(fetchSql).arg(check);
			return;
		} 
		rowsFetched++;
		if (m_ReplicationOption == ReplicationOption::BulkCopy)
		{
			r = SQLExecute(hStmt_Insert);
			if (r == SQL_ERROR) {
				check = qWarnODBCHandle(SQL_HANDLE_STMT, hStmt_Insert);
				 qCCritical(category) << QString("SqlExecute:Insert - Error : %1 is %2").arg(insertSql).arg(check);
				return;
			}
			rowsInserted++;
			if ((rowsFetched % updateInterval) == 0) {
				qCInfo(category) << QString("[%1.%2]	Insertion: %3	Updates : %4	Fetched : %5").arg(profileName).arg(tableName).arg(rowsInserted).arg(rowsUpdated).arg(rowsFetched);
				emit updateStatusFetched(profileName, tableName, rowsFetched,rowsInserted,rowsUpdated);
			}
			if (m_ReplicationOption == ReplicationOption::NetChange)
			{
			r = SQLExecute(hStmt_Update);
			if (r != SQL_SUCCESS) {
				check = qWarnODBCHandle(SQL_HANDLE_STMT, hStmt_Update);
				 qCInfo(category)  << QString("SqlExecute:Update - Error : %1 is %2").arg(updateSql).arg(check);
				r = SQLExecute(hStmt_Insert);
				if (r != SQL_SUCCESS) {
					check = qWarnODBCHandle(SQL_HANDLE_STMT, hStmt_Insert);
					 qCritical(category) << QString("SqlExecute:Insert - Error : %1 is %2").arg(insertSql).arg(check);
					return;
				}
				else 	rowsInserted++;
				}
				else	rowsUpdated++;
			}
			emit updateStatusFetched(profileName, tableName, rowsFetched,rowsInserted,rowsUpdated);
		}
	} 
qCInfo(category) << QString("[%1.%2]	Insertion: %3	Updates : %4	Fetched : %5").arg(profileName).arg(tableName).arg(rowsInserted).arg(rowsUpdated).arg(rowsFetched);
}

void TK_HDRLTPSET::connect(connectionHandle connectionSource)
{

	QLoggingCategory category("classLibQ");
	RETCODE r;

	bool isValid = false;
	HWND	hWnd = nullptr;
	hWnd = ::GetDesktopWindow(); 
	SQLSMALLINT nResult = 0;

	SQLSMALLINT cb;
	UWORD wConnectOption = SQL_DRIVER_COMPLETE; //SQL_DRIVER_NOPROMPT;
	QVarLengthArray<SQLTCHAR> connOut(1024);
	memset(connOut.data(), 0, connOut.size() * sizeof(SQLTCHAR));

	switch (connectionSource)
	{
		case Source:
			{// environment
				SQLHANDLE hEnv = SQL_NULL_HANDLE;
				SQLHANDLE hDbc = SQL_NULL_HANDLE;
				r = ::SQLAllocHandle(SQL_HANDLE_ENV, SQL_NULL_HANDLE, &hEnv);
				if (r == SQL_SUCCESS) isValid = true;

				foreach(nOdbcAttributesClass * k, this->m_OdbcAttributes_Map)
				{
					if (k->attributeType == enumAttributeType::hEnv)
					{
						r = ::SQLSetEnvAttr(hEnv, (SQLINTEGER) k->odbcKey, (SQLPOINTER)k->odbcValue, 0);
						if (r == SQL_SUCCESS) isValid = true;
					}
				}
				hEnv_Source = hEnv;

				r = SQLAllocHandle(SQL_HANDLE_DBC, hEnv, &hDbc);
				if (r == SQL_SUCCESS) isValid = true;
				foreach(nOdbcAttributesClass * k, this->m_OdbcAttributes_Map)
				{
					if (k->attributeType == enumAttributeType::hDbc)
					{
					r = ::SQLSetConnectAttr(hDbc, k->odbcKey, (SQLPOINTER)k->odbcValue, 0);
					if (k->odbcKey == SQL_ATTR_CONNECTION_POOLING && k->odbcValue == SQL_CP_ONE_PER_DRIVER) wConnectOption = SQL_DRIVER_NOPROMPT;
					if (k->odbcKey == SQL_ATTR_CONNECTION_POOLING && k->odbcValue == SQL_CP_ONE_PER_HENV) wConnectOption = SQL_DRIVER_NOPROMPT;
					if (k->odbcKey == SQL_ATTR_CONNECTION_POOLING && k->odbcValue == SQL_CP_DRIVER_AWARE) wConnectOption = SQL_DRIVER_NOPROMPT;
					if (r == SQL_SUCCESS) isValid = true;
					}
				}
				hDbc_source = hDbc;
				if (isValid)
				{
					r = ::SQLDriverConnect(
						hDbc,
						hWnd,
#ifdef UNICODE
						toSQLTCHAR(m_lpszSourceDSN).data(),
#else
						(SQLCHAR*)dsnSource.toUtf8().data(),
#endif
						(SQLSMALLINT)m_lpszSourceDSN.length(),
						connOut.data(),
						1024,
						&cb, 
						wConnectOption); 
					int colSize = cb / sizeof(SQLTCHAR);
					if (r != SQL_SUCCESS && r != SQL_SUCCESS_WITH_INFO)
					{
						QString check = qWarnODBCHandle(SQL_HANDLE_DBC, hDbc);
						qCritical(category) <<  check;
						m_bIsOpen = false;
					}
					m_bIsOpen = true;
				}
			} break;
		case Target:
			{
				SQLHANDLE hEnv = SQL_NULL_HANDLE;
				SQLHANDLE hDbc = SQL_NULL_HANDLE;
				r = ::SQLAllocHandle(SQL_HANDLE_ENV, SQL_NULL_HANDLE, &hEnv);
				if (r == SQL_SUCCESS) isValid = true;

				foreach(nOdbcAttributesClass * k, this->m_OdbcAttributes_Map)
				{
					if (k->attributeType == enumAttributeType::hEnv)
					{
						r = ::SQLSetEnvAttr(hEnv, (SQLINTEGER) k->odbcKey, (SQLPOINTER)k->odbcValue, 0);
						if (r == SQL_SUCCESS) isValid = true;
					}
				}
				hEnv_Target = hEnv;

				r = SQLAllocHandle(SQL_HANDLE_DBC, hEnv, &hDbc);
				if (r == SQL_SUCCESS) isValid = true;
				foreach(nOdbcAttributesClass * k, this->m_OdbcAttributes_Map)
				{
				if (k->attributeType == enumAttributeType::hDbc)
					{
					r = ::SQLSetConnectAttr(hDbc, k->odbcKey, (SQLPOINTER)k->odbcValue, 0);
					if (k->odbcKey == SQL_ATTR_CONNECTION_POOLING && k->odbcValue == SQL_CP_ONE_PER_DRIVER) wConnectOption = SQL_DRIVER_NOPROMPT;
					if (k->odbcKey == SQL_ATTR_CONNECTION_POOLING && k->odbcValue == SQL_CP_ONE_PER_HENV) wConnectOption = SQL_DRIVER_NOPROMPT;
					if (k->odbcKey == SQL_ATTR_CONNECTION_POOLING && k->odbcValue == SQL_CP_DRIVER_AWARE) wConnectOption = SQL_DRIVER_NOPROMPT;
					if (r == SQL_SUCCESS) isValid = true;
					}
				}
				hDbc_target = hDbc;
				if (isValid) {
					r = ::SQLDriverConnect(
						hDbc,
						hWnd,
#ifdef UNICODE
						toSQLTCHAR(m_lpszTargetDSN).data(),
#else
						(SQLCHAR*)m_lpszTargetDSN.toUtf8().data(),
#endif
						(SQLSMALLINT)m_lpszTargetDSN.length(),
						connOut.data(),
						1024,
						&cb, 
						wConnectOption); 
						int colSize = cb / sizeof(SQLTCHAR);
					if (r != SQL_SUCCESS && r != SQL_SUCCESS_WITH_INFO)
						{
							QString check = qWarnODBCHandle(SQL_HANDLE_DBC, hDbc);
							qCritical(category) <<  check;
							m_bIsOpen = false;
						}
							m_bIsOpen = true;
					}
			} break;
			default: break;
	}
}
TK_CNVHSHSET::TK_CNVHSHSET(QObject * parent) : QObject(parent) 
,tableName("TK_CNVHSHSET")
,m_dropOption(DropOption::DropTable) { 
	numRowsFetched = 0;
}

#pragma region ~CTOR TK_CNVHSHSET 
TK_CNVHSHSET::~TK_CNVHSHSET() { 

#pragma region Buffers - Clear 
	DB_ID.clear();
	NVTIMESTAMP.clear();
	OAREA.clear();
	OPAGE.clear();
	OLINE.clear();
	MAREA.clear();
	MPAGE.clear();
	MLINE.clear();
#pragma endregion Buffers - Clear 
}
#pragma endregion Destructor_TK_CNVHSHSET

// begin method functions
void TK_CNVHSHSET::setAbortFlag() { 
	QLoggingCategory category("classLibQ");
	qCInfo(category) << "isAbort was set to True";
	bIsAbort = true;
}

void TK_CNVHSHSET::run() { 
	process(1);
	QLoggingCategory category("classLibQ");
	qDebug(category) << "Entered;";
}

void	TK_CNVHSHSET::initOdbcAttributes()
{
	QLoggingCategory category("classLibQ");
	this->setProfileName(profileName);
	qDebug(category) << "Processing - TRKDB100"; 
	m_OdbcAttributesList = m_OdbcAttributes.split(","); 
	foreach(QString m, m_OdbcAttributesList)
	{
		QStringList keyValue = m.split("=");
		nOdbcAttributesClass * oM = new nOdbcAttributesClass(this);
		if (oM->loadToOdbc(keyValue.value(0), keyValue.value(1)))
		{
			m_OdbcAttributes_Map.insert(oM->odbcKey, oM);
		}
	}
}
void	TK_CNVHSHSET::initialize()
{
	QLoggingCategory category("classLibQ");
	RETCODE r;
	this->setProfileName(profileName);
	qDebug(category) << "Processing - TRKDB100"; 
//SQL Statements
//--------------------------------------------------

#pragma region Sql Statements_TK_CNVHSHSET

	fetchSql = "select  DB_ID, NVTIMESTAMP, OAREA, OPAGE, OLINE, MAREA, MPAGE, MLINE from TK_CNVHSHSET";
		if (m_ReplicationOption == ReplicationOption::NetChange)
		{
			fetchSql.append(" p1, nv_transfers p2 WHERE  p2.table_name = 'TK_CNVHSHSET' AND p1.nvtimestamp > p2.last_completed");
		}
	insertSql = "insert into TK_CNVHSHSET ( PLANT_CODE, NVTIMESTAMP, OAREA, OPAGE, OLINE, MAREA, MPAGE, MLINE ) values ( ?, ?, ?, ?, ?, ?, ?, ?)";
	updateSql = "update TK_CNVHSHSET set  PLANT_CODE = ?, NVTIMESTAMP = ?, OAREA = ?, OPAGE = ?, OLINE = ?, MAREA = ?, MPAGE = ?, MLINE = ?  where area = ? and page = ? line = ? ";

	qDebug(category) << "insertSQL - insert into TK_CNVHSHSET ( PLANT_CODE, NVTIMESTAMP, OAREA, OPAGE, OLINE, MAREA, MPAGE, MLINE ) values ( ?, ?, ?, ?, ?, ?, ?, ?)";
	qDebug(category) << "fetchSQL - select  DB_ID, NVTIMESTAMP, OAREA, OPAGE, OLINE, MAREA, MPAGE, MLINE from TK_CNVHSHSET";
	qDebug(category) << "unsertSQL - update TK_CNVHSHSET set  PLANT_CODE = ?, NVTIMESTAMP = ?, OAREA = ?, OPAGE = ?, OLINE = ?, MAREA = ?, MPAGE = ?, MLINE = ?  where area = ? and page = ? line = ? ";

#pragma endregion Sql Statements_TK_CNVHSHSET
	SQLHANDLE		insert_hStmt = SQL_NULL_HANDLE;
	SQLHANDLE		fetch_hStmt = SQL_NULL_HANDLE; 
	SQLHANDLE		update_hStmt = SQL_NULL_HANDLE; 
 
	r = ::SQLAllocHandle(SQL_HANDLE_STMT, hDbc_source, &fetch_hStmt);
	if (r != SQL_SUCCESS) {
		 qCCritical(category) << QString("Error  hDbc_Source SQLCode : %1 is %2").arg(QString::number( (long)hDbc_source)).arg(QString::number(r));
		return; 
	}
	r = ::SQLAllocHandle(SQL_HANDLE_STMT, hDbc_target, &insert_hStmt);
	if (r != SQL_SUCCESS) {
		 qCCritical(category) << QString("Error hDbc_Source -SQLCode: %1 is %2").arg(QString::number( (long)hDbc_target)).arg(QString::number(r));
		return; 
	}
	r = ::SQLAllocHandle(SQL_HANDLE_STMT, hDbc_target, &update_hStmt);
	if (r != SQL_SUCCESS) {
		 qCCritical(category) << QString("Error hDbc_Source +SQLCode: %1 is %2").arg(QString::number( (long)hDbc_target)).arg(QString::number(r));
		return; 
	}
 
	hStmt_Fetch = fetch_hStmt;
	hStmt_Insert = insert_hStmt;
	hStmt_Update = update_hStmt;
 
	SQLSetStmtAttr(hStmt_Fetch, SQL_ATTR_USE_BOOKMARKS, (SQLPOINTER)SQL_UB_OFF, 0);
	SQLSetStmtAttr(hStmt_Fetch, SQL_ATTR_ROW_BIND_TYPE, (SQLPOINTER)SQL_BIND_BY_COLUMN, 0);
	SQLSetStmtAttr(hStmt_Fetch, SQL_ATTR_ROW_ARRAY_SIZE, (SQLPOINTER)1, 0);
	SQLSetStmtAttr(hStmt_Fetch, SQL_ATTR_ROWS_FETCHED_PTR, &numRowsFetched, 0);

// Fields used by this class 
// ---------------------------------------------------

#pragma region Resize Fields TK_CNVHSHSET
	qDebug(category) << "Malloc - DB_ID[2]";
	DB_ID.resize(2);
	qDebug(category) << "Malloc - NVTIMESTAMP[23]";
	NVTIMESTAMP.resize(23);
	qDebug(category) << "Malloc - OAREA[2]";
	OAREA.resize(2);
	qDebug(category) << "Malloc - OPAGE[4]";
	OPAGE.resize(4);
	qDebug(category) << "Malloc - OLINE[2]";
	OLINE.resize(2);
	qDebug(category) << "Malloc - MAREA[2]";
	MAREA.resize(2);
	qDebug(category) << "Malloc - MPAGE[4]";
	MPAGE.resize(4);
	qDebug(category) << "Malloc - MLINE[2]";
	MLINE.resize(2);

#pragma endregion Resize Fields TK_CNVHSHSET
}
void TK_CNVHSHSET::close()
{
	QLoggingCategory category("classLibQ");
	if (m_bIsOpen)
	{
	qDebug(category) << "database is Open";
		SQLHANDLE source_hStmt = hStmt_Fetch;
		SQLHANDLE insert_hStmt = hStmt_Insert;
		SQLHANDLE hDb_S = this->hDbc_source;
		SQLHANDLE hDb_T = hDbc_target;
		SQLHANDLE hEnvS = hEnv_Source;
		SQLHANDLE hEnvT = hEnv_Target;
		RETCODE r;

		r = ::SQLFreeHandle(SQL_HANDLE_STMT, hStmt_Fetch);
		r = ::SQLFreeHandle(SQL_HANDLE_STMT, hStmt_Insert);
		r = ::SQLFreeHandle(SQL_HANDLE_STMT, hStmt_Update);
		if (hDbc_source != SQL_NULL_HANDLE) 		r = ::SQLDisconnect(hDb_S);
		if (hDbc_target != SQL_NULL_HANDLE) 		r = ::SQLDisconnect(hDb_T);

		r = ::SQLFreeHandle(SQL_HANDLE_DBC, hDb_S);
		r = ::SQLFreeHandle(SQL_HANDLE_DBC, hDb_T);
		r = ::SQLFreeHandle(SQL_HANDLE_ENV, hEnvS);
		r = ::SQLFreeHandle(SQL_HANDLE_ENV, hEnvT);
	}

	hEnv_Source = SQL_NULL_HANDLE;
	hEnv_Target = SQL_NULL_HANDLE;
	hEnv_Source = SQL_NULL_HANDLE;
	hEnv_Target = SQL_NULL_HANDLE;
	hStmt_Fetch = SQL_NULL_HANDLE;
	hStmt_Insert = SQL_NULL_HANDLE;
	hStmt_Update = SQL_NULL_HANDLE;
}

void TK_CNVHSHSET::open(const QString sourceDSN, const QString targetDSN)
{
	QLoggingCategory category("classLibQ");
	m_lpszTargetDSN = targetDSN;
	m_lpszSourceDSN = sourceDSN;
	qDebug(category) << QString("Source - %1[%2]").arg(sourceDSN);
	qDebug(category) << QString("Target - %1[%2]").arg(targetDSN);
}

void TK_CNVHSHSET::createTable()
{
	QLoggingCategory category("classLibQ");
	{
		QScopedPointer<nvTableOracleRdb> tbl(new nvTableOracleRdb(nullptr));
		tbl->initialize("TK_CNVHSHSET", this->m_lpszSourceDSN);
		QString newTbl = tbl->getCreateTableSQL();
		QScopedPointer<qVtExecute> vExec(new qVtExecute(nullptr));
		{
			vExec->initialize(m_lpszTargetDSN, " ", true);
			vExec->setOdbcAttributes(m_OdbcAttributes);
			vExec->ExecuteDirect(newTbl);
		}
	 qDebug(category) << QString("End Create Table %1 ").arg(tableName); 
	}
}

bool TK_CNVHSHSET::prepare()
{
	RETCODE r;
	QString check;
	QLoggingCategory category("classLibQ");
	 qDebug(category) << fetchSql;
	 qDebug(category) << insertSql;
#ifdef UNICODE
	r = SQLPrepare(hStmt_Insert,toSQLTCHAR(insertSql).data(),(SQLINTEGER)insertSql.length()); 
	if (r != SQL_SUCCESS) {
		check = qWarnODBCHandle(SQL_HANDLE_STMT, hStmt_Insert);
		 qCCritical(category) << QString("Prepare Statement-Insert : %1 is %2").arg(insertSql).arg(check);
		return false; 
	}
	r = SQLPrepare(hStmt_Update,toSQLTCHAR(updateSql).data(),(SQLINTEGER)updateSql.length()); 
	if (r != SQL_SUCCESS) {
		check = qWarnODBCHandle(SQL_HANDLE_STMT, hStmt_Update);
		 qCCritical(category) << QString("Prepare Statement-Update : %1 is %2").arg(updateSql).arg(check);
		return false; 
	}
	r = SQLPrepare(hStmt_Fetch,toSQLTCHAR(fetchSql).data(),(SQLINTEGER)fetchSql.length());
	if (r != SQL_SUCCESS) {
		check = qWarnODBCHandle(SQL_HANDLE_STMT, hStmt_Fetch);
		 qCCritical(category) << QString("Prepare Statement-Insert : %1 is %2").arg(fetchSql).arg(check);
		return false; 
	}
#else
	QByteArray queryI8 = insertSql.toUtf8();
	r = SQLPrepare(insert_hStmt,SQLCHAR*)queryI8.data(),(SQLINTEGER)queryI8.length());
	QByteArray queryU8 = fetchSql.toUtf8();
	r = SQLPrepare(hStmt_Fetch,(SQLCHAR*)queryU8.data(),(SQLINTEGER)queryU8.length());
#endif
	return true;

}

void TK_CNVHSHSET::prepareTargetTable()
{
	QLoggingCategory category("classLibQ");
	if (this->m_ReplicationOption == ReplicationOption::BulkCopy)
	{
		QScopedPointer<qVtExecute> execSql(new qVtExecute(nullptr));
		DropOption option = this->m_dropOption;
		switch (option)
		{
			case DropOption::DeleteFromTable:
			{
				QLoggingCategory category("classLibQ");
				execSql->initialize(this->m_lpszTargetDSN, "delete from TK_CNVHSHSET", true);
				execSql->setOdbcAttributes(this->m_OdbcAttributes);
				execSql->ExecuteDirect("delete from TK_CNVHSHSET");
			}break;
			case DropOption::TruncateTable:
			{
				execSql->initialize(this->m_lpszTargetDSN, "truncate table TK_CNVHSHSET", true);
				execSql->setOdbcAttributes(this->m_OdbcAttributes);
				execSql->ExecuteDirect("truncate table TK_CNVHSHSET");
			}break;
			case DropOption::DropTable:
			{
				execSql->initialize(this->m_lpszTargetDSN, "drop table TK_CNVHSHSET", true);
				execSql->setOdbcAttributes(this->m_OdbcAttributes);
				execSql->ExecuteDirect("drop table TK_CNVHSHSET");
				createTable();
			}break;
		}
	}
}

bool TK_CNVHSHSET::bindColumn()
{
	QLoggingCategory category("classLibQ");
	RETCODE r;
	bool isValid=true;
		 qDebug(category) << " Bindings: Ordinal [1] Type: 5 Buffer Size: 2 FieldName: DB_ID ";
		r = ::SQLBindCol(hStmt_Fetch, 1, 5, DB_ID.data(), 2, &cbDB_ID);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Bindings: Ordinal [2] Type: 93 Buffer Size: 23 FieldName: NVTIMESTAMP ";
		r = ::SQLBindCol(hStmt_Fetch, 2, 93, NVTIMESTAMP.data(), 23, &cbNVTIMESTAMP);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Bindings: Ordinal [3] Type: 5 Buffer Size: 2 FieldName: OAREA ";
		r = ::SQLBindCol(hStmt_Fetch, 3, 5, OAREA.data(), 2, &cbOAREA);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Bindings: Ordinal [4] Type: 4 Buffer Size: 4 FieldName: OPAGE ";
		r = ::SQLBindCol(hStmt_Fetch, 4, 4, OPAGE.data(), 4, &cbOPAGE);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Bindings: Ordinal [5] Type: 5 Buffer Size: 2 FieldName: OLINE ";
		r = ::SQLBindCol(hStmt_Fetch, 5, 5, OLINE.data(), 2, &cbOLINE);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Bindings: Ordinal [6] Type: 5 Buffer Size: 2 FieldName: MAREA ";
		r = ::SQLBindCol(hStmt_Fetch, 6, 5, MAREA.data(), 2, &cbMAREA);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Bindings: Ordinal [7] Type: 4 Buffer Size: 4 FieldName: MPAGE ";
		r = ::SQLBindCol(hStmt_Fetch, 7, 4, MPAGE.data(), 4, &cbMPAGE);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Bindings: Ordinal [8] Type: 5 Buffer Size: 2 FieldName: MLINE ";
		r = ::SQLBindCol(hStmt_Fetch, 8, 5, MLINE.data(), 2, &cbMLINE);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
	return isValid;
}

bool TK_CNVHSHSET::bindParameter()
{
	QLoggingCategory category("classLibQ");
	RETCODE r;
	bool isValid=true;
	{
		 qDebug(category) << " Parameters: Ordinal [1] Type: 5 Buffer Size: 2 FieldName: DB_ID ";
		r = SQLBindParameter(hStmt_Insert, 1, SQL_PARAM_INPUT, SQL_C_DEFAULT, 5, 0, 0, (SQLPOINTER)DB_ID.constData(), 0, &cbDB_ID);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Parameters: Ordinal [2] Type: 93 Buffer Size: 23 FieldName: NVTIMESTAMP ";
		r = SQLBindParameter(hStmt_Insert, 2, SQL_PARAM_INPUT, SQL_C_DEFAULT, 93, 23, 0, (SQLPOINTER)NVTIMESTAMP.constData(), 0, &cbNVTIMESTAMP);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Parameters: Ordinal [3] Type: 5 Buffer Size: 2 FieldName: OAREA ";
		r = SQLBindParameter(hStmt_Insert, 3, SQL_PARAM_INPUT, SQL_C_DEFAULT, 5, 0, 0, (SQLPOINTER)OAREA.constData(), 0, &cbOAREA);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Parameters: Ordinal [4] Type: 4 Buffer Size: 4 FieldName: OPAGE ";
		r = SQLBindParameter(hStmt_Insert, 4, SQL_PARAM_INPUT, SQL_C_DEFAULT, 4, 0, 0, (SQLPOINTER)OPAGE.constData(), 0, &cbOPAGE);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Parameters: Ordinal [5] Type: 5 Buffer Size: 2 FieldName: OLINE ";
		r = SQLBindParameter(hStmt_Insert, 5, SQL_PARAM_INPUT, SQL_C_DEFAULT, 5, 0, 0, (SQLPOINTER)OLINE.constData(), 0, &cbOLINE);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Parameters: Ordinal [6] Type: 5 Buffer Size: 2 FieldName: MAREA ";
		r = SQLBindParameter(hStmt_Insert, 6, SQL_PARAM_INPUT, SQL_C_DEFAULT, 5, 0, 0, (SQLPOINTER)MAREA.constData(), 0, &cbMAREA);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Parameters: Ordinal [7] Type: 4 Buffer Size: 4 FieldName: MPAGE ";
		r = SQLBindParameter(hStmt_Insert, 7, SQL_PARAM_INPUT, SQL_C_DEFAULT, 4, 0, 0, (SQLPOINTER)MPAGE.constData(), 0, &cbMPAGE);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Parameters: Ordinal [8] Type: 5 Buffer Size: 2 FieldName: MLINE ";
		r = SQLBindParameter(hStmt_Insert, 8, SQL_PARAM_INPUT, SQL_C_DEFAULT, 5, 0, 0, (SQLPOINTER)MLINE.constData(), 0, &cbMLINE);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
	}
	if (m_ReplicationOption == ReplicationOption::NetChange)
	{
		r = SQLBindParameter(hStmt_Update, 9, SQL_PARAM_INPUT, SQL_C_DEFAULT, 6, 0, 0, (SQLPOINTER)MAREA.constData(), 0, &cbMAREA);
		if (r == SQL_SUCCESS) { isValid=true; }
		r = SQLBindParameter(hStmt_Update, 10, SQL_PARAM_INPUT, SQL_C_DEFAULT, 7, 0, 0, (SQLPOINTER)MPAGE.constData(), 0, &cbMPAGE);
		if (r == SQL_SUCCESS) { isValid=true; }
		r = SQLBindParameter(hStmt_Update, 11, SQL_PARAM_INPUT, SQL_C_DEFAULT, 8, 0, 0, (SQLPOINTER)MLINE.constData(), 0, &cbMLINE);
		if (r == SQL_SUCCESS) { isValid=true; }
	// TK_CNVHSHSET is a well formed table for eNVy Replication 
		 qDebug(category) << " Parameters: Ordinal [6] 00 00 FieldName: MAREA ";
		 qDebug(category) << " Parameters: Ordinal [7] 00 00  FieldName: MPAGE ";
		 qDebug(category) << " Parameters: Ordinal [8] 00 00 FieldName:  MLINE ";
	} // 	if (m_ReplicationOption == ReplicationOption::NetChange)
	return isValid;
}

bool TK_CNVHSHSET::process(int rowSize)
{
	QLoggingCategory category("classLibQ");
	initOdbcAttributes();
	connect(Source);
	connect(Target);
	initialize();
	prepareTargetTable();
	prepare();
	bindColumn();
	bindParameter();
	copyTable();
	close();
	return false;
}

void TK_CNVHSHSET::copyTable()
{
	QLoggingCategory category("classLibQ");
	RETCODE r;
	QString check;
	r = SQLExecute(hStmt_Fetch);
		if (bIsAbort) {
			emit aborted(tableName, rowsFetched, rowsInserted, rowsUpdated);
			return;
		}
		while((r = SQLFetch(hStmt_Fetch)) != SQL_NO_DATA) {
		if (r != SQL_SUCCESS) {
			check = qWarnODBCHandle(SQL_HANDLE_STMT, hStmt_Fetch);
			qCCritical(category) << QString("SqlFetch - Error : %1 is %2").arg(fetchSql).arg(check);
			return;
		} 
		rowsFetched++;
		if (m_ReplicationOption == ReplicationOption::BulkCopy)
		{
			r = SQLExecute(hStmt_Insert);
			if (r == SQL_ERROR) {
				check = qWarnODBCHandle(SQL_HANDLE_STMT, hStmt_Insert);
				 qCCritical(category) << QString("SqlExecute:Insert - Error : %1 is %2").arg(insertSql).arg(check);
				return;
			}
			rowsInserted++;
			if ((rowsFetched % updateInterval) == 0) {
				qCInfo(category) << QString("[%1.%2]	Insertion: %3	Updates : %4	Fetched : %5").arg(profileName).arg(tableName).arg(rowsInserted).arg(rowsUpdated).arg(rowsFetched);
				emit updateStatusFetched(profileName, tableName, rowsFetched,rowsInserted,rowsUpdated);
			}
			if (m_ReplicationOption == ReplicationOption::NetChange)
			{
			r = SQLExecute(hStmt_Update);
			if (r != SQL_SUCCESS) {
				check = qWarnODBCHandle(SQL_HANDLE_STMT, hStmt_Update);
				 qCInfo(category)  << QString("SqlExecute:Update - Error : %1 is %2").arg(updateSql).arg(check);
				r = SQLExecute(hStmt_Insert);
				if (r != SQL_SUCCESS) {
					check = qWarnODBCHandle(SQL_HANDLE_STMT, hStmt_Insert);
					 qCritical(category) << QString("SqlExecute:Insert - Error : %1 is %2").arg(insertSql).arg(check);
					return;
				}
				else 	rowsInserted++;
				}
				else	rowsUpdated++;
			}
			emit updateStatusFetched(profileName, tableName, rowsFetched,rowsInserted,rowsUpdated);
		}
	} 
qCInfo(category) << QString("[%1.%2]	Insertion: %3	Updates : %4	Fetched : %5").arg(profileName).arg(tableName).arg(rowsInserted).arg(rowsUpdated).arg(rowsFetched);
}

void TK_CNVHSHSET::connect(connectionHandle connectionSource)
{

	QLoggingCategory category("classLibQ");
	RETCODE r;

	bool isValid = false;
	HWND	hWnd = nullptr;
	hWnd = ::GetDesktopWindow(); 
	SQLSMALLINT nResult = 0;

	SQLSMALLINT cb;
	UWORD wConnectOption = SQL_DRIVER_COMPLETE; //SQL_DRIVER_NOPROMPT;
	QVarLengthArray<SQLTCHAR> connOut(1024);
	memset(connOut.data(), 0, connOut.size() * sizeof(SQLTCHAR));

	switch (connectionSource)
	{
		case Source:
			{// environment
				SQLHANDLE hEnv = SQL_NULL_HANDLE;
				SQLHANDLE hDbc = SQL_NULL_HANDLE;
				r = ::SQLAllocHandle(SQL_HANDLE_ENV, SQL_NULL_HANDLE, &hEnv);
				if (r == SQL_SUCCESS) isValid = true;

				foreach(nOdbcAttributesClass * k, this->m_OdbcAttributes_Map)
				{
					if (k->attributeType == enumAttributeType::hEnv)
					{
						r = ::SQLSetEnvAttr(hEnv, (SQLINTEGER) k->odbcKey, (SQLPOINTER)k->odbcValue, 0);
						if (r == SQL_SUCCESS) isValid = true;
					}
				}
				hEnv_Source = hEnv;

				r = SQLAllocHandle(SQL_HANDLE_DBC, hEnv, &hDbc);
				if (r == SQL_SUCCESS) isValid = true;
				foreach(nOdbcAttributesClass * k, this->m_OdbcAttributes_Map)
				{
					if (k->attributeType == enumAttributeType::hDbc)
					{
					r = ::SQLSetConnectAttr(hDbc, k->odbcKey, (SQLPOINTER)k->odbcValue, 0);
					if (k->odbcKey == SQL_ATTR_CONNECTION_POOLING && k->odbcValue == SQL_CP_ONE_PER_DRIVER) wConnectOption = SQL_DRIVER_NOPROMPT;
					if (k->odbcKey == SQL_ATTR_CONNECTION_POOLING && k->odbcValue == SQL_CP_ONE_PER_HENV) wConnectOption = SQL_DRIVER_NOPROMPT;
					if (k->odbcKey == SQL_ATTR_CONNECTION_POOLING && k->odbcValue == SQL_CP_DRIVER_AWARE) wConnectOption = SQL_DRIVER_NOPROMPT;
					if (r == SQL_SUCCESS) isValid = true;
					}
				}
				hDbc_source = hDbc;
				if (isValid)
				{
					r = ::SQLDriverConnect(
						hDbc,
						hWnd,
#ifdef UNICODE
						toSQLTCHAR(m_lpszSourceDSN).data(),
#else
						(SQLCHAR*)dsnSource.toUtf8().data(),
#endif
						(SQLSMALLINT)m_lpszSourceDSN.length(),
						connOut.data(),
						1024,
						&cb, 
						wConnectOption); 
					int colSize = cb / sizeof(SQLTCHAR);
					if (r != SQL_SUCCESS && r != SQL_SUCCESS_WITH_INFO)
					{
						QString check = qWarnODBCHandle(SQL_HANDLE_DBC, hDbc);
						qCritical(category) <<  check;
						m_bIsOpen = false;
					}
					m_bIsOpen = true;
				}
			} break;
		case Target:
			{
				SQLHANDLE hEnv = SQL_NULL_HANDLE;
				SQLHANDLE hDbc = SQL_NULL_HANDLE;
				r = ::SQLAllocHandle(SQL_HANDLE_ENV, SQL_NULL_HANDLE, &hEnv);
				if (r == SQL_SUCCESS) isValid = true;

				foreach(nOdbcAttributesClass * k, this->m_OdbcAttributes_Map)
				{
					if (k->attributeType == enumAttributeType::hEnv)
					{
						r = ::SQLSetEnvAttr(hEnv, (SQLINTEGER) k->odbcKey, (SQLPOINTER)k->odbcValue, 0);
						if (r == SQL_SUCCESS) isValid = true;
					}
				}
				hEnv_Target = hEnv;

				r = SQLAllocHandle(SQL_HANDLE_DBC, hEnv, &hDbc);
				if (r == SQL_SUCCESS) isValid = true;
				foreach(nOdbcAttributesClass * k, this->m_OdbcAttributes_Map)
				{
				if (k->attributeType == enumAttributeType::hDbc)
					{
					r = ::SQLSetConnectAttr(hDbc, k->odbcKey, (SQLPOINTER)k->odbcValue, 0);
					if (k->odbcKey == SQL_ATTR_CONNECTION_POOLING && k->odbcValue == SQL_CP_ONE_PER_DRIVER) wConnectOption = SQL_DRIVER_NOPROMPT;
					if (k->odbcKey == SQL_ATTR_CONNECTION_POOLING && k->odbcValue == SQL_CP_ONE_PER_HENV) wConnectOption = SQL_DRIVER_NOPROMPT;
					if (k->odbcKey == SQL_ATTR_CONNECTION_POOLING && k->odbcValue == SQL_CP_DRIVER_AWARE) wConnectOption = SQL_DRIVER_NOPROMPT;
					if (r == SQL_SUCCESS) isValid = true;
					}
				}
				hDbc_target = hDbc;
				if (isValid) {
					r = ::SQLDriverConnect(
						hDbc,
						hWnd,
#ifdef UNICODE
						toSQLTCHAR(m_lpszTargetDSN).data(),
#else
						(SQLCHAR*)m_lpszTargetDSN.toUtf8().data(),
#endif
						(SQLSMALLINT)m_lpszTargetDSN.length(),
						connOut.data(),
						1024,
						&cb, 
						wConnectOption); 
						int colSize = cb / sizeof(SQLTCHAR);
					if (r != SQL_SUCCESS && r != SQL_SUCCESS_WITH_INFO)
						{
							QString check = qWarnODBCHandle(SQL_HANDLE_DBC, hDbc);
							qCritical(category) <<  check;
							m_bIsOpen = false;
						}
							m_bIsOpen = true;
					}
			} break;
			default: break;
	}
}
TK_LTPHSHSET::TK_LTPHSHSET(QObject * parent) : QObject(parent) 
,tableName("TK_LTPHSHSET")
,m_dropOption(DropOption::DropTable) { 
	numRowsFetched = 0;
}

#pragma region ~CTOR TK_LTPHSHSET 
TK_LTPHSHSET::~TK_LTPHSHSET() { 

#pragma region Buffers - Clear 
	DB_ID.clear();
	NVTIMESTAMP.clear();
	OAREA.clear();
	OPAGE.clear();
	OLINE.clear();
	MAREA.clear();
	MPAGE.clear();
	MLINE.clear();
#pragma endregion Buffers - Clear 
}
#pragma endregion Destructor_TK_LTPHSHSET

// begin method functions
void TK_LTPHSHSET::setAbortFlag() { 
	QLoggingCategory category("classLibQ");
	qCInfo(category) << "isAbort was set to True";
	bIsAbort = true;
}

void TK_LTPHSHSET::run() { 
	process(1);
	QLoggingCategory category("classLibQ");
	qDebug(category) << "Entered;";
}

void	TK_LTPHSHSET::initOdbcAttributes()
{
	QLoggingCategory category("classLibQ");
	this->setProfileName(profileName);
	qDebug(category) << "Processing - TRKDB100"; 
	m_OdbcAttributesList = m_OdbcAttributes.split(","); 
	foreach(QString m, m_OdbcAttributesList)
	{
		QStringList keyValue = m.split("=");
		nOdbcAttributesClass * oM = new nOdbcAttributesClass(this);
		if (oM->loadToOdbc(keyValue.value(0), keyValue.value(1)))
		{
			m_OdbcAttributes_Map.insert(oM->odbcKey, oM);
		}
	}
}
void	TK_LTPHSHSET::initialize()
{
	QLoggingCategory category("classLibQ");
	RETCODE r;
	this->setProfileName(profileName);
	qDebug(category) << "Processing - TRKDB100"; 
//SQL Statements
//--------------------------------------------------

#pragma region Sql Statements_TK_LTPHSHSET

	fetchSql = "select  DB_ID, NVTIMESTAMP, OAREA, OPAGE, OLINE, MAREA, MPAGE, MLINE from TK_LTPHSHSET";
		if (m_ReplicationOption == ReplicationOption::NetChange)
		{
			fetchSql.append(" p1, nv_transfers p2 WHERE  p2.table_name = 'TK_LTPHSHSET' AND p1.nvtimestamp > p2.last_completed");
		}
	insertSql = "insert into TK_LTPHSHSET ( PLANT_CODE, NVTIMESTAMP, OAREA, OPAGE, OLINE, MAREA, MPAGE, MLINE ) values ( ?, ?, ?, ?, ?, ?, ?, ?)";
	updateSql = "update TK_LTPHSHSET set  PLANT_CODE = ?, NVTIMESTAMP = ?, OAREA = ?, OPAGE = ?, OLINE = ?, MAREA = ?, MPAGE = ?, MLINE = ?  where area = ? and page = ? line = ? ";

	qDebug(category) << "insertSQL - insert into TK_LTPHSHSET ( PLANT_CODE, NVTIMESTAMP, OAREA, OPAGE, OLINE, MAREA, MPAGE, MLINE ) values ( ?, ?, ?, ?, ?, ?, ?, ?)";
	qDebug(category) << "fetchSQL - select  DB_ID, NVTIMESTAMP, OAREA, OPAGE, OLINE, MAREA, MPAGE, MLINE from TK_LTPHSHSET";
	qDebug(category) << "unsertSQL - update TK_LTPHSHSET set  PLANT_CODE = ?, NVTIMESTAMP = ?, OAREA = ?, OPAGE = ?, OLINE = ?, MAREA = ?, MPAGE = ?, MLINE = ?  where area = ? and page = ? line = ? ";

#pragma endregion Sql Statements_TK_LTPHSHSET
	SQLHANDLE		insert_hStmt = SQL_NULL_HANDLE;
	SQLHANDLE		fetch_hStmt = SQL_NULL_HANDLE; 
	SQLHANDLE		update_hStmt = SQL_NULL_HANDLE; 
 
	r = ::SQLAllocHandle(SQL_HANDLE_STMT, hDbc_source, &fetch_hStmt);
	if (r != SQL_SUCCESS) {
		 qCCritical(category) << QString("Error  hDbc_Source SQLCode : %1 is %2").arg(QString::number( (long)hDbc_source)).arg(QString::number(r));
		return; 
	}
	r = ::SQLAllocHandle(SQL_HANDLE_STMT, hDbc_target, &insert_hStmt);
	if (r != SQL_SUCCESS) {
		 qCCritical(category) << QString("Error hDbc_Source -SQLCode: %1 is %2").arg(QString::number( (long)hDbc_target)).arg(QString::number(r));
		return; 
	}
	r = ::SQLAllocHandle(SQL_HANDLE_STMT, hDbc_target, &update_hStmt);
	if (r != SQL_SUCCESS) {
		 qCCritical(category) << QString("Error hDbc_Source +SQLCode: %1 is %2").arg(QString::number( (long)hDbc_target)).arg(QString::number(r));
		return; 
	}
 
	hStmt_Fetch = fetch_hStmt;
	hStmt_Insert = insert_hStmt;
	hStmt_Update = update_hStmt;
 
	SQLSetStmtAttr(hStmt_Fetch, SQL_ATTR_USE_BOOKMARKS, (SQLPOINTER)SQL_UB_OFF, 0);
	SQLSetStmtAttr(hStmt_Fetch, SQL_ATTR_ROW_BIND_TYPE, (SQLPOINTER)SQL_BIND_BY_COLUMN, 0);
	SQLSetStmtAttr(hStmt_Fetch, SQL_ATTR_ROW_ARRAY_SIZE, (SQLPOINTER)1, 0);
	SQLSetStmtAttr(hStmt_Fetch, SQL_ATTR_ROWS_FETCHED_PTR, &numRowsFetched, 0);

// Fields used by this class 
// ---------------------------------------------------

#pragma region Resize Fields TK_LTPHSHSET
	qDebug(category) << "Malloc - DB_ID[2]";
	DB_ID.resize(2);
	qDebug(category) << "Malloc - NVTIMESTAMP[23]";
	NVTIMESTAMP.resize(23);
	qDebug(category) << "Malloc - OAREA[2]";
	OAREA.resize(2);
	qDebug(category) << "Malloc - OPAGE[4]";
	OPAGE.resize(4);
	qDebug(category) << "Malloc - OLINE[2]";
	OLINE.resize(2);
	qDebug(category) << "Malloc - MAREA[2]";
	MAREA.resize(2);
	qDebug(category) << "Malloc - MPAGE[4]";
	MPAGE.resize(4);
	qDebug(category) << "Malloc - MLINE[2]";
	MLINE.resize(2);

#pragma endregion Resize Fields TK_LTPHSHSET
}
void TK_LTPHSHSET::close()
{
	QLoggingCategory category("classLibQ");
	if (m_bIsOpen)
	{
	qDebug(category) << "database is Open";
		SQLHANDLE source_hStmt = hStmt_Fetch;
		SQLHANDLE insert_hStmt = hStmt_Insert;
		SQLHANDLE hDb_S = this->hDbc_source;
		SQLHANDLE hDb_T = hDbc_target;
		SQLHANDLE hEnvS = hEnv_Source;
		SQLHANDLE hEnvT = hEnv_Target;
		RETCODE r;

		r = ::SQLFreeHandle(SQL_HANDLE_STMT, hStmt_Fetch);
		r = ::SQLFreeHandle(SQL_HANDLE_STMT, hStmt_Insert);
		r = ::SQLFreeHandle(SQL_HANDLE_STMT, hStmt_Update);
		if (hDbc_source != SQL_NULL_HANDLE) 		r = ::SQLDisconnect(hDb_S);
		if (hDbc_target != SQL_NULL_HANDLE) 		r = ::SQLDisconnect(hDb_T);

		r = ::SQLFreeHandle(SQL_HANDLE_DBC, hDb_S);
		r = ::SQLFreeHandle(SQL_HANDLE_DBC, hDb_T);
		r = ::SQLFreeHandle(SQL_HANDLE_ENV, hEnvS);
		r = ::SQLFreeHandle(SQL_HANDLE_ENV, hEnvT);
	}

	hEnv_Source = SQL_NULL_HANDLE;
	hEnv_Target = SQL_NULL_HANDLE;
	hEnv_Source = SQL_NULL_HANDLE;
	hEnv_Target = SQL_NULL_HANDLE;
	hStmt_Fetch = SQL_NULL_HANDLE;
	hStmt_Insert = SQL_NULL_HANDLE;
	hStmt_Update = SQL_NULL_HANDLE;
}

void TK_LTPHSHSET::open(const QString sourceDSN, const QString targetDSN)
{
	QLoggingCategory category("classLibQ");
	m_lpszTargetDSN = targetDSN;
	m_lpszSourceDSN = sourceDSN;
	qDebug(category) << QString("Source - %1[%2]").arg(sourceDSN);
	qDebug(category) << QString("Target - %1[%2]").arg(targetDSN);
}

void TK_LTPHSHSET::createTable()
{
	QLoggingCategory category("classLibQ");
	{
		QScopedPointer<nvTableOracleRdb> tbl(new nvTableOracleRdb(nullptr));
		tbl->initialize("TK_LTPHSHSET", this->m_lpszSourceDSN);
		QString newTbl = tbl->getCreateTableSQL();
		QScopedPointer<qVtExecute> vExec(new qVtExecute(nullptr));
		{
			vExec->initialize(m_lpszTargetDSN, " ", true);
			vExec->setOdbcAttributes(m_OdbcAttributes);
			vExec->ExecuteDirect(newTbl);
		}
	 qDebug(category) << QString("End Create Table %1 ").arg(tableName); 
	}
}

bool TK_LTPHSHSET::prepare()
{
	RETCODE r;
	QString check;
	QLoggingCategory category("classLibQ");
	 qDebug(category) << fetchSql;
	 qDebug(category) << insertSql;
#ifdef UNICODE
	r = SQLPrepare(hStmt_Insert,toSQLTCHAR(insertSql).data(),(SQLINTEGER)insertSql.length()); 
	if (r != SQL_SUCCESS) {
		check = qWarnODBCHandle(SQL_HANDLE_STMT, hStmt_Insert);
		 qCCritical(category) << QString("Prepare Statement-Insert : %1 is %2").arg(insertSql).arg(check);
		return false; 
	}
	r = SQLPrepare(hStmt_Update,toSQLTCHAR(updateSql).data(),(SQLINTEGER)updateSql.length()); 
	if (r != SQL_SUCCESS) {
		check = qWarnODBCHandle(SQL_HANDLE_STMT, hStmt_Update);
		 qCCritical(category) << QString("Prepare Statement-Update : %1 is %2").arg(updateSql).arg(check);
		return false; 
	}
	r = SQLPrepare(hStmt_Fetch,toSQLTCHAR(fetchSql).data(),(SQLINTEGER)fetchSql.length());
	if (r != SQL_SUCCESS) {
		check = qWarnODBCHandle(SQL_HANDLE_STMT, hStmt_Fetch);
		 qCCritical(category) << QString("Prepare Statement-Insert : %1 is %2").arg(fetchSql).arg(check);
		return false; 
	}
#else
	QByteArray queryI8 = insertSql.toUtf8();
	r = SQLPrepare(insert_hStmt,SQLCHAR*)queryI8.data(),(SQLINTEGER)queryI8.length());
	QByteArray queryU8 = fetchSql.toUtf8();
	r = SQLPrepare(hStmt_Fetch,(SQLCHAR*)queryU8.data(),(SQLINTEGER)queryU8.length());
#endif
	return true;

}

void TK_LTPHSHSET::prepareTargetTable()
{
	QLoggingCategory category("classLibQ");
	if (this->m_ReplicationOption == ReplicationOption::BulkCopy)
	{
		QScopedPointer<qVtExecute> execSql(new qVtExecute(nullptr));
		DropOption option = this->m_dropOption;
		switch (option)
		{
			case DropOption::DeleteFromTable:
			{
				QLoggingCategory category("classLibQ");
				execSql->initialize(this->m_lpszTargetDSN, "delete from TK_LTPHSHSET", true);
				execSql->setOdbcAttributes(this->m_OdbcAttributes);
				execSql->ExecuteDirect("delete from TK_LTPHSHSET");
			}break;
			case DropOption::TruncateTable:
			{
				execSql->initialize(this->m_lpszTargetDSN, "truncate table TK_LTPHSHSET", true);
				execSql->setOdbcAttributes(this->m_OdbcAttributes);
				execSql->ExecuteDirect("truncate table TK_LTPHSHSET");
			}break;
			case DropOption::DropTable:
			{
				execSql->initialize(this->m_lpszTargetDSN, "drop table TK_LTPHSHSET", true);
				execSql->setOdbcAttributes(this->m_OdbcAttributes);
				execSql->ExecuteDirect("drop table TK_LTPHSHSET");
				createTable();
			}break;
		}
	}
}

bool TK_LTPHSHSET::bindColumn()
{
	QLoggingCategory category("classLibQ");
	RETCODE r;
	bool isValid=true;
		 qDebug(category) << " Bindings: Ordinal [1] Type: 5 Buffer Size: 2 FieldName: DB_ID ";
		r = ::SQLBindCol(hStmt_Fetch, 1, 5, DB_ID.data(), 2, &cbDB_ID);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Bindings: Ordinal [2] Type: 93 Buffer Size: 23 FieldName: NVTIMESTAMP ";
		r = ::SQLBindCol(hStmt_Fetch, 2, 93, NVTIMESTAMP.data(), 23, &cbNVTIMESTAMP);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Bindings: Ordinal [3] Type: 5 Buffer Size: 2 FieldName: OAREA ";
		r = ::SQLBindCol(hStmt_Fetch, 3, 5, OAREA.data(), 2, &cbOAREA);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Bindings: Ordinal [4] Type: 4 Buffer Size: 4 FieldName: OPAGE ";
		r = ::SQLBindCol(hStmt_Fetch, 4, 4, OPAGE.data(), 4, &cbOPAGE);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Bindings: Ordinal [5] Type: 5 Buffer Size: 2 FieldName: OLINE ";
		r = ::SQLBindCol(hStmt_Fetch, 5, 5, OLINE.data(), 2, &cbOLINE);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Bindings: Ordinal [6] Type: 5 Buffer Size: 2 FieldName: MAREA ";
		r = ::SQLBindCol(hStmt_Fetch, 6, 5, MAREA.data(), 2, &cbMAREA);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Bindings: Ordinal [7] Type: 4 Buffer Size: 4 FieldName: MPAGE ";
		r = ::SQLBindCol(hStmt_Fetch, 7, 4, MPAGE.data(), 4, &cbMPAGE);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Bindings: Ordinal [8] Type: 5 Buffer Size: 2 FieldName: MLINE ";
		r = ::SQLBindCol(hStmt_Fetch, 8, 5, MLINE.data(), 2, &cbMLINE);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
	return isValid;
}

bool TK_LTPHSHSET::bindParameter()
{
	QLoggingCategory category("classLibQ");
	RETCODE r;
	bool isValid=true;
	{
		 qDebug(category) << " Parameters: Ordinal [1] Type: 5 Buffer Size: 2 FieldName: DB_ID ";
		r = SQLBindParameter(hStmt_Insert, 1, SQL_PARAM_INPUT, SQL_C_DEFAULT, 5, 0, 0, (SQLPOINTER)DB_ID.constData(), 0, &cbDB_ID);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Parameters: Ordinal [2] Type: 93 Buffer Size: 23 FieldName: NVTIMESTAMP ";
		r = SQLBindParameter(hStmt_Insert, 2, SQL_PARAM_INPUT, SQL_C_DEFAULT, 93, 23, 0, (SQLPOINTER)NVTIMESTAMP.constData(), 0, &cbNVTIMESTAMP);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Parameters: Ordinal [3] Type: 5 Buffer Size: 2 FieldName: OAREA ";
		r = SQLBindParameter(hStmt_Insert, 3, SQL_PARAM_INPUT, SQL_C_DEFAULT, 5, 0, 0, (SQLPOINTER)OAREA.constData(), 0, &cbOAREA);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Parameters: Ordinal [4] Type: 4 Buffer Size: 4 FieldName: OPAGE ";
		r = SQLBindParameter(hStmt_Insert, 4, SQL_PARAM_INPUT, SQL_C_DEFAULT, 4, 0, 0, (SQLPOINTER)OPAGE.constData(), 0, &cbOPAGE);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Parameters: Ordinal [5] Type: 5 Buffer Size: 2 FieldName: OLINE ";
		r = SQLBindParameter(hStmt_Insert, 5, SQL_PARAM_INPUT, SQL_C_DEFAULT, 5, 0, 0, (SQLPOINTER)OLINE.constData(), 0, &cbOLINE);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Parameters: Ordinal [6] Type: 5 Buffer Size: 2 FieldName: MAREA ";
		r = SQLBindParameter(hStmt_Insert, 6, SQL_PARAM_INPUT, SQL_C_DEFAULT, 5, 0, 0, (SQLPOINTER)MAREA.constData(), 0, &cbMAREA);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Parameters: Ordinal [7] Type: 4 Buffer Size: 4 FieldName: MPAGE ";
		r = SQLBindParameter(hStmt_Insert, 7, SQL_PARAM_INPUT, SQL_C_DEFAULT, 4, 0, 0, (SQLPOINTER)MPAGE.constData(), 0, &cbMPAGE);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Parameters: Ordinal [8] Type: 5 Buffer Size: 2 FieldName: MLINE ";
		r = SQLBindParameter(hStmt_Insert, 8, SQL_PARAM_INPUT, SQL_C_DEFAULT, 5, 0, 0, (SQLPOINTER)MLINE.constData(), 0, &cbMLINE);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
	}
	if (m_ReplicationOption == ReplicationOption::NetChange)
	{
		r = SQLBindParameter(hStmt_Update, 9, SQL_PARAM_INPUT, SQL_C_DEFAULT, 6, 0, 0, (SQLPOINTER)MAREA.constData(), 0, &cbMAREA);
		if (r == SQL_SUCCESS) { isValid=true; }
		r = SQLBindParameter(hStmt_Update, 10, SQL_PARAM_INPUT, SQL_C_DEFAULT, 7, 0, 0, (SQLPOINTER)MPAGE.constData(), 0, &cbMPAGE);
		if (r == SQL_SUCCESS) { isValid=true; }
		r = SQLBindParameter(hStmt_Update, 11, SQL_PARAM_INPUT, SQL_C_DEFAULT, 8, 0, 0, (SQLPOINTER)MLINE.constData(), 0, &cbMLINE);
		if (r == SQL_SUCCESS) { isValid=true; }
	// TK_LTPHSHSET is a well formed table for eNVy Replication 
		 qDebug(category) << " Parameters: Ordinal [6] 00 00 FieldName: MAREA ";
		 qDebug(category) << " Parameters: Ordinal [7] 00 00  FieldName: MPAGE ";
		 qDebug(category) << " Parameters: Ordinal [8] 00 00 FieldName:  MLINE ";
	} // 	if (m_ReplicationOption == ReplicationOption::NetChange)
	return isValid;
}

bool TK_LTPHSHSET::process(int rowSize)
{
	QLoggingCategory category("classLibQ");
	initOdbcAttributes();
	connect(Source);
	connect(Target);
	initialize();
	prepareTargetTable();
	prepare();
	bindColumn();
	bindParameter();
	copyTable();
	close();
	return false;
}

void TK_LTPHSHSET::copyTable()
{
	QLoggingCategory category("classLibQ");
	RETCODE r;
	QString check;
	r = SQLExecute(hStmt_Fetch);
		if (bIsAbort) {
			emit aborted(tableName, rowsFetched, rowsInserted, rowsUpdated);
			return;
		}
		while((r = SQLFetch(hStmt_Fetch)) != SQL_NO_DATA) {
		if (r != SQL_SUCCESS) {
			check = qWarnODBCHandle(SQL_HANDLE_STMT, hStmt_Fetch);
			qCCritical(category) << QString("SqlFetch - Error : %1 is %2").arg(fetchSql).arg(check);
			return;
		} 
		rowsFetched++;
		if (m_ReplicationOption == ReplicationOption::BulkCopy)
		{
			r = SQLExecute(hStmt_Insert);
			if (r == SQL_ERROR) {
				check = qWarnODBCHandle(SQL_HANDLE_STMT, hStmt_Insert);
				 qCCritical(category) << QString("SqlExecute:Insert - Error : %1 is %2").arg(insertSql).arg(check);
				return;
			}
			rowsInserted++;
			if ((rowsFetched % updateInterval) == 0) {
				qCInfo(category) << QString("[%1.%2]	Insertion: %3	Updates : %4	Fetched : %5").arg(profileName).arg(tableName).arg(rowsInserted).arg(rowsUpdated).arg(rowsFetched);
				emit updateStatusFetched(profileName, tableName, rowsFetched,rowsInserted,rowsUpdated);
			}
			if (m_ReplicationOption == ReplicationOption::NetChange)
			{
			r = SQLExecute(hStmt_Update);
			if (r != SQL_SUCCESS) {
				check = qWarnODBCHandle(SQL_HANDLE_STMT, hStmt_Update);
				 qCInfo(category)  << QString("SqlExecute:Update - Error : %1 is %2").arg(updateSql).arg(check);
				r = SQLExecute(hStmt_Insert);
				if (r != SQL_SUCCESS) {
					check = qWarnODBCHandle(SQL_HANDLE_STMT, hStmt_Insert);
					 qCritical(category) << QString("SqlExecute:Insert - Error : %1 is %2").arg(insertSql).arg(check);
					return;
				}
				else 	rowsInserted++;
				}
				else	rowsUpdated++;
			}
			emit updateStatusFetched(profileName, tableName, rowsFetched,rowsInserted,rowsUpdated);
		}
	} 
qCInfo(category) << QString("[%1.%2]	Insertion: %3	Updates : %4	Fetched : %5").arg(profileName).arg(tableName).arg(rowsInserted).arg(rowsUpdated).arg(rowsFetched);
}

void TK_LTPHSHSET::connect(connectionHandle connectionSource)
{

	QLoggingCategory category("classLibQ");
	RETCODE r;

	bool isValid = false;
	HWND	hWnd = nullptr;
	hWnd = ::GetDesktopWindow(); 
	SQLSMALLINT nResult = 0;

	SQLSMALLINT cb;
	UWORD wConnectOption = SQL_DRIVER_COMPLETE; //SQL_DRIVER_NOPROMPT;
	QVarLengthArray<SQLTCHAR> connOut(1024);
	memset(connOut.data(), 0, connOut.size() * sizeof(SQLTCHAR));

	switch (connectionSource)
	{
		case Source:
			{// environment
				SQLHANDLE hEnv = SQL_NULL_HANDLE;
				SQLHANDLE hDbc = SQL_NULL_HANDLE;
				r = ::SQLAllocHandle(SQL_HANDLE_ENV, SQL_NULL_HANDLE, &hEnv);
				if (r == SQL_SUCCESS) isValid = true;

				foreach(nOdbcAttributesClass * k, this->m_OdbcAttributes_Map)
				{
					if (k->attributeType == enumAttributeType::hEnv)
					{
						r = ::SQLSetEnvAttr(hEnv, (SQLINTEGER) k->odbcKey, (SQLPOINTER)k->odbcValue, 0);
						if (r == SQL_SUCCESS) isValid = true;
					}
				}
				hEnv_Source = hEnv;

				r = SQLAllocHandle(SQL_HANDLE_DBC, hEnv, &hDbc);
				if (r == SQL_SUCCESS) isValid = true;
				foreach(nOdbcAttributesClass * k, this->m_OdbcAttributes_Map)
				{
					if (k->attributeType == enumAttributeType::hDbc)
					{
					r = ::SQLSetConnectAttr(hDbc, k->odbcKey, (SQLPOINTER)k->odbcValue, 0);
					if (k->odbcKey == SQL_ATTR_CONNECTION_POOLING && k->odbcValue == SQL_CP_ONE_PER_DRIVER) wConnectOption = SQL_DRIVER_NOPROMPT;
					if (k->odbcKey == SQL_ATTR_CONNECTION_POOLING && k->odbcValue == SQL_CP_ONE_PER_HENV) wConnectOption = SQL_DRIVER_NOPROMPT;
					if (k->odbcKey == SQL_ATTR_CONNECTION_POOLING && k->odbcValue == SQL_CP_DRIVER_AWARE) wConnectOption = SQL_DRIVER_NOPROMPT;
					if (r == SQL_SUCCESS) isValid = true;
					}
				}
				hDbc_source = hDbc;
				if (isValid)
				{
					r = ::SQLDriverConnect(
						hDbc,
						hWnd,
#ifdef UNICODE
						toSQLTCHAR(m_lpszSourceDSN).data(),
#else
						(SQLCHAR*)dsnSource.toUtf8().data(),
#endif
						(SQLSMALLINT)m_lpszSourceDSN.length(),
						connOut.data(),
						1024,
						&cb, 
						wConnectOption); 
					int colSize = cb / sizeof(SQLTCHAR);
					if (r != SQL_SUCCESS && r != SQL_SUCCESS_WITH_INFO)
					{
						QString check = qWarnODBCHandle(SQL_HANDLE_DBC, hDbc);
						qCritical(category) <<  check;
						m_bIsOpen = false;
					}
					m_bIsOpen = true;
				}
			} break;
		case Target:
			{
				SQLHANDLE hEnv = SQL_NULL_HANDLE;
				SQLHANDLE hDbc = SQL_NULL_HANDLE;
				r = ::SQLAllocHandle(SQL_HANDLE_ENV, SQL_NULL_HANDLE, &hEnv);
				if (r == SQL_SUCCESS) isValid = true;

				foreach(nOdbcAttributesClass * k, this->m_OdbcAttributes_Map)
				{
					if (k->attributeType == enumAttributeType::hEnv)
					{
						r = ::SQLSetEnvAttr(hEnv, (SQLINTEGER) k->odbcKey, (SQLPOINTER)k->odbcValue, 0);
						if (r == SQL_SUCCESS) isValid = true;
					}
				}
				hEnv_Target = hEnv;

				r = SQLAllocHandle(SQL_HANDLE_DBC, hEnv, &hDbc);
				if (r == SQL_SUCCESS) isValid = true;
				foreach(nOdbcAttributesClass * k, this->m_OdbcAttributes_Map)
				{
				if (k->attributeType == enumAttributeType::hDbc)
					{
					r = ::SQLSetConnectAttr(hDbc, k->odbcKey, (SQLPOINTER)k->odbcValue, 0);
					if (k->odbcKey == SQL_ATTR_CONNECTION_POOLING && k->odbcValue == SQL_CP_ONE_PER_DRIVER) wConnectOption = SQL_DRIVER_NOPROMPT;
					if (k->odbcKey == SQL_ATTR_CONNECTION_POOLING && k->odbcValue == SQL_CP_ONE_PER_HENV) wConnectOption = SQL_DRIVER_NOPROMPT;
					if (k->odbcKey == SQL_ATTR_CONNECTION_POOLING && k->odbcValue == SQL_CP_DRIVER_AWARE) wConnectOption = SQL_DRIVER_NOPROMPT;
					if (r == SQL_SUCCESS) isValid = true;
					}
				}
				hDbc_target = hDbc;
				if (isValid) {
					r = ::SQLDriverConnect(
						hDbc,
						hWnd,
#ifdef UNICODE
						toSQLTCHAR(m_lpszTargetDSN).data(),
#else
						(SQLCHAR*)m_lpszTargetDSN.toUtf8().data(),
#endif
						(SQLSMALLINT)m_lpszTargetDSN.length(),
						connOut.data(),
						1024,
						&cb, 
						wConnectOption); 
						int colSize = cb / sizeof(SQLTCHAR);
					if (r != SQL_SUCCESS && r != SQL_SUCCESS_WITH_INFO)
						{
							QString check = qWarnODBCHandle(SQL_HANDLE_DBC, hDbc);
							qCritical(category) <<  check;
							m_bIsOpen = false;
						}
							m_bIsOpen = true;
					}
			} break;
			default: break;
	}
}
TK_INTPOSRTSET::TK_INTPOSRTSET(QObject * parent) : QObject(parent) 
,tableName("TK_INTPOSRTSET")
,m_dropOption(DropOption::DropTable) { 
	numRowsFetched = 0;
}

#pragma region ~CTOR TK_INTPOSRTSET 
TK_INTPOSRTSET::~TK_INTPOSRTSET() { 

#pragma region Buffers - Clear 
	DB_ID.clear();
	NVTIMESTAMP.clear();
	OAREA.clear();
	OPAGE.clear();
	OLINE.clear();
	MAREA.clear();
	MPAGE.clear();
	MLINE.clear();
#pragma endregion Buffers - Clear 
}
#pragma endregion Destructor_TK_INTPOSRTSET

// begin method functions
void TK_INTPOSRTSET::setAbortFlag() { 
	QLoggingCategory category("classLibQ");
	qCInfo(category) << "isAbort was set to True";
	bIsAbort = true;
}

void TK_INTPOSRTSET::run() { 
	process(1);
	QLoggingCategory category("classLibQ");
	qDebug(category) << "Entered;";
}

void	TK_INTPOSRTSET::initOdbcAttributes()
{
	QLoggingCategory category("classLibQ");
	this->setProfileName(profileName);
	qDebug(category) << "Processing - TRKDB100"; 
	m_OdbcAttributesList = m_OdbcAttributes.split(","); 
	foreach(QString m, m_OdbcAttributesList)
	{
		QStringList keyValue = m.split("=");
		nOdbcAttributesClass * oM = new nOdbcAttributesClass(this);
		if (oM->loadToOdbc(keyValue.value(0), keyValue.value(1)))
		{
			m_OdbcAttributes_Map.insert(oM->odbcKey, oM);
		}
	}
}
void	TK_INTPOSRTSET::initialize()
{
	QLoggingCategory category("classLibQ");
	RETCODE r;
	this->setProfileName(profileName);
	qDebug(category) << "Processing - TRKDB100"; 
//SQL Statements
//--------------------------------------------------

#pragma region Sql Statements_TK_INTPOSRTSET

	fetchSql = "select  DB_ID, NVTIMESTAMP, OAREA, OPAGE, OLINE, MAREA, MPAGE, MLINE from TK_INTPOSRTSET";
		if (m_ReplicationOption == ReplicationOption::NetChange)
		{
			fetchSql.append(" p1, nv_transfers p2 WHERE  p2.table_name = 'TK_INTPOSRTSET' AND p1.nvtimestamp > p2.last_completed");
		}
	insertSql = "insert into TK_INTPOSRTSET ( PLANT_CODE, NVTIMESTAMP, OAREA, OPAGE, OLINE, MAREA, MPAGE, MLINE ) values ( ?, ?, ?, ?, ?, ?, ?, ?)";
	updateSql = "update TK_INTPOSRTSET set  PLANT_CODE = ?, NVTIMESTAMP = ?, OAREA = ?, OPAGE = ?, OLINE = ?, MAREA = ?, MPAGE = ?, MLINE = ?  where area = ? and page = ? line = ? ";

	qDebug(category) << "insertSQL - insert into TK_INTPOSRTSET ( PLANT_CODE, NVTIMESTAMP, OAREA, OPAGE, OLINE, MAREA, MPAGE, MLINE ) values ( ?, ?, ?, ?, ?, ?, ?, ?)";
	qDebug(category) << "fetchSQL - select  DB_ID, NVTIMESTAMP, OAREA, OPAGE, OLINE, MAREA, MPAGE, MLINE from TK_INTPOSRTSET";
	qDebug(category) << "unsertSQL - update TK_INTPOSRTSET set  PLANT_CODE = ?, NVTIMESTAMP = ?, OAREA = ?, OPAGE = ?, OLINE = ?, MAREA = ?, MPAGE = ?, MLINE = ?  where area = ? and page = ? line = ? ";

#pragma endregion Sql Statements_TK_INTPOSRTSET
	SQLHANDLE		insert_hStmt = SQL_NULL_HANDLE;
	SQLHANDLE		fetch_hStmt = SQL_NULL_HANDLE; 
	SQLHANDLE		update_hStmt = SQL_NULL_HANDLE; 
 
	r = ::SQLAllocHandle(SQL_HANDLE_STMT, hDbc_source, &fetch_hStmt);
	if (r != SQL_SUCCESS) {
		 qCCritical(category) << QString("Error  hDbc_Source SQLCode : %1 is %2").arg(QString::number( (long)hDbc_source)).arg(QString::number(r));
		return; 
	}
	r = ::SQLAllocHandle(SQL_HANDLE_STMT, hDbc_target, &insert_hStmt);
	if (r != SQL_SUCCESS) {
		 qCCritical(category) << QString("Error hDbc_Source -SQLCode: %1 is %2").arg(QString::number( (long)hDbc_target)).arg(QString::number(r));
		return; 
	}
	r = ::SQLAllocHandle(SQL_HANDLE_STMT, hDbc_target, &update_hStmt);
	if (r != SQL_SUCCESS) {
		 qCCritical(category) << QString("Error hDbc_Source +SQLCode: %1 is %2").arg(QString::number( (long)hDbc_target)).arg(QString::number(r));
		return; 
	}
 
	hStmt_Fetch = fetch_hStmt;
	hStmt_Insert = insert_hStmt;
	hStmt_Update = update_hStmt;
 
	SQLSetStmtAttr(hStmt_Fetch, SQL_ATTR_USE_BOOKMARKS, (SQLPOINTER)SQL_UB_OFF, 0);
	SQLSetStmtAttr(hStmt_Fetch, SQL_ATTR_ROW_BIND_TYPE, (SQLPOINTER)SQL_BIND_BY_COLUMN, 0);
	SQLSetStmtAttr(hStmt_Fetch, SQL_ATTR_ROW_ARRAY_SIZE, (SQLPOINTER)1, 0);
	SQLSetStmtAttr(hStmt_Fetch, SQL_ATTR_ROWS_FETCHED_PTR, &numRowsFetched, 0);

// Fields used by this class 
// ---------------------------------------------------

#pragma region Resize Fields TK_INTPOSRTSET
	qDebug(category) << "Malloc - DB_ID[2]";
	DB_ID.resize(2);
	qDebug(category) << "Malloc - NVTIMESTAMP[23]";
	NVTIMESTAMP.resize(23);
	qDebug(category) << "Malloc - OAREA[2]";
	OAREA.resize(2);
	qDebug(category) << "Malloc - OPAGE[4]";
	OPAGE.resize(4);
	qDebug(category) << "Malloc - OLINE[2]";
	OLINE.resize(2);
	qDebug(category) << "Malloc - MAREA[2]";
	MAREA.resize(2);
	qDebug(category) << "Malloc - MPAGE[4]";
	MPAGE.resize(4);
	qDebug(category) << "Malloc - MLINE[2]";
	MLINE.resize(2);

#pragma endregion Resize Fields TK_INTPOSRTSET
}
void TK_INTPOSRTSET::close()
{
	QLoggingCategory category("classLibQ");
	if (m_bIsOpen)
	{
	qDebug(category) << "database is Open";
		SQLHANDLE source_hStmt = hStmt_Fetch;
		SQLHANDLE insert_hStmt = hStmt_Insert;
		SQLHANDLE hDb_S = this->hDbc_source;
		SQLHANDLE hDb_T = hDbc_target;
		SQLHANDLE hEnvS = hEnv_Source;
		SQLHANDLE hEnvT = hEnv_Target;
		RETCODE r;

		r = ::SQLFreeHandle(SQL_HANDLE_STMT, hStmt_Fetch);
		r = ::SQLFreeHandle(SQL_HANDLE_STMT, hStmt_Insert);
		r = ::SQLFreeHandle(SQL_HANDLE_STMT, hStmt_Update);
		if (hDbc_source != SQL_NULL_HANDLE) 		r = ::SQLDisconnect(hDb_S);
		if (hDbc_target != SQL_NULL_HANDLE) 		r = ::SQLDisconnect(hDb_T);

		r = ::SQLFreeHandle(SQL_HANDLE_DBC, hDb_S);
		r = ::SQLFreeHandle(SQL_HANDLE_DBC, hDb_T);
		r = ::SQLFreeHandle(SQL_HANDLE_ENV, hEnvS);
		r = ::SQLFreeHandle(SQL_HANDLE_ENV, hEnvT);
	}

	hEnv_Source = SQL_NULL_HANDLE;
	hEnv_Target = SQL_NULL_HANDLE;
	hEnv_Source = SQL_NULL_HANDLE;
	hEnv_Target = SQL_NULL_HANDLE;
	hStmt_Fetch = SQL_NULL_HANDLE;
	hStmt_Insert = SQL_NULL_HANDLE;
	hStmt_Update = SQL_NULL_HANDLE;
}

void TK_INTPOSRTSET::open(const QString sourceDSN, const QString targetDSN)
{
	QLoggingCategory category("classLibQ");
	m_lpszTargetDSN = targetDSN;
	m_lpszSourceDSN = sourceDSN;
	qDebug(category) << QString("Source - %1[%2]").arg(sourceDSN);
	qDebug(category) << QString("Target - %1[%2]").arg(targetDSN);
}

void TK_INTPOSRTSET::createTable()
{
	QLoggingCategory category("classLibQ");
	{
		QScopedPointer<nvTableOracleRdb> tbl(new nvTableOracleRdb(nullptr));
		tbl->initialize("TK_INTPOSRTSET", this->m_lpszSourceDSN);
		QString newTbl = tbl->getCreateTableSQL();
		QScopedPointer<qVtExecute> vExec(new qVtExecute(nullptr));
		{
			vExec->initialize(m_lpszTargetDSN, " ", true);
			vExec->setOdbcAttributes(m_OdbcAttributes);
			vExec->ExecuteDirect(newTbl);
		}
	 qDebug(category) << QString("End Create Table %1 ").arg(tableName); 
	}
}

bool TK_INTPOSRTSET::prepare()
{
	RETCODE r;
	QString check;
	QLoggingCategory category("classLibQ");
	 qDebug(category) << fetchSql;
	 qDebug(category) << insertSql;
#ifdef UNICODE
	r = SQLPrepare(hStmt_Insert,toSQLTCHAR(insertSql).data(),(SQLINTEGER)insertSql.length()); 
	if (r != SQL_SUCCESS) {
		check = qWarnODBCHandle(SQL_HANDLE_STMT, hStmt_Insert);
		 qCCritical(category) << QString("Prepare Statement-Insert : %1 is %2").arg(insertSql).arg(check);
		return false; 
	}
	r = SQLPrepare(hStmt_Update,toSQLTCHAR(updateSql).data(),(SQLINTEGER)updateSql.length()); 
	if (r != SQL_SUCCESS) {
		check = qWarnODBCHandle(SQL_HANDLE_STMT, hStmt_Update);
		 qCCritical(category) << QString("Prepare Statement-Update : %1 is %2").arg(updateSql).arg(check);
		return false; 
	}
	r = SQLPrepare(hStmt_Fetch,toSQLTCHAR(fetchSql).data(),(SQLINTEGER)fetchSql.length());
	if (r != SQL_SUCCESS) {
		check = qWarnODBCHandle(SQL_HANDLE_STMT, hStmt_Fetch);
		 qCCritical(category) << QString("Prepare Statement-Insert : %1 is %2").arg(fetchSql).arg(check);
		return false; 
	}
#else
	QByteArray queryI8 = insertSql.toUtf8();
	r = SQLPrepare(insert_hStmt,SQLCHAR*)queryI8.data(),(SQLINTEGER)queryI8.length());
	QByteArray queryU8 = fetchSql.toUtf8();
	r = SQLPrepare(hStmt_Fetch,(SQLCHAR*)queryU8.data(),(SQLINTEGER)queryU8.length());
#endif
	return true;

}

void TK_INTPOSRTSET::prepareTargetTable()
{
	QLoggingCategory category("classLibQ");
	if (this->m_ReplicationOption == ReplicationOption::BulkCopy)
	{
		QScopedPointer<qVtExecute> execSql(new qVtExecute(nullptr));
		DropOption option = this->m_dropOption;
		switch (option)
		{
			case DropOption::DeleteFromTable:
			{
				QLoggingCategory category("classLibQ");
				execSql->initialize(this->m_lpszTargetDSN, "delete from TK_INTPOSRTSET", true);
				execSql->setOdbcAttributes(this->m_OdbcAttributes);
				execSql->ExecuteDirect("delete from TK_INTPOSRTSET");
			}break;
			case DropOption::TruncateTable:
			{
				execSql->initialize(this->m_lpszTargetDSN, "truncate table TK_INTPOSRTSET", true);
				execSql->setOdbcAttributes(this->m_OdbcAttributes);
				execSql->ExecuteDirect("truncate table TK_INTPOSRTSET");
			}break;
			case DropOption::DropTable:
			{
				execSql->initialize(this->m_lpszTargetDSN, "drop table TK_INTPOSRTSET", true);
				execSql->setOdbcAttributes(this->m_OdbcAttributes);
				execSql->ExecuteDirect("drop table TK_INTPOSRTSET");
				createTable();
			}break;
		}
	}
}

bool TK_INTPOSRTSET::bindColumn()
{
	QLoggingCategory category("classLibQ");
	RETCODE r;
	bool isValid=true;
		 qDebug(category) << " Bindings: Ordinal [1] Type: 5 Buffer Size: 2 FieldName: DB_ID ";
		r = ::SQLBindCol(hStmt_Fetch, 1, 5, DB_ID.data(), 2, &cbDB_ID);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Bindings: Ordinal [2] Type: 93 Buffer Size: 23 FieldName: NVTIMESTAMP ";
		r = ::SQLBindCol(hStmt_Fetch, 2, 93, NVTIMESTAMP.data(), 23, &cbNVTIMESTAMP);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Bindings: Ordinal [3] Type: 5 Buffer Size: 2 FieldName: OAREA ";
		r = ::SQLBindCol(hStmt_Fetch, 3, 5, OAREA.data(), 2, &cbOAREA);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Bindings: Ordinal [4] Type: 4 Buffer Size: 4 FieldName: OPAGE ";
		r = ::SQLBindCol(hStmt_Fetch, 4, 4, OPAGE.data(), 4, &cbOPAGE);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Bindings: Ordinal [5] Type: 5 Buffer Size: 2 FieldName: OLINE ";
		r = ::SQLBindCol(hStmt_Fetch, 5, 5, OLINE.data(), 2, &cbOLINE);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Bindings: Ordinal [6] Type: 5 Buffer Size: 2 FieldName: MAREA ";
		r = ::SQLBindCol(hStmt_Fetch, 6, 5, MAREA.data(), 2, &cbMAREA);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Bindings: Ordinal [7] Type: 4 Buffer Size: 4 FieldName: MPAGE ";
		r = ::SQLBindCol(hStmt_Fetch, 7, 4, MPAGE.data(), 4, &cbMPAGE);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Bindings: Ordinal [8] Type: 5 Buffer Size: 2 FieldName: MLINE ";
		r = ::SQLBindCol(hStmt_Fetch, 8, 5, MLINE.data(), 2, &cbMLINE);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
	return isValid;
}

bool TK_INTPOSRTSET::bindParameter()
{
	QLoggingCategory category("classLibQ");
	RETCODE r;
	bool isValid=true;
	{
		 qDebug(category) << " Parameters: Ordinal [1] Type: 5 Buffer Size: 2 FieldName: DB_ID ";
		r = SQLBindParameter(hStmt_Insert, 1, SQL_PARAM_INPUT, SQL_C_DEFAULT, 5, 0, 0, (SQLPOINTER)DB_ID.constData(), 0, &cbDB_ID);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Parameters: Ordinal [2] Type: 93 Buffer Size: 23 FieldName: NVTIMESTAMP ";
		r = SQLBindParameter(hStmt_Insert, 2, SQL_PARAM_INPUT, SQL_C_DEFAULT, 93, 23, 0, (SQLPOINTER)NVTIMESTAMP.constData(), 0, &cbNVTIMESTAMP);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Parameters: Ordinal [3] Type: 5 Buffer Size: 2 FieldName: OAREA ";
		r = SQLBindParameter(hStmt_Insert, 3, SQL_PARAM_INPUT, SQL_C_DEFAULT, 5, 0, 0, (SQLPOINTER)OAREA.constData(), 0, &cbOAREA);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Parameters: Ordinal [4] Type: 4 Buffer Size: 4 FieldName: OPAGE ";
		r = SQLBindParameter(hStmt_Insert, 4, SQL_PARAM_INPUT, SQL_C_DEFAULT, 4, 0, 0, (SQLPOINTER)OPAGE.constData(), 0, &cbOPAGE);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Parameters: Ordinal [5] Type: 5 Buffer Size: 2 FieldName: OLINE ";
		r = SQLBindParameter(hStmt_Insert, 5, SQL_PARAM_INPUT, SQL_C_DEFAULT, 5, 0, 0, (SQLPOINTER)OLINE.constData(), 0, &cbOLINE);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Parameters: Ordinal [6] Type: 5 Buffer Size: 2 FieldName: MAREA ";
		r = SQLBindParameter(hStmt_Insert, 6, SQL_PARAM_INPUT, SQL_C_DEFAULT, 5, 0, 0, (SQLPOINTER)MAREA.constData(), 0, &cbMAREA);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Parameters: Ordinal [7] Type: 4 Buffer Size: 4 FieldName: MPAGE ";
		r = SQLBindParameter(hStmt_Insert, 7, SQL_PARAM_INPUT, SQL_C_DEFAULT, 4, 0, 0, (SQLPOINTER)MPAGE.constData(), 0, &cbMPAGE);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Parameters: Ordinal [8] Type: 5 Buffer Size: 2 FieldName: MLINE ";
		r = SQLBindParameter(hStmt_Insert, 8, SQL_PARAM_INPUT, SQL_C_DEFAULT, 5, 0, 0, (SQLPOINTER)MLINE.constData(), 0, &cbMLINE);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
	}
	if (m_ReplicationOption == ReplicationOption::NetChange)
	{
		r = SQLBindParameter(hStmt_Update, 9, SQL_PARAM_INPUT, SQL_C_DEFAULT, 6, 0, 0, (SQLPOINTER)MAREA.constData(), 0, &cbMAREA);
		if (r == SQL_SUCCESS) { isValid=true; }
		r = SQLBindParameter(hStmt_Update, 10, SQL_PARAM_INPUT, SQL_C_DEFAULT, 7, 0, 0, (SQLPOINTER)MPAGE.constData(), 0, &cbMPAGE);
		if (r == SQL_SUCCESS) { isValid=true; }
		r = SQLBindParameter(hStmt_Update, 11, SQL_PARAM_INPUT, SQL_C_DEFAULT, 8, 0, 0, (SQLPOINTER)MLINE.constData(), 0, &cbMLINE);
		if (r == SQL_SUCCESS) { isValid=true; }
	// TK_INTPOSRTSET is a well formed table for eNVy Replication 
		 qDebug(category) << " Parameters: Ordinal [6] 00 00 FieldName: MAREA ";
		 qDebug(category) << " Parameters: Ordinal [7] 00 00  FieldName: MPAGE ";
		 qDebug(category) << " Parameters: Ordinal [8] 00 00 FieldName:  MLINE ";
	} // 	if (m_ReplicationOption == ReplicationOption::NetChange)
	return isValid;
}

bool TK_INTPOSRTSET::process(int rowSize)
{
	QLoggingCategory category("classLibQ");
	initOdbcAttributes();
	connect(Source);
	connect(Target);
	initialize();
	prepareTargetTable();
	prepare();
	bindColumn();
	bindParameter();
	copyTable();
	close();
	return false;
}

void TK_INTPOSRTSET::copyTable()
{
	QLoggingCategory category("classLibQ");
	RETCODE r;
	QString check;
	r = SQLExecute(hStmt_Fetch);
		if (bIsAbort) {
			emit aborted(tableName, rowsFetched, rowsInserted, rowsUpdated);
			return;
		}
		while((r = SQLFetch(hStmt_Fetch)) != SQL_NO_DATA) {
		if (r != SQL_SUCCESS) {
			check = qWarnODBCHandle(SQL_HANDLE_STMT, hStmt_Fetch);
			qCCritical(category) << QString("SqlFetch - Error : %1 is %2").arg(fetchSql).arg(check);
			return;
		} 
		rowsFetched++;
		if (m_ReplicationOption == ReplicationOption::BulkCopy)
		{
			r = SQLExecute(hStmt_Insert);
			if (r == SQL_ERROR) {
				check = qWarnODBCHandle(SQL_HANDLE_STMT, hStmt_Insert);
				 qCCritical(category) << QString("SqlExecute:Insert - Error : %1 is %2").arg(insertSql).arg(check);
				return;
			}
			rowsInserted++;
			if ((rowsFetched % updateInterval) == 0) {
				qCInfo(category) << QString("[%1.%2]	Insertion: %3	Updates : %4	Fetched : %5").arg(profileName).arg(tableName).arg(rowsInserted).arg(rowsUpdated).arg(rowsFetched);
				emit updateStatusFetched(profileName, tableName, rowsFetched,rowsInserted,rowsUpdated);
			}
			if (m_ReplicationOption == ReplicationOption::NetChange)
			{
			r = SQLExecute(hStmt_Update);
			if (r != SQL_SUCCESS) {
				check = qWarnODBCHandle(SQL_HANDLE_STMT, hStmt_Update);
				 qCInfo(category)  << QString("SqlExecute:Update - Error : %1 is %2").arg(updateSql).arg(check);
				r = SQLExecute(hStmt_Insert);
				if (r != SQL_SUCCESS) {
					check = qWarnODBCHandle(SQL_HANDLE_STMT, hStmt_Insert);
					 qCritical(category) << QString("SqlExecute:Insert - Error : %1 is %2").arg(insertSql).arg(check);
					return;
				}
				else 	rowsInserted++;
				}
				else	rowsUpdated++;
			}
			emit updateStatusFetched(profileName, tableName, rowsFetched,rowsInserted,rowsUpdated);
		}
	} 
qCInfo(category) << QString("[%1.%2]	Insertion: %3	Updates : %4	Fetched : %5").arg(profileName).arg(tableName).arg(rowsInserted).arg(rowsUpdated).arg(rowsFetched);
}

void TK_INTPOSRTSET::connect(connectionHandle connectionSource)
{

	QLoggingCategory category("classLibQ");
	RETCODE r;

	bool isValid = false;
	HWND	hWnd = nullptr;
	hWnd = ::GetDesktopWindow(); 
	SQLSMALLINT nResult = 0;

	SQLSMALLINT cb;
	UWORD wConnectOption = SQL_DRIVER_COMPLETE; //SQL_DRIVER_NOPROMPT;
	QVarLengthArray<SQLTCHAR> connOut(1024);
	memset(connOut.data(), 0, connOut.size() * sizeof(SQLTCHAR));

	switch (connectionSource)
	{
		case Source:
			{// environment
				SQLHANDLE hEnv = SQL_NULL_HANDLE;
				SQLHANDLE hDbc = SQL_NULL_HANDLE;
				r = ::SQLAllocHandle(SQL_HANDLE_ENV, SQL_NULL_HANDLE, &hEnv);
				if (r == SQL_SUCCESS) isValid = true;

				foreach(nOdbcAttributesClass * k, this->m_OdbcAttributes_Map)
				{
					if (k->attributeType == enumAttributeType::hEnv)
					{
						r = ::SQLSetEnvAttr(hEnv, (SQLINTEGER) k->odbcKey, (SQLPOINTER)k->odbcValue, 0);
						if (r == SQL_SUCCESS) isValid = true;
					}
				}
				hEnv_Source = hEnv;

				r = SQLAllocHandle(SQL_HANDLE_DBC, hEnv, &hDbc);
				if (r == SQL_SUCCESS) isValid = true;
				foreach(nOdbcAttributesClass * k, this->m_OdbcAttributes_Map)
				{
					if (k->attributeType == enumAttributeType::hDbc)
					{
					r = ::SQLSetConnectAttr(hDbc, k->odbcKey, (SQLPOINTER)k->odbcValue, 0);
					if (k->odbcKey == SQL_ATTR_CONNECTION_POOLING && k->odbcValue == SQL_CP_ONE_PER_DRIVER) wConnectOption = SQL_DRIVER_NOPROMPT;
					if (k->odbcKey == SQL_ATTR_CONNECTION_POOLING && k->odbcValue == SQL_CP_ONE_PER_HENV) wConnectOption = SQL_DRIVER_NOPROMPT;
					if (k->odbcKey == SQL_ATTR_CONNECTION_POOLING && k->odbcValue == SQL_CP_DRIVER_AWARE) wConnectOption = SQL_DRIVER_NOPROMPT;
					if (r == SQL_SUCCESS) isValid = true;
					}
				}
				hDbc_source = hDbc;
				if (isValid)
				{
					r = ::SQLDriverConnect(
						hDbc,
						hWnd,
#ifdef UNICODE
						toSQLTCHAR(m_lpszSourceDSN).data(),
#else
						(SQLCHAR*)dsnSource.toUtf8().data(),
#endif
						(SQLSMALLINT)m_lpszSourceDSN.length(),
						connOut.data(),
						1024,
						&cb, 
						wConnectOption); 
					int colSize = cb / sizeof(SQLTCHAR);
					if (r != SQL_SUCCESS && r != SQL_SUCCESS_WITH_INFO)
					{
						QString check = qWarnODBCHandle(SQL_HANDLE_DBC, hDbc);
						qCritical(category) <<  check;
						m_bIsOpen = false;
					}
					m_bIsOpen = true;
				}
			} break;
		case Target:
			{
				SQLHANDLE hEnv = SQL_NULL_HANDLE;
				SQLHANDLE hDbc = SQL_NULL_HANDLE;
				r = ::SQLAllocHandle(SQL_HANDLE_ENV, SQL_NULL_HANDLE, &hEnv);
				if (r == SQL_SUCCESS) isValid = true;

				foreach(nOdbcAttributesClass * k, this->m_OdbcAttributes_Map)
				{
					if (k->attributeType == enumAttributeType::hEnv)
					{
						r = ::SQLSetEnvAttr(hEnv, (SQLINTEGER) k->odbcKey, (SQLPOINTER)k->odbcValue, 0);
						if (r == SQL_SUCCESS) isValid = true;
					}
				}
				hEnv_Target = hEnv;

				r = SQLAllocHandle(SQL_HANDLE_DBC, hEnv, &hDbc);
				if (r == SQL_SUCCESS) isValid = true;
				foreach(nOdbcAttributesClass * k, this->m_OdbcAttributes_Map)
				{
				if (k->attributeType == enumAttributeType::hDbc)
					{
					r = ::SQLSetConnectAttr(hDbc, k->odbcKey, (SQLPOINTER)k->odbcValue, 0);
					if (k->odbcKey == SQL_ATTR_CONNECTION_POOLING && k->odbcValue == SQL_CP_ONE_PER_DRIVER) wConnectOption = SQL_DRIVER_NOPROMPT;
					if (k->odbcKey == SQL_ATTR_CONNECTION_POOLING && k->odbcValue == SQL_CP_ONE_PER_HENV) wConnectOption = SQL_DRIVER_NOPROMPT;
					if (k->odbcKey == SQL_ATTR_CONNECTION_POOLING && k->odbcValue == SQL_CP_DRIVER_AWARE) wConnectOption = SQL_DRIVER_NOPROMPT;
					if (r == SQL_SUCCESS) isValid = true;
					}
				}
				hDbc_target = hDbc;
				if (isValid) {
					r = ::SQLDriverConnect(
						hDbc,
						hWnd,
#ifdef UNICODE
						toSQLTCHAR(m_lpszTargetDSN).data(),
#else
						(SQLCHAR*)m_lpszTargetDSN.toUtf8().data(),
#endif
						(SQLSMALLINT)m_lpszTargetDSN.length(),
						connOut.data(),
						1024,
						&cb, 
						wConnectOption); 
						int colSize = cb / sizeof(SQLTCHAR);
					if (r != SQL_SUCCESS && r != SQL_SUCCESS_WITH_INFO)
						{
							QString check = qWarnODBCHandle(SQL_HANDLE_DBC, hDbc);
							qCritical(category) <<  check;
							m_bIsOpen = false;
						}
							m_bIsOpen = true;
					}
			} break;
			default: break;
	}
}
TK_UPRTHSHSET::TK_UPRTHSHSET(QObject * parent) : QObject(parent) 
,tableName("TK_UPRTHSHSET")
,m_dropOption(DropOption::DropTable) { 
	numRowsFetched = 0;
}

#pragma region ~CTOR TK_UPRTHSHSET 
TK_UPRTHSHSET::~TK_UPRTHSHSET() { 

#pragma region Buffers - Clear 
	DB_ID.clear();
	NVTIMESTAMP.clear();
	OAREA.clear();
	OPAGE.clear();
	OLINE.clear();
	MAREA.clear();
	MPAGE.clear();
	MLINE.clear();
#pragma endregion Buffers - Clear 
}
#pragma endregion Destructor_TK_UPRTHSHSET

// begin method functions
void TK_UPRTHSHSET::setAbortFlag() { 
	QLoggingCategory category("classLibQ");
	qCInfo(category) << "isAbort was set to True";
	bIsAbort = true;
}

void TK_UPRTHSHSET::run() { 
	process(1);
	QLoggingCategory category("classLibQ");
	qDebug(category) << "Entered;";
}

void	TK_UPRTHSHSET::initOdbcAttributes()
{
	QLoggingCategory category("classLibQ");
	this->setProfileName(profileName);
	qDebug(category) << "Processing - TRKDB100"; 
	m_OdbcAttributesList = m_OdbcAttributes.split(","); 
	foreach(QString m, m_OdbcAttributesList)
	{
		QStringList keyValue = m.split("=");
		nOdbcAttributesClass * oM = new nOdbcAttributesClass(this);
		if (oM->loadToOdbc(keyValue.value(0), keyValue.value(1)))
		{
			m_OdbcAttributes_Map.insert(oM->odbcKey, oM);
		}
	}
}
void	TK_UPRTHSHSET::initialize()
{
	QLoggingCategory category("classLibQ");
	RETCODE r;
	this->setProfileName(profileName);
	qDebug(category) << "Processing - TRKDB100"; 
//SQL Statements
//--------------------------------------------------

#pragma region Sql Statements_TK_UPRTHSHSET

	fetchSql = "select  DB_ID, NVTIMESTAMP, OAREA, OPAGE, OLINE, MAREA, MPAGE, MLINE from TK_UPRTHSHSET";
		if (m_ReplicationOption == ReplicationOption::NetChange)
		{
			fetchSql.append(" p1, nv_transfers p2 WHERE  p2.table_name = 'TK_UPRTHSHSET' AND p1.nvtimestamp > p2.last_completed");
		}
	insertSql = "insert into TK_UPRTHSHSET ( PLANT_CODE, NVTIMESTAMP, OAREA, OPAGE, OLINE, MAREA, MPAGE, MLINE ) values ( ?, ?, ?, ?, ?, ?, ?, ?)";
	updateSql = "update TK_UPRTHSHSET set  PLANT_CODE = ?, NVTIMESTAMP = ?, OAREA = ?, OPAGE = ?, OLINE = ?, MAREA = ?, MPAGE = ?, MLINE = ?  where area = ? and page = ? line = ? ";

	qDebug(category) << "insertSQL - insert into TK_UPRTHSHSET ( PLANT_CODE, NVTIMESTAMP, OAREA, OPAGE, OLINE, MAREA, MPAGE, MLINE ) values ( ?, ?, ?, ?, ?, ?, ?, ?)";
	qDebug(category) << "fetchSQL - select  DB_ID, NVTIMESTAMP, OAREA, OPAGE, OLINE, MAREA, MPAGE, MLINE from TK_UPRTHSHSET";
	qDebug(category) << "unsertSQL - update TK_UPRTHSHSET set  PLANT_CODE = ?, NVTIMESTAMP = ?, OAREA = ?, OPAGE = ?, OLINE = ?, MAREA = ?, MPAGE = ?, MLINE = ?  where area = ? and page = ? line = ? ";

#pragma endregion Sql Statements_TK_UPRTHSHSET
	SQLHANDLE		insert_hStmt = SQL_NULL_HANDLE;
	SQLHANDLE		fetch_hStmt = SQL_NULL_HANDLE; 
	SQLHANDLE		update_hStmt = SQL_NULL_HANDLE; 
 
	r = ::SQLAllocHandle(SQL_HANDLE_STMT, hDbc_source, &fetch_hStmt);
	if (r != SQL_SUCCESS) {
		 qCCritical(category) << QString("Error  hDbc_Source SQLCode : %1 is %2").arg(QString::number( (long)hDbc_source)).arg(QString::number(r));
		return; 
	}
	r = ::SQLAllocHandle(SQL_HANDLE_STMT, hDbc_target, &insert_hStmt);
	if (r != SQL_SUCCESS) {
		 qCCritical(category) << QString("Error hDbc_Source -SQLCode: %1 is %2").arg(QString::number( (long)hDbc_target)).arg(QString::number(r));
		return; 
	}
	r = ::SQLAllocHandle(SQL_HANDLE_STMT, hDbc_target, &update_hStmt);
	if (r != SQL_SUCCESS) {
		 qCCritical(category) << QString("Error hDbc_Source +SQLCode: %1 is %2").arg(QString::number( (long)hDbc_target)).arg(QString::number(r));
		return; 
	}
 
	hStmt_Fetch = fetch_hStmt;
	hStmt_Insert = insert_hStmt;
	hStmt_Update = update_hStmt;
 
	SQLSetStmtAttr(hStmt_Fetch, SQL_ATTR_USE_BOOKMARKS, (SQLPOINTER)SQL_UB_OFF, 0);
	SQLSetStmtAttr(hStmt_Fetch, SQL_ATTR_ROW_BIND_TYPE, (SQLPOINTER)SQL_BIND_BY_COLUMN, 0);
	SQLSetStmtAttr(hStmt_Fetch, SQL_ATTR_ROW_ARRAY_SIZE, (SQLPOINTER)1, 0);
	SQLSetStmtAttr(hStmt_Fetch, SQL_ATTR_ROWS_FETCHED_PTR, &numRowsFetched, 0);

// Fields used by this class 
// ---------------------------------------------------

#pragma region Resize Fields TK_UPRTHSHSET
	qDebug(category) << "Malloc - DB_ID[2]";
	DB_ID.resize(2);
	qDebug(category) << "Malloc - NVTIMESTAMP[23]";
	NVTIMESTAMP.resize(23);
	qDebug(category) << "Malloc - OAREA[2]";
	OAREA.resize(2);
	qDebug(category) << "Malloc - OPAGE[4]";
	OPAGE.resize(4);
	qDebug(category) << "Malloc - OLINE[2]";
	OLINE.resize(2);
	qDebug(category) << "Malloc - MAREA[2]";
	MAREA.resize(2);
	qDebug(category) << "Malloc - MPAGE[4]";
	MPAGE.resize(4);
	qDebug(category) << "Malloc - MLINE[2]";
	MLINE.resize(2);

#pragma endregion Resize Fields TK_UPRTHSHSET
}
void TK_UPRTHSHSET::close()
{
	QLoggingCategory category("classLibQ");
	if (m_bIsOpen)
	{
	qDebug(category) << "database is Open";
		SQLHANDLE source_hStmt = hStmt_Fetch;
		SQLHANDLE insert_hStmt = hStmt_Insert;
		SQLHANDLE hDb_S = this->hDbc_source;
		SQLHANDLE hDb_T = hDbc_target;
		SQLHANDLE hEnvS = hEnv_Source;
		SQLHANDLE hEnvT = hEnv_Target;
		RETCODE r;

		r = ::SQLFreeHandle(SQL_HANDLE_STMT, hStmt_Fetch);
		r = ::SQLFreeHandle(SQL_HANDLE_STMT, hStmt_Insert);
		r = ::SQLFreeHandle(SQL_HANDLE_STMT, hStmt_Update);
		if (hDbc_source != SQL_NULL_HANDLE) 		r = ::SQLDisconnect(hDb_S);
		if (hDbc_target != SQL_NULL_HANDLE) 		r = ::SQLDisconnect(hDb_T);

		r = ::SQLFreeHandle(SQL_HANDLE_DBC, hDb_S);
		r = ::SQLFreeHandle(SQL_HANDLE_DBC, hDb_T);
		r = ::SQLFreeHandle(SQL_HANDLE_ENV, hEnvS);
		r = ::SQLFreeHandle(SQL_HANDLE_ENV, hEnvT);
	}

	hEnv_Source = SQL_NULL_HANDLE;
	hEnv_Target = SQL_NULL_HANDLE;
	hEnv_Source = SQL_NULL_HANDLE;
	hEnv_Target = SQL_NULL_HANDLE;
	hStmt_Fetch = SQL_NULL_HANDLE;
	hStmt_Insert = SQL_NULL_HANDLE;
	hStmt_Update = SQL_NULL_HANDLE;
}

void TK_UPRTHSHSET::open(const QString sourceDSN, const QString targetDSN)
{
	QLoggingCategory category("classLibQ");
	m_lpszTargetDSN = targetDSN;
	m_lpszSourceDSN = sourceDSN;
	qDebug(category) << QString("Source - %1[%2]").arg(sourceDSN);
	qDebug(category) << QString("Target - %1[%2]").arg(targetDSN);
}

void TK_UPRTHSHSET::createTable()
{
	QLoggingCategory category("classLibQ");
	{
		QScopedPointer<nvTableOracleRdb> tbl(new nvTableOracleRdb(nullptr));
		tbl->initialize("TK_UPRTHSHSET", this->m_lpszSourceDSN);
		QString newTbl = tbl->getCreateTableSQL();
		QScopedPointer<qVtExecute> vExec(new qVtExecute(nullptr));
		{
			vExec->initialize(m_lpszTargetDSN, " ", true);
			vExec->setOdbcAttributes(m_OdbcAttributes);
			vExec->ExecuteDirect(newTbl);
		}
	 qDebug(category) << QString("End Create Table %1 ").arg(tableName); 
	}
}

bool TK_UPRTHSHSET::prepare()
{
	RETCODE r;
	QString check;
	QLoggingCategory category("classLibQ");
	 qDebug(category) << fetchSql;
	 qDebug(category) << insertSql;
#ifdef UNICODE
	r = SQLPrepare(hStmt_Insert,toSQLTCHAR(insertSql).data(),(SQLINTEGER)insertSql.length()); 
	if (r != SQL_SUCCESS) {
		check = qWarnODBCHandle(SQL_HANDLE_STMT, hStmt_Insert);
		 qCCritical(category) << QString("Prepare Statement-Insert : %1 is %2").arg(insertSql).arg(check);
		return false; 
	}
	r = SQLPrepare(hStmt_Update,toSQLTCHAR(updateSql).data(),(SQLINTEGER)updateSql.length()); 
	if (r != SQL_SUCCESS) {
		check = qWarnODBCHandle(SQL_HANDLE_STMT, hStmt_Update);
		 qCCritical(category) << QString("Prepare Statement-Update : %1 is %2").arg(updateSql).arg(check);
		return false; 
	}
	r = SQLPrepare(hStmt_Fetch,toSQLTCHAR(fetchSql).data(),(SQLINTEGER)fetchSql.length());
	if (r != SQL_SUCCESS) {
		check = qWarnODBCHandle(SQL_HANDLE_STMT, hStmt_Fetch);
		 qCCritical(category) << QString("Prepare Statement-Insert : %1 is %2").arg(fetchSql).arg(check);
		return false; 
	}
#else
	QByteArray queryI8 = insertSql.toUtf8();
	r = SQLPrepare(insert_hStmt,SQLCHAR*)queryI8.data(),(SQLINTEGER)queryI8.length());
	QByteArray queryU8 = fetchSql.toUtf8();
	r = SQLPrepare(hStmt_Fetch,(SQLCHAR*)queryU8.data(),(SQLINTEGER)queryU8.length());
#endif
	return true;

}

void TK_UPRTHSHSET::prepareTargetTable()
{
	QLoggingCategory category("classLibQ");
	if (this->m_ReplicationOption == ReplicationOption::BulkCopy)
	{
		QScopedPointer<qVtExecute> execSql(new qVtExecute(nullptr));
		DropOption option = this->m_dropOption;
		switch (option)
		{
			case DropOption::DeleteFromTable:
			{
				QLoggingCategory category("classLibQ");
				execSql->initialize(this->m_lpszTargetDSN, "delete from TK_UPRTHSHSET", true);
				execSql->setOdbcAttributes(this->m_OdbcAttributes);
				execSql->ExecuteDirect("delete from TK_UPRTHSHSET");
			}break;
			case DropOption::TruncateTable:
			{
				execSql->initialize(this->m_lpszTargetDSN, "truncate table TK_UPRTHSHSET", true);
				execSql->setOdbcAttributes(this->m_OdbcAttributes);
				execSql->ExecuteDirect("truncate table TK_UPRTHSHSET");
			}break;
			case DropOption::DropTable:
			{
				execSql->initialize(this->m_lpszTargetDSN, "drop table TK_UPRTHSHSET", true);
				execSql->setOdbcAttributes(this->m_OdbcAttributes);
				execSql->ExecuteDirect("drop table TK_UPRTHSHSET");
				createTable();
			}break;
		}
	}
}

bool TK_UPRTHSHSET::bindColumn()
{
	QLoggingCategory category("classLibQ");
	RETCODE r;
	bool isValid=true;
		 qDebug(category) << " Bindings: Ordinal [1] Type: 5 Buffer Size: 2 FieldName: DB_ID ";
		r = ::SQLBindCol(hStmt_Fetch, 1, 5, DB_ID.data(), 2, &cbDB_ID);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Bindings: Ordinal [2] Type: 93 Buffer Size: 23 FieldName: NVTIMESTAMP ";
		r = ::SQLBindCol(hStmt_Fetch, 2, 93, NVTIMESTAMP.data(), 23, &cbNVTIMESTAMP);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Bindings: Ordinal [3] Type: 5 Buffer Size: 2 FieldName: OAREA ";
		r = ::SQLBindCol(hStmt_Fetch, 3, 5, OAREA.data(), 2, &cbOAREA);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Bindings: Ordinal [4] Type: 4 Buffer Size: 4 FieldName: OPAGE ";
		r = ::SQLBindCol(hStmt_Fetch, 4, 4, OPAGE.data(), 4, &cbOPAGE);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Bindings: Ordinal [5] Type: 5 Buffer Size: 2 FieldName: OLINE ";
		r = ::SQLBindCol(hStmt_Fetch, 5, 5, OLINE.data(), 2, &cbOLINE);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Bindings: Ordinal [6] Type: 5 Buffer Size: 2 FieldName: MAREA ";
		r = ::SQLBindCol(hStmt_Fetch, 6, 5, MAREA.data(), 2, &cbMAREA);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Bindings: Ordinal [7] Type: 4 Buffer Size: 4 FieldName: MPAGE ";
		r = ::SQLBindCol(hStmt_Fetch, 7, 4, MPAGE.data(), 4, &cbMPAGE);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Bindings: Ordinal [8] Type: 5 Buffer Size: 2 FieldName: MLINE ";
		r = ::SQLBindCol(hStmt_Fetch, 8, 5, MLINE.data(), 2, &cbMLINE);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
	return isValid;
}

bool TK_UPRTHSHSET::bindParameter()
{
	QLoggingCategory category("classLibQ");
	RETCODE r;
	bool isValid=true;
	{
		 qDebug(category) << " Parameters: Ordinal [1] Type: 5 Buffer Size: 2 FieldName: DB_ID ";
		r = SQLBindParameter(hStmt_Insert, 1, SQL_PARAM_INPUT, SQL_C_DEFAULT, 5, 0, 0, (SQLPOINTER)DB_ID.constData(), 0, &cbDB_ID);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Parameters: Ordinal [2] Type: 93 Buffer Size: 23 FieldName: NVTIMESTAMP ";
		r = SQLBindParameter(hStmt_Insert, 2, SQL_PARAM_INPUT, SQL_C_DEFAULT, 93, 23, 0, (SQLPOINTER)NVTIMESTAMP.constData(), 0, &cbNVTIMESTAMP);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Parameters: Ordinal [3] Type: 5 Buffer Size: 2 FieldName: OAREA ";
		r = SQLBindParameter(hStmt_Insert, 3, SQL_PARAM_INPUT, SQL_C_DEFAULT, 5, 0, 0, (SQLPOINTER)OAREA.constData(), 0, &cbOAREA);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Parameters: Ordinal [4] Type: 4 Buffer Size: 4 FieldName: OPAGE ";
		r = SQLBindParameter(hStmt_Insert, 4, SQL_PARAM_INPUT, SQL_C_DEFAULT, 4, 0, 0, (SQLPOINTER)OPAGE.constData(), 0, &cbOPAGE);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Parameters: Ordinal [5] Type: 5 Buffer Size: 2 FieldName: OLINE ";
		r = SQLBindParameter(hStmt_Insert, 5, SQL_PARAM_INPUT, SQL_C_DEFAULT, 5, 0, 0, (SQLPOINTER)OLINE.constData(), 0, &cbOLINE);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Parameters: Ordinal [6] Type: 5 Buffer Size: 2 FieldName: MAREA ";
		r = SQLBindParameter(hStmt_Insert, 6, SQL_PARAM_INPUT, SQL_C_DEFAULT, 5, 0, 0, (SQLPOINTER)MAREA.constData(), 0, &cbMAREA);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Parameters: Ordinal [7] Type: 4 Buffer Size: 4 FieldName: MPAGE ";
		r = SQLBindParameter(hStmt_Insert, 7, SQL_PARAM_INPUT, SQL_C_DEFAULT, 4, 0, 0, (SQLPOINTER)MPAGE.constData(), 0, &cbMPAGE);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Parameters: Ordinal [8] Type: 5 Buffer Size: 2 FieldName: MLINE ";
		r = SQLBindParameter(hStmt_Insert, 8, SQL_PARAM_INPUT, SQL_C_DEFAULT, 5, 0, 0, (SQLPOINTER)MLINE.constData(), 0, &cbMLINE);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
	}
	if (m_ReplicationOption == ReplicationOption::NetChange)
	{
		r = SQLBindParameter(hStmt_Update, 9, SQL_PARAM_INPUT, SQL_C_DEFAULT, 6, 0, 0, (SQLPOINTER)MAREA.constData(), 0, &cbMAREA);
		if (r == SQL_SUCCESS) { isValid=true; }
		r = SQLBindParameter(hStmt_Update, 10, SQL_PARAM_INPUT, SQL_C_DEFAULT, 7, 0, 0, (SQLPOINTER)MPAGE.constData(), 0, &cbMPAGE);
		if (r == SQL_SUCCESS) { isValid=true; }
		r = SQLBindParameter(hStmt_Update, 11, SQL_PARAM_INPUT, SQL_C_DEFAULT, 8, 0, 0, (SQLPOINTER)MLINE.constData(), 0, &cbMLINE);
		if (r == SQL_SUCCESS) { isValid=true; }
	// TK_UPRTHSHSET is a well formed table for eNVy Replication 
		 qDebug(category) << " Parameters: Ordinal [6] 00 00 FieldName: MAREA ";
		 qDebug(category) << " Parameters: Ordinal [7] 00 00  FieldName: MPAGE ";
		 qDebug(category) << " Parameters: Ordinal [8] 00 00 FieldName:  MLINE ";
	} // 	if (m_ReplicationOption == ReplicationOption::NetChange)
	return isValid;
}

bool TK_UPRTHSHSET::process(int rowSize)
{
	QLoggingCategory category("classLibQ");
	initOdbcAttributes();
	connect(Source);
	connect(Target);
	initialize();
	prepareTargetTable();
	prepare();
	bindColumn();
	bindParameter();
	copyTable();
	close();
	return false;
}

void TK_UPRTHSHSET::copyTable()
{
	QLoggingCategory category("classLibQ");
	RETCODE r;
	QString check;
	r = SQLExecute(hStmt_Fetch);
		if (bIsAbort) {
			emit aborted(tableName, rowsFetched, rowsInserted, rowsUpdated);
			return;
		}
		while((r = SQLFetch(hStmt_Fetch)) != SQL_NO_DATA) {
		if (r != SQL_SUCCESS) {
			check = qWarnODBCHandle(SQL_HANDLE_STMT, hStmt_Fetch);
			qCCritical(category) << QString("SqlFetch - Error : %1 is %2").arg(fetchSql).arg(check);
			return;
		} 
		rowsFetched++;
		if (m_ReplicationOption == ReplicationOption::BulkCopy)
		{
			r = SQLExecute(hStmt_Insert);
			if (r == SQL_ERROR) {
				check = qWarnODBCHandle(SQL_HANDLE_STMT, hStmt_Insert);
				 qCCritical(category) << QString("SqlExecute:Insert - Error : %1 is %2").arg(insertSql).arg(check);
				return;
			}
			rowsInserted++;
			if ((rowsFetched % updateInterval) == 0) {
				qCInfo(category) << QString("[%1.%2]	Insertion: %3	Updates : %4	Fetched : %5").arg(profileName).arg(tableName).arg(rowsInserted).arg(rowsUpdated).arg(rowsFetched);
				emit updateStatusFetched(profileName, tableName, rowsFetched,rowsInserted,rowsUpdated);
			}
			if (m_ReplicationOption == ReplicationOption::NetChange)
			{
			r = SQLExecute(hStmt_Update);
			if (r != SQL_SUCCESS) {
				check = qWarnODBCHandle(SQL_HANDLE_STMT, hStmt_Update);
				 qCInfo(category)  << QString("SqlExecute:Update - Error : %1 is %2").arg(updateSql).arg(check);
				r = SQLExecute(hStmt_Insert);
				if (r != SQL_SUCCESS) {
					check = qWarnODBCHandle(SQL_HANDLE_STMT, hStmt_Insert);
					 qCritical(category) << QString("SqlExecute:Insert - Error : %1 is %2").arg(insertSql).arg(check);
					return;
				}
				else 	rowsInserted++;
				}
				else	rowsUpdated++;
			}
			emit updateStatusFetched(profileName, tableName, rowsFetched,rowsInserted,rowsUpdated);
		}
	} 
qCInfo(category) << QString("[%1.%2]	Insertion: %3	Updates : %4	Fetched : %5").arg(profileName).arg(tableName).arg(rowsInserted).arg(rowsUpdated).arg(rowsFetched);
}

void TK_UPRTHSHSET::connect(connectionHandle connectionSource)
{

	QLoggingCategory category("classLibQ");
	RETCODE r;

	bool isValid = false;
	HWND	hWnd = nullptr;
	hWnd = ::GetDesktopWindow(); 
	SQLSMALLINT nResult = 0;

	SQLSMALLINT cb;
	UWORD wConnectOption = SQL_DRIVER_COMPLETE; //SQL_DRIVER_NOPROMPT;
	QVarLengthArray<SQLTCHAR> connOut(1024);
	memset(connOut.data(), 0, connOut.size() * sizeof(SQLTCHAR));

	switch (connectionSource)
	{
		case Source:
			{// environment
				SQLHANDLE hEnv = SQL_NULL_HANDLE;
				SQLHANDLE hDbc = SQL_NULL_HANDLE;
				r = ::SQLAllocHandle(SQL_HANDLE_ENV, SQL_NULL_HANDLE, &hEnv);
				if (r == SQL_SUCCESS) isValid = true;

				foreach(nOdbcAttributesClass * k, this->m_OdbcAttributes_Map)
				{
					if (k->attributeType == enumAttributeType::hEnv)
					{
						r = ::SQLSetEnvAttr(hEnv, (SQLINTEGER) k->odbcKey, (SQLPOINTER)k->odbcValue, 0);
						if (r == SQL_SUCCESS) isValid = true;
					}
				}
				hEnv_Source = hEnv;

				r = SQLAllocHandle(SQL_HANDLE_DBC, hEnv, &hDbc);
				if (r == SQL_SUCCESS) isValid = true;
				foreach(nOdbcAttributesClass * k, this->m_OdbcAttributes_Map)
				{
					if (k->attributeType == enumAttributeType::hDbc)
					{
					r = ::SQLSetConnectAttr(hDbc, k->odbcKey, (SQLPOINTER)k->odbcValue, 0);
					if (k->odbcKey == SQL_ATTR_CONNECTION_POOLING && k->odbcValue == SQL_CP_ONE_PER_DRIVER) wConnectOption = SQL_DRIVER_NOPROMPT;
					if (k->odbcKey == SQL_ATTR_CONNECTION_POOLING && k->odbcValue == SQL_CP_ONE_PER_HENV) wConnectOption = SQL_DRIVER_NOPROMPT;
					if (k->odbcKey == SQL_ATTR_CONNECTION_POOLING && k->odbcValue == SQL_CP_DRIVER_AWARE) wConnectOption = SQL_DRIVER_NOPROMPT;
					if (r == SQL_SUCCESS) isValid = true;
					}
				}
				hDbc_source = hDbc;
				if (isValid)
				{
					r = ::SQLDriverConnect(
						hDbc,
						hWnd,
#ifdef UNICODE
						toSQLTCHAR(m_lpszSourceDSN).data(),
#else
						(SQLCHAR*)dsnSource.toUtf8().data(),
#endif
						(SQLSMALLINT)m_lpszSourceDSN.length(),
						connOut.data(),
						1024,
						&cb, 
						wConnectOption); 
					int colSize = cb / sizeof(SQLTCHAR);
					if (r != SQL_SUCCESS && r != SQL_SUCCESS_WITH_INFO)
					{
						QString check = qWarnODBCHandle(SQL_HANDLE_DBC, hDbc);
						qCritical(category) <<  check;
						m_bIsOpen = false;
					}
					m_bIsOpen = true;
				}
			} break;
		case Target:
			{
				SQLHANDLE hEnv = SQL_NULL_HANDLE;
				SQLHANDLE hDbc = SQL_NULL_HANDLE;
				r = ::SQLAllocHandle(SQL_HANDLE_ENV, SQL_NULL_HANDLE, &hEnv);
				if (r == SQL_SUCCESS) isValid = true;

				foreach(nOdbcAttributesClass * k, this->m_OdbcAttributes_Map)
				{
					if (k->attributeType == enumAttributeType::hEnv)
					{
						r = ::SQLSetEnvAttr(hEnv, (SQLINTEGER) k->odbcKey, (SQLPOINTER)k->odbcValue, 0);
						if (r == SQL_SUCCESS) isValid = true;
					}
				}
				hEnv_Target = hEnv;

				r = SQLAllocHandle(SQL_HANDLE_DBC, hEnv, &hDbc);
				if (r == SQL_SUCCESS) isValid = true;
				foreach(nOdbcAttributesClass * k, this->m_OdbcAttributes_Map)
				{
				if (k->attributeType == enumAttributeType::hDbc)
					{
					r = ::SQLSetConnectAttr(hDbc, k->odbcKey, (SQLPOINTER)k->odbcValue, 0);
					if (k->odbcKey == SQL_ATTR_CONNECTION_POOLING && k->odbcValue == SQL_CP_ONE_PER_DRIVER) wConnectOption = SQL_DRIVER_NOPROMPT;
					if (k->odbcKey == SQL_ATTR_CONNECTION_POOLING && k->odbcValue == SQL_CP_ONE_PER_HENV) wConnectOption = SQL_DRIVER_NOPROMPT;
					if (k->odbcKey == SQL_ATTR_CONNECTION_POOLING && k->odbcValue == SQL_CP_DRIVER_AWARE) wConnectOption = SQL_DRIVER_NOPROMPT;
					if (r == SQL_SUCCESS) isValid = true;
					}
				}
				hDbc_target = hDbc;
				if (isValid) {
					r = ::SQLDriverConnect(
						hDbc,
						hWnd,
#ifdef UNICODE
						toSQLTCHAR(m_lpszTargetDSN).data(),
#else
						(SQLCHAR*)m_lpszTargetDSN.toUtf8().data(),
#endif
						(SQLSMALLINT)m_lpszTargetDSN.length(),
						connOut.data(),
						1024,
						&cb, 
						wConnectOption); 
						int colSize = cb / sizeof(SQLTCHAR);
					if (r != SQL_SUCCESS && r != SQL_SUCCESS_WITH_INFO)
						{
							QString check = qWarnODBCHandle(SQL_HANDLE_DBC, hDbc);
							qCritical(category) <<  check;
							m_bIsOpen = false;
						}
							m_bIsOpen = true;
					}
			} break;
			default: break;
	}
}
TK_LIDNOTSET::TK_LIDNOTSET(QObject * parent) : QObject(parent) 
,tableName("TK_LIDNOTSET")
,m_dropOption(DropOption::DropTable) { 
	numRowsFetched = 0;
}

#pragma region ~CTOR TK_LIDNOTSET 
TK_LIDNOTSET::~TK_LIDNOTSET() { 

#pragma region Buffers - Clear 
	DB_ID.clear();
	NVTIMESTAMP.clear();
	OAREA.clear();
	OPAGE.clear();
	OLINE.clear();
	MAREA.clear();
	MPAGE.clear();
	MLINE.clear();
#pragma endregion Buffers - Clear 
}
#pragma endregion Destructor_TK_LIDNOTSET

// begin method functions
void TK_LIDNOTSET::setAbortFlag() { 
	QLoggingCategory category("classLibQ");
	qCInfo(category) << "isAbort was set to True";
	bIsAbort = true;
}

void TK_LIDNOTSET::run() { 
	process(1);
	QLoggingCategory category("classLibQ");
	qDebug(category) << "Entered;";
}

void	TK_LIDNOTSET::initOdbcAttributes()
{
	QLoggingCategory category("classLibQ");
	this->setProfileName(profileName);
	qDebug(category) << "Processing - TRKDB100"; 
	m_OdbcAttributesList = m_OdbcAttributes.split(","); 
	foreach(QString m, m_OdbcAttributesList)
	{
		QStringList keyValue = m.split("=");
		nOdbcAttributesClass * oM = new nOdbcAttributesClass(this);
		if (oM->loadToOdbc(keyValue.value(0), keyValue.value(1)))
		{
			m_OdbcAttributes_Map.insert(oM->odbcKey, oM);
		}
	}
}
void	TK_LIDNOTSET::initialize()
{
	QLoggingCategory category("classLibQ");
	RETCODE r;
	this->setProfileName(profileName);
	qDebug(category) << "Processing - TRKDB100"; 
//SQL Statements
//--------------------------------------------------

#pragma region Sql Statements_TK_LIDNOTSET

	fetchSql = "select  DB_ID, NVTIMESTAMP, OAREA, OPAGE, OLINE, MAREA, MPAGE, MLINE from TK_LIDNOTSET";
		if (m_ReplicationOption == ReplicationOption::NetChange)
		{
			fetchSql.append(" p1, nv_transfers p2 WHERE  p2.table_name = 'TK_LIDNOTSET' AND p1.nvtimestamp > p2.last_completed");
		}
	insertSql = "insert into TK_LIDNOTSET ( PLANT_CODE, NVTIMESTAMP, OAREA, OPAGE, OLINE, MAREA, MPAGE, MLINE ) values ( ?, ?, ?, ?, ?, ?, ?, ?)";
	updateSql = "update TK_LIDNOTSET set  PLANT_CODE = ?, NVTIMESTAMP = ?, OAREA = ?, OPAGE = ?, OLINE = ?, MAREA = ?, MPAGE = ?, MLINE = ?  where area = ? and page = ? line = ? ";

	qDebug(category) << "insertSQL - insert into TK_LIDNOTSET ( PLANT_CODE, NVTIMESTAMP, OAREA, OPAGE, OLINE, MAREA, MPAGE, MLINE ) values ( ?, ?, ?, ?, ?, ?, ?, ?)";
	qDebug(category) << "fetchSQL - select  DB_ID, NVTIMESTAMP, OAREA, OPAGE, OLINE, MAREA, MPAGE, MLINE from TK_LIDNOTSET";
	qDebug(category) << "unsertSQL - update TK_LIDNOTSET set  PLANT_CODE = ?, NVTIMESTAMP = ?, OAREA = ?, OPAGE = ?, OLINE = ?, MAREA = ?, MPAGE = ?, MLINE = ?  where area = ? and page = ? line = ? ";

#pragma endregion Sql Statements_TK_LIDNOTSET
	SQLHANDLE		insert_hStmt = SQL_NULL_HANDLE;
	SQLHANDLE		fetch_hStmt = SQL_NULL_HANDLE; 
	SQLHANDLE		update_hStmt = SQL_NULL_HANDLE; 
 
	r = ::SQLAllocHandle(SQL_HANDLE_STMT, hDbc_source, &fetch_hStmt);
	if (r != SQL_SUCCESS) {
		 qCCritical(category) << QString("Error  hDbc_Source SQLCode : %1 is %2").arg(QString::number( (long)hDbc_source)).arg(QString::number(r));
		return; 
	}
	r = ::SQLAllocHandle(SQL_HANDLE_STMT, hDbc_target, &insert_hStmt);
	if (r != SQL_SUCCESS) {
		 qCCritical(category) << QString("Error hDbc_Source -SQLCode: %1 is %2").arg(QString::number( (long)hDbc_target)).arg(QString::number(r));
		return; 
	}
	r = ::SQLAllocHandle(SQL_HANDLE_STMT, hDbc_target, &update_hStmt);
	if (r != SQL_SUCCESS) {
		 qCCritical(category) << QString("Error hDbc_Source +SQLCode: %1 is %2").arg(QString::number( (long)hDbc_target)).arg(QString::number(r));
		return; 
	}
 
	hStmt_Fetch = fetch_hStmt;
	hStmt_Insert = insert_hStmt;
	hStmt_Update = update_hStmt;
 
	SQLSetStmtAttr(hStmt_Fetch, SQL_ATTR_USE_BOOKMARKS, (SQLPOINTER)SQL_UB_OFF, 0);
	SQLSetStmtAttr(hStmt_Fetch, SQL_ATTR_ROW_BIND_TYPE, (SQLPOINTER)SQL_BIND_BY_COLUMN, 0);
	SQLSetStmtAttr(hStmt_Fetch, SQL_ATTR_ROW_ARRAY_SIZE, (SQLPOINTER)1, 0);
	SQLSetStmtAttr(hStmt_Fetch, SQL_ATTR_ROWS_FETCHED_PTR, &numRowsFetched, 0);

// Fields used by this class 
// ---------------------------------------------------

#pragma region Resize Fields TK_LIDNOTSET
	qDebug(category) << "Malloc - DB_ID[2]";
	DB_ID.resize(2);
	qDebug(category) << "Malloc - NVTIMESTAMP[23]";
	NVTIMESTAMP.resize(23);
	qDebug(category) << "Malloc - OAREA[2]";
	OAREA.resize(2);
	qDebug(category) << "Malloc - OPAGE[4]";
	OPAGE.resize(4);
	qDebug(category) << "Malloc - OLINE[2]";
	OLINE.resize(2);
	qDebug(category) << "Malloc - MAREA[2]";
	MAREA.resize(2);
	qDebug(category) << "Malloc - MPAGE[4]";
	MPAGE.resize(4);
	qDebug(category) << "Malloc - MLINE[2]";
	MLINE.resize(2);

#pragma endregion Resize Fields TK_LIDNOTSET
}
void TK_LIDNOTSET::close()
{
	QLoggingCategory category("classLibQ");
	if (m_bIsOpen)
	{
	qDebug(category) << "database is Open";
		SQLHANDLE source_hStmt = hStmt_Fetch;
		SQLHANDLE insert_hStmt = hStmt_Insert;
		SQLHANDLE hDb_S = this->hDbc_source;
		SQLHANDLE hDb_T = hDbc_target;
		SQLHANDLE hEnvS = hEnv_Source;
		SQLHANDLE hEnvT = hEnv_Target;
		RETCODE r;

		r = ::SQLFreeHandle(SQL_HANDLE_STMT, hStmt_Fetch);
		r = ::SQLFreeHandle(SQL_HANDLE_STMT, hStmt_Insert);
		r = ::SQLFreeHandle(SQL_HANDLE_STMT, hStmt_Update);
		if (hDbc_source != SQL_NULL_HANDLE) 		r = ::SQLDisconnect(hDb_S);
		if (hDbc_target != SQL_NULL_HANDLE) 		r = ::SQLDisconnect(hDb_T);

		r = ::SQLFreeHandle(SQL_HANDLE_DBC, hDb_S);
		r = ::SQLFreeHandle(SQL_HANDLE_DBC, hDb_T);
		r = ::SQLFreeHandle(SQL_HANDLE_ENV, hEnvS);
		r = ::SQLFreeHandle(SQL_HANDLE_ENV, hEnvT);
	}

	hEnv_Source = SQL_NULL_HANDLE;
	hEnv_Target = SQL_NULL_HANDLE;
	hEnv_Source = SQL_NULL_HANDLE;
	hEnv_Target = SQL_NULL_HANDLE;
	hStmt_Fetch = SQL_NULL_HANDLE;
	hStmt_Insert = SQL_NULL_HANDLE;
	hStmt_Update = SQL_NULL_HANDLE;
}

void TK_LIDNOTSET::open(const QString sourceDSN, const QString targetDSN)
{
	QLoggingCategory category("classLibQ");
	m_lpszTargetDSN = targetDSN;
	m_lpszSourceDSN = sourceDSN;
	qDebug(category) << QString("Source - %1[%2]").arg(sourceDSN);
	qDebug(category) << QString("Target - %1[%2]").arg(targetDSN);
}

void TK_LIDNOTSET::createTable()
{
	QLoggingCategory category("classLibQ");
	{
		QScopedPointer<nvTableOracleRdb> tbl(new nvTableOracleRdb(nullptr));
		tbl->initialize("TK_LIDNOTSET", this->m_lpszSourceDSN);
		QString newTbl = tbl->getCreateTableSQL();
		QScopedPointer<qVtExecute> vExec(new qVtExecute(nullptr));
		{
			vExec->initialize(m_lpszTargetDSN, " ", true);
			vExec->setOdbcAttributes(m_OdbcAttributes);
			vExec->ExecuteDirect(newTbl);
		}
	 qDebug(category) << QString("End Create Table %1 ").arg(tableName); 
	}
}

bool TK_LIDNOTSET::prepare()
{
	RETCODE r;
	QString check;
	QLoggingCategory category("classLibQ");
	 qDebug(category) << fetchSql;
	 qDebug(category) << insertSql;
#ifdef UNICODE
	r = SQLPrepare(hStmt_Insert,toSQLTCHAR(insertSql).data(),(SQLINTEGER)insertSql.length()); 
	if (r != SQL_SUCCESS) {
		check = qWarnODBCHandle(SQL_HANDLE_STMT, hStmt_Insert);
		 qCCritical(category) << QString("Prepare Statement-Insert : %1 is %2").arg(insertSql).arg(check);
		return false; 
	}
	r = SQLPrepare(hStmt_Update,toSQLTCHAR(updateSql).data(),(SQLINTEGER)updateSql.length()); 
	if (r != SQL_SUCCESS) {
		check = qWarnODBCHandle(SQL_HANDLE_STMT, hStmt_Update);
		 qCCritical(category) << QString("Prepare Statement-Update : %1 is %2").arg(updateSql).arg(check);
		return false; 
	}
	r = SQLPrepare(hStmt_Fetch,toSQLTCHAR(fetchSql).data(),(SQLINTEGER)fetchSql.length());
	if (r != SQL_SUCCESS) {
		check = qWarnODBCHandle(SQL_HANDLE_STMT, hStmt_Fetch);
		 qCCritical(category) << QString("Prepare Statement-Insert : %1 is %2").arg(fetchSql).arg(check);
		return false; 
	}
#else
	QByteArray queryI8 = insertSql.toUtf8();
	r = SQLPrepare(insert_hStmt,SQLCHAR*)queryI8.data(),(SQLINTEGER)queryI8.length());
	QByteArray queryU8 = fetchSql.toUtf8();
	r = SQLPrepare(hStmt_Fetch,(SQLCHAR*)queryU8.data(),(SQLINTEGER)queryU8.length());
#endif
	return true;

}

void TK_LIDNOTSET::prepareTargetTable()
{
	QLoggingCategory category("classLibQ");
	if (this->m_ReplicationOption == ReplicationOption::BulkCopy)
	{
		QScopedPointer<qVtExecute> execSql(new qVtExecute(nullptr));
		DropOption option = this->m_dropOption;
		switch (option)
		{
			case DropOption::DeleteFromTable:
			{
				QLoggingCategory category("classLibQ");
				execSql->initialize(this->m_lpszTargetDSN, "delete from TK_LIDNOTSET", true);
				execSql->setOdbcAttributes(this->m_OdbcAttributes);
				execSql->ExecuteDirect("delete from TK_LIDNOTSET");
			}break;
			case DropOption::TruncateTable:
			{
				execSql->initialize(this->m_lpszTargetDSN, "truncate table TK_LIDNOTSET", true);
				execSql->setOdbcAttributes(this->m_OdbcAttributes);
				execSql->ExecuteDirect("truncate table TK_LIDNOTSET");
			}break;
			case DropOption::DropTable:
			{
				execSql->initialize(this->m_lpszTargetDSN, "drop table TK_LIDNOTSET", true);
				execSql->setOdbcAttributes(this->m_OdbcAttributes);
				execSql->ExecuteDirect("drop table TK_LIDNOTSET");
				createTable();
			}break;
		}
	}
}

bool TK_LIDNOTSET::bindColumn()
{
	QLoggingCategory category("classLibQ");
	RETCODE r;
	bool isValid=true;
		 qDebug(category) << " Bindings: Ordinal [1] Type: 5 Buffer Size: 2 FieldName: DB_ID ";
		r = ::SQLBindCol(hStmt_Fetch, 1, 5, DB_ID.data(), 2, &cbDB_ID);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Bindings: Ordinal [2] Type: 93 Buffer Size: 23 FieldName: NVTIMESTAMP ";
		r = ::SQLBindCol(hStmt_Fetch, 2, 93, NVTIMESTAMP.data(), 23, &cbNVTIMESTAMP);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Bindings: Ordinal [3] Type: 5 Buffer Size: 2 FieldName: OAREA ";
		r = ::SQLBindCol(hStmt_Fetch, 3, 5, OAREA.data(), 2, &cbOAREA);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Bindings: Ordinal [4] Type: 4 Buffer Size: 4 FieldName: OPAGE ";
		r = ::SQLBindCol(hStmt_Fetch, 4, 4, OPAGE.data(), 4, &cbOPAGE);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Bindings: Ordinal [5] Type: 5 Buffer Size: 2 FieldName: OLINE ";
		r = ::SQLBindCol(hStmt_Fetch, 5, 5, OLINE.data(), 2, &cbOLINE);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Bindings: Ordinal [6] Type: 5 Buffer Size: 2 FieldName: MAREA ";
		r = ::SQLBindCol(hStmt_Fetch, 6, 5, MAREA.data(), 2, &cbMAREA);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Bindings: Ordinal [7] Type: 4 Buffer Size: 4 FieldName: MPAGE ";
		r = ::SQLBindCol(hStmt_Fetch, 7, 4, MPAGE.data(), 4, &cbMPAGE);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Bindings: Ordinal [8] Type: 5 Buffer Size: 2 FieldName: MLINE ";
		r = ::SQLBindCol(hStmt_Fetch, 8, 5, MLINE.data(), 2, &cbMLINE);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
	return isValid;
}

bool TK_LIDNOTSET::bindParameter()
{
	QLoggingCategory category("classLibQ");
	RETCODE r;
	bool isValid=true;
	{
		 qDebug(category) << " Parameters: Ordinal [1] Type: 5 Buffer Size: 2 FieldName: DB_ID ";
		r = SQLBindParameter(hStmt_Insert, 1, SQL_PARAM_INPUT, SQL_C_DEFAULT, 5, 0, 0, (SQLPOINTER)DB_ID.constData(), 0, &cbDB_ID);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Parameters: Ordinal [2] Type: 93 Buffer Size: 23 FieldName: NVTIMESTAMP ";
		r = SQLBindParameter(hStmt_Insert, 2, SQL_PARAM_INPUT, SQL_C_DEFAULT, 93, 23, 0, (SQLPOINTER)NVTIMESTAMP.constData(), 0, &cbNVTIMESTAMP);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Parameters: Ordinal [3] Type: 5 Buffer Size: 2 FieldName: OAREA ";
		r = SQLBindParameter(hStmt_Insert, 3, SQL_PARAM_INPUT, SQL_C_DEFAULT, 5, 0, 0, (SQLPOINTER)OAREA.constData(), 0, &cbOAREA);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Parameters: Ordinal [4] Type: 4 Buffer Size: 4 FieldName: OPAGE ";
		r = SQLBindParameter(hStmt_Insert, 4, SQL_PARAM_INPUT, SQL_C_DEFAULT, 4, 0, 0, (SQLPOINTER)OPAGE.constData(), 0, &cbOPAGE);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Parameters: Ordinal [5] Type: 5 Buffer Size: 2 FieldName: OLINE ";
		r = SQLBindParameter(hStmt_Insert, 5, SQL_PARAM_INPUT, SQL_C_DEFAULT, 5, 0, 0, (SQLPOINTER)OLINE.constData(), 0, &cbOLINE);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Parameters: Ordinal [6] Type: 5 Buffer Size: 2 FieldName: MAREA ";
		r = SQLBindParameter(hStmt_Insert, 6, SQL_PARAM_INPUT, SQL_C_DEFAULT, 5, 0, 0, (SQLPOINTER)MAREA.constData(), 0, &cbMAREA);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Parameters: Ordinal [7] Type: 4 Buffer Size: 4 FieldName: MPAGE ";
		r = SQLBindParameter(hStmt_Insert, 7, SQL_PARAM_INPUT, SQL_C_DEFAULT, 4, 0, 0, (SQLPOINTER)MPAGE.constData(), 0, &cbMPAGE);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Parameters: Ordinal [8] Type: 5 Buffer Size: 2 FieldName: MLINE ";
		r = SQLBindParameter(hStmt_Insert, 8, SQL_PARAM_INPUT, SQL_C_DEFAULT, 5, 0, 0, (SQLPOINTER)MLINE.constData(), 0, &cbMLINE);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
	}
	if (m_ReplicationOption == ReplicationOption::NetChange)
	{
		r = SQLBindParameter(hStmt_Update, 9, SQL_PARAM_INPUT, SQL_C_DEFAULT, 6, 0, 0, (SQLPOINTER)MAREA.constData(), 0, &cbMAREA);
		if (r == SQL_SUCCESS) { isValid=true; }
		r = SQLBindParameter(hStmt_Update, 10, SQL_PARAM_INPUT, SQL_C_DEFAULT, 7, 0, 0, (SQLPOINTER)MPAGE.constData(), 0, &cbMPAGE);
		if (r == SQL_SUCCESS) { isValid=true; }
		r = SQLBindParameter(hStmt_Update, 11, SQL_PARAM_INPUT, SQL_C_DEFAULT, 8, 0, 0, (SQLPOINTER)MLINE.constData(), 0, &cbMLINE);
		if (r == SQL_SUCCESS) { isValid=true; }
	// TK_LIDNOTSET is a well formed table for eNVy Replication 
		 qDebug(category) << " Parameters: Ordinal [6] 00 00 FieldName: MAREA ";
		 qDebug(category) << " Parameters: Ordinal [7] 00 00  FieldName: MPAGE ";
		 qDebug(category) << " Parameters: Ordinal [8] 00 00 FieldName:  MLINE ";
	} // 	if (m_ReplicationOption == ReplicationOption::NetChange)
	return isValid;
}

bool TK_LIDNOTSET::process(int rowSize)
{
	QLoggingCategory category("classLibQ");
	initOdbcAttributes();
	connect(Source);
	connect(Target);
	initialize();
	prepareTargetTable();
	prepare();
	bindColumn();
	bindParameter();
	copyTable();
	close();
	return false;
}

void TK_LIDNOTSET::copyTable()
{
	QLoggingCategory category("classLibQ");
	RETCODE r;
	QString check;
	r = SQLExecute(hStmt_Fetch);
		if (bIsAbort) {
			emit aborted(tableName, rowsFetched, rowsInserted, rowsUpdated);
			return;
		}
		while((r = SQLFetch(hStmt_Fetch)) != SQL_NO_DATA) {
		if (r != SQL_SUCCESS) {
			check = qWarnODBCHandle(SQL_HANDLE_STMT, hStmt_Fetch);
			qCCritical(category) << QString("SqlFetch - Error : %1 is %2").arg(fetchSql).arg(check);
			return;
		} 
		rowsFetched++;
		if (m_ReplicationOption == ReplicationOption::BulkCopy)
		{
			r = SQLExecute(hStmt_Insert);
			if (r == SQL_ERROR) {
				check = qWarnODBCHandle(SQL_HANDLE_STMT, hStmt_Insert);
				 qCCritical(category) << QString("SqlExecute:Insert - Error : %1 is %2").arg(insertSql).arg(check);
				return;
			}
			rowsInserted++;
			if ((rowsFetched % updateInterval) == 0) {
				qCInfo(category) << QString("[%1.%2]	Insertion: %3	Updates : %4	Fetched : %5").arg(profileName).arg(tableName).arg(rowsInserted).arg(rowsUpdated).arg(rowsFetched);
				emit updateStatusFetched(profileName, tableName, rowsFetched,rowsInserted,rowsUpdated);
			}
			if (m_ReplicationOption == ReplicationOption::NetChange)
			{
			r = SQLExecute(hStmt_Update);
			if (r != SQL_SUCCESS) {
				check = qWarnODBCHandle(SQL_HANDLE_STMT, hStmt_Update);
				 qCInfo(category)  << QString("SqlExecute:Update - Error : %1 is %2").arg(updateSql).arg(check);
				r = SQLExecute(hStmt_Insert);
				if (r != SQL_SUCCESS) {
					check = qWarnODBCHandle(SQL_HANDLE_STMT, hStmt_Insert);
					 qCritical(category) << QString("SqlExecute:Insert - Error : %1 is %2").arg(insertSql).arg(check);
					return;
				}
				else 	rowsInserted++;
				}
				else	rowsUpdated++;
			}
			emit updateStatusFetched(profileName, tableName, rowsFetched,rowsInserted,rowsUpdated);
		}
	} 
qCInfo(category) << QString("[%1.%2]	Insertion: %3	Updates : %4	Fetched : %5").arg(profileName).arg(tableName).arg(rowsInserted).arg(rowsUpdated).arg(rowsFetched);
}

void TK_LIDNOTSET::connect(connectionHandle connectionSource)
{

	QLoggingCategory category("classLibQ");
	RETCODE r;

	bool isValid = false;
	HWND	hWnd = nullptr;
	hWnd = ::GetDesktopWindow(); 
	SQLSMALLINT nResult = 0;

	SQLSMALLINT cb;
	UWORD wConnectOption = SQL_DRIVER_COMPLETE; //SQL_DRIVER_NOPROMPT;
	QVarLengthArray<SQLTCHAR> connOut(1024);
	memset(connOut.data(), 0, connOut.size() * sizeof(SQLTCHAR));

	switch (connectionSource)
	{
		case Source:
			{// environment
				SQLHANDLE hEnv = SQL_NULL_HANDLE;
				SQLHANDLE hDbc = SQL_NULL_HANDLE;
				r = ::SQLAllocHandle(SQL_HANDLE_ENV, SQL_NULL_HANDLE, &hEnv);
				if (r == SQL_SUCCESS) isValid = true;

				foreach(nOdbcAttributesClass * k, this->m_OdbcAttributes_Map)
				{
					if (k->attributeType == enumAttributeType::hEnv)
					{
						r = ::SQLSetEnvAttr(hEnv, (SQLINTEGER) k->odbcKey, (SQLPOINTER)k->odbcValue, 0);
						if (r == SQL_SUCCESS) isValid = true;
					}
				}
				hEnv_Source = hEnv;

				r = SQLAllocHandle(SQL_HANDLE_DBC, hEnv, &hDbc);
				if (r == SQL_SUCCESS) isValid = true;
				foreach(nOdbcAttributesClass * k, this->m_OdbcAttributes_Map)
				{
					if (k->attributeType == enumAttributeType::hDbc)
					{
					r = ::SQLSetConnectAttr(hDbc, k->odbcKey, (SQLPOINTER)k->odbcValue, 0);
					if (k->odbcKey == SQL_ATTR_CONNECTION_POOLING && k->odbcValue == SQL_CP_ONE_PER_DRIVER) wConnectOption = SQL_DRIVER_NOPROMPT;
					if (k->odbcKey == SQL_ATTR_CONNECTION_POOLING && k->odbcValue == SQL_CP_ONE_PER_HENV) wConnectOption = SQL_DRIVER_NOPROMPT;
					if (k->odbcKey == SQL_ATTR_CONNECTION_POOLING && k->odbcValue == SQL_CP_DRIVER_AWARE) wConnectOption = SQL_DRIVER_NOPROMPT;
					if (r == SQL_SUCCESS) isValid = true;
					}
				}
				hDbc_source = hDbc;
				if (isValid)
				{
					r = ::SQLDriverConnect(
						hDbc,
						hWnd,
#ifdef UNICODE
						toSQLTCHAR(m_lpszSourceDSN).data(),
#else
						(SQLCHAR*)dsnSource.toUtf8().data(),
#endif
						(SQLSMALLINT)m_lpszSourceDSN.length(),
						connOut.data(),
						1024,
						&cb, 
						wConnectOption); 
					int colSize = cb / sizeof(SQLTCHAR);
					if (r != SQL_SUCCESS && r != SQL_SUCCESS_WITH_INFO)
					{
						QString check = qWarnODBCHandle(SQL_HANDLE_DBC, hDbc);
						qCritical(category) <<  check;
						m_bIsOpen = false;
					}
					m_bIsOpen = true;
				}
			} break;
		case Target:
			{
				SQLHANDLE hEnv = SQL_NULL_HANDLE;
				SQLHANDLE hDbc = SQL_NULL_HANDLE;
				r = ::SQLAllocHandle(SQL_HANDLE_ENV, SQL_NULL_HANDLE, &hEnv);
				if (r == SQL_SUCCESS) isValid = true;

				foreach(nOdbcAttributesClass * k, this->m_OdbcAttributes_Map)
				{
					if (k->attributeType == enumAttributeType::hEnv)
					{
						r = ::SQLSetEnvAttr(hEnv, (SQLINTEGER) k->odbcKey, (SQLPOINTER)k->odbcValue, 0);
						if (r == SQL_SUCCESS) isValid = true;
					}
				}
				hEnv_Target = hEnv;

				r = SQLAllocHandle(SQL_HANDLE_DBC, hEnv, &hDbc);
				if (r == SQL_SUCCESS) isValid = true;
				foreach(nOdbcAttributesClass * k, this->m_OdbcAttributes_Map)
				{
				if (k->attributeType == enumAttributeType::hDbc)
					{
					r = ::SQLSetConnectAttr(hDbc, k->odbcKey, (SQLPOINTER)k->odbcValue, 0);
					if (k->odbcKey == SQL_ATTR_CONNECTION_POOLING && k->odbcValue == SQL_CP_ONE_PER_DRIVER) wConnectOption = SQL_DRIVER_NOPROMPT;
					if (k->odbcKey == SQL_ATTR_CONNECTION_POOLING && k->odbcValue == SQL_CP_ONE_PER_HENV) wConnectOption = SQL_DRIVER_NOPROMPT;
					if (k->odbcKey == SQL_ATTR_CONNECTION_POOLING && k->odbcValue == SQL_CP_DRIVER_AWARE) wConnectOption = SQL_DRIVER_NOPROMPT;
					if (r == SQL_SUCCESS) isValid = true;
					}
				}
				hDbc_target = hDbc;
				if (isValid) {
					r = ::SQLDriverConnect(
						hDbc,
						hWnd,
#ifdef UNICODE
						toSQLTCHAR(m_lpszTargetDSN).data(),
#else
						(SQLCHAR*)m_lpszTargetDSN.toUtf8().data(),
#endif
						(SQLSMALLINT)m_lpszTargetDSN.length(),
						connOut.data(),
						1024,
						&cb, 
						wConnectOption); 
						int colSize = cb / sizeof(SQLTCHAR);
					if (r != SQL_SUCCESS && r != SQL_SUCCESS_WITH_INFO)
						{
							QString check = qWarnODBCHandle(SQL_HANDLE_DBC, hDbc);
							qCritical(category) <<  check;
							m_bIsOpen = false;
						}
							m_bIsOpen = true;
					}
			} break;
			default: break;
	}
}
TK_INTTOHSHSET::TK_INTTOHSHSET(QObject * parent) : QObject(parent) 
,tableName("TK_INTTOHSHSET")
,m_dropOption(DropOption::DropTable) { 
	numRowsFetched = 0;
}

#pragma region ~CTOR TK_INTTOHSHSET 
TK_INTTOHSHSET::~TK_INTTOHSHSET() { 

#pragma region Buffers - Clear 
	DB_ID.clear();
	NVTIMESTAMP.clear();
	OAREA.clear();
	OPAGE.clear();
	OLINE.clear();
	MAREA.clear();
	MPAGE.clear();
	MLINE.clear();
#pragma endregion Buffers - Clear 
}
#pragma endregion Destructor_TK_INTTOHSHSET

// begin method functions
void TK_INTTOHSHSET::setAbortFlag() { 
	QLoggingCategory category("classLibQ");
	qCInfo(category) << "isAbort was set to True";
	bIsAbort = true;
}

void TK_INTTOHSHSET::run() { 
	process(1);
	QLoggingCategory category("classLibQ");
	qDebug(category) << "Entered;";
}

void	TK_INTTOHSHSET::initOdbcAttributes()
{
	QLoggingCategory category("classLibQ");
	this->setProfileName(profileName);
	qDebug(category) << "Processing - TRKDB100"; 
	m_OdbcAttributesList = m_OdbcAttributes.split(","); 
	foreach(QString m, m_OdbcAttributesList)
	{
		QStringList keyValue = m.split("=");
		nOdbcAttributesClass * oM = new nOdbcAttributesClass(this);
		if (oM->loadToOdbc(keyValue.value(0), keyValue.value(1)))
		{
			m_OdbcAttributes_Map.insert(oM->odbcKey, oM);
		}
	}
}
void	TK_INTTOHSHSET::initialize()
{
	QLoggingCategory category("classLibQ");
	RETCODE r;
	this->setProfileName(profileName);
	qDebug(category) << "Processing - TRKDB100"; 
//SQL Statements
//--------------------------------------------------

#pragma region Sql Statements_TK_INTTOHSHSET

	fetchSql = "select  DB_ID, NVTIMESTAMP, OAREA, OPAGE, OLINE, MAREA, MPAGE, MLINE from TK_INTTOHSHSET";
		if (m_ReplicationOption == ReplicationOption::NetChange)
		{
			fetchSql.append(" p1, nv_transfers p2 WHERE  p2.table_name = 'TK_INTTOHSHSET' AND p1.nvtimestamp > p2.last_completed");
		}
	insertSql = "insert into TK_INTTOHSHSET ( PLANT_CODE, NVTIMESTAMP, OAREA, OPAGE, OLINE, MAREA, MPAGE, MLINE ) values ( ?, ?, ?, ?, ?, ?, ?, ?)";
	updateSql = "update TK_INTTOHSHSET set  PLANT_CODE = ?, NVTIMESTAMP = ?, OAREA = ?, OPAGE = ?, OLINE = ?, MAREA = ?, MPAGE = ?, MLINE = ?  where area = ? and page = ? line = ? ";

	qDebug(category) << "insertSQL - insert into TK_INTTOHSHSET ( PLANT_CODE, NVTIMESTAMP, OAREA, OPAGE, OLINE, MAREA, MPAGE, MLINE ) values ( ?, ?, ?, ?, ?, ?, ?, ?)";
	qDebug(category) << "fetchSQL - select  DB_ID, NVTIMESTAMP, OAREA, OPAGE, OLINE, MAREA, MPAGE, MLINE from TK_INTTOHSHSET";
	qDebug(category) << "unsertSQL - update TK_INTTOHSHSET set  PLANT_CODE = ?, NVTIMESTAMP = ?, OAREA = ?, OPAGE = ?, OLINE = ?, MAREA = ?, MPAGE = ?, MLINE = ?  where area = ? and page = ? line = ? ";

#pragma endregion Sql Statements_TK_INTTOHSHSET
	SQLHANDLE		insert_hStmt = SQL_NULL_HANDLE;
	SQLHANDLE		fetch_hStmt = SQL_NULL_HANDLE; 
	SQLHANDLE		update_hStmt = SQL_NULL_HANDLE; 
 
	r = ::SQLAllocHandle(SQL_HANDLE_STMT, hDbc_source, &fetch_hStmt);
	if (r != SQL_SUCCESS) {
		 qCCritical(category) << QString("Error  hDbc_Source SQLCode : %1 is %2").arg(QString::number( (long)hDbc_source)).arg(QString::number(r));
		return; 
	}
	r = ::SQLAllocHandle(SQL_HANDLE_STMT, hDbc_target, &insert_hStmt);
	if (r != SQL_SUCCESS) {
		 qCCritical(category) << QString("Error hDbc_Source -SQLCode: %1 is %2").arg(QString::number( (long)hDbc_target)).arg(QString::number(r));
		return; 
	}
	r = ::SQLAllocHandle(SQL_HANDLE_STMT, hDbc_target, &update_hStmt);
	if (r != SQL_SUCCESS) {
		 qCCritical(category) << QString("Error hDbc_Source +SQLCode: %1 is %2").arg(QString::number( (long)hDbc_target)).arg(QString::number(r));
		return; 
	}
 
	hStmt_Fetch = fetch_hStmt;
	hStmt_Insert = insert_hStmt;
	hStmt_Update = update_hStmt;
 
	SQLSetStmtAttr(hStmt_Fetch, SQL_ATTR_USE_BOOKMARKS, (SQLPOINTER)SQL_UB_OFF, 0);
	SQLSetStmtAttr(hStmt_Fetch, SQL_ATTR_ROW_BIND_TYPE, (SQLPOINTER)SQL_BIND_BY_COLUMN, 0);
	SQLSetStmtAttr(hStmt_Fetch, SQL_ATTR_ROW_ARRAY_SIZE, (SQLPOINTER)1, 0);
	SQLSetStmtAttr(hStmt_Fetch, SQL_ATTR_ROWS_FETCHED_PTR, &numRowsFetched, 0);

// Fields used by this class 
// ---------------------------------------------------

#pragma region Resize Fields TK_INTTOHSHSET
	qDebug(category) << "Malloc - DB_ID[2]";
	DB_ID.resize(2);
	qDebug(category) << "Malloc - NVTIMESTAMP[23]";
	NVTIMESTAMP.resize(23);
	qDebug(category) << "Malloc - OAREA[2]";
	OAREA.resize(2);
	qDebug(category) << "Malloc - OPAGE[4]";
	OPAGE.resize(4);
	qDebug(category) << "Malloc - OLINE[2]";
	OLINE.resize(2);
	qDebug(category) << "Malloc - MAREA[2]";
	MAREA.resize(2);
	qDebug(category) << "Malloc - MPAGE[4]";
	MPAGE.resize(4);
	qDebug(category) << "Malloc - MLINE[2]";
	MLINE.resize(2);

#pragma endregion Resize Fields TK_INTTOHSHSET
}
void TK_INTTOHSHSET::close()
{
	QLoggingCategory category("classLibQ");
	if (m_bIsOpen)
	{
	qDebug(category) << "database is Open";
		SQLHANDLE source_hStmt = hStmt_Fetch;
		SQLHANDLE insert_hStmt = hStmt_Insert;
		SQLHANDLE hDb_S = this->hDbc_source;
		SQLHANDLE hDb_T = hDbc_target;
		SQLHANDLE hEnvS = hEnv_Source;
		SQLHANDLE hEnvT = hEnv_Target;
		RETCODE r;

		r = ::SQLFreeHandle(SQL_HANDLE_STMT, hStmt_Fetch);
		r = ::SQLFreeHandle(SQL_HANDLE_STMT, hStmt_Insert);
		r = ::SQLFreeHandle(SQL_HANDLE_STMT, hStmt_Update);
		if (hDbc_source != SQL_NULL_HANDLE) 		r = ::SQLDisconnect(hDb_S);
		if (hDbc_target != SQL_NULL_HANDLE) 		r = ::SQLDisconnect(hDb_T);

		r = ::SQLFreeHandle(SQL_HANDLE_DBC, hDb_S);
		r = ::SQLFreeHandle(SQL_HANDLE_DBC, hDb_T);
		r = ::SQLFreeHandle(SQL_HANDLE_ENV, hEnvS);
		r = ::SQLFreeHandle(SQL_HANDLE_ENV, hEnvT);
	}

	hEnv_Source = SQL_NULL_HANDLE;
	hEnv_Target = SQL_NULL_HANDLE;
	hEnv_Source = SQL_NULL_HANDLE;
	hEnv_Target = SQL_NULL_HANDLE;
	hStmt_Fetch = SQL_NULL_HANDLE;
	hStmt_Insert = SQL_NULL_HANDLE;
	hStmt_Update = SQL_NULL_HANDLE;
}

void TK_INTTOHSHSET::open(const QString sourceDSN, const QString targetDSN)
{
	QLoggingCategory category("classLibQ");
	m_lpszTargetDSN = targetDSN;
	m_lpszSourceDSN = sourceDSN;
	qDebug(category) << QString("Source - %1[%2]").arg(sourceDSN);
	qDebug(category) << QString("Target - %1[%2]").arg(targetDSN);
}

void TK_INTTOHSHSET::createTable()
{
	QLoggingCategory category("classLibQ");
	{
		QScopedPointer<nvTableOracleRdb> tbl(new nvTableOracleRdb(nullptr));
		tbl->initialize("TK_INTTOHSHSET", this->m_lpszSourceDSN);
		QString newTbl = tbl->getCreateTableSQL();
		QScopedPointer<qVtExecute> vExec(new qVtExecute(nullptr));
		{
			vExec->initialize(m_lpszTargetDSN, " ", true);
			vExec->setOdbcAttributes(m_OdbcAttributes);
			vExec->ExecuteDirect(newTbl);
		}
	 qDebug(category) << QString("End Create Table %1 ").arg(tableName); 
	}
}

bool TK_INTTOHSHSET::prepare()
{
	RETCODE r;
	QString check;
	QLoggingCategory category("classLibQ");
	 qDebug(category) << fetchSql;
	 qDebug(category) << insertSql;
#ifdef UNICODE
	r = SQLPrepare(hStmt_Insert,toSQLTCHAR(insertSql).data(),(SQLINTEGER)insertSql.length()); 
	if (r != SQL_SUCCESS) {
		check = qWarnODBCHandle(SQL_HANDLE_STMT, hStmt_Insert);
		 qCCritical(category) << QString("Prepare Statement-Insert : %1 is %2").arg(insertSql).arg(check);
		return false; 
	}
	r = SQLPrepare(hStmt_Update,toSQLTCHAR(updateSql).data(),(SQLINTEGER)updateSql.length()); 
	if (r != SQL_SUCCESS) {
		check = qWarnODBCHandle(SQL_HANDLE_STMT, hStmt_Update);
		 qCCritical(category) << QString("Prepare Statement-Update : %1 is %2").arg(updateSql).arg(check);
		return false; 
	}
	r = SQLPrepare(hStmt_Fetch,toSQLTCHAR(fetchSql).data(),(SQLINTEGER)fetchSql.length());
	if (r != SQL_SUCCESS) {
		check = qWarnODBCHandle(SQL_HANDLE_STMT, hStmt_Fetch);
		 qCCritical(category) << QString("Prepare Statement-Insert : %1 is %2").arg(fetchSql).arg(check);
		return false; 
	}
#else
	QByteArray queryI8 = insertSql.toUtf8();
	r = SQLPrepare(insert_hStmt,SQLCHAR*)queryI8.data(),(SQLINTEGER)queryI8.length());
	QByteArray queryU8 = fetchSql.toUtf8();
	r = SQLPrepare(hStmt_Fetch,(SQLCHAR*)queryU8.data(),(SQLINTEGER)queryU8.length());
#endif
	return true;

}

void TK_INTTOHSHSET::prepareTargetTable()
{
	QLoggingCategory category("classLibQ");
	if (this->m_ReplicationOption == ReplicationOption::BulkCopy)
	{
		QScopedPointer<qVtExecute> execSql(new qVtExecute(nullptr));
		DropOption option = this->m_dropOption;
		switch (option)
		{
			case DropOption::DeleteFromTable:
			{
				QLoggingCategory category("classLibQ");
				execSql->initialize(this->m_lpszTargetDSN, "delete from TK_INTTOHSHSET", true);
				execSql->setOdbcAttributes(this->m_OdbcAttributes);
				execSql->ExecuteDirect("delete from TK_INTTOHSHSET");
			}break;
			case DropOption::TruncateTable:
			{
				execSql->initialize(this->m_lpszTargetDSN, "truncate table TK_INTTOHSHSET", true);
				execSql->setOdbcAttributes(this->m_OdbcAttributes);
				execSql->ExecuteDirect("truncate table TK_INTTOHSHSET");
			}break;
			case DropOption::DropTable:
			{
				execSql->initialize(this->m_lpszTargetDSN, "drop table TK_INTTOHSHSET", true);
				execSql->setOdbcAttributes(this->m_OdbcAttributes);
				execSql->ExecuteDirect("drop table TK_INTTOHSHSET");
				createTable();
			}break;
		}
	}
}

bool TK_INTTOHSHSET::bindColumn()
{
	QLoggingCategory category("classLibQ");
	RETCODE r;
	bool isValid=true;
		 qDebug(category) << " Bindings: Ordinal [1] Type: 5 Buffer Size: 2 FieldName: DB_ID ";
		r = ::SQLBindCol(hStmt_Fetch, 1, 5, DB_ID.data(), 2, &cbDB_ID);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Bindings: Ordinal [2] Type: 93 Buffer Size: 23 FieldName: NVTIMESTAMP ";
		r = ::SQLBindCol(hStmt_Fetch, 2, 93, NVTIMESTAMP.data(), 23, &cbNVTIMESTAMP);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Bindings: Ordinal [3] Type: 5 Buffer Size: 2 FieldName: OAREA ";
		r = ::SQLBindCol(hStmt_Fetch, 3, 5, OAREA.data(), 2, &cbOAREA);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Bindings: Ordinal [4] Type: 4 Buffer Size: 4 FieldName: OPAGE ";
		r = ::SQLBindCol(hStmt_Fetch, 4, 4, OPAGE.data(), 4, &cbOPAGE);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Bindings: Ordinal [5] Type: 5 Buffer Size: 2 FieldName: OLINE ";
		r = ::SQLBindCol(hStmt_Fetch, 5, 5, OLINE.data(), 2, &cbOLINE);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Bindings: Ordinal [6] Type: 5 Buffer Size: 2 FieldName: MAREA ";
		r = ::SQLBindCol(hStmt_Fetch, 6, 5, MAREA.data(), 2, &cbMAREA);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Bindings: Ordinal [7] Type: 4 Buffer Size: 4 FieldName: MPAGE ";
		r = ::SQLBindCol(hStmt_Fetch, 7, 4, MPAGE.data(), 4, &cbMPAGE);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Bindings: Ordinal [8] Type: 5 Buffer Size: 2 FieldName: MLINE ";
		r = ::SQLBindCol(hStmt_Fetch, 8, 5, MLINE.data(), 2, &cbMLINE);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
	return isValid;
}

bool TK_INTTOHSHSET::bindParameter()
{
	QLoggingCategory category("classLibQ");
	RETCODE r;
	bool isValid=true;
	{
		 qDebug(category) << " Parameters: Ordinal [1] Type: 5 Buffer Size: 2 FieldName: DB_ID ";
		r = SQLBindParameter(hStmt_Insert, 1, SQL_PARAM_INPUT, SQL_C_DEFAULT, 5, 0, 0, (SQLPOINTER)DB_ID.constData(), 0, &cbDB_ID);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Parameters: Ordinal [2] Type: 93 Buffer Size: 23 FieldName: NVTIMESTAMP ";
		r = SQLBindParameter(hStmt_Insert, 2, SQL_PARAM_INPUT, SQL_C_DEFAULT, 93, 23, 0, (SQLPOINTER)NVTIMESTAMP.constData(), 0, &cbNVTIMESTAMP);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Parameters: Ordinal [3] Type: 5 Buffer Size: 2 FieldName: OAREA ";
		r = SQLBindParameter(hStmt_Insert, 3, SQL_PARAM_INPUT, SQL_C_DEFAULT, 5, 0, 0, (SQLPOINTER)OAREA.constData(), 0, &cbOAREA);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Parameters: Ordinal [4] Type: 4 Buffer Size: 4 FieldName: OPAGE ";
		r = SQLBindParameter(hStmt_Insert, 4, SQL_PARAM_INPUT, SQL_C_DEFAULT, 4, 0, 0, (SQLPOINTER)OPAGE.constData(), 0, &cbOPAGE);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Parameters: Ordinal [5] Type: 5 Buffer Size: 2 FieldName: OLINE ";
		r = SQLBindParameter(hStmt_Insert, 5, SQL_PARAM_INPUT, SQL_C_DEFAULT, 5, 0, 0, (SQLPOINTER)OLINE.constData(), 0, &cbOLINE);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Parameters: Ordinal [6] Type: 5 Buffer Size: 2 FieldName: MAREA ";
		r = SQLBindParameter(hStmt_Insert, 6, SQL_PARAM_INPUT, SQL_C_DEFAULT, 5, 0, 0, (SQLPOINTER)MAREA.constData(), 0, &cbMAREA);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Parameters: Ordinal [7] Type: 4 Buffer Size: 4 FieldName: MPAGE ";
		r = SQLBindParameter(hStmt_Insert, 7, SQL_PARAM_INPUT, SQL_C_DEFAULT, 4, 0, 0, (SQLPOINTER)MPAGE.constData(), 0, &cbMPAGE);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Parameters: Ordinal [8] Type: 5 Buffer Size: 2 FieldName: MLINE ";
		r = SQLBindParameter(hStmt_Insert, 8, SQL_PARAM_INPUT, SQL_C_DEFAULT, 5, 0, 0, (SQLPOINTER)MLINE.constData(), 0, &cbMLINE);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
	}
	if (m_ReplicationOption == ReplicationOption::NetChange)
	{
		r = SQLBindParameter(hStmt_Update, 9, SQL_PARAM_INPUT, SQL_C_DEFAULT, 6, 0, 0, (SQLPOINTER)MAREA.constData(), 0, &cbMAREA);
		if (r == SQL_SUCCESS) { isValid=true; }
		r = SQLBindParameter(hStmt_Update, 10, SQL_PARAM_INPUT, SQL_C_DEFAULT, 7, 0, 0, (SQLPOINTER)MPAGE.constData(), 0, &cbMPAGE);
		if (r == SQL_SUCCESS) { isValid=true; }
		r = SQLBindParameter(hStmt_Update, 11, SQL_PARAM_INPUT, SQL_C_DEFAULT, 8, 0, 0, (SQLPOINTER)MLINE.constData(), 0, &cbMLINE);
		if (r == SQL_SUCCESS) { isValid=true; }
	// TK_INTTOHSHSET is a well formed table for eNVy Replication 
		 qDebug(category) << " Parameters: Ordinal [6] 00 00 FieldName: MAREA ";
		 qDebug(category) << " Parameters: Ordinal [7] 00 00  FieldName: MPAGE ";
		 qDebug(category) << " Parameters: Ordinal [8] 00 00 FieldName:  MLINE ";
	} // 	if (m_ReplicationOption == ReplicationOption::NetChange)
	return isValid;
}

bool TK_INTTOHSHSET::process(int rowSize)
{
	QLoggingCategory category("classLibQ");
	initOdbcAttributes();
	connect(Source);
	connect(Target);
	initialize();
	prepareTargetTable();
	prepare();
	bindColumn();
	bindParameter();
	copyTable();
	close();
	return false;
}

void TK_INTTOHSHSET::copyTable()
{
	QLoggingCategory category("classLibQ");
	RETCODE r;
	QString check;
	r = SQLExecute(hStmt_Fetch);
		if (bIsAbort) {
			emit aborted(tableName, rowsFetched, rowsInserted, rowsUpdated);
			return;
		}
		while((r = SQLFetch(hStmt_Fetch)) != SQL_NO_DATA) {
		if (r != SQL_SUCCESS) {
			check = qWarnODBCHandle(SQL_HANDLE_STMT, hStmt_Fetch);
			qCCritical(category) << QString("SqlFetch - Error : %1 is %2").arg(fetchSql).arg(check);
			return;
		} 
		rowsFetched++;
		if (m_ReplicationOption == ReplicationOption::BulkCopy)
		{
			r = SQLExecute(hStmt_Insert);
			if (r == SQL_ERROR) {
				check = qWarnODBCHandle(SQL_HANDLE_STMT, hStmt_Insert);
				 qCCritical(category) << QString("SqlExecute:Insert - Error : %1 is %2").arg(insertSql).arg(check);
				return;
			}
			rowsInserted++;
			if ((rowsFetched % updateInterval) == 0) {
				qCInfo(category) << QString("[%1.%2]	Insertion: %3	Updates : %4	Fetched : %5").arg(profileName).arg(tableName).arg(rowsInserted).arg(rowsUpdated).arg(rowsFetched);
				emit updateStatusFetched(profileName, tableName, rowsFetched,rowsInserted,rowsUpdated);
			}
			if (m_ReplicationOption == ReplicationOption::NetChange)
			{
			r = SQLExecute(hStmt_Update);
			if (r != SQL_SUCCESS) {
				check = qWarnODBCHandle(SQL_HANDLE_STMT, hStmt_Update);
				 qCInfo(category)  << QString("SqlExecute:Update - Error : %1 is %2").arg(updateSql).arg(check);
				r = SQLExecute(hStmt_Insert);
				if (r != SQL_SUCCESS) {
					check = qWarnODBCHandle(SQL_HANDLE_STMT, hStmt_Insert);
					 qCritical(category) << QString("SqlExecute:Insert - Error : %1 is %2").arg(insertSql).arg(check);
					return;
				}
				else 	rowsInserted++;
				}
				else	rowsUpdated++;
			}
			emit updateStatusFetched(profileName, tableName, rowsFetched,rowsInserted,rowsUpdated);
		}
	} 
qCInfo(category) << QString("[%1.%2]	Insertion: %3	Updates : %4	Fetched : %5").arg(profileName).arg(tableName).arg(rowsInserted).arg(rowsUpdated).arg(rowsFetched);
}

void TK_INTTOHSHSET::connect(connectionHandle connectionSource)
{

	QLoggingCategory category("classLibQ");
	RETCODE r;

	bool isValid = false;
	HWND	hWnd = nullptr;
	hWnd = ::GetDesktopWindow(); 
	SQLSMALLINT nResult = 0;

	SQLSMALLINT cb;
	UWORD wConnectOption = SQL_DRIVER_COMPLETE; //SQL_DRIVER_NOPROMPT;
	QVarLengthArray<SQLTCHAR> connOut(1024);
	memset(connOut.data(), 0, connOut.size() * sizeof(SQLTCHAR));

	switch (connectionSource)
	{
		case Source:
			{// environment
				SQLHANDLE hEnv = SQL_NULL_HANDLE;
				SQLHANDLE hDbc = SQL_NULL_HANDLE;
				r = ::SQLAllocHandle(SQL_HANDLE_ENV, SQL_NULL_HANDLE, &hEnv);
				if (r == SQL_SUCCESS) isValid = true;

				foreach(nOdbcAttributesClass * k, this->m_OdbcAttributes_Map)
				{
					if (k->attributeType == enumAttributeType::hEnv)
					{
						r = ::SQLSetEnvAttr(hEnv, (SQLINTEGER) k->odbcKey, (SQLPOINTER)k->odbcValue, 0);
						if (r == SQL_SUCCESS) isValid = true;
					}
				}
				hEnv_Source = hEnv;

				r = SQLAllocHandle(SQL_HANDLE_DBC, hEnv, &hDbc);
				if (r == SQL_SUCCESS) isValid = true;
				foreach(nOdbcAttributesClass * k, this->m_OdbcAttributes_Map)
				{
					if (k->attributeType == enumAttributeType::hDbc)
					{
					r = ::SQLSetConnectAttr(hDbc, k->odbcKey, (SQLPOINTER)k->odbcValue, 0);
					if (k->odbcKey == SQL_ATTR_CONNECTION_POOLING && k->odbcValue == SQL_CP_ONE_PER_DRIVER) wConnectOption = SQL_DRIVER_NOPROMPT;
					if (k->odbcKey == SQL_ATTR_CONNECTION_POOLING && k->odbcValue == SQL_CP_ONE_PER_HENV) wConnectOption = SQL_DRIVER_NOPROMPT;
					if (k->odbcKey == SQL_ATTR_CONNECTION_POOLING && k->odbcValue == SQL_CP_DRIVER_AWARE) wConnectOption = SQL_DRIVER_NOPROMPT;
					if (r == SQL_SUCCESS) isValid = true;
					}
				}
				hDbc_source = hDbc;
				if (isValid)
				{
					r = ::SQLDriverConnect(
						hDbc,
						hWnd,
#ifdef UNICODE
						toSQLTCHAR(m_lpszSourceDSN).data(),
#else
						(SQLCHAR*)dsnSource.toUtf8().data(),
#endif
						(SQLSMALLINT)m_lpszSourceDSN.length(),
						connOut.data(),
						1024,
						&cb, 
						wConnectOption); 
					int colSize = cb / sizeof(SQLTCHAR);
					if (r != SQL_SUCCESS && r != SQL_SUCCESS_WITH_INFO)
					{
						QString check = qWarnODBCHandle(SQL_HANDLE_DBC, hDbc);
						qCritical(category) <<  check;
						m_bIsOpen = false;
					}
					m_bIsOpen = true;
				}
			} break;
		case Target:
			{
				SQLHANDLE hEnv = SQL_NULL_HANDLE;
				SQLHANDLE hDbc = SQL_NULL_HANDLE;
				r = ::SQLAllocHandle(SQL_HANDLE_ENV, SQL_NULL_HANDLE, &hEnv);
				if (r == SQL_SUCCESS) isValid = true;

				foreach(nOdbcAttributesClass * k, this->m_OdbcAttributes_Map)
				{
					if (k->attributeType == enumAttributeType::hEnv)
					{
						r = ::SQLSetEnvAttr(hEnv, (SQLINTEGER) k->odbcKey, (SQLPOINTER)k->odbcValue, 0);
						if (r == SQL_SUCCESS) isValid = true;
					}
				}
				hEnv_Target = hEnv;

				r = SQLAllocHandle(SQL_HANDLE_DBC, hEnv, &hDbc);
				if (r == SQL_SUCCESS) isValid = true;
				foreach(nOdbcAttributesClass * k, this->m_OdbcAttributes_Map)
				{
				if (k->attributeType == enumAttributeType::hDbc)
					{
					r = ::SQLSetConnectAttr(hDbc, k->odbcKey, (SQLPOINTER)k->odbcValue, 0);
					if (k->odbcKey == SQL_ATTR_CONNECTION_POOLING && k->odbcValue == SQL_CP_ONE_PER_DRIVER) wConnectOption = SQL_DRIVER_NOPROMPT;
					if (k->odbcKey == SQL_ATTR_CONNECTION_POOLING && k->odbcValue == SQL_CP_ONE_PER_HENV) wConnectOption = SQL_DRIVER_NOPROMPT;
					if (k->odbcKey == SQL_ATTR_CONNECTION_POOLING && k->odbcValue == SQL_CP_DRIVER_AWARE) wConnectOption = SQL_DRIVER_NOPROMPT;
					if (r == SQL_SUCCESS) isValid = true;
					}
				}
				hDbc_target = hDbc;
				if (isValid) {
					r = ::SQLDriverConnect(
						hDbc,
						hWnd,
#ifdef UNICODE
						toSQLTCHAR(m_lpszTargetDSN).data(),
#else
						(SQLCHAR*)m_lpszTargetDSN.toUtf8().data(),
#endif
						(SQLSMALLINT)m_lpszTargetDSN.length(),
						connOut.data(),
						1024,
						&cb, 
						wConnectOption); 
						int colSize = cb / sizeof(SQLTCHAR);
					if (r != SQL_SUCCESS && r != SQL_SUCCESS_WITH_INFO)
						{
							QString check = qWarnODBCHandle(SQL_HANDLE_DBC, hDbc);
							qCritical(category) <<  check;
							m_bIsOpen = false;
						}
							m_bIsOpen = true;
					}
			} break;
			default: break;
	}
}
TK_FLGHSHSET::TK_FLGHSHSET(QObject * parent) : QObject(parent) 
,tableName("TK_FLGHSHSET")
,m_dropOption(DropOption::DropTable) { 
	numRowsFetched = 0;
}

#pragma region ~CTOR TK_FLGHSHSET 
TK_FLGHSHSET::~TK_FLGHSHSET() { 

#pragma region Buffers - Clear 
	DB_ID.clear();
	NVTIMESTAMP.clear();
	OAREA.clear();
	OPAGE.clear();
	OLINE.clear();
	MAREA.clear();
	MPAGE.clear();
	MLINE.clear();
#pragma endregion Buffers - Clear 
}
#pragma endregion Destructor_TK_FLGHSHSET

// begin method functions
void TK_FLGHSHSET::setAbortFlag() { 
	QLoggingCategory category("classLibQ");
	qCInfo(category) << "isAbort was set to True";
	bIsAbort = true;
}

void TK_FLGHSHSET::run() { 
	process(1);
	QLoggingCategory category("classLibQ");
	qDebug(category) << "Entered;";
}

void	TK_FLGHSHSET::initOdbcAttributes()
{
	QLoggingCategory category("classLibQ");
	this->setProfileName(profileName);
	qDebug(category) << "Processing - TRKDB100"; 
	m_OdbcAttributesList = m_OdbcAttributes.split(","); 
	foreach(QString m, m_OdbcAttributesList)
	{
		QStringList keyValue = m.split("=");
		nOdbcAttributesClass * oM = new nOdbcAttributesClass(this);
		if (oM->loadToOdbc(keyValue.value(0), keyValue.value(1)))
		{
			m_OdbcAttributes_Map.insert(oM->odbcKey, oM);
		}
	}
}
void	TK_FLGHSHSET::initialize()
{
	QLoggingCategory category("classLibQ");
	RETCODE r;
	this->setProfileName(profileName);
	qDebug(category) << "Processing - TRKDB100"; 
//SQL Statements
//--------------------------------------------------

#pragma region Sql Statements_TK_FLGHSHSET

	fetchSql = "select  DB_ID, NVTIMESTAMP, OAREA, OPAGE, OLINE, MAREA, MPAGE, MLINE from TK_FLGHSHSET";
		if (m_ReplicationOption == ReplicationOption::NetChange)
		{
			fetchSql.append(" p1, nv_transfers p2 WHERE  p2.table_name = 'TK_FLGHSHSET' AND p1.nvtimestamp > p2.last_completed");
		}
	insertSql = "insert into TK_FLGHSHSET ( PLANT_CODE, NVTIMESTAMP, OAREA, OPAGE, OLINE, MAREA, MPAGE, MLINE ) values ( ?, ?, ?, ?, ?, ?, ?, ?)";
	updateSql = "update TK_FLGHSHSET set  PLANT_CODE = ?, NVTIMESTAMP = ?, OAREA = ?, OPAGE = ?, OLINE = ?, MAREA = ?, MPAGE = ?, MLINE = ?  where area = ? and page = ? line = ? ";

	qDebug(category) << "insertSQL - insert into TK_FLGHSHSET ( PLANT_CODE, NVTIMESTAMP, OAREA, OPAGE, OLINE, MAREA, MPAGE, MLINE ) values ( ?, ?, ?, ?, ?, ?, ?, ?)";
	qDebug(category) << "fetchSQL - select  DB_ID, NVTIMESTAMP, OAREA, OPAGE, OLINE, MAREA, MPAGE, MLINE from TK_FLGHSHSET";
	qDebug(category) << "unsertSQL - update TK_FLGHSHSET set  PLANT_CODE = ?, NVTIMESTAMP = ?, OAREA = ?, OPAGE = ?, OLINE = ?, MAREA = ?, MPAGE = ?, MLINE = ?  where area = ? and page = ? line = ? ";

#pragma endregion Sql Statements_TK_FLGHSHSET
	SQLHANDLE		insert_hStmt = SQL_NULL_HANDLE;
	SQLHANDLE		fetch_hStmt = SQL_NULL_HANDLE; 
	SQLHANDLE		update_hStmt = SQL_NULL_HANDLE; 
 
	r = ::SQLAllocHandle(SQL_HANDLE_STMT, hDbc_source, &fetch_hStmt);
	if (r != SQL_SUCCESS) {
		 qCCritical(category) << QString("Error  hDbc_Source SQLCode : %1 is %2").arg(QString::number( (long)hDbc_source)).arg(QString::number(r));
		return; 
	}
	r = ::SQLAllocHandle(SQL_HANDLE_STMT, hDbc_target, &insert_hStmt);
	if (r != SQL_SUCCESS) {
		 qCCritical(category) << QString("Error hDbc_Source -SQLCode: %1 is %2").arg(QString::number( (long)hDbc_target)).arg(QString::number(r));
		return; 
	}
	r = ::SQLAllocHandle(SQL_HANDLE_STMT, hDbc_target, &update_hStmt);
	if (r != SQL_SUCCESS) {
		 qCCritical(category) << QString("Error hDbc_Source +SQLCode: %1 is %2").arg(QString::number( (long)hDbc_target)).arg(QString::number(r));
		return; 
	}
 
	hStmt_Fetch = fetch_hStmt;
	hStmt_Insert = insert_hStmt;
	hStmt_Update = update_hStmt;
 
	SQLSetStmtAttr(hStmt_Fetch, SQL_ATTR_USE_BOOKMARKS, (SQLPOINTER)SQL_UB_OFF, 0);
	SQLSetStmtAttr(hStmt_Fetch, SQL_ATTR_ROW_BIND_TYPE, (SQLPOINTER)SQL_BIND_BY_COLUMN, 0);
	SQLSetStmtAttr(hStmt_Fetch, SQL_ATTR_ROW_ARRAY_SIZE, (SQLPOINTER)1, 0);
	SQLSetStmtAttr(hStmt_Fetch, SQL_ATTR_ROWS_FETCHED_PTR, &numRowsFetched, 0);

// Fields used by this class 
// ---------------------------------------------------

#pragma region Resize Fields TK_FLGHSHSET
	qDebug(category) << "Malloc - DB_ID[2]";
	DB_ID.resize(2);
	qDebug(category) << "Malloc - NVTIMESTAMP[23]";
	NVTIMESTAMP.resize(23);
	qDebug(category) << "Malloc - OAREA[2]";
	OAREA.resize(2);
	qDebug(category) << "Malloc - OPAGE[4]";
	OPAGE.resize(4);
	qDebug(category) << "Malloc - OLINE[2]";
	OLINE.resize(2);
	qDebug(category) << "Malloc - MAREA[2]";
	MAREA.resize(2);
	qDebug(category) << "Malloc - MPAGE[4]";
	MPAGE.resize(4);
	qDebug(category) << "Malloc - MLINE[2]";
	MLINE.resize(2);

#pragma endregion Resize Fields TK_FLGHSHSET
}
void TK_FLGHSHSET::close()
{
	QLoggingCategory category("classLibQ");
	if (m_bIsOpen)
	{
	qDebug(category) << "database is Open";
		SQLHANDLE source_hStmt = hStmt_Fetch;
		SQLHANDLE insert_hStmt = hStmt_Insert;
		SQLHANDLE hDb_S = this->hDbc_source;
		SQLHANDLE hDb_T = hDbc_target;
		SQLHANDLE hEnvS = hEnv_Source;
		SQLHANDLE hEnvT = hEnv_Target;
		RETCODE r;

		r = ::SQLFreeHandle(SQL_HANDLE_STMT, hStmt_Fetch);
		r = ::SQLFreeHandle(SQL_HANDLE_STMT, hStmt_Insert);
		r = ::SQLFreeHandle(SQL_HANDLE_STMT, hStmt_Update);
		if (hDbc_source != SQL_NULL_HANDLE) 		r = ::SQLDisconnect(hDb_S);
		if (hDbc_target != SQL_NULL_HANDLE) 		r = ::SQLDisconnect(hDb_T);

		r = ::SQLFreeHandle(SQL_HANDLE_DBC, hDb_S);
		r = ::SQLFreeHandle(SQL_HANDLE_DBC, hDb_T);
		r = ::SQLFreeHandle(SQL_HANDLE_ENV, hEnvS);
		r = ::SQLFreeHandle(SQL_HANDLE_ENV, hEnvT);
	}

	hEnv_Source = SQL_NULL_HANDLE;
	hEnv_Target = SQL_NULL_HANDLE;
	hEnv_Source = SQL_NULL_HANDLE;
	hEnv_Target = SQL_NULL_HANDLE;
	hStmt_Fetch = SQL_NULL_HANDLE;
	hStmt_Insert = SQL_NULL_HANDLE;
	hStmt_Update = SQL_NULL_HANDLE;
}

void TK_FLGHSHSET::open(const QString sourceDSN, const QString targetDSN)
{
	QLoggingCategory category("classLibQ");
	m_lpszTargetDSN = targetDSN;
	m_lpszSourceDSN = sourceDSN;
	qDebug(category) << QString("Source - %1[%2]").arg(sourceDSN);
	qDebug(category) << QString("Target - %1[%2]").arg(targetDSN);
}

void TK_FLGHSHSET::createTable()
{
	QLoggingCategory category("classLibQ");
	{
		QScopedPointer<nvTableOracleRdb> tbl(new nvTableOracleRdb(nullptr));
		tbl->initialize("TK_FLGHSHSET", this->m_lpszSourceDSN);
		QString newTbl = tbl->getCreateTableSQL();
		QScopedPointer<qVtExecute> vExec(new qVtExecute(nullptr));
		{
			vExec->initialize(m_lpszTargetDSN, " ", true);
			vExec->setOdbcAttributes(m_OdbcAttributes);
			vExec->ExecuteDirect(newTbl);
		}
	 qDebug(category) << QString("End Create Table %1 ").arg(tableName); 
	}
}

bool TK_FLGHSHSET::prepare()
{
	RETCODE r;
	QString check;
	QLoggingCategory category("classLibQ");
	 qDebug(category) << fetchSql;
	 qDebug(category) << insertSql;
#ifdef UNICODE
	r = SQLPrepare(hStmt_Insert,toSQLTCHAR(insertSql).data(),(SQLINTEGER)insertSql.length()); 
	if (r != SQL_SUCCESS) {
		check = qWarnODBCHandle(SQL_HANDLE_STMT, hStmt_Insert);
		 qCCritical(category) << QString("Prepare Statement-Insert : %1 is %2").arg(insertSql).arg(check);
		return false; 
	}
	r = SQLPrepare(hStmt_Update,toSQLTCHAR(updateSql).data(),(SQLINTEGER)updateSql.length()); 
	if (r != SQL_SUCCESS) {
		check = qWarnODBCHandle(SQL_HANDLE_STMT, hStmt_Update);
		 qCCritical(category) << QString("Prepare Statement-Update : %1 is %2").arg(updateSql).arg(check);
		return false; 
	}
	r = SQLPrepare(hStmt_Fetch,toSQLTCHAR(fetchSql).data(),(SQLINTEGER)fetchSql.length());
	if (r != SQL_SUCCESS) {
		check = qWarnODBCHandle(SQL_HANDLE_STMT, hStmt_Fetch);
		 qCCritical(category) << QString("Prepare Statement-Insert : %1 is %2").arg(fetchSql).arg(check);
		return false; 
	}
#else
	QByteArray queryI8 = insertSql.toUtf8();
	r = SQLPrepare(insert_hStmt,SQLCHAR*)queryI8.data(),(SQLINTEGER)queryI8.length());
	QByteArray queryU8 = fetchSql.toUtf8();
	r = SQLPrepare(hStmt_Fetch,(SQLCHAR*)queryU8.data(),(SQLINTEGER)queryU8.length());
#endif
	return true;

}

void TK_FLGHSHSET::prepareTargetTable()
{
	QLoggingCategory category("classLibQ");
	if (this->m_ReplicationOption == ReplicationOption::BulkCopy)
	{
		QScopedPointer<qVtExecute> execSql(new qVtExecute(nullptr));
		DropOption option = this->m_dropOption;
		switch (option)
		{
			case DropOption::DeleteFromTable:
			{
				QLoggingCategory category("classLibQ");
				execSql->initialize(this->m_lpszTargetDSN, "delete from TK_FLGHSHSET", true);
				execSql->setOdbcAttributes(this->m_OdbcAttributes);
				execSql->ExecuteDirect("delete from TK_FLGHSHSET");
			}break;
			case DropOption::TruncateTable:
			{
				execSql->initialize(this->m_lpszTargetDSN, "truncate table TK_FLGHSHSET", true);
				execSql->setOdbcAttributes(this->m_OdbcAttributes);
				execSql->ExecuteDirect("truncate table TK_FLGHSHSET");
			}break;
			case DropOption::DropTable:
			{
				execSql->initialize(this->m_lpszTargetDSN, "drop table TK_FLGHSHSET", true);
				execSql->setOdbcAttributes(this->m_OdbcAttributes);
				execSql->ExecuteDirect("drop table TK_FLGHSHSET");
				createTable();
			}break;
		}
	}
}

bool TK_FLGHSHSET::bindColumn()
{
	QLoggingCategory category("classLibQ");
	RETCODE r;
	bool isValid=true;
		 qDebug(category) << " Bindings: Ordinal [1] Type: 5 Buffer Size: 2 FieldName: DB_ID ";
		r = ::SQLBindCol(hStmt_Fetch, 1, 5, DB_ID.data(), 2, &cbDB_ID);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Bindings: Ordinal [2] Type: 93 Buffer Size: 23 FieldName: NVTIMESTAMP ";
		r = ::SQLBindCol(hStmt_Fetch, 2, 93, NVTIMESTAMP.data(), 23, &cbNVTIMESTAMP);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Bindings: Ordinal [3] Type: 5 Buffer Size: 2 FieldName: OAREA ";
		r = ::SQLBindCol(hStmt_Fetch, 3, 5, OAREA.data(), 2, &cbOAREA);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Bindings: Ordinal [4] Type: 4 Buffer Size: 4 FieldName: OPAGE ";
		r = ::SQLBindCol(hStmt_Fetch, 4, 4, OPAGE.data(), 4, &cbOPAGE);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Bindings: Ordinal [5] Type: 5 Buffer Size: 2 FieldName: OLINE ";
		r = ::SQLBindCol(hStmt_Fetch, 5, 5, OLINE.data(), 2, &cbOLINE);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Bindings: Ordinal [6] Type: 5 Buffer Size: 2 FieldName: MAREA ";
		r = ::SQLBindCol(hStmt_Fetch, 6, 5, MAREA.data(), 2, &cbMAREA);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Bindings: Ordinal [7] Type: 4 Buffer Size: 4 FieldName: MPAGE ";
		r = ::SQLBindCol(hStmt_Fetch, 7, 4, MPAGE.data(), 4, &cbMPAGE);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Bindings: Ordinal [8] Type: 5 Buffer Size: 2 FieldName: MLINE ";
		r = ::SQLBindCol(hStmt_Fetch, 8, 5, MLINE.data(), 2, &cbMLINE);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
	return isValid;
}

bool TK_FLGHSHSET::bindParameter()
{
	QLoggingCategory category("classLibQ");
	RETCODE r;
	bool isValid=true;
	{
		 qDebug(category) << " Parameters: Ordinal [1] Type: 5 Buffer Size: 2 FieldName: DB_ID ";
		r = SQLBindParameter(hStmt_Insert, 1, SQL_PARAM_INPUT, SQL_C_DEFAULT, 5, 0, 0, (SQLPOINTER)DB_ID.constData(), 0, &cbDB_ID);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Parameters: Ordinal [2] Type: 93 Buffer Size: 23 FieldName: NVTIMESTAMP ";
		r = SQLBindParameter(hStmt_Insert, 2, SQL_PARAM_INPUT, SQL_C_DEFAULT, 93, 23, 0, (SQLPOINTER)NVTIMESTAMP.constData(), 0, &cbNVTIMESTAMP);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Parameters: Ordinal [3] Type: 5 Buffer Size: 2 FieldName: OAREA ";
		r = SQLBindParameter(hStmt_Insert, 3, SQL_PARAM_INPUT, SQL_C_DEFAULT, 5, 0, 0, (SQLPOINTER)OAREA.constData(), 0, &cbOAREA);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Parameters: Ordinal [4] Type: 4 Buffer Size: 4 FieldName: OPAGE ";
		r = SQLBindParameter(hStmt_Insert, 4, SQL_PARAM_INPUT, SQL_C_DEFAULT, 4, 0, 0, (SQLPOINTER)OPAGE.constData(), 0, &cbOPAGE);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Parameters: Ordinal [5] Type: 5 Buffer Size: 2 FieldName: OLINE ";
		r = SQLBindParameter(hStmt_Insert, 5, SQL_PARAM_INPUT, SQL_C_DEFAULT, 5, 0, 0, (SQLPOINTER)OLINE.constData(), 0, &cbOLINE);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Parameters: Ordinal [6] Type: 5 Buffer Size: 2 FieldName: MAREA ";
		r = SQLBindParameter(hStmt_Insert, 6, SQL_PARAM_INPUT, SQL_C_DEFAULT, 5, 0, 0, (SQLPOINTER)MAREA.constData(), 0, &cbMAREA);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Parameters: Ordinal [7] Type: 4 Buffer Size: 4 FieldName: MPAGE ";
		r = SQLBindParameter(hStmt_Insert, 7, SQL_PARAM_INPUT, SQL_C_DEFAULT, 4, 0, 0, (SQLPOINTER)MPAGE.constData(), 0, &cbMPAGE);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Parameters: Ordinal [8] Type: 5 Buffer Size: 2 FieldName: MLINE ";
		r = SQLBindParameter(hStmt_Insert, 8, SQL_PARAM_INPUT, SQL_C_DEFAULT, 5, 0, 0, (SQLPOINTER)MLINE.constData(), 0, &cbMLINE);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
	}
	if (m_ReplicationOption == ReplicationOption::NetChange)
	{
		r = SQLBindParameter(hStmt_Update, 9, SQL_PARAM_INPUT, SQL_C_DEFAULT, 6, 0, 0, (SQLPOINTER)MAREA.constData(), 0, &cbMAREA);
		if (r == SQL_SUCCESS) { isValid=true; }
		r = SQLBindParameter(hStmt_Update, 10, SQL_PARAM_INPUT, SQL_C_DEFAULT, 7, 0, 0, (SQLPOINTER)MPAGE.constData(), 0, &cbMPAGE);
		if (r == SQL_SUCCESS) { isValid=true; }
		r = SQLBindParameter(hStmt_Update, 11, SQL_PARAM_INPUT, SQL_C_DEFAULT, 8, 0, 0, (SQLPOINTER)MLINE.constData(), 0, &cbMLINE);
		if (r == SQL_SUCCESS) { isValid=true; }
	// TK_FLGHSHSET is a well formed table for eNVy Replication 
		 qDebug(category) << " Parameters: Ordinal [6] 00 00 FieldName: MAREA ";
		 qDebug(category) << " Parameters: Ordinal [7] 00 00  FieldName: MPAGE ";
		 qDebug(category) << " Parameters: Ordinal [8] 00 00 FieldName:  MLINE ";
	} // 	if (m_ReplicationOption == ReplicationOption::NetChange)
	return isValid;
}

bool TK_FLGHSHSET::process(int rowSize)
{
	QLoggingCategory category("classLibQ");
	initOdbcAttributes();
	connect(Source);
	connect(Target);
	initialize();
	prepareTargetTable();
	prepare();
	bindColumn();
	bindParameter();
	copyTable();
	close();
	return false;
}

void TK_FLGHSHSET::copyTable()
{
	QLoggingCategory category("classLibQ");
	RETCODE r;
	QString check;
	r = SQLExecute(hStmt_Fetch);
		if (bIsAbort) {
			emit aborted(tableName, rowsFetched, rowsInserted, rowsUpdated);
			return;
		}
		while((r = SQLFetch(hStmt_Fetch)) != SQL_NO_DATA) {
		if (r != SQL_SUCCESS) {
			check = qWarnODBCHandle(SQL_HANDLE_STMT, hStmt_Fetch);
			qCCritical(category) << QString("SqlFetch - Error : %1 is %2").arg(fetchSql).arg(check);
			return;
		} 
		rowsFetched++;
		if (m_ReplicationOption == ReplicationOption::BulkCopy)
		{
			r = SQLExecute(hStmt_Insert);
			if (r == SQL_ERROR) {
				check = qWarnODBCHandle(SQL_HANDLE_STMT, hStmt_Insert);
				 qCCritical(category) << QString("SqlExecute:Insert - Error : %1 is %2").arg(insertSql).arg(check);
				return;
			}
			rowsInserted++;
			if ((rowsFetched % updateInterval) == 0) {
				qCInfo(category) << QString("[%1.%2]	Insertion: %3	Updates : %4	Fetched : %5").arg(profileName).arg(tableName).arg(rowsInserted).arg(rowsUpdated).arg(rowsFetched);
				emit updateStatusFetched(profileName, tableName, rowsFetched,rowsInserted,rowsUpdated);
			}
			if (m_ReplicationOption == ReplicationOption::NetChange)
			{
			r = SQLExecute(hStmt_Update);
			if (r != SQL_SUCCESS) {
				check = qWarnODBCHandle(SQL_HANDLE_STMT, hStmt_Update);
				 qCInfo(category)  << QString("SqlExecute:Update - Error : %1 is %2").arg(updateSql).arg(check);
				r = SQLExecute(hStmt_Insert);
				if (r != SQL_SUCCESS) {
					check = qWarnODBCHandle(SQL_HANDLE_STMT, hStmt_Insert);
					 qCritical(category) << QString("SqlExecute:Insert - Error : %1 is %2").arg(insertSql).arg(check);
					return;
				}
				else 	rowsInserted++;
				}
				else	rowsUpdated++;
			}
			emit updateStatusFetched(profileName, tableName, rowsFetched,rowsInserted,rowsUpdated);
		}
	} 
qCInfo(category) << QString("[%1.%2]	Insertion: %3	Updates : %4	Fetched : %5").arg(profileName).arg(tableName).arg(rowsInserted).arg(rowsUpdated).arg(rowsFetched);
}

void TK_FLGHSHSET::connect(connectionHandle connectionSource)
{

	QLoggingCategory category("classLibQ");
	RETCODE r;

	bool isValid = false;
	HWND	hWnd = nullptr;
	hWnd = ::GetDesktopWindow(); 
	SQLSMALLINT nResult = 0;

	SQLSMALLINT cb;
	UWORD wConnectOption = SQL_DRIVER_COMPLETE; //SQL_DRIVER_NOPROMPT;
	QVarLengthArray<SQLTCHAR> connOut(1024);
	memset(connOut.data(), 0, connOut.size() * sizeof(SQLTCHAR));

	switch (connectionSource)
	{
		case Source:
			{// environment
				SQLHANDLE hEnv = SQL_NULL_HANDLE;
				SQLHANDLE hDbc = SQL_NULL_HANDLE;
				r = ::SQLAllocHandle(SQL_HANDLE_ENV, SQL_NULL_HANDLE, &hEnv);
				if (r == SQL_SUCCESS) isValid = true;

				foreach(nOdbcAttributesClass * k, this->m_OdbcAttributes_Map)
				{
					if (k->attributeType == enumAttributeType::hEnv)
					{
						r = ::SQLSetEnvAttr(hEnv, (SQLINTEGER) k->odbcKey, (SQLPOINTER)k->odbcValue, 0);
						if (r == SQL_SUCCESS) isValid = true;
					}
				}
				hEnv_Source = hEnv;

				r = SQLAllocHandle(SQL_HANDLE_DBC, hEnv, &hDbc);
				if (r == SQL_SUCCESS) isValid = true;
				foreach(nOdbcAttributesClass * k, this->m_OdbcAttributes_Map)
				{
					if (k->attributeType == enumAttributeType::hDbc)
					{
					r = ::SQLSetConnectAttr(hDbc, k->odbcKey, (SQLPOINTER)k->odbcValue, 0);
					if (k->odbcKey == SQL_ATTR_CONNECTION_POOLING && k->odbcValue == SQL_CP_ONE_PER_DRIVER) wConnectOption = SQL_DRIVER_NOPROMPT;
					if (k->odbcKey == SQL_ATTR_CONNECTION_POOLING && k->odbcValue == SQL_CP_ONE_PER_HENV) wConnectOption = SQL_DRIVER_NOPROMPT;
					if (k->odbcKey == SQL_ATTR_CONNECTION_POOLING && k->odbcValue == SQL_CP_DRIVER_AWARE) wConnectOption = SQL_DRIVER_NOPROMPT;
					if (r == SQL_SUCCESS) isValid = true;
					}
				}
				hDbc_source = hDbc;
				if (isValid)
				{
					r = ::SQLDriverConnect(
						hDbc,
						hWnd,
#ifdef UNICODE
						toSQLTCHAR(m_lpszSourceDSN).data(),
#else
						(SQLCHAR*)dsnSource.toUtf8().data(),
#endif
						(SQLSMALLINT)m_lpszSourceDSN.length(),
						connOut.data(),
						1024,
						&cb, 
						wConnectOption); 
					int colSize = cb / sizeof(SQLTCHAR);
					if (r != SQL_SUCCESS && r != SQL_SUCCESS_WITH_INFO)
					{
						QString check = qWarnODBCHandle(SQL_HANDLE_DBC, hDbc);
						qCritical(category) <<  check;
						m_bIsOpen = false;
					}
					m_bIsOpen = true;
				}
			} break;
		case Target:
			{
				SQLHANDLE hEnv = SQL_NULL_HANDLE;
				SQLHANDLE hDbc = SQL_NULL_HANDLE;
				r = ::SQLAllocHandle(SQL_HANDLE_ENV, SQL_NULL_HANDLE, &hEnv);
				if (r == SQL_SUCCESS) isValid = true;

				foreach(nOdbcAttributesClass * k, this->m_OdbcAttributes_Map)
				{
					if (k->attributeType == enumAttributeType::hEnv)
					{
						r = ::SQLSetEnvAttr(hEnv, (SQLINTEGER) k->odbcKey, (SQLPOINTER)k->odbcValue, 0);
						if (r == SQL_SUCCESS) isValid = true;
					}
				}
				hEnv_Target = hEnv;

				r = SQLAllocHandle(SQL_HANDLE_DBC, hEnv, &hDbc);
				if (r == SQL_SUCCESS) isValid = true;
				foreach(nOdbcAttributesClass * k, this->m_OdbcAttributes_Map)
				{
				if (k->attributeType == enumAttributeType::hDbc)
					{
					r = ::SQLSetConnectAttr(hDbc, k->odbcKey, (SQLPOINTER)k->odbcValue, 0);
					if (k->odbcKey == SQL_ATTR_CONNECTION_POOLING && k->odbcValue == SQL_CP_ONE_PER_DRIVER) wConnectOption = SQL_DRIVER_NOPROMPT;
					if (k->odbcKey == SQL_ATTR_CONNECTION_POOLING && k->odbcValue == SQL_CP_ONE_PER_HENV) wConnectOption = SQL_DRIVER_NOPROMPT;
					if (k->odbcKey == SQL_ATTR_CONNECTION_POOLING && k->odbcValue == SQL_CP_DRIVER_AWARE) wConnectOption = SQL_DRIVER_NOPROMPT;
					if (r == SQL_SUCCESS) isValid = true;
					}
				}
				hDbc_target = hDbc;
				if (isValid) {
					r = ::SQLDriverConnect(
						hDbc,
						hWnd,
#ifdef UNICODE
						toSQLTCHAR(m_lpszTargetDSN).data(),
#else
						(SQLCHAR*)m_lpszTargetDSN.toUtf8().data(),
#endif
						(SQLSMALLINT)m_lpszTargetDSN.length(),
						connOut.data(),
						1024,
						&cb, 
						wConnectOption); 
						int colSize = cb / sizeof(SQLTCHAR);
					if (r != SQL_SUCCESS && r != SQL_SUCCESS_WITH_INFO)
						{
							QString check = qWarnODBCHandle(SQL_HANDLE_DBC, hDbc);
							qCritical(category) <<  check;
							m_bIsOpen = false;
						}
							m_bIsOpen = true;
					}
			} break;
			default: break;
	}
}
TK_INTCHNSET::TK_INTCHNSET(QObject * parent) : QObject(parent) 
,tableName("TK_INTCHNSET")
,m_dropOption(DropOption::DropTable) { 
	numRowsFetched = 0;
}

#pragma region ~CTOR TK_INTCHNSET 
TK_INTCHNSET::~TK_INTCHNSET() { 

#pragma region Buffers - Clear 
	DB_ID.clear();
	NVTIMESTAMP.clear();
	OAREA.clear();
	OPAGE.clear();
	OLINE.clear();
	MAREA.clear();
	MPAGE.clear();
	MLINE.clear();
#pragma endregion Buffers - Clear 
}
#pragma endregion Destructor_TK_INTCHNSET

// begin method functions
void TK_INTCHNSET::setAbortFlag() { 
	QLoggingCategory category("classLibQ");
	qCInfo(category) << "isAbort was set to True";
	bIsAbort = true;
}

void TK_INTCHNSET::run() { 
	process(1);
	QLoggingCategory category("classLibQ");
	qDebug(category) << "Entered;";
}

void	TK_INTCHNSET::initOdbcAttributes()
{
	QLoggingCategory category("classLibQ");
	this->setProfileName(profileName);
	qDebug(category) << "Processing - TRKDB100"; 
	m_OdbcAttributesList = m_OdbcAttributes.split(","); 
	foreach(QString m, m_OdbcAttributesList)
	{
		QStringList keyValue = m.split("=");
		nOdbcAttributesClass * oM = new nOdbcAttributesClass(this);
		if (oM->loadToOdbc(keyValue.value(0), keyValue.value(1)))
		{
			m_OdbcAttributes_Map.insert(oM->odbcKey, oM);
		}
	}
}
void	TK_INTCHNSET::initialize()
{
	QLoggingCategory category("classLibQ");
	RETCODE r;
	this->setProfileName(profileName);
	qDebug(category) << "Processing - TRKDB100"; 
//SQL Statements
//--------------------------------------------------

#pragma region Sql Statements_TK_INTCHNSET

	fetchSql = "select  DB_ID, NVTIMESTAMP, OAREA, OPAGE, OLINE, MAREA, MPAGE, MLINE from TK_INTCHNSET";
		if (m_ReplicationOption == ReplicationOption::NetChange)
		{
			fetchSql.append(" p1, nv_transfers p2 WHERE  p2.table_name = 'TK_INTCHNSET' AND p1.nvtimestamp > p2.last_completed");
		}
	insertSql = "insert into TK_INTCHNSET ( PLANT_CODE, NVTIMESTAMP, OAREA, OPAGE, OLINE, MAREA, MPAGE, MLINE ) values ( ?, ?, ?, ?, ?, ?, ?, ?)";
	updateSql = "update TK_INTCHNSET set  PLANT_CODE = ?, NVTIMESTAMP = ?, OAREA = ?, OPAGE = ?, OLINE = ?, MAREA = ?, MPAGE = ?, MLINE = ?  where area = ? and page = ? line = ? ";

	qDebug(category) << "insertSQL - insert into TK_INTCHNSET ( PLANT_CODE, NVTIMESTAMP, OAREA, OPAGE, OLINE, MAREA, MPAGE, MLINE ) values ( ?, ?, ?, ?, ?, ?, ?, ?)";
	qDebug(category) << "fetchSQL - select  DB_ID, NVTIMESTAMP, OAREA, OPAGE, OLINE, MAREA, MPAGE, MLINE from TK_INTCHNSET";
	qDebug(category) << "unsertSQL - update TK_INTCHNSET set  PLANT_CODE = ?, NVTIMESTAMP = ?, OAREA = ?, OPAGE = ?, OLINE = ?, MAREA = ?, MPAGE = ?, MLINE = ?  where area = ? and page = ? line = ? ";

#pragma endregion Sql Statements_TK_INTCHNSET
	SQLHANDLE		insert_hStmt = SQL_NULL_HANDLE;
	SQLHANDLE		fetch_hStmt = SQL_NULL_HANDLE; 
	SQLHANDLE		update_hStmt = SQL_NULL_HANDLE; 
 
	r = ::SQLAllocHandle(SQL_HANDLE_STMT, hDbc_source, &fetch_hStmt);
	if (r != SQL_SUCCESS) {
		 qCCritical(category) << QString("Error  hDbc_Source SQLCode : %1 is %2").arg(QString::number( (long)hDbc_source)).arg(QString::number(r));
		return; 
	}
	r = ::SQLAllocHandle(SQL_HANDLE_STMT, hDbc_target, &insert_hStmt);
	if (r != SQL_SUCCESS) {
		 qCCritical(category) << QString("Error hDbc_Source -SQLCode: %1 is %2").arg(QString::number( (long)hDbc_target)).arg(QString::number(r));
		return; 
	}
	r = ::SQLAllocHandle(SQL_HANDLE_STMT, hDbc_target, &update_hStmt);
	if (r != SQL_SUCCESS) {
		 qCCritical(category) << QString("Error hDbc_Source +SQLCode: %1 is %2").arg(QString::number( (long)hDbc_target)).arg(QString::number(r));
		return; 
	}
 
	hStmt_Fetch = fetch_hStmt;
	hStmt_Insert = insert_hStmt;
	hStmt_Update = update_hStmt;
 
	SQLSetStmtAttr(hStmt_Fetch, SQL_ATTR_USE_BOOKMARKS, (SQLPOINTER)SQL_UB_OFF, 0);
	SQLSetStmtAttr(hStmt_Fetch, SQL_ATTR_ROW_BIND_TYPE, (SQLPOINTER)SQL_BIND_BY_COLUMN, 0);
	SQLSetStmtAttr(hStmt_Fetch, SQL_ATTR_ROW_ARRAY_SIZE, (SQLPOINTER)1, 0);
	SQLSetStmtAttr(hStmt_Fetch, SQL_ATTR_ROWS_FETCHED_PTR, &numRowsFetched, 0);

// Fields used by this class 
// ---------------------------------------------------

#pragma region Resize Fields TK_INTCHNSET
	qDebug(category) << "Malloc - DB_ID[2]";
	DB_ID.resize(2);
	qDebug(category) << "Malloc - NVTIMESTAMP[23]";
	NVTIMESTAMP.resize(23);
	qDebug(category) << "Malloc - OAREA[2]";
	OAREA.resize(2);
	qDebug(category) << "Malloc - OPAGE[4]";
	OPAGE.resize(4);
	qDebug(category) << "Malloc - OLINE[2]";
	OLINE.resize(2);
	qDebug(category) << "Malloc - MAREA[2]";
	MAREA.resize(2);
	qDebug(category) << "Malloc - MPAGE[4]";
	MPAGE.resize(4);
	qDebug(category) << "Malloc - MLINE[2]";
	MLINE.resize(2);

#pragma endregion Resize Fields TK_INTCHNSET
}
void TK_INTCHNSET::close()
{
	QLoggingCategory category("classLibQ");
	if (m_bIsOpen)
	{
	qDebug(category) << "database is Open";
		SQLHANDLE source_hStmt = hStmt_Fetch;
		SQLHANDLE insert_hStmt = hStmt_Insert;
		SQLHANDLE hDb_S = this->hDbc_source;
		SQLHANDLE hDb_T = hDbc_target;
		SQLHANDLE hEnvS = hEnv_Source;
		SQLHANDLE hEnvT = hEnv_Target;
		RETCODE r;

		r = ::SQLFreeHandle(SQL_HANDLE_STMT, hStmt_Fetch);
		r = ::SQLFreeHandle(SQL_HANDLE_STMT, hStmt_Insert);
		r = ::SQLFreeHandle(SQL_HANDLE_STMT, hStmt_Update);
		if (hDbc_source != SQL_NULL_HANDLE) 		r = ::SQLDisconnect(hDb_S);
		if (hDbc_target != SQL_NULL_HANDLE) 		r = ::SQLDisconnect(hDb_T);

		r = ::SQLFreeHandle(SQL_HANDLE_DBC, hDb_S);
		r = ::SQLFreeHandle(SQL_HANDLE_DBC, hDb_T);
		r = ::SQLFreeHandle(SQL_HANDLE_ENV, hEnvS);
		r = ::SQLFreeHandle(SQL_HANDLE_ENV, hEnvT);
	}

	hEnv_Source = SQL_NULL_HANDLE;
	hEnv_Target = SQL_NULL_HANDLE;
	hEnv_Source = SQL_NULL_HANDLE;
	hEnv_Target = SQL_NULL_HANDLE;
	hStmt_Fetch = SQL_NULL_HANDLE;
	hStmt_Insert = SQL_NULL_HANDLE;
	hStmt_Update = SQL_NULL_HANDLE;
}

void TK_INTCHNSET::open(const QString sourceDSN, const QString targetDSN)
{
	QLoggingCategory category("classLibQ");
	m_lpszTargetDSN = targetDSN;
	m_lpszSourceDSN = sourceDSN;
	qDebug(category) << QString("Source - %1[%2]").arg(sourceDSN);
	qDebug(category) << QString("Target - %1[%2]").arg(targetDSN);
}

void TK_INTCHNSET::createTable()
{
	QLoggingCategory category("classLibQ");
	{
		QScopedPointer<nvTableOracleRdb> tbl(new nvTableOracleRdb(nullptr));
		tbl->initialize("TK_INTCHNSET", this->m_lpszSourceDSN);
		QString newTbl = tbl->getCreateTableSQL();
		QScopedPointer<qVtExecute> vExec(new qVtExecute(nullptr));
		{
			vExec->initialize(m_lpszTargetDSN, " ", true);
			vExec->setOdbcAttributes(m_OdbcAttributes);
			vExec->ExecuteDirect(newTbl);
		}
	 qDebug(category) << QString("End Create Table %1 ").arg(tableName); 
	}
}

bool TK_INTCHNSET::prepare()
{
	RETCODE r;
	QString check;
	QLoggingCategory category("classLibQ");
	 qDebug(category) << fetchSql;
	 qDebug(category) << insertSql;
#ifdef UNICODE
	r = SQLPrepare(hStmt_Insert,toSQLTCHAR(insertSql).data(),(SQLINTEGER)insertSql.length()); 
	if (r != SQL_SUCCESS) {
		check = qWarnODBCHandle(SQL_HANDLE_STMT, hStmt_Insert);
		 qCCritical(category) << QString("Prepare Statement-Insert : %1 is %2").arg(insertSql).arg(check);
		return false; 
	}
	r = SQLPrepare(hStmt_Update,toSQLTCHAR(updateSql).data(),(SQLINTEGER)updateSql.length()); 
	if (r != SQL_SUCCESS) {
		check = qWarnODBCHandle(SQL_HANDLE_STMT, hStmt_Update);
		 qCCritical(category) << QString("Prepare Statement-Update : %1 is %2").arg(updateSql).arg(check);
		return false; 
	}
	r = SQLPrepare(hStmt_Fetch,toSQLTCHAR(fetchSql).data(),(SQLINTEGER)fetchSql.length());
	if (r != SQL_SUCCESS) {
		check = qWarnODBCHandle(SQL_HANDLE_STMT, hStmt_Fetch);
		 qCCritical(category) << QString("Prepare Statement-Insert : %1 is %2").arg(fetchSql).arg(check);
		return false; 
	}
#else
	QByteArray queryI8 = insertSql.toUtf8();
	r = SQLPrepare(insert_hStmt,SQLCHAR*)queryI8.data(),(SQLINTEGER)queryI8.length());
	QByteArray queryU8 = fetchSql.toUtf8();
	r = SQLPrepare(hStmt_Fetch,(SQLCHAR*)queryU8.data(),(SQLINTEGER)queryU8.length());
#endif
	return true;

}

void TK_INTCHNSET::prepareTargetTable()
{
	QLoggingCategory category("classLibQ");
	if (this->m_ReplicationOption == ReplicationOption::BulkCopy)
	{
		QScopedPointer<qVtExecute> execSql(new qVtExecute(nullptr));
		DropOption option = this->m_dropOption;
		switch (option)
		{
			case DropOption::DeleteFromTable:
			{
				QLoggingCategory category("classLibQ");
				execSql->initialize(this->m_lpszTargetDSN, "delete from TK_INTCHNSET", true);
				execSql->setOdbcAttributes(this->m_OdbcAttributes);
				execSql->ExecuteDirect("delete from TK_INTCHNSET");
			}break;
			case DropOption::TruncateTable:
			{
				execSql->initialize(this->m_lpszTargetDSN, "truncate table TK_INTCHNSET", true);
				execSql->setOdbcAttributes(this->m_OdbcAttributes);
				execSql->ExecuteDirect("truncate table TK_INTCHNSET");
			}break;
			case DropOption::DropTable:
			{
				execSql->initialize(this->m_lpszTargetDSN, "drop table TK_INTCHNSET", true);
				execSql->setOdbcAttributes(this->m_OdbcAttributes);
				execSql->ExecuteDirect("drop table TK_INTCHNSET");
				createTable();
			}break;
		}
	}
}

bool TK_INTCHNSET::bindColumn()
{
	QLoggingCategory category("classLibQ");
	RETCODE r;
	bool isValid=true;
		 qDebug(category) << " Bindings: Ordinal [1] Type: 5 Buffer Size: 2 FieldName: DB_ID ";
		r = ::SQLBindCol(hStmt_Fetch, 1, 5, DB_ID.data(), 2, &cbDB_ID);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Bindings: Ordinal [2] Type: 93 Buffer Size: 23 FieldName: NVTIMESTAMP ";
		r = ::SQLBindCol(hStmt_Fetch, 2, 93, NVTIMESTAMP.data(), 23, &cbNVTIMESTAMP);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Bindings: Ordinal [3] Type: 5 Buffer Size: 2 FieldName: OAREA ";
		r = ::SQLBindCol(hStmt_Fetch, 3, 5, OAREA.data(), 2, &cbOAREA);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Bindings: Ordinal [4] Type: 4 Buffer Size: 4 FieldName: OPAGE ";
		r = ::SQLBindCol(hStmt_Fetch, 4, 4, OPAGE.data(), 4, &cbOPAGE);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Bindings: Ordinal [5] Type: 5 Buffer Size: 2 FieldName: OLINE ";
		r = ::SQLBindCol(hStmt_Fetch, 5, 5, OLINE.data(), 2, &cbOLINE);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Bindings: Ordinal [6] Type: 5 Buffer Size: 2 FieldName: MAREA ";
		r = ::SQLBindCol(hStmt_Fetch, 6, 5, MAREA.data(), 2, &cbMAREA);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Bindings: Ordinal [7] Type: 4 Buffer Size: 4 FieldName: MPAGE ";
		r = ::SQLBindCol(hStmt_Fetch, 7, 4, MPAGE.data(), 4, &cbMPAGE);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Bindings: Ordinal [8] Type: 5 Buffer Size: 2 FieldName: MLINE ";
		r = ::SQLBindCol(hStmt_Fetch, 8, 5, MLINE.data(), 2, &cbMLINE);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
	return isValid;
}

bool TK_INTCHNSET::bindParameter()
{
	QLoggingCategory category("classLibQ");
	RETCODE r;
	bool isValid=true;
	{
		 qDebug(category) << " Parameters: Ordinal [1] Type: 5 Buffer Size: 2 FieldName: DB_ID ";
		r = SQLBindParameter(hStmt_Insert, 1, SQL_PARAM_INPUT, SQL_C_DEFAULT, 5, 0, 0, (SQLPOINTER)DB_ID.constData(), 0, &cbDB_ID);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Parameters: Ordinal [2] Type: 93 Buffer Size: 23 FieldName: NVTIMESTAMP ";
		r = SQLBindParameter(hStmt_Insert, 2, SQL_PARAM_INPUT, SQL_C_DEFAULT, 93, 23, 0, (SQLPOINTER)NVTIMESTAMP.constData(), 0, &cbNVTIMESTAMP);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Parameters: Ordinal [3] Type: 5 Buffer Size: 2 FieldName: OAREA ";
		r = SQLBindParameter(hStmt_Insert, 3, SQL_PARAM_INPUT, SQL_C_DEFAULT, 5, 0, 0, (SQLPOINTER)OAREA.constData(), 0, &cbOAREA);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Parameters: Ordinal [4] Type: 4 Buffer Size: 4 FieldName: OPAGE ";
		r = SQLBindParameter(hStmt_Insert, 4, SQL_PARAM_INPUT, SQL_C_DEFAULT, 4, 0, 0, (SQLPOINTER)OPAGE.constData(), 0, &cbOPAGE);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Parameters: Ordinal [5] Type: 5 Buffer Size: 2 FieldName: OLINE ";
		r = SQLBindParameter(hStmt_Insert, 5, SQL_PARAM_INPUT, SQL_C_DEFAULT, 5, 0, 0, (SQLPOINTER)OLINE.constData(), 0, &cbOLINE);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Parameters: Ordinal [6] Type: 5 Buffer Size: 2 FieldName: MAREA ";
		r = SQLBindParameter(hStmt_Insert, 6, SQL_PARAM_INPUT, SQL_C_DEFAULT, 5, 0, 0, (SQLPOINTER)MAREA.constData(), 0, &cbMAREA);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Parameters: Ordinal [7] Type: 4 Buffer Size: 4 FieldName: MPAGE ";
		r = SQLBindParameter(hStmt_Insert, 7, SQL_PARAM_INPUT, SQL_C_DEFAULT, 4, 0, 0, (SQLPOINTER)MPAGE.constData(), 0, &cbMPAGE);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Parameters: Ordinal [8] Type: 5 Buffer Size: 2 FieldName: MLINE ";
		r = SQLBindParameter(hStmt_Insert, 8, SQL_PARAM_INPUT, SQL_C_DEFAULT, 5, 0, 0, (SQLPOINTER)MLINE.constData(), 0, &cbMLINE);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
	}
	if (m_ReplicationOption == ReplicationOption::NetChange)
	{
		r = SQLBindParameter(hStmt_Update, 9, SQL_PARAM_INPUT, SQL_C_DEFAULT, 6, 0, 0, (SQLPOINTER)MAREA.constData(), 0, &cbMAREA);
		if (r == SQL_SUCCESS) { isValid=true; }
		r = SQLBindParameter(hStmt_Update, 10, SQL_PARAM_INPUT, SQL_C_DEFAULT, 7, 0, 0, (SQLPOINTER)MPAGE.constData(), 0, &cbMPAGE);
		if (r == SQL_SUCCESS) { isValid=true; }
		r = SQLBindParameter(hStmt_Update, 11, SQL_PARAM_INPUT, SQL_C_DEFAULT, 8, 0, 0, (SQLPOINTER)MLINE.constData(), 0, &cbMLINE);
		if (r == SQL_SUCCESS) { isValid=true; }
	// TK_INTCHNSET is a well formed table for eNVy Replication 
		 qDebug(category) << " Parameters: Ordinal [6] 00 00 FieldName: MAREA ";
		 qDebug(category) << " Parameters: Ordinal [7] 00 00  FieldName: MPAGE ";
		 qDebug(category) << " Parameters: Ordinal [8] 00 00 FieldName:  MLINE ";
	} // 	if (m_ReplicationOption == ReplicationOption::NetChange)
	return isValid;
}

bool TK_INTCHNSET::process(int rowSize)
{
	QLoggingCategory category("classLibQ");
	initOdbcAttributes();
	connect(Source);
	connect(Target);
	initialize();
	prepareTargetTable();
	prepare();
	bindColumn();
	bindParameter();
	copyTable();
	close();
	return false;
}

void TK_INTCHNSET::copyTable()
{
	QLoggingCategory category("classLibQ");
	RETCODE r;
	QString check;
	r = SQLExecute(hStmt_Fetch);
		if (bIsAbort) {
			emit aborted(tableName, rowsFetched, rowsInserted, rowsUpdated);
			return;
		}
		while((r = SQLFetch(hStmt_Fetch)) != SQL_NO_DATA) {
		if (r != SQL_SUCCESS) {
			check = qWarnODBCHandle(SQL_HANDLE_STMT, hStmt_Fetch);
			qCCritical(category) << QString("SqlFetch - Error : %1 is %2").arg(fetchSql).arg(check);
			return;
		} 
		rowsFetched++;
		if (m_ReplicationOption == ReplicationOption::BulkCopy)
		{
			r = SQLExecute(hStmt_Insert);
			if (r == SQL_ERROR) {
				check = qWarnODBCHandle(SQL_HANDLE_STMT, hStmt_Insert);
				 qCCritical(category) << QString("SqlExecute:Insert - Error : %1 is %2").arg(insertSql).arg(check);
				return;
			}
			rowsInserted++;
			if ((rowsFetched % updateInterval) == 0) {
				qCInfo(category) << QString("[%1.%2]	Insertion: %3	Updates : %4	Fetched : %5").arg(profileName).arg(tableName).arg(rowsInserted).arg(rowsUpdated).arg(rowsFetched);
				emit updateStatusFetched(profileName, tableName, rowsFetched,rowsInserted,rowsUpdated);
			}
			if (m_ReplicationOption == ReplicationOption::NetChange)
			{
			r = SQLExecute(hStmt_Update);
			if (r != SQL_SUCCESS) {
				check = qWarnODBCHandle(SQL_HANDLE_STMT, hStmt_Update);
				 qCInfo(category)  << QString("SqlExecute:Update - Error : %1 is %2").arg(updateSql).arg(check);
				r = SQLExecute(hStmt_Insert);
				if (r != SQL_SUCCESS) {
					check = qWarnODBCHandle(SQL_HANDLE_STMT, hStmt_Insert);
					 qCritical(category) << QString("SqlExecute:Insert - Error : %1 is %2").arg(insertSql).arg(check);
					return;
				}
				else 	rowsInserted++;
				}
				else	rowsUpdated++;
			}
			emit updateStatusFetched(profileName, tableName, rowsFetched,rowsInserted,rowsUpdated);
		}
	} 
qCInfo(category) << QString("[%1.%2]	Insertion: %3	Updates : %4	Fetched : %5").arg(profileName).arg(tableName).arg(rowsInserted).arg(rowsUpdated).arg(rowsFetched);
}

void TK_INTCHNSET::connect(connectionHandle connectionSource)
{

	QLoggingCategory category("classLibQ");
	RETCODE r;

	bool isValid = false;
	HWND	hWnd = nullptr;
	hWnd = ::GetDesktopWindow(); 
	SQLSMALLINT nResult = 0;

	SQLSMALLINT cb;
	UWORD wConnectOption = SQL_DRIVER_COMPLETE; //SQL_DRIVER_NOPROMPT;
	QVarLengthArray<SQLTCHAR> connOut(1024);
	memset(connOut.data(), 0, connOut.size() * sizeof(SQLTCHAR));

	switch (connectionSource)
	{
		case Source:
			{// environment
				SQLHANDLE hEnv = SQL_NULL_HANDLE;
				SQLHANDLE hDbc = SQL_NULL_HANDLE;
				r = ::SQLAllocHandle(SQL_HANDLE_ENV, SQL_NULL_HANDLE, &hEnv);
				if (r == SQL_SUCCESS) isValid = true;

				foreach(nOdbcAttributesClass * k, this->m_OdbcAttributes_Map)
				{
					if (k->attributeType == enumAttributeType::hEnv)
					{
						r = ::SQLSetEnvAttr(hEnv, (SQLINTEGER) k->odbcKey, (SQLPOINTER)k->odbcValue, 0);
						if (r == SQL_SUCCESS) isValid = true;
					}
				}
				hEnv_Source = hEnv;

				r = SQLAllocHandle(SQL_HANDLE_DBC, hEnv, &hDbc);
				if (r == SQL_SUCCESS) isValid = true;
				foreach(nOdbcAttributesClass * k, this->m_OdbcAttributes_Map)
				{
					if (k->attributeType == enumAttributeType::hDbc)
					{
					r = ::SQLSetConnectAttr(hDbc, k->odbcKey, (SQLPOINTER)k->odbcValue, 0);
					if (k->odbcKey == SQL_ATTR_CONNECTION_POOLING && k->odbcValue == SQL_CP_ONE_PER_DRIVER) wConnectOption = SQL_DRIVER_NOPROMPT;
					if (k->odbcKey == SQL_ATTR_CONNECTION_POOLING && k->odbcValue == SQL_CP_ONE_PER_HENV) wConnectOption = SQL_DRIVER_NOPROMPT;
					if (k->odbcKey == SQL_ATTR_CONNECTION_POOLING && k->odbcValue == SQL_CP_DRIVER_AWARE) wConnectOption = SQL_DRIVER_NOPROMPT;
					if (r == SQL_SUCCESS) isValid = true;
					}
				}
				hDbc_source = hDbc;
				if (isValid)
				{
					r = ::SQLDriverConnect(
						hDbc,
						hWnd,
#ifdef UNICODE
						toSQLTCHAR(m_lpszSourceDSN).data(),
#else
						(SQLCHAR*)dsnSource.toUtf8().data(),
#endif
						(SQLSMALLINT)m_lpszSourceDSN.length(),
						connOut.data(),
						1024,
						&cb, 
						wConnectOption); 
					int colSize = cb / sizeof(SQLTCHAR);
					if (r != SQL_SUCCESS && r != SQL_SUCCESS_WITH_INFO)
					{
						QString check = qWarnODBCHandle(SQL_HANDLE_DBC, hDbc);
						qCritical(category) <<  check;
						m_bIsOpen = false;
					}
					m_bIsOpen = true;
				}
			} break;
		case Target:
			{
				SQLHANDLE hEnv = SQL_NULL_HANDLE;
				SQLHANDLE hDbc = SQL_NULL_HANDLE;
				r = ::SQLAllocHandle(SQL_HANDLE_ENV, SQL_NULL_HANDLE, &hEnv);
				if (r == SQL_SUCCESS) isValid = true;

				foreach(nOdbcAttributesClass * k, this->m_OdbcAttributes_Map)
				{
					if (k->attributeType == enumAttributeType::hEnv)
					{
						r = ::SQLSetEnvAttr(hEnv, (SQLINTEGER) k->odbcKey, (SQLPOINTER)k->odbcValue, 0);
						if (r == SQL_SUCCESS) isValid = true;
					}
				}
				hEnv_Target = hEnv;

				r = SQLAllocHandle(SQL_HANDLE_DBC, hEnv, &hDbc);
				if (r == SQL_SUCCESS) isValid = true;
				foreach(nOdbcAttributesClass * k, this->m_OdbcAttributes_Map)
				{
				if (k->attributeType == enumAttributeType::hDbc)
					{
					r = ::SQLSetConnectAttr(hDbc, k->odbcKey, (SQLPOINTER)k->odbcValue, 0);
					if (k->odbcKey == SQL_ATTR_CONNECTION_POOLING && k->odbcValue == SQL_CP_ONE_PER_DRIVER) wConnectOption = SQL_DRIVER_NOPROMPT;
					if (k->odbcKey == SQL_ATTR_CONNECTION_POOLING && k->odbcValue == SQL_CP_ONE_PER_HENV) wConnectOption = SQL_DRIVER_NOPROMPT;
					if (k->odbcKey == SQL_ATTR_CONNECTION_POOLING && k->odbcValue == SQL_CP_DRIVER_AWARE) wConnectOption = SQL_DRIVER_NOPROMPT;
					if (r == SQL_SUCCESS) isValid = true;
					}
				}
				hDbc_target = hDbc;
				if (isValid) {
					r = ::SQLDriverConnect(
						hDbc,
						hWnd,
#ifdef UNICODE
						toSQLTCHAR(m_lpszTargetDSN).data(),
#else
						(SQLCHAR*)m_lpszTargetDSN.toUtf8().data(),
#endif
						(SQLSMALLINT)m_lpszTargetDSN.length(),
						connOut.data(),
						1024,
						&cb, 
						wConnectOption); 
						int colSize = cb / sizeof(SQLTCHAR);
					if (r != SQL_SUCCESS && r != SQL_SUCCESS_WITH_INFO)
						{
							QString check = qWarnODBCHandle(SQL_HANDLE_DBC, hDbc);
							qCritical(category) <<  check;
							m_bIsOpen = false;
						}
							m_bIsOpen = true;
					}
			} break;
			default: break;
	}
}
TK_LOTREC::TK_LOTREC(QObject * parent) : QObject(parent) 
,tableName("TK_LOTREC")
,m_dropOption(DropOption::DropTable) { 
	numRowsFetched = 0;
}

#pragma region ~CTOR TK_LOTREC 
TK_LOTREC::~TK_LOTREC() { 

#pragma region Buffers - Clear 
	DB_ID.clear();
	NVTIMESTAMP.clear();
	AREA.clear();
	PAGE.clear();
	LINE.clear();
	TK_LOTNO.clear();
#pragma endregion Buffers - Clear 
}
#pragma endregion Destructor_TK_LOTREC

// begin method functions
void TK_LOTREC::setAbortFlag() { 
	QLoggingCategory category("classLibQ");
	qCInfo(category) << "isAbort was set to True";
	bIsAbort = true;
}

void TK_LOTREC::run() { 
	process(1);
	QLoggingCategory category("classLibQ");
	qDebug(category) << "Entered;";
}

void	TK_LOTREC::initOdbcAttributes()
{
	QLoggingCategory category("classLibQ");
	this->setProfileName(profileName);
	qDebug(category) << "Processing - TRKDB100"; 
	m_OdbcAttributesList = m_OdbcAttributes.split(","); 
	foreach(QString m, m_OdbcAttributesList)
	{
		QStringList keyValue = m.split("=");
		nOdbcAttributesClass * oM = new nOdbcAttributesClass(this);
		if (oM->loadToOdbc(keyValue.value(0), keyValue.value(1)))
		{
			m_OdbcAttributes_Map.insert(oM->odbcKey, oM);
		}
	}
}
void	TK_LOTREC::initialize()
{
	QLoggingCategory category("classLibQ");
	RETCODE r;
	this->setProfileName(profileName);
	qDebug(category) << "Processing - TRKDB100"; 
//SQL Statements
//--------------------------------------------------

#pragma region Sql Statements_TK_LOTREC

	fetchSql = "select  DB_ID, NVTIMESTAMP, AREA, PAGE, LINE, TK_LOTNO from TK_LOTREC";
		if (m_ReplicationOption == ReplicationOption::NetChange)
		{
			fetchSql.append(" p1, nv_transfers p2 WHERE  p2.table_name = 'TK_LOTREC' AND p1.nvtimestamp > p2.last_completed");
		}
	insertSql = "insert into TK_LOTREC ( PLANT_CODE, NVTIMESTAMP, AREA, PAGE, LINE, TK_LOTNO ) values ( ?, ?, ?, ?, ?, ?)";
	updateSql = "update TK_LOTREC set  PLANT_CODE = ?, NVTIMESTAMP = ?, AREA = ?, PAGE = ?, LINE = ?, TK_LOTNO = ?  where area = ? and page = ? line = ? ";

	qDebug(category) << "insertSQL - insert into TK_LOTREC ( PLANT_CODE, NVTIMESTAMP, AREA, PAGE, LINE, TK_LOTNO ) values ( ?, ?, ?, ?, ?, ?)";
	qDebug(category) << "fetchSQL - select  DB_ID, NVTIMESTAMP, AREA, PAGE, LINE, TK_LOTNO from TK_LOTREC";
	qDebug(category) << "unsertSQL - update TK_LOTREC set  PLANT_CODE = ?, NVTIMESTAMP = ?, AREA = ?, PAGE = ?, LINE = ?, TK_LOTNO = ?  where area = ? and page = ? line = ? ";

#pragma endregion Sql Statements_TK_LOTREC
	SQLHANDLE		insert_hStmt = SQL_NULL_HANDLE;
	SQLHANDLE		fetch_hStmt = SQL_NULL_HANDLE; 
	SQLHANDLE		update_hStmt = SQL_NULL_HANDLE; 
 
	r = ::SQLAllocHandle(SQL_HANDLE_STMT, hDbc_source, &fetch_hStmt);
	if (r != SQL_SUCCESS) {
		 qCCritical(category) << QString("Error  hDbc_Source SQLCode : %1 is %2").arg(QString::number( (long)hDbc_source)).arg(QString::number(r));
		return; 
	}
	r = ::SQLAllocHandle(SQL_HANDLE_STMT, hDbc_target, &insert_hStmt);
	if (r != SQL_SUCCESS) {
		 qCCritical(category) << QString("Error hDbc_Source -SQLCode: %1 is %2").arg(QString::number( (long)hDbc_target)).arg(QString::number(r));
		return; 
	}
	r = ::SQLAllocHandle(SQL_HANDLE_STMT, hDbc_target, &update_hStmt);
	if (r != SQL_SUCCESS) {
		 qCCritical(category) << QString("Error hDbc_Source +SQLCode: %1 is %2").arg(QString::number( (long)hDbc_target)).arg(QString::number(r));
		return; 
	}
 
	hStmt_Fetch = fetch_hStmt;
	hStmt_Insert = insert_hStmt;
	hStmt_Update = update_hStmt;
 
	SQLSetStmtAttr(hStmt_Fetch, SQL_ATTR_USE_BOOKMARKS, (SQLPOINTER)SQL_UB_OFF, 0);
	SQLSetStmtAttr(hStmt_Fetch, SQL_ATTR_ROW_BIND_TYPE, (SQLPOINTER)SQL_BIND_BY_COLUMN, 0);
	SQLSetStmtAttr(hStmt_Fetch, SQL_ATTR_ROW_ARRAY_SIZE, (SQLPOINTER)1, 0);
	SQLSetStmtAttr(hStmt_Fetch, SQL_ATTR_ROWS_FETCHED_PTR, &numRowsFetched, 0);

// Fields used by this class 
// ---------------------------------------------------

#pragma region Resize Fields TK_LOTREC
	qDebug(category) << "Malloc - DB_ID[2]";
	DB_ID.resize(2);
	qDebug(category) << "Malloc - NVTIMESTAMP[23]";
	NVTIMESTAMP.resize(23);
	qDebug(category) << "Malloc - AREA[2]";
	AREA.resize(2);
	qDebug(category) << "Malloc - PAGE[4]";
	PAGE.resize(4);
	qDebug(category) << "Malloc - LINE[2]";
	LINE.resize(2);
	qDebug(category) << "Malloc - TK_LOTNO[24]";
	TK_LOTNO.resize(24);

#pragma endregion Resize Fields TK_LOTREC
}
void TK_LOTREC::close()
{
	QLoggingCategory category("classLibQ");
	if (m_bIsOpen)
	{
	qDebug(category) << "database is Open";
		SQLHANDLE source_hStmt = hStmt_Fetch;
		SQLHANDLE insert_hStmt = hStmt_Insert;
		SQLHANDLE hDb_S = this->hDbc_source;
		SQLHANDLE hDb_T = hDbc_target;
		SQLHANDLE hEnvS = hEnv_Source;
		SQLHANDLE hEnvT = hEnv_Target;
		RETCODE r;

		r = ::SQLFreeHandle(SQL_HANDLE_STMT, hStmt_Fetch);
		r = ::SQLFreeHandle(SQL_HANDLE_STMT, hStmt_Insert);
		r = ::SQLFreeHandle(SQL_HANDLE_STMT, hStmt_Update);
		if (hDbc_source != SQL_NULL_HANDLE) 		r = ::SQLDisconnect(hDb_S);
		if (hDbc_target != SQL_NULL_HANDLE) 		r = ::SQLDisconnect(hDb_T);

		r = ::SQLFreeHandle(SQL_HANDLE_DBC, hDb_S);
		r = ::SQLFreeHandle(SQL_HANDLE_DBC, hDb_T);
		r = ::SQLFreeHandle(SQL_HANDLE_ENV, hEnvS);
		r = ::SQLFreeHandle(SQL_HANDLE_ENV, hEnvT);
	}

	hEnv_Source = SQL_NULL_HANDLE;
	hEnv_Target = SQL_NULL_HANDLE;
	hEnv_Source = SQL_NULL_HANDLE;
	hEnv_Target = SQL_NULL_HANDLE;
	hStmt_Fetch = SQL_NULL_HANDLE;
	hStmt_Insert = SQL_NULL_HANDLE;
	hStmt_Update = SQL_NULL_HANDLE;
}

void TK_LOTREC::open(const QString sourceDSN, const QString targetDSN)
{
	QLoggingCategory category("classLibQ");
	m_lpszTargetDSN = targetDSN;
	m_lpszSourceDSN = sourceDSN;
	qDebug(category) << QString("Source - %1[%2]").arg(sourceDSN);
	qDebug(category) << QString("Target - %1[%2]").arg(targetDSN);
}

void TK_LOTREC::createTable()
{
	QLoggingCategory category("classLibQ");
	{
		QScopedPointer<nvTableOracleRdb> tbl(new nvTableOracleRdb(nullptr));
		tbl->initialize("TK_LOTREC", this->m_lpszSourceDSN);
		QString newTbl = tbl->getCreateTableSQL();
		QScopedPointer<qVtExecute> vExec(new qVtExecute(nullptr));
		{
			vExec->initialize(m_lpszTargetDSN, " ", true);
			vExec->setOdbcAttributes(m_OdbcAttributes);
			vExec->ExecuteDirect(newTbl);
		}
	 qDebug(category) << QString("End Create Table %1 ").arg(tableName); 
	}
}

bool TK_LOTREC::prepare()
{
	RETCODE r;
	QString check;
	QLoggingCategory category("classLibQ");
	 qDebug(category) << fetchSql;
	 qDebug(category) << insertSql;
#ifdef UNICODE
	r = SQLPrepare(hStmt_Insert,toSQLTCHAR(insertSql).data(),(SQLINTEGER)insertSql.length()); 
	if (r != SQL_SUCCESS) {
		check = qWarnODBCHandle(SQL_HANDLE_STMT, hStmt_Insert);
		 qCCritical(category) << QString("Prepare Statement-Insert : %1 is %2").arg(insertSql).arg(check);
		return false; 
	}
	r = SQLPrepare(hStmt_Update,toSQLTCHAR(updateSql).data(),(SQLINTEGER)updateSql.length()); 
	if (r != SQL_SUCCESS) {
		check = qWarnODBCHandle(SQL_HANDLE_STMT, hStmt_Update);
		 qCCritical(category) << QString("Prepare Statement-Update : %1 is %2").arg(updateSql).arg(check);
		return false; 
	}
	r = SQLPrepare(hStmt_Fetch,toSQLTCHAR(fetchSql).data(),(SQLINTEGER)fetchSql.length());
	if (r != SQL_SUCCESS) {
		check = qWarnODBCHandle(SQL_HANDLE_STMT, hStmt_Fetch);
		 qCCritical(category) << QString("Prepare Statement-Insert : %1 is %2").arg(fetchSql).arg(check);
		return false; 
	}
#else
	QByteArray queryI8 = insertSql.toUtf8();
	r = SQLPrepare(insert_hStmt,SQLCHAR*)queryI8.data(),(SQLINTEGER)queryI8.length());
	QByteArray queryU8 = fetchSql.toUtf8();
	r = SQLPrepare(hStmt_Fetch,(SQLCHAR*)queryU8.data(),(SQLINTEGER)queryU8.length());
#endif
	return true;

}

void TK_LOTREC::prepareTargetTable()
{
	QLoggingCategory category("classLibQ");
	if (this->m_ReplicationOption == ReplicationOption::BulkCopy)
	{
		QScopedPointer<qVtExecute> execSql(new qVtExecute(nullptr));
		DropOption option = this->m_dropOption;
		switch (option)
		{
			case DropOption::DeleteFromTable:
			{
				QLoggingCategory category("classLibQ");
				execSql->initialize(this->m_lpszTargetDSN, "delete from TK_LOTREC", true);
				execSql->setOdbcAttributes(this->m_OdbcAttributes);
				execSql->ExecuteDirect("delete from TK_LOTREC");
			}break;
			case DropOption::TruncateTable:
			{
				execSql->initialize(this->m_lpszTargetDSN, "truncate table TK_LOTREC", true);
				execSql->setOdbcAttributes(this->m_OdbcAttributes);
				execSql->ExecuteDirect("truncate table TK_LOTREC");
			}break;
			case DropOption::DropTable:
			{
				execSql->initialize(this->m_lpszTargetDSN, "drop table TK_LOTREC", true);
				execSql->setOdbcAttributes(this->m_OdbcAttributes);
				execSql->ExecuteDirect("drop table TK_LOTREC");
				createTable();
			}break;
		}
	}
}

bool TK_LOTREC::bindColumn()
{
	QLoggingCategory category("classLibQ");
	RETCODE r;
	bool isValid=true;
		 qDebug(category) << " Bindings: Ordinal [1] Type: 5 Buffer Size: 2 FieldName: DB_ID ";
		r = ::SQLBindCol(hStmt_Fetch, 1, 5, DB_ID.data(), 2, &cbDB_ID);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Bindings: Ordinal [2] Type: 93 Buffer Size: 23 FieldName: NVTIMESTAMP ";
		r = ::SQLBindCol(hStmt_Fetch, 2, 93, NVTIMESTAMP.data(), 23, &cbNVTIMESTAMP);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Bindings: Ordinal [3] Type: 5 Buffer Size: 2 FieldName: AREA ";
		r = ::SQLBindCol(hStmt_Fetch, 3, 5, AREA.data(), 2, &cbAREA);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Bindings: Ordinal [4] Type: 4 Buffer Size: 4 FieldName: PAGE ";
		r = ::SQLBindCol(hStmt_Fetch, 4, 4, PAGE.data(), 4, &cbPAGE);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Bindings: Ordinal [5] Type: 5 Buffer Size: 2 FieldName: LINE ";
		r = ::SQLBindCol(hStmt_Fetch, 5, 5, LINE.data(), 2, &cbLINE);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Bindings: Ordinal [6] Type: 1 Buffer Size: 24 FieldName: TK_LOTNO ";
		r = ::SQLBindCol(hStmt_Fetch, 6, 1, TK_LOTNO.data(), 24, &cbTK_LOTNO);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
	return isValid;
}

bool TK_LOTREC::bindParameter()
{
	QLoggingCategory category("classLibQ");
	RETCODE r;
	bool isValid=true;
	{
		 qDebug(category) << " Parameters: Ordinal [1] Type: 5 Buffer Size: 2 FieldName: DB_ID ";
		r = SQLBindParameter(hStmt_Insert, 1, SQL_PARAM_INPUT, SQL_C_DEFAULT, 5, 0, 0, (SQLPOINTER)DB_ID.constData(), 0, &cbDB_ID);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Parameters: Ordinal [2] Type: 93 Buffer Size: 23 FieldName: NVTIMESTAMP ";
		r = SQLBindParameter(hStmt_Insert, 2, SQL_PARAM_INPUT, SQL_C_DEFAULT, 93, 23, 0, (SQLPOINTER)NVTIMESTAMP.constData(), 0, &cbNVTIMESTAMP);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Parameters: Ordinal [3] Type: 5 Buffer Size: 2 FieldName: AREA ";
		r = SQLBindParameter(hStmt_Insert, 3, SQL_PARAM_INPUT, SQL_C_DEFAULT, 5, 0, 0, (SQLPOINTER)AREA.constData(), 0, &cbAREA);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Parameters: Ordinal [4] Type: 4 Buffer Size: 4 FieldName: PAGE ";
		r = SQLBindParameter(hStmt_Insert, 4, SQL_PARAM_INPUT, SQL_C_DEFAULT, 4, 0, 0, (SQLPOINTER)PAGE.constData(), 0, &cbPAGE);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Parameters: Ordinal [5] Type: 5 Buffer Size: 2 FieldName: LINE ";
		r = SQLBindParameter(hStmt_Insert, 5, SQL_PARAM_INPUT, SQL_C_DEFAULT, 5, 0, 0, (SQLPOINTER)LINE.constData(), 0, &cbLINE);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Parameters: Ordinal [6] Type: 1 Buffer Size: 24 FieldName: TK_LOTNO ";
		r = SQLBindParameter(hStmt_Insert, 6, SQL_PARAM_INPUT, SQL_C_DEFAULT, 1, 24, 0, (SQLPOINTER)TK_LOTNO.constData(), 0, &cbTK_LOTNO);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
	}
	if (m_ReplicationOption == ReplicationOption::NetChange)
	{
		r = SQLBindParameter(hStmt_Update, 7, SQL_PARAM_INPUT, SQL_C_DEFAULT, 3, 0, 0, (SQLPOINTER)AREA.constData(), 0, &cbAREA);
		if (r == SQL_SUCCESS) { isValid=true; }
		r = SQLBindParameter(hStmt_Update, 8, SQL_PARAM_INPUT, SQL_C_DEFAULT, 4, 0, 0, (SQLPOINTER)PAGE.constData(), 0, &cbPAGE);
		if (r == SQL_SUCCESS) { isValid=true; }
		r = SQLBindParameter(hStmt_Update, 9, SQL_PARAM_INPUT, SQL_C_DEFAULT, 5, 0, 0, (SQLPOINTER)LINE.constData(), 0, &cbLINE);
		if (r == SQL_SUCCESS) { isValid=true; }
	// TK_LOTREC is a well formed table for eNVy Replication 
		 qDebug(category) << " Parameters: Ordinal [3] 00 00 FieldName: AREA ";
		 qDebug(category) << " Parameters: Ordinal [4] 00 00  FieldName: PAGE ";
		 qDebug(category) << " Parameters: Ordinal [5] 00 00 FieldName:  LINE ";
	} // 	if (m_ReplicationOption == ReplicationOption::NetChange)
	return isValid;
}

bool TK_LOTREC::process(int rowSize)
{
	QLoggingCategory category("classLibQ");
	initOdbcAttributes();
	connect(Source);
	connect(Target);
	initialize();
	prepareTargetTable();
	prepare();
	bindColumn();
	bindParameter();
	copyTable();
	close();
	return false;
}

void TK_LOTREC::copyTable()
{
	QLoggingCategory category("classLibQ");
	RETCODE r;
	QString check;
	r = SQLExecute(hStmt_Fetch);
		if (bIsAbort) {
			emit aborted(tableName, rowsFetched, rowsInserted, rowsUpdated);
			return;
		}
		while((r = SQLFetch(hStmt_Fetch)) != SQL_NO_DATA) {
		if (r != SQL_SUCCESS) {
			check = qWarnODBCHandle(SQL_HANDLE_STMT, hStmt_Fetch);
			qCCritical(category) << QString("SqlFetch - Error : %1 is %2").arg(fetchSql).arg(check);
			return;
		} 
		rowsFetched++;
		if (m_ReplicationOption == ReplicationOption::BulkCopy)
		{
			r = SQLExecute(hStmt_Insert);
			if (r == SQL_ERROR) {
				check = qWarnODBCHandle(SQL_HANDLE_STMT, hStmt_Insert);
				 qCCritical(category) << QString("SqlExecute:Insert - Error : %1 is %2").arg(insertSql).arg(check);
				return;
			}
			rowsInserted++;
			if ((rowsFetched % updateInterval) == 0) {
				qCInfo(category) << QString("[%1.%2]	Insertion: %3	Updates : %4	Fetched : %5").arg(profileName).arg(tableName).arg(rowsInserted).arg(rowsUpdated).arg(rowsFetched);
				emit updateStatusFetched(profileName, tableName, rowsFetched,rowsInserted,rowsUpdated);
			}
			if (m_ReplicationOption == ReplicationOption::NetChange)
			{
			r = SQLExecute(hStmt_Update);
			if (r != SQL_SUCCESS) {
				check = qWarnODBCHandle(SQL_HANDLE_STMT, hStmt_Update);
				 qCInfo(category)  << QString("SqlExecute:Update - Error : %1 is %2").arg(updateSql).arg(check);
				r = SQLExecute(hStmt_Insert);
				if (r != SQL_SUCCESS) {
					check = qWarnODBCHandle(SQL_HANDLE_STMT, hStmt_Insert);
					 qCritical(category) << QString("SqlExecute:Insert - Error : %1 is %2").arg(insertSql).arg(check);
					return;
				}
				else 	rowsInserted++;
				}
				else	rowsUpdated++;
			}
			emit updateStatusFetched(profileName, tableName, rowsFetched,rowsInserted,rowsUpdated);
		}
	} 
qCInfo(category) << QString("[%1.%2]	Insertion: %3	Updates : %4	Fetched : %5").arg(profileName).arg(tableName).arg(rowsInserted).arg(rowsUpdated).arg(rowsFetched);
}

void TK_LOTREC::connect(connectionHandle connectionSource)
{

	QLoggingCategory category("classLibQ");
	RETCODE r;

	bool isValid = false;
	HWND	hWnd = nullptr;
	hWnd = ::GetDesktopWindow(); 
	SQLSMALLINT nResult = 0;

	SQLSMALLINT cb;
	UWORD wConnectOption = SQL_DRIVER_COMPLETE; //SQL_DRIVER_NOPROMPT;
	QVarLengthArray<SQLTCHAR> connOut(1024);
	memset(connOut.data(), 0, connOut.size() * sizeof(SQLTCHAR));

	switch (connectionSource)
	{
		case Source:
			{// environment
				SQLHANDLE hEnv = SQL_NULL_HANDLE;
				SQLHANDLE hDbc = SQL_NULL_HANDLE;
				r = ::SQLAllocHandle(SQL_HANDLE_ENV, SQL_NULL_HANDLE, &hEnv);
				if (r == SQL_SUCCESS) isValid = true;

				foreach(nOdbcAttributesClass * k, this->m_OdbcAttributes_Map)
				{
					if (k->attributeType == enumAttributeType::hEnv)
					{
						r = ::SQLSetEnvAttr(hEnv, (SQLINTEGER) k->odbcKey, (SQLPOINTER)k->odbcValue, 0);
						if (r == SQL_SUCCESS) isValid = true;
					}
				}
				hEnv_Source = hEnv;

				r = SQLAllocHandle(SQL_HANDLE_DBC, hEnv, &hDbc);
				if (r == SQL_SUCCESS) isValid = true;
				foreach(nOdbcAttributesClass * k, this->m_OdbcAttributes_Map)
				{
					if (k->attributeType == enumAttributeType::hDbc)
					{
					r = ::SQLSetConnectAttr(hDbc, k->odbcKey, (SQLPOINTER)k->odbcValue, 0);
					if (k->odbcKey == SQL_ATTR_CONNECTION_POOLING && k->odbcValue == SQL_CP_ONE_PER_DRIVER) wConnectOption = SQL_DRIVER_NOPROMPT;
					if (k->odbcKey == SQL_ATTR_CONNECTION_POOLING && k->odbcValue == SQL_CP_ONE_PER_HENV) wConnectOption = SQL_DRIVER_NOPROMPT;
					if (k->odbcKey == SQL_ATTR_CONNECTION_POOLING && k->odbcValue == SQL_CP_DRIVER_AWARE) wConnectOption = SQL_DRIVER_NOPROMPT;
					if (r == SQL_SUCCESS) isValid = true;
					}
				}
				hDbc_source = hDbc;
				if (isValid)
				{
					r = ::SQLDriverConnect(
						hDbc,
						hWnd,
#ifdef UNICODE
						toSQLTCHAR(m_lpszSourceDSN).data(),
#else
						(SQLCHAR*)dsnSource.toUtf8().data(),
#endif
						(SQLSMALLINT)m_lpszSourceDSN.length(),
						connOut.data(),
						1024,
						&cb, 
						wConnectOption); 
					int colSize = cb / sizeof(SQLTCHAR);
					if (r != SQL_SUCCESS && r != SQL_SUCCESS_WITH_INFO)
					{
						QString check = qWarnODBCHandle(SQL_HANDLE_DBC, hDbc);
						qCritical(category) <<  check;
						m_bIsOpen = false;
					}
					m_bIsOpen = true;
				}
			} break;
		case Target:
			{
				SQLHANDLE hEnv = SQL_NULL_HANDLE;
				SQLHANDLE hDbc = SQL_NULL_HANDLE;
				r = ::SQLAllocHandle(SQL_HANDLE_ENV, SQL_NULL_HANDLE, &hEnv);
				if (r == SQL_SUCCESS) isValid = true;

				foreach(nOdbcAttributesClass * k, this->m_OdbcAttributes_Map)
				{
					if (k->attributeType == enumAttributeType::hEnv)
					{
						r = ::SQLSetEnvAttr(hEnv, (SQLINTEGER) k->odbcKey, (SQLPOINTER)k->odbcValue, 0);
						if (r == SQL_SUCCESS) isValid = true;
					}
				}
				hEnv_Target = hEnv;

				r = SQLAllocHandle(SQL_HANDLE_DBC, hEnv, &hDbc);
				if (r == SQL_SUCCESS) isValid = true;
				foreach(nOdbcAttributesClass * k, this->m_OdbcAttributes_Map)
				{
				if (k->attributeType == enumAttributeType::hDbc)
					{
					r = ::SQLSetConnectAttr(hDbc, k->odbcKey, (SQLPOINTER)k->odbcValue, 0);
					if (k->odbcKey == SQL_ATTR_CONNECTION_POOLING && k->odbcValue == SQL_CP_ONE_PER_DRIVER) wConnectOption = SQL_DRIVER_NOPROMPT;
					if (k->odbcKey == SQL_ATTR_CONNECTION_POOLING && k->odbcValue == SQL_CP_ONE_PER_HENV) wConnectOption = SQL_DRIVER_NOPROMPT;
					if (k->odbcKey == SQL_ATTR_CONNECTION_POOLING && k->odbcValue == SQL_CP_DRIVER_AWARE) wConnectOption = SQL_DRIVER_NOPROMPT;
					if (r == SQL_SUCCESS) isValid = true;
					}
				}
				hDbc_target = hDbc;
				if (isValid) {
					r = ::SQLDriverConnect(
						hDbc,
						hWnd,
#ifdef UNICODE
						toSQLTCHAR(m_lpszTargetDSN).data(),
#else
						(SQLCHAR*)m_lpszTargetDSN.toUtf8().data(),
#endif
						(SQLSMALLINT)m_lpszTargetDSN.length(),
						connOut.data(),
						1024,
						&cb, 
						wConnectOption); 
						int colSize = cb / sizeof(SQLTCHAR);
					if (r != SQL_SUCCESS && r != SQL_SUCCESS_WITH_INFO)
						{
							QString check = qWarnODBCHandle(SQL_HANDLE_DBC, hDbc);
							qCritical(category) <<  check;
							m_bIsOpen = false;
						}
							m_bIsOpen = true;
					}
			} break;
			default: break;
	}
}
TK_TYPHDRSET::TK_TYPHDRSET(QObject * parent) : QObject(parent) 
,tableName("TK_TYPHDRSET")
,m_dropOption(DropOption::DropTable) { 
	numRowsFetched = 0;
}

#pragma region ~CTOR TK_TYPHDRSET 
TK_TYPHDRSET::~TK_TYPHDRSET() { 

#pragma region Buffers - Clear 
	DB_ID.clear();
	NVTIMESTAMP.clear();
	OAREA.clear();
	OPAGE.clear();
	OLINE.clear();
	MAREA.clear();
	MPAGE.clear();
	MLINE.clear();
#pragma endregion Buffers - Clear 
}
#pragma endregion Destructor_TK_TYPHDRSET

// begin method functions
void TK_TYPHDRSET::setAbortFlag() { 
	QLoggingCategory category("classLibQ");
	qCInfo(category) << "isAbort was set to True";
	bIsAbort = true;
}

void TK_TYPHDRSET::run() { 
	process(1);
	QLoggingCategory category("classLibQ");
	qDebug(category) << "Entered;";
}

void	TK_TYPHDRSET::initOdbcAttributes()
{
	QLoggingCategory category("classLibQ");
	this->setProfileName(profileName);
	qDebug(category) << "Processing - TRKDB100"; 
	m_OdbcAttributesList = m_OdbcAttributes.split(","); 
	foreach(QString m, m_OdbcAttributesList)
	{
		QStringList keyValue = m.split("=");
		nOdbcAttributesClass * oM = new nOdbcAttributesClass(this);
		if (oM->loadToOdbc(keyValue.value(0), keyValue.value(1)))
		{
			m_OdbcAttributes_Map.insert(oM->odbcKey, oM);
		}
	}
}
void	TK_TYPHDRSET::initialize()
{
	QLoggingCategory category("classLibQ");
	RETCODE r;
	this->setProfileName(profileName);
	qDebug(category) << "Processing - TRKDB100"; 
//SQL Statements
//--------------------------------------------------

#pragma region Sql Statements_TK_TYPHDRSET

	fetchSql = "select  DB_ID, NVTIMESTAMP, OAREA, OPAGE, OLINE, MAREA, MPAGE, MLINE from TK_TYPHDRSET";
		if (m_ReplicationOption == ReplicationOption::NetChange)
		{
			fetchSql.append(" p1, nv_transfers p2 WHERE  p2.table_name = 'TK_TYPHDRSET' AND p1.nvtimestamp > p2.last_completed");
		}
	insertSql = "insert into TK_TYPHDRSET ( PLANT_CODE, NVTIMESTAMP, OAREA, OPAGE, OLINE, MAREA, MPAGE, MLINE ) values ( ?, ?, ?, ?, ?, ?, ?, ?)";
	updateSql = "update TK_TYPHDRSET set  PLANT_CODE = ?, NVTIMESTAMP = ?, OAREA = ?, OPAGE = ?, OLINE = ?, MAREA = ?, MPAGE = ?, MLINE = ?  where area = ? and page = ? line = ? ";

	qDebug(category) << "insertSQL - insert into TK_TYPHDRSET ( PLANT_CODE, NVTIMESTAMP, OAREA, OPAGE, OLINE, MAREA, MPAGE, MLINE ) values ( ?, ?, ?, ?, ?, ?, ?, ?)";
	qDebug(category) << "fetchSQL - select  DB_ID, NVTIMESTAMP, OAREA, OPAGE, OLINE, MAREA, MPAGE, MLINE from TK_TYPHDRSET";
	qDebug(category) << "unsertSQL - update TK_TYPHDRSET set  PLANT_CODE = ?, NVTIMESTAMP = ?, OAREA = ?, OPAGE = ?, OLINE = ?, MAREA = ?, MPAGE = ?, MLINE = ?  where area = ? and page = ? line = ? ";

#pragma endregion Sql Statements_TK_TYPHDRSET
	SQLHANDLE		insert_hStmt = SQL_NULL_HANDLE;
	SQLHANDLE		fetch_hStmt = SQL_NULL_HANDLE; 
	SQLHANDLE		update_hStmt = SQL_NULL_HANDLE; 
 
	r = ::SQLAllocHandle(SQL_HANDLE_STMT, hDbc_source, &fetch_hStmt);
	if (r != SQL_SUCCESS) {
		 qCCritical(category) << QString("Error  hDbc_Source SQLCode : %1 is %2").arg(QString::number( (long)hDbc_source)).arg(QString::number(r));
		return; 
	}
	r = ::SQLAllocHandle(SQL_HANDLE_STMT, hDbc_target, &insert_hStmt);
	if (r != SQL_SUCCESS) {
		 qCCritical(category) << QString("Error hDbc_Source -SQLCode: %1 is %2").arg(QString::number( (long)hDbc_target)).arg(QString::number(r));
		return; 
	}
	r = ::SQLAllocHandle(SQL_HANDLE_STMT, hDbc_target, &update_hStmt);
	if (r != SQL_SUCCESS) {
		 qCCritical(category) << QString("Error hDbc_Source +SQLCode: %1 is %2").arg(QString::number( (long)hDbc_target)).arg(QString::number(r));
		return; 
	}
 
	hStmt_Fetch = fetch_hStmt;
	hStmt_Insert = insert_hStmt;
	hStmt_Update = update_hStmt;
 
	SQLSetStmtAttr(hStmt_Fetch, SQL_ATTR_USE_BOOKMARKS, (SQLPOINTER)SQL_UB_OFF, 0);
	SQLSetStmtAttr(hStmt_Fetch, SQL_ATTR_ROW_BIND_TYPE, (SQLPOINTER)SQL_BIND_BY_COLUMN, 0);
	SQLSetStmtAttr(hStmt_Fetch, SQL_ATTR_ROW_ARRAY_SIZE, (SQLPOINTER)1, 0);
	SQLSetStmtAttr(hStmt_Fetch, SQL_ATTR_ROWS_FETCHED_PTR, &numRowsFetched, 0);

// Fields used by this class 
// ---------------------------------------------------

#pragma region Resize Fields TK_TYPHDRSET
	qDebug(category) << "Malloc - DB_ID[2]";
	DB_ID.resize(2);
	qDebug(category) << "Malloc - NVTIMESTAMP[23]";
	NVTIMESTAMP.resize(23);
	qDebug(category) << "Malloc - OAREA[2]";
	OAREA.resize(2);
	qDebug(category) << "Malloc - OPAGE[4]";
	OPAGE.resize(4);
	qDebug(category) << "Malloc - OLINE[2]";
	OLINE.resize(2);
	qDebug(category) << "Malloc - MAREA[2]";
	MAREA.resize(2);
	qDebug(category) << "Malloc - MPAGE[4]";
	MPAGE.resize(4);
	qDebug(category) << "Malloc - MLINE[2]";
	MLINE.resize(2);

#pragma endregion Resize Fields TK_TYPHDRSET
}
void TK_TYPHDRSET::close()
{
	QLoggingCategory category("classLibQ");
	if (m_bIsOpen)
	{
	qDebug(category) << "database is Open";
		SQLHANDLE source_hStmt = hStmt_Fetch;
		SQLHANDLE insert_hStmt = hStmt_Insert;
		SQLHANDLE hDb_S = this->hDbc_source;
		SQLHANDLE hDb_T = hDbc_target;
		SQLHANDLE hEnvS = hEnv_Source;
		SQLHANDLE hEnvT = hEnv_Target;
		RETCODE r;

		r = ::SQLFreeHandle(SQL_HANDLE_STMT, hStmt_Fetch);
		r = ::SQLFreeHandle(SQL_HANDLE_STMT, hStmt_Insert);
		r = ::SQLFreeHandle(SQL_HANDLE_STMT, hStmt_Update);
		if (hDbc_source != SQL_NULL_HANDLE) 		r = ::SQLDisconnect(hDb_S);
		if (hDbc_target != SQL_NULL_HANDLE) 		r = ::SQLDisconnect(hDb_T);

		r = ::SQLFreeHandle(SQL_HANDLE_DBC, hDb_S);
		r = ::SQLFreeHandle(SQL_HANDLE_DBC, hDb_T);
		r = ::SQLFreeHandle(SQL_HANDLE_ENV, hEnvS);
		r = ::SQLFreeHandle(SQL_HANDLE_ENV, hEnvT);
	}

	hEnv_Source = SQL_NULL_HANDLE;
	hEnv_Target = SQL_NULL_HANDLE;
	hEnv_Source = SQL_NULL_HANDLE;
	hEnv_Target = SQL_NULL_HANDLE;
	hStmt_Fetch = SQL_NULL_HANDLE;
	hStmt_Insert = SQL_NULL_HANDLE;
	hStmt_Update = SQL_NULL_HANDLE;
}

void TK_TYPHDRSET::open(const QString sourceDSN, const QString targetDSN)
{
	QLoggingCategory category("classLibQ");
	m_lpszTargetDSN = targetDSN;
	m_lpszSourceDSN = sourceDSN;
	qDebug(category) << QString("Source - %1[%2]").arg(sourceDSN);
	qDebug(category) << QString("Target - %1[%2]").arg(targetDSN);
}

void TK_TYPHDRSET::createTable()
{
	QLoggingCategory category("classLibQ");
	{
		QScopedPointer<nvTableOracleRdb> tbl(new nvTableOracleRdb(nullptr));
		tbl->initialize("TK_TYPHDRSET", this->m_lpszSourceDSN);
		QString newTbl = tbl->getCreateTableSQL();
		QScopedPointer<qVtExecute> vExec(new qVtExecute(nullptr));
		{
			vExec->initialize(m_lpszTargetDSN, " ", true);
			vExec->setOdbcAttributes(m_OdbcAttributes);
			vExec->ExecuteDirect(newTbl);
		}
	 qDebug(category) << QString("End Create Table %1 ").arg(tableName); 
	}
}

bool TK_TYPHDRSET::prepare()
{
	RETCODE r;
	QString check;
	QLoggingCategory category("classLibQ");
	 qDebug(category) << fetchSql;
	 qDebug(category) << insertSql;
#ifdef UNICODE
	r = SQLPrepare(hStmt_Insert,toSQLTCHAR(insertSql).data(),(SQLINTEGER)insertSql.length()); 
	if (r != SQL_SUCCESS) {
		check = qWarnODBCHandle(SQL_HANDLE_STMT, hStmt_Insert);
		 qCCritical(category) << QString("Prepare Statement-Insert : %1 is %2").arg(insertSql).arg(check);
		return false; 
	}
	r = SQLPrepare(hStmt_Update,toSQLTCHAR(updateSql).data(),(SQLINTEGER)updateSql.length()); 
	if (r != SQL_SUCCESS) {
		check = qWarnODBCHandle(SQL_HANDLE_STMT, hStmt_Update);
		 qCCritical(category) << QString("Prepare Statement-Update : %1 is %2").arg(updateSql).arg(check);
		return false; 
	}
	r = SQLPrepare(hStmt_Fetch,toSQLTCHAR(fetchSql).data(),(SQLINTEGER)fetchSql.length());
	if (r != SQL_SUCCESS) {
		check = qWarnODBCHandle(SQL_HANDLE_STMT, hStmt_Fetch);
		 qCCritical(category) << QString("Prepare Statement-Insert : %1 is %2").arg(fetchSql).arg(check);
		return false; 
	}
#else
	QByteArray queryI8 = insertSql.toUtf8();
	r = SQLPrepare(insert_hStmt,SQLCHAR*)queryI8.data(),(SQLINTEGER)queryI8.length());
	QByteArray queryU8 = fetchSql.toUtf8();
	r = SQLPrepare(hStmt_Fetch,(SQLCHAR*)queryU8.data(),(SQLINTEGER)queryU8.length());
#endif
	return true;

}

void TK_TYPHDRSET::prepareTargetTable()
{
	QLoggingCategory category("classLibQ");
	if (this->m_ReplicationOption == ReplicationOption::BulkCopy)
	{
		QScopedPointer<qVtExecute> execSql(new qVtExecute(nullptr));
		DropOption option = this->m_dropOption;
		switch (option)
		{
			case DropOption::DeleteFromTable:
			{
				QLoggingCategory category("classLibQ");
				execSql->initialize(this->m_lpszTargetDSN, "delete from TK_TYPHDRSET", true);
				execSql->setOdbcAttributes(this->m_OdbcAttributes);
				execSql->ExecuteDirect("delete from TK_TYPHDRSET");
			}break;
			case DropOption::TruncateTable:
			{
				execSql->initialize(this->m_lpszTargetDSN, "truncate table TK_TYPHDRSET", true);
				execSql->setOdbcAttributes(this->m_OdbcAttributes);
				execSql->ExecuteDirect("truncate table TK_TYPHDRSET");
			}break;
			case DropOption::DropTable:
			{
				execSql->initialize(this->m_lpszTargetDSN, "drop table TK_TYPHDRSET", true);
				execSql->setOdbcAttributes(this->m_OdbcAttributes);
				execSql->ExecuteDirect("drop table TK_TYPHDRSET");
				createTable();
			}break;
		}
	}
}

bool TK_TYPHDRSET::bindColumn()
{
	QLoggingCategory category("classLibQ");
	RETCODE r;
	bool isValid=true;
		 qDebug(category) << " Bindings: Ordinal [1] Type: 5 Buffer Size: 2 FieldName: DB_ID ";
		r = ::SQLBindCol(hStmt_Fetch, 1, 5, DB_ID.data(), 2, &cbDB_ID);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Bindings: Ordinal [2] Type: 93 Buffer Size: 23 FieldName: NVTIMESTAMP ";
		r = ::SQLBindCol(hStmt_Fetch, 2, 93, NVTIMESTAMP.data(), 23, &cbNVTIMESTAMP);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Bindings: Ordinal [3] Type: 5 Buffer Size: 2 FieldName: OAREA ";
		r = ::SQLBindCol(hStmt_Fetch, 3, 5, OAREA.data(), 2, &cbOAREA);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Bindings: Ordinal [4] Type: 4 Buffer Size: 4 FieldName: OPAGE ";
		r = ::SQLBindCol(hStmt_Fetch, 4, 4, OPAGE.data(), 4, &cbOPAGE);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Bindings: Ordinal [5] Type: 5 Buffer Size: 2 FieldName: OLINE ";
		r = ::SQLBindCol(hStmt_Fetch, 5, 5, OLINE.data(), 2, &cbOLINE);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Bindings: Ordinal [6] Type: 5 Buffer Size: 2 FieldName: MAREA ";
		r = ::SQLBindCol(hStmt_Fetch, 6, 5, MAREA.data(), 2, &cbMAREA);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Bindings: Ordinal [7] Type: 4 Buffer Size: 4 FieldName: MPAGE ";
		r = ::SQLBindCol(hStmt_Fetch, 7, 4, MPAGE.data(), 4, &cbMPAGE);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Bindings: Ordinal [8] Type: 5 Buffer Size: 2 FieldName: MLINE ";
		r = ::SQLBindCol(hStmt_Fetch, 8, 5, MLINE.data(), 2, &cbMLINE);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
	return isValid;
}

bool TK_TYPHDRSET::bindParameter()
{
	QLoggingCategory category("classLibQ");
	RETCODE r;
	bool isValid=true;
	{
		 qDebug(category) << " Parameters: Ordinal [1] Type: 5 Buffer Size: 2 FieldName: DB_ID ";
		r = SQLBindParameter(hStmt_Insert, 1, SQL_PARAM_INPUT, SQL_C_DEFAULT, 5, 0, 0, (SQLPOINTER)DB_ID.constData(), 0, &cbDB_ID);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Parameters: Ordinal [2] Type: 93 Buffer Size: 23 FieldName: NVTIMESTAMP ";
		r = SQLBindParameter(hStmt_Insert, 2, SQL_PARAM_INPUT, SQL_C_DEFAULT, 93, 23, 0, (SQLPOINTER)NVTIMESTAMP.constData(), 0, &cbNVTIMESTAMP);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Parameters: Ordinal [3] Type: 5 Buffer Size: 2 FieldName: OAREA ";
		r = SQLBindParameter(hStmt_Insert, 3, SQL_PARAM_INPUT, SQL_C_DEFAULT, 5, 0, 0, (SQLPOINTER)OAREA.constData(), 0, &cbOAREA);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Parameters: Ordinal [4] Type: 4 Buffer Size: 4 FieldName: OPAGE ";
		r = SQLBindParameter(hStmt_Insert, 4, SQL_PARAM_INPUT, SQL_C_DEFAULT, 4, 0, 0, (SQLPOINTER)OPAGE.constData(), 0, &cbOPAGE);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Parameters: Ordinal [5] Type: 5 Buffer Size: 2 FieldName: OLINE ";
		r = SQLBindParameter(hStmt_Insert, 5, SQL_PARAM_INPUT, SQL_C_DEFAULT, 5, 0, 0, (SQLPOINTER)OLINE.constData(), 0, &cbOLINE);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Parameters: Ordinal [6] Type: 5 Buffer Size: 2 FieldName: MAREA ";
		r = SQLBindParameter(hStmt_Insert, 6, SQL_PARAM_INPUT, SQL_C_DEFAULT, 5, 0, 0, (SQLPOINTER)MAREA.constData(), 0, &cbMAREA);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Parameters: Ordinal [7] Type: 4 Buffer Size: 4 FieldName: MPAGE ";
		r = SQLBindParameter(hStmt_Insert, 7, SQL_PARAM_INPUT, SQL_C_DEFAULT, 4, 0, 0, (SQLPOINTER)MPAGE.constData(), 0, &cbMPAGE);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Parameters: Ordinal [8] Type: 5 Buffer Size: 2 FieldName: MLINE ";
		r = SQLBindParameter(hStmt_Insert, 8, SQL_PARAM_INPUT, SQL_C_DEFAULT, 5, 0, 0, (SQLPOINTER)MLINE.constData(), 0, &cbMLINE);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
	}
	if (m_ReplicationOption == ReplicationOption::NetChange)
	{
		r = SQLBindParameter(hStmt_Update, 9, SQL_PARAM_INPUT, SQL_C_DEFAULT, 6, 0, 0, (SQLPOINTER)MAREA.constData(), 0, &cbMAREA);
		if (r == SQL_SUCCESS) { isValid=true; }
		r = SQLBindParameter(hStmt_Update, 10, SQL_PARAM_INPUT, SQL_C_DEFAULT, 7, 0, 0, (SQLPOINTER)MPAGE.constData(), 0, &cbMPAGE);
		if (r == SQL_SUCCESS) { isValid=true; }
		r = SQLBindParameter(hStmt_Update, 11, SQL_PARAM_INPUT, SQL_C_DEFAULT, 8, 0, 0, (SQLPOINTER)MLINE.constData(), 0, &cbMLINE);
		if (r == SQL_SUCCESS) { isValid=true; }
	// TK_TYPHDRSET is a well formed table for eNVy Replication 
		 qDebug(category) << " Parameters: Ordinal [6] 00 00 FieldName: MAREA ";
		 qDebug(category) << " Parameters: Ordinal [7] 00 00  FieldName: MPAGE ";
		 qDebug(category) << " Parameters: Ordinal [8] 00 00 FieldName:  MLINE ";
	} // 	if (m_ReplicationOption == ReplicationOption::NetChange)
	return isValid;
}

bool TK_TYPHDRSET::process(int rowSize)
{
	QLoggingCategory category("classLibQ");
	initOdbcAttributes();
	connect(Source);
	connect(Target);
	initialize();
	prepareTargetTable();
	prepare();
	bindColumn();
	bindParameter();
	copyTable();
	close();
	return false;
}

void TK_TYPHDRSET::copyTable()
{
	QLoggingCategory category("classLibQ");
	RETCODE r;
	QString check;
	r = SQLExecute(hStmt_Fetch);
		if (bIsAbort) {
			emit aborted(tableName, rowsFetched, rowsInserted, rowsUpdated);
			return;
		}
		while((r = SQLFetch(hStmt_Fetch)) != SQL_NO_DATA) {
		if (r != SQL_SUCCESS) {
			check = qWarnODBCHandle(SQL_HANDLE_STMT, hStmt_Fetch);
			qCCritical(category) << QString("SqlFetch - Error : %1 is %2").arg(fetchSql).arg(check);
			return;
		} 
		rowsFetched++;
		if (m_ReplicationOption == ReplicationOption::BulkCopy)
		{
			r = SQLExecute(hStmt_Insert);
			if (r == SQL_ERROR) {
				check = qWarnODBCHandle(SQL_HANDLE_STMT, hStmt_Insert);
				 qCCritical(category) << QString("SqlExecute:Insert - Error : %1 is %2").arg(insertSql).arg(check);
				return;
			}
			rowsInserted++;
			if ((rowsFetched % updateInterval) == 0) {
				qCInfo(category) << QString("[%1.%2]	Insertion: %3	Updates : %4	Fetched : %5").arg(profileName).arg(tableName).arg(rowsInserted).arg(rowsUpdated).arg(rowsFetched);
				emit updateStatusFetched(profileName, tableName, rowsFetched,rowsInserted,rowsUpdated);
			}
			if (m_ReplicationOption == ReplicationOption::NetChange)
			{
			r = SQLExecute(hStmt_Update);
			if (r != SQL_SUCCESS) {
				check = qWarnODBCHandle(SQL_HANDLE_STMT, hStmt_Update);
				 qCInfo(category)  << QString("SqlExecute:Update - Error : %1 is %2").arg(updateSql).arg(check);
				r = SQLExecute(hStmt_Insert);
				if (r != SQL_SUCCESS) {
					check = qWarnODBCHandle(SQL_HANDLE_STMT, hStmt_Insert);
					 qCritical(category) << QString("SqlExecute:Insert - Error : %1 is %2").arg(insertSql).arg(check);
					return;
				}
				else 	rowsInserted++;
				}
				else	rowsUpdated++;
			}
			emit updateStatusFetched(profileName, tableName, rowsFetched,rowsInserted,rowsUpdated);
		}
	} 
qCInfo(category) << QString("[%1.%2]	Insertion: %3	Updates : %4	Fetched : %5").arg(profileName).arg(tableName).arg(rowsInserted).arg(rowsUpdated).arg(rowsFetched);
}

void TK_TYPHDRSET::connect(connectionHandle connectionSource)
{

	QLoggingCategory category("classLibQ");
	RETCODE r;

	bool isValid = false;
	HWND	hWnd = nullptr;
	hWnd = ::GetDesktopWindow(); 
	SQLSMALLINT nResult = 0;

	SQLSMALLINT cb;
	UWORD wConnectOption = SQL_DRIVER_COMPLETE; //SQL_DRIVER_NOPROMPT;
	QVarLengthArray<SQLTCHAR> connOut(1024);
	memset(connOut.data(), 0, connOut.size() * sizeof(SQLTCHAR));

	switch (connectionSource)
	{
		case Source:
			{// environment
				SQLHANDLE hEnv = SQL_NULL_HANDLE;
				SQLHANDLE hDbc = SQL_NULL_HANDLE;
				r = ::SQLAllocHandle(SQL_HANDLE_ENV, SQL_NULL_HANDLE, &hEnv);
				if (r == SQL_SUCCESS) isValid = true;

				foreach(nOdbcAttributesClass * k, this->m_OdbcAttributes_Map)
				{
					if (k->attributeType == enumAttributeType::hEnv)
					{
						r = ::SQLSetEnvAttr(hEnv, (SQLINTEGER) k->odbcKey, (SQLPOINTER)k->odbcValue, 0);
						if (r == SQL_SUCCESS) isValid = true;
					}
				}
				hEnv_Source = hEnv;

				r = SQLAllocHandle(SQL_HANDLE_DBC, hEnv, &hDbc);
				if (r == SQL_SUCCESS) isValid = true;
				foreach(nOdbcAttributesClass * k, this->m_OdbcAttributes_Map)
				{
					if (k->attributeType == enumAttributeType::hDbc)
					{
					r = ::SQLSetConnectAttr(hDbc, k->odbcKey, (SQLPOINTER)k->odbcValue, 0);
					if (k->odbcKey == SQL_ATTR_CONNECTION_POOLING && k->odbcValue == SQL_CP_ONE_PER_DRIVER) wConnectOption = SQL_DRIVER_NOPROMPT;
					if (k->odbcKey == SQL_ATTR_CONNECTION_POOLING && k->odbcValue == SQL_CP_ONE_PER_HENV) wConnectOption = SQL_DRIVER_NOPROMPT;
					if (k->odbcKey == SQL_ATTR_CONNECTION_POOLING && k->odbcValue == SQL_CP_DRIVER_AWARE) wConnectOption = SQL_DRIVER_NOPROMPT;
					if (r == SQL_SUCCESS) isValid = true;
					}
				}
				hDbc_source = hDbc;
				if (isValid)
				{
					r = ::SQLDriverConnect(
						hDbc,
						hWnd,
#ifdef UNICODE
						toSQLTCHAR(m_lpszSourceDSN).data(),
#else
						(SQLCHAR*)dsnSource.toUtf8().data(),
#endif
						(SQLSMALLINT)m_lpszSourceDSN.length(),
						connOut.data(),
						1024,
						&cb, 
						wConnectOption); 
					int colSize = cb / sizeof(SQLTCHAR);
					if (r != SQL_SUCCESS && r != SQL_SUCCESS_WITH_INFO)
					{
						QString check = qWarnODBCHandle(SQL_HANDLE_DBC, hDbc);
						qCritical(category) <<  check;
						m_bIsOpen = false;
					}
					m_bIsOpen = true;
				}
			} break;
		case Target:
			{
				SQLHANDLE hEnv = SQL_NULL_HANDLE;
				SQLHANDLE hDbc = SQL_NULL_HANDLE;
				r = ::SQLAllocHandle(SQL_HANDLE_ENV, SQL_NULL_HANDLE, &hEnv);
				if (r == SQL_SUCCESS) isValid = true;

				foreach(nOdbcAttributesClass * k, this->m_OdbcAttributes_Map)
				{
					if (k->attributeType == enumAttributeType::hEnv)
					{
						r = ::SQLSetEnvAttr(hEnv, (SQLINTEGER) k->odbcKey, (SQLPOINTER)k->odbcValue, 0);
						if (r == SQL_SUCCESS) isValid = true;
					}
				}
				hEnv_Target = hEnv;

				r = SQLAllocHandle(SQL_HANDLE_DBC, hEnv, &hDbc);
				if (r == SQL_SUCCESS) isValid = true;
				foreach(nOdbcAttributesClass * k, this->m_OdbcAttributes_Map)
				{
				if (k->attributeType == enumAttributeType::hDbc)
					{
					r = ::SQLSetConnectAttr(hDbc, k->odbcKey, (SQLPOINTER)k->odbcValue, 0);
					if (k->odbcKey == SQL_ATTR_CONNECTION_POOLING && k->odbcValue == SQL_CP_ONE_PER_DRIVER) wConnectOption = SQL_DRIVER_NOPROMPT;
					if (k->odbcKey == SQL_ATTR_CONNECTION_POOLING && k->odbcValue == SQL_CP_ONE_PER_HENV) wConnectOption = SQL_DRIVER_NOPROMPT;
					if (k->odbcKey == SQL_ATTR_CONNECTION_POOLING && k->odbcValue == SQL_CP_DRIVER_AWARE) wConnectOption = SQL_DRIVER_NOPROMPT;
					if (r == SQL_SUCCESS) isValid = true;
					}
				}
				hDbc_target = hDbc;
				if (isValid) {
					r = ::SQLDriverConnect(
						hDbc,
						hWnd,
#ifdef UNICODE
						toSQLTCHAR(m_lpszTargetDSN).data(),
#else
						(SQLCHAR*)m_lpszTargetDSN.toUtf8().data(),
#endif
						(SQLSMALLINT)m_lpszTargetDSN.length(),
						connOut.data(),
						1024,
						&cb, 
						wConnectOption); 
						int colSize = cb / sizeof(SQLTCHAR);
					if (r != SQL_SUCCESS && r != SQL_SUCCESS_WITH_INFO)
						{
							QString check = qWarnODBCHandle(SQL_HANDLE_DBC, hDbc);
							qCritical(category) <<  check;
							m_bIsOpen = false;
						}
							m_bIsOpen = true;
					}
			} break;
			default: break;
	}
}
TK_PRCREC::TK_PRCREC(QObject * parent) : QObject(parent) 
,tableName("TK_PRCREC")
,m_dropOption(DropOption::DropTable) { 
	numRowsFetched = 0;
}

#pragma region ~CTOR TK_PRCREC 
TK_PRCREC::~TK_PRCREC() { 

#pragma region Buffers - Clear 
	DB_ID.clear();
	NVTIMESTAMP.clear();
	AREA.clear();
	PAGE.clear();
	LINE.clear();
	TK_PRCUOM.clear();
	TK_PRCRND.clear();
#pragma endregion Buffers - Clear 
}
#pragma endregion Destructor_TK_PRCREC

// begin method functions
void TK_PRCREC::setAbortFlag() { 
	QLoggingCategory category("classLibQ");
	qCInfo(category) << "isAbort was set to True";
	bIsAbort = true;
}

void TK_PRCREC::run() { 
	process(1);
	QLoggingCategory category("classLibQ");
	qDebug(category) << "Entered;";
}

void	TK_PRCREC::initOdbcAttributes()
{
	QLoggingCategory category("classLibQ");
	this->setProfileName(profileName);
	qDebug(category) << "Processing - TRKDB100"; 
	m_OdbcAttributesList = m_OdbcAttributes.split(","); 
	foreach(QString m, m_OdbcAttributesList)
	{
		QStringList keyValue = m.split("=");
		nOdbcAttributesClass * oM = new nOdbcAttributesClass(this);
		if (oM->loadToOdbc(keyValue.value(0), keyValue.value(1)))
		{
			m_OdbcAttributes_Map.insert(oM->odbcKey, oM);
		}
	}
}
void	TK_PRCREC::initialize()
{
	QLoggingCategory category("classLibQ");
	RETCODE r;
	this->setProfileName(profileName);
	qDebug(category) << "Processing - TRKDB100"; 
//SQL Statements
//--------------------------------------------------

#pragma region Sql Statements_TK_PRCREC

	fetchSql = "select  DB_ID, NVTIMESTAMP, AREA, PAGE, LINE, TK_PRCUOM, TK_PRCRND from TK_PRCREC";
		if (m_ReplicationOption == ReplicationOption::NetChange)
		{
			fetchSql.append(" p1, nv_transfers p2 WHERE  p2.table_name = 'TK_PRCREC' AND p1.nvtimestamp > p2.last_completed");
		}
	insertSql = "insert into TK_PRCREC ( PLANT_CODE, NVTIMESTAMP, AREA, PAGE, LINE, TK_PRCUOM, TK_PRCRND ) values ( ?, ?, ?, ?, ?, ?, ?)";
	updateSql = "update TK_PRCREC set  PLANT_CODE = ?, NVTIMESTAMP = ?, AREA = ?, PAGE = ?, LINE = ?, TK_PRCUOM = ?, TK_PRCRND = ?  where area = ? and page = ? line = ? ";

	qDebug(category) << "insertSQL - insert into TK_PRCREC ( PLANT_CODE, NVTIMESTAMP, AREA, PAGE, LINE, TK_PRCUOM, TK_PRCRND ) values ( ?, ?, ?, ?, ?, ?, ?)";
	qDebug(category) << "fetchSQL - select  DB_ID, NVTIMESTAMP, AREA, PAGE, LINE, TK_PRCUOM, TK_PRCRND from TK_PRCREC";
	qDebug(category) << "unsertSQL - update TK_PRCREC set  PLANT_CODE = ?, NVTIMESTAMP = ?, AREA = ?, PAGE = ?, LINE = ?, TK_PRCUOM = ?, TK_PRCRND = ?  where area = ? and page = ? line = ? ";

#pragma endregion Sql Statements_TK_PRCREC
	SQLHANDLE		insert_hStmt = SQL_NULL_HANDLE;
	SQLHANDLE		fetch_hStmt = SQL_NULL_HANDLE; 
	SQLHANDLE		update_hStmt = SQL_NULL_HANDLE; 
 
	r = ::SQLAllocHandle(SQL_HANDLE_STMT, hDbc_source, &fetch_hStmt);
	if (r != SQL_SUCCESS) {
		 qCCritical(category) << QString("Error  hDbc_Source SQLCode : %1 is %2").arg(QString::number( (long)hDbc_source)).arg(QString::number(r));
		return; 
	}
	r = ::SQLAllocHandle(SQL_HANDLE_STMT, hDbc_target, &insert_hStmt);
	if (r != SQL_SUCCESS) {
		 qCCritical(category) << QString("Error hDbc_Source -SQLCode: %1 is %2").arg(QString::number( (long)hDbc_target)).arg(QString::number(r));
		return; 
	}
	r = ::SQLAllocHandle(SQL_HANDLE_STMT, hDbc_target, &update_hStmt);
	if (r != SQL_SUCCESS) {
		 qCCritical(category) << QString("Error hDbc_Source +SQLCode: %1 is %2").arg(QString::number( (long)hDbc_target)).arg(QString::number(r));
		return; 
	}
 
	hStmt_Fetch = fetch_hStmt;
	hStmt_Insert = insert_hStmt;
	hStmt_Update = update_hStmt;
 
	SQLSetStmtAttr(hStmt_Fetch, SQL_ATTR_USE_BOOKMARKS, (SQLPOINTER)SQL_UB_OFF, 0);
	SQLSetStmtAttr(hStmt_Fetch, SQL_ATTR_ROW_BIND_TYPE, (SQLPOINTER)SQL_BIND_BY_COLUMN, 0);
	SQLSetStmtAttr(hStmt_Fetch, SQL_ATTR_ROW_ARRAY_SIZE, (SQLPOINTER)1, 0);
	SQLSetStmtAttr(hStmt_Fetch, SQL_ATTR_ROWS_FETCHED_PTR, &numRowsFetched, 0);

// Fields used by this class 
// ---------------------------------------------------

#pragma region Resize Fields TK_PRCREC
	qDebug(category) << "Malloc - DB_ID[2]";
	DB_ID.resize(2);
	qDebug(category) << "Malloc - NVTIMESTAMP[23]";
	NVTIMESTAMP.resize(23);
	qDebug(category) << "Malloc - AREA[2]";
	AREA.resize(2);
	qDebug(category) << "Malloc - PAGE[4]";
	PAGE.resize(4);
	qDebug(category) << "Malloc - LINE[2]";
	LINE.resize(2);
	qDebug(category) << "Malloc - TK_PRCUOM[2]";
	TK_PRCUOM.resize(2);
	qDebug(category) << "Malloc - TK_PRCRND[2]";
	TK_PRCRND.resize(2);

#pragma endregion Resize Fields TK_PRCREC
}
void TK_PRCREC::close()
{
	QLoggingCategory category("classLibQ");
	if (m_bIsOpen)
	{
	qDebug(category) << "database is Open";
		SQLHANDLE source_hStmt = hStmt_Fetch;
		SQLHANDLE insert_hStmt = hStmt_Insert;
		SQLHANDLE hDb_S = this->hDbc_source;
		SQLHANDLE hDb_T = hDbc_target;
		SQLHANDLE hEnvS = hEnv_Source;
		SQLHANDLE hEnvT = hEnv_Target;
		RETCODE r;

		r = ::SQLFreeHandle(SQL_HANDLE_STMT, hStmt_Fetch);
		r = ::SQLFreeHandle(SQL_HANDLE_STMT, hStmt_Insert);
		r = ::SQLFreeHandle(SQL_HANDLE_STMT, hStmt_Update);
		if (hDbc_source != SQL_NULL_HANDLE) 		r = ::SQLDisconnect(hDb_S);
		if (hDbc_target != SQL_NULL_HANDLE) 		r = ::SQLDisconnect(hDb_T);

		r = ::SQLFreeHandle(SQL_HANDLE_DBC, hDb_S);
		r = ::SQLFreeHandle(SQL_HANDLE_DBC, hDb_T);
		r = ::SQLFreeHandle(SQL_HANDLE_ENV, hEnvS);
		r = ::SQLFreeHandle(SQL_HANDLE_ENV, hEnvT);
	}

	hEnv_Source = SQL_NULL_HANDLE;
	hEnv_Target = SQL_NULL_HANDLE;
	hEnv_Source = SQL_NULL_HANDLE;
	hEnv_Target = SQL_NULL_HANDLE;
	hStmt_Fetch = SQL_NULL_HANDLE;
	hStmt_Insert = SQL_NULL_HANDLE;
	hStmt_Update = SQL_NULL_HANDLE;
}

void TK_PRCREC::open(const QString sourceDSN, const QString targetDSN)
{
	QLoggingCategory category("classLibQ");
	m_lpszTargetDSN = targetDSN;
	m_lpszSourceDSN = sourceDSN;
	qDebug(category) << QString("Source - %1[%2]").arg(sourceDSN);
	qDebug(category) << QString("Target - %1[%2]").arg(targetDSN);
}

void TK_PRCREC::createTable()
{
	QLoggingCategory category("classLibQ");
	{
		QScopedPointer<nvTableOracleRdb> tbl(new nvTableOracleRdb(nullptr));
		tbl->initialize("TK_PRCREC", this->m_lpszSourceDSN);
		QString newTbl = tbl->getCreateTableSQL();
		QScopedPointer<qVtExecute> vExec(new qVtExecute(nullptr));
		{
			vExec->initialize(m_lpszTargetDSN, " ", true);
			vExec->setOdbcAttributes(m_OdbcAttributes);
			vExec->ExecuteDirect(newTbl);
		}
	 qDebug(category) << QString("End Create Table %1 ").arg(tableName); 
	}
}

bool TK_PRCREC::prepare()
{
	RETCODE r;
	QString check;
	QLoggingCategory category("classLibQ");
	 qDebug(category) << fetchSql;
	 qDebug(category) << insertSql;
#ifdef UNICODE
	r = SQLPrepare(hStmt_Insert,toSQLTCHAR(insertSql).data(),(SQLINTEGER)insertSql.length()); 
	if (r != SQL_SUCCESS) {
		check = qWarnODBCHandle(SQL_HANDLE_STMT, hStmt_Insert);
		 qCCritical(category) << QString("Prepare Statement-Insert : %1 is %2").arg(insertSql).arg(check);
		return false; 
	}
	r = SQLPrepare(hStmt_Update,toSQLTCHAR(updateSql).data(),(SQLINTEGER)updateSql.length()); 
	if (r != SQL_SUCCESS) {
		check = qWarnODBCHandle(SQL_HANDLE_STMT, hStmt_Update);
		 qCCritical(category) << QString("Prepare Statement-Update : %1 is %2").arg(updateSql).arg(check);
		return false; 
	}
	r = SQLPrepare(hStmt_Fetch,toSQLTCHAR(fetchSql).data(),(SQLINTEGER)fetchSql.length());
	if (r != SQL_SUCCESS) {
		check = qWarnODBCHandle(SQL_HANDLE_STMT, hStmt_Fetch);
		 qCCritical(category) << QString("Prepare Statement-Insert : %1 is %2").arg(fetchSql).arg(check);
		return false; 
	}
#else
	QByteArray queryI8 = insertSql.toUtf8();
	r = SQLPrepare(insert_hStmt,SQLCHAR*)queryI8.data(),(SQLINTEGER)queryI8.length());
	QByteArray queryU8 = fetchSql.toUtf8();
	r = SQLPrepare(hStmt_Fetch,(SQLCHAR*)queryU8.data(),(SQLINTEGER)queryU8.length());
#endif
	return true;

}

void TK_PRCREC::prepareTargetTable()
{
	QLoggingCategory category("classLibQ");
	if (this->m_ReplicationOption == ReplicationOption::BulkCopy)
	{
		QScopedPointer<qVtExecute> execSql(new qVtExecute(nullptr));
		DropOption option = this->m_dropOption;
		switch (option)
		{
			case DropOption::DeleteFromTable:
			{
				QLoggingCategory category("classLibQ");
				execSql->initialize(this->m_lpszTargetDSN, "delete from TK_PRCREC", true);
				execSql->setOdbcAttributes(this->m_OdbcAttributes);
				execSql->ExecuteDirect("delete from TK_PRCREC");
			}break;
			case DropOption::TruncateTable:
			{
				execSql->initialize(this->m_lpszTargetDSN, "truncate table TK_PRCREC", true);
				execSql->setOdbcAttributes(this->m_OdbcAttributes);
				execSql->ExecuteDirect("truncate table TK_PRCREC");
			}break;
			case DropOption::DropTable:
			{
				execSql->initialize(this->m_lpszTargetDSN, "drop table TK_PRCREC", true);
				execSql->setOdbcAttributes(this->m_OdbcAttributes);
				execSql->ExecuteDirect("drop table TK_PRCREC");
				createTable();
			}break;
		}
	}
}

bool TK_PRCREC::bindColumn()
{
	QLoggingCategory category("classLibQ");
	RETCODE r;
	bool isValid=true;
		 qDebug(category) << " Bindings: Ordinal [1] Type: 5 Buffer Size: 2 FieldName: DB_ID ";
		r = ::SQLBindCol(hStmt_Fetch, 1, 5, DB_ID.data(), 2, &cbDB_ID);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Bindings: Ordinal [2] Type: 93 Buffer Size: 23 FieldName: NVTIMESTAMP ";
		r = ::SQLBindCol(hStmt_Fetch, 2, 93, NVTIMESTAMP.data(), 23, &cbNVTIMESTAMP);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Bindings: Ordinal [3] Type: 5 Buffer Size: 2 FieldName: AREA ";
		r = ::SQLBindCol(hStmt_Fetch, 3, 5, AREA.data(), 2, &cbAREA);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Bindings: Ordinal [4] Type: 4 Buffer Size: 4 FieldName: PAGE ";
		r = ::SQLBindCol(hStmt_Fetch, 4, 4, PAGE.data(), 4, &cbPAGE);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Bindings: Ordinal [5] Type: 5 Buffer Size: 2 FieldName: LINE ";
		r = ::SQLBindCol(hStmt_Fetch, 5, 5, LINE.data(), 2, &cbLINE);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Bindings: Ordinal [6] Type: 1 Buffer Size: 2 FieldName: TK_PRCUOM ";
		r = ::SQLBindCol(hStmt_Fetch, 6, 1, TK_PRCUOM.data(), 2, &cbTK_PRCUOM);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Bindings: Ordinal [7] Type: 5 Buffer Size: 2 FieldName: TK_PRCRND ";
		r = ::SQLBindCol(hStmt_Fetch, 7, 5, TK_PRCRND.data(), 2, &cbTK_PRCRND);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
	return isValid;
}

bool TK_PRCREC::bindParameter()
{
	QLoggingCategory category("classLibQ");
	RETCODE r;
	bool isValid=true;
	{
		 qDebug(category) << " Parameters: Ordinal [1] Type: 5 Buffer Size: 2 FieldName: DB_ID ";
		r = SQLBindParameter(hStmt_Insert, 1, SQL_PARAM_INPUT, SQL_C_DEFAULT, 5, 0, 0, (SQLPOINTER)DB_ID.constData(), 0, &cbDB_ID);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Parameters: Ordinal [2] Type: 93 Buffer Size: 23 FieldName: NVTIMESTAMP ";
		r = SQLBindParameter(hStmt_Insert, 2, SQL_PARAM_INPUT, SQL_C_DEFAULT, 93, 23, 0, (SQLPOINTER)NVTIMESTAMP.constData(), 0, &cbNVTIMESTAMP);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Parameters: Ordinal [3] Type: 5 Buffer Size: 2 FieldName: AREA ";
		r = SQLBindParameter(hStmt_Insert, 3, SQL_PARAM_INPUT, SQL_C_DEFAULT, 5, 0, 0, (SQLPOINTER)AREA.constData(), 0, &cbAREA);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Parameters: Ordinal [4] Type: 4 Buffer Size: 4 FieldName: PAGE ";
		r = SQLBindParameter(hStmt_Insert, 4, SQL_PARAM_INPUT, SQL_C_DEFAULT, 4, 0, 0, (SQLPOINTER)PAGE.constData(), 0, &cbPAGE);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Parameters: Ordinal [5] Type: 5 Buffer Size: 2 FieldName: LINE ";
		r = SQLBindParameter(hStmt_Insert, 5, SQL_PARAM_INPUT, SQL_C_DEFAULT, 5, 0, 0, (SQLPOINTER)LINE.constData(), 0, &cbLINE);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Parameters: Ordinal [6] Type: 1 Buffer Size: 2 FieldName: TK_PRCUOM ";
		r = SQLBindParameter(hStmt_Insert, 6, SQL_PARAM_INPUT, SQL_C_DEFAULT, 1, 2, 0, (SQLPOINTER)TK_PRCUOM.constData(), 0, &cbTK_PRCUOM);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Parameters: Ordinal [7] Type: 5 Buffer Size: 2 FieldName: TK_PRCRND ";
		r = SQLBindParameter(hStmt_Insert, 7, SQL_PARAM_INPUT, SQL_C_DEFAULT, 5, 0, 0, (SQLPOINTER)TK_PRCRND.constData(), 0, &cbTK_PRCRND);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
	}
	if (m_ReplicationOption == ReplicationOption::NetChange)
	{
		r = SQLBindParameter(hStmt_Update, 8, SQL_PARAM_INPUT, SQL_C_DEFAULT, 3, 0, 0, (SQLPOINTER)AREA.constData(), 0, &cbAREA);
		if (r == SQL_SUCCESS) { isValid=true; }
		r = SQLBindParameter(hStmt_Update, 9, SQL_PARAM_INPUT, SQL_C_DEFAULT, 4, 0, 0, (SQLPOINTER)PAGE.constData(), 0, &cbPAGE);
		if (r == SQL_SUCCESS) { isValid=true; }
		r = SQLBindParameter(hStmt_Update, 10, SQL_PARAM_INPUT, SQL_C_DEFAULT, 5, 0, 0, (SQLPOINTER)LINE.constData(), 0, &cbLINE);
		if (r == SQL_SUCCESS) { isValid=true; }
	// TK_PRCREC is a well formed table for eNVy Replication 
		 qDebug(category) << " Parameters: Ordinal [3] 00 00 FieldName: AREA ";
		 qDebug(category) << " Parameters: Ordinal [4] 00 00  FieldName: PAGE ";
		 qDebug(category) << " Parameters: Ordinal [5] 00 00 FieldName:  LINE ";
	} // 	if (m_ReplicationOption == ReplicationOption::NetChange)
	return isValid;
}

bool TK_PRCREC::process(int rowSize)
{
	QLoggingCategory category("classLibQ");
	initOdbcAttributes();
	connect(Source);
	connect(Target);
	initialize();
	prepareTargetTable();
	prepare();
	bindColumn();
	bindParameter();
	copyTable();
	close();
	return false;
}

void TK_PRCREC::copyTable()
{
	QLoggingCategory category("classLibQ");
	RETCODE r;
	QString check;
	r = SQLExecute(hStmt_Fetch);
		if (bIsAbort) {
			emit aborted(tableName, rowsFetched, rowsInserted, rowsUpdated);
			return;
		}
		while((r = SQLFetch(hStmt_Fetch)) != SQL_NO_DATA) {
		if (r != SQL_SUCCESS) {
			check = qWarnODBCHandle(SQL_HANDLE_STMT, hStmt_Fetch);
			qCCritical(category) << QString("SqlFetch - Error : %1 is %2").arg(fetchSql).arg(check);
			return;
		} 
		rowsFetched++;
		if (m_ReplicationOption == ReplicationOption::BulkCopy)
		{
			r = SQLExecute(hStmt_Insert);
			if (r == SQL_ERROR) {
				check = qWarnODBCHandle(SQL_HANDLE_STMT, hStmt_Insert);
				 qCCritical(category) << QString("SqlExecute:Insert - Error : %1 is %2").arg(insertSql).arg(check);
				return;
			}
			rowsInserted++;
			if ((rowsFetched % updateInterval) == 0) {
				qCInfo(category) << QString("[%1.%2]	Insertion: %3	Updates : %4	Fetched : %5").arg(profileName).arg(tableName).arg(rowsInserted).arg(rowsUpdated).arg(rowsFetched);
				emit updateStatusFetched(profileName, tableName, rowsFetched,rowsInserted,rowsUpdated);
			}
			if (m_ReplicationOption == ReplicationOption::NetChange)
			{
			r = SQLExecute(hStmt_Update);
			if (r != SQL_SUCCESS) {
				check = qWarnODBCHandle(SQL_HANDLE_STMT, hStmt_Update);
				 qCInfo(category)  << QString("SqlExecute:Update - Error : %1 is %2").arg(updateSql).arg(check);
				r = SQLExecute(hStmt_Insert);
				if (r != SQL_SUCCESS) {
					check = qWarnODBCHandle(SQL_HANDLE_STMT, hStmt_Insert);
					 qCritical(category) << QString("SqlExecute:Insert - Error : %1 is %2").arg(insertSql).arg(check);
					return;
				}
				else 	rowsInserted++;
				}
				else	rowsUpdated++;
			}
			emit updateStatusFetched(profileName, tableName, rowsFetched,rowsInserted,rowsUpdated);
		}
	} 
qCInfo(category) << QString("[%1.%2]	Insertion: %3	Updates : %4	Fetched : %5").arg(profileName).arg(tableName).arg(rowsInserted).arg(rowsUpdated).arg(rowsFetched);
}

void TK_PRCREC::connect(connectionHandle connectionSource)
{

	QLoggingCategory category("classLibQ");
	RETCODE r;

	bool isValid = false;
	HWND	hWnd = nullptr;
	hWnd = ::GetDesktopWindow(); 
	SQLSMALLINT nResult = 0;

	SQLSMALLINT cb;
	UWORD wConnectOption = SQL_DRIVER_COMPLETE; //SQL_DRIVER_NOPROMPT;
	QVarLengthArray<SQLTCHAR> connOut(1024);
	memset(connOut.data(), 0, connOut.size() * sizeof(SQLTCHAR));

	switch (connectionSource)
	{
		case Source:
			{// environment
				SQLHANDLE hEnv = SQL_NULL_HANDLE;
				SQLHANDLE hDbc = SQL_NULL_HANDLE;
				r = ::SQLAllocHandle(SQL_HANDLE_ENV, SQL_NULL_HANDLE, &hEnv);
				if (r == SQL_SUCCESS) isValid = true;

				foreach(nOdbcAttributesClass * k, this->m_OdbcAttributes_Map)
				{
					if (k->attributeType == enumAttributeType::hEnv)
					{
						r = ::SQLSetEnvAttr(hEnv, (SQLINTEGER) k->odbcKey, (SQLPOINTER)k->odbcValue, 0);
						if (r == SQL_SUCCESS) isValid = true;
					}
				}
				hEnv_Source = hEnv;

				r = SQLAllocHandle(SQL_HANDLE_DBC, hEnv, &hDbc);
				if (r == SQL_SUCCESS) isValid = true;
				foreach(nOdbcAttributesClass * k, this->m_OdbcAttributes_Map)
				{
					if (k->attributeType == enumAttributeType::hDbc)
					{
					r = ::SQLSetConnectAttr(hDbc, k->odbcKey, (SQLPOINTER)k->odbcValue, 0);
					if (k->odbcKey == SQL_ATTR_CONNECTION_POOLING && k->odbcValue == SQL_CP_ONE_PER_DRIVER) wConnectOption = SQL_DRIVER_NOPROMPT;
					if (k->odbcKey == SQL_ATTR_CONNECTION_POOLING && k->odbcValue == SQL_CP_ONE_PER_HENV) wConnectOption = SQL_DRIVER_NOPROMPT;
					if (k->odbcKey == SQL_ATTR_CONNECTION_POOLING && k->odbcValue == SQL_CP_DRIVER_AWARE) wConnectOption = SQL_DRIVER_NOPROMPT;
					if (r == SQL_SUCCESS) isValid = true;
					}
				}
				hDbc_source = hDbc;
				if (isValid)
				{
					r = ::SQLDriverConnect(
						hDbc,
						hWnd,
#ifdef UNICODE
						toSQLTCHAR(m_lpszSourceDSN).data(),
#else
						(SQLCHAR*)dsnSource.toUtf8().data(),
#endif
						(SQLSMALLINT)m_lpszSourceDSN.length(),
						connOut.data(),
						1024,
						&cb, 
						wConnectOption); 
					int colSize = cb / sizeof(SQLTCHAR);
					if (r != SQL_SUCCESS && r != SQL_SUCCESS_WITH_INFO)
					{
						QString check = qWarnODBCHandle(SQL_HANDLE_DBC, hDbc);
						qCritical(category) <<  check;
						m_bIsOpen = false;
					}
					m_bIsOpen = true;
				}
			} break;
		case Target:
			{
				SQLHANDLE hEnv = SQL_NULL_HANDLE;
				SQLHANDLE hDbc = SQL_NULL_HANDLE;
				r = ::SQLAllocHandle(SQL_HANDLE_ENV, SQL_NULL_HANDLE, &hEnv);
				if (r == SQL_SUCCESS) isValid = true;

				foreach(nOdbcAttributesClass * k, this->m_OdbcAttributes_Map)
				{
					if (k->attributeType == enumAttributeType::hEnv)
					{
						r = ::SQLSetEnvAttr(hEnv, (SQLINTEGER) k->odbcKey, (SQLPOINTER)k->odbcValue, 0);
						if (r == SQL_SUCCESS) isValid = true;
					}
				}
				hEnv_Target = hEnv;

				r = SQLAllocHandle(SQL_HANDLE_DBC, hEnv, &hDbc);
				if (r == SQL_SUCCESS) isValid = true;
				foreach(nOdbcAttributesClass * k, this->m_OdbcAttributes_Map)
				{
				if (k->attributeType == enumAttributeType::hDbc)
					{
					r = ::SQLSetConnectAttr(hDbc, k->odbcKey, (SQLPOINTER)k->odbcValue, 0);
					if (k->odbcKey == SQL_ATTR_CONNECTION_POOLING && k->odbcValue == SQL_CP_ONE_PER_DRIVER) wConnectOption = SQL_DRIVER_NOPROMPT;
					if (k->odbcKey == SQL_ATTR_CONNECTION_POOLING && k->odbcValue == SQL_CP_ONE_PER_HENV) wConnectOption = SQL_DRIVER_NOPROMPT;
					if (k->odbcKey == SQL_ATTR_CONNECTION_POOLING && k->odbcValue == SQL_CP_DRIVER_AWARE) wConnectOption = SQL_DRIVER_NOPROMPT;
					if (r == SQL_SUCCESS) isValid = true;
					}
				}
				hDbc_target = hDbc;
				if (isValid) {
					r = ::SQLDriverConnect(
						hDbc,
						hWnd,
#ifdef UNICODE
						toSQLTCHAR(m_lpszTargetDSN).data(),
#else
						(SQLCHAR*)m_lpszTargetDSN.toUtf8().data(),
#endif
						(SQLSMALLINT)m_lpszTargetDSN.length(),
						connOut.data(),
						1024,
						&cb, 
						wConnectOption); 
						int colSize = cb / sizeof(SQLTCHAR);
					if (r != SQL_SUCCESS && r != SQL_SUCCESS_WITH_INFO)
						{
							QString check = qWarnODBCHandle(SQL_HANDLE_DBC, hDbc);
							qCritical(category) <<  check;
							m_bIsOpen = false;
						}
							m_bIsOpen = true;
					}
			} break;
			default: break;
	}
}
TK_LOTHSHSET::TK_LOTHSHSET(QObject * parent) : QObject(parent) 
,tableName("TK_LOTHSHSET")
,m_dropOption(DropOption::DropTable) { 
	numRowsFetched = 0;
}

#pragma region ~CTOR TK_LOTHSHSET 
TK_LOTHSHSET::~TK_LOTHSHSET() { 

#pragma region Buffers - Clear 
	DB_ID.clear();
	NVTIMESTAMP.clear();
	OAREA.clear();
	OPAGE.clear();
	OLINE.clear();
	MAREA.clear();
	MPAGE.clear();
	MLINE.clear();
#pragma endregion Buffers - Clear 
}
#pragma endregion Destructor_TK_LOTHSHSET

// begin method functions
void TK_LOTHSHSET::setAbortFlag() { 
	QLoggingCategory category("classLibQ");
	qCInfo(category) << "isAbort was set to True";
	bIsAbort = true;
}

void TK_LOTHSHSET::run() { 
	process(1);
	QLoggingCategory category("classLibQ");
	qDebug(category) << "Entered;";
}

void	TK_LOTHSHSET::initOdbcAttributes()
{
	QLoggingCategory category("classLibQ");
	this->setProfileName(profileName);
	qDebug(category) << "Processing - TRKDB100"; 
	m_OdbcAttributesList = m_OdbcAttributes.split(","); 
	foreach(QString m, m_OdbcAttributesList)
	{
		QStringList keyValue = m.split("=");
		nOdbcAttributesClass * oM = new nOdbcAttributesClass(this);
		if (oM->loadToOdbc(keyValue.value(0), keyValue.value(1)))
		{
			m_OdbcAttributes_Map.insert(oM->odbcKey, oM);
		}
	}
}
void	TK_LOTHSHSET::initialize()
{
	QLoggingCategory category("classLibQ");
	RETCODE r;
	this->setProfileName(profileName);
	qDebug(category) << "Processing - TRKDB100"; 
//SQL Statements
//--------------------------------------------------

#pragma region Sql Statements_TK_LOTHSHSET

	fetchSql = "select  DB_ID, NVTIMESTAMP, OAREA, OPAGE, OLINE, MAREA, MPAGE, MLINE from TK_LOTHSHSET";
		if (m_ReplicationOption == ReplicationOption::NetChange)
		{
			fetchSql.append(" p1, nv_transfers p2 WHERE  p2.table_name = 'TK_LOTHSHSET' AND p1.nvtimestamp > p2.last_completed");
		}
	insertSql = "insert into TK_LOTHSHSET ( PLANT_CODE, NVTIMESTAMP, OAREA, OPAGE, OLINE, MAREA, MPAGE, MLINE ) values ( ?, ?, ?, ?, ?, ?, ?, ?)";
	updateSql = "update TK_LOTHSHSET set  PLANT_CODE = ?, NVTIMESTAMP = ?, OAREA = ?, OPAGE = ?, OLINE = ?, MAREA = ?, MPAGE = ?, MLINE = ?  where area = ? and page = ? line = ? ";

	qDebug(category) << "insertSQL - insert into TK_LOTHSHSET ( PLANT_CODE, NVTIMESTAMP, OAREA, OPAGE, OLINE, MAREA, MPAGE, MLINE ) values ( ?, ?, ?, ?, ?, ?, ?, ?)";
	qDebug(category) << "fetchSQL - select  DB_ID, NVTIMESTAMP, OAREA, OPAGE, OLINE, MAREA, MPAGE, MLINE from TK_LOTHSHSET";
	qDebug(category) << "unsertSQL - update TK_LOTHSHSET set  PLANT_CODE = ?, NVTIMESTAMP = ?, OAREA = ?, OPAGE = ?, OLINE = ?, MAREA = ?, MPAGE = ?, MLINE = ?  where area = ? and page = ? line = ? ";

#pragma endregion Sql Statements_TK_LOTHSHSET
	SQLHANDLE		insert_hStmt = SQL_NULL_HANDLE;
	SQLHANDLE		fetch_hStmt = SQL_NULL_HANDLE; 
	SQLHANDLE		update_hStmt = SQL_NULL_HANDLE; 
 
	r = ::SQLAllocHandle(SQL_HANDLE_STMT, hDbc_source, &fetch_hStmt);
	if (r != SQL_SUCCESS) {
		 qCCritical(category) << QString("Error  hDbc_Source SQLCode : %1 is %2").arg(QString::number( (long)hDbc_source)).arg(QString::number(r));
		return; 
	}
	r = ::SQLAllocHandle(SQL_HANDLE_STMT, hDbc_target, &insert_hStmt);
	if (r != SQL_SUCCESS) {
		 qCCritical(category) << QString("Error hDbc_Source -SQLCode: %1 is %2").arg(QString::number( (long)hDbc_target)).arg(QString::number(r));
		return; 
	}
	r = ::SQLAllocHandle(SQL_HANDLE_STMT, hDbc_target, &update_hStmt);
	if (r != SQL_SUCCESS) {
		 qCCritical(category) << QString("Error hDbc_Source +SQLCode: %1 is %2").arg(QString::number( (long)hDbc_target)).arg(QString::number(r));
		return; 
	}
 
	hStmt_Fetch = fetch_hStmt;
	hStmt_Insert = insert_hStmt;
	hStmt_Update = update_hStmt;
 
	SQLSetStmtAttr(hStmt_Fetch, SQL_ATTR_USE_BOOKMARKS, (SQLPOINTER)SQL_UB_OFF, 0);
	SQLSetStmtAttr(hStmt_Fetch, SQL_ATTR_ROW_BIND_TYPE, (SQLPOINTER)SQL_BIND_BY_COLUMN, 0);
	SQLSetStmtAttr(hStmt_Fetch, SQL_ATTR_ROW_ARRAY_SIZE, (SQLPOINTER)1, 0);
	SQLSetStmtAttr(hStmt_Fetch, SQL_ATTR_ROWS_FETCHED_PTR, &numRowsFetched, 0);

// Fields used by this class 
// ---------------------------------------------------

#pragma region Resize Fields TK_LOTHSHSET
	qDebug(category) << "Malloc - DB_ID[2]";
	DB_ID.resize(2);
	qDebug(category) << "Malloc - NVTIMESTAMP[23]";
	NVTIMESTAMP.resize(23);
	qDebug(category) << "Malloc - OAREA[2]";
	OAREA.resize(2);
	qDebug(category) << "Malloc - OPAGE[4]";
	OPAGE.resize(4);
	qDebug(category) << "Malloc - OLINE[2]";
	OLINE.resize(2);
	qDebug(category) << "Malloc - MAREA[2]";
	MAREA.resize(2);
	qDebug(category) << "Malloc - MPAGE[4]";
	MPAGE.resize(4);
	qDebug(category) << "Malloc - MLINE[2]";
	MLINE.resize(2);

#pragma endregion Resize Fields TK_LOTHSHSET
}
void TK_LOTHSHSET::close()
{
	QLoggingCategory category("classLibQ");
	if (m_bIsOpen)
	{
	qDebug(category) << "database is Open";
		SQLHANDLE source_hStmt = hStmt_Fetch;
		SQLHANDLE insert_hStmt = hStmt_Insert;
		SQLHANDLE hDb_S = this->hDbc_source;
		SQLHANDLE hDb_T = hDbc_target;
		SQLHANDLE hEnvS = hEnv_Source;
		SQLHANDLE hEnvT = hEnv_Target;
		RETCODE r;

		r = ::SQLFreeHandle(SQL_HANDLE_STMT, hStmt_Fetch);
		r = ::SQLFreeHandle(SQL_HANDLE_STMT, hStmt_Insert);
		r = ::SQLFreeHandle(SQL_HANDLE_STMT, hStmt_Update);
		if (hDbc_source != SQL_NULL_HANDLE) 		r = ::SQLDisconnect(hDb_S);
		if (hDbc_target != SQL_NULL_HANDLE) 		r = ::SQLDisconnect(hDb_T);

		r = ::SQLFreeHandle(SQL_HANDLE_DBC, hDb_S);
		r = ::SQLFreeHandle(SQL_HANDLE_DBC, hDb_T);
		r = ::SQLFreeHandle(SQL_HANDLE_ENV, hEnvS);
		r = ::SQLFreeHandle(SQL_HANDLE_ENV, hEnvT);
	}

	hEnv_Source = SQL_NULL_HANDLE;
	hEnv_Target = SQL_NULL_HANDLE;
	hEnv_Source = SQL_NULL_HANDLE;
	hEnv_Target = SQL_NULL_HANDLE;
	hStmt_Fetch = SQL_NULL_HANDLE;
	hStmt_Insert = SQL_NULL_HANDLE;
	hStmt_Update = SQL_NULL_HANDLE;
}

void TK_LOTHSHSET::open(const QString sourceDSN, const QString targetDSN)
{
	QLoggingCategory category("classLibQ");
	m_lpszTargetDSN = targetDSN;
	m_lpszSourceDSN = sourceDSN;
	qDebug(category) << QString("Source - %1[%2]").arg(sourceDSN);
	qDebug(category) << QString("Target - %1[%2]").arg(targetDSN);
}

void TK_LOTHSHSET::createTable()
{
	QLoggingCategory category("classLibQ");
	{
		QScopedPointer<nvTableOracleRdb> tbl(new nvTableOracleRdb(nullptr));
		tbl->initialize("TK_LOTHSHSET", this->m_lpszSourceDSN);
		QString newTbl = tbl->getCreateTableSQL();
		QScopedPointer<qVtExecute> vExec(new qVtExecute(nullptr));
		{
			vExec->initialize(m_lpszTargetDSN, " ", true);
			vExec->setOdbcAttributes(m_OdbcAttributes);
			vExec->ExecuteDirect(newTbl);
		}
	 qDebug(category) << QString("End Create Table %1 ").arg(tableName); 
	}
}

bool TK_LOTHSHSET::prepare()
{
	RETCODE r;
	QString check;
	QLoggingCategory category("classLibQ");
	 qDebug(category) << fetchSql;
	 qDebug(category) << insertSql;
#ifdef UNICODE
	r = SQLPrepare(hStmt_Insert,toSQLTCHAR(insertSql).data(),(SQLINTEGER)insertSql.length()); 
	if (r != SQL_SUCCESS) {
		check = qWarnODBCHandle(SQL_HANDLE_STMT, hStmt_Insert);
		 qCCritical(category) << QString("Prepare Statement-Insert : %1 is %2").arg(insertSql).arg(check);
		return false; 
	}
	r = SQLPrepare(hStmt_Update,toSQLTCHAR(updateSql).data(),(SQLINTEGER)updateSql.length()); 
	if (r != SQL_SUCCESS) {
		check = qWarnODBCHandle(SQL_HANDLE_STMT, hStmt_Update);
		 qCCritical(category) << QString("Prepare Statement-Update : %1 is %2").arg(updateSql).arg(check);
		return false; 
	}
	r = SQLPrepare(hStmt_Fetch,toSQLTCHAR(fetchSql).data(),(SQLINTEGER)fetchSql.length());
	if (r != SQL_SUCCESS) {
		check = qWarnODBCHandle(SQL_HANDLE_STMT, hStmt_Fetch);
		 qCCritical(category) << QString("Prepare Statement-Insert : %1 is %2").arg(fetchSql).arg(check);
		return false; 
	}
#else
	QByteArray queryI8 = insertSql.toUtf8();
	r = SQLPrepare(insert_hStmt,SQLCHAR*)queryI8.data(),(SQLINTEGER)queryI8.length());
	QByteArray queryU8 = fetchSql.toUtf8();
	r = SQLPrepare(hStmt_Fetch,(SQLCHAR*)queryU8.data(),(SQLINTEGER)queryU8.length());
#endif
	return true;

}

void TK_LOTHSHSET::prepareTargetTable()
{
	QLoggingCategory category("classLibQ");
	if (this->m_ReplicationOption == ReplicationOption::BulkCopy)
	{
		QScopedPointer<qVtExecute> execSql(new qVtExecute(nullptr));
		DropOption option = this->m_dropOption;
		switch (option)
		{
			case DropOption::DeleteFromTable:
			{
				QLoggingCategory category("classLibQ");
				execSql->initialize(this->m_lpszTargetDSN, "delete from TK_LOTHSHSET", true);
				execSql->setOdbcAttributes(this->m_OdbcAttributes);
				execSql->ExecuteDirect("delete from TK_LOTHSHSET");
			}break;
			case DropOption::TruncateTable:
			{
				execSql->initialize(this->m_lpszTargetDSN, "truncate table TK_LOTHSHSET", true);
				execSql->setOdbcAttributes(this->m_OdbcAttributes);
				execSql->ExecuteDirect("truncate table TK_LOTHSHSET");
			}break;
			case DropOption::DropTable:
			{
				execSql->initialize(this->m_lpszTargetDSN, "drop table TK_LOTHSHSET", true);
				execSql->setOdbcAttributes(this->m_OdbcAttributes);
				execSql->ExecuteDirect("drop table TK_LOTHSHSET");
				createTable();
			}break;
		}
	}
}

bool TK_LOTHSHSET::bindColumn()
{
	QLoggingCategory category("classLibQ");
	RETCODE r;
	bool isValid=true;
		 qDebug(category) << " Bindings: Ordinal [1] Type: 5 Buffer Size: 2 FieldName: DB_ID ";
		r = ::SQLBindCol(hStmt_Fetch, 1, 5, DB_ID.data(), 2, &cbDB_ID);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Bindings: Ordinal [2] Type: 93 Buffer Size: 23 FieldName: NVTIMESTAMP ";
		r = ::SQLBindCol(hStmt_Fetch, 2, 93, NVTIMESTAMP.data(), 23, &cbNVTIMESTAMP);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Bindings: Ordinal [3] Type: 5 Buffer Size: 2 FieldName: OAREA ";
		r = ::SQLBindCol(hStmt_Fetch, 3, 5, OAREA.data(), 2, &cbOAREA);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Bindings: Ordinal [4] Type: 4 Buffer Size: 4 FieldName: OPAGE ";
		r = ::SQLBindCol(hStmt_Fetch, 4, 4, OPAGE.data(), 4, &cbOPAGE);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Bindings: Ordinal [5] Type: 5 Buffer Size: 2 FieldName: OLINE ";
		r = ::SQLBindCol(hStmt_Fetch, 5, 5, OLINE.data(), 2, &cbOLINE);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Bindings: Ordinal [6] Type: 5 Buffer Size: 2 FieldName: MAREA ";
		r = ::SQLBindCol(hStmt_Fetch, 6, 5, MAREA.data(), 2, &cbMAREA);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Bindings: Ordinal [7] Type: 4 Buffer Size: 4 FieldName: MPAGE ";
		r = ::SQLBindCol(hStmt_Fetch, 7, 4, MPAGE.data(), 4, &cbMPAGE);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Bindings: Ordinal [8] Type: 5 Buffer Size: 2 FieldName: MLINE ";
		r = ::SQLBindCol(hStmt_Fetch, 8, 5, MLINE.data(), 2, &cbMLINE);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
	return isValid;
}

bool TK_LOTHSHSET::bindParameter()
{
	QLoggingCategory category("classLibQ");
	RETCODE r;
	bool isValid=true;
	{
		 qDebug(category) << " Parameters: Ordinal [1] Type: 5 Buffer Size: 2 FieldName: DB_ID ";
		r = SQLBindParameter(hStmt_Insert, 1, SQL_PARAM_INPUT, SQL_C_DEFAULT, 5, 0, 0, (SQLPOINTER)DB_ID.constData(), 0, &cbDB_ID);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Parameters: Ordinal [2] Type: 93 Buffer Size: 23 FieldName: NVTIMESTAMP ";
		r = SQLBindParameter(hStmt_Insert, 2, SQL_PARAM_INPUT, SQL_C_DEFAULT, 93, 23, 0, (SQLPOINTER)NVTIMESTAMP.constData(), 0, &cbNVTIMESTAMP);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Parameters: Ordinal [3] Type: 5 Buffer Size: 2 FieldName: OAREA ";
		r = SQLBindParameter(hStmt_Insert, 3, SQL_PARAM_INPUT, SQL_C_DEFAULT, 5, 0, 0, (SQLPOINTER)OAREA.constData(), 0, &cbOAREA);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Parameters: Ordinal [4] Type: 4 Buffer Size: 4 FieldName: OPAGE ";
		r = SQLBindParameter(hStmt_Insert, 4, SQL_PARAM_INPUT, SQL_C_DEFAULT, 4, 0, 0, (SQLPOINTER)OPAGE.constData(), 0, &cbOPAGE);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Parameters: Ordinal [5] Type: 5 Buffer Size: 2 FieldName: OLINE ";
		r = SQLBindParameter(hStmt_Insert, 5, SQL_PARAM_INPUT, SQL_C_DEFAULT, 5, 0, 0, (SQLPOINTER)OLINE.constData(), 0, &cbOLINE);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Parameters: Ordinal [6] Type: 5 Buffer Size: 2 FieldName: MAREA ";
		r = SQLBindParameter(hStmt_Insert, 6, SQL_PARAM_INPUT, SQL_C_DEFAULT, 5, 0, 0, (SQLPOINTER)MAREA.constData(), 0, &cbMAREA);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Parameters: Ordinal [7] Type: 4 Buffer Size: 4 FieldName: MPAGE ";
		r = SQLBindParameter(hStmt_Insert, 7, SQL_PARAM_INPUT, SQL_C_DEFAULT, 4, 0, 0, (SQLPOINTER)MPAGE.constData(), 0, &cbMPAGE);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Parameters: Ordinal [8] Type: 5 Buffer Size: 2 FieldName: MLINE ";
		r = SQLBindParameter(hStmt_Insert, 8, SQL_PARAM_INPUT, SQL_C_DEFAULT, 5, 0, 0, (SQLPOINTER)MLINE.constData(), 0, &cbMLINE);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
	}
	if (m_ReplicationOption == ReplicationOption::NetChange)
	{
		r = SQLBindParameter(hStmt_Update, 9, SQL_PARAM_INPUT, SQL_C_DEFAULT, 6, 0, 0, (SQLPOINTER)MAREA.constData(), 0, &cbMAREA);
		if (r == SQL_SUCCESS) { isValid=true; }
		r = SQLBindParameter(hStmt_Update, 10, SQL_PARAM_INPUT, SQL_C_DEFAULT, 7, 0, 0, (SQLPOINTER)MPAGE.constData(), 0, &cbMPAGE);
		if (r == SQL_SUCCESS) { isValid=true; }
		r = SQLBindParameter(hStmt_Update, 11, SQL_PARAM_INPUT, SQL_C_DEFAULT, 8, 0, 0, (SQLPOINTER)MLINE.constData(), 0, &cbMLINE);
		if (r == SQL_SUCCESS) { isValid=true; }
	// TK_LOTHSHSET is a well formed table for eNVy Replication 
		 qDebug(category) << " Parameters: Ordinal [6] 00 00 FieldName: MAREA ";
		 qDebug(category) << " Parameters: Ordinal [7] 00 00  FieldName: MPAGE ";
		 qDebug(category) << " Parameters: Ordinal [8] 00 00 FieldName:  MLINE ";
	} // 	if (m_ReplicationOption == ReplicationOption::NetChange)
	return isValid;
}

bool TK_LOTHSHSET::process(int rowSize)
{
	QLoggingCategory category("classLibQ");
	initOdbcAttributes();
	connect(Source);
	connect(Target);
	initialize();
	prepareTargetTable();
	prepare();
	bindColumn();
	bindParameter();
	copyTable();
	close();
	return false;
}

void TK_LOTHSHSET::copyTable()
{
	QLoggingCategory category("classLibQ");
	RETCODE r;
	QString check;
	r = SQLExecute(hStmt_Fetch);
		if (bIsAbort) {
			emit aborted(tableName, rowsFetched, rowsInserted, rowsUpdated);
			return;
		}
		while((r = SQLFetch(hStmt_Fetch)) != SQL_NO_DATA) {
		if (r != SQL_SUCCESS) {
			check = qWarnODBCHandle(SQL_HANDLE_STMT, hStmt_Fetch);
			qCCritical(category) << QString("SqlFetch - Error : %1 is %2").arg(fetchSql).arg(check);
			return;
		} 
		rowsFetched++;
		if (m_ReplicationOption == ReplicationOption::BulkCopy)
		{
			r = SQLExecute(hStmt_Insert);
			if (r == SQL_ERROR) {
				check = qWarnODBCHandle(SQL_HANDLE_STMT, hStmt_Insert);
				 qCCritical(category) << QString("SqlExecute:Insert - Error : %1 is %2").arg(insertSql).arg(check);
				return;
			}
			rowsInserted++;
			if ((rowsFetched % updateInterval) == 0) {
				qCInfo(category) << QString("[%1.%2]	Insertion: %3	Updates : %4	Fetched : %5").arg(profileName).arg(tableName).arg(rowsInserted).arg(rowsUpdated).arg(rowsFetched);
				emit updateStatusFetched(profileName, tableName, rowsFetched,rowsInserted,rowsUpdated);
			}
			if (m_ReplicationOption == ReplicationOption::NetChange)
			{
			r = SQLExecute(hStmt_Update);
			if (r != SQL_SUCCESS) {
				check = qWarnODBCHandle(SQL_HANDLE_STMT, hStmt_Update);
				 qCInfo(category)  << QString("SqlExecute:Update - Error : %1 is %2").arg(updateSql).arg(check);
				r = SQLExecute(hStmt_Insert);
				if (r != SQL_SUCCESS) {
					check = qWarnODBCHandle(SQL_HANDLE_STMT, hStmt_Insert);
					 qCritical(category) << QString("SqlExecute:Insert - Error : %1 is %2").arg(insertSql).arg(check);
					return;
				}
				else 	rowsInserted++;
				}
				else	rowsUpdated++;
			}
			emit updateStatusFetched(profileName, tableName, rowsFetched,rowsInserted,rowsUpdated);
		}
	} 
qCInfo(category) << QString("[%1.%2]	Insertion: %3	Updates : %4	Fetched : %5").arg(profileName).arg(tableName).arg(rowsInserted).arg(rowsUpdated).arg(rowsFetched);
}

void TK_LOTHSHSET::connect(connectionHandle connectionSource)
{

	QLoggingCategory category("classLibQ");
	RETCODE r;

	bool isValid = false;
	HWND	hWnd = nullptr;
	hWnd = ::GetDesktopWindow(); 
	SQLSMALLINT nResult = 0;

	SQLSMALLINT cb;
	UWORD wConnectOption = SQL_DRIVER_COMPLETE; //SQL_DRIVER_NOPROMPT;
	QVarLengthArray<SQLTCHAR> connOut(1024);
	memset(connOut.data(), 0, connOut.size() * sizeof(SQLTCHAR));

	switch (connectionSource)
	{
		case Source:
			{// environment
				SQLHANDLE hEnv = SQL_NULL_HANDLE;
				SQLHANDLE hDbc = SQL_NULL_HANDLE;
				r = ::SQLAllocHandle(SQL_HANDLE_ENV, SQL_NULL_HANDLE, &hEnv);
				if (r == SQL_SUCCESS) isValid = true;

				foreach(nOdbcAttributesClass * k, this->m_OdbcAttributes_Map)
				{
					if (k->attributeType == enumAttributeType::hEnv)
					{
						r = ::SQLSetEnvAttr(hEnv, (SQLINTEGER) k->odbcKey, (SQLPOINTER)k->odbcValue, 0);
						if (r == SQL_SUCCESS) isValid = true;
					}
				}
				hEnv_Source = hEnv;

				r = SQLAllocHandle(SQL_HANDLE_DBC, hEnv, &hDbc);
				if (r == SQL_SUCCESS) isValid = true;
				foreach(nOdbcAttributesClass * k, this->m_OdbcAttributes_Map)
				{
					if (k->attributeType == enumAttributeType::hDbc)
					{
					r = ::SQLSetConnectAttr(hDbc, k->odbcKey, (SQLPOINTER)k->odbcValue, 0);
					if (k->odbcKey == SQL_ATTR_CONNECTION_POOLING && k->odbcValue == SQL_CP_ONE_PER_DRIVER) wConnectOption = SQL_DRIVER_NOPROMPT;
					if (k->odbcKey == SQL_ATTR_CONNECTION_POOLING && k->odbcValue == SQL_CP_ONE_PER_HENV) wConnectOption = SQL_DRIVER_NOPROMPT;
					if (k->odbcKey == SQL_ATTR_CONNECTION_POOLING && k->odbcValue == SQL_CP_DRIVER_AWARE) wConnectOption = SQL_DRIVER_NOPROMPT;
					if (r == SQL_SUCCESS) isValid = true;
					}
				}
				hDbc_source = hDbc;
				if (isValid)
				{
					r = ::SQLDriverConnect(
						hDbc,
						hWnd,
#ifdef UNICODE
						toSQLTCHAR(m_lpszSourceDSN).data(),
#else
						(SQLCHAR*)dsnSource.toUtf8().data(),
#endif
						(SQLSMALLINT)m_lpszSourceDSN.length(),
						connOut.data(),
						1024,
						&cb, 
						wConnectOption); 
					int colSize = cb / sizeof(SQLTCHAR);
					if (r != SQL_SUCCESS && r != SQL_SUCCESS_WITH_INFO)
					{
						QString check = qWarnODBCHandle(SQL_HANDLE_DBC, hDbc);
						qCritical(category) <<  check;
						m_bIsOpen = false;
					}
					m_bIsOpen = true;
				}
			} break;
		case Target:
			{
				SQLHANDLE hEnv = SQL_NULL_HANDLE;
				SQLHANDLE hDbc = SQL_NULL_HANDLE;
				r = ::SQLAllocHandle(SQL_HANDLE_ENV, SQL_NULL_HANDLE, &hEnv);
				if (r == SQL_SUCCESS) isValid = true;

				foreach(nOdbcAttributesClass * k, this->m_OdbcAttributes_Map)
				{
					if (k->attributeType == enumAttributeType::hEnv)
					{
						r = ::SQLSetEnvAttr(hEnv, (SQLINTEGER) k->odbcKey, (SQLPOINTER)k->odbcValue, 0);
						if (r == SQL_SUCCESS) isValid = true;
					}
				}
				hEnv_Target = hEnv;

				r = SQLAllocHandle(SQL_HANDLE_DBC, hEnv, &hDbc);
				if (r == SQL_SUCCESS) isValid = true;
				foreach(nOdbcAttributesClass * k, this->m_OdbcAttributes_Map)
				{
				if (k->attributeType == enumAttributeType::hDbc)
					{
					r = ::SQLSetConnectAttr(hDbc, k->odbcKey, (SQLPOINTER)k->odbcValue, 0);
					if (k->odbcKey == SQL_ATTR_CONNECTION_POOLING && k->odbcValue == SQL_CP_ONE_PER_DRIVER) wConnectOption = SQL_DRIVER_NOPROMPT;
					if (k->odbcKey == SQL_ATTR_CONNECTION_POOLING && k->odbcValue == SQL_CP_ONE_PER_HENV) wConnectOption = SQL_DRIVER_NOPROMPT;
					if (k->odbcKey == SQL_ATTR_CONNECTION_POOLING && k->odbcValue == SQL_CP_DRIVER_AWARE) wConnectOption = SQL_DRIVER_NOPROMPT;
					if (r == SQL_SUCCESS) isValid = true;
					}
				}
				hDbc_target = hDbc;
				if (isValid) {
					r = ::SQLDriverConnect(
						hDbc,
						hWnd,
#ifdef UNICODE
						toSQLTCHAR(m_lpszTargetDSN).data(),
#else
						(SQLCHAR*)m_lpszTargetDSN.toUtf8().data(),
#endif
						(SQLSMALLINT)m_lpszTargetDSN.length(),
						connOut.data(),
						1024,
						&cb, 
						wConnectOption); 
						int colSize = cb / sizeof(SQLTCHAR);
					if (r != SQL_SUCCESS && r != SQL_SUCCESS_WITH_INFO)
						{
							QString check = qWarnODBCHandle(SQL_HANDLE_DBC, hDbc);
							qCritical(category) <<  check;
							m_bIsOpen = false;
						}
							m_bIsOpen = true;
					}
			} break;
			default: break;
	}
}
TK_PRTLTFSET::TK_PRTLTFSET(QObject * parent) : QObject(parent) 
,tableName("TK_PRTLTFSET")
,m_dropOption(DropOption::DropTable) { 
	numRowsFetched = 0;
}

#pragma region ~CTOR TK_PRTLTFSET 
TK_PRTLTFSET::~TK_PRTLTFSET() { 

#pragma region Buffers - Clear 
	DB_ID.clear();
	NVTIMESTAMP.clear();
	OAREA.clear();
	OPAGE.clear();
	OLINE.clear();
	MAREA.clear();
	MPAGE.clear();
	MLINE.clear();
#pragma endregion Buffers - Clear 
}
#pragma endregion Destructor_TK_PRTLTFSET

// begin method functions
void TK_PRTLTFSET::setAbortFlag() { 
	QLoggingCategory category("classLibQ");
	qCInfo(category) << "isAbort was set to True";
	bIsAbort = true;
}

void TK_PRTLTFSET::run() { 
	process(1);
	QLoggingCategory category("classLibQ");
	qDebug(category) << "Entered;";
}

void	TK_PRTLTFSET::initOdbcAttributes()
{
	QLoggingCategory category("classLibQ");
	this->setProfileName(profileName);
	qDebug(category) << "Processing - TRKDB100"; 
	m_OdbcAttributesList = m_OdbcAttributes.split(","); 
	foreach(QString m, m_OdbcAttributesList)
	{
		QStringList keyValue = m.split("=");
		nOdbcAttributesClass * oM = new nOdbcAttributesClass(this);
		if (oM->loadToOdbc(keyValue.value(0), keyValue.value(1)))
		{
			m_OdbcAttributes_Map.insert(oM->odbcKey, oM);
		}
	}
}
void	TK_PRTLTFSET::initialize()
{
	QLoggingCategory category("classLibQ");
	RETCODE r;
	this->setProfileName(profileName);
	qDebug(category) << "Processing - TRKDB100"; 
//SQL Statements
//--------------------------------------------------

#pragma region Sql Statements_TK_PRTLTFSET

	fetchSql = "select  DB_ID, NVTIMESTAMP, OAREA, OPAGE, OLINE, MAREA, MPAGE, MLINE from TK_PRTLTFSET";
		if (m_ReplicationOption == ReplicationOption::NetChange)
		{
			fetchSql.append(" p1, nv_transfers p2 WHERE  p2.table_name = 'TK_PRTLTFSET' AND p1.nvtimestamp > p2.last_completed");
		}
	insertSql = "insert into TK_PRTLTFSET ( PLANT_CODE, NVTIMESTAMP, OAREA, OPAGE, OLINE, MAREA, MPAGE, MLINE ) values ( ?, ?, ?, ?, ?, ?, ?, ?)";
	updateSql = "update TK_PRTLTFSET set  PLANT_CODE = ?, NVTIMESTAMP = ?, OAREA = ?, OPAGE = ?, OLINE = ?, MAREA = ?, MPAGE = ?, MLINE = ?  where area = ? and page = ? line = ? ";

	qDebug(category) << "insertSQL - insert into TK_PRTLTFSET ( PLANT_CODE, NVTIMESTAMP, OAREA, OPAGE, OLINE, MAREA, MPAGE, MLINE ) values ( ?, ?, ?, ?, ?, ?, ?, ?)";
	qDebug(category) << "fetchSQL - select  DB_ID, NVTIMESTAMP, OAREA, OPAGE, OLINE, MAREA, MPAGE, MLINE from TK_PRTLTFSET";
	qDebug(category) << "unsertSQL - update TK_PRTLTFSET set  PLANT_CODE = ?, NVTIMESTAMP = ?, OAREA = ?, OPAGE = ?, OLINE = ?, MAREA = ?, MPAGE = ?, MLINE = ?  where area = ? and page = ? line = ? ";

#pragma endregion Sql Statements_TK_PRTLTFSET
	SQLHANDLE		insert_hStmt = SQL_NULL_HANDLE;
	SQLHANDLE		fetch_hStmt = SQL_NULL_HANDLE; 
	SQLHANDLE		update_hStmt = SQL_NULL_HANDLE; 
 
	r = ::SQLAllocHandle(SQL_HANDLE_STMT, hDbc_source, &fetch_hStmt);
	if (r != SQL_SUCCESS) {
		 qCCritical(category) << QString("Error  hDbc_Source SQLCode : %1 is %2").arg(QString::number( (long)hDbc_source)).arg(QString::number(r));
		return; 
	}
	r = ::SQLAllocHandle(SQL_HANDLE_STMT, hDbc_target, &insert_hStmt);
	if (r != SQL_SUCCESS) {
		 qCCritical(category) << QString("Error hDbc_Source -SQLCode: %1 is %2").arg(QString::number( (long)hDbc_target)).arg(QString::number(r));
		return; 
	}
	r = ::SQLAllocHandle(SQL_HANDLE_STMT, hDbc_target, &update_hStmt);
	if (r != SQL_SUCCESS) {
		 qCCritical(category) << QString("Error hDbc_Source +SQLCode: %1 is %2").arg(QString::number( (long)hDbc_target)).arg(QString::number(r));
		return; 
	}
 
	hStmt_Fetch = fetch_hStmt;
	hStmt_Insert = insert_hStmt;
	hStmt_Update = update_hStmt;
 
	SQLSetStmtAttr(hStmt_Fetch, SQL_ATTR_USE_BOOKMARKS, (SQLPOINTER)SQL_UB_OFF, 0);
	SQLSetStmtAttr(hStmt_Fetch, SQL_ATTR_ROW_BIND_TYPE, (SQLPOINTER)SQL_BIND_BY_COLUMN, 0);
	SQLSetStmtAttr(hStmt_Fetch, SQL_ATTR_ROW_ARRAY_SIZE, (SQLPOINTER)1, 0);
	SQLSetStmtAttr(hStmt_Fetch, SQL_ATTR_ROWS_FETCHED_PTR, &numRowsFetched, 0);

// Fields used by this class 
// ---------------------------------------------------

#pragma region Resize Fields TK_PRTLTFSET
	qDebug(category) << "Malloc - DB_ID[2]";
	DB_ID.resize(2);
	qDebug(category) << "Malloc - NVTIMESTAMP[23]";
	NVTIMESTAMP.resize(23);
	qDebug(category) << "Malloc - OAREA[2]";
	OAREA.resize(2);
	qDebug(category) << "Malloc - OPAGE[4]";
	OPAGE.resize(4);
	qDebug(category) << "Malloc - OLINE[2]";
	OLINE.resize(2);
	qDebug(category) << "Malloc - MAREA[2]";
	MAREA.resize(2);
	qDebug(category) << "Malloc - MPAGE[4]";
	MPAGE.resize(4);
	qDebug(category) << "Malloc - MLINE[2]";
	MLINE.resize(2);

#pragma endregion Resize Fields TK_PRTLTFSET
}
void TK_PRTLTFSET::close()
{
	QLoggingCategory category("classLibQ");
	if (m_bIsOpen)
	{
	qDebug(category) << "database is Open";
		SQLHANDLE source_hStmt = hStmt_Fetch;
		SQLHANDLE insert_hStmt = hStmt_Insert;
		SQLHANDLE hDb_S = this->hDbc_source;
		SQLHANDLE hDb_T = hDbc_target;
		SQLHANDLE hEnvS = hEnv_Source;
		SQLHANDLE hEnvT = hEnv_Target;
		RETCODE r;

		r = ::SQLFreeHandle(SQL_HANDLE_STMT, hStmt_Fetch);
		r = ::SQLFreeHandle(SQL_HANDLE_STMT, hStmt_Insert);
		r = ::SQLFreeHandle(SQL_HANDLE_STMT, hStmt_Update);
		if (hDbc_source != SQL_NULL_HANDLE) 		r = ::SQLDisconnect(hDb_S);
		if (hDbc_target != SQL_NULL_HANDLE) 		r = ::SQLDisconnect(hDb_T);

		r = ::SQLFreeHandle(SQL_HANDLE_DBC, hDb_S);
		r = ::SQLFreeHandle(SQL_HANDLE_DBC, hDb_T);
		r = ::SQLFreeHandle(SQL_HANDLE_ENV, hEnvS);
		r = ::SQLFreeHandle(SQL_HANDLE_ENV, hEnvT);
	}

	hEnv_Source = SQL_NULL_HANDLE;
	hEnv_Target = SQL_NULL_HANDLE;
	hEnv_Source = SQL_NULL_HANDLE;
	hEnv_Target = SQL_NULL_HANDLE;
	hStmt_Fetch = SQL_NULL_HANDLE;
	hStmt_Insert = SQL_NULL_HANDLE;
	hStmt_Update = SQL_NULL_HANDLE;
}

void TK_PRTLTFSET::open(const QString sourceDSN, const QString targetDSN)
{
	QLoggingCategory category("classLibQ");
	m_lpszTargetDSN = targetDSN;
	m_lpszSourceDSN = sourceDSN;
	qDebug(category) << QString("Source - %1[%2]").arg(sourceDSN);
	qDebug(category) << QString("Target - %1[%2]").arg(targetDSN);
}

void TK_PRTLTFSET::createTable()
{
	QLoggingCategory category("classLibQ");
	{
		QScopedPointer<nvTableOracleRdb> tbl(new nvTableOracleRdb(nullptr));
		tbl->initialize("TK_PRTLTFSET", this->m_lpszSourceDSN);
		QString newTbl = tbl->getCreateTableSQL();
		QScopedPointer<qVtExecute> vExec(new qVtExecute(nullptr));
		{
			vExec->initialize(m_lpszTargetDSN, " ", true);
			vExec->setOdbcAttributes(m_OdbcAttributes);
			vExec->ExecuteDirect(newTbl);
		}
	 qDebug(category) << QString("End Create Table %1 ").arg(tableName); 
	}
}

bool TK_PRTLTFSET::prepare()
{
	RETCODE r;
	QString check;
	QLoggingCategory category("classLibQ");
	 qDebug(category) << fetchSql;
	 qDebug(category) << insertSql;
#ifdef UNICODE
	r = SQLPrepare(hStmt_Insert,toSQLTCHAR(insertSql).data(),(SQLINTEGER)insertSql.length()); 
	if (r != SQL_SUCCESS) {
		check = qWarnODBCHandle(SQL_HANDLE_STMT, hStmt_Insert);
		 qCCritical(category) << QString("Prepare Statement-Insert : %1 is %2").arg(insertSql).arg(check);
		return false; 
	}
	r = SQLPrepare(hStmt_Update,toSQLTCHAR(updateSql).data(),(SQLINTEGER)updateSql.length()); 
	if (r != SQL_SUCCESS) {
		check = qWarnODBCHandle(SQL_HANDLE_STMT, hStmt_Update);
		 qCCritical(category) << QString("Prepare Statement-Update : %1 is %2").arg(updateSql).arg(check);
		return false; 
	}
	r = SQLPrepare(hStmt_Fetch,toSQLTCHAR(fetchSql).data(),(SQLINTEGER)fetchSql.length());
	if (r != SQL_SUCCESS) {
		check = qWarnODBCHandle(SQL_HANDLE_STMT, hStmt_Fetch);
		 qCCritical(category) << QString("Prepare Statement-Insert : %1 is %2").arg(fetchSql).arg(check);
		return false; 
	}
#else
	QByteArray queryI8 = insertSql.toUtf8();
	r = SQLPrepare(insert_hStmt,SQLCHAR*)queryI8.data(),(SQLINTEGER)queryI8.length());
	QByteArray queryU8 = fetchSql.toUtf8();
	r = SQLPrepare(hStmt_Fetch,(SQLCHAR*)queryU8.data(),(SQLINTEGER)queryU8.length());
#endif
	return true;

}

void TK_PRTLTFSET::prepareTargetTable()
{
	QLoggingCategory category("classLibQ");
	if (this->m_ReplicationOption == ReplicationOption::BulkCopy)
	{
		QScopedPointer<qVtExecute> execSql(new qVtExecute(nullptr));
		DropOption option = this->m_dropOption;
		switch (option)
		{
			case DropOption::DeleteFromTable:
			{
				QLoggingCategory category("classLibQ");
				execSql->initialize(this->m_lpszTargetDSN, "delete from TK_PRTLTFSET", true);
				execSql->setOdbcAttributes(this->m_OdbcAttributes);
				execSql->ExecuteDirect("delete from TK_PRTLTFSET");
			}break;
			case DropOption::TruncateTable:
			{
				execSql->initialize(this->m_lpszTargetDSN, "truncate table TK_PRTLTFSET", true);
				execSql->setOdbcAttributes(this->m_OdbcAttributes);
				execSql->ExecuteDirect("truncate table TK_PRTLTFSET");
			}break;
			case DropOption::DropTable:
			{
				execSql->initialize(this->m_lpszTargetDSN, "drop table TK_PRTLTFSET", true);
				execSql->setOdbcAttributes(this->m_OdbcAttributes);
				execSql->ExecuteDirect("drop table TK_PRTLTFSET");
				createTable();
			}break;
		}
	}
}

bool TK_PRTLTFSET::bindColumn()
{
	QLoggingCategory category("classLibQ");
	RETCODE r;
	bool isValid=true;
		 qDebug(category) << " Bindings: Ordinal [1] Type: 5 Buffer Size: 2 FieldName: DB_ID ";
		r = ::SQLBindCol(hStmt_Fetch, 1, 5, DB_ID.data(), 2, &cbDB_ID);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Bindings: Ordinal [2] Type: 93 Buffer Size: 23 FieldName: NVTIMESTAMP ";
		r = ::SQLBindCol(hStmt_Fetch, 2, 93, NVTIMESTAMP.data(), 23, &cbNVTIMESTAMP);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Bindings: Ordinal [3] Type: 5 Buffer Size: 2 FieldName: OAREA ";
		r = ::SQLBindCol(hStmt_Fetch, 3, 5, OAREA.data(), 2, &cbOAREA);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Bindings: Ordinal [4] Type: 4 Buffer Size: 4 FieldName: OPAGE ";
		r = ::SQLBindCol(hStmt_Fetch, 4, 4, OPAGE.data(), 4, &cbOPAGE);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Bindings: Ordinal [5] Type: 5 Buffer Size: 2 FieldName: OLINE ";
		r = ::SQLBindCol(hStmt_Fetch, 5, 5, OLINE.data(), 2, &cbOLINE);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Bindings: Ordinal [6] Type: 5 Buffer Size: 2 FieldName: MAREA ";
		r = ::SQLBindCol(hStmt_Fetch, 6, 5, MAREA.data(), 2, &cbMAREA);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Bindings: Ordinal [7] Type: 4 Buffer Size: 4 FieldName: MPAGE ";
		r = ::SQLBindCol(hStmt_Fetch, 7, 4, MPAGE.data(), 4, &cbMPAGE);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Bindings: Ordinal [8] Type: 5 Buffer Size: 2 FieldName: MLINE ";
		r = ::SQLBindCol(hStmt_Fetch, 8, 5, MLINE.data(), 2, &cbMLINE);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
	return isValid;
}

bool TK_PRTLTFSET::bindParameter()
{
	QLoggingCategory category("classLibQ");
	RETCODE r;
	bool isValid=true;
	{
		 qDebug(category) << " Parameters: Ordinal [1] Type: 5 Buffer Size: 2 FieldName: DB_ID ";
		r = SQLBindParameter(hStmt_Insert, 1, SQL_PARAM_INPUT, SQL_C_DEFAULT, 5, 0, 0, (SQLPOINTER)DB_ID.constData(), 0, &cbDB_ID);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Parameters: Ordinal [2] Type: 93 Buffer Size: 23 FieldName: NVTIMESTAMP ";
		r = SQLBindParameter(hStmt_Insert, 2, SQL_PARAM_INPUT, SQL_C_DEFAULT, 93, 23, 0, (SQLPOINTER)NVTIMESTAMP.constData(), 0, &cbNVTIMESTAMP);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Parameters: Ordinal [3] Type: 5 Buffer Size: 2 FieldName: OAREA ";
		r = SQLBindParameter(hStmt_Insert, 3, SQL_PARAM_INPUT, SQL_C_DEFAULT, 5, 0, 0, (SQLPOINTER)OAREA.constData(), 0, &cbOAREA);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Parameters: Ordinal [4] Type: 4 Buffer Size: 4 FieldName: OPAGE ";
		r = SQLBindParameter(hStmt_Insert, 4, SQL_PARAM_INPUT, SQL_C_DEFAULT, 4, 0, 0, (SQLPOINTER)OPAGE.constData(), 0, &cbOPAGE);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Parameters: Ordinal [5] Type: 5 Buffer Size: 2 FieldName: OLINE ";
		r = SQLBindParameter(hStmt_Insert, 5, SQL_PARAM_INPUT, SQL_C_DEFAULT, 5, 0, 0, (SQLPOINTER)OLINE.constData(), 0, &cbOLINE);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Parameters: Ordinal [6] Type: 5 Buffer Size: 2 FieldName: MAREA ";
		r = SQLBindParameter(hStmt_Insert, 6, SQL_PARAM_INPUT, SQL_C_DEFAULT, 5, 0, 0, (SQLPOINTER)MAREA.constData(), 0, &cbMAREA);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Parameters: Ordinal [7] Type: 4 Buffer Size: 4 FieldName: MPAGE ";
		r = SQLBindParameter(hStmt_Insert, 7, SQL_PARAM_INPUT, SQL_C_DEFAULT, 4, 0, 0, (SQLPOINTER)MPAGE.constData(), 0, &cbMPAGE);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Parameters: Ordinal [8] Type: 5 Buffer Size: 2 FieldName: MLINE ";
		r = SQLBindParameter(hStmt_Insert, 8, SQL_PARAM_INPUT, SQL_C_DEFAULT, 5, 0, 0, (SQLPOINTER)MLINE.constData(), 0, &cbMLINE);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
	}
	if (m_ReplicationOption == ReplicationOption::NetChange)
	{
		r = SQLBindParameter(hStmt_Update, 9, SQL_PARAM_INPUT, SQL_C_DEFAULT, 6, 0, 0, (SQLPOINTER)MAREA.constData(), 0, &cbMAREA);
		if (r == SQL_SUCCESS) { isValid=true; }
		r = SQLBindParameter(hStmt_Update, 10, SQL_PARAM_INPUT, SQL_C_DEFAULT, 7, 0, 0, (SQLPOINTER)MPAGE.constData(), 0, &cbMPAGE);
		if (r == SQL_SUCCESS) { isValid=true; }
		r = SQLBindParameter(hStmt_Update, 11, SQL_PARAM_INPUT, SQL_C_DEFAULT, 8, 0, 0, (SQLPOINTER)MLINE.constData(), 0, &cbMLINE);
		if (r == SQL_SUCCESS) { isValid=true; }
	// TK_PRTLTFSET is a well formed table for eNVy Replication 
		 qDebug(category) << " Parameters: Ordinal [6] 00 00 FieldName: MAREA ";
		 qDebug(category) << " Parameters: Ordinal [7] 00 00  FieldName: MPAGE ";
		 qDebug(category) << " Parameters: Ordinal [8] 00 00 FieldName:  MLINE ";
	} // 	if (m_ReplicationOption == ReplicationOption::NetChange)
	return isValid;
}

bool TK_PRTLTFSET::process(int rowSize)
{
	QLoggingCategory category("classLibQ");
	initOdbcAttributes();
	connect(Source);
	connect(Target);
	initialize();
	prepareTargetTable();
	prepare();
	bindColumn();
	bindParameter();
	copyTable();
	close();
	return false;
}

void TK_PRTLTFSET::copyTable()
{
	QLoggingCategory category("classLibQ");
	RETCODE r;
	QString check;
	r = SQLExecute(hStmt_Fetch);
		if (bIsAbort) {
			emit aborted(tableName, rowsFetched, rowsInserted, rowsUpdated);
			return;
		}
		while((r = SQLFetch(hStmt_Fetch)) != SQL_NO_DATA) {
		if (r != SQL_SUCCESS) {
			check = qWarnODBCHandle(SQL_HANDLE_STMT, hStmt_Fetch);
			qCCritical(category) << QString("SqlFetch - Error : %1 is %2").arg(fetchSql).arg(check);
			return;
		} 
		rowsFetched++;
		if (m_ReplicationOption == ReplicationOption::BulkCopy)
		{
			r = SQLExecute(hStmt_Insert);
			if (r == SQL_ERROR) {
				check = qWarnODBCHandle(SQL_HANDLE_STMT, hStmt_Insert);
				 qCCritical(category) << QString("SqlExecute:Insert - Error : %1 is %2").arg(insertSql).arg(check);
				return;
			}
			rowsInserted++;
			if ((rowsFetched % updateInterval) == 0) {
				qCInfo(category) << QString("[%1.%2]	Insertion: %3	Updates : %4	Fetched : %5").arg(profileName).arg(tableName).arg(rowsInserted).arg(rowsUpdated).arg(rowsFetched);
				emit updateStatusFetched(profileName, tableName, rowsFetched,rowsInserted,rowsUpdated);
			}
			if (m_ReplicationOption == ReplicationOption::NetChange)
			{
			r = SQLExecute(hStmt_Update);
			if (r != SQL_SUCCESS) {
				check = qWarnODBCHandle(SQL_HANDLE_STMT, hStmt_Update);
				 qCInfo(category)  << QString("SqlExecute:Update - Error : %1 is %2").arg(updateSql).arg(check);
				r = SQLExecute(hStmt_Insert);
				if (r != SQL_SUCCESS) {
					check = qWarnODBCHandle(SQL_HANDLE_STMT, hStmt_Insert);
					 qCritical(category) << QString("SqlExecute:Insert - Error : %1 is %2").arg(insertSql).arg(check);
					return;
				}
				else 	rowsInserted++;
				}
				else	rowsUpdated++;
			}
			emit updateStatusFetched(profileName, tableName, rowsFetched,rowsInserted,rowsUpdated);
		}
	} 
qCInfo(category) << QString("[%1.%2]	Insertion: %3	Updates : %4	Fetched : %5").arg(profileName).arg(tableName).arg(rowsInserted).arg(rowsUpdated).arg(rowsFetched);
}

void TK_PRTLTFSET::connect(connectionHandle connectionSource)
{

	QLoggingCategory category("classLibQ");
	RETCODE r;

	bool isValid = false;
	HWND	hWnd = nullptr;
	hWnd = ::GetDesktopWindow(); 
	SQLSMALLINT nResult = 0;

	SQLSMALLINT cb;
	UWORD wConnectOption = SQL_DRIVER_COMPLETE; //SQL_DRIVER_NOPROMPT;
	QVarLengthArray<SQLTCHAR> connOut(1024);
	memset(connOut.data(), 0, connOut.size() * sizeof(SQLTCHAR));

	switch (connectionSource)
	{
		case Source:
			{// environment
				SQLHANDLE hEnv = SQL_NULL_HANDLE;
				SQLHANDLE hDbc = SQL_NULL_HANDLE;
				r = ::SQLAllocHandle(SQL_HANDLE_ENV, SQL_NULL_HANDLE, &hEnv);
				if (r == SQL_SUCCESS) isValid = true;

				foreach(nOdbcAttributesClass * k, this->m_OdbcAttributes_Map)
				{
					if (k->attributeType == enumAttributeType::hEnv)
					{
						r = ::SQLSetEnvAttr(hEnv, (SQLINTEGER) k->odbcKey, (SQLPOINTER)k->odbcValue, 0);
						if (r == SQL_SUCCESS) isValid = true;
					}
				}
				hEnv_Source = hEnv;

				r = SQLAllocHandle(SQL_HANDLE_DBC, hEnv, &hDbc);
				if (r == SQL_SUCCESS) isValid = true;
				foreach(nOdbcAttributesClass * k, this->m_OdbcAttributes_Map)
				{
					if (k->attributeType == enumAttributeType::hDbc)
					{
					r = ::SQLSetConnectAttr(hDbc, k->odbcKey, (SQLPOINTER)k->odbcValue, 0);
					if (k->odbcKey == SQL_ATTR_CONNECTION_POOLING && k->odbcValue == SQL_CP_ONE_PER_DRIVER) wConnectOption = SQL_DRIVER_NOPROMPT;
					if (k->odbcKey == SQL_ATTR_CONNECTION_POOLING && k->odbcValue == SQL_CP_ONE_PER_HENV) wConnectOption = SQL_DRIVER_NOPROMPT;
					if (k->odbcKey == SQL_ATTR_CONNECTION_POOLING && k->odbcValue == SQL_CP_DRIVER_AWARE) wConnectOption = SQL_DRIVER_NOPROMPT;
					if (r == SQL_SUCCESS) isValid = true;
					}
				}
				hDbc_source = hDbc;
				if (isValid)
				{
					r = ::SQLDriverConnect(
						hDbc,
						hWnd,
#ifdef UNICODE
						toSQLTCHAR(m_lpszSourceDSN).data(),
#else
						(SQLCHAR*)dsnSource.toUtf8().data(),
#endif
						(SQLSMALLINT)m_lpszSourceDSN.length(),
						connOut.data(),
						1024,
						&cb, 
						wConnectOption); 
					int colSize = cb / sizeof(SQLTCHAR);
					if (r != SQL_SUCCESS && r != SQL_SUCCESS_WITH_INFO)
					{
						QString check = qWarnODBCHandle(SQL_HANDLE_DBC, hDbc);
						qCritical(category) <<  check;
						m_bIsOpen = false;
					}
					m_bIsOpen = true;
				}
			} break;
		case Target:
			{
				SQLHANDLE hEnv = SQL_NULL_HANDLE;
				SQLHANDLE hDbc = SQL_NULL_HANDLE;
				r = ::SQLAllocHandle(SQL_HANDLE_ENV, SQL_NULL_HANDLE, &hEnv);
				if (r == SQL_SUCCESS) isValid = true;

				foreach(nOdbcAttributesClass * k, this->m_OdbcAttributes_Map)
				{
					if (k->attributeType == enumAttributeType::hEnv)
					{
						r = ::SQLSetEnvAttr(hEnv, (SQLINTEGER) k->odbcKey, (SQLPOINTER)k->odbcValue, 0);
						if (r == SQL_SUCCESS) isValid = true;
					}
				}
				hEnv_Target = hEnv;

				r = SQLAllocHandle(SQL_HANDLE_DBC, hEnv, &hDbc);
				if (r == SQL_SUCCESS) isValid = true;
				foreach(nOdbcAttributesClass * k, this->m_OdbcAttributes_Map)
				{
				if (k->attributeType == enumAttributeType::hDbc)
					{
					r = ::SQLSetConnectAttr(hDbc, k->odbcKey, (SQLPOINTER)k->odbcValue, 0);
					if (k->odbcKey == SQL_ATTR_CONNECTION_POOLING && k->odbcValue == SQL_CP_ONE_PER_DRIVER) wConnectOption = SQL_DRIVER_NOPROMPT;
					if (k->odbcKey == SQL_ATTR_CONNECTION_POOLING && k->odbcValue == SQL_CP_ONE_PER_HENV) wConnectOption = SQL_DRIVER_NOPROMPT;
					if (k->odbcKey == SQL_ATTR_CONNECTION_POOLING && k->odbcValue == SQL_CP_DRIVER_AWARE) wConnectOption = SQL_DRIVER_NOPROMPT;
					if (r == SQL_SUCCESS) isValid = true;
					}
				}
				hDbc_target = hDbc;
				if (isValid) {
					r = ::SQLDriverConnect(
						hDbc,
						hWnd,
#ifdef UNICODE
						toSQLTCHAR(m_lpszTargetDSN).data(),
#else
						(SQLCHAR*)m_lpszTargetDSN.toUtf8().data(),
#endif
						(SQLSMALLINT)m_lpszTargetDSN.length(),
						connOut.data(),
						1024,
						&cb, 
						wConnectOption); 
						int colSize = cb / sizeof(SQLTCHAR);
					if (r != SQL_SUCCESS && r != SQL_SUCCESS_WITH_INFO)
						{
							QString check = qWarnODBCHandle(SQL_HANDLE_DBC, hDbc);
							qCritical(category) <<  check;
							m_bIsOpen = false;
						}
							m_bIsOpen = true;
					}
			} break;
			default: break;
	}
}
TK_PRTREC::TK_PRTREC(QObject * parent) : QObject(parent) 
,tableName("TK_PRTREC")
,m_dropOption(DropOption::DropTable) { 
	numRowsFetched = 0;
}

#pragma region ~CTOR TK_PRTREC 
TK_PRTREC::~TK_PRTREC() { 

#pragma region Buffers - Clear 
	DB_ID.clear();
	NVTIMESTAMP.clear();
	AREA.clear();
	PAGE.clear();
	LINE.clear();
	TK_PRTNO.clear();
	TK_PRTMUQ.clear();
	TK_PRTLCFLG.clear();
#pragma endregion Buffers - Clear 
}
#pragma endregion Destructor_TK_PRTREC

// begin method functions
void TK_PRTREC::setAbortFlag() { 
	QLoggingCategory category("classLibQ");
	qCInfo(category) << "isAbort was set to True";
	bIsAbort = true;
}

void TK_PRTREC::run() { 
	process(1);
	QLoggingCategory category("classLibQ");
	qDebug(category) << "Entered;";
}

void	TK_PRTREC::initOdbcAttributes()
{
	QLoggingCategory category("classLibQ");
	this->setProfileName(profileName);
	qDebug(category) << "Processing - TRKDB100"; 
	m_OdbcAttributesList = m_OdbcAttributes.split(","); 
	foreach(QString m, m_OdbcAttributesList)
	{
		QStringList keyValue = m.split("=");
		nOdbcAttributesClass * oM = new nOdbcAttributesClass(this);
		if (oM->loadToOdbc(keyValue.value(0), keyValue.value(1)))
		{
			m_OdbcAttributes_Map.insert(oM->odbcKey, oM);
		}
	}
}
void	TK_PRTREC::initialize()
{
	QLoggingCategory category("classLibQ");
	RETCODE r;
	this->setProfileName(profileName);
	qDebug(category) << "Processing - TRKDB100"; 
//SQL Statements
//--------------------------------------------------

#pragma region Sql Statements_TK_PRTREC

	fetchSql = "select  DB_ID, NVTIMESTAMP, AREA, PAGE, LINE, TK_PRTNO, TK_PRTMUQ, TK_PRTLCFLG from TK_PRTREC";
		if (m_ReplicationOption == ReplicationOption::NetChange)
		{
			fetchSql.append(" p1, nv_transfers p2 WHERE  p2.table_name = 'TK_PRTREC' AND p1.nvtimestamp > p2.last_completed");
		}
	insertSql = "insert into TK_PRTREC ( PLANT_CODE, NVTIMESTAMP, AREA, PAGE, LINE, TK_PRTNO, TK_PRTMUQ, TK_PRTLCFLG ) values ( ?, ?, ?, ?, ?, ?, ?, ?)";
	updateSql = "update TK_PRTREC set  PLANT_CODE = ?, NVTIMESTAMP = ?, AREA = ?, PAGE = ?, LINE = ?, TK_PRTNO = ?, TK_PRTMUQ = ?, TK_PRTLCFLG = ?  where area = ? and page = ? line = ? ";

	qDebug(category) << "insertSQL - insert into TK_PRTREC ( PLANT_CODE, NVTIMESTAMP, AREA, PAGE, LINE, TK_PRTNO, TK_PRTMUQ, TK_PRTLCFLG ) values ( ?, ?, ?, ?, ?, ?, ?, ?)";
	qDebug(category) << "fetchSQL - select  DB_ID, NVTIMESTAMP, AREA, PAGE, LINE, TK_PRTNO, TK_PRTMUQ, TK_PRTLCFLG from TK_PRTREC";
	qDebug(category) << "unsertSQL - update TK_PRTREC set  PLANT_CODE = ?, NVTIMESTAMP = ?, AREA = ?, PAGE = ?, LINE = ?, TK_PRTNO = ?, TK_PRTMUQ = ?, TK_PRTLCFLG = ?  where area = ? and page = ? line = ? ";

#pragma endregion Sql Statements_TK_PRTREC
	SQLHANDLE		insert_hStmt = SQL_NULL_HANDLE;
	SQLHANDLE		fetch_hStmt = SQL_NULL_HANDLE; 
	SQLHANDLE		update_hStmt = SQL_NULL_HANDLE; 
 
	r = ::SQLAllocHandle(SQL_HANDLE_STMT, hDbc_source, &fetch_hStmt);
	if (r != SQL_SUCCESS) {
		 qCCritical(category) << QString("Error  hDbc_Source SQLCode : %1 is %2").arg(QString::number( (long)hDbc_source)).arg(QString::number(r));
		return; 
	}
	r = ::SQLAllocHandle(SQL_HANDLE_STMT, hDbc_target, &insert_hStmt);
	if (r != SQL_SUCCESS) {
		 qCCritical(category) << QString("Error hDbc_Source -SQLCode: %1 is %2").arg(QString::number( (long)hDbc_target)).arg(QString::number(r));
		return; 
	}
	r = ::SQLAllocHandle(SQL_HANDLE_STMT, hDbc_target, &update_hStmt);
	if (r != SQL_SUCCESS) {
		 qCCritical(category) << QString("Error hDbc_Source +SQLCode: %1 is %2").arg(QString::number( (long)hDbc_target)).arg(QString::number(r));
		return; 
	}
 
	hStmt_Fetch = fetch_hStmt;
	hStmt_Insert = insert_hStmt;
	hStmt_Update = update_hStmt;
 
	SQLSetStmtAttr(hStmt_Fetch, SQL_ATTR_USE_BOOKMARKS, (SQLPOINTER)SQL_UB_OFF, 0);
	SQLSetStmtAttr(hStmt_Fetch, SQL_ATTR_ROW_BIND_TYPE, (SQLPOINTER)SQL_BIND_BY_COLUMN, 0);
	SQLSetStmtAttr(hStmt_Fetch, SQL_ATTR_ROW_ARRAY_SIZE, (SQLPOINTER)1, 0);
	SQLSetStmtAttr(hStmt_Fetch, SQL_ATTR_ROWS_FETCHED_PTR, &numRowsFetched, 0);

// Fields used by this class 
// ---------------------------------------------------

#pragma region Resize Fields TK_PRTREC
	qDebug(category) << "Malloc - DB_ID[2]";
	DB_ID.resize(2);
	qDebug(category) << "Malloc - NVTIMESTAMP[23]";
	NVTIMESTAMP.resize(23);
	qDebug(category) << "Malloc - AREA[2]";
	AREA.resize(2);
	qDebug(category) << "Malloc - PAGE[4]";
	PAGE.resize(4);
	qDebug(category) << "Malloc - LINE[2]";
	LINE.resize(2);
	qDebug(category) << "Malloc - TK_PRTNO[18]";
	TK_PRTNO.resize(18);
	qDebug(category) << "Malloc - TK_PRTMUQ[8]";
	TK_PRTMUQ.resize(8);
	qDebug(category) << "Malloc - TK_PRTLCFLG[2]";
	TK_PRTLCFLG.resize(2);

#pragma endregion Resize Fields TK_PRTREC
}
void TK_PRTREC::close()
{
	QLoggingCategory category("classLibQ");
	if (m_bIsOpen)
	{
	qDebug(category) << "database is Open";
		SQLHANDLE source_hStmt = hStmt_Fetch;
		SQLHANDLE insert_hStmt = hStmt_Insert;
		SQLHANDLE hDb_S = this->hDbc_source;
		SQLHANDLE hDb_T = hDbc_target;
		SQLHANDLE hEnvS = hEnv_Source;
		SQLHANDLE hEnvT = hEnv_Target;
		RETCODE r;

		r = ::SQLFreeHandle(SQL_HANDLE_STMT, hStmt_Fetch);
		r = ::SQLFreeHandle(SQL_HANDLE_STMT, hStmt_Insert);
		r = ::SQLFreeHandle(SQL_HANDLE_STMT, hStmt_Update);
		if (hDbc_source != SQL_NULL_HANDLE) 		r = ::SQLDisconnect(hDb_S);
		if (hDbc_target != SQL_NULL_HANDLE) 		r = ::SQLDisconnect(hDb_T);

		r = ::SQLFreeHandle(SQL_HANDLE_DBC, hDb_S);
		r = ::SQLFreeHandle(SQL_HANDLE_DBC, hDb_T);
		r = ::SQLFreeHandle(SQL_HANDLE_ENV, hEnvS);
		r = ::SQLFreeHandle(SQL_HANDLE_ENV, hEnvT);
	}

	hEnv_Source = SQL_NULL_HANDLE;
	hEnv_Target = SQL_NULL_HANDLE;
	hEnv_Source = SQL_NULL_HANDLE;
	hEnv_Target = SQL_NULL_HANDLE;
	hStmt_Fetch = SQL_NULL_HANDLE;
	hStmt_Insert = SQL_NULL_HANDLE;
	hStmt_Update = SQL_NULL_HANDLE;
}

void TK_PRTREC::open(const QString sourceDSN, const QString targetDSN)
{
	QLoggingCategory category("classLibQ");
	m_lpszTargetDSN = targetDSN;
	m_lpszSourceDSN = sourceDSN;
	qDebug(category) << QString("Source - %1[%2]").arg(sourceDSN);
	qDebug(category) << QString("Target - %1[%2]").arg(targetDSN);
}

void TK_PRTREC::createTable()
{
	QLoggingCategory category("classLibQ");
	{
		QScopedPointer<nvTableOracleRdb> tbl(new nvTableOracleRdb(nullptr));
		tbl->initialize("TK_PRTREC", this->m_lpszSourceDSN);
		QString newTbl = tbl->getCreateTableSQL();
		QScopedPointer<qVtExecute> vExec(new qVtExecute(nullptr));
		{
			vExec->initialize(m_lpszTargetDSN, " ", true);
			vExec->setOdbcAttributes(m_OdbcAttributes);
			vExec->ExecuteDirect(newTbl);
		}
	 qDebug(category) << QString("End Create Table %1 ").arg(tableName); 
	}
}

bool TK_PRTREC::prepare()
{
	RETCODE r;
	QString check;
	QLoggingCategory category("classLibQ");
	 qDebug(category) << fetchSql;
	 qDebug(category) << insertSql;
#ifdef UNICODE
	r = SQLPrepare(hStmt_Insert,toSQLTCHAR(insertSql).data(),(SQLINTEGER)insertSql.length()); 
	if (r != SQL_SUCCESS) {
		check = qWarnODBCHandle(SQL_HANDLE_STMT, hStmt_Insert);
		 qCCritical(category) << QString("Prepare Statement-Insert : %1 is %2").arg(insertSql).arg(check);
		return false; 
	}
	r = SQLPrepare(hStmt_Update,toSQLTCHAR(updateSql).data(),(SQLINTEGER)updateSql.length()); 
	if (r != SQL_SUCCESS) {
		check = qWarnODBCHandle(SQL_HANDLE_STMT, hStmt_Update);
		 qCCritical(category) << QString("Prepare Statement-Update : %1 is %2").arg(updateSql).arg(check);
		return false; 
	}
	r = SQLPrepare(hStmt_Fetch,toSQLTCHAR(fetchSql).data(),(SQLINTEGER)fetchSql.length());
	if (r != SQL_SUCCESS) {
		check = qWarnODBCHandle(SQL_HANDLE_STMT, hStmt_Fetch);
		 qCCritical(category) << QString("Prepare Statement-Insert : %1 is %2").arg(fetchSql).arg(check);
		return false; 
	}
#else
	QByteArray queryI8 = insertSql.toUtf8();
	r = SQLPrepare(insert_hStmt,SQLCHAR*)queryI8.data(),(SQLINTEGER)queryI8.length());
	QByteArray queryU8 = fetchSql.toUtf8();
	r = SQLPrepare(hStmt_Fetch,(SQLCHAR*)queryU8.data(),(SQLINTEGER)queryU8.length());
#endif
	return true;

}

void TK_PRTREC::prepareTargetTable()
{
	QLoggingCategory category("classLibQ");
	if (this->m_ReplicationOption == ReplicationOption::BulkCopy)
	{
		QScopedPointer<qVtExecute> execSql(new qVtExecute(nullptr));
		DropOption option = this->m_dropOption;
		switch (option)
		{
			case DropOption::DeleteFromTable:
			{
				QLoggingCategory category("classLibQ");
				execSql->initialize(this->m_lpszTargetDSN, "delete from TK_PRTREC", true);
				execSql->setOdbcAttributes(this->m_OdbcAttributes);
				execSql->ExecuteDirect("delete from TK_PRTREC");
			}break;
			case DropOption::TruncateTable:
			{
				execSql->initialize(this->m_lpszTargetDSN, "truncate table TK_PRTREC", true);
				execSql->setOdbcAttributes(this->m_OdbcAttributes);
				execSql->ExecuteDirect("truncate table TK_PRTREC");
			}break;
			case DropOption::DropTable:
			{
				execSql->initialize(this->m_lpszTargetDSN, "drop table TK_PRTREC", true);
				execSql->setOdbcAttributes(this->m_OdbcAttributes);
				execSql->ExecuteDirect("drop table TK_PRTREC");
				createTable();
			}break;
		}
	}
}

bool TK_PRTREC::bindColumn()
{
	QLoggingCategory category("classLibQ");
	RETCODE r;
	bool isValid=true;
		 qDebug(category) << " Bindings: Ordinal [1] Type: 5 Buffer Size: 2 FieldName: DB_ID ";
		r = ::SQLBindCol(hStmt_Fetch, 1, 5, DB_ID.data(), 2, &cbDB_ID);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Bindings: Ordinal [2] Type: 93 Buffer Size: 23 FieldName: NVTIMESTAMP ";
		r = ::SQLBindCol(hStmt_Fetch, 2, 93, NVTIMESTAMP.data(), 23, &cbNVTIMESTAMP);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Bindings: Ordinal [3] Type: 5 Buffer Size: 2 FieldName: AREA ";
		r = ::SQLBindCol(hStmt_Fetch, 3, 5, AREA.data(), 2, &cbAREA);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Bindings: Ordinal [4] Type: 4 Buffer Size: 4 FieldName: PAGE ";
		r = ::SQLBindCol(hStmt_Fetch, 4, 4, PAGE.data(), 4, &cbPAGE);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Bindings: Ordinal [5] Type: 5 Buffer Size: 2 FieldName: LINE ";
		r = ::SQLBindCol(hStmt_Fetch, 5, 5, LINE.data(), 2, &cbLINE);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Bindings: Ordinal [6] Type: 1 Buffer Size: 18 FieldName: TK_PRTNO ";
		r = ::SQLBindCol(hStmt_Fetch, 6, 1, TK_PRTNO.data(), 18, &cbTK_PRTNO);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Bindings: Ordinal [7] Type: 8 Buffer Size: 8 FieldName: TK_PRTMUQ ";
		r = ::SQLBindCol(hStmt_Fetch, 7, 8, TK_PRTMUQ.data(), 8, &cbTK_PRTMUQ);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Bindings: Ordinal [8] Type: 5 Buffer Size: 2 FieldName: TK_PRTLCFLG ";
		r = ::SQLBindCol(hStmt_Fetch, 8, 5, TK_PRTLCFLG.data(), 2, &cbTK_PRTLCFLG);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
	return isValid;
}

bool TK_PRTREC::bindParameter()
{
	QLoggingCategory category("classLibQ");
	RETCODE r;
	bool isValid=true;
	{
		 qDebug(category) << " Parameters: Ordinal [1] Type: 5 Buffer Size: 2 FieldName: DB_ID ";
		r = SQLBindParameter(hStmt_Insert, 1, SQL_PARAM_INPUT, SQL_C_DEFAULT, 5, 0, 0, (SQLPOINTER)DB_ID.constData(), 0, &cbDB_ID);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Parameters: Ordinal [2] Type: 93 Buffer Size: 23 FieldName: NVTIMESTAMP ";
		r = SQLBindParameter(hStmt_Insert, 2, SQL_PARAM_INPUT, SQL_C_DEFAULT, 93, 23, 0, (SQLPOINTER)NVTIMESTAMP.constData(), 0, &cbNVTIMESTAMP);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Parameters: Ordinal [3] Type: 5 Buffer Size: 2 FieldName: AREA ";
		r = SQLBindParameter(hStmt_Insert, 3, SQL_PARAM_INPUT, SQL_C_DEFAULT, 5, 0, 0, (SQLPOINTER)AREA.constData(), 0, &cbAREA);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Parameters: Ordinal [4] Type: 4 Buffer Size: 4 FieldName: PAGE ";
		r = SQLBindParameter(hStmt_Insert, 4, SQL_PARAM_INPUT, SQL_C_DEFAULT, 4, 0, 0, (SQLPOINTER)PAGE.constData(), 0, &cbPAGE);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Parameters: Ordinal [5] Type: 5 Buffer Size: 2 FieldName: LINE ";
		r = SQLBindParameter(hStmt_Insert, 5, SQL_PARAM_INPUT, SQL_C_DEFAULT, 5, 0, 0, (SQLPOINTER)LINE.constData(), 0, &cbLINE);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Parameters: Ordinal [6] Type: 1 Buffer Size: 18 FieldName: TK_PRTNO ";
		r = SQLBindParameter(hStmt_Insert, 6, SQL_PARAM_INPUT, SQL_C_DEFAULT, 1, 18, 0, (SQLPOINTER)TK_PRTNO.constData(), 0, &cbTK_PRTNO);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Parameters: Ordinal [7] Type: 8 Buffer Size: 8 FieldName: TK_PRTMUQ ";
		r = SQLBindParameter(hStmt_Insert, 7, SQL_PARAM_INPUT, SQL_C_DEFAULT, 8, 0, 0, (SQLPOINTER)TK_PRTMUQ.constData(), 0, &cbTK_PRTMUQ);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Parameters: Ordinal [8] Type: 5 Buffer Size: 2 FieldName: TK_PRTLCFLG ";
		r = SQLBindParameter(hStmt_Insert, 8, SQL_PARAM_INPUT, SQL_C_DEFAULT, 5, 0, 0, (SQLPOINTER)TK_PRTLCFLG.constData(), 0, &cbTK_PRTLCFLG);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
	}
	if (m_ReplicationOption == ReplicationOption::NetChange)
	{
		r = SQLBindParameter(hStmt_Update, 9, SQL_PARAM_INPUT, SQL_C_DEFAULT, 3, 0, 0, (SQLPOINTER)AREA.constData(), 0, &cbAREA);
		if (r == SQL_SUCCESS) { isValid=true; }
		r = SQLBindParameter(hStmt_Update, 10, SQL_PARAM_INPUT, SQL_C_DEFAULT, 4, 0, 0, (SQLPOINTER)PAGE.constData(), 0, &cbPAGE);
		if (r == SQL_SUCCESS) { isValid=true; }
		r = SQLBindParameter(hStmt_Update, 11, SQL_PARAM_INPUT, SQL_C_DEFAULT, 5, 0, 0, (SQLPOINTER)LINE.constData(), 0, &cbLINE);
		if (r == SQL_SUCCESS) { isValid=true; }
	// TK_PRTREC is a well formed table for eNVy Replication 
		 qDebug(category) << " Parameters: Ordinal [3] 00 00 FieldName: AREA ";
		 qDebug(category) << " Parameters: Ordinal [4] 00 00  FieldName: PAGE ";
		 qDebug(category) << " Parameters: Ordinal [5] 00 00 FieldName:  LINE ";
	} // 	if (m_ReplicationOption == ReplicationOption::NetChange)
	return isValid;
}

bool TK_PRTREC::process(int rowSize)
{
	QLoggingCategory category("classLibQ");
	initOdbcAttributes();
	connect(Source);
	connect(Target);
	initialize();
	prepareTargetTable();
	prepare();
	bindColumn();
	bindParameter();
	copyTable();
	close();
	return false;
}

void TK_PRTREC::copyTable()
{
	QLoggingCategory category("classLibQ");
	RETCODE r;
	QString check;
	r = SQLExecute(hStmt_Fetch);
		if (bIsAbort) {
			emit aborted(tableName, rowsFetched, rowsInserted, rowsUpdated);
			return;
		}
		while((r = SQLFetch(hStmt_Fetch)) != SQL_NO_DATA) {
		if (r != SQL_SUCCESS) {
			check = qWarnODBCHandle(SQL_HANDLE_STMT, hStmt_Fetch);
			qCCritical(category) << QString("SqlFetch - Error : %1 is %2").arg(fetchSql).arg(check);
			return;
		} 
		rowsFetched++;
		if (m_ReplicationOption == ReplicationOption::BulkCopy)
		{
			r = SQLExecute(hStmt_Insert);
			if (r == SQL_ERROR) {
				check = qWarnODBCHandle(SQL_HANDLE_STMT, hStmt_Insert);
				 qCCritical(category) << QString("SqlExecute:Insert - Error : %1 is %2").arg(insertSql).arg(check);
				return;
			}
			rowsInserted++;
			if ((rowsFetched % updateInterval) == 0) {
				qCInfo(category) << QString("[%1.%2]	Insertion: %3	Updates : %4	Fetched : %5").arg(profileName).arg(tableName).arg(rowsInserted).arg(rowsUpdated).arg(rowsFetched);
				emit updateStatusFetched(profileName, tableName, rowsFetched,rowsInserted,rowsUpdated);
			}
			if (m_ReplicationOption == ReplicationOption::NetChange)
			{
			r = SQLExecute(hStmt_Update);
			if (r != SQL_SUCCESS) {
				check = qWarnODBCHandle(SQL_HANDLE_STMT, hStmt_Update);
				 qCInfo(category)  << QString("SqlExecute:Update - Error : %1 is %2").arg(updateSql).arg(check);
				r = SQLExecute(hStmt_Insert);
				if (r != SQL_SUCCESS) {
					check = qWarnODBCHandle(SQL_HANDLE_STMT, hStmt_Insert);
					 qCritical(category) << QString("SqlExecute:Insert - Error : %1 is %2").arg(insertSql).arg(check);
					return;
				}
				else 	rowsInserted++;
				}
				else	rowsUpdated++;
			}
			emit updateStatusFetched(profileName, tableName, rowsFetched,rowsInserted,rowsUpdated);
		}
	} 
qCInfo(category) << QString("[%1.%2]	Insertion: %3	Updates : %4	Fetched : %5").arg(profileName).arg(tableName).arg(rowsInserted).arg(rowsUpdated).arg(rowsFetched);
}

void TK_PRTREC::connect(connectionHandle connectionSource)
{

	QLoggingCategory category("classLibQ");
	RETCODE r;

	bool isValid = false;
	HWND	hWnd = nullptr;
	hWnd = ::GetDesktopWindow(); 
	SQLSMALLINT nResult = 0;

	SQLSMALLINT cb;
	UWORD wConnectOption = SQL_DRIVER_COMPLETE; //SQL_DRIVER_NOPROMPT;
	QVarLengthArray<SQLTCHAR> connOut(1024);
	memset(connOut.data(), 0, connOut.size() * sizeof(SQLTCHAR));

	switch (connectionSource)
	{
		case Source:
			{// environment
				SQLHANDLE hEnv = SQL_NULL_HANDLE;
				SQLHANDLE hDbc = SQL_NULL_HANDLE;
				r = ::SQLAllocHandle(SQL_HANDLE_ENV, SQL_NULL_HANDLE, &hEnv);
				if (r == SQL_SUCCESS) isValid = true;

				foreach(nOdbcAttributesClass * k, this->m_OdbcAttributes_Map)
				{
					if (k->attributeType == enumAttributeType::hEnv)
					{
						r = ::SQLSetEnvAttr(hEnv, (SQLINTEGER) k->odbcKey, (SQLPOINTER)k->odbcValue, 0);
						if (r == SQL_SUCCESS) isValid = true;
					}
				}
				hEnv_Source = hEnv;

				r = SQLAllocHandle(SQL_HANDLE_DBC, hEnv, &hDbc);
				if (r == SQL_SUCCESS) isValid = true;
				foreach(nOdbcAttributesClass * k, this->m_OdbcAttributes_Map)
				{
					if (k->attributeType == enumAttributeType::hDbc)
					{
					r = ::SQLSetConnectAttr(hDbc, k->odbcKey, (SQLPOINTER)k->odbcValue, 0);
					if (k->odbcKey == SQL_ATTR_CONNECTION_POOLING && k->odbcValue == SQL_CP_ONE_PER_DRIVER) wConnectOption = SQL_DRIVER_NOPROMPT;
					if (k->odbcKey == SQL_ATTR_CONNECTION_POOLING && k->odbcValue == SQL_CP_ONE_PER_HENV) wConnectOption = SQL_DRIVER_NOPROMPT;
					if (k->odbcKey == SQL_ATTR_CONNECTION_POOLING && k->odbcValue == SQL_CP_DRIVER_AWARE) wConnectOption = SQL_DRIVER_NOPROMPT;
					if (r == SQL_SUCCESS) isValid = true;
					}
				}
				hDbc_source = hDbc;
				if (isValid)
				{
					r = ::SQLDriverConnect(
						hDbc,
						hWnd,
#ifdef UNICODE
						toSQLTCHAR(m_lpszSourceDSN).data(),
#else
						(SQLCHAR*)dsnSource.toUtf8().data(),
#endif
						(SQLSMALLINT)m_lpszSourceDSN.length(),
						connOut.data(),
						1024,
						&cb, 
						wConnectOption); 
					int colSize = cb / sizeof(SQLTCHAR);
					if (r != SQL_SUCCESS && r != SQL_SUCCESS_WITH_INFO)
					{
						QString check = qWarnODBCHandle(SQL_HANDLE_DBC, hDbc);
						qCritical(category) <<  check;
						m_bIsOpen = false;
					}
					m_bIsOpen = true;
				}
			} break;
		case Target:
			{
				SQLHANDLE hEnv = SQL_NULL_HANDLE;
				SQLHANDLE hDbc = SQL_NULL_HANDLE;
				r = ::SQLAllocHandle(SQL_HANDLE_ENV, SQL_NULL_HANDLE, &hEnv);
				if (r == SQL_SUCCESS) isValid = true;

				foreach(nOdbcAttributesClass * k, this->m_OdbcAttributes_Map)
				{
					if (k->attributeType == enumAttributeType::hEnv)
					{
						r = ::SQLSetEnvAttr(hEnv, (SQLINTEGER) k->odbcKey, (SQLPOINTER)k->odbcValue, 0);
						if (r == SQL_SUCCESS) isValid = true;
					}
				}
				hEnv_Target = hEnv;

				r = SQLAllocHandle(SQL_HANDLE_DBC, hEnv, &hDbc);
				if (r == SQL_SUCCESS) isValid = true;
				foreach(nOdbcAttributesClass * k, this->m_OdbcAttributes_Map)
				{
				if (k->attributeType == enumAttributeType::hDbc)
					{
					r = ::SQLSetConnectAttr(hDbc, k->odbcKey, (SQLPOINTER)k->odbcValue, 0);
					if (k->odbcKey == SQL_ATTR_CONNECTION_POOLING && k->odbcValue == SQL_CP_ONE_PER_DRIVER) wConnectOption = SQL_DRIVER_NOPROMPT;
					if (k->odbcKey == SQL_ATTR_CONNECTION_POOLING && k->odbcValue == SQL_CP_ONE_PER_HENV) wConnectOption = SQL_DRIVER_NOPROMPT;
					if (k->odbcKey == SQL_ATTR_CONNECTION_POOLING && k->odbcValue == SQL_CP_DRIVER_AWARE) wConnectOption = SQL_DRIVER_NOPROMPT;
					if (r == SQL_SUCCESS) isValid = true;
					}
				}
				hDbc_target = hDbc;
				if (isValid) {
					r = ::SQLDriverConnect(
						hDbc,
						hWnd,
#ifdef UNICODE
						toSQLTCHAR(m_lpszTargetDSN).data(),
#else
						(SQLCHAR*)m_lpszTargetDSN.toUtf8().data(),
#endif
						(SQLSMALLINT)m_lpszTargetDSN.length(),
						connOut.data(),
						1024,
						&cb, 
						wConnectOption); 
						int colSize = cb / sizeof(SQLTCHAR);
					if (r != SQL_SUCCESS && r != SQL_SUCCESS_WITH_INFO)
						{
							QString check = qWarnODBCHandle(SQL_HANDLE_DBC, hDbc);
							qCritical(category) <<  check;
							m_bIsOpen = false;
						}
							m_bIsOpen = true;
					}
			} break;
			default: break;
	}
}
TK_UHSTCHNSET::TK_UHSTCHNSET(QObject * parent) : QObject(parent) 
,tableName("TK_UHSTCHNSET")
,m_dropOption(DropOption::DropTable) { 
	numRowsFetched = 0;
}

#pragma region ~CTOR TK_UHSTCHNSET 
TK_UHSTCHNSET::~TK_UHSTCHNSET() { 

#pragma region Buffers - Clear 
	DB_ID.clear();
	NVTIMESTAMP.clear();
	OAREA.clear();
	OPAGE.clear();
	OLINE.clear();
	MAREA.clear();
	MPAGE.clear();
	MLINE.clear();
#pragma endregion Buffers - Clear 
}
#pragma endregion Destructor_TK_UHSTCHNSET

// begin method functions
void TK_UHSTCHNSET::setAbortFlag() { 
	QLoggingCategory category("classLibQ");
	qCInfo(category) << "isAbort was set to True";
	bIsAbort = true;
}

void TK_UHSTCHNSET::run() { 
	process(1);
	QLoggingCategory category("classLibQ");
	qDebug(category) << "Entered;";
}

void	TK_UHSTCHNSET::initOdbcAttributes()
{
	QLoggingCategory category("classLibQ");
	this->setProfileName(profileName);
	qDebug(category) << "Processing - TRKDB100"; 
	m_OdbcAttributesList = m_OdbcAttributes.split(","); 
	foreach(QString m, m_OdbcAttributesList)
	{
		QStringList keyValue = m.split("=");
		nOdbcAttributesClass * oM = new nOdbcAttributesClass(this);
		if (oM->loadToOdbc(keyValue.value(0), keyValue.value(1)))
		{
			m_OdbcAttributes_Map.insert(oM->odbcKey, oM);
		}
	}
}
void	TK_UHSTCHNSET::initialize()
{
	QLoggingCategory category("classLibQ");
	RETCODE r;
	this->setProfileName(profileName);
	qDebug(category) << "Processing - TRKDB100"; 
//SQL Statements
//--------------------------------------------------

#pragma region Sql Statements_TK_UHSTCHNSET

	fetchSql = "select  DB_ID, NVTIMESTAMP, OAREA, OPAGE, OLINE, MAREA, MPAGE, MLINE from TK_UHSTCHNSET";
		if (m_ReplicationOption == ReplicationOption::NetChange)
		{
			fetchSql.append(" p1, nv_transfers p2 WHERE  p2.table_name = 'TK_UHSTCHNSET' AND p1.nvtimestamp > p2.last_completed");
		}
	insertSql = "insert into TK_UHSTCHNSET ( PLANT_CODE, NVTIMESTAMP, OAREA, OPAGE, OLINE, MAREA, MPAGE, MLINE ) values ( ?, ?, ?, ?, ?, ?, ?, ?)";
	updateSql = "update TK_UHSTCHNSET set  PLANT_CODE = ?, NVTIMESTAMP = ?, OAREA = ?, OPAGE = ?, OLINE = ?, MAREA = ?, MPAGE = ?, MLINE = ?  where area = ? and page = ? line = ? ";

	qDebug(category) << "insertSQL - insert into TK_UHSTCHNSET ( PLANT_CODE, NVTIMESTAMP, OAREA, OPAGE, OLINE, MAREA, MPAGE, MLINE ) values ( ?, ?, ?, ?, ?, ?, ?, ?)";
	qDebug(category) << "fetchSQL - select  DB_ID, NVTIMESTAMP, OAREA, OPAGE, OLINE, MAREA, MPAGE, MLINE from TK_UHSTCHNSET";
	qDebug(category) << "unsertSQL - update TK_UHSTCHNSET set  PLANT_CODE = ?, NVTIMESTAMP = ?, OAREA = ?, OPAGE = ?, OLINE = ?, MAREA = ?, MPAGE = ?, MLINE = ?  where area = ? and page = ? line = ? ";

#pragma endregion Sql Statements_TK_UHSTCHNSET
	SQLHANDLE		insert_hStmt = SQL_NULL_HANDLE;
	SQLHANDLE		fetch_hStmt = SQL_NULL_HANDLE; 
	SQLHANDLE		update_hStmt = SQL_NULL_HANDLE; 
 
	r = ::SQLAllocHandle(SQL_HANDLE_STMT, hDbc_source, &fetch_hStmt);
	if (r != SQL_SUCCESS) {
		 qCCritical(category) << QString("Error  hDbc_Source SQLCode : %1 is %2").arg(QString::number( (long)hDbc_source)).arg(QString::number(r));
		return; 
	}
	r = ::SQLAllocHandle(SQL_HANDLE_STMT, hDbc_target, &insert_hStmt);
	if (r != SQL_SUCCESS) {
		 qCCritical(category) << QString("Error hDbc_Source -SQLCode: %1 is %2").arg(QString::number( (long)hDbc_target)).arg(QString::number(r));
		return; 
	}
	r = ::SQLAllocHandle(SQL_HANDLE_STMT, hDbc_target, &update_hStmt);
	if (r != SQL_SUCCESS) {
		 qCCritical(category) << QString("Error hDbc_Source +SQLCode: %1 is %2").arg(QString::number( (long)hDbc_target)).arg(QString::number(r));
		return; 
	}
 
	hStmt_Fetch = fetch_hStmt;
	hStmt_Insert = insert_hStmt;
	hStmt_Update = update_hStmt;
 
	SQLSetStmtAttr(hStmt_Fetch, SQL_ATTR_USE_BOOKMARKS, (SQLPOINTER)SQL_UB_OFF, 0);
	SQLSetStmtAttr(hStmt_Fetch, SQL_ATTR_ROW_BIND_TYPE, (SQLPOINTER)SQL_BIND_BY_COLUMN, 0);
	SQLSetStmtAttr(hStmt_Fetch, SQL_ATTR_ROW_ARRAY_SIZE, (SQLPOINTER)1, 0);
	SQLSetStmtAttr(hStmt_Fetch, SQL_ATTR_ROWS_FETCHED_PTR, &numRowsFetched, 0);

// Fields used by this class 
// ---------------------------------------------------

#pragma region Resize Fields TK_UHSTCHNSET
	qDebug(category) << "Malloc - DB_ID[2]";
	DB_ID.resize(2);
	qDebug(category) << "Malloc - NVTIMESTAMP[23]";
	NVTIMESTAMP.resize(23);
	qDebug(category) << "Malloc - OAREA[2]";
	OAREA.resize(2);
	qDebug(category) << "Malloc - OPAGE[4]";
	OPAGE.resize(4);
	qDebug(category) << "Malloc - OLINE[2]";
	OLINE.resize(2);
	qDebug(category) << "Malloc - MAREA[2]";
	MAREA.resize(2);
	qDebug(category) << "Malloc - MPAGE[4]";
	MPAGE.resize(4);
	qDebug(category) << "Malloc - MLINE[2]";
	MLINE.resize(2);

#pragma endregion Resize Fields TK_UHSTCHNSET
}
void TK_UHSTCHNSET::close()
{
	QLoggingCategory category("classLibQ");
	if (m_bIsOpen)
	{
	qDebug(category) << "database is Open";
		SQLHANDLE source_hStmt = hStmt_Fetch;
		SQLHANDLE insert_hStmt = hStmt_Insert;
		SQLHANDLE hDb_S = this->hDbc_source;
		SQLHANDLE hDb_T = hDbc_target;
		SQLHANDLE hEnvS = hEnv_Source;
		SQLHANDLE hEnvT = hEnv_Target;
		RETCODE r;

		r = ::SQLFreeHandle(SQL_HANDLE_STMT, hStmt_Fetch);
		r = ::SQLFreeHandle(SQL_HANDLE_STMT, hStmt_Insert);
		r = ::SQLFreeHandle(SQL_HANDLE_STMT, hStmt_Update);
		if (hDbc_source != SQL_NULL_HANDLE) 		r = ::SQLDisconnect(hDb_S);
		if (hDbc_target != SQL_NULL_HANDLE) 		r = ::SQLDisconnect(hDb_T);

		r = ::SQLFreeHandle(SQL_HANDLE_DBC, hDb_S);
		r = ::SQLFreeHandle(SQL_HANDLE_DBC, hDb_T);
		r = ::SQLFreeHandle(SQL_HANDLE_ENV, hEnvS);
		r = ::SQLFreeHandle(SQL_HANDLE_ENV, hEnvT);
	}

	hEnv_Source = SQL_NULL_HANDLE;
	hEnv_Target = SQL_NULL_HANDLE;
	hEnv_Source = SQL_NULL_HANDLE;
	hEnv_Target = SQL_NULL_HANDLE;
	hStmt_Fetch = SQL_NULL_HANDLE;
	hStmt_Insert = SQL_NULL_HANDLE;
	hStmt_Update = SQL_NULL_HANDLE;
}

void TK_UHSTCHNSET::open(const QString sourceDSN, const QString targetDSN)
{
	QLoggingCategory category("classLibQ");
	m_lpszTargetDSN = targetDSN;
	m_lpszSourceDSN = sourceDSN;
	qDebug(category) << QString("Source - %1[%2]").arg(sourceDSN);
	qDebug(category) << QString("Target - %1[%2]").arg(targetDSN);
}

void TK_UHSTCHNSET::createTable()
{
	QLoggingCategory category("classLibQ");
	{
		QScopedPointer<nvTableOracleRdb> tbl(new nvTableOracleRdb(nullptr));
		tbl->initialize("TK_UHSTCHNSET", this->m_lpszSourceDSN);
		QString newTbl = tbl->getCreateTableSQL();
		QScopedPointer<qVtExecute> vExec(new qVtExecute(nullptr));
		{
			vExec->initialize(m_lpszTargetDSN, " ", true);
			vExec->setOdbcAttributes(m_OdbcAttributes);
			vExec->ExecuteDirect(newTbl);
		}
	 qDebug(category) << QString("End Create Table %1 ").arg(tableName); 
	}
}

bool TK_UHSTCHNSET::prepare()
{
	RETCODE r;
	QString check;
	QLoggingCategory category("classLibQ");
	 qDebug(category) << fetchSql;
	 qDebug(category) << insertSql;
#ifdef UNICODE
	r = SQLPrepare(hStmt_Insert,toSQLTCHAR(insertSql).data(),(SQLINTEGER)insertSql.length()); 
	if (r != SQL_SUCCESS) {
		check = qWarnODBCHandle(SQL_HANDLE_STMT, hStmt_Insert);
		 qCCritical(category) << QString("Prepare Statement-Insert : %1 is %2").arg(insertSql).arg(check);
		return false; 
	}
	r = SQLPrepare(hStmt_Update,toSQLTCHAR(updateSql).data(),(SQLINTEGER)updateSql.length()); 
	if (r != SQL_SUCCESS) {
		check = qWarnODBCHandle(SQL_HANDLE_STMT, hStmt_Update);
		 qCCritical(category) << QString("Prepare Statement-Update : %1 is %2").arg(updateSql).arg(check);
		return false; 
	}
	r = SQLPrepare(hStmt_Fetch,toSQLTCHAR(fetchSql).data(),(SQLINTEGER)fetchSql.length());
	if (r != SQL_SUCCESS) {
		check = qWarnODBCHandle(SQL_HANDLE_STMT, hStmt_Fetch);
		 qCCritical(category) << QString("Prepare Statement-Insert : %1 is %2").arg(fetchSql).arg(check);
		return false; 
	}
#else
	QByteArray queryI8 = insertSql.toUtf8();
	r = SQLPrepare(insert_hStmt,SQLCHAR*)queryI8.data(),(SQLINTEGER)queryI8.length());
	QByteArray queryU8 = fetchSql.toUtf8();
	r = SQLPrepare(hStmt_Fetch,(SQLCHAR*)queryU8.data(),(SQLINTEGER)queryU8.length());
#endif
	return true;

}

void TK_UHSTCHNSET::prepareTargetTable()
{
	QLoggingCategory category("classLibQ");
	if (this->m_ReplicationOption == ReplicationOption::BulkCopy)
	{
		QScopedPointer<qVtExecute> execSql(new qVtExecute(nullptr));
		DropOption option = this->m_dropOption;
		switch (option)
		{
			case DropOption::DeleteFromTable:
			{
				QLoggingCategory category("classLibQ");
				execSql->initialize(this->m_lpszTargetDSN, "delete from TK_UHSTCHNSET", true);
				execSql->setOdbcAttributes(this->m_OdbcAttributes);
				execSql->ExecuteDirect("delete from TK_UHSTCHNSET");
			}break;
			case DropOption::TruncateTable:
			{
				execSql->initialize(this->m_lpszTargetDSN, "truncate table TK_UHSTCHNSET", true);
				execSql->setOdbcAttributes(this->m_OdbcAttributes);
				execSql->ExecuteDirect("truncate table TK_UHSTCHNSET");
			}break;
			case DropOption::DropTable:
			{
				execSql->initialize(this->m_lpszTargetDSN, "drop table TK_UHSTCHNSET", true);
				execSql->setOdbcAttributes(this->m_OdbcAttributes);
				execSql->ExecuteDirect("drop table TK_UHSTCHNSET");
				createTable();
			}break;
		}
	}
}

bool TK_UHSTCHNSET::bindColumn()
{
	QLoggingCategory category("classLibQ");
	RETCODE r;
	bool isValid=true;
		 qDebug(category) << " Bindings: Ordinal [1] Type: 5 Buffer Size: 2 FieldName: DB_ID ";
		r = ::SQLBindCol(hStmt_Fetch, 1, 5, DB_ID.data(), 2, &cbDB_ID);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Bindings: Ordinal [2] Type: 93 Buffer Size: 23 FieldName: NVTIMESTAMP ";
		r = ::SQLBindCol(hStmt_Fetch, 2, 93, NVTIMESTAMP.data(), 23, &cbNVTIMESTAMP);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Bindings: Ordinal [3] Type: 5 Buffer Size: 2 FieldName: OAREA ";
		r = ::SQLBindCol(hStmt_Fetch, 3, 5, OAREA.data(), 2, &cbOAREA);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Bindings: Ordinal [4] Type: 4 Buffer Size: 4 FieldName: OPAGE ";
		r = ::SQLBindCol(hStmt_Fetch, 4, 4, OPAGE.data(), 4, &cbOPAGE);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Bindings: Ordinal [5] Type: 5 Buffer Size: 2 FieldName: OLINE ";
		r = ::SQLBindCol(hStmt_Fetch, 5, 5, OLINE.data(), 2, &cbOLINE);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Bindings: Ordinal [6] Type: 5 Buffer Size: 2 FieldName: MAREA ";
		r = ::SQLBindCol(hStmt_Fetch, 6, 5, MAREA.data(), 2, &cbMAREA);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Bindings: Ordinal [7] Type: 4 Buffer Size: 4 FieldName: MPAGE ";
		r = ::SQLBindCol(hStmt_Fetch, 7, 4, MPAGE.data(), 4, &cbMPAGE);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Bindings: Ordinal [8] Type: 5 Buffer Size: 2 FieldName: MLINE ";
		r = ::SQLBindCol(hStmt_Fetch, 8, 5, MLINE.data(), 2, &cbMLINE);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
	return isValid;
}

bool TK_UHSTCHNSET::bindParameter()
{
	QLoggingCategory category("classLibQ");
	RETCODE r;
	bool isValid=true;
	{
		 qDebug(category) << " Parameters: Ordinal [1] Type: 5 Buffer Size: 2 FieldName: DB_ID ";
		r = SQLBindParameter(hStmt_Insert, 1, SQL_PARAM_INPUT, SQL_C_DEFAULT, 5, 0, 0, (SQLPOINTER)DB_ID.constData(), 0, &cbDB_ID);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Parameters: Ordinal [2] Type: 93 Buffer Size: 23 FieldName: NVTIMESTAMP ";
		r = SQLBindParameter(hStmt_Insert, 2, SQL_PARAM_INPUT, SQL_C_DEFAULT, 93, 23, 0, (SQLPOINTER)NVTIMESTAMP.constData(), 0, &cbNVTIMESTAMP);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Parameters: Ordinal [3] Type: 5 Buffer Size: 2 FieldName: OAREA ";
		r = SQLBindParameter(hStmt_Insert, 3, SQL_PARAM_INPUT, SQL_C_DEFAULT, 5, 0, 0, (SQLPOINTER)OAREA.constData(), 0, &cbOAREA);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Parameters: Ordinal [4] Type: 4 Buffer Size: 4 FieldName: OPAGE ";
		r = SQLBindParameter(hStmt_Insert, 4, SQL_PARAM_INPUT, SQL_C_DEFAULT, 4, 0, 0, (SQLPOINTER)OPAGE.constData(), 0, &cbOPAGE);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Parameters: Ordinal [5] Type: 5 Buffer Size: 2 FieldName: OLINE ";
		r = SQLBindParameter(hStmt_Insert, 5, SQL_PARAM_INPUT, SQL_C_DEFAULT, 5, 0, 0, (SQLPOINTER)OLINE.constData(), 0, &cbOLINE);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Parameters: Ordinal [6] Type: 5 Buffer Size: 2 FieldName: MAREA ";
		r = SQLBindParameter(hStmt_Insert, 6, SQL_PARAM_INPUT, SQL_C_DEFAULT, 5, 0, 0, (SQLPOINTER)MAREA.constData(), 0, &cbMAREA);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Parameters: Ordinal [7] Type: 4 Buffer Size: 4 FieldName: MPAGE ";
		r = SQLBindParameter(hStmt_Insert, 7, SQL_PARAM_INPUT, SQL_C_DEFAULT, 4, 0, 0, (SQLPOINTER)MPAGE.constData(), 0, &cbMPAGE);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Parameters: Ordinal [8] Type: 5 Buffer Size: 2 FieldName: MLINE ";
		r = SQLBindParameter(hStmt_Insert, 8, SQL_PARAM_INPUT, SQL_C_DEFAULT, 5, 0, 0, (SQLPOINTER)MLINE.constData(), 0, &cbMLINE);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
	}
	if (m_ReplicationOption == ReplicationOption::NetChange)
	{
		r = SQLBindParameter(hStmt_Update, 9, SQL_PARAM_INPUT, SQL_C_DEFAULT, 6, 0, 0, (SQLPOINTER)MAREA.constData(), 0, &cbMAREA);
		if (r == SQL_SUCCESS) { isValid=true; }
		r = SQLBindParameter(hStmt_Update, 10, SQL_PARAM_INPUT, SQL_C_DEFAULT, 7, 0, 0, (SQLPOINTER)MPAGE.constData(), 0, &cbMPAGE);
		if (r == SQL_SUCCESS) { isValid=true; }
		r = SQLBindParameter(hStmt_Update, 11, SQL_PARAM_INPUT, SQL_C_DEFAULT, 8, 0, 0, (SQLPOINTER)MLINE.constData(), 0, &cbMLINE);
		if (r == SQL_SUCCESS) { isValid=true; }
	// TK_UHSTCHNSET is a well formed table for eNVy Replication 
		 qDebug(category) << " Parameters: Ordinal [6] 00 00 FieldName: MAREA ";
		 qDebug(category) << " Parameters: Ordinal [7] 00 00  FieldName: MPAGE ";
		 qDebug(category) << " Parameters: Ordinal [8] 00 00 FieldName:  MLINE ";
	} // 	if (m_ReplicationOption == ReplicationOption::NetChange)
	return isValid;
}

bool TK_UHSTCHNSET::process(int rowSize)
{
	QLoggingCategory category("classLibQ");
	initOdbcAttributes();
	connect(Source);
	connect(Target);
	initialize();
	prepareTargetTable();
	prepare();
	bindColumn();
	bindParameter();
	copyTable();
	close();
	return false;
}

void TK_UHSTCHNSET::copyTable()
{
	QLoggingCategory category("classLibQ");
	RETCODE r;
	QString check;
	r = SQLExecute(hStmt_Fetch);
		if (bIsAbort) {
			emit aborted(tableName, rowsFetched, rowsInserted, rowsUpdated);
			return;
		}
		while((r = SQLFetch(hStmt_Fetch)) != SQL_NO_DATA) {
		if (r != SQL_SUCCESS) {
			check = qWarnODBCHandle(SQL_HANDLE_STMT, hStmt_Fetch);
			qCCritical(category) << QString("SqlFetch - Error : %1 is %2").arg(fetchSql).arg(check);
			return;
		} 
		rowsFetched++;
		if (m_ReplicationOption == ReplicationOption::BulkCopy)
		{
			r = SQLExecute(hStmt_Insert);
			if (r == SQL_ERROR) {
				check = qWarnODBCHandle(SQL_HANDLE_STMT, hStmt_Insert);
				 qCCritical(category) << QString("SqlExecute:Insert - Error : %1 is %2").arg(insertSql).arg(check);
				return;
			}
			rowsInserted++;
			if ((rowsFetched % updateInterval) == 0) {
				qCInfo(category) << QString("[%1.%2]	Insertion: %3	Updates : %4	Fetched : %5").arg(profileName).arg(tableName).arg(rowsInserted).arg(rowsUpdated).arg(rowsFetched);
				emit updateStatusFetched(profileName, tableName, rowsFetched,rowsInserted,rowsUpdated);
			}
			if (m_ReplicationOption == ReplicationOption::NetChange)
			{
			r = SQLExecute(hStmt_Update);
			if (r != SQL_SUCCESS) {
				check = qWarnODBCHandle(SQL_HANDLE_STMT, hStmt_Update);
				 qCInfo(category)  << QString("SqlExecute:Update - Error : %1 is %2").arg(updateSql).arg(check);
				r = SQLExecute(hStmt_Insert);
				if (r != SQL_SUCCESS) {
					check = qWarnODBCHandle(SQL_HANDLE_STMT, hStmt_Insert);
					 qCritical(category) << QString("SqlExecute:Insert - Error : %1 is %2").arg(insertSql).arg(check);
					return;
				}
				else 	rowsInserted++;
				}
				else	rowsUpdated++;
			}
			emit updateStatusFetched(profileName, tableName, rowsFetched,rowsInserted,rowsUpdated);
		}
	} 
qCInfo(category) << QString("[%1.%2]	Insertion: %3	Updates : %4	Fetched : %5").arg(profileName).arg(tableName).arg(rowsInserted).arg(rowsUpdated).arg(rowsFetched);
}

void TK_UHSTCHNSET::connect(connectionHandle connectionSource)
{

	QLoggingCategory category("classLibQ");
	RETCODE r;

	bool isValid = false;
	HWND	hWnd = nullptr;
	hWnd = ::GetDesktopWindow(); 
	SQLSMALLINT nResult = 0;

	SQLSMALLINT cb;
	UWORD wConnectOption = SQL_DRIVER_COMPLETE; //SQL_DRIVER_NOPROMPT;
	QVarLengthArray<SQLTCHAR> connOut(1024);
	memset(connOut.data(), 0, connOut.size() * sizeof(SQLTCHAR));

	switch (connectionSource)
	{
		case Source:
			{// environment
				SQLHANDLE hEnv = SQL_NULL_HANDLE;
				SQLHANDLE hDbc = SQL_NULL_HANDLE;
				r = ::SQLAllocHandle(SQL_HANDLE_ENV, SQL_NULL_HANDLE, &hEnv);
				if (r == SQL_SUCCESS) isValid = true;

				foreach(nOdbcAttributesClass * k, this->m_OdbcAttributes_Map)
				{
					if (k->attributeType == enumAttributeType::hEnv)
					{
						r = ::SQLSetEnvAttr(hEnv, (SQLINTEGER) k->odbcKey, (SQLPOINTER)k->odbcValue, 0);
						if (r == SQL_SUCCESS) isValid = true;
					}
				}
				hEnv_Source = hEnv;

				r = SQLAllocHandle(SQL_HANDLE_DBC, hEnv, &hDbc);
				if (r == SQL_SUCCESS) isValid = true;
				foreach(nOdbcAttributesClass * k, this->m_OdbcAttributes_Map)
				{
					if (k->attributeType == enumAttributeType::hDbc)
					{
					r = ::SQLSetConnectAttr(hDbc, k->odbcKey, (SQLPOINTER)k->odbcValue, 0);
					if (k->odbcKey == SQL_ATTR_CONNECTION_POOLING && k->odbcValue == SQL_CP_ONE_PER_DRIVER) wConnectOption = SQL_DRIVER_NOPROMPT;
					if (k->odbcKey == SQL_ATTR_CONNECTION_POOLING && k->odbcValue == SQL_CP_ONE_PER_HENV) wConnectOption = SQL_DRIVER_NOPROMPT;
					if (k->odbcKey == SQL_ATTR_CONNECTION_POOLING && k->odbcValue == SQL_CP_DRIVER_AWARE) wConnectOption = SQL_DRIVER_NOPROMPT;
					if (r == SQL_SUCCESS) isValid = true;
					}
				}
				hDbc_source = hDbc;
				if (isValid)
				{
					r = ::SQLDriverConnect(
						hDbc,
						hWnd,
#ifdef UNICODE
						toSQLTCHAR(m_lpszSourceDSN).data(),
#else
						(SQLCHAR*)dsnSource.toUtf8().data(),
#endif
						(SQLSMALLINT)m_lpszSourceDSN.length(),
						connOut.data(),
						1024,
						&cb, 
						wConnectOption); 
					int colSize = cb / sizeof(SQLTCHAR);
					if (r != SQL_SUCCESS && r != SQL_SUCCESS_WITH_INFO)
					{
						QString check = qWarnODBCHandle(SQL_HANDLE_DBC, hDbc);
						qCritical(category) <<  check;
						m_bIsOpen = false;
					}
					m_bIsOpen = true;
				}
			} break;
		case Target:
			{
				SQLHANDLE hEnv = SQL_NULL_HANDLE;
				SQLHANDLE hDbc = SQL_NULL_HANDLE;
				r = ::SQLAllocHandle(SQL_HANDLE_ENV, SQL_NULL_HANDLE, &hEnv);
				if (r == SQL_SUCCESS) isValid = true;

				foreach(nOdbcAttributesClass * k, this->m_OdbcAttributes_Map)
				{
					if (k->attributeType == enumAttributeType::hEnv)
					{
						r = ::SQLSetEnvAttr(hEnv, (SQLINTEGER) k->odbcKey, (SQLPOINTER)k->odbcValue, 0);
						if (r == SQL_SUCCESS) isValid = true;
					}
				}
				hEnv_Target = hEnv;

				r = SQLAllocHandle(SQL_HANDLE_DBC, hEnv, &hDbc);
				if (r == SQL_SUCCESS) isValid = true;
				foreach(nOdbcAttributesClass * k, this->m_OdbcAttributes_Map)
				{
				if (k->attributeType == enumAttributeType::hDbc)
					{
					r = ::SQLSetConnectAttr(hDbc, k->odbcKey, (SQLPOINTER)k->odbcValue, 0);
					if (k->odbcKey == SQL_ATTR_CONNECTION_POOLING && k->odbcValue == SQL_CP_ONE_PER_DRIVER) wConnectOption = SQL_DRIVER_NOPROMPT;
					if (k->odbcKey == SQL_ATTR_CONNECTION_POOLING && k->odbcValue == SQL_CP_ONE_PER_HENV) wConnectOption = SQL_DRIVER_NOPROMPT;
					if (k->odbcKey == SQL_ATTR_CONNECTION_POOLING && k->odbcValue == SQL_CP_DRIVER_AWARE) wConnectOption = SQL_DRIVER_NOPROMPT;
					if (r == SQL_SUCCESS) isValid = true;
					}
				}
				hDbc_target = hDbc;
				if (isValid) {
					r = ::SQLDriverConnect(
						hDbc,
						hWnd,
#ifdef UNICODE
						toSQLTCHAR(m_lpszTargetDSN).data(),
#else
						(SQLCHAR*)m_lpszTargetDSN.toUtf8().data(),
#endif
						(SQLSMALLINT)m_lpszTargetDSN.length(),
						connOut.data(),
						1024,
						&cb, 
						wConnectOption); 
						int colSize = cb / sizeof(SQLTCHAR);
					if (r != SQL_SUCCESS && r != SQL_SUCCESS_WITH_INFO)
						{
							QString check = qWarnODBCHandle(SQL_HANDLE_DBC, hDbc);
							qCritical(category) <<  check;
							m_bIsOpen = false;
						}
							m_bIsOpen = true;
					}
			} break;
			default: break;
	}
}
TK_LOTLIDSET::TK_LOTLIDSET(QObject * parent) : QObject(parent) 
,tableName("TK_LOTLIDSET")
,m_dropOption(DropOption::DropTable) { 
	numRowsFetched = 0;
}

#pragma region ~CTOR TK_LOTLIDSET 
TK_LOTLIDSET::~TK_LOTLIDSET() { 

#pragma region Buffers - Clear 
	DB_ID.clear();
	NVTIMESTAMP.clear();
	OAREA.clear();
	OPAGE.clear();
	OLINE.clear();
	MAREA.clear();
	MPAGE.clear();
	MLINE.clear();
#pragma endregion Buffers - Clear 
}
#pragma endregion Destructor_TK_LOTLIDSET

// begin method functions
void TK_LOTLIDSET::setAbortFlag() { 
	QLoggingCategory category("classLibQ");
	qCInfo(category) << "isAbort was set to True";
	bIsAbort = true;
}

void TK_LOTLIDSET::run() { 
	process(1);
	QLoggingCategory category("classLibQ");
	qDebug(category) << "Entered;";
}

void	TK_LOTLIDSET::initOdbcAttributes()
{
	QLoggingCategory category("classLibQ");
	this->setProfileName(profileName);
	qDebug(category) << "Processing - TRKDB100"; 
	m_OdbcAttributesList = m_OdbcAttributes.split(","); 
	foreach(QString m, m_OdbcAttributesList)
	{
		QStringList keyValue = m.split("=");
		nOdbcAttributesClass * oM = new nOdbcAttributesClass(this);
		if (oM->loadToOdbc(keyValue.value(0), keyValue.value(1)))
		{
			m_OdbcAttributes_Map.insert(oM->odbcKey, oM);
		}
	}
}
void	TK_LOTLIDSET::initialize()
{
	QLoggingCategory category("classLibQ");
	RETCODE r;
	this->setProfileName(profileName);
	qDebug(category) << "Processing - TRKDB100"; 
//SQL Statements
//--------------------------------------------------

#pragma region Sql Statements_TK_LOTLIDSET

	fetchSql = "select  DB_ID, NVTIMESTAMP, OAREA, OPAGE, OLINE, MAREA, MPAGE, MLINE from TK_LOTLIDSET";
		if (m_ReplicationOption == ReplicationOption::NetChange)
		{
			fetchSql.append(" p1, nv_transfers p2 WHERE  p2.table_name = 'TK_LOTLIDSET' AND p1.nvtimestamp > p2.last_completed");
		}
	insertSql = "insert into TK_LOTLIDSET ( PLANT_CODE, NVTIMESTAMP, OAREA, OPAGE, OLINE, MAREA, MPAGE, MLINE ) values ( ?, ?, ?, ?, ?, ?, ?, ?)";
	updateSql = "update TK_LOTLIDSET set  PLANT_CODE = ?, NVTIMESTAMP = ?, OAREA = ?, OPAGE = ?, OLINE = ?, MAREA = ?, MPAGE = ?, MLINE = ?  where area = ? and page = ? line = ? ";

	qDebug(category) << "insertSQL - insert into TK_LOTLIDSET ( PLANT_CODE, NVTIMESTAMP, OAREA, OPAGE, OLINE, MAREA, MPAGE, MLINE ) values ( ?, ?, ?, ?, ?, ?, ?, ?)";
	qDebug(category) << "fetchSQL - select  DB_ID, NVTIMESTAMP, OAREA, OPAGE, OLINE, MAREA, MPAGE, MLINE from TK_LOTLIDSET";
	qDebug(category) << "unsertSQL - update TK_LOTLIDSET set  PLANT_CODE = ?, NVTIMESTAMP = ?, OAREA = ?, OPAGE = ?, OLINE = ?, MAREA = ?, MPAGE = ?, MLINE = ?  where area = ? and page = ? line = ? ";

#pragma endregion Sql Statements_TK_LOTLIDSET
	SQLHANDLE		insert_hStmt = SQL_NULL_HANDLE;
	SQLHANDLE		fetch_hStmt = SQL_NULL_HANDLE; 
	SQLHANDLE		update_hStmt = SQL_NULL_HANDLE; 
 
	r = ::SQLAllocHandle(SQL_HANDLE_STMT, hDbc_source, &fetch_hStmt);
	if (r != SQL_SUCCESS) {
		 qCCritical(category) << QString("Error  hDbc_Source SQLCode : %1 is %2").arg(QString::number( (long)hDbc_source)).arg(QString::number(r));
		return; 
	}
	r = ::SQLAllocHandle(SQL_HANDLE_STMT, hDbc_target, &insert_hStmt);
	if (r != SQL_SUCCESS) {
		 qCCritical(category) << QString("Error hDbc_Source -SQLCode: %1 is %2").arg(QString::number( (long)hDbc_target)).arg(QString::number(r));
		return; 
	}
	r = ::SQLAllocHandle(SQL_HANDLE_STMT, hDbc_target, &update_hStmt);
	if (r != SQL_SUCCESS) {
		 qCCritical(category) << QString("Error hDbc_Source +SQLCode: %1 is %2").arg(QString::number( (long)hDbc_target)).arg(QString::number(r));
		return; 
	}
 
	hStmt_Fetch = fetch_hStmt;
	hStmt_Insert = insert_hStmt;
	hStmt_Update = update_hStmt;
 
	SQLSetStmtAttr(hStmt_Fetch, SQL_ATTR_USE_BOOKMARKS, (SQLPOINTER)SQL_UB_OFF, 0);
	SQLSetStmtAttr(hStmt_Fetch, SQL_ATTR_ROW_BIND_TYPE, (SQLPOINTER)SQL_BIND_BY_COLUMN, 0);
	SQLSetStmtAttr(hStmt_Fetch, SQL_ATTR_ROW_ARRAY_SIZE, (SQLPOINTER)1, 0);
	SQLSetStmtAttr(hStmt_Fetch, SQL_ATTR_ROWS_FETCHED_PTR, &numRowsFetched, 0);

// Fields used by this class 
// ---------------------------------------------------

#pragma region Resize Fields TK_LOTLIDSET
	qDebug(category) << "Malloc - DB_ID[2]";
	DB_ID.resize(2);
	qDebug(category) << "Malloc - NVTIMESTAMP[23]";
	NVTIMESTAMP.resize(23);
	qDebug(category) << "Malloc - OAREA[2]";
	OAREA.resize(2);
	qDebug(category) << "Malloc - OPAGE[4]";
	OPAGE.resize(4);
	qDebug(category) << "Malloc - OLINE[2]";
	OLINE.resize(2);
	qDebug(category) << "Malloc - MAREA[2]";
	MAREA.resize(2);
	qDebug(category) << "Malloc - MPAGE[4]";
	MPAGE.resize(4);
	qDebug(category) << "Malloc - MLINE[2]";
	MLINE.resize(2);

#pragma endregion Resize Fields TK_LOTLIDSET
}
void TK_LOTLIDSET::close()
{
	QLoggingCategory category("classLibQ");
	if (m_bIsOpen)
	{
	qDebug(category) << "database is Open";
		SQLHANDLE source_hStmt = hStmt_Fetch;
		SQLHANDLE insert_hStmt = hStmt_Insert;
		SQLHANDLE hDb_S = this->hDbc_source;
		SQLHANDLE hDb_T = hDbc_target;
		SQLHANDLE hEnvS = hEnv_Source;
		SQLHANDLE hEnvT = hEnv_Target;
		RETCODE r;

		r = ::SQLFreeHandle(SQL_HANDLE_STMT, hStmt_Fetch);
		r = ::SQLFreeHandle(SQL_HANDLE_STMT, hStmt_Insert);
		r = ::SQLFreeHandle(SQL_HANDLE_STMT, hStmt_Update);
		if (hDbc_source != SQL_NULL_HANDLE) 		r = ::SQLDisconnect(hDb_S);
		if (hDbc_target != SQL_NULL_HANDLE) 		r = ::SQLDisconnect(hDb_T);

		r = ::SQLFreeHandle(SQL_HANDLE_DBC, hDb_S);
		r = ::SQLFreeHandle(SQL_HANDLE_DBC, hDb_T);
		r = ::SQLFreeHandle(SQL_HANDLE_ENV, hEnvS);
		r = ::SQLFreeHandle(SQL_HANDLE_ENV, hEnvT);
	}

	hEnv_Source = SQL_NULL_HANDLE;
	hEnv_Target = SQL_NULL_HANDLE;
	hEnv_Source = SQL_NULL_HANDLE;
	hEnv_Target = SQL_NULL_HANDLE;
	hStmt_Fetch = SQL_NULL_HANDLE;
	hStmt_Insert = SQL_NULL_HANDLE;
	hStmt_Update = SQL_NULL_HANDLE;
}

void TK_LOTLIDSET::open(const QString sourceDSN, const QString targetDSN)
{
	QLoggingCategory category("classLibQ");
	m_lpszTargetDSN = targetDSN;
	m_lpszSourceDSN = sourceDSN;
	qDebug(category) << QString("Source - %1[%2]").arg(sourceDSN);
	qDebug(category) << QString("Target - %1[%2]").arg(targetDSN);
}

void TK_LOTLIDSET::createTable()
{
	QLoggingCategory category("classLibQ");
	{
		QScopedPointer<nvTableOracleRdb> tbl(new nvTableOracleRdb(nullptr));
		tbl->initialize("TK_LOTLIDSET", this->m_lpszSourceDSN);
		QString newTbl = tbl->getCreateTableSQL();
		QScopedPointer<qVtExecute> vExec(new qVtExecute(nullptr));
		{
			vExec->initialize(m_lpszTargetDSN, " ", true);
			vExec->setOdbcAttributes(m_OdbcAttributes);
			vExec->ExecuteDirect(newTbl);
		}
	 qDebug(category) << QString("End Create Table %1 ").arg(tableName); 
	}
}

bool TK_LOTLIDSET::prepare()
{
	RETCODE r;
	QString check;
	QLoggingCategory category("classLibQ");
	 qDebug(category) << fetchSql;
	 qDebug(category) << insertSql;
#ifdef UNICODE
	r = SQLPrepare(hStmt_Insert,toSQLTCHAR(insertSql).data(),(SQLINTEGER)insertSql.length()); 
	if (r != SQL_SUCCESS) {
		check = qWarnODBCHandle(SQL_HANDLE_STMT, hStmt_Insert);
		 qCCritical(category) << QString("Prepare Statement-Insert : %1 is %2").arg(insertSql).arg(check);
		return false; 
	}
	r = SQLPrepare(hStmt_Update,toSQLTCHAR(updateSql).data(),(SQLINTEGER)updateSql.length()); 
	if (r != SQL_SUCCESS) {
		check = qWarnODBCHandle(SQL_HANDLE_STMT, hStmt_Update);
		 qCCritical(category) << QString("Prepare Statement-Update : %1 is %2").arg(updateSql).arg(check);
		return false; 
	}
	r = SQLPrepare(hStmt_Fetch,toSQLTCHAR(fetchSql).data(),(SQLINTEGER)fetchSql.length());
	if (r != SQL_SUCCESS) {
		check = qWarnODBCHandle(SQL_HANDLE_STMT, hStmt_Fetch);
		 qCCritical(category) << QString("Prepare Statement-Insert : %1 is %2").arg(fetchSql).arg(check);
		return false; 
	}
#else
	QByteArray queryI8 = insertSql.toUtf8();
	r = SQLPrepare(insert_hStmt,SQLCHAR*)queryI8.data(),(SQLINTEGER)queryI8.length());
	QByteArray queryU8 = fetchSql.toUtf8();
	r = SQLPrepare(hStmt_Fetch,(SQLCHAR*)queryU8.data(),(SQLINTEGER)queryU8.length());
#endif
	return true;

}

void TK_LOTLIDSET::prepareTargetTable()
{
	QLoggingCategory category("classLibQ");
	if (this->m_ReplicationOption == ReplicationOption::BulkCopy)
	{
		QScopedPointer<qVtExecute> execSql(new qVtExecute(nullptr));
		DropOption option = this->m_dropOption;
		switch (option)
		{
			case DropOption::DeleteFromTable:
			{
				QLoggingCategory category("classLibQ");
				execSql->initialize(this->m_lpszTargetDSN, "delete from TK_LOTLIDSET", true);
				execSql->setOdbcAttributes(this->m_OdbcAttributes);
				execSql->ExecuteDirect("delete from TK_LOTLIDSET");
			}break;
			case DropOption::TruncateTable:
			{
				execSql->initialize(this->m_lpszTargetDSN, "truncate table TK_LOTLIDSET", true);
				execSql->setOdbcAttributes(this->m_OdbcAttributes);
				execSql->ExecuteDirect("truncate table TK_LOTLIDSET");
			}break;
			case DropOption::DropTable:
			{
				execSql->initialize(this->m_lpszTargetDSN, "drop table TK_LOTLIDSET", true);
				execSql->setOdbcAttributes(this->m_OdbcAttributes);
				execSql->ExecuteDirect("drop table TK_LOTLIDSET");
				createTable();
			}break;
		}
	}
}

bool TK_LOTLIDSET::bindColumn()
{
	QLoggingCategory category("classLibQ");
	RETCODE r;
	bool isValid=true;
		 qDebug(category) << " Bindings: Ordinal [1] Type: 5 Buffer Size: 2 FieldName: DB_ID ";
		r = ::SQLBindCol(hStmt_Fetch, 1, 5, DB_ID.data(), 2, &cbDB_ID);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Bindings: Ordinal [2] Type: 93 Buffer Size: 23 FieldName: NVTIMESTAMP ";
		r = ::SQLBindCol(hStmt_Fetch, 2, 93, NVTIMESTAMP.data(), 23, &cbNVTIMESTAMP);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Bindings: Ordinal [3] Type: 5 Buffer Size: 2 FieldName: OAREA ";
		r = ::SQLBindCol(hStmt_Fetch, 3, 5, OAREA.data(), 2, &cbOAREA);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Bindings: Ordinal [4] Type: 4 Buffer Size: 4 FieldName: OPAGE ";
		r = ::SQLBindCol(hStmt_Fetch, 4, 4, OPAGE.data(), 4, &cbOPAGE);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Bindings: Ordinal [5] Type: 5 Buffer Size: 2 FieldName: OLINE ";
		r = ::SQLBindCol(hStmt_Fetch, 5, 5, OLINE.data(), 2, &cbOLINE);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Bindings: Ordinal [6] Type: 5 Buffer Size: 2 FieldName: MAREA ";
		r = ::SQLBindCol(hStmt_Fetch, 6, 5, MAREA.data(), 2, &cbMAREA);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Bindings: Ordinal [7] Type: 4 Buffer Size: 4 FieldName: MPAGE ";
		r = ::SQLBindCol(hStmt_Fetch, 7, 4, MPAGE.data(), 4, &cbMPAGE);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Bindings: Ordinal [8] Type: 5 Buffer Size: 2 FieldName: MLINE ";
		r = ::SQLBindCol(hStmt_Fetch, 8, 5, MLINE.data(), 2, &cbMLINE);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
	return isValid;
}

bool TK_LOTLIDSET::bindParameter()
{
	QLoggingCategory category("classLibQ");
	RETCODE r;
	bool isValid=true;
	{
		 qDebug(category) << " Parameters: Ordinal [1] Type: 5 Buffer Size: 2 FieldName: DB_ID ";
		r = SQLBindParameter(hStmt_Insert, 1, SQL_PARAM_INPUT, SQL_C_DEFAULT, 5, 0, 0, (SQLPOINTER)DB_ID.constData(), 0, &cbDB_ID);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Parameters: Ordinal [2] Type: 93 Buffer Size: 23 FieldName: NVTIMESTAMP ";
		r = SQLBindParameter(hStmt_Insert, 2, SQL_PARAM_INPUT, SQL_C_DEFAULT, 93, 23, 0, (SQLPOINTER)NVTIMESTAMP.constData(), 0, &cbNVTIMESTAMP);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Parameters: Ordinal [3] Type: 5 Buffer Size: 2 FieldName: OAREA ";
		r = SQLBindParameter(hStmt_Insert, 3, SQL_PARAM_INPUT, SQL_C_DEFAULT, 5, 0, 0, (SQLPOINTER)OAREA.constData(), 0, &cbOAREA);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Parameters: Ordinal [4] Type: 4 Buffer Size: 4 FieldName: OPAGE ";
		r = SQLBindParameter(hStmt_Insert, 4, SQL_PARAM_INPUT, SQL_C_DEFAULT, 4, 0, 0, (SQLPOINTER)OPAGE.constData(), 0, &cbOPAGE);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Parameters: Ordinal [5] Type: 5 Buffer Size: 2 FieldName: OLINE ";
		r = SQLBindParameter(hStmt_Insert, 5, SQL_PARAM_INPUT, SQL_C_DEFAULT, 5, 0, 0, (SQLPOINTER)OLINE.constData(), 0, &cbOLINE);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Parameters: Ordinal [6] Type: 5 Buffer Size: 2 FieldName: MAREA ";
		r = SQLBindParameter(hStmt_Insert, 6, SQL_PARAM_INPUT, SQL_C_DEFAULT, 5, 0, 0, (SQLPOINTER)MAREA.constData(), 0, &cbMAREA);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Parameters: Ordinal [7] Type: 4 Buffer Size: 4 FieldName: MPAGE ";
		r = SQLBindParameter(hStmt_Insert, 7, SQL_PARAM_INPUT, SQL_C_DEFAULT, 4, 0, 0, (SQLPOINTER)MPAGE.constData(), 0, &cbMPAGE);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Parameters: Ordinal [8] Type: 5 Buffer Size: 2 FieldName: MLINE ";
		r = SQLBindParameter(hStmt_Insert, 8, SQL_PARAM_INPUT, SQL_C_DEFAULT, 5, 0, 0, (SQLPOINTER)MLINE.constData(), 0, &cbMLINE);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
	}
	if (m_ReplicationOption == ReplicationOption::NetChange)
	{
		r = SQLBindParameter(hStmt_Update, 9, SQL_PARAM_INPUT, SQL_C_DEFAULT, 6, 0, 0, (SQLPOINTER)MAREA.constData(), 0, &cbMAREA);
		if (r == SQL_SUCCESS) { isValid=true; }
		r = SQLBindParameter(hStmt_Update, 10, SQL_PARAM_INPUT, SQL_C_DEFAULT, 7, 0, 0, (SQLPOINTER)MPAGE.constData(), 0, &cbMPAGE);
		if (r == SQL_SUCCESS) { isValid=true; }
		r = SQLBindParameter(hStmt_Update, 11, SQL_PARAM_INPUT, SQL_C_DEFAULT, 8, 0, 0, (SQLPOINTER)MLINE.constData(), 0, &cbMLINE);
		if (r == SQL_SUCCESS) { isValid=true; }
	// TK_LOTLIDSET is a well formed table for eNVy Replication 
		 qDebug(category) << " Parameters: Ordinal [6] 00 00 FieldName: MAREA ";
		 qDebug(category) << " Parameters: Ordinal [7] 00 00  FieldName: MPAGE ";
		 qDebug(category) << " Parameters: Ordinal [8] 00 00 FieldName:  MLINE ";
	} // 	if (m_ReplicationOption == ReplicationOption::NetChange)
	return isValid;
}

bool TK_LOTLIDSET::process(int rowSize)
{
	QLoggingCategory category("classLibQ");
	initOdbcAttributes();
	connect(Source);
	connect(Target);
	initialize();
	prepareTargetTable();
	prepare();
	bindColumn();
	bindParameter();
	copyTable();
	close();
	return false;
}

void TK_LOTLIDSET::copyTable()
{
	QLoggingCategory category("classLibQ");
	RETCODE r;
	QString check;
	r = SQLExecute(hStmt_Fetch);
		if (bIsAbort) {
			emit aborted(tableName, rowsFetched, rowsInserted, rowsUpdated);
			return;
		}
		while((r = SQLFetch(hStmt_Fetch)) != SQL_NO_DATA) {
		if (r != SQL_SUCCESS) {
			check = qWarnODBCHandle(SQL_HANDLE_STMT, hStmt_Fetch);
			qCCritical(category) << QString("SqlFetch - Error : %1 is %2").arg(fetchSql).arg(check);
			return;
		} 
		rowsFetched++;
		if (m_ReplicationOption == ReplicationOption::BulkCopy)
		{
			r = SQLExecute(hStmt_Insert);
			if (r == SQL_ERROR) {
				check = qWarnODBCHandle(SQL_HANDLE_STMT, hStmt_Insert);
				 qCCritical(category) << QString("SqlExecute:Insert - Error : %1 is %2").arg(insertSql).arg(check);
				return;
			}
			rowsInserted++;
			if ((rowsFetched % updateInterval) == 0) {
				qCInfo(category) << QString("[%1.%2]	Insertion: %3	Updates : %4	Fetched : %5").arg(profileName).arg(tableName).arg(rowsInserted).arg(rowsUpdated).arg(rowsFetched);
				emit updateStatusFetched(profileName, tableName, rowsFetched,rowsInserted,rowsUpdated);
			}
			if (m_ReplicationOption == ReplicationOption::NetChange)
			{
			r = SQLExecute(hStmt_Update);
			if (r != SQL_SUCCESS) {
				check = qWarnODBCHandle(SQL_HANDLE_STMT, hStmt_Update);
				 qCInfo(category)  << QString("SqlExecute:Update - Error : %1 is %2").arg(updateSql).arg(check);
				r = SQLExecute(hStmt_Insert);
				if (r != SQL_SUCCESS) {
					check = qWarnODBCHandle(SQL_HANDLE_STMT, hStmt_Insert);
					 qCritical(category) << QString("SqlExecute:Insert - Error : %1 is %2").arg(insertSql).arg(check);
					return;
				}
				else 	rowsInserted++;
				}
				else	rowsUpdated++;
			}
			emit updateStatusFetched(profileName, tableName, rowsFetched,rowsInserted,rowsUpdated);
		}
	} 
qCInfo(category) << QString("[%1.%2]	Insertion: %3	Updates : %4	Fetched : %5").arg(profileName).arg(tableName).arg(rowsInserted).arg(rowsUpdated).arg(rowsFetched);
}

void TK_LOTLIDSET::connect(connectionHandle connectionSource)
{

	QLoggingCategory category("classLibQ");
	RETCODE r;

	bool isValid = false;
	HWND	hWnd = nullptr;
	hWnd = ::GetDesktopWindow(); 
	SQLSMALLINT nResult = 0;

	SQLSMALLINT cb;
	UWORD wConnectOption = SQL_DRIVER_COMPLETE; //SQL_DRIVER_NOPROMPT;
	QVarLengthArray<SQLTCHAR> connOut(1024);
	memset(connOut.data(), 0, connOut.size() * sizeof(SQLTCHAR));

	switch (connectionSource)
	{
		case Source:
			{// environment
				SQLHANDLE hEnv = SQL_NULL_HANDLE;
				SQLHANDLE hDbc = SQL_NULL_HANDLE;
				r = ::SQLAllocHandle(SQL_HANDLE_ENV, SQL_NULL_HANDLE, &hEnv);
				if (r == SQL_SUCCESS) isValid = true;

				foreach(nOdbcAttributesClass * k, this->m_OdbcAttributes_Map)
				{
					if (k->attributeType == enumAttributeType::hEnv)
					{
						r = ::SQLSetEnvAttr(hEnv, (SQLINTEGER) k->odbcKey, (SQLPOINTER)k->odbcValue, 0);
						if (r == SQL_SUCCESS) isValid = true;
					}
				}
				hEnv_Source = hEnv;

				r = SQLAllocHandle(SQL_HANDLE_DBC, hEnv, &hDbc);
				if (r == SQL_SUCCESS) isValid = true;
				foreach(nOdbcAttributesClass * k, this->m_OdbcAttributes_Map)
				{
					if (k->attributeType == enumAttributeType::hDbc)
					{
					r = ::SQLSetConnectAttr(hDbc, k->odbcKey, (SQLPOINTER)k->odbcValue, 0);
					if (k->odbcKey == SQL_ATTR_CONNECTION_POOLING && k->odbcValue == SQL_CP_ONE_PER_DRIVER) wConnectOption = SQL_DRIVER_NOPROMPT;
					if (k->odbcKey == SQL_ATTR_CONNECTION_POOLING && k->odbcValue == SQL_CP_ONE_PER_HENV) wConnectOption = SQL_DRIVER_NOPROMPT;
					if (k->odbcKey == SQL_ATTR_CONNECTION_POOLING && k->odbcValue == SQL_CP_DRIVER_AWARE) wConnectOption = SQL_DRIVER_NOPROMPT;
					if (r == SQL_SUCCESS) isValid = true;
					}
				}
				hDbc_source = hDbc;
				if (isValid)
				{
					r = ::SQLDriverConnect(
						hDbc,
						hWnd,
#ifdef UNICODE
						toSQLTCHAR(m_lpszSourceDSN).data(),
#else
						(SQLCHAR*)dsnSource.toUtf8().data(),
#endif
						(SQLSMALLINT)m_lpszSourceDSN.length(),
						connOut.data(),
						1024,
						&cb, 
						wConnectOption); 
					int colSize = cb / sizeof(SQLTCHAR);
					if (r != SQL_SUCCESS && r != SQL_SUCCESS_WITH_INFO)
					{
						QString check = qWarnODBCHandle(SQL_HANDLE_DBC, hDbc);
						qCritical(category) <<  check;
						m_bIsOpen = false;
					}
					m_bIsOpen = true;
				}
			} break;
		case Target:
			{
				SQLHANDLE hEnv = SQL_NULL_HANDLE;
				SQLHANDLE hDbc = SQL_NULL_HANDLE;
				r = ::SQLAllocHandle(SQL_HANDLE_ENV, SQL_NULL_HANDLE, &hEnv);
				if (r == SQL_SUCCESS) isValid = true;

				foreach(nOdbcAttributesClass * k, this->m_OdbcAttributes_Map)
				{
					if (k->attributeType == enumAttributeType::hEnv)
					{
						r = ::SQLSetEnvAttr(hEnv, (SQLINTEGER) k->odbcKey, (SQLPOINTER)k->odbcValue, 0);
						if (r == SQL_SUCCESS) isValid = true;
					}
				}
				hEnv_Target = hEnv;

				r = SQLAllocHandle(SQL_HANDLE_DBC, hEnv, &hDbc);
				if (r == SQL_SUCCESS) isValid = true;
				foreach(nOdbcAttributesClass * k, this->m_OdbcAttributes_Map)
				{
				if (k->attributeType == enumAttributeType::hDbc)
					{
					r = ::SQLSetConnectAttr(hDbc, k->odbcKey, (SQLPOINTER)k->odbcValue, 0);
					if (k->odbcKey == SQL_ATTR_CONNECTION_POOLING && k->odbcValue == SQL_CP_ONE_PER_DRIVER) wConnectOption = SQL_DRIVER_NOPROMPT;
					if (k->odbcKey == SQL_ATTR_CONNECTION_POOLING && k->odbcValue == SQL_CP_ONE_PER_HENV) wConnectOption = SQL_DRIVER_NOPROMPT;
					if (k->odbcKey == SQL_ATTR_CONNECTION_POOLING && k->odbcValue == SQL_CP_DRIVER_AWARE) wConnectOption = SQL_DRIVER_NOPROMPT;
					if (r == SQL_SUCCESS) isValid = true;
					}
				}
				hDbc_target = hDbc;
				if (isValid) {
					r = ::SQLDriverConnect(
						hDbc,
						hWnd,
#ifdef UNICODE
						toSQLTCHAR(m_lpszTargetDSN).data(),
#else
						(SQLCHAR*)m_lpszTargetDSN.toUtf8().data(),
#endif
						(SQLSMALLINT)m_lpszTargetDSN.length(),
						connOut.data(),
						1024,
						&cb, 
						wConnectOption); 
						int colSize = cb / sizeof(SQLTCHAR);
					if (r != SQL_SUCCESS && r != SQL_SUCCESS_WITH_INFO)
						{
							QString check = qWarnODBCHandle(SQL_HANDLE_DBC, hDbc);
							qCritical(category) <<  check;
							m_bIsOpen = false;
						}
							m_bIsOpen = true;
					}
			} break;
			default: break;
	}
}
TK_LTPREC::TK_LTPREC(QObject * parent) : QObject(parent) 
,tableName("TK_LTPREC")
,m_dropOption(DropOption::DropTable) { 
	numRowsFetched = 0;
}

#pragma region ~CTOR TK_LTPREC 
TK_LTPREC::~TK_LTPREC() { 

#pragma region Buffers - Clear 
	DB_ID.clear();
	NVTIMESTAMP.clear();
	AREA.clear();
	PAGE.clear();
	LINE.clear();
	TK_LTPLOT.clear();
	TK_LTPPRT.clear();
	TK_LTPTYPE.clear();
	TK_LTPKEY1.clear();
	TK_LTPKEY2.clear();
	TK_LTPKEY3.clear();
	TK_LTPSUBTYPE.clear();
	QTY.clear();
	TK_LTPISSQTY.clear();
	TK_LTPSCRPQTY.clear();
	TK_LTPRTVQTY.clear();
	TK_LTPCRDAT.clear();
	TK_LTPISSDAT.clear();
	DAT.clear();
	TK_LTPARCISSQTY.clear();
	TK_LTPARCRECQTY.clear();
	TK_LTPARCSCRPQTY.clear();
	TK_LTPARCRTVQTY.clear();
	TK_LTPPOLINE.clear();
	TK_LIDLOT.clear();
	TK_HDRCODE.clear();
#pragma endregion Buffers - Clear 
}
#pragma endregion Destructor_TK_LTPREC

// begin method functions
void TK_LTPREC::setAbortFlag() { 
	QLoggingCategory category("classLibQ");
	qCInfo(category) << "isAbort was set to True";
	bIsAbort = true;
}

void TK_LTPREC::run() { 
	process(1);
	QLoggingCategory category("classLibQ");
	qDebug(category) << "Entered;";
}

void	TK_LTPREC::initOdbcAttributes()
{
	QLoggingCategory category("classLibQ");
	this->setProfileName(profileName);
	qDebug(category) << "Processing - TRKDB100"; 
	m_OdbcAttributesList = m_OdbcAttributes.split(","); 
	foreach(QString m, m_OdbcAttributesList)
	{
		QStringList keyValue = m.split("=");
		nOdbcAttributesClass * oM = new nOdbcAttributesClass(this);
		if (oM->loadToOdbc(keyValue.value(0), keyValue.value(1)))
		{
			m_OdbcAttributes_Map.insert(oM->odbcKey, oM);
		}
	}
}
void	TK_LTPREC::initialize()
{
	QLoggingCategory category("classLibQ");
	RETCODE r;
	this->setProfileName(profileName);
	qDebug(category) << "Processing - TRKDB100"; 
//SQL Statements
//--------------------------------------------------

#pragma region Sql Statements_TK_LTPREC

	fetchSql = "select  DB_ID, NVTIMESTAMP, AREA, PAGE, LINE, TK_LTPLOT, TK_LTPPRT, TK_LTPTYPE, TK_LTPKEY1, TK_LTPKEY2, TK_LTPKEY3, TK_LTPSUBTYPE, QTY, TK_LTPISSQTY, TK_LTPSCRPQTY, TK_LTPRTVQTY, TK_LTPCRDAT, TK_LTPISSDAT, DAT, TK_LTPARCISSQTY, TK_LTPARCRECQTY, TK_LTPARCSCRPQTY, TK_LTPARCRTVQTY, TK_LTPPOLINE, TK_LIDLOT, TK_HDRCODE from TK_LTPREC";
		if (m_ReplicationOption == ReplicationOption::NetChange)
		{
			fetchSql.append(" p1, nv_transfers p2 WHERE  p2.table_name = 'TK_LTPREC' AND p1.nvtimestamp > p2.last_completed");
		}
	insertSql = "insert into TK_LTPREC ( PLANT_CODE, NVTIMESTAMP, AREA, PAGE, LINE, TK_LTPLOT, TK_LTPPRT, TK_LTPTYPE, TK_LTPKEY1, TK_LTPKEY2, TK_LTPKEY3, TK_LTPSUBTYPE, QTY, TK_LTPISSQTY, TK_LTPSCRPQTY, TK_LTPRTVQTY, TK_LTPCRDAT, TK_LTPISSDAT, DAT, TK_LTPARCISSQTY, TK_LTPARCRECQTY, TK_LTPARCSCRPQTY, TK_LTPARCRTVQTY, TK_LTPPOLINE, TK_LIDLOT, TK_HDRCODE ) values ( ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?)";
	updateSql = "update TK_LTPREC set  PLANT_CODE = ?, NVTIMESTAMP = ?, AREA = ?, PAGE = ?, LINE = ?, TK_LTPLOT = ?, TK_LTPPRT = ?, TK_LTPTYPE = ?, TK_LTPKEY1 = ?, TK_LTPKEY2 = ?, TK_LTPKEY3 = ?, TK_LTPSUBTYPE = ?, QTY = ?, TK_LTPISSQTY = ?, TK_LTPSCRPQTY = ?, TK_LTPRTVQTY = ?, TK_LTPCRDAT = ?, TK_LTPISSDAT = ?, DAT = ?, TK_LTPARCISSQTY = ?, TK_LTPARCRECQTY = ?, TK_LTPARCSCRPQTY = ?, TK_LTPARCRTVQTY = ?, TK_LTPPOLINE = ?, TK_LIDLOT = ?, TK_HDRCODE = ?  where area = ? and page = ? line = ? ";

	qDebug(category) << "insertSQL - insert into TK_LTPREC ( PLANT_CODE, NVTIMESTAMP, AREA, PAGE, LINE, TK_LTPLOT, TK_LTPPRT, TK_LTPTYPE, TK_LTPKEY1, TK_LTPKEY2, TK_LTPKEY3, TK_LTPSUBTYPE, QTY, TK_LTPISSQTY, TK_LTPSCRPQTY, TK_LTPRTVQTY, TK_LTPCRDAT, TK_LTPISSDAT, DAT, TK_LTPARCISSQTY, TK_LTPARCRECQTY, TK_LTPARCSCRPQTY, TK_LTPARCRTVQTY, TK_LTPPOLINE, TK_LIDLOT, TK_HDRCODE ) values ( ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?)";
	qDebug(category) << "fetchSQL - select  DB_ID, NVTIMESTAMP, AREA, PAGE, LINE, TK_LTPLOT, TK_LTPPRT, TK_LTPTYPE, TK_LTPKEY1, TK_LTPKEY2, TK_LTPKEY3, TK_LTPSUBTYPE, QTY, TK_LTPISSQTY, TK_LTPSCRPQTY, TK_LTPRTVQTY, TK_LTPCRDAT, TK_LTPISSDAT, DAT, TK_LTPARCISSQTY, TK_LTPARCRECQTY, TK_LTPARCSCRPQTY, TK_LTPARCRTVQTY, TK_LTPPOLINE, TK_LIDLOT, TK_HDRCODE from TK_LTPREC";
	qDebug(category) << "unsertSQL - update TK_LTPREC set  PLANT_CODE = ?, NVTIMESTAMP = ?, AREA = ?, PAGE = ?, LINE = ?, TK_LTPLOT = ?, TK_LTPPRT = ?, TK_LTPTYPE = ?, TK_LTPKEY1 = ?, TK_LTPKEY2 = ?, TK_LTPKEY3 = ?, TK_LTPSUBTYPE = ?, QTY = ?, TK_LTPISSQTY = ?, TK_LTPSCRPQTY = ?, TK_LTPRTVQTY = ?, TK_LTPCRDAT = ?, TK_LTPISSDAT = ?, DAT = ?, TK_LTPARCISSQTY = ?, TK_LTPARCRECQTY = ?, TK_LTPARCSCRPQTY = ?, TK_LTPARCRTVQTY = ?, TK_LTPPOLINE = ?, TK_LIDLOT = ?, TK_HDRCODE = ?  where area = ? and page = ? line = ? ";

#pragma endregion Sql Statements_TK_LTPREC
	SQLHANDLE		insert_hStmt = SQL_NULL_HANDLE;
	SQLHANDLE		fetch_hStmt = SQL_NULL_HANDLE; 
	SQLHANDLE		update_hStmt = SQL_NULL_HANDLE; 
 
	r = ::SQLAllocHandle(SQL_HANDLE_STMT, hDbc_source, &fetch_hStmt);
	if (r != SQL_SUCCESS) {
		 qCCritical(category) << QString("Error  hDbc_Source SQLCode : %1 is %2").arg(QString::number( (long)hDbc_source)).arg(QString::number(r));
		return; 
	}
	r = ::SQLAllocHandle(SQL_HANDLE_STMT, hDbc_target, &insert_hStmt);
	if (r != SQL_SUCCESS) {
		 qCCritical(category) << QString("Error hDbc_Source -SQLCode: %1 is %2").arg(QString::number( (long)hDbc_target)).arg(QString::number(r));
		return; 
	}
	r = ::SQLAllocHandle(SQL_HANDLE_STMT, hDbc_target, &update_hStmt);
	if (r != SQL_SUCCESS) {
		 qCCritical(category) << QString("Error hDbc_Source +SQLCode: %1 is %2").arg(QString::number( (long)hDbc_target)).arg(QString::number(r));
		return; 
	}
 
	hStmt_Fetch = fetch_hStmt;
	hStmt_Insert = insert_hStmt;
	hStmt_Update = update_hStmt;
 
	SQLSetStmtAttr(hStmt_Fetch, SQL_ATTR_USE_BOOKMARKS, (SQLPOINTER)SQL_UB_OFF, 0);
	SQLSetStmtAttr(hStmt_Fetch, SQL_ATTR_ROW_BIND_TYPE, (SQLPOINTER)SQL_BIND_BY_COLUMN, 0);
	SQLSetStmtAttr(hStmt_Fetch, SQL_ATTR_ROW_ARRAY_SIZE, (SQLPOINTER)1, 0);
	SQLSetStmtAttr(hStmt_Fetch, SQL_ATTR_ROWS_FETCHED_PTR, &numRowsFetched, 0);

// Fields used by this class 
// ---------------------------------------------------

#pragma region Resize Fields TK_LTPREC
	qDebug(category) << "Malloc - DB_ID[2]";
	DB_ID.resize(2);
	qDebug(category) << "Malloc - NVTIMESTAMP[23]";
	NVTIMESTAMP.resize(23);
	qDebug(category) << "Malloc - AREA[2]";
	AREA.resize(2);
	qDebug(category) << "Malloc - PAGE[4]";
	PAGE.resize(4);
	qDebug(category) << "Malloc - LINE[2]";
	LINE.resize(2);
	qDebug(category) << "Malloc - TK_LTPLOT[24]";
	TK_LTPLOT.resize(24);
	qDebug(category) << "Malloc - TK_LTPPRT[18]";
	TK_LTPPRT.resize(18);
	qDebug(category) << "Malloc - TK_LTPTYPE[2]";
	TK_LTPTYPE.resize(2);
	qDebug(category) << "Malloc - TK_LTPKEY1[10]";
	TK_LTPKEY1.resize(10);
	qDebug(category) << "Malloc - TK_LTPKEY2[10]";
	TK_LTPKEY2.resize(10);
	qDebug(category) << "Malloc - TK_LTPKEY3[24]";
	TK_LTPKEY3.resize(24);
	qDebug(category) << "Malloc - TK_LTPSUBTYPE[2]";
	TK_LTPSUBTYPE.resize(2);
	qDebug(category) << "Malloc - QTY[8]";
	QTY.resize(8);
	qDebug(category) << "Malloc - TK_LTPISSQTY[8]";
	TK_LTPISSQTY.resize(8);
	qDebug(category) << "Malloc - TK_LTPSCRPQTY[8]";
	TK_LTPSCRPQTY.resize(8);
	qDebug(category) << "Malloc - TK_LTPRTVQTY[8]";
	TK_LTPRTVQTY.resize(8);
	qDebug(category) << "Malloc - TK_LTPCRDAT[4]";
	TK_LTPCRDAT.resize(4);
	qDebug(category) << "Malloc - TK_LTPISSDAT[4]";
	TK_LTPISSDAT.resize(4);
	qDebug(category) << "Malloc - DAT[4]";
	DAT.resize(4);
	qDebug(category) << "Malloc - TK_LTPARCISSQTY[8]";
	TK_LTPARCISSQTY.resize(8);
	qDebug(category) << "Malloc - TK_LTPARCRECQTY[8]";
	TK_LTPARCRECQTY.resize(8);
	qDebug(category) << "Malloc - TK_LTPARCSCRPQTY[8]";
	TK_LTPARCSCRPQTY.resize(8);
	qDebug(category) << "Malloc - TK_LTPARCRTVQTY[8]";
	TK_LTPARCRTVQTY.resize(8);
	qDebug(category) << "Malloc - TK_LTPPOLINE[4]";
	TK_LTPPOLINE.resize(4);
	qDebug(category) << "Malloc - TK_LIDLOT[24]";
	TK_LIDLOT.resize(24);
	qDebug(category) << "Malloc - TK_HDRCODE[2]";
	TK_HDRCODE.resize(2);

#pragma endregion Resize Fields TK_LTPREC
}
void TK_LTPREC::close()
{
	QLoggingCategory category("classLibQ");
	if (m_bIsOpen)
	{
	qDebug(category) << "database is Open";
		SQLHANDLE source_hStmt = hStmt_Fetch;
		SQLHANDLE insert_hStmt = hStmt_Insert;
		SQLHANDLE hDb_S = this->hDbc_source;
		SQLHANDLE hDb_T = hDbc_target;
		SQLHANDLE hEnvS = hEnv_Source;
		SQLHANDLE hEnvT = hEnv_Target;
		RETCODE r;

		r = ::SQLFreeHandle(SQL_HANDLE_STMT, hStmt_Fetch);
		r = ::SQLFreeHandle(SQL_HANDLE_STMT, hStmt_Insert);
		r = ::SQLFreeHandle(SQL_HANDLE_STMT, hStmt_Update);
		if (hDbc_source != SQL_NULL_HANDLE) 		r = ::SQLDisconnect(hDb_S);
		if (hDbc_target != SQL_NULL_HANDLE) 		r = ::SQLDisconnect(hDb_T);

		r = ::SQLFreeHandle(SQL_HANDLE_DBC, hDb_S);
		r = ::SQLFreeHandle(SQL_HANDLE_DBC, hDb_T);
		r = ::SQLFreeHandle(SQL_HANDLE_ENV, hEnvS);
		r = ::SQLFreeHandle(SQL_HANDLE_ENV, hEnvT);
	}

	hEnv_Source = SQL_NULL_HANDLE;
	hEnv_Target = SQL_NULL_HANDLE;
	hEnv_Source = SQL_NULL_HANDLE;
	hEnv_Target = SQL_NULL_HANDLE;
	hStmt_Fetch = SQL_NULL_HANDLE;
	hStmt_Insert = SQL_NULL_HANDLE;
	hStmt_Update = SQL_NULL_HANDLE;
}

void TK_LTPREC::open(const QString sourceDSN, const QString targetDSN)
{
	QLoggingCategory category("classLibQ");
	m_lpszTargetDSN = targetDSN;
	m_lpszSourceDSN = sourceDSN;
	qDebug(category) << QString("Source - %1[%2]").arg(sourceDSN);
	qDebug(category) << QString("Target - %1[%2]").arg(targetDSN);
}

void TK_LTPREC::createTable()
{
	QLoggingCategory category("classLibQ");
	{
		QScopedPointer<nvTableOracleRdb> tbl(new nvTableOracleRdb(nullptr));
		tbl->initialize("TK_LTPREC", this->m_lpszSourceDSN);
		QString newTbl = tbl->getCreateTableSQL();
		QScopedPointer<qVtExecute> vExec(new qVtExecute(nullptr));
		{
			vExec->initialize(m_lpszTargetDSN, " ", true);
			vExec->setOdbcAttributes(m_OdbcAttributes);
			vExec->ExecuteDirect(newTbl);
		}
	 qDebug(category) << QString("End Create Table %1 ").arg(tableName); 
	}
}

bool TK_LTPREC::prepare()
{
	RETCODE r;
	QString check;
	QLoggingCategory category("classLibQ");
	 qDebug(category) << fetchSql;
	 qDebug(category) << insertSql;
#ifdef UNICODE
	r = SQLPrepare(hStmt_Insert,toSQLTCHAR(insertSql).data(),(SQLINTEGER)insertSql.length()); 
	if (r != SQL_SUCCESS) {
		check = qWarnODBCHandle(SQL_HANDLE_STMT, hStmt_Insert);
		 qCCritical(category) << QString("Prepare Statement-Insert : %1 is %2").arg(insertSql).arg(check);
		return false; 
	}
	r = SQLPrepare(hStmt_Update,toSQLTCHAR(updateSql).data(),(SQLINTEGER)updateSql.length()); 
	if (r != SQL_SUCCESS) {
		check = qWarnODBCHandle(SQL_HANDLE_STMT, hStmt_Update);
		 qCCritical(category) << QString("Prepare Statement-Update : %1 is %2").arg(updateSql).arg(check);
		return false; 
	}
	r = SQLPrepare(hStmt_Fetch,toSQLTCHAR(fetchSql).data(),(SQLINTEGER)fetchSql.length());
	if (r != SQL_SUCCESS) {
		check = qWarnODBCHandle(SQL_HANDLE_STMT, hStmt_Fetch);
		 qCCritical(category) << QString("Prepare Statement-Insert : %1 is %2").arg(fetchSql).arg(check);
		return false; 
	}
#else
	QByteArray queryI8 = insertSql.toUtf8();
	r = SQLPrepare(insert_hStmt,SQLCHAR*)queryI8.data(),(SQLINTEGER)queryI8.length());
	QByteArray queryU8 = fetchSql.toUtf8();
	r = SQLPrepare(hStmt_Fetch,(SQLCHAR*)queryU8.data(),(SQLINTEGER)queryU8.length());
#endif
	return true;

}

void TK_LTPREC::prepareTargetTable()
{
	QLoggingCategory category("classLibQ");
	if (this->m_ReplicationOption == ReplicationOption::BulkCopy)
	{
		QScopedPointer<qVtExecute> execSql(new qVtExecute(nullptr));
		DropOption option = this->m_dropOption;
		switch (option)
		{
			case DropOption::DeleteFromTable:
			{
				QLoggingCategory category("classLibQ");
				execSql->initialize(this->m_lpszTargetDSN, "delete from TK_LTPREC", true);
				execSql->setOdbcAttributes(this->m_OdbcAttributes);
				execSql->ExecuteDirect("delete from TK_LTPREC");
			}break;
			case DropOption::TruncateTable:
			{
				execSql->initialize(this->m_lpszTargetDSN, "truncate table TK_LTPREC", true);
				execSql->setOdbcAttributes(this->m_OdbcAttributes);
				execSql->ExecuteDirect("truncate table TK_LTPREC");
			}break;
			case DropOption::DropTable:
			{
				execSql->initialize(this->m_lpszTargetDSN, "drop table TK_LTPREC", true);
				execSql->setOdbcAttributes(this->m_OdbcAttributes);
				execSql->ExecuteDirect("drop table TK_LTPREC");
				createTable();
			}break;
		}
	}
}

bool TK_LTPREC::bindColumn()
{
	QLoggingCategory category("classLibQ");
	RETCODE r;
	bool isValid=true;
		 qDebug(category) << " Bindings: Ordinal [1] Type: 5 Buffer Size: 2 FieldName: DB_ID ";
		r = ::SQLBindCol(hStmt_Fetch, 1, 5, DB_ID.data(), 2, &cbDB_ID);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Bindings: Ordinal [2] Type: 93 Buffer Size: 23 FieldName: NVTIMESTAMP ";
		r = ::SQLBindCol(hStmt_Fetch, 2, 93, NVTIMESTAMP.data(), 23, &cbNVTIMESTAMP);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Bindings: Ordinal [3] Type: 5 Buffer Size: 2 FieldName: AREA ";
		r = ::SQLBindCol(hStmt_Fetch, 3, 5, AREA.data(), 2, &cbAREA);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Bindings: Ordinal [4] Type: 4 Buffer Size: 4 FieldName: PAGE ";
		r = ::SQLBindCol(hStmt_Fetch, 4, 4, PAGE.data(), 4, &cbPAGE);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Bindings: Ordinal [5] Type: 5 Buffer Size: 2 FieldName: LINE ";
		r = ::SQLBindCol(hStmt_Fetch, 5, 5, LINE.data(), 2, &cbLINE);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Bindings: Ordinal [6] Type: 1 Buffer Size: 24 FieldName: TK_LTPLOT ";
		r = ::SQLBindCol(hStmt_Fetch, 6, 1, TK_LTPLOT.data(), 24, &cbTK_LTPLOT);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Bindings: Ordinal [7] Type: 1 Buffer Size: 18 FieldName: TK_LTPPRT ";
		r = ::SQLBindCol(hStmt_Fetch, 7, 1, TK_LTPPRT.data(), 18, &cbTK_LTPPRT);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Bindings: Ordinal [8] Type: 5 Buffer Size: 2 FieldName: TK_LTPTYPE ";
		r = ::SQLBindCol(hStmt_Fetch, 8, 5, TK_LTPTYPE.data(), 2, &cbTK_LTPTYPE);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Bindings: Ordinal [9] Type: 1 Buffer Size: 10 FieldName: TK_LTPKEY1 ";
		r = ::SQLBindCol(hStmt_Fetch, 9, 1, TK_LTPKEY1.data(), 10, &cbTK_LTPKEY1);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Bindings: Ordinal [10] Type: 1 Buffer Size: 10 FieldName: TK_LTPKEY2 ";
		r = ::SQLBindCol(hStmt_Fetch, 10, 1, TK_LTPKEY2.data(), 10, &cbTK_LTPKEY2);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Bindings: Ordinal [11] Type: 1 Buffer Size: 24 FieldName: TK_LTPKEY3 ";
		r = ::SQLBindCol(hStmt_Fetch, 11, 1, TK_LTPKEY3.data(), 24, &cbTK_LTPKEY3);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Bindings: Ordinal [12] Type: 5 Buffer Size: 2 FieldName: TK_LTPSUBTYPE ";
		r = ::SQLBindCol(hStmt_Fetch, 12, 5, TK_LTPSUBTYPE.data(), 2, &cbTK_LTPSUBTYPE);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Bindings: Ordinal [13] Type: 8 Buffer Size: 8 FieldName: QTY ";
		r = ::SQLBindCol(hStmt_Fetch, 13, 8, QTY.data(), 8, &cbQTY);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Bindings: Ordinal [14] Type: 8 Buffer Size: 8 FieldName: TK_LTPISSQTY ";
		r = ::SQLBindCol(hStmt_Fetch, 14, 8, TK_LTPISSQTY.data(), 8, &cbTK_LTPISSQTY);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Bindings: Ordinal [15] Type: 8 Buffer Size: 8 FieldName: TK_LTPSCRPQTY ";
		r = ::SQLBindCol(hStmt_Fetch, 15, 8, TK_LTPSCRPQTY.data(), 8, &cbTK_LTPSCRPQTY);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Bindings: Ordinal [16] Type: 8 Buffer Size: 8 FieldName: TK_LTPRTVQTY ";
		r = ::SQLBindCol(hStmt_Fetch, 16, 8, TK_LTPRTVQTY.data(), 8, &cbTK_LTPRTVQTY);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Bindings: Ordinal [17] Type: 4 Buffer Size: 4 FieldName: TK_LTPCRDAT ";
		r = ::SQLBindCol(hStmt_Fetch, 17, 4, TK_LTPCRDAT.data(), 4, &cbTK_LTPCRDAT);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Bindings: Ordinal [18] Type: 4 Buffer Size: 4 FieldName: TK_LTPISSDAT ";
		r = ::SQLBindCol(hStmt_Fetch, 18, 4, TK_LTPISSDAT.data(), 4, &cbTK_LTPISSDAT);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Bindings: Ordinal [19] Type: 4 Buffer Size: 4 FieldName: DAT ";
		r = ::SQLBindCol(hStmt_Fetch, 19, 4, DAT.data(), 4, &cbDAT);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Bindings: Ordinal [20] Type: 8 Buffer Size: 8 FieldName: TK_LTPARCISSQTY ";
		r = ::SQLBindCol(hStmt_Fetch, 20, 8, TK_LTPARCISSQTY.data(), 8, &cbTK_LTPARCISSQTY);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Bindings: Ordinal [21] Type: 8 Buffer Size: 8 FieldName: TK_LTPARCRECQTY ";
		r = ::SQLBindCol(hStmt_Fetch, 21, 8, TK_LTPARCRECQTY.data(), 8, &cbTK_LTPARCRECQTY);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Bindings: Ordinal [22] Type: 8 Buffer Size: 8 FieldName: TK_LTPARCSCRPQTY ";
		r = ::SQLBindCol(hStmt_Fetch, 22, 8, TK_LTPARCSCRPQTY.data(), 8, &cbTK_LTPARCSCRPQTY);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Bindings: Ordinal [23] Type: 8 Buffer Size: 8 FieldName: TK_LTPARCRTVQTY ";
		r = ::SQLBindCol(hStmt_Fetch, 23, 8, TK_LTPARCRTVQTY.data(), 8, &cbTK_LTPARCRTVQTY);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Bindings: Ordinal [24] Type: 4 Buffer Size: 4 FieldName: TK_LTPPOLINE ";
		r = ::SQLBindCol(hStmt_Fetch, 24, 4, TK_LTPPOLINE.data(), 4, &cbTK_LTPPOLINE);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Bindings: Ordinal [25] Type: 1 Buffer Size: 24 FieldName: TK_LIDLOT ";
		r = ::SQLBindCol(hStmt_Fetch, 25, 1, TK_LIDLOT.data(), 24, &cbTK_LIDLOT);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Bindings: Ordinal [26] Type: 5 Buffer Size: 2 FieldName: TK_HDRCODE ";
		r = ::SQLBindCol(hStmt_Fetch, 26, 5, TK_HDRCODE.data(), 2, &cbTK_HDRCODE);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
	return isValid;
}

bool TK_LTPREC::bindParameter()
{
	QLoggingCategory category("classLibQ");
	RETCODE r;
	bool isValid=true;
	{
		 qDebug(category) << " Parameters: Ordinal [1] Type: 5 Buffer Size: 2 FieldName: DB_ID ";
		r = SQLBindParameter(hStmt_Insert, 1, SQL_PARAM_INPUT, SQL_C_DEFAULT, 5, 0, 0, (SQLPOINTER)DB_ID.constData(), 0, &cbDB_ID);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Parameters: Ordinal [2] Type: 93 Buffer Size: 23 FieldName: NVTIMESTAMP ";
		r = SQLBindParameter(hStmt_Insert, 2, SQL_PARAM_INPUT, SQL_C_DEFAULT, 93, 23, 0, (SQLPOINTER)NVTIMESTAMP.constData(), 0, &cbNVTIMESTAMP);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Parameters: Ordinal [3] Type: 5 Buffer Size: 2 FieldName: AREA ";
		r = SQLBindParameter(hStmt_Insert, 3, SQL_PARAM_INPUT, SQL_C_DEFAULT, 5, 0, 0, (SQLPOINTER)AREA.constData(), 0, &cbAREA);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Parameters: Ordinal [4] Type: 4 Buffer Size: 4 FieldName: PAGE ";
		r = SQLBindParameter(hStmt_Insert, 4, SQL_PARAM_INPUT, SQL_C_DEFAULT, 4, 0, 0, (SQLPOINTER)PAGE.constData(), 0, &cbPAGE);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Parameters: Ordinal [5] Type: 5 Buffer Size: 2 FieldName: LINE ";
		r = SQLBindParameter(hStmt_Insert, 5, SQL_PARAM_INPUT, SQL_C_DEFAULT, 5, 0, 0, (SQLPOINTER)LINE.constData(), 0, &cbLINE);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Parameters: Ordinal [6] Type: 1 Buffer Size: 24 FieldName: TK_LTPLOT ";
		r = SQLBindParameter(hStmt_Insert, 6, SQL_PARAM_INPUT, SQL_C_DEFAULT, 1, 24, 0, (SQLPOINTER)TK_LTPLOT.constData(), 0, &cbTK_LTPLOT);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Parameters: Ordinal [7] Type: 1 Buffer Size: 18 FieldName: TK_LTPPRT ";
		r = SQLBindParameter(hStmt_Insert, 7, SQL_PARAM_INPUT, SQL_C_DEFAULT, 1, 18, 0, (SQLPOINTER)TK_LTPPRT.constData(), 0, &cbTK_LTPPRT);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Parameters: Ordinal [8] Type: 5 Buffer Size: 2 FieldName: TK_LTPTYPE ";
		r = SQLBindParameter(hStmt_Insert, 8, SQL_PARAM_INPUT, SQL_C_DEFAULT, 5, 0, 0, (SQLPOINTER)TK_LTPTYPE.constData(), 0, &cbTK_LTPTYPE);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Parameters: Ordinal [9] Type: 1 Buffer Size: 10 FieldName: TK_LTPKEY1 ";
		r = SQLBindParameter(hStmt_Insert, 9, SQL_PARAM_INPUT, SQL_C_DEFAULT, 1, 10, 0, (SQLPOINTER)TK_LTPKEY1.constData(), 0, &cbTK_LTPKEY1);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Parameters: Ordinal [10] Type: 1 Buffer Size: 10 FieldName: TK_LTPKEY2 ";
		r = SQLBindParameter(hStmt_Insert, 10, SQL_PARAM_INPUT, SQL_C_DEFAULT, 1, 10, 0, (SQLPOINTER)TK_LTPKEY2.constData(), 0, &cbTK_LTPKEY2);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Parameters: Ordinal [11] Type: 1 Buffer Size: 24 FieldName: TK_LTPKEY3 ";
		r = SQLBindParameter(hStmt_Insert, 11, SQL_PARAM_INPUT, SQL_C_DEFAULT, 1, 24, 0, (SQLPOINTER)TK_LTPKEY3.constData(), 0, &cbTK_LTPKEY3);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Parameters: Ordinal [12] Type: 5 Buffer Size: 2 FieldName: TK_LTPSUBTYPE ";
		r = SQLBindParameter(hStmt_Insert, 12, SQL_PARAM_INPUT, SQL_C_DEFAULT, 5, 0, 0, (SQLPOINTER)TK_LTPSUBTYPE.constData(), 0, &cbTK_LTPSUBTYPE);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Parameters: Ordinal [13] Type: 8 Buffer Size: 8 FieldName: QTY ";
		r = SQLBindParameter(hStmt_Insert, 13, SQL_PARAM_INPUT, SQL_C_DEFAULT, 8, 0, 0, (SQLPOINTER)QTY.constData(), 0, &cbQTY);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Parameters: Ordinal [14] Type: 8 Buffer Size: 8 FieldName: TK_LTPISSQTY ";
		r = SQLBindParameter(hStmt_Insert, 14, SQL_PARAM_INPUT, SQL_C_DEFAULT, 8, 0, 0, (SQLPOINTER)TK_LTPISSQTY.constData(), 0, &cbTK_LTPISSQTY);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Parameters: Ordinal [15] Type: 8 Buffer Size: 8 FieldName: TK_LTPSCRPQTY ";
		r = SQLBindParameter(hStmt_Insert, 15, SQL_PARAM_INPUT, SQL_C_DEFAULT, 8, 0, 0, (SQLPOINTER)TK_LTPSCRPQTY.constData(), 0, &cbTK_LTPSCRPQTY);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Parameters: Ordinal [16] Type: 8 Buffer Size: 8 FieldName: TK_LTPRTVQTY ";
		r = SQLBindParameter(hStmt_Insert, 16, SQL_PARAM_INPUT, SQL_C_DEFAULT, 8, 0, 0, (SQLPOINTER)TK_LTPRTVQTY.constData(), 0, &cbTK_LTPRTVQTY);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Parameters: Ordinal [17] Type: 4 Buffer Size: 4 FieldName: TK_LTPCRDAT ";
		r = SQLBindParameter(hStmt_Insert, 17, SQL_PARAM_INPUT, SQL_C_DEFAULT, 4, 0, 0, (SQLPOINTER)TK_LTPCRDAT.constData(), 0, &cbTK_LTPCRDAT);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Parameters: Ordinal [18] Type: 4 Buffer Size: 4 FieldName: TK_LTPISSDAT ";
		r = SQLBindParameter(hStmt_Insert, 18, SQL_PARAM_INPUT, SQL_C_DEFAULT, 4, 0, 0, (SQLPOINTER)TK_LTPISSDAT.constData(), 0, &cbTK_LTPISSDAT);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Parameters: Ordinal [19] Type: 4 Buffer Size: 4 FieldName: DAT ";
		r = SQLBindParameter(hStmt_Insert, 19, SQL_PARAM_INPUT, SQL_C_DEFAULT, 4, 0, 0, (SQLPOINTER)DAT.constData(), 0, &cbDAT);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Parameters: Ordinal [20] Type: 8 Buffer Size: 8 FieldName: TK_LTPARCISSQTY ";
		r = SQLBindParameter(hStmt_Insert, 20, SQL_PARAM_INPUT, SQL_C_DEFAULT, 8, 0, 0, (SQLPOINTER)TK_LTPARCISSQTY.constData(), 0, &cbTK_LTPARCISSQTY);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Parameters: Ordinal [21] Type: 8 Buffer Size: 8 FieldName: TK_LTPARCRECQTY ";
		r = SQLBindParameter(hStmt_Insert, 21, SQL_PARAM_INPUT, SQL_C_DEFAULT, 8, 0, 0, (SQLPOINTER)TK_LTPARCRECQTY.constData(), 0, &cbTK_LTPARCRECQTY);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Parameters: Ordinal [22] Type: 8 Buffer Size: 8 FieldName: TK_LTPARCSCRPQTY ";
		r = SQLBindParameter(hStmt_Insert, 22, SQL_PARAM_INPUT, SQL_C_DEFAULT, 8, 0, 0, (SQLPOINTER)TK_LTPARCSCRPQTY.constData(), 0, &cbTK_LTPARCSCRPQTY);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Parameters: Ordinal [23] Type: 8 Buffer Size: 8 FieldName: TK_LTPARCRTVQTY ";
		r = SQLBindParameter(hStmt_Insert, 23, SQL_PARAM_INPUT, SQL_C_DEFAULT, 8, 0, 0, (SQLPOINTER)TK_LTPARCRTVQTY.constData(), 0, &cbTK_LTPARCRTVQTY);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Parameters: Ordinal [24] Type: 4 Buffer Size: 4 FieldName: TK_LTPPOLINE ";
		r = SQLBindParameter(hStmt_Insert, 24, SQL_PARAM_INPUT, SQL_C_DEFAULT, 4, 0, 0, (SQLPOINTER)TK_LTPPOLINE.constData(), 0, &cbTK_LTPPOLINE);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Parameters: Ordinal [25] Type: 1 Buffer Size: 24 FieldName: TK_LIDLOT ";
		r = SQLBindParameter(hStmt_Insert, 25, SQL_PARAM_INPUT, SQL_C_DEFAULT, 1, 24, 0, (SQLPOINTER)TK_LIDLOT.constData(), 0, &cbTK_LIDLOT);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Parameters: Ordinal [26] Type: 5 Buffer Size: 2 FieldName: TK_HDRCODE ";
		r = SQLBindParameter(hStmt_Insert, 26, SQL_PARAM_INPUT, SQL_C_DEFAULT, 5, 0, 0, (SQLPOINTER)TK_HDRCODE.constData(), 0, &cbTK_HDRCODE);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
	}
	if (m_ReplicationOption == ReplicationOption::NetChange)
	{
		r = SQLBindParameter(hStmt_Update, 27, SQL_PARAM_INPUT, SQL_C_DEFAULT, 3, 0, 0, (SQLPOINTER)AREA.constData(), 0, &cbAREA);
		if (r == SQL_SUCCESS) { isValid=true; }
		r = SQLBindParameter(hStmt_Update, 28, SQL_PARAM_INPUT, SQL_C_DEFAULT, 4, 0, 0, (SQLPOINTER)PAGE.constData(), 0, &cbPAGE);
		if (r == SQL_SUCCESS) { isValid=true; }
		r = SQLBindParameter(hStmt_Update, 29, SQL_PARAM_INPUT, SQL_C_DEFAULT, 24, 0, 0, (SQLPOINTER)TK_LTPPOLINE.constData(), 0, &cbTK_LTPPOLINE);
		if (r == SQL_SUCCESS) { isValid=true; }
	// TK_LTPREC is a well formed table for eNVy Replication 
		 qDebug(category) << " Parameters: Ordinal [3] 00 00 FieldName: AREA ";
		 qDebug(category) << " Parameters: Ordinal [4] 00 00  FieldName: PAGE ";
		 qDebug(category) << " Parameters: Ordinal [24] 00 00 FieldName:  TK_LTPPOLINE ";
	} // 	if (m_ReplicationOption == ReplicationOption::NetChange)
	return isValid;
}

bool TK_LTPREC::process(int rowSize)
{
	QLoggingCategory category("classLibQ");
	initOdbcAttributes();
	connect(Source);
	connect(Target);
	initialize();
	prepareTargetTable();
	prepare();
	bindColumn();
	bindParameter();
	copyTable();
	close();
	return false;
}

void TK_LTPREC::copyTable()
{
	QLoggingCategory category("classLibQ");
	RETCODE r;
	QString check;
	r = SQLExecute(hStmt_Fetch);
		if (bIsAbort) {
			emit aborted(tableName, rowsFetched, rowsInserted, rowsUpdated);
			return;
		}
		while((r = SQLFetch(hStmt_Fetch)) != SQL_NO_DATA) {
		if (r != SQL_SUCCESS) {
			check = qWarnODBCHandle(SQL_HANDLE_STMT, hStmt_Fetch);
			qCCritical(category) << QString("SqlFetch - Error : %1 is %2").arg(fetchSql).arg(check);
			return;
		} 
		rowsFetched++;
		if (m_ReplicationOption == ReplicationOption::BulkCopy)
		{
			r = SQLExecute(hStmt_Insert);
			if (r == SQL_ERROR) {
				check = qWarnODBCHandle(SQL_HANDLE_STMT, hStmt_Insert);
				 qCCritical(category) << QString("SqlExecute:Insert - Error : %1 is %2").arg(insertSql).arg(check);
				return;
			}
			rowsInserted++;
			if ((rowsFetched % updateInterval) == 0) {
				qCInfo(category) << QString("[%1.%2]	Insertion: %3	Updates : %4	Fetched : %5").arg(profileName).arg(tableName).arg(rowsInserted).arg(rowsUpdated).arg(rowsFetched);
				emit updateStatusFetched(profileName, tableName, rowsFetched,rowsInserted,rowsUpdated);
			}
			if (m_ReplicationOption == ReplicationOption::NetChange)
			{
			r = SQLExecute(hStmt_Update);
			if (r != SQL_SUCCESS) {
				check = qWarnODBCHandle(SQL_HANDLE_STMT, hStmt_Update);
				 qCInfo(category)  << QString("SqlExecute:Update - Error : %1 is %2").arg(updateSql).arg(check);
				r = SQLExecute(hStmt_Insert);
				if (r != SQL_SUCCESS) {
					check = qWarnODBCHandle(SQL_HANDLE_STMT, hStmt_Insert);
					 qCritical(category) << QString("SqlExecute:Insert - Error : %1 is %2").arg(insertSql).arg(check);
					return;
				}
				else 	rowsInserted++;
				}
				else	rowsUpdated++;
			}
			emit updateStatusFetched(profileName, tableName, rowsFetched,rowsInserted,rowsUpdated);
		}
	} 
qCInfo(category) << QString("[%1.%2]	Insertion: %3	Updates : %4	Fetched : %5").arg(profileName).arg(tableName).arg(rowsInserted).arg(rowsUpdated).arg(rowsFetched);
}

void TK_LTPREC::connect(connectionHandle connectionSource)
{

	QLoggingCategory category("classLibQ");
	RETCODE r;

	bool isValid = false;
	HWND	hWnd = nullptr;
	hWnd = ::GetDesktopWindow(); 
	SQLSMALLINT nResult = 0;

	SQLSMALLINT cb;
	UWORD wConnectOption = SQL_DRIVER_COMPLETE; //SQL_DRIVER_NOPROMPT;
	QVarLengthArray<SQLTCHAR> connOut(1024);
	memset(connOut.data(), 0, connOut.size() * sizeof(SQLTCHAR));

	switch (connectionSource)
	{
		case Source:
			{// environment
				SQLHANDLE hEnv = SQL_NULL_HANDLE;
				SQLHANDLE hDbc = SQL_NULL_HANDLE;
				r = ::SQLAllocHandle(SQL_HANDLE_ENV, SQL_NULL_HANDLE, &hEnv);
				if (r == SQL_SUCCESS) isValid = true;

				foreach(nOdbcAttributesClass * k, this->m_OdbcAttributes_Map)
				{
					if (k->attributeType == enumAttributeType::hEnv)
					{
						r = ::SQLSetEnvAttr(hEnv, (SQLINTEGER) k->odbcKey, (SQLPOINTER)k->odbcValue, 0);
						if (r == SQL_SUCCESS) isValid = true;
					}
				}
				hEnv_Source = hEnv;

				r = SQLAllocHandle(SQL_HANDLE_DBC, hEnv, &hDbc);
				if (r == SQL_SUCCESS) isValid = true;
				foreach(nOdbcAttributesClass * k, this->m_OdbcAttributes_Map)
				{
					if (k->attributeType == enumAttributeType::hDbc)
					{
					r = ::SQLSetConnectAttr(hDbc, k->odbcKey, (SQLPOINTER)k->odbcValue, 0);
					if (k->odbcKey == SQL_ATTR_CONNECTION_POOLING && k->odbcValue == SQL_CP_ONE_PER_DRIVER) wConnectOption = SQL_DRIVER_NOPROMPT;
					if (k->odbcKey == SQL_ATTR_CONNECTION_POOLING && k->odbcValue == SQL_CP_ONE_PER_HENV) wConnectOption = SQL_DRIVER_NOPROMPT;
					if (k->odbcKey == SQL_ATTR_CONNECTION_POOLING && k->odbcValue == SQL_CP_DRIVER_AWARE) wConnectOption = SQL_DRIVER_NOPROMPT;
					if (r == SQL_SUCCESS) isValid = true;
					}
				}
				hDbc_source = hDbc;
				if (isValid)
				{
					r = ::SQLDriverConnect(
						hDbc,
						hWnd,
#ifdef UNICODE
						toSQLTCHAR(m_lpszSourceDSN).data(),
#else
						(SQLCHAR*)dsnSource.toUtf8().data(),
#endif
						(SQLSMALLINT)m_lpszSourceDSN.length(),
						connOut.data(),
						1024,
						&cb, 
						wConnectOption); 
					int colSize = cb / sizeof(SQLTCHAR);
					if (r != SQL_SUCCESS && r != SQL_SUCCESS_WITH_INFO)
					{
						QString check = qWarnODBCHandle(SQL_HANDLE_DBC, hDbc);
						qCritical(category) <<  check;
						m_bIsOpen = false;
					}
					m_bIsOpen = true;
				}
			} break;
		case Target:
			{
				SQLHANDLE hEnv = SQL_NULL_HANDLE;
				SQLHANDLE hDbc = SQL_NULL_HANDLE;
				r = ::SQLAllocHandle(SQL_HANDLE_ENV, SQL_NULL_HANDLE, &hEnv);
				if (r == SQL_SUCCESS) isValid = true;

				foreach(nOdbcAttributesClass * k, this->m_OdbcAttributes_Map)
				{
					if (k->attributeType == enumAttributeType::hEnv)
					{
						r = ::SQLSetEnvAttr(hEnv, (SQLINTEGER) k->odbcKey, (SQLPOINTER)k->odbcValue, 0);
						if (r == SQL_SUCCESS) isValid = true;
					}
				}
				hEnv_Target = hEnv;

				r = SQLAllocHandle(SQL_HANDLE_DBC, hEnv, &hDbc);
				if (r == SQL_SUCCESS) isValid = true;
				foreach(nOdbcAttributesClass * k, this->m_OdbcAttributes_Map)
				{
				if (k->attributeType == enumAttributeType::hDbc)
					{
					r = ::SQLSetConnectAttr(hDbc, k->odbcKey, (SQLPOINTER)k->odbcValue, 0);
					if (k->odbcKey == SQL_ATTR_CONNECTION_POOLING && k->odbcValue == SQL_CP_ONE_PER_DRIVER) wConnectOption = SQL_DRIVER_NOPROMPT;
					if (k->odbcKey == SQL_ATTR_CONNECTION_POOLING && k->odbcValue == SQL_CP_ONE_PER_HENV) wConnectOption = SQL_DRIVER_NOPROMPT;
					if (k->odbcKey == SQL_ATTR_CONNECTION_POOLING && k->odbcValue == SQL_CP_DRIVER_AWARE) wConnectOption = SQL_DRIVER_NOPROMPT;
					if (r == SQL_SUCCESS) isValid = true;
					}
				}
				hDbc_target = hDbc;
				if (isValid) {
					r = ::SQLDriverConnect(
						hDbc,
						hWnd,
#ifdef UNICODE
						toSQLTCHAR(m_lpszTargetDSN).data(),
#else
						(SQLCHAR*)m_lpszTargetDSN.toUtf8().data(),
#endif
						(SQLSMALLINT)m_lpszTargetDSN.length(),
						connOut.data(),
						1024,
						&cb, 
						wConnectOption); 
						int colSize = cb / sizeof(SQLTCHAR);
					if (r != SQL_SUCCESS && r != SQL_SUCCESS_WITH_INFO)
						{
							QString check = qWarnODBCHandle(SQL_HANDLE_DBC, hDbc);
							qCritical(category) <<  check;
							m_bIsOpen = false;
						}
							m_bIsOpen = true;
					}
			} break;
			default: break;
	}
}
TK_TYPREC::TK_TYPREC(QObject * parent) : QObject(parent) 
,tableName("TK_TYPREC")
,m_dropOption(DropOption::DropTable) { 
	numRowsFetched = 0;
}

#pragma region ~CTOR TK_TYPREC 
TK_TYPREC::~TK_TYPREC() { 

#pragma region Buffers - Clear 
	DB_ID.clear();
	NVTIMESTAMP.clear();
	AREA.clear();
	PAGE.clear();
	LINE.clear();
	TK_TYPCODE.clear();
	TK_TYPNO.clear();
	TK_TYPNAME.clear();
	TK_TYPCUSNO.clear();
#pragma endregion Buffers - Clear 
}
#pragma endregion Destructor_TK_TYPREC

// begin method functions
void TK_TYPREC::setAbortFlag() { 
	QLoggingCategory category("classLibQ");
	qCInfo(category) << "isAbort was set to True";
	bIsAbort = true;
}

void TK_TYPREC::run() { 
	process(1);
	QLoggingCategory category("classLibQ");
	qDebug(category) << "Entered;";
}

void	TK_TYPREC::initOdbcAttributes()
{
	QLoggingCategory category("classLibQ");
	this->setProfileName(profileName);
	qDebug(category) << "Processing - TRKDB100"; 
	m_OdbcAttributesList = m_OdbcAttributes.split(","); 
	foreach(QString m, m_OdbcAttributesList)
	{
		QStringList keyValue = m.split("=");
		nOdbcAttributesClass * oM = new nOdbcAttributesClass(this);
		if (oM->loadToOdbc(keyValue.value(0), keyValue.value(1)))
		{
			m_OdbcAttributes_Map.insert(oM->odbcKey, oM);
		}
	}
}
void	TK_TYPREC::initialize()
{
	QLoggingCategory category("classLibQ");
	RETCODE r;
	this->setProfileName(profileName);
	qDebug(category) << "Processing - TRKDB100"; 
//SQL Statements
//--------------------------------------------------

#pragma region Sql Statements_TK_TYPREC

	fetchSql = "select  DB_ID, NVTIMESTAMP, AREA, PAGE, LINE, TK_TYPCODE, TK_TYPNO, TK_TYPNAME, TK_TYPCUSNO from TK_TYPREC";
		if (m_ReplicationOption == ReplicationOption::NetChange)
		{
			fetchSql.append(" p1, nv_transfers p2 WHERE  p2.table_name = 'TK_TYPREC' AND p1.nvtimestamp > p2.last_completed");
		}
	insertSql = "insert into TK_TYPREC ( PLANT_CODE, NVTIMESTAMP, AREA, PAGE, LINE, TK_TYPCODE, TK_TYPNO, TK_TYPNAME, TK_TYPCUSNO ) values ( ?, ?, ?, ?, ?, ?, ?, ?, ?)";
	updateSql = "update TK_TYPREC set  PLANT_CODE = ?, NVTIMESTAMP = ?, AREA = ?, PAGE = ?, LINE = ?, TK_TYPCODE = ?, TK_TYPNO = ?, TK_TYPNAME = ?, TK_TYPCUSNO = ?  where area = ? and page = ? line = ? ";

	qDebug(category) << "insertSQL - insert into TK_TYPREC ( PLANT_CODE, NVTIMESTAMP, AREA, PAGE, LINE, TK_TYPCODE, TK_TYPNO, TK_TYPNAME, TK_TYPCUSNO ) values ( ?, ?, ?, ?, ?, ?, ?, ?, ?)";
	qDebug(category) << "fetchSQL - select  DB_ID, NVTIMESTAMP, AREA, PAGE, LINE, TK_TYPCODE, TK_TYPNO, TK_TYPNAME, TK_TYPCUSNO from TK_TYPREC";
	qDebug(category) << "unsertSQL - update TK_TYPREC set  PLANT_CODE = ?, NVTIMESTAMP = ?, AREA = ?, PAGE = ?, LINE = ?, TK_TYPCODE = ?, TK_TYPNO = ?, TK_TYPNAME = ?, TK_TYPCUSNO = ?  where area = ? and page = ? line = ? ";

#pragma endregion Sql Statements_TK_TYPREC
	SQLHANDLE		insert_hStmt = SQL_NULL_HANDLE;
	SQLHANDLE		fetch_hStmt = SQL_NULL_HANDLE; 
	SQLHANDLE		update_hStmt = SQL_NULL_HANDLE; 
 
	r = ::SQLAllocHandle(SQL_HANDLE_STMT, hDbc_source, &fetch_hStmt);
	if (r != SQL_SUCCESS) {
		 qCCritical(category) << QString("Error  hDbc_Source SQLCode : %1 is %2").arg(QString::number( (long)hDbc_source)).arg(QString::number(r));
		return; 
	}
	r = ::SQLAllocHandle(SQL_HANDLE_STMT, hDbc_target, &insert_hStmt);
	if (r != SQL_SUCCESS) {
		 qCCritical(category) << QString("Error hDbc_Source -SQLCode: %1 is %2").arg(QString::number( (long)hDbc_target)).arg(QString::number(r));
		return; 
	}
	r = ::SQLAllocHandle(SQL_HANDLE_STMT, hDbc_target, &update_hStmt);
	if (r != SQL_SUCCESS) {
		 qCCritical(category) << QString("Error hDbc_Source +SQLCode: %1 is %2").arg(QString::number( (long)hDbc_target)).arg(QString::number(r));
		return; 
	}
 
	hStmt_Fetch = fetch_hStmt;
	hStmt_Insert = insert_hStmt;
	hStmt_Update = update_hStmt;
 
	SQLSetStmtAttr(hStmt_Fetch, SQL_ATTR_USE_BOOKMARKS, (SQLPOINTER)SQL_UB_OFF, 0);
	SQLSetStmtAttr(hStmt_Fetch, SQL_ATTR_ROW_BIND_TYPE, (SQLPOINTER)SQL_BIND_BY_COLUMN, 0);
	SQLSetStmtAttr(hStmt_Fetch, SQL_ATTR_ROW_ARRAY_SIZE, (SQLPOINTER)1, 0);
	SQLSetStmtAttr(hStmt_Fetch, SQL_ATTR_ROWS_FETCHED_PTR, &numRowsFetched, 0);

// Fields used by this class 
// ---------------------------------------------------

#pragma region Resize Fields TK_TYPREC
	qDebug(category) << "Malloc - DB_ID[2]";
	DB_ID.resize(2);
	qDebug(category) << "Malloc - NVTIMESTAMP[23]";
	NVTIMESTAMP.resize(23);
	qDebug(category) << "Malloc - AREA[2]";
	AREA.resize(2);
	qDebug(category) << "Malloc - PAGE[4]";
	PAGE.resize(4);
	qDebug(category) << "Malloc - LINE[2]";
	LINE.resize(2);
	qDebug(category) << "Malloc - TK_TYPCODE[2]";
	TK_TYPCODE.resize(2);
	qDebug(category) << "Malloc - TK_TYPNO[10]";
	TK_TYPNO.resize(10);
	qDebug(category) << "Malloc - TK_TYPNAME[30]";
	TK_TYPNAME.resize(30);
	qDebug(category) << "Malloc - TK_TYPCUSNO[10]";
	TK_TYPCUSNO.resize(10);

#pragma endregion Resize Fields TK_TYPREC
}
void TK_TYPREC::close()
{
	QLoggingCategory category("classLibQ");
	if (m_bIsOpen)
	{
	qDebug(category) << "database is Open";
		SQLHANDLE source_hStmt = hStmt_Fetch;
		SQLHANDLE insert_hStmt = hStmt_Insert;
		SQLHANDLE hDb_S = this->hDbc_source;
		SQLHANDLE hDb_T = hDbc_target;
		SQLHANDLE hEnvS = hEnv_Source;
		SQLHANDLE hEnvT = hEnv_Target;
		RETCODE r;

		r = ::SQLFreeHandle(SQL_HANDLE_STMT, hStmt_Fetch);
		r = ::SQLFreeHandle(SQL_HANDLE_STMT, hStmt_Insert);
		r = ::SQLFreeHandle(SQL_HANDLE_STMT, hStmt_Update);
		if (hDbc_source != SQL_NULL_HANDLE) 		r = ::SQLDisconnect(hDb_S);
		if (hDbc_target != SQL_NULL_HANDLE) 		r = ::SQLDisconnect(hDb_T);

		r = ::SQLFreeHandle(SQL_HANDLE_DBC, hDb_S);
		r = ::SQLFreeHandle(SQL_HANDLE_DBC, hDb_T);
		r = ::SQLFreeHandle(SQL_HANDLE_ENV, hEnvS);
		r = ::SQLFreeHandle(SQL_HANDLE_ENV, hEnvT);
	}

	hEnv_Source = SQL_NULL_HANDLE;
	hEnv_Target = SQL_NULL_HANDLE;
	hEnv_Source = SQL_NULL_HANDLE;
	hEnv_Target = SQL_NULL_HANDLE;
	hStmt_Fetch = SQL_NULL_HANDLE;
	hStmt_Insert = SQL_NULL_HANDLE;
	hStmt_Update = SQL_NULL_HANDLE;
}

void TK_TYPREC::open(const QString sourceDSN, const QString targetDSN)
{
	QLoggingCategory category("classLibQ");
	m_lpszTargetDSN = targetDSN;
	m_lpszSourceDSN = sourceDSN;
	qDebug(category) << QString("Source - %1[%2]").arg(sourceDSN);
	qDebug(category) << QString("Target - %1[%2]").arg(targetDSN);
}

void TK_TYPREC::createTable()
{
	QLoggingCategory category("classLibQ");
	{
		QScopedPointer<nvTableOracleRdb> tbl(new nvTableOracleRdb(nullptr));
		tbl->initialize("TK_TYPREC", this->m_lpszSourceDSN);
		QString newTbl = tbl->getCreateTableSQL();
		QScopedPointer<qVtExecute> vExec(new qVtExecute(nullptr));
		{
			vExec->initialize(m_lpszTargetDSN, " ", true);
			vExec->setOdbcAttributes(m_OdbcAttributes);
			vExec->ExecuteDirect(newTbl);
		}
	 qDebug(category) << QString("End Create Table %1 ").arg(tableName); 
	}
}

bool TK_TYPREC::prepare()
{
	RETCODE r;
	QString check;
	QLoggingCategory category("classLibQ");
	 qDebug(category) << fetchSql;
	 qDebug(category) << insertSql;
#ifdef UNICODE
	r = SQLPrepare(hStmt_Insert,toSQLTCHAR(insertSql).data(),(SQLINTEGER)insertSql.length()); 
	if (r != SQL_SUCCESS) {
		check = qWarnODBCHandle(SQL_HANDLE_STMT, hStmt_Insert);
		 qCCritical(category) << QString("Prepare Statement-Insert : %1 is %2").arg(insertSql).arg(check);
		return false; 
	}
	r = SQLPrepare(hStmt_Update,toSQLTCHAR(updateSql).data(),(SQLINTEGER)updateSql.length()); 
	if (r != SQL_SUCCESS) {
		check = qWarnODBCHandle(SQL_HANDLE_STMT, hStmt_Update);
		 qCCritical(category) << QString("Prepare Statement-Update : %1 is %2").arg(updateSql).arg(check);
		return false; 
	}
	r = SQLPrepare(hStmt_Fetch,toSQLTCHAR(fetchSql).data(),(SQLINTEGER)fetchSql.length());
	if (r != SQL_SUCCESS) {
		check = qWarnODBCHandle(SQL_HANDLE_STMT, hStmt_Fetch);
		 qCCritical(category) << QString("Prepare Statement-Insert : %1 is %2").arg(fetchSql).arg(check);
		return false; 
	}
#else
	QByteArray queryI8 = insertSql.toUtf8();
	r = SQLPrepare(insert_hStmt,SQLCHAR*)queryI8.data(),(SQLINTEGER)queryI8.length());
	QByteArray queryU8 = fetchSql.toUtf8();
	r = SQLPrepare(hStmt_Fetch,(SQLCHAR*)queryU8.data(),(SQLINTEGER)queryU8.length());
#endif
	return true;

}

void TK_TYPREC::prepareTargetTable()
{
	QLoggingCategory category("classLibQ");
	if (this->m_ReplicationOption == ReplicationOption::BulkCopy)
	{
		QScopedPointer<qVtExecute> execSql(new qVtExecute(nullptr));
		DropOption option = this->m_dropOption;
		switch (option)
		{
			case DropOption::DeleteFromTable:
			{
				QLoggingCategory category("classLibQ");
				execSql->initialize(this->m_lpszTargetDSN, "delete from TK_TYPREC", true);
				execSql->setOdbcAttributes(this->m_OdbcAttributes);
				execSql->ExecuteDirect("delete from TK_TYPREC");
			}break;
			case DropOption::TruncateTable:
			{
				execSql->initialize(this->m_lpszTargetDSN, "truncate table TK_TYPREC", true);
				execSql->setOdbcAttributes(this->m_OdbcAttributes);
				execSql->ExecuteDirect("truncate table TK_TYPREC");
			}break;
			case DropOption::DropTable:
			{
				execSql->initialize(this->m_lpszTargetDSN, "drop table TK_TYPREC", true);
				execSql->setOdbcAttributes(this->m_OdbcAttributes);
				execSql->ExecuteDirect("drop table TK_TYPREC");
				createTable();
			}break;
		}
	}
}

bool TK_TYPREC::bindColumn()
{
	QLoggingCategory category("classLibQ");
	RETCODE r;
	bool isValid=true;
		 qDebug(category) << " Bindings: Ordinal [1] Type: 5 Buffer Size: 2 FieldName: DB_ID ";
		r = ::SQLBindCol(hStmt_Fetch, 1, 5, DB_ID.data(), 2, &cbDB_ID);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Bindings: Ordinal [2] Type: 93 Buffer Size: 23 FieldName: NVTIMESTAMP ";
		r = ::SQLBindCol(hStmt_Fetch, 2, 93, NVTIMESTAMP.data(), 23, &cbNVTIMESTAMP);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Bindings: Ordinal [3] Type: 5 Buffer Size: 2 FieldName: AREA ";
		r = ::SQLBindCol(hStmt_Fetch, 3, 5, AREA.data(), 2, &cbAREA);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Bindings: Ordinal [4] Type: 4 Buffer Size: 4 FieldName: PAGE ";
		r = ::SQLBindCol(hStmt_Fetch, 4, 4, PAGE.data(), 4, &cbPAGE);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Bindings: Ordinal [5] Type: 5 Buffer Size: 2 FieldName: LINE ";
		r = ::SQLBindCol(hStmt_Fetch, 5, 5, LINE.data(), 2, &cbLINE);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Bindings: Ordinal [6] Type: 5 Buffer Size: 2 FieldName: TK_TYPCODE ";
		r = ::SQLBindCol(hStmt_Fetch, 6, 5, TK_TYPCODE.data(), 2, &cbTK_TYPCODE);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Bindings: Ordinal [7] Type: 1 Buffer Size: 10 FieldName: TK_TYPNO ";
		r = ::SQLBindCol(hStmt_Fetch, 7, 1, TK_TYPNO.data(), 10, &cbTK_TYPNO);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Bindings: Ordinal [8] Type: 1 Buffer Size: 30 FieldName: TK_TYPNAME ";
		r = ::SQLBindCol(hStmt_Fetch, 8, 1, TK_TYPNAME.data(), 30, &cbTK_TYPNAME);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Bindings: Ordinal [9] Type: 1 Buffer Size: 10 FieldName: TK_TYPCUSNO ";
		r = ::SQLBindCol(hStmt_Fetch, 9, 1, TK_TYPCUSNO.data(), 10, &cbTK_TYPCUSNO);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
	return isValid;
}

bool TK_TYPREC::bindParameter()
{
	QLoggingCategory category("classLibQ");
	RETCODE r;
	bool isValid=true;
	{
		 qDebug(category) << " Parameters: Ordinal [1] Type: 5 Buffer Size: 2 FieldName: DB_ID ";
		r = SQLBindParameter(hStmt_Insert, 1, SQL_PARAM_INPUT, SQL_C_DEFAULT, 5, 0, 0, (SQLPOINTER)DB_ID.constData(), 0, &cbDB_ID);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Parameters: Ordinal [2] Type: 93 Buffer Size: 23 FieldName: NVTIMESTAMP ";
		r = SQLBindParameter(hStmt_Insert, 2, SQL_PARAM_INPUT, SQL_C_DEFAULT, 93, 23, 0, (SQLPOINTER)NVTIMESTAMP.constData(), 0, &cbNVTIMESTAMP);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Parameters: Ordinal [3] Type: 5 Buffer Size: 2 FieldName: AREA ";
		r = SQLBindParameter(hStmt_Insert, 3, SQL_PARAM_INPUT, SQL_C_DEFAULT, 5, 0, 0, (SQLPOINTER)AREA.constData(), 0, &cbAREA);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Parameters: Ordinal [4] Type: 4 Buffer Size: 4 FieldName: PAGE ";
		r = SQLBindParameter(hStmt_Insert, 4, SQL_PARAM_INPUT, SQL_C_DEFAULT, 4, 0, 0, (SQLPOINTER)PAGE.constData(), 0, &cbPAGE);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Parameters: Ordinal [5] Type: 5 Buffer Size: 2 FieldName: LINE ";
		r = SQLBindParameter(hStmt_Insert, 5, SQL_PARAM_INPUT, SQL_C_DEFAULT, 5, 0, 0, (SQLPOINTER)LINE.constData(), 0, &cbLINE);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Parameters: Ordinal [6] Type: 5 Buffer Size: 2 FieldName: TK_TYPCODE ";
		r = SQLBindParameter(hStmt_Insert, 6, SQL_PARAM_INPUT, SQL_C_DEFAULT, 5, 0, 0, (SQLPOINTER)TK_TYPCODE.constData(), 0, &cbTK_TYPCODE);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Parameters: Ordinal [7] Type: 1 Buffer Size: 10 FieldName: TK_TYPNO ";
		r = SQLBindParameter(hStmt_Insert, 7, SQL_PARAM_INPUT, SQL_C_DEFAULT, 1, 10, 0, (SQLPOINTER)TK_TYPNO.constData(), 0, &cbTK_TYPNO);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Parameters: Ordinal [8] Type: 1 Buffer Size: 30 FieldName: TK_TYPNAME ";
		r = SQLBindParameter(hStmt_Insert, 8, SQL_PARAM_INPUT, SQL_C_DEFAULT, 1, 30, 0, (SQLPOINTER)TK_TYPNAME.constData(), 0, &cbTK_TYPNAME);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Parameters: Ordinal [9] Type: 1 Buffer Size: 10 FieldName: TK_TYPCUSNO ";
		r = SQLBindParameter(hStmt_Insert, 9, SQL_PARAM_INPUT, SQL_C_DEFAULT, 1, 10, 0, (SQLPOINTER)TK_TYPCUSNO.constData(), 0, &cbTK_TYPCUSNO);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
	}
	if (m_ReplicationOption == ReplicationOption::NetChange)
	{
		r = SQLBindParameter(hStmt_Update, 10, SQL_PARAM_INPUT, SQL_C_DEFAULT, 3, 0, 0, (SQLPOINTER)AREA.constData(), 0, &cbAREA);
		if (r == SQL_SUCCESS) { isValid=true; }
		r = SQLBindParameter(hStmt_Update, 11, SQL_PARAM_INPUT, SQL_C_DEFAULT, 4, 0, 0, (SQLPOINTER)PAGE.constData(), 0, &cbPAGE);
		if (r == SQL_SUCCESS) { isValid=true; }
		r = SQLBindParameter(hStmt_Update, 12, SQL_PARAM_INPUT, SQL_C_DEFAULT, 5, 0, 0, (SQLPOINTER)LINE.constData(), 0, &cbLINE);
		if (r == SQL_SUCCESS) { isValid=true; }
	// TK_TYPREC is a well formed table for eNVy Replication 
		 qDebug(category) << " Parameters: Ordinal [3] 00 00 FieldName: AREA ";
		 qDebug(category) << " Parameters: Ordinal [4] 00 00  FieldName: PAGE ";
		 qDebug(category) << " Parameters: Ordinal [5] 00 00 FieldName:  LINE ";
	} // 	if (m_ReplicationOption == ReplicationOption::NetChange)
	return isValid;
}

bool TK_TYPREC::process(int rowSize)
{
	QLoggingCategory category("classLibQ");
	initOdbcAttributes();
	connect(Source);
	connect(Target);
	initialize();
	prepareTargetTable();
	prepare();
	bindColumn();
	bindParameter();
	copyTable();
	close();
	return false;
}

void TK_TYPREC::copyTable()
{
	QLoggingCategory category("classLibQ");
	RETCODE r;
	QString check;
	r = SQLExecute(hStmt_Fetch);
		if (bIsAbort) {
			emit aborted(tableName, rowsFetched, rowsInserted, rowsUpdated);
			return;
		}
		while((r = SQLFetch(hStmt_Fetch)) != SQL_NO_DATA) {
		if (r != SQL_SUCCESS) {
			check = qWarnODBCHandle(SQL_HANDLE_STMT, hStmt_Fetch);
			qCCritical(category) << QString("SqlFetch - Error : %1 is %2").arg(fetchSql).arg(check);
			return;
		} 
		rowsFetched++;
		if (m_ReplicationOption == ReplicationOption::BulkCopy)
		{
			r = SQLExecute(hStmt_Insert);
			if (r == SQL_ERROR) {
				check = qWarnODBCHandle(SQL_HANDLE_STMT, hStmt_Insert);
				 qCCritical(category) << QString("SqlExecute:Insert - Error : %1 is %2").arg(insertSql).arg(check);
				return;
			}
			rowsInserted++;
			if ((rowsFetched % updateInterval) == 0) {
				qCInfo(category) << QString("[%1.%2]	Insertion: %3	Updates : %4	Fetched : %5").arg(profileName).arg(tableName).arg(rowsInserted).arg(rowsUpdated).arg(rowsFetched);
				emit updateStatusFetched(profileName, tableName, rowsFetched,rowsInserted,rowsUpdated);
			}
			if (m_ReplicationOption == ReplicationOption::NetChange)
			{
			r = SQLExecute(hStmt_Update);
			if (r != SQL_SUCCESS) {
				check = qWarnODBCHandle(SQL_HANDLE_STMT, hStmt_Update);
				 qCInfo(category)  << QString("SqlExecute:Update - Error : %1 is %2").arg(updateSql).arg(check);
				r = SQLExecute(hStmt_Insert);
				if (r != SQL_SUCCESS) {
					check = qWarnODBCHandle(SQL_HANDLE_STMT, hStmt_Insert);
					 qCritical(category) << QString("SqlExecute:Insert - Error : %1 is %2").arg(insertSql).arg(check);
					return;
				}
				else 	rowsInserted++;
				}
				else	rowsUpdated++;
			}
			emit updateStatusFetched(profileName, tableName, rowsFetched,rowsInserted,rowsUpdated);
		}
	} 
qCInfo(category) << QString("[%1.%2]	Insertion: %3	Updates : %4	Fetched : %5").arg(profileName).arg(tableName).arg(rowsInserted).arg(rowsUpdated).arg(rowsFetched);
}

void TK_TYPREC::connect(connectionHandle connectionSource)
{

	QLoggingCategory category("classLibQ");
	RETCODE r;

	bool isValid = false;
	HWND	hWnd = nullptr;
	hWnd = ::GetDesktopWindow(); 
	SQLSMALLINT nResult = 0;

	SQLSMALLINT cb;
	UWORD wConnectOption = SQL_DRIVER_COMPLETE; //SQL_DRIVER_NOPROMPT;
	QVarLengthArray<SQLTCHAR> connOut(1024);
	memset(connOut.data(), 0, connOut.size() * sizeof(SQLTCHAR));

	switch (connectionSource)
	{
		case Source:
			{// environment
				SQLHANDLE hEnv = SQL_NULL_HANDLE;
				SQLHANDLE hDbc = SQL_NULL_HANDLE;
				r = ::SQLAllocHandle(SQL_HANDLE_ENV, SQL_NULL_HANDLE, &hEnv);
				if (r == SQL_SUCCESS) isValid = true;

				foreach(nOdbcAttributesClass * k, this->m_OdbcAttributes_Map)
				{
					if (k->attributeType == enumAttributeType::hEnv)
					{
						r = ::SQLSetEnvAttr(hEnv, (SQLINTEGER) k->odbcKey, (SQLPOINTER)k->odbcValue, 0);
						if (r == SQL_SUCCESS) isValid = true;
					}
				}
				hEnv_Source = hEnv;

				r = SQLAllocHandle(SQL_HANDLE_DBC, hEnv, &hDbc);
				if (r == SQL_SUCCESS) isValid = true;
				foreach(nOdbcAttributesClass * k, this->m_OdbcAttributes_Map)
				{
					if (k->attributeType == enumAttributeType::hDbc)
					{
					r = ::SQLSetConnectAttr(hDbc, k->odbcKey, (SQLPOINTER)k->odbcValue, 0);
					if (k->odbcKey == SQL_ATTR_CONNECTION_POOLING && k->odbcValue == SQL_CP_ONE_PER_DRIVER) wConnectOption = SQL_DRIVER_NOPROMPT;
					if (k->odbcKey == SQL_ATTR_CONNECTION_POOLING && k->odbcValue == SQL_CP_ONE_PER_HENV) wConnectOption = SQL_DRIVER_NOPROMPT;
					if (k->odbcKey == SQL_ATTR_CONNECTION_POOLING && k->odbcValue == SQL_CP_DRIVER_AWARE) wConnectOption = SQL_DRIVER_NOPROMPT;
					if (r == SQL_SUCCESS) isValid = true;
					}
				}
				hDbc_source = hDbc;
				if (isValid)
				{
					r = ::SQLDriverConnect(
						hDbc,
						hWnd,
#ifdef UNICODE
						toSQLTCHAR(m_lpszSourceDSN).data(),
#else
						(SQLCHAR*)dsnSource.toUtf8().data(),
#endif
						(SQLSMALLINT)m_lpszSourceDSN.length(),
						connOut.data(),
						1024,
						&cb, 
						wConnectOption); 
					int colSize = cb / sizeof(SQLTCHAR);
					if (r != SQL_SUCCESS && r != SQL_SUCCESS_WITH_INFO)
					{
						QString check = qWarnODBCHandle(SQL_HANDLE_DBC, hDbc);
						qCritical(category) <<  check;
						m_bIsOpen = false;
					}
					m_bIsOpen = true;
				}
			} break;
		case Target:
			{
				SQLHANDLE hEnv = SQL_NULL_HANDLE;
				SQLHANDLE hDbc = SQL_NULL_HANDLE;
				r = ::SQLAllocHandle(SQL_HANDLE_ENV, SQL_NULL_HANDLE, &hEnv);
				if (r == SQL_SUCCESS) isValid = true;

				foreach(nOdbcAttributesClass * k, this->m_OdbcAttributes_Map)
				{
					if (k->attributeType == enumAttributeType::hEnv)
					{
						r = ::SQLSetEnvAttr(hEnv, (SQLINTEGER) k->odbcKey, (SQLPOINTER)k->odbcValue, 0);
						if (r == SQL_SUCCESS) isValid = true;
					}
				}
				hEnv_Target = hEnv;

				r = SQLAllocHandle(SQL_HANDLE_DBC, hEnv, &hDbc);
				if (r == SQL_SUCCESS) isValid = true;
				foreach(nOdbcAttributesClass * k, this->m_OdbcAttributes_Map)
				{
				if (k->attributeType == enumAttributeType::hDbc)
					{
					r = ::SQLSetConnectAttr(hDbc, k->odbcKey, (SQLPOINTER)k->odbcValue, 0);
					if (k->odbcKey == SQL_ATTR_CONNECTION_POOLING && k->odbcValue == SQL_CP_ONE_PER_DRIVER) wConnectOption = SQL_DRIVER_NOPROMPT;
					if (k->odbcKey == SQL_ATTR_CONNECTION_POOLING && k->odbcValue == SQL_CP_ONE_PER_HENV) wConnectOption = SQL_DRIVER_NOPROMPT;
					if (k->odbcKey == SQL_ATTR_CONNECTION_POOLING && k->odbcValue == SQL_CP_DRIVER_AWARE) wConnectOption = SQL_DRIVER_NOPROMPT;
					if (r == SQL_SUCCESS) isValid = true;
					}
				}
				hDbc_target = hDbc;
				if (isValid) {
					r = ::SQLDriverConnect(
						hDbc,
						hWnd,
#ifdef UNICODE
						toSQLTCHAR(m_lpszTargetDSN).data(),
#else
						(SQLCHAR*)m_lpszTargetDSN.toUtf8().data(),
#endif
						(SQLSMALLINT)m_lpszTargetDSN.length(),
						connOut.data(),
						1024,
						&cb, 
						wConnectOption); 
						int colSize = cb / sizeof(SQLTCHAR);
					if (r != SQL_SUCCESS && r != SQL_SUCCESS_WITH_INFO)
						{
							QString check = qWarnODBCHandle(SQL_HANDLE_DBC, hDbc);
							qCritical(category) <<  check;
							m_bIsOpen = false;
						}
							m_bIsOpen = true;
					}
			} break;
			default: break;
	}
}
TK_ULSTREC::TK_ULSTREC(QObject * parent) : QObject(parent) 
,tableName("TK_ULSTREC")
,m_dropOption(DropOption::DropTable) { 
	numRowsFetched = 0;
}

#pragma region ~CTOR TK_ULSTREC 
TK_ULSTREC::~TK_ULSTREC() { 

#pragma region Buffers - Clear 
	DB_ID.clear();
	NVTIMESTAMP.clear();
	AREA.clear();
	PAGE.clear();
	LINE.clear();
	TK_ULSTUOM.clear();
	TK_UPRTNO.clear();
#pragma endregion Buffers - Clear 
}
#pragma endregion Destructor_TK_ULSTREC

// begin method functions
void TK_ULSTREC::setAbortFlag() { 
	QLoggingCategory category("classLibQ");
	qCInfo(category) << "isAbort was set to True";
	bIsAbort = true;
}

void TK_ULSTREC::run() { 
	process(1);
	QLoggingCategory category("classLibQ");
	qDebug(category) << "Entered;";
}

void	TK_ULSTREC::initOdbcAttributes()
{
	QLoggingCategory category("classLibQ");
	this->setProfileName(profileName);
	qDebug(category) << "Processing - TRKDB100"; 
	m_OdbcAttributesList = m_OdbcAttributes.split(","); 
	foreach(QString m, m_OdbcAttributesList)
	{
		QStringList keyValue = m.split("=");
		nOdbcAttributesClass * oM = new nOdbcAttributesClass(this);
		if (oM->loadToOdbc(keyValue.value(0), keyValue.value(1)))
		{
			m_OdbcAttributes_Map.insert(oM->odbcKey, oM);
		}
	}
}
void	TK_ULSTREC::initialize()
{
	QLoggingCategory category("classLibQ");
	RETCODE r;
	this->setProfileName(profileName);
	qDebug(category) << "Processing - TRKDB100"; 
//SQL Statements
//--------------------------------------------------

#pragma region Sql Statements_TK_ULSTREC

	fetchSql = "select  DB_ID, NVTIMESTAMP, AREA, PAGE, LINE, TK_ULSTUOM, TK_UPRTNO from TK_ULSTREC";
		if (m_ReplicationOption == ReplicationOption::NetChange)
		{
			fetchSql.append(" p1, nv_transfers p2 WHERE  p2.table_name = 'TK_ULSTREC' AND p1.nvtimestamp > p2.last_completed");
		}
	insertSql = "insert into TK_ULSTREC ( PLANT_CODE, NVTIMESTAMP, AREA, PAGE, LINE, TK_ULSTUOM, TK_UPRTNO ) values ( ?, ?, ?, ?, ?, ?, ?)";
	updateSql = "update TK_ULSTREC set  PLANT_CODE = ?, NVTIMESTAMP = ?, AREA = ?, PAGE = ?, LINE = ?, TK_ULSTUOM = ?, TK_UPRTNO = ?  where area = ? and page = ? line = ? ";

	qDebug(category) << "insertSQL - insert into TK_ULSTREC ( PLANT_CODE, NVTIMESTAMP, AREA, PAGE, LINE, TK_ULSTUOM, TK_UPRTNO ) values ( ?, ?, ?, ?, ?, ?, ?)";
	qDebug(category) << "fetchSQL - select  DB_ID, NVTIMESTAMP, AREA, PAGE, LINE, TK_ULSTUOM, TK_UPRTNO from TK_ULSTREC";
	qDebug(category) << "unsertSQL - update TK_ULSTREC set  PLANT_CODE = ?, NVTIMESTAMP = ?, AREA = ?, PAGE = ?, LINE = ?, TK_ULSTUOM = ?, TK_UPRTNO = ?  where area = ? and page = ? line = ? ";

#pragma endregion Sql Statements_TK_ULSTREC
	SQLHANDLE		insert_hStmt = SQL_NULL_HANDLE;
	SQLHANDLE		fetch_hStmt = SQL_NULL_HANDLE; 
	SQLHANDLE		update_hStmt = SQL_NULL_HANDLE; 
 
	r = ::SQLAllocHandle(SQL_HANDLE_STMT, hDbc_source, &fetch_hStmt);
	if (r != SQL_SUCCESS) {
		 qCCritical(category) << QString("Error  hDbc_Source SQLCode : %1 is %2").arg(QString::number( (long)hDbc_source)).arg(QString::number(r));
		return; 
	}
	r = ::SQLAllocHandle(SQL_HANDLE_STMT, hDbc_target, &insert_hStmt);
	if (r != SQL_SUCCESS) {
		 qCCritical(category) << QString("Error hDbc_Source -SQLCode: %1 is %2").arg(QString::number( (long)hDbc_target)).arg(QString::number(r));
		return; 
	}
	r = ::SQLAllocHandle(SQL_HANDLE_STMT, hDbc_target, &update_hStmt);
	if (r != SQL_SUCCESS) {
		 qCCritical(category) << QString("Error hDbc_Source +SQLCode: %1 is %2").arg(QString::number( (long)hDbc_target)).arg(QString::number(r));
		return; 
	}
 
	hStmt_Fetch = fetch_hStmt;
	hStmt_Insert = insert_hStmt;
	hStmt_Update = update_hStmt;
 
	SQLSetStmtAttr(hStmt_Fetch, SQL_ATTR_USE_BOOKMARKS, (SQLPOINTER)SQL_UB_OFF, 0);
	SQLSetStmtAttr(hStmt_Fetch, SQL_ATTR_ROW_BIND_TYPE, (SQLPOINTER)SQL_BIND_BY_COLUMN, 0);
	SQLSetStmtAttr(hStmt_Fetch, SQL_ATTR_ROW_ARRAY_SIZE, (SQLPOINTER)1, 0);
	SQLSetStmtAttr(hStmt_Fetch, SQL_ATTR_ROWS_FETCHED_PTR, &numRowsFetched, 0);

// Fields used by this class 
// ---------------------------------------------------

#pragma region Resize Fields TK_ULSTREC
	qDebug(category) << "Malloc - DB_ID[2]";
	DB_ID.resize(2);
	qDebug(category) << "Malloc - NVTIMESTAMP[23]";
	NVTIMESTAMP.resize(23);
	qDebug(category) << "Malloc - AREA[2]";
	AREA.resize(2);
	qDebug(category) << "Malloc - PAGE[4]";
	PAGE.resize(4);
	qDebug(category) << "Malloc - LINE[2]";
	LINE.resize(2);
	qDebug(category) << "Malloc - TK_ULSTUOM[2]";
	TK_ULSTUOM.resize(2);
	qDebug(category) << "Malloc - TK_UPRTNO[18]";
	TK_UPRTNO.resize(18);

#pragma endregion Resize Fields TK_ULSTREC
}
void TK_ULSTREC::close()
{
	QLoggingCategory category("classLibQ");
	if (m_bIsOpen)
	{
	qDebug(category) << "database is Open";
		SQLHANDLE source_hStmt = hStmt_Fetch;
		SQLHANDLE insert_hStmt = hStmt_Insert;
		SQLHANDLE hDb_S = this->hDbc_source;
		SQLHANDLE hDb_T = hDbc_target;
		SQLHANDLE hEnvS = hEnv_Source;
		SQLHANDLE hEnvT = hEnv_Target;
		RETCODE r;

		r = ::SQLFreeHandle(SQL_HANDLE_STMT, hStmt_Fetch);
		r = ::SQLFreeHandle(SQL_HANDLE_STMT, hStmt_Insert);
		r = ::SQLFreeHandle(SQL_HANDLE_STMT, hStmt_Update);
		if (hDbc_source != SQL_NULL_HANDLE) 		r = ::SQLDisconnect(hDb_S);
		if (hDbc_target != SQL_NULL_HANDLE) 		r = ::SQLDisconnect(hDb_T);

		r = ::SQLFreeHandle(SQL_HANDLE_DBC, hDb_S);
		r = ::SQLFreeHandle(SQL_HANDLE_DBC, hDb_T);
		r = ::SQLFreeHandle(SQL_HANDLE_ENV, hEnvS);
		r = ::SQLFreeHandle(SQL_HANDLE_ENV, hEnvT);
	}

	hEnv_Source = SQL_NULL_HANDLE;
	hEnv_Target = SQL_NULL_HANDLE;
	hEnv_Source = SQL_NULL_HANDLE;
	hEnv_Target = SQL_NULL_HANDLE;
	hStmt_Fetch = SQL_NULL_HANDLE;
	hStmt_Insert = SQL_NULL_HANDLE;
	hStmt_Update = SQL_NULL_HANDLE;
}

void TK_ULSTREC::open(const QString sourceDSN, const QString targetDSN)
{
	QLoggingCategory category("classLibQ");
	m_lpszTargetDSN = targetDSN;
	m_lpszSourceDSN = sourceDSN;
	qDebug(category) << QString("Source - %1[%2]").arg(sourceDSN);
	qDebug(category) << QString("Target - %1[%2]").arg(targetDSN);
}

void TK_ULSTREC::createTable()
{
	QLoggingCategory category("classLibQ");
	{
		QScopedPointer<nvTableOracleRdb> tbl(new nvTableOracleRdb(nullptr));
		tbl->initialize("TK_ULSTREC", this->m_lpszSourceDSN);
		QString newTbl = tbl->getCreateTableSQL();
		QScopedPointer<qVtExecute> vExec(new qVtExecute(nullptr));
		{
			vExec->initialize(m_lpszTargetDSN, " ", true);
			vExec->setOdbcAttributes(m_OdbcAttributes);
			vExec->ExecuteDirect(newTbl);
		}
	 qDebug(category) << QString("End Create Table %1 ").arg(tableName); 
	}
}

bool TK_ULSTREC::prepare()
{
	RETCODE r;
	QString check;
	QLoggingCategory category("classLibQ");
	 qDebug(category) << fetchSql;
	 qDebug(category) << insertSql;
#ifdef UNICODE
	r = SQLPrepare(hStmt_Insert,toSQLTCHAR(insertSql).data(),(SQLINTEGER)insertSql.length()); 
	if (r != SQL_SUCCESS) {
		check = qWarnODBCHandle(SQL_HANDLE_STMT, hStmt_Insert);
		 qCCritical(category) << QString("Prepare Statement-Insert : %1 is %2").arg(insertSql).arg(check);
		return false; 
	}
	r = SQLPrepare(hStmt_Update,toSQLTCHAR(updateSql).data(),(SQLINTEGER)updateSql.length()); 
	if (r != SQL_SUCCESS) {
		check = qWarnODBCHandle(SQL_HANDLE_STMT, hStmt_Update);
		 qCCritical(category) << QString("Prepare Statement-Update : %1 is %2").arg(updateSql).arg(check);
		return false; 
	}
	r = SQLPrepare(hStmt_Fetch,toSQLTCHAR(fetchSql).data(),(SQLINTEGER)fetchSql.length());
	if (r != SQL_SUCCESS) {
		check = qWarnODBCHandle(SQL_HANDLE_STMT, hStmt_Fetch);
		 qCCritical(category) << QString("Prepare Statement-Insert : %1 is %2").arg(fetchSql).arg(check);
		return false; 
	}
#else
	QByteArray queryI8 = insertSql.toUtf8();
	r = SQLPrepare(insert_hStmt,SQLCHAR*)queryI8.data(),(SQLINTEGER)queryI8.length());
	QByteArray queryU8 = fetchSql.toUtf8();
	r = SQLPrepare(hStmt_Fetch,(SQLCHAR*)queryU8.data(),(SQLINTEGER)queryU8.length());
#endif
	return true;

}

void TK_ULSTREC::prepareTargetTable()
{
	QLoggingCategory category("classLibQ");
	if (this->m_ReplicationOption == ReplicationOption::BulkCopy)
	{
		QScopedPointer<qVtExecute> execSql(new qVtExecute(nullptr));
		DropOption option = this->m_dropOption;
		switch (option)
		{
			case DropOption::DeleteFromTable:
			{
				QLoggingCategory category("classLibQ");
				execSql->initialize(this->m_lpszTargetDSN, "delete from TK_ULSTREC", true);
				execSql->setOdbcAttributes(this->m_OdbcAttributes);
				execSql->ExecuteDirect("delete from TK_ULSTREC");
			}break;
			case DropOption::TruncateTable:
			{
				execSql->initialize(this->m_lpszTargetDSN, "truncate table TK_ULSTREC", true);
				execSql->setOdbcAttributes(this->m_OdbcAttributes);
				execSql->ExecuteDirect("truncate table TK_ULSTREC");
			}break;
			case DropOption::DropTable:
			{
				execSql->initialize(this->m_lpszTargetDSN, "drop table TK_ULSTREC", true);
				execSql->setOdbcAttributes(this->m_OdbcAttributes);
				execSql->ExecuteDirect("drop table TK_ULSTREC");
				createTable();
			}break;
		}
	}
}

bool TK_ULSTREC::bindColumn()
{
	QLoggingCategory category("classLibQ");
	RETCODE r;
	bool isValid=true;
		 qDebug(category) << " Bindings: Ordinal [1] Type: 5 Buffer Size: 2 FieldName: DB_ID ";
		r = ::SQLBindCol(hStmt_Fetch, 1, 5, DB_ID.data(), 2, &cbDB_ID);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Bindings: Ordinal [2] Type: 93 Buffer Size: 23 FieldName: NVTIMESTAMP ";
		r = ::SQLBindCol(hStmt_Fetch, 2, 93, NVTIMESTAMP.data(), 23, &cbNVTIMESTAMP);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Bindings: Ordinal [3] Type: 5 Buffer Size: 2 FieldName: AREA ";
		r = ::SQLBindCol(hStmt_Fetch, 3, 5, AREA.data(), 2, &cbAREA);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Bindings: Ordinal [4] Type: 4 Buffer Size: 4 FieldName: PAGE ";
		r = ::SQLBindCol(hStmt_Fetch, 4, 4, PAGE.data(), 4, &cbPAGE);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Bindings: Ordinal [5] Type: 5 Buffer Size: 2 FieldName: LINE ";
		r = ::SQLBindCol(hStmt_Fetch, 5, 5, LINE.data(), 2, &cbLINE);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Bindings: Ordinal [6] Type: 1 Buffer Size: 2 FieldName: TK_ULSTUOM ";
		r = ::SQLBindCol(hStmt_Fetch, 6, 1, TK_ULSTUOM.data(), 2, &cbTK_ULSTUOM);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Bindings: Ordinal [7] Type: 1 Buffer Size: 18 FieldName: TK_UPRTNO ";
		r = ::SQLBindCol(hStmt_Fetch, 7, 1, TK_UPRTNO.data(), 18, &cbTK_UPRTNO);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
	return isValid;
}

bool TK_ULSTREC::bindParameter()
{
	QLoggingCategory category("classLibQ");
	RETCODE r;
	bool isValid=true;
	{
		 qDebug(category) << " Parameters: Ordinal [1] Type: 5 Buffer Size: 2 FieldName: DB_ID ";
		r = SQLBindParameter(hStmt_Insert, 1, SQL_PARAM_INPUT, SQL_C_DEFAULT, 5, 0, 0, (SQLPOINTER)DB_ID.constData(), 0, &cbDB_ID);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Parameters: Ordinal [2] Type: 93 Buffer Size: 23 FieldName: NVTIMESTAMP ";
		r = SQLBindParameter(hStmt_Insert, 2, SQL_PARAM_INPUT, SQL_C_DEFAULT, 93, 23, 0, (SQLPOINTER)NVTIMESTAMP.constData(), 0, &cbNVTIMESTAMP);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Parameters: Ordinal [3] Type: 5 Buffer Size: 2 FieldName: AREA ";
		r = SQLBindParameter(hStmt_Insert, 3, SQL_PARAM_INPUT, SQL_C_DEFAULT, 5, 0, 0, (SQLPOINTER)AREA.constData(), 0, &cbAREA);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Parameters: Ordinal [4] Type: 4 Buffer Size: 4 FieldName: PAGE ";
		r = SQLBindParameter(hStmt_Insert, 4, SQL_PARAM_INPUT, SQL_C_DEFAULT, 4, 0, 0, (SQLPOINTER)PAGE.constData(), 0, &cbPAGE);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Parameters: Ordinal [5] Type: 5 Buffer Size: 2 FieldName: LINE ";
		r = SQLBindParameter(hStmt_Insert, 5, SQL_PARAM_INPUT, SQL_C_DEFAULT, 5, 0, 0, (SQLPOINTER)LINE.constData(), 0, &cbLINE);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Parameters: Ordinal [6] Type: 1 Buffer Size: 2 FieldName: TK_ULSTUOM ";
		r = SQLBindParameter(hStmt_Insert, 6, SQL_PARAM_INPUT, SQL_C_DEFAULT, 1, 2, 0, (SQLPOINTER)TK_ULSTUOM.constData(), 0, &cbTK_ULSTUOM);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
		 qDebug(category) << " Parameters: Ordinal [7] Type: 1 Buffer Size: 18 FieldName: TK_UPRTNO ";
		r = SQLBindParameter(hStmt_Insert, 7, SQL_PARAM_INPUT, SQL_C_DEFAULT, 1, 18, 0, (SQLPOINTER)TK_UPRTNO.constData(), 0, &cbTK_UPRTNO);
		if (r == SQL_SUCCESS) { isValid=true; }
		else { return false;}
	}
	if (m_ReplicationOption == ReplicationOption::NetChange)
	{
		r = SQLBindParameter(hStmt_Update, 8, SQL_PARAM_INPUT, SQL_C_DEFAULT, 3, 0, 0, (SQLPOINTER)AREA.constData(), 0, &cbAREA);
		if (r == SQL_SUCCESS) { isValid=true; }
		r = SQLBindParameter(hStmt_Update, 9, SQL_PARAM_INPUT, SQL_C_DEFAULT, 4, 0, 0, (SQLPOINTER)PAGE.constData(), 0, &cbPAGE);
		if (r == SQL_SUCCESS) { isValid=true; }
		r = SQLBindParameter(hStmt_Update, 10, SQL_PARAM_INPUT, SQL_C_DEFAULT, 5, 0, 0, (SQLPOINTER)LINE.constData(), 0, &cbLINE);
		if (r == SQL_SUCCESS) { isValid=true; }
	// TK_ULSTREC is a well formed table for eNVy Replication 
		 qDebug(category) << " Parameters: Ordinal [3] 00 00 FieldName: AREA ";
		 qDebug(category) << " Parameters: Ordinal [4] 00 00  FieldName: PAGE ";
		 qDebug(category) << " Parameters: Ordinal [5] 00 00 FieldName:  LINE ";
	} // 	if (m_ReplicationOption == ReplicationOption::NetChange)
	return isValid;
}

bool TK_ULSTREC::process(int rowSize)
{
	QLoggingCategory category("classLibQ");
	initOdbcAttributes();
	connect(Source);
	connect(Target);
	initialize();
	prepareTargetTable();
	prepare();
	bindColumn();
	bindParameter();
	copyTable();
	close();
	return false;
}

void TK_ULSTREC::copyTable()
{
	QLoggingCategory category("classLibQ");
	RETCODE r;
	QString check;
	r = SQLExecute(hStmt_Fetch);
		if (bIsAbort) {
			emit aborted(tableName, rowsFetched, rowsInserted, rowsUpdated);
			return;
		}
		while((r = SQLFetch(hStmt_Fetch)) != SQL_NO_DATA) {
		if (r != SQL_SUCCESS) {
			check = qWarnODBCHandle(SQL_HANDLE_STMT, hStmt_Fetch);
			qCCritical(category) << QString("SqlFetch - Error : %1 is %2").arg(fetchSql).arg(check);
			return;
		} 
		rowsFetched++;
		if (m_ReplicationOption == ReplicationOption::BulkCopy)
		{
			r = SQLExecute(hStmt_Insert);
			if (r == SQL_ERROR) {
				check = qWarnODBCHandle(SQL_HANDLE_STMT, hStmt_Insert);
				 qCCritical(category) << QString("SqlExecute:Insert - Error : %1 is %2").arg(insertSql).arg(check);
				return;
			}
			rowsInserted++;
			if ((rowsFetched % updateInterval) == 0) {
				qCInfo(category) << QString("[%1.%2]	Insertion: %3	Updates : %4	Fetched : %5").arg(profileName).arg(tableName).arg(rowsInserted).arg(rowsUpdated).arg(rowsFetched);
				emit updateStatusFetched(profileName, tableName, rowsFetched,rowsInserted,rowsUpdated);
			}
			if (m_ReplicationOption == ReplicationOption::NetChange)
			{
			r = SQLExecute(hStmt_Update);
			if (r != SQL_SUCCESS) {
				check = qWarnODBCHandle(SQL_HANDLE_STMT, hStmt_Update);
				 qCInfo(category)  << QString("SqlExecute:Update - Error : %1 is %2").arg(updateSql).arg(check);
				r = SQLExecute(hStmt_Insert);
				if (r != SQL_SUCCESS) {
					check = qWarnODBCHandle(SQL_HANDLE_STMT, hStmt_Insert);
					 qCritical(category) << QString("SqlExecute:Insert - Error : %1 is %2").arg(insertSql).arg(check);
					return;
				}
				else 	rowsInserted++;
				}
				else	rowsUpdated++;
			}
			emit updateStatusFetched(profileName, tableName, rowsFetched,rowsInserted,rowsUpdated);
		}
	} 
qCInfo(category) << QString("[%1.%2]	Insertion: %3	Updates : %4	Fetched : %5").arg(profileName).arg(tableName).arg(rowsInserted).arg(rowsUpdated).arg(rowsFetched);
}

void TK_ULSTREC::connect(connectionHandle connectionSource)
{

	QLoggingCategory category("classLibQ");
	RETCODE r;

	bool isValid = false;
	HWND	hWnd = nullptr;
	hWnd = ::GetDesktopWindow(); 
	SQLSMALLINT nResult = 0;

	SQLSMALLINT cb;
	UWORD wConnectOption = SQL_DRIVER_COMPLETE; //SQL_DRIVER_NOPROMPT;
	QVarLengthArray<SQLTCHAR> connOut(1024);
	memset(connOut.data(), 0, connOut.size() * sizeof(SQLTCHAR));

	switch (connectionSource)
	{
		case Source:
			{// environment
				SQLHANDLE hEnv = SQL_NULL_HANDLE;
				SQLHANDLE hDbc = SQL_NULL_HANDLE;
				r = ::SQLAllocHandle(SQL_HANDLE_ENV, SQL_NULL_HANDLE, &hEnv);
				if (r == SQL_SUCCESS) isValid = true;

				foreach(nOdbcAttributesClass * k, this->m_OdbcAttributes_Map)
				{
					if (k->attributeType == enumAttributeType::hEnv)
					{
						r = ::SQLSetEnvAttr(hEnv, (SQLINTEGER) k->odbcKey, (SQLPOINTER)k->odbcValue, 0);
						if (r == SQL_SUCCESS) isValid = true;
					}
				}
				hEnv_Source = hEnv;

				r = SQLAllocHandle(SQL_HANDLE_DBC, hEnv, &hDbc);
				if (r == SQL_SUCCESS) isValid = true;
				foreach(nOdbcAttributesClass * k, this->m_OdbcAttributes_Map)
				{
					if (k->attributeType == enumAttributeType::hDbc)
					{
					r = ::SQLSetConnectAttr(hDbc, k->odbcKey, (SQLPOINTER)k->odbcValue, 0);
					if (k->odbcKey == SQL_ATTR_CONNECTION_POOLING && k->odbcValue == SQL_CP_ONE_PER_DRIVER) wConnectOption = SQL_DRIVER_NOPROMPT;
					if (k->odbcKey == SQL_ATTR_CONNECTION_POOLING && k->odbcValue == SQL_CP_ONE_PER_HENV) wConnectOption = SQL_DRIVER_NOPROMPT;
					if (k->odbcKey == SQL_ATTR_CONNECTION_POOLING && k->odbcValue == SQL_CP_DRIVER_AWARE) wConnectOption = SQL_DRIVER_NOPROMPT;
					if (r == SQL_SUCCESS) isValid = true;
					}
				}
				hDbc_source = hDbc;
				if (isValid)
				{
					r = ::SQLDriverConnect(
						hDbc,
						hWnd,
#ifdef UNICODE
						toSQLTCHAR(m_lpszSourceDSN).data(),
#else
						(SQLCHAR*)dsnSource.toUtf8().data(),
#endif
						(SQLSMALLINT)m_lpszSourceDSN.length(),
						connOut.data(),
						1024,
						&cb, 
						wConnectOption); 
					int colSize = cb / sizeof(SQLTCHAR);
					if (r != SQL_SUCCESS && r != SQL_SUCCESS_WITH_INFO)
					{
						QString check = qWarnODBCHandle(SQL_HANDLE_DBC, hDbc);
						qCritical(category) <<  check;
						m_bIsOpen = false;
					}
					m_bIsOpen = true;
				}
			} break;
		case Target:
			{
				SQLHANDLE hEnv = SQL_NULL_HANDLE;
				SQLHANDLE hDbc = SQL_NULL_HANDLE;
				r = ::SQLAllocHandle(SQL_HANDLE_ENV, SQL_NULL_HANDLE, &hEnv);
				if (r == SQL_SUCCESS) isValid = true;

				foreach(nOdbcAttributesClass * k, this->m_OdbcAttributes_Map)
				{
					if (k->attributeType == enumAttributeType::hEnv)
					{
						r = ::SQLSetEnvAttr(hEnv, (SQLINTEGER) k->odbcKey, (SQLPOINTER)k->odbcValue, 0);
						if (r == SQL_SUCCESS) isValid = true;
					}
				}
				hEnv_Target = hEnv;

				r = SQLAllocHandle(SQL_HANDLE_DBC, hEnv, &hDbc);
				if (r == SQL_SUCCESS) isValid = true;
				foreach(nOdbcAttributesClass * k, this->m_OdbcAttributes_Map)
				{
				if (k->attributeType == enumAttributeType::hDbc)
					{
					r = ::SQLSetConnectAttr(hDbc, k->odbcKey, (SQLPOINTER)k->odbcValue, 0);
					if (k->odbcKey == SQL_ATTR_CONNECTION_POOLING && k->odbcValue == SQL_CP_ONE_PER_DRIVER) wConnectOption = SQL_DRIVER_NOPROMPT;
					if (k->odbcKey == SQL_ATTR_CONNECTION_POOLING && k->odbcValue == SQL_CP_ONE_PER_HENV) wConnectOption = SQL_DRIVER_NOPROMPT;
					if (k->odbcKey == SQL_ATTR_CONNECTION_POOLING && k->odbcValue == SQL_CP_DRIVER_AWARE) wConnectOption = SQL_DRIVER_NOPROMPT;
					if (r == SQL_SUCCESS) isValid = true;
					}
				}
				hDbc_target = hDbc;
				if (isValid) {
					r = ::SQLDriverConnect(
						hDbc,
						hWnd,
#ifdef UNICODE
						toSQLTCHAR(m_lpszTargetDSN).data(),
#else
						(SQLCHAR*)m_lpszTargetDSN.toUtf8().data(),
#endif
						(SQLSMALLINT)m_lpszTargetDSN.length(),
						connOut.data(),
						1024,
						&cb, 
						wConnectOption); 
						int colSize = cb / sizeof(SQLTCHAR);
					if (r != SQL_SUCCESS && r != SQL_SUCCESS_WITH_INFO)
						{
							QString check = qWarnODBCHandle(SQL_HANDLE_DBC, hDbc);
							qCritical(category) <<  check;
							m_bIsOpen = false;
						}
							m_bIsOpen = true;
					}
			} break;
			default: break;
	}
}
