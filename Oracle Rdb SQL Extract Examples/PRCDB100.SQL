-- RMU/EXTRACT for Oracle Rdb V7.2-200                   11-OCT-2018 10:46:58.45
--
--                           Database Definition File
--
-- Source Database Name: DKA300:[ENVY.100]PRCDB.RDB;1
--------------------------------------------------------------------------------
set verify;
set language ENGLISH;
set default date format 'SQL92';
set quoting rules 'SQL92';
set date format DATE 001, TIME 001;

-- RMU/EXTRACT for Oracle Rdb V7.2-200                   11-OCT-2018 10:46:58.45
--
--                         Physical Database Definition
--
--------------------------------------------------------------------------------
create database
    filename 'DKA300:[ENVY.100]PRCDB.RDB'
    protection is ACL
    number of users 50
    number of cluster nodes 16 (multiple instance)
    buffer size is 6 blocks
    number of buffers 20
    number of recovery buffers 20
    adjustable lock granularity ENABLED (count is 3)
    global buffers are DISABLED
    carry over locks are ENABLED
    lock timeout interval is 0 seconds
    lock partitioning is DISABLED
    incremental backup scan optimization
    async prefetch is ENABLED (depth is 5)
    async batch writes are ENABLED
        (clean buffer count is 5,
         maximum buffer count is 4)
    detected async prefetch is ENABLED
        (depth is 4 buffers,
         threshold is 4 buffers)
    open is AUTOMATIC
    recovery journal
        (no location, 
         buffer memory is GLOBAL)
    row cache is DISABLED
        (no location, 
         checkpoint updated rows to backing file)
    shared memory is PROCESS
    metadata changes are ENABLED
    workload collection is DISABLED
    cardinality collection is ENABLED
    set transaction modes (all)
    prestarted transactions are ON
    notify is DISABLED
    statistics collection is ENABLED
    system index
        (prefix cardinality collection is ENABLED,
         compression is ENABLED)
    restricted access
    reserve 100 storage areas
    reserve 1 journal
    reserve 1 cache slot
    reserve 32 sequences
    security checking is EXTERNAL
    snapshot is ENABLED IMMEDIATE
    
    segmented string storage area is RDB$SYSTEM
    default storage area is RDB$SYSTEM
    
    create storage area RDB$SYSTEM
        filename 'NV$DISK:[ENVY.100]PRCDB.RDA'
        -- read write storage area
        locking is row level
        page format is UNIFORM
        page size is 2 blocks
        allocation is 207009 pages
        extent is (minimum 1998, maximum 19998, percent growth 20)
        snapshot filename 'NV$DISK:[ENVY.100]PRCDB.SNP'
        snapshot allocation is 1232 pages
        snapshot extent is (minimum 99, maximum 9999, percent growth 20)
    
    create storage area PCFRMAREA
        filename 'NV$DISK:[ENVY.100]NV_PCFRMAREA.RDA'
        -- read write storage area
        locking is row level
        page format is UNIFORM
        page size is 2 blocks
        allocation is 17271 pages
        extent is (minimum 1998, maximum 19998, percent growth 20)
        snapshot filename 'NV$DISK:[ENVY.100]NV_PCFRMAREA.SNP'
        snapshot allocation is 100 pages
        snapshot extent is (minimum 99, maximum 9999, percent growth 20)
    
    create storage area PCFCOAREA
        filename 'NV$DISK:[ENVY.100]NV_PCFCOAREA.RDA'
        -- read write storage area
        locking is row level
        page format is UNIFORM
        page size is 2 blocks
        allocation is 2001 pages
        extent is (minimum 1998, maximum 19998, percent growth 20)
        snapshot filename 'NV$DISK:[ENVY.100]NV_PCFCOAREA.SNP'
        snapshot allocation is 100 pages
        snapshot extent is (minimum 99, maximum 9999, percent growth 20)
    
    create storage area PCPIAREA
        filename 'NV$DISK:[ENVY.100]NV_PCPIAREA.RDA'
        -- read write storage area
        locking is row level
        page format is UNIFORM
        page size is 2 blocks
        allocation is 35817 pages
        extent is (minimum 1998, maximum 19998, percent growth 20)
        snapshot filename 'NV$DISK:[ENVY.100]NV_PCPIAREA.SNP'
        snapshot allocation is 100 pages
        snapshot extent is (minimum 99, maximum 9999, percent growth 20)
    
    create storage area PCMBOAREA
        filename 'NV$DISK:[ENVY.100]NV_PCMBOAREA.RDA'
        -- read write storage area
        locking is row level
        page format is UNIFORM
        page size is 2 blocks
        allocation is 106959 pages
        extent is (minimum 1998, maximum 19998, percent growth 20)
        snapshot filename 'NV$DISK:[ENVY.100]NV_PCMBOAREA.SNP'
        snapshot allocation is 100 pages
        snapshot extent is (minimum 99, maximum 9999, percent growth 20)
    
    create storage area PCTEXAREA
        filename 'NV$DISK:[ENVY.100]NV_PCTEXAREA.RDA'
        -- read write storage area
        locking is row level
        page format is UNIFORM
        page size is 2 blocks
        allocation is 206949 pages
        extent is (minimum 1998, maximum 19998, percent growth 20)
        snapshot filename 'NV$DISK:[ENVY.100]NV_PCTEXAREA.SNP'
        snapshot allocation is 100 pages
        snapshot extent is (minimum 99, maximum 9999, percent growth 20)
    
    create storage area PCCHGAREA
        filename 'NV$DISK:[ENVY.100]NV_PCCHGAREA.RDA'
        -- read write storage area
        locking is row level
        page format is UNIFORM
        page size is 2 blocks
        allocation is 35817 pages
        extent is (minimum 1998, maximum 19998, percent growth 20)
        snapshot filename 'NV$DISK:[ENVY.100]NV_PCCHGAREA.SNP'
        snapshot allocation is 100 pages
        snapshot extent is (minimum 99, maximum 9999, percent growth 20)
    
    create storage area PCWOHAREA
        filename 'NV$DISK:[ENVY.100]NV_PCWOHAREA.RDA'
        -- read write storage area
        locking is row level
        page format is UNIFORM
        page size is 2 blocks
        allocation is 24873 pages
        extent is (minimum 1998, maximum 19998, percent growth 20)
        snapshot filename 'NV$DISK:[ENVY.100]NV_PCWOHAREA.SNP'
        snapshot allocation is 100 pages
        snapshot extent is (minimum 99, maximum 9999, percent growth 20)
; -- end create database

-- RMU/EXTRACT for Oracle Rdb V7.2-200                   11-OCT-2018 10:46:58.45
--
--                                  Sequences
--
--------------------------------------------------------------------------------
-- no sequences defined

-- RMU/EXTRACT for Oracle Rdb V7.2-200                   11-OCT-2018 10:46:58.45
--
--                             Collating Sequences
--
--------------------------------------------------------------------------------
-- no collating sequences defined

-- RMU/EXTRACT for Oracle Rdb V7.2-200                   11-OCT-2018 10:46:58.45
--
--                              Domain Definitions
--
--------------------------------------------------------------------------------
-- no domains defined

-- RMU/EXTRACT for Oracle Rdb V7.2-200                   11-OCT-2018 10:46:58.45
--
--                             Function Definitions
--
--------------------------------------------------------------------------------
-- no functions defined

-- RMU/EXTRACT for Oracle Rdb V7.2-200                   11-OCT-2018 10:46:58.45
--
--                            Procedure Definitions
--
--------------------------------------------------------------------------------
-- no procedures defined

-- RMU/EXTRACT for Oracle Rdb V7.2-200                   11-OCT-2018 10:46:58.45
--
--                              Table Definitions
--
--------------------------------------------------------------------------------
create table PC_CATREC (
    DB_ID
        SMALLINT,
    NVTIMESTAMP
        TIMESTAMP(2)
        default CURRENT_TIMESTAMP,
    "AREA"
        SMALLINT,
    "PAGE"
        INTEGER,
    "LINE"
        SMALLINT,
    PC_CATEGORY
        CHAR (10),
    PC_CATDESC
        CHAR (30),
    PC_CATSTAT
        SMALLINT,
    PC_CAT_LASTUPD
        CHAR (23));
 
create table PC_SLFREC (
    DB_ID
        SMALLINT,
    NVTIMESTAMP
        TIMESTAMP(2)
        default CURRENT_TIMESTAMP,
    "AREA"
        SMALLINT,
    "PAGE"
        INTEGER,
    "LINE"
        SMALLINT,
    PC_SLFNO
        CHAR (16),
    PC_PRTNO
        CHAR (18));
 
create table PC_SLTREC (
    DB_ID
        SMALLINT,
    NVTIMESTAMP
        TIMESTAMP(2)
        default CURRENT_TIMESTAMP,
    "AREA"
        SMALLINT,
    "PAGE"
        INTEGER,
    "LINE"
        SMALLINT,
    PC_SLTNO
        CHAR (16),
    PC_PRTNO
        CHAR (18));
 
create table PC_ALTHREC (
    DB_ID
        SMALLINT,
    NVTIMESTAMP
        TIMESTAMP(2)
        default CURRENT_TIMESTAMP,
    "AREA"
        SMALLINT,
    "PAGE"
        INTEGER,
    "LINE"
        SMALLINT,
    PC_ALTHSUBNO
        CHAR (16),
    PC_ALTHTYPE
        SMALLINT,
    PC_ALTHFRMNAME
        CHAR (20),
    PC_ALTHEDAT
        INTEGER,
    PC_ALTHIDAT
        INTEGER,
    PC_ALTH_LASTUPD
        CHAR (23));
 
create table PC_ADTREC (
    DB_ID
        SMALLINT,
    NVTIMESTAMP
        TIMESTAMP(2)
        default CURRENT_TIMESTAMP,
    "AREA"
        SMALLINT,
    "PAGE"
        INTEGER,
    "LINE"
        SMALLINT,
    PC_ADTINGRED
        CHAR (18),
    PC_ADTYLD
        DOUBLE PRECISION,
    PC_ADTITEM
        SMALLINT,
    PC_ADTSCALE
        SMALLINT,
    PC_ADTQPB
        DOUBLE PRECISION,
    PC_ADTSEQ
        SMALLINT,
    PC_ADTUOM
        CHAR (2),
    PC_ADT_LASTUPD
        CHAR (23),
    PC_ALTHSUBNO
        CHAR (16));
 
create table PC_ADFREC (
    DB_ID
        SMALLINT,
    NVTIMESTAMP
        TIMESTAMP(2)
        default CURRENT_TIMESTAMP,
    "AREA"
        SMALLINT,
    "PAGE"
        INTEGER,
    "LINE"
        SMALLINT,
    PC_ADFINGRED
        CHAR (18),
    PC_ADF_LASTUPD
        CHAR (23),
    PC_ALTHSUBNO
        CHAR (16));
 
