-- RMU/EXTRACT for Oracle Rdb V7.2-200                   11-OCT-2018 10:47:11.07
--
--                           Database Definition File
--
-- Source Database Name: DKA300:[ENVY.100]TRKDB.RDB;1
--------------------------------------------------------------------------------
set verify;
set language ENGLISH;
set default date format 'SQL92';
set quoting rules 'SQL92';
set date format DATE 001, TIME 001;

-- RMU/EXTRACT for Oracle Rdb V7.2-200                   11-OCT-2018 10:47:11.07
--
--                         Physical Database Definition
--
--------------------------------------------------------------------------------
create database
    filename 'DKA300:[ENVY.100]TRKDB.RDB'
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
        filename 'NV$DISK:[ENVY.100]TRKDB.RDA'
        -- read write storage area
        locking is row level
        page format is UNIFORM
        page size is 2 blocks
        allocation is 326997 pages
        extent is (minimum 1998, maximum 19998, percent growth 20)
        snapshot filename 'NV$DISK:[ENVY.100]TRKDB.SNP'
        snapshot allocation is 496 pages
        snapshot extent is (minimum 99, maximum 9999, percent growth 20)
    
    create storage area TKLOTAREA
        filename 'NV$DISK:[ENVY.100]NV_TKLOTAREA.RDA'
        -- read write storage area
        locking is row level
        page format is UNIFORM
        page size is 2 blocks
        allocation is 11991 pages
        extent is (minimum 1998, maximum 19998, percent growth 20)
        snapshot filename 'NV$DISK:[ENVY.100]NV_TKLOTAREA.SNP'
        snapshot allocation is 100 pages
        snapshot extent is (minimum 99, maximum 9999, percent growth 20)
    
    create storage area TKLIDAREA
        filename 'NV$DISK:[ENVY.100]NV_TKLIDAREA.RDA'
        -- read write storage area
        locking is row level
        page format is UNIFORM
        page size is 2 blocks
        allocation is 74277 pages
        extent is (minimum 1998, maximum 19998, percent growth 20)
        snapshot filename 'NV$DISK:[ENVY.100]NV_TKLIDAREA.SNP'
        snapshot allocation is 100 pages
        snapshot extent is (minimum 99, maximum 9999, percent growth 20)
    
    create storage area TKLTPAREA
        filename 'NV$DISK:[ENVY.100]NV_TKLTPAREA.RDA'
        -- read write storage area
        locking is row level
        page format is UNIFORM
        page size is 2 blocks
        allocation is 126957 pages
        extent is (minimum 1998, maximum 19998, percent growth 20)
        snapshot filename 'NV$DISK:[ENVY.100]NV_TKLTPAREA.SNP'
        snapshot allocation is 100 pages
        snapshot extent is (minimum 99, maximum 9999, percent growth 20)
    
    create storage area TKLTDAREA
        filename 'NV$DISK:[ENVY.100]NV_TKLTDAREA.RDA'
        -- read write storage area
        locking is row level
        page format is UNIFORM
        page size is 2 blocks
        allocation is 186951 pages
        extent is (minimum 1998, maximum 19998, percent growth 20)
        snapshot filename 'NV$DISK:[ENVY.100]NV_TKLTDAREA.SNP'
        snapshot allocation is 100 pages
        snapshot extent is (minimum 99, maximum 9999, percent growth 20)
    
    create storage area TKHDRAREA
        filename 'NV$DISK:[ENVY.100]NV_TKHDRAREA.RDA'
        -- read write storage area
        locking is row level
        page format is UNIFORM
        page size is 2 blocks
        allocation is 14391 pages
        extent is (minimum 1998, maximum 19998, percent growth 20)
        snapshot filename 'NV$DISK:[ENVY.100]NV_TKHDRAREA.SNP'
        snapshot allocation is 100 pages
        snapshot extent is (minimum 99, maximum 9999, percent growth 20)
    
    create storage area TKINTAREA
        filename 'NV$DISK:[ENVY.100]NV_TKINTAREA.RDA'
        -- read write storage area
        locking is row level
        page format is UNIFORM
        page size is 2 blocks
        allocation is 2001 pages
        extent is (minimum 1998, maximum 19998, percent growth 20)
        snapshot filename 'NV$DISK:[ENVY.100]NV_TKINTAREA.SNP'
        snapshot allocation is 100 pages
        snapshot extent is (minimum 99, maximum 9999, percent growth 20)
    
    create storage area TKFLGAREA
        filename 'NV$DISK:[ENVY.100]NV_TKFLGAREA.RDA'
        -- read write storage area
        locking is row level
        page format is UNIFORM
        page size is 2 blocks
        allocation is 3 pages
        extent is (minimum 1998, maximum 19998, percent growth 20)
        snapshot filename 'NV$DISK:[ENVY.100]NV_TKFLGAREA.SNP'
        snapshot allocation is 100 pages
        snapshot extent is (minimum 99, maximum 9999, percent growth 20)
    
    create storage area TKCNVAREA
        filename 'NV$DISK:[ENVY.100]NV_TKCNVAREA.RDA'
        -- read write storage area
        locking is row level
        page format is UNIFORM
        page size is 2 blocks
        allocation is 2001 pages
        extent is (minimum 1998, maximum 19998, percent growth 20)
        snapshot filename 'NV$DISK:[ENVY.100]NV_TKCNVAREA.SNP'
        snapshot allocation is 100 pages
        snapshot extent is (minimum 99, maximum 9999, percent growth 20)
    
    create storage area TKUPRTAREA
        filename 'NV$DISK:[ENVY.100]NV_TKUPRTAREA.RDA'
        -- read write storage area
        locking is row level
        page format is UNIFORM
        page size is 2 blocks
        allocation is 2001 pages
        extent is (minimum 1998, maximum 19998, percent growth 20)
        snapshot filename 'NV$DISK:[ENVY.100]NV_TKUPRTAREA.SNP'
        snapshot allocation is 100 pages
        snapshot extent is (minimum 99, maximum 9999, percent growth 20)
    
    create storage area TKUHSTAREA
        filename 'NV$DISK:[ENVY.100]NV_TKUHSTAREA.RDA'
        -- read write storage area
        locking is row level
        page format is UNIFORM
        page size is 2 blocks
        allocation is 2001 pages
        extent is (minimum 1998, maximum 19998, percent growth 20)
        snapshot filename 'NV$DISK:[ENVY.100]NV_TKUHSTAREA.SNP'
        snapshot allocation is 100 pages
        snapshot extent is (minimum 99, maximum 9999, percent growth 20)
