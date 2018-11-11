/*H**********************************************************************
* FILENAME :        Launcher_MANDB100.h             DESIGN REF: 
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

#pragma once
#ifndef LAUNCHQRC_MANDB100_H
#define LAUNCHQRC_MANDB100_H
#include <QObject>
#include <QRunnable>
#include "qnvstaticclass.h"
#include "NvLib_Enumerations.h"
#include "schemafield.h"

class launchQRC_MANDB100 : public QObject, public QRunnable {
	Q_OBJECT

public:
	launchQRC_MANDB100(QObject * parent = Q_NULLPTR);
	~launchQRC_MANDB100();
	void initialize(const QString profileName, const QString tableName, const QString sourceDSN, const QString targetDSN, DropOption dropOption, ReplicationOption replicationOption);
	void process();
	void setDropOption(DropOption dropOption) { edropOption = dropOption; }
	void setReplicationOption(ReplicationOption replicationOption) { eReplicationOption = replicationOption; }
	void setTablesList(QStringList tables) { tables.append(tables); }
	void setRepositoryDSN(const QString envyDSN) { envyRepositoryString = envyDSN; }
	void setOdbcAttributes(const QString odbcAttr) { odbcAttributes = odbcAttr; }
	void setCommitInterval(int uCommitInterval) { commitInterval = uCommitInterval; }
	void setUpdateInterval(int uUpdateInterval) { updateInterval = uUpdateInterval; }
	void run() { process(); }
private:
	int commitInterval;
	int updateInterval;
	QString tableName;
	QString profileName;
	QString sourceDSN;
	QString targetDSN;
	int maxThreadCount;
	int commitThrottle;
	QString odbcAttributes;
	QString envyRepositoryString;
	DropOption edropOption;
	ReplicationOption eReplicationOption;
	QStringList  tables;
	QHash<QString, schemaField*> m_HashedMap_MANDB100;
	QThreadPool * workerPool;
#include "tableEnumerations_MANDB100.h" 

};
#endif LAUNCHQRC_MANDB100_H