create table PC_ADTDESREC (
    DB_ID
        SMALLINT,
    NVTIMESTAMP
        TIMESTAMP(2)
        default CURRENT_TIMESTAMP,
    "AREA"
        SMALLINT,
    "PAGE"
        INTEGER,
    "LINE"
        SMALLINT,
    PC_ADTDESCODE
        CHAR (10),
    PC_ADTDESTEXT
        CHAR (60),
    PC_ADTDES_LASTUPD
        CHAR (23),
    PC_ADTINGRED
        CHAR (18));
 
create table PC_ASTPREC (
    DB_ID
        SMALLINT,
    NVTIMESTAMP
        TIMESTAMP(2)
        default CURRENT_TIMESTAMP,
    "AREA"
        SMALLINT,
    "PAGE"
        INTEGER,
    "LINE"
        SMALLINT,
    PC_ASTPTQTY
        DOUBLE PRECISION,
    PC_ASTPQPB
        DOUBLE PRECISION,
    PC_ASTPUOM
        CHAR (2),
    PC_ASTP_LASTUPD
        CHAR (23),
    PC_ADTINGRED
        CHAR (18));
 
create table PC_IXREC (
    DB_ID
        SMALLINT,
    NVTIMESTAMP
        TIMESTAMP(2)
        default CURRENT_TIMESTAMP,
    "AREA"
        SMALLINT,
    "PAGE"
        INTEGER,
    "LINE"
        SMALLINT,
    PC_IXSUBNO
        CHAR (16),
    PC_IXTYPE
        SMALLINT,
    PC_IX_LASTUPD
        CHAR (23),
    PC_CATEGORY
        CHAR (10));
 
create table PC_TEXTREC (
    DB_ID
        SMALLINT,
    NVTIMESTAMP
        TIMESTAMP(2)
        default CURRENT_TIMESTAMP,
    "AREA"
        SMALLINT,
    "PAGE"
        INTEGER,
    "LINE"
        SMALLINT,
    PC_TEXTCODE
        CHAR (10),
    PC_TEXTREFOCC
        SMALLINT,
    PC_TEXT_LASTUPD
        CHAR (23));
 
create table PC_TEXDREC (
    DB_ID
        SMALLINT,
    NVTIMESTAMP
        TIMESTAMP(2)
        default CURRENT_TIMESTAMP,
    "AREA"
        SMALLINT,
    "PAGE"
        INTEGER,
    "LINE"
        SMALLINT,
    PC_TEXDESC
        CHAR (60),
    PC_TEXD_LASTUPD
        CHAR (23),
    PC_TEXTCODE
        CHAR (10));
 
create table PC_FRMREC (
    DB_ID
        SMALLINT,
    NVTIMESTAMP
        TIMESTAMP(2)
        default CURRENT_TIMESTAMP,
    "AREA"
        SMALLINT,
    "PAGE"
        INTEGER,
    "LINE"
        SMALLINT,
    PC_FRMNAME
        CHAR (20),
    PC_FRMSTAT
        SMALLINT,
    PC_FRMPROD
        CHAR (18),
    PC_FRMSTDQTY
        DOUBLE PRECISION,
    PC_FRMUOM
        CHAR (2),
    PC_FRMREV
        CHAR (2),
    PC_FRMORIG
        CHAR (10),
    PC_FRMENDAT
        INTEGER,
    PC_FRMCHGLOGFLG
        SMALLINT,
    PC_FRMUSERDEF1
        CHAR (30),
    PC_FRMUSERDEF2
        CHAR (30),
    PC_FRMUSERDEF3
        CHAR (30),
    PC_FRMUSERDEF4
        CHAR (30),
    PC_FRM_LASTUPD
        CHAR (23),
    PC_PRTNO
        CHAR (18),
    PC_CATEGORY
        CHAR (10));
 
create table PC_INGREC (
    DB_ID
        SMALLINT,
    NVTIMESTAMP
        TIMESTAMP(2)
        default CURRENT_TIMESTAMP,
    "AREA"
        SMALLINT,
    "PAGE"
        INTEGER,
    "LINE"
        SMALLINT,
    PC_INGRED
        CHAR (18),
    PC_INGITEM
        SMALLINT,
    PC_INGSCALE
        SMALLINT,
    PC_INGQPB
        DOUBLE PRECISION,
    PC_INGUOM
        CHAR (2),
    PC_INGSEQ
        SMALLINT,
    PC_INGYLD
        DOUBLE PRECISION,
    PC_INGEDAT
        INTEGER,
    PC_INGIDAT
        INTEGER,
    PC_INGTYPE
        CHAR (2),
    PC_INGFSDOFF
        DOUBLE PRECISION,
    PC_INGVSDOFF
        DOUBLE PRECISION,
    PC_INGUSERDEF1
        CHAR (30),
    PC_INGUSERDEF2
        CHAR (30),
    PC_INGUSERDEF3
        CHAR (30),
    PC_INGUSERDEF4
        CHAR (30),
    PC_INGPIYLD
        DOUBLE PRECISION,
    PC_ING_LASTUPD
        CHAR (23),
    PC_FRMNAME
        CHAR (20),
    PC_PRTNO
        CHAR (18));
 
create table PC_ENDREC (
    DB_ID
        SMALLINT,
    NVTIMESTAMP
        TIMESTAMP(2)
        default CURRENT_TIMESTAMP,
    "AREA"
        SMALLINT,
    "PAGE"
        INTEGER,
    "LINE"
        SMALLINT,
    PC_ENDPROD
        CHAR (18),
    PC_ENDTYPE
        CHAR (2),
    PC_ENDCRFLG
        SMALLINT,
    PC_ENDQTYQ
        DOUBLE PRECISION,
    PC_ENDQTYPCT
        DOUBLE PRECISION,
    PC_ENDUOM
        CHAR (2),
    PC_ENDCSTPCT
        DOUBLE PRECISION,
    PC_ENDSEQ
        SMALLINT,
    PC_ENDFSDOFF
        DOUBLE PRECISION,
    PC_ENDVSDOFF
        DOUBLE PRECISION,
    PC_ENDMPFLG
        SMALLINT,
    PC_END_LASTUPD
        CHAR (23),
    PC_PRTNO
        CHAR (18),
    PC_FRMNAME
        CHAR (20));
 
create table PC_HDESREC (
    DB_ID
        SMALLINT,
    NVTIMESTAMP
        TIMESTAMP(2)
        default CURRENT_TIMESTAMP,
    "AREA"
        SMALLINT,
    "PAGE"
        INTEGER,
    "LINE"
        SMALLINT,
    PC_HDESCODE
        CHAR (10),
    PC_HDESTEXT
        CHAR (60),
    PC_HDES_LASTUPD
        CHAR (23),
    PC_FRMNAME
        CHAR (20));
 
create table PC_IDESREC (
    DB_ID
        SMALLINT,
    NVTIMESTAMP
        TIMESTAMP(2)
        default CURRENT_TIMESTAMP,
    "AREA"
        SMALLINT,
    "PAGE"
        INTEGER,
    "LINE"
        SMALLINT,
    PC_IDESCODE
        CHAR (10),
    PC_IDESTEXT
        CHAR (60),
    PC_IDES_LASTUPD
        CHAR (23),
    PC_INGRED
        CHAR (18));
 
create table PC_STEPREC (
    DB_ID
        SMALLINT,
    NVTIMESTAMP
        TIMESTAMP(2)
        default CURRENT_TIMESTAMP,
    "AREA"
        SMALLINT,
    "PAGE"
        INTEGER,
    "LINE"
        SMALLINT,
    PC_STEPTQTY
        DOUBLE PRECISION,
    PC_STEPQPB
        DOUBLE PRECISION,
    PC_STEPUOM
        CHAR (2),
    PC_STEP_LASTUPD
        CHAR (23),
    PC_INGRED
        CHAR (18));
 
create table PC_SIFREC (
    DB_ID
        SMALLINT,
    NVTIMESTAMP
        TIMESTAMP(2)
        default CURRENT_TIMESTAMP,
    "AREA"
        SMALLINT,
    "PAGE"
        INTEGER,
    "LINE"
        SMALLINT,
    PC_SIFNO
        CHAR (16),
    PC_INGRED
        CHAR (18));
 
create table PC_CHGHREC (
    DB_ID
        SMALLINT,
    NVTIMESTAMP
        TIMESTAMP(2)
        default CURRENT_TIMESTAMP,
    "AREA"
        SMALLINT,
    "PAGE"
        INTEGER,
    "LINE"
        SMALLINT,
    PC_CHGHTYPE
        SMALLINT,
    PC_CHGHFRMNAME
        CHAR (20),
    PC_CHGHPROD
        CHAR (18),
    PC_CHGHCAT
        CHAR (10),
    PC_CHGH_LASTUPD
        CHAR (23));
 
create table PC_CHGDREC (
    DB_ID
        SMALLINT,
    NVTIMESTAMP
        TIMESTAMP(2)
        default CURRENT_TIMESTAMP,
    "AREA"
        SMALLINT,
    "PAGE"
        INTEGER,
    "LINE"
        SMALLINT,
    PC_CHGDUSER
        CHAR (12),
    PC_CHGDNODE
        CHAR (15),
    PC_CHGDFILE
        SMALLINT,
    PC_CHGDFLD1
        CHAR (18),
    PC_CHGDFLD2
        DOUBLE PRECISION,
    PC_CHGDFLD3
        SMALLINT,
    PC_CHGDFLD4
        SMALLINT,
    PC_CHGDDAT
        INTEGER,
    PC_CHGDTIME
        CHAR (8),
    PC_CHGDITEM
        CHAR (18),
    PC_CHGDOLD
        CHAR (30),
    PC_CHGDNEW
        CHAR (30),
    PC_CHGD_LASTUPD
        CHAR (23),
    PC_CHGHTYPE
        SMALLINT);
 