; -- end create database

-- RMU/EXTRACT for Oracle Rdb V7.2-200                   11-OCT-2018 10:47:11.07
--
--                                  Sequences
--
--------------------------------------------------------------------------------
-- no sequences defined

-- RMU/EXTRACT for Oracle Rdb V7.2-200                   11-OCT-2018 10:47:11.07
--
--                             Collating Sequences
--
--------------------------------------------------------------------------------
-- no collating sequences defined

-- RMU/EXTRACT for Oracle Rdb V7.2-200                   11-OCT-2018 10:47:11.07
--
--                              Domain Definitions
--
--------------------------------------------------------------------------------
-- no domains defined

-- RMU/EXTRACT for Oracle Rdb V7.2-200                   11-OCT-2018 10:47:11.07
--
--                             Function Definitions
--
--------------------------------------------------------------------------------
-- no functions defined

-- RMU/EXTRACT for Oracle Rdb V7.2-200                   11-OCT-2018 10:47:11.07
--
--                            Procedure Definitions
--
--------------------------------------------------------------------------------
-- no procedures defined

-- RMU/EXTRACT for Oracle Rdb V7.2-200                   11-OCT-2018 10:47:11.07
--
--                              Table Definitions
--
--------------------------------------------------------------------------------
create table TK_LOTREC (
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
    TK_LOTNO
        CHAR (24));
 
create table TK_PRTREC (
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
    TK_PRTNO
        CHAR (18),
    TK_PRTMUQ
        DOUBLE PRECISION,
    TK_PRTLCFLG
        SMALLINT);
 
