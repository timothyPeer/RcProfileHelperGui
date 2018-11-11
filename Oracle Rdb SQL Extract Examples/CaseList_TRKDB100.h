/*H**********************************************************************
* FILENAME :        CaseList_TRKDB100.h             DESIGN REF: 
*
* DESCRIPTION :
*       This file contains a branches for each record that can be processed in the TRKDB MANMAN R11
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

#ifndef caseList__h_TRKDB100
#define caseList__h_TRKDB100

#pragma region caselist for TRKDB100

	switch (ffx)
	{
		case Rctables::enumTK_INTSOHSHSET:
		{
			QScopedPointer<TK_INTSOHSHSET> tk_intsohshset(new TK_INTSOHSHSET(nullptr));
			tk_intsohshset->open(sourceDSN, targetDSN);
			tk_intsohshset->setRepositoryString(envyRepositoryString);
			tk_intsohshset->setProfileName(profileName);
			tk_intsohshset->setReplicationOption(eReplicationOption);
			tk_intsohshset->setDropOption(edropOption);
			tk_intsohshset->setOdbcAttributes(odbcAttributes);
			tk_intsohshset->setUpdateInterval(updateInterval);
			tk_intsohshset->setCommitInterval(commitInterval);
			tk_intsohshset->process(1);
		} break;
		case Rctables::enumTK_PRTLIDSET:
		{
			QScopedPointer<TK_PRTLIDSET> tk_prtlidset(new TK_PRTLIDSET(nullptr));
			tk_prtlidset->open(sourceDSN, targetDSN);
			tk_prtlidset->setRepositoryString(envyRepositoryString);
			tk_prtlidset->setProfileName(profileName);
			tk_prtlidset->setReplicationOption(eReplicationOption);
			tk_prtlidset->setDropOption(edropOption);
			tk_prtlidset->setOdbcAttributes(odbcAttributes);
			tk_prtlidset->setUpdateInterval(updateInterval);
			tk_prtlidset->setCommitInterval(commitInterval);
			tk_prtlidset->process(1);
		} break;
		case Rctables::enumTK_PRTHSHSET:
		{
			QScopedPointer<TK_PRTHSHSET> tk_prthshset(new TK_PRTHSHSET(nullptr));
			tk_prthshset->open(sourceDSN, targetDSN);
			tk_prthshset->setRepositoryString(envyRepositoryString);
			tk_prthshset->setProfileName(profileName);
			tk_prthshset->setReplicationOption(eReplicationOption);
			tk_prthshset->setDropOption(edropOption);
			tk_prthshset->setOdbcAttributes(odbcAttributes);
			tk_prthshset->setUpdateInterval(updateInterval);
			tk_prthshset->setCommitInterval(commitInterval);
			tk_prthshset->process(1);
		} break;
		case Rctables::enumTK_TYPHSHSET:
		{
			QScopedPointer<TK_TYPHSHSET> tk_typhshset(new TK_TYPHSHSET(nullptr));
			tk_typhshset->open(sourceDSN, targetDSN);
			tk_typhshset->setRepositoryString(envyRepositoryString);
			tk_typhshset->setProfileName(profileName);
			tk_typhshset->setReplicationOption(eReplicationOption);
			tk_typhshset->setDropOption(edropOption);
			tk_typhshset->setOdbcAttributes(odbcAttributes);
			tk_typhshset->setUpdateInterval(updateInterval);
			tk_typhshset->setCommitInterval(commitInterval);
			tk_typhshset->process(1);
		} break;
		case Rctables::enumTK_FLGREC:
		{
			QScopedPointer<TK_FLGREC> tk_flgrec(new TK_FLGREC(nullptr));
			tk_flgrec->open(sourceDSN, targetDSN);
			tk_flgrec->setRepositoryString(envyRepositoryString);
			tk_flgrec->setProfileName(profileName);
			tk_flgrec->setReplicationOption(eReplicationOption);
			tk_flgrec->setDropOption(edropOption);
			tk_flgrec->setOdbcAttributes(odbcAttributes);
			tk_flgrec->setUpdateInterval(updateInterval);
			tk_flgrec->setCommitInterval(commitInterval);
			tk_flgrec->process(1);
		} break;
		case Rctables::enumTK_LTFREC:
		{
			QScopedPointer<TK_LTFREC> tk_ltfrec(new TK_LTFREC(nullptr));
			tk_ltfrec->open(sourceDSN, targetDSN);
			tk_ltfrec->setRepositoryString(envyRepositoryString);
			tk_ltfrec->setProfileName(profileName);
			tk_ltfrec->setReplicationOption(eReplicationOption);
			tk_ltfrec->setDropOption(edropOption);
			tk_ltfrec->setOdbcAttributes(odbcAttributes);
			tk_ltfrec->setUpdateInterval(updateInterval);
			tk_ltfrec->setCommitInterval(commitInterval);
			tk_ltfrec->process(1);
		} break;
		case Rctables::enumTK_PRCHSHSET:
		{
			QScopedPointer<TK_PRCHSHSET> tk_prchshset(new TK_PRCHSHSET(nullptr));
			tk_prchshset->open(sourceDSN, targetDSN);
			tk_prchshset->setRepositoryString(envyRepositoryString);
			tk_prchshset->setProfileName(profileName);
			tk_prchshset->setReplicationOption(eReplicationOption);
			tk_prchshset->setDropOption(edropOption);
			tk_prchshset->setOdbcAttributes(odbcAttributes);
			tk_prchshset->setUpdateInterval(updateInterval);
			tk_prchshset->setCommitInterval(commitInterval);
			tk_prchshset->process(1);
		} break;
		case Rctables::enumTK_NOTREC:
		{
			QScopedPointer<TK_NOTREC> tk_notrec(new TK_NOTREC(nullptr));
			tk_notrec->open(sourceDSN, targetDSN);
			tk_notrec->setRepositoryString(envyRepositoryString);
			tk_notrec->setProfileName(profileName);
			tk_notrec->setReplicationOption(eReplicationOption);
			tk_notrec->setDropOption(edropOption);
			tk_notrec->setOdbcAttributes(odbcAttributes);
			tk_notrec->setUpdateInterval(updateInterval);
			tk_notrec->setCommitInterval(commitInterval);
			tk_notrec->process(1);
		} break;
		case Rctables::enumTK_UPRTREC:
		{
			QScopedPointer<TK_UPRTREC> tk_uprtrec(new TK_UPRTREC(nullptr));
			tk_uprtrec->open(sourceDSN, targetDSN);
			tk_uprtrec->setRepositoryString(envyRepositoryString);
			tk_uprtrec->setProfileName(profileName);
			tk_uprtrec->setReplicationOption(eReplicationOption);
			tk_uprtrec->setDropOption(edropOption);
			tk_uprtrec->setOdbcAttributes(odbcAttributes);
			tk_uprtrec->setUpdateInterval(updateInterval);
			tk_uprtrec->setCommitInterval(commitInterval);
			tk_uprtrec->process(1);
		} break;
		case Rctables::enumTK_UPRTULSTSET:
		{
			QScopedPointer<TK_UPRTULSTSET> tk_uprtulstset(new TK_UPRTULSTSET(nullptr));
			tk_uprtulstset->open(sourceDSN, targetDSN);
			tk_uprtulstset->setRepositoryString(envyRepositoryString);
			tk_uprtulstset->setProfileName(profileName);
			tk_uprtulstset->setReplicationOption(eReplicationOption);
			tk_uprtulstset->setDropOption(edropOption);
			tk_uprtulstset->setOdbcAttributes(odbcAttributes);
			tk_uprtulstset->setUpdateInterval(updateInterval);
			tk_uprtulstset->setCommitInterval(commitInterval);
			tk_uprtulstset->process(1);
		} break;
		case Rctables::enumTK_LIDREC:
		{
			QScopedPointer<TK_LIDREC> tk_lidrec(new TK_LIDREC(nullptr));
			tk_lidrec->open(sourceDSN, targetDSN);
			tk_lidrec->setRepositoryString(envyRepositoryString);
			tk_lidrec->setProfileName(profileName);
			tk_lidrec->setReplicationOption(eReplicationOption);
			tk_lidrec->setDropOption(edropOption);
			tk_lidrec->setOdbcAttributes(odbcAttributes);
			tk_lidrec->setUpdateInterval(updateInterval);
			tk_lidrec->setCommitInterval(commitInterval);
			tk_lidrec->process(1);
		} break;
		case Rctables::enumTK_LTPBOMSET:
		{
			QScopedPointer<TK_LTPBOMSET> tk_ltpbomset(new TK_LTPBOMSET(nullptr));
			tk_ltpbomset->open(sourceDSN, targetDSN);
			tk_ltpbomset->setRepositoryString(envyRepositoryString);
			tk_ltpbomset->setProfileName(profileName);
			tk_ltpbomset->setReplicationOption(eReplicationOption);
			tk_ltpbomset->setDropOption(edropOption);
			tk_ltpbomset->setOdbcAttributes(odbcAttributes);
			tk_ltpbomset->setUpdateInterval(updateInterval);
			tk_ltpbomset->setCommitInterval(commitInterval);
			tk_ltpbomset->process(1);
		} break;
		case Rctables::enumTK_LIDHSHSET:
		{
			QScopedPointer<TK_LIDHSHSET> tk_lidhshset(new TK_LIDHSHSET(nullptr));
			tk_lidhshset->open(sourceDSN, targetDSN);
			tk_lidhshset->setRepositoryString(envyRepositoryString);
			tk_lidhshset->setProfileName(profileName);
			tk_lidhshset->setReplicationOption(eReplicationOption);
			tk_lidhshset->setDropOption(edropOption);
			tk_lidhshset->setOdbcAttributes(odbcAttributes);
			tk_lidhshset->setUpdateInterval(updateInterval);
			tk_lidhshset->setCommitInterval(commitInterval);
			tk_lidhshset->process(1);
		} break;
		case Rctables::enumTK_LIDLTPSET:
		{
			QScopedPointer<TK_LIDLTPSET> tk_lidltpset(new TK_LIDLTPSET(nullptr));
			tk_lidltpset->open(sourceDSN, targetDSN);
			tk_lidltpset->setRepositoryString(envyRepositoryString);
			tk_lidltpset->setProfileName(profileName);
			tk_lidltpset->setReplicationOption(eReplicationOption);
			tk_lidltpset->setDropOption(edropOption);
			tk_lidltpset->setOdbcAttributes(odbcAttributes);
			tk_lidltpset->setUpdateInterval(updateInterval);
			tk_lidltpset->setCommitInterval(commitInterval);
			tk_lidltpset->process(1);
		} break;
		case Rctables::enumTK_INTREC:
		{
			QScopedPointer<TK_INTREC> tk_intrec(new TK_INTREC(nullptr));
			tk_intrec->open(sourceDSN, targetDSN);
			tk_intrec->setRepositoryString(envyRepositoryString);
			tk_intrec->setProfileName(profileName);
			tk_intrec->setReplicationOption(eReplicationOption);
			tk_intrec->setDropOption(edropOption);
			tk_intrec->setOdbcAttributes(odbcAttributes);
			tk_intrec->setUpdateInterval(updateInterval);
			tk_intrec->setCommitInterval(commitInterval);
			tk_intrec->process(1);
		} break;
		case Rctables::enumTK_LTPCOMSET:
		{
			QScopedPointer<TK_LTPCOMSET> tk_ltpcomset(new TK_LTPCOMSET(nullptr));
			tk_ltpcomset->open(sourceDSN, targetDSN);
			tk_ltpcomset->setRepositoryString(envyRepositoryString);
			tk_ltpcomset->setProfileName(profileName);
			tk_ltpcomset->setReplicationOption(eReplicationOption);
			tk_ltpcomset->setDropOption(edropOption);
			tk_ltpcomset->setOdbcAttributes(odbcAttributes);
			tk_ltpcomset->setUpdateInterval(updateInterval);
			tk_ltpcomset->setCommitInterval(commitInterval);
			tk_ltpcomset->process(1);
		} break;
		case Rctables::enumTK_HDRREC:
		{
			QScopedPointer<TK_HDRREC> tk_hdrrec(new TK_HDRREC(nullptr));
			tk_hdrrec->open(sourceDSN, targetDSN);
			tk_hdrrec->setRepositoryString(envyRepositoryString);
			tk_hdrrec->setProfileName(profileName);
			tk_hdrrec->setReplicationOption(eReplicationOption);
			tk_hdrrec->setDropOption(edropOption);
			tk_hdrrec->setOdbcAttributes(odbcAttributes);
			tk_hdrrec->setUpdateInterval(updateInterval);
			tk_hdrrec->setCommitInterval(commitInterval);
			tk_hdrrec->process(1);
		} break;
		case Rctables::enumTK_CNVREC:
		{
			QScopedPointer<TK_CNVREC> tk_cnvrec(new TK_CNVREC(nullptr));
			tk_cnvrec->open(sourceDSN, targetDSN);
			tk_cnvrec->setRepositoryString(envyRepositoryString);
			tk_cnvrec->setProfileName(profileName);
			tk_cnvrec->setReplicationOption(eReplicationOption);
			tk_cnvrec->setDropOption(edropOption);
			tk_cnvrec->setOdbcAttributes(odbcAttributes);
			tk_cnvrec->setUpdateInterval(updateInterval);
			tk_cnvrec->setCommitInterval(commitInterval);
			tk_cnvrec->process(1);
		} break;
		case Rctables::enumTK_UHSTREC:
		{
			QScopedPointer<TK_UHSTREC> tk_uhstrec(new TK_UHSTREC(nullptr));
			tk_uhstrec->open(sourceDSN, targetDSN);
			tk_uhstrec->setRepositoryString(envyRepositoryString);
			tk_uhstrec->setProfileName(profileName);
			tk_uhstrec->setReplicationOption(eReplicationOption);
			tk_uhstrec->setDropOption(edropOption);
			tk_uhstrec->setOdbcAttributes(odbcAttributes);
			tk_uhstrec->setUpdateInterval(updateInterval);
			tk_uhstrec->setCommitInterval(commitInterval);
			tk_uhstrec->process(1);
		} break;
		case Rctables::enumTK_INTFMHSHSET:
		{
			QScopedPointer<TK_INTFMHSHSET> tk_intfmhshset(new TK_INTFMHSHSET(nullptr));
			tk_intfmhshset->open(sourceDSN, targetDSN);
			tk_intfmhshset->setRepositoryString(envyRepositoryString);
			tk_intfmhshset->setProfileName(profileName);
			tk_intfmhshset->setReplicationOption(eReplicationOption);
			tk_intfmhshset->setDropOption(edropOption);
			tk_intfmhshset->setOdbcAttributes(odbcAttributes);
			tk_intfmhshset->setUpdateInterval(updateInterval);
			tk_intfmhshset->setCommitInterval(commitInterval);
			tk_intfmhshset->process(1);
		} break;
		case Rctables::enumTK_LTDREC:
		{
			QScopedPointer<TK_LTDREC> tk_ltdrec(new TK_LTDREC(nullptr));
			tk_ltdrec->open(sourceDSN, targetDSN);
			tk_ltdrec->setRepositoryString(envyRepositoryString);
			tk_ltdrec->setProfileName(profileName);
			tk_ltdrec->setReplicationOption(eReplicationOption);
			tk_ltdrec->setDropOption(edropOption);
			tk_ltdrec->setOdbcAttributes(odbcAttributes);
			tk_ltdrec->setUpdateInterval(updateInterval);
			tk_ltdrec->setCommitInterval(commitInterval);
			tk_ltdrec->process(1);
		} break;
		case Rctables::enumTK_HDRHSHSET:
		{
			QScopedPointer<TK_HDRHSHSET> tk_hdrhshset(new TK_HDRHSHSET(nullptr));
			tk_hdrhshset->open(sourceDSN, targetDSN);
			tk_hdrhshset->setRepositoryString(envyRepositoryString);
			tk_hdrhshset->setProfileName(profileName);
			tk_hdrhshset->setReplicationOption(eReplicationOption);
			tk_hdrhshset->setDropOption(edropOption);
			tk_hdrhshset->setOdbcAttributes(odbcAttributes);
			tk_hdrhshset->setUpdateInterval(updateInterval);
			tk_hdrhshset->setCommitInterval(commitInterval);
			tk_hdrhshset->process(1);
		} break;
		case Rctables::enumTK_HDRLTPSET:
		{
			QScopedPointer<TK_HDRLTPSET> tk_hdrltpset(new TK_HDRLTPSET(nullptr));
			tk_hdrltpset->open(sourceDSN, targetDSN);
			tk_hdrltpset->setRepositoryString(envyRepositoryString);
			tk_hdrltpset->setProfileName(profileName);
			tk_hdrltpset->setReplicationOption(eReplicationOption);
			tk_hdrltpset->setDropOption(edropOption);
			tk_hdrltpset->setOdbcAttributes(odbcAttributes);
			tk_hdrltpset->setUpdateInterval(updateInterval);
			tk_hdrltpset->setCommitInterval(commitInterval);
			tk_hdrltpset->process(1);
		} break;
		case Rctables::enumTK_CNVHSHSET:
		{
			QScopedPointer<TK_CNVHSHSET> tk_cnvhshset(new TK_CNVHSHSET(nullptr));
			tk_cnvhshset->open(sourceDSN, targetDSN);
			tk_cnvhshset->setRepositoryString(envyRepositoryString);
			tk_cnvhshset->setProfileName(profileName);
			tk_cnvhshset->setReplicationOption(eReplicationOption);
			tk_cnvhshset->setDropOption(edropOption);
			tk_cnvhshset->setOdbcAttributes(odbcAttributes);
			tk_cnvhshset->setUpdateInterval(updateInterval);
			tk_cnvhshset->setCommitInterval(commitInterval);
			tk_cnvhshset->process(1);
		} break;
		case Rctables::enumTK_LTPHSHSET:
		{
			QScopedPointer<TK_LTPHSHSET> tk_ltphshset(new TK_LTPHSHSET(nullptr));
			tk_ltphshset->open(sourceDSN, targetDSN);
			tk_ltphshset->setRepositoryString(envyRepositoryString);
			tk_ltphshset->setProfileName(profileName);
			tk_ltphshset->setReplicationOption(eReplicationOption);
			tk_ltphshset->setDropOption(edropOption);
			tk_ltphshset->setOdbcAttributes(odbcAttributes);
			tk_ltphshset->setUpdateInterval(updateInterval);
			tk_ltphshset->setCommitInterval(commitInterval);
			tk_ltphshset->process(1);
		} break;
		case Rctables::enumTK_INTPOSRTSET:
		{
			QScopedPointer<TK_INTPOSRTSET> tk_intposrtset(new TK_INTPOSRTSET(nullptr));
			tk_intposrtset->open(sourceDSN, targetDSN);
			tk_intposrtset->setRepositoryString(envyRepositoryString);
			tk_intposrtset->setProfileName(profileName);
			tk_intposrtset->setReplicationOption(eReplicationOption);
			tk_intposrtset->setDropOption(edropOption);
			tk_intposrtset->setOdbcAttributes(odbcAttributes);
			tk_intposrtset->setUpdateInterval(updateInterval);
			tk_intposrtset->setCommitInterval(commitInterval);
			tk_intposrtset->process(1);
		} break;
		case Rctables::enumTK_UPRTHSHSET:
		{
			QScopedPointer<TK_UPRTHSHSET> tk_uprthshset(new TK_UPRTHSHSET(nullptr));
			tk_uprthshset->open(sourceDSN, targetDSN);
			tk_uprthshset->setRepositoryString(envyRepositoryString);
			tk_uprthshset->setProfileName(profileName);
			tk_uprthshset->setReplicationOption(eReplicationOption);
			tk_uprthshset->setDropOption(edropOption);
			tk_uprthshset->setOdbcAttributes(odbcAttributes);
			tk_uprthshset->setUpdateInterval(updateInterval);
			tk_uprthshset->setCommitInterval(commitInterval);
			tk_uprthshset->process(1);
		} break;
		case Rctables::enumTK_LIDNOTSET:
		{
			QScopedPointer<TK_LIDNOTSET> tk_lidnotset(new TK_LIDNOTSET(nullptr));
			tk_lidnotset->open(sourceDSN, targetDSN);
			tk_lidnotset->setRepositoryString(envyRepositoryString);
			tk_lidnotset->setProfileName(profileName);
			tk_lidnotset->setReplicationOption(eReplicationOption);
			tk_lidnotset->setDropOption(edropOption);
			tk_lidnotset->setOdbcAttributes(odbcAttributes);
			tk_lidnotset->setUpdateInterval(updateInterval);
			tk_lidnotset->setCommitInterval(commitInterval);
			tk_lidnotset->process(1);
		} break;
		case Rctables::enumTK_INTTOHSHSET:
		{
			QScopedPointer<TK_INTTOHSHSET> tk_inttohshset(new TK_INTTOHSHSET(nullptr));
			tk_inttohshset->open(sourceDSN, targetDSN);
			tk_inttohshset->setRepositoryString(envyRepositoryString);
			tk_inttohshset->setProfileName(profileName);
			tk_inttohshset->setReplicationOption(eReplicationOption);
			tk_inttohshset->setDropOption(edropOption);
			tk_inttohshset->setOdbcAttributes(odbcAttributes);
			tk_inttohshset->setUpdateInterval(updateInterval);
			tk_inttohshset->setCommitInterval(commitInterval);
			tk_inttohshset->process(1);
		} break;
		case Rctables::enumTK_FLGHSHSET:
		{
			QScopedPointer<TK_FLGHSHSET> tk_flghshset(new TK_FLGHSHSET(nullptr));
			tk_flghshset->open(sourceDSN, targetDSN);
			tk_flghshset->setRepositoryString(envyRepositoryString);
			tk_flghshset->setProfileName(profileName);
			tk_flghshset->setReplicationOption(eReplicationOption);
			tk_flghshset->setDropOption(edropOption);
			tk_flghshset->setOdbcAttributes(odbcAttributes);
			tk_flghshset->setUpdateInterval(updateInterval);
			tk_flghshset->setCommitInterval(commitInterval);
			tk_flghshset->process(1);
		} break;
		case Rctables::enumTK_INTCHNSET:
		{
			QScopedPointer<TK_INTCHNSET> tk_intchnset(new TK_INTCHNSET(nullptr));
			tk_intchnset->open(sourceDSN, targetDSN);
			tk_intchnset->setRepositoryString(envyRepositoryString);
			tk_intchnset->setProfileName(profileName);
			tk_intchnset->setReplicationOption(eReplicationOption);
			tk_intchnset->setDropOption(edropOption);
			tk_intchnset->setOdbcAttributes(odbcAttributes);
			tk_intchnset->setUpdateInterval(updateInterval);
			tk_intchnset->setCommitInterval(commitInterval);
			tk_intchnset->process(1);
		} break;
		case Rctables::enumTK_LOTREC:
		{
			QScopedPointer<TK_LOTREC> tk_lotrec(new TK_LOTREC(nullptr));
			tk_lotrec->open(sourceDSN, targetDSN);
			tk_lotrec->setRepositoryString(envyRepositoryString);
			tk_lotrec->setProfileName(profileName);
			tk_lotrec->setReplicationOption(eReplicationOption);
			tk_lotrec->setDropOption(edropOption);
			tk_lotrec->setOdbcAttributes(odbcAttributes);
			tk_lotrec->setUpdateInterval(updateInterval);
			tk_lotrec->setCommitInterval(commitInterval);
			tk_lotrec->process(1);
		} break;
		case Rctables::enumTK_TYPHDRSET:
		{
			QScopedPointer<TK_TYPHDRSET> tk_typhdrset(new TK_TYPHDRSET(nullptr));
			tk_typhdrset->open(sourceDSN, targetDSN);
			tk_typhdrset->setRepositoryString(envyRepositoryString);
			tk_typhdrset->setProfileName(profileName);
			tk_typhdrset->setReplicationOption(eReplicationOption);
			tk_typhdrset->setDropOption(edropOption);
			tk_typhdrset->setOdbcAttributes(odbcAttributes);
			tk_typhdrset->setUpdateInterval(updateInterval);
			tk_typhdrset->setCommitInterval(commitInterval);
			tk_typhdrset->process(1);
		} break;
		case Rctables::enumTK_PRCREC:
		{
			QScopedPointer<TK_PRCREC> tk_prcrec(new TK_PRCREC(nullptr));
			tk_prcrec->open(sourceDSN, targetDSN);
			tk_prcrec->setRepositoryString(envyRepositoryString);
			tk_prcrec->setProfileName(profileName);
			tk_prcrec->setReplicationOption(eReplicationOption);
			tk_prcrec->setDropOption(edropOption);
			tk_prcrec->setOdbcAttributes(odbcAttributes);
			tk_prcrec->setUpdateInterval(updateInterval);
			tk_prcrec->setCommitInterval(commitInterval);
			tk_prcrec->process(1);
		} break;
		case Rctables::enumTK_LOTHSHSET:
		{
			QScopedPointer<TK_LOTHSHSET> tk_lothshset(new TK_LOTHSHSET(nullptr));
			tk_lothshset->open(sourceDSN, targetDSN);
			tk_lothshset->setRepositoryString(envyRepositoryString);
			tk_lothshset->setProfileName(profileName);
			tk_lothshset->setReplicationOption(eReplicationOption);
			tk_lothshset->setDropOption(edropOption);
			tk_lothshset->setOdbcAttributes(odbcAttributes);
			tk_lothshset->setUpdateInterval(updateInterval);
			tk_lothshset->setCommitInterval(commitInterval);
			tk_lothshset->process(1);
		} break;
		case Rctables::enumTK_PRTLTFSET:
		{
			QScopedPointer<TK_PRTLTFSET> tk_prtltfset(new TK_PRTLTFSET(nullptr));
			tk_prtltfset->open(sourceDSN, targetDSN);
			tk_prtltfset->setRepositoryString(envyRepositoryString);
			tk_prtltfset->setProfileName(profileName);
			tk_prtltfset->setReplicationOption(eReplicationOption);
			tk_prtltfset->setDropOption(edropOption);
			tk_prtltfset->setOdbcAttributes(odbcAttributes);
			tk_prtltfset->setUpdateInterval(updateInterval);
			tk_prtltfset->setCommitInterval(commitInterval);
			tk_prtltfset->process(1);
		} break;
		case Rctables::enumTK_PRTREC:
		{
			QScopedPointer<TK_PRTREC> tk_prtrec(new TK_PRTREC(nullptr));
			tk_prtrec->open(sourceDSN, targetDSN);
			tk_prtrec->setRepositoryString(envyRepositoryString);
			tk_prtrec->setProfileName(profileName);
			tk_prtrec->setReplicationOption(eReplicationOption);
			tk_prtrec->setDropOption(edropOption);
			tk_prtrec->setOdbcAttributes(odbcAttributes);
			tk_prtrec->setUpdateInterval(updateInterval);
			tk_prtrec->setCommitInterval(commitInterval);
			tk_prtrec->process(1);
		} break;
		case Rctables::enumTK_UHSTCHNSET:
		{
			QScopedPointer<TK_UHSTCHNSET> tk_uhstchnset(new TK_UHSTCHNSET(nullptr));
			tk_uhstchnset->open(sourceDSN, targetDSN);
			tk_uhstchnset->setRepositoryString(envyRepositoryString);
			tk_uhstchnset->setProfileName(profileName);
			tk_uhstchnset->setReplicationOption(eReplicationOption);
			tk_uhstchnset->setDropOption(edropOption);
			tk_uhstchnset->setOdbcAttributes(odbcAttributes);
			tk_uhstchnset->setUpdateInterval(updateInterval);
			tk_uhstchnset->setCommitInterval(commitInterval);
			tk_uhstchnset->process(1);
		} break;
		case Rctables::enumTK_LOTLIDSET:
		{
			QScopedPointer<TK_LOTLIDSET> tk_lotlidset(new TK_LOTLIDSET(nullptr));
			tk_lotlidset->open(sourceDSN, targetDSN);
			tk_lotlidset->setRepositoryString(envyRepositoryString);
			tk_lotlidset->setProfileName(profileName);
			tk_lotlidset->setReplicationOption(eReplicationOption);
			tk_lotlidset->setDropOption(edropOption);
			tk_lotlidset->setOdbcAttributes(odbcAttributes);
			tk_lotlidset->setUpdateInterval(updateInterval);
			tk_lotlidset->setCommitInterval(commitInterval);
			tk_lotlidset->process(1);
		} break;
		case Rctables::enumTK_LTPREC:
		{
			QScopedPointer<TK_LTPREC> tk_ltprec(new TK_LTPREC(nullptr));
			tk_ltprec->open(sourceDSN, targetDSN);
			tk_ltprec->setRepositoryString(envyRepositoryString);
			tk_ltprec->setProfileName(profileName);
			tk_ltprec->setReplicationOption(eReplicationOption);
			tk_ltprec->setDropOption(edropOption);
			tk_ltprec->setOdbcAttributes(odbcAttributes);
			tk_ltprec->setUpdateInterval(updateInterval);
			tk_ltprec->setCommitInterval(commitInterval);
			tk_ltprec->process(1);
		} break;
		case Rctables::enumTK_TYPREC:
		{
			QScopedPointer<TK_TYPREC> tk_typrec(new TK_TYPREC(nullptr));
			tk_typrec->open(sourceDSN, targetDSN);
			tk_typrec->setRepositoryString(envyRepositoryString);
			tk_typrec->setProfileName(profileName);
			tk_typrec->setReplicationOption(eReplicationOption);
			tk_typrec->setDropOption(edropOption);
			tk_typrec->setOdbcAttributes(odbcAttributes);
			tk_typrec->setUpdateInterval(updateInterval);
			tk_typrec->setCommitInterval(commitInterval);
			tk_typrec->process(1);
		} break;
		case Rctables::enumTK_ULSTREC:
		{
			QScopedPointer<TK_ULSTREC> tk_ulstrec(new TK_ULSTREC(nullptr));
			tk_ulstrec->open(sourceDSN, targetDSN);
			tk_ulstrec->setRepositoryString(envyRepositoryString);
			tk_ulstrec->setProfileName(profileName);
			tk_ulstrec->setReplicationOption(eReplicationOption);
			tk_ulstrec->setDropOption(edropOption);
			tk_ulstrec->setOdbcAttributes(odbcAttributes);
			tk_ulstrec->setUpdateInterval(updateInterval);
			tk_ulstrec->setCommitInterval(commitInterval);
			tk_ulstrec->process(1);
		} break;
	}
#pragma endregion caselist
#endif caseList__h_TRKDB100