create table PC_PIREC (
    DB_ID
        SMALLINT,
    NVTIMESTAMP
        TIMESTAMP(2)
        default CURRENT_TIMESTAMP,
    "AREA"
        SMALLINT,
    "PAGE"
        INTEGER,
    "LINE"
        SMALLINT,
    PC_PICODE
        SMALLINT,
    PC_PISEQ
        SMALLINT,
    PC_PIEFDAT
        INTEGER,
    PC_PIINDAT
        INTEGER,
    PC_PICPFLG
        SMALLINT,
    PC_PIPRUFLG
        SMALLINT,
    PC_PITHR
        DOUBLE PRECISION,
    PC_PIOSHR
        DOUBLE PRECISION,
    PC_PIORHR
        DOUBLE PRECISION,
    PC_PISLSHR
        DOUBLE PRECISION,
    PC_PISLRHR
        DOUBLE PRECISION,
    PC_PISMSHR
        DOUBLE PRECISION,
    PC_PISMRHR
        DOUBLE PRECISION,
    PC_PIYLD
        DOUBLE PRECISION,
    PC_PISPROC
        DOUBLE PRECISION,
    PC_PIPLSHR
        DOUBLE PRECISION,
    PC_PIPLRHR
        DOUBLE PRECISION,
    PC_PIPMSHR
        DOUBLE PRECISION,
    PC_PIPMRHR
        DOUBLE PRECISION,
    PC_PIPYLD
        DOUBLE PRECISION,
    PC_PIPPROC
        DOUBLE PRECISION,
    PC_PIYSCMT
        DOUBLE PRECISION,
    PC_PIYSCMO
        DOUBLE PRECISION,
    PC_PIYSADL
        DOUBLE PRECISION,
    PC_PIYSCDL
        DOUBLE PRECISION,
    PC_PIYSAO1
        DOUBLE PRECISION,
    PC_PIYSCO1
        DOUBLE PRECISION,
    PC_PIYSAO2
        DOUBLE PRECISION,
    PC_PIYSCO2
        DOUBLE PRECISION,
    PC_PIYSAOP
        DOUBLE PRECISION,
    PC_PIYSCOP
        DOUBLE PRECISION,
    PC_PIYSAOO
        DOUBLE PRECISION,
    PC_PIYSCOO
        DOUBLE PRECISION,
    PC_PIYPCMT
        DOUBLE PRECISION,
    PC_PIYPCMO
        DOUBLE PRECISION,
    PC_PIYPADL
        DOUBLE PRECISION,
    PC_PIYPCDL
        DOUBLE PRECISION,
    PC_PIYPAO1
        DOUBLE PRECISION,
    PC_PIYPCO1
        DOUBLE PRECISION,
    PC_PIYPAO2
        DOUBLE PRECISION,
    PC_PIYPCO2
        DOUBLE PRECISION,
    PC_PIYPAOP
        DOUBLE PRECISION,
    PC_PIYPCOP
        DOUBLE PRECISION,
    PC_PIYPAOO
        DOUBLE PRECISION,
    PC_PIYPCOO
        DOUBLE PRECISION,
    PC_PIQUE
        CHAR (10),
    PC_PI_LASTUPD
        CHAR (23),
    PC_PIMSEQ
        SMALLINT,
    PC_FRMNAME
        CHAR (20),
    PC_WKCNTR
        CHAR (10));
 
create table PC_PIDESREC (
    DB_ID
        SMALLINT,
    NVTIMESTAMP
        TIMESTAMP(2)
        default CURRENT_TIMESTAMP,
    "AREA"
        SMALLINT,
    "PAGE"
        INTEGER,
    "LINE"
        SMALLINT,
    PC_PIDESCODE
        CHAR (10),
    PC_PIDESTEXT
        CHAR (60),
    PC_PIDES_LASTUPD
        CHAR (23),
    PC_PICODE
        SMALLINT);
 
create table PC_SUBPREC (
    DB_ID
        SMALLINT,
    NVTIMESTAMP
        TIMESTAMP(2)
        default CURRENT_TIMESTAMP,
    "AREA"
        SMALLINT,
    "PAGE"
        INTEGER,
    "LINE"
        SMALLINT,
    PC_SUBPNO
        CHAR (16),
    PC_PICODE
        SMALLINT);
 
create table PC_APIHREC (
    DB_ID
        SMALLINT,
    NVTIMESTAMP
        TIMESTAMP(2)
        default CURRENT_TIMESTAMP,
    "AREA"
        SMALLINT,
    "PAGE"
        INTEGER,
    "LINE"
        SMALLINT,
    PC_APIHSUBPNO
        CHAR (16),
    PC_APIHTYPE
        SMALLINT,
    PC_APIHPICODE
        SMALLINT,
    PC_APIHFRMNAME
        CHAR (20),
    PC_APIHEDAT
        INTEGER,
    PC_APIHIDAT
        INTEGER,
    PC_APIH_LASTUPD
        CHAR (23));
 
create table PC_APITREC (
    DB_ID
        SMALLINT,
    NVTIMESTAMP
        TIMESTAMP(2)
        default CURRENT_TIMESTAMP,
    "AREA"
        SMALLINT,
    "PAGE"
        INTEGER,
    "LINE"
        SMALLINT,
    PC_APITCODE
        SMALLINT,
    PC_APITSEQ
        SMALLINT,
    PC_APITEFDAT
        INTEGER,
    PC_APITINDAT
        INTEGER,
    PC_APITCPFLG
        SMALLINT,
    PC_APITPRUFLG
        SMALLINT,
    PC_APITTHR
        DOUBLE PRECISION,
    PC_APITOSHR
        DOUBLE PRECISION,
    PC_APITORHR
        DOUBLE PRECISION,
    PC_APITSLSHR
        DOUBLE PRECISION,
    PC_APITSLRHR
        DOUBLE PRECISION,
    PC_APITSMSHR
        DOUBLE PRECISION,
    PC_APITSMRHR
        DOUBLE PRECISION,
    PC_APITYLD
        DOUBLE PRECISION,
    PC_APITSPROC
        DOUBLE PRECISION,
    PC_APITPLSHR
        DOUBLE PRECISION,
    PC_APITPLRHR
        DOUBLE PRECISION,
    PC_APITPMSHR
        DOUBLE PRECISION,
    PC_APITPMRHR
        DOUBLE PRECISION,
    PC_APITPYLD
        DOUBLE PRECISION,
    PC_APITPPROC
        DOUBLE PRECISION,
    PC_APITQUE
        CHAR (10),
    PC_APIT_LASTUPD
        CHAR (23),
    PC_APIHSUBPNO
        CHAR (16),
    PC_WKCNTR
        CHAR (10));
 
create table PC_APIFREC (
    DB_ID
        SMALLINT,
    NVTIMESTAMP
        TIMESTAMP(2)
        default CURRENT_TIMESTAMP,
    "AREA"
        SMALLINT,
    "PAGE"
        INTEGER,
    "LINE"
        SMALLINT,
    PC_APIFCODE
        SMALLINT,
    PC_APIFSEQ
        SMALLINT,
    PC_APIF_LASTUPD
        CHAR (23),
    PC_APIHSUBPNO
        CHAR (16));
 
create table PC_APIDESREC (
    DB_ID
        SMALLINT,
    NVTIMESTAMP
        TIMESTAMP(2)
        default CURRENT_TIMESTAMP,
    "AREA"
        SMALLINT,
    "PAGE"
        INTEGER,
    "LINE"
        SMALLINT,
    PC_APIDESCODE
        CHAR (10),
    PC_APIDESTEXT
        CHAR (60),
    PC_APIDES_LASTUPD
        CHAR (23),
    PC_APITCODE
        SMALLINT);
 
create table PC_PISAFREC (
    DB_ID
        SMALLINT,
    NVTIMESTAMP
        TIMESTAMP(2)
        default CURRENT_TIMESTAMP,
    "AREA"
        SMALLINT,
    "PAGE"
        INTEGER,
    "LINE"
        SMALLINT,
    PC_PISAFCODE
        CHAR (10),
    PC_PISAFTEXT
        CHAR (60),
    PC_PISAF_LASTUPD
        CHAR (23),
    PC_PICODE
        SMALLINT);
 
create table PC_APISAFREC (
    DB_ID
        SMALLINT,
    NVTIMESTAMP
        TIMESTAMP(2)
        default CURRENT_TIMESTAMP,
    "AREA"
        SMALLINT,
    "PAGE"
        INTEGER,
    "LINE"
        SMALLINT,
    PC_APISAFCODE
        CHAR (10),
    PC_APISAFTEXT
        CHAR (60),
    PC_APISAF_LASTUPD
        CHAR (23),
    PC_APITCODE
        SMALLINT);
 
create table PC_WKCREC (
    DB_ID
        SMALLINT,
    NVTIMESTAMP
        TIMESTAMP(2)
        default CURRENT_TIMESTAMP,
    "AREA"
        SMALLINT,
    "PAGE"
        INTEGER,
    "LINE"
        SMALLINT,
    PC_WKCNTR
        CHAR (10),
    PC_WKC_LASTUPD
        CHAR (23));
 
create table PC_TOOREC (
    DB_ID
        SMALLINT,
    NVTIMESTAMP
        TIMESTAMP(2)
        default CURRENT_TIMESTAMP,
    "AREA"
        SMALLINT,
    "PAGE"
        INTEGER,
    "LINE"
        SMALLINT,
    PC_TOONO
        CHAR (18),
    PC_TOO_LASTUPD
        CHAR (23));
 
create table PC_TWUREC (
    DB_ID
        SMALLINT,
    NVTIMESTAMP
        TIMESTAMP(2)
        default CURRENT_TIMESTAMP,
    "AREA"
        SMALLINT,
    "PAGE"
        INTEGER,
    "LINE"
        SMALLINT,
    PC_TWUCNT
        SMALLINT,
    PC_TWU_LASTUPD
        CHAR (23),
    PC_PICODE
        SMALLINT,
    PC_TOONO
        CHAR (18),
    PC_MPICODE
        SMALLINT,
    PC_APITCODE
        SMALLINT);
 
create table PC_MBOREC (
    DB_ID
        SMALLINT,
    NVTIMESTAMP
        TIMESTAMP(2)
        default CURRENT_TIMESTAMP,
    "AREA"
        SMALLINT,
    "PAGE"
        INTEGER,
    "LINE"
        SMALLINT,
    PC_MBOWIPACCT
        CHAR (24),
    PC_MBOVARACCT
        CHAR (24),
    PC_MBOREPFLG
        SMALLINT,
    PC_MBONO
        CHAR (10),
    PC_MBOSTAT
        SMALLINT,
    PC_MBOFRMNAME
        CHAR (20),
    PC_MBOFRMSTAT
        SMALLINT,
    PC_MBOCATEGORY
        CHAR (10),
    PC_MBOQTY
        DOUBLE PRECISION,
    PC_MBOUOM
        CHAR (2),
    PC_MBOENDAT
        INTEGER,
    PC_MBOPC
        CHAR (2),
    PC_MBOREV
        CHAR (2),
    PC_MBOACCWRQTY
        DOUBLE PRECISION,
    PC_MBOACCWCQTY
        DOUBLE PRECISION,
    PC_MBOACCWSQTY
        DOUBLE PRECISION,
    PC_MBOACCBSRQTY
        DOUBLE PRECISION,
    PC_MBOACCBSCQTY
        DOUBLE PRECISION,
    PC_MBOACCBSSQTY
        DOUBLE PRECISION,
    PC_MBOUSERDEF1
        CHAR (30),
    PC_MBOUSERDEF2
        CHAR (30),
    PC_MBOUSERDEF3
        CHAR (30),
    PC_MBOUSERDEF4
        CHAR (30),
    PC_MBO_LASTUPD
        CHAR (23),
    PC_PRTNO
        CHAR (18));
 