create table TK_LTFREC (
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
    TK_LTFVALUE
        CHAR (4),
    TK_LTFUSR
        CHAR (12),
    TK_LTFDAT
        INTEGER,
    TK_LTFTIM
        CHAR (8),
    TK_LTFCMD
        CHAR (6),
    TK_PRTNO
        CHAR (18));
 
create table TK_LIDREC (
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
    TK_LIDLOT
        CHAR (24),
    TK_LIDPRT
        CHAR (18),
    TK_LIDLOTDESC
        CHAR (30),
    TK_LIDPRTDESC
        CHAR (30),
    TK_LIDPRTREV
        CHAR (2),
    TK_LIDPRTSC
        CHAR (2),
    TK_LIDPRTUOM
        CHAR (2),
    TK_LIDACCCODE
        SMALLINT,
    TK_LIDACCTYPE
        SMALLINT,
    TK_LIDEXPDAT
        INTEGER,
    TK_LIDRECQTY
        DOUBLE PRECISION,
    TK_LIDISSQTY
        DOUBLE PRECISION,
    TK_LIDSCRPQTY
        DOUBLE PRECISION,
    TK_LIDRTVQTY
        DOUBLE PRECISION,
    TK_LIDCRDAT
        INTEGER,
    TK_LIDISSDAT
        INTEGER,
    TK_LIDRECDAT
        INTEGER,
    TK_LIDARCDAT
        INTEGER,
    TK_LIDARCISSQTY
        DOUBLE PRECISION,
    TK_LIDARCRECQTY
        DOUBLE PRECISION,
    TK_LIDUSRFLD1
        CHAR (30),
    TK_LIDUSRFLD2
        CHAR (30),
    TK_LIDUSRFLD3
        CHAR (30),
    TK_LIDUSRFLD4
        CHAR (30),
    TK_LIDARCCODDESC
        CHAR (30),
    TK_LIDPOT
        SMALLINT,
    TK_LIDMUQ
        DOUBLE PRECISION,
    TK_LIDLOTUOM
        CHAR (2),
    TK_LIDACTCOD1
        SMALLINT,
    TK_LIDACTDAT1
        INTEGER,
    TK_LIDACTCOD2
        SMALLINT,
    TK_LIDACTDAT2
        INTEGER,
    TK_LOTNO
        CHAR (24),
    TK_PRTNO
        CHAR (18));
 
create table TK_NOTREC (
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
    TK_NOTDESC
        CHAR (70),
    TK_NOTCODE
        SMALLINT,
    TK_LIDLOT
        CHAR (24));
 
create table TK_LTPREC (
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
    TK_LTPLOT
        CHAR (24),
    TK_LTPPRT
        CHAR (18),
    TK_LTPTYPE
        SMALLINT,
    TK_LTPKEY1
        CHAR (10),
    TK_LTPKEY2
        CHAR (10),
    TK_LTPKEY3
        CHAR (24),
    TK_LTPSUBTYPE
        SMALLINT,
    TK_LTPRECQTY
        DOUBLE PRECISION,
    TK_LTPISSQTY
        DOUBLE PRECISION,
    TK_LTPSCRPQTY
        DOUBLE PRECISION,
    TK_LTPRTVQTY
        DOUBLE PRECISION,
    TK_LTPCRDAT
        INTEGER,
    TK_LTPISSDAT
        INTEGER,
    TK_LTPRECDAT
        INTEGER,
    TK_LTPARCISSQTY
        DOUBLE PRECISION,
    TK_LTPARCRECQTY
        DOUBLE PRECISION,
    TK_LTPARCSCRPQTY
        DOUBLE PRECISION,
    TK_LTPARCRTVQTY
        DOUBLE PRECISION,
    TK_LTPPOLINE
        INTEGER,
    TK_LIDLOT
        CHAR (24),
    TK_HDRCODE
        SMALLINT);
 
create table TK_LTDREC (
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
    TK_LTDISSQTY
        DOUBLE PRECISION,
    TK_LTDDAT
        INTEGER,
    TK_LTDCMD
        CHAR (6),
    TK_LTDARCFLG
        SMALLINT,
    TK_LTPLOT
        CHAR (24),
    TK_LTPLOT15
        CHAR (24));
 
