/*H**********************************************************************
* FILENAME :        CaseList_MANDB100.h             DESIGN REF: 
*
* DESCRIPTION :
*       This file contains a case branch for each record that can be processed in the MANDB MANMAN R11
*        Rdb schema.
*
*    THIS FILE IS AN AUTO-GENERATED
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

#ifndef caseList__h_MANDB100
#define caseList__h_MANDB100

#pragma region caselist for MANDB100

	switch (ffx)
	{
		case Rctables::enumAP_VNDVENSET:
		{
			QScopedPointer<AP_VNDVENSET> ap_vndvenset(new AP_VNDVENSET(nullptr));
			ap_vndvenset->open(sourceDSN, targetDSN);
			ap_vndvenset->setRepositoryString(envyRepositoryString);
			ap_vndvenset->setProfileName(profileName);
			ap_vndvenset->setReplicationOption(eReplicationOption);
			ap_vndvenset->setDropOption(edropOption);
			ap_vndvenset->setOdbcAttributes(odbcAttributes);
			ap_vndvenset->setUpdateInterval(updateInterval);
			ap_vndvenset->setCommitInterval(commitInterval);
			ap_vndvenset->process(1);
		} break;
		case Rctables::enumMRHREC:
		{
			QScopedPointer<MRHREC> mrhrec(new MRHREC(nullptr));
			mrhrec->open(sourceDSN, targetDSN);
			mrhrec->setRepositoryString(envyRepositoryString);
			mrhrec->setProfileName(profileName);
			mrhrec->setReplicationOption(eReplicationOption);
			mrhrec->setDropOption(edropOption);
			mrhrec->setOdbcAttributes(odbcAttributes);
			mrhrec->setUpdateInterval(updateInterval);
			mrhrec->setCommitInterval(commitInterval);
			mrhrec->process(1);
		} break;
		case Rctables::enumGL_ACCTHSHSET:
		{
			QScopedPointer<GL_ACCTHSHSET> gl_accthshset(new GL_ACCTHSHSET(nullptr));
			gl_accthshset->open(sourceDSN, targetDSN);
			gl_accthshset->setRepositoryString(envyRepositoryString);
			gl_accthshset->setProfileName(profileName);
			gl_accthshset->setReplicationOption(eReplicationOption);
			gl_accthshset->setDropOption(edropOption);
			gl_accthshset->setOdbcAttributes(odbcAttributes);
			gl_accthshset->setUpdateInterval(updateInterval);
			gl_accthshset->setCommitInterval(commitInterval);
			gl_accthshset->process(1);
		} break;
		case Rctables::enumMA_BILSHPSET:
		{
			QScopedPointer<MA_BILSHPSET> ma_bilshpset(new MA_BILSHPSET(nullptr));
			ma_bilshpset->open(sourceDSN, targetDSN);
			ma_bilshpset->setRepositoryString(envyRepositoryString);
			ma_bilshpset->setProfileName(profileName);
			ma_bilshpset->setReplicationOption(eReplicationOption);
			ma_bilshpset->setDropOption(edropOption);
			ma_bilshpset->setOdbcAttributes(odbcAttributes);
			ma_bilshpset->setUpdateInterval(updateInterval);
			ma_bilshpset->setCommitInterval(commitInterval);
			ma_bilshpset->process(1);
		} break;
		case Rctables::enumFRTREC:
		{
			QScopedPointer<FRTREC> frtrec(new FRTREC(nullptr));
			frtrec->open(sourceDSN, targetDSN);
			frtrec->setRepositoryString(envyRepositoryString);
			frtrec->setProfileName(profileName);
			frtrec->setReplicationOption(eReplicationOption);
			frtrec->setDropOption(edropOption);
			frtrec->setOdbcAttributes(odbcAttributes);
			frtrec->setUpdateInterval(updateInterval);
			frtrec->setCommitInterval(commitInterval);
			frtrec->process(1);
		} break;
		case Rctables::enumWIPYLDSET:
		{
			QScopedPointer<WIPYLDSET> wipyldset(new WIPYLDSET(nullptr));
			wipyldset->open(sourceDSN, targetDSN);
			wipyldset->setRepositoryString(envyRepositoryString);
			wipyldset->setProfileName(profileName);
			wipyldset->setReplicationOption(eReplicationOption);
			wipyldset->setDropOption(edropOption);
			wipyldset->setOdbcAttributes(odbcAttributes);
			wipyldset->setUpdateInterval(updateInterval);
			wipyldset->setCommitInterval(commitInterval);
			wipyldset->process(1);
		} break;
		case Rctables::enumWKCREC:
		{
			QScopedPointer<WKCREC> wkcrec(new WKCREC(nullptr));
			wkcrec->open(sourceDSN, targetDSN);
			wkcrec->setRepositoryString(envyRepositoryString);
			wkcrec->setProfileName(profileName);
			wkcrec->setReplicationOption(eReplicationOption);
			wkcrec->setDropOption(edropOption);
			wkcrec->setOdbcAttributes(odbcAttributes);
			wkcrec->setUpdateInterval(updateInterval);
			wkcrec->setCommitInterval(commitInterval);
			wkcrec->process(1);
		} break;
		case Rctables::enumMA_SHPQUOHSET:
		{
			QScopedPointer<MA_SHPQUOHSET> ma_shpquohset(new MA_SHPQUOHSET(nullptr));
			ma_shpquohset->open(sourceDSN, targetDSN);
			ma_shpquohset->setRepositoryString(envyRepositoryString);
			ma_shpquohset->setProfileName(profileName);
			ma_shpquohset->setReplicationOption(eReplicationOption);
			ma_shpquohset->setDropOption(edropOption);
			ma_shpquohset->setOdbcAttributes(odbcAttributes);
			ma_shpquohset->setUpdateInterval(updateInterval);
			ma_shpquohset->setCommitInterval(commitInterval);
			ma_shpquohset->process(1);
		} break;
		case Rctables::enumMA_RSNCHGHSET:
		{
			QScopedPointer<MA_RSNCHGHSET> ma_rsnchghset(new MA_RSNCHGHSET(nullptr));
			ma_rsnchghset->open(sourceDSN, targetDSN);
			ma_rsnchghset->setRepositoryString(envyRepositoryString);
			ma_rsnchghset->setProfileName(profileName);
			ma_rsnchghset->setReplicationOption(eReplicationOption);
			ma_rsnchghset->setDropOption(edropOption);
			ma_rsnchghset->setOdbcAttributes(odbcAttributes);
			ma_rsnchghset->setUpdateInterval(updateInterval);
			ma_rsnchghset->setCommitInterval(commitInterval);
			ma_rsnchghset->process(1);
		} break;
		case Rctables::enumBOLOPENSET:
		{
			QScopedPointer<BOLOPENSET> bolopenset(new BOLOPENSET(nullptr));
			bolopenset->open(sourceDSN, targetDSN);
			bolopenset->setRepositoryString(envyRepositoryString);
			bolopenset->setProfileName(profileName);
			bolopenset->setReplicationOption(eReplicationOption);
			bolopenset->setDropOption(edropOption);
			bolopenset->setOdbcAttributes(odbcAttributes);
			bolopenset->setUpdateInterval(updateInterval);
			bolopenset->setCommitInterval(commitInterval);
			bolopenset->process(1);
		} break;
		case Rctables::enumAP_VATREC:
		{
			QScopedPointer<AP_VATREC> ap_vatrec(new AP_VATREC(nullptr));
			ap_vatrec->open(sourceDSN, targetDSN);
			ap_vatrec->setRepositoryString(envyRepositoryString);
			ap_vatrec->setProfileName(profileName);
			ap_vatrec->setReplicationOption(eReplicationOption);
			ap_vatrec->setDropOption(edropOption);
			ap_vatrec->setOdbcAttributes(odbcAttributes);
			ap_vatrec->setUpdateInterval(updateInterval);
			ap_vatrec->setCommitInterval(commitInterval);
			ap_vatrec->process(1);
		} break;
		case Rctables::enumMA_PFAMREC:
		{
			QScopedPointer<MA_PFAMREC> ma_pfamrec(new MA_PFAMREC(nullptr));
			ma_pfamrec->open(sourceDSN, targetDSN);
			ma_pfamrec->setRepositoryString(envyRepositoryString);
			ma_pfamrec->setProfileName(profileName);
			ma_pfamrec->setReplicationOption(eReplicationOption);
			ma_pfamrec->setDropOption(edropOption);
			ma_pfamrec->setOdbcAttributes(odbcAttributes);
			ma_pfamrec->setUpdateInterval(updateInterval);
			ma_pfamrec->setCommitInterval(commitInterval);
			ma_pfamrec->process(1);
		} break;
		case Rctables::enumFSCCALHSHSET:
		{
			QScopedPointer<FSCCALHSHSET> fsccalhshset(new FSCCALHSHSET(nullptr));
			fsccalhshset->open(sourceDSN, targetDSN);
			fsccalhshset->setRepositoryString(envyRepositoryString);
			fsccalhshset->setProfileName(profileName);
			fsccalhshset->setReplicationOption(eReplicationOption);
			fsccalhshset->setDropOption(edropOption);
			fsccalhshset->setOdbcAttributes(odbcAttributes);
			fsccalhshset->setUpdateInterval(updateInterval);
			fsccalhshset->setCommitInterval(commitInterval);
			fsccalhshset->process(1);
		} break;
		case Rctables::enumAP_DEFACCTSET:
		{
			QScopedPointer<AP_DEFACCTSET> ap_defacctset(new AP_DEFACCTSET(nullptr));
			ap_defacctset->open(sourceDSN, targetDSN);
			ap_defacctset->setRepositoryString(envyRepositoryString);
			ap_defacctset->setProfileName(profileName);
			ap_defacctset->setReplicationOption(eReplicationOption);
			ap_defacctset->setDropOption(edropOption);
			ap_defacctset->setOdbcAttributes(odbcAttributes);
			ap_defacctset->setUpdateInterval(updateInterval);
			ap_defacctset->setCommitInterval(commitInterval);
			ap_defacctset->process(1);
		} break;
		case Rctables::enumMA_BILPOSTSET:
		{
			QScopedPointer<MA_BILPOSTSET> ma_bilpostset(new MA_BILPOSTSET(nullptr));
			ma_bilpostset->open(sourceDSN, targetDSN);
			ma_bilpostset->setRepositoryString(envyRepositoryString);
			ma_bilpostset->setProfileName(profileName);
			ma_bilpostset->setReplicationOption(eReplicationOption);
			ma_bilpostset->setDropOption(edropOption);
			ma_bilpostset->setOdbcAttributes(odbcAttributes);
			ma_bilpostset->setUpdateInterval(updateInterval);
			ma_bilpostset->setCommitInterval(commitInterval);
			ma_bilpostset->process(1);
		} break;
		case Rctables::enumAP_HDRVNDSET:
		{
			QScopedPointer<AP_HDRVNDSET> ap_hdrvndset(new AP_HDRVNDSET(nullptr));
			ap_hdrvndset->open(sourceDSN, targetDSN);
			ap_hdrvndset->setRepositoryString(envyRepositoryString);
			ap_hdrvndset->setProfileName(profileName);
			ap_hdrvndset->setReplicationOption(eReplicationOption);
			ap_hdrvndset->setDropOption(edropOption);
			ap_hdrvndset->setOdbcAttributes(odbcAttributes);
			ap_hdrvndset->setUpdateInterval(updateInterval);
			ap_hdrvndset->setCommitInterval(commitInterval);
			ap_hdrvndset->process(1);
		} break;
		case Rctables::enumAP_SEARCHREC:
		{
			QScopedPointer<AP_SEARCHREC> ap_searchrec(new AP_SEARCHREC(nullptr));
			ap_searchrec->open(sourceDSN, targetDSN);
			ap_searchrec->setRepositoryString(envyRepositoryString);
			ap_searchrec->setProfileName(profileName);
			ap_searchrec->setReplicationOption(eReplicationOption);
			ap_searchrec->setDropOption(edropOption);
			ap_searchrec->setOdbcAttributes(odbcAttributes);
			ap_searchrec->setUpdateInterval(updateInterval);
			ap_searchrec->setCommitInterval(commitInterval);
			ap_searchrec->process(1);
		} break;
		case Rctables::enumMA_SHPSOHSET:
		{
			QScopedPointer<MA_SHPSOHSET> ma_shpsohset(new MA_SHPSOHSET(nullptr));
			ma_shpsohset->open(sourceDSN, targetDSN);
			ma_shpsohset->setRepositoryString(envyRepositoryString);
			ma_shpsohset->setProfileName(profileName);
			ma_shpsohset->setReplicationOption(eReplicationOption);
			ma_shpsohset->setDropOption(edropOption);
			ma_shpsohset->setOdbcAttributes(odbcAttributes);
			ma_shpsohset->setUpdateInterval(updateInterval);
			ma_shpsohset->setCommitInterval(commitInterval);
			ma_shpsohset->process(1);
		} break;
		case Rctables::enumDRVARSET:
		{
			QScopedPointer<DRVARSET> drvarset(new DRVARSET(nullptr));
			drvarset->open(sourceDSN, targetDSN);
			drvarset->setRepositoryString(envyRepositoryString);
			drvarset->setProfileName(profileName);
			drvarset->setReplicationOption(eReplicationOption);
			drvarset->setDropOption(edropOption);
			drvarset->setOdbcAttributes(odbcAttributes);
			drvarset->setUpdateInterval(updateInterval);
			drvarset->setCommitInterval(commitInterval);
			drvarset->process(1);
		} break;
		case Rctables::enumMA_COMCREC:
		{
			QScopedPointer<MA_COMCREC> ma_comcrec(new MA_COMCREC(nullptr));
			ma_comcrec->open(sourceDSN, targetDSN);
			ma_comcrec->setRepositoryString(envyRepositoryString);
			ma_comcrec->setProfileName(profileName);
			ma_comcrec->setReplicationOption(eReplicationOption);
			ma_comcrec->setDropOption(edropOption);
			ma_comcrec->setOdbcAttributes(odbcAttributes);
			ma_comcrec->setUpdateInterval(updateInterval);
			ma_comcrec->setCommitInterval(commitInterval);
			ma_comcrec->process(1);
		} break;
		case Rctables::enumMA_PRCTREC:
		{
			QScopedPointer<MA_PRCTREC> ma_prctrec(new MA_PRCTREC(nullptr));
			ma_prctrec->open(sourceDSN, targetDSN);
			ma_prctrec->setRepositoryString(envyRepositoryString);
			ma_prctrec->setProfileName(profileName);
			ma_prctrec->setReplicationOption(eReplicationOption);
			ma_prctrec->setDropOption(edropOption);
			ma_prctrec->setOdbcAttributes(odbcAttributes);
			ma_prctrec->setUpdateInterval(updateInterval);
			ma_prctrec->setCommitInterval(commitInterval);
			ma_prctrec->process(1);
		} break;
		case Rctables::enumMA_SODINDSET:
		{
			QScopedPointer<MA_SODINDSET> ma_sodindset(new MA_SODINDSET(nullptr));
			ma_sodindset->open(sourceDSN, targetDSN);
			ma_sodindset->setRepositoryString(envyRepositoryString);
			ma_sodindset->setProfileName(profileName);
			ma_sodindset->setReplicationOption(eReplicationOption);
			ma_sodindset->setDropOption(edropOption);
			ma_sodindset->setOdbcAttributes(odbcAttributes);
			ma_sodindset->setUpdateInterval(updateInterval);
			ma_sodindset->setCommitInterval(commitInterval);
			ma_sodindset->process(1);
		} break;
		case Rctables::enumMA_INHDMHSET:
		{
			QScopedPointer<MA_INHDMHSET> ma_inhdmhset(new MA_INHDMHSET(nullptr));
			ma_inhdmhset->open(sourceDSN, targetDSN);
			ma_inhdmhset->setRepositoryString(envyRepositoryString);
			ma_inhdmhset->setProfileName(profileName);
			ma_inhdmhset->setReplicationOption(eReplicationOption);
			ma_inhdmhset->setDropOption(edropOption);
			ma_inhdmhset->setOdbcAttributes(odbcAttributes);
			ma_inhdmhset->setUpdateInterval(updateInterval);
			ma_inhdmhset->setCommitInterval(commitInterval);
			ma_inhdmhset->process(1);
		} break;
		case Rctables::enumMA_STATEREC:
		{
			QScopedPointer<MA_STATEREC> ma_staterec(new MA_STATEREC(nullptr));
			ma_staterec->open(sourceDSN, targetDSN);
			ma_staterec->setRepositoryString(envyRepositoryString);
			ma_staterec->setProfileName(profileName);
			ma_staterec->setReplicationOption(eReplicationOption);
			ma_staterec->setDropOption(edropOption);
			ma_staterec->setOdbcAttributes(odbcAttributes);
			ma_staterec->setUpdateInterval(updateInterval);
			ma_staterec->setCommitInterval(commitInterval);
			ma_staterec->process(1);
		} break;
		case Rctables::enumPRTFORSET:
		{
			QScopedPointer<PRTFORSET> prtforset(new PRTFORSET(nullptr));
			prtforset->open(sourceDSN, targetDSN);
			prtforset->setRepositoryString(envyRepositoryString);
			prtforset->setProfileName(profileName);
			prtforset->setReplicationOption(eReplicationOption);
			prtforset->setDropOption(edropOption);
			prtforset->setOdbcAttributes(odbcAttributes);
			prtforset->setUpdateInterval(updateInterval);
			prtforset->setCommitInterval(commitInterval);
			prtforset->process(1);
		} break;
		case Rctables::enumMA_PRTTOPSET:
		{
			QScopedPointer<MA_PRTTOPSET> ma_prttopset(new MA_PRTTOPSET(nullptr));
			ma_prttopset->open(sourceDSN, targetDSN);
			ma_prttopset->setRepositoryString(envyRepositoryString);
			ma_prttopset->setProfileName(profileName);
			ma_prttopset->setReplicationOption(eReplicationOption);
			ma_prttopset->setDropOption(edropOption);
			ma_prttopset->setOdbcAttributes(odbcAttributes);
			ma_prttopset->setUpdateInterval(updateInterval);
			ma_prttopset->setCommitInterval(commitInterval);
			ma_prttopset->process(1);
		} break;
		case Rctables::enumPAYSET:
		{
			QScopedPointer<PAYSET> payset(new PAYSET(nullptr));
			payset->open(sourceDSN, targetDSN);
			payset->setRepositoryString(envyRepositoryString);
			payset->setProfileName(profileName);
			payset->setReplicationOption(eReplicationOption);
			payset->setDropOption(edropOption);
			payset->setOdbcAttributes(odbcAttributes);
			payset->setUpdateInterval(updateInterval);
			payset->setCommitInterval(commitInterval);
			payset->process(1);
		} break;
		case Rctables::enumWOHEALSET:
		{
			QScopedPointer<WOHEALSET> wohealset(new WOHEALSET(nullptr));
			wohealset->open(sourceDSN, targetDSN);
			wohealset->setRepositoryString(envyRepositoryString);
			wohealset->setProfileName(profileName);
			wohealset->setReplicationOption(eReplicationOption);
			wohealset->setDropOption(edropOption);
			wohealset->setOdbcAttributes(odbcAttributes);
			wohealset->setUpdateInterval(updateInterval);
			wohealset->setCommitInterval(commitInterval);
			wohealset->process(1);
		} break;
		case Rctables::enumMA_GLCTTABSET:
		{
			QScopedPointer<MA_GLCTTABSET> ma_glcttabset(new MA_GLCTTABSET(nullptr));
			ma_glcttabset->open(sourceDSN, targetDSN);
			ma_glcttabset->setRepositoryString(envyRepositoryString);
			ma_glcttabset->setProfileName(profileName);
			ma_glcttabset->setReplicationOption(eReplicationOption);
			ma_glcttabset->setDropOption(edropOption);
			ma_glcttabset->setOdbcAttributes(odbcAttributes);
			ma_glcttabset->setUpdateInterval(updateInterval);
			ma_glcttabset->setCommitInterval(commitInterval);
			ma_glcttabset->process(1);
		} break;
		case Rctables::enumAP_BATCHHSHSET:
		{
			QScopedPointer<AP_BATCHHSHSET> ap_batchhshset(new AP_BATCHHSHSET(nullptr));
			ap_batchhshset->open(sourceDSN, targetDSN);
			ap_batchhshset->setRepositoryString(envyRepositoryString);
			ap_batchhshset->setProfileName(profileName);
			ap_batchhshset->setReplicationOption(eReplicationOption);
			ap_batchhshset->setDropOption(edropOption);
			ap_batchhshset->setOdbcAttributes(odbcAttributes);
			ap_batchhshset->setUpdateInterval(updateInterval);
			ap_batchhshset->setCommitInterval(commitInterval);
			ap_batchhshset->process(1);
		} break;
		case Rctables::enumMA_PRPTPRODSET:
		{
			QScopedPointer<MA_PRPTPRODSET> ma_prptprodset(new MA_PRPTPRODSET(nullptr));
			ma_prptprodset->open(sourceDSN, targetDSN);
			ma_prptprodset->setRepositoryString(envyRepositoryString);
			ma_prptprodset->setProfileName(profileName);
			ma_prptprodset->setReplicationOption(eReplicationOption);
			ma_prptprodset->setDropOption(edropOption);
			ma_prptprodset->setOdbcAttributes(odbcAttributes);
			ma_prptprodset->setUpdateInterval(updateInterval);
			ma_prptprodset->setCommitInterval(commitInterval);
			ma_prptprodset->process(1);
		} break;
		case Rctables::enumAP_BNKVCHSET:
		{
			QScopedPointer<AP_BNKVCHSET> ap_bnkvchset(new AP_BNKVCHSET(nullptr));
			ap_bnkvchset->open(sourceDSN, targetDSN);
			ap_bnkvchset->setRepositoryString(envyRepositoryString);
			ap_bnkvchset->setProfileName(profileName);
			ap_bnkvchset->setReplicationOption(eReplicationOption);
			ap_bnkvchset->setDropOption(edropOption);
			ap_bnkvchset->setOdbcAttributes(odbcAttributes);
			ap_bnkvchset->setUpdateInterval(updateInterval);
			ap_bnkvchset->setCommitInterval(commitInterval);
			ap_bnkvchset->process(1);
		} break;
		case Rctables::enumMA_FRTHSHSET:
		{
			QScopedPointer<MA_FRTHSHSET> ma_frthshset(new MA_FRTHSHSET(nullptr));
			ma_frthshset->open(sourceDSN, targetDSN);
			ma_frthshset->setRepositoryString(envyRepositoryString);
			ma_frthshset->setProfileName(profileName);
			ma_frthshset->setReplicationOption(eReplicationOption);
			ma_frthshset->setDropOption(edropOption);
			ma_frthshset->setOdbcAttributes(odbcAttributes);
			ma_frthshset->setUpdateInterval(updateInterval);
			ma_frthshset->setCommitInterval(commitInterval);
			ma_frthshset->process(1);
		} break;
		case Rctables::enumMA_RSNCMHSET:
		{
			QScopedPointer<MA_RSNCMHSET> ma_rsncmhset(new MA_RSNCMHSET(nullptr));
			ma_rsncmhset->open(sourceDSN, targetDSN);
			ma_rsncmhset->setRepositoryString(envyRepositoryString);
			ma_rsncmhset->setProfileName(profileName);
			ma_rsncmhset->setReplicationOption(eReplicationOption);
			ma_rsncmhset->setDropOption(edropOption);
			ma_rsncmhset->setOdbcAttributes(odbcAttributes);
			ma_rsncmhset->setUpdateInterval(updateInterval);
			ma_rsncmhset->setCommitInterval(commitInterval);
			ma_rsncmhset->process(1);
		} break;
		case Rctables::enumPOHPRHSET:
		{
			QScopedPointer<POHPRHSET> pohprhset(new POHPRHSET(nullptr));
			pohprhset->open(sourceDSN, targetDSN);
			pohprhset->setRepositoryString(envyRepositoryString);
			pohprhset->setProfileName(profileName);
			pohprhset->setReplicationOption(eReplicationOption);
			pohprhset->setDropOption(edropOption);
			pohprhset->setOdbcAttributes(odbcAttributes);
			pohprhset->setUpdateInterval(updateInterval);
			pohprhset->setCommitInterval(commitInterval);
			pohprhset->process(1);
		} break;
		case Rctables::enumAP_VENHOLDSET:
		{
			QScopedPointer<AP_VENHOLDSET> ap_venholdset(new AP_VENHOLDSET(nullptr));
			ap_venholdset->open(sourceDSN, targetDSN);
			ap_venholdset->setRepositoryString(envyRepositoryString);
			ap_venholdset->setProfileName(profileName);
			ap_venholdset->setReplicationOption(eReplicationOption);
			ap_venholdset->setDropOption(edropOption);
			ap_venholdset->setOdbcAttributes(odbcAttributes);
			ap_venholdset->setUpdateInterval(updateInterval);
			ap_venholdset->setCommitInterval(commitInterval);
			ap_venholdset->process(1);
		} break;
		case Rctables::enumGL_FP_NREC:
		{
			QScopedPointer<GL_FP_NREC> gl_fp_nrec(new GL_FP_NREC(nullptr));
			gl_fp_nrec->open(sourceDSN, targetDSN);
			gl_fp_nrec->setRepositoryString(envyRepositoryString);
			gl_fp_nrec->setProfileName(profileName);
			gl_fp_nrec->setReplicationOption(eReplicationOption);
			gl_fp_nrec->setDropOption(edropOption);
			gl_fp_nrec->setOdbcAttributes(odbcAttributes);
			gl_fp_nrec->setUpdateInterval(updateInterval);
			gl_fp_nrec->setCommitInterval(commitInterval);
			gl_fp_nrec->process(1);
		} break;
		case Rctables::enumWARINTSET:
		{
			QScopedPointer<WARINTSET> warintset(new WARINTSET(nullptr));
			warintset->open(sourceDSN, targetDSN);
			warintset->setRepositoryString(envyRepositoryString);
			warintset->setProfileName(profileName);
			warintset->setReplicationOption(eReplicationOption);
			warintset->setDropOption(edropOption);
			warintset->setOdbcAttributes(odbcAttributes);
			warintset->setUpdateInterval(updateInterval);
			warintset->setCommitInterval(commitInterval);
			warintset->process(1);
		} break;
		case Rctables::enumGL_FPTOPCTSET:
		{
			QScopedPointer<GL_FPTOPCTSET> gl_fptopctset(new GL_FPTOPCTSET(nullptr));
			gl_fptopctset->open(sourceDSN, targetDSN);
			gl_fptopctset->setRepositoryString(envyRepositoryString);
			gl_fptopctset->setProfileName(profileName);
			gl_fptopctset->setReplicationOption(eReplicationOption);
			gl_fptopctset->setDropOption(edropOption);
			gl_fptopctset->setOdbcAttributes(odbcAttributes);
			gl_fptopctset->setUpdateInterval(updateInterval);
			gl_fptopctset->setCommitInterval(commitInterval);
			gl_fptopctset->process(1);
		} break;
		case Rctables::enumED_AUDREC:
		{
			QScopedPointer<ED_AUDREC> ed_audrec(new ED_AUDREC(nullptr));
			ed_audrec->open(sourceDSN, targetDSN);
			ed_audrec->setRepositoryString(envyRepositoryString);
			ed_audrec->setProfileName(profileName);
			ed_audrec->setReplicationOption(eReplicationOption);
			ed_audrec->setDropOption(edropOption);
			ed_audrec->setOdbcAttributes(odbcAttributes);
			ed_audrec->setUpdateInterval(updateInterval);
			ed_audrec->setCommitInterval(commitInterval);
			ed_audrec->process(1);
		} break;
		case Rctables::enumVENREC:
		{
			QScopedPointer<VENREC> venrec(new VENREC(nullptr));
			venrec->open(sourceDSN, targetDSN);
			venrec->setRepositoryString(envyRepositoryString);
			venrec->setProfileName(profileName);
			venrec->setReplicationOption(eReplicationOption);
			venrec->setDropOption(edropOption);
			venrec->setOdbcAttributes(odbcAttributes);
			venrec->setUpdateInterval(updateInterval);
			venrec->setCommitInterval(commitInterval);
			venrec->process(1);
		} break;
		case Rctables::enumMA_PRPTHSHSET:
		{
			QScopedPointer<MA_PRPTHSHSET> ma_prpthshset(new MA_PRPTHSHSET(nullptr));
			ma_prpthshset->open(sourceDSN, targetDSN);
			ma_prpthshset->setRepositoryString(envyRepositoryString);
			ma_prpthshset->setProfileName(profileName);
			ma_prpthshset->setReplicationOption(eReplicationOption);
			ma_prpthshset->setDropOption(edropOption);
			ma_prpthshset->setOdbcAttributes(odbcAttributes);
			ma_prpthshset->setUpdateInterval(updateInterval);
			ma_prpthshset->setCommitInterval(commitInterval);
			ma_prpthshset->process(1);
		} break;
		case Rctables::enumMA_SOHPBSET:
		{
			QScopedPointer<MA_SOHPBSET> ma_sohpbset(new MA_SOHPBSET(nullptr));
			ma_sohpbset->open(sourceDSN, targetDSN);
			ma_sohpbset->setRepositoryString(envyRepositoryString);
			ma_sohpbset->setProfileName(profileName);
			ma_sohpbset->setReplicationOption(eReplicationOption);
			ma_sohpbset->setDropOption(edropOption);
			ma_sohpbset->setOdbcAttributes(odbcAttributes);
			ma_sohpbset->setUpdateInterval(updateInterval);
			ma_sohpbset->setCommitInterval(commitInterval);
			ma_sohpbset->process(1);
		} break;
		case Rctables::enumGL_LINKREC:
		{
			QScopedPointer<GL_LINKREC> gl_linkrec(new GL_LINKREC(nullptr));
			gl_linkrec->open(sourceDSN, targetDSN);
			gl_linkrec->setRepositoryString(envyRepositoryString);
			gl_linkrec->setProfileName(profileName);
			gl_linkrec->setReplicationOption(eReplicationOption);
			gl_linkrec->setDropOption(edropOption);
			gl_linkrec->setOdbcAttributes(odbcAttributes);
			gl_linkrec->setUpdateInterval(updateInterval);
			gl_linkrec->setCommitInterval(commitInterval);
			gl_linkrec->process(1);
		} break;
		case Rctables::enumAP_RECNOTEREC:
		{
			QScopedPointer<AP_RECNOTEREC> ap_recnoterec(new AP_RECNOTEREC(nullptr));
			ap_recnoterec->open(sourceDSN, targetDSN);
			ap_recnoterec->setRepositoryString(envyRepositoryString);
			ap_recnoterec->setProfileName(profileName);
			ap_recnoterec->setReplicationOption(eReplicationOption);
			ap_recnoterec->setDropOption(edropOption);
			ap_recnoterec->setOdbcAttributes(odbcAttributes);
			ap_recnoterec->setUpdateInterval(updateInterval);
			ap_recnoterec->setCommitInterval(commitInterval);
			ap_recnoterec->process(1);
		} break;
		case Rctables::enumGL_BATCHSET:
		{
			QScopedPointer<GL_BATCHSET> gl_batchset(new GL_BATCHSET(nullptr));
			gl_batchset->open(sourceDSN, targetDSN);
			gl_batchset->setRepositoryString(envyRepositoryString);
			gl_batchset->setProfileName(profileName);
			gl_batchset->setReplicationOption(eReplicationOption);
			gl_batchset->setDropOption(edropOption);
			gl_batchset->setOdbcAttributes(odbcAttributes);
			gl_batchset->setUpdateInterval(updateInterval);
			gl_batchset->setCommitInterval(commitInterval);
			gl_batchset->process(1);
		} break;
		case Rctables::enumOPCREC:
		{
			QScopedPointer<OPCREC> opcrec(new OPCREC(nullptr));
			opcrec->open(sourceDSN, targetDSN);
			opcrec->setRepositoryString(envyRepositoryString);
			opcrec->setProfileName(profileName);
			opcrec->setReplicationOption(eReplicationOption);
			opcrec->setDropOption(edropOption);
			opcrec->setOdbcAttributes(odbcAttributes);
			opcrec->setUpdateInterval(updateInterval);
			opcrec->setCommitInterval(commitInterval);
			opcrec->process(1);
		} break;
		case Rctables::enumAP_VNDCHKSET:
		{
			QScopedPointer<AP_VNDCHKSET> ap_vndchkset(new AP_VNDCHKSET(nullptr));
			ap_vndchkset->open(sourceDSN, targetDSN);
			ap_vndchkset->setRepositoryString(envyRepositoryString);
			ap_vndchkset->setProfileName(profileName);
			ap_vndchkset->setReplicationOption(eReplicationOption);
			ap_vndchkset->setDropOption(edropOption);
			ap_vndchkset->setOdbcAttributes(odbcAttributes);
			ap_vndchkset->setUpdateInterval(updateInterval);
			ap_vndchkset->setCommitInterval(commitInterval);
			ap_vndchkset->process(1);
		} break;
		case Rctables::enumPOMREC:
		{
			QScopedPointer<POMREC> pomrec(new POMREC(nullptr));
			pomrec->open(sourceDSN, targetDSN);
			pomrec->setRepositoryString(envyRepositoryString);
			pomrec->setProfileName(profileName);
			pomrec->setReplicationOption(eReplicationOption);
			pomrec->setDropOption(edropOption);
			pomrec->setOdbcAttributes(odbcAttributes);
			pomrec->setUpdateInterval(updateInterval);
			pomrec->setCommitInterval(commitInterval);
			pomrec->process(1);
		} break;
		case Rctables::enumGL_VPDEN_DREC:
		{
			QScopedPointer<GL_VPDEN_DREC> gl_vpden_drec(new GL_VPDEN_DREC(nullptr));
			gl_vpden_drec->open(sourceDSN, targetDSN);
			gl_vpden_drec->setRepositoryString(envyRepositoryString);
			gl_vpden_drec->setProfileName(profileName);
			gl_vpden_drec->setReplicationOption(eReplicationOption);
			gl_vpden_drec->setDropOption(edropOption);
			gl_vpden_drec->setOdbcAttributes(odbcAttributes);
			gl_vpden_drec->setUpdateInterval(updateInterval);
			gl_vpden_drec->setCommitInterval(commitInterval);
			gl_vpden_drec->process(1);
		} break;
		case Rctables::enumWOHREC:
		{
			QScopedPointer<WOHREC> wohrec(new WOHREC(nullptr));
			wohrec->open(sourceDSN, targetDSN);
			wohrec->setRepositoryString(envyRepositoryString);
			wohrec->setProfileName(profileName);
			wohrec->setReplicationOption(eReplicationOption);
			wohrec->setDropOption(edropOption);
			wohrec->setOdbcAttributes(odbcAttributes);
			wohrec->setUpdateInterval(updateInterval);
			wohrec->setCommitInterval(commitInterval);
			wohrec->process(1);
		} break;
		case Rctables::enumGL_PRPT_NREC:
		{
			QScopedPointer<GL_PRPT_NREC> gl_prpt_nrec(new GL_PRPT_NREC(nullptr));
			gl_prpt_nrec->open(sourceDSN, targetDSN);
			gl_prpt_nrec->setRepositoryString(envyRepositoryString);
			gl_prpt_nrec->setProfileName(profileName);
			gl_prpt_nrec->setReplicationOption(eReplicationOption);
			gl_prpt_nrec->setDropOption(edropOption);
			gl_prpt_nrec->setOdbcAttributes(odbcAttributes);
			gl_prpt_nrec->setUpdateInterval(updateInterval);
			gl_prpt_nrec->setCommitInterval(commitInterval);
			gl_prpt_nrec->process(1);
		} break;
		case Rctables::enumMA_PNOTHSHSET:
		{
			QScopedPointer<MA_PNOTHSHSET> ma_pnothshset(new MA_PNOTHSHSET(nullptr));
			ma_pnothshset->open(sourceDSN, targetDSN);
			ma_pnothshset->setRepositoryString(envyRepositoryString);
			ma_pnothshset->setProfileName(profileName);
			ma_pnothshset->setReplicationOption(eReplicationOption);
			ma_pnothshset->setDropOption(edropOption);
			ma_pnothshset->setOdbcAttributes(odbcAttributes);
			ma_pnothshset->setUpdateInterval(updateInterval);
			ma_pnothshset->setCommitInterval(commitInterval);
			ma_pnothshset->process(1);
		} break;
		case Rctables::enumGL_FPTOACCTSET:
		{
			QScopedPointer<GL_FPTOACCTSET> gl_fptoacctset(new GL_FPTOACCTSET(nullptr));
			gl_fptoacctset->open(sourceDSN, targetDSN);
			gl_fptoacctset->setRepositoryString(envyRepositoryString);
			gl_fptoacctset->setProfileName(profileName);
			gl_fptoacctset->setReplicationOption(eReplicationOption);
			gl_fptoacctset->setDropOption(edropOption);
			gl_fptoacctset->setOdbcAttributes(odbcAttributes);
			gl_fptoacctset->setUpdateInterval(updateInterval);
			gl_fptoacctset->setCommitInterval(commitInterval);
			gl_fptoacctset->process(1);
		} break;
		case Rctables::enumWIPEFFSET:
		{
			QScopedPointer<WIPEFFSET> wipeffset(new WIPEFFSET(nullptr));
			wipeffset->open(sourceDSN, targetDSN);
			wipeffset->setRepositoryString(envyRepositoryString);
			wipeffset->setProfileName(profileName);
			wipeffset->setReplicationOption(eReplicationOption);
			wipeffset->setDropOption(edropOption);
			wipeffset->setOdbcAttributes(odbcAttributes);
			wipeffset->setUpdateInterval(updateInterval);
			wipeffset->setCommitInterval(commitInterval);
			wipeffset->process(1);
		} break;
		case Rctables::enumGL_ISBSHSHSET:
		{
			QScopedPointer<GL_ISBSHSHSET> gl_isbshshset(new GL_ISBSHSHSET(nullptr));
			gl_isbshshset->open(sourceDSN, targetDSN);
			gl_isbshshset->setRepositoryString(envyRepositoryString);
			gl_isbshshset->setProfileName(profileName);
			gl_isbshshset->setReplicationOption(eReplicationOption);
			gl_isbshshset->setDropOption(edropOption);
			gl_isbshshset->setOdbcAttributes(odbcAttributes);
			gl_isbshshset->setUpdateInterval(updateInterval);
			gl_isbshshset->setCommitInterval(commitInterval);
			gl_isbshshset->process(1);
		} break;
		case Rctables::enumAP_POPSET:
		{
			QScopedPointer<AP_POPSET> ap_popset(new AP_POPSET(nullptr));
			ap_popset->open(sourceDSN, targetDSN);
			ap_popset->setRepositoryString(envyRepositoryString);
			ap_popset->setProfileName(profileName);
			ap_popset->setReplicationOption(eReplicationOption);
			ap_popset->setDropOption(edropOption);
			ap_popset->setOdbcAttributes(odbcAttributes);
			ap_popset->setUpdateInterval(updateInterval);
			ap_popset->setCommitInterval(commitInterval);
			ap_popset->process(1);
		} break;
		case Rctables::enumMA_FCPRTABREC:
		{
			QScopedPointer<MA_FCPRTABREC> ma_fcprtabrec(new MA_FCPRTABREC(nullptr));
			ma_fcprtabrec->open(sourceDSN, targetDSN);
			ma_fcprtabrec->setRepositoryString(envyRepositoryString);
			ma_fcprtabrec->setProfileName(profileName);
			ma_fcprtabrec->setReplicationOption(eReplicationOption);
			ma_fcprtabrec->setDropOption(edropOption);
			ma_fcprtabrec->setOdbcAttributes(odbcAttributes);
			ma_fcprtabrec->setUpdateInterval(updateInterval);
			ma_fcprtabrec->setCommitInterval(commitInterval);
			ma_fcprtabrec->process(1);
		} break;
		case Rctables::enumMA_QUOHSPISET:
		{
			QScopedPointer<MA_QUOHSPISET> ma_quohspiset(new MA_QUOHSPISET(nullptr));
			ma_quohspiset->open(sourceDSN, targetDSN);
			ma_quohspiset->setRepositoryString(envyRepositoryString);
			ma_quohspiset->setProfileName(profileName);
			ma_quohspiset->setReplicationOption(eReplicationOption);
			ma_quohspiset->setDropOption(edropOption);
			ma_quohspiset->setOdbcAttributes(odbcAttributes);
			ma_quohspiset->setUpdateInterval(updateInterval);
			ma_quohspiset->setCommitInterval(commitInterval);
			ma_quohspiset->process(1);
		} break;
		case Rctables::enumMA_SOCATREC:
		{
			QScopedPointer<MA_SOCATREC> ma_socatrec(new MA_SOCATREC(nullptr));
			ma_socatrec->open(sourceDSN, targetDSN);
			ma_socatrec->setRepositoryString(envyRepositoryString);
			ma_socatrec->setProfileName(profileName);
			ma_socatrec->setReplicationOption(eReplicationOption);
			ma_socatrec->setDropOption(edropOption);
			ma_socatrec->setOdbcAttributes(odbcAttributes);
			ma_socatrec->setUpdateInterval(updateInterval);
			ma_socatrec->setCommitInterval(commitInterval);
			ma_socatrec->process(1);
		} break;
		case Rctables::enumAP_VENVCHSET:
		{
			QScopedPointer<AP_VENVCHSET> ap_venvchset(new AP_VENVCHSET(nullptr));
			ap_venvchset->open(sourceDSN, targetDSN);
			ap_venvchset->setRepositoryString(envyRepositoryString);
			ap_venvchset->setProfileName(profileName);
			ap_venvchset->setReplicationOption(eReplicationOption);
			ap_venvchset->setDropOption(edropOption);
			ap_venvchset->setOdbcAttributes(odbcAttributes);
			ap_venvchset->setUpdateInterval(updateInterval);
			ap_venvchset->setCommitInterval(commitInterval);
			ap_venvchset->process(1);
		} break;
		case Rctables::enumINDFHSHSET:
		{
			QScopedPointer<INDFHSHSET> indfhshset(new INDFHSHSET(nullptr));
			indfhshset->open(sourceDSN, targetDSN);
			indfhshset->setRepositoryString(envyRepositoryString);
			indfhshset->setProfileName(profileName);
			indfhshset->setReplicationOption(eReplicationOption);
			indfhshset->setDropOption(edropOption);
			indfhshset->setOdbcAttributes(odbcAttributes);
			indfhshset->setUpdateInterval(updateInterval);
			indfhshset->setCommitInterval(commitInterval);
			indfhshset->process(1);
		} break;
		case Rctables::enumGL_REAMTSET:
		{
			QScopedPointer<GL_REAMTSET> gl_reamtset(new GL_REAMTSET(nullptr));
			gl_reamtset->open(sourceDSN, targetDSN);
			gl_reamtset->setRepositoryString(envyRepositoryString);
			gl_reamtset->setProfileName(profileName);
			gl_reamtset->setReplicationOption(eReplicationOption);
			gl_reamtset->setDropOption(edropOption);
			gl_reamtset->setOdbcAttributes(odbcAttributes);
			gl_reamtset->setUpdateInterval(updateInterval);
			gl_reamtset->setCommitInterval(commitInterval);
			gl_reamtset->process(1);
		} break;
		case Rctables::enumRQHRQDSET:
		{
			QScopedPointer<RQHRQDSET> rqhrqdset(new RQHRQDSET(nullptr));
			rqhrqdset->open(sourceDSN, targetDSN);
			rqhrqdset->setRepositoryString(envyRepositoryString);
			rqhrqdset->setProfileName(profileName);
			rqhrqdset->setReplicationOption(eReplicationOption);
			rqhrqdset->setDropOption(edropOption);
			rqhrqdset->setOdbcAttributes(odbcAttributes);
			rqhrqdset->setUpdateInterval(updateInterval);
			rqhrqdset->setCommitInterval(commitInterval);
			rqhrqdset->process(1);
		} break;
		case Rctables::enumGL_ARPT_DREC:
		{
			QScopedPointer<GL_ARPT_DREC> gl_arpt_drec(new GL_ARPT_DREC(nullptr));
			gl_arpt_drec->open(sourceDSN, targetDSN);
			gl_arpt_drec->setRepositoryString(envyRepositoryString);
			gl_arpt_drec->setProfileName(profileName);
			gl_arpt_drec->setReplicationOption(eReplicationOption);
			gl_arpt_drec->setDropOption(edropOption);
			gl_arpt_drec->setOdbcAttributes(odbcAttributes);
			gl_arpt_drec->setUpdateInterval(updateInterval);
			gl_arpt_drec->setCommitInterval(commitInterval);
			gl_arpt_drec->process(1);
		} break;
		case Rctables::enumMA_INHAPCPOSTSET:
		{
			QScopedPointer<MA_INHAPCPOSTSET> ma_inhapcpostset(new MA_INHAPCPOSTSET(nullptr));
			ma_inhapcpostset->open(sourceDSN, targetDSN);
			ma_inhapcpostset->setRepositoryString(envyRepositoryString);
			ma_inhapcpostset->setProfileName(profileName);
			ma_inhapcpostset->setReplicationOption(eReplicationOption);
			ma_inhapcpostset->setDropOption(edropOption);
			ma_inhapcpostset->setOdbcAttributes(odbcAttributes);
			ma_inhapcpostset->setUpdateInterval(updateInterval);
			ma_inhapcpostset->setCommitInterval(commitInterval);
			ma_inhapcpostset->process(1);
		} break;
		case Rctables::enumMA_COMOREC:
		{
			QScopedPointer<MA_COMOREC> ma_comorec(new MA_COMOREC(nullptr));
			ma_comorec->open(sourceDSN, targetDSN);
			ma_comorec->setRepositoryString(envyRepositoryString);
			ma_comorec->setProfileName(profileName);
			ma_comorec->setReplicationOption(eReplicationOption);
			ma_comorec->setDropOption(edropOption);
			ma_comorec->setOdbcAttributes(odbcAttributes);
			ma_comorec->setUpdateInterval(updateInterval);
			ma_comorec->setCommitInterval(commitInterval);
			ma_comorec->process(1);
		} break;
		case Rctables::enumAP_VNDHSHSET:
		{
			QScopedPointer<AP_VNDHSHSET> ap_vndhshset(new AP_VNDHSHSET(nullptr));
			ap_vndhshset->open(sourceDSN, targetDSN);
			ap_vndhshset->setRepositoryString(envyRepositoryString);
			ap_vndhshset->setProfileName(profileName);
			ap_vndhshset->setReplicationOption(eReplicationOption);
			ap_vndhshset->setDropOption(edropOption);
			ap_vndhshset->setOdbcAttributes(odbcAttributes);
			ap_vndhshset->setUpdateInterval(updateInterval);
			ap_vndhshset->setCommitInterval(commitInterval);
			ap_vndhshset->process(1);
		} break;
		case Rctables::enumCRVARSET:
		{
			QScopedPointer<CRVARSET> crvarset(new CRVARSET(nullptr));
			crvarset->open(sourceDSN, targetDSN);
			crvarset->setRepositoryString(envyRepositoryString);
			crvarset->setProfileName(profileName);
			crvarset->setReplicationOption(eReplicationOption);
			crvarset->setDropOption(edropOption);
			crvarset->setOdbcAttributes(odbcAttributes);
			crvarset->setUpdateInterval(updateInterval);
			crvarset->setCommitInterval(commitInterval);
			crvarset->process(1);
		} break;
		case Rctables::enumMA_PRCTFCPRTABSET:
		{
			QScopedPointer<MA_PRCTFCPRTABSET> ma_prctfcprtabset(new MA_PRCTFCPRTABSET(nullptr));
			ma_prctfcprtabset->open(sourceDSN, targetDSN);
			ma_prctfcprtabset->setRepositoryString(envyRepositoryString);
			ma_prctfcprtabset->setProfileName(profileName);
			ma_prctfcprtabset->setReplicationOption(eReplicationOption);
			ma_prctfcprtabset->setDropOption(edropOption);
			ma_prctfcprtabset->setOdbcAttributes(odbcAttributes);
			ma_prctfcprtabset->setUpdateInterval(updateInterval);
			ma_prctfcprtabset->setCommitInterval(commitInterval);
			ma_prctfcprtabset->process(1);
		} break;
		case Rctables::enumWOHHSHSET:
		{
			QScopedPointer<WOHHSHSET> wohhshset(new WOHHSHSET(nullptr));
			wohhshset->open(sourceDSN, targetDSN);
			wohhshset->setRepositoryString(envyRepositoryString);
			wohhshset->setProfileName(profileName);
			wohhshset->setReplicationOption(eReplicationOption);
			wohhshset->setDropOption(edropOption);
			wohhshset->setOdbcAttributes(odbcAttributes);
			wohhshset->setUpdateInterval(updateInterval);
			wohhshset->setCommitInterval(commitInterval);
			wohhshset->process(1);
		} break;
		case Rctables::enumMA_INDSPNLSET:
		{
			QScopedPointer<MA_INDSPNLSET> ma_indspnlset(new MA_INDSPNLSET(nullptr));
			ma_indspnlset->open(sourceDSN, targetDSN);
			ma_indspnlset->setRepositoryString(envyRepositoryString);
			ma_indspnlset->setProfileName(profileName);
			ma_indspnlset->setReplicationOption(eReplicationOption);
			ma_indspnlset->setDropOption(edropOption);
			ma_indspnlset->setOdbcAttributes(odbcAttributes);
			ma_indspnlset->setUpdateInterval(updateInterval);
			ma_indspnlset->setCommitInterval(commitInterval);
			ma_indspnlset->process(1);
		} break;
		case Rctables::enumPODIRCTSET:
		{
			QScopedPointer<PODIRCTSET> podirctset(new PODIRCTSET(nullptr));
			podirctset->open(sourceDSN, targetDSN);
			podirctset->setRepositoryString(envyRepositoryString);
			podirctset->setProfileName(profileName);
			podirctset->setReplicationOption(eReplicationOption);
			podirctset->setDropOption(edropOption);
			podirctset->setOdbcAttributes(odbcAttributes);
			podirctset->setUpdateInterval(updateInterval);
			podirctset->setCommitInterval(commitInterval);
			podirctset->process(1);
		} break;
		case Rctables::enumMA_BILFCPRTABSET:
		{
			QScopedPointer<MA_BILFCPRTABSET> ma_bilfcprtabset(new MA_BILFCPRTABSET(nullptr));
			ma_bilfcprtabset->open(sourceDSN, targetDSN);
			ma_bilfcprtabset->setRepositoryString(envyRepositoryString);
			ma_bilfcprtabset->setProfileName(profileName);
			ma_bilfcprtabset->setReplicationOption(eReplicationOption);
			ma_bilfcprtabset->setDropOption(edropOption);
			ma_bilfcprtabset->setOdbcAttributes(odbcAttributes);
			ma_bilfcprtabset->setUpdateInterval(updateInterval);
			ma_bilfcprtabset->setCommitInterval(commitInterval);
			ma_bilfcprtabset->process(1);
		} break;
		case Rctables::enumSOHREC:
		{
			QScopedPointer<SOHREC> sohrec(new SOHREC(nullptr));
			sohrec->open(sourceDSN, targetDSN);
			sohrec->setRepositoryString(envyRepositoryString);
			sohrec->setProfileName(profileName);
			sohrec->setReplicationOption(eReplicationOption);
			sohrec->setDropOption(edropOption);
			sohrec->setOdbcAttributes(odbcAttributes);
			sohrec->setUpdateInterval(updateInterval);
			sohrec->setCommitInterval(commitInterval);
			sohrec->process(1);
		} break;
		case Rctables::enumAP_BCHVCHSET:
		{
			QScopedPointer<AP_BCHVCHSET> ap_bchvchset(new AP_BCHVCHSET(nullptr));
			ap_bchvchset->open(sourceDSN, targetDSN);
			ap_bchvchset->setRepositoryString(envyRepositoryString);
			ap_bchvchset->setProfileName(profileName);
			ap_bchvchset->setReplicationOption(eReplicationOption);
			ap_bchvchset->setDropOption(edropOption);
			ap_bchvchset->setOdbcAttributes(odbcAttributes);
			ap_bchvchset->setUpdateInterval(updateInterval);
			ap_bchvchset->setCommitInterval(commitInterval);
			ap_bchvchset->process(1);
		} break;
		case Rctables::enumACTHSHSET:
		{
			QScopedPointer<ACTHSHSET> acthshset(new ACTHSHSET(nullptr));
			acthshset->open(sourceDSN, targetDSN);
			acthshset->setRepositoryString(envyRepositoryString);
			acthshset->setProfileName(profileName);
			acthshset->setReplicationOption(eReplicationOption);
			acthshset->setDropOption(edropOption);
			acthshset->setOdbcAttributes(odbcAttributes);
			acthshset->setUpdateInterval(updateInterval);
			acthshset->setCommitInterval(commitInterval);
			acthshset->process(1);
		} break;
		case Rctables::enumAP_HDRREC:
		{
			QScopedPointer<AP_HDRREC> ap_hdrrec(new AP_HDRREC(nullptr));
			ap_hdrrec->open(sourceDSN, targetDSN);
			ap_hdrrec->setRepositoryString(envyRepositoryString);
			ap_hdrrec->setProfileName(profileName);
			ap_hdrrec->setReplicationOption(eReplicationOption);
			ap_hdrrec->setDropOption(edropOption);
			ap_hdrrec->setOdbcAttributes(odbcAttributes);
			ap_hdrrec->setUpdateInterval(updateInterval);
			ap_hdrrec->setCommitInterval(commitInterval);
			ap_hdrrec->process(1);
		} break;
		case Rctables::enumGL_VPDESCSET:
		{
			QScopedPointer<GL_VPDESCSET> gl_vpdescset(new GL_VPDESCSET(nullptr));
			gl_vpdescset->open(sourceDSN, targetDSN);
			gl_vpdescset->setRepositoryString(envyRepositoryString);
			gl_vpdescset->setProfileName(profileName);
			gl_vpdescset->setReplicationOption(eReplicationOption);
			gl_vpdescset->setDropOption(edropOption);
			gl_vpdescset->setOdbcAttributes(odbcAttributes);
			gl_vpdescset->setUpdateInterval(updateInterval);
			gl_vpdescset->setCommitInterval(commitInterval);
			gl_vpdescset->process(1);
		} break;
		case Rctables::enumPRTIRCTSET:
		{
			QScopedPointer<PRTIRCTSET> prtirctset(new PRTIRCTSET(nullptr));
			prtirctset->open(sourceDSN, targetDSN);
			prtirctset->setRepositoryString(envyRepositoryString);
			prtirctset->setProfileName(profileName);
			prtirctset->setReplicationOption(eReplicationOption);
			prtirctset->setDropOption(edropOption);
			prtirctset->setOdbcAttributes(odbcAttributes);
			prtirctset->setUpdateInterval(updateInterval);
			prtirctset->setCommitInterval(commitInterval);
			prtirctset->process(1);
		} break;
		case Rctables::enumGENPRTSET:
		{
			QScopedPointer<GENPRTSET> genprtset(new GENPRTSET(nullptr));
			genprtset->open(sourceDSN, targetDSN);
			genprtset->setRepositoryString(envyRepositoryString);
			genprtset->setProfileName(profileName);
			genprtset->setReplicationOption(eReplicationOption);
			genprtset->setDropOption(edropOption);
			genprtset->setOdbcAttributes(odbcAttributes);
			genprtset->setUpdateInterval(updateInterval);
			genprtset->setCommitInterval(commitInterval);
			genprtset->process(1);
		} break;
		case Rctables::enumWARLOCSET:
		{
			QScopedPointer<WARLOCSET> warlocset(new WARLOCSET(nullptr));
			warlocset->open(sourceDSN, targetDSN);
			warlocset->setRepositoryString(envyRepositoryString);
			warlocset->setProfileName(profileName);
			warlocset->setReplicationOption(eReplicationOption);
			warlocset->setDropOption(edropOption);
			warlocset->setOdbcAttributes(odbcAttributes);
			warlocset->setUpdateInterval(updateInterval);
			warlocset->setCommitInterval(commitInterval);
			warlocset->process(1);
		} break;
		case Rctables::enumRTDREC:
		{
			QScopedPointer<RTDREC> rtdrec(new RTDREC(nullptr));
			rtdrec->open(sourceDSN, targetDSN);
			rtdrec->setRepositoryString(envyRepositoryString);
			rtdrec->setProfileName(profileName);
			rtdrec->setReplicationOption(eReplicationOption);
			rtdrec->setDropOption(edropOption);
			rtdrec->setOdbcAttributes(odbcAttributes);
			rtdrec->setUpdateInterval(updateInterval);
			rtdrec->setCommitInterval(commitInterval);
			rtdrec->process(1);
		} break;
		case Rctables::enumMA_DMHDMHLSET:
		{
			QScopedPointer<MA_DMHDMHLSET> ma_dmhdmhlset(new MA_DMHDMHLSET(nullptr));
			ma_dmhdmhlset->open(sourceDSN, targetDSN);
			ma_dmhdmhlset->setRepositoryString(envyRepositoryString);
			ma_dmhdmhlset->setProfileName(profileName);
			ma_dmhdmhlset->setReplicationOption(eReplicationOption);
			ma_dmhdmhlset->setDropOption(edropOption);
			ma_dmhdmhlset->setOdbcAttributes(odbcAttributes);
			ma_dmhdmhlset->setUpdateInterval(updateInterval);
			ma_dmhdmhlset->setCommitInterval(commitInterval);
			ma_dmhdmhlset->process(1);
		} break;
		case Rctables::enumAP_RECPAYCHNSET:
		{
			QScopedPointer<AP_RECPAYCHNSET> ap_recpaychnset(new AP_RECPAYCHNSET(nullptr));
			ap_recpaychnset->open(sourceDSN, targetDSN);
			ap_recpaychnset->setRepositoryString(envyRepositoryString);
			ap_recpaychnset->setProfileName(profileName);
			ap_recpaychnset->setReplicationOption(eReplicationOption);
			ap_recpaychnset->setDropOption(edropOption);
			ap_recpaychnset->setOdbcAttributes(odbcAttributes);
			ap_recpaychnset->setUpdateInterval(updateInterval);
			ap_recpaychnset->setCommitInterval(commitInterval);
			ap_recpaychnset->process(1);
		} break;
		case Rctables::enumIRCTSET:
		{
			QScopedPointer<IRCTSET> irctset(new IRCTSET(nullptr));
			irctset->open(sourceDSN, targetDSN);
			irctset->setRepositoryString(envyRepositoryString);
			irctset->setProfileName(profileName);
			irctset->setReplicationOption(eReplicationOption);
			irctset->setDropOption(edropOption);
			irctset->setOdbcAttributes(odbcAttributes);
			irctset->setUpdateInterval(updateInterval);
			irctset->setCommitInterval(commitInterval);
			irctset->process(1);
		} break;
		case Rctables::enumGL_PROJRPTSET:
		{
			QScopedPointer<GL_PROJRPTSET> gl_projrptset(new GL_PROJRPTSET(nullptr));
			gl_projrptset->open(sourceDSN, targetDSN);
			gl_projrptset->setRepositoryString(envyRepositoryString);
			gl_projrptset->setProfileName(profileName);
			gl_projrptset->setReplicationOption(eReplicationOption);
			gl_projrptset->setDropOption(edropOption);
			gl_projrptset->setOdbcAttributes(odbcAttributes);
			gl_projrptset->setUpdateInterval(updateInterval);
			gl_projrptset->setCommitInterval(commitInterval);
			gl_projrptset->process(1);
		} break;
		case Rctables::enumAP_RECPOSTREC:
		{
			QScopedPointer<AP_RECPOSTREC> ap_recpostrec(new AP_RECPOSTREC(nullptr));
			ap_recpostrec->open(sourceDSN, targetDSN);
			ap_recpostrec->setRepositoryString(envyRepositoryString);
			ap_recpostrec->setProfileName(profileName);
			ap_recpostrec->setReplicationOption(eReplicationOption);
			ap_recpostrec->setDropOption(edropOption);
			ap_recpostrec->setOdbcAttributes(odbcAttributes);
			ap_recpostrec->setUpdateInterval(updateInterval);
			ap_recpostrec->setCommitInterval(commitInterval);
			ap_recpostrec->process(1);
		} break;
		case Rctables::enumPRTYLDSET:
		{
			QScopedPointer<PRTYLDSET> prtyldset(new PRTYLDSET(nullptr));
			prtyldset->open(sourceDSN, targetDSN);
			prtyldset->setRepositoryString(envyRepositoryString);
			prtyldset->setProfileName(profileName);
			prtyldset->setReplicationOption(eReplicationOption);
			prtyldset->setDropOption(edropOption);
			prtyldset->setOdbcAttributes(odbcAttributes);
			prtyldset->setUpdateInterval(updateInterval);
			prtyldset->setCommitInterval(commitInterval);
			prtyldset->process(1);
		} break;
		case Rctables::enumPOHRCTSET:
		{
			QScopedPointer<POHRCTSET> pohrctset(new POHRCTSET(nullptr));
			pohrctset->open(sourceDSN, targetDSN);
			pohrctset->setRepositoryString(envyRepositoryString);
			pohrctset->setProfileName(profileName);
			pohrctset->setReplicationOption(eReplicationOption);
			pohrctset->setDropOption(edropOption);
			pohrctset->setOdbcAttributes(odbcAttributes);
			pohrctset->setUpdateInterval(updateInterval);
			pohrctset->setCommitInterval(commitInterval);
			pohrctset->process(1);
		} break;
		case Rctables::enumMA_INHSHHSET:
		{
			QScopedPointer<MA_INHSHHSET> ma_inhshhset(new MA_INHSHHSET(nullptr));
			ma_inhshhset->open(sourceDSN, targetDSN);
			ma_inhshhset->setRepositoryString(envyRepositoryString);
			ma_inhshhset->setProfileName(profileName);
			ma_inhshhset->setReplicationOption(eReplicationOption);
			ma_inhshhset->setDropOption(edropOption);
			ma_inhshhset->setOdbcAttributes(odbcAttributes);
			ma_inhshhset->setUpdateInterval(updateInterval);
			ma_inhshhset->setCommitInterval(commitInterval);
			ma_inhshhset->process(1);
		} break;
		case Rctables::enumRCTHSHSET:
		{
			QScopedPointer<RCTHSHSET> rcthshset(new RCTHSHSET(nullptr));
			rcthshset->open(sourceDSN, targetDSN);
			rcthshset->setRepositoryString(envyRepositoryString);
			rcthshset->setProfileName(profileName);
			rcthshset->setReplicationOption(eReplicationOption);
			rcthshset->setDropOption(edropOption);
			rcthshset->setOdbcAttributes(odbcAttributes);
			rcthshset->setUpdateInterval(updateInterval);
			rcthshset->setCommitInterval(commitInterval);
			rcthshset->process(1);
		} break;
		case Rctables::enumVENBILSET:
		{
			QScopedPointer<VENBILSET> venbilset(new VENBILSET(nullptr));
			venbilset->open(sourceDSN, targetDSN);
			venbilset->setRepositoryString(envyRepositoryString);
			venbilset->setProfileName(profileName);
			venbilset->setReplicationOption(eReplicationOption);
			venbilset->setDropOption(edropOption);
			venbilset->setOdbcAttributes(odbcAttributes);
			venbilset->setUpdateInterval(updateInterval);
			venbilset->setCommitInterval(commitInterval);
			venbilset->process(1);
		} break;
		case Rctables::enumMA_APCSPISET:
		{
			QScopedPointer<MA_APCSPISET> ma_apcspiset(new MA_APCSPISET(nullptr));
			ma_apcspiset->open(sourceDSN, targetDSN);
			ma_apcspiset->setRepositoryString(envyRepositoryString);
			ma_apcspiset->setProfileName(profileName);
			ma_apcspiset->setReplicationOption(eReplicationOption);
			ma_apcspiset->setDropOption(edropOption);
			ma_apcspiset->setOdbcAttributes(odbcAttributes);
			ma_apcspiset->setUpdateInterval(updateInterval);
			ma_apcspiset->setCommitInterval(commitInterval);
			ma_apcspiset->process(1);
		} break;
		case Rctables::enumINTREC:
		{
			QScopedPointer<INTREC> intrec(new INTREC(nullptr));
			intrec->open(sourceDSN, targetDSN);
			intrec->setRepositoryString(envyRepositoryString);
			intrec->setProfileName(profileName);
			intrec->setReplicationOption(eReplicationOption);
			intrec->setDropOption(edropOption);
			intrec->setOdbcAttributes(odbcAttributes);
			intrec->setUpdateInterval(updateInterval);
			intrec->setCommitInterval(commitInterval);
			intrec->process(1);
		} break;
		case Rctables::enumMA_SHHREC:
		{
			QScopedPointer<MA_SHHREC> ma_shhrec(new MA_SHHREC(nullptr));
			ma_shhrec->open(sourceDSN, targetDSN);
			ma_shhrec->setRepositoryString(envyRepositoryString);
			ma_shhrec->setProfileName(profileName);
			ma_shhrec->setReplicationOption(eReplicationOption);
			ma_shhrec->setDropOption(edropOption);
			ma_shhrec->setOdbcAttributes(odbcAttributes);
			ma_shhrec->setUpdateInterval(updateInterval);
			ma_shhrec->setCommitInterval(commitInterval);
			ma_shhrec->process(1);
		} break;
		case Rctables::enumMA_ACCTSRTSET:
		{
			QScopedPointer<MA_ACCTSRTSET> ma_acctsrtset(new MA_ACCTSRTSET(nullptr));
			ma_acctsrtset->open(sourceDSN, targetDSN);
			ma_acctsrtset->setRepositoryString(envyRepositoryString);
			ma_acctsrtset->setProfileName(profileName);
			ma_acctsrtset->setReplicationOption(eReplicationOption);
			ma_acctsrtset->setDropOption(edropOption);
			ma_acctsrtset->setOdbcAttributes(odbcAttributes);
			ma_acctsrtset->setUpdateInterval(updateInterval);
			ma_acctsrtset->setCommitInterval(commitInterval);
			ma_acctsrtset->process(1);
		} break;
		case Rctables::enumMA_COMOCLREC:
		{
			QScopedPointer<MA_COMOCLREC> ma_comoclrec(new MA_COMOCLREC(nullptr));
			ma_comoclrec->open(sourceDSN, targetDSN);
			ma_comoclrec->setRepositoryString(envyRepositoryString);
			ma_comoclrec->setProfileName(profileName);
			ma_comoclrec->setReplicationOption(eReplicationOption);
			ma_comoclrec->setDropOption(edropOption);
			ma_comoclrec->setOdbcAttributes(odbcAttributes);
			ma_comoclrec->setUpdateInterval(updateInterval);
			ma_comoclrec->setCommitInterval(commitInterval);
			ma_comoclrec->process(1);
		} break;
		case Rctables::enumMA_SHDSERSET:
		{
			QScopedPointer<MA_SHDSERSET> ma_shdserset(new MA_SHDSERSET(nullptr));
			ma_shdserset->open(sourceDSN, targetDSN);
			ma_shdserset->setRepositoryString(envyRepositoryString);
			ma_shdserset->setProfileName(profileName);
			ma_shdserset->setReplicationOption(eReplicationOption);
			ma_shdserset->setDropOption(edropOption);
			ma_shdserset->setOdbcAttributes(odbcAttributes);
			ma_shdserset->setUpdateInterval(updateInterval);
			ma_shdserset->setCommitInterval(commitInterval);
			ma_shdserset->process(1);
		} break;
		case Rctables::enumENGREC:
		{
			QScopedPointer<ENGREC> engrec(new ENGREC(nullptr));
			engrec->open(sourceDSN, targetDSN);
			engrec->setRepositoryString(envyRepositoryString);
			engrec->setProfileName(profileName);
			engrec->setReplicationOption(eReplicationOption);
			engrec->setDropOption(edropOption);
			engrec->setOdbcAttributes(odbcAttributes);
			engrec->setUpdateInterval(updateInterval);
			engrec->setCommitInterval(commitInterval);
			engrec->process(1);
		} break;
		case Rctables::enumFA_ACCTHSHSET:
		{
			QScopedPointer<FA_ACCTHSHSET> fa_accthshset(new FA_ACCTHSHSET(nullptr));
			fa_accthshset->open(sourceDSN, targetDSN);
			fa_accthshset->setRepositoryString(envyRepositoryString);
			fa_accthshset->setProfileName(profileName);
			fa_accthshset->setReplicationOption(eReplicationOption);
			fa_accthshset->setDropOption(edropOption);
			fa_accthshset->setOdbcAttributes(odbcAttributes);
			fa_accthshset->setUpdateInterval(updateInterval);
			fa_accthshset->setCommitInterval(commitInterval);
			fa_accthshset->process(1);
		} break;
		case Rctables::enumWIPMATSET:
		{
			QScopedPointer<WIPMATSET> wipmatset(new WIPMATSET(nullptr));
			wipmatset->open(sourceDSN, targetDSN);
			wipmatset->setRepositoryString(envyRepositoryString);
			wipmatset->setProfileName(profileName);
			wipmatset->setReplicationOption(eReplicationOption);
			wipmatset->setDropOption(edropOption);
			wipmatset->setOdbcAttributes(odbcAttributes);
			wipmatset->setUpdateInterval(updateInterval);
			wipmatset->setCommitInterval(commitInterval);
			wipmatset->process(1);
		} break;
		case Rctables::enumMA_SHPHSHSET:
		{
			QScopedPointer<MA_SHPHSHSET> ma_shphshset(new MA_SHPHSHSET(nullptr));
			ma_shphshset->open(sourceDSN, targetDSN);
			ma_shphshset->setRepositoryString(envyRepositoryString);
			ma_shphshset->setProfileName(profileName);
			ma_shphshset->setReplicationOption(eReplicationOption);
			ma_shphshset->setDropOption(edropOption);
			ma_shphshset->setOdbcAttributes(odbcAttributes);
			ma_shphshset->setUpdateInterval(updateInterval);
			ma_shphshset->setCommitInterval(commitInterval);
			ma_shphshset->process(1);
		} break;
		case Rctables::enumDELREC:
		{
			QScopedPointer<DELREC> delrec(new DELREC(nullptr));
			delrec->open(sourceDSN, targetDSN);
			delrec->setRepositoryString(envyRepositoryString);
			delrec->setProfileName(profileName);
			delrec->setReplicationOption(eReplicationOption);
			delrec->setDropOption(edropOption);
			delrec->setOdbcAttributes(odbcAttributes);
			delrec->setUpdateInterval(updateInterval);
			delrec->setCommitInterval(commitInterval);
			delrec->process(1);
		} break;
		case Rctables::enumMA_TXRTHSHSET:
		{
			QScopedPointer<MA_TXRTHSHSET> ma_txrthshset(new MA_TXRTHSHSET(nullptr));
			ma_txrthshset->open(sourceDSN, targetDSN);
			ma_txrthshset->setRepositoryString(envyRepositoryString);
			ma_txrthshset->setProfileName(profileName);
			ma_txrthshset->setReplicationOption(eReplicationOption);
			ma_txrthshset->setDropOption(edropOption);
			ma_txrthshset->setOdbcAttributes(odbcAttributes);
			ma_txrthshset->setUpdateInterval(updateInterval);
			ma_txrthshset->setCommitInterval(commitInterval);
			ma_txrthshset->process(1);
		} break;
		case Rctables::enumFSCSET:
		{
			QScopedPointer<FSCSET> fscset(new FSCSET(nullptr));
			fscset->open(sourceDSN, targetDSN);
			fscset->setRepositoryString(envyRepositoryString);
			fscset->setProfileName(profileName);
			fscset->setReplicationOption(eReplicationOption);
			fscset->setDropOption(edropOption);
			fscset->setOdbcAttributes(odbcAttributes);
			fscset->setUpdateInterval(updateInterval);
			fscset->setCommitInterval(commitInterval);
			fscset->process(1);
		} break;
		case Rctables::enumAP_BATCHREC:
		{
			QScopedPointer<AP_BATCHREC> ap_batchrec(new AP_BATCHREC(nullptr));
			ap_batchrec->open(sourceDSN, targetDSN);
			ap_batchrec->setRepositoryString(envyRepositoryString);
			ap_batchrec->setProfileName(profileName);
			ap_batchrec->setReplicationOption(eReplicationOption);
			ap_batchrec->setDropOption(edropOption);
			ap_batchrec->setOdbcAttributes(odbcAttributes);
			ap_batchrec->setUpdateInterval(updateInterval);
			ap_batchrec->setCommitInterval(commitInterval);
			ap_batchrec->process(1);
		} break;
		case Rctables::enumDRMTRSET:
		{
			QScopedPointer<DRMTRSET> drmtrset(new DRMTRSET(nullptr));
			drmtrset->open(sourceDSN, targetDSN);
			drmtrset->setRepositoryString(envyRepositoryString);
			drmtrset->setProfileName(profileName);
			drmtrset->setReplicationOption(eReplicationOption);
			drmtrset->setDropOption(edropOption);
			drmtrset->setOdbcAttributes(odbcAttributes);
			drmtrset->setUpdateInterval(updateInterval);
			drmtrset->setCommitInterval(commitInterval);
			drmtrset->process(1);
		} break;
		case Rctables::enumMA_SODSPNLSET:
		{
			QScopedPointer<MA_SODSPNLSET> ma_sodspnlset(new MA_SODSPNLSET(nullptr));
			ma_sodspnlset->open(sourceDSN, targetDSN);
			ma_sodspnlset->setRepositoryString(envyRepositoryString);
			ma_sodspnlset->setProfileName(profileName);
			ma_sodspnlset->setReplicationOption(eReplicationOption);
			ma_sodspnlset->setDropOption(edropOption);
			ma_sodspnlset->setOdbcAttributes(odbcAttributes);
			ma_sodspnlset->setUpdateInterval(updateInterval);
			ma_sodspnlset->setCommitInterval(commitInterval);
			ma_sodspnlset->process(1);
		} break;
		case Rctables::enumMA_BILPRTABSET:
		{
			QScopedPointer<MA_BILPRTABSET> ma_bilprtabset(new MA_BILPRTABSET(nullptr));
			ma_bilprtabset->open(sourceDSN, targetDSN);
			ma_bilprtabset->setRepositoryString(envyRepositoryString);
			ma_bilprtabset->setProfileName(profileName);
			ma_bilprtabset->setReplicationOption(eReplicationOption);
			ma_bilprtabset->setDropOption(edropOption);
			ma_bilprtabset->setOdbcAttributes(odbcAttributes);
			ma_bilprtabset->setUpdateInterval(updateInterval);
			ma_bilprtabset->setCommitInterval(commitInterval);
			ma_bilprtabset->process(1);
		} break;
		case Rctables::enumWKCRTGSET:
		{
			QScopedPointer<WKCRTGSET> wkcrtgset(new WKCRTGSET(nullptr));
			wkcrtgset->open(sourceDSN, targetDSN);
			wkcrtgset->setRepositoryString(envyRepositoryString);
			wkcrtgset->setProfileName(profileName);
			wkcrtgset->setReplicationOption(eReplicationOption);
			wkcrtgset->setDropOption(edropOption);
			wkcrtgset->setOdbcAttributes(odbcAttributes);
			wkcrtgset->setUpdateInterval(updateInterval);
			wkcrtgset->setCommitInterval(commitInterval);
			wkcrtgset->process(1);
		} break;
		case Rctables::enumGL_OOLINKSET:
		{
			QScopedPointer<GL_OOLINKSET> gl_oolinkset(new GL_OOLINKSET(nullptr));
			gl_oolinkset->open(sourceDSN, targetDSN);
			gl_oolinkset->setRepositoryString(envyRepositoryString);
			gl_oolinkset->setProfileName(profileName);
			gl_oolinkset->setReplicationOption(eReplicationOption);
			gl_oolinkset->setDropOption(edropOption);
			gl_oolinkset->setOdbcAttributes(odbcAttributes);
			gl_oolinkset->setUpdateInterval(updateInterval);
			gl_oolinkset->setCommitInterval(commitInterval);
			gl_oolinkset->process(1);
		} break;
		case Rctables::enumDELRCTSET:
		{
			QScopedPointer<DELRCTSET> delrctset(new DELRCTSET(nullptr));
			delrctset->open(sourceDSN, targetDSN);
			delrctset->setRepositoryString(envyRepositoryString);
			delrctset->setProfileName(profileName);
			delrctset->setReplicationOption(eReplicationOption);
			delrctset->setDropOption(edropOption);
			delrctset->setOdbcAttributes(odbcAttributes);
			delrctset->setUpdateInterval(updateInterval);
			delrctset->setCommitInterval(commitInterval);
			delrctset->process(1);
		} break;
		case Rctables::enumACSTREC:
		{
			QScopedPointer<ACSTREC> acstrec(new ACSTREC(nullptr));
			acstrec->open(sourceDSN, targetDSN);
			acstrec->setRepositoryString(envyRepositoryString);
			acstrec->setProfileName(profileName);
			acstrec->setReplicationOption(eReplicationOption);
			acstrec->setDropOption(edropOption);
			acstrec->setOdbcAttributes(odbcAttributes);
			acstrec->setUpdateInterval(updateInterval);
			acstrec->setCommitInterval(commitInterval);
			acstrec->process(1);
		} break;
		case Rctables::enumWIPREC:
		{
			QScopedPointer<WIPREC> wiprec(new WIPREC(nullptr));
			wiprec->open(sourceDSN, targetDSN);
			wiprec->setRepositoryString(envyRepositoryString);
			wiprec->setProfileName(profileName);
			wiprec->setReplicationOption(eReplicationOption);
			wiprec->setDropOption(edropOption);
			wiprec->setOdbcAttributes(odbcAttributes);
			wiprec->setUpdateInterval(updateInterval);
			wiprec->setCommitInterval(commitInterval);
			wiprec->process(1);
		} break;
		case Rctables::enumMA_PNOTINVREC:
		{
			QScopedPointer<MA_PNOTINVREC> ma_pnotinvrec(new MA_PNOTINVREC(nullptr));
			ma_pnotinvrec->open(sourceDSN, targetDSN);
			ma_pnotinvrec->setRepositoryString(envyRepositoryString);
			ma_pnotinvrec->setProfileName(profileName);
			ma_pnotinvrec->setReplicationOption(eReplicationOption);
			ma_pnotinvrec->setDropOption(edropOption);
			ma_pnotinvrec->setOdbcAttributes(odbcAttributes);
			ma_pnotinvrec->setUpdateInterval(updateInterval);
			ma_pnotinvrec->setCommitInterval(commitInterval);
			ma_pnotinvrec->process(1);
		} break;
		case Rctables::enumAP_VNDREC:
		{
			QScopedPointer<AP_VNDREC> ap_vndrec(new AP_VNDREC(nullptr));
			ap_vndrec->open(sourceDSN, targetDSN);
			ap_vndrec->setRepositoryString(envyRepositoryString);
			ap_vndrec->setProfileName(profileName);
			ap_vndrec->setReplicationOption(eReplicationOption);
			ap_vndrec->setDropOption(edropOption);
			ap_vndrec->setOdbcAttributes(odbcAttributes);
			ap_vndrec->setUpdateInterval(updateInterval);
			ap_vndrec->setCommitInterval(commitInterval);
			ap_vndrec->process(1);
		} break;
		case Rctables::enumWIPWOHSET:
		{
			QScopedPointer<WIPWOHSET> wipwohset(new WIPWOHSET(nullptr));
			wipwohset->open(sourceDSN, targetDSN);
			wipwohset->setRepositoryString(envyRepositoryString);
			wipwohset->setProfileName(profileName);
			wipwohset->setReplicationOption(eReplicationOption);
			wipwohset->setDropOption(edropOption);
			wipwohset->setOdbcAttributes(odbcAttributes);
			wipwohset->setUpdateInterval(updateInterval);
			wipwohset->setCommitInterval(commitInterval);
			wipwohset->process(1);
		} break;
		case Rctables::enumMA_STERSAMSET:
		{
			QScopedPointer<MA_STERSAMSET> ma_stersamset(new MA_STERSAMSET(nullptr));
			ma_stersamset->open(sourceDSN, targetDSN);
			ma_stersamset->setRepositoryString(envyRepositoryString);
			ma_stersamset->setProfileName(profileName);
			ma_stersamset->setReplicationOption(eReplicationOption);
			ma_stersamset->setDropOption(edropOption);
			ma_stersamset->setOdbcAttributes(odbcAttributes);
			ma_stersamset->setUpdateInterval(updateInterval);
			ma_stersamset->setCommitInterval(commitInterval);
			ma_stersamset->process(1);
		} break;
		case Rctables::enumAP_BCHHOLDSET:
		{
			QScopedPointer<AP_BCHHOLDSET> ap_bchholdset(new AP_BCHHOLDSET(nullptr));
			ap_bchholdset->open(sourceDSN, targetDSN);
			ap_bchholdset->setRepositoryString(envyRepositoryString);
			ap_bchholdset->setProfileName(profileName);
			ap_bchholdset->setReplicationOption(eReplicationOption);
			ap_bchholdset->setDropOption(edropOption);
			ap_bchholdset->setOdbcAttributes(odbcAttributes);
			ap_bchholdset->setUpdateInterval(updateInterval);
			ap_bchholdset->setCommitInterval(commitInterval);
			ap_bchholdset->process(1);
		} break;
		case Rctables::enumGL_ACCTREC:
		{
			QScopedPointer<GL_ACCTREC> gl_acctrec(new GL_ACCTREC(nullptr));
			gl_acctrec->open(sourceDSN, targetDSN);
			gl_acctrec->setRepositoryString(envyRepositoryString);
			gl_acctrec->setProfileName(profileName);
			gl_acctrec->setReplicationOption(eReplicationOption);
			gl_acctrec->setDropOption(edropOption);
			gl_acctrec->setOdbcAttributes(odbcAttributes);
			gl_acctrec->setUpdateInterval(updateInterval);
			gl_acctrec->setCommitInterval(commitInterval);
			gl_acctrec->process(1);
		} break;
		case Rctables::enumACTOPSET:
		{
			QScopedPointer<ACTOPSET> actopset(new ACTOPSET(nullptr));
			actopset->open(sourceDSN, targetDSN);
			actopset->setRepositoryString(envyRepositoryString);
			actopset->setProfileName(profileName);
			actopset->setReplicationOption(eReplicationOption);
			actopset->setDropOption(edropOption);
			actopset->setOdbcAttributes(odbcAttributes);
			actopset->setUpdateInterval(updateInterval);
			actopset->setCommitInterval(commitInterval);
			actopset->process(1);
		} break;
		case Rctables::enumWOHVARSET:
		{
			QScopedPointer<WOHVARSET> wohvarset(new WOHVARSET(nullptr));
			wohvarset->open(sourceDSN, targetDSN);
			wohvarset->setRepositoryString(envyRepositoryString);
			wohvarset->setProfileName(profileName);
			wohvarset->setReplicationOption(eReplicationOption);
			wohvarset->setDropOption(edropOption);
			wohvarset->setOdbcAttributes(odbcAttributes);
			wohvarset->setUpdateInterval(updateInterval);
			wohvarset->setCommitInterval(commitInterval);
			wohvarset->process(1);
		} break;
		case Rctables::enumMA_FLDREC:
		{
			QScopedPointer<MA_FLDREC> ma_fldrec(new MA_FLDREC(nullptr));
			ma_fldrec->open(sourceDSN, targetDSN);
			ma_fldrec->setRepositoryString(envyRepositoryString);
			ma_fldrec->setProfileName(profileName);
			ma_fldrec->setReplicationOption(eReplicationOption);
			ma_fldrec->setDropOption(edropOption);
			ma_fldrec->setOdbcAttributes(odbcAttributes);
			ma_fldrec->setUpdateInterval(updateInterval);
			ma_fldrec->setCommitInterval(commitInterval);
			ma_fldrec->process(1);
		} break;
		case Rctables::enumGL_VPFRSET:
		{
			QScopedPointer<GL_VPFRSET> gl_vpfrset(new GL_VPFRSET(nullptr));
			gl_vpfrset->open(sourceDSN, targetDSN);
			gl_vpfrset->setRepositoryString(envyRepositoryString);
			gl_vpfrset->setProfileName(profileName);
			gl_vpfrset->setReplicationOption(eReplicationOption);
			gl_vpfrset->setDropOption(edropOption);
			gl_vpfrset->setOdbcAttributes(odbcAttributes);
			gl_vpfrset->setUpdateInterval(updateInterval);
			gl_vpfrset->setCommitInterval(commitInterval);
			gl_vpfrset->process(1);
		} break;
		case Rctables::enumMA_INDREC:
		{
			QScopedPointer<MA_INDREC> ma_indrec(new MA_INDREC(nullptr));
			ma_indrec->open(sourceDSN, targetDSN);
			ma_indrec->setRepositoryString(envyRepositoryString);
			ma_indrec->setProfileName(profileName);
			ma_indrec->setReplicationOption(eReplicationOption);
			ma_indrec->setDropOption(edropOption);
			ma_indrec->setOdbcAttributes(odbcAttributes);
			ma_indrec->setUpdateInterval(updateInterval);
			ma_indrec->setCommitInterval(commitInterval);
			ma_indrec->process(1);
		} break;
		case Rctables::enumPRTFAMSET:
		{
			QScopedPointer<PRTFAMSET> prtfamset(new PRTFAMSET(nullptr));
			prtfamset->open(sourceDSN, targetDSN);
			prtfamset->setRepositoryString(envyRepositoryString);
			prtfamset->setProfileName(profileName);
			prtfamset->setReplicationOption(eReplicationOption);
			prtfamset->setDropOption(edropOption);
			prtfamset->setOdbcAttributes(odbcAttributes);
			prtfamset->setUpdateInterval(updateInterval);
			prtfamset->setCommitInterval(commitInterval);
			prtfamset->process(1);
		} break;
		case Rctables::enumCDLCONSET:
		{
			QScopedPointer<CDLCONSET> cdlconset(new CDLCONSET(nullptr));
			cdlconset->open(sourceDSN, targetDSN);
			cdlconset->setRepositoryString(envyRepositoryString);
			cdlconset->setProfileName(profileName);
			cdlconset->setReplicationOption(eReplicationOption);
			cdlconset->setDropOption(edropOption);
			cdlconset->setOdbcAttributes(odbcAttributes);
			cdlconset->setUpdateInterval(updateInterval);
			cdlconset->setCommitInterval(commitInterval);
			cdlconset->process(1);
		} break;
		case Rctables::enumFLDSET:
		{
			QScopedPointer<FLDSET> fldset(new FLDSET(nullptr));
			fldset->open(sourceDSN, targetDSN);
			fldset->setRepositoryString(envyRepositoryString);
			fldset->setProfileName(profileName);
			fldset->setReplicationOption(eReplicationOption);
			fldset->setDropOption(edropOption);
			fldset->setOdbcAttributes(odbcAttributes);
			fldset->setUpdateInterval(updateInterval);
			fldset->setCommitInterval(commitInterval);
			fldset->process(1);
		} break;
		case Rctables::enumMA_COMOCOMOCLSET:
		{
			QScopedPointer<MA_COMOCOMOCLSET> ma_comocomoclset(new MA_COMOCOMOCLSET(nullptr));
			ma_comocomoclset->open(sourceDSN, targetDSN);
			ma_comocomoclset->setRepositoryString(envyRepositoryString);
			ma_comocomoclset->setProfileName(profileName);
			ma_comocomoclset->setReplicationOption(eReplicationOption);
			ma_comocomoclset->setDropOption(edropOption);
			ma_comocomoclset->setOdbcAttributes(odbcAttributes);
			ma_comocomoclset->setUpdateInterval(updateInterval);
			ma_comocomoclset->setCommitInterval(commitInterval);
			ma_comocomoclset->process(1);
		} break;
		case Rctables::enumFA_PROJREC:
		{
			QScopedPointer<FA_PROJREC> fa_projrec(new FA_PROJREC(nullptr));
			fa_projrec->open(sourceDSN, targetDSN);
			fa_projrec->setRepositoryString(envyRepositoryString);
			fa_projrec->setProfileName(profileName);
			fa_projrec->setReplicationOption(eReplicationOption);
			fa_projrec->setDropOption(edropOption);
			fa_projrec->setOdbcAttributes(odbcAttributes);
			fa_projrec->setUpdateInterval(updateInterval);
			fa_projrec->setCommitInterval(commitInterval);
			fa_projrec->process(1);
		} break;
		case Rctables::enumMA_RSNHSHSET:
		{
			QScopedPointer<MA_RSNHSHSET> ma_rsnhshset(new MA_RSNHSHSET(nullptr));
			ma_rsnhshset->open(sourceDSN, targetDSN);
			ma_rsnhshset->setRepositoryString(envyRepositoryString);
			ma_rsnhshset->setProfileName(profileName);
			ma_rsnhshset->setReplicationOption(eReplicationOption);
			ma_rsnhshset->setDropOption(edropOption);
			ma_rsnhshset->setOdbcAttributes(odbcAttributes);
			ma_rsnhshset->setUpdateInterval(updateInterval);
			ma_rsnhshset->setCommitInterval(commitInterval);
			ma_rsnhshset->process(1);
		} break;
		case Rctables::enumMA_INHPOSTSET:
		{
			QScopedPointer<MA_INHPOSTSET> ma_inhpostset(new MA_INHPOSTSET(nullptr));
			ma_inhpostset->open(sourceDSN, targetDSN);
			ma_inhpostset->setRepositoryString(envyRepositoryString);
			ma_inhpostset->setProfileName(profileName);
			ma_inhpostset->setReplicationOption(eReplicationOption);
			ma_inhpostset->setDropOption(edropOption);
			ma_inhpostset->setOdbcAttributes(odbcAttributes);
			ma_inhpostset->setUpdateInterval(updateInterval);
			ma_inhpostset->setCommitInterval(commitInterval);
			ma_inhpostset->process(1);
		} break;
		case Rctables::enumMA_QUOHQUODSET:
		{
			QScopedPointer<MA_QUOHQUODSET> ma_quohquodset(new MA_QUOHQUODSET(nullptr));
			ma_quohquodset->open(sourceDSN, targetDSN);
			ma_quohquodset->setRepositoryString(envyRepositoryString);
			ma_quohquodset->setProfileName(profileName);
			ma_quohquodset->setReplicationOption(eReplicationOption);
			ma_quohquodset->setDropOption(edropOption);
			ma_quohquodset->setOdbcAttributes(odbcAttributes);
			ma_quohquodset->setUpdateInterval(updateInterval);
			ma_quohquodset->setCommitInterval(commitInterval);
			ma_quohquodset->process(1);
		} break;
		case Rctables::enumMA_CMHSPNLSET:
		{
			QScopedPointer<MA_CMHSPNLSET> ma_cmhspnlset(new MA_CMHSPNLSET(nullptr));
			ma_cmhspnlset->open(sourceDSN, targetDSN);
			ma_cmhspnlset->setRepositoryString(envyRepositoryString);
			ma_cmhspnlset->setProfileName(profileName);
			ma_cmhspnlset->setReplicationOption(eReplicationOption);
			ma_cmhspnlset->setDropOption(edropOption);
			ma_cmhspnlset->setOdbcAttributes(odbcAttributes);
			ma_cmhspnlset->setUpdateInterval(updateInterval);
			ma_cmhspnlset->setCommitInterval(commitInterval);
			ma_cmhspnlset->process(1);
		} break;
		case Rctables::enumED_TPREC:
		{
			QScopedPointer<ED_TPREC> ed_tprec(new ED_TPREC(nullptr));
			ed_tprec->open(sourceDSN, targetDSN);
			ed_tprec->setRepositoryString(envyRepositoryString);
			ed_tprec->setProfileName(profileName);
			ed_tprec->setReplicationOption(eReplicationOption);
			ed_tprec->setDropOption(edropOption);
			ed_tprec->setOdbcAttributes(odbcAttributes);
			ed_tprec->setUpdateInterval(updateInterval);
			ed_tprec->setCommitInterval(commitInterval);
			ed_tprec->process(1);
		} break;
		case Rctables::enumWIPMETSET:
		{
			QScopedPointer<WIPMETSET> wipmetset(new WIPMETSET(nullptr));
			wipmetset->open(sourceDSN, targetDSN);
			wipmetset->setRepositoryString(envyRepositoryString);
			wipmetset->setProfileName(profileName);
			wipmetset->setReplicationOption(eReplicationOption);
			wipmetset->setDropOption(edropOption);
			wipmetset->setOdbcAttributes(odbcAttributes);
			wipmetset->setUpdateInterval(updateInterval);
			wipmetset->setCommitInterval(commitInterval);
			wipmetset->process(1);
		} break;
		case Rctables::enumAP_PROJHSHSET:
		{
			QScopedPointer<AP_PROJHSHSET> ap_projhshset(new AP_PROJHSHSET(nullptr));
			ap_projhshset->open(sourceDSN, targetDSN);
			ap_projhshset->setRepositoryString(envyRepositoryString);
			ap_projhshset->setProfileName(profileName);
			ap_projhshset->setReplicationOption(eReplicationOption);
			ap_projhshset->setDropOption(edropOption);
			ap_projhshset->setOdbcAttributes(odbcAttributes);
			ap_projhshset->setUpdateInterval(updateInterval);
			ap_projhshset->setCommitInterval(commitInterval);
			ap_projhshset->process(1);
		} break;
		case Rctables::enumTRKREC:
		{
			QScopedPointer<TRKREC> trkrec(new TRKREC(nullptr));
			trkrec->open(sourceDSN, targetDSN);
			trkrec->setRepositoryString(envyRepositoryString);
			trkrec->setProfileName(profileName);
			trkrec->setReplicationOption(eReplicationOption);
			trkrec->setDropOption(edropOption);
			trkrec->setOdbcAttributes(odbcAttributes);
			trkrec->setUpdateInterval(updateInterval);
			trkrec->setCommitInterval(commitInterval);
			trkrec->process(1);
		} break;
		case Rctables::enumMA_SODREC:
		{
			QScopedPointer<MA_SODREC> ma_sodrec(new MA_SODREC(nullptr));
			ma_sodrec->open(sourceDSN, targetDSN);
			ma_sodrec->setRepositoryString(envyRepositoryString);
			ma_sodrec->setProfileName(profileName);
			ma_sodrec->setReplicationOption(eReplicationOption);
			ma_sodrec->setDropOption(edropOption);
			ma_sodrec->setOdbcAttributes(odbcAttributes);
			ma_sodrec->setUpdateInterval(updateInterval);
			ma_sodrec->setCommitInterval(commitInterval);
			ma_sodrec->process(1);
		} break;
		case Rctables::enumAP_VNOTEREC:
		{
			QScopedPointer<AP_VNOTEREC> ap_vnoterec(new AP_VNOTEREC(nullptr));
			ap_vnoterec->open(sourceDSN, targetDSN);
			ap_vnoterec->setRepositoryString(envyRepositoryString);
			ap_vnoterec->setProfileName(profileName);
			ap_vnoterec->setReplicationOption(eReplicationOption);
			ap_vnoterec->setDropOption(edropOption);
			ap_vnoterec->setOdbcAttributes(odbcAttributes);
			ap_vnoterec->setUpdateInterval(updateInterval);
			ap_vnoterec->setCommitInterval(commitInterval);
			ap_vnoterec->process(1);
		} break;
		case Rctables::enumSODREC:
		{
			QScopedPointer<SODREC> sodrec(new SODREC(nullptr));
			sodrec->open(sourceDSN, targetDSN);
			sodrec->setRepositoryString(envyRepositoryString);
			sodrec->setProfileName(profileName);
			sodrec->setReplicationOption(eReplicationOption);
			sodrec->setDropOption(edropOption);
			sodrec->setOdbcAttributes(odbcAttributes);
			sodrec->setUpdateInterval(updateInterval);
			sodrec->setCommitInterval(commitInterval);
			sodrec->process(1);
		} break;
		case Rctables::enumMA_ACCTPOSTSET:
		{
			QScopedPointer<MA_ACCTPOSTSET> ma_acctpostset(new MA_ACCTPOSTSET(nullptr));
			ma_acctpostset->open(sourceDSN, targetDSN);
			ma_acctpostset->setRepositoryString(envyRepositoryString);
			ma_acctpostset->setProfileName(profileName);
			ma_acctpostset->setReplicationOption(eReplicationOption);
			ma_acctpostset->setDropOption(edropOption);
			ma_acctpostset->setOdbcAttributes(odbcAttributes);
			ma_acctpostset->setUpdateInterval(updateInterval);
			ma_acctpostset->setCommitInterval(commitInterval);
			ma_acctpostset->process(1);
		} break;
		case Rctables::enumAP_VCHPOSTSET:
		{
			QScopedPointer<AP_VCHPOSTSET> ap_vchpostset(new AP_VCHPOSTSET(nullptr));
			ap_vchpostset->open(sourceDSN, targetDSN);
			ap_vchpostset->setRepositoryString(envyRepositoryString);
			ap_vchpostset->setProfileName(profileName);
			ap_vchpostset->setReplicationOption(eReplicationOption);
			ap_vchpostset->setDropOption(edropOption);
			ap_vchpostset->setOdbcAttributes(odbcAttributes);
			ap_vchpostset->setUpdateInterval(updateInterval);
			ap_vchpostset->setCommitInterval(commitInterval);
			ap_vchpostset->process(1);
		} break;
		case Rctables::enumAP_SEARCHHSHSET:
		{
			QScopedPointer<AP_SEARCHHSHSET> ap_searchhshset(new AP_SEARCHHSHSET(nullptr));
			ap_searchhshset->open(sourceDSN, targetDSN);
			ap_searchhshset->setRepositoryString(envyRepositoryString);
			ap_searchhshset->setProfileName(profileName);
			ap_searchhshset->setReplicationOption(eReplicationOption);
			ap_searchhshset->setDropOption(edropOption);
			ap_searchhshset->setOdbcAttributes(odbcAttributes);
			ap_searchhshset->setUpdateInterval(updateInterval);
			ap_searchhshset->setCommitInterval(commitInterval);
			ap_searchhshset->process(1);
		} break;
		case Rctables::enumGL_PROJAPSET:
		{
			QScopedPointer<GL_PROJAPSET> gl_projapset(new GL_PROJAPSET(nullptr));
			gl_projapset->open(sourceDSN, targetDSN);
			gl_projapset->setRepositoryString(envyRepositoryString);
			gl_projapset->setProfileName(profileName);
			gl_projapset->setReplicationOption(eReplicationOption);
			gl_projapset->setDropOption(edropOption);
			gl_projapset->setOdbcAttributes(odbcAttributes);
			gl_projapset->setUpdateInterval(updateInterval);
			gl_projapset->setCommitInterval(commitInterval);
			gl_projapset->process(1);
		} break;
		case Rctables::enumEMPLABPYSET:
		{
			QScopedPointer<EMPLABPYSET> emplabpyset(new EMPLABPYSET(nullptr));
			emplabpyset->open(sourceDSN, targetDSN);
			emplabpyset->setRepositoryString(envyRepositoryString);
			emplabpyset->setProfileName(profileName);
			emplabpyset->setReplicationOption(eReplicationOption);
			emplabpyset->setDropOption(edropOption);
			emplabpyset->setOdbcAttributes(odbcAttributes);
			emplabpyset->setUpdateInterval(updateInterval);
			emplabpyset->setCommitInterval(commitInterval);
			emplabpyset->process(1);
		} break;
		case Rctables::enumRTGREC:
		{
			QScopedPointer<RTGREC> rtgrec(new RTGREC(nullptr));
			rtgrec->open(sourceDSN, targetDSN);
			rtgrec->setRepositoryString(envyRepositoryString);
			rtgrec->setProfileName(profileName);
			rtgrec->setReplicationOption(eReplicationOption);
			rtgrec->setDropOption(edropOption);
			rtgrec->setOdbcAttributes(odbcAttributes);
			rtgrec->setUpdateInterval(updateInterval);
			rtgrec->setCommitInterval(commitInterval);
			rtgrec->process(1);
		} break;
		case Rctables::enumMA_DMHREC:
		{
			QScopedPointer<MA_DMHREC> ma_dmhrec(new MA_DMHREC(nullptr));
			ma_dmhrec->open(sourceDSN, targetDSN);
			ma_dmhrec->setRepositoryString(envyRepositoryString);
			ma_dmhrec->setProfileName(profileName);
			ma_dmhrec->setReplicationOption(eReplicationOption);
			ma_dmhrec->setDropOption(edropOption);
			ma_dmhrec->setOdbcAttributes(odbcAttributes);
			ma_dmhrec->setUpdateInterval(updateInterval);
			ma_dmhrec->setCommitInterval(commitInterval);
			ma_dmhrec->process(1);
		} break;
		case Rctables::enumMA_STERREC:
		{
			QScopedPointer<MA_STERREC> ma_sterrec(new MA_STERREC(nullptr));
			ma_sterrec->open(sourceDSN, targetDSN);
			ma_sterrec->setRepositoryString(envyRepositoryString);
			ma_sterrec->setProfileName(profileName);
			ma_sterrec->setReplicationOption(eReplicationOption);
			ma_sterrec->setDropOption(edropOption);
			ma_sterrec->setOdbcAttributes(odbcAttributes);
			ma_sterrec->setUpdateInterval(updateInterval);
			ma_sterrec->setCommitInterval(commitInterval);
			ma_sterrec->process(1);
		} break;
		case Rctables::enumFA_PROJHSHSET:
		{
			QScopedPointer<FA_PROJHSHSET> fa_projhshset(new FA_PROJHSHSET(nullptr));
			fa_projhshset->open(sourceDSN, targetDSN);
			fa_projhshset->setRepositoryString(envyRepositoryString);
			fa_projhshset->setProfileName(profileName);
			fa_projhshset->setReplicationOption(eReplicationOption);
			fa_projhshset->setDropOption(edropOption);
			fa_projhshset->setOdbcAttributes(odbcAttributes);
			fa_projhshset->setUpdateInterval(updateInterval);
			fa_projhshset->setCommitInterval(commitInterval);
			fa_projhshset->process(1);
		} break;
		case Rctables::enumMA_PRPTFCPRTABSET:
		{
			QScopedPointer<MA_PRPTFCPRTABSET> ma_prptfcprtabset(new MA_PRPTFCPRTABSET(nullptr));
			ma_prptfcprtabset->open(sourceDSN, targetDSN);
			ma_prptfcprtabset->setRepositoryString(envyRepositoryString);
			ma_prptfcprtabset->setProfileName(profileName);
			ma_prptfcprtabset->setReplicationOption(eReplicationOption);
			ma_prptfcprtabset->setDropOption(edropOption);
			ma_prptfcprtabset->setOdbcAttributes(odbcAttributes);
			ma_prptfcprtabset->setUpdateInterval(updateInterval);
			ma_prptfcprtabset->setCommitInterval(commitInterval);
			ma_prptfcprtabset->process(1);
		} break;
		case Rctables::enumPOHPODSET:
		{
			QScopedPointer<POHPODSET> pohpodset(new POHPODSET(nullptr));
			pohpodset->open(sourceDSN, targetDSN);
			pohpodset->setRepositoryString(envyRepositoryString);
			pohpodset->setProfileName(profileName);
			pohpodset->setReplicationOption(eReplicationOption);
			pohpodset->setDropOption(edropOption);
			pohpodset->setOdbcAttributes(odbcAttributes);
			pohpodset->setUpdateInterval(updateInterval);
			pohpodset->setCommitInterval(commitInterval);
			pohpodset->process(1);
		} break;
		case Rctables::enumGL_PROJAMTSET:
		{
			QScopedPointer<GL_PROJAMTSET> gl_projamtset(new GL_PROJAMTSET(nullptr));
			gl_projamtset->open(sourceDSN, targetDSN);
			gl_projamtset->setRepositoryString(envyRepositoryString);
			gl_projamtset->setProfileName(profileName);
			gl_projamtset->setReplicationOption(eReplicationOption);
			gl_projamtset->setDropOption(edropOption);
			gl_projamtset->setOdbcAttributes(odbcAttributes);
			gl_projamtset->setUpdateInterval(updateInterval);
			gl_projamtset->setCommitInterval(commitInterval);
			gl_projamtset->process(1);
		} break;
		case Rctables::enumRESHSHSET:
		{
			QScopedPointer<RESHSHSET> reshshset(new RESHSHSET(nullptr));
			reshshset->open(sourceDSN, targetDSN);
			reshshset->setRepositoryString(envyRepositoryString);
			reshshset->setProfileName(profileName);
			reshshset->setReplicationOption(eReplicationOption);
			reshshset->setDropOption(edropOption);
			reshshset->setOdbcAttributes(odbcAttributes);
			reshshset->setUpdateInterval(updateInterval);
			reshshset->setCommitInterval(commitInterval);
			reshshset->process(1);
		} break;
		case Rctables::enumMA_SHPCOMCSET:
		{
			QScopedPointer<MA_SHPCOMCSET> ma_shpcomcset(new MA_SHPCOMCSET(nullptr));
			ma_shpcomcset->open(sourceDSN, targetDSN);
			ma_shpcomcset->setRepositoryString(envyRepositoryString);
			ma_shpcomcset->setProfileName(profileName);
			ma_shpcomcset->setReplicationOption(eReplicationOption);
			ma_shpcomcset->setDropOption(edropOption);
			ma_shpcomcset->setOdbcAttributes(odbcAttributes);
			ma_shpcomcset->setUpdateInterval(updateInterval);
			ma_shpcomcset->setCommitInterval(commitInterval);
			ma_shpcomcset->process(1);
		} break;
		case Rctables::enumGL_ACCTDESCSET:
		{
			QScopedPointer<GL_ACCTDESCSET> gl_acctdescset(new GL_ACCTDESCSET(nullptr));
			gl_acctdescset->open(sourceDSN, targetDSN);
			gl_acctdescset->setRepositoryString(envyRepositoryString);
			gl_acctdescset->setProfileName(profileName);
			gl_acctdescset->setReplicationOption(eReplicationOption);
			gl_acctdescset->setDropOption(edropOption);
			gl_acctdescset->setOdbcAttributes(odbcAttributes);
			gl_acctdescset->setUpdateInterval(updateInterval);
			gl_acctdescset->setCommitInterval(commitInterval);
			gl_acctdescset->process(1);
		} break;
		case Rctables::enumAP_PNOTHSHSET:
		{
			QScopedPointer<AP_PNOTHSHSET> ap_pnothshset(new AP_PNOTHSHSET(nullptr));
			ap_pnothshset->open(sourceDSN, targetDSN);
			ap_pnothshset->setRepositoryString(envyRepositoryString);
			ap_pnothshset->setProfileName(profileName);
			ap_pnothshset->setReplicationOption(eReplicationOption);
			ap_pnothshset->setDropOption(edropOption);
			ap_pnothshset->setOdbcAttributes(odbcAttributes);
			ap_pnothshset->setUpdateInterval(updateInterval);
			ap_pnothshset->setCommitInterval(commitInterval);
			ap_pnothshset->process(1);
		} break;
		case Rctables::enumGL_FPFRSET:
		{
			QScopedPointer<GL_FPFRSET> gl_fpfrset(new GL_FPFRSET(nullptr));
			gl_fpfrset->open(sourceDSN, targetDSN);
			gl_fpfrset->setRepositoryString(envyRepositoryString);
			gl_fpfrset->setProfileName(profileName);
			gl_fpfrset->setReplicationOption(eReplicationOption);
			gl_fpfrset->setDropOption(edropOption);
			gl_fpfrset->setOdbcAttributes(odbcAttributes);
			gl_fpfrset->setUpdateInterval(updateInterval);
			gl_fpfrset->setCommitInterval(commitInterval);
			gl_fpfrset->process(1);
		} break;
		case Rctables::enumMRLMRHSET:
		{
			QScopedPointer<MRLMRHSET> mrlmrhset(new MRLMRHSET(nullptr));
			mrlmrhset->open(sourceDSN, targetDSN);
			mrlmrhset->setRepositoryString(envyRepositoryString);
			mrlmrhset->setProfileName(profileName);
			mrlmrhset->setReplicationOption(eReplicationOption);
			mrlmrhset->setDropOption(edropOption);
			mrlmrhset->setOdbcAttributes(odbcAttributes);
			mrlmrhset->setUpdateInterval(updateInterval);
			mrlmrhset->setCommitInterval(commitInterval);
			mrlmrhset->process(1);
		} break;
		case Rctables::enumGL_ARPT_HREC:
		{
			QScopedPointer<GL_ARPT_HREC> gl_arpt_hrec(new GL_ARPT_HREC(nullptr));
			gl_arpt_hrec->open(sourceDSN, targetDSN);
			gl_arpt_hrec->setRepositoryString(envyRepositoryString);
			gl_arpt_hrec->setProfileName(profileName);
			gl_arpt_hrec->setReplicationOption(eReplicationOption);
			gl_arpt_hrec->setDropOption(edropOption);
			gl_arpt_hrec->setOdbcAttributes(odbcAttributes);
			gl_arpt_hrec->setUpdateInterval(updateInterval);
			gl_arpt_hrec->setCommitInterval(commitInterval);
			gl_arpt_hrec->process(1);
		} break;
		case Rctables::enumMA_TXINHSET:
		{
			QScopedPointer<MA_TXINHSET> ma_txinhset(new MA_TXINHSET(nullptr));
			ma_txinhset->open(sourceDSN, targetDSN);
			ma_txinhset->setRepositoryString(envyRepositoryString);
			ma_txinhset->setProfileName(profileName);
			ma_txinhset->setReplicationOption(eReplicationOption);
			ma_txinhset->setDropOption(edropOption);
			ma_txinhset->setOdbcAttributes(odbcAttributes);
			ma_txinhset->setUpdateInterval(updateInterval);
			ma_txinhset->setCommitInterval(commitInterval);
			ma_txinhset->process(1);
		} break;
		case Rctables::enumMA_CHGDCOMOCLSET:
		{
			QScopedPointer<MA_CHGDCOMOCLSET> ma_chgdcomoclset(new MA_CHGDCOMOCLSET(nullptr));
			ma_chgdcomoclset->open(sourceDSN, targetDSN);
			ma_chgdcomoclset->setRepositoryString(envyRepositoryString);
			ma_chgdcomoclset->setProfileName(profileName);
			ma_chgdcomoclset->setReplicationOption(eReplicationOption);
			ma_chgdcomoclset->setDropOption(edropOption);
			ma_chgdcomoclset->setOdbcAttributes(odbcAttributes);
			ma_chgdcomoclset->setUpdateInterval(updateInterval);
			ma_chgdcomoclset->setCommitInterval(commitInterval);
			ma_chgdcomoclset->process(1);
		} break;
		case Rctables::enumGL_ABUDREC:
		{
			QScopedPointer<GL_ABUDREC> gl_abudrec(new GL_ABUDREC(nullptr));
			gl_abudrec->open(sourceDSN, targetDSN);
			gl_abudrec->setRepositoryString(envyRepositoryString);
			gl_abudrec->setProfileName(profileName);
			gl_abudrec->setReplicationOption(eReplicationOption);
			gl_abudrec->setDropOption(edropOption);
			gl_abudrec->setOdbcAttributes(odbcAttributes);
			gl_abudrec->setUpdateInterval(updateInterval);
			gl_abudrec->setCommitInterval(commitInterval);
			gl_abudrec->process(1);
		} break;
		case Rctables::enumBYDREC:
		{
			QScopedPointer<BYDREC> bydrec(new BYDREC(nullptr));
			bydrec->open(sourceDSN, targetDSN);
			bydrec->setRepositoryString(envyRepositoryString);
			bydrec->setProfileName(profileName);
			bydrec->setReplicationOption(eReplicationOption);
			bydrec->setDropOption(edropOption);
			bydrec->setOdbcAttributes(odbcAttributes);
			bydrec->setUpdateInterval(updateInterval);
			bydrec->setCommitInterval(commitInterval);
			bydrec->process(1);
		} break;
		case Rctables::enumACTREC:
		{
			QScopedPointer<ACTREC> actrec(new ACTREC(nullptr));
			actrec->open(sourceDSN, targetDSN);
			actrec->setRepositoryString(envyRepositoryString);
			actrec->setProfileName(profileName);
			actrec->setReplicationOption(eReplicationOption);
			actrec->setDropOption(edropOption);
			actrec->setOdbcAttributes(odbcAttributes);
			actrec->setUpdateInterval(updateInterval);
			actrec->setCommitInterval(commitInterval);
			actrec->process(1);
		} break;
		case Rctables::enumMA_INHPRTSET:
		{
			QScopedPointer<MA_INHPRTSET> ma_inhprtset(new MA_INHPRTSET(nullptr));
			ma_inhprtset->open(sourceDSN, targetDSN);
			ma_inhprtset->setRepositoryString(envyRepositoryString);
			ma_inhprtset->setProfileName(profileName);
			ma_inhprtset->setReplicationOption(eReplicationOption);
			ma_inhprtset->setDropOption(edropOption);
			ma_inhprtset->setOdbcAttributes(odbcAttributes);
			ma_inhprtset->setUpdateInterval(updateInterval);
			ma_inhprtset->setCommitInterval(commitInterval);
			ma_inhprtset->process(1);
		} break;
		case Rctables::enumMA_SHDPREC:
		{
			QScopedPointer<MA_SHDPREC> ma_shdprec(new MA_SHDPREC(nullptr));
			ma_shdprec->open(sourceDSN, targetDSN);
			ma_shdprec->setRepositoryString(envyRepositoryString);
			ma_shdprec->setProfileName(profileName);
			ma_shdprec->setReplicationOption(eReplicationOption);
			ma_shdprec->setDropOption(edropOption);
			ma_shdprec->setOdbcAttributes(odbcAttributes);
			ma_shdprec->setUpdateInterval(updateInterval);
			ma_shdprec->setCommitInterval(commitInterval);
			ma_shdprec->process(1);
		} break;
		case Rctables::enumGL_FPOFFPROJSET:
		{
			QScopedPointer<GL_FPOFFPROJSET> gl_fpoffprojset(new GL_FPOFFPROJSET(nullptr));
			gl_fpoffprojset->open(sourceDSN, targetDSN);
			gl_fpoffprojset->setRepositoryString(envyRepositoryString);
			gl_fpoffprojset->setProfileName(profileName);
			gl_fpoffprojset->setReplicationOption(eReplicationOption);
			gl_fpoffprojset->setDropOption(edropOption);
			gl_fpoffprojset->setOdbcAttributes(odbcAttributes);
			gl_fpoffprojset->setUpdateInterval(updateInterval);
			gl_fpoffprojset->setCommitInterval(commitInterval);
			gl_fpoffprojset->process(1);
		} break;
		case Rctables::enumMA_POSTHSHSET:
		{
			QScopedPointer<MA_POSTHSHSET> ma_posthshset(new MA_POSTHSHSET(nullptr));
			ma_posthshset->open(sourceDSN, targetDSN);
			ma_posthshset->setRepositoryString(envyRepositoryString);
			ma_posthshset->setProfileName(profileName);
			ma_posthshset->setReplicationOption(eReplicationOption);
			ma_posthshset->setDropOption(edropOption);
			ma_posthshset->setOdbcAttributes(odbcAttributes);
			ma_posthshset->setUpdateInterval(updateInterval);
			ma_posthshset->setCommitInterval(commitInterval);
			ma_posthshset->process(1);
		} break;
		case Rctables::enumGL_JVREC:
		{
			QScopedPointer<GL_JVREC> gl_jvrec(new GL_JVREC(nullptr));
			gl_jvrec->open(sourceDSN, targetDSN);
			gl_jvrec->setRepositoryString(envyRepositoryString);
			gl_jvrec->setProfileName(profileName);
			gl_jvrec->setReplicationOption(eReplicationOption);
			gl_jvrec->setDropOption(edropOption);
			gl_jvrec->setOdbcAttributes(odbcAttributes);
			gl_jvrec->setUpdateInterval(updateInterval);
			gl_jvrec->setCommitInterval(commitInterval);
			gl_jvrec->process(1);
		} break;
		case Rctables::enumAP_SEARCHSRTSET:
		{
			QScopedPointer<AP_SEARCHSRTSET> ap_searchsrtset(new AP_SEARCHSRTSET(nullptr));
			ap_searchsrtset->open(sourceDSN, targetDSN);
			ap_searchsrtset->setRepositoryString(envyRepositoryString);
			ap_searchsrtset->setProfileName(profileName);
			ap_searchsrtset->setReplicationOption(eReplicationOption);
			ap_searchsrtset->setDropOption(edropOption);
			ap_searchsrtset->setOdbcAttributes(odbcAttributes);
			ap_searchsrtset->setUpdateInterval(updateInterval);
			ap_searchsrtset->setCommitInterval(commitInterval);
			ap_searchsrtset->process(1);
		} break;
		case Rctables::enumMA_PRODCOMOSET:
		{
			QScopedPointer<MA_PRODCOMOSET> ma_prodcomoset(new MA_PRODCOMOSET(nullptr));
			ma_prodcomoset->open(sourceDSN, targetDSN);
			ma_prodcomoset->setRepositoryString(envyRepositoryString);
			ma_prodcomoset->setProfileName(profileName);
			ma_prodcomoset->setReplicationOption(eReplicationOption);
			ma_prodcomoset->setDropOption(edropOption);
			ma_prodcomoset->setOdbcAttributes(odbcAttributes);
			ma_prodcomoset->setUpdateInterval(updateInterval);
			ma_prodcomoset->setCommitInterval(commitInterval);
			ma_prodcomoset->process(1);
		} break;
		case Rctables::enumPRTQOHSET:
		{
			QScopedPointer<PRTQOHSET> prtqohset(new PRTQOHSET(nullptr));
			prtqohset->open(sourceDSN, targetDSN);
			prtqohset->setRepositoryString(envyRepositoryString);
			prtqohset->setProfileName(profileName);
			prtqohset->setReplicationOption(eReplicationOption);
			prtqohset->setDropOption(edropOption);
			prtqohset->setOdbcAttributes(odbcAttributes);
			prtqohset->setUpdateInterval(updateInterval);
			prtqohset->setCommitInterval(commitInterval);
			prtqohset->process(1);
		} break;
		case Rctables::enumPONREC:
		{
			QScopedPointer<PONREC> ponrec(new PONREC(nullptr));
			ponrec->open(sourceDSN, targetDSN);
			ponrec->setRepositoryString(envyRepositoryString);
			ponrec->setProfileName(profileName);
			ponrec->setReplicationOption(eReplicationOption);
			ponrec->setDropOption(edropOption);
			ponrec->setOdbcAttributes(odbcAttributes);
			ponrec->setUpdateInterval(updateInterval);
			ponrec->setCommitInterval(commitInterval);
			ponrec->process(1);
		} break;
		case Rctables::enumBORREC:
		{
			QScopedPointer<BORREC> borrec(new BORREC(nullptr));
			borrec->open(sourceDSN, targetDSN);
			borrec->setRepositoryString(envyRepositoryString);
			borrec->setProfileName(profileName);
			borrec->setReplicationOption(eReplicationOption);
			borrec->setDropOption(edropOption);
			borrec->setOdbcAttributes(odbcAttributes);
			borrec->setUpdateInterval(updateInterval);
			borrec->setCommitInterval(commitInterval);
			borrec->process(1);
		} break;
		case Rctables::enumMA_PARTREC:
		{
			QScopedPointer<MA_PARTREC> ma_partrec(new MA_PARTREC(nullptr));
			ma_partrec->open(sourceDSN, targetDSN);
			ma_partrec->setRepositoryString(envyRepositoryString);
			ma_partrec->setProfileName(profileName);
			ma_partrec->setReplicationOption(eReplicationOption);
			ma_partrec->setDropOption(edropOption);
			ma_partrec->setOdbcAttributes(odbcAttributes);
			ma_partrec->setUpdateInterval(updateInterval);
			ma_partrec->setCommitInterval(commitInterval);
			ma_partrec->process(1);
		} break;
		case Rctables::enumECCREC:
		{
			QScopedPointer<ECCREC> eccrec(new ECCREC(nullptr));
			eccrec->open(sourceDSN, targetDSN);
			eccrec->setRepositoryString(envyRepositoryString);
			eccrec->setProfileName(profileName);
			eccrec->setReplicationOption(eReplicationOption);
			eccrec->setDropOption(edropOption);
			eccrec->setOdbcAttributes(odbcAttributes);
			eccrec->setUpdateInterval(updateInterval);
			eccrec->setCommitInterval(commitInterval);
			eccrec->process(1);
		} break;
		case Rctables::enumMA_SODQUODSET:
		{
			QScopedPointer<MA_SODQUODSET> ma_sodquodset(new MA_SODQUODSET(nullptr));
			ma_sodquodset->open(sourceDSN, targetDSN);
			ma_sodquodset->setRepositoryString(envyRepositoryString);
			ma_sodquodset->setProfileName(profileName);
			ma_sodquodset->setReplicationOption(eReplicationOption);
			ma_sodquodset->setDropOption(edropOption);
			ma_sodquodset->setOdbcAttributes(odbcAttributes);
			ma_sodquodset->setUpdateInterval(updateInterval);
			ma_sodquodset->setCommitInterval(commitInterval);
			ma_sodquodset->process(1);
		} break;
		case Rctables::enumMA_CMDMREC:
		{
			QScopedPointer<MA_CMDMREC> ma_cmdmrec(new MA_CMDMREC(nullptr));
			ma_cmdmrec->open(sourceDSN, targetDSN);
			ma_cmdmrec->setRepositoryString(envyRepositoryString);
			ma_cmdmrec->setProfileName(profileName);
			ma_cmdmrec->setReplicationOption(eReplicationOption);
			ma_cmdmrec->setDropOption(edropOption);
			ma_cmdmrec->setOdbcAttributes(odbcAttributes);
			ma_cmdmrec->setUpdateInterval(updateInterval);
			ma_cmdmrec->setCommitInterval(commitInterval);
			ma_cmdmrec->process(1);
		} break;
		case Rctables::enumAP_VNDVCHSET:
		{
			QScopedPointer<AP_VNDVCHSET> ap_vndvchset(new AP_VNDVCHSET(nullptr));
			ap_vndvchset->open(sourceDSN, targetDSN);
			ap_vndvchset->setRepositoryString(envyRepositoryString);
			ap_vndvchset->setProfileName(profileName);
			ap_vndvchset->setReplicationOption(eReplicationOption);
			ap_vndvchset->setDropOption(edropOption);
			ap_vndvchset->setOdbcAttributes(odbcAttributes);
			ap_vndvchset->setUpdateInterval(updateInterval);
			ap_vndvchset->setCommitInterval(commitInterval);
			ap_vndvchset->process(1);
		} break;
		case Rctables::enumPRTHSHSET:
		{
			QScopedPointer<PRTHSHSET> prthshset(new PRTHSHSET(nullptr));
			prthshset->open(sourceDSN, targetDSN);
			prthshset->setRepositoryString(envyRepositoryString);
			prthshset->setProfileName(profileName);
			prthshset->setReplicationOption(eReplicationOption);
			prthshset->setDropOption(edropOption);
			prthshset->setOdbcAttributes(odbcAttributes);
			prthshset->setUpdateInterval(updateInterval);
			prthshset->setCommitInterval(commitInterval);
			prthshset->process(1);
		} break;
		case Rctables::enumMA_STGHSHSET:
		{
			QScopedPointer<MA_STGHSHSET> ma_stghshset(new MA_STGHSHSET(nullptr));
			ma_stghshset->open(sourceDSN, targetDSN);
			ma_stghshset->setRepositoryString(envyRepositoryString);
			ma_stghshset->setProfileName(profileName);
			ma_stghshset->setReplicationOption(eReplicationOption);
			ma_stghshset->setDropOption(edropOption);
			ma_stghshset->setOdbcAttributes(odbcAttributes);
			ma_stghshset->setUpdateInterval(updateInterval);
			ma_stghshset->setCommitInterval(commitInterval);
			ma_stghshset->process(1);
		} break;
		case Rctables::enumGL_FPOFFACCTSET:
		{
			QScopedPointer<GL_FPOFFACCTSET> gl_fpoffacctset(new GL_FPOFFACCTSET(nullptr));
			gl_fpoffacctset->open(sourceDSN, targetDSN);
			gl_fpoffacctset->setRepositoryString(envyRepositoryString);
			gl_fpoffacctset->setProfileName(profileName);
			gl_fpoffacctset->setReplicationOption(eReplicationOption);
			gl_fpoffacctset->setDropOption(edropOption);
			gl_fpoffacctset->setOdbcAttributes(odbcAttributes);
			gl_fpoffacctset->setUpdateInterval(updateInterval);
			gl_fpoffacctset->setCommitInterval(commitInterval);
			gl_fpoffacctset->process(1);
		} break;
		case Rctables::enumMA_PARTOPTSET:
		{
			QScopedPointer<MA_PARTOPTSET> ma_partoptset(new MA_PARTOPTSET(nullptr));
			ma_partoptset->open(sourceDSN, targetDSN);
			ma_partoptset->setRepositoryString(envyRepositoryString);
			ma_partoptset->setProfileName(profileName);
			ma_partoptset->setReplicationOption(eReplicationOption);
			ma_partoptset->setDropOption(edropOption);
			ma_partoptset->setOdbcAttributes(odbcAttributes);
			ma_partoptset->setUpdateInterval(updateInterval);
			ma_partoptset->setCommitInterval(commitInterval);
			ma_partoptset->process(1);
		} break;
		case Rctables::enumFRTHSHSET:
		{
			QScopedPointer<FRTHSHSET> frthshset(new FRTHSHSET(nullptr));
			frthshset->open(sourceDSN, targetDSN);
			frthshset->setRepositoryString(envyRepositoryString);
			frthshset->setProfileName(profileName);
			frthshset->setReplicationOption(eReplicationOption);
			frthshset->setDropOption(edropOption);
			frthshset->setOdbcAttributes(odbcAttributes);
			frthshset->setUpdateInterval(updateInterval);
			frthshset->setCommitInterval(commitInterval);
			frthshset->process(1);
		} break;
		case Rctables::enumGL_CLEARSET:
		{
			QScopedPointer<GL_CLEARSET> gl_clearset(new GL_CLEARSET(nullptr));
			gl_clearset->open(sourceDSN, targetDSN);
			gl_clearset->setRepositoryString(envyRepositoryString);
			gl_clearset->setProfileName(profileName);
			gl_clearset->setReplicationOption(eReplicationOption);
			gl_clearset->setDropOption(edropOption);
			gl_clearset->setOdbcAttributes(odbcAttributes);
			gl_clearset->setUpdateInterval(updateInterval);
			gl_clearset->setCommitInterval(commitInterval);
			gl_clearset->process(1);
		} break;
		case Rctables::enumOPCPRTSET:
		{
			QScopedPointer<OPCPRTSET> opcprtset(new OPCPRTSET(nullptr));
			opcprtset->open(sourceDSN, targetDSN);
			opcprtset->setRepositoryString(envyRepositoryString);
			opcprtset->setProfileName(profileName);
			opcprtset->setReplicationOption(eReplicationOption);
			opcprtset->setDropOption(edropOption);
			opcprtset->setOdbcAttributes(odbcAttributes);
			opcprtset->setUpdateInterval(updateInterval);
			opcprtset->setCommitInterval(commitInterval);
			opcprtset->process(1);
		} break;
		case Rctables::enumLOTHSHSET:
		{
			QScopedPointer<LOTHSHSET> lothshset(new LOTHSHSET(nullptr));
			lothshset->open(sourceDSN, targetDSN);
			lothshset->setRepositoryString(envyRepositoryString);
			lothshset->setProfileName(profileName);
			lothshset->setReplicationOption(eReplicationOption);
			lothshset->setDropOption(edropOption);
			lothshset->setOdbcAttributes(odbcAttributes);
			lothshset->setUpdateInterval(updateInterval);
			lothshset->setCommitInterval(commitInterval);
			lothshset->process(1);
		} break;
		case Rctables::enumMA_SOCATHSHSET:
		{
			QScopedPointer<MA_SOCATHSHSET> ma_socathshset(new MA_SOCATHSHSET(nullptr));
			ma_socathshset->open(sourceDSN, targetDSN);
			ma_socathshset->setRepositoryString(envyRepositoryString);
			ma_socathshset->setProfileName(profileName);
			ma_socathshset->setReplicationOption(eReplicationOption);
			ma_socathshset->setDropOption(edropOption);
			ma_socathshset->setOdbcAttributes(odbcAttributes);
			ma_socathshset->setUpdateInterval(updateInterval);
			ma_socathshset->setCommitInterval(commitInterval);
			ma_socathshset->process(1);
		} break;
		case Rctables::enumGL_OPLINKSET:
		{
			QScopedPointer<GL_OPLINKSET> gl_oplinkset(new GL_OPLINKSET(nullptr));
			gl_oplinkset->open(sourceDSN, targetDSN);
			gl_oplinkset->setRepositoryString(envyRepositoryString);
			gl_oplinkset->setProfileName(profileName);
			gl_oplinkset->setReplicationOption(eReplicationOption);
			gl_oplinkset->setDropOption(edropOption);
			gl_oplinkset->setOdbcAttributes(odbcAttributes);
			gl_oplinkset->setUpdateInterval(updateInterval);
			gl_oplinkset->setCommitInterval(commitInterval);
			gl_oplinkset->process(1);
		} break;
		case Rctables::enumCURREC:
		{
			QScopedPointer<CURREC> currec(new CURREC(nullptr));
			currec->open(sourceDSN, targetDSN);
			currec->setRepositoryString(envyRepositoryString);
			currec->setProfileName(profileName);
			currec->setReplicationOption(eReplicationOption);
			currec->setDropOption(edropOption);
			currec->setOdbcAttributes(odbcAttributes);
			currec->setUpdateInterval(updateInterval);
			currec->setCommitInterval(commitInterval);
			currec->process(1);
		} break;
		case Rctables::enumMA_FRTREC:
		{
			QScopedPointer<MA_FRTREC> ma_frtrec(new MA_FRTREC(nullptr));
			ma_frtrec->open(sourceDSN, targetDSN);
			ma_frtrec->setRepositoryString(envyRepositoryString);
			ma_frtrec->setProfileName(profileName);
			ma_frtrec->setReplicationOption(eReplicationOption);
			ma_frtrec->setDropOption(edropOption);
			ma_frtrec->setOdbcAttributes(odbcAttributes);
			ma_frtrec->setUpdateInterval(updateInterval);
			ma_frtrec->setCommitInterval(commitInterval);
			ma_frtrec->process(1);
		} break;
		case Rctables::enumMA_CMHDMHLSET:
		{
			QScopedPointer<MA_CMHDMHLSET> ma_cmhdmhlset(new MA_CMHDMHLSET(nullptr));
			ma_cmhdmhlset->open(sourceDSN, targetDSN);
			ma_cmhdmhlset->setRepositoryString(envyRepositoryString);
			ma_cmhdmhlset->setProfileName(profileName);
			ma_cmhdmhlset->setReplicationOption(eReplicationOption);
			ma_cmhdmhlset->setDropOption(edropOption);
			ma_cmhdmhlset->setOdbcAttributes(odbcAttributes);
			ma_cmhdmhlset->setUpdateInterval(updateInterval);
			ma_cmhdmhlset->setCommitInterval(commitInterval);
			ma_cmhdmhlset->process(1);
		} break;
		case Rctables::enumGL_VPHSHSET:
		{
			QScopedPointer<GL_VPHSHSET> gl_vphshset(new GL_VPHSHSET(nullptr));
			gl_vphshset->open(sourceDSN, targetDSN);
			gl_vphshset->setRepositoryString(envyRepositoryString);
			gl_vphshset->setProfileName(profileName);
			gl_vphshset->setReplicationOption(eReplicationOption);
			gl_vphshset->setDropOption(edropOption);
			gl_vphshset->setOdbcAttributes(odbcAttributes);
			gl_vphshset->setUpdateInterval(updateInterval);
			gl_vphshset->setCommitInterval(commitInterval);
			gl_vphshset->process(1);
		} break;
		case Rctables::enumPODPOPSET:
		{
			QScopedPointer<PODPOPSET> podpopset(new PODPOPSET(nullptr));
			podpopset->open(sourceDSN, targetDSN);
			podpopset->setRepositoryString(envyRepositoryString);
			podpopset->setProfileName(profileName);
			podpopset->setReplicationOption(eReplicationOption);
			podpopset->setDropOption(edropOption);
			podpopset->setOdbcAttributes(odbcAttributes);
			podpopset->setUpdateInterval(updateInterval);
			podpopset->setCommitInterval(commitInterval);
			podpopset->process(1);
		} break;
		case Rctables::enumED_ENTAUDSET:
		{
			QScopedPointer<ED_ENTAUDSET> ed_entaudset(new ED_ENTAUDSET(nullptr));
			ed_entaudset->open(sourceDSN, targetDSN);
			ed_entaudset->setRepositoryString(envyRepositoryString);
			ed_entaudset->setProfileName(profileName);
			ed_entaudset->setReplicationOption(eReplicationOption);
			ed_entaudset->setDropOption(edropOption);
			ed_entaudset->setOdbcAttributes(odbcAttributes);
			ed_entaudset->setUpdateInterval(updateInterval);
			ed_entaudset->setCommitInterval(commitInterval);
			ed_entaudset->process(1);
		} break;
		case Rctables::enumCDLCOPSET:
		{
			QScopedPointer<CDLCOPSET> cdlcopset(new CDLCOPSET(nullptr));
			cdlcopset->open(sourceDSN, targetDSN);
			cdlcopset->setRepositoryString(envyRepositoryString);
			cdlcopset->setProfileName(profileName);
			cdlcopset->setReplicationOption(eReplicationOption);
			cdlcopset->setDropOption(edropOption);
			cdlcopset->setOdbcAttributes(odbcAttributes);
			cdlcopset->setUpdateInterval(updateInterval);
			cdlcopset->setCommitInterval(commitInterval);
			cdlcopset->process(1);
		} break;
		case Rctables::enumWOHACLSET:
		{
			QScopedPointer<WOHACLSET> wohaclset(new WOHACLSET(nullptr));
			wohaclset->open(sourceDSN, targetDSN);
			wohaclset->setRepositoryString(envyRepositoryString);
			wohaclset->setProfileName(profileName);
			wohaclset->setReplicationOption(eReplicationOption);
			wohaclset->setDropOption(edropOption);
			wohaclset->setOdbcAttributes(odbcAttributes);
			wohaclset->setUpdateInterval(updateInterval);
			wohaclset->setCommitInterval(commitInterval);
			wohaclset->process(1);
		} break;
		case Rctables::enumINVLOCSET:
		{
			QScopedPointer<INVLOCSET> invlocset(new INVLOCSET(nullptr));
			invlocset->open(sourceDSN, targetDSN);
			invlocset->setRepositoryString(envyRepositoryString);
			invlocset->setProfileName(profileName);
			invlocset->setReplicationOption(eReplicationOption);
			invlocset->setDropOption(edropOption);
			invlocset->setOdbcAttributes(odbcAttributes);
			invlocset->setUpdateInterval(updateInterval);
			invlocset->setCommitInterval(commitInterval);
			invlocset->process(1);
		} break;
		case Rctables::enumMA_INHWOPOSTSET:
		{
			QScopedPointer<MA_INHWOPOSTSET> ma_inhwopostset(new MA_INHWOPOSTSET(nullptr));
			ma_inhwopostset->open(sourceDSN, targetDSN);
			ma_inhwopostset->setRepositoryString(envyRepositoryString);
			ma_inhwopostset->setProfileName(profileName);
			ma_inhwopostset->setReplicationOption(eReplicationOption);
			ma_inhwopostset->setDropOption(edropOption);
			ma_inhwopostset->setOdbcAttributes(odbcAttributes);
			ma_inhwopostset->setUpdateInterval(updateInterval);
			ma_inhwopostset->setCommitInterval(commitInterval);
			ma_inhwopostset->process(1);
		} break;
		case Rctables::enumMA_DMHSPISET:
		{
			QScopedPointer<MA_DMHSPISET> ma_dmhspiset(new MA_DMHSPISET(nullptr));
			ma_dmhspiset->open(sourceDSN, targetDSN);
			ma_dmhspiset->setRepositoryString(envyRepositoryString);
			ma_dmhspiset->setProfileName(profileName);
			ma_dmhspiset->setReplicationOption(eReplicationOption);
			ma_dmhspiset->setDropOption(edropOption);
			ma_dmhspiset->setOdbcAttributes(odbcAttributes);
			ma_dmhspiset->setUpdateInterval(updateInterval);
			ma_dmhspiset->setCommitInterval(commitInterval);
			ma_dmhspiset->process(1);
		} break;
		case Rctables::enumMA_BILCMHSET:
		{
			QScopedPointer<MA_BILCMHSET> ma_bilcmhset(new MA_BILCMHSET(nullptr));
			ma_bilcmhset->open(sourceDSN, targetDSN);
			ma_bilcmhset->setRepositoryString(envyRepositoryString);
			ma_bilcmhset->setProfileName(profileName);
			ma_bilcmhset->setReplicationOption(eReplicationOption);
			ma_bilcmhset->setDropOption(edropOption);
			ma_bilcmhset->setOdbcAttributes(odbcAttributes);
			ma_bilcmhset->setUpdateInterval(updateInterval);
			ma_bilcmhset->setCommitInterval(commitInterval);
			ma_bilcmhset->process(1);
		} break;
		case Rctables::enumCPRREC:
		{
			QScopedPointer<CPRREC> cprrec(new CPRREC(nullptr));
			cprrec->open(sourceDSN, targetDSN);
			cprrec->setRepositoryString(envyRepositoryString);
			cprrec->setProfileName(profileName);
			cprrec->setReplicationOption(eReplicationOption);
			cprrec->setDropOption(edropOption);
			cprrec->setOdbcAttributes(odbcAttributes);
			cprrec->setUpdateInterval(updateInterval);
			cprrec->setCommitInterval(commitInterval);
			cprrec->process(1);
		} break;
		case Rctables::enumRCTMREC:
		{
			QScopedPointer<RCTMREC> rctmrec(new RCTMREC(nullptr));
			rctmrec->open(sourceDSN, targetDSN);
			rctmrec->setRepositoryString(envyRepositoryString);
			rctmrec->setProfileName(profileName);
			rctmrec->setReplicationOption(eReplicationOption);
			rctmrec->setDropOption(edropOption);
			rctmrec->setOdbcAttributes(odbcAttributes);
			rctmrec->setUpdateInterval(updateInterval);
			rctmrec->setCommitInterval(commitInterval);
			rctmrec->process(1);
		} break;
		case Rctables::enumMA_PRODGLTABSET:
		{
			QScopedPointer<MA_PRODGLTABSET> ma_prodgltabset(new MA_PRODGLTABSET(nullptr));
			ma_prodgltabset->open(sourceDSN, targetDSN);
			ma_prodgltabset->setRepositoryString(envyRepositoryString);
			ma_prodgltabset->setProfileName(profileName);
			ma_prodgltabset->setReplicationOption(eReplicationOption);
			ma_prodgltabset->setDropOption(edropOption);
			ma_prodgltabset->setOdbcAttributes(odbcAttributes);
			ma_prodgltabset->setUpdateInterval(updateInterval);
			ma_prodgltabset->setCommitInterval(commitInterval);
			ma_prodgltabset->process(1);
		} break;
		case Rctables::enumMA_INHHSHSET:
		{
			QScopedPointer<MA_INHHSHSET> ma_inhhshset(new MA_INHHSHSET(nullptr));
			ma_inhhshset->open(sourceDSN, targetDSN);
			ma_inhhshset->setRepositoryString(envyRepositoryString);
			ma_inhhshset->setProfileName(profileName);
			ma_inhhshset->setReplicationOption(eReplicationOption);
			ma_inhhshset->setDropOption(edropOption);
			ma_inhhshset->setOdbcAttributes(odbcAttributes);
			ma_inhhshset->setUpdateInterval(updateInterval);
			ma_inhhshset->setCommitInterval(commitInterval);
			ma_inhhshset->process(1);
		} break;
		case Rctables::enumCOHHSHSET:
		{
			QScopedPointer<COHHSHSET> cohhshset(new COHHSHSET(nullptr));
			cohhshset->open(sourceDSN, targetDSN);
			cohhshset->setRepositoryString(envyRepositoryString);
			cohhshset->setProfileName(profileName);
			cohhshset->setReplicationOption(eReplicationOption);
			cohhshset->setDropOption(edropOption);
			cohhshset->setOdbcAttributes(odbcAttributes);
			cohhshset->setUpdateInterval(updateInterval);
			cohhshset->setCommitInterval(commitInterval);
			cohhshset->process(1);
		} break;
		case Rctables::enumGL_LINKDESCSET:
		{
			QScopedPointer<GL_LINKDESCSET> gl_linkdescset(new GL_LINKDESCSET(nullptr));
			gl_linkdescset->open(sourceDSN, targetDSN);
			gl_linkdescset->setRepositoryString(envyRepositoryString);
			gl_linkdescset->setProfileName(profileName);
			gl_linkdescset->setReplicationOption(eReplicationOption);
			gl_linkdescset->setDropOption(edropOption);
			gl_linkdescset->setOdbcAttributes(odbcAttributes);
			gl_linkdescset->setUpdateInterval(updateInterval);
			gl_linkdescset->setCommitInterval(commitInterval);
			gl_linkdescset->process(1);
		} break;
		case Rctables::enumWIPRATSET:
		{
			QScopedPointer<WIPRATSET> wipratset(new WIPRATSET(nullptr));
			wipratset->open(sourceDSN, targetDSN);
			wipratset->setRepositoryString(envyRepositoryString);
			wipratset->setProfileName(profileName);
			wipratset->setReplicationOption(eReplicationOption);
			wipratset->setDropOption(edropOption);
			wipratset->setOdbcAttributes(odbcAttributes);
			wipratset->setUpdateInterval(updateInterval);
			wipratset->setCommitInterval(commitInterval);
			wipratset->process(1);
		} break;
		case Rctables::enumVMCHSHSET:
		{
			QScopedPointer<VMCHSHSET> vmchshset(new VMCHSHSET(nullptr));
			vmchshset->open(sourceDSN, targetDSN);
			vmchshset->setRepositoryString(envyRepositoryString);
			vmchshset->setProfileName(profileName);
			vmchshset->setReplicationOption(eReplicationOption);
			vmchshset->setDropOption(edropOption);
			vmchshset->setOdbcAttributes(odbcAttributes);
			vmchshset->setUpdateInterval(updateInterval);
			vmchshset->setCommitInterval(commitInterval);
			vmchshset->process(1);
		} break;
		case Rctables::enumPRTSRTSET:
		{
			QScopedPointer<PRTSRTSET> prtsrtset(new PRTSRTSET(nullptr));
			prtsrtset->open(sourceDSN, targetDSN);
			prtsrtset->setRepositoryString(envyRepositoryString);
			prtsrtset->setProfileName(profileName);
			prtsrtset->setReplicationOption(eReplicationOption);
			prtsrtset->setDropOption(edropOption);
			prtsrtset->setOdbcAttributes(odbcAttributes);
			prtsrtset->setUpdateInterval(updateInterval);
			prtsrtset->setCommitInterval(commitInterval);
			prtsrtset->process(1);
		} break;
		case Rctables::enumLOTACSTSET:
		{
			QScopedPointer<LOTACSTSET> lotacstset(new LOTACSTSET(nullptr));
			lotacstset->open(sourceDSN, targetDSN);
			lotacstset->setRepositoryString(envyRepositoryString);
			lotacstset->setProfileName(profileName);
			lotacstset->setReplicationOption(eReplicationOption);
			lotacstset->setDropOption(edropOption);
			lotacstset->setOdbcAttributes(odbcAttributes);
			lotacstset->setUpdateInterval(updateInterval);
			lotacstset->setCommitInterval(commitInterval);
			lotacstset->process(1);
		} break;
		case Rctables::enumMA_CHGDCOMCLSET:
		{
			QScopedPointer<MA_CHGDCOMCLSET> ma_chgdcomclset(new MA_CHGDCOMCLSET(nullptr));
			ma_chgdcomclset->open(sourceDSN, targetDSN);
			ma_chgdcomclset->setRepositoryString(envyRepositoryString);
			ma_chgdcomclset->setProfileName(profileName);
			ma_chgdcomclset->setReplicationOption(eReplicationOption);
			ma_chgdcomclset->setDropOption(edropOption);
			ma_chgdcomclset->setOdbcAttributes(odbcAttributes);
			ma_chgdcomclset->setUpdateInterval(updateInterval);
			ma_chgdcomclset->setCommitInterval(commitInterval);
			ma_chgdcomclset->process(1);
		} break;
		case Rctables::enumED_ENTPRDXRFSET:
		{
			QScopedPointer<ED_ENTPRDXRFSET> ed_entprdxrfset(new ED_ENTPRDXRFSET(nullptr));
			ed_entprdxrfset->open(sourceDSN, targetDSN);
			ed_entprdxrfset->setRepositoryString(envyRepositoryString);
			ed_entprdxrfset->setProfileName(profileName);
			ed_entprdxrfset->setReplicationOption(eReplicationOption);
			ed_entprdxrfset->setDropOption(edropOption);
			ed_entprdxrfset->setOdbcAttributes(odbcAttributes);
			ed_entprdxrfset->setUpdateInterval(updateInterval);
			ed_entprdxrfset->setCommitInterval(commitInterval);
			ed_entprdxrfset->process(1);
		} break;
		case Rctables::enumFA_ACCTREC:
		{
			QScopedPointer<FA_ACCTREC> fa_acctrec(new FA_ACCTREC(nullptr));
			fa_acctrec->open(sourceDSN, targetDSN);
			fa_acctrec->setRepositoryString(envyRepositoryString);
			fa_acctrec->setProfileName(profileName);
			fa_acctrec->setReplicationOption(eReplicationOption);
			fa_acctrec->setDropOption(edropOption);
			fa_acctrec->setOdbcAttributes(odbcAttributes);
			fa_acctrec->setUpdateInterval(updateInterval);
			fa_acctrec->setCommitInterval(commitInterval);
			fa_acctrec->process(1);
		} break;
		case Rctables::enumMFGSET:
		{
			QScopedPointer<MFGSET> mfgset(new MFGSET(nullptr));
			mfgset->open(sourceDSN, targetDSN);
			mfgset->setRepositoryString(envyRepositoryString);
			mfgset->setProfileName(profileName);
			mfgset->setReplicationOption(eReplicationOption);
			mfgset->setDropOption(edropOption);
			mfgset->setOdbcAttributes(odbcAttributes);
			mfgset->setUpdateInterval(updateInterval);
			mfgset->setCommitInterval(commitInterval);
			mfgset->process(1);
		} break;
		case Rctables::enumMA_APCREC:
		{
			QScopedPointer<MA_APCREC> ma_apcrec(new MA_APCREC(nullptr));
			ma_apcrec->open(sourceDSN, targetDSN);
			ma_apcrec->setRepositoryString(envyRepositoryString);
			ma_apcrec->setProfileName(profileName);
			ma_apcrec->setReplicationOption(eReplicationOption);
			ma_apcrec->setDropOption(edropOption);
			ma_apcrec->setOdbcAttributes(odbcAttributes);
			ma_apcrec->setUpdateInterval(updateInterval);
			ma_apcrec->setCommitInterval(commitInterval);
			ma_apcrec->process(1);
		} break;
		case Rctables::enumPODDELSET:
		{
			QScopedPointer<PODDELSET> poddelset(new PODDELSET(nullptr));
			poddelset->open(sourceDSN, targetDSN);
			poddelset->setRepositoryString(envyRepositoryString);
			poddelset->setProfileName(profileName);
			poddelset->setReplicationOption(eReplicationOption);
			poddelset->setDropOption(edropOption);
			poddelset->setOdbcAttributes(odbcAttributes);
			poddelset->setUpdateInterval(updateInterval);
			poddelset->setCommitInterval(commitInterval);
			poddelset->process(1);
		} break;
		case Rctables::enumECOSET:
		{
			QScopedPointer<ECOSET> ecoset(new ECOSET(nullptr));
			ecoset->open(sourceDSN, targetDSN);
			ecoset->setRepositoryString(envyRepositoryString);
			ecoset->setProfileName(profileName);
			ecoset->setReplicationOption(eReplicationOption);
			ecoset->setDropOption(edropOption);
			ecoset->setOdbcAttributes(odbcAttributes);
			ecoset->setUpdateInterval(updateInterval);
			ecoset->setCommitInterval(commitInterval);
			ecoset->process(1);
		} break;
		case Rctables::enumCDAREC:
		{
			QScopedPointer<CDAREC> cdarec(new CDAREC(nullptr));
			cdarec->open(sourceDSN, targetDSN);
			cdarec->setRepositoryString(envyRepositoryString);
			cdarec->setProfileName(profileName);
			cdarec->setReplicationOption(eReplicationOption);
			cdarec->setDropOption(edropOption);
			cdarec->setOdbcAttributes(odbcAttributes);
			cdarec->setUpdateInterval(updateInterval);
			cdarec->setCommitInterval(commitInterval);
			cdarec->process(1);
		} break;
		case Rctables::enumMA_PLINPRODSET:
		{
			QScopedPointer<MA_PLINPRODSET> ma_plinprodset(new MA_PLINPRODSET(nullptr));
			ma_plinprodset->open(sourceDSN, targetDSN);
			ma_plinprodset->setRepositoryString(envyRepositoryString);
			ma_plinprodset->setProfileName(profileName);
			ma_plinprodset->setReplicationOption(eReplicationOption);
			ma_plinprodset->setDropOption(edropOption);
			ma_plinprodset->setOdbcAttributes(odbcAttributes);
			ma_plinprodset->setUpdateInterval(updateInterval);
			ma_plinprodset->setCommitInterval(commitInterval);
			ma_plinprodset->process(1);
		} break;
		case Rctables::enumMA_CHGHHSHSET:
		{
			QScopedPointer<MA_CHGHHSHSET> ma_chghhshset(new MA_CHGHHSHSET(nullptr));
			ma_chghhshset->open(sourceDSN, targetDSN);
			ma_chghhshset->setRepositoryString(envyRepositoryString);
			ma_chghhshset->setProfileName(profileName);
			ma_chghhshset->setReplicationOption(eReplicationOption);
			ma_chghhshset->setDropOption(edropOption);
			ma_chghhshset->setOdbcAttributes(odbcAttributes);
			ma_chghhshset->setUpdateInterval(updateInterval);
			ma_chghhshset->setCommitInterval(commitInterval);
			ma_chghhshset->process(1);
		} break;
		case Rctables::enumAP_POPREC:
		{
			QScopedPointer<AP_POPREC> ap_poprec(new AP_POPREC(nullptr));
			ap_poprec->open(sourceDSN, targetDSN);
			ap_poprec->setRepositoryString(envyRepositoryString);
			ap_poprec->setProfileName(profileName);
			ap_poprec->setReplicationOption(eReplicationOption);
			ap_poprec->setDropOption(edropOption);
			ap_poprec->setOdbcAttributes(odbcAttributes);
			ap_poprec->setUpdateInterval(updateInterval);
			ap_poprec->setCommitInterval(commitInterval);
			ap_poprec->process(1);
		} break;
		case Rctables::enumAP_PROJPOSTSET:
		{
			QScopedPointer<AP_PROJPOSTSET> ap_projpostset(new AP_PROJPOSTSET(nullptr));
			ap_projpostset->open(sourceDSN, targetDSN);
			ap_projpostset->setRepositoryString(envyRepositoryString);
			ap_projpostset->setProfileName(profileName);
			ap_projpostset->setReplicationOption(eReplicationOption);
			ap_projpostset->setDropOption(edropOption);
			ap_projpostset->setOdbcAttributes(odbcAttributes);
			ap_projpostset->setUpdateInterval(updateInterval);
			ap_projpostset->setCommitInterval(commitInterval);
			ap_projpostset->process(1);
		} break;
		case Rctables::enumMA_PFAMPLINSET:
		{
			QScopedPointer<MA_PFAMPLINSET> ma_pfamplinset(new MA_PFAMPLINSET(nullptr));
			ma_pfamplinset->open(sourceDSN, targetDSN);
			ma_pfamplinset->setRepositoryString(envyRepositoryString);
			ma_pfamplinset->setProfileName(profileName);
			ma_pfamplinset->setReplicationOption(eReplicationOption);
			ma_pfamplinset->setDropOption(edropOption);
			ma_pfamplinset->setOdbcAttributes(odbcAttributes);
			ma_pfamplinset->setUpdateInterval(updateInterval);
			ma_pfamplinset->setCommitInterval(commitInterval);
			ma_pfamplinset->process(1);
		} break;
		case Rctables::enumWARREC:
		{
			QScopedPointer<WARREC> warrec(new WARREC(nullptr));
			warrec->open(sourceDSN, targetDSN);
			warrec->setRepositoryString(envyRepositoryString);
			warrec->setProfileName(profileName);
			warrec->setReplicationOption(eReplicationOption);
			warrec->setDropOption(edropOption);
			warrec->setOdbcAttributes(odbcAttributes);
			warrec->setUpdateInterval(updateInterval);
			warrec->setCommitInterval(commitInterval);
			warrec->process(1);
		} break;
		case Rctables::enumCUREXREC:
		{
			QScopedPointer<CUREXREC> curexrec(new CUREXREC(nullptr));
			curexrec->open(sourceDSN, targetDSN);
			curexrec->setRepositoryString(envyRepositoryString);
			curexrec->setProfileName(profileName);
			curexrec->setReplicationOption(eReplicationOption);
			curexrec->setDropOption(edropOption);
			curexrec->setOdbcAttributes(odbcAttributes);
			curexrec->setUpdateInterval(updateInterval);
			curexrec->setCommitInterval(commitInterval);
			curexrec->process(1);
		} break;
		case Rctables::enumRQDREC:
		{
			QScopedPointer<RQDREC> rqdrec(new RQDREC(nullptr));
			rqdrec->open(sourceDSN, targetDSN);
			rqdrec->setRepositoryString(envyRepositoryString);
			rqdrec->setProfileName(profileName);
			rqdrec->setReplicationOption(eReplicationOption);
			rqdrec->setDropOption(edropOption);
			rqdrec->setOdbcAttributes(odbcAttributes);
			rqdrec->setUpdateInterval(updateInterval);
			rqdrec->setCommitInterval(commitInterval);
			rqdrec->process(1);
		} break;
		case Rctables::enumPOHHSHSET:
		{
			QScopedPointer<POHHSHSET> pohhshset(new POHHSHSET(nullptr));
			pohhshset->open(sourceDSN, targetDSN);
			pohhshset->setRepositoryString(envyRepositoryString);
			pohhshset->setProfileName(profileName);
			pohhshset->setReplicationOption(eReplicationOption);
			pohhshset->setDropOption(edropOption);
			pohhshset->setOdbcAttributes(odbcAttributes);
			pohhshset->setUpdateInterval(updateInterval);
			pohhshset->setCommitInterval(commitInterval);
			pohhshset->process(1);
		} break;
		case Rctables::enumPRTREC:
		{
			QScopedPointer<PRTREC> prtrec(new PRTREC(nullptr));
			prtrec->open(sourceDSN, targetDSN);
			prtrec->setRepositoryString(envyRepositoryString);
			prtrec->setProfileName(profileName);
			prtrec->setReplicationOption(eReplicationOption);
			prtrec->setDropOption(edropOption);
			prtrec->setOdbcAttributes(odbcAttributes);
			prtrec->setUpdateInterval(updateInterval);
			prtrec->setCommitInterval(commitInterval);
			prtrec->process(1);
		} break;
		case Rctables::enumAP_BNKHSHSET:
		{
			QScopedPointer<AP_BNKHSHSET> ap_bnkhshset(new AP_BNKHSHSET(nullptr));
			ap_bnkhshset->open(sourceDSN, targetDSN);
			ap_bnkhshset->setRepositoryString(envyRepositoryString);
			ap_bnkhshset->setProfileName(profileName);
			ap_bnkhshset->setReplicationOption(eReplicationOption);
			ap_bnkhshset->setDropOption(edropOption);
			ap_bnkhshset->setOdbcAttributes(odbcAttributes);
			ap_bnkhshset->setUpdateInterval(updateInterval);
			ap_bnkhshset->setCommitInterval(commitInterval);
			ap_bnkhshset->process(1);
		} break;
		case Rctables::enumACTPOSET:
		{
			QScopedPointer<ACTPOSET> actposet(new ACTPOSET(nullptr));
			actposet->open(sourceDSN, targetDSN);
			actposet->setRepositoryString(envyRepositoryString);
			actposet->setProfileName(profileName);
			actposet->setReplicationOption(eReplicationOption);
			actposet->setDropOption(edropOption);
			actposet->setOdbcAttributes(odbcAttributes);
			actposet->setUpdateInterval(updateInterval);
			actposet->setCommitInterval(commitInterval);
			actposet->process(1);
		} break;
		case Rctables::enumMA_BILSREC:
		{
			QScopedPointer<MA_BILSREC> ma_bilsrec(new MA_BILSREC(nullptr));
			ma_bilsrec->open(sourceDSN, targetDSN);
			ma_bilsrec->setRepositoryString(envyRepositoryString);
			ma_bilsrec->setProfileName(profileName);
			ma_bilsrec->setReplicationOption(eReplicationOption);
			ma_bilsrec->setDropOption(edropOption);
			ma_bilsrec->setOdbcAttributes(odbcAttributes);
			ma_bilsrec->setUpdateInterval(updateInterval);
			ma_bilsrec->setCommitInterval(commitInterval);
			ma_bilsrec->process(1);
		} break;
		case Rctables::enumMTRREC:
		{
			QScopedPointer<MTRREC> mtrrec(new MTRREC(nullptr));
			mtrrec->open(sourceDSN, targetDSN);
			mtrrec->setRepositoryString(envyRepositoryString);
			mtrrec->setProfileName(profileName);
			mtrrec->setReplicationOption(eReplicationOption);
			mtrrec->setDropOption(edropOption);
			mtrrec->setOdbcAttributes(odbcAttributes);
			mtrrec->setUpdateInterval(updateInterval);
			mtrrec->setCommitInterval(commitInterval);
			mtrrec->process(1);
		} break;
		case Rctables::enumAP_POHPOHSET:
		{
			QScopedPointer<AP_POHPOHSET> ap_pohpohset(new AP_POHPOHSET(nullptr));
			ap_pohpohset->open(sourceDSN, targetDSN);
			ap_pohpohset->setRepositoryString(envyRepositoryString);
			ap_pohpohset->setProfileName(profileName);
			ap_pohpohset->setReplicationOption(eReplicationOption);
			ap_pohpohset->setDropOption(edropOption);
			ap_pohpohset->setOdbcAttributes(odbcAttributes);
			ap_pohpohset->setUpdateInterval(updateInterval);
			ap_pohpohset->setCommitInterval(commitInterval);
			ap_pohpohset->process(1);
		} break;
		case Rctables::enumSPDSET:
		{
			QScopedPointer<SPDSET> spdset(new SPDSET(nullptr));
			spdset->open(sourceDSN, targetDSN);
			spdset->setRepositoryString(envyRepositoryString);
			spdset->setProfileName(profileName);
			spdset->setReplicationOption(eReplicationOption);
			spdset->setDropOption(edropOption);
			spdset->setOdbcAttributes(odbcAttributes);
			spdset->setUpdateInterval(updateInterval);
			spdset->setCommitInterval(commitInterval);
			spdset->process(1);
		} break;
		case Rctables::enumMA_BILINHSET:
		{
			QScopedPointer<MA_BILINHSET> ma_bilinhset(new MA_BILINHSET(nullptr));
			ma_bilinhset->open(sourceDSN, targetDSN);
			ma_bilinhset->setRepositoryString(envyRepositoryString);
			ma_bilinhset->setProfileName(profileName);
			ma_bilinhset->setReplicationOption(eReplicationOption);
			ma_bilinhset->setDropOption(edropOption);
			ma_bilinhset->setOdbcAttributes(odbcAttributes);
			ma_bilinhset->setUpdateInterval(updateInterval);
			ma_bilinhset->setCommitInterval(commitInterval);
			ma_bilinhset->process(1);
		} break;
		case Rctables::enumMA_FRTTREC:
		{
			QScopedPointer<MA_FRTTREC> ma_frttrec(new MA_FRTTREC(nullptr));
			ma_frttrec->open(sourceDSN, targetDSN);
			ma_frttrec->setRepositoryString(envyRepositoryString);
			ma_frttrec->setProfileName(profileName);
			ma_frttrec->setReplicationOption(eReplicationOption);
			ma_frttrec->setDropOption(edropOption);
			ma_frttrec->setOdbcAttributes(odbcAttributes);
			ma_frttrec->setUpdateInterval(updateInterval);
			ma_frttrec->setCommitInterval(commitInterval);
			ma_frttrec->process(1);
		} break;
		case Rctables::enumMA_DMHSPNLSET:
		{
			QScopedPointer<MA_DMHSPNLSET> ma_dmhspnlset(new MA_DMHSPNLSET(nullptr));
			ma_dmhspnlset->open(sourceDSN, targetDSN);
			ma_dmhspnlset->setRepositoryString(envyRepositoryString);
			ma_dmhspnlset->setProfileName(profileName);
			ma_dmhspnlset->setReplicationOption(eReplicationOption);
			ma_dmhspnlset->setDropOption(edropOption);
			ma_dmhspnlset->setOdbcAttributes(odbcAttributes);
			ma_dmhspnlset->setUpdateInterval(updateInterval);
			ma_dmhspnlset->setCommitInterval(commitInterval);
			ma_dmhspnlset->process(1);
		} break;
		case Rctables::enumEMPHSHSET:
		{
			QScopedPointer<EMPHSHSET> emphshset(new EMPHSHSET(nullptr));
			emphshset->open(sourceDSN, targetDSN);
			emphshset->setRepositoryString(envyRepositoryString);
			emphshset->setProfileName(profileName);
			emphshset->setReplicationOption(eReplicationOption);
			emphshset->setDropOption(edropOption);
			emphshset->setOdbcAttributes(odbcAttributes);
			emphshset->setUpdateInterval(updateInterval);
			emphshset->setCommitInterval(commitInterval);
			emphshset->process(1);
		} break;
		case Rctables::enumACTDLSET:
		{
			QScopedPointer<ACTDLSET> actdlset(new ACTDLSET(nullptr));
			actdlset->open(sourceDSN, targetDSN);
			actdlset->setRepositoryString(envyRepositoryString);
			actdlset->setProfileName(profileName);
			actdlset->setReplicationOption(eReplicationOption);
			actdlset->setDropOption(edropOption);
			actdlset->setOdbcAttributes(odbcAttributes);
			actdlset->setUpdateInterval(updateInterval);
			actdlset->setCommitInterval(commitInterval);
			actdlset->process(1);
		} break;
		case Rctables::enumGL_FPTOPROJSET:
		{
			QScopedPointer<GL_FPTOPROJSET> gl_fptoprojset(new GL_FPTOPROJSET(nullptr));
			gl_fptoprojset->open(sourceDSN, targetDSN);
			gl_fptoprojset->setRepositoryString(envyRepositoryString);
			gl_fptoprojset->setProfileName(profileName);
			gl_fptoprojset->setReplicationOption(eReplicationOption);
			gl_fptoprojset->setDropOption(edropOption);
			gl_fptoprojset->setOdbcAttributes(odbcAttributes);
			gl_fptoprojset->setUpdateInterval(updateInterval);
			gl_fptoprojset->setCommitInterval(commitInterval);
			gl_fptoprojset->process(1);
		} break;
		case Rctables::enumMA_INTHSHSET:
		{
			QScopedPointer<MA_INTHSHSET> ma_inthshset(new MA_INTHSHSET(nullptr));
			ma_inthshset->open(sourceDSN, targetDSN);
			ma_inthshset->setRepositoryString(envyRepositoryString);
			ma_inthshset->setProfileName(profileName);
			ma_inthshset->setReplicationOption(eReplicationOption);
			ma_inthshset->setDropOption(edropOption);
			ma_inthshset->setOdbcAttributes(odbcAttributes);
			ma_inthshset->setUpdateInterval(updateInterval);
			ma_inthshset->setCommitInterval(commitInterval);
			ma_inthshset->process(1);
		} break;
		case Rctables::enumGL_VPNUMSET:
		{
			QScopedPointer<GL_VPNUMSET> gl_vpnumset(new GL_VPNUMSET(nullptr));
			gl_vpnumset->open(sourceDSN, targetDSN);
			gl_vpnumset->setRepositoryString(envyRepositoryString);
			gl_vpnumset->setProfileName(profileName);
			gl_vpnumset->setReplicationOption(eReplicationOption);
			gl_vpnumset->setDropOption(edropOption);
			gl_vpnumset->setOdbcAttributes(odbcAttributes);
			gl_vpnumset->setUpdateInterval(updateInterval);
			gl_vpnumset->setCommitInterval(commitInterval);
			gl_vpnumset->process(1);
		} break;
		case Rctables::enumGL_PROJPOSTSET:
		{
			QScopedPointer<GL_PROJPOSTSET> gl_projpostset(new GL_PROJPOSTSET(nullptr));
			gl_projpostset->open(sourceDSN, targetDSN);
			gl_projpostset->setRepositoryString(envyRepositoryString);
			gl_projpostset->setProfileName(profileName);
			gl_projpostset->setReplicationOption(eReplicationOption);
			gl_projpostset->setDropOption(edropOption);
			gl_projpostset->setOdbcAttributes(odbcAttributes);
			gl_projpostset->setUpdateInterval(updateInterval);
			gl_projpostset->setCommitInterval(commitInterval);
			gl_projpostset->process(1);
		} break;
		case Rctables::enumPOHBOLLSET:
		{
			QScopedPointer<POHBOLLSET> pohbollset(new POHBOLLSET(nullptr));
			pohbollset->open(sourceDSN, targetDSN);
			pohbollset->setRepositoryString(envyRepositoryString);
			pohbollset->setProfileName(profileName);
			pohbollset->setReplicationOption(eReplicationOption);
			pohbollset->setDropOption(edropOption);
			pohbollset->setOdbcAttributes(odbcAttributes);
			pohbollset->setUpdateInterval(updateInterval);
			pohbollset->setCommitInterval(commitInterval);
			pohbollset->process(1);
		} break;
		case Rctables::enumGL_MOLINKSET:
		{
			QScopedPointer<GL_MOLINKSET> gl_molinkset(new GL_MOLINKSET(nullptr));
			gl_molinkset->open(sourceDSN, targetDSN);
			gl_molinkset->setRepositoryString(envyRepositoryString);
			gl_molinkset->setProfileName(profileName);
			gl_molinkset->setReplicationOption(eReplicationOption);
			gl_molinkset->setDropOption(edropOption);
			gl_molinkset->setOdbcAttributes(odbcAttributes);
			gl_molinkset->setUpdateInterval(updateInterval);
			gl_molinkset->setCommitInterval(commitInterval);
			gl_molinkset->process(1);
		} break;
		case Rctables::enumMA_SERHSHSET:
		{
			QScopedPointer<MA_SERHSHSET> ma_serhshset(new MA_SERHSHSET(nullptr));
			ma_serhshset->open(sourceDSN, targetDSN);
			ma_serhshset->setRepositoryString(envyRepositoryString);
			ma_serhshset->setProfileName(profileName);
			ma_serhshset->setReplicationOption(eReplicationOption);
			ma_serhshset->setDropOption(edropOption);
			ma_serhshset->setOdbcAttributes(odbcAttributes);
			ma_serhshset->setUpdateInterval(updateInterval);
			ma_serhshset->setCommitInterval(commitInterval);
			ma_serhshset->process(1);
		} break;
		case Rctables::enumBOLHSHSET:
		{
			QScopedPointer<BOLHSHSET> bolhshset(new BOLHSHSET(nullptr));
			bolhshset->open(sourceDSN, targetDSN);
			bolhshset->setRepositoryString(envyRepositoryString);
			bolhshset->setProfileName(profileName);
			bolhshset->setReplicationOption(eReplicationOption);
			bolhshset->setDropOption(edropOption);
			bolhshset->setOdbcAttributes(odbcAttributes);
			bolhshset->setUpdateInterval(updateInterval);
			bolhshset->setCommitInterval(commitInterval);
			bolhshset->process(1);
		} break;
		case Rctables::enumED_PRDXRFREC:
		{
			QScopedPointer<ED_PRDXRFREC> ed_prdxrfrec(new ED_PRDXRFREC(nullptr));
			ed_prdxrfrec->open(sourceDSN, targetDSN);
			ed_prdxrfrec->setRepositoryString(envyRepositoryString);
			ed_prdxrfrec->setProfileName(profileName);
			ed_prdxrfrec->setReplicationOption(eReplicationOption);
			ed_prdxrfrec->setDropOption(edropOption);
			ed_prdxrfrec->setOdbcAttributes(odbcAttributes);
			ed_prdxrfrec->setUpdateInterval(updateInterval);
			ed_prdxrfrec->setCommitInterval(commitInterval);
			ed_prdxrfrec->process(1);
		} break;
		case Rctables::enumGL_FOLINKSET:
		{
			QScopedPointer<GL_FOLINKSET> gl_folinkset(new GL_FOLINKSET(nullptr));
			gl_folinkset->open(sourceDSN, targetDSN);
			gl_folinkset->setRepositoryString(envyRepositoryString);
			gl_folinkset->setProfileName(profileName);
			gl_folinkset->setReplicationOption(eReplicationOption);
			gl_folinkset->setDropOption(edropOption);
			gl_folinkset->setOdbcAttributes(odbcAttributes);
			gl_folinkset->setUpdateInterval(updateInterval);
			gl_folinkset->setCommitInterval(commitInterval);
			gl_folinkset->process(1);
		} break;
		case Rctables::enumMA_PRODHSHSET:
		{
			QScopedPointer<MA_PRODHSHSET> ma_prodhshset(new MA_PRODHSHSET(nullptr));
			ma_prodhshset->open(sourceDSN, targetDSN);
			ma_prodhshset->setRepositoryString(envyRepositoryString);
			ma_prodhshset->setProfileName(profileName);
			ma_prodhshset->setReplicationOption(eReplicationOption);
			ma_prodhshset->setDropOption(edropOption);
			ma_prodhshset->setOdbcAttributes(odbcAttributes);
			ma_prodhshset->setUpdateInterval(updateInterval);
			ma_prodhshset->setCommitInterval(commitInterval);
			ma_prodhshset->process(1);
		} break;
		case Rctables::enumAP_BNKOPENSET:
		{
			QScopedPointer<AP_BNKOPENSET> ap_bnkopenset(new AP_BNKOPENSET(nullptr));
			ap_bnkopenset->open(sourceDSN, targetDSN);
			ap_bnkopenset->setRepositoryString(envyRepositoryString);
			ap_bnkopenset->setProfileName(profileName);
			ap_bnkopenset->setReplicationOption(eReplicationOption);
			ap_bnkopenset->setDropOption(edropOption);
			ap_bnkopenset->setOdbcAttributes(odbcAttributes);
			ap_bnkopenset->setUpdateInterval(updateInterval);
			ap_bnkopenset->setCommitInterval(commitInterval);
			ap_bnkopenset->process(1);
		} break;
		case Rctables::enumDRLABSET:
		{
			QScopedPointer<DRLABSET> drlabset(new DRLABSET(nullptr));
			drlabset->open(sourceDSN, targetDSN);
			drlabset->setRepositoryString(envyRepositoryString);
			drlabset->setProfileName(profileName);
			drlabset->setReplicationOption(eReplicationOption);
			drlabset->setDropOption(edropOption);
			drlabset->setOdbcAttributes(odbcAttributes);
			drlabset->setUpdateInterval(updateInterval);
			drlabset->setCommitInterval(commitInterval);
			drlabset->process(1);
		} break;
		case Rctables::enumMA_CHGDREC:
		{
			QScopedPointer<MA_CHGDREC> ma_chgdrec(new MA_CHGDREC(nullptr));
			ma_chgdrec->open(sourceDSN, targetDSN);
			ma_chgdrec->setRepositoryString(envyRepositoryString);
			ma_chgdrec->setProfileName(profileName);
			ma_chgdrec->setReplicationOption(eReplicationOption);
			ma_chgdrec->setDropOption(edropOption);
			ma_chgdrec->setOdbcAttributes(odbcAttributes);
			ma_chgdrec->setUpdateInterval(updateInterval);
			ma_chgdrec->setCommitInterval(commitInterval);
			ma_chgdrec->process(1);
		} break;
		case Rctables::enumAP_INVRCTSET:
		{
			QScopedPointer<AP_INVRCTSET> ap_invrctset(new AP_INVRCTSET(nullptr));
			ap_invrctset->open(sourceDSN, targetDSN);
			ap_invrctset->setRepositoryString(envyRepositoryString);
			ap_invrctset->setProfileName(profileName);
			ap_invrctset->setReplicationOption(eReplicationOption);
			ap_invrctset->setDropOption(edropOption);
			ap_invrctset->setOdbcAttributes(odbcAttributes);
			ap_invrctset->setUpdateInterval(updateInterval);
			ap_invrctset->setCommitInterval(commitInterval);
			ap_invrctset->process(1);
		} break;
		case Rctables::enumSOHHSH2SET:
		{
			QScopedPointer<SOHHSH2SET> sohhsh2set(new SOHHSH2SET(nullptr));
			sohhsh2set->open(sourceDSN, targetDSN);
			sohhsh2set->setRepositoryString(envyRepositoryString);
			sohhsh2set->setProfileName(profileName);
			sohhsh2set->setReplicationOption(eReplicationOption);
			sohhsh2set->setDropOption(edropOption);
			sohhsh2set->setOdbcAttributes(odbcAttributes);
			sohhsh2set->setUpdateInterval(updateInterval);
			sohhsh2set->setCommitInterval(commitInterval);
			sohhsh2set->process(1);
		} break;
		case Rctables::enumBOLLREC:
		{
			QScopedPointer<BOLLREC> bollrec(new BOLLREC(nullptr));
			bollrec->open(sourceDSN, targetDSN);
			bollrec->setRepositoryString(envyRepositoryString);
			bollrec->setProfileName(profileName);
			bollrec->setReplicationOption(eReplicationOption);
			bollrec->setDropOption(edropOption);
			bollrec->setOdbcAttributes(odbcAttributes);
			bollrec->setUpdateInterval(updateInterval);
			bollrec->setCommitInterval(commitInterval);
			bollrec->process(1);
		} break;
		case Rctables::enumMA_DMHHSHSET:
		{
			QScopedPointer<MA_DMHHSHSET> ma_dmhhshset(new MA_DMHHSHSET(nullptr));
			ma_dmhhshset->open(sourceDSN, targetDSN);
			ma_dmhhshset->setRepositoryString(envyRepositoryString);
			ma_dmhhshset->setProfileName(profileName);
			ma_dmhhshset->setReplicationOption(eReplicationOption);
			ma_dmhhshset->setDropOption(edropOption);
			ma_dmhhshset->setOdbcAttributes(odbcAttributes);
			ma_dmhhshset->setUpdateInterval(updateInterval);
			ma_dmhhshset->setCommitInterval(commitInterval);
			ma_dmhhshset->process(1);
		} break;
		case Rctables::enumPRTMATSET:
		{
			QScopedPointer<PRTMATSET> prtmatset(new PRTMATSET(nullptr));
			prtmatset->open(sourceDSN, targetDSN);
			prtmatset->setRepositoryString(envyRepositoryString);
			prtmatset->setProfileName(profileName);
			prtmatset->setReplicationOption(eReplicationOption);
			prtmatset->setDropOption(edropOption);
			prtmatset->setOdbcAttributes(odbcAttributes);
			prtmatset->setUpdateInterval(updateInterval);
			prtmatset->setCommitInterval(commitInterval);
			prtmatset->process(1);
		} break;
		case Rctables::enumMA_BILCTBILSET:
		{
			QScopedPointer<MA_BILCTBILSET> ma_bilctbilset(new MA_BILCTBILSET(nullptr));
			ma_bilctbilset->open(sourceDSN, targetDSN);
			ma_bilctbilset->setRepositoryString(envyRepositoryString);
			ma_bilctbilset->setProfileName(profileName);
			ma_bilctbilset->setReplicationOption(eReplicationOption);
			ma_bilctbilset->setDropOption(edropOption);
			ma_bilctbilset->setOdbcAttributes(odbcAttributes);
			ma_bilctbilset->setUpdateInterval(updateInterval);
			ma_bilctbilset->setCommitInterval(commitInterval);
			ma_bilctbilset->process(1);
		} break;
		case Rctables::enumREFREC:
		{
			QScopedPointer<REFREC> refrec(new REFREC(nullptr));
			refrec->open(sourceDSN, targetDSN);
			refrec->setRepositoryString(envyRepositoryString);
			refrec->setProfileName(profileName);
			refrec->setReplicationOption(eReplicationOption);
			refrec->setDropOption(edropOption);
			refrec->setOdbcAttributes(odbcAttributes);
			refrec->setUpdateInterval(updateInterval);
			refrec->setCommitInterval(commitInterval);
			refrec->process(1);
		} break;
		case Rctables::enumCOHCDLSET:
		{
			QScopedPointer<COHCDLSET> cohcdlset(new COHCDLSET(nullptr));
			cohcdlset->open(sourceDSN, targetDSN);
			cohcdlset->setRepositoryString(envyRepositoryString);
			cohcdlset->setProfileName(profileName);
			cohcdlset->setReplicationOption(eReplicationOption);
			cohcdlset->setDropOption(edropOption);
			cohcdlset->setOdbcAttributes(odbcAttributes);
			cohcdlset->setUpdateInterval(updateInterval);
			cohcdlset->setCommitInterval(commitInterval);
			cohcdlset->process(1);
		} break;
		case Rctables::enumIDHSHSET:
		{
			QScopedPointer<IDHSHSET> idhshset(new IDHSHSET(nullptr));
			idhshset->open(sourceDSN, targetDSN);
			idhshset->setRepositoryString(envyRepositoryString);
			idhshset->setProfileName(profileName);
			idhshset->setReplicationOption(eReplicationOption);
			idhshset->setDropOption(edropOption);
			idhshset->setOdbcAttributes(odbcAttributes);
			idhshset->setUpdateInterval(updateInterval);
			idhshset->setCommitInterval(commitInterval);
			idhshset->process(1);
		} break;
		case Rctables::enumGENREC:
		{
			QScopedPointer<GENREC> genrec(new GENREC(nullptr));
			genrec->open(sourceDSN, targetDSN);
			genrec->setRepositoryString(envyRepositoryString);
			genrec->setProfileName(profileName);
			genrec->setReplicationOption(eReplicationOption);
			genrec->setDropOption(edropOption);
			genrec->setOdbcAttributes(odbcAttributes);
			genrec->setUpdateInterval(updateInterval);
			genrec->setCommitInterval(commitInterval);
			genrec->process(1);
		} break;
		case Rctables::enumENGHSHSET:
		{
			QScopedPointer<ENGHSHSET> enghshset(new ENGHSHSET(nullptr));
			enghshset->open(sourceDSN, targetDSN);
			enghshset->setRepositoryString(envyRepositoryString);
			enghshset->setProfileName(profileName);
			enghshset->setReplicationOption(eReplicationOption);
			enghshset->setDropOption(edropOption);
			enghshset->setOdbcAttributes(odbcAttributes);
			enghshset->setUpdateInterval(updateInterval);
			enghshset->setCommitInterval(commitInterval);
			enghshset->process(1);
		} break;
		case Rctables::enumCOHREC:
		{
			QScopedPointer<COHREC> cohrec(new COHREC(nullptr));
			cohrec->open(sourceDSN, targetDSN);
			cohrec->setRepositoryString(envyRepositoryString);
			cohrec->setProfileName(profileName);
			cohrec->setReplicationOption(eReplicationOption);
			cohrec->setDropOption(edropOption);
			cohrec->setOdbcAttributes(odbcAttributes);
			cohrec->setUpdateInterval(updateInterval);
			cohrec->setCommitInterval(commitInterval);
			cohrec->process(1);
		} break;
		case Rctables::enumRQHHSHSET:
		{
			QScopedPointer<RQHHSHSET> rqhhshset(new RQHHSHSET(nullptr));
			rqhhshset->open(sourceDSN, targetDSN);
			rqhhshset->setRepositoryString(envyRepositoryString);
			rqhhshset->setProfileName(profileName);
			rqhhshset->setReplicationOption(eReplicationOption);
			rqhhshset->setDropOption(edropOption);
			rqhhshset->setOdbcAttributes(odbcAttributes);
			rqhhshset->setUpdateInterval(updateInterval);
			rqhhshset->setCommitInterval(commitInterval);
			rqhhshset->process(1);
		} break;
		case Rctables::enumACTOOSET:
		{
			QScopedPointer<ACTOOSET> actooset(new ACTOOSET(nullptr));
			actooset->open(sourceDSN, targetDSN);
			actooset->setRepositoryString(envyRepositoryString);
			actooset->setProfileName(profileName);
			actooset->setReplicationOption(eReplicationOption);
			actooset->setDropOption(edropOption);
			actooset->setOdbcAttributes(odbcAttributes);
			actooset->setUpdateInterval(updateInterval);
			actooset->setCommitInterval(commitInterval);
			actooset->process(1);
		} break;
		case Rctables::enumAP_INVREC:
		{
			QScopedPointer<AP_INVREC> ap_invrec(new AP_INVREC(nullptr));
			ap_invrec->open(sourceDSN, targetDSN);
			ap_invrec->setRepositoryString(envyRepositoryString);
			ap_invrec->setProfileName(profileName);
			ap_invrec->setReplicationOption(eReplicationOption);
			ap_invrec->setDropOption(edropOption);
			ap_invrec->setOdbcAttributes(odbcAttributes);
			ap_invrec->setUpdateInterval(updateInterval);
			ap_invrec->setCommitInterval(commitInterval);
			ap_invrec->process(1);
		} break;
		case Rctables::enumACTDFASET:
		{
			QScopedPointer<ACTDFASET> actdfaset(new ACTDFASET(nullptr));
			actdfaset->open(sourceDSN, targetDSN);
			actdfaset->setRepositoryString(envyRepositoryString);
			actdfaset->setProfileName(profileName);
			actdfaset->setReplicationOption(eReplicationOption);
			actdfaset->setDropOption(edropOption);
			actdfaset->setOdbcAttributes(odbcAttributes);
			actdfaset->setUpdateInterval(updateInterval);
			actdfaset->setCommitInterval(commitInterval);
			actdfaset->process(1);
		} break;
		case Rctables::enumMA_TXLREC:
		{
			QScopedPointer<MA_TXLREC> ma_txlrec(new MA_TXLREC(nullptr));
			ma_txlrec->open(sourceDSN, targetDSN);
			ma_txlrec->setRepositoryString(envyRepositoryString);
			ma_txlrec->setProfileName(profileName);
			ma_txlrec->setReplicationOption(eReplicationOption);
			ma_txlrec->setDropOption(edropOption);
			ma_txlrec->setOdbcAttributes(odbcAttributes);
			ma_txlrec->setUpdateInterval(updateInterval);
			ma_txlrec->setCommitInterval(commitInterval);
			ma_txlrec->process(1);
		} break;
		case Rctables::enumAP_VCHPNOTVCHSET:
		{
			QScopedPointer<AP_VCHPNOTVCHSET> ap_vchpnotvchset(new AP_VCHPNOTVCHSET(nullptr));
			ap_vchpnotvchset->open(sourceDSN, targetDSN);
			ap_vchpnotvchset->setRepositoryString(envyRepositoryString);
			ap_vchpnotvchset->setProfileName(profileName);
			ap_vchpnotvchset->setReplicationOption(eReplicationOption);
			ap_vchpnotvchset->setDropOption(edropOption);
			ap_vchpnotvchset->setOdbcAttributes(odbcAttributes);
			ap_vchpnotvchset->setUpdateInterval(updateInterval);
			ap_vchpnotvchset->setCommitInterval(commitInterval);
			ap_vchpnotvchset->process(1);
		} break;
		case Rctables::enumAP_SEARCHVNDSET:
		{
			QScopedPointer<AP_SEARCHVNDSET> ap_searchvndset(new AP_SEARCHVNDSET(nullptr));
			ap_searchvndset->open(sourceDSN, targetDSN);
			ap_searchvndset->setRepositoryString(envyRepositoryString);
			ap_searchvndset->setProfileName(profileName);
			ap_searchvndset->setReplicationOption(eReplicationOption);
			ap_searchvndset->setDropOption(edropOption);
			ap_searchvndset->setOdbcAttributes(odbcAttributes);
			ap_searchvndset->setUpdateInterval(updateInterval);
			ap_searchvndset->setCommitInterval(commitInterval);
			ap_searchvndset->process(1);
		} break;
		case Rctables::enumMA_CMDCOMOSET:
		{
			QScopedPointer<MA_CMDCOMOSET> ma_cmdcomoset(new MA_CMDCOMOSET(nullptr));
			ma_cmdcomoset->open(sourceDSN, targetDSN);
			ma_cmdcomoset->setRepositoryString(envyRepositoryString);
			ma_cmdcomoset->setProfileName(profileName);
			ma_cmdcomoset->setReplicationOption(eReplicationOption);
			ma_cmdcomoset->setDropOption(edropOption);
			ma_cmdcomoset->setOdbcAttributes(odbcAttributes);
			ma_cmdcomoset->setUpdateInterval(updateInterval);
			ma_cmdcomoset->setCommitInterval(commitInterval);
			ma_cmdcomoset->process(1);
		} break;
		case Rctables::enumOPNPOHSET:
		{
			QScopedPointer<OPNPOHSET> opnpohset(new OPNPOHSET(nullptr));
			opnpohset->open(sourceDSN, targetDSN);
			opnpohset->setRepositoryString(envyRepositoryString);
			opnpohset->setProfileName(profileName);
			opnpohset->setReplicationOption(eReplicationOption);
			opnpohset->setDropOption(edropOption);
			opnpohset->setOdbcAttributes(odbcAttributes);
			opnpohset->setUpdateInterval(updateInterval);
			opnpohset->setCommitInterval(commitInterval);
			opnpohset->process(1);
		} break;
		case Rctables::enumMA_INTREC:
		{
			QScopedPointer<MA_INTREC> ma_intrec(new MA_INTREC(nullptr));
			ma_intrec->open(sourceDSN, targetDSN);
			ma_intrec->setRepositoryString(envyRepositoryString);
			ma_intrec->setProfileName(profileName);
			ma_intrec->setReplicationOption(eReplicationOption);
			ma_intrec->setDropOption(edropOption);
			ma_intrec->setOdbcAttributes(odbcAttributes);
			ma_intrec->setUpdateInterval(updateInterval);
			ma_intrec->setCommitInterval(commitInterval);
			ma_intrec->process(1);
		} break;
		case Rctables::enumECOHSHSET:
		{
			QScopedPointer<ECOHSHSET> ecohshset(new ECOHSHSET(nullptr));
			ecohshset->open(sourceDSN, targetDSN);
			ecohshset->setRepositoryString(envyRepositoryString);
			ecohshset->setProfileName(profileName);
			ecohshset->setReplicationOption(eReplicationOption);
			ecohshset->setDropOption(edropOption);
			ecohshset->setOdbcAttributes(odbcAttributes);
			ecohshset->setUpdateInterval(updateInterval);
			ecohshset->setCommitInterval(commitInterval);
			ecohshset->process(1);
		} break;
		case Rctables::enumMA_PFAMHSHSET:
		{
			QScopedPointer<MA_PFAMHSHSET> ma_pfamhshset(new MA_PFAMHSHSET(nullptr));
			ma_pfamhshset->open(sourceDSN, targetDSN);
			ma_pfamhshset->setRepositoryString(envyRepositoryString);
			ma_pfamhshset->setProfileName(profileName);
			ma_pfamhshset->setReplicationOption(eReplicationOption);
			ma_pfamhshset->setDropOption(edropOption);
			ma_pfamhshset->setOdbcAttributes(odbcAttributes);
			ma_pfamhshset->setUpdateInterval(updateInterval);
			ma_pfamhshset->setCommitInterval(commitInterval);
			ma_pfamhshset->process(1);
		} break;
		case Rctables::enumAP_ACCTREC:
		{
			QScopedPointer<AP_ACCTREC> ap_acctrec(new AP_ACCTREC(nullptr));
			ap_acctrec->open(sourceDSN, targetDSN);
			ap_acctrec->setRepositoryString(envyRepositoryString);
			ap_acctrec->setProfileName(profileName);
			ap_acctrec->setReplicationOption(eReplicationOption);
			ap_acctrec->setDropOption(edropOption);
			ap_acctrec->setOdbcAttributes(odbcAttributes);
			ap_acctrec->setUpdateInterval(updateInterval);
			ap_acctrec->setCommitInterval(commitInterval);
			ap_acctrec->process(1);
		} break;
		case Rctables::enumPRHREC:
		{
			QScopedPointer<PRHREC> prhrec(new PRHREC(nullptr));
			prhrec->open(sourceDSN, targetDSN);
			prhrec->setRepositoryString(envyRepositoryString);
			prhrec->setProfileName(profileName);
			prhrec->setReplicationOption(eReplicationOption);
			prhrec->setDropOption(edropOption);
			prhrec->setOdbcAttributes(odbcAttributes);
			prhrec->setUpdateInterval(updateInterval);
			prhrec->setCommitInterval(commitInterval);
			prhrec->process(1);
		} break;
		case Rctables::enumWIPJOBSET:
		{
			QScopedPointer<WIPJOBSET> wipjobset(new WIPJOBSET(nullptr));
			wipjobset->open(sourceDSN, targetDSN);
			wipjobset->setRepositoryString(envyRepositoryString);
			wipjobset->setProfileName(profileName);
			wipjobset->setReplicationOption(eReplicationOption);
			wipjobset->setDropOption(edropOption);
			wipjobset->setOdbcAttributes(odbcAttributes);
			wipjobset->setUpdateInterval(updateInterval);
			wipjobset->setCommitInterval(commitInterval);
			wipjobset->process(1);
		} break;
		case Rctables::enumMA_SHDREC:
		{
			QScopedPointer<MA_SHDREC> ma_shdrec(new MA_SHDREC(nullptr));
			ma_shdrec->open(sourceDSN, targetDSN);
			ma_shdrec->setRepositoryString(envyRepositoryString);
			ma_shdrec->setProfileName(profileName);
			ma_shdrec->setReplicationOption(eReplicationOption);
			ma_shdrec->setDropOption(edropOption);
			ma_shdrec->setOdbcAttributes(odbcAttributes);
			ma_shdrec->setUpdateInterval(updateInterval);
			ma_shdrec->setCommitInterval(commitInterval);
			ma_shdrec->process(1);
		} break;
		case Rctables::enumENGENDSET:
		{
			QScopedPointer<ENGENDSET> engendset(new ENGENDSET(nullptr));
			engendset->open(sourceDSN, targetDSN);
			engendset->setRepositoryString(envyRepositoryString);
			engendset->setProfileName(profileName);
			engendset->setReplicationOption(eReplicationOption);
			engendset->setDropOption(edropOption);
			engendset->setOdbcAttributes(odbcAttributes);
			engendset->setUpdateInterval(updateInterval);
			engendset->setCommitInterval(commitInterval);
			engendset->process(1);
		} break;
		case Rctables::enumVENPRHSET:
		{
			QScopedPointer<VENPRHSET> venprhset(new VENPRHSET(nullptr));
			venprhset->open(sourceDSN, targetDSN);
			venprhset->setRepositoryString(envyRepositoryString);
			venprhset->setProfileName(profileName);
			venprhset->setReplicationOption(eReplicationOption);
			venprhset->setDropOption(edropOption);
			venprhset->setOdbcAttributes(odbcAttributes);
			venprhset->setUpdateInterval(updateInterval);
			venprhset->setCommitInterval(commitInterval);
			venprhset->process(1);
		} break;
		case Rctables::enumCDLREC:
		{
			QScopedPointer<CDLREC> cdlrec(new CDLREC(nullptr));
			cdlrec->open(sourceDSN, targetDSN);
			cdlrec->setRepositoryString(envyRepositoryString);
			cdlrec->setProfileName(profileName);
			cdlrec->setReplicationOption(eReplicationOption);
			cdlrec->setDropOption(edropOption);
			cdlrec->setOdbcAttributes(odbcAttributes);
			cdlrec->setUpdateInterval(updateInterval);
			cdlrec->setCommitInterval(commitInterval);
			cdlrec->process(1);
		} break;
		case Rctables::enumCDACDPSET:
		{
			QScopedPointer<CDACDPSET> cdacdpset(new CDACDPSET(nullptr));
			cdacdpset->open(sourceDSN, targetDSN);
			cdacdpset->setRepositoryString(envyRepositoryString);
			cdacdpset->setProfileName(profileName);
			cdacdpset->setReplicationOption(eReplicationOption);
			cdacdpset->setDropOption(edropOption);
			cdacdpset->setOdbcAttributes(odbcAttributes);
			cdacdpset->setUpdateInterval(updateInterval);
			cdacdpset->setCommitInterval(commitInterval);
			cdacdpset->process(1);
		} break;
		case Rctables::enumGL_PRPTDESCSET:
		{
			QScopedPointer<GL_PRPTDESCSET> gl_prptdescset(new GL_PRPTDESCSET(nullptr));
			gl_prptdescset->open(sourceDSN, targetDSN);
			gl_prptdescset->setRepositoryString(envyRepositoryString);
			gl_prptdescset->setProfileName(profileName);
			gl_prptdescset->setReplicationOption(eReplicationOption);
			gl_prptdescset->setDropOption(edropOption);
			gl_prptdescset->setOdbcAttributes(odbcAttributes);
			gl_prptdescset->setUpdateInterval(updateInterval);
			gl_prptdescset->setCommitInterval(commitInterval);
			gl_prptdescset->process(1);
		} break;
		case Rctables::enumMA_SHDSPISET:
		{
			QScopedPointer<MA_SHDSPISET> ma_shdspiset(new MA_SHDSPISET(nullptr));
			ma_shdspiset->open(sourceDSN, targetDSN);
			ma_shdspiset->setRepositoryString(envyRepositoryString);
			ma_shdspiset->setProfileName(profileName);
			ma_shdspiset->setReplicationOption(eReplicationOption);
			ma_shdspiset->setDropOption(edropOption);
			ma_shdspiset->setOdbcAttributes(odbcAttributes);
			ma_shdspiset->setUpdateInterval(updateInterval);
			ma_shdspiset->setCommitInterval(commitInterval);
			ma_shdspiset->process(1);
		} break;
		case Rctables::enumINVREC:
		{
			QScopedPointer<INVREC> invrec(new INVREC(nullptr));
			invrec->open(sourceDSN, targetDSN);
			invrec->setRepositoryString(envyRepositoryString);
			invrec->setProfileName(profileName);
			invrec->setReplicationOption(eReplicationOption);
			invrec->setDropOption(edropOption);
			invrec->setOdbcAttributes(odbcAttributes);
			invrec->setUpdateInterval(updateInterval);
			invrec->setCommitInterval(commitInterval);
			invrec->process(1);
		} break;
		case Rctables::enumMA_CHGHREC:
		{
			QScopedPointer<MA_CHGHREC> ma_chghrec(new MA_CHGHREC(nullptr));
			ma_chghrec->open(sourceDSN, targetDSN);
			ma_chghrec->setRepositoryString(envyRepositoryString);
			ma_chghrec->setProfileName(profileName);
			ma_chghrec->setReplicationOption(eReplicationOption);
			ma_chghrec->setDropOption(edropOption);
			ma_chghrec->setOdbcAttributes(odbcAttributes);
			ma_chghrec->setUpdateInterval(updateInterval);
			ma_chghrec->setCommitInterval(commitInterval);
			ma_chghrec->process(1);
		} break;
		case Rctables::enumGL_REPROJSET:
		{
			QScopedPointer<GL_REPROJSET> gl_reprojset(new GL_REPROJSET(nullptr));
			gl_reprojset->open(sourceDSN, targetDSN);
			gl_reprojset->setRepositoryString(envyRepositoryString);
			gl_reprojset->setProfileName(profileName);
			gl_reprojset->setReplicationOption(eReplicationOption);
			gl_reprojset->setDropOption(edropOption);
			gl_reprojset->setOdbcAttributes(odbcAttributes);
			gl_reprojset->setUpdateInterval(updateInterval);
			gl_reprojset->setCommitInterval(commitInterval);
			gl_reprojset->process(1);
		} break;
		case Rctables::enumWIPHSHSET:
		{
			QScopedPointer<WIPHSHSET> wiphshset(new WIPHSHSET(nullptr));
			wiphshset->open(sourceDSN, targetDSN);
			wiphshset->setRepositoryString(envyRepositoryString);
			wiphshset->setProfileName(profileName);
			wiphshset->setReplicationOption(eReplicationOption);
			wiphshset->setDropOption(edropOption);
			wiphshset->setOdbcAttributes(odbcAttributes);
			wiphshset->setUpdateInterval(updateInterval);
			wiphshset->setCommitInterval(commitInterval);
			wiphshset->process(1);
		} break;
		case Rctables::enumPRTPRDSET:
		{
			QScopedPointer<PRTPRDSET> prtprdset(new PRTPRDSET(nullptr));
			prtprdset->open(sourceDSN, targetDSN);
			prtprdset->setRepositoryString(envyRepositoryString);
			prtprdset->setProfileName(profileName);
			prtprdset->setReplicationOption(eReplicationOption);
			prtprdset->setDropOption(edropOption);
			prtprdset->setOdbcAttributes(odbcAttributes);
			prtprdset->setUpdateInterval(updateInterval);
			prtprdset->setCommitInterval(commitInterval);
			prtprdset->process(1);
		} break;
		case Rctables::enumPRTSODSET:
		{
			QScopedPointer<PRTSODSET> prtsodset(new PRTSODSET(nullptr));
			prtsodset->open(sourceDSN, targetDSN);
			prtsodset->setRepositoryString(envyRepositoryString);
			prtsodset->setProfileName(profileName);
			prtsodset->setReplicationOption(eReplicationOption);
			prtsodset->setDropOption(edropOption);
			prtsodset->setOdbcAttributes(odbcAttributes);
			prtsodset->setUpdateInterval(updateInterval);
			prtsodset->setCommitInterval(commitInterval);
			prtsodset->process(1);
		} break;
		case Rctables::enumMA_SPNREC:
		{
			QScopedPointer<MA_SPNREC> ma_spnrec(new MA_SPNREC(nullptr));
			ma_spnrec->open(sourceDSN, targetDSN);
			ma_spnrec->setRepositoryString(envyRepositoryString);
			ma_spnrec->setProfileName(profileName);
			ma_spnrec->setReplicationOption(eReplicationOption);
			ma_spnrec->setDropOption(edropOption);
			ma_spnrec->setOdbcAttributes(odbcAttributes);
			ma_spnrec->setUpdateInterval(updateInterval);
			ma_spnrec->setCommitInterval(commitInterval);
			ma_spnrec->process(1);
		} break;
		case Rctables::enumLOCREC:
		{
			QScopedPointer<LOCREC> locrec(new LOCREC(nullptr));
			locrec->open(sourceDSN, targetDSN);
			locrec->setRepositoryString(envyRepositoryString);
			locrec->setProfileName(profileName);
			locrec->setReplicationOption(eReplicationOption);
			locrec->setDropOption(edropOption);
			locrec->setOdbcAttributes(odbcAttributes);
			locrec->setUpdateInterval(updateInterval);
			locrec->setCommitInterval(commitInterval);
			locrec->process(1);
		} break;
		case Rctables::enumAP_CHKNOTSET:
		{
			QScopedPointer<AP_CHKNOTSET> ap_chknotset(new AP_CHKNOTSET(nullptr));
			ap_chknotset->open(sourceDSN, targetDSN);
			ap_chknotset->setRepositoryString(envyRepositoryString);
			ap_chknotset->setProfileName(profileName);
			ap_chknotset->setReplicationOption(eReplicationOption);
			ap_chknotset->setDropOption(edropOption);
			ap_chknotset->setOdbcAttributes(odbcAttributes);
			ap_chknotset->setUpdateInterval(updateInterval);
			ap_chknotset->setCommitInterval(commitInterval);
			ap_chknotset->process(1);
		} break;
		case Rctables::enumMA_CMHINHLSET:
		{
			QScopedPointer<MA_CMHINHLSET> ma_cmhinhlset(new MA_CMHINHLSET(nullptr));
			ma_cmhinhlset->open(sourceDSN, targetDSN);
			ma_cmhinhlset->setRepositoryString(envyRepositoryString);
			ma_cmhinhlset->setProfileName(profileName);
			ma_cmhinhlset->setReplicationOption(eReplicationOption);
			ma_cmhinhlset->setDropOption(edropOption);
			ma_cmhinhlset->setOdbcAttributes(odbcAttributes);
			ma_cmhinhlset->setUpdateInterval(updateInterval);
			ma_cmhinhlset->setCommitInterval(commitInterval);
			ma_cmhinhlset->process(1);
		} break;
		case Rctables::enumWIPSET:
		{
			QScopedPointer<WIPSET> wipset(new WIPSET(nullptr));
			wipset->open(sourceDSN, targetDSN);
			wipset->setRepositoryString(envyRepositoryString);
			wipset->setProfileName(profileName);
			wipset->setReplicationOption(eReplicationOption);
			wipset->setDropOption(edropOption);
			wipset->setOdbcAttributes(odbcAttributes);
			wipset->setUpdateInterval(updateInterval);
			wipset->setCommitInterval(commitInterval);
			wipset->process(1);
		} break;
		case Rctables::enumGL_VPTOACCTSET:
		{
			QScopedPointer<GL_VPTOACCTSET> gl_vptoacctset(new GL_VPTOACCTSET(nullptr));
			gl_vptoacctset->open(sourceDSN, targetDSN);
			gl_vptoacctset->setRepositoryString(envyRepositoryString);
			gl_vptoacctset->setProfileName(profileName);
			gl_vptoacctset->setReplicationOption(eReplicationOption);
			gl_vptoacctset->setDropOption(edropOption);
			gl_vptoacctset->setOdbcAttributes(odbcAttributes);
			gl_vptoacctset->setUpdateInterval(updateInterval);
			gl_vptoacctset->setCommitInterval(commitInterval);
			gl_vptoacctset->process(1);
		} break;
		case Rctables::enumIDPRHSET:
		{
			QScopedPointer<IDPRHSET> idprhset(new IDPRHSET(nullptr));
			idprhset->open(sourceDSN, targetDSN);
			idprhset->setRepositoryString(envyRepositoryString);
			idprhset->setProfileName(profileName);
			idprhset->setReplicationOption(eReplicationOption);
			idprhset->setDropOption(edropOption);
			idprhset->setOdbcAttributes(odbcAttributes);
			idprhset->setUpdateInterval(updateInterval);
			idprhset->setCommitInterval(commitInterval);
			idprhset->process(1);
		} break;
		case Rctables::enumMA_SERREC:
		{
			QScopedPointer<MA_SERREC> ma_serrec(new MA_SERREC(nullptr));
			ma_serrec->open(sourceDSN, targetDSN);
			ma_serrec->setRepositoryString(envyRepositoryString);
			ma_serrec->setProfileName(profileName);
			ma_serrec->setReplicationOption(eReplicationOption);
			ma_serrec->setDropOption(edropOption);
			ma_serrec->setOdbcAttributes(odbcAttributes);
			ma_serrec->setUpdateInterval(updateInterval);
			ma_serrec->setCommitInterval(commitInterval);
			ma_serrec->process(1);
		} break;
		case Rctables::enumMA_SODOPTSET:
		{
			QScopedPointer<MA_SODOPTSET> ma_sodoptset(new MA_SODOPTSET(nullptr));
			ma_sodoptset->open(sourceDSN, targetDSN);
			ma_sodoptset->setRepositoryString(envyRepositoryString);
			ma_sodoptset->setProfileName(profileName);
			ma_sodoptset->setReplicationOption(eReplicationOption);
			ma_sodoptset->setDropOption(edropOption);
			ma_sodoptset->setOdbcAttributes(odbcAttributes);
			ma_sodoptset->setUpdateInterval(updateInterval);
			ma_sodoptset->setCommitInterval(commitInterval);
			ma_sodoptset->process(1);
		} break;
		case Rctables::enumMA_GLPTHSHSET:
		{
			QScopedPointer<MA_GLPTHSHSET> ma_glpthshset(new MA_GLPTHSHSET(nullptr));
			ma_glpthshset->open(sourceDSN, targetDSN);
			ma_glpthshset->setRepositoryString(envyRepositoryString);
			ma_glpthshset->setProfileName(profileName);
			ma_glpthshset->setReplicationOption(eReplicationOption);
			ma_glpthshset->setDropOption(edropOption);
			ma_glpthshset->setOdbcAttributes(odbcAttributes);
			ma_glpthshset->setUpdateInterval(updateInterval);
			ma_glpthshset->setCommitInterval(commitInterval);
			ma_glpthshset->process(1);
		} break;
		case Rctables::enumMA_SHPREC:
		{
			QScopedPointer<MA_SHPREC> ma_shprec(new MA_SHPREC(nullptr));
			ma_shprec->open(sourceDSN, targetDSN);
			ma_shprec->setRepositoryString(envyRepositoryString);
			ma_shprec->setProfileName(profileName);
			ma_shprec->setReplicationOption(eReplicationOption);
			ma_shprec->setDropOption(edropOption);
			ma_shprec->setOdbcAttributes(odbcAttributes);
			ma_shprec->setUpdateInterval(updateInterval);
			ma_shprec->setCommitInterval(commitInterval);
			ma_shprec->process(1);
		} break;
		case Rctables::enumMFGREC:
		{
			QScopedPointer<MFGREC> mfgrec(new MFGREC(nullptr));
			mfgrec->open(sourceDSN, targetDSN);
			mfgrec->setRepositoryString(envyRepositoryString);
			mfgrec->setProfileName(profileName);
			mfgrec->setReplicationOption(eReplicationOption);
			mfgrec->setDropOption(edropOption);
			mfgrec->setOdbcAttributes(odbcAttributes);
			mfgrec->setUpdateInterval(updateInterval);
			mfgrec->setCommitInterval(commitInterval);
			mfgrec->process(1);
		} break;
		case Rctables::enumPRTINTSET:
		{
			QScopedPointer<PRTINTSET> prtintset(new PRTINTSET(nullptr));
			prtintset->open(sourceDSN, targetDSN);
			prtintset->setRepositoryString(envyRepositoryString);
			prtintset->setProfileName(profileName);
			prtintset->setReplicationOption(eReplicationOption);
			prtintset->setDropOption(edropOption);
			prtintset->setOdbcAttributes(odbcAttributes);
			prtintset->setUpdateInterval(updateInterval);
			prtintset->setCommitInterval(commitInterval);
			prtintset->process(1);
		} break;
		case Rctables::enumMA_SHDPSERSET:
		{
			QScopedPointer<MA_SHDPSERSET> ma_shdpserset(new MA_SHDPSERSET(nullptr));
			ma_shdpserset->open(sourceDSN, targetDSN);
			ma_shdpserset->setRepositoryString(envyRepositoryString);
			ma_shdpserset->setProfileName(profileName);
			ma_shdpserset->setReplicationOption(eReplicationOption);
			ma_shdpserset->setDropOption(edropOption);
			ma_shdpserset->setOdbcAttributes(odbcAttributes);
			ma_shdpserset->setUpdateInterval(updateInterval);
			ma_shdpserset->setCommitInterval(commitInterval);
			ma_shdpserset->process(1);
		} break;
		case Rctables::enumMA_TXCMHSET:
		{
			QScopedPointer<MA_TXCMHSET> ma_txcmhset(new MA_TXCMHSET(nullptr));
			ma_txcmhset->open(sourceDSN, targetDSN);
			ma_txcmhset->setRepositoryString(envyRepositoryString);
			ma_txcmhset->setProfileName(profileName);
			ma_txcmhset->setReplicationOption(eReplicationOption);
			ma_txcmhset->setDropOption(edropOption);
			ma_txcmhset->setOdbcAttributes(odbcAttributes);
			ma_txcmhset->setUpdateInterval(updateInterval);
			ma_txcmhset->setCommitInterval(commitInterval);
			ma_txcmhset->process(1);
		} break;
		case Rctables::enumMA_ACCTPPDSET:
		{
			QScopedPointer<MA_ACCTPPDSET> ma_acctppdset(new MA_ACCTPPDSET(nullptr));
			ma_acctppdset->open(sourceDSN, targetDSN);
			ma_acctppdset->setRepositoryString(envyRepositoryString);
			ma_acctppdset->setProfileName(profileName);
			ma_acctppdset->setReplicationOption(eReplicationOption);
			ma_acctppdset->setDropOption(edropOption);
			ma_acctppdset->setOdbcAttributes(odbcAttributes);
			ma_acctppdset->setUpdateInterval(updateInterval);
			ma_acctppdset->setCommitInterval(commitInterval);
			ma_acctppdset->process(1);
		} break;
		case Rctables::enumGL_REHSHSET:
		{
			QScopedPointer<GL_REHSHSET> gl_rehshset(new GL_REHSHSET(nullptr));
			gl_rehshset->open(sourceDSN, targetDSN);
			gl_rehshset->setRepositoryString(envyRepositoryString);
			gl_rehshset->setProfileName(profileName);
			gl_rehshset->setReplicationOption(eReplicationOption);
			gl_rehshset->setDropOption(edropOption);
			gl_rehshset->setOdbcAttributes(odbcAttributes);
			gl_rehshset->setUpdateInterval(updateInterval);
			gl_rehshset->setCommitInterval(commitInterval);
			gl_rehshset->process(1);
		} break;
		case Rctables::enumAP_PAYPLTSET:
		{
			QScopedPointer<AP_PAYPLTSET> ap_paypltset(new AP_PAYPLTSET(nullptr));
			ap_paypltset->open(sourceDSN, targetDSN);
			ap_paypltset->setRepositoryString(envyRepositoryString);
			ap_paypltset->setProfileName(profileName);
			ap_paypltset->setReplicationOption(eReplicationOption);
			ap_paypltset->setDropOption(edropOption);
			ap_paypltset->setOdbcAttributes(odbcAttributes);
			ap_paypltset->setUpdateInterval(updateInterval);
			ap_paypltset->setCommitInterval(commitInterval);
			ap_paypltset->process(1);
		} break;
		case Rctables::enumMA_BILREC:
		{
			QScopedPointer<MA_BILREC> ma_bilrec(new MA_BILREC(nullptr));
			ma_bilrec->open(sourceDSN, targetDSN);
			ma_bilrec->setRepositoryString(envyRepositoryString);
			ma_bilrec->setProfileName(profileName);
			ma_bilrec->setReplicationOption(eReplicationOption);
			ma_bilrec->setDropOption(edropOption);
			ma_bilrec->setOdbcAttributes(odbcAttributes);
			ma_bilrec->setUpdateInterval(updateInterval);
			ma_bilrec->setCommitInterval(commitInterval);
			ma_bilrec->process(1);
		} break;
		case Rctables::enumSPDREC:
		{
			QScopedPointer<SPDREC> spdrec(new SPDREC(nullptr));
			spdrec->open(sourceDSN, targetDSN);
			spdrec->setRepositoryString(envyRepositoryString);
			spdrec->setProfileName(profileName);
			spdrec->setReplicationOption(eReplicationOption);
			spdrec->setDropOption(edropOption);
			spdrec->setOdbcAttributes(odbcAttributes);
			spdrec->setUpdateInterval(updateInterval);
			spdrec->setCommitInterval(commitInterval);
			spdrec->process(1);
		} break;
		case Rctables::enumPAYHSHSET:
		{
			QScopedPointer<PAYHSHSET> payhshset(new PAYHSHSET(nullptr));
			payhshset->open(sourceDSN, targetDSN);
			payhshset->setRepositoryString(envyRepositoryString);
			payhshset->setProfileName(profileName);
			payhshset->setReplicationOption(eReplicationOption);
			payhshset->setDropOption(edropOption);
			payhshset->setOdbcAttributes(odbcAttributes);
			payhshset->setUpdateInterval(updateInterval);
			payhshset->setCommitInterval(commitInterval);
			payhshset->process(1);
		} break;
		case Rctables::enumMA_CMHREC:
		{
			QScopedPointer<MA_CMHREC> ma_cmhrec(new MA_CMHREC(nullptr));
			ma_cmhrec->open(sourceDSN, targetDSN);
			ma_cmhrec->setRepositoryString(envyRepositoryString);
			ma_cmhrec->setProfileName(profileName);
			ma_cmhrec->setReplicationOption(eReplicationOption);
			ma_cmhrec->setDropOption(edropOption);
			ma_cmhrec->setOdbcAttributes(odbcAttributes);
			ma_cmhrec->setUpdateInterval(updateInterval);
			ma_cmhrec->setCommitInterval(commitInterval);
			ma_cmhrec->process(1);
		} break;
		case Rctables::enumMA_CMDSPISET:
		{
			QScopedPointer<MA_CMDSPISET> ma_cmdspiset(new MA_CMDSPISET(nullptr));
			ma_cmdspiset->open(sourceDSN, targetDSN);
			ma_cmdspiset->setRepositoryString(envyRepositoryString);
			ma_cmdspiset->setProfileName(profileName);
			ma_cmdspiset->setReplicationOption(eReplicationOption);
			ma_cmdspiset->setDropOption(edropOption);
			ma_cmdspiset->setOdbcAttributes(odbcAttributes);
			ma_cmdspiset->setUpdateInterval(updateInterval);
			ma_cmdspiset->setCommitInterval(commitInterval);
			ma_cmdspiset->process(1);
		} break;
		case Rctables::enumOPCHSHSET:
		{
			QScopedPointer<OPCHSHSET> opchshset(new OPCHSHSET(nullptr));
			opchshset->open(sourceDSN, targetDSN);
			opchshset->setRepositoryString(envyRepositoryString);
			opchshset->setProfileName(profileName);
			opchshset->setReplicationOption(eReplicationOption);
			opchshset->setDropOption(edropOption);
			opchshset->setOdbcAttributes(odbcAttributes);
			opchshset->setUpdateInterval(updateInterval);
			opchshset->setCommitInterval(commitInterval);
			opchshset->process(1);
		} break;
		case Rctables::enumMRQREC:
		{
			QScopedPointer<MRQREC> mrqrec(new MRQREC(nullptr));
			mrqrec->open(sourceDSN, targetDSN);
			mrqrec->setRepositoryString(envyRepositoryString);
			mrqrec->setProfileName(profileName);
			mrqrec->setReplicationOption(eReplicationOption);
			mrqrec->setDropOption(edropOption);
			mrqrec->setOdbcAttributes(odbcAttributes);
			mrqrec->setUpdateInterval(updateInterval);
			mrqrec->setCommitInterval(commitInterval);
			mrqrec->process(1);
		} break;
		case Rctables::enumMA_PAYTDREC:
		{
			QScopedPointer<MA_PAYTDREC> ma_paytdrec(new MA_PAYTDREC(nullptr));
			ma_paytdrec->open(sourceDSN, targetDSN);
			ma_paytdrec->setRepositoryString(envyRepositoryString);
			ma_paytdrec->setProfileName(profileName);
			ma_paytdrec->setReplicationOption(eReplicationOption);
			ma_paytdrec->setDropOption(edropOption);
			ma_paytdrec->setOdbcAttributes(odbcAttributes);
			ma_paytdrec->setUpdateInterval(updateInterval);
			ma_paytdrec->setCommitInterval(commitInterval);
			ma_paytdrec->process(1);
		} break;
		case Rctables::enumGL_ACCTAMTSET:
		{
			QScopedPointer<GL_ACCTAMTSET> gl_acctamtset(new GL_ACCTAMTSET(nullptr));
			gl_acctamtset->open(sourceDSN, targetDSN);
			gl_acctamtset->setRepositoryString(envyRepositoryString);
			gl_acctamtset->setProfileName(profileName);
			gl_acctamtset->setReplicationOption(eReplicationOption);
			gl_acctamtset->setDropOption(edropOption);
			gl_acctamtset->setOdbcAttributes(odbcAttributes);
			gl_acctamtset->setUpdateInterval(updateInterval);
			gl_acctamtset->setCommitInterval(commitInterval);
			gl_acctamtset->process(1);
		} break;
		case Rctables::enumMA_RSNREC:
		{
			QScopedPointer<MA_RSNREC> ma_rsnrec(new MA_RSNREC(nullptr));
			ma_rsnrec->open(sourceDSN, targetDSN);
			ma_rsnrec->setRepositoryString(envyRepositoryString);
			ma_rsnrec->setProfileName(profileName);
			ma_rsnrec->setReplicationOption(eReplicationOption);
			ma_rsnrec->setDropOption(edropOption);
			ma_rsnrec->setOdbcAttributes(odbcAttributes);
			ma_rsnrec->setUpdateInterval(updateInterval);
			ma_rsnrec->setCommitInterval(commitInterval);
			ma_rsnrec->process(1);
		} break;
		case Rctables::enumLABREC:
		{
			QScopedPointer<LABREC> labrec(new LABREC(nullptr));
			labrec->open(sourceDSN, targetDSN);
			labrec->setRepositoryString(envyRepositoryString);
			labrec->setProfileName(profileName);
			labrec->setReplicationOption(eReplicationOption);
			labrec->setDropOption(edropOption);
			labrec->setOdbcAttributes(odbcAttributes);
			labrec->setUpdateInterval(updateInterval);
			labrec->setCommitInterval(commitInterval);
			labrec->process(1);
		} break;
		case Rctables::enumMA_CMHHSHSET:
		{
			QScopedPointer<MA_CMHHSHSET> ma_cmhhshset(new MA_CMHHSHSET(nullptr));
			ma_cmhhshset->open(sourceDSN, targetDSN);
			ma_cmhhshset->setRepositoryString(envyRepositoryString);
			ma_cmhhshset->setProfileName(profileName);
			ma_cmhhshset->setReplicationOption(eReplicationOption);
			ma_cmhhshset->setDropOption(edropOption);
			ma_cmhhshset->setOdbcAttributes(odbcAttributes);
			ma_cmhhshset->setUpdateInterval(updateInterval);
			ma_cmhhshset->setCommitInterval(commitInterval);
			ma_cmhhshset->process(1);
		} break;
		case Rctables::enumPRTDESSET:
		{
			QScopedPointer<PRTDESSET> prtdesset(new PRTDESSET(nullptr));
			prtdesset->open(sourceDSN, targetDSN);
			prtdesset->setRepositoryString(envyRepositoryString);
			prtdesset->setProfileName(profileName);
			prtdesset->setReplicationOption(eReplicationOption);
			prtdesset->setDropOption(edropOption);
			prtdesset->setOdbcAttributes(odbcAttributes);
			prtdesset->setUpdateInterval(updateInterval);
			prtdesset->setCommitInterval(commitInterval);
			prtdesset->process(1);
		} break;
		case Rctables::enumGL_PRPT_DREC:
		{
			QScopedPointer<GL_PRPT_DREC> gl_prpt_drec(new GL_PRPT_DREC(nullptr));
			gl_prpt_drec->open(sourceDSN, targetDSN);
			gl_prpt_drec->setRepositoryString(envyRepositoryString);
			gl_prpt_drec->setProfileName(profileName);
			gl_prpt_drec->setReplicationOption(eReplicationOption);
			gl_prpt_drec->setDropOption(edropOption);
			gl_prpt_drec->setOdbcAttributes(odbcAttributes);
			gl_prpt_drec->setUpdateInterval(updateInterval);
			gl_prpt_drec->setCommitInterval(commitInterval);
			gl_prpt_drec->process(1);
		} break;
		case Rctables::enumMA_INHUPDSET:
		{
			QScopedPointer<MA_INHUPDSET> ma_inhupdset(new MA_INHUPDSET(nullptr));
			ma_inhupdset->open(sourceDSN, targetDSN);
			ma_inhupdset->setRepositoryString(envyRepositoryString);
			ma_inhupdset->setProfileName(profileName);
			ma_inhupdset->setReplicationOption(eReplicationOption);
			ma_inhupdset->setDropOption(edropOption);
			ma_inhupdset->setOdbcAttributes(odbcAttributes);
			ma_inhupdset->setUpdateInterval(updateInterval);
			ma_inhupdset->setCommitInterval(commitInterval);
			ma_inhupdset->process(1);
		} break;
		case Rctables::enumGL_PROJBUDSET:
		{
			QScopedPointer<GL_PROJBUDSET> gl_projbudset(new GL_PROJBUDSET(nullptr));
			gl_projbudset->open(sourceDSN, targetDSN);
			gl_projbudset->setRepositoryString(envyRepositoryString);
			gl_projbudset->setProfileName(profileName);
			gl_projbudset->setReplicationOption(eReplicationOption);
			gl_projbudset->setDropOption(edropOption);
			gl_projbudset->setOdbcAttributes(odbcAttributes);
			gl_projbudset->setUpdateInterval(updateInterval);
			gl_projbudset->setCommitInterval(commitInterval);
			gl_projbudset->process(1);
		} break;
		case Rctables::enumMA_ACCTPRVARSET:
		{
			QScopedPointer<MA_ACCTPRVARSET> ma_acctprvarset(new MA_ACCTPRVARSET(nullptr));
			ma_acctprvarset->open(sourceDSN, targetDSN);
			ma_acctprvarset->setRepositoryString(envyRepositoryString);
			ma_acctprvarset->setProfileName(profileName);
			ma_acctprvarset->setReplicationOption(eReplicationOption);
			ma_acctprvarset->setDropOption(edropOption);
			ma_acctprvarset->setOdbcAttributes(odbcAttributes);
			ma_acctprvarset->setUpdateInterval(updateInterval);
			ma_acctprvarset->setCommitInterval(commitInterval);
			ma_acctprvarset->process(1);
		} break;
		case Rctables::enumEMPLABSET:
		{
			QScopedPointer<EMPLABSET> emplabset(new EMPLABSET(nullptr));
			emplabset->open(sourceDSN, targetDSN);
			emplabset->setRepositoryString(envyRepositoryString);
			emplabset->setProfileName(profileName);
			emplabset->setReplicationOption(eReplicationOption);
			emplabset->setDropOption(edropOption);
			emplabset->setOdbcAttributes(odbcAttributes);
			emplabset->setUpdateInterval(updateInterval);
			emplabset->setCommitInterval(commitInterval);
			emplabset->process(1);
		} break;
		case Rctables::enumGL_JVDESCSET:
		{
			QScopedPointer<GL_JVDESCSET> gl_jvdescset(new GL_JVDESCSET(nullptr));
			gl_jvdescset->open(sourceDSN, targetDSN);
			gl_jvdescset->setRepositoryString(envyRepositoryString);
			gl_jvdescset->setProfileName(profileName);
			gl_jvdescset->setReplicationOption(eReplicationOption);
			gl_jvdescset->setDropOption(edropOption);
			gl_jvdescset->setOdbcAttributes(odbcAttributes);
			gl_jvdescset->setUpdateInterval(updateInterval);
			gl_jvdescset->setCommitInterval(commitInterval);
			gl_jvdescset->process(1);
		} break;
		case Rctables::enumAP_RECPAYPOSTSET:
		{
			QScopedPointer<AP_RECPAYPOSTSET> ap_recpaypostset(new AP_RECPAYPOSTSET(nullptr));
			ap_recpaypostset->open(sourceDSN, targetDSN);
			ap_recpaypostset->setRepositoryString(envyRepositoryString);
			ap_recpaypostset->setProfileName(profileName);
			ap_recpaypostset->setReplicationOption(eReplicationOption);
			ap_recpaypostset->setDropOption(edropOption);
			ap_recpaypostset->setOdbcAttributes(odbcAttributes);
			ap_recpaypostset->setUpdateInterval(updateInterval);
			ap_recpaypostset->setCommitInterval(commitInterval);
			ap_recpaypostset->process(1);
		} break;
		case Rctables::enumPRHPONSET:
		{
			QScopedPointer<PRHPONSET> prhponset(new PRHPONSET(nullptr));
			prhponset->open(sourceDSN, targetDSN);
			prhponset->setRepositoryString(envyRepositoryString);
			prhponset->setProfileName(profileName);
			prhponset->setReplicationOption(eReplicationOption);
			prhponset->setDropOption(edropOption);
			prhponset->setOdbcAttributes(odbcAttributes);
			prhponset->setUpdateInterval(updateInterval);
			prhponset->setCommitInterval(commitInterval);
			prhponset->process(1);
		} break;
		case Rctables::enumMA_ACTSTGSET:
		{
			QScopedPointer<MA_ACTSTGSET> ma_actstgset(new MA_ACTSTGSET(nullptr));
			ma_actstgset->open(sourceDSN, targetDSN);
			ma_actstgset->setRepositoryString(envyRepositoryString);
			ma_actstgset->setProfileName(profileName);
			ma_actstgset->setReplicationOption(eReplicationOption);
			ma_actstgset->setDropOption(edropOption);
			ma_actstgset->setOdbcAttributes(odbcAttributes);
			ma_actstgset->setUpdateInterval(updateInterval);
			ma_actstgset->setCommitInterval(commitInterval);
			ma_actstgset->process(1);
		} break;
		case Rctables::enumMA_COMCLREC:
		{
			QScopedPointer<MA_COMCLREC> ma_comclrec(new MA_COMCLREC(nullptr));
			ma_comclrec->open(sourceDSN, targetDSN);
			ma_comclrec->setRepositoryString(envyRepositoryString);
			ma_comclrec->setProfileName(profileName);
			ma_comclrec->setReplicationOption(eReplicationOption);
			ma_comclrec->setDropOption(edropOption);
			ma_comclrec->setOdbcAttributes(odbcAttributes);
			ma_comclrec->setUpdateInterval(updateInterval);
			ma_comclrec->setCommitInterval(commitInterval);
			ma_comclrec->process(1);
		} break;
		case Rctables::enumFLGREC:
		{
			QScopedPointer<FLGREC> flgrec(new FLGREC(nullptr));
			flgrec->open(sourceDSN, targetDSN);
			flgrec->setRepositoryString(envyRepositoryString);
			flgrec->setProfileName(profileName);
			flgrec->setReplicationOption(eReplicationOption);
			flgrec->setDropOption(edropOption);
			flgrec->setOdbcAttributes(odbcAttributes);
			flgrec->setUpdateInterval(updateInterval);
			flgrec->setCommitInterval(commitInterval);
			flgrec->process(1);
		} break;
		case Rctables::enumMA_SOHHSHSET:
		{
			QScopedPointer<MA_SOHHSHSET> ma_sohhshset(new MA_SOHHSHSET(nullptr));
			ma_sohhshset->open(sourceDSN, targetDSN);
			ma_sohhshset->setRepositoryString(envyRepositoryString);
			ma_sohhshset->setProfileName(profileName);
			ma_sohhshset->setReplicationOption(eReplicationOption);
			ma_sohhshset->setDropOption(edropOption);
			ma_sohhshset->setOdbcAttributes(odbcAttributes);
			ma_sohhshset->setUpdateInterval(updateInterval);
			ma_sohhshset->setCommitInterval(commitInterval);
			ma_sohhshset->process(1);
		} break;
		case Rctables::enumMA_SHPCOMOSET:
		{
			QScopedPointer<MA_SHPCOMOSET> ma_shpcomoset(new MA_SHPCOMOSET(nullptr));
			ma_shpcomoset->open(sourceDSN, targetDSN);
			ma_shpcomoset->setRepositoryString(envyRepositoryString);
			ma_shpcomoset->setProfileName(profileName);
			ma_shpcomoset->setReplicationOption(eReplicationOption);
			ma_shpcomoset->setDropOption(edropOption);
			ma_shpcomoset->setOdbcAttributes(odbcAttributes);
			ma_shpcomoset->setUpdateInterval(updateInterval);
			ma_shpcomoset->setCommitInterval(commitInterval);
			ma_shpcomoset->process(1);
		} break;
		case Rctables::enumAP_RECPAYHSHSET:
		{
			QScopedPointer<AP_RECPAYHSHSET> ap_recpayhshset(new AP_RECPAYHSHSET(nullptr));
			ap_recpayhshset->open(sourceDSN, targetDSN);
			ap_recpayhshset->setRepositoryString(envyRepositoryString);
			ap_recpayhshset->setProfileName(profileName);
			ap_recpayhshset->setReplicationOption(eReplicationOption);
			ap_recpayhshset->setDropOption(edropOption);
			ap_recpayhshset->setOdbcAttributes(odbcAttributes);
			ap_recpayhshset->setUpdateInterval(updateInterval);
			ap_recpayhshset->setCommitInterval(commitInterval);
			ap_recpayhshset->process(1);
		} break;
		case Rctables::enumGL_FISCHSHSET:
		{
			QScopedPointer<GL_FISCHSHSET> gl_fischshset(new GL_FISCHSHSET(nullptr));
			gl_fischshset->open(sourceDSN, targetDSN);
			gl_fischshset->setRepositoryString(envyRepositoryString);
			gl_fischshset->setProfileName(profileName);
			gl_fischshset->setReplicationOption(eReplicationOption);
			gl_fischshset->setDropOption(edropOption);
			gl_fischshset->setOdbcAttributes(odbcAttributes);
			gl_fischshset->setUpdateInterval(updateInterval);
			gl_fischshset->setCommitInterval(commitInterval);
			gl_fischshset->process(1);
		} break;
		case Rctables::enumMA_ACCTLINDSET:
		{
			QScopedPointer<MA_ACCTLINDSET> ma_acctlindset(new MA_ACCTLINDSET(nullptr));
			ma_acctlindset->open(sourceDSN, targetDSN);
			ma_acctlindset->setRepositoryString(envyRepositoryString);
			ma_acctlindset->setProfileName(profileName);
			ma_acctlindset->setReplicationOption(eReplicationOption);
			ma_acctlindset->setDropOption(edropOption);
			ma_acctlindset->setOdbcAttributes(odbcAttributes);
			ma_acctlindset->setUpdateInterval(updateInterval);
			ma_acctlindset->setCommitInterval(commitInterval);
			ma_acctlindset->process(1);
		} break;
		case Rctables::enumMA_SOHINHSET:
		{
			QScopedPointer<MA_SOHINHSET> ma_sohinhset(new MA_SOHINHSET(nullptr));
			ma_sohinhset->open(sourceDSN, targetDSN);
			ma_sohinhset->setRepositoryString(envyRepositoryString);
			ma_sohinhset->setProfileName(profileName);
			ma_sohinhset->setReplicationOption(eReplicationOption);
			ma_sohinhset->setDropOption(edropOption);
			ma_sohinhset->setOdbcAttributes(odbcAttributes);
			ma_sohinhset->setUpdateInterval(updateInterval);
			ma_sohinhset->setCommitInterval(commitInterval);
			ma_sohinhset->process(1);
		} break;
		case Rctables::enumAP_BNKVNDSET:
		{
			QScopedPointer<AP_BNKVNDSET> ap_bnkvndset(new AP_BNKVNDSET(nullptr));
			ap_bnkvndset->open(sourceDSN, targetDSN);
			ap_bnkvndset->setRepositoryString(envyRepositoryString);
			ap_bnkvndset->setProfileName(profileName);
			ap_bnkvndset->setReplicationOption(eReplicationOption);
			ap_bnkvndset->setDropOption(edropOption);
			ap_bnkvndset->setOdbcAttributes(odbcAttributes);
			ap_bnkvndset->setUpdateInterval(updateInterval);
			ap_bnkvndset->setCommitInterval(commitInterval);
			ap_bnkvndset->process(1);
		} break;
		case Rctables::enumAP_INVVCHSET:
		{
			QScopedPointer<AP_INVVCHSET> ap_invvchset(new AP_INVVCHSET(nullptr));
			ap_invvchset->open(sourceDSN, targetDSN);
			ap_invvchset->setRepositoryString(envyRepositoryString);
			ap_invvchset->setProfileName(profileName);
			ap_invvchset->setReplicationOption(eReplicationOption);
			ap_invvchset->setDropOption(edropOption);
			ap_invvchset->setOdbcAttributes(odbcAttributes);
			ap_invvchset->setUpdateInterval(updateInterval);
			ap_invvchset->setCommitInterval(commitInterval);
			ap_invvchset->process(1);
		} break;
		case Rctables::enumMA_SHHSODSET:
		{
			QScopedPointer<MA_SHHSODSET> ma_shhsodset(new MA_SHHSODSET(nullptr));
			ma_shhsodset->open(sourceDSN, targetDSN);
			ma_shhsodset->setRepositoryString(envyRepositoryString);
			ma_shhsodset->setProfileName(profileName);
			ma_shhsodset->setReplicationOption(eReplicationOption);
			ma_shhsodset->setDropOption(edropOption);
			ma_shhsodset->setOdbcAttributes(odbcAttributes);
			ma_shhsodset->setUpdateInterval(updateInterval);
			ma_shhsodset->setCommitInterval(commitInterval);
			ma_shhsodset->process(1);
		} break;
		case Rctables::enumGL_VPBATSET:
		{
			QScopedPointer<GL_VPBATSET> gl_vpbatset(new GL_VPBATSET(nullptr));
			gl_vpbatset->open(sourceDSN, targetDSN);
			gl_vpbatset->setRepositoryString(envyRepositoryString);
			gl_vpbatset->setProfileName(profileName);
			gl_vpbatset->setReplicationOption(eReplicationOption);
			gl_vpbatset->setDropOption(edropOption);
			gl_vpbatset->setOdbcAttributes(odbcAttributes);
			gl_vpbatset->setUpdateInterval(updateInterval);
			gl_vpbatset->setCommitInterval(commitInterval);
			gl_vpbatset->process(1);
		} break;
		case Rctables::enumGL_FP_DREC:
		{
			QScopedPointer<GL_FP_DREC> gl_fp_drec(new GL_FP_DREC(nullptr));
			gl_fp_drec->open(sourceDSN, targetDSN);
			gl_fp_drec->setRepositoryString(envyRepositoryString);
			gl_fp_drec->setProfileName(profileName);
			gl_fp_drec->setReplicationOption(eReplicationOption);
			gl_fp_drec->setDropOption(edropOption);
			gl_fp_drec->setOdbcAttributes(odbcAttributes);
			gl_fp_drec->setUpdateInterval(updateInterval);
			gl_fp_drec->setCommitInterval(commitInterval);
			gl_fp_drec->process(1);
		} break;
		case Rctables::enumGL_VPDENACCTSET:
		{
			QScopedPointer<GL_VPDENACCTSET> gl_vpdenacctset(new GL_VPDENACCTSET(nullptr));
			gl_vpdenacctset->open(sourceDSN, targetDSN);
			gl_vpdenacctset->setRepositoryString(envyRepositoryString);
			gl_vpdenacctset->setProfileName(profileName);
			gl_vpdenacctset->setReplicationOption(eReplicationOption);
			gl_vpdenacctset->setDropOption(edropOption);
			gl_vpdenacctset->setOdbcAttributes(odbcAttributes);
			gl_vpdenacctset->setUpdateInterval(updateInterval);
			gl_vpdenacctset->setCommitInterval(commitInterval);
			gl_vpdenacctset->process(1);
		} break;
		case Rctables::enumGL_ARPTDESCSET:
		{
			QScopedPointer<GL_ARPTDESCSET> gl_arptdescset(new GL_ARPTDESCSET(nullptr));
			gl_arptdescset->open(sourceDSN, targetDSN);
			gl_arptdescset->setRepositoryString(envyRepositoryString);
			gl_arptdescset->setProfileName(profileName);
			gl_arptdescset->setReplicationOption(eReplicationOption);
			gl_arptdescset->setDropOption(edropOption);
			gl_arptdescset->setOdbcAttributes(odbcAttributes);
			gl_arptdescset->setUpdateInterval(updateInterval);
			gl_arptdescset->setCommitInterval(commitInterval);
			gl_arptdescset->process(1);
		} break;
		case Rctables::enumGL_PROJMASET:
		{
			QScopedPointer<GL_PROJMASET> gl_projmaset(new GL_PROJMASET(nullptr));
			gl_projmaset->open(sourceDSN, targetDSN);
			gl_projmaset->setRepositoryString(envyRepositoryString);
			gl_projmaset->setProfileName(profileName);
			gl_projmaset->setReplicationOption(eReplicationOption);
			gl_projmaset->setDropOption(edropOption);
			gl_projmaset->setOdbcAttributes(odbcAttributes);
			gl_projmaset->setUpdateInterval(updateInterval);
			gl_projmaset->setCommitInterval(commitInterval);
			gl_projmaset->process(1);
		} break;
		case Rctables::enumMA_SHPSHPSSET:
		{
			QScopedPointer<MA_SHPSHPSSET> ma_shpshpsset(new MA_SHPSHPSSET(nullptr));
			ma_shpshpsset->open(sourceDSN, targetDSN);
			ma_shpshpsset->setRepositoryString(envyRepositoryString);
			ma_shpshpsset->setProfileName(profileName);
			ma_shpshpsset->setReplicationOption(eReplicationOption);
			ma_shpshpsset->setDropOption(edropOption);
			ma_shpshpsset->setOdbcAttributes(odbcAttributes);
			ma_shpshpsset->setUpdateInterval(updateInterval);
			ma_shpshpsset->setCommitInterval(commitInterval);
			ma_shpshpsset->process(1);
		} break;
		case Rctables::enumMA_SODSTGPSET:
		{
			QScopedPointer<MA_SODSTGPSET> ma_sodstgpset(new MA_SODSTGPSET(nullptr));
			ma_sodstgpset->open(sourceDSN, targetDSN);
			ma_sodstgpset->setRepositoryString(envyRepositoryString);
			ma_sodstgpset->setProfileName(profileName);
			ma_sodstgpset->setReplicationOption(eReplicationOption);
			ma_sodstgpset->setDropOption(edropOption);
			ma_sodstgpset->setOdbcAttributes(odbcAttributes);
			ma_sodstgpset->setUpdateInterval(updateInterval);
			ma_sodstgpset->setCommitInterval(commitInterval);
			ma_sodstgpset->process(1);
		} break;
		case Rctables::enumPRTMRHSET:
		{
			QScopedPointer<PRTMRHSET> prtmrhset(new PRTMRHSET(nullptr));
			prtmrhset->open(sourceDSN, targetDSN);
			prtmrhset->setRepositoryString(envyRepositoryString);
			prtmrhset->setProfileName(profileName);
			prtmrhset->setReplicationOption(eReplicationOption);
			prtmrhset->setDropOption(edropOption);
			prtmrhset->setOdbcAttributes(odbcAttributes);
			prtmrhset->setUpdateInterval(updateInterval);
			prtmrhset->setCommitInterval(commitInterval);
			prtmrhset->process(1);
		} break;
		case Rctables::enumMA_PRTABREC:
		{
			QScopedPointer<MA_PRTABREC> ma_prtabrec(new MA_PRTABREC(nullptr));
			ma_prtabrec->open(sourceDSN, targetDSN);
			ma_prtabrec->setRepositoryString(envyRepositoryString);
			ma_prtabrec->setProfileName(profileName);
			ma_prtabrec->setReplicationOption(eReplicationOption);
			ma_prtabrec->setDropOption(edropOption);
			ma_prtabrec->setOdbcAttributes(odbcAttributes);
			ma_prtabrec->setUpdateInterval(updateInterval);
			ma_prtabrec->setCommitInterval(commitInterval);
			ma_prtabrec->process(1);
		} break;
		case Rctables::enumPFAMREC:
		{
			QScopedPointer<PFAMREC> pfamrec(new PFAMREC(nullptr));
			pfamrec->open(sourceDSN, targetDSN);
			pfamrec->setRepositoryString(envyRepositoryString);
			pfamrec->setProfileName(profileName);
			pfamrec->setReplicationOption(eReplicationOption);
			pfamrec->setDropOption(edropOption);
			pfamrec->setOdbcAttributes(odbcAttributes);
			pfamrec->setUpdateInterval(updateInterval);
			pfamrec->setCommitInterval(commitInterval);
			pfamrec->process(1);
		} break;
		case Rctables::enumAP_1099REC:
		{
			QScopedPointer<AP_1099REC> ap_1099rec(new AP_1099REC(nullptr));
			ap_1099rec->open(sourceDSN, targetDSN);
			ap_1099rec->setRepositoryString(envyRepositoryString);
			ap_1099rec->setProfileName(profileName);
			ap_1099rec->setReplicationOption(eReplicationOption);
			ap_1099rec->setDropOption(edropOption);
			ap_1099rec->setOdbcAttributes(odbcAttributes);
			ap_1099rec->setUpdateInterval(updateInterval);
			ap_1099rec->setCommitInterval(commitInterval);
			ap_1099rec->process(1);
		} break;
		case Rctables::enumGL_TRDESCSET:
		{
			QScopedPointer<GL_TRDESCSET> gl_trdescset(new GL_TRDESCSET(nullptr));
			gl_trdescset->open(sourceDSN, targetDSN);
			gl_trdescset->setRepositoryString(envyRepositoryString);
			gl_trdescset->setProfileName(profileName);
			gl_trdescset->setReplicationOption(eReplicationOption);
			gl_trdescset->setDropOption(edropOption);
			gl_trdescset->setOdbcAttributes(odbcAttributes);
			gl_trdescset->setUpdateInterval(updateInterval);
			gl_trdescset->setCommitInterval(commitInterval);
			gl_trdescset->process(1);
		} break;
		case Rctables::enumTOOHSHSET:
		{
			QScopedPointer<TOOHSHSET> toohshset(new TOOHSHSET(nullptr));
			toohshset->open(sourceDSN, targetDSN);
			toohshset->setRepositoryString(envyRepositoryString);
			toohshset->setProfileName(profileName);
			toohshset->setReplicationOption(eReplicationOption);
			toohshset->setDropOption(edropOption);
			toohshset->setOdbcAttributes(odbcAttributes);
			toohshset->setUpdateInterval(updateInterval);
			toohshset->setCommitInterval(commitInterval);
			toohshset->process(1);
		} break;
		case Rctables::enumGL_ACCTBUDSET:
		{
			QScopedPointer<GL_ACCTBUDSET> gl_acctbudset(new GL_ACCTBUDSET(nullptr));
			gl_acctbudset->open(sourceDSN, targetDSN);
			gl_acctbudset->setRepositoryString(envyRepositoryString);
			gl_acctbudset->setProfileName(profileName);
			gl_acctbudset->setReplicationOption(eReplicationOption);
			gl_acctbudset->setDropOption(edropOption);
			gl_acctbudset->setOdbcAttributes(odbcAttributes);
			gl_acctbudset->setUpdateInterval(updateInterval);
			gl_acctbudset->setCommitInterval(commitInterval);
			gl_acctbudset->process(1);
		} break;
		case Rctables::enumAP_POHHSHSET:
		{
			QScopedPointer<AP_POHHSHSET> ap_pohhshset(new AP_POHHSHSET(nullptr));
			ap_pohhshset->open(sourceDSN, targetDSN);
			ap_pohhshset->setRepositoryString(envyRepositoryString);
			ap_pohhshset->setProfileName(profileName);
			ap_pohhshset->setReplicationOption(eReplicationOption);
			ap_pohhshset->setDropOption(edropOption);
			ap_pohhshset->setOdbcAttributes(odbcAttributes);
			ap_pohhshset->setUpdateInterval(updateInterval);
			ap_pohhshset->setCommitInterval(commitInterval);
			ap_pohhshset->process(1);
		} break;
		case Rctables::enumMA_PROJHSHSET:
		{
			QScopedPointer<MA_PROJHSHSET> ma_projhshset(new MA_PROJHSHSET(nullptr));
			ma_projhshset->open(sourceDSN, targetDSN);
			ma_projhshset->setRepositoryString(envyRepositoryString);
			ma_projhshset->setProfileName(profileName);
			ma_projhshset->setReplicationOption(eReplicationOption);
			ma_projhshset->setDropOption(edropOption);
			ma_projhshset->setOdbcAttributes(odbcAttributes);
			ma_projhshset->setUpdateInterval(updateInterval);
			ma_projhshset->setCommitInterval(commitInterval);
			ma_projhshset->process(1);
		} break;
		case Rctables::enumENCREC:
		{
			QScopedPointer<ENCREC> encrec(new ENCREC(nullptr));
			encrec->open(sourceDSN, targetDSN);
			encrec->setRepositoryString(envyRepositoryString);
			encrec->setProfileName(profileName);
			encrec->setReplicationOption(eReplicationOption);
			encrec->setDropOption(edropOption);
			encrec->setOdbcAttributes(odbcAttributes);
			encrec->setUpdateInterval(updateInterval);
			encrec->setCommitInterval(commitInterval);
			encrec->process(1);
		} break;
		case Rctables::enumED_ENTDOCSET:
		{
			QScopedPointer<ED_ENTDOCSET> ed_entdocset(new ED_ENTDOCSET(nullptr));
			ed_entdocset->open(sourceDSN, targetDSN);
			ed_entdocset->setRepositoryString(envyRepositoryString);
			ed_entdocset->setProfileName(profileName);
			ed_entdocset->setReplicationOption(eReplicationOption);
			ed_entdocset->setDropOption(edropOption);
			ed_entdocset->setOdbcAttributes(odbcAttributes);
			ed_entdocset->setUpdateInterval(updateInterval);
			ed_entdocset->setCommitInterval(commitInterval);
			ed_entdocset->process(1);
		} break;
		case Rctables::enumMA_TXSOHSET:
		{
			QScopedPointer<MA_TXSOHSET> ma_txsohset(new MA_TXSOHSET(nullptr));
			ma_txsohset->open(sourceDSN, targetDSN);
			ma_txsohset->setRepositoryString(envyRepositoryString);
			ma_txsohset->setProfileName(profileName);
			ma_txsohset->setReplicationOption(eReplicationOption);
			ma_txsohset->setDropOption(edropOption);
			ma_txsohset->setOdbcAttributes(odbcAttributes);
			ma_txsohset->setUpdateInterval(updateInterval);
			ma_txsohset->setCommitInterval(commitInterval);
			ma_txsohset->process(1);
		} break;
		case Rctables::enumPRHCPRSET:
		{
			QScopedPointer<PRHCPRSET> prhcprset(new PRHCPRSET(nullptr));
			prhcprset->open(sourceDSN, targetDSN);
			prhcprset->setRepositoryString(envyRepositoryString);
			prhcprset->setProfileName(profileName);
			prhcprset->setReplicationOption(eReplicationOption);
			prhcprset->setDropOption(edropOption);
			prhcprset->setOdbcAttributes(odbcAttributes);
			prhcprset->setUpdateInterval(updateInterval);
			prhcprset->setCommitInterval(commitInterval);
			prhcprset->process(1);
		} break;
		case Rctables::enumECCSET:
		{
			QScopedPointer<ECCSET> eccset(new ECCSET(nullptr));
			eccset->open(sourceDSN, targetDSN);
			eccset->setRepositoryString(envyRepositoryString);
			eccset->setProfileName(profileName);
			eccset->setReplicationOption(eReplicationOption);
			eccset->setDropOption(edropOption);
			eccset->setOdbcAttributes(odbcAttributes);
			eccset->setUpdateInterval(updateInterval);
			eccset->setCommitInterval(commitInterval);
			eccset->process(1);
		} break;
		case Rctables::enumMA_CMDSPNLSET:
		{
			QScopedPointer<MA_CMDSPNLSET> ma_cmdspnlset(new MA_CMDSPNLSET(nullptr));
			ma_cmdspnlset->open(sourceDSN, targetDSN);
			ma_cmdspnlset->setRepositoryString(envyRepositoryString);
			ma_cmdspnlset->setProfileName(profileName);
			ma_cmdspnlset->setReplicationOption(eReplicationOption);
			ma_cmdspnlset->setDropOption(edropOption);
			ma_cmdspnlset->setOdbcAttributes(odbcAttributes);
			ma_cmdspnlset->setUpdateInterval(updateInterval);
			ma_cmdspnlset->setCommitInterval(commitInterval);
			ma_cmdspnlset->process(1);
		} break;
		case Rctables::enumGL_PROJHSHSET:
		{
			QScopedPointer<GL_PROJHSHSET> gl_projhshset(new GL_PROJHSHSET(nullptr));
			gl_projhshset->open(sourceDSN, targetDSN);
			gl_projhshset->setRepositoryString(envyRepositoryString);
			gl_projhshset->setProfileName(profileName);
			gl_projhshset->setReplicationOption(eReplicationOption);
			gl_projhshset->setDropOption(edropOption);
			gl_projhshset->setOdbcAttributes(odbcAttributes);
			gl_projhshset->setUpdateInterval(updateInterval);
			gl_projhshset->setCommitInterval(commitInterval);
			gl_projhshset->process(1);
		} break;
		case Rctables::enumLOCSET:
		{
			QScopedPointer<LOCSET> locset(new LOCSET(nullptr));
			locset->open(sourceDSN, targetDSN);
			locset->setRepositoryString(envyRepositoryString);
			locset->setProfileName(profileName);
			locset->setReplicationOption(eReplicationOption);
			locset->setDropOption(edropOption);
			locset->setOdbcAttributes(odbcAttributes);
			locset->setUpdateInterval(updateInterval);
			locset->setCommitInterval(commitInterval);
			locset->process(1);
		} break;
		case Rctables::enumGL_BATCHSHSET:
		{
			QScopedPointer<GL_BATCHSHSET> gl_batchshset(new GL_BATCHSHSET(nullptr));
			gl_batchshset->open(sourceDSN, targetDSN);
			gl_batchshset->setRepositoryString(envyRepositoryString);
			gl_batchshset->setProfileName(profileName);
			gl_batchshset->setReplicationOption(eReplicationOption);
			gl_batchshset->setDropOption(edropOption);
			gl_batchshset->setOdbcAttributes(odbcAttributes);
			gl_batchshset->setUpdateInterval(updateInterval);
			gl_batchshset->setCommitInterval(commitInterval);
			gl_batchshset->process(1);
		} break;
		case Rctables::enumMA_ACCTHSHSET:
		{
			QScopedPointer<MA_ACCTHSHSET> ma_accthshset(new MA_ACCTHSHSET(nullptr));
			ma_accthshset->open(sourceDSN, targetDSN);
			ma_accthshset->setRepositoryString(envyRepositoryString);
			ma_accthshset->setProfileName(profileName);
			ma_accthshset->setReplicationOption(eReplicationOption);
			ma_accthshset->setDropOption(edropOption);
			ma_accthshset->setOdbcAttributes(odbcAttributes);
			ma_accthshset->setUpdateInterval(updateInterval);
			ma_accthshset->setCommitInterval(commitInterval);
			ma_accthshset->process(1);
		} break;
		case Rctables::enumGL_MCLINKSET:
		{
			QScopedPointer<GL_MCLINKSET> gl_mclinkset(new GL_MCLINKSET(nullptr));
			gl_mclinkset->open(sourceDSN, targetDSN);
			gl_mclinkset->setRepositoryString(envyRepositoryString);
			gl_mclinkset->setProfileName(profileName);
			gl_mclinkset->setReplicationOption(eReplicationOption);
			gl_mclinkset->setDropOption(edropOption);
			gl_mclinkset->setOdbcAttributes(odbcAttributes);
			gl_mclinkset->setUpdateInterval(updateInterval);
			gl_mclinkset->setCommitInterval(commitInterval);
			gl_mclinkset->process(1);
		} break;
		case Rctables::enumUSGREC:
		{
			QScopedPointer<USGREC> usgrec(new USGREC(nullptr));
			usgrec->open(sourceDSN, targetDSN);
			usgrec->setRepositoryString(envyRepositoryString);
			usgrec->setProfileName(profileName);
			usgrec->setReplicationOption(eReplicationOption);
			usgrec->setDropOption(edropOption);
			usgrec->setOdbcAttributes(odbcAttributes);
			usgrec->setUpdateInterval(updateInterval);
			usgrec->setCommitInterval(commitInterval);
			usgrec->process(1);
		} break;
		case Rctables::enumMA_BILDMHSET:
		{
			QScopedPointer<MA_BILDMHSET> ma_bildmhset(new MA_BILDMHSET(nullptr));
			ma_bildmhset->open(sourceDSN, targetDSN);
			ma_bildmhset->setRepositoryString(envyRepositoryString);
			ma_bildmhset->setProfileName(profileName);
			ma_bildmhset->setReplicationOption(eReplicationOption);
			ma_bildmhset->setDropOption(edropOption);
			ma_bildmhset->setOdbcAttributes(odbcAttributes);
			ma_bildmhset->setUpdateInterval(updateInterval);
			ma_bildmhset->setCommitInterval(commitInterval);
			ma_bildmhset->process(1);
		} break;
		case Rctables::enumMA_SOHCOMCSET:
		{
			QScopedPointer<MA_SOHCOMCSET> ma_sohcomcset(new MA_SOHCOMCSET(nullptr));
			ma_sohcomcset->open(sourceDSN, targetDSN);
			ma_sohcomcset->setRepositoryString(envyRepositoryString);
			ma_sohcomcset->setProfileName(profileName);
			ma_sohcomcset->setReplicationOption(eReplicationOption);
			ma_sohcomcset->setDropOption(edropOption);
			ma_sohcomcset->setOdbcAttributes(odbcAttributes);
			ma_sohcomcset->setUpdateInterval(updateInterval);
			ma_sohcomcset->setCommitInterval(commitInterval);
			ma_sohcomcset->process(1);
		} break;
		case Rctables::enumMA_SPNHSHSET:
		{
			QScopedPointer<MA_SPNHSHSET> ma_spnhshset(new MA_SPNHSHSET(nullptr));
			ma_spnhshset->open(sourceDSN, targetDSN);
			ma_spnhshset->setRepositoryString(envyRepositoryString);
			ma_spnhshset->setProfileName(profileName);
			ma_spnhshset->setReplicationOption(eReplicationOption);
			ma_spnhshset->setDropOption(edropOption);
			ma_spnhshset->setOdbcAttributes(odbcAttributes);
			ma_spnhshset->setUpdateInterval(updateInterval);
			ma_spnhshset->setCommitInterval(commitInterval);
			ma_spnhshset->process(1);
		} break;
		case Rctables::enumMA_SAMSAMSSET:
		{
			QScopedPointer<MA_SAMSAMSSET> ma_samsamsset(new MA_SAMSAMSSET(nullptr));
			ma_samsamsset->open(sourceDSN, targetDSN);
			ma_samsamsset->setRepositoryString(envyRepositoryString);
			ma_samsamsset->setProfileName(profileName);
			ma_samsamsset->setReplicationOption(eReplicationOption);
			ma_samsamsset->setDropOption(edropOption);
			ma_samsamsset->setOdbcAttributes(odbcAttributes);
			ma_samsamsset->setUpdateInterval(updateInterval);
			ma_samsamsset->setCommitInterval(commitInterval);
			ma_samsamsset->process(1);
		} break;
		case Rctables::enumMA_BILBILSSET:
		{
			QScopedPointer<MA_BILBILSSET> ma_bilbilsset(new MA_BILBILSSET(nullptr));
			ma_bilbilsset->open(sourceDSN, targetDSN);
			ma_bilbilsset->setRepositoryString(envyRepositoryString);
			ma_bilbilsset->setProfileName(profileName);
			ma_bilbilsset->setReplicationOption(eReplicationOption);
			ma_bilbilsset->setDropOption(edropOption);
			ma_bilbilsset->setOdbcAttributes(odbcAttributes);
			ma_bilbilsset->setUpdateInterval(updateInterval);
			ma_bilbilsset->setCommitInterval(commitInterval);
			ma_bilbilsset->process(1);
		} break;
		case Rctables::enumMA_QUODHSHSET:
		{
			QScopedPointer<MA_QUODHSHSET> ma_quodhshset(new MA_QUODHSHSET(nullptr));
			ma_quodhshset->open(sourceDSN, targetDSN);
			ma_quodhshset->setRepositoryString(envyRepositoryString);
			ma_quodhshset->setProfileName(profileName);
			ma_quodhshset->setReplicationOption(eReplicationOption);
			ma_quodhshset->setDropOption(edropOption);
			ma_quodhshset->setOdbcAttributes(odbcAttributes);
			ma_quodhshset->setUpdateInterval(updateInterval);
			ma_quodhshset->setCommitInterval(commitInterval);
			ma_quodhshset->process(1);
		} break;
		case Rctables::enumAP_VATPOST2SET:
		{
			QScopedPointer<AP_VATPOST2SET> ap_vatpost2set(new AP_VATPOST2SET(nullptr));
			ap_vatpost2set->open(sourceDSN, targetDSN);
			ap_vatpost2set->setRepositoryString(envyRepositoryString);
			ap_vatpost2set->setProfileName(profileName);
			ap_vatpost2set->setReplicationOption(eReplicationOption);
			ap_vatpost2set->setDropOption(edropOption);
			ap_vatpost2set->setOdbcAttributes(odbcAttributes);
			ap_vatpost2set->setUpdateInterval(updateInterval);
			ap_vatpost2set->setCommitInterval(commitInterval);
			ap_vatpost2set->process(1);
		} break;
		case Rctables::enumGL_JVHSHSET:
		{
			QScopedPointer<GL_JVHSHSET> gl_jvhshset(new GL_JVHSHSET(nullptr));
			gl_jvhshset->open(sourceDSN, targetDSN);
			gl_jvhshset->setRepositoryString(envyRepositoryString);
			gl_jvhshset->setProfileName(profileName);
			gl_jvhshset->setReplicationOption(eReplicationOption);
			gl_jvhshset->setDropOption(edropOption);
			gl_jvhshset->setOdbcAttributes(odbcAttributes);
			gl_jvhshset->setUpdateInterval(updateInterval);
			gl_jvhshset->setCommitInterval(commitInterval);
			gl_jvhshset->process(1);
		} break;
		case Rctables::enumAP_BEFTPMTSET:
		{
			QScopedPointer<AP_BEFTPMTSET> ap_beftpmtset(new AP_BEFTPMTSET(nullptr));
			ap_beftpmtset->open(sourceDSN, targetDSN);
			ap_beftpmtset->setRepositoryString(envyRepositoryString);
			ap_beftpmtset->setProfileName(profileName);
			ap_beftpmtset->setReplicationOption(eReplicationOption);
			ap_beftpmtset->setDropOption(edropOption);
			ap_beftpmtset->setOdbcAttributes(odbcAttributes);
			ap_beftpmtset->setUpdateInterval(updateInterval);
			ap_beftpmtset->setCommitInterval(commitInterval);
			ap_beftpmtset->process(1);
		} break;
		case Rctables::enumACTLOCSET:
		{
			QScopedPointer<ACTLOCSET> actlocset(new ACTLOCSET(nullptr));
			actlocset->open(sourceDSN, targetDSN);
			actlocset->setRepositoryString(envyRepositoryString);
			actlocset->setProfileName(profileName);
			actlocset->setReplicationOption(eReplicationOption);
			actlocset->setDropOption(edropOption);
			actlocset->setOdbcAttributes(odbcAttributes);
			actlocset->setUpdateInterval(updateInterval);
			actlocset->setCommitInterval(commitInterval);
			actlocset->process(1);
		} break;
		case Rctables::enumAP_HDRSET:
		{
			QScopedPointer<AP_HDRSET> ap_hdrset(new AP_HDRSET(nullptr));
			ap_hdrset->open(sourceDSN, targetDSN);
			ap_hdrset->setRepositoryString(envyRepositoryString);
			ap_hdrset->setProfileName(profileName);
			ap_hdrset->setReplicationOption(eReplicationOption);
			ap_hdrset->setDropOption(edropOption);
			ap_hdrset->setOdbcAttributes(odbcAttributes);
			ap_hdrset->setUpdateInterval(updateInterval);
			ap_hdrset->setCommitInterval(commitInterval);
			ap_hdrset->process(1);
		} break;
		case Rctables::enumMISREC:
		{
			QScopedPointer<MISREC> misrec(new MISREC(nullptr));
			misrec->open(sourceDSN, targetDSN);
			misrec->setRepositoryString(envyRepositoryString);
			misrec->setProfileName(profileName);
			misrec->setReplicationOption(eReplicationOption);
			misrec->setDropOption(edropOption);
			misrec->setOdbcAttributes(odbcAttributes);
			misrec->setUpdateInterval(updateInterval);
			misrec->setCommitInterval(commitInterval);
			misrec->process(1);
		} break;
		case Rctables::enumMA_ACCTREC:
		{
			QScopedPointer<MA_ACCTREC> ma_acctrec(new MA_ACCTREC(nullptr));
			ma_acctrec->open(sourceDSN, targetDSN);
			ma_acctrec->setRepositoryString(envyRepositoryString);
			ma_acctrec->setProfileName(profileName);
			ma_acctrec->setReplicationOption(eReplicationOption);
			ma_acctrec->setDropOption(edropOption);
			ma_acctrec->setOdbcAttributes(odbcAttributes);
			ma_acctrec->setUpdateInterval(updateInterval);
			ma_acctrec->setCommitInterval(commitInterval);
			ma_acctrec->process(1);
		} break;
		case Rctables::enumAP_VCHPOHSET:
		{
			QScopedPointer<AP_VCHPOHSET> ap_vchpohset(new AP_VCHPOHSET(nullptr));
			ap_vchpohset->open(sourceDSN, targetDSN);
			ap_vchpohset->setRepositoryString(envyRepositoryString);
			ap_vchpohset->setProfileName(profileName);
			ap_vchpohset->setReplicationOption(eReplicationOption);
			ap_vchpohset->setDropOption(edropOption);
			ap_vchpohset->setOdbcAttributes(odbcAttributes);
			ap_vchpohset->setUpdateInterval(updateInterval);
			ap_vchpohset->setCommitInterval(commitInterval);
			ap_vchpohset->process(1);
		} break;
		case Rctables::enumAP_ACCTTYPEREC:
		{
			QScopedPointer<AP_ACCTTYPEREC> ap_accttyperec(new AP_ACCTTYPEREC(nullptr));
			ap_accttyperec->open(sourceDSN, targetDSN);
			ap_accttyperec->setRepositoryString(envyRepositoryString);
			ap_accttyperec->setProfileName(profileName);
			ap_accttyperec->setReplicationOption(eReplicationOption);
			ap_accttyperec->setDropOption(edropOption);
			ap_accttyperec->setOdbcAttributes(odbcAttributes);
			ap_accttyperec->setUpdateInterval(updateInterval);
			ap_accttyperec->setCommitInterval(commitInterval);
			ap_accttyperec->process(1);
		} break;
		case Rctables::enumBOLBOLLSET:
		{
			QScopedPointer<BOLBOLLSET> bolbollset(new BOLBOLLSET(nullptr));
			bolbollset->open(sourceDSN, targetDSN);
			bolbollset->setRepositoryString(envyRepositoryString);
			bolbollset->setProfileName(profileName);
			bolbollset->setReplicationOption(eReplicationOption);
			bolbollset->setDropOption(edropOption);
			bolbollset->setOdbcAttributes(odbcAttributes);
			bolbollset->setUpdateInterval(updateInterval);
			bolbollset->setCommitInterval(commitInterval);
			bolbollset->process(1);
		} break;
		case Rctables::enumAP_VATHSHSET:
		{
			QScopedPointer<AP_VATHSHSET> ap_vathshset(new AP_VATHSHSET(nullptr));
			ap_vathshset->open(sourceDSN, targetDSN);
			ap_vathshset->setRepositoryString(envyRepositoryString);
			ap_vathshset->setProfileName(profileName);
			ap_vathshset->setReplicationOption(eReplicationOption);
			ap_vathshset->setDropOption(edropOption);
			ap_vathshset->setOdbcAttributes(odbcAttributes);
			ap_vathshset->setUpdateInterval(updateInterval);
			ap_vathshset->setCommitInterval(commitInterval);
			ap_vathshset->process(1);
		} break;
		case Rctables::enumGL_ARPTSET:
		{
			QScopedPointer<GL_ARPTSET> gl_arptset(new GL_ARPTSET(nullptr));
			gl_arptset->open(sourceDSN, targetDSN);
			gl_arptset->setRepositoryString(envyRepositoryString);
			gl_arptset->setProfileName(profileName);
			gl_arptset->setReplicationOption(eReplicationOption);
			gl_arptset->setDropOption(edropOption);
			gl_arptset->setOdbcAttributes(odbcAttributes);
			gl_arptset->setUpdateInterval(updateInterval);
			gl_arptset->setCommitInterval(commitInterval);
			gl_arptset->process(1);
		} break;
		case Rctables::enumAP_RECPAYNOTESET:
		{
			QScopedPointer<AP_RECPAYNOTESET> ap_recpaynoteset(new AP_RECPAYNOTESET(nullptr));
			ap_recpaynoteset->open(sourceDSN, targetDSN);
			ap_recpaynoteset->setRepositoryString(envyRepositoryString);
			ap_recpaynoteset->setProfileName(profileName);
			ap_recpaynoteset->setReplicationOption(eReplicationOption);
			ap_recpaynoteset->setDropOption(edropOption);
			ap_recpaynoteset->setOdbcAttributes(odbcAttributes);
			ap_recpaynoteset->setUpdateInterval(updateInterval);
			ap_recpaynoteset->setCommitInterval(commitInterval);
			ap_recpaynoteset->process(1);
		} break;
		case Rctables::enumMA_INHLREC:
		{
			QScopedPointer<MA_INHLREC> ma_inhlrec(new MA_INHLREC(nullptr));
			ma_inhlrec->open(sourceDSN, targetDSN);
			ma_inhlrec->setRepositoryString(envyRepositoryString);
			ma_inhlrec->setProfileName(profileName);
			ma_inhlrec->setReplicationOption(eReplicationOption);
			ma_inhlrec->setDropOption(edropOption);
			ma_inhlrec->setOdbcAttributes(odbcAttributes);
			ma_inhlrec->setUpdateInterval(updateInterval);
			ma_inhlrec->setCommitInterval(commitInterval);
			ma_inhlrec->process(1);
		} break;
		case Rctables::enumMA_CMHPOSTSET:
		{
			QScopedPointer<MA_CMHPOSTSET> ma_cmhpostset(new MA_CMHPOSTSET(nullptr));
			ma_cmhpostset->open(sourceDSN, targetDSN);
			ma_cmhpostset->setRepositoryString(envyRepositoryString);
			ma_cmhpostset->setProfileName(profileName);
			ma_cmhpostset->setReplicationOption(eReplicationOption);
			ma_cmhpostset->setDropOption(edropOption);
			ma_cmhpostset->setOdbcAttributes(odbcAttributes);
			ma_cmhpostset->setUpdateInterval(updateInterval);
			ma_cmhpostset->setCommitInterval(commitInterval);
			ma_cmhpostset->process(1);
		} break;
		case Rctables::enumGL_VPOFFPROJSET:
		{
			QScopedPointer<GL_VPOFFPROJSET> gl_vpoffprojset(new GL_VPOFFPROJSET(nullptr));
			gl_vpoffprojset->open(sourceDSN, targetDSN);
			gl_vpoffprojset->setRepositoryString(envyRepositoryString);
			gl_vpoffprojset->setProfileName(profileName);
			gl_vpoffprojset->setReplicationOption(eReplicationOption);
			gl_vpoffprojset->setDropOption(edropOption);
			gl_vpoffprojset->setOdbcAttributes(odbcAttributes);
			gl_vpoffprojset->setUpdateInterval(updateInterval);
			gl_vpoffprojset->setCommitInterval(commitInterval);
			gl_vpoffprojset->process(1);
		} break;
		case Rctables::enumAP_CHKPOSTSET:
		{
			QScopedPointer<AP_CHKPOSTSET> ap_chkpostset(new AP_CHKPOSTSET(nullptr));
			ap_chkpostset->open(sourceDSN, targetDSN);
			ap_chkpostset->setRepositoryString(envyRepositoryString);
			ap_chkpostset->setProfileName(profileName);
			ap_chkpostset->setReplicationOption(eReplicationOption);
			ap_chkpostset->setDropOption(edropOption);
			ap_chkpostset->setOdbcAttributes(odbcAttributes);
			ap_chkpostset->setUpdateInterval(updateInterval);
			ap_chkpostset->setCommitInterval(commitInterval);
			ap_chkpostset->process(1);
		} break;
		case Rctables::enumMA_TXTHSHSET:
		{
			QScopedPointer<MA_TXTHSHSET> ma_txthshset(new MA_TXTHSHSET(nullptr));
			ma_txthshset->open(sourceDSN, targetDSN);
			ma_txthshset->setRepositoryString(envyRepositoryString);
			ma_txthshset->setProfileName(profileName);
			ma_txthshset->setReplicationOption(eReplicationOption);
			ma_txthshset->setDropOption(edropOption);
			ma_txthshset->setOdbcAttributes(odbcAttributes);
			ma_txthshset->setUpdateInterval(updateInterval);
			ma_txthshset->setCommitInterval(commitInterval);
			ma_txthshset->process(1);
		} break;
		case Rctables::enumMA_INDMCMDMSET:
		{
			QScopedPointer<MA_INDMCMDMSET> ma_indmcmdmset(new MA_INDMCMDMSET(nullptr));
			ma_indmcmdmset->open(sourceDSN, targetDSN);
			ma_indmcmdmset->setRepositoryString(envyRepositoryString);
			ma_indmcmdmset->setProfileName(profileName);
			ma_indmcmdmset->setReplicationOption(eReplicationOption);
			ma_indmcmdmset->setDropOption(edropOption);
			ma_indmcmdmset->setOdbcAttributes(odbcAttributes);
			ma_indmcmdmset->setUpdateInterval(updateInterval);
			ma_indmcmdmset->setCommitInterval(commitInterval);
			ma_indmcmdmset->process(1);
		} break;
		case Rctables::enumGL_FPHSHSET:
		{
			QScopedPointer<GL_FPHSHSET> gl_fphshset(new GL_FPHSHSET(nullptr));
			gl_fphshset->open(sourceDSN, targetDSN);
			gl_fphshset->setRepositoryString(envyRepositoryString);
			gl_fphshset->setProfileName(profileName);
			gl_fphshset->setReplicationOption(eReplicationOption);
			gl_fphshset->setDropOption(edropOption);
			gl_fphshset->setOdbcAttributes(odbcAttributes);
			gl_fphshset->setUpdateInterval(updateInterval);
			gl_fphshset->setCommitInterval(commitInterval);
			gl_fphshset->process(1);
		} break;
		case Rctables::enumMA_INHAPCSET:
		{
			QScopedPointer<MA_INHAPCSET> ma_inhapcset(new MA_INHAPCSET(nullptr));
			ma_inhapcset->open(sourceDSN, targetDSN);
			ma_inhapcset->setRepositoryString(envyRepositoryString);
			ma_inhapcset->setProfileName(profileName);
			ma_inhapcset->setReplicationOption(eReplicationOption);
			ma_inhapcset->setDropOption(edropOption);
			ma_inhapcset->setOdbcAttributes(odbcAttributes);
			ma_inhapcset->setUpdateInterval(updateInterval);
			ma_inhapcset->setCommitInterval(commitInterval);
			ma_inhapcset->process(1);
		} break;
		case Rctables::enumGL_ARPT_NREC:
		{
			QScopedPointer<GL_ARPT_NREC> gl_arpt_nrec(new GL_ARPT_NREC(nullptr));
			gl_arpt_nrec->open(sourceDSN, targetDSN);
			gl_arpt_nrec->setRepositoryString(envyRepositoryString);
			gl_arpt_nrec->setProfileName(profileName);
			gl_arpt_nrec->setReplicationOption(eReplicationOption);
			gl_arpt_nrec->setDropOption(edropOption);
			gl_arpt_nrec->setOdbcAttributes(odbcAttributes);
			gl_arpt_nrec->setUpdateInterval(updateInterval);
			gl_arpt_nrec->setCommitInterval(commitInterval);
			gl_arpt_nrec->process(1);
		} break;
		case Rctables::enumMA_QUOHHSHSET:
		{
			QScopedPointer<MA_QUOHHSHSET> ma_quohhshset(new MA_QUOHHSHSET(nullptr));
			ma_quohhshset->open(sourceDSN, targetDSN);
			ma_quohhshset->setRepositoryString(envyRepositoryString);
			ma_quohhshset->setProfileName(profileName);
			ma_quohhshset->setReplicationOption(eReplicationOption);
			ma_quohhshset->setDropOption(edropOption);
			ma_quohhshset->setOdbcAttributes(odbcAttributes);
			ma_quohhshset->setUpdateInterval(updateInterval);
			ma_quohhshset->setCommitInterval(commitInterval);
			ma_quohhshset->process(1);
		} break;
		case Rctables::enumMA_STGPREC:
		{
			QScopedPointer<MA_STGPREC> ma_stgprec(new MA_STGPREC(nullptr));
			ma_stgprec->open(sourceDSN, targetDSN);
			ma_stgprec->setRepositoryString(envyRepositoryString);
			ma_stgprec->setProfileName(profileName);
			ma_stgprec->setReplicationOption(eReplicationOption);
			ma_stgprec->setDropOption(edropOption);
			ma_stgprec->setOdbcAttributes(odbcAttributes);
			ma_stgprec->setUpdateInterval(updateInterval);
			ma_stgprec->setCommitInterval(commitInterval);
			ma_stgprec->process(1);
		} break;
		case Rctables::enumFLDREC:
		{
			QScopedPointer<FLDREC> fldrec(new FLDREC(nullptr));
			fldrec->open(sourceDSN, targetDSN);
			fldrec->setRepositoryString(envyRepositoryString);
			fldrec->setProfileName(profileName);
			fldrec->setReplicationOption(eReplicationOption);
			fldrec->setDropOption(edropOption);
			fldrec->setOdbcAttributes(odbcAttributes);
			fldrec->setUpdateInterval(updateInterval);
			fldrec->setCommitInterval(commitInterval);
			fldrec->process(1);
		} break;
		case Rctables::enumRESBORSET:
		{
			QScopedPointer<RESBORSET> resborset(new RESBORSET(nullptr));
			resborset->open(sourceDSN, targetDSN);
			resborset->setRepositoryString(envyRepositoryString);
			resborset->setProfileName(profileName);
			resborset->setReplicationOption(eReplicationOption);
			resborset->setDropOption(edropOption);
			resborset->setOdbcAttributes(odbcAttributes);
			resborset->setUpdateInterval(updateInterval);
			resborset->setCommitInterval(commitInterval);
			resborset->process(1);
		} break;
		case Rctables::enumVENSHPSET:
		{
			QScopedPointer<VENSHPSET> venshpset(new VENSHPSET(nullptr));
			venshpset->open(sourceDSN, targetDSN);
			venshpset->setRepositoryString(envyRepositoryString);
			venshpset->setProfileName(profileName);
			venshpset->setReplicationOption(eReplicationOption);
			venshpset->setDropOption(edropOption);
			venshpset->setOdbcAttributes(odbcAttributes);
			venshpset->setUpdateInterval(updateInterval);
			venshpset->setCommitInterval(commitInterval);
			venshpset->process(1);
		} break;
		case Rctables::enumMA_PRCTPRTABSET:
		{
			QScopedPointer<MA_PRCTPRTABSET> ma_prctprtabset(new MA_PRCTPRTABSET(nullptr));
			ma_prctprtabset->open(sourceDSN, targetDSN);
			ma_prctprtabset->setRepositoryString(envyRepositoryString);
			ma_prctprtabset->setProfileName(profileName);
			ma_prctprtabset->setReplicationOption(eReplicationOption);
			ma_prctprtabset->setDropOption(edropOption);
			ma_prctprtabset->setOdbcAttributes(odbcAttributes);
			ma_prctprtabset->setUpdateInterval(updateInterval);
			ma_prctprtabset->setCommitInterval(commitInterval);
			ma_prctprtabset->process(1);
		} break;
		case Rctables::enumMA_PRODPRODSSET:
		{
			QScopedPointer<MA_PRODPRODSSET> ma_prodprodsset(new MA_PRODPRODSSET(nullptr));
			ma_prodprodsset->open(sourceDSN, targetDSN);
			ma_prodprodsset->setRepositoryString(envyRepositoryString);
			ma_prodprodsset->setProfileName(profileName);
			ma_prodprodsset->setReplicationOption(eReplicationOption);
			ma_prodprodsset->setDropOption(edropOption);
			ma_prodprodsset->setOdbcAttributes(odbcAttributes);
			ma_prodprodsset->setUpdateInterval(updateInterval);
			ma_prodprodsset->setCommitInterval(commitInterval);
			ma_prodprodsset->process(1);
		} break;
		case Rctables::enumCODREC:
		{
			QScopedPointer<CODREC> codrec(new CODREC(nullptr));
			codrec->open(sourceDSN, targetDSN);
			codrec->setRepositoryString(envyRepositoryString);
			codrec->setProfileName(profileName);
			codrec->setReplicationOption(eReplicationOption);
			codrec->setDropOption(edropOption);
			codrec->setOdbcAttributes(odbcAttributes);
			codrec->setUpdateInterval(updateInterval);
			codrec->setCommitInterval(commitInterval);
			codrec->process(1);
		} break;
		case Rctables::enumMA_QUODOPTSET:
		{
			QScopedPointer<MA_QUODOPTSET> ma_quodoptset(new MA_QUODOPTSET(nullptr));
			ma_quodoptset->open(sourceDSN, targetDSN);
			ma_quodoptset->setRepositoryString(envyRepositoryString);
			ma_quodoptset->setProfileName(profileName);
			ma_quodoptset->setReplicationOption(eReplicationOption);
			ma_quodoptset->setDropOption(edropOption);
			ma_quodoptset->setOdbcAttributes(odbcAttributes);
			ma_quodoptset->setUpdateInterval(updateInterval);
			ma_quodoptset->setCommitInterval(commitInterval);
			ma_quodoptset->process(1);
		} break;
		case Rctables::enumMA_CPOREC:
		{
			QScopedPointer<MA_CPOREC> ma_cporec(new MA_CPOREC(nullptr));
			ma_cporec->open(sourceDSN, targetDSN);
			ma_cporec->setRepositoryString(envyRepositoryString);
			ma_cporec->setProfileName(profileName);
			ma_cporec->setReplicationOption(eReplicationOption);
			ma_cporec->setDropOption(edropOption);
			ma_cporec->setOdbcAttributes(odbcAttributes);
			ma_cporec->setUpdateInterval(updateInterval);
			ma_cporec->setCommitInterval(commitInterval);
			ma_cporec->process(1);
		} break;
		case Rctables::enumMA_CMHCMDSET:
		{
			QScopedPointer<MA_CMHCMDSET> ma_cmhcmdset(new MA_CMHCMDSET(nullptr));
			ma_cmhcmdset->open(sourceDSN, targetDSN);
			ma_cmhcmdset->setRepositoryString(envyRepositoryString);
			ma_cmhcmdset->setProfileName(profileName);
			ma_cmhcmdset->setReplicationOption(eReplicationOption);
			ma_cmhcmdset->setDropOption(edropOption);
			ma_cmhcmdset->setOdbcAttributes(odbcAttributes);
			ma_cmhcmdset->setUpdateInterval(updateInterval);
			ma_cmhcmdset->setCommitInterval(commitInterval);
			ma_cmhcmdset->process(1);
		} break;
		case Rctables::enumED_AUDDOCSET:
		{
			QScopedPointer<ED_AUDDOCSET> ed_auddocset(new ED_AUDDOCSET(nullptr));
			ed_auddocset->open(sourceDSN, targetDSN);
			ed_auddocset->setRepositoryString(envyRepositoryString);
			ed_auddocset->setProfileName(profileName);
			ed_auddocset->setReplicationOption(eReplicationOption);
			ed_auddocset->setDropOption(edropOption);
			ed_auddocset->setOdbcAttributes(odbcAttributes);
			ed_auddocset->setUpdateInterval(updateInterval);
			ed_auddocset->setCommitInterval(commitInterval);
			ed_auddocset->process(1);
		} break;
		case Rctables::enumWKCTRKSET:
		{
			QScopedPointer<WKCTRKSET> wkctrkset(new WKCTRKSET(nullptr));
			wkctrkset->open(sourceDSN, targetDSN);
			wkctrkset->setRepositoryString(envyRepositoryString);
			wkctrkset->setProfileName(profileName);
			wkctrkset->setReplicationOption(eReplicationOption);
			wkctrkset->setDropOption(edropOption);
			wkctrkset->setOdbcAttributes(odbcAttributes);
			wkctrkset->setUpdateInterval(updateInterval);
			wkctrkset->setCommitInterval(commitInterval);
			wkctrkset->process(1);
		} break;
		case Rctables::enumMA_OPTREC:
		{
			QScopedPointer<MA_OPTREC> ma_optrec(new MA_OPTREC(nullptr));
			ma_optrec->open(sourceDSN, targetDSN);
			ma_optrec->setRepositoryString(envyRepositoryString);
			ma_optrec->setProfileName(profileName);
			ma_optrec->setReplicationOption(eReplicationOption);
			ma_optrec->setDropOption(edropOption);
			ma_optrec->setOdbcAttributes(odbcAttributes);
			ma_optrec->setUpdateInterval(updateInterval);
			ma_optrec->setCommitInterval(commitInterval);
			ma_optrec->process(1);
		} break;
		case Rctables::enumGL_ACCTMASET:
		{
			QScopedPointer<GL_ACCTMASET> gl_acctmaset(new GL_ACCTMASET(nullptr));
			gl_acctmaset->open(sourceDSN, targetDSN);
			gl_acctmaset->setRepositoryString(envyRepositoryString);
			gl_acctmaset->setProfileName(profileName);
			gl_acctmaset->setReplicationOption(eReplicationOption);
			gl_acctmaset->setDropOption(edropOption);
			gl_acctmaset->setOdbcAttributes(odbcAttributes);
			gl_acctmaset->setUpdateInterval(updateInterval);
			gl_acctmaset->setCommitInterval(commitInterval);
			gl_acctmaset->process(1);
		} break;
		case Rctables::enumMA_PRPTPRTABSET:
		{
			QScopedPointer<MA_PRPTPRTABSET> ma_prptprtabset(new MA_PRPTPRTABSET(nullptr));
			ma_prptprtabset->open(sourceDSN, targetDSN);
			ma_prptprtabset->setRepositoryString(envyRepositoryString);
			ma_prptprtabset->setProfileName(profileName);
			ma_prptprtabset->setReplicationOption(eReplicationOption);
			ma_prptprtabset->setDropOption(edropOption);
			ma_prptprtabset->setOdbcAttributes(odbcAttributes);
			ma_prptprtabset->setUpdateInterval(updateInterval);
			ma_prptprtabset->setCommitInterval(commitInterval);
			ma_prptprtabset->process(1);
		} break;
		case Rctables::enumMA_INDCOMOSET:
		{
			QScopedPointer<MA_INDCOMOSET> ma_indcomoset(new MA_INDCOMOSET(nullptr));
			ma_indcomoset->open(sourceDSN, targetDSN);
			ma_indcomoset->setRepositoryString(envyRepositoryString);
			ma_indcomoset->setProfileName(profileName);
			ma_indcomoset->setReplicationOption(eReplicationOption);
			ma_indcomoset->setDropOption(edropOption);
			ma_indcomoset->setOdbcAttributes(odbcAttributes);
			ma_indcomoset->setUpdateInterval(updateInterval);
			ma_indcomoset->setCommitInterval(commitInterval);
			ma_indcomoset->process(1);
		} break;
		case Rctables::enumPRTMTRSET:
		{
			QScopedPointer<PRTMTRSET> prtmtrset(new PRTMTRSET(nullptr));
			prtmtrset->open(sourceDSN, targetDSN);
			prtmtrset->setRepositoryString(envyRepositoryString);
			prtmtrset->setProfileName(profileName);
			prtmtrset->setReplicationOption(eReplicationOption);
			prtmtrset->setDropOption(edropOption);
			prtmtrset->setOdbcAttributes(odbcAttributes);
			prtmtrset->setUpdateInterval(updateInterval);
			prtmtrset->setCommitInterval(commitInterval);
			prtmtrset->process(1);
		} break;
		case Rctables::enumMA_ACCTCOGSSET:
		{
			QScopedPointer<MA_ACCTCOGSSET> ma_acctcogsset(new MA_ACCTCOGSSET(nullptr));
			ma_acctcogsset->open(sourceDSN, targetDSN);
			ma_acctcogsset->setRepositoryString(envyRepositoryString);
			ma_acctcogsset->setProfileName(profileName);
			ma_acctcogsset->setReplicationOption(eReplicationOption);
			ma_acctcogsset->setDropOption(edropOption);
			ma_acctcogsset->setOdbcAttributes(odbcAttributes);
			ma_acctcogsset->setUpdateInterval(updateInterval);
			ma_acctcogsset->setCommitInterval(commitInterval);
			ma_acctcogsset->process(1);
		} break;
		case Rctables::enumMA_INHSPNLSET:
		{
			QScopedPointer<MA_INHSPNLSET> ma_inhspnlset(new MA_INHSPNLSET(nullptr));
			ma_inhspnlset->open(sourceDSN, targetDSN);
			ma_inhspnlset->setRepositoryString(envyRepositoryString);
			ma_inhspnlset->setProfileName(profileName);
			ma_inhspnlset->setReplicationOption(eReplicationOption);
			ma_inhspnlset->setDropOption(edropOption);
			ma_inhspnlset->setOdbcAttributes(odbcAttributes);
			ma_inhspnlset->setUpdateInterval(updateInterval);
			ma_inhspnlset->setCommitInterval(commitInterval);
			ma_inhspnlset->process(1);
		} break;
		case Rctables::enumSOHSODSET:
		{
			QScopedPointer<SOHSODSET> sohsodset(new SOHSODSET(nullptr));
			sohsodset->open(sourceDSN, targetDSN);
			sohsodset->setRepositoryString(envyRepositoryString);
			sohsodset->setProfileName(profileName);
			sohsodset->setReplicationOption(eReplicationOption);
			sohsodset->setDropOption(edropOption);
			sohsodset->setOdbcAttributes(odbcAttributes);
			sohsodset->setUpdateInterval(updateInterval);
			sohsodset->setCommitInterval(commitInterval);
			sohsodset->process(1);
		} break;
		case Rctables::enumMA_SVINDREC:
		{
			QScopedPointer<MA_SVINDREC> ma_svindrec(new MA_SVINDREC(nullptr));
			ma_svindrec->open(sourceDSN, targetDSN);
			ma_svindrec->setRepositoryString(envyRepositoryString);
			ma_svindrec->setProfileName(profileName);
			ma_svindrec->setReplicationOption(eReplicationOption);
			ma_svindrec->setDropOption(edropOption);
			ma_svindrec->setOdbcAttributes(odbcAttributes);
			ma_svindrec->setUpdateInterval(updateInterval);
			ma_svindrec->setCommitInterval(commitInterval);
			ma_svindrec->process(1);
		} break;
		case Rctables::enumCRLABSET:
		{
			QScopedPointer<CRLABSET> crlabset(new CRLABSET(nullptr));
			crlabset->open(sourceDSN, targetDSN);
			crlabset->setRepositoryString(envyRepositoryString);
			crlabset->setProfileName(profileName);
			crlabset->setReplicationOption(eReplicationOption);
			crlabset->setDropOption(edropOption);
			crlabset->setOdbcAttributes(odbcAttributes);
			crlabset->setUpdateInterval(updateInterval);
			crlabset->setCommitInterval(commitInterval);
			crlabset->process(1);
		} break;
		case Rctables::enumGENHSHSET:
		{
			QScopedPointer<GENHSHSET> genhshset(new GENHSHSET(nullptr));
			genhshset->open(sourceDSN, targetDSN);
			genhshset->setRepositoryString(envyRepositoryString);
			genhshset->setProfileName(profileName);
			genhshset->setReplicationOption(eReplicationOption);
			genhshset->setDropOption(edropOption);
			genhshset->setOdbcAttributes(odbcAttributes);
			genhshset->setUpdateInterval(updateInterval);
			genhshset->setCommitInterval(commitInterval);
			genhshset->process(1);
		} break;
		case Rctables::enumTOOTWUSET:
		{
			QScopedPointer<TOOTWUSET> tootwuset(new TOOTWUSET(nullptr));
			tootwuset->open(sourceDSN, targetDSN);
			tootwuset->setRepositoryString(envyRepositoryString);
			tootwuset->setProfileName(profileName);
			tootwuset->setReplicationOption(eReplicationOption);
			tootwuset->setDropOption(edropOption);
			tootwuset->setOdbcAttributes(odbcAttributes);
			tootwuset->setUpdateInterval(updateInterval);
			tootwuset->setCommitInterval(commitInterval);
			tootwuset->process(1);
		} break;
		case Rctables::enumMA_ACCTTRASET:
		{
			QScopedPointer<MA_ACCTTRASET> ma_accttraset(new MA_ACCTTRASET(nullptr));
			ma_accttraset->open(sourceDSN, targetDSN);
			ma_accttraset->setRepositoryString(envyRepositoryString);
			ma_accttraset->setProfileName(profileName);
			ma_accttraset->setReplicationOption(eReplicationOption);
			ma_accttraset->setDropOption(edropOption);
			ma_accttraset->setOdbcAttributes(odbcAttributes);
			ma_accttraset->setUpdateInterval(updateInterval);
			ma_accttraset->setCommitInterval(commitInterval);
			ma_accttraset->process(1);
		} break;
		case Rctables::enumED_AUDHSHSET:
		{
			QScopedPointer<ED_AUDHSHSET> ed_audhshset(new ED_AUDHSHSET(nullptr));
			ed_audhshset->open(sourceDSN, targetDSN);
			ed_audhshset->setRepositoryString(envyRepositoryString);
			ed_audhshset->setProfileName(profileName);
			ed_audhshset->setReplicationOption(eReplicationOption);
			ed_audhshset->setDropOption(edropOption);
			ed_audhshset->setOdbcAttributes(odbcAttributes);
			ed_audhshset->setUpdateInterval(updateInterval);
			ed_audhshset->setCommitInterval(commitInterval);
			ed_audhshset->process(1);
		} break;
		case Rctables::enumMA_SOHSHHSET:
		{
			QScopedPointer<MA_SOHSHHSET> ma_sohshhset(new MA_SOHSHHSET(nullptr));
			ma_sohshhset->open(sourceDSN, targetDSN);
			ma_sohshhset->setRepositoryString(envyRepositoryString);
			ma_sohshhset->setProfileName(profileName);
			ma_sohshhset->setReplicationOption(eReplicationOption);
			ma_sohshhset->setDropOption(edropOption);
			ma_sohshhset->setOdbcAttributes(odbcAttributes);
			ma_sohshhset->setUpdateInterval(updateInterval);
			ma_sohshhset->setCommitInterval(commitInterval);
			ma_sohshhset->process(1);
		} break;
		case Rctables::enumGL_PAMTREC:
		{
			QScopedPointer<GL_PAMTREC> gl_pamtrec(new GL_PAMTREC(nullptr));
			gl_pamtrec->open(sourceDSN, targetDSN);
			gl_pamtrec->setRepositoryString(envyRepositoryString);
			gl_pamtrec->setProfileName(profileName);
			gl_pamtrec->setReplicationOption(eReplicationOption);
			gl_pamtrec->setDropOption(edropOption);
			gl_pamtrec->setOdbcAttributes(odbcAttributes);
			gl_pamtrec->setUpdateInterval(updateInterval);
			gl_pamtrec->setCommitInterval(commitInterval);
			gl_pamtrec->process(1);
		} break;
		case Rctables::enumED_ENTREC:
		{
			QScopedPointer<ED_ENTREC> ed_entrec(new ED_ENTREC(nullptr));
			ed_entrec->open(sourceDSN, targetDSN);
			ed_entrec->setRepositoryString(envyRepositoryString);
			ed_entrec->setProfileName(profileName);
			ed_entrec->setReplicationOption(eReplicationOption);
			ed_entrec->setDropOption(edropOption);
			ed_entrec->setOdbcAttributes(odbcAttributes);
			ed_entrec->setUpdateInterval(updateInterval);
			ed_entrec->setCommitInterval(commitInterval);
			ed_entrec->process(1);
		} break;
		case Rctables::enumMA_INHSPISET:
		{
			QScopedPointer<MA_INHSPISET> ma_inhspiset(new MA_INHSPISET(nullptr));
			ma_inhspiset->open(sourceDSN, targetDSN);
			ma_inhspiset->setRepositoryString(envyRepositoryString);
			ma_inhspiset->setProfileName(profileName);
			ma_inhspiset->setReplicationOption(eReplicationOption);
			ma_inhspiset->setDropOption(edropOption);
			ma_inhspiset->setOdbcAttributes(odbcAttributes);
			ma_inhspiset->setUpdateInterval(updateInterval);
			ma_inhspiset->setCommitInterval(commitInterval);
			ma_inhspiset->process(1);
		} break;
		case Rctables::enumGL_LINK_NREC:
		{
			QScopedPointer<GL_LINK_NREC> gl_link_nrec(new GL_LINK_NREC(nullptr));
			gl_link_nrec->open(sourceDSN, targetDSN);
			gl_link_nrec->setRepositoryString(envyRepositoryString);
			gl_link_nrec->setProfileName(profileName);
			gl_link_nrec->setReplicationOption(eReplicationOption);
			gl_link_nrec->setDropOption(edropOption);
			gl_link_nrec->setOdbcAttributes(odbcAttributes);
			gl_link_nrec->setUpdateInterval(updateInterval);
			gl_link_nrec->setCommitInterval(commitInterval);
			gl_link_nrec->process(1);
		} break;
		case Rctables::enumGL_FPFRACCTSET:
		{
			QScopedPointer<GL_FPFRACCTSET> gl_fpfracctset(new GL_FPFRACCTSET(nullptr));
			gl_fpfracctset->open(sourceDSN, targetDSN);
			gl_fpfracctset->setRepositoryString(envyRepositoryString);
			gl_fpfracctset->setProfileName(profileName);
			gl_fpfracctset->setReplicationOption(eReplicationOption);
			gl_fpfracctset->setDropOption(edropOption);
			gl_fpfracctset->setOdbcAttributes(odbcAttributes);
			gl_fpfracctset->setUpdateInterval(updateInterval);
			gl_fpfracctset->setCommitInterval(commitInterval);
			gl_fpfracctset->process(1);
		} break;
		case Rctables::enumAP_POHVCHREC:
		{
			QScopedPointer<AP_POHVCHREC> ap_pohvchrec(new AP_POHVCHREC(nullptr));
			ap_pohvchrec->open(sourceDSN, targetDSN);
			ap_pohvchrec->setRepositoryString(envyRepositoryString);
			ap_pohvchrec->setProfileName(profileName);
			ap_pohvchrec->setReplicationOption(eReplicationOption);
			ap_pohvchrec->setDropOption(edropOption);
			ap_pohvchrec->setOdbcAttributes(odbcAttributes);
			ap_pohvchrec->setUpdateInterval(updateInterval);
			ap_pohvchrec->setCommitInterval(commitInterval);
			ap_pohvchrec->process(1);
		} break;
		case Rctables::enumMA_CTERSHPSET:
		{
			QScopedPointer<MA_CTERSHPSET> ma_ctershpset(new MA_CTERSHPSET(nullptr));
			ma_ctershpset->open(sourceDSN, targetDSN);
			ma_ctershpset->setRepositoryString(envyRepositoryString);
			ma_ctershpset->setProfileName(profileName);
			ma_ctershpset->setReplicationOption(eReplicationOption);
			ma_ctershpset->setDropOption(edropOption);
			ma_ctershpset->setOdbcAttributes(odbcAttributes);
			ma_ctershpset->setUpdateInterval(updateInterval);
			ma_ctershpset->setCommitInterval(commitInterval);
			ma_ctershpset->process(1);
		} break;
		case Rctables::enumCSTREC:
		{
			QScopedPointer<CSTREC> cstrec(new CSTREC(nullptr));
			cstrec->open(sourceDSN, targetDSN);
			cstrec->setRepositoryString(envyRepositoryString);
			cstrec->setProfileName(profileName);
			cstrec->setReplicationOption(eReplicationOption);
			cstrec->setDropOption(edropOption);
			cstrec->setOdbcAttributes(odbcAttributes);
			cstrec->setUpdateInterval(updateInterval);
			cstrec->setCommitInterval(commitInterval);
			cstrec->process(1);
		} break;
		case Rctables::enumAP_PPVNDSET:
		{
			QScopedPointer<AP_PPVNDSET> ap_ppvndset(new AP_PPVNDSET(nullptr));
			ap_ppvndset->open(sourceDSN, targetDSN);
			ap_ppvndset->setRepositoryString(envyRepositoryString);
			ap_ppvndset->setProfileName(profileName);
			ap_ppvndset->setReplicationOption(eReplicationOption);
			ap_ppvndset->setDropOption(edropOption);
			ap_ppvndset->setOdbcAttributes(odbcAttributes);
			ap_ppvndset->setUpdateInterval(updateInterval);
			ap_ppvndset->setCommitInterval(commitInterval);
			ap_ppvndset->process(1);
		} break;
		case Rctables::enumAP_INVHSHSET:
		{
			QScopedPointer<AP_INVHSHSET> ap_invhshset(new AP_INVHSHSET(nullptr));
			ap_invhshset->open(sourceDSN, targetDSN);
			ap_invhshset->setRepositoryString(envyRepositoryString);
			ap_invhshset->setProfileName(profileName);
			ap_invhshset->setReplicationOption(eReplicationOption);
			ap_invhshset->setDropOption(edropOption);
			ap_invhshset->setOdbcAttributes(odbcAttributes);
			ap_invhshset->setUpdateInterval(updateInterval);
			ap_invhshset->setCommitInterval(commitInterval);
			ap_invhshset->process(1);
		} break;
		case Rctables::enumIDREC:
		{
			QScopedPointer<IDREC> idrec(new IDREC(nullptr));
			idrec->open(sourceDSN, targetDSN);
			idrec->setRepositoryString(envyRepositoryString);
			idrec->setProfileName(profileName);
			idrec->setReplicationOption(eReplicationOption);
			idrec->setDropOption(edropOption);
			idrec->setOdbcAttributes(odbcAttributes);
			idrec->setUpdateInterval(updateInterval);
			idrec->setCommitInterval(commitInterval);
			idrec->process(1);
		} break;
		case Rctables::enumMA_SHHHSHSET:
		{
			QScopedPointer<MA_SHHHSHSET> ma_shhhshset(new MA_SHHHSHSET(nullptr));
			ma_shhhshset->open(sourceDSN, targetDSN);
			ma_shhhshset->setRepositoryString(envyRepositoryString);
			ma_shhhshset->setProfileName(profileName);
			ma_shhhshset->setReplicationOption(eReplicationOption);
			ma_shhhshset->setDropOption(edropOption);
			ma_shhhshset->setOdbcAttributes(odbcAttributes);
			ma_shhhshset->setUpdateInterval(updateInterval);
			ma_shhhshset->setCommitInterval(commitInterval);
			ma_shhhshset->process(1);
		} break;
		case Rctables::enumMA_INHREC:
		{
			QScopedPointer<MA_INHREC> ma_inhrec(new MA_INHREC(nullptr));
			ma_inhrec->open(sourceDSN, targetDSN);
			ma_inhrec->setRepositoryString(envyRepositoryString);
			ma_inhrec->setProfileName(profileName);
			ma_inhrec->setReplicationOption(eReplicationOption);
			ma_inhrec->setDropOption(edropOption);
			ma_inhrec->setOdbcAttributes(odbcAttributes);
			ma_inhrec->setUpdateInterval(updateInterval);
			ma_inhrec->setCommitInterval(commitInterval);
			ma_inhrec->process(1);
		} break;
		case Rctables::enumIRCTREC:
		{
			QScopedPointer<IRCTREC> irctrec(new IRCTREC(nullptr));
			irctrec->open(sourceDSN, targetDSN);
			irctrec->setRepositoryString(envyRepositoryString);
			irctrec->setProfileName(profileName);
			irctrec->setReplicationOption(eReplicationOption);
			irctrec->setDropOption(edropOption);
			irctrec->setOdbcAttributes(odbcAttributes);
			irctrec->setUpdateInterval(updateInterval);
			irctrec->setCommitInterval(commitInterval);
			irctrec->process(1);
		} break;
		case Rctables::enumMA_CPOHSHSET:
		{
			QScopedPointer<MA_CPOHSHSET> ma_cpohshset(new MA_CPOHSHSET(nullptr));
			ma_cpohshset->open(sourceDSN, targetDSN);
			ma_cpohshset->setRepositoryString(envyRepositoryString);
			ma_cpohshset->setProfileName(profileName);
			ma_cpohshset->setReplicationOption(eReplicationOption);
			ma_cpohshset->setDropOption(edropOption);
			ma_cpohshset->setOdbcAttributes(odbcAttributes);
			ma_cpohshset->setUpdateInterval(updateInterval);
			ma_cpohshset->setCommitInterval(commitInterval);
			ma_cpohshset->process(1);
		} break;
		case Rctables::enumMA_PLINREC:
		{
			QScopedPointer<MA_PLINREC> ma_plinrec(new MA_PLINREC(nullptr));
			ma_plinrec->open(sourceDSN, targetDSN);
			ma_plinrec->setRepositoryString(envyRepositoryString);
			ma_plinrec->setProfileName(profileName);
			ma_plinrec->setReplicationOption(eReplicationOption);
			ma_plinrec->setDropOption(edropOption);
			ma_plinrec->setOdbcAttributes(odbcAttributes);
			ma_plinrec->setUpdateInterval(updateInterval);
			ma_plinrec->setCommitInterval(commitInterval);
			ma_plinrec->process(1);
		} break;
		case Rctables::enumBOLRCTSET:
		{
			QScopedPointer<BOLRCTSET> bolrctset(new BOLRCTSET(nullptr));
			bolrctset->open(sourceDSN, targetDSN);
			bolrctset->setRepositoryString(envyRepositoryString);
			bolrctset->setProfileName(profileName);
			bolrctset->setReplicationOption(eReplicationOption);
			bolrctset->setDropOption(edropOption);
			bolrctset->setOdbcAttributes(odbcAttributes);
			bolrctset->setUpdateInterval(updateInterval);
			bolrctset->setCommitInterval(commitInterval);
			bolrctset->process(1);
		} break;
		case Rctables::enumAP_INVRCTRCTMSET:
		{
			QScopedPointer<AP_INVRCTRCTMSET> ap_invrctrctmset(new AP_INVRCTRCTMSET(nullptr));
			ap_invrctrctmset->open(sourceDSN, targetDSN);
			ap_invrctrctmset->setRepositoryString(envyRepositoryString);
			ap_invrctrctmset->setProfileName(profileName);
			ap_invrctrctmset->setReplicationOption(eReplicationOption);
			ap_invrctrctmset->setDropOption(edropOption);
			ap_invrctrctmset->setOdbcAttributes(odbcAttributes);
			ap_invrctrctmset->setUpdateInterval(updateInterval);
			ap_invrctrctmset->setCommitInterval(commitInterval);
			ap_invrctrctmset->process(1);
		} break;
		case Rctables::enumGL_RE_HREC:
		{
			QScopedPointer<GL_RE_HREC> gl_re_hrec(new GL_RE_HREC(nullptr));
			gl_re_hrec->open(sourceDSN, targetDSN);
			gl_re_hrec->setRepositoryString(envyRepositoryString);
			gl_re_hrec->setProfileName(profileName);
			gl_re_hrec->setReplicationOption(eReplicationOption);
			gl_re_hrec->setDropOption(edropOption);
			gl_re_hrec->setOdbcAttributes(odbcAttributes);
			gl_re_hrec->setUpdateInterval(updateInterval);
			gl_re_hrec->setCommitInterval(commitInterval);
			gl_re_hrec->process(1);
		} break;
		case Rctables::enumMA_STGPHSHSET:
		{
			QScopedPointer<MA_STGPHSHSET> ma_stgphshset(new MA_STGPHSHSET(nullptr));
			ma_stgphshset->open(sourceDSN, targetDSN);
			ma_stgphshset->setRepositoryString(envyRepositoryString);
			ma_stgphshset->setProfileName(profileName);
			ma_stgphshset->setReplicationOption(eReplicationOption);
			ma_stgphshset->setDropOption(edropOption);
			ma_stgphshset->setOdbcAttributes(odbcAttributes);
			ma_stgphshset->setUpdateInterval(updateInterval);
			ma_stgphshset->setCommitInterval(commitInterval);
			ma_stgphshset->process(1);
		} break;
		case Rctables::enumGL_ISBSREC:
		{
			QScopedPointer<GL_ISBSREC> gl_isbsrec(new GL_ISBSREC(nullptr));
			gl_isbsrec->open(sourceDSN, targetDSN);
			gl_isbsrec->setRepositoryString(envyRepositoryString);
			gl_isbsrec->setProfileName(profileName);
			gl_isbsrec->setReplicationOption(eReplicationOption);
			gl_isbsrec->setDropOption(edropOption);
			gl_isbsrec->setOdbcAttributes(odbcAttributes);
			gl_isbsrec->setUpdateInterval(updateInterval);
			gl_isbsrec->setCommitInterval(commitInterval);
			gl_isbsrec->process(1);
		} break;
		case Rctables::enumAUTREC:
		{
			QScopedPointer<AUTREC> autrec(new AUTREC(nullptr));
			autrec->open(sourceDSN, targetDSN);
			autrec->setRepositoryString(envyRepositoryString);
			autrec->setProfileName(profileName);
			autrec->setReplicationOption(eReplicationOption);
			autrec->setDropOption(edropOption);
			autrec->setOdbcAttributes(odbcAttributes);
			autrec->setUpdateInterval(updateInterval);
			autrec->setCommitInterval(commitInterval);
			autrec->process(1);
		} break;
		case Rctables::enumMA_SPNSPNLSET:
		{
			QScopedPointer<MA_SPNSPNLSET> ma_spnspnlset(new MA_SPNSPNLSET(nullptr));
			ma_spnspnlset->open(sourceDSN, targetDSN);
			ma_spnspnlset->setRepositoryString(envyRepositoryString);
			ma_spnspnlset->setProfileName(profileName);
			ma_spnspnlset->setReplicationOption(eReplicationOption);
			ma_spnspnlset->setDropOption(edropOption);
			ma_spnspnlset->setOdbcAttributes(odbcAttributes);
			ma_spnspnlset->setUpdateInterval(updateInterval);
			ma_spnspnlset->setCommitInterval(commitInterval);
			ma_spnspnlset->process(1);
		} break;
		case Rctables::enumSPNHSHSET:
		{
			QScopedPointer<SPNHSHSET> spnhshset(new SPNHSHSET(nullptr));
			spnhshset->open(sourceDSN, targetDSN);
			spnhshset->setRepositoryString(envyRepositoryString);
			spnhshset->setProfileName(profileName);
			spnhshset->setReplicationOption(eReplicationOption);
			spnhshset->setDropOption(edropOption);
			spnhshset->setOdbcAttributes(odbcAttributes);
			spnhshset->setUpdateInterval(updateInterval);
			spnhshset->setCommitInterval(commitInterval);
			spnhshset->process(1);
		} break;
		case Rctables::enumMA_SPIREC:
		{
			QScopedPointer<MA_SPIREC> ma_spirec(new MA_SPIREC(nullptr));
			ma_spirec->open(sourceDSN, targetDSN);
			ma_spirec->setRepositoryString(envyRepositoryString);
			ma_spirec->setProfileName(profileName);
			ma_spirec->setReplicationOption(eReplicationOption);
			ma_spirec->setDropOption(edropOption);
			ma_spirec->setOdbcAttributes(odbcAttributes);
			ma_spirec->setUpdateInterval(updateInterval);
			ma_spirec->setCommitInterval(commitInterval);
			ma_spirec->process(1);
		} break;
		case Rctables::enumGL_VPTOSET:
		{
			QScopedPointer<GL_VPTOSET> gl_vptoset(new GL_VPTOSET(nullptr));
			gl_vptoset->open(sourceDSN, targetDSN);
			gl_vptoset->setRepositoryString(envyRepositoryString);
			gl_vptoset->setProfileName(profileName);
			gl_vptoset->setReplicationOption(eReplicationOption);
			gl_vptoset->setDropOption(edropOption);
			gl_vptoset->setOdbcAttributes(odbcAttributes);
			gl_vptoset->setUpdateInterval(updateInterval);
			gl_vptoset->setCommitInterval(commitInterval);
			gl_vptoset->process(1);
		} break;
		case Rctables::enumMA_INHSVINHSET:
		{
			QScopedPointer<MA_INHSVINHSET> ma_inhsvinhset(new MA_INHSVINHSET(nullptr));
			ma_inhsvinhset->open(sourceDSN, targetDSN);
			ma_inhsvinhset->setRepositoryString(envyRepositoryString);
			ma_inhsvinhset->setProfileName(profileName);
			ma_inhsvinhset->setReplicationOption(eReplicationOption);
			ma_inhsvinhset->setDropOption(edropOption);
			ma_inhsvinhset->setOdbcAttributes(odbcAttributes);
			ma_inhsvinhset->setUpdateInterval(updateInterval);
			ma_inhsvinhset->setCommitInterval(commitInterval);
			ma_inhsvinhset->process(1);
		} break;
		case Rctables::enumMA_ACTCOGSSET:
		{
			QScopedPointer<MA_ACTCOGSSET> ma_actcogsset(new MA_ACTCOGSSET(nullptr));
			ma_actcogsset->open(sourceDSN, targetDSN);
			ma_actcogsset->setRepositoryString(envyRepositoryString);
			ma_actcogsset->setProfileName(profileName);
			ma_actcogsset->setReplicationOption(eReplicationOption);
			ma_actcogsset->setDropOption(edropOption);
			ma_actcogsset->setOdbcAttributes(odbcAttributes);
			ma_actcogsset->setUpdateInterval(updateInterval);
			ma_actcogsset->setCommitInterval(commitInterval);
			ma_actcogsset->process(1);
		} break;
		case Rctables::enumMA_SHDSPNLSET:
		{
			QScopedPointer<MA_SHDSPNLSET> ma_shdspnlset(new MA_SHDSPNLSET(nullptr));
			ma_shdspnlset->open(sourceDSN, targetDSN);
			ma_shdspnlset->setRepositoryString(envyRepositoryString);
			ma_shdspnlset->setProfileName(profileName);
			ma_shdspnlset->setReplicationOption(eReplicationOption);
			ma_shdspnlset->setDropOption(edropOption);
			ma_shdspnlset->setOdbcAttributes(odbcAttributes);
			ma_shdspnlset->setUpdateInterval(updateInterval);
			ma_shdspnlset->setCommitInterval(commitInterval);
			ma_shdspnlset->process(1);
		} break;
		case Rctables::enumAP_VNDBOLSET:
		{
			QScopedPointer<AP_VNDBOLSET> ap_vndbolset(new AP_VNDBOLSET(nullptr));
			ap_vndbolset->open(sourceDSN, targetDSN);
			ap_vndbolset->setRepositoryString(envyRepositoryString);
			ap_vndbolset->setProfileName(profileName);
			ap_vndbolset->setReplicationOption(eReplicationOption);
			ap_vndbolset->setDropOption(edropOption);
			ap_vndbolset->setOdbcAttributes(odbcAttributes);
			ap_vndbolset->setUpdateInterval(updateInterval);
			ap_vndbolset->setCommitInterval(commitInterval);
			ap_vndbolset->process(1);
		} break;
		case Rctables::enumVENIRCTSET:
		{
			QScopedPointer<VENIRCTSET> venirctset(new VENIRCTSET(nullptr));
			venirctset->open(sourceDSN, targetDSN);
			venirctset->setRepositoryString(envyRepositoryString);
			venirctset->setProfileName(profileName);
			venirctset->setReplicationOption(eReplicationOption);
			venirctset->setDropOption(edropOption);
			venirctset->setOdbcAttributes(odbcAttributes);
			venirctset->setUpdateInterval(updateInterval);
			venirctset->setCommitInterval(commitInterval);
			venirctset->process(1);
		} break;
		case Rctables::enumAP_CNOTEREC:
		{
			QScopedPointer<AP_CNOTEREC> ap_cnoterec(new AP_CNOTEREC(nullptr));
			ap_cnoterec->open(sourceDSN, targetDSN);
			ap_cnoterec->setRepositoryString(envyRepositoryString);
			ap_cnoterec->setProfileName(profileName);
			ap_cnoterec->setReplicationOption(eReplicationOption);
			ap_cnoterec->setDropOption(edropOption);
			ap_cnoterec->setOdbcAttributes(odbcAttributes);
			ap_cnoterec->setUpdateInterval(updateInterval);
			ap_cnoterec->setCommitInterval(commitInterval);
			ap_cnoterec->process(1);
		} break;
		case Rctables::enumAP_POHREC:
		{
			QScopedPointer<AP_POHREC> ap_pohrec(new AP_POHREC(nullptr));
			ap_pohrec->open(sourceDSN, targetDSN);
			ap_pohrec->setRepositoryString(envyRepositoryString);
			ap_pohrec->setProfileName(profileName);
			ap_pohrec->setReplicationOption(eReplicationOption);
			ap_pohrec->setDropOption(edropOption);
			ap_pohrec->setOdbcAttributes(odbcAttributes);
			ap_pohrec->setUpdateInterval(updateInterval);
			ap_pohrec->setCommitInterval(commitInterval);
			ap_pohrec->process(1);
		} break;
		case Rctables::enumAP_PNOTREC:
		{
			QScopedPointer<AP_PNOTREC> ap_pnotrec(new AP_PNOTREC(nullptr));
			ap_pnotrec->open(sourceDSN, targetDSN);
			ap_pnotrec->setRepositoryString(envyRepositoryString);
			ap_pnotrec->setProfileName(profileName);
			ap_pnotrec->setReplicationOption(eReplicationOption);
			ap_pnotrec->setDropOption(edropOption);
			ap_pnotrec->setOdbcAttributes(odbcAttributes);
			ap_pnotrec->setUpdateInterval(updateInterval);
			ap_pnotrec->setCommitInterval(commitInterval);
			ap_pnotrec->process(1);
		} break;
		case Rctables::enumMISMISREFSET:
		{
			QScopedPointer<MISMISREFSET> mismisrefset(new MISMISREFSET(nullptr));
			mismisrefset->open(sourceDSN, targetDSN);
			mismisrefset->setRepositoryString(envyRepositoryString);
			mismisrefset->setProfileName(profileName);
			mismisrefset->setReplicationOption(eReplicationOption);
			mismisrefset->setDropOption(edropOption);
			mismisrefset->setOdbcAttributes(odbcAttributes);
			mismisrefset->setUpdateInterval(updateInterval);
			mismisrefset->setCommitInterval(commitInterval);
			mismisrefset->process(1);
		} break;
		case Rctables::enumMA_PRODFCPRTABSET:
		{
			QScopedPointer<MA_PRODFCPRTABSET> ma_prodfcprtabset(new MA_PRODFCPRTABSET(nullptr));
			ma_prodfcprtabset->open(sourceDSN, targetDSN);
			ma_prodfcprtabset->setRepositoryString(envyRepositoryString);
			ma_prodfcprtabset->setProfileName(profileName);
			ma_prodfcprtabset->setReplicationOption(eReplicationOption);
			ma_prodfcprtabset->setDropOption(edropOption);
			ma_prodfcprtabset->setOdbcAttributes(odbcAttributes);
			ma_prodfcprtabset->setUpdateInterval(updateInterval);
			ma_prodfcprtabset->setCommitInterval(commitInterval);
			ma_prodfcprtabset->process(1);
		} break;
		case Rctables::enumMA_PRODOPTSET:
		{
			QScopedPointer<MA_PRODOPTSET> ma_prodoptset(new MA_PRODOPTSET(nullptr));
			ma_prodoptset->open(sourceDSN, targetDSN);
			ma_prodoptset->setRepositoryString(envyRepositoryString);
			ma_prodoptset->setProfileName(profileName);
			ma_prodoptset->setReplicationOption(eReplicationOption);
			ma_prodoptset->setDropOption(edropOption);
			ma_prodoptset->setOdbcAttributes(odbcAttributes);
			ma_prodoptset->setUpdateInterval(updateInterval);
			ma_prodoptset->setCommitInterval(commitInterval);
			ma_prodoptset->process(1);
		} break;
		case Rctables::enumAP_RCTHSHSET:
		{
			QScopedPointer<AP_RCTHSHSET> ap_rcthshset(new AP_RCTHSHSET(nullptr));
			ap_rcthshset->open(sourceDSN, targetDSN);
			ap_rcthshset->setRepositoryString(envyRepositoryString);
			ap_rcthshset->setProfileName(profileName);
			ap_rcthshset->setReplicationOption(eReplicationOption);
			ap_rcthshset->setDropOption(edropOption);
			ap_rcthshset->setOdbcAttributes(odbcAttributes);
			ap_rcthshset->setUpdateInterval(updateInterval);
			ap_rcthshset->setCommitInterval(commitInterval);
			ap_rcthshset->process(1);
		} break;
		case Rctables::enumGL_FPFRLINKREC:
		{
			QScopedPointer<GL_FPFRLINKREC> gl_fpfrlinkrec(new GL_FPFRLINKREC(nullptr));
			gl_fpfrlinkrec->open(sourceDSN, targetDSN);
			gl_fpfrlinkrec->setRepositoryString(envyRepositoryString);
			gl_fpfrlinkrec->setProfileName(profileName);
			gl_fpfrlinkrec->setReplicationOption(eReplicationOption);
			gl_fpfrlinkrec->setDropOption(edropOption);
			gl_fpfrlinkrec->setOdbcAttributes(odbcAttributes);
			gl_fpfrlinkrec->setUpdateInterval(updateInterval);
			gl_fpfrlinkrec->setCommitInterval(commitInterval);
			gl_fpfrlinkrec->process(1);
		} break;
		case Rctables::enumMA_HLDHSHSET:
		{
			QScopedPointer<MA_HLDHSHSET> ma_hldhshset(new MA_HLDHSHSET(nullptr));
			ma_hldhshset->open(sourceDSN, targetDSN);
			ma_hldhshset->setRepositoryString(envyRepositoryString);
			ma_hldhshset->setProfileName(profileName);
			ma_hldhshset->setReplicationOption(eReplicationOption);
			ma_hldhshset->setDropOption(edropOption);
			ma_hldhshset->setOdbcAttributes(odbcAttributes);
			ma_hldhshset->setUpdateInterval(updateInterval);
			ma_hldhshset->setCommitInterval(commitInterval);
			ma_hldhshset->process(1);
		} break;
		case Rctables::enumMA_INDMREC:
		{
			QScopedPointer<MA_INDMREC> ma_indmrec(new MA_INDMREC(nullptr));
			ma_indmrec->open(sourceDSN, targetDSN);
			ma_indmrec->setRepositoryString(envyRepositoryString);
			ma_indmrec->setProfileName(profileName);
			ma_indmrec->setReplicationOption(eReplicationOption);
			ma_indmrec->setDropOption(edropOption);
			ma_indmrec->setOdbcAttributes(odbcAttributes);
			ma_indmrec->setUpdateInterval(updateInterval);
			ma_indmrec->setCommitInterval(commitInterval);
			ma_indmrec->process(1);
		} break;
		case Rctables::enumMA_PAYTHSHSET:
		{
			QScopedPointer<MA_PAYTHSHSET> ma_paythshset(new MA_PAYTHSHSET(nullptr));
			ma_paythshset->open(sourceDSN, targetDSN);
			ma_paythshset->setRepositoryString(envyRepositoryString);
			ma_paythshset->setProfileName(profileName);
			ma_paythshset->setReplicationOption(eReplicationOption);
			ma_paythshset->setDropOption(edropOption);
			ma_paythshset->setOdbcAttributes(odbcAttributes);
			ma_paythshset->setUpdateInterval(updateInterval);
			ma_paythshset->setCommitInterval(commitInterval);
			ma_paythshset->process(1);
		} break;
		case Rctables::enumMA_POSTREC:
		{
			QScopedPointer<MA_POSTREC> ma_postrec(new MA_POSTREC(nullptr));
			ma_postrec->open(sourceDSN, targetDSN);
			ma_postrec->setRepositoryString(envyRepositoryString);
			ma_postrec->setProfileName(profileName);
			ma_postrec->setReplicationOption(eReplicationOption);
			ma_postrec->setDropOption(edropOption);
			ma_postrec->setOdbcAttributes(odbcAttributes);
			ma_postrec->setUpdateInterval(updateInterval);
			ma_postrec->setCommitInterval(commitInterval);
			ma_postrec->process(1);
		} break;
		case Rctables::enumGL_ABUDSET:
		{
			QScopedPointer<GL_ABUDSET> gl_abudset(new GL_ABUDSET(nullptr));
			gl_abudset->open(sourceDSN, targetDSN);
			gl_abudset->setRepositoryString(envyRepositoryString);
			gl_abudset->setProfileName(profileName);
			gl_abudset->setReplicationOption(eReplicationOption);
			gl_abudset->setDropOption(edropOption);
			gl_abudset->setOdbcAttributes(odbcAttributes);
			gl_abudset->setUpdateInterval(updateInterval);
			gl_abudset->setCommitInterval(commitInterval);
			gl_abudset->process(1);
		} break;
		case Rctables::enumRCTREC:
		{
			QScopedPointer<RCTREC> rctrec(new RCTREC(nullptr));
			rctrec->open(sourceDSN, targetDSN);
			rctrec->setRepositoryString(envyRepositoryString);
			rctrec->setProfileName(profileName);
			rctrec->setReplicationOption(eReplicationOption);
			rctrec->setDropOption(edropOption);
			rctrec->setOdbcAttributes(odbcAttributes);
			rctrec->setUpdateInterval(updateInterval);
			rctrec->setCommitInterval(commitInterval);
			rctrec->process(1);
		} break;
		case Rctables::enumMA_SODCOMOSET:
		{
			QScopedPointer<MA_SODCOMOSET> ma_sodcomoset(new MA_SODCOMOSET(nullptr));
			ma_sodcomoset->open(sourceDSN, targetDSN);
			ma_sodcomoset->setRepositoryString(envyRepositoryString);
			ma_sodcomoset->setProfileName(profileName);
			ma_sodcomoset->setReplicationOption(eReplicationOption);
			ma_sodcomoset->setDropOption(edropOption);
			ma_sodcomoset->setOdbcAttributes(odbcAttributes);
			ma_sodcomoset->setUpdateInterval(updateInterval);
			ma_sodcomoset->setCommitInterval(commitInterval);
			ma_sodcomoset->process(1);
		} break;
		case Rctables::enumMA_SAMCOMOSET:
		{
			QScopedPointer<MA_SAMCOMOSET> ma_samcomoset(new MA_SAMCOMOSET(nullptr));
			ma_samcomoset->open(sourceDSN, targetDSN);
			ma_samcomoset->setRepositoryString(envyRepositoryString);
			ma_samcomoset->setProfileName(profileName);
			ma_samcomoset->setReplicationOption(eReplicationOption);
			ma_samcomoset->setDropOption(edropOption);
			ma_samcomoset->setOdbcAttributes(odbcAttributes);
			ma_samcomoset->setUpdateInterval(updateInterval);
			ma_samcomoset->setCommitInterval(commitInterval);
			ma_samcomoset->process(1);
		} break;
		case Rctables::enumWKCLABSET:
		{
			QScopedPointer<WKCLABSET> wkclabset(new WKCLABSET(nullptr));
			wkclabset->open(sourceDSN, targetDSN);
			wkclabset->setRepositoryString(envyRepositoryString);
			wkclabset->setProfileName(profileName);
			wkclabset->setReplicationOption(eReplicationOption);
			wkclabset->setDropOption(edropOption);
			wkclabset->setOdbcAttributes(odbcAttributes);
			wkclabset->setUpdateInterval(updateInterval);
			wkclabset->setCommitInterval(commitInterval);
			wkclabset->process(1);
		} break;
		case Rctables::enumMA_GLPTREC:
		{
			QScopedPointer<MA_GLPTREC> ma_glptrec(new MA_GLPTREC(nullptr));
			ma_glptrec->open(sourceDSN, targetDSN);
			ma_glptrec->setRepositoryString(envyRepositoryString);
			ma_glptrec->setProfileName(profileName);
			ma_glptrec->setReplicationOption(eReplicationOption);
			ma_glptrec->setDropOption(edropOption);
			ma_glptrec->setOdbcAttributes(odbcAttributes);
			ma_glptrec->setUpdateInterval(updateInterval);
			ma_glptrec->setCommitInterval(commitInterval);
			ma_glptrec->process(1);
		} break;
		case Rctables::enumTRKTRDSET:
		{
			QScopedPointer<TRKTRDSET> trktrdset(new TRKTRDSET(nullptr));
			trktrdset->open(sourceDSN, targetDSN);
			trktrdset->setRepositoryString(envyRepositoryString);
			trktrdset->setProfileName(profileName);
			trktrdset->setReplicationOption(eReplicationOption);
			trktrdset->setDropOption(edropOption);
			trktrdset->setOdbcAttributes(odbcAttributes);
			trktrdset->setUpdateInterval(updateInterval);
			trktrdset->setCommitInterval(commitInterval);
			trktrdset->process(1);
		} break;
		case Rctables::enumGL_ARPTHSHSET:
		{
			QScopedPointer<GL_ARPTHSHSET> gl_arpthshset(new GL_ARPTHSHSET(nullptr));
			gl_arpthshset->open(sourceDSN, targetDSN);
			gl_arpthshset->setRepositoryString(envyRepositoryString);
			gl_arpthshset->setProfileName(profileName);
			gl_arpthshset->setReplicationOption(eReplicationOption);
			gl_arpthshset->setDropOption(edropOption);
			gl_arpthshset->setOdbcAttributes(odbcAttributes);
			gl_arpthshset->setUpdateInterval(updateInterval);
			gl_arpthshset->setCommitInterval(commitInterval);
			gl_arpthshset->process(1);
		} break;
		case Rctables::enumMA_GLCTBILSET:
		{
			QScopedPointer<MA_GLCTBILSET> ma_glctbilset(new MA_GLCTBILSET(nullptr));
			ma_glctbilset->open(sourceDSN, targetDSN);
			ma_glctbilset->setRepositoryString(envyRepositoryString);
			ma_glctbilset->setProfileName(profileName);
			ma_glctbilset->setReplicationOption(eReplicationOption);
			ma_glctbilset->setDropOption(edropOption);
			ma_glctbilset->setOdbcAttributes(odbcAttributes);
			ma_glctbilset->setUpdateInterval(updateInterval);
			ma_glctbilset->setCommitInterval(commitInterval);
			ma_glctbilset->process(1);
		} break;
		case Rctables::enumPRTPFAMSET:
		{
			QScopedPointer<PRTPFAMSET> prtpfamset(new PRTPFAMSET(nullptr));
			prtpfamset->open(sourceDSN, targetDSN);
			prtpfamset->setRepositoryString(envyRepositoryString);
			prtpfamset->setProfileName(profileName);
			prtpfamset->setReplicationOption(eReplicationOption);
			prtpfamset->setDropOption(edropOption);
			prtpfamset->setOdbcAttributes(odbcAttributes);
			prtpfamset->setUpdateInterval(updateInterval);
			prtpfamset->setCommitInterval(commitInterval);
			prtpfamset->process(1);
		} break;
		case Rctables::enumAP_BOLHSHSET:
		{
			QScopedPointer<AP_BOLHSHSET> ap_bolhshset(new AP_BOLHSHSET(nullptr));
			ap_bolhshset->open(sourceDSN, targetDSN);
			ap_bolhshset->setRepositoryString(envyRepositoryString);
			ap_bolhshset->setProfileName(profileName);
			ap_bolhshset->setReplicationOption(eReplicationOption);
			ap_bolhshset->setDropOption(edropOption);
			ap_bolhshset->setOdbcAttributes(odbcAttributes);
			ap_bolhshset->setUpdateInterval(updateInterval);
			ap_bolhshset->setCommitInterval(commitInterval);
			ap_bolhshset->process(1);
		} break;
		case Rctables::enumCOPREC:
		{
			QScopedPointer<COPREC> coprec(new COPREC(nullptr));
			coprec->open(sourceDSN, targetDSN);
			coprec->setRepositoryString(envyRepositoryString);
			coprec->setProfileName(profileName);
			coprec->setReplicationOption(eReplicationOption);
			coprec->setDropOption(edropOption);
			coprec->setOdbcAttributes(odbcAttributes);
			coprec->setUpdateInterval(updateInterval);
			coprec->setCommitInterval(commitInterval);
			coprec->process(1);
		} break;
		case Rctables::enumVENRCTSET:
		{
			QScopedPointer<VENRCTSET> venrctset(new VENRCTSET(nullptr));
			venrctset->open(sourceDSN, targetDSN);
			venrctset->setRepositoryString(envyRepositoryString);
			venrctset->setProfileName(profileName);
			venrctset->setReplicationOption(eReplicationOption);
			venrctset->setDropOption(edropOption);
			venrctset->setOdbcAttributes(odbcAttributes);
			venrctset->setUpdateInterval(updateInterval);
			venrctset->setCommitInterval(commitInterval);
			venrctset->process(1);
		} break;
		case Rctables::enumMA_INHCMHSET:
		{
			QScopedPointer<MA_INHCMHSET> ma_inhcmhset(new MA_INHCMHSET(nullptr));
			ma_inhcmhset->open(sourceDSN, targetDSN);
			ma_inhcmhset->setRepositoryString(envyRepositoryString);
			ma_inhcmhset->setProfileName(profileName);
			ma_inhcmhset->setReplicationOption(eReplicationOption);
			ma_inhcmhset->setDropOption(edropOption);
			ma_inhcmhset->setOdbcAttributes(odbcAttributes);
			ma_inhcmhset->setUpdateInterval(updateInterval);
			ma_inhcmhset->setCommitInterval(commitInterval);
			ma_inhcmhset->process(1);
		} break;
		case Rctables::enumMA_BILCTREC:
		{
			QScopedPointer<MA_BILCTREC> ma_bilctrec(new MA_BILCTREC(nullptr));
			ma_bilctrec->open(sourceDSN, targetDSN);
			ma_bilctrec->setRepositoryString(envyRepositoryString);
			ma_bilctrec->setProfileName(profileName);
			ma_bilctrec->setReplicationOption(eReplicationOption);
			ma_bilctrec->setDropOption(edropOption);
			ma_bilctrec->setOdbcAttributes(odbcAttributes);
			ma_bilctrec->setUpdateInterval(updateInterval);
			ma_bilctrec->setCommitInterval(commitInterval);
			ma_bilctrec->process(1);
		} break;
		case Rctables::enumED_ENTMMHSHSET:
		{
			QScopedPointer<ED_ENTMMHSHSET> ed_entmmhshset(new ED_ENTMMHSHSET(nullptr));
			ed_entmmhshset->open(sourceDSN, targetDSN);
			ed_entmmhshset->setRepositoryString(envyRepositoryString);
			ed_entmmhshset->setProfileName(profileName);
			ed_entmmhshset->setReplicationOption(eReplicationOption);
			ed_entmmhshset->setDropOption(edropOption);
			ed_entmmhshset->setOdbcAttributes(odbcAttributes);
			ed_entmmhshset->setUpdateInterval(updateInterval);
			ed_entmmhshset->setCommitInterval(commitInterval);
			ed_entmmhshset->process(1);
		} break;
		case Rctables::enumMA_GLPTPRODSET:
		{
			QScopedPointer<MA_GLPTPRODSET> ma_glptprodset(new MA_GLPTPRODSET(nullptr));
			ma_glptprodset->open(sourceDSN, targetDSN);
			ma_glptprodset->setRepositoryString(envyRepositoryString);
			ma_glptprodset->setProfileName(profileName);
			ma_glptprodset->setReplicationOption(eReplicationOption);
			ma_glptprodset->setDropOption(edropOption);
			ma_glptprodset->setOdbcAttributes(odbcAttributes);
			ma_glptprodset->setUpdateInterval(updateInterval);
			ma_glptprodset->setCommitInterval(commitInterval);
			ma_glptprodset->process(1);
		} break;
		case Rctables::enumED_TPHSHSET:
		{
			QScopedPointer<ED_TPHSHSET> ed_tphshset(new ED_TPHSHSET(nullptr));
			ed_tphshset->open(sourceDSN, targetDSN);
			ed_tphshset->setRepositoryString(envyRepositoryString);
			ed_tphshset->setProfileName(profileName);
			ed_tphshset->setReplicationOption(eReplicationOption);
			ed_tphshset->setDropOption(edropOption);
			ed_tphshset->setOdbcAttributes(odbcAttributes);
			ed_tphshset->setUpdateInterval(updateInterval);
			ed_tphshset->setCommitInterval(commitInterval);
			ed_tphshset->process(1);
		} break;
		case Rctables::enumMA_INDCMDSET:
		{
			QScopedPointer<MA_INDCMDSET> ma_indcmdset(new MA_INDCMDSET(nullptr));
			ma_indcmdset->open(sourceDSN, targetDSN);
			ma_indcmdset->setRepositoryString(envyRepositoryString);
			ma_indcmdset->setProfileName(profileName);
			ma_indcmdset->setReplicationOption(eReplicationOption);
			ma_indcmdset->setDropOption(edropOption);
			ma_indcmdset->setOdbcAttributes(odbcAttributes);
			ma_indcmdset->setUpdateInterval(updateInterval);
			ma_indcmdset->setCommitInterval(commitInterval);
			ma_indcmdset->process(1);
		} break;
		case Rctables::enumMA_BILCIASET:
		{
			QScopedPointer<MA_BILCIASET> ma_bilciaset(new MA_BILCIASET(nullptr));
			ma_bilciaset->open(sourceDSN, targetDSN);
			ma_bilciaset->setRepositoryString(envyRepositoryString);
			ma_bilciaset->setProfileName(profileName);
			ma_bilciaset->setReplicationOption(eReplicationOption);
			ma_bilciaset->setDropOption(edropOption);
			ma_bilciaset->setOdbcAttributes(odbcAttributes);
			ma_bilciaset->setUpdateInterval(updateInterval);
			ma_bilciaset->setCommitInterval(commitInterval);
			ma_bilciaset->process(1);
		} break;
		case Rctables::enumMA_CMHVDPOSTSET:
		{
			QScopedPointer<MA_CMHVDPOSTSET> ma_cmhvdpostset(new MA_CMHVDPOSTSET(nullptr));
			ma_cmhvdpostset->open(sourceDSN, targetDSN);
			ma_cmhvdpostset->setRepositoryString(envyRepositoryString);
			ma_cmhvdpostset->setProfileName(profileName);
			ma_cmhvdpostset->setReplicationOption(eReplicationOption);
			ma_cmhvdpostset->setDropOption(edropOption);
			ma_cmhvdpostset->setOdbcAttributes(odbcAttributes);
			ma_cmhvdpostset->setUpdateInterval(updateInterval);
			ma_cmhvdpostset->setCommitInterval(commitInterval);
			ma_cmhvdpostset->process(1);
		} break;
		case Rctables::enumMA_PRODSREC:
		{
			QScopedPointer<MA_PRODSREC> ma_prodsrec(new MA_PRODSREC(nullptr));
			ma_prodsrec->open(sourceDSN, targetDSN);
			ma_prodsrec->setRepositoryString(envyRepositoryString);
			ma_prodsrec->setProfileName(profileName);
			ma_prodsrec->setReplicationOption(eReplicationOption);
			ma_prodsrec->setDropOption(edropOption);
			ma_prodsrec->setOdbcAttributes(odbcAttributes);
			ma_prodsrec->setUpdateInterval(updateInterval);
			ma_prodsrec->setCommitInterval(commitInterval);
			ma_prodsrec->process(1);
		} break;
		case Rctables::enumPRTPODSET:
		{
			QScopedPointer<PRTPODSET> prtpodset(new PRTPODSET(nullptr));
			prtpodset->open(sourceDSN, targetDSN);
			prtpodset->setRepositoryString(envyRepositoryString);
			prtpodset->setProfileName(profileName);
			prtpodset->setReplicationOption(eReplicationOption);
			prtpodset->setDropOption(edropOption);
			prtpodset->setOdbcAttributes(odbcAttributes);
			prtpodset->setUpdateInterval(updateInterval);
			prtpodset->setCommitInterval(commitInterval);
			prtpodset->process(1);
		} break;
		case Rctables::enumINVLOC2SET:
		{
			QScopedPointer<INVLOC2SET> invloc2set(new INVLOC2SET(nullptr));
			invloc2set->open(sourceDSN, targetDSN);
			invloc2set->setRepositoryString(envyRepositoryString);
			invloc2set->setProfileName(profileName);
			invloc2set->setReplicationOption(eReplicationOption);
			invloc2set->setDropOption(edropOption);
			invloc2set->setOdbcAttributes(odbcAttributes);
			invloc2set->setUpdateInterval(updateInterval);
			invloc2set->setCommitInterval(commitInterval);
			invloc2set->process(1);
		} break;
		case Rctables::enumWOHMOVSET:
		{
			QScopedPointer<WOHMOVSET> wohmovset(new WOHMOVSET(nullptr));
			wohmovset->open(sourceDSN, targetDSN);
			wohmovset->setRepositoryString(envyRepositoryString);
			wohmovset->setProfileName(profileName);
			wohmovset->setReplicationOption(eReplicationOption);
			wohmovset->setDropOption(edropOption);
			wohmovset->setOdbcAttributes(odbcAttributes);
			wohmovset->setUpdateInterval(updateInterval);
			wohmovset->setCommitInterval(commitInterval);
			wohmovset->process(1);
		} break;
		case Rctables::enumFSCREC:
		{
			QScopedPointer<FSCREC> fscrec(new FSCREC(nullptr));
			fscrec->open(sourceDSN, targetDSN);
			fscrec->setRepositoryString(envyRepositoryString);
			fscrec->setProfileName(profileName);
			fscrec->setReplicationOption(eReplicationOption);
			fscrec->setDropOption(edropOption);
			fscrec->setOdbcAttributes(odbcAttributes);
			fscrec->setUpdateInterval(updateInterval);
			fscrec->setCommitInterval(commitInterval);
			fscrec->process(1);
		} break;
		case Rctables::enumAP_INVRCTMREC:
		{
			QScopedPointer<AP_INVRCTMREC> ap_invrctmrec(new AP_INVRCTMREC(nullptr));
			ap_invrctmrec->open(sourceDSN, targetDSN);
			ap_invrctmrec->setRepositoryString(envyRepositoryString);
			ap_invrctmrec->setProfileName(profileName);
			ap_invrctmrec->setReplicationOption(eReplicationOption);
			ap_invrctmrec->setDropOption(edropOption);
			ap_invrctmrec->setOdbcAttributes(odbcAttributes);
			ap_invrctmrec->setUpdateInterval(updateInterval);
			ap_invrctmrec->setCommitInterval(commitInterval);
			ap_invrctmrec->process(1);
		} break;
		case Rctables::enumAP_DMVCHREC:
		{
			QScopedPointer<AP_DMVCHREC> ap_dmvchrec(new AP_DMVCHREC(nullptr));
			ap_dmvchrec->open(sourceDSN, targetDSN);
			ap_dmvchrec->setRepositoryString(envyRepositoryString);
			ap_dmvchrec->setProfileName(profileName);
			ap_dmvchrec->setReplicationOption(eReplicationOption);
			ap_dmvchrec->setDropOption(edropOption);
			ap_dmvchrec->setOdbcAttributes(odbcAttributes);
			ap_dmvchrec->setUpdateInterval(updateInterval);
			ap_dmvchrec->setCommitInterval(commitInterval);
			ap_dmvchrec->process(1);
		} break;
		case Rctables::enumGL_ACCTPOSTSET:
		{
			QScopedPointer<GL_ACCTPOSTSET> gl_acctpostset(new GL_ACCTPOSTSET(nullptr));
			gl_acctpostset->open(sourceDSN, targetDSN);
			gl_acctpostset->setRepositoryString(envyRepositoryString);
			gl_acctpostset->setProfileName(profileName);
			gl_acctpostset->setReplicationOption(eReplicationOption);
			gl_acctpostset->setDropOption(edropOption);
			gl_acctpostset->setOdbcAttributes(odbcAttributes);
			gl_acctpostset->setUpdateInterval(updateInterval);
			gl_acctpostset->setCommitInterval(commitInterval);
			gl_acctpostset->process(1);
		} break;
		case Rctables::enumCOMSET:
		{
			QScopedPointer<COMSET> comset(new COMSET(nullptr));
			comset->open(sourceDSN, targetDSN);
			comset->setRepositoryString(envyRepositoryString);
			comset->setProfileName(profileName);
			comset->setReplicationOption(eReplicationOption);
			comset->setDropOption(edropOption);
			comset->setOdbcAttributes(odbcAttributes);
			comset->setUpdateInterval(updateInterval);
			comset->setCommitInterval(commitInterval);
			comset->process(1);
		} break;
		case Rctables::enumAP_VATPOSTSET:
		{
			QScopedPointer<AP_VATPOSTSET> ap_vatpostset(new AP_VATPOSTSET(nullptr));
			ap_vatpostset->open(sourceDSN, targetDSN);
			ap_vatpostset->setRepositoryString(envyRepositoryString);
			ap_vatpostset->setProfileName(profileName);
			ap_vatpostset->setReplicationOption(eReplicationOption);
			ap_vatpostset->setDropOption(edropOption);
			ap_vatpostset->setOdbcAttributes(odbcAttributes);
			ap_vatpostset->setUpdateInterval(updateInterval);
			ap_vatpostset->setCommitInterval(commitInterval);
			ap_vatpostset->process(1);
		} break;
		case Rctables::enumRQHREC:
		{
			QScopedPointer<RQHREC> rqhrec(new RQHREC(nullptr));
			rqhrec->open(sourceDSN, targetDSN);
			rqhrec->setRepositoryString(envyRepositoryString);
			rqhrec->setProfileName(profileName);
			rqhrec->setReplicationOption(eReplicationOption);
			rqhrec->setDropOption(edropOption);
			rqhrec->setOdbcAttributes(odbcAttributes);
			rqhrec->setUpdateInterval(updateInterval);
			rqhrec->setCommitInterval(commitInterval);
			rqhrec->process(1);
		} break;
		case Rctables::enumMA_SAMHSHSET:
		{
			QScopedPointer<MA_SAMHSHSET> ma_samhshset(new MA_SAMHSHSET(nullptr));
			ma_samhshset->open(sourceDSN, targetDSN);
			ma_samhshset->setRepositoryString(envyRepositoryString);
			ma_samhshset->setProfileName(profileName);
			ma_samhshset->setReplicationOption(eReplicationOption);
			ma_samhshset->setDropOption(edropOption);
			ma_samhshset->setOdbcAttributes(odbcAttributes);
			ma_samhshset->setUpdateInterval(updateInterval);
			ma_samhshset->setCommitInterval(commitInterval);
			ma_samhshset->process(1);
		} break;
		case Rctables::enumMA_INHINDSET:
		{
			QScopedPointer<MA_INHINDSET> ma_inhindset(new MA_INHINDSET(nullptr));
			ma_inhindset->open(sourceDSN, targetDSN);
			ma_inhindset->setRepositoryString(envyRepositoryString);
			ma_inhindset->setProfileName(profileName);
			ma_inhindset->setReplicationOption(eReplicationOption);
			ma_inhindset->setDropOption(edropOption);
			ma_inhindset->setOdbcAttributes(odbcAttributes);
			ma_inhindset->setUpdateInterval(updateInterval);
			ma_inhindset->setCommitInterval(commitInterval);
			ma_inhindset->process(1);
		} break;
		case Rctables::enumCURCUREXSET:
		{
			QScopedPointer<CURCUREXSET> curcurexset(new CURCUREXSET(nullptr));
			curcurexset->open(sourceDSN, targetDSN);
			curcurexset->setRepositoryString(envyRepositoryString);
			curcurexset->setProfileName(profileName);
			curcurexset->setReplicationOption(eReplicationOption);
			curcurexset->setDropOption(edropOption);
			curcurexset->setOdbcAttributes(odbcAttributes);
			curcurexset->setUpdateInterval(updateInterval);
			curcurexset->setCommitInterval(commitInterval);
			curcurexset->process(1);
		} break;
		case Rctables::enumAP_BTCHEFTREC:
		{
			QScopedPointer<AP_BTCHEFTREC> ap_btcheftrec(new AP_BTCHEFTREC(nullptr));
			ap_btcheftrec->open(sourceDSN, targetDSN);
			ap_btcheftrec->setRepositoryString(envyRepositoryString);
			ap_btcheftrec->setProfileName(profileName);
			ap_btcheftrec->setReplicationOption(eReplicationOption);
			ap_btcheftrec->setDropOption(edropOption);
			ap_btcheftrec->setOdbcAttributes(odbcAttributes);
			ap_btcheftrec->setUpdateInterval(updateInterval);
			ap_btcheftrec->setCommitInterval(commitInterval);
			ap_btcheftrec->process(1);
		} break;
		case Rctables::enumPODPRDSET:
		{
			QScopedPointer<PODPRDSET> podprdset(new PODPRDSET(nullptr));
			podprdset->open(sourceDSN, targetDSN);
			podprdset->setRepositoryString(envyRepositoryString);
			podprdset->setProfileName(profileName);
			podprdset->setReplicationOption(eReplicationOption);
			podprdset->setDropOption(edropOption);
			podprdset->setOdbcAttributes(odbcAttributes);
			podprdset->setUpdateInterval(updateInterval);
			podprdset->setCommitInterval(commitInterval);
			podprdset->process(1);
		} break;
		case Rctables::enumGL_ISBSACCTSET:
		{
			QScopedPointer<GL_ISBSACCTSET> gl_isbsacctset(new GL_ISBSACCTSET(nullptr));
			gl_isbsacctset->open(sourceDSN, targetDSN);
			gl_isbsacctset->setRepositoryString(envyRepositoryString);
			gl_isbsacctset->setProfileName(profileName);
			gl_isbsacctset->setReplicationOption(eReplicationOption);
			gl_isbsacctset->setDropOption(edropOption);
			gl_isbsacctset->setOdbcAttributes(odbcAttributes);
			gl_isbsacctset->setUpdateInterval(updateInterval);
			gl_isbsacctset->setCommitInterval(commitInterval);
			gl_isbsacctset->process(1);
		} break;
		case Rctables::enumGL_VPFRLINKREC:
		{
			QScopedPointer<GL_VPFRLINKREC> gl_vpfrlinkrec(new GL_VPFRLINKREC(nullptr));
			gl_vpfrlinkrec->open(sourceDSN, targetDSN);
			gl_vpfrlinkrec->setRepositoryString(envyRepositoryString);
			gl_vpfrlinkrec->setProfileName(profileName);
			gl_vpfrlinkrec->setReplicationOption(eReplicationOption);
			gl_vpfrlinkrec->setDropOption(edropOption);
			gl_vpfrlinkrec->setOdbcAttributes(odbcAttributes);
			gl_vpfrlinkrec->setUpdateInterval(updateInterval);
			gl_vpfrlinkrec->setCommitInterval(commitInterval);
			gl_vpfrlinkrec->process(1);
		} break;
		case Rctables::enumMA_COMCCOMCLSET:
		{
			QScopedPointer<MA_COMCCOMCLSET> ma_comccomclset(new MA_COMCCOMCLSET(nullptr));
			ma_comccomclset->open(sourceDSN, targetDSN);
			ma_comccomclset->setRepositoryString(envyRepositoryString);
			ma_comccomclset->setProfileName(profileName);
			ma_comccomclset->setReplicationOption(eReplicationOption);
			ma_comccomclset->setDropOption(edropOption);
			ma_comccomclset->setOdbcAttributes(odbcAttributes);
			ma_comccomclset->setUpdateInterval(updateInterval);
			ma_comccomclset->setCommitInterval(commitInterval);
			ma_comccomclset->process(1);
		} break;
		case Rctables::enumPFAMHSHSET:
		{
			QScopedPointer<PFAMHSHSET> pfamhshset(new PFAMHSHSET(nullptr));
			pfamhshset->open(sourceDSN, targetDSN);
			pfamhshset->setRepositoryString(envyRepositoryString);
			pfamhshset->setProfileName(profileName);
			pfamhshset->setReplicationOption(eReplicationOption);
			pfamhshset->setDropOption(edropOption);
			pfamhshset->setOdbcAttributes(odbcAttributes);
			pfamhshset->setUpdateInterval(updateInterval);
			pfamhshset->setCommitInterval(commitInterval);
			pfamhshset->process(1);
		} break;
		case Rctables::enumAP_POSTREC:
		{
			QScopedPointer<AP_POSTREC> ap_postrec(new AP_POSTREC(nullptr));
			ap_postrec->open(sourceDSN, targetDSN);
			ap_postrec->setRepositoryString(envyRepositoryString);
			ap_postrec->setProfileName(profileName);
			ap_postrec->setReplicationOption(eReplicationOption);
			ap_postrec->setDropOption(edropOption);
			ap_postrec->setOdbcAttributes(odbcAttributes);
			ap_postrec->setUpdateInterval(updateInterval);
			ap_postrec->setCommitInterval(commitInterval);
			ap_postrec->process(1);
		} break;
		case Rctables::enumMRHMRQSET:
		{
			QScopedPointer<MRHMRQSET> mrhmrqset(new MRHMRQSET(nullptr));
			mrhmrqset->open(sourceDSN, targetDSN);
			mrhmrqset->setRepositoryString(envyRepositoryString);
			mrhmrqset->setProfileName(profileName);
			mrhmrqset->setReplicationOption(eReplicationOption);
			mrhmrqset->setDropOption(edropOption);
			mrhmrqset->setOdbcAttributes(odbcAttributes);
			mrhmrqset->setUpdateInterval(updateInterval);
			mrhmrqset->setCommitInterval(commitInterval);
			mrhmrqset->process(1);
		} break;
		case Rctables::enumMA_STGSTGPSET:
		{
			QScopedPointer<MA_STGSTGPSET> ma_stgstgpset(new MA_STGSTGPSET(nullptr));
			ma_stgstgpset->open(sourceDSN, targetDSN);
			ma_stgstgpset->setRepositoryString(envyRepositoryString);
			ma_stgstgpset->setProfileName(profileName);
			ma_stgstgpset->setReplicationOption(eReplicationOption);
			ma_stgstgpset->setDropOption(edropOption);
			ma_stgstgpset->setOdbcAttributes(odbcAttributes);
			ma_stgstgpset->setUpdateInterval(updateInterval);
			ma_stgstgpset->setCommitInterval(commitInterval);
			ma_stgstgpset->process(1);
		} break;
		case Rctables::enumGL_VPNUMACCTSET:
		{
			QScopedPointer<GL_VPNUMACCTSET> gl_vpnumacctset(new GL_VPNUMACCTSET(nullptr));
			gl_vpnumacctset->open(sourceDSN, targetDSN);
			gl_vpnumacctset->setRepositoryString(envyRepositoryString);
			gl_vpnumacctset->setProfileName(profileName);
			gl_vpnumacctset->setReplicationOption(eReplicationOption);
			gl_vpnumacctset->setDropOption(edropOption);
			gl_vpnumacctset->setOdbcAttributes(odbcAttributes);
			gl_vpnumacctset->setUpdateInterval(updateInterval);
			gl_vpnumacctset->setCommitInterval(commitInterval);
			gl_vpnumacctset->process(1);
		} break;
		case Rctables::enumAP_BNKCHKSET:
		{
			QScopedPointer<AP_BNKCHKSET> ap_bnkchkset(new AP_BNKCHKSET(nullptr));
			ap_bnkchkset->open(sourceDSN, targetDSN);
			ap_bnkchkset->setRepositoryString(envyRepositoryString);
			ap_bnkchkset->setProfileName(profileName);
			ap_bnkchkset->setReplicationOption(eReplicationOption);
			ap_bnkchkset->setDropOption(edropOption);
			ap_bnkchkset->setOdbcAttributes(odbcAttributes);
			ap_bnkchkset->setUpdateInterval(updateInterval);
			ap_bnkchkset->setCommitInterval(commitInterval);
			ap_bnkchkset->process(1);
		} break;
		case Rctables::enumGL_RE_NREC:
		{
			QScopedPointer<GL_RE_NREC> gl_re_nrec(new GL_RE_NREC(nullptr));
			gl_re_nrec->open(sourceDSN, targetDSN);
			gl_re_nrec->setRepositoryString(envyRepositoryString);
			gl_re_nrec->setProfileName(profileName);
			gl_re_nrec->setReplicationOption(eReplicationOption);
			gl_re_nrec->setDropOption(edropOption);
			gl_re_nrec->setOdbcAttributes(odbcAttributes);
			gl_re_nrec->setUpdateInterval(updateInterval);
			gl_re_nrec->setCommitInterval(commitInterval);
			gl_re_nrec->process(1);
		} break;
		case Rctables::enumMA_INHINHLSET:
		{
			QScopedPointer<MA_INHINHLSET> ma_inhinhlset(new MA_INHINHLSET(nullptr));
			ma_inhinhlset->open(sourceDSN, targetDSN);
			ma_inhinhlset->setRepositoryString(envyRepositoryString);
			ma_inhinhlset->setProfileName(profileName);
			ma_inhinhlset->setReplicationOption(eReplicationOption);
			ma_inhinhlset->setDropOption(edropOption);
			ma_inhinhlset->setOdbcAttributes(odbcAttributes);
			ma_inhinhlset->setUpdateInterval(updateInterval);
			ma_inhinhlset->setCommitInterval(commitInterval);
			ma_inhinhlset->process(1);
		} break;
		case Rctables::enumWKCHSHSET:
		{
			QScopedPointer<WKCHSHSET> wkchshset(new WKCHSHSET(nullptr));
			wkchshset->open(sourceDSN, targetDSN);
			wkchshset->setRepositoryString(envyRepositoryString);
			wkchshset->setProfileName(profileName);
			wkchshset->setReplicationOption(eReplicationOption);
			wkchshset->setDropOption(edropOption);
			wkchshset->setOdbcAttributes(odbcAttributes);
			wkchshset->setUpdateInterval(updateInterval);
			wkchshset->setCommitInterval(commitInterval);
			wkchshset->process(1);
		} break;
		case Rctables::enumMA_INHPNOTINVSET:
		{
			QScopedPointer<MA_INHPNOTINVSET> ma_inhpnotinvset(new MA_INHPNOTINVSET(nullptr));
			ma_inhpnotinvset->open(sourceDSN, targetDSN);
			ma_inhpnotinvset->setRepositoryString(envyRepositoryString);
			ma_inhpnotinvset->setProfileName(profileName);
			ma_inhpnotinvset->setReplicationOption(eReplicationOption);
			ma_inhpnotinvset->setDropOption(edropOption);
			ma_inhpnotinvset->setOdbcAttributes(odbcAttributes);
			ma_inhpnotinvset->setUpdateInterval(updateInterval);
			ma_inhpnotinvset->setCommitInterval(commitInterval);
			ma_inhpnotinvset->process(1);
		} break;
		case Rctables::enumPODPONSET:
		{
			QScopedPointer<PODPONSET> podponset(new PODPONSET(nullptr));
			podponset->open(sourceDSN, targetDSN);
			podponset->setRepositoryString(envyRepositoryString);
			podponset->setProfileName(profileName);
			podponset->setReplicationOption(eReplicationOption);
			podponset->setDropOption(edropOption);
			podponset->setOdbcAttributes(odbcAttributes);
			podponset->setUpdateInterval(updateInterval);
			podponset->setCommitInterval(commitInterval);
			podponset->process(1);
		} break;
		case Rctables::enumAP_CHKHSHSET:
		{
			QScopedPointer<AP_CHKHSHSET> ap_chkhshset(new AP_CHKHSHSET(nullptr));
			ap_chkhshset->open(sourceDSN, targetDSN);
			ap_chkhshset->setRepositoryString(envyRepositoryString);
			ap_chkhshset->setProfileName(profileName);
			ap_chkhshset->setReplicationOption(eReplicationOption);
			ap_chkhshset->setDropOption(edropOption);
			ap_chkhshset->setOdbcAttributes(odbcAttributes);
			ap_chkhshset->setUpdateInterval(updateInterval);
			ap_chkhshset->setCommitInterval(commitInterval);
			ap_chkhshset->process(1);
		} break;
		case Rctables::enumGL_PROJ_NREC:
		{
			QScopedPointer<GL_PROJ_NREC> gl_proj_nrec(new GL_PROJ_NREC(nullptr));
			gl_proj_nrec->open(sourceDSN, targetDSN);
			gl_proj_nrec->setRepositoryString(envyRepositoryString);
			gl_proj_nrec->setProfileName(profileName);
			gl_proj_nrec->setReplicationOption(eReplicationOption);
			gl_proj_nrec->setDropOption(edropOption);
			gl_proj_nrec->setOdbcAttributes(odbcAttributes);
			gl_proj_nrec->setUpdateInterval(updateInterval);
			gl_proj_nrec->setCommitInterval(commitInterval);
			gl_proj_nrec->process(1);
		} break;
		case Rctables::enumCLDPOHSET:
		{
			QScopedPointer<CLDPOHSET> cldpohset(new CLDPOHSET(nullptr));
			cldpohset->open(sourceDSN, targetDSN);
			cldpohset->setRepositoryString(envyRepositoryString);
			cldpohset->setProfileName(profileName);
			cldpohset->setReplicationOption(eReplicationOption);
			cldpohset->setDropOption(edropOption);
			cldpohset->setOdbcAttributes(odbcAttributes);
			cldpohset->setUpdateInterval(updateInterval);
			cldpohset->setCommitInterval(commitInterval);
			cldpohset->process(1);
		} break;
		case Rctables::enumAP_VNDHOLDSET:
		{
			QScopedPointer<AP_VNDHOLDSET> ap_vndholdset(new AP_VNDHOLDSET(nullptr));
			ap_vndholdset->open(sourceDSN, targetDSN);
			ap_vndholdset->setRepositoryString(envyRepositoryString);
			ap_vndholdset->setProfileName(profileName);
			ap_vndholdset->setReplicationOption(eReplicationOption);
			ap_vndholdset->setDropOption(edropOption);
			ap_vndholdset->setOdbcAttributes(odbcAttributes);
			ap_vndholdset->setUpdateInterval(updateInterval);
			ap_vndholdset->setCommitInterval(commitInterval);
			ap_vndholdset->process(1);
		} break;
		case Rctables::enumVENHSHSET:
		{
			QScopedPointer<VENHSHSET> venhshset(new VENHSHSET(nullptr));
			venhshset->open(sourceDSN, targetDSN);
			venhshset->setRepositoryString(envyRepositoryString);
			venhshset->setProfileName(profileName);
			venhshset->setReplicationOption(eReplicationOption);
			venhshset->setDropOption(edropOption);
			venhshset->setOdbcAttributes(odbcAttributes);
			venhshset->setUpdateInterval(updateInterval);
			venhshset->setCommitInterval(commitInterval);
			venhshset->process(1);
		} break;
		case Rctables::enumACTFOSET:
		{
			QScopedPointer<ACTFOSET> actfoset(new ACTFOSET(nullptr));
			actfoset->open(sourceDSN, targetDSN);
			actfoset->setRepositoryString(envyRepositoryString);
			actfoset->setProfileName(profileName);
			actfoset->setReplicationOption(eReplicationOption);
			actfoset->setDropOption(edropOption);
			actfoset->setOdbcAttributes(odbcAttributes);
			actfoset->setUpdateInterval(updateInterval);
			actfoset->setCommitInterval(commitInterval);
			actfoset->process(1);
		} break;
		case Rctables::enumPRTRCTSET:
		{
			QScopedPointer<PRTRCTSET> prtrctset(new PRTRCTSET(nullptr));
			prtrctset->open(sourceDSN, targetDSN);
			prtrctset->setRepositoryString(envyRepositoryString);
			prtrctset->setProfileName(profileName);
			prtrctset->setReplicationOption(eReplicationOption);
			prtrctset->setDropOption(edropOption);
			prtrctset->setOdbcAttributes(odbcAttributes);
			prtrctset->setUpdateInterval(updateInterval);
			prtrctset->setCommitInterval(commitInterval);
			prtrctset->process(1);
		} break;
		case Rctables::enumGL_VPTOPROJSET:
		{
			QScopedPointer<GL_VPTOPROJSET> gl_vptoprojset(new GL_VPTOPROJSET(nullptr));
			gl_vptoprojset->open(sourceDSN, targetDSN);
			gl_vptoprojset->setRepositoryString(envyRepositoryString);
			gl_vptoprojset->setProfileName(profileName);
			gl_vptoprojset->setReplicationOption(eReplicationOption);
			gl_vptoprojset->setDropOption(edropOption);
			gl_vptoprojset->setOdbcAttributes(odbcAttributes);
			gl_vptoprojset->setUpdateInterval(updateInterval);
			gl_vptoprojset->setCommitInterval(commitInterval);
			gl_vptoprojset->process(1);
		} break;
		case Rctables::enumMA_SVINDSPNLSET:
		{
			QScopedPointer<MA_SVINDSPNLSET> ma_svindspnlset(new MA_SVINDSPNLSET(nullptr));
			ma_svindspnlset->open(sourceDSN, targetDSN);
			ma_svindspnlset->setRepositoryString(envyRepositoryString);
			ma_svindspnlset->setProfileName(profileName);
			ma_svindspnlset->setReplicationOption(eReplicationOption);
			ma_svindspnlset->setDropOption(edropOption);
			ma_svindspnlset->setOdbcAttributes(odbcAttributes);
			ma_svindspnlset->setUpdateInterval(updateInterval);
			ma_svindspnlset->setCommitInterval(commitInterval);
			ma_svindspnlset->process(1);
		} break;
		case Rctables::enumMA_PRTABHSHSET:
		{
			QScopedPointer<MA_PRTABHSHSET> ma_prtabhshset(new MA_PRTABHSHSET(nullptr));
			ma_prtabhshset->open(sourceDSN, targetDSN);
			ma_prtabhshset->setRepositoryString(envyRepositoryString);
			ma_prtabhshset->setProfileName(profileName);
			ma_prtabhshset->setReplicationOption(eReplicationOption);
			ma_prtabhshset->setDropOption(edropOption);
			ma_prtabhshset->setOdbcAttributes(odbcAttributes);
			ma_prtabhshset->setUpdateInterval(updateInterval);
			ma_prtabhshset->setCommitInterval(commitInterval);
			ma_prtabhshset->process(1);
		} break;
		case Rctables::enumGL_VP_HREC:
		{
			QScopedPointer<GL_VP_HREC> gl_vp_hrec(new GL_VP_HREC(nullptr));
			gl_vp_hrec->open(sourceDSN, targetDSN);
			gl_vp_hrec->setRepositoryString(envyRepositoryString);
			gl_vp_hrec->setProfileName(profileName);
			gl_vp_hrec->setReplicationOption(eReplicationOption);
			gl_vp_hrec->setDropOption(edropOption);
			gl_vp_hrec->setOdbcAttributes(odbcAttributes);
			gl_vp_hrec->setUpdateInterval(updateInterval);
			gl_vp_hrec->setCommitInterval(commitInterval);
			gl_vp_hrec->process(1);
		} break;
		case Rctables::enumMA_SAMCOMCSET:
		{
			QScopedPointer<MA_SAMCOMCSET> ma_samcomcset(new MA_SAMCOMCSET(nullptr));
			ma_samcomcset->open(sourceDSN, targetDSN);
			ma_samcomcset->setRepositoryString(envyRepositoryString);
			ma_samcomcset->setProfileName(profileName);
			ma_samcomcset->setReplicationOption(eReplicationOption);
			ma_samcomcset->setDropOption(edropOption);
			ma_samcomcset->setOdbcAttributes(odbcAttributes);
			ma_samcomcset->setUpdateInterval(updateInterval);
			ma_samcomcset->setCommitInterval(commitInterval);
			ma_samcomcset->process(1);
		} break;
		case Rctables::enumMA_SOHSPISET:
		{
			QScopedPointer<MA_SOHSPISET> ma_sohspiset(new MA_SOHSPISET(nullptr));
			ma_sohspiset->open(sourceDSN, targetDSN);
			ma_sohspiset->setRepositoryString(envyRepositoryString);
			ma_sohspiset->setProfileName(profileName);
			ma_sohspiset->setReplicationOption(eReplicationOption);
			ma_sohspiset->setDropOption(edropOption);
			ma_sohspiset->setOdbcAttributes(odbcAttributes);
			ma_sohspiset->setUpdateInterval(updateInterval);
			ma_sohspiset->setCommitInterval(commitInterval);
			ma_sohspiset->process(1);
		} break;
		case Rctables::enumMA_SPNSPNDSET:
		{
			QScopedPointer<MA_SPNSPNDSET> ma_spnspndset(new MA_SPNSPNDSET(nullptr));
			ma_spnspndset->open(sourceDSN, targetDSN);
			ma_spnspndset->setRepositoryString(envyRepositoryString);
			ma_spnspndset->setProfileName(profileName);
			ma_spnspndset->setReplicationOption(eReplicationOption);
			ma_spnspndset->setDropOption(edropOption);
			ma_spnspndset->setOdbcAttributes(odbcAttributes);
			ma_spnspndset->setUpdateInterval(updateInterval);
			ma_spnspndset->setCommitInterval(commitInterval);
			ma_spnspndset->process(1);
		} break;
		case Rctables::enumGL_PBUDREC:
		{
			QScopedPointer<GL_PBUDREC> gl_pbudrec(new GL_PBUDREC(nullptr));
			gl_pbudrec->open(sourceDSN, targetDSN);
			gl_pbudrec->setRepositoryString(envyRepositoryString);
			gl_pbudrec->setProfileName(profileName);
			gl_pbudrec->setReplicationOption(eReplicationOption);
			gl_pbudrec->setDropOption(edropOption);
			gl_pbudrec->setOdbcAttributes(odbcAttributes);
			gl_pbudrec->setUpdateInterval(updateInterval);
			gl_pbudrec->setCommitInterval(commitInterval);
			gl_pbudrec->process(1);
		} break;
		case Rctables::enumMA_SOHPRTSET:
		{
			QScopedPointer<MA_SOHPRTSET> ma_sohprtset(new MA_SOHPRTSET(nullptr));
			ma_sohprtset->open(sourceDSN, targetDSN);
			ma_sohprtset->setRepositoryString(envyRepositoryString);
			ma_sohprtset->setProfileName(profileName);
			ma_sohprtset->setReplicationOption(eReplicationOption);
			ma_sohprtset->setDropOption(edropOption);
			ma_sohprtset->setOdbcAttributes(odbcAttributes);
			ma_sohprtset->setUpdateInterval(updateInterval);
			ma_sohprtset->setCommitInterval(commitInterval);
			ma_sohprtset->process(1);
		} break;
		case Rctables::enumEMPSET:
		{
			QScopedPointer<EMPSET> empset(new EMPSET(nullptr));
			empset->open(sourceDSN, targetDSN);
			empset->setRepositoryString(envyRepositoryString);
			empset->setProfileName(profileName);
			empset->setReplicationOption(eReplicationOption);
			empset->setDropOption(edropOption);
			empset->setOdbcAttributes(odbcAttributes);
			empset->setUpdateInterval(updateInterval);
			empset->setCommitInterval(commitInterval);
			empset->process(1);
		} break;
		case Rctables::enumMRLREC:
		{
			QScopedPointer<MRLREC> mrlrec(new MRLREC(nullptr));
			mrlrec->open(sourceDSN, targetDSN);
			mrlrec->setRepositoryString(envyRepositoryString);
			mrlrec->setProfileName(profileName);
			mrlrec->setReplicationOption(eReplicationOption);
			mrlrec->setDropOption(edropOption);
			mrlrec->setOdbcAttributes(odbcAttributes);
			mrlrec->setUpdateInterval(updateInterval);
			mrlrec->setCommitInterval(commitInterval);
			mrlrec->process(1);
		} break;
		case Rctables::enumAUTPRHSET:
		{
			QScopedPointer<AUTPRHSET> autprhset(new AUTPRHSET(nullptr));
			autprhset->open(sourceDSN, targetDSN);
			autprhset->setRepositoryString(envyRepositoryString);
			autprhset->setProfileName(profileName);
			autprhset->setReplicationOption(eReplicationOption);
			autprhset->setDropOption(edropOption);
			autprhset->setOdbcAttributes(odbcAttributes);
			autprhset->setUpdateInterval(updateInterval);
			autprhset->setCommitInterval(commitInterval);
			autprhset->process(1);
		} break;
		case Rctables::enumGL_VPFRACCTSET:
		{
			QScopedPointer<GL_VPFRACCTSET> gl_vpfracctset(new GL_VPFRACCTSET(nullptr));
			gl_vpfracctset->open(sourceDSN, targetDSN);
			gl_vpfracctset->setRepositoryString(envyRepositoryString);
			gl_vpfracctset->setProfileName(profileName);
			gl_vpfracctset->setReplicationOption(eReplicationOption);
			gl_vpfracctset->setDropOption(edropOption);
			gl_vpfracctset->setOdbcAttributes(odbcAttributes);
			gl_vpfracctset->setUpdateInterval(updateInterval);
			gl_vpfracctset->setCommitInterval(commitInterval);
			gl_vpfracctset->process(1);
		} break;
		case Rctables::enumMA_PRODCMDSET:
		{
			QScopedPointer<MA_PRODCMDSET> ma_prodcmdset(new MA_PRODCMDSET(nullptr));
			ma_prodcmdset->open(sourceDSN, targetDSN);
			ma_prodcmdset->setRepositoryString(envyRepositoryString);
			ma_prodcmdset->setProfileName(profileName);
			ma_prodcmdset->setReplicationOption(eReplicationOption);
			ma_prodcmdset->setDropOption(edropOption);
			ma_prodcmdset->setOdbcAttributes(odbcAttributes);
			ma_prodcmdset->setUpdateInterval(updateInterval);
			ma_prodcmdset->setCommitInterval(commitInterval);
			ma_prodcmdset->process(1);
		} break;
		case Rctables::enumMA_SAMSREC:
		{
			QScopedPointer<MA_SAMSREC> ma_samsrec(new MA_SAMSREC(nullptr));
			ma_samsrec->open(sourceDSN, targetDSN);
			ma_samsrec->setRepositoryString(envyRepositoryString);
			ma_samsrec->setProfileName(profileName);
			ma_samsrec->setReplicationOption(eReplicationOption);
			ma_samsrec->setDropOption(edropOption);
			ma_samsrec->setOdbcAttributes(odbcAttributes);
			ma_samsrec->setUpdateInterval(updateInterval);
			ma_samsrec->setCommitInterval(commitInterval);
			ma_samsrec->process(1);
		} break;
		case Rctables::enumMA_QUODSPNLSET:
		{
			QScopedPointer<MA_QUODSPNLSET> ma_quodspnlset(new MA_QUODSPNLSET(nullptr));
			ma_quodspnlset->open(sourceDSN, targetDSN);
			ma_quodspnlset->setRepositoryString(envyRepositoryString);
			ma_quodspnlset->setProfileName(profileName);
			ma_quodspnlset->setReplicationOption(eReplicationOption);
			ma_quodspnlset->setDropOption(edropOption);
			ma_quodspnlset->setOdbcAttributes(odbcAttributes);
			ma_quodspnlset->setUpdateInterval(updateInterval);
			ma_quodspnlset->setCommitInterval(commitInterval);
			ma_quodspnlset->process(1);
		} break;
		case Rctables::enumMATREC:
		{
			QScopedPointer<MATREC> matrec(new MATREC(nullptr));
			matrec->open(sourceDSN, targetDSN);
			matrec->setRepositoryString(envyRepositoryString);
			matrec->setProfileName(profileName);
			matrec->setReplicationOption(eReplicationOption);
			matrec->setDropOption(edropOption);
			matrec->setOdbcAttributes(odbcAttributes);
			matrec->setUpdateInterval(updateInterval);
			matrec->setCommitInterval(commitInterval);
			matrec->process(1);
		} break;
		case Rctables::enumMA_BILHSHSET:
		{
			QScopedPointer<MA_BILHSHSET> ma_bilhshset(new MA_BILHSHSET(nullptr));
			ma_bilhshset->open(sourceDSN, targetDSN);
			ma_bilhshset->setRepositoryString(envyRepositoryString);
			ma_bilhshset->setProfileName(profileName);
			ma_bilhshset->setReplicationOption(eReplicationOption);
			ma_bilhshset->setDropOption(edropOption);
			ma_bilhshset->setOdbcAttributes(odbcAttributes);
			ma_bilhshset->setUpdateInterval(updateInterval);
			ma_bilhshset->setCommitInterval(commitInterval);
			ma_bilhshset->process(1);
		} break;
		case Rctables::enumAP_BEFTHSHSET:
		{
			QScopedPointer<AP_BEFTHSHSET> ap_befthshset(new AP_BEFTHSHSET(nullptr));
			ap_befthshset->open(sourceDSN, targetDSN);
			ap_befthshset->setRepositoryString(envyRepositoryString);
			ap_befthshset->setProfileName(profileName);
			ap_befthshset->setReplicationOption(eReplicationOption);
			ap_befthshset->setDropOption(edropOption);
			ap_befthshset->setOdbcAttributes(odbcAttributes);
			ap_befthshset->setUpdateInterval(updateInterval);
			ap_befthshset->setCommitInterval(commitInterval);
			ap_befthshset->process(1);
		} break;
		case Rctables::enumAP_BOLLREC:
		{
			QScopedPointer<AP_BOLLREC> ap_bollrec(new AP_BOLLREC(nullptr));
			ap_bollrec->open(sourceDSN, targetDSN);
			ap_bollrec->setRepositoryString(envyRepositoryString);
			ap_bollrec->setProfileName(profileName);
			ap_bollrec->setReplicationOption(eReplicationOption);
			ap_bollrec->setDropOption(edropOption);
			ap_bollrec->setOdbcAttributes(odbcAttributes);
			ap_bollrec->setUpdateInterval(updateInterval);
			ap_bollrec->setCommitInterval(commitInterval);
			ap_bollrec->process(1);
		} break;
		case Rctables::enumMA_QUOHCOMOSET:
		{
			QScopedPointer<MA_QUOHCOMOSET> ma_quohcomoset(new MA_QUOHCOMOSET(nullptr));
			ma_quohcomoset->open(sourceDSN, targetDSN);
			ma_quohcomoset->setRepositoryString(envyRepositoryString);
			ma_quohcomoset->setProfileName(profileName);
			ma_quohcomoset->setReplicationOption(eReplicationOption);
			ma_quohcomoset->setDropOption(edropOption);
			ma_quohcomoset->setOdbcAttributes(odbcAttributes);
			ma_quohcomoset->setUpdateInterval(updateInterval);
			ma_quohcomoset->setCommitInterval(commitInterval);
			ma_quohcomoset->process(1);
		} break;
		case Rctables::enumPODREC:
		{
			QScopedPointer<PODREC> podrec(new PODREC(nullptr));
			podrec->open(sourceDSN, targetDSN);
			podrec->setRepositoryString(envyRepositoryString);
			podrec->setProfileName(profileName);
			podrec->setReplicationOption(eReplicationOption);
			podrec->setDropOption(edropOption);
			podrec->setOdbcAttributes(odbcAttributes);
			podrec->setUpdateInterval(updateInterval);
			podrec->setCommitInterval(commitInterval);
			podrec->process(1);
		} break;
		case Rctables::enumAP_PDCHKSET:
		{
			QScopedPointer<AP_PDCHKSET> ap_pdchkset(new AP_PDCHKSET(nullptr));
			ap_pdchkset->open(sourceDSN, targetDSN);
			ap_pdchkset->setRepositoryString(envyRepositoryString);
			ap_pdchkset->setProfileName(profileName);
			ap_pdchkset->setReplicationOption(eReplicationOption);
			ap_pdchkset->setDropOption(edropOption);
			ap_pdchkset->setOdbcAttributes(odbcAttributes);
			ap_pdchkset->setUpdateInterval(updateInterval);
			ap_pdchkset->setCommitInterval(commitInterval);
			ap_pdchkset->process(1);
		} break;
		case Rctables::enumCDPCDPLSET:
		{
			QScopedPointer<CDPCDPLSET> cdpcdplset(new CDPCDPLSET(nullptr));
			cdpcdplset->open(sourceDSN, targetDSN);
			cdpcdplset->setRepositoryString(envyRepositoryString);
			cdpcdplset->setProfileName(profileName);
			cdpcdplset->setReplicationOption(eReplicationOption);
			cdpcdplset->setDropOption(edropOption);
			cdpcdplset->setOdbcAttributes(odbcAttributes);
			cdpcdplset->setUpdateInterval(updateInterval);
			cdpcdplset->setCommitInterval(commitInterval);
			cdpcdplset->process(1);
		} break;
		case Rctables::enumPUNREC:
		{
			QScopedPointer<PUNREC> punrec(new PUNREC(nullptr));
			punrec->open(sourceDSN, targetDSN);
			punrec->setRepositoryString(envyRepositoryString);
			punrec->setProfileName(profileName);
			punrec->setReplicationOption(eReplicationOption);
			punrec->setDropOption(edropOption);
			punrec->setOdbcAttributes(odbcAttributes);
			punrec->setUpdateInterval(updateInterval);
			punrec->setCommitInterval(commitInterval);
			punrec->process(1);
		} break;
		case Rctables::enumAP_ACCTHSHSET:
		{
			QScopedPointer<AP_ACCTHSHSET> ap_accthshset(new AP_ACCTHSHSET(nullptr));
			ap_accthshset->open(sourceDSN, targetDSN);
			ap_accthshset->setRepositoryString(envyRepositoryString);
			ap_accthshset->setProfileName(profileName);
			ap_accthshset->setReplicationOption(eReplicationOption);
			ap_accthshset->setDropOption(edropOption);
			ap_accthshset->setOdbcAttributes(odbcAttributes);
			ap_accthshset->setUpdateInterval(updateInterval);
			ap_accthshset->setCommitInterval(commitInterval);
			ap_accthshset->process(1);
		} break;
		case Rctables::enumFSCHSHSET:
		{
			QScopedPointer<FSCHSHSET> fschshset(new FSCHSHSET(nullptr));
			fschshset->open(sourceDSN, targetDSN);
			fschshset->setRepositoryString(envyRepositoryString);
			fschshset->setProfileName(profileName);
			fschshset->setReplicationOption(eReplicationOption);
			fschshset->setDropOption(edropOption);
			fschshset->setOdbcAttributes(odbcAttributes);
			fschshset->setUpdateInterval(updateInterval);
			fschshset->setCommitInterval(commitInterval);
			fschshset->process(1);
		} break;
		case Rctables::enumMA_CIAPOSTSET:
		{
			QScopedPointer<MA_CIAPOSTSET> ma_ciapostset(new MA_CIAPOSTSET(nullptr));
			ma_ciapostset->open(sourceDSN, targetDSN);
			ma_ciapostset->setRepositoryString(envyRepositoryString);
			ma_ciapostset->setProfileName(profileName);
			ma_ciapostset->setReplicationOption(eReplicationOption);
			ma_ciapostset->setDropOption(edropOption);
			ma_ciapostset->setOdbcAttributes(odbcAttributes);
			ma_ciapostset->setUpdateInterval(updateInterval);
			ma_ciapostset->setCommitInterval(commitInterval);
			ma_ciapostset->process(1);
		} break;
		case Rctables::enumAP_VCHREC:
		{
			QScopedPointer<AP_VCHREC> ap_vchrec(new AP_VCHREC(nullptr));
			ap_vchrec->open(sourceDSN, targetDSN);
			ap_vchrec->setRepositoryString(envyRepositoryString);
			ap_vchrec->setProfileName(profileName);
			ap_vchrec->setReplicationOption(eReplicationOption);
			ap_vchrec->setDropOption(edropOption);
			ap_vchrec->setOdbcAttributes(odbcAttributes);
			ap_vchrec->setUpdateInterval(updateInterval);
			ap_vchrec->setCommitInterval(commitInterval);
			ap_vchrec->process(1);
		} break;
		case Rctables::enumMA_QUODSPISET:
		{
			QScopedPointer<MA_QUODSPISET> ma_quodspiset(new MA_QUODSPISET(nullptr));
			ma_quodspiset->open(sourceDSN, targetDSN);
			ma_quodspiset->setRepositoryString(envyRepositoryString);
			ma_quodspiset->setProfileName(profileName);
			ma_quodspiset->setReplicationOption(eReplicationOption);
			ma_quodspiset->setDropOption(edropOption);
			ma_quodspiset->setOdbcAttributes(odbcAttributes);
			ma_quodspiset->setUpdateInterval(updateInterval);
			ma_quodspiset->setCommitInterval(commitInterval);
			ma_quodspiset->process(1);
		} break;
		case Rctables::enumMA_CMDREC:
		{
			QScopedPointer<MA_CMDREC> ma_cmdrec(new MA_CMDREC(nullptr));
			ma_cmdrec->open(sourceDSN, targetDSN);
			ma_cmdrec->setRepositoryString(envyRepositoryString);
			ma_cmdrec->setProfileName(profileName);
			ma_cmdrec->setReplicationOption(eReplicationOption);
			ma_cmdrec->setDropOption(edropOption);
			ma_cmdrec->setOdbcAttributes(odbcAttributes);
			ma_cmdrec->setUpdateInterval(updateInterval);
			ma_cmdrec->setCommitInterval(commitInterval);
			ma_cmdrec->process(1);
		} break;
		case Rctables::enumCDPREC:
		{
			QScopedPointer<CDPREC> cdprec(new CDPREC(nullptr));
			cdprec->open(sourceDSN, targetDSN);
			cdprec->setRepositoryString(envyRepositoryString);
			cdprec->setProfileName(profileName);
			cdprec->setReplicationOption(eReplicationOption);
			cdprec->setDropOption(edropOption);
			cdprec->setOdbcAttributes(odbcAttributes);
			cdprec->setUpdateInterval(updateInterval);
			cdprec->setCommitInterval(commitInterval);
			cdprec->process(1);
		} break;
		case Rctables::enumMA_ACCTUPPDSET:
		{
			QScopedPointer<MA_ACCTUPPDSET> ma_acctuppdset(new MA_ACCTUPPDSET(nullptr));
			ma_acctuppdset->open(sourceDSN, targetDSN);
			ma_acctuppdset->setRepositoryString(envyRepositoryString);
			ma_acctuppdset->setProfileName(profileName);
			ma_acctuppdset->setReplicationOption(eReplicationOption);
			ma_acctuppdset->setDropOption(edropOption);
			ma_acctuppdset->setOdbcAttributes(odbcAttributes);
			ma_acctuppdset->setUpdateInterval(updateInterval);
			ma_acctuppdset->setCommitInterval(commitInterval);
			ma_acctuppdset->process(1);
		} break;
		case Rctables::enumED_ENTHSHSET:
		{
			QScopedPointer<ED_ENTHSHSET> ed_enthshset(new ED_ENTHSHSET(nullptr));
			ed_enthshset->open(sourceDSN, targetDSN);
			ed_enthshset->setRepositoryString(envyRepositoryString);
			ed_enthshset->setProfileName(profileName);
			ed_enthshset->setReplicationOption(eReplicationOption);
			ed_enthshset->setDropOption(edropOption);
			ed_enthshset->setOdbcAttributes(odbcAttributes);
			ed_enthshset->setUpdateInterval(updateInterval);
			ed_enthshset->setCommitInterval(commitInterval);
			ed_enthshset->process(1);
		} break;
		case Rctables::enumMA_INDMSPISET:
		{
			QScopedPointer<MA_INDMSPISET> ma_indmspiset(new MA_INDMSPISET(nullptr));
			ma_indmspiset->open(sourceDSN, targetDSN);
			ma_indmspiset->setRepositoryString(envyRepositoryString);
			ma_indmspiset->setProfileName(profileName);
			ma_indmspiset->setReplicationOption(eReplicationOption);
			ma_indmspiset->setDropOption(edropOption);
			ma_indmspiset->setOdbcAttributes(odbcAttributes);
			ma_indmspiset->setUpdateInterval(updateInterval);
			ma_indmspiset->setCommitInterval(commitInterval);
			ma_indmspiset->process(1);
		} break;
		case Rctables::enumGL_JVTRSET:
		{
			QScopedPointer<GL_JVTRSET> gl_jvtrset(new GL_JVTRSET(nullptr));
			gl_jvtrset->open(sourceDSN, targetDSN);
			gl_jvtrset->setRepositoryString(envyRepositoryString);
			gl_jvtrset->setProfileName(profileName);
			gl_jvtrset->setReplicationOption(eReplicationOption);
			gl_jvtrset->setDropOption(edropOption);
			gl_jvtrset->setOdbcAttributes(odbcAttributes);
			gl_jvtrset->setUpdateInterval(updateInterval);
			gl_jvtrset->setCommitInterval(commitInterval);
			gl_jvtrset->process(1);
		} break;
		case Rctables::enumMA_PRODTOPSET:
		{
			QScopedPointer<MA_PRODTOPSET> ma_prodtopset(new MA_PRODTOPSET(nullptr));
			ma_prodtopset->open(sourceDSN, targetDSN);
			ma_prodtopset->setRepositoryString(envyRepositoryString);
			ma_prodtopset->setProfileName(profileName);
			ma_prodtopset->setReplicationOption(eReplicationOption);
			ma_prodtopset->setDropOption(edropOption);
			ma_prodtopset->setOdbcAttributes(odbcAttributes);
			ma_prodtopset->setUpdateInterval(updateInterval);
			ma_prodtopset->setCommitInterval(commitInterval);
			ma_prodtopset->process(1);
		} break;
		case Rctables::enumAP_PMTHSHSET:
		{
			QScopedPointer<AP_PMTHSHSET> ap_pmthshset(new AP_PMTHSHSET(nullptr));
			ap_pmthshset->open(sourceDSN, targetDSN);
			ap_pmthshset->setRepositoryString(envyRepositoryString);
			ap_pmthshset->setProfileName(profileName);
			ap_pmthshset->setReplicationOption(eReplicationOption);
			ap_pmthshset->setDropOption(edropOption);
			ap_pmthshset->setOdbcAttributes(odbcAttributes);
			ap_pmthshset->setUpdateInterval(updateInterval);
			ap_pmthshset->setCommitInterval(commitInterval);
			ap_pmthshset->process(1);
		} break;
		case Rctables::enumAP_PROJREC:
		{
			QScopedPointer<AP_PROJREC> ap_projrec(new AP_PROJREC(nullptr));
			ap_projrec->open(sourceDSN, targetDSN);
			ap_projrec->setRepositoryString(envyRepositoryString);
			ap_projrec->setProfileName(profileName);
			ap_projrec->setReplicationOption(eReplicationOption);
			ap_projrec->setDropOption(edropOption);
			ap_projrec->setOdbcAttributes(odbcAttributes);
			ap_projrec->setUpdateInterval(updateInterval);
			ap_projrec->setCommitInterval(commitInterval);
			ap_projrec->process(1);
		} break;
		case Rctables::enumMA_USRFLDSET:
		{
			QScopedPointer<MA_USRFLDSET> ma_usrfldset(new MA_USRFLDSET(nullptr));
			ma_usrfldset->open(sourceDSN, targetDSN);
			ma_usrfldset->setRepositoryString(envyRepositoryString);
			ma_usrfldset->setProfileName(profileName);
			ma_usrfldset->setReplicationOption(eReplicationOption);
			ma_usrfldset->setDropOption(edropOption);
			ma_usrfldset->setOdbcAttributes(odbcAttributes);
			ma_usrfldset->setUpdateInterval(updateInterval);
			ma_usrfldset->setCommitInterval(commitInterval);
			ma_usrfldset->process(1);
		} break;
		case Rctables::enumPRDPONSET:
		{
			QScopedPointer<PRDPONSET> prdponset(new PRDPONSET(nullptr));
			prdponset->open(sourceDSN, targetDSN);
			prdponset->setRepositoryString(envyRepositoryString);
			prdponset->setProfileName(profileName);
			prdponset->setReplicationOption(eReplicationOption);
			prdponset->setDropOption(edropOption);
			prdponset->setOdbcAttributes(odbcAttributes);
			prdponset->setUpdateInterval(updateInterval);
			prdponset->setCommitInterval(commitInterval);
			prdponset->process(1);
		} break;
		case Rctables::enumMA_PRODPRTABSET:
		{
			QScopedPointer<MA_PRODPRTABSET> ma_prodprtabset(new MA_PRODPRTABSET(nullptr));
			ma_prodprtabset->open(sourceDSN, targetDSN);
			ma_prodprtabset->setRepositoryString(envyRepositoryString);
			ma_prodprtabset->setProfileName(profileName);
			ma_prodprtabset->setReplicationOption(eReplicationOption);
			ma_prodprtabset->setDropOption(edropOption);
			ma_prodprtabset->setOdbcAttributes(odbcAttributes);
			ma_prodprtabset->setUpdateInterval(updateInterval);
			ma_prodprtabset->setCommitInterval(commitInterval);
			ma_prodprtabset->process(1);
		} break;
		case Rctables::enumMA_PRPTREC:
		{
			QScopedPointer<MA_PRPTREC> ma_prptrec(new MA_PRPTREC(nullptr));
			ma_prptrec->open(sourceDSN, targetDSN);
			ma_prptrec->setRepositoryString(envyRepositoryString);
			ma_prptrec->setProfileName(profileName);
			ma_prptrec->setReplicationOption(eReplicationOption);
			ma_prptrec->setDropOption(edropOption);
			ma_prptrec->setOdbcAttributes(odbcAttributes);
			ma_prptrec->setUpdateInterval(updateInterval);
			ma_prptrec->setCommitInterval(commitInterval);
			ma_prptrec->process(1);
		} break;
		case Rctables::enumGL_ACCTAPSET:
		{
			QScopedPointer<GL_ACCTAPSET> gl_acctapset(new GL_ACCTAPSET(nullptr));
			gl_acctapset->open(sourceDSN, targetDSN);
			gl_acctapset->setRepositoryString(envyRepositoryString);
			gl_acctapset->setProfileName(profileName);
			gl_acctapset->setReplicationOption(eReplicationOption);
			gl_acctapset->setDropOption(edropOption);
			gl_acctapset->setOdbcAttributes(odbcAttributes);
			gl_acctapset->setUpdateInterval(updateInterval);
			gl_acctapset->setCommitInterval(commitInterval);
			gl_acctapset->process(1);
		} break;
		case Rctables::enumAP_VNDINVSET:
		{
			QScopedPointer<AP_VNDINVSET> ap_vndinvset(new AP_VNDINVSET(nullptr));
			ap_vndinvset->open(sourceDSN, targetDSN);
			ap_vndinvset->setRepositoryString(envyRepositoryString);
			ap_vndinvset->setProfileName(profileName);
			ap_vndinvset->setReplicationOption(eReplicationOption);
			ap_vndinvset->setDropOption(edropOption);
			ap_vndinvset->setOdbcAttributes(odbcAttributes);
			ap_vndinvset->setUpdateInterval(updateInterval);
			ap_vndinvset->setCommitInterval(commitInterval);
			ap_vndinvset->process(1);
		} break;
		case Rctables::enumGL_AAMTREC:
		{
			QScopedPointer<GL_AAMTREC> gl_aamtrec(new GL_AAMTREC(nullptr));
			gl_aamtrec->open(sourceDSN, targetDSN);
			gl_aamtrec->setRepositoryString(envyRepositoryString);
			gl_aamtrec->setProfileName(profileName);
			gl_aamtrec->setReplicationOption(eReplicationOption);
			gl_aamtrec->setDropOption(edropOption);
			gl_aamtrec->setOdbcAttributes(odbcAttributes);
			gl_aamtrec->setUpdateInterval(updateInterval);
			gl_aamtrec->setCommitInterval(commitInterval);
			gl_aamtrec->process(1);
		} break;
		case Rctables::enumRESREC:
		{
			QScopedPointer<RESREC> resrec(new RESREC(nullptr));
			resrec->open(sourceDSN, targetDSN);
			resrec->setRepositoryString(envyRepositoryString);
			resrec->setProfileName(profileName);
			resrec->setReplicationOption(eReplicationOption);
			resrec->setDropOption(edropOption);
			resrec->setOdbcAttributes(odbcAttributes);
			resrec->setUpdateInterval(updateInterval);
			resrec->setCommitInterval(commitInterval);
			resrec->process(1);
		} break;
		case Rctables::enumBOMREC:
		{
			QScopedPointer<BOMREC> bomrec(new BOMREC(nullptr));
			bomrec->open(sourceDSN, targetDSN);
			bomrec->setRepositoryString(envyRepositoryString);
			bomrec->setProfileName(profileName);
			bomrec->setReplicationOption(eReplicationOption);
			bomrec->setDropOption(edropOption);
			bomrec->setOdbcAttributes(odbcAttributes);
			bomrec->setUpdateInterval(updateInterval);
			bomrec->setCommitInterval(commitInterval);
			bomrec->process(1);
		} break;
		case Rctables::enumPOHREC:
		{
			QScopedPointer<POHREC> pohrec(new POHREC(nullptr));
			pohrec->open(sourceDSN, targetDSN);
			pohrec->setRepositoryString(envyRepositoryString);
			pohrec->setProfileName(profileName);
			pohrec->setReplicationOption(eReplicationOption);
			pohrec->setDropOption(edropOption);
			pohrec->setOdbcAttributes(odbcAttributes);
			pohrec->setUpdateInterval(updateInterval);
			pohrec->setCommitInterval(commitInterval);
			pohrec->process(1);
		} break;
		case Rctables::enumMA_TXHSHSET:
		{
			QScopedPointer<MA_TXHSHSET> ma_txhshset(new MA_TXHSHSET(nullptr));
			ma_txhshset->open(sourceDSN, targetDSN);
			ma_txhshset->setRepositoryString(envyRepositoryString);
			ma_txhshset->setProfileName(profileName);
			ma_txhshset->setReplicationOption(eReplicationOption);
			ma_txhshset->setDropOption(edropOption);
			ma_txhshset->setOdbcAttributes(odbcAttributes);
			ma_txhshset->setUpdateInterval(updateInterval);
			ma_txhshset->setCommitInterval(commitInterval);
			ma_txhshset->process(1);
		} break;
		case Rctables::enumACTPODSET:
		{
			QScopedPointer<ACTPODSET> actpodset(new ACTPODSET(nullptr));
			actpodset->open(sourceDSN, targetDSN);
			actpodset->setRepositoryString(envyRepositoryString);
			actpodset->setProfileName(profileName);
			actpodset->setReplicationOption(eReplicationOption);
			actpodset->setDropOption(edropOption);
			actpodset->setOdbcAttributes(odbcAttributes);
			actpodset->setUpdateInterval(updateInterval);
			actpodset->setCommitInterval(commitInterval);
			actpodset->process(1);
		} break;
		case Rctables::enumMA_INTINHSET:
		{
			QScopedPointer<MA_INTINHSET> ma_intinhset(new MA_INTINHSET(nullptr));
			ma_intinhset->open(sourceDSN, targetDSN);
			ma_intinhset->setRepositoryString(envyRepositoryString);
			ma_intinhset->setProfileName(profileName);
			ma_intinhset->setReplicationOption(eReplicationOption);
			ma_intinhset->setDropOption(edropOption);
			ma_intinhset->setOdbcAttributes(odbcAttributes);
			ma_intinhset->setUpdateInterval(updateInterval);
			ma_intinhset->setCommitInterval(commitInterval);
			ma_intinhset->process(1);
		} break;
		case Rctables::enumPOPREC:
		{
			QScopedPointer<POPREC> poprec(new POPREC(nullptr));
			poprec->open(sourceDSN, targetDSN);
			poprec->setRepositoryString(envyRepositoryString);
			poprec->setProfileName(profileName);
			poprec->setReplicationOption(eReplicationOption);
			poprec->setDropOption(edropOption);
			poprec->setOdbcAttributes(odbcAttributes);
			poprec->setUpdateInterval(updateInterval);
			poprec->setCommitInterval(commitInterval);
			poprec->process(1);
		} break;
		case Rctables::enumGL_VPDENSET:
		{
			QScopedPointer<GL_VPDENSET> gl_vpdenset(new GL_VPDENSET(nullptr));
			gl_vpdenset->open(sourceDSN, targetDSN);
			gl_vpdenset->setRepositoryString(envyRepositoryString);
			gl_vpdenset->setProfileName(profileName);
			gl_vpdenset->setReplicationOption(eReplicationOption);
			gl_vpdenset->setDropOption(edropOption);
			gl_vpdenset->setOdbcAttributes(odbcAttributes);
			gl_vpdenset->setUpdateInterval(updateInterval);
			gl_vpdenset->setCommitInterval(commitInterval);
			gl_vpdenset->process(1);
		} break;
		case Rctables::enumMA_CMDMSPNLSET:
		{
			QScopedPointer<MA_CMDMSPNLSET> ma_cmdmspnlset(new MA_CMDMSPNLSET(nullptr));
			ma_cmdmspnlset->open(sourceDSN, targetDSN);
			ma_cmdmspnlset->setRepositoryString(envyRepositoryString);
			ma_cmdmspnlset->setProfileName(profileName);
			ma_cmdmspnlset->setReplicationOption(eReplicationOption);
			ma_cmdmspnlset->setDropOption(edropOption);
			ma_cmdmspnlset->setOdbcAttributes(odbcAttributes);
			ma_cmdmspnlset->setUpdateInterval(updateInterval);
			ma_cmdmspnlset->setCommitInterval(commitInterval);
			ma_cmdmspnlset->process(1);
		} break;
		case Rctables::enumPOCOHSRTSET:
		{
			QScopedPointer<POCOHSRTSET> pocohsrtset(new POCOHSRTSET(nullptr));
			pocohsrtset->open(sourceDSN, targetDSN);
			pocohsrtset->setRepositoryString(envyRepositoryString);
			pocohsrtset->setProfileName(profileName);
			pocohsrtset->setReplicationOption(eReplicationOption);
			pocohsrtset->setDropOption(edropOption);
			pocohsrtset->setOdbcAttributes(odbcAttributes);
			pocohsrtset->setUpdateInterval(updateInterval);
			pocohsrtset->setCommitInterval(commitInterval);
			pocohsrtset->process(1);
		} break;
		case Rctables::enumMA_ACCTPRTDSET:
		{
			QScopedPointer<MA_ACCTPRTDSET> ma_acctprtdset(new MA_ACCTPRTDSET(nullptr));
			ma_acctprtdset->open(sourceDSN, targetDSN);
			ma_acctprtdset->setRepositoryString(envyRepositoryString);
			ma_acctprtdset->setProfileName(profileName);
			ma_acctprtdset->setReplicationOption(eReplicationOption);
			ma_acctprtdset->setDropOption(edropOption);
			ma_acctprtdset->setOdbcAttributes(odbcAttributes);
			ma_acctprtdset->setUpdateInterval(updateInterval);
			ma_acctprtdset->setCommitInterval(commitInterval);
			ma_acctprtdset->process(1);
		} break;
		case Rctables::enumGL_TR_NREC:
		{
			QScopedPointer<GL_TR_NREC> gl_tr_nrec(new GL_TR_NREC(nullptr));
			gl_tr_nrec->open(sourceDSN, targetDSN);
			gl_tr_nrec->setRepositoryString(envyRepositoryString);
			gl_tr_nrec->setProfileName(profileName);
			gl_tr_nrec->setReplicationOption(eReplicationOption);
			gl_tr_nrec->setDropOption(edropOption);
			gl_tr_nrec->setOdbcAttributes(odbcAttributes);
			gl_tr_nrec->setUpdateInterval(updateInterval);
			gl_tr_nrec->setCommitInterval(commitInterval);
			gl_tr_nrec->process(1);
		} break;
		case Rctables::enumAP_VATVTPSTSET:
		{
			QScopedPointer<AP_VATVTPSTSET> ap_vatvtpstset(new AP_VATVTPSTSET(nullptr));
			ap_vatvtpstset->open(sourceDSN, targetDSN);
			ap_vatvtpstset->setRepositoryString(envyRepositoryString);
			ap_vatvtpstset->setProfileName(profileName);
			ap_vatvtpstset->setReplicationOption(eReplicationOption);
			ap_vatvtpstset->setDropOption(edropOption);
			ap_vatvtpstset->setOdbcAttributes(odbcAttributes);
			ap_vatvtpstset->setUpdateInterval(updateInterval);
			ap_vatvtpstset->setCommitInterval(commitInterval);
			ap_vatvtpstset->process(1);
		} break;
		case Rctables::enumRCTRCTMSET:
		{
			QScopedPointer<RCTRCTMSET> rctrctmset(new RCTRCTMSET(nullptr));
			rctrctmset->open(sourceDSN, targetDSN);
			rctrctmset->setRepositoryString(envyRepositoryString);
			rctrctmset->setProfileName(profileName);
			rctrctmset->setReplicationOption(eReplicationOption);
			rctrctmset->setDropOption(edropOption);
			rctrctmset->setOdbcAttributes(odbcAttributes);
			rctrctmset->setUpdateInterval(updateInterval);
			rctrctmset->setCommitInterval(commitInterval);
			rctrctmset->process(1);
		} break;
		case Rctables::enumAP_PMTREC:
		{
			QScopedPointer<AP_PMTREC> ap_pmtrec(new AP_PMTREC(nullptr));
			ap_pmtrec->open(sourceDSN, targetDSN);
			ap_pmtrec->setRepositoryString(envyRepositoryString);
			ap_pmtrec->setProfileName(profileName);
			ap_pmtrec->setReplicationOption(eReplicationOption);
			ap_pmtrec->setDropOption(edropOption);
			ap_pmtrec->setOdbcAttributes(odbcAttributes);
			ap_pmtrec->setUpdateInterval(updateInterval);
			ap_pmtrec->setCommitInterval(commitInterval);
			ap_pmtrec->process(1);
		} break;
		case Rctables::enumMA_SVINHSVINDSET:
		{
			QScopedPointer<MA_SVINHSVINDSET> ma_svinhsvindset(new MA_SVINHSVINDSET(nullptr));
			ma_svinhsvindset->open(sourceDSN, targetDSN);
			ma_svinhsvindset->setRepositoryString(envyRepositoryString);
			ma_svinhsvindset->setProfileName(profileName);
			ma_svinhsvindset->setReplicationOption(eReplicationOption);
			ma_svinhsvindset->setDropOption(edropOption);
			ma_svinhsvindset->setOdbcAttributes(odbcAttributes);
			ma_svinhsvindset->setUpdateInterval(updateInterval);
			ma_svinhsvindset->setCommitInterval(commitInterval);
			ma_svinhsvindset->process(1);
		} break;
		case Rctables::enumED_TPPRDXRFSET:
		{
			QScopedPointer<ED_TPPRDXRFSET> ed_tpprdxrfset(new ED_TPPRDXRFSET(nullptr));
			ed_tpprdxrfset->open(sourceDSN, targetDSN);
			ed_tpprdxrfset->setRepositoryString(envyRepositoryString);
			ed_tpprdxrfset->setProfileName(profileName);
			ed_tpprdxrfset->setReplicationOption(eReplicationOption);
			ed_tpprdxrfset->setDropOption(edropOption);
			ed_tpprdxrfset->setOdbcAttributes(odbcAttributes);
			ed_tpprdxrfset->setUpdateInterval(updateInterval);
			ed_tpprdxrfset->setCommitInterval(commitInterval);
			ed_tpprdxrfset->process(1);
		} break;
		case Rctables::enumECOREC:
		{
			QScopedPointer<ECOREC> ecorec(new ECOREC(nullptr));
			ecorec->open(sourceDSN, targetDSN);
			ecorec->setRepositoryString(envyRepositoryString);
			ecorec->setProfileName(profileName);
			ecorec->setReplicationOption(eReplicationOption);
			ecorec->setDropOption(edropOption);
			ecorec->setOdbcAttributes(odbcAttributes);
			ecorec->setUpdateInterval(updateInterval);
			ecorec->setCommitInterval(commitInterval);
			ecorec->process(1);
		} break;
		case Rctables::enumAP_INVRCTREC:
		{
			QScopedPointer<AP_INVRCTREC> ap_invrctrec(new AP_INVRCTREC(nullptr));
			ap_invrctrec->open(sourceDSN, targetDSN);
			ap_invrctrec->setRepositoryString(envyRepositoryString);
			ap_invrctrec->setProfileName(profileName);
			ap_invrctrec->setReplicationOption(eReplicationOption);
			ap_invrctrec->setDropOption(edropOption);
			ap_invrctrec->setOdbcAttributes(odbcAttributes);
			ap_invrctrec->setUpdateInterval(updateInterval);
			ap_invrctrec->setCommitInterval(commitInterval);
			ap_invrctrec->process(1);
		} break;
		case Rctables::enumMA_SODSPISET:
		{
			QScopedPointer<MA_SODSPISET> ma_sodspiset(new MA_SODSPISET(nullptr));
			ma_sodspiset->open(sourceDSN, targetDSN);
			ma_sodspiset->setRepositoryString(envyRepositoryString);
			ma_sodspiset->setProfileName(profileName);
			ma_sodspiset->setReplicationOption(eReplicationOption);
			ma_sodspiset->setDropOption(edropOption);
			ma_sodspiset->setOdbcAttributes(odbcAttributes);
			ma_sodspiset->setUpdateInterval(updateInterval);
			ma_sodspiset->setCommitInterval(commitInterval);
			ma_sodspiset->process(1);
		} break;
		case Rctables::enumAP_APPOSTSET:
		{
			QScopedPointer<AP_APPOSTSET> ap_appostset(new AP_APPOSTSET(nullptr));
			ap_appostset->open(sourceDSN, targetDSN);
			ap_appostset->setRepositoryString(envyRepositoryString);
			ap_appostset->setProfileName(profileName);
			ap_appostset->setReplicationOption(eReplicationOption);
			ap_appostset->setDropOption(edropOption);
			ap_appostset->setOdbcAttributes(odbcAttributes);
			ap_appostset->setUpdateInterval(updateInterval);
			ap_appostset->setCommitInterval(commitInterval);
			ap_appostset->process(1);
		} break;
		case Rctables::enumWIPCONSET:
		{
			QScopedPointer<WIPCONSET> wipconset(new WIPCONSET(nullptr));
			wipconset->open(sourceDSN, targetDSN);
			wipconset->setRepositoryString(envyRepositoryString);
			wipconset->setProfileName(profileName);
			wipconset->setReplicationOption(eReplicationOption);
			wipconset->setDropOption(edropOption);
			wipconset->setOdbcAttributes(odbcAttributes);
			wipconset->setUpdateInterval(updateInterval);
			wipconset->setCommitInterval(commitInterval);
			wipconset->process(1);
		} break;
		case Rctables::enumGL_PROJREC:
		{
			QScopedPointer<GL_PROJREC> gl_projrec(new GL_PROJREC(nullptr));
			gl_projrec->open(sourceDSN, targetDSN);
			gl_projrec->setRepositoryString(envyRepositoryString);
			gl_projrec->setProfileName(profileName);
			gl_projrec->setReplicationOption(eReplicationOption);
			gl_projrec->setDropOption(edropOption);
			gl_projrec->setOdbcAttributes(odbcAttributes);
			gl_projrec->setUpdateInterval(updateInterval);
			gl_projrec->setCommitInterval(commitInterval);
			gl_projrec->process(1);
		} break;
		case Rctables::enumMA_TXTTXRTSET:
		{
			QScopedPointer<MA_TXTTXRTSET> ma_txttxrtset(new MA_TXTTXRTSET(nullptr));
			ma_txttxrtset->open(sourceDSN, targetDSN);
			ma_txttxrtset->setRepositoryString(envyRepositoryString);
			ma_txttxrtset->setProfileName(profileName);
			ma_txttxrtset->setReplicationOption(eReplicationOption);
			ma_txttxrtset->setDropOption(edropOption);
			ma_txttxrtset->setOdbcAttributes(odbcAttributes);
			ma_txttxrtset->setUpdateInterval(updateInterval);
			ma_txttxrtset->setCommitInterval(commitInterval);
			ma_txttxrtset->process(1);
		} break;
		case Rctables::enumGL_FISCTRSET:
		{
			QScopedPointer<GL_FISCTRSET> gl_fisctrset(new GL_FISCTRSET(nullptr));
			gl_fisctrset->open(sourceDSN, targetDSN);
			gl_fisctrset->setRepositoryString(envyRepositoryString);
			gl_fisctrset->setProfileName(profileName);
			gl_fisctrset->setReplicationOption(eReplicationOption);
			gl_fisctrset->setDropOption(edropOption);
			gl_fisctrset->setOdbcAttributes(odbcAttributes);
			gl_fisctrset->setUpdateInterval(updateInterval);
			gl_fisctrset->setCommitInterval(commitInterval);
			gl_fisctrset->process(1);
		} break;
		case Rctables::enumGL_PRPT_HREC:
		{
			QScopedPointer<GL_PRPT_HREC> gl_prpt_hrec(new GL_PRPT_HREC(nullptr));
			gl_prpt_hrec->open(sourceDSN, targetDSN);
			gl_prpt_hrec->setRepositoryString(envyRepositoryString);
			gl_prpt_hrec->setProfileName(profileName);
			gl_prpt_hrec->setReplicationOption(eReplicationOption);
			gl_prpt_hrec->setDropOption(edropOption);
			gl_prpt_hrec->setOdbcAttributes(odbcAttributes);
			gl_prpt_hrec->setUpdateInterval(updateInterval);
			gl_prpt_hrec->setCommitInterval(commitInterval);
			gl_prpt_hrec->process(1);
		} break;
		case Rctables::enumGL_VOLINKSET:
		{
			QScopedPointer<GL_VOLINKSET> gl_volinkset(new GL_VOLINKSET(nullptr));
			gl_volinkset->open(sourceDSN, targetDSN);
			gl_volinkset->setRepositoryString(envyRepositoryString);
			gl_volinkset->setProfileName(profileName);
			gl_volinkset->setReplicationOption(eReplicationOption);
			gl_volinkset->setDropOption(edropOption);
			gl_volinkset->setOdbcAttributes(odbcAttributes);
			gl_volinkset->setUpdateInterval(updateInterval);
			gl_volinkset->setCommitInterval(commitInterval);
			gl_volinkset->process(1);
		} break;
		case Rctables::enumMA_SOHQUOHSET:
		{
			QScopedPointer<MA_SOHQUOHSET> ma_sohquohset(new MA_SOHQUOHSET(nullptr));
			ma_sohquohset->open(sourceDSN, targetDSN);
			ma_sohquohset->setRepositoryString(envyRepositoryString);
			ma_sohquohset->setProfileName(profileName);
			ma_sohquohset->setReplicationOption(eReplicationOption);
			ma_sohquohset->setDropOption(edropOption);
			ma_sohquohset->setOdbcAttributes(odbcAttributes);
			ma_sohquohset->setUpdateInterval(updateInterval);
			ma_sohquohset->setCommitInterval(commitInterval);
			ma_sohquohset->process(1);
		} break;
		case Rctables::enumMA_PLINHSHSET:
		{
			QScopedPointer<MA_PLINHSHSET> ma_plinhshset(new MA_PLINHSHSET(nullptr));
			ma_plinhshset->open(sourceDSN, targetDSN);
			ma_plinhshset->setRepositoryString(envyRepositoryString);
			ma_plinhshset->setProfileName(profileName);
			ma_plinhshset->setReplicationOption(eReplicationOption);
			ma_plinhshset->setDropOption(edropOption);
			ma_plinhshset->setOdbcAttributes(odbcAttributes);
			ma_plinhshset->setUpdateInterval(updateInterval);
			ma_plinhshset->setCommitInterval(commitInterval);
			ma_plinhshset->process(1);
		} break;
		case Rctables::enumGL_PRPTSET:
		{
			QScopedPointer<GL_PRPTSET> gl_prptset(new GL_PRPTSET(nullptr));
			gl_prptset->open(sourceDSN, targetDSN);
			gl_prptset->setRepositoryString(envyRepositoryString);
			gl_prptset->setProfileName(profileName);
			gl_prptset->setReplicationOption(eReplicationOption);
			gl_prptset->setDropOption(edropOption);
			gl_prptset->setOdbcAttributes(odbcAttributes);
			gl_prptset->setUpdateInterval(updateInterval);
			gl_prptset->setCommitInterval(commitInterval);
			gl_prptset->process(1);
		} break;
		case Rctables::enumWIPMIXSET:
		{
			QScopedPointer<WIPMIXSET> wipmixset(new WIPMIXSET(nullptr));
			wipmixset->open(sourceDSN, targetDSN);
			wipmixset->setRepositoryString(envyRepositoryString);
			wipmixset->setProfileName(profileName);
			wipmixset->setReplicationOption(eReplicationOption);
			wipmixset->setDropOption(edropOption);
			wipmixset->setOdbcAttributes(odbcAttributes);
			wipmixset->setUpdateInterval(updateInterval);
			wipmixset->setCommitInterval(commitInterval);
			wipmixset->process(1);
		} break;
		case Rctables::enumVENVMCSET:
		{
			QScopedPointer<VENVMCSET> venvmcset(new VENVMCSET(nullptr));
			venvmcset->open(sourceDSN, targetDSN);
			venvmcset->setRepositoryString(envyRepositoryString);
			venvmcset->setProfileName(profileName);
			venvmcset->setReplicationOption(eReplicationOption);
			venvmcset->setDropOption(edropOption);
			venvmcset->setOdbcAttributes(odbcAttributes);
			venvmcset->setUpdateInterval(updateInterval);
			venvmcset->setCommitInterval(commitInterval);
			venvmcset->process(1);
		} break;
		case Rctables::enumGL_LINKMFGSET:
		{
			QScopedPointer<GL_LINKMFGSET> gl_linkmfgset(new GL_LINKMFGSET(nullptr));
			gl_linkmfgset->open(sourceDSN, targetDSN);
			gl_linkmfgset->setRepositoryString(envyRepositoryString);
			gl_linkmfgset->setProfileName(profileName);
			gl_linkmfgset->setReplicationOption(eReplicationOption);
			gl_linkmfgset->setDropOption(edropOption);
			gl_linkmfgset->setOdbcAttributes(odbcAttributes);
			gl_linkmfgset->setUpdateInterval(updateInterval);
			gl_linkmfgset->setCommitInterval(commitInterval);
			gl_linkmfgset->process(1);
		} break;
		case Rctables::enumMA_GLCTREC:
		{
			QScopedPointer<MA_GLCTREC> ma_glctrec(new MA_GLCTREC(nullptr));
			ma_glctrec->open(sourceDSN, targetDSN);
			ma_glctrec->setRepositoryString(envyRepositoryString);
			ma_glctrec->setProfileName(profileName);
			ma_glctrec->setReplicationOption(eReplicationOption);
			ma_glctrec->setDropOption(edropOption);
			ma_glctrec->setOdbcAttributes(odbcAttributes);
			ma_glctrec->setUpdateInterval(updateInterval);
			ma_glctrec->setCommitInterval(commitInterval);
			ma_glctrec->process(1);
		} break;
		case Rctables::enumMA_PRCTHSHSET:
		{
			QScopedPointer<MA_PRCTHSHSET> ma_prcthshset(new MA_PRCTHSHSET(nullptr));
			ma_prcthshset->open(sourceDSN, targetDSN);
			ma_prcthshset->setRepositoryString(envyRepositoryString);
			ma_prcthshset->setProfileName(profileName);
			ma_prcthshset->setReplicationOption(eReplicationOption);
			ma_prcthshset->setDropOption(edropOption);
			ma_prcthshset->setOdbcAttributes(odbcAttributes);
			ma_prcthshset->setUpdateInterval(updateInterval);
			ma_prcthshset->setCommitInterval(commitInterval);
			ma_prcthshset->process(1);
		} break;
		case Rctables::enumFRTBOLSET:
		{
			QScopedPointer<FRTBOLSET> frtbolset(new FRTBOLSET(nullptr));
			frtbolset->open(sourceDSN, targetDSN);
			frtbolset->setRepositoryString(envyRepositoryString);
			frtbolset->setProfileName(profileName);
			frtbolset->setReplicationOption(eReplicationOption);
			frtbolset->setDropOption(edropOption);
			frtbolset->setOdbcAttributes(odbcAttributes);
			frtbolset->setUpdateInterval(updateInterval);
			frtbolset->setCommitInterval(commitInterval);
			frtbolset->process(1);
		} break;
		case Rctables::enumAP_BANKREC:
		{
			QScopedPointer<AP_BANKREC> ap_bankrec(new AP_BANKREC(nullptr));
			ap_bankrec->open(sourceDSN, targetDSN);
			ap_bankrec->setRepositoryString(envyRepositoryString);
			ap_bankrec->setProfileName(profileName);
			ap_bankrec->setReplicationOption(eReplicationOption);
			ap_bankrec->setDropOption(edropOption);
			ap_bankrec->setOdbcAttributes(odbcAttributes);
			ap_bankrec->setUpdateInterval(updateInterval);
			ap_bankrec->setCommitInterval(commitInterval);
			ap_bankrec->process(1);
		} break;
		case Rctables::enumMA_PAYTPAYTDSET:
		{
			QScopedPointer<MA_PAYTPAYTDSET> ma_paytpaytdset(new MA_PAYTPAYTDSET(nullptr));
			ma_paytpaytdset->open(sourceDSN, targetDSN);
			ma_paytpaytdset->setRepositoryString(envyRepositoryString);
			ma_paytpaytdset->setProfileName(profileName);
			ma_paytpaytdset->setReplicationOption(eReplicationOption);
			ma_paytpaytdset->setDropOption(edropOption);
			ma_paytpaytdset->setOdbcAttributes(odbcAttributes);
			ma_paytpaytdset->setUpdateInterval(updateInterval);
			ma_paytpaytdset->setCommitInterval(commitInterval);
			ma_paytpaytdset->process(1);
		} break;
		case Rctables::enumGL_FPDESCSET:
		{
			QScopedPointer<GL_FPDESCSET> gl_fpdescset(new GL_FPDESCSET(nullptr));
			gl_fpdescset->open(sourceDSN, targetDSN);
			gl_fpdescset->setRepositoryString(envyRepositoryString);
			gl_fpdescset->setProfileName(profileName);
			gl_fpdescset->setReplicationOption(eReplicationOption);
			gl_fpdescset->setDropOption(edropOption);
			gl_fpdescset->setOdbcAttributes(odbcAttributes);
			gl_fpdescset->setUpdateInterval(updateInterval);
			gl_fpdescset->setCommitInterval(commitInterval);
			gl_fpdescset->process(1);
		} break;
		case Rctables::enumAP_VCHHSHSET:
		{
			QScopedPointer<AP_VCHHSHSET> ap_vchhshset(new AP_VCHHSHSET(nullptr));
			ap_vchhshset->open(sourceDSN, targetDSN);
			ap_vchhshset->setRepositoryString(envyRepositoryString);
			ap_vchhshset->setProfileName(profileName);
			ap_vchhshset->setReplicationOption(eReplicationOption);
			ap_vchhshset->setDropOption(edropOption);
			ap_vchhshset->setOdbcAttributes(odbcAttributes);
			ap_vchhshset->setUpdateInterval(updateInterval);
			ap_vchhshset->setCommitInterval(commitInterval);
			ap_vchhshset->process(1);
		} break;
		case Rctables::enumWARSET:
		{
			QScopedPointer<WARSET> warset(new WARSET(nullptr));
			warset->open(sourceDSN, targetDSN);
			warset->setRepositoryString(envyRepositoryString);
			warset->setProfileName(profileName);
			warset->setReplicationOption(eReplicationOption);
			warset->setDropOption(edropOption);
			warset->setOdbcAttributes(odbcAttributes);
			warset->setUpdateInterval(updateInterval);
			warset->setCommitInterval(commitInterval);
			warset->process(1);
		} break;
		case Rctables::enumAP_DMVCHSET:
		{
			QScopedPointer<AP_DMVCHSET> ap_dmvchset(new AP_DMVCHSET(nullptr));
			ap_dmvchset->open(sourceDSN, targetDSN);
			ap_dmvchset->setRepositoryString(envyRepositoryString);
			ap_dmvchset->setProfileName(profileName);
			ap_dmvchset->setReplicationOption(eReplicationOption);
			ap_dmvchset->setDropOption(edropOption);
			ap_dmvchset->setOdbcAttributes(odbcAttributes);
			ap_dmvchset->setUpdateInterval(updateInterval);
			ap_dmvchset->setCommitInterval(commitInterval);
			ap_dmvchset->process(1);
		} break;
		case Rctables::enumAUTAPPSET:
		{
			QScopedPointer<AUTAPPSET> autappset(new AUTAPPSET(nullptr));
			autappset->open(sourceDSN, targetDSN);
			autappset->setRepositoryString(envyRepositoryString);
			autappset->setProfileName(profileName);
			autappset->setReplicationOption(eReplicationOption);
			autappset->setDropOption(edropOption);
			autappset->setOdbcAttributes(odbcAttributes);
			autappset->setUpdateInterval(updateInterval);
			autappset->setCommitInterval(commitInterval);
			autappset->process(1);
		} break;
		case Rctables::enumMA_GLTABREC:
		{
			QScopedPointer<MA_GLTABREC> ma_gltabrec(new MA_GLTABREC(nullptr));
			ma_gltabrec->open(sourceDSN, targetDSN);
			ma_gltabrec->setRepositoryString(envyRepositoryString);
			ma_gltabrec->setProfileName(profileName);
			ma_gltabrec->setReplicationOption(eReplicationOption);
			ma_gltabrec->setDropOption(edropOption);
			ma_gltabrec->setOdbcAttributes(odbcAttributes);
			ma_gltabrec->setUpdateInterval(updateInterval);
			ma_gltabrec->setCommitInterval(commitInterval);
			ma_gltabrec->process(1);
		} break;
		case Rctables::enumMA_QUOHREC:
		{
			QScopedPointer<MA_QUOHREC> ma_quohrec(new MA_QUOHREC(nullptr));
			ma_quohrec->open(sourceDSN, targetDSN);
			ma_quohrec->setRepositoryString(envyRepositoryString);
			ma_quohrec->setProfileName(profileName);
			ma_quohrec->setReplicationOption(eReplicationOption);
			ma_quohrec->setDropOption(edropOption);
			ma_quohrec->setOdbcAttributes(odbcAttributes);
			ma_quohrec->setUpdateInterval(updateInterval);
			ma_quohrec->setCommitInterval(commitInterval);
			ma_quohrec->process(1);
		} break;
		case Rctables::enumPRTMISSET:
		{
			QScopedPointer<PRTMISSET> prtmisset(new PRTMISSET(nullptr));
			prtmisset->open(sourceDSN, targetDSN);
			prtmisset->setRepositoryString(envyRepositoryString);
			prtmisset->setProfileName(profileName);
			prtmisset->setReplicationOption(eReplicationOption);
			prtmisset->setDropOption(edropOption);
			prtmisset->setOdbcAttributes(odbcAttributes);
			prtmisset->setUpdateInterval(updateInterval);
			prtmisset->setCommitInterval(commitInterval);
			prtmisset->process(1);
		} break;
		case Rctables::enumVENCOHSET:
		{
			QScopedPointer<VENCOHSET> vencohset(new VENCOHSET(nullptr));
			vencohset->open(sourceDSN, targetDSN);
			vencohset->setRepositoryString(envyRepositoryString);
			vencohset->setProfileName(profileName);
			vencohset->setReplicationOption(eReplicationOption);
			vencohset->setDropOption(edropOption);
			vencohset->setOdbcAttributes(odbcAttributes);
			vencohset->setUpdateInterval(updateInterval);
			vencohset->setCommitInterval(commitInterval);
			vencohset->process(1);
		} break;
		case Rctables::enumWIPLOTSET:
		{
			QScopedPointer<WIPLOTSET> wiplotset(new WIPLOTSET(nullptr));
			wiplotset->open(sourceDSN, targetDSN);
			wiplotset->setRepositoryString(envyRepositoryString);
			wiplotset->setProfileName(profileName);
			wiplotset->setReplicationOption(eReplicationOption);
			wiplotset->setDropOption(edropOption);
			wiplotset->setOdbcAttributes(odbcAttributes);
			wiplotset->setUpdateInterval(updateInterval);
			wiplotset->setCommitInterval(commitInterval);
			wiplotset->process(1);
		} break;
		case Rctables::enumMA_SOHSODSET:
		{
			QScopedPointer<MA_SOHSODSET> ma_sohsodset(new MA_SOHSODSET(nullptr));
			ma_sohsodset->open(sourceDSN, targetDSN);
			ma_sohsodset->setRepositoryString(envyRepositoryString);
			ma_sohsodset->setProfileName(profileName);
			ma_sohsodset->setReplicationOption(eReplicationOption);
			ma_sohsodset->setDropOption(edropOption);
			ma_sohsodset->setOdbcAttributes(odbcAttributes);
			ma_sohsodset->setUpdateInterval(updateInterval);
			ma_sohsodset->setCommitInterval(commitInterval);
			ma_sohsodset->process(1);
		} break;
		case Rctables::enumAP_RCTINRCSET:
		{
			QScopedPointer<AP_RCTINRCSET> ap_rctinrcset(new AP_RCTINRCSET(nullptr));
			ap_rctinrcset->open(sourceDSN, targetDSN);
			ap_rctinrcset->setRepositoryString(envyRepositoryString);
			ap_rctinrcset->setProfileName(profileName);
			ap_rctinrcset->setReplicationOption(eReplicationOption);
			ap_rctinrcset->setDropOption(edropOption);
			ap_rctinrcset->setOdbcAttributes(odbcAttributes);
			ap_rctinrcset->setUpdateInterval(updateInterval);
			ap_rctinrcset->setCommitInterval(commitInterval);
			ap_rctinrcset->process(1);
		} break;
		case Rctables::enumAP_CASHBNKSET:
		{
			QScopedPointer<AP_CASHBNKSET> ap_cashbnkset(new AP_CASHBNKSET(nullptr));
			ap_cashbnkset->open(sourceDSN, targetDSN);
			ap_cashbnkset->setRepositoryString(envyRepositoryString);
			ap_cashbnkset->setProfileName(profileName);
			ap_cashbnkset->setReplicationOption(eReplicationOption);
			ap_cashbnkset->setDropOption(edropOption);
			ap_cashbnkset->setOdbcAttributes(odbcAttributes);
			ap_cashbnkset->setUpdateInterval(updateInterval);
			ap_cashbnkset->setCommitInterval(commitInterval);
			ap_cashbnkset->process(1);
		} break;
		case Rctables::enumMA_TXREC:
		{
			QScopedPointer<MA_TXREC> ma_txrec(new MA_TXREC(nullptr));
			ma_txrec->open(sourceDSN, targetDSN);
			ma_txrec->setRepositoryString(envyRepositoryString);
			ma_txrec->setProfileName(profileName);
			ma_txrec->setReplicationOption(eReplicationOption);
			ma_txrec->setDropOption(edropOption);
			ma_txrec->setOdbcAttributes(odbcAttributes);
			ma_txrec->setUpdateInterval(updateInterval);
			ma_txrec->setCommitInterval(commitInterval);
			ma_txrec->process(1);
		} break;
		case Rctables::enumMA_INHCRPOSTSET:
		{
			QScopedPointer<MA_INHCRPOSTSET> ma_inhcrpostset(new MA_INHCRPOSTSET(nullptr));
			ma_inhcrpostset->open(sourceDSN, targetDSN);
			ma_inhcrpostset->setRepositoryString(envyRepositoryString);
			ma_inhcrpostset->setProfileName(profileName);
			ma_inhcrpostset->setReplicationOption(eReplicationOption);
			ma_inhcrpostset->setDropOption(edropOption);
			ma_inhcrpostset->setOdbcAttributes(odbcAttributes);
			ma_inhcrpostset->setUpdateInterval(updateInterval);
			ma_inhcrpostset->setCommitInterval(commitInterval);
			ma_inhcrpostset->process(1);
		} break;
		case Rctables::enumSPNREC:
		{
			QScopedPointer<SPNREC> spnrec(new SPNREC(nullptr));
			spnrec->open(sourceDSN, targetDSN);
			spnrec->setRepositoryString(envyRepositoryString);
			spnrec->setProfileName(profileName);
			spnrec->setReplicationOption(eReplicationOption);
			spnrec->setDropOption(edropOption);
			spnrec->setOdbcAttributes(odbcAttributes);
			spnrec->setUpdateInterval(updateInterval);
			spnrec->setCommitInterval(commitInterval);
			spnrec->process(1);
		} break;
		case Rctables::enumPRTBORSET:
		{
			QScopedPointer<PRTBORSET> prtborset(new PRTBORSET(nullptr));
			prtborset->open(sourceDSN, targetDSN);
			prtborset->setRepositoryString(envyRepositoryString);
			prtborset->setProfileName(profileName);
			prtborset->setReplicationOption(eReplicationOption);
			prtborset->setDropOption(edropOption);
			prtborset->setOdbcAttributes(odbcAttributes);
			prtborset->setUpdateInterval(updateInterval);
			prtborset->setCommitInterval(commitInterval);
			prtborset->process(1);
		} break;
		case Rctables::enumMA_QUOHSPNLSET:
		{
			QScopedPointer<MA_QUOHSPNLSET> ma_quohspnlset(new MA_QUOHSPNLSET(nullptr));
			ma_quohspnlset->open(sourceDSN, targetDSN);
			ma_quohspnlset->setRepositoryString(envyRepositoryString);
			ma_quohspnlset->setProfileName(profileName);
			ma_quohspnlset->setReplicationOption(eReplicationOption);
			ma_quohspnlset->setDropOption(edropOption);
			ma_quohspnlset->setOdbcAttributes(odbcAttributes);
			ma_quohspnlset->setUpdateInterval(updateInterval);
			ma_quohspnlset->setCommitInterval(commitInterval);
			ma_quohspnlset->process(1);
		} break;
		case Rctables::enumMA_SOHUPDSET:
		{
			QScopedPointer<MA_SOHUPDSET> ma_sohupdset(new MA_SOHUPDSET(nullptr));
			ma_sohupdset->open(sourceDSN, targetDSN);
			ma_sohupdset->setRepositoryString(envyRepositoryString);
			ma_sohupdset->setProfileName(profileName);
			ma_sohupdset->setReplicationOption(eReplicationOption);
			ma_sohupdset->setDropOption(edropOption);
			ma_sohupdset->setOdbcAttributes(odbcAttributes);
			ma_sohupdset->setUpdateInterval(updateInterval);
			ma_sohupdset->setCommitInterval(commitInterval);
			ma_sohupdset->process(1);
		} break;
		case Rctables::enumAP_DISCBNKSET:
		{
			QScopedPointer<AP_DISCBNKSET> ap_discbnkset(new AP_DISCBNKSET(nullptr));
			ap_discbnkset->open(sourceDSN, targetDSN);
			ap_discbnkset->setRepositoryString(envyRepositoryString);
			ap_discbnkset->setProfileName(profileName);
			ap_discbnkset->setReplicationOption(eReplicationOption);
			ap_discbnkset->setDropOption(edropOption);
			ap_discbnkset->setOdbcAttributes(odbcAttributes);
			ap_discbnkset->setUpdateInterval(updateInterval);
			ap_discbnkset->setCommitInterval(commitInterval);
			ap_discbnkset->process(1);
		} break;
		case Rctables::enumBYDHSHSET:
		{
			QScopedPointer<BYDHSHSET> bydhshset(new BYDHSHSET(nullptr));
			bydhshset->open(sourceDSN, targetDSN);
			bydhshset->setRepositoryString(envyRepositoryString);
			bydhshset->setProfileName(profileName);
			bydhshset->setReplicationOption(eReplicationOption);
			bydhshset->setDropOption(edropOption);
			bydhshset->setOdbcAttributes(odbcAttributes);
			bydhshset->setUpdateInterval(updateInterval);
			bydhshset->setCommitInterval(commitInterval);
			bydhshset->process(1);
		} break;
		case Rctables::enumMA_INHINDMSET:
		{
			QScopedPointer<MA_INHINDMSET> ma_inhindmset(new MA_INHINDMSET(nullptr));
			ma_inhindmset->open(sourceDSN, targetDSN);
			ma_inhindmset->setRepositoryString(envyRepositoryString);
			ma_inhindmset->setProfileName(profileName);
			ma_inhindmset->setReplicationOption(eReplicationOption);
			ma_inhindmset->setDropOption(edropOption);
			ma_inhindmset->setOdbcAttributes(odbcAttributes);
			ma_inhindmset->setUpdateInterval(updateInterval);
			ma_inhindmset->setCommitInterval(commitInterval);
			ma_inhindmset->process(1);
		} break;
		case Rctables::enumGL_FP_HREC:
		{
			QScopedPointer<GL_FP_HREC> gl_fp_hrec(new GL_FP_HREC(nullptr));
			gl_fp_hrec->open(sourceDSN, targetDSN);
			gl_fp_hrec->setRepositoryString(envyRepositoryString);
			gl_fp_hrec->setProfileName(profileName);
			gl_fp_hrec->setReplicationOption(eReplicationOption);
			gl_fp_hrec->setDropOption(edropOption);
			gl_fp_hrec->setOdbcAttributes(odbcAttributes);
			gl_fp_hrec->setUpdateInterval(updateInterval);
			gl_fp_hrec->setCommitInterval(commitInterval);
			gl_fp_hrec->process(1);
		} break;
		case Rctables::enumMA_PARTTOPSET:
		{
			QScopedPointer<MA_PARTTOPSET> ma_parttopset(new MA_PARTTOPSET(nullptr));
			ma_parttopset->open(sourceDSN, targetDSN);
			ma_parttopset->setRepositoryString(envyRepositoryString);
			ma_parttopset->setProfileName(profileName);
			ma_parttopset->setReplicationOption(eReplicationOption);
			ma_parttopset->setDropOption(edropOption);
			ma_parttopset->setOdbcAttributes(odbcAttributes);
			ma_parttopset->setUpdateInterval(updateInterval);
			ma_parttopset->setCommitInterval(commitInterval);
			ma_parttopset->process(1);
		} break;
		case Rctables::enumGL_REDESCSET:
		{
			QScopedPointer<GL_REDESCSET> gl_redescset(new GL_REDESCSET(nullptr));
			gl_redescset->open(sourceDSN, targetDSN);
			gl_redescset->setRepositoryString(envyRepositoryString);
			gl_redescset->setProfileName(profileName);
			gl_redescset->setReplicationOption(eReplicationOption);
			gl_redescset->setDropOption(edropOption);
			gl_redescset->setOdbcAttributes(odbcAttributes);
			gl_redescset->setUpdateInterval(updateInterval);
			gl_redescset->setCommitInterval(commitInterval);
			gl_redescset->process(1);
		} break;
		case Rctables::enumGL_VPOFFACCTSET:
		{
			QScopedPointer<GL_VPOFFACCTSET> gl_vpoffacctset(new GL_VPOFFACCTSET(nullptr));
			gl_vpoffacctset->open(sourceDSN, targetDSN);
			gl_vpoffacctset->setRepositoryString(envyRepositoryString);
			gl_vpoffacctset->setProfileName(profileName);
			gl_vpoffacctset->setReplicationOption(eReplicationOption);
			gl_vpoffacctset->setDropOption(edropOption);
			gl_vpoffacctset->setOdbcAttributes(odbcAttributes);
			gl_vpoffacctset->setUpdateInterval(updateInterval);
			gl_vpoffacctset->setCommitInterval(commitInterval);
			gl_vpoffacctset->process(1);
		} break;
		case Rctables::enumAP_BOLBOLLSET:
		{
			QScopedPointer<AP_BOLBOLLSET> ap_bolbollset(new AP_BOLBOLLSET(nullptr));
			ap_bolbollset->open(sourceDSN, targetDSN);
			ap_bolbollset->setRepositoryString(envyRepositoryString);
			ap_bolbollset->setProfileName(profileName);
			ap_bolbollset->setReplicationOption(eReplicationOption);
			ap_bolbollset->setDropOption(edropOption);
			ap_bolbollset->setOdbcAttributes(odbcAttributes);
			ap_bolbollset->setUpdateInterval(updateInterval);
			ap_bolbollset->setCommitInterval(commitInterval);
			ap_bolbollset->process(1);
		} break;
		case Rctables::enumMA_SPFREC:
		{
			QScopedPointer<MA_SPFREC> ma_spfrec(new MA_SPFREC(nullptr));
			ma_spfrec->open(sourceDSN, targetDSN);
			ma_spfrec->setRepositoryString(envyRepositoryString);
			ma_spfrec->setProfileName(profileName);
			ma_spfrec->setReplicationOption(eReplicationOption);
			ma_spfrec->setDropOption(edropOption);
			ma_spfrec->setOdbcAttributes(odbcAttributes);
			ma_spfrec->setUpdateInterval(updateInterval);
			ma_spfrec->setCommitInterval(commitInterval);
			ma_spfrec->process(1);
		} break;
		case Rctables::enumBOLREC:
		{
			QScopedPointer<BOLREC> bolrec(new BOLREC(nullptr));
			bolrec->open(sourceDSN, targetDSN);
			bolrec->setRepositoryString(envyRepositoryString);
			bolrec->setProfileName(profileName);
			bolrec->setReplicationOption(eReplicationOption);
			bolrec->setDropOption(edropOption);
			bolrec->setOdbcAttributes(odbcAttributes);
			bolrec->setUpdateInterval(updateInterval);
			bolrec->setCommitInterval(commitInterval);
			bolrec->process(1);
		} break;
		case Rctables::enumCURHSHSET:
		{
			QScopedPointer<CURHSHSET> curhshset(new CURHSHSET(nullptr));
			curhshset->open(sourceDSN, targetDSN);
			curhshset->setRepositoryString(envyRepositoryString);
			curhshset->setProfileName(profileName);
			curhshset->setReplicationOption(eReplicationOption);
			curhshset->setDropOption(edropOption);
			curhshset->setOdbcAttributes(odbcAttributes);
			curhshset->setUpdateInterval(updateInterval);
			curhshset->setCommitInterval(commitInterval);
			curhshset->process(1);
		} break;
		case Rctables::enumMA_PRODSODSET:
		{
			QScopedPointer<MA_PRODSODSET> ma_prodsodset(new MA_PRODSODSET(nullptr));
			ma_prodsodset->open(sourceDSN, targetDSN);
			ma_prodsodset->setRepositoryString(envyRepositoryString);
			ma_prodsodset->setProfileName(profileName);
			ma_prodsodset->setReplicationOption(eReplicationOption);
			ma_prodsodset->setDropOption(edropOption);
			ma_prodsodset->setOdbcAttributes(odbcAttributes);
			ma_prodsodset->setUpdateInterval(updateInterval);
			ma_prodsodset->setCommitInterval(commitInterval);
			ma_prodsodset->process(1);
		} break;
		case Rctables::enumREFSET:
		{
			QScopedPointer<REFSET> refset(new REFSET(nullptr));
			refset->open(sourceDSN, targetDSN);
			refset->setRepositoryString(envyRepositoryString);
			refset->setProfileName(profileName);
			refset->setReplicationOption(eReplicationOption);
			refset->setDropOption(edropOption);
			refset->setOdbcAttributes(odbcAttributes);
			refset->setUpdateInterval(updateInterval);
			refset->setCommitInterval(commitInterval);
			refset->process(1);
		} break;
		case Rctables::enumMA_INDSPISET:
		{
			QScopedPointer<MA_INDSPISET> ma_indspiset(new MA_INDSPISET(nullptr));
			ma_indspiset->open(sourceDSN, targetDSN);
			ma_indspiset->setRepositoryString(envyRepositoryString);
			ma_indspiset->setProfileName(profileName);
			ma_indspiset->setReplicationOption(eReplicationOption);
			ma_indspiset->setDropOption(edropOption);
			ma_indspiset->setOdbcAttributes(odbcAttributes);
			ma_indspiset->setUpdateInterval(updateInterval);
			ma_indspiset->setCommitInterval(commitInterval);
			ma_indspiset->process(1);
		} break;
		case Rctables::enumLOTREC:
		{
			QScopedPointer<LOTREC> lotrec(new LOTREC(nullptr));
			lotrec->open(sourceDSN, targetDSN);
			lotrec->setRepositoryString(envyRepositoryString);
			lotrec->setProfileName(profileName);
			lotrec->setReplicationOption(eReplicationOption);
			lotrec->setDropOption(edropOption);
			lotrec->setOdbcAttributes(odbcAttributes);
			lotrec->setUpdateInterval(updateInterval);
			lotrec->setCommitInterval(commitInterval);
			lotrec->process(1);
		} break;
		case Rctables::enumINVHSHSET:
		{
			QScopedPointer<INVHSHSET> invhshset(new INVHSHSET(nullptr));
			invhshset->open(sourceDSN, targetDSN);
			invhshset->setRepositoryString(envyRepositoryString);
			invhshset->setProfileName(profileName);
			invhshset->setReplicationOption(eReplicationOption);
			invhshset->setDropOption(edropOption);
			invhshset->setOdbcAttributes(odbcAttributes);
			invhshset->setUpdateInterval(updateInterval);
			invhshset->setCommitInterval(commitInterval);
			invhshset->process(1);
		} break;
		case Rctables::enumMA_QUOHPRTSET:
		{
			QScopedPointer<MA_QUOHPRTSET> ma_quohprtset(new MA_QUOHPRTSET(nullptr));
			ma_quohprtset->open(sourceDSN, targetDSN);
			ma_quohprtset->setRepositoryString(envyRepositoryString);
			ma_quohprtset->setProfileName(profileName);
			ma_quohprtset->setReplicationOption(eReplicationOption);
			ma_quohprtset->setDropOption(edropOption);
			ma_quohprtset->setOdbcAttributes(odbcAttributes);
			ma_quohprtset->setUpdateInterval(updateInterval);
			ma_quohprtset->setCommitInterval(commitInterval);
			ma_quohprtset->process(1);
		} break;
		case Rctables::enumMA_CTERREC:
		{
			QScopedPointer<MA_CTERREC> ma_cterrec(new MA_CTERREC(nullptr));
			ma_cterrec->open(sourceDSN, targetDSN);
			ma_cterrec->setRepositoryString(envyRepositoryString);
			ma_cterrec->setProfileName(profileName);
			ma_cterrec->setReplicationOption(eReplicationOption);
			ma_cterrec->setDropOption(edropOption);
			ma_cterrec->setOdbcAttributes(odbcAttributes);
			ma_cterrec->setUpdateInterval(updateInterval);
			ma_cterrec->setCommitInterval(commitInterval);
			ma_cterrec->process(1);
		} break;
		case Rctables::enumMA_PAKPRTSET:
		{
			QScopedPointer<MA_PAKPRTSET> ma_pakprtset(new MA_PAKPRTSET(nullptr));
			ma_pakprtset->open(sourceDSN, targetDSN);
			ma_pakprtset->setRepositoryString(envyRepositoryString);
			ma_pakprtset->setProfileName(profileName);
			ma_pakprtset->setReplicationOption(eReplicationOption);
			ma_pakprtset->setDropOption(edropOption);
			ma_pakprtset->setOdbcAttributes(odbcAttributes);
			ma_pakprtset->setUpdateInterval(updateInterval);
			ma_pakprtset->setCommitInterval(commitInterval);
			ma_pakprtset->process(1);
		} break;
		case Rctables::enumPRHPRDSET:
		{
			QScopedPointer<PRHPRDSET> prhprdset(new PRHPRDSET(nullptr));
			prhprdset->open(sourceDSN, targetDSN);
			prhprdset->setRepositoryString(envyRepositoryString);
			prhprdset->setProfileName(profileName);
			prhprdset->setReplicationOption(eReplicationOption);
			prhprdset->setDropOption(edropOption);
			prhprdset->setOdbcAttributes(odbcAttributes);
			prhprdset->setUpdateInterval(updateInterval);
			prhprdset->setCommitInterval(commitInterval);
			prhprdset->process(1);
		} break;
		case Rctables::enumMSCREC:
		{
			QScopedPointer<MSCREC> mscrec(new MSCREC(nullptr));
			mscrec->open(sourceDSN, targetDSN);
			mscrec->setRepositoryString(envyRepositoryString);
			mscrec->setProfileName(profileName);
			mscrec->setReplicationOption(eReplicationOption);
			mscrec->setDropOption(edropOption);
			mscrec->setOdbcAttributes(odbcAttributes);
			mscrec->setUpdateInterval(updateInterval);
			mscrec->setCommitInterval(commitInterval);
			mscrec->process(1);
		} break;
		case Rctables::enumWOHMISSET:
		{
			QScopedPointer<WOHMISSET> wohmisset(new WOHMISSET(nullptr));
			wohmisset->open(sourceDSN, targetDSN);
			wohmisset->setRepositoryString(envyRepositoryString);
			wohmisset->setProfileName(profileName);
			wohmisset->setReplicationOption(eReplicationOption);
			wohmisset->setDropOption(edropOption);
			wohmisset->setOdbcAttributes(odbcAttributes);
			wohmisset->setUpdateInterval(updateInterval);
			wohmisset->setCommitInterval(commitInterval);
			wohmisset->process(1);
		} break;
		case Rctables::enumAP_PAYOR1099REC:
		{
			QScopedPointer<AP_PAYOR1099REC> ap_payor1099rec(new AP_PAYOR1099REC(nullptr));
			ap_payor1099rec->open(sourceDSN, targetDSN);
			ap_payor1099rec->setRepositoryString(envyRepositoryString);
			ap_payor1099rec->setProfileName(profileName);
			ap_payor1099rec->setReplicationOption(eReplicationOption);
			ap_payor1099rec->setDropOption(edropOption);
			ap_payor1099rec->setOdbcAttributes(odbcAttributes);
			ap_payor1099rec->setUpdateInterval(updateInterval);
			ap_payor1099rec->setCommitInterval(commitInterval);
			ap_payor1099rec->process(1);
		} break;
		case Rctables::enumMA_DMHLREC:
		{
			QScopedPointer<MA_DMHLREC> ma_dmhlrec(new MA_DMHLREC(nullptr));
			ma_dmhlrec->open(sourceDSN, targetDSN);
			ma_dmhlrec->setRepositoryString(envyRepositoryString);
			ma_dmhlrec->setProfileName(profileName);
			ma_dmhlrec->setReplicationOption(eReplicationOption);
			ma_dmhlrec->setDropOption(edropOption);
			ma_dmhlrec->setOdbcAttributes(odbcAttributes);
			ma_dmhlrec->setUpdateInterval(updateInterval);
			ma_dmhlrec->setCommitInterval(commitInterval);
			ma_dmhlrec->process(1);
		} break;
		case Rctables::enumCCSRTSET:
		{
			QScopedPointer<CCSRTSET> ccsrtset(new CCSRTSET(nullptr));
			ccsrtset->open(sourceDSN, targetDSN);
			ccsrtset->setRepositoryString(envyRepositoryString);
			ccsrtset->setProfileName(profileName);
			ccsrtset->setReplicationOption(eReplicationOption);
			ccsrtset->setDropOption(edropOption);
			ccsrtset->setOdbcAttributes(odbcAttributes);
			ccsrtset->setUpdateInterval(updateInterval);
			ccsrtset->setCommitInterval(commitInterval);
			ccsrtset->process(1);
		} break;
		case Rctables::enumCODHSHSET:
		{
			QScopedPointer<CODHSHSET> codhshset(new CODHSHSET(nullptr));
			codhshset->open(sourceDSN, targetDSN);
			codhshset->setRepositoryString(envyRepositoryString);
			codhshset->setProfileName(profileName);
			codhshset->setReplicationOption(eReplicationOption);
			codhshset->setDropOption(edropOption);
			codhshset->setOdbcAttributes(odbcAttributes);
			codhshset->setUpdateInterval(updateInterval);
			codhshset->setCommitInterval(commitInterval);
			codhshset->process(1);
		} break;
		case Rctables::enumAP_RCTREC:
		{
			QScopedPointer<AP_RCTREC> ap_rctrec(new AP_RCTREC(nullptr));
			ap_rctrec->open(sourceDSN, targetDSN);
			ap_rctrec->setRepositoryString(envyRepositoryString);
			ap_rctrec->setProfileName(profileName);
			ap_rctrec->setReplicationOption(eReplicationOption);
			ap_rctrec->setDropOption(edropOption);
			ap_rctrec->setOdbcAttributes(odbcAttributes);
			ap_rctrec->setUpdateInterval(updateInterval);
			ap_rctrec->setCommitInterval(commitInterval);
			ap_rctrec->process(1);
		} break;
		case Rctables::enumGL_REACCTSET:
		{
			QScopedPointer<GL_REACCTSET> gl_reacctset(new GL_REACCTSET(nullptr));
			gl_reacctset->open(sourceDSN, targetDSN);
			gl_reacctset->setRepositoryString(envyRepositoryString);
			gl_reacctset->setProfileName(profileName);
			gl_reacctset->setReplicationOption(eReplicationOption);
			gl_reacctset->setDropOption(edropOption);
			gl_reacctset->setOdbcAttributes(odbcAttributes);
			gl_reacctset->setUpdateInterval(updateInterval);
			gl_reacctset->setCommitInterval(commitInterval);
			gl_reacctset->process(1);
		} break;
		case Rctables::enumMA_GLCTHSHSET:
		{
			QScopedPointer<MA_GLCTHSHSET> ma_glcthshset(new MA_GLCTHSHSET(nullptr));
			ma_glcthshset->open(sourceDSN, targetDSN);
			ma_glcthshset->setRepositoryString(envyRepositoryString);
			ma_glcthshset->setProfileName(profileName);
			ma_glcthshset->setReplicationOption(eReplicationOption);
			ma_glcthshset->setDropOption(edropOption);
			ma_glcthshset->setOdbcAttributes(odbcAttributes);
			ma_glcthshset->setUpdateInterval(updateInterval);
			ma_glcthshset->setCommitInterval(commitInterval);
			ma_glcthshset->process(1);
		} break;
		case Rctables::enumED_TPENTSET:
		{
			QScopedPointer<ED_TPENTSET> ed_tpentset(new ED_TPENTSET(nullptr));
			ed_tpentset->open(sourceDSN, targetDSN);
			ed_tpentset->setRepositoryString(envyRepositoryString);
			ed_tpentset->setProfileName(profileName);
			ed_tpentset->setReplicationOption(eReplicationOption);
			ed_tpentset->setDropOption(edropOption);
			ed_tpentset->setOdbcAttributes(odbcAttributes);
			ed_tpentset->setUpdateInterval(updateInterval);
			ed_tpentset->setCommitInterval(commitInterval);
			ed_tpentset->process(1);
		} break;
		case Rctables::enumMA_GLPTTABSET:
		{
			QScopedPointer<MA_GLPTTABSET> ma_glpttabset(new MA_GLPTTABSET(nullptr));
			ma_glpttabset->open(sourceDSN, targetDSN);
			ma_glpttabset->setRepositoryString(envyRepositoryString);
			ma_glpttabset->setProfileName(profileName);
			ma_glpttabset->setReplicationOption(eReplicationOption);
			ma_glpttabset->setDropOption(edropOption);
			ma_glpttabset->setOdbcAttributes(odbcAttributes);
			ma_glpttabset->setUpdateInterval(updateInterval);
			ma_glpttabset->setCommitInterval(commitInterval);
			ma_glpttabset->process(1);
		} break;
		case Rctables::enumDFAHSHSET:
		{
			QScopedPointer<DFAHSHSET> dfahshset(new DFAHSHSET(nullptr));
			dfahshset->open(sourceDSN, targetDSN);
			dfahshset->setRepositoryString(envyRepositoryString);
			dfahshset->setProfileName(profileName);
			dfahshset->setReplicationOption(eReplicationOption);
			dfahshset->setDropOption(edropOption);
			dfahshset->setOdbcAttributes(odbcAttributes);
			dfahshset->setUpdateInterval(updateInterval);
			dfahshset->setCommitInterval(commitInterval);
			dfahshset->process(1);
		} break;
		case Rctables::enumGL_ACCT_NREC:
		{
			QScopedPointer<GL_ACCT_NREC> gl_acct_nrec(new GL_ACCT_NREC(nullptr));
			gl_acct_nrec->open(sourceDSN, targetDSN);
			gl_acct_nrec->setRepositoryString(envyRepositoryString);
			gl_acct_nrec->setProfileName(profileName);
			gl_acct_nrec->setReplicationOption(eReplicationOption);
			gl_acct_nrec->setDropOption(edropOption);
			gl_acct_nrec->setOdbcAttributes(odbcAttributes);
			gl_acct_nrec->setUpdateInterval(updateInterval);
			gl_acct_nrec->setCommitInterval(commitInterval);
			gl_acct_nrec->process(1);
		} break;
		case Rctables::enumFSCCALREC:
		{
			QScopedPointer<FSCCALREC> fsccalrec(new FSCCALREC(nullptr));
			fsccalrec->open(sourceDSN, targetDSN);
			fsccalrec->setRepositoryString(envyRepositoryString);
			fsccalrec->setProfileName(profileName);
			fsccalrec->setReplicationOption(eReplicationOption);
			fsccalrec->setDropOption(edropOption);
			fsccalrec->setOdbcAttributes(odbcAttributes);
			fsccalrec->setUpdateInterval(updateInterval);
			fsccalrec->setCommitInterval(commitInterval);
			fsccalrec->process(1);
		} break;
		case Rctables::enumCDPLREC:
		{
			QScopedPointer<CDPLREC> cdplrec(new CDPLREC(nullptr));
			cdplrec->open(sourceDSN, targetDSN);
			cdplrec->setRepositoryString(envyRepositoryString);
			cdplrec->setProfileName(profileName);
			cdplrec->setReplicationOption(eReplicationOption);
			cdplrec->setDropOption(edropOption);
			cdplrec->setOdbcAttributes(odbcAttributes);
			cdplrec->setUpdateInterval(updateInterval);
			cdplrec->setCommitInterval(commitInterval);
			cdplrec->process(1);
		} break;
		case Rctables::enumAP_RCTSET:
		{
			QScopedPointer<AP_RCTSET> ap_rctset(new AP_RCTSET(nullptr));
			ap_rctset->open(sourceDSN, targetDSN);
			ap_rctset->setRepositoryString(envyRepositoryString);
			ap_rctset->setProfileName(profileName);
			ap_rctset->setReplicationOption(eReplicationOption);
			ap_rctset->setDropOption(edropOption);
			ap_rctset->setOdbcAttributes(odbcAttributes);
			ap_rctset->setUpdateInterval(updateInterval);
			ap_rctset->setCommitInterval(commitInterval);
			ap_rctset->process(1);
		} break;
		case Rctables::enumRTGTRKSET:
		{
			QScopedPointer<RTGTRKSET> rtgtrkset(new RTGTRKSET(nullptr));
			rtgtrkset->open(sourceDSN, targetDSN);
			rtgtrkset->setRepositoryString(envyRepositoryString);
			rtgtrkset->setProfileName(profileName);
			rtgtrkset->setReplicationOption(eReplicationOption);
			rtgtrkset->setDropOption(edropOption);
			rtgtrkset->setOdbcAttributes(odbcAttributes);
			rtgtrkset->setUpdateInterval(updateInterval);
			rtgtrkset->setCommitInterval(commitInterval);
			rtgtrkset->process(1);
		} break;
		case Rctables::enumCDLCDASET:
		{
			QScopedPointer<CDLCDASET> cdlcdaset(new CDLCDASET(nullptr));
			cdlcdaset->open(sourceDSN, targetDSN);
			cdlcdaset->setRepositoryString(envyRepositoryString);
			cdlcdaset->setProfileName(profileName);
			cdlcdaset->setReplicationOption(eReplicationOption);
			cdlcdaset->setDropOption(edropOption);
			cdlcdaset->setOdbcAttributes(odbcAttributes);
			cdlcdaset->setUpdateInterval(updateInterval);
			cdlcdaset->setCommitInterval(commitInterval);
			cdlcdaset->process(1);
		} break;
		case Rctables::enumMA_STATETXSET:
		{
			QScopedPointer<MA_STATETXSET> ma_statetxset(new MA_STATETXSET(nullptr));
			ma_statetxset->open(sourceDSN, targetDSN);
			ma_statetxset->setRepositoryString(envyRepositoryString);
			ma_statetxset->setProfileName(profileName);
			ma_statetxset->setReplicationOption(eReplicationOption);
			ma_statetxset->setDropOption(edropOption);
			ma_statetxset->setOdbcAttributes(odbcAttributes);
			ma_statetxset->setUpdateInterval(updateInterval);
			ma_statetxset->setCommitInterval(commitInterval);
			ma_statetxset->process(1);
		} break;
		case Rctables::enumMA_SHHSHDSET:
		{
			QScopedPointer<MA_SHHSHDSET> ma_shhshdset(new MA_SHHSHDSET(nullptr));
			ma_shhshdset->open(sourceDSN, targetDSN);
			ma_shhshdset->setRepositoryString(envyRepositoryString);
			ma_shhshdset->setProfileName(profileName);
			ma_shhshdset->setReplicationOption(eReplicationOption);
			ma_shhshdset->setDropOption(edropOption);
			ma_shhshdset->setOdbcAttributes(odbcAttributes);
			ma_shhshdset->setUpdateInterval(updateInterval);
			ma_shhshdset->setCommitInterval(commitInterval);
			ma_shhshdset->process(1);
		} break;
		case Rctables::enumTOOREC:
		{
			QScopedPointer<TOOREC> toorec(new TOOREC(nullptr));
			toorec->open(sourceDSN, targetDSN);
			toorec->setRepositoryString(envyRepositoryString);
			toorec->setProfileName(profileName);
			toorec->setReplicationOption(eReplicationOption);
			toorec->setDropOption(edropOption);
			toorec->setOdbcAttributes(odbcAttributes);
			toorec->setUpdateInterval(updateInterval);
			toorec->setCommitInterval(commitInterval);
			toorec->process(1);
		} break;
		case Rctables::enumACTPCSET:
		{
			QScopedPointer<ACTPCSET> actpcset(new ACTPCSET(nullptr));
			actpcset->open(sourceDSN, targetDSN);
			actpcset->setRepositoryString(envyRepositoryString);
			actpcset->setProfileName(profileName);
			actpcset->setReplicationOption(eReplicationOption);
			actpcset->setDropOption(edropOption);
			actpcset->setOdbcAttributes(odbcAttributes);
			actpcset->setUpdateInterval(updateInterval);
			actpcset->setCommitInterval(commitInterval);
			actpcset->process(1);
		} break;
		case Rctables::enumMA_PAYTREC:
		{
			QScopedPointer<MA_PAYTREC> ma_paytrec(new MA_PAYTREC(nullptr));
			ma_paytrec->open(sourceDSN, targetDSN);
			ma_paytrec->setRepositoryString(envyRepositoryString);
			ma_paytrec->setProfileName(profileName);
			ma_paytrec->setReplicationOption(eReplicationOption);
			ma_paytrec->setDropOption(edropOption);
			ma_paytrec->setOdbcAttributes(odbcAttributes);
			ma_paytrec->setUpdateInterval(updateInterval);
			ma_paytrec->setCommitInterval(commitInterval);
			ma_paytrec->process(1);
		} break;
		case Rctables::enumAP_APVNDSET:
		{
			QScopedPointer<AP_APVNDSET> ap_apvndset(new AP_APVNDSET(nullptr));
			ap_apvndset->open(sourceDSN, targetDSN);
			ap_apvndset->setRepositoryString(envyRepositoryString);
			ap_apvndset->setProfileName(profileName);
			ap_apvndset->setReplicationOption(eReplicationOption);
			ap_apvndset->setDropOption(edropOption);
			ap_apvndset->setOdbcAttributes(odbcAttributes);
			ap_apvndset->setUpdateInterval(updateInterval);
			ap_apvndset->setCommitInterval(commitInterval);
			ap_apvndset->process(1);
		} break;
		case Rctables::enumRTDSET:
		{
			QScopedPointer<RTDSET> rtdset(new RTDSET(nullptr));
			rtdset->open(sourceDSN, targetDSN);
			rtdset->setRepositoryString(envyRepositoryString);
			rtdset->setProfileName(profileName);
			rtdset->setReplicationOption(eReplicationOption);
			rtdset->setDropOption(edropOption);
			rtdset->setOdbcAttributes(odbcAttributes);
			rtdset->setUpdateInterval(updateInterval);
			rtdset->setCommitInterval(commitInterval);
			rtdset->process(1);
		} break;
		case Rctables::enumMA_SOHSPNLSET:
		{
			QScopedPointer<MA_SOHSPNLSET> ma_sohspnlset(new MA_SOHSPNLSET(nullptr));
			ma_sohspnlset->open(sourceDSN, targetDSN);
			ma_sohspnlset->setRepositoryString(envyRepositoryString);
			ma_sohspnlset->setProfileName(profileName);
			ma_sohspnlset->setReplicationOption(eReplicationOption);
			ma_sohspnlset->setDropOption(edropOption);
			ma_sohspnlset->setOdbcAttributes(odbcAttributes);
			ma_sohspnlset->setUpdateInterval(updateInterval);
			ma_sohspnlset->setCommitInterval(commitInterval);
			ma_sohspnlset->process(1);
		} break;
		case Rctables::enumPRTRQDSET:
		{
			QScopedPointer<PRTRQDSET> prtrqdset(new PRTRQDSET(nullptr));
			prtrqdset->open(sourceDSN, targetDSN);
			prtrqdset->setRepositoryString(envyRepositoryString);
			prtrqdset->setProfileName(profileName);
			prtrqdset->setReplicationOption(eReplicationOption);
			prtrqdset->setDropOption(edropOption);
			prtrqdset->setOdbcAttributes(odbcAttributes);
			prtrqdset->setUpdateInterval(updateInterval);
			prtrqdset->setCommitInterval(commitInterval);
			prtrqdset->process(1);
		} break;
		case Rctables::enumACTMOSET:
		{
			QScopedPointer<ACTMOSET> actmoset(new ACTMOSET(nullptr));
			actmoset->open(sourceDSN, targetDSN);
			actmoset->setRepositoryString(envyRepositoryString);
			actmoset->setProfileName(profileName);
			actmoset->setReplicationOption(eReplicationOption);
			actmoset->setDropOption(edropOption);
			actmoset->setOdbcAttributes(odbcAttributes);
			actmoset->setUpdateInterval(updateInterval);
			actmoset->setCommitInterval(commitInterval);
			actmoset->process(1);
		} break;
		case Rctables::enumAP_PLTREC:
		{
			QScopedPointer<AP_PLTREC> ap_pltrec(new AP_PLTREC(nullptr));
			ap_pltrec->open(sourceDSN, targetDSN);
			ap_pltrec->setRepositoryString(envyRepositoryString);
			ap_pltrec->setProfileName(profileName);
			ap_pltrec->setReplicationOption(eReplicationOption);
			ap_pltrec->setDropOption(edropOption);
			ap_pltrec->setOdbcAttributes(odbcAttributes);
			ap_pltrec->setUpdateInterval(updateInterval);
			ap_pltrec->setCommitInterval(commitInterval);
			ap_pltrec->process(1);
		} break;
		case Rctables::enumGL_LINKHSHSET:
		{
			QScopedPointer<GL_LINKHSHSET> gl_linkhshset(new GL_LINKHSHSET(nullptr));
			gl_linkhshset->open(sourceDSN, targetDSN);
			gl_linkhshset->setRepositoryString(envyRepositoryString);
			gl_linkhshset->setProfileName(profileName);
			gl_linkhshset->setReplicationOption(eReplicationOption);
			gl_linkhshset->setDropOption(edropOption);
			gl_linkhshset->setOdbcAttributes(odbcAttributes);
			gl_linkhshset->setUpdateInterval(updateInterval);
			gl_linkhshset->setCommitInterval(commitInterval);
			gl_linkhshset->process(1);
		} break;
		case Rctables::enumAP_PMTNOTTRANSSET:
		{
			QScopedPointer<AP_PMTNOTTRANSSET> ap_pmtnottransset(new AP_PMTNOTTRANSSET(nullptr));
			ap_pmtnottransset->open(sourceDSN, targetDSN);
			ap_pmtnottransset->setRepositoryString(envyRepositoryString);
			ap_pmtnottransset->setProfileName(profileName);
			ap_pmtnottransset->setReplicationOption(eReplicationOption);
			ap_pmtnottransset->setDropOption(edropOption);
			ap_pmtnottransset->setOdbcAttributes(odbcAttributes);
			ap_pmtnottransset->setUpdateInterval(updateInterval);
			ap_pmtnottransset->setCommitInterval(commitInterval);
			ap_pmtnottransset->process(1);
		} break;
		case Rctables::enumAP_VND1099SET:
		{
			QScopedPointer<AP_VND1099SET> ap_vnd1099set(new AP_VND1099SET(nullptr));
			ap_vnd1099set->open(sourceDSN, targetDSN);
			ap_vnd1099set->setRepositoryString(envyRepositoryString);
			ap_vnd1099set->setProfileName(profileName);
			ap_vnd1099set->setReplicationOption(eReplicationOption);
			ap_vnd1099set->setDropOption(edropOption);
			ap_vnd1099set->setOdbcAttributes(odbcAttributes);
			ap_vnd1099set->setUpdateInterval(updateInterval);
			ap_vnd1099set->setCommitInterval(commitInterval);
			ap_vnd1099set->process(1);
		} break;
		case Rctables::enumMA_PROJREC:
		{
			QScopedPointer<MA_PROJREC> ma_projrec(new MA_PROJREC(nullptr));
			ma_projrec->open(sourceDSN, targetDSN);
			ma_projrec->setRepositoryString(envyRepositoryString);
			ma_projrec->setProfileName(profileName);
			ma_projrec->setReplicationOption(eReplicationOption);
			ma_projrec->setDropOption(edropOption);
			ma_projrec->setOdbcAttributes(odbcAttributes);
			ma_projrec->setUpdateInterval(updateInterval);
			ma_projrec->setCommitInterval(commitInterval);
			ma_projrec->process(1);
		} break;
		case Rctables::enumMA_REMREC:
		{
			QScopedPointer<MA_REMREC> ma_remrec(new MA_REMREC(nullptr));
			ma_remrec->open(sourceDSN, targetDSN);
			ma_remrec->setRepositoryString(envyRepositoryString);
			ma_remrec->setProfileName(profileName);
			ma_remrec->setReplicationOption(eReplicationOption);
			ma_remrec->setDropOption(edropOption);
			ma_remrec->setOdbcAttributes(odbcAttributes);
			ma_remrec->setUpdateInterval(updateInterval);
			ma_remrec->setCommitInterval(commitInterval);
			ma_remrec->process(1);
		} break;
		case Rctables::enumAP_POHVCHSET:
		{
			QScopedPointer<AP_POHVCHSET> ap_pohvchset(new AP_POHVCHSET(nullptr));
			ap_pohvchset->open(sourceDSN, targetDSN);
			ap_pohvchset->setRepositoryString(envyRepositoryString);
			ap_pohvchset->setProfileName(profileName);
			ap_pohvchset->setReplicationOption(eReplicationOption);
			ap_pohvchset->setDropOption(edropOption);
			ap_pohvchset->setOdbcAttributes(odbcAttributes);
			ap_pohvchset->setUpdateInterval(updateInterval);
			ap_pohvchset->setCommitInterval(commitInterval);
			ap_pohvchset->process(1);
		} break;
		case Rctables::enumSODINTSET:
		{
			QScopedPointer<SODINTSET> sodintset(new SODINTSET(nullptr));
			sodintset->open(sourceDSN, targetDSN);
			sodintset->setRepositoryString(envyRepositoryString);
			sodintset->setProfileName(profileName);
			sodintset->setReplicationOption(eReplicationOption);
			sodintset->setDropOption(edropOption);
			sodintset->setOdbcAttributes(odbcAttributes);
			sodintset->setUpdateInterval(updateInterval);
			sodintset->setCommitInterval(commitInterval);
			sodintset->process(1);
		} break;
		case Rctables::enumCSTSET:
		{
			QScopedPointer<CSTSET> cstset(new CSTSET(nullptr));
			cstset->open(sourceDSN, targetDSN);
			cstset->setRepositoryString(envyRepositoryString);
			cstset->setProfileName(profileName);
			cstset->setReplicationOption(eReplicationOption);
			cstset->setDropOption(edropOption);
			cstset->setOdbcAttributes(odbcAttributes);
			cstset->setUpdateInterval(updateInterval);
			cstset->setCommitInterval(commitInterval);
			cstset->process(1);
		} break;
		case Rctables::enumMA_SODSHDSET:
		{
			QScopedPointer<MA_SODSHDSET> ma_sodshdset(new MA_SODSHDSET(nullptr));
			ma_sodshdset->open(sourceDSN, targetDSN);
			ma_sodshdset->setRepositoryString(envyRepositoryString);
			ma_sodshdset->setProfileName(profileName);
			ma_sodshdset->setReplicationOption(eReplicationOption);
			ma_sodshdset->setDropOption(edropOption);
			ma_sodshdset->setOdbcAttributes(odbcAttributes);
			ma_sodshdset->setUpdateInterval(updateInterval);
			ma_sodshdset->setCommitInterval(commitInterval);
			ma_sodshdset->process(1);
		} break;
		case Rctables::enumFORREC:
		{
			QScopedPointer<FORREC> forrec(new FORREC(nullptr));
			forrec->open(sourceDSN, targetDSN);
			forrec->setRepositoryString(envyRepositoryString);
			forrec->setProfileName(profileName);
			forrec->setReplicationOption(eReplicationOption);
			forrec->setDropOption(edropOption);
			forrec->setOdbcAttributes(odbcAttributes);
			forrec->setUpdateInterval(updateInterval);
			forrec->setCommitInterval(commitInterval);
			forrec->process(1);
		} break;
		case Rctables::enumBOMSET:
		{
			QScopedPointer<BOMSET> bomset(new BOMSET(nullptr));
			bomset->open(sourceDSN, targetDSN);
			bomset->setRepositoryString(envyRepositoryString);
			bomset->setProfileName(profileName);
			bomset->setReplicationOption(eReplicationOption);
			bomset->setDropOption(edropOption);
			bomset->setOdbcAttributes(odbcAttributes);
			bomset->setUpdateInterval(updateInterval);
			bomset->setCommitInterval(commitInterval);
			bomset->process(1);
		} break;
		case Rctables::enumTRDREC:
		{
			QScopedPointer<TRDREC> trdrec(new TRDREC(nullptr));
			trdrec->open(sourceDSN, targetDSN);
			trdrec->setRepositoryString(envyRepositoryString);
			trdrec->setProfileName(profileName);
			trdrec->setReplicationOption(eReplicationOption);
			trdrec->setDropOption(edropOption);
			trdrec->setOdbcAttributes(odbcAttributes);
			trdrec->setUpdateInterval(updateInterval);
			trdrec->setCommitInterval(commitInterval);
			trdrec->process(1);
		} break;
		case Rctables::enumRTGTWUSET:
		{
			QScopedPointer<RTGTWUSET> rtgtwuset(new RTGTWUSET(nullptr));
			rtgtwuset->open(sourceDSN, targetDSN);
			rtgtwuset->setRepositoryString(envyRepositoryString);
			rtgtwuset->setProfileName(profileName);
			rtgtwuset->setReplicationOption(eReplicationOption);
			rtgtwuset->setDropOption(edropOption);
			rtgtwuset->setOdbcAttributes(odbcAttributes);
			rtgtwuset->setUpdateInterval(updateInterval);
			rtgtwuset->setCommitInterval(commitInterval);
			rtgtwuset->process(1);
		} break;
		case Rctables::enumMA_PARTHSHSET:
		{
			QScopedPointer<MA_PARTHSHSET> ma_parthshset(new MA_PARTHSHSET(nullptr));
			ma_parthshset->open(sourceDSN, targetDSN);
			ma_parthshset->setRepositoryString(envyRepositoryString);
			ma_parthshset->setProfileName(profileName);
			ma_parthshset->setReplicationOption(eReplicationOption);
			ma_parthshset->setDropOption(edropOption);
			ma_parthshset->setOdbcAttributes(odbcAttributes);
			ma_parthshset->setUpdateInterval(updateInterval);
			ma_parthshset->setCommitInterval(commitInterval);
			ma_parthshset->process(1);
		} break;
		case Rctables::enumPOHPRNTSET:
		{
			QScopedPointer<POHPRNTSET> pohprntset(new POHPRNTSET(nullptr));
			pohprntset->open(sourceDSN, targetDSN);
			pohprntset->setRepositoryString(envyRepositoryString);
			pohprntset->setProfileName(profileName);
			pohprntset->setReplicationOption(eReplicationOption);
			pohprntset->setDropOption(edropOption);
			pohprntset->setOdbcAttributes(odbcAttributes);
			pohprntset->setUpdateInterval(updateInterval);
			pohprntset->setCommitInterval(commitInterval);
			pohprntset->process(1);
		} break;
		case Rctables::enumMA_SHPSREC:
		{
			QScopedPointer<MA_SHPSREC> ma_shpsrec(new MA_SHPSREC(nullptr));
			ma_shpsrec->open(sourceDSN, targetDSN);
			ma_shpsrec->setRepositoryString(envyRepositoryString);
			ma_shpsrec->setProfileName(profileName);
			ma_shpsrec->setReplicationOption(eReplicationOption);
			ma_shpsrec->setDropOption(edropOption);
			ma_shpsrec->setOdbcAttributes(odbcAttributes);
			ma_shpsrec->setUpdateInterval(updateInterval);
			ma_shpsrec->setCommitInterval(commitInterval);
			ma_shpsrec->process(1);
		} break;
		case Rctables::enumMA_STGREC:
		{
			QScopedPointer<MA_STGREC> ma_stgrec(new MA_STGREC(nullptr));
			ma_stgrec->open(sourceDSN, targetDSN);
			ma_stgrec->setRepositoryString(envyRepositoryString);
			ma_stgrec->setProfileName(profileName);
			ma_stgrec->setReplicationOption(eReplicationOption);
			ma_stgrec->setDropOption(edropOption);
			ma_stgrec->setOdbcAttributes(odbcAttributes);
			ma_stgrec->setUpdateInterval(updateInterval);
			ma_stgrec->setCommitInterval(commitInterval);
			ma_stgrec->process(1);
		} break;
		case Rctables::enumMRLHSHSET:
		{
			QScopedPointer<MRLHSHSET> mrlhshset(new MRLHSHSET(nullptr));
			mrlhshset->open(sourceDSN, targetDSN);
			mrlhshset->setRepositoryString(envyRepositoryString);
			mrlhshset->setProfileName(profileName);
			mrlhshset->setReplicationOption(eReplicationOption);
			mrlhshset->setDropOption(edropOption);
			mrlhshset->setOdbcAttributes(odbcAttributes);
			mrlhshset->setUpdateInterval(updateInterval);
			mrlhshset->setCommitInterval(commitInterval);
			mrlhshset->process(1);
		} break;
		case Rctables::enumAP_PAYOR1099HSHSET:
		{
			QScopedPointer<AP_PAYOR1099HSHSET> ap_payor1099hshset(new AP_PAYOR1099HSHSET(nullptr));
			ap_payor1099hshset->open(sourceDSN, targetDSN);
			ap_payor1099hshset->setRepositoryString(envyRepositoryString);
			ap_payor1099hshset->setProfileName(profileName);
			ap_payor1099hshset->setReplicationOption(eReplicationOption);
			ap_payor1099hshset->setDropOption(edropOption);
			ap_payor1099hshset->setOdbcAttributes(odbcAttributes);
			ap_payor1099hshset->setUpdateInterval(updateInterval);
			ap_payor1099hshset->setCommitInterval(commitInterval);
			ap_payor1099hshset->process(1);
		} break;
		case Rctables::enumGL_FPBATSET:
		{
			QScopedPointer<GL_FPBATSET> gl_fpbatset(new GL_FPBATSET(nullptr));
			gl_fpbatset->open(sourceDSN, targetDSN);
			gl_fpbatset->setRepositoryString(envyRepositoryString);
			gl_fpbatset->setProfileName(profileName);
			gl_fpbatset->setReplicationOption(eReplicationOption);
			gl_fpbatset->setDropOption(edropOption);
			gl_fpbatset->setOdbcAttributes(odbcAttributes);
			gl_fpbatset->setUpdateInterval(updateInterval);
			gl_fpbatset->setCommitInterval(commitInterval);
			gl_fpbatset->process(1);
		} break;
		case Rctables::enumPRTCDLSET:
		{
			QScopedPointer<PRTCDLSET> prtcdlset(new PRTCDLSET(nullptr));
			prtcdlset->open(sourceDSN, targetDSN);
			prtcdlset->setRepositoryString(envyRepositoryString);
			prtcdlset->setProfileName(profileName);
			prtcdlset->setReplicationOption(eReplicationOption);
			prtcdlset->setDropOption(edropOption);
			prtcdlset->setOdbcAttributes(odbcAttributes);
			prtcdlset->setUpdateInterval(updateInterval);
			prtcdlset->setCommitInterval(commitInterval);
			prtcdlset->process(1);
		} break;
		case Rctables::enumMA_FRTTHSHSET:
		{
			QScopedPointer<MA_FRTTHSHSET> ma_frtthshset(new MA_FRTTHSHSET(nullptr));
			ma_frtthshset->open(sourceDSN, targetDSN);
			ma_frtthshset->setRepositoryString(envyRepositoryString);
			ma_frtthshset->setProfileName(profileName);
			ma_frtthshset->setReplicationOption(eReplicationOption);
			ma_frtthshset->setDropOption(edropOption);
			ma_frtthshset->setOdbcAttributes(odbcAttributes);
			ma_frtthshset->setUpdateInterval(updateInterval);
			ma_frtthshset->setCommitInterval(commitInterval);
			ma_frtthshset->process(1);
		} break;
		case Rctables::enumMA_CMHPRTSET:
		{
			QScopedPointer<MA_CMHPRTSET> ma_cmhprtset(new MA_CMHPRTSET(nullptr));
			ma_cmhprtset->open(sourceDSN, targetDSN);
			ma_cmhprtset->setRepositoryString(envyRepositoryString);
			ma_cmhprtset->setProfileName(profileName);
			ma_cmhprtset->setReplicationOption(eReplicationOption);
			ma_cmhprtset->setDropOption(edropOption);
			ma_cmhprtset->setOdbcAttributes(odbcAttributes);
			ma_cmhprtset->setUpdateInterval(updateInterval);
			ma_cmhprtset->setCommitInterval(commitInterval);
			ma_cmhprtset->process(1);
		} break;
		case Rctables::enumGL_BATCHREC:
		{
			QScopedPointer<GL_BATCHREC> gl_batchrec(new GL_BATCHREC(nullptr));
			gl_batchrec->open(sourceDSN, targetDSN);
			gl_batchrec->setRepositoryString(envyRepositoryString);
			gl_batchrec->setProfileName(profileName);
			gl_batchrec->setReplicationOption(eReplicationOption);
			gl_batchrec->setDropOption(edropOption);
			gl_batchrec->setOdbcAttributes(odbcAttributes);
			gl_batchrec->setUpdateInterval(updateInterval);
			gl_batchrec->setCommitInterval(commitInterval);
			gl_batchrec->process(1);
		} break;
		case Rctables::enumMA_POSTSPISET:
		{
			QScopedPointer<MA_POSTSPISET> ma_postspiset(new MA_POSTSPISET(nullptr));
			ma_postspiset->open(sourceDSN, targetDSN);
			ma_postspiset->setRepositoryString(envyRepositoryString);
			ma_postspiset->setProfileName(profileName);
			ma_postspiset->setReplicationOption(eReplicationOption);
			ma_postspiset->setDropOption(edropOption);
			ma_postspiset->setOdbcAttributes(odbcAttributes);
			ma_postspiset->setUpdateInterval(updateInterval);
			ma_postspiset->setCommitInterval(commitInterval);
			ma_postspiset->process(1);
		} break;
		case Rctables::enumMA_CPOSOHSET:
		{
			QScopedPointer<MA_CPOSOHSET> ma_cposohset(new MA_CPOSOHSET(nullptr));
			ma_cposohset->open(sourceDSN, targetDSN);
			ma_cposohset->setRepositoryString(envyRepositoryString);
			ma_cposohset->setProfileName(profileName);
			ma_cposohset->setReplicationOption(eReplicationOption);
			ma_cposohset->setDropOption(edropOption);
			ma_cposohset->setOdbcAttributes(odbcAttributes);
			ma_cposohset->setUpdateInterval(updateInterval);
			ma_cposohset->setCommitInterval(commitInterval);
			ma_cposohset->process(1);
		} break;
		case Rctables::enumMA_USRREC:
		{
			QScopedPointer<MA_USRREC> ma_usrrec(new MA_USRREC(nullptr));
			ma_usrrec->open(sourceDSN, targetDSN);
			ma_usrrec->setRepositoryString(envyRepositoryString);
			ma_usrrec->setProfileName(profileName);
			ma_usrrec->setReplicationOption(eReplicationOption);
			ma_usrrec->setDropOption(edropOption);
			ma_usrrec->setOdbcAttributes(odbcAttributes);
			ma_usrrec->setUpdateInterval(updateInterval);
			ma_usrrec->setCommitInterval(commitInterval);
			ma_usrrec->process(1);
		} break;
		case Rctables::enumMA_TXRTTXLSET:
		{
			QScopedPointer<MA_TXRTTXLSET> ma_txrttxlset(new MA_TXRTTXLSET(nullptr));
			ma_txrttxlset->open(sourceDSN, targetDSN);
			ma_txrttxlset->setRepositoryString(envyRepositoryString);
			ma_txrttxlset->setProfileName(profileName);
			ma_txrttxlset->setReplicationOption(eReplicationOption);
			ma_txrttxlset->setDropOption(edropOption);
			ma_txrttxlset->setOdbcAttributes(odbcAttributes);
			ma_txrttxlset->setUpdateInterval(updateInterval);
			ma_txrttxlset->setCommitInterval(commitInterval);
			ma_txrttxlset->process(1);
		} break;
		case Rctables::enumMA_QUODREC:
		{
			QScopedPointer<MA_QUODREC> ma_quodrec(new MA_QUODREC(nullptr));
			ma_quodrec->open(sourceDSN, targetDSN);
			ma_quodrec->setRepositoryString(envyRepositoryString);
			ma_quodrec->setProfileName(profileName);
			ma_quodrec->setReplicationOption(eReplicationOption);
			ma_quodrec->setDropOption(edropOption);
			ma_quodrec->setOdbcAttributes(odbcAttributes);
			ma_quodrec->setUpdateInterval(updateInterval);
			ma_quodrec->setCommitInterval(commitInterval);
			ma_quodrec->process(1);
		} break;
		case Rctables::enumWOHMSCSET:
		{
			QScopedPointer<WOHMSCSET> wohmscset(new WOHMSCSET(nullptr));
			wohmscset->open(sourceDSN, targetDSN);
			wohmscset->setRepositoryString(envyRepositoryString);
			wohmscset->setProfileName(profileName);
			wohmscset->setReplicationOption(eReplicationOption);
			wohmscset->setDropOption(edropOption);
			wohmscset->setOdbcAttributes(odbcAttributes);
			wohmscset->setUpdateInterval(updateInterval);
			wohmscset->setCommitInterval(commitInterval);
			wohmscset->process(1);
		} break;
		case Rctables::enumMA_CIAAPCSET:
		{
			QScopedPointer<MA_CIAAPCSET> ma_ciaapcset(new MA_CIAAPCSET(nullptr));
			ma_ciaapcset->open(sourceDSN, targetDSN);
			ma_ciaapcset->setRepositoryString(envyRepositoryString);
			ma_ciaapcset->setProfileName(profileName);
			ma_ciaapcset->setReplicationOption(eReplicationOption);
			ma_ciaapcset->setDropOption(edropOption);
			ma_ciaapcset->setOdbcAttributes(odbcAttributes);
			ma_ciaapcset->setUpdateInterval(updateInterval);
			ma_ciaapcset->setCommitInterval(commitInterval);
			ma_ciaapcset->process(1);
		} break;
		case Rctables::enumMA_BILCTHSHSET:
		{
			QScopedPointer<MA_BILCTHSHSET> ma_bilcthshset(new MA_BILCTHSHSET(nullptr));
			ma_bilcthshset->open(sourceDSN, targetDSN);
			ma_bilcthshset->setRepositoryString(envyRepositoryString);
			ma_bilcthshset->setProfileName(profileName);
			ma_bilcthshset->setReplicationOption(eReplicationOption);
			ma_bilcthshset->setDropOption(edropOption);
			ma_bilcthshset->setOdbcAttributes(odbcAttributes);
			ma_bilcthshset->setUpdateInterval(updateInterval);
			ma_bilcthshset->setCommitInterval(commitInterval);
			ma_bilcthshset->process(1);
		} break;
		case Rctables::enumMA_SPFHSHSET:
		{
			QScopedPointer<MA_SPFHSHSET> ma_spfhshset(new MA_SPFHSHSET(nullptr));
			ma_spfhshset->open(sourceDSN, targetDSN);
			ma_spfhshset->setRepositoryString(envyRepositoryString);
			ma_spfhshset->setProfileName(profileName);
			ma_spfhshset->setReplicationOption(eReplicationOption);
			ma_spfhshset->setDropOption(edropOption);
			ma_spfhshset->setOdbcAttributes(odbcAttributes);
			ma_spfhshset->setUpdateInterval(updateInterval);
			ma_spfhshset->setCommitInterval(commitInterval);
			ma_spfhshset->process(1);
		} break;
		case Rctables::enumMA_TXTREC:
		{
			QScopedPointer<MA_TXTREC> ma_txtrec(new MA_TXTREC(nullptr));
			ma_txtrec->open(sourceDSN, targetDSN);
			ma_txtrec->setRepositoryString(envyRepositoryString);
			ma_txtrec->setProfileName(profileName);
			ma_txtrec->setReplicationOption(eReplicationOption);
			ma_txtrec->setDropOption(edropOption);
			ma_txtrec->setOdbcAttributes(odbcAttributes);
			ma_txtrec->setUpdateInterval(updateInterval);
			ma_txtrec->setCommitInterval(commitInterval);
			ma_txtrec->process(1);
		} break;
		case Rctables::enumMA_CMHCMDMSET:
		{
			QScopedPointer<MA_CMHCMDMSET> ma_cmhcmdmset(new MA_CMHCMDMSET(nullptr));
			ma_cmhcmdmset->open(sourceDSN, targetDSN);
			ma_cmhcmdmset->setRepositoryString(envyRepositoryString);
			ma_cmhcmdmset->setProfileName(profileName);
			ma_cmhcmdmset->setReplicationOption(eReplicationOption);
			ma_cmhcmdmset->setDropOption(edropOption);
			ma_cmhcmdmset->setOdbcAttributes(odbcAttributes);
			ma_cmhcmdmset->setUpdateInterval(updateInterval);
			ma_cmhcmdmset->setCommitInterval(commitInterval);
			ma_cmhcmdmset->process(1);
		} break;
		case Rctables::enumMA_PRTSTGPSET:
		{
			QScopedPointer<MA_PRTSTGPSET> ma_prtstgpset(new MA_PRTSTGPSET(nullptr));
			ma_prtstgpset->open(sourceDSN, targetDSN);
			ma_prtstgpset->setRepositoryString(envyRepositoryString);
			ma_prtstgpset->setProfileName(profileName);
			ma_prtstgpset->setReplicationOption(eReplicationOption);
			ma_prtstgpset->setDropOption(edropOption);
			ma_prtstgpset->setOdbcAttributes(odbcAttributes);
			ma_prtstgpset->setUpdateInterval(updateInterval);
			ma_prtstgpset->setCommitInterval(commitInterval);
			ma_prtstgpset->process(1);
		} break;
		case Rctables::enumMA_BILSODSET:
		{
			QScopedPointer<MA_BILSODSET> ma_bilsodset(new MA_BILSODSET(nullptr));
			ma_bilsodset->open(sourceDSN, targetDSN);
			ma_bilsodset->setRepositoryString(envyRepositoryString);
			ma_bilsodset->setProfileName(profileName);
			ma_bilsodset->setReplicationOption(eReplicationOption);
			ma_bilsodset->setDropOption(edropOption);
			ma_bilsodset->setOdbcAttributes(odbcAttributes);
			ma_bilsodset->setUpdateInterval(updateInterval);
			ma_bilsodset->setCommitInterval(commitInterval);
			ma_bilsodset->process(1);
		} break;
		case Rctables::enumAP_ACCTTYPESET:
		{
			QScopedPointer<AP_ACCTTYPESET> ap_accttypeset(new AP_ACCTTYPESET(nullptr));
			ap_accttypeset->open(sourceDSN, targetDSN);
			ap_accttypeset->setRepositoryString(envyRepositoryString);
			ap_accttypeset->setProfileName(profileName);
			ap_accttypeset->setReplicationOption(eReplicationOption);
			ap_accttypeset->setDropOption(edropOption);
			ap_accttypeset->setOdbcAttributes(odbcAttributes);
			ap_accttypeset->setUpdateInterval(updateInterval);
			ap_accttypeset->setCommitInterval(commitInterval);
			ap_accttypeset->process(1);
		} break;
		case Rctables::enumMA_SAMREC:
		{
			QScopedPointer<MA_SAMREC> ma_samrec(new MA_SAMREC(nullptr));
			ma_samrec->open(sourceDSN, targetDSN);
			ma_samrec->setRepositoryString(envyRepositoryString);
			ma_samrec->setProfileName(profileName);
			ma_samrec->setReplicationOption(eReplicationOption);
			ma_samrec->setDropOption(edropOption);
			ma_samrec->setOdbcAttributes(odbcAttributes);
			ma_samrec->setUpdateInterval(updateInterval);
			ma_samrec->setCommitInterval(commitInterval);
			ma_samrec->process(1);
		} break;
		case Rctables::enumDESREC:
		{
			QScopedPointer<DESREC> desrec(new DESREC(nullptr));
			desrec->open(sourceDSN, targetDSN);
			desrec->setRepositoryString(envyRepositoryString);
			desrec->setProfileName(profileName);
			desrec->setReplicationOption(eReplicationOption);
			desrec->setDropOption(edropOption);
			desrec->setOdbcAttributes(odbcAttributes);
			desrec->setUpdateInterval(updateInterval);
			desrec->setCommitInterval(commitInterval);
			desrec->process(1);
		} break;
		case Rctables::enumCOHCONSET:
		{
			QScopedPointer<COHCONSET> cohconset(new COHCONSET(nullptr));
			cohconset->open(sourceDSN, targetDSN);
			cohconset->setRepositoryString(envyRepositoryString);
			cohconset->setProfileName(profileName);
			cohconset->setReplicationOption(eReplicationOption);
			cohconset->setDropOption(edropOption);
			cohconset->setOdbcAttributes(odbcAttributes);
			cohconset->setUpdateInterval(updateInterval);
			cohconset->setCommitInterval(commitInterval);
			cohconset->process(1);
		} break;
		case Rctables::enumENDREC:
		{
			QScopedPointer<ENDREC> endrec(new ENDREC(nullptr));
			endrec->open(sourceDSN, targetDSN);
			endrec->setRepositoryString(envyRepositoryString);
			endrec->setProfileName(profileName);
			endrec->setReplicationOption(eReplicationOption);
			endrec->setDropOption(edropOption);
			endrec->setOdbcAttributes(odbcAttributes);
			endrec->setUpdateInterval(updateInterval);
			endrec->setCommitInterval(commitInterval);
			endrec->process(1);
		} break;
		case Rctables::enumWARHSHSET:
		{
			QScopedPointer<WARHSHSET> warhshset(new WARHSHSET(nullptr));
			warhshset->open(sourceDSN, targetDSN);
			warhshset->setRepositoryString(envyRepositoryString);
			warhshset->setProfileName(profileName);
			warhshset->setReplicationOption(eReplicationOption);
			warhshset->setDropOption(edropOption);
			warhshset->setOdbcAttributes(odbcAttributes);
			warhshset->setUpdateInterval(updateInterval);
			warhshset->setCommitInterval(commitInterval);
			warhshset->process(1);
		} break;
		case Rctables::enumMA_PNOTREC:
		{
			QScopedPointer<MA_PNOTREC> ma_pnotrec(new MA_PNOTREC(nullptr));
			ma_pnotrec->open(sourceDSN, targetDSN);
			ma_pnotrec->setRepositoryString(envyRepositoryString);
			ma_pnotrec->setProfileName(profileName);
			ma_pnotrec->setReplicationOption(eReplicationOption);
			ma_pnotrec->setDropOption(edropOption);
			ma_pnotrec->setOdbcAttributes(odbcAttributes);
			ma_pnotrec->setUpdateInterval(updateInterval);
			ma_pnotrec->setCommitInterval(commitInterval);
			ma_pnotrec->process(1);
		} break;
		case Rctables::enumWOHTRKSET:
		{
			QScopedPointer<WOHTRKSET> wohtrkset(new WOHTRKSET(nullptr));
			wohtrkset->open(sourceDSN, targetDSN);
			wohtrkset->setRepositoryString(envyRepositoryString);
			wohtrkset->setProfileName(profileName);
			wohtrkset->setReplicationOption(eReplicationOption);
			wohtrkset->setDropOption(edropOption);
			wohtrkset->setOdbcAttributes(odbcAttributes);
			wohtrkset->setUpdateInterval(updateInterval);
			wohtrkset->setCommitInterval(commitInterval);
			wohtrkset->process(1);
		} break;
		case Rctables::enumMA_SPNLREC:
		{
			QScopedPointer<MA_SPNLREC> ma_spnlrec(new MA_SPNLREC(nullptr));
			ma_spnlrec->open(sourceDSN, targetDSN);
			ma_spnlrec->setRepositoryString(envyRepositoryString);
			ma_spnlrec->setProfileName(profileName);
			ma_spnlrec->setReplicationOption(eReplicationOption);
			ma_spnlrec->setDropOption(edropOption);
			ma_spnlrec->setOdbcAttributes(odbcAttributes);
			ma_spnlrec->setUpdateInterval(updateInterval);
			ma_spnlrec->setCommitInterval(commitInterval);
			ma_spnlrec->process(1);
		} break;
		case Rctables::enumCRMTRSET:
		{
			QScopedPointer<CRMTRSET> crmtrset(new CRMTRSET(nullptr));
			crmtrset->open(sourceDSN, targetDSN);
			crmtrset->setRepositoryString(envyRepositoryString);
			crmtrset->setProfileName(profileName);
			crmtrset->setReplicationOption(eReplicationOption);
			crmtrset->setDropOption(edropOption);
			crmtrset->setOdbcAttributes(odbcAttributes);
			crmtrset->setUpdateInterval(updateInterval);
			crmtrset->setCommitInterval(commitInterval);
			crmtrset->process(1);
		} break;
		case Rctables::enumMA_CHGHCHGDSET:
		{
			QScopedPointer<MA_CHGHCHGDSET> ma_chghchgdset(new MA_CHGHCHGDSET(nullptr));
			ma_chghchgdset->open(sourceDSN, targetDSN);
			ma_chghchgdset->setRepositoryString(envyRepositoryString);
			ma_chghchgdset->setProfileName(profileName);
			ma_chghchgdset->setReplicationOption(eReplicationOption);
			ma_chghchgdset->setDropOption(edropOption);
			ma_chghchgdset->setOdbcAttributes(odbcAttributes);
			ma_chghchgdset->setUpdateInterval(updateInterval);
			ma_chghchgdset->setCommitInterval(commitInterval);
			ma_chghchgdset->process(1);
		} break;
		case Rctables::enumGL_ABUDHSHSET:
		{
			QScopedPointer<GL_ABUDHSHSET> gl_abudhshset(new GL_ABUDHSHSET(nullptr));
			gl_abudhshset->open(sourceDSN, targetDSN);
			gl_abudhshset->setRepositoryString(envyRepositoryString);
			gl_abudhshset->setProfileName(profileName);
			gl_abudhshset->setReplicationOption(eReplicationOption);
			gl_abudhshset->setDropOption(edropOption);
			gl_abudhshset->setOdbcAttributes(odbcAttributes);
			gl_abudhshset->setUpdateInterval(updateInterval);
			gl_abudhshset->setCommitInterval(commitInterval);
			gl_abudhshset->process(1);
		} break;
		case Rctables::enumDFAREC:
		{
			QScopedPointer<DFAREC> dfarec(new DFAREC(nullptr));
			dfarec->open(sourceDSN, targetDSN);
			dfarec->setRepositoryString(envyRepositoryString);
			dfarec->setProfileName(profileName);
			dfarec->setReplicationOption(eReplicationOption);
			dfarec->setDropOption(edropOption);
			dfarec->setOdbcAttributes(odbcAttributes);
			dfarec->setUpdateInterval(updateInterval);
			dfarec->setCommitInterval(commitInterval);
			dfarec->process(1);
		} break;
		case Rctables::enumPRTPUNSET:
		{
			QScopedPointer<PRTPUNSET> prtpunset(new PRTPUNSET(nullptr));
			prtpunset->open(sourceDSN, targetDSN);
			prtpunset->setRepositoryString(envyRepositoryString);
			prtpunset->setProfileName(profileName);
			prtpunset->setReplicationOption(eReplicationOption);
			prtpunset->setDropOption(edropOption);
			prtpunset->setOdbcAttributes(odbcAttributes);
			prtpunset->setUpdateInterval(updateInterval);
			prtpunset->setCommitInterval(commitInterval);
			prtpunset->process(1);
		} break;
		case Rctables::enumMA_SHDSHDPSET:
		{
			QScopedPointer<MA_SHDSHDPSET> ma_shdshdpset(new MA_SHDSHDPSET(nullptr));
			ma_shdshdpset->open(sourceDSN, targetDSN);
			ma_shdshdpset->setRepositoryString(envyRepositoryString);
			ma_shdshdpset->setProfileName(profileName);
			ma_shdshdpset->setReplicationOption(eReplicationOption);
			ma_shdshdpset->setDropOption(edropOption);
			ma_shdshdpset->setOdbcAttributes(odbcAttributes);
			ma_shdshdpset->setUpdateInterval(updateInterval);
			ma_shdshdpset->setCommitInterval(commitInterval);
			ma_shdshdpset->process(1);
		} break;
		case Rctables::enumEMPREC:
		{
			QScopedPointer<EMPREC> emprec(new EMPREC(nullptr));
			emprec->open(sourceDSN, targetDSN);
			emprec->setRepositoryString(envyRepositoryString);
			emprec->setProfileName(profileName);
			emprec->setReplicationOption(eReplicationOption);
			emprec->setDropOption(edropOption);
			emprec->setOdbcAttributes(odbcAttributes);
			emprec->setUpdateInterval(updateInterval);
			emprec->setCommitInterval(commitInterval);
			emprec->process(1);
		} break;
		case Rctables::enumED_PRDHSHSET:
		{
			QScopedPointer<ED_PRDHSHSET> ed_prdhshset(new ED_PRDHSHSET(nullptr));
			ed_prdhshset->open(sourceDSN, targetDSN);
			ed_prdhshset->setRepositoryString(envyRepositoryString);
			ed_prdhshset->setProfileName(profileName);
			ed_prdhshset->setReplicationOption(eReplicationOption);
			ed_prdhshset->setDropOption(edropOption);
			ed_prdhshset->setOdbcAttributes(odbcAttributes);
			ed_prdhshset->setUpdateInterval(updateInterval);
			ed_prdhshset->setCommitInterval(commitInterval);
			ed_prdhshset->process(1);
		} break;
		case Rctables::enumMISREFREC:
		{
			QScopedPointer<MISREFREC> misrefrec(new MISREFREC(nullptr));
			misrefrec->open(sourceDSN, targetDSN);
			misrefrec->setRepositoryString(envyRepositoryString);
			misrefrec->setProfileName(profileName);
			misrefrec->setReplicationOption(eReplicationOption);
			misrefrec->setDropOption(edropOption);
			misrefrec->setOdbcAttributes(odbcAttributes);
			misrefrec->setUpdateInterval(updateInterval);
			misrefrec->setCommitInterval(commitInterval);
			misrefrec->process(1);
		} break;
		case Rctables::enumLOCLOTSET:
		{
			QScopedPointer<LOCLOTSET> loclotset(new LOCLOTSET(nullptr));
			loclotset->open(sourceDSN, targetDSN);
			loclotset->setRepositoryString(envyRepositoryString);
			loclotset->setProfileName(profileName);
			loclotset->setReplicationOption(eReplicationOption);
			loclotset->setDropOption(edropOption);
			loclotset->setOdbcAttributes(odbcAttributes);
			loclotset->setUpdateInterval(updateInterval);
			loclotset->setCommitInterval(commitInterval);
			loclotset->process(1);
		} break;
		case Rctables::enumGL_ACCTFASET:
		{
			QScopedPointer<GL_ACCTFASET> gl_acctfaset(new GL_ACCTFASET(nullptr));
			gl_acctfaset->open(sourceDSN, targetDSN);
			gl_acctfaset->setRepositoryString(envyRepositoryString);
			gl_acctfaset->setProfileName(profileName);
			gl_acctfaset->setReplicationOption(eReplicationOption);
			gl_acctfaset->setDropOption(edropOption);
			gl_acctfaset->setOdbcAttributes(odbcAttributes);
			gl_acctfaset->setUpdateInterval(updateInterval);
			gl_acctfaset->setCommitInterval(commitInterval);
			gl_acctfaset->process(1);
		} break;
		case Rctables::enumPRTVMCSET:
		{
			QScopedPointer<PRTVMCSET> prtvmcset(new PRTVMCSET(nullptr));
			prtvmcset->open(sourceDSN, targetDSN);
			prtvmcset->setRepositoryString(envyRepositoryString);
			prtvmcset->setProfileName(profileName);
			prtvmcset->setReplicationOption(eReplicationOption);
			prtvmcset->setDropOption(edropOption);
			prtvmcset->setOdbcAttributes(odbcAttributes);
			prtvmcset->setUpdateInterval(updateInterval);
			prtvmcset->setCommitInterval(commitInterval);
			prtvmcset->process(1);
		} break;
		case Rctables::enumMA_USRHSHSET:
		{
			QScopedPointer<MA_USRHSHSET> ma_usrhshset(new MA_USRHSHSET(nullptr));
			ma_usrhshset->open(sourceDSN, targetDSN);
			ma_usrhshset->setRepositoryString(envyRepositoryString);
			ma_usrhshset->setProfileName(profileName);
			ma_usrhshset->setReplicationOption(eReplicationOption);
			ma_usrhshset->setDropOption(edropOption);
			ma_usrhshset->setOdbcAttributes(odbcAttributes);
			ma_usrhshset->setUpdateInterval(updateInterval);
			ma_usrhshset->setCommitInterval(commitInterval);
			ma_usrhshset->process(1);
		} break;
		case Rctables::enumQOHREC:
		{
			QScopedPointer<QOHREC> qohrec(new QOHREC(nullptr));
			qohrec->open(sourceDSN, targetDSN);
			qohrec->setRepositoryString(envyRepositoryString);
			qohrec->setProfileName(profileName);
			qohrec->setReplicationOption(eReplicationOption);
			qohrec->setDropOption(edropOption);
			qohrec->setOdbcAttributes(odbcAttributes);
			qohrec->setUpdateInterval(updateInterval);
			qohrec->setCommitInterval(commitInterval);
			qohrec->process(1);
		} break;
		case Rctables::enumAP_RECPAYVCHSET:
		{
			QScopedPointer<AP_RECPAYVCHSET> ap_recpayvchset(new AP_RECPAYVCHSET(nullptr));
			ap_recpayvchset->open(sourceDSN, targetDSN);
			ap_recpayvchset->setRepositoryString(envyRepositoryString);
			ap_recpayvchset->setProfileName(profileName);
			ap_recpayvchset->setReplicationOption(eReplicationOption);
			ap_recpayvchset->setDropOption(edropOption);
			ap_recpayvchset->setOdbcAttributes(odbcAttributes);
			ap_recpayvchset->setUpdateInterval(updateInterval);
			ap_recpayvchset->setCommitInterval(commitInterval);
			ap_recpayvchset->process(1);
		} break;
		case Rctables::enumGL_DLLINKSET:
		{
			QScopedPointer<GL_DLLINKSET> gl_dllinkset(new GL_DLLINKSET(nullptr));
			gl_dllinkset->open(sourceDSN, targetDSN);
			gl_dllinkset->setRepositoryString(envyRepositoryString);
			gl_dllinkset->setProfileName(profileName);
			gl_dllinkset->setReplicationOption(eReplicationOption);
			gl_dllinkset->setDropOption(edropOption);
			gl_dllinkset->setOdbcAttributes(odbcAttributes);
			gl_dllinkset->setUpdateInterval(updateInterval);
			gl_dllinkset->setCommitInterval(commitInterval);
			gl_dllinkset->process(1);
		} break;
		case Rctables::enumMA_SVINHREC:
		{
			QScopedPointer<MA_SVINHREC> ma_svinhrec(new MA_SVINHREC(nullptr));
			ma_svinhrec->open(sourceDSN, targetDSN);
			ma_svinhrec->setRepositoryString(envyRepositoryString);
			ma_svinhrec->setProfileName(profileName);
			ma_svinhrec->setReplicationOption(eReplicationOption);
			ma_svinhrec->setDropOption(edropOption);
			ma_svinhrec->setOdbcAttributes(odbcAttributes);
			ma_svinhrec->setUpdateInterval(updateInterval);
			ma_svinhrec->setCommitInterval(commitInterval);
			ma_svinhrec->process(1);
		} break;
		case Rctables::enumMA_INHCOMCSET:
		{
			QScopedPointer<MA_INHCOMCSET> ma_inhcomcset(new MA_INHCOMCSET(nullptr));
			ma_inhcomcset->open(sourceDSN, targetDSN);
			ma_inhcomcset->setRepositoryString(envyRepositoryString);
			ma_inhcomcset->setProfileName(profileName);
			ma_inhcomcset->setReplicationOption(eReplicationOption);
			ma_inhcomcset->setDropOption(edropOption);
			ma_inhcomcset->setOdbcAttributes(odbcAttributes);
			ma_inhcomcset->setUpdateInterval(updateInterval);
			ma_inhcomcset->setCommitInterval(commitInterval);
			ma_inhcomcset->process(1);
		} break;
		case Rctables::enumINDFREC:
		{
			QScopedPointer<INDFREC> indfrec(new INDFREC(nullptr));
			indfrec->open(sourceDSN, targetDSN);
			indfrec->setRepositoryString(envyRepositoryString);
			indfrec->setProfileName(profileName);
			indfrec->setReplicationOption(eReplicationOption);
			indfrec->setDropOption(edropOption);
			indfrec->setOdbcAttributes(odbcAttributes);
			indfrec->setUpdateInterval(updateInterval);
			indfrec->setCommitInterval(commitInterval);
			indfrec->process(1);
		} break;
		case Rctables::enumPODPOMSET:
		{
			QScopedPointer<PODPOMSET> podpomset(new PODPOMSET(nullptr));
			podpomset->open(sourceDSN, targetDSN);
			podpomset->setRepositoryString(envyRepositoryString);
			podpomset->setProfileName(profileName);
			podpomset->setReplicationOption(eReplicationOption);
			podpomset->setDropOption(edropOption);
			podpomset->setOdbcAttributes(odbcAttributes);
			podpomset->setUpdateInterval(updateInterval);
			podpomset->setCommitInterval(commitInterval);
			podpomset->process(1);
		} break;
		case Rctables::enumGL_TRREC:
		{
			QScopedPointer<GL_TRREC> gl_trrec(new GL_TRREC(nullptr));
			gl_trrec->open(sourceDSN, targetDSN);
			gl_trrec->setRepositoryString(envyRepositoryString);
			gl_trrec->setProfileName(profileName);
			gl_trrec->setReplicationOption(eReplicationOption);
			gl_trrec->setDropOption(edropOption);
			gl_trrec->setOdbcAttributes(odbcAttributes);
			gl_trrec->setUpdateInterval(updateInterval);
			gl_trrec->setCommitInterval(commitInterval);
			gl_trrec->process(1);
		} break;
		case Rctables::enumMA_PRODREC:
		{
			QScopedPointer<MA_PRODREC> ma_prodrec(new MA_PRODREC(nullptr));
			ma_prodrec->open(sourceDSN, targetDSN);
			ma_prodrec->setRepositoryString(envyRepositoryString);
			ma_prodrec->setProfileName(profileName);
			ma_prodrec->setReplicationOption(eReplicationOption);
			ma_prodrec->setDropOption(edropOption);
			ma_prodrec->setOdbcAttributes(odbcAttributes);
			ma_prodrec->setUpdateInterval(updateInterval);
			ma_prodrec->setCommitInterval(commitInterval);
			ma_prodrec->process(1);
		} break;
		case Rctables::enumMA_ACCTRETSET:
		{
			QScopedPointer<MA_ACCTRETSET> ma_acctretset(new MA_ACCTRETSET(nullptr));
			ma_acctretset->open(sourceDSN, targetDSN);
			ma_acctretset->setRepositoryString(envyRepositoryString);
			ma_acctretset->setProfileName(profileName);
			ma_acctretset->setReplicationOption(eReplicationOption);
			ma_acctretset->setDropOption(edropOption);
			ma_acctretset->setOdbcAttributes(odbcAttributes);
			ma_acctretset->setUpdateInterval(updateInterval);
			ma_acctretset->setCommitInterval(commitInterval);
			ma_acctretset->process(1);
		} break;
		case Rctables::enumAP_PNOTVCHREC:
		{
			QScopedPointer<AP_PNOTVCHREC> ap_pnotvchrec(new AP_PNOTVCHREC(nullptr));
			ap_pnotvchrec->open(sourceDSN, targetDSN);
			ap_pnotvchrec->setRepositoryString(envyRepositoryString);
			ap_pnotvchrec->setProfileName(profileName);
			ap_pnotvchrec->setReplicationOption(eReplicationOption);
			ap_pnotvchrec->setDropOption(edropOption);
			ap_pnotvchrec->setOdbcAttributes(odbcAttributes);
			ap_pnotvchrec->setUpdateInterval(updateInterval);
			ap_pnotvchrec->setCommitInterval(commitInterval);
			ap_pnotvchrec->process(1);
		} break;
		case Rctables::enumSODFAMSET:
		{
			QScopedPointer<SODFAMSET> sodfamset(new SODFAMSET(nullptr));
			sodfamset->open(sourceDSN, targetDSN);
			sodfamset->setRepositoryString(envyRepositoryString);
			sodfamset->setProfileName(profileName);
			sodfamset->setReplicationOption(eReplicationOption);
			sodfamset->setDropOption(edropOption);
			sodfamset->setOdbcAttributes(odbcAttributes);
			sodfamset->setUpdateInterval(updateInterval);
			sodfamset->setCommitInterval(commitInterval);
			sodfamset->process(1);
		} break;
		case Rctables::enumAP_VTPSTREC:
		{
			QScopedPointer<AP_VTPSTREC> ap_vtpstrec(new AP_VTPSTREC(nullptr));
			ap_vtpstrec->open(sourceDSN, targetDSN);
			ap_vtpstrec->setRepositoryString(envyRepositoryString);
			ap_vtpstrec->setProfileName(profileName);
			ap_vtpstrec->setReplicationOption(eReplicationOption);
			ap_vtpstrec->setDropOption(edropOption);
			ap_vtpstrec->setOdbcAttributes(odbcAttributes);
			ap_vtpstrec->setUpdateInterval(updateInterval);
			ap_vtpstrec->setCommitInterval(commitInterval);
			ap_vtpstrec->process(1);
		} break;
		case Rctables::enumSOHHSHSET:
		{
			QScopedPointer<SOHHSHSET> sohhshset(new SOHHSHSET(nullptr));
			sohhshset->open(sourceDSN, targetDSN);
			sohhshset->setRepositoryString(envyRepositoryString);
			sohhshset->setProfileName(profileName);
			sohhshset->setReplicationOption(eReplicationOption);
			sohhshset->setDropOption(edropOption);
			sohhshset->setOdbcAttributes(odbcAttributes);
			sohhshset->setUpdateInterval(updateInterval);
			sohhshset->setCommitInterval(commitInterval);
			sohhshset->process(1);
		} break;
		case Rctables::enumPRDREC:
		{
			QScopedPointer<PRDREC> prdrec(new PRDREC(nullptr));
			prdrec->open(sourceDSN, targetDSN);
			prdrec->setRepositoryString(envyRepositoryString);
			prdrec->setProfileName(profileName);
			prdrec->setReplicationOption(eReplicationOption);
			prdrec->setDropOption(edropOption);
			prdrec->setOdbcAttributes(odbcAttributes);
			prdrec->setUpdateInterval(updateInterval);
			prdrec->setCommitInterval(commitInterval);
			prdrec->process(1);
		} break;
		case Rctables::enumGL_RE_DREC:
		{
			QScopedPointer<GL_RE_DREC> gl_re_drec(new GL_RE_DREC(nullptr));
			gl_re_drec->open(sourceDSN, targetDSN);
			gl_re_drec->setRepositoryString(envyRepositoryString);
			gl_re_drec->setProfileName(profileName);
			gl_re_drec->setReplicationOption(eReplicationOption);
			gl_re_drec->setDropOption(edropOption);
			gl_re_drec->setOdbcAttributes(odbcAttributes);
			gl_re_drec->setUpdateInterval(updateInterval);
			gl_re_drec->setCommitInterval(commitInterval);
			gl_re_drec->process(1);
		} break;
		case Rctables::enumFLGHSHSET:
		{
			QScopedPointer<FLGHSHSET> flghshset(new FLGHSHSET(nullptr));
			flghshset->open(sourceDSN, targetDSN);
			flghshset->setRepositoryString(envyRepositoryString);
			flghshset->setProfileName(profileName);
			flghshset->setReplicationOption(eReplicationOption);
			flghshset->setDropOption(edropOption);
			flghshset->setOdbcAttributes(odbcAttributes);
			flghshset->setUpdateInterval(updateInterval);
			flghshset->setCommitInterval(commitInterval);
			flghshset->process(1);
		} break;
		case Rctables::enumGL_ACCTRPTSET:
		{
			QScopedPointer<GL_ACCTRPTSET> gl_acctrptset(new GL_ACCTRPTSET(nullptr));
			gl_acctrptset->open(sourceDSN, targetDSN);
			gl_acctrptset->setRepositoryString(envyRepositoryString);
			gl_acctrptset->setProfileName(profileName);
			gl_acctrptset->setReplicationOption(eReplicationOption);
			gl_acctrptset->setDropOption(edropOption);
			gl_acctrptset->setOdbcAttributes(odbcAttributes);
			gl_acctrptset->setUpdateInterval(updateInterval);
			gl_acctrptset->setCommitInterval(commitInterval);
			gl_acctrptset->process(1);
		} break;
		case Rctables::enumMA_CPOINHSET:
		{
			QScopedPointer<MA_CPOINHSET> ma_cpoinhset(new MA_CPOINHSET(nullptr));
			ma_cpoinhset->open(sourceDSN, targetDSN);
			ma_cpoinhset->setRepositoryString(envyRepositoryString);
			ma_cpoinhset->setProfileName(profileName);
			ma_cpoinhset->setReplicationOption(eReplicationOption);
			ma_cpoinhset->setDropOption(edropOption);
			ma_cpoinhset->setOdbcAttributes(odbcAttributes);
			ma_cpoinhset->setUpdateInterval(updateInterval);
			ma_cpoinhset->setCommitInterval(commitInterval);
			ma_cpoinhset->process(1);
		} break;
		case Rctables::enumMA_TXRTREC:
		{
			QScopedPointer<MA_TXRTREC> ma_txrtrec(new MA_TXRTREC(nullptr));
			ma_txrtrec->open(sourceDSN, targetDSN);
			ma_txrtrec->setRepositoryString(envyRepositoryString);
			ma_txrtrec->setProfileName(profileName);
			ma_txrtrec->setReplicationOption(eReplicationOption);
			ma_txrtrec->setDropOption(edropOption);
			ma_txrtrec->setOdbcAttributes(odbcAttributes);
			ma_txrtrec->setUpdateInterval(updateInterval);
			ma_txrtrec->setCommitInterval(commitInterval);
			ma_txrtrec->process(1);
		} break;
		case Rctables::enumMA_CMHSPISET:
		{
			QScopedPointer<MA_CMHSPISET> ma_cmhspiset(new MA_CMHSPISET(nullptr));
			ma_cmhspiset->open(sourceDSN, targetDSN);
			ma_cmhspiset->setRepositoryString(envyRepositoryString);
			ma_cmhspiset->setProfileName(profileName);
			ma_cmhspiset->setReplicationOption(eReplicationOption);
			ma_cmhspiset->setDropOption(edropOption);
			ma_cmhspiset->setOdbcAttributes(odbcAttributes);
			ma_cmhspiset->setUpdateInterval(updateInterval);
			ma_cmhspiset->setCommitInterval(commitInterval);
			ma_cmhspiset->process(1);
		} break;
		case Rctables::enumMA_TXTXLSET:
		{
			QScopedPointer<MA_TXTXLSET> ma_txtxlset(new MA_TXTXLSET(nullptr));
			ma_txtxlset->open(sourceDSN, targetDSN);
			ma_txtxlset->setRepositoryString(envyRepositoryString);
			ma_txtxlset->setProfileName(profileName);
			ma_txtxlset->setReplicationOption(eReplicationOption);
			ma_txtxlset->setDropOption(edropOption);
			ma_txtxlset->setOdbcAttributes(odbcAttributes);
			ma_txtxlset->setUpdateInterval(updateInterval);
			ma_txtxlset->setCommitInterval(commitInterval);
			ma_txtxlset->process(1);
		} break;
		case Rctables::enumACTMCSET:
		{
			QScopedPointer<ACTMCSET> actmcset(new ACTMCSET(nullptr));
			actmcset->open(sourceDSN, targetDSN);
			actmcset->setRepositoryString(envyRepositoryString);
			actmcset->setProfileName(profileName);
			actmcset->setReplicationOption(eReplicationOption);
			actmcset->setDropOption(edropOption);
			actmcset->setOdbcAttributes(odbcAttributes);
			actmcset->setUpdateInterval(updateInterval);
			actmcset->setCommitInterval(commitInterval);
			actmcset->process(1);
		} break;
		case Rctables::enumMA_STERHSHSET:
		{
			QScopedPointer<MA_STERHSHSET> ma_sterhshset(new MA_STERHSHSET(nullptr));
			ma_sterhshset->open(sourceDSN, targetDSN);
			ma_sterhshset->setRepositoryString(envyRepositoryString);
			ma_sterhshset->setProfileName(profileName);
			ma_sterhshset->setReplicationOption(eReplicationOption);
			ma_sterhshset->setDropOption(edropOption);
			ma_sterhshset->setOdbcAttributes(odbcAttributes);
			ma_sterhshset->setUpdateInterval(updateInterval);
			ma_sterhshset->setCommitInterval(commitInterval);
			ma_sterhshset->process(1);
		} break;
		case Rctables::enumAP_PAYPLTREC:
		{
			QScopedPointer<AP_PAYPLTREC> ap_paypltrec(new AP_PAYPLTREC(nullptr));
			ap_paypltrec->open(sourceDSN, targetDSN);
			ap_paypltrec->setRepositoryString(envyRepositoryString);
			ap_paypltrec->setProfileName(profileName);
			ap_paypltrec->setReplicationOption(eReplicationOption);
			ap_paypltrec->setDropOption(edropOption);
			ap_paypltrec->setOdbcAttributes(odbcAttributes);
			ap_paypltrec->setUpdateInterval(updateInterval);
			ap_paypltrec->setCommitInterval(commitInterval);
			ap_paypltrec->process(1);
		} break;
		case Rctables::enumGL_PROJDESCSET:
		{
			QScopedPointer<GL_PROJDESCSET> gl_projdescset(new GL_PROJDESCSET(nullptr));
			gl_projdescset->open(sourceDSN, targetDSN);
			gl_projdescset->setRepositoryString(envyRepositoryString);
			gl_projdescset->setProfileName(profileName);
			gl_projdescset->setReplicationOption(eReplicationOption);
			gl_projdescset->setDropOption(edropOption);
			gl_projdescset->setOdbcAttributes(odbcAttributes);
			gl_projdescset->setUpdateInterval(updateInterval);
			gl_projdescset->setCommitInterval(commitInterval);
			gl_projdescset->process(1);
		} break;
		case Rctables::enumGL_REBATSET:
		{
			QScopedPointer<GL_REBATSET> gl_rebatset(new GL_REBATSET(nullptr));
			gl_rebatset->open(sourceDSN, targetDSN);
			gl_rebatset->setRepositoryString(envyRepositoryString);
			gl_rebatset->setProfileName(profileName);
			gl_rebatset->setReplicationOption(eReplicationOption);
			gl_rebatset->setDropOption(edropOption);
			gl_rebatset->setOdbcAttributes(odbcAttributes);
			gl_rebatset->setUpdateInterval(updateInterval);
			gl_rebatset->setCommitInterval(commitInterval);
			gl_rebatset->process(1);
		} break;
		case Rctables::enumAP_VCHVTPSTSET:
		{
			QScopedPointer<AP_VCHVTPSTSET> ap_vchvtpstset(new AP_VCHVTPSTSET(nullptr));
			ap_vchvtpstset->open(sourceDSN, targetDSN);
			ap_vchvtpstset->setRepositoryString(envyRepositoryString);
			ap_vchvtpstset->setProfileName(profileName);
			ap_vchvtpstset->setReplicationOption(eReplicationOption);
			ap_vchvtpstset->setDropOption(edropOption);
			ap_vchvtpstset->setOdbcAttributes(odbcAttributes);
			ap_vchvtpstset->setUpdateInterval(updateInterval);
			ap_vchvtpstset->setCommitInterval(commitInterval);
			ap_vchvtpstset->process(1);
		} break;
		case Rctables::enumPRTUSGSET:
		{
			QScopedPointer<PRTUSGSET> prtusgset(new PRTUSGSET(nullptr));
			prtusgset->open(sourceDSN, targetDSN);
			prtusgset->setRepositoryString(envyRepositoryString);
			prtusgset->setProfileName(profileName);
			prtusgset->setReplicationOption(eReplicationOption);
			prtusgset->setDropOption(edropOption);
			prtusgset->setOdbcAttributes(odbcAttributes);
			prtusgset->setUpdateInterval(updateInterval);
			prtusgset->setCommitInterval(commitInterval);
			prtusgset->process(1);
		} break;
		case Rctables::enumAUTHSHSET:
		{
			QScopedPointer<AUTHSHSET> authshset(new AUTHSHSET(nullptr));
			authshset->open(sourceDSN, targetDSN);
			authshset->setRepositoryString(envyRepositoryString);
			authshset->setProfileName(profileName);
			authshset->setReplicationOption(eReplicationOption);
			authshset->setDropOption(edropOption);
			authshset->setOdbcAttributes(odbcAttributes);
			authshset->setUpdateInterval(updateInterval);
			authshset->setCommitInterval(commitInterval);
			authshset->process(1);
		} break;
		case Rctables::enumWIPMBOSET:
		{
			QScopedPointer<WIPMBOSET> wipmboset(new WIPMBOSET(nullptr));
			wipmboset->open(sourceDSN, targetDSN);
			wipmboset->setRepositoryString(envyRepositoryString);
			wipmboset->setProfileName(profileName);
			wipmboset->setReplicationOption(eReplicationOption);
			wipmboset->setDropOption(edropOption);
			wipmboset->setOdbcAttributes(odbcAttributes);
			wipmboset->setUpdateInterval(updateInterval);
			wipmboset->setCommitInterval(commitInterval);
			wipmboset->process(1);
		} break;
		case Rctables::enumGL_TRHSHSET:
		{
			QScopedPointer<GL_TRHSHSET> gl_trhshset(new GL_TRHSHSET(nullptr));
			gl_trhshset->open(sourceDSN, targetDSN);
			gl_trhshset->setRepositoryString(envyRepositoryString);
			gl_trhshset->setProfileName(profileName);
			gl_trhshset->setReplicationOption(eReplicationOption);
			gl_trhshset->setDropOption(edropOption);
			gl_trhshset->setOdbcAttributes(odbcAttributes);
			gl_trhshset->setUpdateInterval(updateInterval);
			gl_trhshset->setCommitInterval(commitInterval);
			gl_trhshset->process(1);
		} break;
		case Rctables::enumMA_INHVDPOSTSET:
		{
			QScopedPointer<MA_INHVDPOSTSET> ma_inhvdpostset(new MA_INHVDPOSTSET(nullptr));
			ma_inhvdpostset->open(sourceDSN, targetDSN);
			ma_inhvdpostset->setRepositoryString(envyRepositoryString);
			ma_inhvdpostset->setProfileName(profileName);
			ma_inhvdpostset->setReplicationOption(eReplicationOption);
			ma_inhvdpostset->setDropOption(edropOption);
			ma_inhvdpostset->setOdbcAttributes(odbcAttributes);
			ma_inhvdpostset->setUpdateInterval(updateInterval);
			ma_inhvdpostset->setCommitInterval(commitInterval);
			ma_inhvdpostset->process(1);
		} break;
		case Rctables::enumMA_DMHCMHSET:
		{
			QScopedPointer<MA_DMHCMHSET> ma_dmhcmhset(new MA_DMHCMHSET(nullptr));
			ma_dmhcmhset->open(sourceDSN, targetDSN);
			ma_dmhcmhset->setRepositoryString(envyRepositoryString);
			ma_dmhcmhset->setProfileName(profileName);
			ma_dmhcmhset->setReplicationOption(eReplicationOption);
			ma_dmhcmhset->setDropOption(edropOption);
			ma_dmhcmhset->setOdbcAttributes(odbcAttributes);
			ma_dmhcmhset->setUpdateInterval(updateInterval);
			ma_dmhcmhset->setCommitInterval(commitInterval);
			ma_dmhcmhset->process(1);
		} break;
		case Rctables::enumMA_STATEHSHSET:
		{
			QScopedPointer<MA_STATEHSHSET> ma_statehshset(new MA_STATEHSHSET(nullptr));
			ma_statehshset->open(sourceDSN, targetDSN);
			ma_statehshset->setRepositoryString(envyRepositoryString);
			ma_statehshset->setProfileName(profileName);
			ma_statehshset->setReplicationOption(eReplicationOption);
			ma_statehshset->setDropOption(edropOption);
			ma_statehshset->setOdbcAttributes(odbcAttributes);
			ma_statehshset->setUpdateInterval(updateInterval);
			ma_statehshset->setCommitInterval(commitInterval);
			ma_statehshset->process(1);
		} break;
		case Rctables::enumVMCREC:
		{
			QScopedPointer<VMCREC> vmcrec(new VMCREC(nullptr));
			vmcrec->open(sourceDSN, targetDSN);
			vmcrec->setRepositoryString(envyRepositoryString);
			vmcrec->setProfileName(profileName);
			vmcrec->setReplicationOption(eReplicationOption);
			vmcrec->setDropOption(edropOption);
			vmcrec->setOdbcAttributes(odbcAttributes);
			vmcrec->setUpdateInterval(updateInterval);
			vmcrec->setCommitInterval(commitInterval);
			vmcrec->process(1);
		} break;
		case Rctables::enumAP_PDCHKREC:
		{
			QScopedPointer<AP_PDCHKREC> ap_pdchkrec(new AP_PDCHKREC(nullptr));
			ap_pdchkrec->open(sourceDSN, targetDSN);
			ap_pdchkrec->setRepositoryString(envyRepositoryString);
			ap_pdchkrec->setProfileName(profileName);
			ap_pdchkrec->setReplicationOption(eReplicationOption);
			ap_pdchkrec->setDropOption(edropOption);
			ap_pdchkrec->setOdbcAttributes(odbcAttributes);
			ap_pdchkrec->setUpdateInterval(updateInterval);
			ap_pdchkrec->setCommitInterval(commitInterval);
			ap_pdchkrec->process(1);
		} break;
		case Rctables::enumGL_PRPTHSHSET:
		{
			QScopedPointer<GL_PRPTHSHSET> gl_prpthshset(new GL_PRPTHSHSET(nullptr));
			gl_prpthshset->open(sourceDSN, targetDSN);
			gl_prpthshset->setRepositoryString(envyRepositoryString);
			gl_prpthshset->setProfileName(profileName);
			gl_prpthshset->setReplicationOption(eReplicationOption);
			gl_prpthshset->setDropOption(edropOption);
			gl_prpthshset->setOdbcAttributes(odbcAttributes);
			gl_prpthshset->setUpdateInterval(updateInterval);
			gl_prpthshset->setCommitInterval(commitInterval);
			gl_prpthshset->process(1);
		} break;
		case Rctables::enumAPPREC:
		{
			QScopedPointer<APPREC> apprec(new APPREC(nullptr));
			apprec->open(sourceDSN, targetDSN);
			apprec->setRepositoryString(envyRepositoryString);
			apprec->setProfileName(profileName);
			apprec->setReplicationOption(eReplicationOption);
			apprec->setDropOption(edropOption);
			apprec->setOdbcAttributes(odbcAttributes);
			apprec->setUpdateInterval(updateInterval);
			apprec->setCommitInterval(commitInterval);
			apprec->process(1);
		} break;
		case Rctables::enumAP_VCHCHKSET:
		{
			QScopedPointer<AP_VCHCHKSET> ap_vchchkset(new AP_VCHCHKSET(nullptr));
			ap_vchchkset->open(sourceDSN, targetDSN);
			ap_vchchkset->setRepositoryString(envyRepositoryString);
			ap_vchchkset->setProfileName(profileName);
			ap_vchchkset->setReplicationOption(eReplicationOption);
			ap_vchchkset->setDropOption(edropOption);
			ap_vchchkset->setOdbcAttributes(odbcAttributes);
			ap_vchchkset->setUpdateInterval(updateInterval);
			ap_vchchkset->setCommitInterval(commitInterval);
			ap_vchchkset->process(1);
		} break;
		case Rctables::enumRCTNOHSHSET:
		{
			QScopedPointer<RCTNOHSHSET> rctnohshset(new RCTNOHSHSET(nullptr));
			rctnohshset->open(sourceDSN, targetDSN);
			rctnohshset->setRepositoryString(envyRepositoryString);
			rctnohshset->setProfileName(profileName);
			rctnohshset->setReplicationOption(eReplicationOption);
			rctnohshset->setDropOption(edropOption);
			rctnohshset->setOdbcAttributes(odbcAttributes);
			rctnohshset->setUpdateInterval(updateInterval);
			rctnohshset->setCommitInterval(commitInterval);
			rctnohshset->process(1);
		} break;
		case Rctables::enumGL_VPNUM_DREC:
		{
			QScopedPointer<GL_VPNUM_DREC> gl_vpnum_drec(new GL_VPNUM_DREC(nullptr));
			gl_vpnum_drec->open(sourceDSN, targetDSN);
			gl_vpnum_drec->setRepositoryString(envyRepositoryString);
			gl_vpnum_drec->setProfileName(profileName);
			gl_vpnum_drec->setReplicationOption(eReplicationOption);
			gl_vpnum_drec->setDropOption(edropOption);
			gl_vpnum_drec->setOdbcAttributes(odbcAttributes);
			gl_vpnum_drec->setUpdateInterval(updateInterval);
			gl_vpnum_drec->setCommitInterval(commitInterval);
			gl_vpnum_drec->process(1);
		} break;
		case Rctables::enumMA_PNOTPNOTINVSET:
		{
			QScopedPointer<MA_PNOTPNOTINVSET> ma_pnotpnotinvset(new MA_PNOTPNOTINVSET(nullptr));
			ma_pnotpnotinvset->open(sourceDSN, targetDSN);
			ma_pnotpnotinvset->setRepositoryString(envyRepositoryString);
			ma_pnotpnotinvset->setProfileName(profileName);
			ma_pnotpnotinvset->setReplicationOption(eReplicationOption);
			ma_pnotpnotinvset->setDropOption(edropOption);
			ma_pnotpnotinvset->setOdbcAttributes(odbcAttributes);
			ma_pnotpnotinvset->setUpdateInterval(updateInterval);
			ma_pnotpnotinvset->setCommitInterval(commitInterval);
			ma_pnotpnotinvset->process(1);
		} break;
		case Rctables::enumPOHCPRSET:
		{
			QScopedPointer<POHCPRSET> pohcprset(new POHCPRSET(nullptr));
			pohcprset->open(sourceDSN, targetDSN);
			pohcprset->setRepositoryString(envyRepositoryString);
			pohcprset->setProfileName(profileName);
			pohcprset->setReplicationOption(eReplicationOption);
			pohcprset->setDropOption(edropOption);
			pohcprset->setOdbcAttributes(odbcAttributes);
			pohcprset->setUpdateInterval(updateInterval);
			pohcprset->setCommitInterval(commitInterval);
			pohcprset->process(1);
		} break;
		case Rctables::enumAP_VCHNOTSET:
		{
			QScopedPointer<AP_VCHNOTSET> ap_vchnotset(new AP_VCHNOTSET(nullptr));
			ap_vchnotset->open(sourceDSN, targetDSN);
			ap_vchnotset->setRepositoryString(envyRepositoryString);
			ap_vchnotset->setProfileName(profileName);
			ap_vchnotset->setReplicationOption(eReplicationOption);
			ap_vchnotset->setDropOption(edropOption);
			ap_vchnotset->setOdbcAttributes(odbcAttributes);
			ap_vchnotset->setUpdateInterval(updateInterval);
			ap_vchnotset->setCommitInterval(commitInterval);
			ap_vchnotset->process(1);
		} break;
		case Rctables::enumWIPBYPSET:
		{
			QScopedPointer<WIPBYPSET> wipbypset(new WIPBYPSET(nullptr));
			wipbypset->open(sourceDSN, targetDSN);
			wipbypset->setRepositoryString(envyRepositoryString);
			wipbypset->setProfileName(profileName);
			wipbypset->setReplicationOption(eReplicationOption);
			wipbypset->setDropOption(edropOption);
			wipbypset->setOdbcAttributes(odbcAttributes);
			wipbypset->setUpdateInterval(updateInterval);
			wipbypset->setCommitInterval(commitInterval);
			wipbypset->process(1);
		} break;
		case Rctables::enumMA_HLDREC:
		{
			QScopedPointer<MA_HLDREC> ma_hldrec(new MA_HLDREC(nullptr));
			ma_hldrec->open(sourceDSN, targetDSN);
			ma_hldrec->setRepositoryString(envyRepositoryString);
			ma_hldrec->setProfileName(profileName);
			ma_hldrec->setReplicationOption(eReplicationOption);
			ma_hldrec->setDropOption(edropOption);
			ma_hldrec->setOdbcAttributes(odbcAttributes);
			ma_hldrec->setUpdateInterval(updateInterval);
			ma_hldrec->setCommitInterval(commitInterval);
			ma_hldrec->process(1);
		} break;
		case Rctables::enumAP_VNDPLTSET:
		{
			QScopedPointer<AP_VNDPLTSET> ap_vndpltset(new AP_VNDPLTSET(nullptr));
			ap_vndpltset->open(sourceDSN, targetDSN);
			ap_vndpltset->setRepositoryString(envyRepositoryString);
			ap_vndpltset->setProfileName(profileName);
			ap_vndpltset->setReplicationOption(eReplicationOption);
			ap_vndpltset->setDropOption(edropOption);
			ap_vndpltset->setOdbcAttributes(odbcAttributes);
			ap_vndpltset->setUpdateInterval(updateInterval);
			ap_vndpltset->setCommitInterval(commitInterval);
			ap_vndpltset->process(1);
		} break;
		case Rctables::enumPRTMRPSET:
		{
			QScopedPointer<PRTMRPSET> prtmrpset(new PRTMRPSET(nullptr));
			prtmrpset->open(sourceDSN, targetDSN);
			prtmrpset->setRepositoryString(envyRepositoryString);
			prtmrpset->setProfileName(profileName);
			prtmrpset->setReplicationOption(eReplicationOption);
			prtmrpset->setDropOption(edropOption);
			prtmrpset->setOdbcAttributes(odbcAttributes);
			prtmrpset->setUpdateInterval(updateInterval);
			prtmrpset->setCommitInterval(commitInterval);
			prtmrpset->process(1);
		} break;
		case Rctables::enumGL_ABUDNUMSET:
		{
			QScopedPointer<GL_ABUDNUMSET> gl_abudnumset(new GL_ABUDNUMSET(nullptr));
			gl_abudnumset->open(sourceDSN, targetDSN);
			gl_abudnumset->setRepositoryString(envyRepositoryString);
			gl_abudnumset->setProfileName(profileName);
			gl_abudnumset->setReplicationOption(eReplicationOption);
			gl_abudnumset->setDropOption(edropOption);
			gl_abudnumset->setOdbcAttributes(odbcAttributes);
			gl_abudnumset->setUpdateInterval(updateInterval);
			gl_abudnumset->setCommitInterval(commitInterval);
			gl_abudnumset->process(1);
		} break;
		case Rctables::enumENGENCSET:
		{
			QScopedPointer<ENGENCSET> engencset(new ENGENCSET(nullptr));
			engencset->open(sourceDSN, targetDSN);
			engencset->setRepositoryString(envyRepositoryString);
			engencset->setProfileName(profileName);
			engencset->setReplicationOption(eReplicationOption);
			engencset->setDropOption(edropOption);
			engencset->setOdbcAttributes(odbcAttributes);
			engencset->setUpdateInterval(updateInterval);
			engencset->setCommitInterval(commitInterval);
			engencset->process(1);
		} break;
		case Rctables::enumPOHPOPSET:
		{
			QScopedPointer<POHPOPSET> pohpopset(new POHPOPSET(nullptr));
			pohpopset->open(sourceDSN, targetDSN);
			pohpopset->setRepositoryString(envyRepositoryString);
			pohpopset->setProfileName(profileName);
			pohpopset->setReplicationOption(eReplicationOption);
			pohpopset->setDropOption(edropOption);
			pohpopset->setOdbcAttributes(odbcAttributes);
			pohpopset->setUpdateInterval(updateInterval);
			pohpopset->setCommitInterval(commitInterval);
			pohpopset->process(1);
		} break;
		case Rctables::enumMA_CMDMSPISET:
		{
			QScopedPointer<MA_CMDMSPISET> ma_cmdmspiset(new MA_CMDMSPISET(nullptr));
			ma_cmdmspiset->open(sourceDSN, targetDSN);
			ma_cmdmspiset->setRepositoryString(envyRepositoryString);
			ma_cmdmspiset->setProfileName(profileName);
			ma_cmdmspiset->setReplicationOption(eReplicationOption);
			ma_cmdmspiset->setDropOption(edropOption);
			ma_cmdmspiset->setOdbcAttributes(odbcAttributes);
			ma_cmdmspiset->setUpdateInterval(updateInterval);
			ma_cmdmspiset->setCommitInterval(commitInterval);
			ma_cmdmspiset->process(1);
		} break;
		case Rctables::enumAP_BOLREC:
		{
			QScopedPointer<AP_BOLREC> ap_bolrec(new AP_BOLREC(nullptr));
			ap_bolrec->open(sourceDSN, targetDSN);
			ap_bolrec->setRepositoryString(envyRepositoryString);
			ap_bolrec->setProfileName(profileName);
			ap_bolrec->setReplicationOption(eReplicationOption);
			ap_bolrec->setDropOption(edropOption);
			ap_bolrec->setOdbcAttributes(odbcAttributes);
			ap_bolrec->setUpdateInterval(updateInterval);
			ap_bolrec->setCommitInterval(commitInterval);
			ap_bolrec->process(1);
		} break;
		case Rctables::enumGL_VP_DREC:
		{
			QScopedPointer<GL_VP_DREC> gl_vp_drec(new GL_VP_DREC(nullptr));
			gl_vp_drec->open(sourceDSN, targetDSN);
			gl_vp_drec->setRepositoryString(envyRepositoryString);
			gl_vp_drec->setProfileName(profileName);
			gl_vp_drec->setReplicationOption(eReplicationOption);
			gl_vp_drec->setDropOption(edropOption);
			gl_vp_drec->setOdbcAttributes(odbcAttributes);
			gl_vp_drec->setUpdateInterval(updateInterval);
			gl_vp_drec->setCommitInterval(commitInterval);
			gl_vp_drec->process(1);
		} break;
		case Rctables::enumGL_PROJFASET:
		{
			QScopedPointer<GL_PROJFASET> gl_projfaset(new GL_PROJFASET(nullptr));
			gl_projfaset->open(sourceDSN, targetDSN);
			gl_projfaset->setRepositoryString(envyRepositoryString);
			gl_projfaset->setProfileName(profileName);
			gl_projfaset->setReplicationOption(eReplicationOption);
			gl_projfaset->setDropOption(edropOption);
			gl_projfaset->setOdbcAttributes(odbcAttributes);
			gl_projfaset->setUpdateInterval(updateInterval);
			gl_projfaset->setCommitInterval(commitInterval);
			gl_projfaset->process(1);
		} break;
		case Rctables::enumACTVOSET:
		{
			QScopedPointer<ACTVOSET> actvoset(new ACTVOSET(nullptr));
			actvoset->open(sourceDSN, targetDSN);
			actvoset->setRepositoryString(envyRepositoryString);
			actvoset->setProfileName(profileName);
			actvoset->setReplicationOption(eReplicationOption);
			actvoset->setDropOption(edropOption);
			actvoset->setOdbcAttributes(odbcAttributes);
			actvoset->setUpdateInterval(updateInterval);
			actvoset->setCommitInterval(commitInterval);
			actvoset->process(1);
		} break;
		case Rctables::enumMA_SODCHGDSET:
		{
			QScopedPointer<MA_SODCHGDSET> ma_sodchgdset(new MA_SODCHGDSET(nullptr));
			ma_sodchgdset->open(sourceDSN, targetDSN);
			ma_sodchgdset->setRepositoryString(envyRepositoryString);
			ma_sodchgdset->setProfileName(profileName);
			ma_sodchgdset->setReplicationOption(eReplicationOption);
			ma_sodchgdset->setDropOption(edropOption);
			ma_sodchgdset->setOdbcAttributes(odbcAttributes);
			ma_sodchgdset->setUpdateInterval(updateInterval);
			ma_sodchgdset->setCommitInterval(commitInterval);
			ma_sodchgdset->process(1);
		} break;
		case Rctables::enumINTSET:
		{
			QScopedPointer<INTSET> intset(new INTSET(nullptr));
			intset->open(sourceDSN, targetDSN);
			intset->setRepositoryString(envyRepositoryString);
			intset->setProfileName(profileName);
			intset->setReplicationOption(eReplicationOption);
			intset->setDropOption(edropOption);
			intset->setOdbcAttributes(odbcAttributes);
			intset->setUpdateInterval(updateInterval);
			intset->setCommitInterval(commitInterval);
			intset->process(1);
		} break;
		case Rctables::enumMA_SHHSPISET:
		{
			QScopedPointer<MA_SHHSPISET> ma_shhspiset(new MA_SHHSPISET(nullptr));
			ma_shhspiset->open(sourceDSN, targetDSN);
			ma_shhspiset->setRepositoryString(envyRepositoryString);
			ma_shhspiset->setProfileName(profileName);
			ma_shhspiset->setReplicationOption(eReplicationOption);
			ma_shhspiset->setDropOption(edropOption);
			ma_shhspiset->setOdbcAttributes(odbcAttributes);
			ma_shhspiset->setUpdateInterval(updateInterval);
			ma_shhspiset->setCommitInterval(commitInterval);
			ma_shhspiset->process(1);
		} break;
		case Rctables::enumMA_FCPRTABHSHSET:
		{
			QScopedPointer<MA_FCPRTABHSHSET> ma_fcprtabhshset(new MA_FCPRTABHSHSET(nullptr));
			ma_fcprtabhshset->open(sourceDSN, targetDSN);
			ma_fcprtabhshset->setRepositoryString(envyRepositoryString);
			ma_fcprtabhshset->setProfileName(profileName);
			ma_fcprtabhshset->setReplicationOption(eReplicationOption);
			ma_fcprtabhshset->setDropOption(edropOption);
			ma_fcprtabhshset->setOdbcAttributes(odbcAttributes);
			ma_fcprtabhshset->setUpdateInterval(updateInterval);
			ma_fcprtabhshset->setCommitInterval(commitInterval);
			ma_fcprtabhshset->process(1);
		} break;
		case Rctables::enumMA_INDMSPNLSET:
		{
			QScopedPointer<MA_INDMSPNLSET> ma_indmspnlset(new MA_INDMSPNLSET(nullptr));
			ma_indmspnlset->open(sourceDSN, targetDSN);
			ma_indmspnlset->setRepositoryString(envyRepositoryString);
			ma_indmspnlset->setProfileName(profileName);
			ma_indmspnlset->setReplicationOption(eReplicationOption);
			ma_indmspnlset->setDropOption(edropOption);
			ma_indmspnlset->setOdbcAttributes(odbcAttributes);
			ma_indmspnlset->setUpdateInterval(updateInterval);
			ma_indmspnlset->setCommitInterval(commitInterval);
			ma_indmspnlset->process(1);
		} break;
		case Rctables::enumWARQOHSET:
		{
			QScopedPointer<WARQOHSET> warqohset(new WARQOHSET(nullptr));
			warqohset->open(sourceDSN, targetDSN);
			warqohset->setRepositoryString(envyRepositoryString);
			warqohset->setProfileName(profileName);
			warqohset->setReplicationOption(eReplicationOption);
			warqohset->setDropOption(edropOption);
			warqohset->setOdbcAttributes(odbcAttributes);
			warqohset->setUpdateInterval(updateInterval);
			warqohset->setCommitInterval(commitInterval);
			warqohset->process(1);
		} break;
		case Rctables::enumPRHAPPSET:
		{
			QScopedPointer<PRHAPPSET> prhappset(new PRHAPPSET(nullptr));
			prhappset->open(sourceDSN, targetDSN);
			prhappset->setRepositoryString(envyRepositoryString);
			prhappset->setProfileName(profileName);
			prhappset->setReplicationOption(eReplicationOption);
			prhappset->setDropOption(edropOption);
			prhappset->setOdbcAttributes(odbcAttributes);
			prhappset->setUpdateInterval(updateInterval);
			prhappset->setCommitInterval(commitInterval);
			prhappset->process(1);
		} break;
		case Rctables::enumAP_VCHDMSET:
		{
			QScopedPointer<AP_VCHDMSET> ap_vchdmset(new AP_VCHDMSET(nullptr));
			ap_vchdmset->open(sourceDSN, targetDSN);
			ap_vchdmset->setRepositoryString(envyRepositoryString);
			ap_vchdmset->setProfileName(profileName);
			ap_vchdmset->setReplicationOption(eReplicationOption);
			ap_vchdmset->setDropOption(edropOption);
			ap_vchdmset->setOdbcAttributes(odbcAttributes);
			ap_vchdmset->setUpdateInterval(updateInterval);
			ap_vchdmset->setCommitInterval(commitInterval);
			ap_vchdmset->process(1);
		} break;
		case Rctables::enumGL_VP_NREC:
		{
			QScopedPointer<GL_VP_NREC> gl_vp_nrec(new GL_VP_NREC(nullptr));
			gl_vp_nrec->open(sourceDSN, targetDSN);
			gl_vp_nrec->setRepositoryString(envyRepositoryString);
			gl_vp_nrec->setProfileName(profileName);
			gl_vp_nrec->setReplicationOption(eReplicationOption);
			gl_vp_nrec->setDropOption(edropOption);
			gl_vp_nrec->setOdbcAttributes(odbcAttributes);
			gl_vp_nrec->setUpdateInterval(updateInterval);
			gl_vp_nrec->setCommitInterval(commitInterval);
			gl_vp_nrec->process(1);
		} break;
		case Rctables::enumMA_SVINDSPISET:
		{
			QScopedPointer<MA_SVINDSPISET> ma_svindspiset(new MA_SVINDSPISET(nullptr));
			ma_svindspiset->open(sourceDSN, targetDSN);
			ma_svindspiset->setRepositoryString(envyRepositoryString);
			ma_svindspiset->setProfileName(profileName);
			ma_svindspiset->setReplicationOption(eReplicationOption);
			ma_svindspiset->setDropOption(edropOption);
			ma_svindspiset->setOdbcAttributes(odbcAttributes);
			ma_svindspiset->setUpdateInterval(updateInterval);
			ma_svindspiset->setCommitInterval(commitInterval);
			ma_svindspiset->process(1);
		} break;
		case Rctables::enumPRTRTGSET:
		{
			QScopedPointer<PRTRTGSET> prtrtgset(new PRTRTGSET(nullptr));
			prtrtgset->open(sourceDSN, targetDSN);
			prtrtgset->setRepositoryString(envyRepositoryString);
			prtrtgset->setProfileName(profileName);
			prtrtgset->setReplicationOption(eReplicationOption);
			prtrtgset->setDropOption(edropOption);
			prtrtgset->setOdbcAttributes(odbcAttributes);
			prtrtgset->setUpdateInterval(updateInterval);
			prtrtgset->setCommitInterval(commitInterval);
			prtrtgset->process(1);
		} break;
		case Rctables::enumPRHHSHSET:
		{
			QScopedPointer<PRHHSHSET> prhhshset(new PRHHSHSET(nullptr));
			prhhshset->open(sourceDSN, targetDSN);
			prhhshset->setRepositoryString(envyRepositoryString);
			prhhshset->setProfileName(profileName);
			prhhshset->setReplicationOption(eReplicationOption);
			prhhshset->setDropOption(edropOption);
			prhhshset->setOdbcAttributes(odbcAttributes);
			prhhshset->setUpdateInterval(updateInterval);
			prhhshset->setCommitInterval(commitInterval);
			prhhshset->process(1);
		} break;
		case Rctables::enumAP_RECPAYREC:
		{
			QScopedPointer<AP_RECPAYREC> ap_recpayrec(new AP_RECPAYREC(nullptr));
			ap_recpayrec->open(sourceDSN, targetDSN);
			ap_recpayrec->setRepositoryString(envyRepositoryString);
			ap_recpayrec->setProfileName(profileName);
			ap_recpayrec->setReplicationOption(eReplicationOption);
			ap_recpayrec->setDropOption(edropOption);
			ap_recpayrec->setOdbcAttributes(odbcAttributes);
			ap_recpayrec->setUpdateInterval(updateInterval);
			ap_recpayrec->setCommitInterval(commitInterval);
			ap_recpayrec->process(1);
		} break;
		case Rctables::enumMA_SHHPRTSET:
		{
			QScopedPointer<MA_SHHPRTSET> ma_shhprtset(new MA_SHHPRTSET(nullptr));
			ma_shhprtset->open(sourceDSN, targetDSN);
			ma_shhprtset->setRepositoryString(envyRepositoryString);
			ma_shhprtset->setProfileName(profileName);
			ma_shhprtset->setReplicationOption(eReplicationOption);
			ma_shhprtset->setDropOption(edropOption);
			ma_shhprtset->setOdbcAttributes(odbcAttributes);
			ma_shhprtset->setUpdateInterval(updateInterval);
			ma_shhprtset->setCommitInterval(commitInterval);
			ma_shhprtset->process(1);
		} break;
		case Rctables::enumPRTENDSET:
		{
			QScopedPointer<PRTENDSET> prtendset(new PRTENDSET(nullptr));
			prtendset->open(sourceDSN, targetDSN);
			prtendset->setRepositoryString(envyRepositoryString);
			prtendset->setProfileName(profileName);
			prtendset->setReplicationOption(eReplicationOption);
			prtendset->setDropOption(edropOption);
			prtendset->setOdbcAttributes(odbcAttributes);
			prtendset->setUpdateInterval(updateInterval);
			prtendset->setCommitInterval(commitInterval);
			prtendset->process(1);
		} break;
		case Rctables::enumMA_SOHREC:
		{
			QScopedPointer<MA_SOHREC> ma_sohrec(new MA_SOHREC(nullptr));
			ma_sohrec->open(sourceDSN, targetDSN);
			ma_sohrec->setRepositoryString(envyRepositoryString);
			ma_sohrec->setProfileName(profileName);
			ma_sohrec->setReplicationOption(eReplicationOption);
			ma_sohrec->setDropOption(edropOption);
			ma_sohrec->setOdbcAttributes(odbcAttributes);
			ma_sohrec->setUpdateInterval(updateInterval);
			ma_sohrec->setCommitInterval(commitInterval);
			ma_sohrec->process(1);
		} break;
		case Rctables::enumED_DOCXRFREC:
		{
			QScopedPointer<ED_DOCXRFREC> ed_docxrfrec(new ED_DOCXRFREC(nullptr));
			ed_docxrfrec->open(sourceDSN, targetDSN);
			ed_docxrfrec->setRepositoryString(envyRepositoryString);
			ed_docxrfrec->setProfileName(profileName);
			ed_docxrfrec->setReplicationOption(eReplicationOption);
			ed_docxrfrec->setDropOption(edropOption);
			ed_docxrfrec->setOdbcAttributes(odbcAttributes);
			ed_docxrfrec->setUpdateInterval(updateInterval);
			ed_docxrfrec->setCommitInterval(commitInterval);
			ed_docxrfrec->process(1);
		} break;
		case Rctables::enumMA_SHHSPNLSET:
		{
			QScopedPointer<MA_SHHSPNLSET> ma_shhspnlset(new MA_SHHSPNLSET(nullptr));
			ma_shhspnlset->open(sourceDSN, targetDSN);
			ma_shhspnlset->setRepositoryString(envyRepositoryString);
			ma_shhspnlset->setProfileName(profileName);
			ma_shhspnlset->setReplicationOption(eReplicationOption);
			ma_shhspnlset->setDropOption(edropOption);
			ma_shhspnlset->setOdbcAttributes(odbcAttributes);
			ma_shhspnlset->setUpdateInterval(updateInterval);
			ma_shhspnlset->setCommitInterval(commitInterval);
			ma_shhspnlset->process(1);
		} break;
		case Rctables::enumCONREC:
		{
			QScopedPointer<CONREC> conrec(new CONREC(nullptr));
			conrec->open(sourceDSN, targetDSN);
			conrec->setRepositoryString(envyRepositoryString);
			conrec->setProfileName(profileName);
			conrec->setReplicationOption(eReplicationOption);
			conrec->setDropOption(edropOption);
			conrec->setOdbcAttributes(odbcAttributes);
			conrec->setUpdateInterval(updateInterval);
			conrec->setCommitInterval(commitInterval);
			conrec->process(1);
		} break;
		case Rctables::enumGL_ABUDNUMREC:
		{
			QScopedPointer<GL_ABUDNUMREC> gl_abudnumrec(new GL_ABUDNUMREC(nullptr));
			gl_abudnumrec->open(sourceDSN, targetDSN);
			gl_abudnumrec->setRepositoryString(envyRepositoryString);
			gl_abudnumrec->setProfileName(profileName);
			gl_abudnumrec->setReplicationOption(eReplicationOption);
			gl_abudnumrec->setDropOption(edropOption);
			gl_abudnumrec->setOdbcAttributes(odbcAttributes);
			gl_abudnumrec->setUpdateInterval(updateInterval);
			gl_abudnumrec->setCommitInterval(commitInterval);
			gl_abudnumrec->process(1);
		} break;
		case Rctables::enumAP_CHKREC:
		{
			QScopedPointer<AP_CHKREC> ap_chkrec(new AP_CHKREC(nullptr));
			ap_chkrec->open(sourceDSN, targetDSN);
			ap_chkrec->setRepositoryString(envyRepositoryString);
			ap_chkrec->setProfileName(profileName);
			ap_chkrec->setReplicationOption(eReplicationOption);
			ap_chkrec->setDropOption(edropOption);
			ap_chkrec->setOdbcAttributes(odbcAttributes);
			ap_chkrec->setUpdateInterval(updateInterval);
			ap_chkrec->setCommitInterval(commitInterval);
			ap_chkrec->process(1);
		} break;
		case Rctables::enumTWUREC:
		{
			QScopedPointer<TWUREC> twurec(new TWUREC(nullptr));
			twurec->open(sourceDSN, targetDSN);
			twurec->setRepositoryString(envyRepositoryString);
			twurec->setProfileName(profileName);
			twurec->setReplicationOption(eReplicationOption);
			twurec->setDropOption(edropOption);
			twurec->setOdbcAttributes(odbcAttributes);
			twurec->setUpdateInterval(updateInterval);
			twurec->setCommitInterval(commitInterval);
			twurec->process(1);
		} break;
		case Rctables::enumMA_QUOHUPDSET:
		{
			QScopedPointer<MA_QUOHUPDSET> ma_quohupdset(new MA_QUOHUPDSET(nullptr));
			ma_quohupdset->open(sourceDSN, targetDSN);
			ma_quohupdset->setRepositoryString(envyRepositoryString);
			ma_quohupdset->setProfileName(profileName);
			ma_quohupdset->setReplicationOption(eReplicationOption);
			ma_quohupdset->setDropOption(edropOption);
			ma_quohupdset->setOdbcAttributes(odbcAttributes);
			ma_quohupdset->setUpdateInterval(updateInterval);
			ma_quohupdset->setCommitInterval(commitInterval);
			ma_quohupdset->process(1);
		} break;
		case Rctables::enumMA_CTERHSHSET:
		{
			QScopedPointer<MA_CTERHSHSET> ma_cterhshset(new MA_CTERHSHSET(nullptr));
			ma_cterhshset->open(sourceDSN, targetDSN);
			ma_cterhshset->setRepositoryString(envyRepositoryString);
			ma_cterhshset->setProfileName(profileName);
			ma_cterhshset->setReplicationOption(eReplicationOption);
			ma_cterhshset->setDropOption(edropOption);
			ma_cterhshset->setOdbcAttributes(odbcAttributes);
			ma_cterhshset->setUpdateInterval(updateInterval);
			ma_cterhshset->setCommitInterval(commitInterval);
			ma_cterhshset->process(1);
		} break;
		case Rctables::enumPODRCTSET:
		{
			QScopedPointer<PODRCTSET> podrctset(new PODRCTSET(nullptr));
			podrctset->open(sourceDSN, targetDSN);
			podrctset->setRepositoryString(envyRepositoryString);
			podrctset->setProfileName(profileName);
			podrctset->setReplicationOption(eReplicationOption);
			podrctset->setDropOption(edropOption);
			podrctset->setOdbcAttributes(odbcAttributes);
			podrctset->setUpdateInterval(updateInterval);
			podrctset->setCommitInterval(commitInterval);
			podrctset->process(1);
		} break;
		case Rctables::enumMA_CIAREC:
		{
			QScopedPointer<MA_CIAREC> ma_ciarec(new MA_CIAREC(nullptr));
			ma_ciarec->open(sourceDSN, targetDSN);
			ma_ciarec->setRepositoryString(envyRepositoryString);
			ma_ciarec->setProfileName(profileName);
			ma_ciarec->setReplicationOption(eReplicationOption);
			ma_ciarec->setDropOption(edropOption);
			ma_ciarec->setOdbcAttributes(odbcAttributes);
			ma_ciarec->setUpdateInterval(updateInterval);
			ma_ciarec->setCommitInterval(commitInterval);
			ma_ciarec->process(1);
		} break;
		case Rctables::enumGL_TRPOSTSET:
		{
			QScopedPointer<GL_TRPOSTSET> gl_trpostset(new GL_TRPOSTSET(nullptr));
			gl_trpostset->open(sourceDSN, targetDSN);
			gl_trpostset->setRepositoryString(envyRepositoryString);
			gl_trpostset->setProfileName(profileName);
			gl_trpostset->setReplicationOption(eReplicationOption);
			gl_trpostset->setDropOption(edropOption);
			gl_trpostset->setOdbcAttributes(odbcAttributes);
			gl_trpostset->setUpdateInterval(updateInterval);
			gl_trpostset->setCommitInterval(commitInterval);
			gl_trpostset->process(1);
		} break;
		case Rctables::enumMA_ACCTSALESET:
		{
			QScopedPointer<MA_ACCTSALESET> ma_acctsaleset(new MA_ACCTSALESET(nullptr));
			ma_acctsaleset->open(sourceDSN, targetDSN);
			ma_acctsaleset->setRepositoryString(envyRepositoryString);
			ma_acctsaleset->setProfileName(profileName);
			ma_acctsaleset->setReplicationOption(eReplicationOption);
			ma_acctsaleset->setDropOption(edropOption);
			ma_acctsaleset->setOdbcAttributes(odbcAttributes);
			ma_acctsaleset->setUpdateInterval(updateInterval);
			ma_acctsaleset->setCommitInterval(commitInterval);
			ma_acctsaleset->process(1);
		} break;
		case Rctables::enumMA_PROJPOSTSET:
		{
			QScopedPointer<MA_PROJPOSTSET> ma_projpostset(new MA_PROJPOSTSET(nullptr));
			ma_projpostset->open(sourceDSN, targetDSN);
			ma_projpostset->setRepositoryString(envyRepositoryString);
			ma_projpostset->setProfileName(profileName);
			ma_projpostset->setReplicationOption(eReplicationOption);
			ma_projpostset->setDropOption(edropOption);
			ma_projpostset->setOdbcAttributes(odbcAttributes);
			ma_projpostset->setUpdateInterval(updateInterval);
			ma_projpostset->setCommitInterval(commitInterval);
			ma_projpostset->process(1);
		} break;
		case Rctables::enumPRTWOHSET:
		{
			QScopedPointer<PRTWOHSET> prtwohset(new PRTWOHSET(nullptr));
			prtwohset->open(sourceDSN, targetDSN);
			prtwohset->setRepositoryString(envyRepositoryString);
			prtwohset->setProfileName(profileName);
			prtwohset->setReplicationOption(eReplicationOption);
			prtwohset->setDropOption(edropOption);
			prtwohset->setOdbcAttributes(odbcAttributes);
			prtwohset->setUpdateInterval(updateInterval);
			prtwohset->setCommitInterval(commitInterval);
			prtwohset->process(1);
		} break;
		case Rctables::enumMA_WARSTGSET:
		{
			QScopedPointer<MA_WARSTGSET> ma_warstgset(new MA_WARSTGSET(nullptr));
			ma_warstgset->open(sourceDSN, targetDSN);
			ma_warstgset->setRepositoryString(envyRepositoryString);
			ma_warstgset->setProfileName(profileName);
			ma_warstgset->setReplicationOption(eReplicationOption);
			ma_warstgset->setDropOption(edropOption);
			ma_warstgset->setOdbcAttributes(odbcAttributes);
			ma_warstgset->setUpdateInterval(updateInterval);
			ma_warstgset->setCommitInterval(commitInterval);
			ma_warstgset->process(1);
		} break;
		case Rctables::enumGL_POSTREC:
		{
			QScopedPointer<GL_POSTREC> gl_postrec(new GL_POSTREC(nullptr));
			gl_postrec->open(sourceDSN, targetDSN);
			gl_postrec->setRepositoryString(envyRepositoryString);
			gl_postrec->setProfileName(profileName);
			gl_postrec->setReplicationOption(eReplicationOption);
			gl_postrec->setDropOption(edropOption);
			gl_postrec->setOdbcAttributes(odbcAttributes);
			gl_postrec->setUpdateInterval(updateInterval);
			gl_postrec->setCommitInterval(commitInterval);
			gl_postrec->process(1);
		} break;
		case Rctables::enumAP_VCHBOLLSET:
		{
			QScopedPointer<AP_VCHBOLLSET> ap_vchbollset(new AP_VCHBOLLSET(nullptr));
			ap_vchbollset->open(sourceDSN, targetDSN);
			ap_vchbollset->setRepositoryString(envyRepositoryString);
			ap_vchbollset->setProfileName(profileName);
			ap_vchbollset->setReplicationOption(eReplicationOption);
			ap_vchbollset->setDropOption(edropOption);
			ap_vchbollset->setOdbcAttributes(odbcAttributes);
			ap_vchbollset->setUpdateInterval(updateInterval);
			ap_vchbollset->setCommitInterval(commitInterval);
			ap_vchbollset->process(1);
		} break;
		case Rctables::enumGL_JV_NREC:
		{
			QScopedPointer<GL_JV_NREC> gl_jv_nrec(new GL_JV_NREC(nullptr));
			gl_jv_nrec->open(sourceDSN, targetDSN);
			gl_jv_nrec->setRepositoryString(envyRepositoryString);
			gl_jv_nrec->setProfileName(profileName);
			gl_jv_nrec->setReplicationOption(eReplicationOption);
			gl_jv_nrec->setDropOption(edropOption);
			gl_jv_nrec->setOdbcAttributes(odbcAttributes);
			gl_jv_nrec->setUpdateInterval(updateInterval);
			gl_jv_nrec->setCommitInterval(commitInterval);
			gl_jv_nrec->process(1);
		} break;
		case Rctables::enumMA_PRCTBILSET:
		{
			QScopedPointer<MA_PRCTBILSET> ma_prctbilset(new MA_PRCTBILSET(nullptr));
			ma_prctbilset->open(sourceDSN, targetDSN);
			ma_prctbilset->setRepositoryString(envyRepositoryString);
			ma_prctbilset->setProfileName(profileName);
			ma_prctbilset->setReplicationOption(eReplicationOption);
			ma_prctbilset->setDropOption(edropOption);
			ma_prctbilset->setOdbcAttributes(odbcAttributes);
			ma_prctbilset->setUpdateInterval(updateInterval);
			ma_prctbilset->setCommitInterval(commitInterval);
			ma_prctbilset->process(1);
		} break;
		case Rctables::enumAP_ACCTSET:
		{
			QScopedPointer<AP_ACCTSET> ap_acctset(new AP_ACCTSET(nullptr));
			ap_acctset->open(sourceDSN, targetDSN);
			ap_acctset->setRepositoryString(envyRepositoryString);
			ap_acctset->setProfileName(profileName);
			ap_acctset->setReplicationOption(eReplicationOption);
			ap_acctset->setDropOption(edropOption);
			ap_acctset->setOdbcAttributes(odbcAttributes);
			ap_acctset->setUpdateInterval(updateInterval);
			ap_acctset->setCommitInterval(commitInterval);
			ap_acctset->process(1);
		} break;
		case Rctables::enumAP_PNOTPNOTVCHSET:
		{
			QScopedPointer<AP_PNOTPNOTVCHSET> ap_pnotpnotvchset(new AP_PNOTPNOTVCHSET(nullptr));
			ap_pnotpnotvchset->open(sourceDSN, targetDSN);
			ap_pnotpnotvchset->setRepositoryString(envyRepositoryString);
			ap_pnotpnotvchset->setProfileName(profileName);
			ap_pnotpnotvchset->setReplicationOption(eReplicationOption);
			ap_pnotpnotvchset->setDropOption(edropOption);
			ap_pnotpnotvchset->setOdbcAttributes(odbcAttributes);
			ap_pnotpnotvchset->setUpdateInterval(updateInterval);
			ap_pnotpnotvchset->setCommitInterval(commitInterval);
			ap_pnotpnotvchset->process(1);
		} break;
		case Rctables::enumVARREC:
		{
			QScopedPointer<VARREC> varrec(new VARREC(nullptr));
			varrec->open(sourceDSN, targetDSN);
			varrec->setRepositoryString(envyRepositoryString);
			varrec->setProfileName(profileName);
			varrec->setReplicationOption(eReplicationOption);
			varrec->setDropOption(edropOption);
			varrec->setOdbcAttributes(odbcAttributes);
			varrec->setUpdateInterval(updateInterval);
			varrec->setCommitInterval(commitInterval);
			varrec->process(1);
		} break;
		case Rctables::enumGL_FISCREC:
		{
			QScopedPointer<GL_FISCREC> gl_fiscrec(new GL_FISCREC(nullptr));
			gl_fiscrec->open(sourceDSN, targetDSN);
			gl_fiscrec->setRepositoryString(envyRepositoryString);
			gl_fiscrec->setProfileName(profileName);
			gl_fiscrec->setReplicationOption(eReplicationOption);
			gl_fiscrec->setDropOption(edropOption);
			gl_fiscrec->setOdbcAttributes(odbcAttributes);
			gl_fiscrec->setUpdateInterval(updateInterval);
			gl_fiscrec->setCommitInterval(commitInterval);
			gl_fiscrec->process(1);
		} break;
		case Rctables::enumFSCCALSET:
		{
			QScopedPointer<FSCCALSET> fsccalset(new FSCCALSET(nullptr));
			fsccalset->open(sourceDSN, targetDSN);
			fsccalset->setRepositoryString(envyRepositoryString);
			fsccalset->setProfileName(profileName);
			fsccalset->setReplicationOption(eReplicationOption);
			fsccalset->setDropOption(edropOption);
			fsccalset->setOdbcAttributes(odbcAttributes);
			fsccalset->setUpdateInterval(updateInterval);
			fsccalset->setCommitInterval(commitInterval);
			fsccalset->process(1);
		} break;
		case Rctables::enumMA_PRODCHGDSET:
		{
			QScopedPointer<MA_PRODCHGDSET> ma_prodchgdset(new MA_PRODCHGDSET(nullptr));
			ma_prodchgdset->open(sourceDSN, targetDSN);
			ma_prodchgdset->setRepositoryString(envyRepositoryString);
			ma_prodchgdset->setProfileName(profileName);
			ma_prodchgdset->setReplicationOption(eReplicationOption);
			ma_prodchgdset->setDropOption(edropOption);
			ma_prodchgdset->setOdbcAttributes(odbcAttributes);
			ma_prodchgdset->setUpdateInterval(updateInterval);
			ma_prodchgdset->setCommitInterval(commitInterval);
			ma_prodchgdset->process(1);
		} break;
		case Rctables::enumPOHPONSET:
		{
			QScopedPointer<POHPONSET> pohponset(new POHPONSET(nullptr));
			pohponset->open(sourceDSN, targetDSN);
			pohponset->setRepositoryString(envyRepositoryString);
			pohponset->setProfileName(profileName);
			pohponset->setReplicationOption(eReplicationOption);
			pohponset->setDropOption(edropOption);
			pohponset->setOdbcAttributes(odbcAttributes);
			pohponset->setUpdateInterval(updateInterval);
			pohponset->setCommitInterval(commitInterval);
			pohponset->process(1);
		} break;
		case Rctables::enumMA_TOPREC:
		{
			QScopedPointer<MA_TOPREC> ma_toprec(new MA_TOPREC(nullptr));
			ma_toprec->open(sourceDSN, targetDSN);
			ma_toprec->setRepositoryString(envyRepositoryString);
			ma_toprec->setProfileName(profileName);
			ma_toprec->setReplicationOption(eReplicationOption);
			ma_toprec->setDropOption(edropOption);
			ma_toprec->setOdbcAttributes(odbcAttributes);
			ma_toprec->setUpdateInterval(updateInterval);
			ma_toprec->setCommitInterval(commitInterval);
			ma_toprec->process(1);
		} break;
		case Rctables::enumMA_GLTABHSHSET:
		{
			QScopedPointer<MA_GLTABHSHSET> ma_gltabhshset(new MA_GLTABHSHSET(nullptr));
			ma_gltabhshset->open(sourceDSN, targetDSN);
			ma_gltabhshset->setRepositoryString(envyRepositoryString);
			ma_gltabhshset->setProfileName(profileName);
			ma_gltabhshset->setReplicationOption(eReplicationOption);
			ma_gltabhshset->setDropOption(edropOption);
			ma_gltabhshset->setOdbcAttributes(odbcAttributes);
			ma_gltabhshset->setUpdateInterval(updateInterval);
			ma_gltabhshset->setCommitInterval(commitInterval);
			ma_gltabhshset->process(1);
		} break;
		case Rctables::enumPAYREC:
		{
			QScopedPointer<PAYREC> payrec(new PAYREC(nullptr));
			payrec->open(sourceDSN, targetDSN);
			payrec->setRepositoryString(envyRepositoryString);
			payrec->setProfileName(profileName);
			payrec->setReplicationOption(eReplicationOption);
			payrec->setDropOption(edropOption);
			payrec->setOdbcAttributes(odbcAttributes);
			payrec->setUpdateInterval(updateInterval);
			payrec->setCommitInterval(commitInterval);
			payrec->process(1);
		} break;
		case Rctables::enumMA_SPNDREC:
		{
			QScopedPointer<MA_SPNDREC> ma_spndrec(new MA_SPNDREC(nullptr));
			ma_spndrec->open(sourceDSN, targetDSN);
			ma_spndrec->setRepositoryString(envyRepositoryString);
			ma_spndrec->setProfileName(profileName);
			ma_spndrec->setReplicationOption(eReplicationOption);
			ma_spndrec->setDropOption(edropOption);
			ma_spndrec->setOdbcAttributes(odbcAttributes);
			ma_spndrec->setUpdateInterval(updateInterval);
			ma_spndrec->setCommitInterval(commitInterval);
			ma_spndrec->process(1);
		} break;
		case Rctables::enumMA_REMHSHSET:
		{
			QScopedPointer<MA_REMHSHSET> ma_remhshset(new MA_REMHSHSET(nullptr));
			ma_remhshset->open(sourceDSN, targetDSN);
			ma_remhshset->setRepositoryString(envyRepositoryString);
			ma_remhshset->setProfileName(profileName);
			ma_remhshset->setReplicationOption(eReplicationOption);
			ma_remhshset->setDropOption(edropOption);
			ma_remhshset->setOdbcAttributes(odbcAttributes);
			ma_remhshset->setUpdateInterval(updateInterval);
			ma_remhshset->setCommitInterval(commitInterval);
			ma_remhshset->process(1);
		} break;
	}
#pragma endregion caselist
#endif caseList__h_MANDB100