create table PC_MBODESREC (
    DB_ID
        SMALLINT,
    NVTIMESTAMP
        TIMESTAMP(2)
        default CURRENT_TIMESTAMP,
    "AREA"
        SMALLINT,
    "PAGE"
        INTEGER,
    "LINE"
        SMALLINT,
    PC_MBODESCODE
        CHAR (10),
    PC_MBODESTEXT
        CHAR (60),
    PC_MBODES_LASTUPD
        CHAR (23),
    PC_MBOWIPACCT
        CHAR (24));
 
create table PC_MENDREC (
    DB_ID
        SMALLINT,
    NVTIMESTAMP
        TIMESTAMP(2)
        default CURRENT_TIMESTAMP,
    "AREA"
        SMALLINT,
    "PAGE"
        INTEGER,
    "LINE"
        SMALLINT,
    PC_MENDPROD
        CHAR (18),
    PC_MENDTYPE
        CHAR (2),
    PC_MENDCRFLG
        SMALLINT,
    PC_MENDQTYQ
        DOUBLE PRECISION,
    PC_MENDQTYPCT
        DOUBLE PRECISION,
    PC_MENDUOM
        CHAR (2),
    PC_MENDCSTPCT
        DOUBLE PRECISION,
    PC_MENDSEQ
        SMALLINT,
    PC_MENDFSDOFF
        DOUBLE PRECISION,
    PC_MENDVSDOFF
        DOUBLE PRECISION,
    PC_MENDMPFLG
        SMALLINT,
    PC_MEND_LASTUPD
        CHAR (23),
    PC_MBOWIPACCT
        CHAR (24),
    PC_PRTNO
        CHAR (18));
 
create table PC_MINGREC (
    DB_ID
        SMALLINT,
    NVTIMESTAMP
        TIMESTAMP(2)
        default CURRENT_TIMESTAMP,
    "AREA"
        SMALLINT,
    "PAGE"
        INTEGER,
    "LINE"
        SMALLINT,
    PC_MINGRED
        CHAR (18),
    PC_MINGITEM
        SMALLINT,
    PC_MINGSCALE
        SMALLINT,
    PC_MINGQPB
        DOUBLE PRECISION,
    PC_MINGUOM
        CHAR (2),
    PC_MINGSEQ
        SMALLINT,
    PC_MINGYLD
        DOUBLE PRECISION,
    PC_MINGEDAT
        INTEGER,
    PC_MINGIDAT
        INTEGER,
    PC_MINGTYPE
        CHAR (2),
    PC_MINGFSDOFF
        DOUBLE PRECISION,
    PC_MINGVSDOFF
        DOUBLE PRECISION,
    PC_MINGUSERDEF1
        CHAR (30),
    PC_MINGUSERDEF2
        CHAR (30),
    PC_MINGUSERDEF3
        CHAR (30),
    PC_MINGUSERDEF4
        CHAR (30),
    PC_MINGPIYLD
        DOUBLE PRECISION,
    PC_MING_LASTUPD
        CHAR (23),
    PC_MBOWIPACCT
        CHAR (24),
    PC_PRTNO
        CHAR (18));
 
create table PC_MIDESREC (
    DB_ID
        SMALLINT,
    NVTIMESTAMP
        TIMESTAMP(2)
        default CURRENT_TIMESTAMP,
    "AREA"
        SMALLINT,
    "PAGE"
        INTEGER,
    "LINE"
        SMALLINT,
    PC_MIDESCODE
        CHAR (10),
    PC_MIDESTEXT
        CHAR (60),
    PC_MIDES_LASTUPD
        CHAR (23),
    PC_MINGRED
        CHAR (18));
 
create table PC_MPIREC (
    DB_ID
        SMALLINT,
    NVTIMESTAMP
        TIMESTAMP(2)
        default CURRENT_TIMESTAMP,
    "AREA"
        SMALLINT,
    "PAGE"
        INTEGER,
    "LINE"
        SMALLINT,
    PC_MPICODE
        SMALLINT,
    PC_MPISEQ
        SMALLINT,
    PC_MPIEFDAT
        INTEGER,
    PC_MPIINDAT
        INTEGER,
    PC_MPICPFLG
        SMALLINT,
    PC_MPIPRUFLG
        SMALLINT,
    PC_MPITHR
        DOUBLE PRECISION,
    PC_MPIOSHR
        DOUBLE PRECISION,
    PC_MPIORHR
        DOUBLE PRECISION,
    PC_MPISLSHR
        DOUBLE PRECISION,
    PC_MPISLRHR
        DOUBLE PRECISION,
    PC_MPISMSHR
        DOUBLE PRECISION,
    PC_MPISMRHR
        DOUBLE PRECISION,
    PC_MPIYLD
        DOUBLE PRECISION,
    PC_MPISPROC
        DOUBLE PRECISION,
    PC_MPIYSCMT
        DOUBLE PRECISION,
    PC_MPIYSCMO
        DOUBLE PRECISION,
    PC_MPIYSADL
        DOUBLE PRECISION,
    PC_MPIYSCDL
        DOUBLE PRECISION,
    PC_MPIYSAO1
        DOUBLE PRECISION,
    PC_MPIYSCO1
        DOUBLE PRECISION,
    PC_MPIYSAO2
        DOUBLE PRECISION,
    PC_MPIYSCO2
        DOUBLE PRECISION,
    PC_MPIYSAOP
        DOUBLE PRECISION,
    PC_MPIYSCOP
        DOUBLE PRECISION,
    PC_MPIYSAOO
        DOUBLE PRECISION,
    PC_MPIYSCOO
        DOUBLE PRECISION,
    PC_MPIQUE
        CHAR (10),
    PC_MPI_LASTUPD
        CHAR (23),
    PC_MBOWIPACCT
        CHAR (24),
    PC_WKCNTR
        CHAR (10));
 
create table PC_MPIDESREC (
    DB_ID
        SMALLINT,
    NVTIMESTAMP
        TIMESTAMP(2)
        default CURRENT_TIMESTAMP,
    "AREA"
        SMALLINT,
    "PAGE"
        INTEGER,
    "LINE"
        SMALLINT,
    PC_MPIDESCODE
        CHAR (10),
    PC_MPIDESTEXT
        CHAR (60),
    PC_MPIDES_LASTUPD
        CHAR (23),
    PC_MPICODE
        SMALLINT);
 
create table PC_MPISAFREC (
    DB_ID
        SMALLINT,
    NVTIMESTAMP
        TIMESTAMP(2)
        default CURRENT_TIMESTAMP,
    "AREA"
        SMALLINT,
    "PAGE"
        INTEGER,
    "LINE"
        SMALLINT,
    PC_MPISAFCODE
        CHAR (10),
    PC_MPISAFTEXT
        CHAR (60),
    PC_MPISAF_LASTUPD
        CHAR (23),
    PC_MPICODE
        SMALLINT);
 
create table PC_MCSTREC (
    DB_ID
        SMALLINT,
    NVTIMESTAMP
        TIMESTAMP(2)
        default CURRENT_TIMESTAMP,
    "AREA"
        SMALLINT,
    "PAGE"
        INTEGER,
    "LINE"
        SMALLINT,
    PC_MCSTMTHD
        CHAR (2),
    PC_MCSTSCMT
        DOUBLE PRECISION,
    PC_MCSTSCMO
        DOUBLE PRECISION,
    PC_MCSTSAMBF
        DOUBLE PRECISION,
    PC_MCSTSCDL
        DOUBLE PRECISION,
    PC_MCSTSCO1
        DOUBLE PRECISION,
    PC_MCSTSCO2
        DOUBLE PRECISION,
    PC_MCSTSCOP
        DOUBLE PRECISION,
    PC_MCSTSCOO
        DOUBLE PRECISION,
    PC_MCSTSADL
        DOUBLE PRECISION,
    PC_MCSTSAO1
        DOUBLE PRECISION,
    PC_MCSTSAO2
        DOUBLE PRECISION,
    PC_MCSTSAOP
        DOUBLE PRECISION,
    PC_MCSTSAOBF
        DOUBLE PRECISION,
    PC_MCSTSPUR
        DOUBLE PRECISION,
    PC_MCSTLSTAMAT
        DOUBLE PRECISION,
    PC_MCSTLSTAMATO
        DOUBLE PRECISION,
    PC_MCSTLSTALAB
        DOUBLE PRECISION,
    PC_MCSTLSTALABO
        DOUBLE PRECISION,
    PC_MCST_LASTUPD
        CHAR (23),
    PC_MENDPROD
        CHAR (18));
 
create table PC_WOHREC (
    DB_ID
        SMALLINT,
    NVTIMESTAMP
        TIMESTAMP(2)
        default CURRENT_TIMESTAMP,
    "AREA"
        SMALLINT,
    "PAGE"
        INTEGER,
    "LINE"
        SMALLINT,
    PC_WOHNO
        CHAR (10),
    PC_WOHPRT
        CHAR (18),
    PC_WOH_LASTUPD
        CHAR (23),
    PC_MBOWIPACCT
        CHAR (24));
 
create table PC_WODREC (
    DB_ID
        SMALLINT,
    NVTIMESTAMP
        TIMESTAMP(2)
        default CURRENT_TIMESTAMP,
    "AREA"
        SMALLINT,
    "PAGE"
        INTEGER,
    "LINE"
        SMALLINT,
    PC_WODPRT
        CHAR (18),
    PC_WODNO
        CHAR (10),
    PC_WODENDTYPE
        CHAR (2),
    PC_WODOQTY
        DOUBLE PRECISION,
    PC_WODCQTY
        DOUBLE PRECISION,
    PC_WODAQTY
        DOUBLE PRECISION,
    PC_WODMRP
        INTEGER,
    PC_WODLDDAT
        INTEGER,
    PC_WODMPFLG
        SMALLINT,
    PC_WOD_LASTUPD
        CHAR (23),
    PC_WOHNO
        CHAR (10),
    PC_PRTNO
        CHAR (18));
 
create table PC_TRKNOREC (
    DB_ID
        SMALLINT,
    NVTIMESTAMP
        TIMESTAMP(2)
        default CURRENT_TIMESTAMP,
    "AREA"
        SMALLINT,
    "PAGE"
        INTEGER,
    "LINE"
        SMALLINT,
    PC_TRKNONO
        CHAR (10),
    PC_TRKNO_LASTUPD
        CHAR (23));
 