create table TK_TYPREC (
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
    TK_TYPCODE
        SMALLINT,
    TK_TYPNO
        CHAR (10),
    TK_TYPNAME
        CHAR (30),
    TK_TYPCUSNO
        CHAR (10));
 
create table TK_HDRREC (
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
    TK_HDRCODE
        SMALLINT,
    TK_HDRNO
        CHAR (24),
    TK_HDRKEY1
        CHAR (10),
    TK_TYPCODE
        SMALLINT);
 
create table TK_INTREC (
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
    TK_INTFLOT
        CHAR (24),
    TK_INTFPRT
        CHAR (18),
    TK_INTFLOTTYPE
        SMALLINT,
    TK_INTFWAR
        CHAR (10),
    TK_INTFLOC
        CHAR (10),
    TK_INTFQTY
        DOUBLE PRECISION,
    TK_INTTLOT
        CHAR (24),
    TK_INTTPRT
        CHAR (18),
    TK_INTTLOTTYPE
        SMALLINT,
    TK_INTTWAR
        CHAR (10),
    TK_INTTLOC
        CHAR (10),
    TK_INTTQTY
        DOUBLE PRECISION,
    TK_INTDAT
        INTEGER,
    TK_INTCMD
        CHAR (6),
    TK_INTORDNO
        CHAR (10),
    TK_INTSUBORDNO
        CHAR (10),
    TK_INTCODE
        CHAR (10),
    TK_INTNAME
        CHAR (30),
    TK_INTTIME
        CHAR (8),
    TK_INTPOLINE
        INTEGER,
    TK_INTCHNSET
        SMALLINT,
    TK_INTTOHSHSET
        SMALLINT,
    TK_INTFMHSHSET
        SMALLINT,
    TK_INTPOSRTSET
        SMALLINT,
    TK_INTSOHSHSET
        SMALLINT);
 
create table TK_FLGREC (
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
    TK_FLGNO
        SMALLINT,
    TK_FLGVALU
        CHAR (30));
 
create table TK_CNVREC (
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
    TK_CNVPRT
        CHAR (18),
    TK_CNVFUOM
        CHAR (2),
    TK_CNVTUOM
        CHAR (2),
    TK_CNVFCTR
        DOUBLE PRECISION,
    TK_CNVRCP
        DOUBLE PRECISION,
    TK_CNVTYP
        SMALLINT);
 
create table TK_PRCREC (
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
    TK_PRCUOM
        CHAR (2),
    TK_PRCRND
        SMALLINT);
 
create table TK_UPRTREC (
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
    TK_UPRTNO
        CHAR (18));
 
create table TK_ULSTREC (
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
    TK_ULSTUOM
        CHAR (2),
    TK_UPRTNO
        CHAR (18));
 
create table TK_UHSTREC (
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
    TK_UHSTDATE
        INTEGER,
    TK_UHSTTIME
        CHAR (8),
    TK_UHSTUSER
        CHAR (12),
    TK_UHSTCMD
        CHAR (6),
    TK_UHSTOLDPRT
        CHAR (18),
    TK_UHSTNEWPRT
        CHAR (18),
    TK_UHSTOLDFUOM
        CHAR (2),
    TK_UHSTNEWFUOM
        CHAR (2),
    TK_UHSTOLDTUOM
        CHAR (2),
    TK_UHSTNEWTUOM
        CHAR (2),
    TK_UHSTOLDFCTR
        DOUBLE PRECISION,
    TK_UHSTNEWFCTR
        DOUBLE PRECISION);
 
 

 
