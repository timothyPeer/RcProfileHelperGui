/*H**********************************************************************
* FILENAME :        CaseList_PRCDB100.h             DESIGN REF: 
*
* DESCRIPTION :
*       This file contains a case branch for each record that can be processed in the PRCDB Manman V11
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

#ifndef caseList__h_PRCDB100
#define caseList__h_PRCDB100

#pragma region caselist for PRCDB100

	switch (ffx)
	{
		case Rctables::enumPC_IDESREC:
		{
			QScopedPointer<PC_IDESREC> pc_idesrec(new PC_IDESREC(nullptr));
			pc_idesrec->open(sourceDSN, targetDSN);
			pc_idesrec->setRepositoryString(envyRepositoryString);
			pc_idesrec->setProfileName(profileName);
			pc_idesrec->setReplicationOption(eReplicationOption);
			pc_idesrec->setDropOption(edropOption);
			pc_idesrec->setOdbcAttributes(odbcAttributes);
			pc_idesrec->setUpdateInterval(updateInterval);
			pc_idesrec->setCommitInterval(commitInterval);
			pc_idesrec->process(1);
		} break;
		case Rctables::enumPC_FRMINGSET:
		{
			QScopedPointer<PC_FRMINGSET> pc_frmingset(new PC_FRMINGSET(nullptr));
			pc_frmingset->open(sourceDSN, targetDSN);
			pc_frmingset->setRepositoryString(envyRepositoryString);
			pc_frmingset->setProfileName(profileName);
			pc_frmingset->setReplicationOption(eReplicationOption);
			pc_frmingset->setDropOption(edropOption);
			pc_frmingset->setOdbcAttributes(odbcAttributes);
			pc_frmingset->setUpdateInterval(updateInterval);
			pc_frmingset->setCommitInterval(commitInterval);
			pc_frmingset->process(1);
		} break;
		case Rctables::enumPC_IXREC:
		{
			QScopedPointer<PC_IXREC> pc_ixrec(new PC_IXREC(nullptr));
			pc_ixrec->open(sourceDSN, targetDSN);
			pc_ixrec->setRepositoryString(envyRepositoryString);
			pc_ixrec->setProfileName(profileName);
			pc_ixrec->setReplicationOption(eReplicationOption);
			pc_ixrec->setDropOption(edropOption);
			pc_ixrec->setOdbcAttributes(odbcAttributes);
			pc_ixrec->setUpdateInterval(updateInterval);
			pc_ixrec->setCommitInterval(commitInterval);
			pc_ixrec->process(1);
		} break;
		case Rctables::enumPC_ENDREC:
		{
			QScopedPointer<PC_ENDREC> pc_endrec(new PC_ENDREC(nullptr));
			pc_endrec->open(sourceDSN, targetDSN);
			pc_endrec->setRepositoryString(envyRepositoryString);
			pc_endrec->setProfileName(profileName);
			pc_endrec->setReplicationOption(eReplicationOption);
			pc_endrec->setDropOption(edropOption);
			pc_endrec->setOdbcAttributes(odbcAttributes);
			pc_endrec->setUpdateInterval(updateInterval);
			pc_endrec->setCommitInterval(commitInterval);
			pc_endrec->process(1);
		} break;
		case Rctables::enumPC_MBOMINGSET:
		{
			QScopedPointer<PC_MBOMINGSET> pc_mbomingset(new PC_MBOMINGSET(nullptr));
			pc_mbomingset->open(sourceDSN, targetDSN);
			pc_mbomingset->setRepositoryString(envyRepositoryString);
			pc_mbomingset->setProfileName(profileName);
			pc_mbomingset->setReplicationOption(eReplicationOption);
			pc_mbomingset->setDropOption(edropOption);
			pc_mbomingset->setOdbcAttributes(odbcAttributes);
			pc_mbomingset->setUpdateInterval(updateInterval);
			pc_mbomingset->setCommitInterval(commitInterval);
			pc_mbomingset->process(1);
		} break;
		case Rctables::enumPC_WKCMPISET:
		{
			QScopedPointer<PC_WKCMPISET> pc_wkcmpiset(new PC_WKCMPISET(nullptr));
			pc_wkcmpiset->open(sourceDSN, targetDSN);
			pc_wkcmpiset->setRepositoryString(envyRepositoryString);
			pc_wkcmpiset->setProfileName(profileName);
			pc_wkcmpiset->setReplicationOption(eReplicationOption);
			pc_wkcmpiset->setDropOption(edropOption);
			pc_wkcmpiset->setOdbcAttributes(odbcAttributes);
			pc_wkcmpiset->setUpdateInterval(updateInterval);
			pc_wkcmpiset->setCommitInterval(commitInterval);
			pc_wkcmpiset->process(1);
		} break;
		case Rctables::enumPC_TEXDREC:
		{
			QScopedPointer<PC_TEXDREC> pc_texdrec(new PC_TEXDREC(nullptr));
			pc_texdrec->open(sourceDSN, targetDSN);
			pc_texdrec->setRepositoryString(envyRepositoryString);
			pc_texdrec->setProfileName(profileName);
			pc_texdrec->setReplicationOption(eReplicationOption);
			pc_texdrec->setDropOption(edropOption);
			pc_texdrec->setOdbcAttributes(odbcAttributes);
			pc_texdrec->setUpdateInterval(updateInterval);
			pc_texdrec->setCommitInterval(commitInterval);
			pc_texdrec->process(1);
		} break;
		case Rctables::enumPC_FCODESREC:
		{
			QScopedPointer<PC_FCODESREC> pc_fcodesrec(new PC_FCODESREC(nullptr));
			pc_fcodesrec->open(sourceDSN, targetDSN);
			pc_fcodesrec->setRepositoryString(envyRepositoryString);
			pc_fcodesrec->setProfileName(profileName);
			pc_fcodesrec->setReplicationOption(eReplicationOption);
			pc_fcodesrec->setDropOption(edropOption);
			pc_fcodesrec->setOdbcAttributes(odbcAttributes);
			pc_fcodesrec->setUpdateInterval(updateInterval);
			pc_fcodesrec->setCommitInterval(commitInterval);
			pc_fcodesrec->process(1);
		} break;
		case Rctables::enumPC_PRTENDSET:
		{
			QScopedPointer<PC_PRTENDSET> pc_prtendset(new PC_PRTENDSET(nullptr));
			pc_prtendset->open(sourceDSN, targetDSN);
			pc_prtendset->setRepositoryString(envyRepositoryString);
			pc_prtendset->setProfileName(profileName);
			pc_prtendset->setReplicationOption(eReplicationOption);
			pc_prtendset->setDropOption(edropOption);
			pc_prtendset->setOdbcAttributes(odbcAttributes);
			pc_prtendset->setUpdateInterval(updateInterval);
			pc_prtendset->setCommitInterval(commitInterval);
			pc_prtendset->process(1);
		} break;
		case Rctables::enumPC_FCOHHSHSET:
		{
			QScopedPointer<PC_FCOHHSHSET> pc_fcohhshset(new PC_FCOHHSHSET(nullptr));
			pc_fcohhshset->open(sourceDSN, targetDSN);
			pc_fcohhshset->setRepositoryString(envyRepositoryString);
			pc_fcohhshset->setProfileName(profileName);
			pc_fcohhshset->setReplicationOption(eReplicationOption);
			pc_fcohhshset->setDropOption(edropOption);
			pc_fcohhshset->setOdbcAttributes(odbcAttributes);
			pc_fcohhshset->setUpdateInterval(updateInterval);
			pc_fcohhshset->setCommitInterval(commitInterval);
			pc_fcohhshset->process(1);
		} break;
		case Rctables::enumPC_MPIREC:
		{
			QScopedPointer<PC_MPIREC> pc_mpirec(new PC_MPIREC(nullptr));
			pc_mpirec->open(sourceDSN, targetDSN);
			pc_mpirec->setRepositoryString(envyRepositoryString);
			pc_mpirec->setProfileName(profileName);
			pc_mpirec->setReplicationOption(eReplicationOption);
			pc_mpirec->setDropOption(edropOption);
			pc_mpirec->setOdbcAttributes(odbcAttributes);
			pc_mpirec->setUpdateInterval(updateInterval);
			pc_mpirec->setCommitInterval(commitInterval);
			pc_mpirec->process(1);
		} break;
		case Rctables::enumPC_FRMPVHSHSET:
		{
			QScopedPointer<PC_FRMPVHSHSET> pc_frmpvhshset(new PC_FRMPVHSHSET(nullptr));
			pc_frmpvhshset->open(sourceDSN, targetDSN);
			pc_frmpvhshset->setRepositoryString(envyRepositoryString);
			pc_frmpvhshset->setProfileName(profileName);
			pc_frmpvhshset->setReplicationOption(eReplicationOption);
			pc_frmpvhshset->setDropOption(edropOption);
			pc_frmpvhshset->setOdbcAttributes(odbcAttributes);
			pc_frmpvhshset->setUpdateInterval(updateInterval);
			pc_frmpvhshset->setCommitInterval(commitInterval);
			pc_frmpvhshset->process(1);
		} break;
		case Rctables::enumPC_WKCPISET:
		{
			QScopedPointer<PC_WKCPISET> pc_wkcpiset(new PC_WKCPISET(nullptr));
			pc_wkcpiset->open(sourceDSN, targetDSN);
			pc_wkcpiset->setRepositoryString(envyRepositoryString);
			pc_wkcpiset->setProfileName(profileName);
			pc_wkcpiset->setReplicationOption(eReplicationOption);
			pc_wkcpiset->setDropOption(edropOption);
			pc_wkcpiset->setOdbcAttributes(odbcAttributes);
			pc_wkcpiset->setUpdateInterval(updateInterval);
			pc_wkcpiset->setCommitInterval(commitInterval);
			pc_wkcpiset->process(1);
		} break;
		case Rctables::enumPC_WOHWODSET:
		{
			QScopedPointer<PC_WOHWODSET> pc_wohwodset(new PC_WOHWODSET(nullptr));
			pc_wohwodset->open(sourceDSN, targetDSN);
			pc_wohwodset->setRepositoryString(envyRepositoryString);
			pc_wohwodset->setProfileName(profileName);
			pc_wohwodset->setReplicationOption(eReplicationOption);
			pc_wohwodset->setDropOption(edropOption);
			pc_wohwodset->setOdbcAttributes(odbcAttributes);
			pc_wohwodset->setUpdateInterval(updateInterval);
			pc_wohwodset->setCommitInterval(commitInterval);
			pc_wohwodset->process(1);
		} break;
		case Rctables::enumPC_USRFRMPVSET:
		{
			QScopedPointer<PC_USRFRMPVSET> pc_usrfrmpvset(new PC_USRFRMPVSET(nullptr));
			pc_usrfrmpvset->open(sourceDSN, targetDSN);
			pc_usrfrmpvset->setRepositoryString(envyRepositoryString);
			pc_usrfrmpvset->setProfileName(profileName);
			pc_usrfrmpvset->setReplicationOption(eReplicationOption);
			pc_usrfrmpvset->setDropOption(edropOption);
			pc_usrfrmpvset->setOdbcAttributes(odbcAttributes);
			pc_usrfrmpvset->setUpdateInterval(updateInterval);
			pc_usrfrmpvset->setCommitInterval(commitInterval);
			pc_usrfrmpvset->process(1);
		} break;
		case Rctables::enumPC_FCOHFCODESSET:
		{
			QScopedPointer<PC_FCOHFCODESSET> pc_fcohfcodesset(new PC_FCOHFCODESSET(nullptr));
			pc_fcohfcodesset->open(sourceDSN, targetDSN);
			pc_fcohfcodesset->setRepositoryString(envyRepositoryString);
			pc_fcohfcodesset->setProfileName(profileName);
			pc_fcohfcodesset->setReplicationOption(eReplicationOption);
			pc_fcohfcodesset->setDropOption(edropOption);
			pc_fcohfcodesset->setOdbcAttributes(odbcAttributes);
			pc_fcohfcodesset->setUpdateInterval(updateInterval);
			pc_fcohfcodesset->setCommitInterval(commitInterval);
			pc_fcohfcodesset->process(1);
		} break;
		case Rctables::enumPC_PIPISAFSET:
		{
			QScopedPointer<PC_PIPISAFSET> pc_pipisafset(new PC_PIPISAFSET(nullptr));
			pc_pipisafset->open(sourceDSN, targetDSN);
			pc_pipisafset->setRepositoryString(envyRepositoryString);
			pc_pipisafset->setProfileName(profileName);
			pc_pipisafset->setReplicationOption(eReplicationOption);
			pc_pipisafset->setDropOption(edropOption);
			pc_pipisafset->setOdbcAttributes(odbcAttributes);
			pc_pipisafset->setUpdateInterval(updateInterval);
			pc_pipisafset->setCommitInterval(commitInterval);
			pc_pipisafset->process(1);
		} break;
		case Rctables::enumPC_INGIDESSET:
		{
			QScopedPointer<PC_INGIDESSET> pc_ingidesset(new PC_INGIDESSET(nullptr));
			pc_ingidesset->open(sourceDSN, targetDSN);
			pc_ingidesset->setRepositoryString(envyRepositoryString);
			pc_ingidesset->setProfileName(profileName);
			pc_ingidesset->setReplicationOption(eReplicationOption);
			pc_ingidesset->setDropOption(edropOption);
			pc_ingidesset->setOdbcAttributes(odbcAttributes);
			pc_ingidesset->setUpdateInterval(updateInterval);
			pc_ingidesset->setCommitInterval(commitInterval);
			pc_ingidesset->process(1);
		} break;
		case Rctables::enumPC_ALTHADTSET:
		{
			QScopedPointer<PC_ALTHADTSET> pc_althadtset(new PC_ALTHADTSET(nullptr));
			pc_althadtset->open(sourceDSN, targetDSN);
			pc_althadtset->setRepositoryString(envyRepositoryString);
			pc_althadtset->setProfileName(profileName);
			pc_althadtset->setReplicationOption(eReplicationOption);
			pc_althadtset->setDropOption(edropOption);
			pc_althadtset->setOdbcAttributes(odbcAttributes);
			pc_althadtset->setUpdateInterval(updateInterval);
			pc_althadtset->setCommitInterval(commitInterval);
			pc_althadtset->process(1);
		} break;
		case Rctables::enumPC_TRKNOHSHSET:
		{
			QScopedPointer<PC_TRKNOHSHSET> pc_trknohshset(new PC_TRKNOHSHSET(nullptr));
			pc_trknohshset->open(sourceDSN, targetDSN);
			pc_trknohshset->setRepositoryString(envyRepositoryString);
			pc_trknohshset->setProfileName(profileName);
			pc_trknohshset->setReplicationOption(eReplicationOption);
			pc_trknohshset->setDropOption(edropOption);
			pc_trknohshset->setOdbcAttributes(odbcAttributes);
			pc_trknohshset->setUpdateInterval(updateInterval);
			pc_trknohshset->setCommitInterval(commitInterval);
			pc_trknohshset->process(1);
		} break;
		case Rctables::enumPC_APIHAPITSET:
		{
			QScopedPointer<PC_APIHAPITSET> pc_apihapitset(new PC_APIHAPITSET(nullptr));
			pc_apihapitset->open(sourceDSN, targetDSN);
			pc_apihapitset->setRepositoryString(envyRepositoryString);
			pc_apihapitset->setProfileName(profileName);
			pc_apihapitset->setReplicationOption(eReplicationOption);
			pc_apihapitset->setDropOption(edropOption);
			pc_apihapitset->setOdbcAttributes(odbcAttributes);
			pc_apihapitset->setUpdateInterval(updateInterval);
			pc_apihapitset->setCommitInterval(commitInterval);
			pc_apihapitset->process(1);
		} break;
		case Rctables::enumPC_PRTWODSET:
		{
			QScopedPointer<PC_PRTWODSET> pc_prtwodset(new PC_PRTWODSET(nullptr));
			pc_prtwodset->open(sourceDSN, targetDSN);
			pc_prtwodset->setRepositoryString(envyRepositoryString);
			pc_prtwodset->setProfileName(profileName);
			pc_prtwodset->setReplicationOption(eReplicationOption);
			pc_prtwodset->setDropOption(edropOption);
			pc_prtwodset->setOdbcAttributes(odbcAttributes);
			pc_prtwodset->setUpdateInterval(updateInterval);
			pc_prtwodset->setCommitInterval(commitInterval);
			pc_prtwodset->process(1);
		} break;
		case Rctables::enumPC_CHGHHSHSET:
		{
			QScopedPointer<PC_CHGHHSHSET> pc_chghhshset(new PC_CHGHHSHSET(nullptr));
			pc_chghhshset->open(sourceDSN, targetDSN);
			pc_chghhshset->setRepositoryString(envyRepositoryString);
			pc_chghhshset->setProfileName(profileName);
			pc_chghhshset->setReplicationOption(eReplicationOption);
			pc_chghhshset->setDropOption(edropOption);
			pc_chghhshset->setOdbcAttributes(odbcAttributes);
			pc_chghhshset->setUpdateInterval(updateInterval);
			pc_chghhshset->setCommitInterval(commitInterval);
			pc_chghhshset->process(1);
		} break;
		case Rctables::enumPC_APIHHSHSET:
		{
			QScopedPointer<PC_APIHHSHSET> pc_apihhshset(new PC_APIHHSHSET(nullptr));
			pc_apihhshset->open(sourceDSN, targetDSN);
			pc_apihhshset->setRepositoryString(envyRepositoryString);
			pc_apihhshset->setProfileName(profileName);
			pc_apihhshset->setReplicationOption(eReplicationOption);
			pc_apihhshset->setDropOption(edropOption);
			pc_apihhshset->setOdbcAttributes(odbcAttributes);
			pc_apihhshset->setUpdateInterval(updateInterval);
			pc_apihhshset->setCommitInterval(commitInterval);
			pc_apihhshset->process(1);
		} break;
		case Rctables::enumPC_USRREC:
		{
			QScopedPointer<PC_USRREC> pc_usrrec(new PC_USRREC(nullptr));
			pc_usrrec->open(sourceDSN, targetDSN);
			pc_usrrec->setRepositoryString(envyRepositoryString);
			pc_usrrec->setProfileName(profileName);
			pc_usrrec->setReplicationOption(eReplicationOption);
			pc_usrrec->setDropOption(edropOption);
			pc_usrrec->setOdbcAttributes(odbcAttributes);
			pc_usrrec->setUpdateInterval(updateInterval);
			pc_usrrec->setCommitInterval(commitInterval);
			pc_usrrec->process(1);
		} break;
		case Rctables::enumPC_MPISAFREC:
		{
			QScopedPointer<PC_MPISAFREC> pc_mpisafrec(new PC_MPISAFREC(nullptr));
			pc_mpisafrec->open(sourceDSN, targetDSN);
			pc_mpisafrec->setRepositoryString(envyRepositoryString);
			pc_mpisafrec->setProfileName(profileName);
			pc_mpisafrec->setReplicationOption(eReplicationOption);
			pc_mpisafrec->setDropOption(edropOption);
			pc_mpisafrec->setOdbcAttributes(odbcAttributes);
			pc_mpisafrec->setUpdateInterval(updateInterval);
			pc_mpisafrec->setCommitInterval(commitInterval);
			pc_mpisafrec->process(1);
		} break;
		case Rctables::enumPC_FRMFCODSET:
		{
			QScopedPointer<PC_FRMFCODSET> pc_frmfcodset(new PC_FRMFCODSET(nullptr));
			pc_frmfcodset->open(sourceDSN, targetDSN);
			pc_frmfcodset->setRepositoryString(envyRepositoryString);
			pc_frmfcodset->setProfileName(profileName);
			pc_frmfcodset->setReplicationOption(eReplicationOption);
			pc_frmfcodset->setDropOption(edropOption);
			pc_frmfcodset->setOdbcAttributes(odbcAttributes);
			pc_frmfcodset->setUpdateInterval(updateInterval);
			pc_frmfcodset->setCommitInterval(commitInterval);
			pc_frmfcodset->process(1);
		} break;
		case Rctables::enumPC_APITREC:
		{
			QScopedPointer<PC_APITREC> pc_apitrec(new PC_APITREC(nullptr));
			pc_apitrec->open(sourceDSN, targetDSN);
			pc_apitrec->setRepositoryString(envyRepositoryString);
			pc_apitrec->setProfileName(profileName);
			pc_apitrec->setReplicationOption(eReplicationOption);
			pc_apitrec->setDropOption(edropOption);
			pc_apitrec->setOdbcAttributes(odbcAttributes);
			pc_apitrec->setUpdateInterval(updateInterval);
			pc_apitrec->setCommitInterval(commitInterval);
			pc_apitrec->process(1);
		} break;
		case Rctables::enumPC_PRTMINGSET:
		{
			QScopedPointer<PC_PRTMINGSET> pc_prtmingset(new PC_PRTMINGSET(nullptr));
			pc_prtmingset->open(sourceDSN, targetDSN);
			pc_prtmingset->setRepositoryString(envyRepositoryString);
			pc_prtmingset->setProfileName(profileName);
			pc_prtmingset->setReplicationOption(eReplicationOption);
			pc_prtmingset->setDropOption(edropOption);
			pc_prtmingset->setOdbcAttributes(odbcAttributes);
			pc_prtmingset->setUpdateInterval(updateInterval);
			pc_prtmingset->setCommitInterval(commitInterval);
			pc_prtmingset->process(1);
		} break;
		case Rctables::enumPC_WODREC:
		{
			QScopedPointer<PC_WODREC> pc_wodrec(new PC_WODREC(nullptr));
			pc_wodrec->open(sourceDSN, targetDSN);
			pc_wodrec->setRepositoryString(envyRepositoryString);
			pc_wodrec->setProfileName(profileName);
			pc_wodrec->setReplicationOption(eReplicationOption);
			pc_wodrec->setDropOption(edropOption);
			pc_wodrec->setOdbcAttributes(odbcAttributes);
			pc_wodrec->setUpdateInterval(updateInterval);
			pc_wodrec->setCommitInterval(commitInterval);
			pc_wodrec->process(1);
		} break;
		case Rctables::enumPC_TEXTHSHSET:
		{
			QScopedPointer<PC_TEXTHSHSET> pc_texthshset(new PC_TEXTHSHSET(nullptr));
			pc_texthshset->open(sourceDSN, targetDSN);
			pc_texthshset->setRepositoryString(envyRepositoryString);
			pc_texthshset->setProfileName(profileName);
			pc_texthshset->setReplicationOption(eReplicationOption);
			pc_texthshset->setDropOption(edropOption);
			pc_texthshset->setOdbcAttributes(odbcAttributes);
			pc_texthshset->setUpdateInterval(updateInterval);
			pc_texthshset->setCommitInterval(commitInterval);
			pc_texthshset->process(1);
		} break;
		case Rctables::enumPC_PRTFRMSET:
		{
			QScopedPointer<PC_PRTFRMSET> pc_prtfrmset(new PC_PRTFRMSET(nullptr));
			pc_prtfrmset->open(sourceDSN, targetDSN);
			pc_prtfrmset->setRepositoryString(envyRepositoryString);
			pc_prtfrmset->setProfileName(profileName);
			pc_prtfrmset->setReplicationOption(eReplicationOption);
			pc_prtfrmset->setDropOption(edropOption);
			pc_prtfrmset->setOdbcAttributes(odbcAttributes);
			pc_prtfrmset->setUpdateInterval(updateInterval);
			pc_prtfrmset->setCommitInterval(commitInterval);
			pc_prtfrmset->process(1);
		} break;
		case Rctables::enumPC_MPITWUSET:
		{
			QScopedPointer<PC_MPITWUSET> pc_mpitwuset(new PC_MPITWUSET(nullptr));
			pc_mpitwuset->open(sourceDSN, targetDSN);
			pc_mpitwuset->setRepositoryString(envyRepositoryString);
			pc_mpitwuset->setProfileName(profileName);
			pc_mpitwuset->setReplicationOption(eReplicationOption);
			pc_mpitwuset->setDropOption(edropOption);
			pc_mpitwuset->setOdbcAttributes(odbcAttributes);
			pc_mpitwuset->setUpdateInterval(updateInterval);
			pc_mpitwuset->setCommitInterval(commitInterval);
			pc_mpitwuset->process(1);
		} break;
		case Rctables::enumPC_INGSTEPSET:
		{
			QScopedPointer<PC_INGSTEPSET> pc_ingstepset(new PC_INGSTEPSET(nullptr));
			pc_ingstepset->open(sourceDSN, targetDSN);
			pc_ingstepset->setRepositoryString(envyRepositoryString);
			pc_ingstepset->setProfileName(profileName);
			pc_ingstepset->setReplicationOption(eReplicationOption);
			pc_ingstepset->setDropOption(edropOption);
			pc_ingstepset->setOdbcAttributes(odbcAttributes);
			pc_ingstepset->setUpdateInterval(updateInterval);
			pc_ingstepset->setCommitInterval(commitInterval);
			pc_ingstepset->process(1);
		} break;
		case Rctables::enumPC_MBOWOHSET:
		{
			QScopedPointer<PC_MBOWOHSET> pc_mbowohset(new PC_MBOWOHSET(nullptr));
			pc_mbowohset->open(sourceDSN, targetDSN);
			pc_mbowohset->setRepositoryString(envyRepositoryString);
			pc_mbowohset->setProfileName(profileName);
			pc_mbowohset->setReplicationOption(eReplicationOption);
			pc_mbowohset->setDropOption(edropOption);
			pc_mbowohset->setOdbcAttributes(odbcAttributes);
			pc_mbowohset->setUpdateInterval(updateInterval);
			pc_mbowohset->setCommitInterval(commitInterval);
			pc_mbowohset->process(1);
		} break;
		case Rctables::enumPC_ADFREC:
		{
			QScopedPointer<PC_ADFREC> pc_adfrec(new PC_ADFREC(nullptr));
			pc_adfrec->open(sourceDSN, targetDSN);
			pc_adfrec->setRepositoryString(envyRepositoryString);
			pc_adfrec->setProfileName(profileName);
			pc_adfrec->setReplicationOption(eReplicationOption);
			pc_adfrec->setDropOption(edropOption);
			pc_adfrec->setOdbcAttributes(odbcAttributes);
			pc_adfrec->setUpdateInterval(updateInterval);
			pc_adfrec->setCommitInterval(commitInterval);
			pc_adfrec->process(1);
		} break;
		case Rctables::enumPC_TRKNOREC:
		{
			QScopedPointer<PC_TRKNOREC> pc_trknorec(new PC_TRKNOREC(nullptr));
			pc_trknorec->open(sourceDSN, targetDSN);
			pc_trknorec->setRepositoryString(envyRepositoryString);
			pc_trknorec->setProfileName(profileName);
			pc_trknorec->setReplicationOption(eReplicationOption);
			pc_trknorec->setDropOption(edropOption);
			pc_trknorec->setOdbcAttributes(odbcAttributes);
			pc_trknorec->setUpdateInterval(updateInterval);
			pc_trknorec->setCommitInterval(commitInterval);
			pc_trknorec->process(1);
		} break;
		case Rctables::enumPC_CHGHREC:
		{
			QScopedPointer<PC_CHGHREC> pc_chghrec(new PC_CHGHREC(nullptr));
			pc_chghrec->open(sourceDSN, targetDSN);
			pc_chghrec->setRepositoryString(envyRepositoryString);
			pc_chghrec->setProfileName(profileName);
			pc_chghrec->setReplicationOption(eReplicationOption);
			pc_chghrec->setDropOption(edropOption);
			pc_chghrec->setOdbcAttributes(odbcAttributes);
			pc_chghrec->setUpdateInterval(updateInterval);
			pc_chghrec->setCommitInterval(commitInterval);
			pc_chghrec->process(1);
		} break;
		case Rctables::enumPC_ADTDESREC:
		{
			QScopedPointer<PC_ADTDESREC> pc_adtdesrec(new PC_ADTDESREC(nullptr));
			pc_adtdesrec->open(sourceDSN, targetDSN);
			pc_adtdesrec->setRepositoryString(envyRepositoryString);
			pc_adtdesrec->setProfileName(profileName);
			pc_adtdesrec->setReplicationOption(eReplicationOption);
			pc_adtdesrec->setDropOption(edropOption);
			pc_adtdesrec->setOdbcAttributes(odbcAttributes);
			pc_adtdesrec->setUpdateInterval(updateInterval);
			pc_adtdesrec->setCommitInterval(commitInterval);
			pc_adtdesrec->process(1);
		} break;
		case Rctables::enumPC_MENDMCSTSET:
		{
			QScopedPointer<PC_MENDMCSTSET> pc_mendmcstset(new PC_MENDMCSTSET(nullptr));
			pc_mendmcstset->open(sourceDSN, targetDSN);
			pc_mendmcstset->setRepositoryString(envyRepositoryString);
			pc_mendmcstset->setProfileName(profileName);
			pc_mendmcstset->setReplicationOption(eReplicationOption);
			pc_mendmcstset->setDropOption(edropOption);
			pc_mendmcstset->setOdbcAttributes(odbcAttributes);
			pc_mendmcstset->setUpdateInterval(updateInterval);
			pc_mendmcstset->setCommitInterval(commitInterval);
			pc_mendmcstset->process(1);
		} break;
		case Rctables::enumPC_WKCHSHSET:
		{
			QScopedPointer<PC_WKCHSHSET> pc_wkchshset(new PC_WKCHSHSET(nullptr));
			pc_wkchshset->open(sourceDSN, targetDSN);
			pc_wkchshset->setRepositoryString(envyRepositoryString);
			pc_wkchshset->setProfileName(profileName);
			pc_wkchshset->setReplicationOption(eReplicationOption);
			pc_wkchshset->setDropOption(edropOption);
			pc_wkchshset->setOdbcAttributes(odbcAttributes);
			pc_wkchshset->setUpdateInterval(updateInterval);
			pc_wkchshset->setCommitInterval(commitInterval);
			pc_wkchshset->process(1);
		} break;
		case Rctables::enumPC_CATREC:
		{
			QScopedPointer<PC_CATREC> pc_catrec(new PC_CATREC(nullptr));
			pc_catrec->open(sourceDSN, targetDSN);
			pc_catrec->setRepositoryString(envyRepositoryString);
			pc_catrec->setProfileName(profileName);
			pc_catrec->setReplicationOption(eReplicationOption);
			pc_catrec->setDropOption(edropOption);
			pc_catrec->setOdbcAttributes(odbcAttributes);
			pc_catrec->setUpdateInterval(updateInterval);
			pc_catrec->setCommitInterval(commitInterval);
			pc_catrec->process(1);
		} break;
		case Rctables::enumPC_FCODREC:
		{
			QScopedPointer<PC_FCODREC> pc_fcodrec(new PC_FCODREC(nullptr));
			pc_fcodrec->open(sourceDSN, targetDSN);
			pc_fcodrec->setRepositoryString(envyRepositoryString);
			pc_fcodrec->setProfileName(profileName);
			pc_fcodrec->setReplicationOption(eReplicationOption);
			pc_fcodrec->setDropOption(edropOption);
			pc_fcodrec->setOdbcAttributes(odbcAttributes);
			pc_fcodrec->setUpdateInterval(updateInterval);
			pc_fcodrec->setCommitInterval(commitInterval);
			pc_fcodrec->process(1);
		} break;
		case Rctables::enumPC_MINGREC:
		{
			QScopedPointer<PC_MINGREC> pc_mingrec(new PC_MINGREC(nullptr));
			pc_mingrec->open(sourceDSN, targetDSN);
			pc_mingrec->setRepositoryString(envyRepositoryString);
			pc_mingrec->setProfileName(profileName);
			pc_mingrec->setReplicationOption(eReplicationOption);
			pc_mingrec->setDropOption(edropOption);
			pc_mingrec->setOdbcAttributes(odbcAttributes);
			pc_mingrec->setUpdateInterval(updateInterval);
			pc_mingrec->setCommitInterval(commitInterval);
			pc_mingrec->process(1);
		} break;
		case Rctables::enumPC_FRMHDESSET:
		{
			QScopedPointer<PC_FRMHDESSET> pc_frmhdesset(new PC_FRMHDESSET(nullptr));
			pc_frmhdesset->open(sourceDSN, targetDSN);
			pc_frmhdesset->setRepositoryString(envyRepositoryString);
			pc_frmhdesset->setProfileName(profileName);
			pc_frmhdesset->setReplicationOption(eReplicationOption);
			pc_frmhdesset->setDropOption(edropOption);
			pc_frmhdesset->setOdbcAttributes(odbcAttributes);
			pc_frmhdesset->setUpdateInterval(updateInterval);
			pc_frmhdesset->setCommitInterval(commitInterval);
			pc_frmhdesset->process(1);
		} break;
		case Rctables::enumPC_CATFRMPVSET:
		{
			QScopedPointer<PC_CATFRMPVSET> pc_catfrmpvset(new PC_CATFRMPVSET(nullptr));
			pc_catfrmpvset->open(sourceDSN, targetDSN);
			pc_catfrmpvset->setRepositoryString(envyRepositoryString);
			pc_catfrmpvset->setProfileName(profileName);
			pc_catfrmpvset->setReplicationOption(eReplicationOption);
			pc_catfrmpvset->setDropOption(edropOption);
			pc_catfrmpvset->setOdbcAttributes(odbcAttributes);
			pc_catfrmpvset->setUpdateInterval(updateInterval);
			pc_catfrmpvset->setCommitInterval(commitInterval);
			pc_catfrmpvset->process(1);
		} break;
		case Rctables::enumPC_CHGHCHGDSET:
		{
			QScopedPointer<PC_CHGHCHGDSET> pc_chghchgdset(new PC_CHGHCHGDSET(nullptr));
			pc_chghchgdset->open(sourceDSN, targetDSN);
			pc_chghchgdset->setRepositoryString(envyRepositoryString);
			pc_chghchgdset->setProfileName(profileName);
			pc_chghchgdset->setReplicationOption(eReplicationOption);
			pc_chghchgdset->setDropOption(edropOption);
			pc_chghchgdset->setOdbcAttributes(odbcAttributes);
			pc_chghchgdset->setUpdateInterval(updateInterval);
			pc_chghchgdset->setCommitInterval(commitInterval);
			pc_chghchgdset->process(1);
		} break;
		case Rctables::enumPC_FRMENDSET:
		{
			QScopedPointer<PC_FRMENDSET> pc_frmendset(new PC_FRMENDSET(nullptr));
			pc_frmendset->open(sourceDSN, targetDSN);
			pc_frmendset->setRepositoryString(envyRepositoryString);
			pc_frmendset->setProfileName(profileName);
			pc_frmendset->setReplicationOption(eReplicationOption);
			pc_frmendset->setDropOption(edropOption);
			pc_frmendset->setOdbcAttributes(odbcAttributes);
			pc_frmendset->setUpdateInterval(updateInterval);
			pc_frmendset->setCommitInterval(commitInterval);
			pc_frmendset->process(1);
		} break;
		case Rctables::enumPC_WOHHSHSET:
		{
			QScopedPointer<PC_WOHHSHSET> pc_wohhshset(new PC_WOHHSHSET(nullptr));
			pc_wohhshset->open(sourceDSN, targetDSN);
			pc_wohhshset->setRepositoryString(envyRepositoryString);
			pc_wohhshset->setProfileName(profileName);
			pc_wohhshset->setReplicationOption(eReplicationOption);
			pc_wohhshset->setDropOption(edropOption);
			pc_wohhshset->setOdbcAttributes(odbcAttributes);
			pc_wohhshset->setUpdateInterval(updateInterval);
			pc_wohhshset->setCommitInterval(commitInterval);
			pc_wohhshset->process(1);
		} break;
		case Rctables::enumPC_PISAFREC:
		{
			QScopedPointer<PC_PISAFREC> pc_pisafrec(new PC_PISAFREC(nullptr));
			pc_pisafrec->open(sourceDSN, targetDSN);
			pc_pisafrec->setRepositoryString(envyRepositoryString);
			pc_pisafrec->setProfileName(profileName);
			pc_pisafrec->setReplicationOption(eReplicationOption);
			pc_pisafrec->setDropOption(edropOption);
			pc_pisafrec->setOdbcAttributes(odbcAttributes);
			pc_pisafrec->setUpdateInterval(updateInterval);
			pc_pisafrec->setCommitInterval(commitInterval);
			pc_pisafrec->process(1);
		} break;
		case Rctables::enumPC_FCOHFCODSET:
		{
			QScopedPointer<PC_FCOHFCODSET> pc_fcohfcodset(new PC_FCOHFCODSET(nullptr));
			pc_fcohfcodset->open(sourceDSN, targetDSN);
			pc_fcohfcodset->setRepositoryString(envyRepositoryString);
			pc_fcohfcodset->setProfileName(profileName);
			pc_fcohfcodset->setReplicationOption(eReplicationOption);
			pc_fcohfcodset->setDropOption(edropOption);
			pc_fcohfcodset->setOdbcAttributes(odbcAttributes);
			pc_fcohfcodset->setUpdateInterval(updateInterval);
			pc_fcohfcodset->setCommitInterval(commitInterval);
			pc_fcohfcodset->process(1);
		} break;
		case Rctables::enumPC_FRMREC:
		{
			QScopedPointer<PC_FRMREC> pc_frmrec(new PC_FRMREC(nullptr));
			pc_frmrec->open(sourceDSN, targetDSN);
			pc_frmrec->setRepositoryString(envyRepositoryString);
			pc_frmrec->setProfileName(profileName);
			pc_frmrec->setReplicationOption(eReplicationOption);
			pc_frmrec->setDropOption(edropOption);
			pc_frmrec->setOdbcAttributes(odbcAttributes);
			pc_frmrec->setUpdateInterval(updateInterval);
			pc_frmrec->setCommitInterval(commitInterval);
			pc_frmrec->process(1);
		} break;
		case Rctables::enumPC_WKCAPITSET:
		{
			QScopedPointer<PC_WKCAPITSET> pc_wkcapitset(new PC_WKCAPITSET(nullptr));
			pc_wkcapitset->open(sourceDSN, targetDSN);
			pc_wkcapitset->setRepositoryString(envyRepositoryString);
			pc_wkcapitset->setProfileName(profileName);
			pc_wkcapitset->setReplicationOption(eReplicationOption);
			pc_wkcapitset->setDropOption(edropOption);
			pc_wkcapitset->setOdbcAttributes(odbcAttributes);
			pc_wkcapitset->setUpdateInterval(updateInterval);
			pc_wkcapitset->setCommitInterval(commitInterval);
			pc_wkcapitset->process(1);
		} break;
		case Rctables::enumPC_MBOREC:
		{
			QScopedPointer<PC_MBOREC> pc_mborec(new PC_MBOREC(nullptr));
			pc_mborec->open(sourceDSN, targetDSN);
			pc_mborec->setRepositoryString(envyRepositoryString);
			pc_mborec->setProfileName(profileName);
			pc_mborec->setReplicationOption(eReplicationOption);
			pc_mborec->setDropOption(edropOption);
			pc_mborec->setOdbcAttributes(odbcAttributes);
			pc_mborec->setUpdateInterval(updateInterval);
			pc_mborec->setCommitInterval(commitInterval);
			pc_mborec->process(1);
		} break;
		case Rctables::enumPC_MBOMENDSET:
		{
			QScopedPointer<PC_MBOMENDSET> pc_mbomendset(new PC_MBOMENDSET(nullptr));
			pc_mbomendset->open(sourceDSN, targetDSN);
			pc_mbomendset->setRepositoryString(envyRepositoryString);
			pc_mbomendset->setProfileName(profileName);
			pc_mbomendset->setReplicationOption(eReplicationOption);
			pc_mbomendset->setDropOption(edropOption);
			pc_mbomendset->setOdbcAttributes(odbcAttributes);
			pc_mbomendset->setUpdateInterval(updateInterval);
			pc_mbomendset->setCommitInterval(commitInterval);
			pc_mbomendset->process(1);
		} break;
		case Rctables::enumPC_PRTFCODSET:
		{
			QScopedPointer<PC_PRTFCODSET> pc_prtfcodset(new PC_PRTFCODSET(nullptr));
			pc_prtfcodset->open(sourceDSN, targetDSN);
			pc_prtfcodset->setRepositoryString(envyRepositoryString);
			pc_prtfcodset->setProfileName(profileName);
			pc_prtfcodset->setReplicationOption(eReplicationOption);
			pc_prtfcodset->setDropOption(edropOption);
			pc_prtfcodset->setOdbcAttributes(odbcAttributes);
			pc_prtfcodset->setUpdateInterval(updateInterval);
			pc_prtfcodset->setCommitInterval(commitInterval);
			pc_prtfcodset->process(1);
		} break;
		case Rctables::enumPC_TRKNOTREC:
		{
			QScopedPointer<PC_TRKNOTREC> pc_trknotrec(new PC_TRKNOTREC(nullptr));
			pc_trknotrec->open(sourceDSN, targetDSN);
			pc_trknotrec->setRepositoryString(envyRepositoryString);
			pc_trknotrec->setProfileName(profileName);
			pc_trknotrec->setReplicationOption(eReplicationOption);
			pc_trknotrec->setDropOption(edropOption);
			pc_trknotrec->setOdbcAttributes(odbcAttributes);
			pc_trknotrec->setUpdateInterval(updateInterval);
			pc_trknotrec->setCommitInterval(commitInterval);
			pc_trknotrec->process(1);
		} break;
		case Rctables::enumPC_TRKTRKNOTSET:
		{
			QScopedPointer<PC_TRKTRKNOTSET> pc_trktrknotset(new PC_TRKTRKNOTSET(nullptr));
			pc_trktrknotset->open(sourceDSN, targetDSN);
			pc_trktrknotset->setRepositoryString(envyRepositoryString);
			pc_trktrknotset->setProfileName(profileName);
			pc_trktrknotset->setReplicationOption(eReplicationOption);
			pc_trktrknotset->setDropOption(edropOption);
			pc_trktrknotset->setOdbcAttributes(odbcAttributes);
			pc_trktrknotset->setUpdateInterval(updateInterval);
			pc_trktrknotset->setCommitInterval(commitInterval);
			pc_trktrknotset->process(1);
		} break;
		case Rctables::enumPC_ALTHREC:
		{
			QScopedPointer<PC_ALTHREC> pc_althrec(new PC_ALTHREC(nullptr));
			pc_althrec->open(sourceDSN, targetDSN);
			pc_althrec->setRepositoryString(envyRepositoryString);
			pc_althrec->setProfileName(profileName);
			pc_althrec->setReplicationOption(eReplicationOption);
			pc_althrec->setDropOption(edropOption);
			pc_althrec->setOdbcAttributes(odbcAttributes);
			pc_althrec->setUpdateInterval(updateInterval);
			pc_althrec->setCommitInterval(commitInterval);
			pc_althrec->process(1);
		} break;
		case Rctables::enumPC_STEPREC:
		{
			QScopedPointer<PC_STEPREC> pc_steprec(new PC_STEPREC(nullptr));
			pc_steprec->open(sourceDSN, targetDSN);
			pc_steprec->setRepositoryString(envyRepositoryString);
			pc_steprec->setProfileName(profileName);
			pc_steprec->setReplicationOption(eReplicationOption);
			pc_steprec->setDropOption(edropOption);
			pc_steprec->setOdbcAttributes(odbcAttributes);
			pc_steprec->setUpdateInterval(updateInterval);
			pc_steprec->setCommitInterval(commitInterval);
			pc_steprec->process(1);
		} break;
		case Rctables::enumPC_MBOMBODESSET:
		{
			QScopedPointer<PC_MBOMBODESSET> pc_mbombodesset(new PC_MBOMBODESSET(nullptr));
			pc_mbombodesset->open(sourceDSN, targetDSN);
			pc_mbombodesset->setRepositoryString(envyRepositoryString);
			pc_mbombodesset->setProfileName(profileName);
			pc_mbombodesset->setReplicationOption(eReplicationOption);
			pc_mbombodesset->setDropOption(edropOption);
			pc_mbombodesset->setOdbcAttributes(odbcAttributes);
			pc_mbombodesset->setUpdateInterval(updateInterval);
			pc_mbombodesset->setCommitInterval(commitInterval);
			pc_mbombodesset->process(1);
		} break;
		case Rctables::enumPC_SUBPREC:
		{
			QScopedPointer<PC_SUBPREC> pc_subprec(new PC_SUBPREC(nullptr));
			pc_subprec->open(sourceDSN, targetDSN);
			pc_subprec->setRepositoryString(envyRepositoryString);
			pc_subprec->setProfileName(profileName);
			pc_subprec->setReplicationOption(eReplicationOption);
			pc_subprec->setDropOption(edropOption);
			pc_subprec->setOdbcAttributes(odbcAttributes);
			pc_subprec->setUpdateInterval(updateInterval);
			pc_subprec->setCommitInterval(commitInterval);
			pc_subprec->process(1);
		} break;
		case Rctables::enumPC_FRMHSHSET:
		{
			QScopedPointer<PC_FRMHSHSET> pc_frmhshset(new PC_FRMHSHSET(nullptr));
			pc_frmhshset->open(sourceDSN, targetDSN);
			pc_frmhshset->setRepositoryString(envyRepositoryString);
			pc_frmhshset->setProfileName(profileName);
			pc_frmhshset->setReplicationOption(eReplicationOption);
			pc_frmhshset->setDropOption(edropOption);
			pc_frmhshset->setOdbcAttributes(odbcAttributes);
			pc_frmhshset->setUpdateInterval(updateInterval);
			pc_frmhshset->setCommitInterval(commitInterval);
			pc_frmhshset->process(1);
		} break;
		case Rctables::enumPC_WKCREC:
		{
			QScopedPointer<PC_WKCREC> pc_wkcrec(new PC_WKCREC(nullptr));
			pc_wkcrec->open(sourceDSN, targetDSN);
			pc_wkcrec->setRepositoryString(envyRepositoryString);
			pc_wkcrec->setProfileName(profileName);
			pc_wkcrec->setReplicationOption(eReplicationOption);
			pc_wkcrec->setDropOption(edropOption);
			pc_wkcrec->setOdbcAttributes(odbcAttributes);
			pc_wkcrec->setUpdateInterval(updateInterval);
			pc_wkcrec->setCommitInterval(commitInterval);
			pc_wkcrec->process(1);
		} break;
		case Rctables::enumPC_TOOREC:
		{
			QScopedPointer<PC_TOOREC> pc_toorec(new PC_TOOREC(nullptr));
			pc_toorec->open(sourceDSN, targetDSN);
			pc_toorec->setRepositoryString(envyRepositoryString);
			pc_toorec->setProfileName(profileName);
			pc_toorec->setReplicationOption(eReplicationOption);
			pc_toorec->setDropOption(edropOption);
			pc_toorec->setOdbcAttributes(odbcAttributes);
			pc_toorec->setUpdateInterval(updateInterval);
			pc_toorec->setCommitInterval(commitInterval);
			pc_toorec->process(1);
		} break;
		case Rctables::enumPC_PIDESREC:
		{
			QScopedPointer<PC_PIDESREC> pc_pidesrec(new PC_PIDESREC(nullptr));
			pc_pidesrec->open(sourceDSN, targetDSN);
			pc_pidesrec->setRepositoryString(envyRepositoryString);
			pc_pidesrec->setProfileName(profileName);
			pc_pidesrec->setReplicationOption(eReplicationOption);
			pc_pidesrec->setDropOption(edropOption);
			pc_pidesrec->setOdbcAttributes(odbcAttributes);
			pc_pidesrec->setUpdateInterval(updateInterval);
			pc_pidesrec->setCommitInterval(commitInterval);
			pc_pidesrec->process(1);
		} break;
		case Rctables::enumPC_SLFREC:
		{
			QScopedPointer<PC_SLFREC> pc_slfrec(new PC_SLFREC(nullptr));
			pc_slfrec->open(sourceDSN, targetDSN);
			pc_slfrec->setRepositoryString(envyRepositoryString);
			pc_slfrec->setProfileName(profileName);
			pc_slfrec->setReplicationOption(eReplicationOption);
			pc_slfrec->setDropOption(edropOption);
			pc_slfrec->setOdbcAttributes(odbcAttributes);
			pc_slfrec->setUpdateInterval(updateInterval);
			pc_slfrec->setCommitInterval(commitInterval);
			pc_slfrec->process(1);
		} break;
		case Rctables::enumPC_MINGMIDESSET:
		{
			QScopedPointer<PC_MINGMIDESSET> pc_mingmidesset(new PC_MINGMIDESSET(nullptr));
			pc_mingmidesset->open(sourceDSN, targetDSN);
			pc_mingmidesset->setRepositoryString(envyRepositoryString);
			pc_mingmidesset->setProfileName(profileName);
			pc_mingmidesset->setReplicationOption(eReplicationOption);
			pc_mingmidesset->setDropOption(edropOption);
			pc_mingmidesset->setOdbcAttributes(odbcAttributes);
			pc_mingmidesset->setUpdateInterval(updateInterval);
			pc_mingmidesset->setCommitInterval(commitInterval);
			pc_mingmidesset->process(1);
		} break;
		case Rctables::enumPC_USRHSHSET:
		{
			QScopedPointer<PC_USRHSHSET> pc_usrhshset(new PC_USRHSHSET(nullptr));
			pc_usrhshset->open(sourceDSN, targetDSN);
			pc_usrhshset->setRepositoryString(envyRepositoryString);
			pc_usrhshset->setProfileName(profileName);
			pc_usrhshset->setReplicationOption(eReplicationOption);
			pc_usrhshset->setDropOption(edropOption);
			pc_usrhshset->setOdbcAttributes(odbcAttributes);
			pc_usrhshset->setUpdateInterval(updateInterval);
			pc_usrhshset->setCommitInterval(commitInterval);
			pc_usrhshset->process(1);
		} break;
		case Rctables::enumPC_PRTSLFSET:
		{
			QScopedPointer<PC_PRTSLFSET> pc_prtslfset(new PC_PRTSLFSET(nullptr));
			pc_prtslfset->open(sourceDSN, targetDSN);
			pc_prtslfset->setRepositoryString(envyRepositoryString);
			pc_prtslfset->setProfileName(profileName);
			pc_prtslfset->setReplicationOption(eReplicationOption);
			pc_prtslfset->setDropOption(edropOption);
			pc_prtslfset->setOdbcAttributes(odbcAttributes);
			pc_prtslfset->setUpdateInterval(updateInterval);
			pc_prtslfset->setCommitInterval(commitInterval);
			pc_prtslfset->process(1);
		} break;
		case Rctables::enumPC_MBOHSHSET:
		{
			QScopedPointer<PC_MBOHSHSET> pc_mbohshset(new PC_MBOHSHSET(nullptr));
			pc_mbohshset->open(sourceDSN, targetDSN);
			pc_mbohshset->setRepositoryString(envyRepositoryString);
			pc_mbohshset->setProfileName(profileName);
			pc_mbohshset->setReplicationOption(eReplicationOption);
			pc_mbohshset->setDropOption(edropOption);
			pc_mbohshset->setOdbcAttributes(odbcAttributes);
			pc_mbohshset->setUpdateInterval(updateInterval);
			pc_mbohshset->setCommitInterval(commitInterval);
			pc_mbohshset->process(1);
		} break;
		case Rctables::enumPC_CHGDREC:
		{
			QScopedPointer<PC_CHGDREC> pc_chgdrec(new PC_CHGDREC(nullptr));
			pc_chgdrec->open(sourceDSN, targetDSN);
			pc_chgdrec->setRepositoryString(envyRepositoryString);
			pc_chgdrec->setProfileName(profileName);
			pc_chgdrec->setReplicationOption(eReplicationOption);
			pc_chgdrec->setDropOption(edropOption);
			pc_chgdrec->setOdbcAttributes(odbcAttributes);
			pc_chgdrec->setUpdateInterval(updateInterval);
			pc_chgdrec->setCommitInterval(commitInterval);
			pc_chgdrec->process(1);
		} break;
		case Rctables::enumPC_INGSIFSET:
		{
			QScopedPointer<PC_INGSIFSET> pc_ingsifset(new PC_INGSIFSET(nullptr));
			pc_ingsifset->open(sourceDSN, targetDSN);
			pc_ingsifset->setRepositoryString(envyRepositoryString);
			pc_ingsifset->setProfileName(profileName);
			pc_ingsifset->setReplicationOption(eReplicationOption);
			pc_ingsifset->setDropOption(edropOption);
			pc_ingsifset->setOdbcAttributes(odbcAttributes);
			pc_ingsifset->setUpdateInterval(updateInterval);
			pc_ingsifset->setCommitInterval(commitInterval);
			pc_ingsifset->process(1);
		} break;
		case Rctables::enumPC_HDESREC:
		{
			QScopedPointer<PC_HDESREC> pc_hdesrec(new PC_HDESREC(nullptr));
			pc_hdesrec->open(sourceDSN, targetDSN);
			pc_hdesrec->setRepositoryString(envyRepositoryString);
			pc_hdesrec->setProfileName(profileName);
			pc_hdesrec->setReplicationOption(eReplicationOption);
			pc_hdesrec->setDropOption(edropOption);
			pc_hdesrec->setOdbcAttributes(odbcAttributes);
			pc_hdesrec->setUpdateInterval(updateInterval);
			pc_hdesrec->setCommitInterval(commitInterval);
			pc_hdesrec->process(1);
		} break;
		case Rctables::enumPC_APITAPIDESSET:
		{
			QScopedPointer<PC_APITAPIDESSET> pc_apitapidesset(new PC_APITAPIDESSET(nullptr));
			pc_apitapidesset->open(sourceDSN, targetDSN);
			pc_apitapidesset->setRepositoryString(envyRepositoryString);
			pc_apitapidesset->setProfileName(profileName);
			pc_apitapidesset->setReplicationOption(eReplicationOption);
			pc_apitapidesset->setDropOption(edropOption);
			pc_apitapidesset->setOdbcAttributes(odbcAttributes);
			pc_apitapidesset->setUpdateInterval(updateInterval);
			pc_apitapidesset->setCommitInterval(commitInterval);
			pc_apitapidesset->process(1);
		} break;
		case Rctables::enumPC_ALTHHSHSET:
		{
			QScopedPointer<PC_ALTHHSHSET> pc_althhshset(new PC_ALTHHSHSET(nullptr));
			pc_althhshset->open(sourceDSN, targetDSN);
			pc_althhshset->setRepositoryString(envyRepositoryString);
			pc_althhshset->setProfileName(profileName);
			pc_althhshset->setReplicationOption(eReplicationOption);
			pc_althhshset->setDropOption(edropOption);
			pc_althhshset->setOdbcAttributes(odbcAttributes);
			pc_althhshset->setUpdateInterval(updateInterval);
			pc_althhshset->setCommitInterval(commitInterval);
			pc_althhshset->process(1);
		} break;
		case Rctables::enumPC_CATHSHSET:
		{
			QScopedPointer<PC_CATHSHSET> pc_cathshset(new PC_CATHSHSET(nullptr));
			pc_cathshset->open(sourceDSN, targetDSN);
			pc_cathshset->setRepositoryString(envyRepositoryString);
			pc_cathshset->setProfileName(profileName);
			pc_cathshset->setReplicationOption(eReplicationOption);
			pc_cathshset->setDropOption(edropOption);
			pc_cathshset->setOdbcAttributes(odbcAttributes);
			pc_cathshset->setUpdateInterval(updateInterval);
			pc_cathshset->setCommitInterval(commitInterval);
			pc_cathshset->process(1);
		} break;
		case Rctables::enumPC_TWUREC:
		{
			QScopedPointer<PC_TWUREC> pc_twurec(new PC_TWUREC(nullptr));
			pc_twurec->open(sourceDSN, targetDSN);
			pc_twurec->setRepositoryString(envyRepositoryString);
			pc_twurec->setProfileName(profileName);
			pc_twurec->setReplicationOption(eReplicationOption);
			pc_twurec->setDropOption(edropOption);
			pc_twurec->setOdbcAttributes(odbcAttributes);
			pc_twurec->setUpdateInterval(updateInterval);
			pc_twurec->setCommitInterval(commitInterval);
			pc_twurec->process(1);
		} break;
		case Rctables::enumPC_FCOHREC:
		{
			QScopedPointer<PC_FCOHREC> pc_fcohrec(new PC_FCOHREC(nullptr));
			pc_fcohrec->open(sourceDSN, targetDSN);
			pc_fcohrec->setRepositoryString(envyRepositoryString);
			pc_fcohrec->setProfileName(profileName);
			pc_fcohrec->setReplicationOption(eReplicationOption);
			pc_fcohrec->setDropOption(edropOption);
			pc_fcohrec->setOdbcAttributes(odbcAttributes);
			pc_fcohrec->setUpdateInterval(updateInterval);
			pc_fcohrec->setCommitInterval(commitInterval);
			pc_fcohrec->process(1);
		} break;
		case Rctables::enumPC_TEXTREC:
		{
			QScopedPointer<PC_TEXTREC> pc_textrec(new PC_TEXTREC(nullptr));
			pc_textrec->open(sourceDSN, targetDSN);
			pc_textrec->setRepositoryString(envyRepositoryString);
			pc_textrec->setProfileName(profileName);
			pc_textrec->setReplicationOption(eReplicationOption);
			pc_textrec->setDropOption(edropOption);
			pc_textrec->setOdbcAttributes(odbcAttributes);
			pc_textrec->setUpdateInterval(updateInterval);
			pc_textrec->setCommitInterval(commitInterval);
			pc_textrec->process(1);
		} break;
		case Rctables::enumPC_APIHAPIFSET:
		{
			QScopedPointer<PC_APIHAPIFSET> pc_apihapifset(new PC_APIHAPIFSET(nullptr));
			pc_apihapifset->open(sourceDSN, targetDSN);
			pc_apihapifset->setRepositoryString(envyRepositoryString);
			pc_apihapifset->setProfileName(profileName);
			pc_apihapifset->setReplicationOption(eReplicationOption);
			pc_apihapifset->setDropOption(edropOption);
			pc_apihapifset->setOdbcAttributes(odbcAttributes);
			pc_apihapifset->setUpdateInterval(updateInterval);
			pc_apihapifset->setCommitInterval(commitInterval);
			pc_apihapifset->process(1);
		} break;
		case Rctables::enumPC_APISAFREC:
		{
			QScopedPointer<PC_APISAFREC> pc_apisafrec(new PC_APISAFREC(nullptr));
			pc_apisafrec->open(sourceDSN, targetDSN);
			pc_apisafrec->setRepositoryString(envyRepositoryString);
			pc_apisafrec->setProfileName(profileName);
			pc_apisafrec->setReplicationOption(eReplicationOption);
			pc_apisafrec->setDropOption(edropOption);
			pc_apisafrec->setOdbcAttributes(odbcAttributes);
			pc_apisafrec->setUpdateInterval(updateInterval);
			pc_apisafrec->setCommitInterval(commitInterval);
			pc_apisafrec->process(1);
		} break;
		case Rctables::enumPC_SLTREC:
		{
			QScopedPointer<PC_SLTREC> pc_sltrec(new PC_SLTREC(nullptr));
			pc_sltrec->open(sourceDSN, targetDSN);
			pc_sltrec->setRepositoryString(envyRepositoryString);
			pc_sltrec->setProfileName(profileName);
			pc_sltrec->setReplicationOption(eReplicationOption);
			pc_sltrec->setDropOption(edropOption);
			pc_sltrec->setOdbcAttributes(odbcAttributes);
			pc_sltrec->setUpdateInterval(updateInterval);
			pc_sltrec->setCommitInterval(commitInterval);
			pc_sltrec->process(1);
		} break;
		case Rctables::enumPC_CATIXSET:
		{
			QScopedPointer<PC_CATIXSET> pc_catixset(new PC_CATIXSET(nullptr));
			pc_catixset->open(sourceDSN, targetDSN);
			pc_catixset->setRepositoryString(envyRepositoryString);
			pc_catixset->setProfileName(profileName);
			pc_catixset->setReplicationOption(eReplicationOption);
			pc_catixset->setDropOption(edropOption);
			pc_catixset->setOdbcAttributes(odbcAttributes);
			pc_catixset->setUpdateInterval(updateInterval);
			pc_catixset->setCommitInterval(commitInterval);
			pc_catixset->process(1);
		} break;
		case Rctables::enumPC_TRKREC:
		{
			QScopedPointer<PC_TRKREC> pc_trkrec(new PC_TRKREC(nullptr));
			pc_trkrec->open(sourceDSN, targetDSN);
			pc_trkrec->setRepositoryString(envyRepositoryString);
			pc_trkrec->setProfileName(profileName);
			pc_trkrec->setReplicationOption(eReplicationOption);
			pc_trkrec->setDropOption(edropOption);
			pc_trkrec->setOdbcAttributes(odbcAttributes);
			pc_trkrec->setUpdateInterval(updateInterval);
			pc_trkrec->setCommitInterval(commitInterval);
			pc_trkrec->process(1);
		} break;
		case Rctables::enumPC_TEXTTEXDSET:
		{
			QScopedPointer<PC_TEXTTEXDSET> pc_texttexdset(new PC_TEXTTEXDSET(nullptr));
			pc_texttexdset->open(sourceDSN, targetDSN);
			pc_texttexdset->setRepositoryString(envyRepositoryString);
			pc_texttexdset->setProfileName(profileName);
			pc_texttexdset->setReplicationOption(eReplicationOption);
			pc_texttexdset->setDropOption(edropOption);
			pc_texttexdset->setOdbcAttributes(odbcAttributes);
			pc_texttexdset->setUpdateInterval(updateInterval);
			pc_texttexdset->setCommitInterval(commitInterval);
			pc_texttexdset->process(1);
		} break;
		case Rctables::enumPC_PRTHSHSET:
		{
			QScopedPointer<PC_PRTHSHSET> pc_prthshset(new PC_PRTHSHSET(nullptr));
			pc_prthshset->open(sourceDSN, targetDSN);
			pc_prthshset->setRepositoryString(envyRepositoryString);
			pc_prthshset->setProfileName(profileName);
			pc_prthshset->setReplicationOption(eReplicationOption);
			pc_prthshset->setDropOption(edropOption);
			pc_prthshset->setOdbcAttributes(odbcAttributes);
			pc_prthshset->setUpdateInterval(updateInterval);
			pc_prthshset->setCommitInterval(commitInterval);
			pc_prthshset->process(1);
		} break;
		case Rctables::enumPC_PRTMBOSET:
		{
			QScopedPointer<PC_PRTMBOSET> pc_prtmboset(new PC_PRTMBOSET(nullptr));
			pc_prtmboset->open(sourceDSN, targetDSN);
			pc_prtmboset->setRepositoryString(envyRepositoryString);
			pc_prtmboset->setProfileName(profileName);
			pc_prtmboset->setReplicationOption(eReplicationOption);
			pc_prtmboset->setDropOption(edropOption);
			pc_prtmboset->setOdbcAttributes(odbcAttributes);
			pc_prtmboset->setUpdateInterval(updateInterval);
			pc_prtmboset->setCommitInterval(commitInterval);
			pc_prtmboset->process(1);
		} break;
		case Rctables::enumPC_ADTADTDESSET:
		{
			QScopedPointer<PC_ADTADTDESSET> pc_adtadtdesset(new PC_ADTADTDESSET(nullptr));
			pc_adtadtdesset->open(sourceDSN, targetDSN);
			pc_adtadtdesset->setRepositoryString(envyRepositoryString);
			pc_adtadtdesset->setProfileName(profileName);
			pc_adtadtdesset->setReplicationOption(eReplicationOption);
			pc_adtadtdesset->setDropOption(edropOption);
			pc_adtadtdesset->setOdbcAttributes(odbcAttributes);
			pc_adtadtdesset->setUpdateInterval(updateInterval);
			pc_adtadtdesset->setCommitInterval(commitInterval);
			pc_adtadtdesset->process(1);
		} break;
		case Rctables::enumPC_MCSTREC:
		{
			QScopedPointer<PC_MCSTREC> pc_mcstrec(new PC_MCSTREC(nullptr));
			pc_mcstrec->open(sourceDSN, targetDSN);
			pc_mcstrec->setRepositoryString(envyRepositoryString);
			pc_mcstrec->setProfileName(profileName);
			pc_mcstrec->setReplicationOption(eReplicationOption);
			pc_mcstrec->setDropOption(edropOption);
			pc_mcstrec->setOdbcAttributes(odbcAttributes);
			pc_mcstrec->setUpdateInterval(updateInterval);
			pc_mcstrec->setCommitInterval(commitInterval);
			pc_mcstrec->process(1);
		} break;
		case Rctables::enumPC_TOOTWUSET:
		{
			QScopedPointer<PC_TOOTWUSET> pc_tootwuset(new PC_TOOTWUSET(nullptr));
			pc_tootwuset->open(sourceDSN, targetDSN);
			pc_tootwuset->setRepositoryString(envyRepositoryString);
			pc_tootwuset->setProfileName(profileName);
			pc_tootwuset->setReplicationOption(eReplicationOption);
			pc_tootwuset->setDropOption(edropOption);
			pc_tootwuset->setOdbcAttributes(odbcAttributes);
			pc_tootwuset->setUpdateInterval(updateInterval);
			pc_tootwuset->setCommitInterval(commitInterval);
			pc_tootwuset->process(1);
		} break;
		case Rctables::enumPC_ADTREC:
		{
			QScopedPointer<PC_ADTREC> pc_adtrec(new PC_ADTREC(nullptr));
			pc_adtrec->open(sourceDSN, targetDSN);
			pc_adtrec->setRepositoryString(envyRepositoryString);
			pc_adtrec->setProfileName(profileName);
			pc_adtrec->setReplicationOption(eReplicationOption);
			pc_adtrec->setDropOption(edropOption);
			pc_adtrec->setOdbcAttributes(odbcAttributes);
			pc_adtrec->setUpdateInterval(updateInterval);
			pc_adtrec->setCommitInterval(commitInterval);
			pc_adtrec->process(1);
		} break;
		case Rctables::enumPC_APITAPISAFSET:
		{
			QScopedPointer<PC_APITAPISAFSET> pc_apitapisafset(new PC_APITAPISAFSET(nullptr));
			pc_apitapisafset->open(sourceDSN, targetDSN);
			pc_apitapisafset->setRepositoryString(envyRepositoryString);
			pc_apitapisafset->setProfileName(profileName);
			pc_apitapisafset->setReplicationOption(eReplicationOption);
			pc_apitapisafset->setDropOption(edropOption);
			pc_apitapisafset->setOdbcAttributes(odbcAttributes);
			pc_apitapisafset->setUpdateInterval(updateInterval);
			pc_apitapisafset->setCommitInterval(commitInterval);
			pc_apitapisafset->process(1);
		} break;
		case Rctables::enumPC_ALTHADFSET:
		{
			QScopedPointer<PC_ALTHADFSET> pc_althadfset(new PC_ALTHADFSET(nullptr));
			pc_althadfset->open(sourceDSN, targetDSN);
			pc_althadfset->setRepositoryString(envyRepositoryString);
			pc_althadfset->setProfileName(profileName);
			pc_althadfset->setReplicationOption(eReplicationOption);
			pc_althadfset->setDropOption(edropOption);
			pc_althadfset->setOdbcAttributes(odbcAttributes);
			pc_althadfset->setUpdateInterval(updateInterval);
			pc_althadfset->setCommitInterval(commitInterval);
			pc_althadfset->process(1);
		} break;
		case Rctables::enumPC_MPIDESREC:
		{
			QScopedPointer<PC_MPIDESREC> pc_mpidesrec(new PC_MPIDESREC(nullptr));
			pc_mpidesrec->open(sourceDSN, targetDSN);
			pc_mpidesrec->setRepositoryString(envyRepositoryString);
			pc_mpidesrec->setProfileName(profileName);
			pc_mpidesrec->setReplicationOption(eReplicationOption);
			pc_mpidesrec->setDropOption(edropOption);
			pc_mpidesrec->setOdbcAttributes(odbcAttributes);
			pc_mpidesrec->setUpdateInterval(updateInterval);
			pc_mpidesrec->setCommitInterval(commitInterval);
			pc_mpidesrec->process(1);
		} break;
		case Rctables::enumPC_APIDESREC:
		{
			QScopedPointer<PC_APIDESREC> pc_apidesrec(new PC_APIDESREC(nullptr));
			pc_apidesrec->open(sourceDSN, targetDSN);
			pc_apidesrec->setRepositoryString(envyRepositoryString);
			pc_apidesrec->setProfileName(profileName);
			pc_apidesrec->setReplicationOption(eReplicationOption);
			pc_apidesrec->setDropOption(edropOption);
			pc_apidesrec->setOdbcAttributes(odbcAttributes);
			pc_apidesrec->setUpdateInterval(updateInterval);
			pc_apidesrec->setCommitInterval(commitInterval);
			pc_apidesrec->process(1);
		} break;
		case Rctables::enumPC_MBOMPISET:
		{
			QScopedPointer<PC_MBOMPISET> pc_mbompiset(new PC_MBOMPISET(nullptr));
			pc_mbompiset->open(sourceDSN, targetDSN);
			pc_mbompiset->setRepositoryString(envyRepositoryString);
			pc_mbompiset->setProfileName(profileName);
			pc_mbompiset->setReplicationOption(eReplicationOption);
			pc_mbompiset->setDropOption(edropOption);
			pc_mbompiset->setOdbcAttributes(odbcAttributes);
			pc_mbompiset->setUpdateInterval(updateInterval);
			pc_mbompiset->setCommitInterval(commitInterval);
			pc_mbompiset->process(1);
		} break;
		case Rctables::enumPC_PRTMENDSET:
		{
			QScopedPointer<PC_PRTMENDSET> pc_prtmendset(new PC_PRTMENDSET(nullptr));
			pc_prtmendset->open(sourceDSN, targetDSN);
			pc_prtmendset->setRepositoryString(envyRepositoryString);
			pc_prtmendset->setProfileName(profileName);
			pc_prtmendset->setReplicationOption(eReplicationOption);
			pc_prtmendset->setDropOption(edropOption);
			pc_prtmendset->setOdbcAttributes(odbcAttributes);
			pc_prtmendset->setUpdateInterval(updateInterval);
			pc_prtmendset->setCommitInterval(commitInterval);
			pc_prtmendset->process(1);
		} break;
		case Rctables::enumPC_APIHREC:
		{
			QScopedPointer<PC_APIHREC> pc_apihrec(new PC_APIHREC(nullptr));
			pc_apihrec->open(sourceDSN, targetDSN);
			pc_apihrec->setRepositoryString(envyRepositoryString);
			pc_apihrec->setProfileName(profileName);
			pc_apihrec->setReplicationOption(eReplicationOption);
			pc_apihrec->setDropOption(edropOption);
			pc_apihrec->setOdbcAttributes(odbcAttributes);
			pc_apihrec->setUpdateInterval(updateInterval);
			pc_apihrec->setCommitInterval(commitInterval);
			pc_apihrec->process(1);
		} break;
		case Rctables::enumPC_APIFREC:
		{
			QScopedPointer<PC_APIFREC> pc_apifrec(new PC_APIFREC(nullptr));
			pc_apifrec->open(sourceDSN, targetDSN);
			pc_apifrec->setRepositoryString(envyRepositoryString);
			pc_apifrec->setProfileName(profileName);
			pc_apifrec->setReplicationOption(eReplicationOption);
			pc_apifrec->setDropOption(edropOption);
			pc_apifrec->setOdbcAttributes(odbcAttributes);
			pc_apifrec->setUpdateInterval(updateInterval);
			pc_apifrec->setCommitInterval(commitInterval);
			pc_apifrec->process(1);
		} break;
		case Rctables::enumPC_PRTSLTSET:
		{
			QScopedPointer<PC_PRTSLTSET> pc_prtsltset(new PC_PRTSLTSET(nullptr));
			pc_prtsltset->open(sourceDSN, targetDSN);
			pc_prtsltset->setRepositoryString(envyRepositoryString);
			pc_prtsltset->setProfileName(profileName);
			pc_prtsltset->setReplicationOption(eReplicationOption);
			pc_prtsltset->setDropOption(edropOption);
			pc_prtsltset->setOdbcAttributes(odbcAttributes);
			pc_prtsltset->setUpdateInterval(updateInterval);
			pc_prtsltset->setCommitInterval(commitInterval);
			pc_prtsltset->process(1);
		} break;
		case Rctables::enumPC_SIFREC:
		{
			QScopedPointer<PC_SIFREC> pc_sifrec(new PC_SIFREC(nullptr));
			pc_sifrec->open(sourceDSN, targetDSN);
			pc_sifrec->setRepositoryString(envyRepositoryString);
			pc_sifrec->setProfileName(profileName);
			pc_sifrec->setReplicationOption(eReplicationOption);
			pc_sifrec->setDropOption(edropOption);
			pc_sifrec->setOdbcAttributes(odbcAttributes);
			pc_sifrec->setUpdateInterval(updateInterval);
			pc_sifrec->setCommitInterval(commitInterval);
			pc_sifrec->process(1);
		} break;
		case Rctables::enumPC_MBODESREC:
		{
			QScopedPointer<PC_MBODESREC> pc_mbodesrec(new PC_MBODESREC(nullptr));
			pc_mbodesrec->open(sourceDSN, targetDSN);
			pc_mbodesrec->setRepositoryString(envyRepositoryString);
			pc_mbodesrec->setProfileName(profileName);
			pc_mbodesrec->setReplicationOption(eReplicationOption);
			pc_mbodesrec->setDropOption(edropOption);
			pc_mbodesrec->setOdbcAttributes(odbcAttributes);
			pc_mbodesrec->setUpdateInterval(updateInterval);
			pc_mbodesrec->setCommitInterval(commitInterval);
			pc_mbodesrec->process(1);
		} break;
		case Rctables::enumPC_MPIMPISAFSET:
		{
			QScopedPointer<PC_MPIMPISAFSET> pc_mpimpisafset(new PC_MPIMPISAFSET(nullptr));
			pc_mpimpisafset->open(sourceDSN, targetDSN);
			pc_mpimpisafset->setRepositoryString(envyRepositoryString);
			pc_mpimpisafset->setProfileName(profileName);
			pc_mpimpisafset->setReplicationOption(eReplicationOption);
			pc_mpimpisafset->setDropOption(edropOption);
			pc_mpimpisafset->setOdbcAttributes(odbcAttributes);
			pc_mpimpisafset->setUpdateInterval(updateInterval);
			pc_mpimpisafset->setCommitInterval(commitInterval);
			pc_mpimpisafset->process(1);
		} break;
		case Rctables::enumPC_WOHREC:
		{
			QScopedPointer<PC_WOHREC> pc_wohrec(new PC_WOHREC(nullptr));
			pc_wohrec->open(sourceDSN, targetDSN);
			pc_wohrec->setRepositoryString(envyRepositoryString);
			pc_wohrec->setProfileName(profileName);
			pc_wohrec->setReplicationOption(eReplicationOption);
			pc_wohrec->setDropOption(edropOption);
			pc_wohrec->setOdbcAttributes(odbcAttributes);
			pc_wohrec->setUpdateInterval(updateInterval);
			pc_wohrec->setCommitInterval(commitInterval);
			pc_wohrec->process(1);
		} break;
		case Rctables::enumPC_TRKNOTRKSET:
		{
			QScopedPointer<PC_TRKNOTRKSET> pc_trknotrkset(new PC_TRKNOTRKSET(nullptr));
			pc_trknotrkset->open(sourceDSN, targetDSN);
			pc_trknotrkset->setRepositoryString(envyRepositoryString);
			pc_trknotrkset->setProfileName(profileName);
			pc_trknotrkset->setReplicationOption(eReplicationOption);
			pc_trknotrkset->setDropOption(edropOption);
			pc_trknotrkset->setOdbcAttributes(odbcAttributes);
			pc_trknotrkset->setUpdateInterval(updateInterval);
			pc_trknotrkset->setCommitInterval(commitInterval);
			pc_trknotrkset->process(1);
		} break;
		case Rctables::enumPC_APITTWUSET:
		{
			QScopedPointer<PC_APITTWUSET> pc_apittwuset(new PC_APITTWUSET(nullptr));
			pc_apittwuset->open(sourceDSN, targetDSN);
			pc_apittwuset->setRepositoryString(envyRepositoryString);
			pc_apittwuset->setProfileName(profileName);
			pc_apittwuset->setReplicationOption(eReplicationOption);
			pc_apittwuset->setDropOption(edropOption);
			pc_apittwuset->setOdbcAttributes(odbcAttributes);
			pc_apittwuset->setUpdateInterval(updateInterval);
			pc_apittwuset->setCommitInterval(commitInterval);
			pc_apittwuset->process(1);
		} break;
		case Rctables::enumPC_CATFRMSET:
		{
			QScopedPointer<PC_CATFRMSET> pc_catfrmset(new PC_CATFRMSET(nullptr));
			pc_catfrmset->open(sourceDSN, targetDSN);
			pc_catfrmset->setRepositoryString(envyRepositoryString);
			pc_catfrmset->setProfileName(profileName);
			pc_catfrmset->setReplicationOption(eReplicationOption);
			pc_catfrmset->setDropOption(edropOption);
			pc_catfrmset->setOdbcAttributes(odbcAttributes);
			pc_catfrmset->setUpdateInterval(updateInterval);
			pc_catfrmset->setCommitInterval(commitInterval);
			pc_catfrmset->process(1);
		} break;
		case Rctables::enumPC_PRTINGSET:
		{
			QScopedPointer<PC_PRTINGSET> pc_prtingset(new PC_PRTINGSET(nullptr));
			pc_prtingset->open(sourceDSN, targetDSN);
			pc_prtingset->setRepositoryString(envyRepositoryString);
			pc_prtingset->setProfileName(profileName);
			pc_prtingset->setReplicationOption(eReplicationOption);
			pc_prtingset->setDropOption(edropOption);
			pc_prtingset->setOdbcAttributes(odbcAttributes);
			pc_prtingset->setUpdateInterval(updateInterval);
			pc_prtingset->setCommitInterval(commitInterval);
			pc_prtingset->process(1);
		} break;
		case Rctables::enumPC_PITWUSET:
		{
			QScopedPointer<PC_PITWUSET> pc_pitwuset(new PC_PITWUSET(nullptr));
			pc_pitwuset->open(sourceDSN, targetDSN);
			pc_pitwuset->setRepositoryString(envyRepositoryString);
			pc_pitwuset->setProfileName(profileName);
			pc_pitwuset->setReplicationOption(eReplicationOption);
			pc_pitwuset->setDropOption(edropOption);
			pc_pitwuset->setOdbcAttributes(odbcAttributes);
			pc_pitwuset->setUpdateInterval(updateInterval);
			pc_pitwuset->setCommitInterval(commitInterval);
			pc_pitwuset->process(1);
		} break;
		case Rctables::enumPC_PRTREC:
		{
			QScopedPointer<PC_PRTREC> pc_prtrec(new PC_PRTREC(nullptr));
			pc_prtrec->open(sourceDSN, targetDSN);
			pc_prtrec->setRepositoryString(envyRepositoryString);
			pc_prtrec->setProfileName(profileName);
			pc_prtrec->setReplicationOption(eReplicationOption);
			pc_prtrec->setDropOption(edropOption);
			pc_prtrec->setOdbcAttributes(odbcAttributes);
			pc_prtrec->setUpdateInterval(updateInterval);
			pc_prtrec->setCommitInterval(commitInterval);
			pc_prtrec->process(1);
		} break;
		case Rctables::enumPC_PIREC:
		{
			QScopedPointer<PC_PIREC> pc_pirec(new PC_PIREC(nullptr));
			pc_pirec->open(sourceDSN, targetDSN);
			pc_pirec->setRepositoryString(envyRepositoryString);
			pc_pirec->setProfileName(profileName);
			pc_pirec->setReplicationOption(eReplicationOption);
			pc_pirec->setDropOption(edropOption);
			pc_pirec->setOdbcAttributes(odbcAttributes);
			pc_pirec->setUpdateInterval(updateInterval);
			pc_pirec->setCommitInterval(commitInterval);
			pc_pirec->process(1);
		} break;
		case Rctables::enumPC_MPIMPIDESSET:
		{
			QScopedPointer<PC_MPIMPIDESSET> pc_mpimpidesset(new PC_MPIMPIDESSET(nullptr));
			pc_mpimpidesset->open(sourceDSN, targetDSN);
			pc_mpimpidesset->setRepositoryString(envyRepositoryString);
			pc_mpimpidesset->setProfileName(profileName);
			pc_mpimpidesset->setReplicationOption(eReplicationOption);
			pc_mpimpidesset->setDropOption(edropOption);
			pc_mpimpidesset->setOdbcAttributes(odbcAttributes);
			pc_mpimpidesset->setUpdateInterval(updateInterval);
			pc_mpimpidesset->setCommitInterval(commitInterval);
			pc_mpimpidesset->process(1);
		} break;
		case Rctables::enumPC_ADTASTPSET:
		{
			QScopedPointer<PC_ADTASTPSET> pc_adtastpset(new PC_ADTASTPSET(nullptr));
			pc_adtastpset->open(sourceDSN, targetDSN);
			pc_adtastpset->setRepositoryString(envyRepositoryString);
			pc_adtastpset->setProfileName(profileName);
			pc_adtastpset->setReplicationOption(eReplicationOption);
			pc_adtastpset->setDropOption(edropOption);
			pc_adtastpset->setOdbcAttributes(odbcAttributes);
			pc_adtastpset->setUpdateInterval(updateInterval);
			pc_adtastpset->setCommitInterval(commitInterval);
			pc_adtastpset->process(1);
		} break;
		case Rctables::enumPC_FRMPISET:
		{
			QScopedPointer<PC_FRMPISET> pc_frmpiset(new PC_FRMPISET(nullptr));
			pc_frmpiset->open(sourceDSN, targetDSN);
			pc_frmpiset->setRepositoryString(envyRepositoryString);
			pc_frmpiset->setProfileName(profileName);
			pc_frmpiset->setReplicationOption(eReplicationOption);
			pc_frmpiset->setDropOption(edropOption);
			pc_frmpiset->setOdbcAttributes(odbcAttributes);
			pc_frmpiset->setUpdateInterval(updateInterval);
			pc_frmpiset->setCommitInterval(commitInterval);
			pc_frmpiset->process(1);
		} break;
		case Rctables::enumPC_IXHSHSET:
		{
			QScopedPointer<PC_IXHSHSET> pc_ixhshset(new PC_IXHSHSET(nullptr));
			pc_ixhshset->open(sourceDSN, targetDSN);
			pc_ixhshset->setRepositoryString(envyRepositoryString);
			pc_ixhshset->setProfileName(profileName);
			pc_ixhshset->setReplicationOption(eReplicationOption);
			pc_ixhshset->setDropOption(edropOption);
			pc_ixhshset->setOdbcAttributes(odbcAttributes);
			pc_ixhshset->setUpdateInterval(updateInterval);
			pc_ixhshset->setCommitInterval(commitInterval);
			pc_ixhshset->process(1);
		} break;
		case Rctables::enumPC_FRMPVREC:
		{
			QScopedPointer<PC_FRMPVREC> pc_frmpvrec(new PC_FRMPVREC(nullptr));
			pc_frmpvrec->open(sourceDSN, targetDSN);
			pc_frmpvrec->setRepositoryString(envyRepositoryString);
			pc_frmpvrec->setProfileName(profileName);
			pc_frmpvrec->setReplicationOption(eReplicationOption);
			pc_frmpvrec->setDropOption(edropOption);
			pc_frmpvrec->setOdbcAttributes(odbcAttributes);
			pc_frmpvrec->setUpdateInterval(updateInterval);
			pc_frmpvrec->setCommitInterval(commitInterval);
			pc_frmpvrec->process(1);
		} break;
		case Rctables::enumPC_PISUBPSET:
		{
			QScopedPointer<PC_PISUBPSET> pc_pisubpset(new PC_PISUBPSET(nullptr));
			pc_pisubpset->open(sourceDSN, targetDSN);
			pc_pisubpset->setRepositoryString(envyRepositoryString);
			pc_pisubpset->setProfileName(profileName);
			pc_pisubpset->setReplicationOption(eReplicationOption);
			pc_pisubpset->setDropOption(edropOption);
			pc_pisubpset->setOdbcAttributes(odbcAttributes);
			pc_pisubpset->setUpdateInterval(updateInterval);
			pc_pisubpset->setCommitInterval(commitInterval);
			pc_pisubpset->process(1);
		} break;
		case Rctables::enumPC_MIDESREC:
		{
			QScopedPointer<PC_MIDESREC> pc_midesrec(new PC_MIDESREC(nullptr));
			pc_midesrec->open(sourceDSN, targetDSN);
			pc_midesrec->setRepositoryString(envyRepositoryString);
			pc_midesrec->setProfileName(profileName);
			pc_midesrec->setReplicationOption(eReplicationOption);
			pc_midesrec->setDropOption(edropOption);
			pc_midesrec->setOdbcAttributes(odbcAttributes);
			pc_midesrec->setUpdateInterval(updateInterval);
			pc_midesrec->setCommitInterval(commitInterval);
			pc_midesrec->process(1);
		} break;
		case Rctables::enumPC_PIPIDESSET:
		{
			QScopedPointer<PC_PIPIDESSET> pc_pipidesset(new PC_PIPIDESSET(nullptr));
			pc_pipidesset->open(sourceDSN, targetDSN);
			pc_pipidesset->setRepositoryString(envyRepositoryString);
			pc_pipidesset->setProfileName(profileName);
			pc_pipidesset->setReplicationOption(eReplicationOption);
			pc_pipidesset->setDropOption(edropOption);
			pc_pipidesset->setOdbcAttributes(odbcAttributes);
			pc_pipidesset->setUpdateInterval(updateInterval);
			pc_pipidesset->setCommitInterval(commitInterval);
			pc_pipidesset->process(1);
		} break;
		case Rctables::enumPC_ASTPREC:
		{
			QScopedPointer<PC_ASTPREC> pc_astprec(new PC_ASTPREC(nullptr));
			pc_astprec->open(sourceDSN, targetDSN);
			pc_astprec->setRepositoryString(envyRepositoryString);
			pc_astprec->setProfileName(profileName);
			pc_astprec->setReplicationOption(eReplicationOption);
			pc_astprec->setDropOption(edropOption);
			pc_astprec->setOdbcAttributes(odbcAttributes);
			pc_astprec->setUpdateInterval(updateInterval);
			pc_astprec->setCommitInterval(commitInterval);
			pc_astprec->process(1);
		} break;
		case Rctables::enumPC_MENDREC:
		{
			QScopedPointer<PC_MENDREC> pc_mendrec(new PC_MENDREC(nullptr));
			pc_mendrec->open(sourceDSN, targetDSN);
			pc_mendrec->setRepositoryString(envyRepositoryString);
			pc_mendrec->setProfileName(profileName);
			pc_mendrec->setReplicationOption(eReplicationOption);
			pc_mendrec->setDropOption(edropOption);
			pc_mendrec->setOdbcAttributes(odbcAttributes);
			pc_mendrec->setUpdateInterval(updateInterval);
			pc_mendrec->setCommitInterval(commitInterval);
			pc_mendrec->process(1);
		} break;
		case Rctables::enumPC_TOOHSHSET:
		{
			QScopedPointer<PC_TOOHSHSET> pc_toohshset(new PC_TOOHSHSET(nullptr));
			pc_toohshset->open(sourceDSN, targetDSN);
			pc_toohshset->setRepositoryString(envyRepositoryString);
			pc_toohshset->setProfileName(profileName);
			pc_toohshset->setReplicationOption(eReplicationOption);
			pc_toohshset->setDropOption(edropOption);
			pc_toohshset->setOdbcAttributes(odbcAttributes);
			pc_toohshset->setUpdateInterval(updateInterval);
			pc_toohshset->setCommitInterval(commitInterval);
			pc_toohshset->process(1);
		} break;
		case Rctables::enumPC_INGREC:
		{
			QScopedPointer<PC_INGREC> pc_ingrec(new PC_INGREC(nullptr));
			pc_ingrec->open(sourceDSN, targetDSN);
			pc_ingrec->setRepositoryString(envyRepositoryString);
			pc_ingrec->setProfileName(profileName);
			pc_ingrec->setReplicationOption(eReplicationOption);
			pc_ingrec->setDropOption(edropOption);
			pc_ingrec->setOdbcAttributes(odbcAttributes);
			pc_ingrec->setUpdateInterval(updateInterval);
			pc_ingrec->setCommitInterval(commitInterval);
			pc_ingrec->process(1);
		} break;
	}
#pragma endregion caselist
#endif caseList__h_PRCDB100