create table PC_TRKREC (
    DB_ID
        SMALLINT,
    NVTIMESTAMP
        TIMESTAMP(2)
        default CURRENT_TIMESTAMP,
    "AREA"
        SMALLINT,
    "PAGE"
        INTEGER,
    "LINE"
        SMALLINT,
    PC_TRKNO
        CHAR (10),
    PC_TRKREF1
        CHAR (10),
    PC_TRKREF2
        CHAR (10),
    PC_TRKREF3
        CHAR (10),
    PC_TRKREF4
        CHAR (30),
    PC_TRKTIME
        CHAR (8),
    PC_TRKDATE
        INTEGER,
    PC_TRKTDATE
        INTEGER,
    PC_TRKLOGON
        CHAR (12),
    PC_TRKCMD
        CHAR (6),
    PC_TRKSEQ
        SMALLINT,
    PC_TRKWKC
        CHAR (10),
    PC_TRKPRT
        CHAR (18),
    PC_TRKTYPE
        SMALLINT,
    PC_TRKKEY1
        CHAR (10),
    PC_TRKKEY2
        CHAR (10),
    PC_TRKKEY3
        CHAR (24),
    PC_TRKKEY4
        CHAR (24),
    PC_TRKQTY
        DOUBLE PRECISION,
    PC_TRKUOMQTY
        DOUBLE PRECISION,
    PC_TRKUOM
        CHAR (2),
    PC_TRKUOMCONV
        DOUBLE PRECISION,
    PC_TRKREASCODE
        SMALLINT,
    PC_TRKREASDESC
        CHAR (30),
    PC_TRKARCFLAG
        SMALLINT,
    PC_TRKUSERDEF1
        CHAR (30),
    PC_TRKUSERDEF2
        CHAR (30),
    PC_TRKUSERDEF3
        CHAR (30),
    PC_TRKUSERDEF4
        CHAR (30),
    PC_TRK_LASTUPD
        CHAR (23),
    PC_TRKNONO
        CHAR (10));
 
create table PC_TRKNOTREC (
    DB_ID
        SMALLINT,
    NVTIMESTAMP
        TIMESTAMP(2)
        default CURRENT_TIMESTAMP,
    "AREA"
        SMALLINT,
    "PAGE"
        INTEGER,
    "LINE"
        SMALLINT,
    PC_TRKNOTDESC
        CHAR (60),
    PC_TRKNOT_LASTUPD
        CHAR (23),
    PC_TRKNO
        CHAR (10));
 
create table PC_PRTREC (
    DB_ID
        SMALLINT,
    NVTIMESTAMP
        TIMESTAMP(2)
        default CURRENT_TIMESTAMP,
    "AREA"
        SMALLINT,
    "PAGE"
        INTEGER,
    "LINE"
        SMALLINT,
    PC_PRTNO
        CHAR (18),
    PC_PRTNBFLG
        CHAR (2),
    PC_PRTCSTFRM
        CHAR (20),
    PC_PRTMSDS
        CHAR (10),
    PC_PRT_LASTUPD
        CHAR (23),
    PC_PRTACTSTAT
        CHAR (5),
    PC_PRTACTDATE
        INTEGER);
 
create table PC_FCOHREC (
    DB_ID
        SMALLINT,
    NVTIMESTAMP
        TIMESTAMP(2)
        default CURRENT_TIMESTAMP,
    "AREA"
        SMALLINT,
    "PAGE"
        INTEGER,
    "LINE"
        SMALLINT,
    PC_FCOHNO
        CHAR (10),
    PC_FCOHENDAT
        INTEGER,
    PC_FCOH_LASTUPD
        CHAR (23));
 
create table PC_FCODREC (
    DB_ID
        SMALLINT,
    NVTIMESTAMP
        TIMESTAMP(2)
        default CURRENT_TIMESTAMP,
    "AREA"
        SMALLINT,
    "PAGE"
        INTEGER,
    "LINE"
        SMALLINT,
    PC_FCODOREV
        CHAR (2),
    PC_FCODNREV
        CHAR (2),
    PC_FCODEDAT
        INTEGER,
    PC_FCOD_LASTUPD
        CHAR (23),
    PC_FCOHNO
        CHAR (10),
    PC_PRTNO
        CHAR (18),
    PC_FRMNAME
        CHAR (20));
 
create table PC_FCODESREC (
    DB_ID
        SMALLINT,
    NVTIMESTAMP
        TIMESTAMP(2)
        default CURRENT_TIMESTAMP,
    "AREA"
        SMALLINT,
    "PAGE"
        INTEGER,
    "LINE"
        SMALLINT,
    PC_FCODESCOM
        CHAR (60),
    PC_FCODES_LASTUPD
        CHAR (23),
    PC_FCOHNO
        CHAR (10));
 
create table PC_USRREC (
    DB_ID
        SMALLINT,
    NVTIMESTAMP
        TIMESTAMP(2)
        default CURRENT_TIMESTAMP,
    "AREA"
        SMALLINT,
    "PAGE"
        INTEGER,
    "LINE"
        SMALLINT,
    PC_USRNAME
        CHAR (12),
    PC_USRENDAT
        INTEGER,
    PC_USR_LASTUPD
        CHAR (23));
 
create table PC_FRMPVREC (
    DB_ID
        SMALLINT,
    NVTIMESTAMP
        TIMESTAMP(2)
        default CURRENT_TIMESTAMP,
    "AREA"
        SMALLINT,
    "PAGE"
        INTEGER,
    "LINE"
        SMALLINT,
    PC_FRMPVUSR
        CHAR (12),
    PC_FRMPVIXFLG
        SMALLINT,
    PC_FRMPVCAT
        CHAR (10),
    PC_FRMPV_LASTUPD
        CHAR (23),
    PC_USRNAME
        CHAR (12),
    PC_CATEGORY
        CHAR (10));
 

 
create table PC_CATHSHSET (
    DB_ID
        SMALLINT,
    NVTIMESTAMP
        TIMESTAMP(2)
        default CURRENT_TIMESTAMP,
    OAREA
        SMALLINT,
    OPAGE
        INTEGER,
    OLINE
        SMALLINT,
    MAREA
        SMALLINT,
    MPAGE
        INTEGER,
    MLINE
        SMALLINT);
 
create table PC_ALTHHSHSET (
    DB_ID
        SMALLINT,
    NVTIMESTAMP
        TIMESTAMP(2)
        default CURRENT_TIMESTAMP,
    OAREA
        SMALLINT,
    OPAGE
        INTEGER,
    OLINE
        SMALLINT,
    MAREA
        SMALLINT,
    MPAGE
        INTEGER,
    MLINE
        SMALLINT);
 
create table PC_ALTHADFSET (
    DB_ID
        SMALLINT,
    NVTIMESTAMP
        TIMESTAMP(2)
        default CURRENT_TIMESTAMP,
    OAREA
        SMALLINT,
    OPAGE
        INTEGER,
    OLINE
        SMALLINT,
    MAREA
        SMALLINT,
    MPAGE
        INTEGER,
    MLINE
        SMALLINT);
 
create table PC_ALTHADTSET (
    DB_ID
        SMALLINT,
    NVTIMESTAMP
        TIMESTAMP(2)
        default CURRENT_TIMESTAMP,
    OAREA
        SMALLINT,
    OPAGE
        INTEGER,
    OLINE
        SMALLINT,
    MAREA
        SMALLINT,
    MPAGE
        INTEGER,
    MLINE
        SMALLINT);
 
create table PC_ADTADTDESSET (
    DB_ID
        SMALLINT,
    NVTIMESTAMP
        TIMESTAMP(2)
        default CURRENT_TIMESTAMP,
    OAREA
        SMALLINT,
    OPAGE
        INTEGER,
    OLINE
        SMALLINT,
    MAREA
        SMALLINT,
    MPAGE
        INTEGER,
    MLINE
        SMALLINT);
 
create table PC_CATIXSET (
    DB_ID
        SMALLINT,
    NVTIMESTAMP
        TIMESTAMP(2)
        default CURRENT_TIMESTAMP,
    OAREA
        SMALLINT,
    OPAGE
        INTEGER,
    OLINE
        SMALLINT,
    MAREA
        SMALLINT,
    MPAGE
        INTEGER,
    MLINE
        SMALLINT);
 
create table PC_PRTSLFSET (
    DB_ID
        SMALLINT,
    NVTIMESTAMP
        TIMESTAMP(2)
        default CURRENT_TIMESTAMP,
    OAREA
        SMALLINT,
    OPAGE
        INTEGER,
    OLINE
        SMALLINT,
    MAREA
        SMALLINT,
    MPAGE
        INTEGER,
    MLINE
        SMALLINT);
 
create table PC_PRTSLTSET (
    DB_ID
        SMALLINT,
    NVTIMESTAMP
        TIMESTAMP(2)
        default CURRENT_TIMESTAMP,
    OAREA
        SMALLINT,
    OPAGE
        INTEGER,
    OLINE
        SMALLINT,
    MAREA
        SMALLINT,
    MPAGE
        INTEGER,
    MLINE
        SMALLINT);
 
create table PC_ADTASTPSET (
    DB_ID
        SMALLINT,
    NVTIMESTAMP
        TIMESTAMP(2)
        default CURRENT_TIMESTAMP,
    OAREA
        SMALLINT,
    OPAGE
        INTEGER,
    OLINE
        SMALLINT,
    MAREA
        SMALLINT,
    MPAGE
        INTEGER,
    MLINE
        SMALLINT);
 
create table PC_TEXTHSHSET (
    DB_ID
        SMALLINT,
    NVTIMESTAMP
        TIMESTAMP(2)
        default CURRENT_TIMESTAMP,
    OAREA
        SMALLINT,
    OPAGE
        INTEGER,
    OLINE
        SMALLINT,
    MAREA
        SMALLINT,
    MPAGE
        INTEGER,
    MLINE
        SMALLINT);
 
create table PC_TEXTTEXDSET (
    DB_ID
        SMALLINT,
    NVTIMESTAMP
        TIMESTAMP(2)
        default CURRENT_TIMESTAMP,
    OAREA
        SMALLINT,
    OPAGE
        INTEGER,
    OLINE
        SMALLINT,
    MAREA
        SMALLINT,
    MPAGE
        INTEGER,
    MLINE
        SMALLINT);
 
create table PC_PRTFRMSET (
    DB_ID
        SMALLINT,
    NVTIMESTAMP
        TIMESTAMP(2)
        default CURRENT_TIMESTAMP,
    OAREA
        SMALLINT,
    OPAGE
        INTEGER,
    OLINE
        SMALLINT,
    MAREA
        SMALLINT,
    MPAGE
        INTEGER,
    MLINE
        SMALLINT);
 
create table PC_PRTENDSET (
    DB_ID
        SMALLINT,
    NVTIMESTAMP
        TIMESTAMP(2)
        default CURRENT_TIMESTAMP,
    OAREA
        SMALLINT,
    OPAGE
        INTEGER,
    OLINE
        SMALLINT,
    MAREA
        SMALLINT,
    MPAGE
        INTEGER,
    MLINE
        SMALLINT);
 