create table TK_PRTHSHSET (
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
 
create table TK_LOTHSHSET (
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
 
create table TK_LIDHSHSET (
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
 
create table TK_LTPHSHSET (
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
 
create table TK_TYPHSHSET (
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
 
create table TK_HDRHSHSET (
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
 
create table TK_LOTLIDSET (
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
 
create table TK_PRTLIDSET (
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
 
create table TK_PRTLTFSET (
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
 
create table TK_LIDLTPSET (
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
 
create table TK_TYPHDRSET (
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
 
create table TK_HDRLTPSET (
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
 
create table TK_LIDNOTSET (
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
 
create table TK_LTPBOMSET (
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
 
create table TK_LTPCOMSET (
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
 
create table TK_INTCHNSET (
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
 
create table TK_INTTOHSHSET (
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
 
create table TK_INTFMHSHSET (
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
 
create table TK_FLGHSHSET (
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
 
create table TK_CNVHSHSET (
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
 
create table TK_PRCHSHSET (
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
 
create table TK_UPRTHSHSET (
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
 
create table TK_UPRTULSTSET (
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
 
create table TK_UHSTCHNSET (
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
 
create table TK_INTPOSRTSET (
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
 
create table TK_INTSOHSHSET (
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
 

 

-- RMU/EXTRACT for Oracle Rdb V7.2-200                   11-OCT-2018 10:47:11.07
--
--                              Index Definitions
--
--------------------------------------------------------------------------------
-- no indices defined

-- RMU/EXTRACT for Oracle Rdb V7.2-200                   11-OCT-2018 10:47:11.07
--
--                           Storage Map Definitions
--
--------------------------------------------------------------------------------
create storage map TK_CNVREC_MAP
    for TK_CNVREC
    store 
        in TKCNVAREA;
 
commit work;
 
create storage map TK_FLGREC_MAP
    for TK_FLGREC
    store 
        in TKFLGAREA;
 
commit work;
 
create storage map TK_HDRREC_MAP
    for TK_HDRREC
    store 
        in TKHDRAREA;
 
commit work;
 
create storage map TK_INTREC_MAP
    for TK_INTREC
    store 
        in TKINTAREA;
 
commit work;
 
create storage map TK_LIDREC_MAP
    for TK_LIDREC
    store 
        in TKLIDAREA;
 
commit work;
 
create storage map TK_LOTREC_MAP
    for TK_LOTREC
    store 
        in TKLOTAREA;
 
commit work;
 
create storage map TK_LTDREC_MAP
    for TK_LTDREC
    store 
        in TKLTDAREA;
 
commit work;
 
create storage map TK_LTFREC_MAP
    for TK_LTFREC
    store 
        in TKLOTAREA;
 
commit work;
 
create storage map TK_LTPREC_MAP
    for TK_LTPREC
    store 
        in TKLTPAREA;
 
commit work;
 
create storage map TK_NOTREC_MAP
    for TK_NOTREC
    store 
        in TKLIDAREA;
 
commit work;
 
create storage map TK_PRCREC_MAP
    for TK_PRCREC
    store 
        in TKUPRTAREA;
 
commit work;
 
create storage map TK_PRTREC_MAP
    for TK_PRTREC
    store 
        in TKLOTAREA;
 
commit work;
 
create storage map TK_TYPREC_MAP
    for TK_TYPREC
    store 
        in TKHDRAREA;
 
commit work;
 
create storage map TK_UHSTREC_MAP
    for TK_UHSTREC
    store 
        in TKUHSTAREA;
 
commit work;
 
create storage map TK_ULSTREC_MAP
    for TK_ULSTREC
    store 
        in TKUPRTAREA;
 
commit work;
 
create storage map TK_UPRTREC_MAP
    for TK_UPRTREC
    store 
        in TKUPRTAREA;
 
commit work;
 

-- RMU/EXTRACT for Oracle Rdb V7.2-200                   11-OCT-2018 10:47:11.07
--
--                               View Definitions
--
--------------------------------------------------------------------------------
-- no views defined

-- RMU/EXTRACT for Oracle Rdb V7.2-200                   11-OCT-2018 10:47:11.07
--
--                             Trigger Definitions
--
--------------------------------------------------------------------------------
-- no triggers defined

-- RMU/EXTRACT for Oracle Rdb V7.2-200                   11-OCT-2018 10:47:11.07
--
--                              Module Definitions
--
--------------------------------------------------------------------------------
-- no modules defined

-- RMU/EXTRACT for Oracle Rdb V7.2-200                   11-OCT-2018 10:47:11.07
--
--                          Query Outline Definitions
--
--------------------------------------------------------------------------------
-- no outlines defined
