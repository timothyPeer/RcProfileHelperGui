/*H**********************************************************************
* FILENAME :        Launcher_TRKDB100.cpp            DESIGN REF: 
*
* DESCRIPTION :
*       This class configures a container to interact with the QThreadPool
*       data replications. This class is the main class to access core 
*       functions for the replication process. 
*
*        Rdb schema.
*
*    THIS FILE IS AN AUTO-GENERATED INCLUDE FILE
*
* PUBLIC FUNCTIONS :
*       None
*      
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


#pragma region hashMap TRKDB100
#include "LaunchQRC_TRKDB100.h"
#include <QLoggingCategory>
#include "connectionstringbuilder.h"
#include "clsrowstodeletecleanup.h" 
#include "tableEnumerations_TRKDB100.h"
#pragma region table includes
#include "ClassLibQ_TRKDB100.h"
#include "vcnvtransfers.h" 

#pragma endregion table includes
launchQRC_TRKDB100::launchQRC_TRKDB100(QObject * parent) : QObject(parent) {
	 workerPool = new QThreadPool(this);
}

launchQRC_TRKDB100::~launchQRC_TRKDB100() {
	m_HashedMap_TRKDB100.clear();
}

void launchQRC_TRKDB100::initialize(const QString _profileName, const QString _tableName, const QString _sourceDSN, const QString _targetDSN, DropOption dropOption, ReplicationOption replicationOption)
{
	tables.clear();
	tableName = _tableName;
	targetDSN = _targetDSN;
	sourceDSN = _sourceDSN;
	profileName = _profileName;
// 	QScopedPointer<connectionStringBuilder> builder(new connectionStringBuilder());
	// 	envyRepositoryString = builder->getEnvyConnectionString();
	setDropOption(dropOption);
	setReplicationOption(replicationOption);
# pragma region HashedMap_TRKDB100
	schemaField * TK_INTSOHSHSET_Field = new schemaField(this);
	schemaField * TK_PRTLIDSET_Field = new schemaField(this);
	schemaField * TK_PRTHSHSET_Field = new schemaField(this);
	schemaField * TK_TYPHSHSET_Field = new schemaField(this);
	schemaField * TK_FLGREC_Field = new schemaField(this);
	schemaField * TK_LTFREC_Field = new schemaField(this);
	schemaField * TK_PRCHSHSET_Field = new schemaField(this);
	schemaField * TK_NOTREC_Field = new schemaField(this);
	schemaField * TK_UPRTREC_Field = new schemaField(this);
	schemaField * TK_UPRTULSTSET_Field = new schemaField(this);
	schemaField * TK_LIDREC_Field = new schemaField(this);
	schemaField * TK_LTPBOMSET_Field = new schemaField(this);
	schemaField * TK_LIDHSHSET_Field = new schemaField(this);
	schemaField * TK_LIDLTPSET_Field = new schemaField(this);
	schemaField * TK_INTREC_Field = new schemaField(this);
	schemaField * TK_LTPCOMSET_Field = new schemaField(this);
	schemaField * TK_HDRREC_Field = new schemaField(this);
	schemaField * TK_CNVREC_Field = new schemaField(this);
	schemaField * TK_UHSTREC_Field = new schemaField(this);
	schemaField * TK_INTFMHSHSET_Field = new schemaField(this);
	schemaField * TK_LTDREC_Field = new schemaField(this);
	schemaField * TK_HDRHSHSET_Field = new schemaField(this);
	schemaField * TK_HDRLTPSET_Field = new schemaField(this);
	schemaField * TK_CNVHSHSET_Field = new schemaField(this);
	schemaField * TK_LTPHSHSET_Field = new schemaField(this);
	schemaField * TK_INTPOSRTSET_Field = new schemaField(this);
	schemaField * TK_UPRTHSHSET_Field = new schemaField(this);
	schemaField * TK_LIDNOTSET_Field = new schemaField(this);
	schemaField * TK_INTTOHSHSET_Field = new schemaField(this);
	schemaField * TK_FLGHSHSET_Field = new schemaField(this);
	schemaField * TK_INTCHNSET_Field = new schemaField(this);
	schemaField * TK_LOTREC_Field = new schemaField(this);
	schemaField * TK_TYPHDRSET_Field = new schemaField(this);
	schemaField * TK_PRCREC_Field = new schemaField(this);
	schemaField * TK_LOTHSHSET_Field = new schemaField(this);
	schemaField * TK_PRTLTFSET_Field = new schemaField(this);
	schemaField * TK_PRTREC_Field = new schemaField(this);
	schemaField * TK_UHSTCHNSET_Field = new schemaField(this);
	schemaField * TK_LOTLIDSET_Field = new schemaField(this);
	schemaField * TK_LTPREC_Field = new schemaField(this);
	schemaField * TK_TYPREC_Field = new schemaField(this);
	schemaField * TK_ULSTREC_Field = new schemaField(this);
	TK_INTSOHSHSET_Field->setSchemaField("TK_INTSOHSHSET",enumTK_INTSOHSHSET);
	TK_PRTLIDSET_Field->setSchemaField("TK_PRTLIDSET",enumTK_PRTLIDSET);
	TK_PRTHSHSET_Field->setSchemaField("TK_PRTHSHSET",enumTK_PRTHSHSET);
	TK_TYPHSHSET_Field->setSchemaField("TK_TYPHSHSET",enumTK_TYPHSHSET);
	TK_FLGREC_Field->setSchemaField("TK_FLGREC",enumTK_FLGREC);
	TK_LTFREC_Field->setSchemaField("TK_LTFREC",enumTK_LTFREC);
	TK_PRCHSHSET_Field->setSchemaField("TK_PRCHSHSET",enumTK_PRCHSHSET);
	TK_NOTREC_Field->setSchemaField("TK_NOTREC",enumTK_NOTREC);
	TK_UPRTREC_Field->setSchemaField("TK_UPRTREC",enumTK_UPRTREC);
	TK_UPRTULSTSET_Field->setSchemaField("TK_UPRTULSTSET",enumTK_UPRTULSTSET);
	TK_LIDREC_Field->setSchemaField("TK_LIDREC",enumTK_LIDREC);
	TK_LTPBOMSET_Field->setSchemaField("TK_LTPBOMSET",enumTK_LTPBOMSET);
	TK_LIDHSHSET_Field->setSchemaField("TK_LIDHSHSET",enumTK_LIDHSHSET);
	TK_LIDLTPSET_Field->setSchemaField("TK_LIDLTPSET",enumTK_LIDLTPSET);
	TK_INTREC_Field->setSchemaField("TK_INTREC",enumTK_INTREC);
	TK_LTPCOMSET_Field->setSchemaField("TK_LTPCOMSET",enumTK_LTPCOMSET);
	TK_HDRREC_Field->setSchemaField("TK_HDRREC",enumTK_HDRREC);
	TK_CNVREC_Field->setSchemaField("TK_CNVREC",enumTK_CNVREC);
	TK_UHSTREC_Field->setSchemaField("TK_UHSTREC",enumTK_UHSTREC);
	TK_INTFMHSHSET_Field->setSchemaField("TK_INTFMHSHSET",enumTK_INTFMHSHSET);
	TK_LTDREC_Field->setSchemaField("TK_LTDREC",enumTK_LTDREC);
	TK_HDRHSHSET_Field->setSchemaField("TK_HDRHSHSET",enumTK_HDRHSHSET);
	TK_HDRLTPSET_Field->setSchemaField("TK_HDRLTPSET",enumTK_HDRLTPSET);
	TK_CNVHSHSET_Field->setSchemaField("TK_CNVHSHSET",enumTK_CNVHSHSET);
	TK_LTPHSHSET_Field->setSchemaField("TK_LTPHSHSET",enumTK_LTPHSHSET);
	TK_INTPOSRTSET_Field->setSchemaField("TK_INTPOSRTSET",enumTK_INTPOSRTSET);
	TK_UPRTHSHSET_Field->setSchemaField("TK_UPRTHSHSET",enumTK_UPRTHSHSET);
	TK_LIDNOTSET_Field->setSchemaField("TK_LIDNOTSET",enumTK_LIDNOTSET);
	TK_INTTOHSHSET_Field->setSchemaField("TK_INTTOHSHSET",enumTK_INTTOHSHSET);
	TK_FLGHSHSET_Field->setSchemaField("TK_FLGHSHSET",enumTK_FLGHSHSET);
	TK_INTCHNSET_Field->setSchemaField("TK_INTCHNSET",enumTK_INTCHNSET);
	TK_LOTREC_Field->setSchemaField("TK_LOTREC",enumTK_LOTREC);
	TK_TYPHDRSET_Field->setSchemaField("TK_TYPHDRSET",enumTK_TYPHDRSET);
	TK_PRCREC_Field->setSchemaField("TK_PRCREC",enumTK_PRCREC);
	TK_LOTHSHSET_Field->setSchemaField("TK_LOTHSHSET",enumTK_LOTHSHSET);
	TK_PRTLTFSET_Field->setSchemaField("TK_PRTLTFSET",enumTK_PRTLTFSET);
	TK_PRTREC_Field->setSchemaField("TK_PRTREC",enumTK_PRTREC);
	TK_UHSTCHNSET_Field->setSchemaField("TK_UHSTCHNSET",enumTK_UHSTCHNSET);
	TK_LOTLIDSET_Field->setSchemaField("TK_LOTLIDSET",enumTK_LOTLIDSET);
	TK_LTPREC_Field->setSchemaField("TK_LTPREC",enumTK_LTPREC);
	TK_TYPREC_Field->setSchemaField("TK_TYPREC",enumTK_TYPREC);
	TK_ULSTREC_Field->setSchemaField("TK_ULSTREC",enumTK_ULSTREC);
	m_HashedMap_TRKDB100.insert("TK_INTSOHSHSET", TK_INTSOHSHSET_Field);
	m_HashedMap_TRKDB100.insert("TK_PRTLIDSET", TK_PRTLIDSET_Field);
	m_HashedMap_TRKDB100.insert("TK_PRTHSHSET", TK_PRTHSHSET_Field);
	m_HashedMap_TRKDB100.insert("TK_TYPHSHSET", TK_TYPHSHSET_Field);
	m_HashedMap_TRKDB100.insert("TK_FLGREC", TK_FLGREC_Field);
	m_HashedMap_TRKDB100.insert("TK_LTFREC", TK_LTFREC_Field);
	m_HashedMap_TRKDB100.insert("TK_PRCHSHSET", TK_PRCHSHSET_Field);
	m_HashedMap_TRKDB100.insert("TK_NOTREC", TK_NOTREC_Field);
	m_HashedMap_TRKDB100.insert("TK_UPRTREC", TK_UPRTREC_Field);
	m_HashedMap_TRKDB100.insert("TK_UPRTULSTSET", TK_UPRTULSTSET_Field);
	m_HashedMap_TRKDB100.insert("TK_LIDREC", TK_LIDREC_Field);
	m_HashedMap_TRKDB100.insert("TK_LTPBOMSET", TK_LTPBOMSET_Field);
	m_HashedMap_TRKDB100.insert("TK_LIDHSHSET", TK_LIDHSHSET_Field);
	m_HashedMap_TRKDB100.insert("TK_LIDLTPSET", TK_LIDLTPSET_Field);
	m_HashedMap_TRKDB100.insert("TK_INTREC", TK_INTREC_Field);
	m_HashedMap_TRKDB100.insert("TK_LTPCOMSET", TK_LTPCOMSET_Field);
	m_HashedMap_TRKDB100.insert("TK_HDRREC", TK_HDRREC_Field);
	m_HashedMap_TRKDB100.insert("TK_CNVREC", TK_CNVREC_Field);
	m_HashedMap_TRKDB100.insert("TK_UHSTREC", TK_UHSTREC_Field);
	m_HashedMap_TRKDB100.insert("TK_INTFMHSHSET", TK_INTFMHSHSET_Field);
	m_HashedMap_TRKDB100.insert("TK_LTDREC", TK_LTDREC_Field);
	m_HashedMap_TRKDB100.insert("TK_HDRHSHSET", TK_HDRHSHSET_Field);
	m_HashedMap_TRKDB100.insert("TK_HDRLTPSET", TK_HDRLTPSET_Field);
	m_HashedMap_TRKDB100.insert("TK_CNVHSHSET", TK_CNVHSHSET_Field);
	m_HashedMap_TRKDB100.insert("TK_LTPHSHSET", TK_LTPHSHSET_Field);
	m_HashedMap_TRKDB100.insert("TK_INTPOSRTSET", TK_INTPOSRTSET_Field);
	m_HashedMap_TRKDB100.insert("TK_UPRTHSHSET", TK_UPRTHSHSET_Field);
	m_HashedMap_TRKDB100.insert("TK_LIDNOTSET", TK_LIDNOTSET_Field);
	m_HashedMap_TRKDB100.insert("TK_INTTOHSHSET", TK_INTTOHSHSET_Field);
	m_HashedMap_TRKDB100.insert("TK_FLGHSHSET", TK_FLGHSHSET_Field);
	m_HashedMap_TRKDB100.insert("TK_INTCHNSET", TK_INTCHNSET_Field);
	m_HashedMap_TRKDB100.insert("TK_LOTREC", TK_LOTREC_Field);
	m_HashedMap_TRKDB100.insert("TK_TYPHDRSET", TK_TYPHDRSET_Field);
	m_HashedMap_TRKDB100.insert("TK_PRCREC", TK_PRCREC_Field);
	m_HashedMap_TRKDB100.insert("TK_LOTHSHSET", TK_LOTHSHSET_Field);
	m_HashedMap_TRKDB100.insert("TK_PRTLTFSET", TK_PRTLTFSET_Field);
	m_HashedMap_TRKDB100.insert("TK_PRTREC", TK_PRTREC_Field);
	m_HashedMap_TRKDB100.insert("TK_UHSTCHNSET", TK_UHSTCHNSET_Field);
	m_HashedMap_TRKDB100.insert("TK_LOTLIDSET", TK_LOTLIDSET_Field);
	m_HashedMap_TRKDB100.insert("TK_LTPREC", TK_LTPREC_Field);
	m_HashedMap_TRKDB100.insert("TK_TYPREC", TK_TYPREC_Field);
	m_HashedMap_TRKDB100.insert("TK_ULSTREC", TK_ULSTREC_Field);
#pragma endregion hashMap TRKDB100

}

void launchQRC_TRKDB100::process()
{

		connectionStringBuilder builder;
		QString envyRepositoryString = builder.getEnvyConnectionString();
		QString odbcAttributes = builder.getOdbcAttributes();
	int ffx;
	QHash<QString, schemaField*>::const_iterator i = m_HashedMap_TRKDB100.find(tableName);
	while (i != m_HashedMap_TRKDB100.end() && i.key() == tableName) {
		schemaField * fld = i.value();
		ffx = fld->ordinalId;
		break;
	}


	switch (ffx)
	{
		case Rctables::enumTK_INTSOHSHSET:
		{
			QLoggingCategory category("classLibQ");
			QDateTime dateTime1 = QDateTime::currentDateTime();
			QScopedPointer<connectionStringBuilder> builder(new connectionStringBuilder(this));
			vcNvTransfers nt;
			clsRowsToDeleteCleanup nRtd;
			nt.setSourceDSN(sourceDSN);
			nt.setTableName("TK_INTSOHSHSET");
			nt.setProfileName("TRKDB100");
			nt.UpdateNvTransfersFromLastAttempted();
			nt.setAutoDelete(true);
			nRtd.initialize(builder->getEnvyConnectionString(),builder->getOdbcAttributes(),tableName,profileName,sourceDSN,targetDSN);
			nRtd.deleteRtdFromTarget();
			QScopedPointer<TK_INTSOHSHSET> tk_intsohshset(new TK_INTSOHSHSET());
			tk_intsohshset->open(sourceDSN, targetDSN);
			tk_intsohshset->setRepositoryString(builder->getEnvyConnectionString());
			tk_intsohshset->setProfileName(profileName);
			tk_intsohshset->setReplicationOption(eReplicationOption);
			tk_intsohshset->setDropOption(edropOption);
			tk_intsohshset->setOdbcAttributes(builder->getOdbcAttributes());
			tk_intsohshset->process(1);
// send the Update
			nt.run();
			nRtd.run();
			QDateTime dateTime2 = QDateTime::currentDateTime();
			qint64 millisecondsDiff = dateTime1.msecsTo(dateTime2);
			qInfo(category) << QString("Processed  %1->rowsProcessed() in %2 seconds").arg(tableName).arg(millisecondsDiff/60);
		} break;
		case Rctables::enumTK_PRTLIDSET:
		{
			QLoggingCategory category("classLibQ");
			QDateTime dateTime1 = QDateTime::currentDateTime();
			QScopedPointer<connectionStringBuilder> builder(new connectionStringBuilder(this));
			vcNvTransfers nt;
			clsRowsToDeleteCleanup nRtd;
			nt.setSourceDSN(sourceDSN);
			nt.setTableName("TK_PRTLIDSET");
			nt.setProfileName("TRKDB100");
			nt.UpdateNvTransfersFromLastAttempted();
			nt.setAutoDelete(true);
			nRtd.initialize(builder->getEnvyConnectionString(),builder->getOdbcAttributes(),tableName,profileName,sourceDSN,targetDSN);
			nRtd.deleteRtdFromTarget();
			QScopedPointer<TK_PRTLIDSET> tk_prtlidset(new TK_PRTLIDSET());
			tk_prtlidset->open(sourceDSN, targetDSN);
			tk_prtlidset->setRepositoryString(builder->getEnvyConnectionString());
			tk_prtlidset->setProfileName(profileName);
			tk_prtlidset->setReplicationOption(eReplicationOption);
			tk_prtlidset->setDropOption(edropOption);
			tk_prtlidset->setOdbcAttributes(builder->getOdbcAttributes());
			tk_prtlidset->process(1);
// send the Update
			nt.run();
			nRtd.run();
			QDateTime dateTime2 = QDateTime::currentDateTime();
			qint64 millisecondsDiff = dateTime1.msecsTo(dateTime2);
			qInfo(category) << QString("Processed  %1->rowsProcessed() in %2 seconds").arg(tableName).arg(millisecondsDiff/60);
		} break;
		case Rctables::enumTK_PRTHSHSET:
		{
			QLoggingCategory category("classLibQ");
			QDateTime dateTime1 = QDateTime::currentDateTime();
			QScopedPointer<connectionStringBuilder> builder(new connectionStringBuilder(this));
			vcNvTransfers nt;
			clsRowsToDeleteCleanup nRtd;
			nt.setSourceDSN(sourceDSN);
			nt.setTableName("TK_PRTHSHSET");
			nt.setProfileName("TRKDB100");
			nt.UpdateNvTransfersFromLastAttempted();
			nt.setAutoDelete(true);
			nRtd.initialize(builder->getEnvyConnectionString(),builder->getOdbcAttributes(),tableName,profileName,sourceDSN,targetDSN);
			nRtd.deleteRtdFromTarget();
			QScopedPointer<TK_PRTHSHSET> tk_prthshset(new TK_PRTHSHSET());
			tk_prthshset->open(sourceDSN, targetDSN);
			tk_prthshset->setRepositoryString(builder->getEnvyConnectionString());
			tk_prthshset->setProfileName(profileName);
			tk_prthshset->setReplicationOption(eReplicationOption);
			tk_prthshset->setDropOption(edropOption);
			tk_prthshset->setOdbcAttributes(builder->getOdbcAttributes());
			tk_prthshset->process(1);
// send the Update
			nt.run();
			nRtd.run();
			QDateTime dateTime2 = QDateTime::currentDateTime();
			qint64 millisecondsDiff = dateTime1.msecsTo(dateTime2);
			qInfo(category) << QString("Processed  %1->rowsProcessed() in %2 seconds").arg(tableName).arg(millisecondsDiff/60);
		} break;
		case Rctables::enumTK_TYPHSHSET:
		{
			QLoggingCategory category("classLibQ");
			QDateTime dateTime1 = QDateTime::currentDateTime();
			QScopedPointer<connectionStringBuilder> builder(new connectionStringBuilder(this));
			vcNvTransfers nt;
			clsRowsToDeleteCleanup nRtd;
			nt.setSourceDSN(sourceDSN);
			nt.setTableName("TK_TYPHSHSET");
			nt.setProfileName("TRKDB100");
			nt.UpdateNvTransfersFromLastAttempted();
			nt.setAutoDelete(true);
			nRtd.initialize(builder->getEnvyConnectionString(),builder->getOdbcAttributes(),tableName,profileName,sourceDSN,targetDSN);
			nRtd.deleteRtdFromTarget();
			QScopedPointer<TK_TYPHSHSET> tk_typhshset(new TK_TYPHSHSET());
			tk_typhshset->open(sourceDSN, targetDSN);
			tk_typhshset->setRepositoryString(builder->getEnvyConnectionString());
			tk_typhshset->setProfileName(profileName);
			tk_typhshset->setReplicationOption(eReplicationOption);
			tk_typhshset->setDropOption(edropOption);
			tk_typhshset->setOdbcAttributes(builder->getOdbcAttributes());
			tk_typhshset->process(1);
// send the Update
			nt.run();
			nRtd.run();
			QDateTime dateTime2 = QDateTime::currentDateTime();
			qint64 millisecondsDiff = dateTime1.msecsTo(dateTime2);
			qInfo(category) << QString("Processed  %1->rowsProcessed() in %2 seconds").arg(tableName).arg(millisecondsDiff/60);
		} break;
		case Rctables::enumTK_FLGREC:
		{
			QLoggingCategory category("classLibQ");
			QDateTime dateTime1 = QDateTime::currentDateTime();
			QScopedPointer<connectionStringBuilder> builder(new connectionStringBuilder(this));
			vcNvTransfers nt;
			clsRowsToDeleteCleanup nRtd;
			nt.setSourceDSN(sourceDSN);
			nt.setTableName("TK_FLGREC");
			nt.setProfileName("TRKDB100");
			nt.UpdateNvTransfersFromLastAttempted();
			nt.setAutoDelete(true);
			nRtd.initialize(builder->getEnvyConnectionString(),builder->getOdbcAttributes(),tableName,profileName,sourceDSN,targetDSN);
			nRtd.deleteRtdFromTarget();
			QScopedPointer<TK_FLGREC> tk_flgrec(new TK_FLGREC());
			tk_flgrec->open(sourceDSN, targetDSN);
			tk_flgrec->setRepositoryString(builder->getEnvyConnectionString());
			tk_flgrec->setProfileName(profileName);
			tk_flgrec->setReplicationOption(eReplicationOption);
			tk_flgrec->setDropOption(edropOption);
			tk_flgrec->setOdbcAttributes(builder->getOdbcAttributes());
			tk_flgrec->process(1);
// send the Update
			nt.run();
			nRtd.run();
			QDateTime dateTime2 = QDateTime::currentDateTime();
			qint64 millisecondsDiff = dateTime1.msecsTo(dateTime2);
			qInfo(category) << QString("Processed  %1->rowsProcessed() in %2 seconds").arg(tableName).arg(millisecondsDiff/60);
		} break;
		case Rctables::enumTK_LTFREC:
		{
			QLoggingCategory category("classLibQ");
			QDateTime dateTime1 = QDateTime::currentDateTime();
			QScopedPointer<connectionStringBuilder> builder(new connectionStringBuilder(this));
			vcNvTransfers nt;
			clsRowsToDeleteCleanup nRtd;
			nt.setSourceDSN(sourceDSN);
			nt.setTableName("TK_LTFREC");
			nt.setProfileName("TRKDB100");
			nt.UpdateNvTransfersFromLastAttempted();
			nt.setAutoDelete(true);
			nRtd.initialize(builder->getEnvyConnectionString(),builder->getOdbcAttributes(),tableName,profileName,sourceDSN,targetDSN);
			nRtd.deleteRtdFromTarget();
			QScopedPointer<TK_LTFREC> tk_ltfrec(new TK_LTFREC());
			tk_ltfrec->open(sourceDSN, targetDSN);
			tk_ltfrec->setRepositoryString(builder->getEnvyConnectionString());
			tk_ltfrec->setProfileName(profileName);
			tk_ltfrec->setReplicationOption(eReplicationOption);
			tk_ltfrec->setDropOption(edropOption);
			tk_ltfrec->setOdbcAttributes(builder->getOdbcAttributes());
			tk_ltfrec->process(1);
// send the Update
			nt.run();
			nRtd.run();
			QDateTime dateTime2 = QDateTime::currentDateTime();
			qint64 millisecondsDiff = dateTime1.msecsTo(dateTime2);
			qInfo(category) << QString("Processed  %1->rowsProcessed() in %2 seconds").arg(tableName).arg(millisecondsDiff/60);
		} break;
		case Rctables::enumTK_PRCHSHSET:
		{
			QLoggingCategory category("classLibQ");
			QDateTime dateTime1 = QDateTime::currentDateTime();
			QScopedPointer<connectionStringBuilder> builder(new connectionStringBuilder(this));
			vcNvTransfers nt;
			clsRowsToDeleteCleanup nRtd;
			nt.setSourceDSN(sourceDSN);
			nt.setTableName("TK_PRCHSHSET");
			nt.setProfileName("TRKDB100");
			nt.UpdateNvTransfersFromLastAttempted();
			nt.setAutoDelete(true);
			nRtd.initialize(builder->getEnvyConnectionString(),builder->getOdbcAttributes(),tableName,profileName,sourceDSN,targetDSN);
			nRtd.deleteRtdFromTarget();
			QScopedPointer<TK_PRCHSHSET> tk_prchshset(new TK_PRCHSHSET());
			tk_prchshset->open(sourceDSN, targetDSN);
			tk_prchshset->setRepositoryString(builder->getEnvyConnectionString());
			tk_prchshset->setProfileName(profileName);
			tk_prchshset->setReplicationOption(eReplicationOption);
			tk_prchshset->setDropOption(edropOption);
			tk_prchshset->setOdbcAttributes(builder->getOdbcAttributes());
			tk_prchshset->process(1);
// send the Update
			nt.run();
			nRtd.run();
			QDateTime dateTime2 = QDateTime::currentDateTime();
			qint64 millisecondsDiff = dateTime1.msecsTo(dateTime2);
			qInfo(category) << QString("Processed  %1->rowsProcessed() in %2 seconds").arg(tableName).arg(millisecondsDiff/60);
		} break;
		case Rctables::enumTK_NOTREC:
		{
			QLoggingCategory category("classLibQ");
			QDateTime dateTime1 = QDateTime::currentDateTime();
			QScopedPointer<connectionStringBuilder> builder(new connectionStringBuilder(this));
			vcNvTransfers nt;
			clsRowsToDeleteCleanup nRtd;
			nt.setSourceDSN(sourceDSN);
			nt.setTableName("TK_NOTREC");
			nt.setProfileName("TRKDB100");
			nt.UpdateNvTransfersFromLastAttempted();
			nt.setAutoDelete(true);
			nRtd.initialize(builder->getEnvyConnectionString(),builder->getOdbcAttributes(),tableName,profileName,sourceDSN,targetDSN);
			nRtd.deleteRtdFromTarget();
			QScopedPointer<TK_NOTREC> tk_notrec(new TK_NOTREC());
			tk_notrec->open(sourceDSN, targetDSN);
			tk_notrec->setRepositoryString(builder->getEnvyConnectionString());
			tk_notrec->setProfileName(profileName);
			tk_notrec->setReplicationOption(eReplicationOption);
			tk_notrec->setDropOption(edropOption);
			tk_notrec->setOdbcAttributes(builder->getOdbcAttributes());
			tk_notrec->process(1);
// send the Update
			nt.run();
			nRtd.run();
			QDateTime dateTime2 = QDateTime::currentDateTime();
			qint64 millisecondsDiff = dateTime1.msecsTo(dateTime2);
			qInfo(category) << QString("Processed  %1->rowsProcessed() in %2 seconds").arg(tableName).arg(millisecondsDiff/60);
		} break;
		case Rctables::enumTK_UPRTREC:
		{
			QLoggingCategory category("classLibQ");
			QDateTime dateTime1 = QDateTime::currentDateTime();
			QScopedPointer<connectionStringBuilder> builder(new connectionStringBuilder(this));
			vcNvTransfers nt;
			clsRowsToDeleteCleanup nRtd;
			nt.setSourceDSN(sourceDSN);
			nt.setTableName("TK_UPRTREC");
			nt.setProfileName("TRKDB100");
			nt.UpdateNvTransfersFromLastAttempted();
			nt.setAutoDelete(true);
			nRtd.initialize(builder->getEnvyConnectionString(),builder->getOdbcAttributes(),tableName,profileName,sourceDSN,targetDSN);
			nRtd.deleteRtdFromTarget();
			QScopedPointer<TK_UPRTREC> tk_uprtrec(new TK_UPRTREC());
			tk_uprtrec->open(sourceDSN, targetDSN);
			tk_uprtrec->setRepositoryString(builder->getEnvyConnectionString());
			tk_uprtrec->setProfileName(profileName);
			tk_uprtrec->setReplicationOption(eReplicationOption);
			tk_uprtrec->setDropOption(edropOption);
			tk_uprtrec->setOdbcAttributes(builder->getOdbcAttributes());
			tk_uprtrec->process(1);
// send the Update
			nt.run();
			nRtd.run();
			QDateTime dateTime2 = QDateTime::currentDateTime();
			qint64 millisecondsDiff = dateTime1.msecsTo(dateTime2);
			qInfo(category) << QString("Processed  %1->rowsProcessed() in %2 seconds").arg(tableName).arg(millisecondsDiff/60);
		} break;
		case Rctables::enumTK_UPRTULSTSET:
		{
			QLoggingCategory category("classLibQ");
			QDateTime dateTime1 = QDateTime::currentDateTime();
			QScopedPointer<connectionStringBuilder> builder(new connectionStringBuilder(this));
			vcNvTransfers nt;
			clsRowsToDeleteCleanup nRtd;
			nt.setSourceDSN(sourceDSN);
			nt.setTableName("TK_UPRTULSTSET");
			nt.setProfileName("TRKDB100");
			nt.UpdateNvTransfersFromLastAttempted();
			nt.setAutoDelete(true);
			nRtd.initialize(builder->getEnvyConnectionString(),builder->getOdbcAttributes(),tableName,profileName,sourceDSN,targetDSN);
			nRtd.deleteRtdFromTarget();
			QScopedPointer<TK_UPRTULSTSET> tk_uprtulstset(new TK_UPRTULSTSET());
			tk_uprtulstset->open(sourceDSN, targetDSN);
			tk_uprtulstset->setRepositoryString(builder->getEnvyConnectionString());
			tk_uprtulstset->setProfileName(profileName);
			tk_uprtulstset->setReplicationOption(eReplicationOption);
			tk_uprtulstset->setDropOption(edropOption);
			tk_uprtulstset->setOdbcAttributes(builder->getOdbcAttributes());
			tk_uprtulstset->process(1);
// send the Update
			nt.run();
			nRtd.run();
			QDateTime dateTime2 = QDateTime::currentDateTime();
			qint64 millisecondsDiff = dateTime1.msecsTo(dateTime2);
			qInfo(category) << QString("Processed  %1->rowsProcessed() in %2 seconds").arg(tableName).arg(millisecondsDiff/60);
		} break;
		case Rctables::enumTK_LIDREC:
		{
			QLoggingCategory category("classLibQ");
			QDateTime dateTime1 = QDateTime::currentDateTime();
			QScopedPointer<connectionStringBuilder> builder(new connectionStringBuilder(this));
			vcNvTransfers nt;
			clsRowsToDeleteCleanup nRtd;
			nt.setSourceDSN(sourceDSN);
			nt.setTableName("TK_LIDREC");
			nt.setProfileName("TRKDB100");
			nt.UpdateNvTransfersFromLastAttempted();
			nt.setAutoDelete(true);
			nRtd.initialize(builder->getEnvyConnectionString(),builder->getOdbcAttributes(),tableName,profileName,sourceDSN,targetDSN);
			nRtd.deleteRtdFromTarget();
			QScopedPointer<TK_LIDREC> tk_lidrec(new TK_LIDREC());
			tk_lidrec->open(sourceDSN, targetDSN);
			tk_lidrec->setRepositoryString(builder->getEnvyConnectionString());
			tk_lidrec->setProfileName(profileName);
			tk_lidrec->setReplicationOption(eReplicationOption);
			tk_lidrec->setDropOption(edropOption);
			tk_lidrec->setOdbcAttributes(builder->getOdbcAttributes());
			tk_lidrec->process(1);
// send the Update
			nt.run();
			nRtd.run();
			QDateTime dateTime2 = QDateTime::currentDateTime();
			qint64 millisecondsDiff = dateTime1.msecsTo(dateTime2);
			qInfo(category) << QString("Processed  %1->rowsProcessed() in %2 seconds").arg(tableName).arg(millisecondsDiff/60);
		} break;
		case Rctables::enumTK_LTPBOMSET:
		{
			QLoggingCategory category("classLibQ");
			QDateTime dateTime1 = QDateTime::currentDateTime();
			QScopedPointer<connectionStringBuilder> builder(new connectionStringBuilder(this));
			vcNvTransfers nt;
			clsRowsToDeleteCleanup nRtd;
			nt.setSourceDSN(sourceDSN);
			nt.setTableName("TK_LTPBOMSET");
			nt.setProfileName("TRKDB100");
			nt.UpdateNvTransfersFromLastAttempted();
			nt.setAutoDelete(true);
			nRtd.initialize(builder->getEnvyConnectionString(),builder->getOdbcAttributes(),tableName,profileName,sourceDSN,targetDSN);
			nRtd.deleteRtdFromTarget();
			QScopedPointer<TK_LTPBOMSET> tk_ltpbomset(new TK_LTPBOMSET());
			tk_ltpbomset->open(sourceDSN, targetDSN);
			tk_ltpbomset->setRepositoryString(builder->getEnvyConnectionString());
			tk_ltpbomset->setProfileName(profileName);
			tk_ltpbomset->setReplicationOption(eReplicationOption);
			tk_ltpbomset->setDropOption(edropOption);
			tk_ltpbomset->setOdbcAttributes(builder->getOdbcAttributes());
			tk_ltpbomset->process(1);
// send the Update
			nt.run();
			nRtd.run();
			QDateTime dateTime2 = QDateTime::currentDateTime();
			qint64 millisecondsDiff = dateTime1.msecsTo(dateTime2);
			qInfo(category) << QString("Processed  %1->rowsProcessed() in %2 seconds").arg(tableName).arg(millisecondsDiff/60);
		} break;
		case Rctables::enumTK_LIDHSHSET:
		{
			QLoggingCategory category("classLibQ");
			QDateTime dateTime1 = QDateTime::currentDateTime();
			QScopedPointer<connectionStringBuilder> builder(new connectionStringBuilder(this));
			vcNvTransfers nt;
			clsRowsToDeleteCleanup nRtd;
			nt.setSourceDSN(sourceDSN);
			nt.setTableName("TK_LIDHSHSET");
			nt.setProfileName("TRKDB100");
			nt.UpdateNvTransfersFromLastAttempted();
			nt.setAutoDelete(true);
			nRtd.initialize(builder->getEnvyConnectionString(),builder->getOdbcAttributes(),tableName,profileName,sourceDSN,targetDSN);
			nRtd.deleteRtdFromTarget();
			QScopedPointer<TK_LIDHSHSET> tk_lidhshset(new TK_LIDHSHSET());
			tk_lidhshset->open(sourceDSN, targetDSN);
			tk_lidhshset->setRepositoryString(builder->getEnvyConnectionString());
			tk_lidhshset->setProfileName(profileName);
			tk_lidhshset->setReplicationOption(eReplicationOption);
			tk_lidhshset->setDropOption(edropOption);
			tk_lidhshset->setOdbcAttributes(builder->getOdbcAttributes());
			tk_lidhshset->process(1);
// send the Update
			nt.run();
			nRtd.run();
			QDateTime dateTime2 = QDateTime::currentDateTime();
			qint64 millisecondsDiff = dateTime1.msecsTo(dateTime2);
			qInfo(category) << QString("Processed  %1->rowsProcessed() in %2 seconds").arg(tableName).arg(millisecondsDiff/60);
		} break;
		case Rctables::enumTK_LIDLTPSET:
		{
			QLoggingCategory category("classLibQ");
			QDateTime dateTime1 = QDateTime::currentDateTime();
			QScopedPointer<connectionStringBuilder> builder(new connectionStringBuilder(this));
			vcNvTransfers nt;
			clsRowsToDeleteCleanup nRtd;
			nt.setSourceDSN(sourceDSN);
			nt.setTableName("TK_LIDLTPSET");
			nt.setProfileName("TRKDB100");
			nt.UpdateNvTransfersFromLastAttempted();
			nt.setAutoDelete(true);
			nRtd.initialize(builder->getEnvyConnectionString(),builder->getOdbcAttributes(),tableName,profileName,sourceDSN,targetDSN);
			nRtd.deleteRtdFromTarget();
			QScopedPointer<TK_LIDLTPSET> tk_lidltpset(new TK_LIDLTPSET());
			tk_lidltpset->open(sourceDSN, targetDSN);
			tk_lidltpset->setRepositoryString(builder->getEnvyConnectionString());
			tk_lidltpset->setProfileName(profileName);
			tk_lidltpset->setReplicationOption(eReplicationOption);
			tk_lidltpset->setDropOption(edropOption);
			tk_lidltpset->setOdbcAttributes(builder->getOdbcAttributes());
			tk_lidltpset->process(1);
// send the Update
			nt.run();
			nRtd.run();
			QDateTime dateTime2 = QDateTime::currentDateTime();
			qint64 millisecondsDiff = dateTime1.msecsTo(dateTime2);
			qInfo(category) << QString("Processed  %1->rowsProcessed() in %2 seconds").arg(tableName).arg(millisecondsDiff/60);
		} break;
		case Rctables::enumTK_INTREC:
		{
			QLoggingCategory category("classLibQ");
			QDateTime dateTime1 = QDateTime::currentDateTime();
			QScopedPointer<connectionStringBuilder> builder(new connectionStringBuilder(this));
			vcNvTransfers nt;
			clsRowsToDeleteCleanup nRtd;
			nt.setSourceDSN(sourceDSN);
			nt.setTableName("TK_INTREC");
			nt.setProfileName("TRKDB100");
			nt.UpdateNvTransfersFromLastAttempted();
			nt.setAutoDelete(true);
			nRtd.initialize(builder->getEnvyConnectionString(),builder->getOdbcAttributes(),tableName,profileName,sourceDSN,targetDSN);
			nRtd.deleteRtdFromTarget();
			QScopedPointer<TK_INTREC> tk_intrec(new TK_INTREC());
			tk_intrec->open(sourceDSN, targetDSN);
			tk_intrec->setRepositoryString(builder->getEnvyConnectionString());
			tk_intrec->setProfileName(profileName);
			tk_intrec->setReplicationOption(eReplicationOption);
			tk_intrec->setDropOption(edropOption);
			tk_intrec->setOdbcAttributes(builder->getOdbcAttributes());
			tk_intrec->process(1);
// send the Update
			nt.run();
			nRtd.run();
			QDateTime dateTime2 = QDateTime::currentDateTime();
			qint64 millisecondsDiff = dateTime1.msecsTo(dateTime2);
			qInfo(category) << QString("Processed  %1->rowsProcessed() in %2 seconds").arg(tableName).arg(millisecondsDiff/60);
		} break;
		case Rctables::enumTK_LTPCOMSET:
		{
			QLoggingCategory category("classLibQ");
			QDateTime dateTime1 = QDateTime::currentDateTime();
			QScopedPointer<connectionStringBuilder> builder(new connectionStringBuilder(this));
			vcNvTransfers nt;
			clsRowsToDeleteCleanup nRtd;
			nt.setSourceDSN(sourceDSN);
			nt.setTableName("TK_LTPCOMSET");
			nt.setProfileName("TRKDB100");
			nt.UpdateNvTransfersFromLastAttempted();
			nt.setAutoDelete(true);
			nRtd.initialize(builder->getEnvyConnectionString(),builder->getOdbcAttributes(),tableName,profileName,sourceDSN,targetDSN);
			nRtd.deleteRtdFromTarget();
			QScopedPointer<TK_LTPCOMSET> tk_ltpcomset(new TK_LTPCOMSET());
			tk_ltpcomset->open(sourceDSN, targetDSN);
			tk_ltpcomset->setRepositoryString(builder->getEnvyConnectionString());
			tk_ltpcomset->setProfileName(profileName);
			tk_ltpcomset->setReplicationOption(eReplicationOption);
			tk_ltpcomset->setDropOption(edropOption);
			tk_ltpcomset->setOdbcAttributes(builder->getOdbcAttributes());
			tk_ltpcomset->process(1);
// send the Update
			nt.run();
			nRtd.run();
			QDateTime dateTime2 = QDateTime::currentDateTime();
			qint64 millisecondsDiff = dateTime1.msecsTo(dateTime2);
			qInfo(category) << QString("Processed  %1->rowsProcessed() in %2 seconds").arg(tableName).arg(millisecondsDiff/60);
		} break;
		case Rctables::enumTK_HDRREC:
		{
			QLoggingCategory category("classLibQ");
			QDateTime dateTime1 = QDateTime::currentDateTime();
			QScopedPointer<connectionStringBuilder> builder(new connectionStringBuilder(this));
			vcNvTransfers nt;
			clsRowsToDeleteCleanup nRtd;
			nt.setSourceDSN(sourceDSN);
			nt.setTableName("TK_HDRREC");
			nt.setProfileName("TRKDB100");
			nt.UpdateNvTransfersFromLastAttempted();
			nt.setAutoDelete(true);
			nRtd.initialize(builder->getEnvyConnectionString(),builder->getOdbcAttributes(),tableName,profileName,sourceDSN,targetDSN);
			nRtd.deleteRtdFromTarget();
			QScopedPointer<TK_HDRREC> tk_hdrrec(new TK_HDRREC());
			tk_hdrrec->open(sourceDSN, targetDSN);
			tk_hdrrec->setRepositoryString(builder->getEnvyConnectionString());
			tk_hdrrec->setProfileName(profileName);
			tk_hdrrec->setReplicationOption(eReplicationOption);
			tk_hdrrec->setDropOption(edropOption);
			tk_hdrrec->setOdbcAttributes(builder->getOdbcAttributes());
			tk_hdrrec->process(1);
// send the Update
			nt.run();
			nRtd.run();
			QDateTime dateTime2 = QDateTime::currentDateTime();
			qint64 millisecondsDiff = dateTime1.msecsTo(dateTime2);
			qInfo(category) << QString("Processed  %1->rowsProcessed() in %2 seconds").arg(tableName).arg(millisecondsDiff/60);
		} break;
		case Rctables::enumTK_CNVREC:
		{
			QLoggingCategory category("classLibQ");
			QDateTime dateTime1 = QDateTime::currentDateTime();
			QScopedPointer<connectionStringBuilder> builder(new connectionStringBuilder(this));
			vcNvTransfers nt;
			clsRowsToDeleteCleanup nRtd;
			nt.setSourceDSN(sourceDSN);
			nt.setTableName("TK_CNVREC");
			nt.setProfileName("TRKDB100");
			nt.UpdateNvTransfersFromLastAttempted();
			nt.setAutoDelete(true);
			nRtd.initialize(builder->getEnvyConnectionString(),builder->getOdbcAttributes(),tableName,profileName,sourceDSN,targetDSN);
			nRtd.deleteRtdFromTarget();
			QScopedPointer<TK_CNVREC> tk_cnvrec(new TK_CNVREC());
			tk_cnvrec->open(sourceDSN, targetDSN);
			tk_cnvrec->setRepositoryString(builder->getEnvyConnectionString());
			tk_cnvrec->setProfileName(profileName);
			tk_cnvrec->setReplicationOption(eReplicationOption);
			tk_cnvrec->setDropOption(edropOption);
			tk_cnvrec->setOdbcAttributes(builder->getOdbcAttributes());
			tk_cnvrec->process(1);
// send the Update
			nt.run();
			nRtd.run();
			QDateTime dateTime2 = QDateTime::currentDateTime();
			qint64 millisecondsDiff = dateTime1.msecsTo(dateTime2);
			qInfo(category) << QString("Processed  %1->rowsProcessed() in %2 seconds").arg(tableName).arg(millisecondsDiff/60);
		} break;
		case Rctables::enumTK_UHSTREC:
		{
			QLoggingCategory category("classLibQ");
			QDateTime dateTime1 = QDateTime::currentDateTime();
			QScopedPointer<connectionStringBuilder> builder(new connectionStringBuilder(this));
			vcNvTransfers nt;
			clsRowsToDeleteCleanup nRtd;
			nt.setSourceDSN(sourceDSN);
			nt.setTableName("TK_UHSTREC");
			nt.setProfileName("TRKDB100");
			nt.UpdateNvTransfersFromLastAttempted();
			nt.setAutoDelete(true);
			nRtd.initialize(builder->getEnvyConnectionString(),builder->getOdbcAttributes(),tableName,profileName,sourceDSN,targetDSN);
			nRtd.deleteRtdFromTarget();
			QScopedPointer<TK_UHSTREC> tk_uhstrec(new TK_UHSTREC());
			tk_uhstrec->open(sourceDSN, targetDSN);
			tk_uhstrec->setRepositoryString(builder->getEnvyConnectionString());
			tk_uhstrec->setProfileName(profileName);
			tk_uhstrec->setReplicationOption(eReplicationOption);
			tk_uhstrec->setDropOption(edropOption);
			tk_uhstrec->setOdbcAttributes(builder->getOdbcAttributes());
			tk_uhstrec->process(1);
// send the Update
			nt.run();
			nRtd.run();
			QDateTime dateTime2 = QDateTime::currentDateTime();
			qint64 millisecondsDiff = dateTime1.msecsTo(dateTime2);
			qInfo(category) << QString("Processed  %1->rowsProcessed() in %2 seconds").arg(tableName).arg(millisecondsDiff/60);
		} break;
		case Rctables::enumTK_INTFMHSHSET:
		{
			QLoggingCategory category("classLibQ");
			QDateTime dateTime1 = QDateTime::currentDateTime();
			QScopedPointer<connectionStringBuilder> builder(new connectionStringBuilder(this));
			vcNvTransfers nt;
			clsRowsToDeleteCleanup nRtd;
			nt.setSourceDSN(sourceDSN);
			nt.setTableName("TK_INTFMHSHSET");
			nt.setProfileName("TRKDB100");
			nt.UpdateNvTransfersFromLastAttempted();
			nt.setAutoDelete(true);
			nRtd.initialize(builder->getEnvyConnectionString(),builder->getOdbcAttributes(),tableName,profileName,sourceDSN,targetDSN);
			nRtd.deleteRtdFromTarget();
			QScopedPointer<TK_INTFMHSHSET> tk_intfmhshset(new TK_INTFMHSHSET());
			tk_intfmhshset->open(sourceDSN, targetDSN);
			tk_intfmhshset->setRepositoryString(builder->getEnvyConnectionString());
			tk_intfmhshset->setProfileName(profileName);
			tk_intfmhshset->setReplicationOption(eReplicationOption);
			tk_intfmhshset->setDropOption(edropOption);
			tk_intfmhshset->setOdbcAttributes(builder->getOdbcAttributes());
			tk_intfmhshset->process(1);
// send the Update
			nt.run();
			nRtd.run();
			QDateTime dateTime2 = QDateTime::currentDateTime();
			qint64 millisecondsDiff = dateTime1.msecsTo(dateTime2);
			qInfo(category) << QString("Processed  %1->rowsProcessed() in %2 seconds").arg(tableName).arg(millisecondsDiff/60);
		} break;
		case Rctables::enumTK_LTDREC:
		{
			QLoggingCategory category("classLibQ");
			QDateTime dateTime1 = QDateTime::currentDateTime();
			QScopedPointer<connectionStringBuilder> builder(new connectionStringBuilder(this));
			vcNvTransfers nt;
			clsRowsToDeleteCleanup nRtd;
			nt.setSourceDSN(sourceDSN);
			nt.setTableName("TK_LTDREC");
			nt.setProfileName("TRKDB100");
			nt.UpdateNvTransfersFromLastAttempted();
			nt.setAutoDelete(true);
			nRtd.initialize(builder->getEnvyConnectionString(),builder->getOdbcAttributes(),tableName,profileName,sourceDSN,targetDSN);
			nRtd.deleteRtdFromTarget();
			QScopedPointer<TK_LTDREC> tk_ltdrec(new TK_LTDREC());
			tk_ltdrec->open(sourceDSN, targetDSN);
			tk_ltdrec->setRepositoryString(builder->getEnvyConnectionString());
			tk_ltdrec->setProfileName(profileName);
			tk_ltdrec->setReplicationOption(eReplicationOption);
			tk_ltdrec->setDropOption(edropOption);
			tk_ltdrec->setOdbcAttributes(builder->getOdbcAttributes());
			tk_ltdrec->process(1);
// send the Update
			nt.run();
			nRtd.run();
			QDateTime dateTime2 = QDateTime::currentDateTime();
			qint64 millisecondsDiff = dateTime1.msecsTo(dateTime2);
			qInfo(category) << QString("Processed  %1->rowsProcessed() in %2 seconds").arg(tableName).arg(millisecondsDiff/60);
		} break;
		case Rctables::enumTK_HDRHSHSET:
		{
			QLoggingCategory category("classLibQ");
			QDateTime dateTime1 = QDateTime::currentDateTime();
			QScopedPointer<connectionStringBuilder> builder(new connectionStringBuilder(this));
			vcNvTransfers nt;
			clsRowsToDeleteCleanup nRtd;
			nt.setSourceDSN(sourceDSN);
			nt.setTableName("TK_HDRHSHSET");
			nt.setProfileName("TRKDB100");
			nt.UpdateNvTransfersFromLastAttempted();
			nt.setAutoDelete(true);
			nRtd.initialize(builder->getEnvyConnectionString(),builder->getOdbcAttributes(),tableName,profileName,sourceDSN,targetDSN);
			nRtd.deleteRtdFromTarget();
			QScopedPointer<TK_HDRHSHSET> tk_hdrhshset(new TK_HDRHSHSET());
			tk_hdrhshset->open(sourceDSN, targetDSN);
			tk_hdrhshset->setRepositoryString(builder->getEnvyConnectionString());
			tk_hdrhshset->setProfileName(profileName);
			tk_hdrhshset->setReplicationOption(eReplicationOption);
			tk_hdrhshset->setDropOption(edropOption);
			tk_hdrhshset->setOdbcAttributes(builder->getOdbcAttributes());
			tk_hdrhshset->process(1);
// send the Update
			nt.run();
			nRtd.run();
			QDateTime dateTime2 = QDateTime::currentDateTime();
			qint64 millisecondsDiff = dateTime1.msecsTo(dateTime2);
			qInfo(category) << QString("Processed  %1->rowsProcessed() in %2 seconds").arg(tableName).arg(millisecondsDiff/60);
		} break;
		case Rctables::enumTK_HDRLTPSET:
		{
			QLoggingCategory category("classLibQ");
			QDateTime dateTime1 = QDateTime::currentDateTime();
			QScopedPointer<connectionStringBuilder> builder(new connectionStringBuilder(this));
			vcNvTransfers nt;
			clsRowsToDeleteCleanup nRtd;
			nt.setSourceDSN(sourceDSN);
			nt.setTableName("TK_HDRLTPSET");
			nt.setProfileName("TRKDB100");
			nt.UpdateNvTransfersFromLastAttempted();
			nt.setAutoDelete(true);
			nRtd.initialize(builder->getEnvyConnectionString(),builder->getOdbcAttributes(),tableName,profileName,sourceDSN,targetDSN);
			nRtd.deleteRtdFromTarget();
			QScopedPointer<TK_HDRLTPSET> tk_hdrltpset(new TK_HDRLTPSET());
			tk_hdrltpset->open(sourceDSN, targetDSN);
			tk_hdrltpset->setRepositoryString(builder->getEnvyConnectionString());
			tk_hdrltpset->setProfileName(profileName);
			tk_hdrltpset->setReplicationOption(eReplicationOption);
			tk_hdrltpset->setDropOption(edropOption);
			tk_hdrltpset->setOdbcAttributes(builder->getOdbcAttributes());
			tk_hdrltpset->process(1);
// send the Update
			nt.run();
			nRtd.run();
			QDateTime dateTime2 = QDateTime::currentDateTime();
			qint64 millisecondsDiff = dateTime1.msecsTo(dateTime2);
			qInfo(category) << QString("Processed  %1->rowsProcessed() in %2 seconds").arg(tableName).arg(millisecondsDiff/60);
		} break;
		case Rctables::enumTK_CNVHSHSET:
		{
			QLoggingCategory category("classLibQ");
			QDateTime dateTime1 = QDateTime::currentDateTime();
			QScopedPointer<connectionStringBuilder> builder(new connectionStringBuilder(this));
			vcNvTransfers nt;
			clsRowsToDeleteCleanup nRtd;
			nt.setSourceDSN(sourceDSN);
			nt.setTableName("TK_CNVHSHSET");
			nt.setProfileName("TRKDB100");
			nt.UpdateNvTransfersFromLastAttempted();
			nt.setAutoDelete(true);
			nRtd.initialize(builder->getEnvyConnectionString(),builder->getOdbcAttributes(),tableName,profileName,sourceDSN,targetDSN);
			nRtd.deleteRtdFromTarget();
			QScopedPointer<TK_CNVHSHSET> tk_cnvhshset(new TK_CNVHSHSET());
			tk_cnvhshset->open(sourceDSN, targetDSN);
			tk_cnvhshset->setRepositoryString(builder->getEnvyConnectionString());
			tk_cnvhshset->setProfileName(profileName);
			tk_cnvhshset->setReplicationOption(eReplicationOption);
			tk_cnvhshset->setDropOption(edropOption);
			tk_cnvhshset->setOdbcAttributes(builder->getOdbcAttributes());
			tk_cnvhshset->process(1);
// send the Update
			nt.run();
			nRtd.run();
			QDateTime dateTime2 = QDateTime::currentDateTime();
			qint64 millisecondsDiff = dateTime1.msecsTo(dateTime2);
			qInfo(category) << QString("Processed  %1->rowsProcessed() in %2 seconds").arg(tableName).arg(millisecondsDiff/60);
		} break;
		case Rctables::enumTK_LTPHSHSET:
		{
			QLoggingCategory category("classLibQ");
			QDateTime dateTime1 = QDateTime::currentDateTime();
			QScopedPointer<connectionStringBuilder> builder(new connectionStringBuilder(this));
			vcNvTransfers nt;
			clsRowsToDeleteCleanup nRtd;
			nt.setSourceDSN(sourceDSN);
			nt.setTableName("TK_LTPHSHSET");
			nt.setProfileName("TRKDB100");
			nt.UpdateNvTransfersFromLastAttempted();
			nt.setAutoDelete(true);
			nRtd.initialize(builder->getEnvyConnectionString(),builder->getOdbcAttributes(),tableName,profileName,sourceDSN,targetDSN);
			nRtd.deleteRtdFromTarget();
			QScopedPointer<TK_LTPHSHSET> tk_ltphshset(new TK_LTPHSHSET());
			tk_ltphshset->open(sourceDSN, targetDSN);
			tk_ltphshset->setRepositoryString(builder->getEnvyConnectionString());
			tk_ltphshset->setProfileName(profileName);
			tk_ltphshset->setReplicationOption(eReplicationOption);
			tk_ltphshset->setDropOption(edropOption);
			tk_ltphshset->setOdbcAttributes(builder->getOdbcAttributes());
			tk_ltphshset->process(1);
// send the Update
			nt.run();
			nRtd.run();
			QDateTime dateTime2 = QDateTime::currentDateTime();
			qint64 millisecondsDiff = dateTime1.msecsTo(dateTime2);
			qInfo(category) << QString("Processed  %1->rowsProcessed() in %2 seconds").arg(tableName).arg(millisecondsDiff/60);
		} break;
		case Rctables::enumTK_INTPOSRTSET:
		{
			QLoggingCategory category("classLibQ");
			QDateTime dateTime1 = QDateTime::currentDateTime();
			QScopedPointer<connectionStringBuilder> builder(new connectionStringBuilder(this));
			vcNvTransfers nt;
			clsRowsToDeleteCleanup nRtd;
			nt.setSourceDSN(sourceDSN);
			nt.setTableName("TK_INTPOSRTSET");
			nt.setProfileName("TRKDB100");
			nt.UpdateNvTransfersFromLastAttempted();
			nt.setAutoDelete(true);
			nRtd.initialize(builder->getEnvyConnectionString(),builder->getOdbcAttributes(),tableName,profileName,sourceDSN,targetDSN);
			nRtd.deleteRtdFromTarget();
			QScopedPointer<TK_INTPOSRTSET> tk_intposrtset(new TK_INTPOSRTSET());
			tk_intposrtset->open(sourceDSN, targetDSN);
			tk_intposrtset->setRepositoryString(builder->getEnvyConnectionString());
			tk_intposrtset->setProfileName(profileName);
			tk_intposrtset->setReplicationOption(eReplicationOption);
			tk_intposrtset->setDropOption(edropOption);
			tk_intposrtset->setOdbcAttributes(builder->getOdbcAttributes());
			tk_intposrtset->process(1);
// send the Update
			nt.run();
			nRtd.run();
			QDateTime dateTime2 = QDateTime::currentDateTime();
			qint64 millisecondsDiff = dateTime1.msecsTo(dateTime2);
			qInfo(category) << QString("Processed  %1->rowsProcessed() in %2 seconds").arg(tableName).arg(millisecondsDiff/60);
		} break;
		case Rctables::enumTK_UPRTHSHSET:
		{
			QLoggingCategory category("classLibQ");
			QDateTime dateTime1 = QDateTime::currentDateTime();
			QScopedPointer<connectionStringBuilder> builder(new connectionStringBuilder(this));
			vcNvTransfers nt;
			clsRowsToDeleteCleanup nRtd;
			nt.setSourceDSN(sourceDSN);
			nt.setTableName("TK_UPRTHSHSET");
			nt.setProfileName("TRKDB100");
			nt.UpdateNvTransfersFromLastAttempted();
			nt.setAutoDelete(true);
			nRtd.initialize(builder->getEnvyConnectionString(),builder->getOdbcAttributes(),tableName,profileName,sourceDSN,targetDSN);
			nRtd.deleteRtdFromTarget();
			QScopedPointer<TK_UPRTHSHSET> tk_uprthshset(new TK_UPRTHSHSET());
			tk_uprthshset->open(sourceDSN, targetDSN);
			tk_uprthshset->setRepositoryString(builder->getEnvyConnectionString());
			tk_uprthshset->setProfileName(profileName);
			tk_uprthshset->setReplicationOption(eReplicationOption);
			tk_uprthshset->setDropOption(edropOption);
			tk_uprthshset->setOdbcAttributes(builder->getOdbcAttributes());
			tk_uprthshset->process(1);
// send the Update
			nt.run();
			nRtd.run();
			QDateTime dateTime2 = QDateTime::currentDateTime();
			qint64 millisecondsDiff = dateTime1.msecsTo(dateTime2);
			qInfo(category) << QString("Processed  %1->rowsProcessed() in %2 seconds").arg(tableName).arg(millisecondsDiff/60);
		} break;
		case Rctables::enumTK_LIDNOTSET:
		{
			QLoggingCategory category("classLibQ");
			QDateTime dateTime1 = QDateTime::currentDateTime();
			QScopedPointer<connectionStringBuilder> builder(new connectionStringBuilder(this));
			vcNvTransfers nt;
			clsRowsToDeleteCleanup nRtd;
			nt.setSourceDSN(sourceDSN);
			nt.setTableName("TK_LIDNOTSET");
			nt.setProfileName("TRKDB100");
			nt.UpdateNvTransfersFromLastAttempted();
			nt.setAutoDelete(true);
			nRtd.initialize(builder->getEnvyConnectionString(),builder->getOdbcAttributes(),tableName,profileName,sourceDSN,targetDSN);
			nRtd.deleteRtdFromTarget();
			QScopedPointer<TK_LIDNOTSET> tk_lidnotset(new TK_LIDNOTSET());
			tk_lidnotset->open(sourceDSN, targetDSN);
			tk_lidnotset->setRepositoryString(builder->getEnvyConnectionString());
			tk_lidnotset->setProfileName(profileName);
			tk_lidnotset->setReplicationOption(eReplicationOption);
			tk_lidnotset->setDropOption(edropOption);
			tk_lidnotset->setOdbcAttributes(builder->getOdbcAttributes());
			tk_lidnotset->process(1);
// send the Update
			nt.run();
			nRtd.run();
			QDateTime dateTime2 = QDateTime::currentDateTime();
			qint64 millisecondsDiff = dateTime1.msecsTo(dateTime2);
			qInfo(category) << QString("Processed  %1->rowsProcessed() in %2 seconds").arg(tableName).arg(millisecondsDiff/60);
		} break;
		case Rctables::enumTK_INTTOHSHSET:
		{
			QLoggingCategory category("classLibQ");
			QDateTime dateTime1 = QDateTime::currentDateTime();
			QScopedPointer<connectionStringBuilder> builder(new connectionStringBuilder(this));
			vcNvTransfers nt;
			clsRowsToDeleteCleanup nRtd;
			nt.setSourceDSN(sourceDSN);
			nt.setTableName("TK_INTTOHSHSET");
			nt.setProfileName("TRKDB100");
			nt.UpdateNvTransfersFromLastAttempted();
			nt.setAutoDelete(true);
			nRtd.initialize(builder->getEnvyConnectionString(),builder->getOdbcAttributes(),tableName,profileName,sourceDSN,targetDSN);
			nRtd.deleteRtdFromTarget();
			QScopedPointer<TK_INTTOHSHSET> tk_inttohshset(new TK_INTTOHSHSET());
			tk_inttohshset->open(sourceDSN, targetDSN);
			tk_inttohshset->setRepositoryString(builder->getEnvyConnectionString());
			tk_inttohshset->setProfileName(profileName);
			tk_inttohshset->setReplicationOption(eReplicationOption);
			tk_inttohshset->setDropOption(edropOption);
			tk_inttohshset->setOdbcAttributes(builder->getOdbcAttributes());
			tk_inttohshset->process(1);
// send the Update
			nt.run();
			nRtd.run();
			QDateTime dateTime2 = QDateTime::currentDateTime();
			qint64 millisecondsDiff = dateTime1.msecsTo(dateTime2);
			qInfo(category) << QString("Processed  %1->rowsProcessed() in %2 seconds").arg(tableName).arg(millisecondsDiff/60);
		} break;
		case Rctables::enumTK_FLGHSHSET:
		{
			QLoggingCategory category("classLibQ");
			QDateTime dateTime1 = QDateTime::currentDateTime();
			QScopedPointer<connectionStringBuilder> builder(new connectionStringBuilder(this));
			vcNvTransfers nt;
			clsRowsToDeleteCleanup nRtd;
			nt.setSourceDSN(sourceDSN);
			nt.setTableName("TK_FLGHSHSET");
			nt.setProfileName("TRKDB100");
			nt.UpdateNvTransfersFromLastAttempted();
			nt.setAutoDelete(true);
			nRtd.initialize(builder->getEnvyConnectionString(),builder->getOdbcAttributes(),tableName,profileName,sourceDSN,targetDSN);
			nRtd.deleteRtdFromTarget();
			QScopedPointer<TK_FLGHSHSET> tk_flghshset(new TK_FLGHSHSET());
			tk_flghshset->open(sourceDSN, targetDSN);
			tk_flghshset->setRepositoryString(builder->getEnvyConnectionString());
			tk_flghshset->setProfileName(profileName);
			tk_flghshset->setReplicationOption(eReplicationOption);
			tk_flghshset->setDropOption(edropOption);
			tk_flghshset->setOdbcAttributes(builder->getOdbcAttributes());
			tk_flghshset->process(1);
// send the Update
			nt.run();
			nRtd.run();
			QDateTime dateTime2 = QDateTime::currentDateTime();
			qint64 millisecondsDiff = dateTime1.msecsTo(dateTime2);
			qInfo(category) << QString("Processed  %1->rowsProcessed() in %2 seconds").arg(tableName).arg(millisecondsDiff/60);
		} break;
		case Rctables::enumTK_INTCHNSET:
		{
			QLoggingCategory category("classLibQ");
			QDateTime dateTime1 = QDateTime::currentDateTime();
			QScopedPointer<connectionStringBuilder> builder(new connectionStringBuilder(this));
			vcNvTransfers nt;
			clsRowsToDeleteCleanup nRtd;
			nt.setSourceDSN(sourceDSN);
			nt.setTableName("TK_INTCHNSET");
			nt.setProfileName("TRKDB100");
			nt.UpdateNvTransfersFromLastAttempted();
			nt.setAutoDelete(true);
			nRtd.initialize(builder->getEnvyConnectionString(),builder->getOdbcAttributes(),tableName,profileName,sourceDSN,targetDSN);
			nRtd.deleteRtdFromTarget();
			QScopedPointer<TK_INTCHNSET> tk_intchnset(new TK_INTCHNSET());
			tk_intchnset->open(sourceDSN, targetDSN);
			tk_intchnset->setRepositoryString(builder->getEnvyConnectionString());
			tk_intchnset->setProfileName(profileName);
			tk_intchnset->setReplicationOption(eReplicationOption);
			tk_intchnset->setDropOption(edropOption);
			tk_intchnset->setOdbcAttributes(builder->getOdbcAttributes());
			tk_intchnset->process(1);
// send the Update
			nt.run();
			nRtd.run();
			QDateTime dateTime2 = QDateTime::currentDateTime();
			qint64 millisecondsDiff = dateTime1.msecsTo(dateTime2);
			qInfo(category) << QString("Processed  %1->rowsProcessed() in %2 seconds").arg(tableName).arg(millisecondsDiff/60);
		} break;
		case Rctables::enumTK_LOTREC:
		{
			QLoggingCategory category("classLibQ");
			QDateTime dateTime1 = QDateTime::currentDateTime();
			QScopedPointer<connectionStringBuilder> builder(new connectionStringBuilder(this));
			vcNvTransfers nt;
			clsRowsToDeleteCleanup nRtd;
			nt.setSourceDSN(sourceDSN);
			nt.setTableName("TK_LOTREC");
			nt.setProfileName("TRKDB100");
			nt.UpdateNvTransfersFromLastAttempted();
			nt.setAutoDelete(true);
			nRtd.initialize(builder->getEnvyConnectionString(),builder->getOdbcAttributes(),tableName,profileName,sourceDSN,targetDSN);
			nRtd.deleteRtdFromTarget();
			QScopedPointer<TK_LOTREC> tk_lotrec(new TK_LOTREC());
			tk_lotrec->open(sourceDSN, targetDSN);
			tk_lotrec->setRepositoryString(builder->getEnvyConnectionString());
			tk_lotrec->setProfileName(profileName);
			tk_lotrec->setReplicationOption(eReplicationOption);
			tk_lotrec->setDropOption(edropOption);
			tk_lotrec->setOdbcAttributes(builder->getOdbcAttributes());
			tk_lotrec->process(1);
// send the Update
			nt.run();
			nRtd.run();
			QDateTime dateTime2 = QDateTime::currentDateTime();
			qint64 millisecondsDiff = dateTime1.msecsTo(dateTime2);
			qInfo(category) << QString("Processed  %1->rowsProcessed() in %2 seconds").arg(tableName).arg(millisecondsDiff/60);
		} break;
		case Rctables::enumTK_TYPHDRSET:
		{
			QLoggingCategory category("classLibQ");
			QDateTime dateTime1 = QDateTime::currentDateTime();
			QScopedPointer<connectionStringBuilder> builder(new connectionStringBuilder(this));
			vcNvTransfers nt;
			clsRowsToDeleteCleanup nRtd;
			nt.setSourceDSN(sourceDSN);
			nt.setTableName("TK_TYPHDRSET");
			nt.setProfileName("TRKDB100");
			nt.UpdateNvTransfersFromLastAttempted();
			nt.setAutoDelete(true);
			nRtd.initialize(builder->getEnvyConnectionString(),builder->getOdbcAttributes(),tableName,profileName,sourceDSN,targetDSN);
			nRtd.deleteRtdFromTarget();
			QScopedPointer<TK_TYPHDRSET> tk_typhdrset(new TK_TYPHDRSET());
			tk_typhdrset->open(sourceDSN, targetDSN);
			tk_typhdrset->setRepositoryString(builder->getEnvyConnectionString());
			tk_typhdrset->setProfileName(profileName);
			tk_typhdrset->setReplicationOption(eReplicationOption);
			tk_typhdrset->setDropOption(edropOption);
			tk_typhdrset->setOdbcAttributes(builder->getOdbcAttributes());
			tk_typhdrset->process(1);
// send the Update
			nt.run();
			nRtd.run();
			QDateTime dateTime2 = QDateTime::currentDateTime();
			qint64 millisecondsDiff = dateTime1.msecsTo(dateTime2);
			qInfo(category) << QString("Processed  %1->rowsProcessed() in %2 seconds").arg(tableName).arg(millisecondsDiff/60);
		} break;
		case Rctables::enumTK_PRCREC:
		{
			QLoggingCategory category("classLibQ");
			QDateTime dateTime1 = QDateTime::currentDateTime();
			QScopedPointer<connectionStringBuilder> builder(new connectionStringBuilder(this));
			vcNvTransfers nt;
			clsRowsToDeleteCleanup nRtd;
			nt.setSourceDSN(sourceDSN);
			nt.setTableName("TK_PRCREC");
			nt.setProfileName("TRKDB100");
			nt.UpdateNvTransfersFromLastAttempted();
			nt.setAutoDelete(true);
			nRtd.initialize(builder->getEnvyConnectionString(),builder->getOdbcAttributes(),tableName,profileName,sourceDSN,targetDSN);
			nRtd.deleteRtdFromTarget();
			QScopedPointer<TK_PRCREC> tk_prcrec(new TK_PRCREC());
			tk_prcrec->open(sourceDSN, targetDSN);
			tk_prcrec->setRepositoryString(builder->getEnvyConnectionString());
			tk_prcrec->setProfileName(profileName);
			tk_prcrec->setReplicationOption(eReplicationOption);
			tk_prcrec->setDropOption(edropOption);
			tk_prcrec->setOdbcAttributes(builder->getOdbcAttributes());
			tk_prcrec->process(1);
// send the Update
			nt.run();
			nRtd.run();
			QDateTime dateTime2 = QDateTime::currentDateTime();
			qint64 millisecondsDiff = dateTime1.msecsTo(dateTime2);
			qInfo(category) << QString("Processed  %1->rowsProcessed() in %2 seconds").arg(tableName).arg(millisecondsDiff/60);
		} break;
		case Rctables::enumTK_LOTHSHSET:
		{
			QLoggingCategory category("classLibQ");
			QDateTime dateTime1 = QDateTime::currentDateTime();
			QScopedPointer<connectionStringBuilder> builder(new connectionStringBuilder(this));
			vcNvTransfers nt;
			clsRowsToDeleteCleanup nRtd;
			nt.setSourceDSN(sourceDSN);
			nt.setTableName("TK_LOTHSHSET");
			nt.setProfileName("TRKDB100");
			nt.UpdateNvTransfersFromLastAttempted();
			nt.setAutoDelete(true);
			nRtd.initialize(builder->getEnvyConnectionString(),builder->getOdbcAttributes(),tableName,profileName,sourceDSN,targetDSN);
			nRtd.deleteRtdFromTarget();
			QScopedPointer<TK_LOTHSHSET> tk_lothshset(new TK_LOTHSHSET());
			tk_lothshset->open(sourceDSN, targetDSN);
			tk_lothshset->setRepositoryString(builder->getEnvyConnectionString());
			tk_lothshset->setProfileName(profileName);
			tk_lothshset->setReplicationOption(eReplicationOption);
			tk_lothshset->setDropOption(edropOption);
			tk_lothshset->setOdbcAttributes(builder->getOdbcAttributes());
			tk_lothshset->process(1);
// send the Update
			nt.run();
			nRtd.run();
			QDateTime dateTime2 = QDateTime::currentDateTime();
			qint64 millisecondsDiff = dateTime1.msecsTo(dateTime2);
			qInfo(category) << QString("Processed  %1->rowsProcessed() in %2 seconds").arg(tableName).arg(millisecondsDiff/60);
		} break;
		case Rctables::enumTK_PRTLTFSET:
		{
			QLoggingCategory category("classLibQ");
			QDateTime dateTime1 = QDateTime::currentDateTime();
			QScopedPointer<connectionStringBuilder> builder(new connectionStringBuilder(this));
			vcNvTransfers nt;
			clsRowsToDeleteCleanup nRtd;
			nt.setSourceDSN(sourceDSN);
			nt.setTableName("TK_PRTLTFSET");
			nt.setProfileName("TRKDB100");
			nt.UpdateNvTransfersFromLastAttempted();
			nt.setAutoDelete(true);
			nRtd.initialize(builder->getEnvyConnectionString(),builder->getOdbcAttributes(),tableName,profileName,sourceDSN,targetDSN);
			nRtd.deleteRtdFromTarget();
			QScopedPointer<TK_PRTLTFSET> tk_prtltfset(new TK_PRTLTFSET());
			tk_prtltfset->open(sourceDSN, targetDSN);
			tk_prtltfset->setRepositoryString(builder->getEnvyConnectionString());
			tk_prtltfset->setProfileName(profileName);
			tk_prtltfset->setReplicationOption(eReplicationOption);
			tk_prtltfset->setDropOption(edropOption);
			tk_prtltfset->setOdbcAttributes(builder->getOdbcAttributes());
			tk_prtltfset->process(1);
// send the Update
			nt.run();
			nRtd.run();
			QDateTime dateTime2 = QDateTime::currentDateTime();
			qint64 millisecondsDiff = dateTime1.msecsTo(dateTime2);
			qInfo(category) << QString("Processed  %1->rowsProcessed() in %2 seconds").arg(tableName).arg(millisecondsDiff/60);
		} break;
		case Rctables::enumTK_PRTREC:
		{
			QLoggingCategory category("classLibQ");
			QDateTime dateTime1 = QDateTime::currentDateTime();
			QScopedPointer<connectionStringBuilder> builder(new connectionStringBuilder(this));
			vcNvTransfers nt;
			clsRowsToDeleteCleanup nRtd;
			nt.setSourceDSN(sourceDSN);
			nt.setTableName("TK_PRTREC");
			nt.setProfileName("TRKDB100");
			nt.UpdateNvTransfersFromLastAttempted();
			nt.setAutoDelete(true);
			nRtd.initialize(builder->getEnvyConnectionString(),builder->getOdbcAttributes(),tableName,profileName,sourceDSN,targetDSN);
			nRtd.deleteRtdFromTarget();
			QScopedPointer<TK_PRTREC> tk_prtrec(new TK_PRTREC());
			tk_prtrec->open(sourceDSN, targetDSN);
			tk_prtrec->setRepositoryString(builder->getEnvyConnectionString());
			tk_prtrec->setProfileName(profileName);
			tk_prtrec->setReplicationOption(eReplicationOption);
			tk_prtrec->setDropOption(edropOption);
			tk_prtrec->setOdbcAttributes(builder->getOdbcAttributes());
			tk_prtrec->process(1);
// send the Update
			nt.run();
			nRtd.run();
			QDateTime dateTime2 = QDateTime::currentDateTime();
			qint64 millisecondsDiff = dateTime1.msecsTo(dateTime2);
			qInfo(category) << QString("Processed  %1->rowsProcessed() in %2 seconds").arg(tableName).arg(millisecondsDiff/60);
		} break;
		case Rctables::enumTK_UHSTCHNSET:
		{
			QLoggingCategory category("classLibQ");
			QDateTime dateTime1 = QDateTime::currentDateTime();
			QScopedPointer<connectionStringBuilder> builder(new connectionStringBuilder(this));
			vcNvTransfers nt;
			clsRowsToDeleteCleanup nRtd;
			nt.setSourceDSN(sourceDSN);
			nt.setTableName("TK_UHSTCHNSET");
			nt.setProfileName("TRKDB100");
			nt.UpdateNvTransfersFromLastAttempted();
			nt.setAutoDelete(true);
			nRtd.initialize(builder->getEnvyConnectionString(),builder->getOdbcAttributes(),tableName,profileName,sourceDSN,targetDSN);
			nRtd.deleteRtdFromTarget();
			QScopedPointer<TK_UHSTCHNSET> tk_uhstchnset(new TK_UHSTCHNSET());
			tk_uhstchnset->open(sourceDSN, targetDSN);
			tk_uhstchnset->setRepositoryString(builder->getEnvyConnectionString());
			tk_uhstchnset->setProfileName(profileName);
			tk_uhstchnset->setReplicationOption(eReplicationOption);
			tk_uhstchnset->setDropOption(edropOption);
			tk_uhstchnset->setOdbcAttributes(builder->getOdbcAttributes());
			tk_uhstchnset->process(1);
// send the Update
			nt.run();
			nRtd.run();
			QDateTime dateTime2 = QDateTime::currentDateTime();
			qint64 millisecondsDiff = dateTime1.msecsTo(dateTime2);
			qInfo(category) << QString("Processed  %1->rowsProcessed() in %2 seconds").arg(tableName).arg(millisecondsDiff/60);
		} break;
		case Rctables::enumTK_LOTLIDSET:
		{
			QLoggingCategory category("classLibQ");
			QDateTime dateTime1 = QDateTime::currentDateTime();
			QScopedPointer<connectionStringBuilder> builder(new connectionStringBuilder(this));
			vcNvTransfers nt;
			clsRowsToDeleteCleanup nRtd;
			nt.setSourceDSN(sourceDSN);
			nt.setTableName("TK_LOTLIDSET");
			nt.setProfileName("TRKDB100");
			nt.UpdateNvTransfersFromLastAttempted();
			nt.setAutoDelete(true);
			nRtd.initialize(builder->getEnvyConnectionString(),builder->getOdbcAttributes(),tableName,profileName,sourceDSN,targetDSN);
			nRtd.deleteRtdFromTarget();
			QScopedPointer<TK_LOTLIDSET> tk_lotlidset(new TK_LOTLIDSET());
			tk_lotlidset->open(sourceDSN, targetDSN);
			tk_lotlidset->setRepositoryString(builder->getEnvyConnectionString());
			tk_lotlidset->setProfileName(profileName);
			tk_lotlidset->setReplicationOption(eReplicationOption);
			tk_lotlidset->setDropOption(edropOption);
			tk_lotlidset->setOdbcAttributes(builder->getOdbcAttributes());
			tk_lotlidset->process(1);
// send the Update
			nt.run();
			nRtd.run();
			QDateTime dateTime2 = QDateTime::currentDateTime();
			qint64 millisecondsDiff = dateTime1.msecsTo(dateTime2);
			qInfo(category) << QString("Processed  %1->rowsProcessed() in %2 seconds").arg(tableName).arg(millisecondsDiff/60);
		} break;
		case Rctables::enumTK_LTPREC:
		{
			QLoggingCategory category("classLibQ");
			QDateTime dateTime1 = QDateTime::currentDateTime();
			QScopedPointer<connectionStringBuilder> builder(new connectionStringBuilder(this));
			vcNvTransfers nt;
			clsRowsToDeleteCleanup nRtd;
			nt.setSourceDSN(sourceDSN);
			nt.setTableName("TK_LTPREC");
			nt.setProfileName("TRKDB100");
			nt.UpdateNvTransfersFromLastAttempted();
			nt.setAutoDelete(true);
			nRtd.initialize(builder->getEnvyConnectionString(),builder->getOdbcAttributes(),tableName,profileName,sourceDSN,targetDSN);
			nRtd.deleteRtdFromTarget();
			QScopedPointer<TK_LTPREC> tk_ltprec(new TK_LTPREC());
			tk_ltprec->open(sourceDSN, targetDSN);
			tk_ltprec->setRepositoryString(builder->getEnvyConnectionString());
			tk_ltprec->setProfileName(profileName);
			tk_ltprec->setReplicationOption(eReplicationOption);
			tk_ltprec->setDropOption(edropOption);
			tk_ltprec->setOdbcAttributes(builder->getOdbcAttributes());
			tk_ltprec->process(1);
// send the Update
			nt.run();
			nRtd.run();
			QDateTime dateTime2 = QDateTime::currentDateTime();
			qint64 millisecondsDiff = dateTime1.msecsTo(dateTime2);
			qInfo(category) << QString("Processed  %1->rowsProcessed() in %2 seconds").arg(tableName).arg(millisecondsDiff/60);
		} break;
		case Rctables::enumTK_TYPREC:
		{
			QLoggingCategory category("classLibQ");
			QDateTime dateTime1 = QDateTime::currentDateTime();
			QScopedPointer<connectionStringBuilder> builder(new connectionStringBuilder(this));
			vcNvTransfers nt;
			clsRowsToDeleteCleanup nRtd;
			nt.setSourceDSN(sourceDSN);
			nt.setTableName("TK_TYPREC");
			nt.setProfileName("TRKDB100");
			nt.UpdateNvTransfersFromLastAttempted();
			nt.setAutoDelete(true);
			nRtd.initialize(builder->getEnvyConnectionString(),builder->getOdbcAttributes(),tableName,profileName,sourceDSN,targetDSN);
			nRtd.deleteRtdFromTarget();
			QScopedPointer<TK_TYPREC> tk_typrec(new TK_TYPREC());
			tk_typrec->open(sourceDSN, targetDSN);
			tk_typrec->setRepositoryString(builder->getEnvyConnectionString());
			tk_typrec->setProfileName(profileName);
			tk_typrec->setReplicationOption(eReplicationOption);
			tk_typrec->setDropOption(edropOption);
			tk_typrec->setOdbcAttributes(builder->getOdbcAttributes());
			tk_typrec->process(1);
// send the Update
			nt.run();
			nRtd.run();
			QDateTime dateTime2 = QDateTime::currentDateTime();
			qint64 millisecondsDiff = dateTime1.msecsTo(dateTime2);
			qInfo(category) << QString("Processed  %1->rowsProcessed() in %2 seconds").arg(tableName).arg(millisecondsDiff/60);
		} break;
		case Rctables::enumTK_ULSTREC:
		{
			QLoggingCategory category("classLibQ");
			QDateTime dateTime1 = QDateTime::currentDateTime();
			QScopedPointer<connectionStringBuilder> builder(new connectionStringBuilder(this));
			vcNvTransfers nt;
			clsRowsToDeleteCleanup nRtd;
			nt.setSourceDSN(sourceDSN);
			nt.setTableName("TK_ULSTREC");
			nt.setProfileName("TRKDB100");
			nt.UpdateNvTransfersFromLastAttempted();
			nt.setAutoDelete(true);
			nRtd.initialize(builder->getEnvyConnectionString(),builder->getOdbcAttributes(),tableName,profileName,sourceDSN,targetDSN);
			nRtd.deleteRtdFromTarget();
			QScopedPointer<TK_ULSTREC> tk_ulstrec(new TK_ULSTREC());
			tk_ulstrec->open(sourceDSN, targetDSN);
			tk_ulstrec->setRepositoryString(builder->getEnvyConnectionString());
			tk_ulstrec->setProfileName(profileName);
			tk_ulstrec->setReplicationOption(eReplicationOption);
			tk_ulstrec->setDropOption(edropOption);
			tk_ulstrec->setOdbcAttributes(builder->getOdbcAttributes());
			tk_ulstrec->process(1);
// send the Update
			nt.run();
			nRtd.run();
			QDateTime dateTime2 = QDateTime::currentDateTime();
			qint64 millisecondsDiff = dateTime1.msecsTo(dateTime2);
			qInfo(category) << QString("Processed  %1->rowsProcessed() in %2 seconds").arg(tableName).arg(millisecondsDiff/60);
		} break;
	}
}
#pragma endregion