create table PC_FRMENDSET (
    DB_ID
        SMALLINT,
    NVTIMESTAMP
        TIMESTAMP(2)
        default CURRENT_TIMESTAMP,
    OAREA
        SMALLINT,
    OPAGE
        INTEGER,
    OLINE
        SMALLINT,
    MAREA
        SMALLINT,
    MPAGE
        INTEGER,
    MLINE
        SMALLINT);
 
create table PC_FRMHDESSET (
    DB_ID
        SMALLINT,
    NVTIMESTAMP
        TIMESTAMP(2)
        default CURRENT_TIMESTAMP,
    OAREA
        SMALLINT,
    OPAGE
        INTEGER,
    OLINE
        SMALLINT,
    MAREA
        SMALLINT,
    MPAGE
        INTEGER,
    MLINE
        SMALLINT);
 
create table PC_FRMINGSET (
    DB_ID
        SMALLINT,
    NVTIMESTAMP
        TIMESTAMP(2)
        default CURRENT_TIMESTAMP,
    OAREA
        SMALLINT,
    OPAGE
        INTEGER,
    OLINE
        SMALLINT,
    MAREA
        SMALLINT,
    MPAGE
        INTEGER,
    MLINE
        SMALLINT);
 
create table PC_PRTINGSET (
    DB_ID
        SMALLINT,
    NVTIMESTAMP
        TIMESTAMP(2)
        default CURRENT_TIMESTAMP,
    OAREA
        SMALLINT,
    OPAGE
        INTEGER,
    OLINE
        SMALLINT,
    MAREA
        SMALLINT,
    MPAGE
        INTEGER,
    MLINE
        SMALLINT);
 
create table PC_INGIDESSET (
    DB_ID
        SMALLINT,
    NVTIMESTAMP
        TIMESTAMP(2)
        default CURRENT_TIMESTAMP,
    OAREA
        SMALLINT,
    OPAGE
        INTEGER,
    OLINE
        SMALLINT,
    MAREA
        SMALLINT,
    MPAGE
        INTEGER,
    MLINE
        SMALLINT);
 
create table PC_INGSTEPSET (
    DB_ID
        SMALLINT,
    NVTIMESTAMP
        TIMESTAMP(2)
        default CURRENT_TIMESTAMP,
    OAREA
        SMALLINT,
    OPAGE
        INTEGER,
    OLINE
        SMALLINT,
    MAREA
        SMALLINT,
    MPAGE
        INTEGER,
    MLINE
        SMALLINT);
 
create table PC_CATFRMSET (
    DB_ID
        SMALLINT,
    NVTIMESTAMP
        TIMESTAMP(2)
        default CURRENT_TIMESTAMP,
    OAREA
        SMALLINT,
    OPAGE
        INTEGER,
    OLINE
        SMALLINT,
    MAREA
        SMALLINT,
    MPAGE
        INTEGER,
    MLINE
        SMALLINT);
 
create table PC_FRMHSHSET (
    DB_ID
        SMALLINT,
    NVTIMESTAMP
        TIMESTAMP(2)
        default CURRENT_TIMESTAMP,
    OAREA
        SMALLINT,
    OPAGE
        INTEGER,
    OLINE
        SMALLINT,
    MAREA
        SMALLINT,
    MPAGE
        INTEGER,
    MLINE
        SMALLINT);
 
create table PC_INGSIFSET (
    DB_ID
        SMALLINT,
    NVTIMESTAMP
        TIMESTAMP(2)
        default CURRENT_TIMESTAMP,
    OAREA
        SMALLINT,
    OPAGE
        INTEGER,
    OLINE
        SMALLINT,
    MAREA
        SMALLINT,
    MPAGE
        INTEGER,
    MLINE
        SMALLINT);
 
create table PC_CHGHHSHSET (
    DB_ID
        SMALLINT,
    NVTIMESTAMP
        TIMESTAMP(2)
        default CURRENT_TIMESTAMP,
    OAREA
        SMALLINT,
    OPAGE
        INTEGER,
    OLINE
        SMALLINT,
    MAREA
        SMALLINT,
    MPAGE
        INTEGER,
    MLINE
        SMALLINT);
 
create table PC_CHGHCHGDSET (
    DB_ID
        SMALLINT,
    NVTIMESTAMP
        TIMESTAMP(2)
        default CURRENT_TIMESTAMP,
    OAREA
        SMALLINT,
    OPAGE
        INTEGER,
    OLINE
        SMALLINT,
    MAREA
        SMALLINT,
    MPAGE
        INTEGER,
    MLINE
        SMALLINT);
 
create table PC_FRMPISET (
    DB_ID
        SMALLINT,
    NVTIMESTAMP
        TIMESTAMP(2)
        default CURRENT_TIMESTAMP,
    OAREA
        SMALLINT,
    OPAGE
        INTEGER,
    OLINE
        SMALLINT,
    MAREA
        SMALLINT,
    MPAGE
        INTEGER,
    MLINE
        SMALLINT);
 
create table PC_PIPIDESSET (
    DB_ID
        SMALLINT,
    NVTIMESTAMP
        TIMESTAMP(2)
        default CURRENT_TIMESTAMP,
    OAREA
        SMALLINT,
    OPAGE
        INTEGER,
    OLINE
        SMALLINT,
    MAREA
        SMALLINT,
    MPAGE
        INTEGER,
    MLINE
        SMALLINT);
 
create table PC_APIHAPITSET (
    DB_ID
        SMALLINT,
    NVTIMESTAMP
        TIMESTAMP(2)
        default CURRENT_TIMESTAMP,
    OAREA
        SMALLINT,
    OPAGE
        INTEGER,
    OLINE
        SMALLINT,
    MAREA
        SMALLINT,
    MPAGE
        INTEGER,
    MLINE
        SMALLINT);
 
create table PC_APIHAPIFSET (
    DB_ID
        SMALLINT,
    NVTIMESTAMP
        TIMESTAMP(2)
        default CURRENT_TIMESTAMP,
    OAREA
        SMALLINT,
    OPAGE
        INTEGER,
    OLINE
        SMALLINT,
    MAREA
        SMALLINT,
    MPAGE
        INTEGER,
    MLINE
        SMALLINT);
 
create table PC_APITAPIDESSET (
    DB_ID
        SMALLINT,
    NVTIMESTAMP
        TIMESTAMP(2)
        default CURRENT_TIMESTAMP,
    OAREA
        SMALLINT,
    OPAGE
        INTEGER,
    OLINE
        SMALLINT,
    MAREA
        SMALLINT,
    MPAGE
        INTEGER,
    MLINE
        SMALLINT);
 
create table PC_PITWUSET (
    DB_ID
        SMALLINT,
    NVTIMESTAMP
        TIMESTAMP(2)
        default CURRENT_TIMESTAMP,
    OAREA
        SMALLINT,
    OPAGE
        INTEGER,
    OLINE
        SMALLINT,
    MAREA
        SMALLINT,
    MPAGE
        INTEGER,
    MLINE
        SMALLINT);
 
create table PC_WKCPISET (
    DB_ID
        SMALLINT,
    NVTIMESTAMP
        TIMESTAMP(2)
        default CURRENT_TIMESTAMP,
    OAREA
        SMALLINT,
    OPAGE
        INTEGER,
    OLINE
        SMALLINT,
    MAREA
        SMALLINT,
    MPAGE
        INTEGER,
    MLINE
        SMALLINT);
 
create table PC_PIPISAFSET (
    DB_ID
        SMALLINT,
    NVTIMESTAMP
        TIMESTAMP(2)
        default CURRENT_TIMESTAMP,
    OAREA
        SMALLINT,
    OPAGE
        INTEGER,
    OLINE
        SMALLINT,
    MAREA
        SMALLINT,
    MPAGE
        INTEGER,
    MLINE
        SMALLINT);
 
create table PC_APITAPISAFSET (
    DB_ID
        SMALLINT,
    NVTIMESTAMP
        TIMESTAMP(2)
        default CURRENT_TIMESTAMP,
    OAREA
        SMALLINT,
    OPAGE
        INTEGER,
    OLINE
        SMALLINT,
    MAREA
        SMALLINT,
    MPAGE
        INTEGER,
    MLINE
        SMALLINT);
 
create table PC_PISUBPSET (
    DB_ID
        SMALLINT,
    NVTIMESTAMP
        TIMESTAMP(2)
        default CURRENT_TIMESTAMP,
    OAREA
        SMALLINT,
    OPAGE
        INTEGER,
    OLINE
        SMALLINT,
    MAREA
        SMALLINT,
    MPAGE
        INTEGER,
    MLINE
        SMALLINT);
 
create table PC_APIHHSHSET (
    DB_ID
        SMALLINT,
    NVTIMESTAMP
        TIMESTAMP(2)
        default CURRENT_TIMESTAMP,
    OAREA
        SMALLINT,
    OPAGE
        INTEGER,
    OLINE
        SMALLINT,
    MAREA
        SMALLINT,
    MPAGE
        INTEGER,
    MLINE
        SMALLINT);
 
create table PC_WKCHSHSET (
    DB_ID
        SMALLINT,
    NVTIMESTAMP
        TIMESTAMP(2)
        default CURRENT_TIMESTAMP,
    OAREA
        SMALLINT,
    OPAGE
        INTEGER,
    OLINE
        SMALLINT,
    MAREA
        SMALLINT,
    MPAGE
        INTEGER,
    MLINE
        SMALLINT);
 
create table PC_TOOHSHSET (
    DB_ID
        SMALLINT,
    NVTIMESTAMP
        TIMESTAMP(2)
        default CURRENT_TIMESTAMP,
    OAREA
        SMALLINT,
    OPAGE
        INTEGER,
    OLINE
        SMALLINT,
    MAREA
        SMALLINT,
    MPAGE
        INTEGER,
    MLINE
        SMALLINT);
 
create table PC_TOOTWUSET (
    DB_ID
        SMALLINT,
    NVTIMESTAMP
        TIMESTAMP(2)
        default CURRENT_TIMESTAMP,
    OAREA
        SMALLINT,
    OPAGE
        INTEGER,
    OLINE
        SMALLINT,
    MAREA
        SMALLINT,
    MPAGE
        INTEGER,
    MLINE
        SMALLINT);
 
create table PC_PRTMBOSET (
    DB_ID
        SMALLINT,
    NVTIMESTAMP
        TIMESTAMP(2)
        default CURRENT_TIMESTAMP,
    OAREA
        SMALLINT,
    OPAGE
        INTEGER,
    OLINE
        SMALLINT,
    MAREA
        SMALLINT,
    MPAGE
        INTEGER,
    MLINE
        SMALLINT);
 
create table PC_MBOMINGSET (
    DB_ID
        SMALLINT,
    NVTIMESTAMP
        TIMESTAMP(2)
        default CURRENT_TIMESTAMP,
    OAREA
        SMALLINT,
    OPAGE
        INTEGER,
    OLINE
        SMALLINT,
    MAREA
        SMALLINT,
    MPAGE
        INTEGER,
    MLINE
        SMALLINT);
 
create table PC_MINGMIDESSET (
    DB_ID
        SMALLINT,
    NVTIMESTAMP
        TIMESTAMP(2)
        default CURRENT_TIMESTAMP,
    OAREA
        SMALLINT,
    OPAGE
        INTEGER,
    OLINE
        SMALLINT,
    MAREA
        SMALLINT,
    MPAGE
        INTEGER,
    MLINE
        SMALLINT);
 
create table PC_MBOMENDSET (
    DB_ID
        SMALLINT,
    NVTIMESTAMP
        TIMESTAMP(2)
        default CURRENT_TIMESTAMP,
    OAREA
        SMALLINT,
    OPAGE
        INTEGER,
    OLINE
        SMALLINT,
    MAREA
        SMALLINT,
    MPAGE
        INTEGER,
    MLINE
        SMALLINT);
 
create table PC_MBOMBODESSET (
    DB_ID
        SMALLINT,
    NVTIMESTAMP
        TIMESTAMP(2)
        default CURRENT_TIMESTAMP,
    OAREA
        SMALLINT,
    OPAGE
        INTEGER,
    OLINE
        SMALLINT,
    MAREA
        SMALLINT,
    MPAGE
        INTEGER,
    MLINE
        SMALLINT);
 
create table PC_MBOMPISET (
    DB_ID
        SMALLINT,
    NVTIMESTAMP
        TIMESTAMP(2)
        default CURRENT_TIMESTAMP,
    OAREA
        SMALLINT,
    OPAGE
        INTEGER,
    OLINE
        SMALLINT,
    MAREA
        SMALLINT,
    MPAGE
        INTEGER,
    MLINE
        SMALLINT);
 
create table PC_MPIMPIDESSET (
    DB_ID
        SMALLINT,
    NVTIMESTAMP
        TIMESTAMP(2)
        default CURRENT_TIMESTAMP,
    OAREA
        SMALLINT,
    OPAGE
        INTEGER,
    OLINE
        SMALLINT,
    MAREA
        SMALLINT,
    MPAGE
        INTEGER,
    MLINE
        SMALLINT);
 
create table PC_MPIMPISAFSET (
    DB_ID
        SMALLINT,
    NVTIMESTAMP
        TIMESTAMP(2)
        default CURRENT_TIMESTAMP,
    OAREA
        SMALLINT,
    OPAGE
        INTEGER,
    OLINE
        SMALLINT,
    MAREA
        SMALLINT,
    MPAGE
        INTEGER,
    MLINE
        SMALLINT);
 
create table PC_WKCMPISET (
    DB_ID
        SMALLINT,
    NVTIMESTAMP
        TIMESTAMP(2)
        default CURRENT_TIMESTAMP,
    OAREA
        SMALLINT,
    OPAGE
        INTEGER,
    OLINE
        SMALLINT,
    MAREA
        SMALLINT,
    MPAGE
        INTEGER,
    MLINE
        SMALLINT);
 
create table PC_MPITWUSET (
    DB_ID
        SMALLINT,
    NVTIMESTAMP
        TIMESTAMP(2)
        default CURRENT_TIMESTAMP,
    OAREA
        SMALLINT,
    OPAGE
        INTEGER,
    OLINE
        SMALLINT,
    MAREA
        SMALLINT,
    MPAGE
        INTEGER,
    MLINE
        SMALLINT);
 
create table PC_MENDMCSTSET (
    DB_ID
        SMALLINT,
    NVTIMESTAMP
        TIMESTAMP(2)
        default CURRENT_TIMESTAMP,
    OAREA
        SMALLINT,
    OPAGE
        INTEGER,
    OLINE
        SMALLINT,
    MAREA
        SMALLINT,
    MPAGE
        INTEGER,
    MLINE
        SMALLINT);
 
create table PC_MBOWOHSET (
    DB_ID
        SMALLINT,
    NVTIMESTAMP
        TIMESTAMP(2)
        default CURRENT_TIMESTAMP,
    OAREA
        SMALLINT,
    OPAGE
        INTEGER,
    OLINE
        SMALLINT,
    MAREA
        SMALLINT,
    MPAGE
        INTEGER,
    MLINE
        SMALLINT);
 
create table PC_MBOHSHSET (
    DB_ID
        SMALLINT,
    NVTIMESTAMP
        TIMESTAMP(2)
        default CURRENT_TIMESTAMP,
    OAREA
        SMALLINT,
    OPAGE
        INTEGER,
    OLINE
        SMALLINT,
    MAREA
        SMALLINT,
    MPAGE
        INTEGER,
    MLINE
        SMALLINT);
 
create table PC_WOHHSHSET (
    DB_ID
        SMALLINT,
    NVTIMESTAMP
        TIMESTAMP(2)
        default CURRENT_TIMESTAMP,
    OAREA
        SMALLINT,
    OPAGE
        INTEGER,
    OLINE
        SMALLINT,
    MAREA
        SMALLINT,
    MPAGE
        INTEGER,
    MLINE
        SMALLINT);
 
create table PC_WOHWODSET (
    DB_ID
        SMALLINT,
    NVTIMESTAMP
        TIMESTAMP(2)
        default CURRENT_TIMESTAMP,
    OAREA
        SMALLINT,
    OPAGE
        INTEGER,
    OLINE
        SMALLINT,
    MAREA
        SMALLINT,
    MPAGE
        INTEGER,
    MLINE
        SMALLINT);
 
create table PC_PRTWODSET (
    DB_ID
        SMALLINT,
    NVTIMESTAMP
        TIMESTAMP(2)
        default CURRENT_TIMESTAMP,
    OAREA
        SMALLINT,
    OPAGE
        INTEGER,
    OLINE
        SMALLINT,
    MAREA
        SMALLINT,
    MPAGE
        INTEGER,
    MLINE
        SMALLINT);
 
create table PC_TRKNOHSHSET (
    DB_ID
        SMALLINT,
    NVTIMESTAMP
        TIMESTAMP(2)
        default CURRENT_TIMESTAMP,
    OAREA
        SMALLINT,
    OPAGE
        INTEGER,
    OLINE
        SMALLINT,
    MAREA
        SMALLINT,
    MPAGE
        INTEGER,
    MLINE
        SMALLINT);
 
create table PC_TRKNOTRKSET (
    DB_ID
        SMALLINT,
    NVTIMESTAMP
        TIMESTAMP(2)
        default CURRENT_TIMESTAMP,
    OAREA
        SMALLINT,
    OPAGE
        INTEGER,
    OLINE
        SMALLINT,
    MAREA
        SMALLINT,
    MPAGE
        INTEGER,
    MLINE
        SMALLINT);
 
create table PC_TRKTRKNOTSET (
    DB_ID
        SMALLINT,
    NVTIMESTAMP
        TIMESTAMP(2)
        default CURRENT_TIMESTAMP,
    OAREA
        SMALLINT,
    OPAGE
        INTEGER,
    OLINE
        SMALLINT,
    MAREA
        SMALLINT,
    MPAGE
        INTEGER,
    MLINE
        SMALLINT);
 
create table PC_PRTHSHSET (
    DB_ID
        SMALLINT,
    NVTIMESTAMP
        TIMESTAMP(2)
        default CURRENT_TIMESTAMP,
    OAREA
        SMALLINT,
    OPAGE
        INTEGER,
    OLINE
        SMALLINT,
    MAREA
        SMALLINT,
    MPAGE
        INTEGER,
    MLINE
        SMALLINT);
 
create table PC_FCOHHSHSET (
    DB_ID
        SMALLINT,
    NVTIMESTAMP
        TIMESTAMP(2)
        default CURRENT_TIMESTAMP,
    OAREA
        SMALLINT,
    OPAGE
        INTEGER,
    OLINE
        SMALLINT,
    MAREA
        SMALLINT,
    MPAGE
        INTEGER,
    MLINE
        SMALLINT);
 
create table PC_FCOHFCODSET (
    DB_ID
        SMALLINT,
    NVTIMESTAMP
        TIMESTAMP(2)
        default CURRENT_TIMESTAMP,
    OAREA
        SMALLINT,
    OPAGE
        INTEGER,
    OLINE
        SMALLINT,
    MAREA
        SMALLINT,
    MPAGE
        INTEGER,
    MLINE
        SMALLINT);
 
create table PC_FCOHFCODESSET (
    DB_ID
        SMALLINT,
    NVTIMESTAMP
        TIMESTAMP(2)
        default CURRENT_TIMESTAMP,
    OAREA
        SMALLINT,
    OPAGE
        INTEGER,
    OLINE
        SMALLINT,
    MAREA
        SMALLINT,
    MPAGE
        INTEGER,
    MLINE
        SMALLINT);
 
create table PC_PRTFCODSET (
    DB_ID
        SMALLINT,
    NVTIMESTAMP
        TIMESTAMP(2)
        default CURRENT_TIMESTAMP,
    OAREA
        SMALLINT,
    OPAGE
        INTEGER,
    OLINE
        SMALLINT,
    MAREA
        SMALLINT,
    MPAGE
        INTEGER,
    MLINE
        SMALLINT);
 
create table PC_FRMFCODSET (
    DB_ID
        SMALLINT,
    NVTIMESTAMP
        TIMESTAMP(2)
        default CURRENT_TIMESTAMP,
    OAREA
        SMALLINT,
    OPAGE
        INTEGER,
    OLINE
        SMALLINT,
    MAREA
        SMALLINT,
    MPAGE
        INTEGER,
    MLINE
        SMALLINT);
 
create table PC_USRHSHSET (
    DB_ID
        SMALLINT,
    NVTIMESTAMP
        TIMESTAMP(2)
        default CURRENT_TIMESTAMP,
    OAREA
        SMALLINT,
    OPAGE
        INTEGER,
    OLINE
        SMALLINT,
    MAREA
        SMALLINT,
    MPAGE
        INTEGER,
    MLINE
        SMALLINT);
 
create table PC_USRFRMPVSET (
    DB_ID
        SMALLINT,
    NVTIMESTAMP
        TIMESTAMP(2)
        default CURRENT_TIMESTAMP,
    OAREA
        SMALLINT,
    OPAGE
        INTEGER,
    OLINE
        SMALLINT,
    MAREA
        SMALLINT,
    MPAGE
        INTEGER,
    MLINE
        SMALLINT);
 
create table PC_FRMPVHSHSET (
    DB_ID
        SMALLINT,
    NVTIMESTAMP
        TIMESTAMP(2)
        default CURRENT_TIMESTAMP,
    OAREA
        SMALLINT,
    OPAGE
        INTEGER,
    OLINE
        SMALLINT,
    MAREA
        SMALLINT,
    MPAGE
        INTEGER,
    MLINE
        SMALLINT);
 
create table PC_CATFRMPVSET (
    DB_ID
        SMALLINT,
    NVTIMESTAMP
        TIMESTAMP(2)
        default CURRENT_TIMESTAMP,
    OAREA
        SMALLINT,
    OPAGE
        INTEGER,
    OLINE
        SMALLINT,
    MAREA
        SMALLINT,
    MPAGE
        INTEGER,
    MLINE
        SMALLINT);
 
create table PC_WKCAPITSET (
    DB_ID
        SMALLINT,
    NVTIMESTAMP
        TIMESTAMP(2)
        default CURRENT_TIMESTAMP,
    OAREA
        SMALLINT,
    OPAGE
        INTEGER,
    OLINE
        SMALLINT,
    MAREA
        SMALLINT,
    MPAGE
        INTEGER,
    MLINE
        SMALLINT);
 
create table PC_APITTWUSET (
    DB_ID
        SMALLINT,
    NVTIMESTAMP
        TIMESTAMP(2)
        default CURRENT_TIMESTAMP,
    OAREA
        SMALLINT,
    OPAGE
        INTEGER,
    OLINE
        SMALLINT,
    MAREA
        SMALLINT,
    MPAGE
        INTEGER,
    MLINE
        SMALLINT);
 
create table PC_IXHSHSET (
    DB_ID
        SMALLINT,
    NVTIMESTAMP
        TIMESTAMP(2)
        default CURRENT_TIMESTAMP,
    OAREA
        SMALLINT,
    OPAGE
        INTEGER,
    OLINE
        SMALLINT,
    MAREA
        SMALLINT,
    MPAGE
        INTEGER,
    MLINE
        SMALLINT);
 
create table PC_PRTMENDSET (
    DB_ID
        SMALLINT,
    NVTIMESTAMP
        TIMESTAMP(2)
        default CURRENT_TIMESTAMP,
    OAREA
        SMALLINT,
    OPAGE
        INTEGER,
    OLINE
        SMALLINT,
    MAREA
        SMALLINT,
    MPAGE
        INTEGER,
    MLINE
        SMALLINT);
 
create table PC_PRTMINGSET (
    DB_ID
        SMALLINT,
    NVTIMESTAMP
        TIMESTAMP(2)
        default CURRENT_TIMESTAMP,
    OAREA
        SMALLINT,
    OPAGE
        INTEGER,
    OLINE
        SMALLINT,
    MAREA
        SMALLINT,
    MPAGE
        INTEGER,
    MLINE
        SMALLINT);
 
 

 
commit work;
 

-- RMU/EXTRACT for Oracle Rdb V7.2-200                   11-OCT-2018 10:46:58.45
--
--                              Index Definitions
--
--------------------------------------------------------------------------------
-- no indices defined

-- RMU/EXTRACT for Oracle Rdb V7.2-200                   11-OCT-2018 10:46:58.45
--
--                           Storage Map Definitions
--
--------------------------------------------------------------------------------
create storage map PC_ADFREC_MAP
    for PC_ADFREC
    store 
        in PCFRMAREA;
 
commit work;
 
create storage map PC_ADTDESREC_MAP
    for PC_ADTDESREC
    store 
        in PCFRMAREA;
 
commit work;
 
create storage map PC_ADTREC_MAP
    for PC_ADTREC
    store 
        in PCFRMAREA;
 
commit work;
 
create storage map PC_ALTHREC_MAP
    for PC_ALTHREC
    store 
        in PCFRMAREA;
 
commit work;
 
create storage map PC_APIDESREC_MAP
    for PC_APIDESREC
    store 
        in PCPIAREA;
 
commit work;
 
create storage map PC_APIFREC_MAP
    for PC_APIFREC
    store 
        in PCPIAREA;
 
commit work;
 
create storage map PC_APIHREC_MAP
    for PC_APIHREC
    store 
        in PCPIAREA;
 
commit work;
 
create storage map PC_APISAFREC_MAP
    for PC_APISAFREC
    store 
        in PCPIAREA;
 
commit work;
 
create storage map PC_APITREC_MAP
    for PC_APITREC
    store 
        in PCPIAREA;
 
commit work;
 
create storage map PC_ASTPREC_MAP
    for PC_ASTPREC
    store 
        in PCFRMAREA;
 
commit work;
 
create storage map PC_CATREC_MAP
    for PC_CATREC
    store 
        in PCFRMAREA;
 
commit work;
 
create storage map PC_CHGDREC_MAP
    for PC_CHGDREC
    store 
        in PCCHGAREA;
 
commit work;
 
create storage map PC_CHGHREC_MAP
    for PC_CHGHREC
    store 
        in PCCHGAREA;
 
commit work;
 
create storage map PC_ENDREC_MAP
    for PC_ENDREC
    store 
        in PCFRMAREA;
 
commit work;
 
create storage map PC_FCODESREC_MAP
    for PC_FCODESREC
    store 
        in PCFCOAREA;
 
commit work;
 
create storage map PC_FCODREC_MAP
    for PC_FCODREC
    store 
        in PCFCOAREA;
 
commit work;
 
create storage map PC_FCOHREC_MAP
    for PC_FCOHREC
    store 
        in PCFCOAREA;
 
commit work;
 
create storage map PC_FRMPVREC_MAP
    for PC_FRMPVREC
    store 
        in PCFRMAREA;
 
commit work;
 
create storage map PC_FRMREC_MAP
    for PC_FRMREC
    store 
        in PCFRMAREA;
 
commit work;
 
create storage map PC_HDESREC_MAP
    for PC_HDESREC
    store 
        in PCFRMAREA;
 
commit work;
 
create storage map PC_IDESREC_MAP
    for PC_IDESREC
    store 
        in PCFRMAREA;
 
commit work;
 
create storage map PC_INGREC_MAP
    for PC_INGREC
    store 
        in PCFRMAREA;
 
commit work;
 
create storage map PC_IXREC_MAP
    for PC_IXREC
    store 
        in PCFRMAREA;
 
commit work;
 
create storage map PC_MBODESREC_MAP
    for PC_MBODESREC
    store 
        in PCMBOAREA;
 
commit work;
 
create storage map PC_MBOREC_MAP
    for PC_MBOREC
    store 
        in PCMBOAREA;
 
commit work;
 
create storage map PC_MCSTREC_MAP
    for PC_MCSTREC
    store 
        in PCMBOAREA;
 
commit work;
 
create storage map PC_MENDREC_MAP
    for PC_MENDREC
    store 
        in PCMBOAREA;
 
commit work;
 
create storage map PC_MIDESREC_MAP
    for PC_MIDESREC
    store 
        in PCMBOAREA;
 
commit work;
 
create storage map PC_MINGREC_MAP
    for PC_MINGREC
    store 
        in PCMBOAREA;
 
commit work;
 
create storage map PC_MPIDESREC_MAP
    for PC_MPIDESREC
    store 
        in PCMBOAREA;
 
commit work;
 
create storage map PC_MPIREC_MAP
    for PC_MPIREC
    store 
        in PCMBOAREA;
 
commit work;
 
create storage map PC_MPISAFREC_MAP
    for PC_MPISAFREC
    store 
        in PCMBOAREA;
 
commit work;
 
create storage map PC_PIDESREC_MAP
    for PC_PIDESREC
    store 
        in PCPIAREA;
 
commit work;
 
create storage map PC_PIREC_MAP
    for PC_PIREC
    store 
        in PCPIAREA;
 
commit work;
 
create storage map PC_PISAFREC_MAP
    for PC_PISAFREC
    store 
        in PCPIAREA;
 
commit work;
 
create storage map PC_PRTREC_MAP
    for PC_PRTREC
    store 
        in PCFRMAREA;
 
commit work;
 
create storage map PC_SIFREC_MAP
    for PC_SIFREC
    store 
        in PCFRMAREA;
 
commit work;
 
create storage map PC_SLFREC_MAP
    for PC_SLFREC
    store 
        in PCFRMAREA;
 
commit work;
 
create storage map PC_SLTREC_MAP
    for PC_SLTREC
    store 
        in PCFRMAREA;
 
commit work;
 
create storage map PC_STEPREC_MAP
    for PC_STEPREC
    store 
        in PCFRMAREA;
 
commit work;
 
create storage map PC_SUBPREC_MAP
    for PC_SUBPREC
    store 
        in PCPIAREA;
 
commit work;
 
create storage map PC_TEXDREC_MAP
    for PC_TEXDREC
    store 
        in PCTEXAREA;
 
commit work;
 
create storage map PC_TEXTREC_MAP
    for PC_TEXTREC
    store 
        in PCTEXAREA;
 
commit work;
 
create storage map PC_TOOREC_MAP
    for PC_TOOREC
    store 
        in PCPIAREA;
 
commit work;
 
create storage map PC_TRKNOREC_MAP
    for PC_TRKNOREC
    store 
        in PCWOHAREA;
 
commit work;
 
create storage map PC_TRKNOTREC_MAP
    for PC_TRKNOTREC
    store 
        in PCWOHAREA;
 
commit work;
 
create storage map PC_TRKREC_MAP
    for PC_TRKREC
    store 
        in PCWOHAREA;
 
commit work;
 
create storage map PC_TWUREC_MAP
    for PC_TWUREC
    store 
        in PCPIAREA;
 
commit work;
 
create storage map PC_USRREC_MAP
    for PC_USRREC
    store 
        in PCFRMAREA;
 
commit work;
 
create storage map PC_WKCREC_MAP
    for PC_WKCREC
    store 
        in PCPIAREA;
 
commit work;
 
create storage map PC_WODREC_MAP
    for PC_WODREC
    store 
        in PCWOHAREA;
 
commit work;
 
create storage map PC_WOHREC_MAP
    for PC_WOHREC
    store 
        in PCWOHAREA;
 
commit work;
 

-- RMU/EXTRACT for Oracle Rdb V7.2-200                   11-OCT-2018 10:46:58.45
--
--                               View Definitions
--
--------------------------------------------------------------------------------
-- no views defined

-- RMU/EXTRACT for Oracle Rdb V7.2-200                   11-OCT-2018 10:46:58.45
--
--                             Trigger Definitions
--
--------------------------------------------------------------------------------
-- no triggers defined

-- RMU/EXTRACT for Oracle Rdb V7.2-200                   11-OCT-2018 10:46:58.45
--
--                              Module Definitions
--
--------------------------------------------------------------------------------
-- no modules defined

-- RMU/EXTRACT for Oracle Rdb V7.2-200                   11-OCT-2018 10:46:58.45
--
--                          Query Outline Definitions
--
--------------------------------------------------------------------------------
-- no outlines defined
