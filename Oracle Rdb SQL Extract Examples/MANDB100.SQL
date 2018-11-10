-- RMU/EXTRACT for Oracle Rdb V7.2-200                   11-OCT-2018 10:44:00.15
--
--                           Database Definition File
--
-- Source Database Name: DKA300:[ENVY.100]MANDB.RDB;1
--------------------------------------------------------------------------------
set verify;
set language ENGLISH;
set default date format 'SQL92';
set quoting rules 'SQL92';
set date format DATE 001, TIME 001;

-- RMU/EXTRACT for Oracle Rdb V7.2-200                   11-OCT-2018 10:44:00.15
--
--                         Physical Database Definition
--
--------------------------------------------------------------------------------
create database
    filename 'DKA300:[ENVY.100]MANDB.RDB'
    protection is ACL
    number of users 300
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
        filename 'NV$DISK:[ENVY.100]MANDB.RDA'
        -- read write storage area
        locking is row level
        page format is UNIFORM
        page size is 2 blocks
        allocation is 16665363 pages
        extent is (minimum 1998, maximum 19998, percent growth 20)
        snapshot filename 'NV$DISK:[ENVY.100]MANDB.SNP'
        snapshot allocation is 7615 pages
        snapshot extent is (minimum 99, maximum 9999, percent growth 20)
    
    create storage area FLGAREA
        filename 'NV$DISK:[ENVY.100]NV_FLGAREA.RDA'
        -- read write storage area
        locking is row level
        page format is UNIFORM
        page size is 2 blocks
        allocation is 3 pages
        extent is (minimum 1998, maximum 19998, percent growth 20)
        snapshot filename 'NV$DISK:[ENVY.100]NV_FLGAREA.SNP'
        snapshot allocation is 100 pages
        snapshot extent is (minimum 99, maximum 9999, percent growth 20)
    
    create storage area PRTAREA
        filename 'NV$DISK:[ENVY.100]NV_PRTAREA.RDA'
        -- read write storage area
        locking is row level
        page format is UNIFORM
        page size is 2 blocks
        allocation is 3 pages
        extent is (minimum 1998, maximum 19998, percent growth 20)
        snapshot filename 'NV$DISK:[ENVY.100]NV_PRTAREA.SNP'
        snapshot allocation is 100 pages
        snapshot extent is (minimum 99, maximum 9999, percent growth 20)
    
    create storage area CSTAREA
        filename 'NV$DISK:[ENVY.100]NV_CSTAREA.RDA'
        -- read write storage area
        locking is row level
        page format is UNIFORM
        page size is 2 blocks
        allocation is 3 pages
        extent is (minimum 1998, maximum 19998, percent growth 20)
        snapshot filename 'NV$DISK:[ENVY.100]NV_CSTAREA.SNP'
        snapshot allocation is 100 pages
        snapshot extent is (minimum 99, maximum 9999, percent growth 20)
    
    create storage area LOCAREA
        filename 'NV$DISK:[ENVY.100]NV_LOCAREA.RDA'
        -- read write storage area
        locking is row level
        page format is UNIFORM
        page size is 2 blocks
        allocation is 3 pages
        extent is (minimum 1998, maximum 19998, percent growth 20)
        snapshot filename 'NV$DISK:[ENVY.100]NV_LOCAREA.SNP'
        snapshot allocation is 100 pages
        snapshot extent is (minimum 99, maximum 9999, percent growth 20)
    
    create storage area FORAREA
        filename 'NV$DISK:[ENVY.100]NV_FORAREA.RDA'
        -- read write storage area
        locking is row level
        page format is UNIFORM
        page size is 2 blocks
        allocation is 3 pages
        extent is (minimum 1998, maximum 19998, percent growth 20)
        snapshot filename 'NV$DISK:[ENVY.100]NV_FORAREA.SNP'
        snapshot allocation is 100 pages
        snapshot extent is (minimum 99, maximum 9999, percent growth 20)
    
    create storage area POHAREA
        filename 'NV$DISK:[ENVY.100]NV_POHAREA.RDA'
        -- read write storage area
        locking is row level
        page format is UNIFORM
        page size is 2 blocks
        allocation is 3 pages
        extent is (minimum 1998, maximum 19998, percent growth 20)
        snapshot filename 'NV$DISK:[ENVY.100]NV_POHAREA.SNP'
        snapshot allocation is 100 pages
        snapshot extent is (minimum 99, maximum 9999, percent growth 20)
    
    create storage area WOHAREA
        filename 'NV$DISK:[ENVY.100]NV_WOHAREA.RDA'
        -- read write storage area
        locking is row level
        page format is UNIFORM
        page size is 2 blocks
        allocation is 3 pages
        extent is (minimum 1998, maximum 19998, percent growth 20)
        snapshot filename 'NV$DISK:[ENVY.100]NV_WOHAREA.SNP'
        snapshot allocation is 100 pages
        snapshot extent is (minimum 99, maximum 9999, percent growth 20)
    
    create storage area EMPAREA
        filename 'NV$DISK:[ENVY.100]NV_EMPAREA.RDA'
        -- read write storage area
        locking is row level
        page format is UNIFORM
        page size is 2 blocks
        allocation is 3 pages
        extent is (minimum 1998, maximum 19998, percent growth 20)
        snapshot filename 'NV$DISK:[ENVY.100]NV_EMPAREA.SNP'
        snapshot allocation is 100 pages
        snapshot extent is (minimum 99, maximum 9999, percent growth 20)
    
    create storage area SOHAREA
        filename 'NV$DISK:[ENVY.100]NV_SOHAREA.RDA'
        -- read write storage area
        locking is row level
        page format is UNIFORM
        page size is 2 blocks
        allocation is 3 pages
        extent is (minimum 1998, maximum 19998, percent growth 20)
        snapshot filename 'NV$DISK:[ENVY.100]NV_SOHAREA.SNP'
        snapshot allocation is 100 pages
        snapshot extent is (minimum 99, maximum 9999, percent growth 20)
    
    create storage area MTRAREA
        filename 'NV$DISK:[ENVY.100]NV_MTRAREA.RDA'
        -- read write storage area
        locking is row level
        page format is UNIFORM
        page size is 2 blocks
        allocation is 3 pages
        extent is (minimum 1998, maximum 19998, percent growth 20)
        snapshot filename 'NV$DISK:[ENVY.100]NV_MTRAREA.SNP'
        snapshot allocation is 100 pages
        snapshot extent is (minimum 99, maximum 9999, percent growth 20)
    
    create storage area BOMAREA
        filename 'NV$DISK:[ENVY.100]NV_BOMAREA.RDA'
        -- read write storage area
        locking is row level
        page format is UNIFORM
        page size is 2 blocks
        allocation is 3 pages
        extent is (minimum 1998, maximum 19998, percent growth 20)
        snapshot filename 'NV$DISK:[ENVY.100]NV_BOMAREA.SNP'
        snapshot allocation is 100 pages
        snapshot extent is (minimum 99, maximum 9999, percent growth 20)
    
    create storage area ECOAREA
        filename 'NV$DISK:[ENVY.100]NV_ECOAREA.RDA'
        -- read write storage area
        locking is row level
        page format is UNIFORM
        page size is 2 blocks
        allocation is 3 pages
        extent is (minimum 1998, maximum 19998, percent growth 20)
        snapshot filename 'NV$DISK:[ENVY.100]NV_ECOAREA.SNP'
        snapshot allocation is 100 pages
        snapshot extent is (minimum 99, maximum 9999, percent growth 20)
    
    create storage area VENAREA
        filename 'NV$DISK:[ENVY.100]NV_VENAREA.RDA'
        -- read write storage area
        locking is row level
        page format is UNIFORM
        page size is 2 blocks
        allocation is 3 pages
        extent is (minimum 1998, maximum 19998, percent growth 20)
        snapshot filename 'NV$DISK:[ENVY.100]NV_VENAREA.SNP'
        snapshot allocation is 100 pages
        snapshot extent is (minimum 99, maximum 9999, percent growth 20)
    
    create storage area CALAREA
        filename 'NV$DISK:[ENVY.100]NV_CALAREA.RDA'
        -- read write storage area
        locking is row level
        page format is UNIFORM
        page size is 2 blocks
        allocation is 3 pages
        extent is (minimum 1998, maximum 19998, percent growth 20)
        snapshot filename 'NV$DISK:[ENVY.100]NV_CALAREA.SNP'
        snapshot allocation is 100 pages
        snapshot extent is (minimum 99, maximum 9999, percent growth 20)
    
    create storage area ACTAREA
        filename 'NV$DISK:[ENVY.100]NV_ACTAREA.RDA'
        -- read write storage area
        locking is row level
        page format is UNIFORM
        page size is 2 blocks
        allocation is 3 pages
        extent is (minimum 1998, maximum 19998, percent growth 20)
        snapshot filename 'NV$DISK:[ENVY.100]NV_ACTAREA.SNP'
        snapshot allocation is 100 pages
        snapshot extent is (minimum 99, maximum 9999, percent growth 20)
    
    create storage area RTGAREA
        filename 'NV$DISK:[ENVY.100]NV_RTGAREA.RDA'
        -- read write storage area
        locking is row level
        page format is UNIFORM
        page size is 2 blocks
        allocation is 3 pages
        extent is (minimum 1998, maximum 19998, percent growth 20)
        snapshot filename 'NV$DISK:[ENVY.100]NV_RTGAREA.SNP'
        snapshot allocation is 100 pages
        snapshot extent is (minimum 99, maximum 9999, percent growth 20)
    
    create storage area SPNAREA
        filename 'NV$DISK:[ENVY.100]NV_SPNAREA.RDA'
        -- read write storage area
        locking is row level
        page format is UNIFORM
        page size is 2 blocks
        allocation is 3 pages
        extent is (minimum 1998, maximum 19998, percent growth 20)
        snapshot filename 'NV$DISK:[ENVY.100]NV_SPNAREA.SNP'
        snapshot allocation is 100 pages
        snapshot extent is (minimum 99, maximum 9999, percent growth 20)
    
    create storage area MRQAREA
        filename 'NV$DISK:[ENVY.100]NV_MRQAREA.RDA'
        -- read write storage area
        locking is row level
        page format is UNIFORM
        page size is 2 blocks
        allocation is 3 pages
        extent is (minimum 1998, maximum 19998, percent growth 20)
        snapshot filename 'NV$DISK:[ENVY.100]NV_MRQAREA.SNP'
        snapshot allocation is 100 pages
        snapshot extent is (minimum 99, maximum 9999, percent growth 20)
    
    create storage area MAACTAREA
        filename 'NV$DISK:[ENVY.100]NV_MAACTAREA.RDA'
        -- read write storage area
        locking is row level
        page format is UNIFORM
        page size is 2 blocks
        allocation is 3 pages
        extent is (minimum 1998, maximum 19998, percent growth 20)
        snapshot filename 'NV$DISK:[ENVY.100]NV_MAACTAREA.SNP'
        snapshot allocation is 100 pages
        snapshot extent is (minimum 99, maximum 9999, percent growth 20)
    
    create storage area MASTGAREA
        filename 'NV$DISK:[ENVY.100]NV_MASTGAREA.RDA'
        -- read write storage area
        locking is row level
        page format is UNIFORM
        page size is 2 blocks
        allocation is 3 pages
        extent is (minimum 1998, maximum 19998, percent growth 20)
        snapshot filename 'NV$DISK:[ENVY.100]NV_MASTGAREA.SNP'
        snapshot allocation is 100 pages
        snapshot extent is (minimum 99, maximum 9999, percent growth 20)
    
    create storage area MAAPCAREA
        filename 'NV$DISK:[ENVY.100]NV_MAAPCAREA.RDA'
        -- read write storage area
        locking is row level
        page format is UNIFORM
        page size is 2 blocks
        allocation is 3 pages
        extent is (minimum 1998, maximum 19998, percent growth 20)
        snapshot filename 'NV$DISK:[ENVY.100]NV_MAAPCAREA.SNP'
        snapshot allocation is 100 pages
        snapshot extent is (minimum 99, maximum 9999, percent growth 20)
    
    create storage area MABILAREA
        filename 'NV$DISK:[ENVY.100]NV_MABILAREA.RDA'
        -- read write storage area
        locking is row level
        page format is UNIFORM
        page size is 2 blocks
        allocation is 3 pages
        extent is (minimum 1998, maximum 19998, percent growth 20)
        snapshot filename 'NV$DISK:[ENVY.100]NV_MABILAREA.SNP'
        snapshot allocation is 100 pages
        snapshot extent is (minimum 99, maximum 9999, percent growth 20)
    
    create storage area MABUKAREA
        filename 'NV$DISK:[ENVY.100]NV_MABUKAREA.RDA'
        -- read write storage area
        locking is row level
        page format is UNIFORM
        page size is 2 blocks
        allocation is 3 pages
        extent is (minimum 1998, maximum 19998, percent growth 20)
        snapshot filename 'NV$DISK:[ENVY.100]NV_MABUKAREA.SNP'
        snapshot allocation is 100 pages
        snapshot extent is (minimum 99, maximum 9999, percent growth 20)
    
    create storage area MACHGAREA
        filename 'NV$DISK:[ENVY.100]NV_MACHGAREA.RDA'
        -- read write storage area
        locking is row level
        page format is UNIFORM
        page size is 2 blocks
        allocation is 3 pages
        extent is (minimum 1998, maximum 19998, percent growth 20)
        snapshot filename 'NV$DISK:[ENVY.100]NV_MACHGAREA.SNP'
        snapshot allocation is 100 pages
        snapshot extent is (minimum 99, maximum 9999, percent growth 20)
    
    create storage area MACMAREA
        filename 'NV$DISK:[ENVY.100]NV_MACMAREA.RDA'
        -- read write storage area
        locking is row level
        page format is UNIFORM
        page size is 2 blocks
        allocation is 3 pages
        extent is (minimum 1998, maximum 19998, percent growth 20)
        snapshot filename 'NV$DISK:[ENVY.100]NV_MACMAREA.SNP'
        snapshot allocation is 100 pages
        snapshot extent is (minimum 99, maximum 9999, percent growth 20)
    
    create storage area MACOMAREA
        filename 'NV$DISK:[ENVY.100]NV_MACOMAREA.RDA'
        -- read write storage area
        locking is row level
        page format is UNIFORM
        page size is 2 blocks
        allocation is 3 pages
        extent is (minimum 1998, maximum 19998, percent growth 20)
        snapshot filename 'NV$DISK:[ENVY.100]NV_MACOMAREA.SNP'
        snapshot allocation is 100 pages
        snapshot extent is (minimum 99, maximum 9999, percent growth 20)
    
    create storage area MACUSAREA
        filename 'NV$DISK:[ENVY.100]NV_MACUSAREA.RDA'
        -- read write storage area
        locking is row level
        page format is UNIFORM
        page size is 2 blocks
        allocation is 3 pages
        extent is (minimum 1998, maximum 19998, percent growth 20)
        snapshot filename 'NV$DISK:[ENVY.100]NV_MACUSAREA.SNP'
        snapshot allocation is 100 pages
        snapshot extent is (minimum 99, maximum 9999, percent growth 20)
    
    create storage area MADMAREA
        filename 'NV$DISK:[ENVY.100]NV_MADMAREA.RDA'
        -- read write storage area
        locking is row level
        page format is UNIFORM
        page size is 2 blocks
        allocation is 3 pages
        extent is (minimum 1998, maximum 19998, percent growth 20)
        snapshot filename 'NV$DISK:[ENVY.100]NV_MADMAREA.SNP'
        snapshot allocation is 100 pages
        snapshot extent is (minimum 99, maximum 9999, percent growth 20)
    
    create storage area MAINDAREA
        filename 'NV$DISK:[ENVY.100]NV_MAINDAREA.RDA'
        -- read write storage area
        locking is row level
        page format is UNIFORM
        page size is 2 blocks
        allocation is 3 pages
        extent is (minimum 1998, maximum 19998, percent growth 20)
        snapshot filename 'NV$DISK:[ENVY.100]NV_MAINDAREA.SNP'
        snapshot allocation is 100 pages
        snapshot extent is (minimum 99, maximum 9999, percent growth 20)
    
    create storage area MAINHAREA
        filename 'NV$DISK:[ENVY.100]NV_MAINHAREA.RDA'
        -- read write storage area
        locking is row level
        page format is UNIFORM
        page size is 2 blocks
        allocation is 3 pages
        extent is (minimum 1998, maximum 19998, percent growth 20)
        snapshot filename 'NV$DISK:[ENVY.100]NV_MAINHAREA.SNP'
        snapshot allocation is 100 pages
        snapshot extent is (minimum 99, maximum 9999, percent growth 20)
    
    create storage area MANOTAREA
        filename 'NV$DISK:[ENVY.100]NV_MANOTAREA.RDA'
        -- read write storage area
        locking is row level
        page format is UNIFORM
        page size is 2 blocks
        allocation is 3 pages
        extent is (minimum 1998, maximum 19998, percent growth 20)
        snapshot filename 'NV$DISK:[ENVY.100]NV_MANOTAREA.SNP'
        snapshot allocation is 100 pages
        snapshot extent is (minimum 99, maximum 9999, percent growth 20)
    
    create storage area MAPROAREA
        filename 'NV$DISK:[ENVY.100]NV_MAPROAREA.RDA'
        -- read write storage area
        locking is row level
        page format is UNIFORM
        page size is 2 blocks
        allocation is 3 pages
        extent is (minimum 1998, maximum 19998, percent growth 20)
        snapshot filename 'NV$DISK:[ENVY.100]NV_MAPROAREA.SNP'
        snapshot allocation is 100 pages
        snapshot extent is (minimum 99, maximum 9999, percent growth 20)
    
    create storage area MAPRJAREA
        filename 'NV$DISK:[ENVY.100]NV_MAPRJAREA.RDA'
        -- read write storage area
        locking is row level
        page format is UNIFORM
        page size is 2 blocks
        allocation is 3 pages
        extent is (minimum 1998, maximum 19998, percent growth 20)
        snapshot filename 'NV$DISK:[ENVY.100]NV_MAPRJAREA.SNP'
        snapshot allocation is 100 pages
        snapshot extent is (minimum 99, maximum 9999, percent growth 20)
    
    create storage area MAPSTAREA
        filename 'NV$DISK:[ENVY.100]NV_MAPSTAREA.RDA'
        -- read write storage area
        locking is row level
        page format is UNIFORM
        page size is 2 blocks
        allocation is 3 pages
        extent is (minimum 1998, maximum 19998, percent growth 20)
        snapshot filename 'NV$DISK:[ENVY.100]NV_MAPSTAREA.SNP'
        snapshot allocation is 100 pages
        snapshot extent is (minimum 99, maximum 9999, percent growth 20)
    
    create storage area MASAMAREA
        filename 'NV$DISK:[ENVY.100]NV_MASAMAREA.RDA'
        -- read write storage area
        locking is row level
        page format is UNIFORM
        page size is 2 blocks
        allocation is 3 pages
        extent is (minimum 1998, maximum 19998, percent growth 20)
        snapshot filename 'NV$DISK:[ENVY.100]NV_MASAMAREA.SNP'
        snapshot allocation is 100 pages
        snapshot extent is (minimum 99, maximum 9999, percent growth 20)
    
    create storage area MASHDAREA
        filename 'NV$DISK:[ENVY.100]NV_MASHDAREA.RDA'
        -- read write storage area
        locking is row level
        page format is UNIFORM
        page size is 2 blocks
        allocation is 3 pages
        extent is (minimum 1998, maximum 19998, percent growth 20)
        snapshot filename 'NV$DISK:[ENVY.100]NV_MASHDAREA.SNP'
        snapshot allocation is 100 pages
        snapshot extent is (minimum 99, maximum 9999, percent growth 20)
    
    create storage area MASHHAREA
        filename 'NV$DISK:[ENVY.100]NV_MASHHAREA.RDA'
        -- read write storage area
        locking is row level
        page format is UNIFORM
        page size is 2 blocks
        allocation is 3 pages
        extent is (minimum 1998, maximum 19998, percent growth 20)
        snapshot filename 'NV$DISK:[ENVY.100]NV_MASHHAREA.SNP'
        snapshot allocation is 100 pages
        snapshot extent is (minimum 99, maximum 9999, percent growth 20)
    
    create storage area MASODAREA
        filename 'NV$DISK:[ENVY.100]NV_MASODAREA.RDA'
        -- read write storage area
        locking is row level
        page format is UNIFORM
        page size is 2 blocks
        allocation is 3 pages
        extent is (minimum 1998, maximum 19998, percent growth 20)
        snapshot filename 'NV$DISK:[ENVY.100]NV_MASODAREA.SNP'
        snapshot allocation is 100 pages
        snapshot extent is (minimum 99, maximum 9999, percent growth 20)
    
    create storage area MASOHAREA
        filename 'NV$DISK:[ENVY.100]NV_MASOHAREA.RDA'
        -- read write storage area
        locking is row level
        page format is UNIFORM
        page size is 2 blocks
        allocation is 3 pages
        extent is (minimum 1998, maximum 19998, percent growth 20)
        snapshot filename 'NV$DISK:[ENVY.100]NV_MASOHAREA.SNP'
        snapshot allocation is 100 pages
        snapshot extent is (minimum 99, maximum 9999, percent growth 20)
    
    create storage area MASOXAREA
        filename 'NV$DISK:[ENVY.100]NV_MASOXAREA.RDA'
        -- read write storage area
        locking is row level
        page format is UNIFORM
        page size is 2 blocks
        allocation is 3 pages
        extent is (minimum 1998, maximum 19998, percent growth 20)
        snapshot filename 'NV$DISK:[ENVY.100]NV_MASOXAREA.SNP'
        snapshot allocation is 100 pages
        snapshot extent is (minimum 99, maximum 9999, percent growth 20)
    
    create storage area MATBLAREA
        filename 'NV$DISK:[ENVY.100]NV_MATBLAREA.RDA'
        -- read write storage area
        locking is row level
        page format is UNIFORM
        page size is 2 blocks
        allocation is 3 pages
        extent is (minimum 1998, maximum 19998, percent growth 20)
        snapshot filename 'NV$DISK:[ENVY.100]NV_MATBLAREA.SNP'
        snapshot allocation is 100 pages
        snapshot extent is (minimum 99, maximum 9999, percent growth 20)
    
    create storage area MATOPAREA
        filename 'NV$DISK:[ENVY.100]NV_MATOPAREA.RDA'
        -- read write storage area
        locking is row level
        page format is UNIFORM
        page size is 2 blocks
        allocation is 3 pages
        extent is (minimum 1998, maximum 19998, percent growth 20)
        snapshot filename 'NV$DISK:[ENVY.100]NV_MATOPAREA.SNP'
        snapshot allocation is 100 pages
        snapshot extent is (minimum 99, maximum 9999, percent growth 20)
    
    create storage area MATYPAREA
        filename 'NV$DISK:[ENVY.100]NV_MATYPAREA.RDA'
        -- read write storage area
        locking is row level
        page format is UNIFORM
        page size is 2 blocks
        allocation is 3 pages
        extent is (minimum 1998, maximum 19998, percent growth 20)
        snapshot filename 'NV$DISK:[ENVY.100]NV_MATYPAREA.SNP'
        snapshot allocation is 100 pages
        snapshot extent is (minimum 99, maximum 9999, percent growth 20)
    
    create storage area MATAXAREA
        filename 'NV$DISK:[ENVY.100]NV_MATAXAREA.RDA'
        -- read write storage area
        locking is row level
        page format is UNIFORM
        page size is 2 blocks
        allocation is 3 pages
        extent is (minimum 1998, maximum 19998, percent growth 20)
        snapshot filename 'NV$DISK:[ENVY.100]NV_MATAXAREA.SNP'
        snapshot allocation is 100 pages
        snapshot extent is (minimum 99, maximum 9999, percent growth 20)
    
    create storage area GLACTAREA
        filename 'NV$DISK:[ENVY.100]NV_GLACTAREA.RDA'
        -- read write storage area
        locking is row level
        page format is UNIFORM
        page size is 2 blocks
        allocation is 3 pages
        extent is (minimum 1998, maximum 19998, percent growth 20)
        snapshot filename 'NV$DISK:[ENVY.100]NV_GLACTAREA.SNP'
        snapshot allocation is 100 pages
        snapshot extent is (minimum 99, maximum 9999, percent growth 20)
    
    create storage area GLLNKAREA
        filename 'NV$DISK:[ENVY.100]NV_GLLNKAREA.RDA'
        -- read write storage area
        locking is row level
        page format is UNIFORM
        page size is 2 blocks
        allocation is 3 pages
        extent is (minimum 1998, maximum 19998, percent growth 20)
        snapshot filename 'NV$DISK:[ENVY.100]NV_GLLNKAREA.SNP'
        snapshot allocation is 100 pages
        snapshot extent is (minimum 99, maximum 9999, percent growth 20)
    
    create storage area GLAMTAREA
        filename 'NV$DISK:[ENVY.100]NV_GLAMTAREA.RDA'
        -- read write storage area
        locking is row level
        page format is UNIFORM
        page size is 2 blocks
        allocation is 3 pages
        extent is (minimum 1998, maximum 19998, percent growth 20)
        snapshot filename 'NV$DISK:[ENVY.100]NV_GLAMTAREA.SNP'
        snapshot allocation is 100 pages
        snapshot extent is (minimum 99, maximum 9999, percent growth 20)
    
    create storage area GLARPAREA
        filename 'NV$DISK:[ENVY.100]NV_GLARPAREA.RDA'
        -- read write storage area
        locking is row level
        page format is UNIFORM
        page size is 2 blocks
        allocation is 3 pages
        extent is (minimum 1998, maximum 19998, percent growth 20)
        snapshot filename 'NV$DISK:[ENVY.100]NV_GLARPAREA.SNP'
        snapshot allocation is 100 pages
        snapshot extent is (minimum 99, maximum 9999, percent growth 20)
    
    create storage area GLPRPAREA
        filename 'NV$DISK:[ENVY.100]NV_GLPRPAREA.RDA'
        -- read write storage area
        locking is row level
        page format is UNIFORM
        page size is 2 blocks
        allocation is 3 pages
        extent is (minimum 1998, maximum 19998, percent growth 20)
        snapshot filename 'NV$DISK:[ENVY.100]NV_GLPRPAREA.SNP'
        snapshot allocation is 100 pages
        snapshot extent is (minimum 99, maximum 9999, percent growth 20)
    
    create storage area GLPMTAREA
        filename 'NV$DISK:[ENVY.100]NV_GLPMTAREA.RDA'
        -- read write storage area
        locking is row level
        page format is UNIFORM
        page size is 2 blocks
        allocation is 3 pages
        extent is (minimum 1998, maximum 19998, percent growth 20)
        snapshot filename 'NV$DISK:[ENVY.100]NV_GLPMTAREA.SNP'
        snapshot allocation is 100 pages
        snapshot extent is (minimum 99, maximum 9999, percent growth 20)
    
    create storage area GLPRJAREA
        filename 'NV$DISK:[ENVY.100]NV_GLPRJAREA.RDA'
        -- read write storage area
        locking is row level
        page format is UNIFORM
        page size is 2 blocks
        allocation is 3 pages
        extent is (minimum 1998, maximum 19998, percent growth 20)
        snapshot filename 'NV$DISK:[ENVY.100]NV_GLPRJAREA.SNP'
        snapshot allocation is 100 pages
        snapshot extent is (minimum 99, maximum 9999, percent growth 20)
    
    create storage area GLPSTAREA
        filename 'NV$DISK:[ENVY.100]NV_GLPSTAREA.RDA'
        -- read write storage area
        locking is row level
        page format is UNIFORM
        page size is 2 blocks
        allocation is 3 pages
        extent is (minimum 1998, maximum 19998, percent growth 20)
        snapshot filename 'NV$DISK:[ENVY.100]NV_GLPSTAREA.SNP'
        snapshot allocation is 100 pages
        snapshot extent is (minimum 99, maximum 9999, percent growth 20)
    
    create storage area GLTRNAREA
        filename 'NV$DISK:[ENVY.100]NV_GLTRNAREA.RDA'
        -- read write storage area
        locking is row level
        page format is UNIFORM
        page size is 2 blocks
        allocation is 3 pages
        extent is (minimum 1998, maximum 19998, percent growth 20)
        snapshot filename 'NV$DISK:[ENVY.100]NV_GLTRNAREA.SNP'
        snapshot allocation is 100 pages
        snapshot extent is (minimum 99, maximum 9999, percent growth 20)
    
    create storage area APACTAREA
        filename 'NV$DISK:[ENVY.100]NV_APACTAREA.RDA'
        -- read write storage area
        locking is row level
        page format is UNIFORM
        page size is 2 blocks
        allocation is 3 pages
        extent is (minimum 1998, maximum 19998, percent growth 20)
        snapshot filename 'NV$DISK:[ENVY.100]NV_APACTAREA.SNP'
        snapshot allocation is 100 pages
        snapshot extent is (minimum 99, maximum 9999, percent growth 20)
    
    create storage area APCHKAREA
        filename 'NV$DISK:[ENVY.100]NV_APCHKAREA.RDA'
        -- read write storage area
        locking is row level
        page format is UNIFORM
        page size is 2 blocks
        allocation is 3 pages
        extent is (minimum 1998, maximum 19998, percent growth 20)
        snapshot filename 'NV$DISK:[ENVY.100]NV_APCHKAREA.SNP'
        snapshot allocation is 100 pages
        snapshot extent is (minimum 99, maximum 9999, percent growth 20)
    
    create storage area APSTTAREA
        filename 'NV$DISK:[ENVY.100]NV_APSTTAREA.RDA'
        -- read write storage area
        locking is row level
        page format is UNIFORM
        page size is 2 blocks
        allocation is 3 pages
        extent is (minimum 1998, maximum 19998, percent growth 20)
        snapshot filename 'NV$DISK:[ENVY.100]NV_APSTTAREA.SNP'
        snapshot allocation is 100 pages
        snapshot extent is (minimum 99, maximum 9999, percent growth 20)
    
    create storage area APPRJAREA
        filename 'NV$DISK:[ENVY.100]NV_APPRJAREA.RDA'
        -- read write storage area
        locking is row level
        page format is UNIFORM
        page size is 2 blocks
        allocation is 3 pages
        extent is (minimum 1998, maximum 19998, percent growth 20)
        snapshot filename 'NV$DISK:[ENVY.100]NV_APPRJAREA.SNP'
        snapshot allocation is 100 pages
        snapshot extent is (minimum 99, maximum 9999, percent growth 20)
    
    create storage area APVCHAREA
        filename 'NV$DISK:[ENVY.100]NV_APVCHAREA.RDA'
        -- read write storage area
        locking is row level
        page format is UNIFORM
        page size is 2 blocks
        allocation is 3 pages
        extent is (minimum 1998, maximum 19998, percent growth 20)
        snapshot filename 'NV$DISK:[ENVY.100]NV_APVCHAREA.SNP'
        snapshot allocation is 100 pages
        snapshot extent is (minimum 99, maximum 9999, percent growth 20)
    
    create storage area APRCTAREA
        filename 'NV$DISK:[ENVY.100]NV_APRCTAREA.RDA'
        -- read write storage area
        locking is row level
        page format is UNIFORM
        page size is 2 blocks
        allocation is 3 pages
        extent is (minimum 1998, maximum 19998, percent growth 20)
        snapshot filename 'NV$DISK:[ENVY.100]NV_APRCTAREA.SNP'
        snapshot allocation is 100 pages
        snapshot extent is (minimum 99, maximum 9999, percent growth 20)
    
    create storage area FAACTAREA
        filename 'NV$DISK:[ENVY.100]NV_FAACTAREA.RDA'
        -- read write storage area
        locking is row level
        page format is UNIFORM
        page size is 2 blocks
        allocation is 3 pages
        extent is (minimum 1998, maximum 19998, percent growth 20)
        snapshot filename 'NV$DISK:[ENVY.100]NV_FAACTAREA.SNP'
        snapshot allocation is 100 pages
        snapshot extent is (minimum 99, maximum 9999, percent growth 20)
    
    create storage area FAPRJAREA
        filename 'NV$DISK:[ENVY.100]NV_FAPRJAREA.RDA'
        -- read write storage area
        locking is row level
        page format is UNIFORM
        page size is 2 blocks
        allocation is 3 pages
        extent is (minimum 1998, maximum 19998, percent growth 20)
        snapshot filename 'NV$DISK:[ENVY.100]NV_FAPRJAREA.SNP'
        snapshot allocation is 100 pages
        snapshot extent is (minimum 99, maximum 9999, percent growth 20)
    
    create storage area INTAREA
        filename 'NV$DISK:[ENVY.100]NV_INTAREA.RDA'
        -- read write storage area
        locking is row level
        page format is UNIFORM
        page size is 2 blocks
        allocation is 3 pages
        extent is (minimum 1998, maximum 19998, percent growth 20)
        snapshot filename 'NV$DISK:[ENVY.100]NV_INTAREA.SNP'
        snapshot allocation is 100 pages
        snapshot extent is (minimum 99, maximum 9999, percent growth 20)
    
    create storage area IRCTAREA
        filename 'NV$DISK:[ENVY.100]NV_IRCTAREA.RDA'
        -- read write storage area
        locking is row level
        page format is UNIFORM
        page size is 2 blocks
        allocation is 3 pages
        extent is (minimum 1998, maximum 19998, percent growth 20)
        snapshot filename 'NV$DISK:[ENVY.100]NV_IRCTAREA.SNP'
        snapshot allocation is 100 pages
        snapshot extent is (minimum 99, maximum 9999, percent growth 20)
    
    create storage area AP109AREA
        filename 'NV$DISK:[ENVY.100]NV_AP109AREA.RDA'
        -- read write storage area
        locking is row level
        page format is UNIFORM
        page size is 2 blocks
        allocation is 3 pages
        extent is (minimum 1998, maximum 19998, percent growth 20)
        snapshot filename 'NV$DISK:[ENVY.100]NV_AP109AREA.SNP'
        snapshot allocation is 100 pages
        snapshot extent is (minimum 99, maximum 9999, percent growth 20)
    
    create storage area APPMTAREA
        filename 'NV$DISK:[ENVY.100]NV_APPMTAREA.RDA'
        -- read write storage area
        locking is row level
        page format is UNIFORM
        page size is 2 blocks
        allocation is 3 pages
        extent is (minimum 1998, maximum 19998, percent growth 20)
        snapshot filename 'NV$DISK:[ENVY.100]NV_APPMTAREA.SNP'
        snapshot allocation is 100 pages
        snapshot extent is (minimum 99, maximum 9999, percent growth 20)
    
    create storage area APBFTAREA
        filename 'NV$DISK:[ENVY.100]NV_APBFTAREA.RDA'
        -- read write storage area
        locking is row level
        page format is UNIFORM
        page size is 2 blocks
        allocation is 3 pages
        extent is (minimum 1998, maximum 19998, percent growth 20)
        snapshot filename 'NV$DISK:[ENVY.100]NV_APBFTAREA.SNP'
        snapshot allocation is 100 pages
        snapshot extent is (minimum 99, maximum 9999, percent growth 20)
    
    create storage area APNOTAREA
        filename 'NV$DISK:[ENVY.100]NV_APNOTAREA.RDA'
        -- read write storage area
        locking is row level
        page format is UNIFORM
        page size is 2 blocks
        allocation is 3 pages
        extent is (minimum 1998, maximum 19998, percent growth 20)
        snapshot filename 'NV$DISK:[ENVY.100]NV_APNOTAREA.SNP'
        snapshot allocation is 100 pages
        snapshot extent is (minimum 99, maximum 9999, percent growth 20)
    
    create storage area MAPNTAREA
        filename 'NV$DISK:[ENVY.100]NV_MAPNTAREA.RDA'
        -- read write storage area
        locking is row level
        page format is UNIFORM
        page size is 2 blocks
        allocation is 3 pages
        extent is (minimum 1998, maximum 19998, percent growth 20)
        snapshot filename 'NV$DISK:[ENVY.100]NV_MAPNTAREA.SNP'
        snapshot allocation is 100 pages
        snapshot extent is (minimum 99, maximum 9999, percent growth 20)
    
    create storage area BYDAREA
        filename 'NV$DISK:[ENVY.100]NV_BYDAREA.RDA'
        -- read write storage area
        locking is row level
        page format is UNIFORM
        page size is 2 blocks
        allocation is 3 pages
        extent is (minimum 1998, maximum 19998, percent growth 20)
        snapshot filename 'NV$DISK:[ENVY.100]NV_BYDAREA.SNP'
        snapshot allocation is 100 pages
        snapshot extent is (minimum 99, maximum 9999, percent growth 20)
    
    create storage area GENAREA
        filename 'NV$DISK:[ENVY.100]NV_GENAREA.RDA'
        -- read write storage area
        locking is row level
        page format is UNIFORM
        page size is 2 blocks
        allocation is 3 pages
        extent is (minimum 1998, maximum 19998, percent growth 20)
        snapshot filename 'NV$DISK:[ENVY.100]NV_GENAREA.SNP'
        snapshot allocation is 100 pages
        snapshot extent is (minimum 99, maximum 9999, percent growth 20)
    
    create storage area COHAREA
        filename 'NV$DISK:[ENVY.100]NV_COHAREA.RDA'
        -- read write storage area
        locking is row level
        page format is UNIFORM
        page size is 2 blocks
        allocation is 3 pages
        extent is (minimum 1998, maximum 19998, percent growth 20)
        snapshot filename 'NV$DISK:[ENVY.100]NV_COHAREA.SNP'
        snapshot allocation is 100 pages
        snapshot extent is (minimum 99, maximum 9999, percent growth 20)
    
    create storage area CDLAREA
        filename 'NV$DISK:[ENVY.100]NV_CDLAREA.RDA'
        -- read write storage area
        locking is row level
        page format is UNIFORM
        page size is 2 blocks
        allocation is 3 pages
        extent is (minimum 1998, maximum 19998, percent growth 20)
        snapshot filename 'NV$DISK:[ENVY.100]NV_CDLAREA.SNP'
        snapshot allocation is 100 pages
        snapshot extent is (minimum 99, maximum 9999, percent growth 20)
    
    create storage area CDAAREA
        filename 'NV$DISK:[ENVY.100]NV_CDAAREA.RDA'
        -- read write storage area
        locking is row level
        page format is UNIFORM
        page size is 2 blocks
        allocation is 3 pages
        extent is (minimum 1998, maximum 19998, percent growth 20)
        snapshot filename 'NV$DISK:[ENVY.100]NV_CDAAREA.SNP'
        snapshot allocation is 100 pages
        snapshot extent is (minimum 99, maximum 9999, percent growth 20)
    
    create storage area CDPLAREA
        filename 'NV$DISK:[ENVY.100]NV_CDPLAREA.RDA'
        -- read write storage area
        locking is row level
        page format is UNIFORM
        page size is 2 blocks
        allocation is 3 pages
        extent is (minimum 1998, maximum 19998, percent growth 20)
        snapshot filename 'NV$DISK:[ENVY.100]NV_CDPLAREA.SNP'
        snapshot allocation is 100 pages
        snapshot extent is (minimum 99, maximum 9999, percent growth 20)
    
    create storage area CONAREA
        filename 'NV$DISK:[ENVY.100]NV_CONAREA.RDA'
        -- read write storage area
        locking is row level
        page format is UNIFORM
        page size is 2 blocks
        allocation is 3 pages
        extent is (minimum 1998, maximum 19998, percent growth 20)
        snapshot filename 'NV$DISK:[ENVY.100]NV_CONAREA.SNP'
        snapshot allocation is 100 pages
        snapshot extent is (minimum 99, maximum 9999, percent growth 20)
    
    create storage area FRTAREA
        filename 'NV$DISK:[ENVY.100]NV_FRTAREA.RDA'
        -- read write storage area
        locking is row level
        page format is UNIFORM
        page size is 2 blocks
        allocation is 3 pages
        extent is (minimum 1998, maximum 19998, percent growth 20)
        snapshot filename 'NV$DISK:[ENVY.100]NV_FRTAREA.SNP'
        snapshot allocation is 100 pages
        snapshot extent is (minimum 99, maximum 9999, percent growth 20)
    
    create storage area BOLAREA
        filename 'NV$DISK:[ENVY.100]NV_BOLAREA.RDA'
        -- read write storage area
        locking is row level
        page format is UNIFORM
        page size is 2 blocks
        allocation is 3 pages
        extent is (minimum 1998, maximum 19998, percent growth 20)
        snapshot filename 'NV$DISK:[ENVY.100]NV_BOLAREA.SNP'
        snapshot allocation is 100 pages
        snapshot extent is (minimum 99, maximum 9999, percent growth 20)
    
    create storage area PODAREA
        filename 'NV$DISK:[ENVY.100]NV_PODAREA.RDA'
        -- read write storage area
        locking is row level
        page format is UNIFORM
        page size is 2 blocks
        allocation is 3 pages
        extent is (minimum 1998, maximum 19998, percent growth 20)
        snapshot filename 'NV$DISK:[ENVY.100]NV_PODAREA.SNP'
        snapshot allocation is 100 pages
        snapshot extent is (minimum 99, maximum 9999, percent growth 20)
    
    create storage area RCTAREA
        filename 'NV$DISK:[ENVY.100]NV_RCTAREA.RDA'
        -- read write storage area
        locking is row level
        page format is UNIFORM
        page size is 2 blocks
        allocation is 3 pages
        extent is (minimum 1998, maximum 19998, percent growth 20)
        snapshot filename 'NV$DISK:[ENVY.100]NV_RCTAREA.SNP'
        snapshot allocation is 100 pages
        snapshot extent is (minimum 99, maximum 9999, percent growth 20)
    
    create storage area APBOLAREA
        filename 'NV$DISK:[ENVY.100]NV_APBOLAREA.RDA'
        -- read write storage area
        locking is row level
        page format is UNIFORM
        page size is 2 blocks
        allocation is 3 pages
        extent is (minimum 1998, maximum 19998, percent growth 20)
        snapshot filename 'NV$DISK:[ENVY.100]NV_APBOLAREA.SNP'
        snapshot allocation is 100 pages
        snapshot extent is (minimum 99, maximum 9999, percent growth 20)
    
    create storage area APPOPAREA
        filename 'NV$DISK:[ENVY.100]NV_APPOPAREA.RDA'
        -- read write storage area
        locking is row level
        page format is UNIFORM
        page size is 2 blocks
        allocation is 3 pages
        extent is (minimum 1998, maximum 19998, percent growth 20)
        snapshot filename 'NV$DISK:[ENVY.100]NV_APPOPAREA.SNP'
        snapshot allocation is 100 pages
        snapshot extent is (minimum 99, maximum 9999, percent growth 20)
    
    create storage area EDTPAREA
        filename 'NV$DISK:[ENVY.100]NV_EDTPAREA.RDA'
        -- read write storage area
        locking is row level
        page format is UNIFORM
        page size is 2 blocks
        allocation is 3 pages
        extent is (minimum 1998, maximum 19998, percent growth 20)
        snapshot filename 'NV$DISK:[ENVY.100]NV_EDTPAREA.SNP'
        snapshot allocation is 100 pages
        snapshot extent is (minimum 99, maximum 9999, percent growth 20)
    
    create storage area EDDOCAREA
        filename 'NV$DISK:[ENVY.100]NV_EDDOCAREA.RDA'
        -- read write storage area
        locking is row level
        page format is UNIFORM
        page size is 2 blocks
        allocation is 3 pages
        extent is (minimum 1998, maximum 19998, percent growth 20)
        snapshot filename 'NV$DISK:[ENVY.100]NV_EDDOCAREA.SNP'
        snapshot allocation is 100 pages
        snapshot extent is (minimum 99, maximum 9999, percent growth 20)
; -- end create database

-- RMU/EXTRACT for Oracle Rdb V7.2-200                   11-OCT-2018 10:44:00.15
--
--                                  Sequences
--
--------------------------------------------------------------------------------
-- no sequences defined

-- RMU/EXTRACT for Oracle Rdb V7.2-200                   11-OCT-2018 10:44:00.15
--
--                             Collating Sequences
--
--------------------------------------------------------------------------------
-- no collating sequences defined

-- RMU/EXTRACT for Oracle Rdb V7.2-200                   11-OCT-2018 10:44:00.15
--
--                              Domain Definitions
--
--------------------------------------------------------------------------------
-- no domains defined

-- RMU/EXTRACT for Oracle Rdb V7.2-200                   11-OCT-2018 10:44:00.15
--
--                             Function Definitions
--
--------------------------------------------------------------------------------
-- no functions defined

-- RMU/EXTRACT for Oracle Rdb V7.2-200                   11-OCT-2018 10:44:00.15
--
--                            Procedure Definitions
--
--------------------------------------------------------------------------------
-- no procedures defined

-- RMU/EXTRACT for Oracle Rdb V7.2-200                   11-OCT-2018 10:44:00.15
--
--                              Table Definitions
--
--------------------------------------------------------------------------------
create table ACTREC (
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
    ACTNO
        CHAR (24),
    ACTDESC
        CHAR (30),
    ACTSTAT
        SMALLINT,
    ACTDATE
        INTEGER,
    ACTTYPE
        SMALLINT,
    ACTGLMAT
        CHAR (24),
    ACTGLMATOH
        CHAR (24),
    ACTGLLAB
        CHAR (24),
    ACTGLFIXOH
        CHAR (24),
    ACTGLVAROH
        CHAR (24),
    ACTGLOP
        CHAR (24),
    ACTGLOPOH
        CHAR (24),
    ACTGLPUR
        CHAR (24),
    ACTGLPUROH
        CHAR (24),
    GL_LINKNAME
        CHAR (24),
    GL_ACCTNO
        CHAR (24),
    GL_ACCTNO439
        CHAR (24),
    GL_ACCTNO440
        CHAR (24),
    GL_ACCTNO441
        CHAR (24),
    GL_ACCTNO442
        CHAR (24),
    GL_ACCTNO443
        CHAR (24),
    GL_ACCTNO444
        CHAR (24),
    GL_ACCTNO445
        CHAR (24),
    GL_ACCTNO446
        CHAR (24));
 
create table BOMREC (
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
    BOMCPNO
        CHAR (18),
    BOMITEM
        SMALLINT,
    BOMQPA
        DOUBLE PRECISION,
    BOMSDOFF
        DOUBLE PRECISION,
    BOMSEQ
        SMALLINT,
    BOMEDAT
        INTEGER,
    BOMIDAT
        INTEGER,
    BOMYLD
        DOUBLE PRECISION,
    BOMMRGFLG
        CHAR (2),
    BOMREQOPT
        SMALLINT,
    BOMPRNTFLG
        SMALLINT,
    BOMPRIPRNTFLG
        SMALLINT,
    BOMDEFQTY
        DOUBLE PRECISION,
    BOMSORTKEY
        SMALLINT,
    BOMMKTGDESC
        CHAR (18),
    BOMMINQPA
        DOUBLE PRECISION,
    BOMMAXQPA
        DOUBLE PRECISION,
    BOMKITPKFLG
        SMALLINT,
    BOMRTGYLD
        DOUBLE PRECISION,
    BOMSERFLG
        SMALLINT,
    BOMVSDOFF
        DOUBLE PRECISION,
    PRTNO
        CHAR (18),
    PRTNO9
        CHAR (18));
 
create table BORREC (
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
    BORQTY
        DOUBLE PRECISION,
    BORSDOFF
        DOUBLE PRECISION,
    BORDUR
        SMALLINT,
    PRTNO
        CHAR (18),
    RESCODE
        CHAR (10));
 
create table CODREC (
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
    CODNO
        SMALLINT,
    CODTYP
        SMALLINT,
    CODDESC
        CHAR (30));
 
create table CSTREC (
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
    CSTMTHD
        CHAR (2),
    CSTSCMT
        DOUBLE PRECISION,
    CSTCCMT
        DOUBLE PRECISION,
    CSTACMT
        DOUBLE PRECISION,
    CSTSCMO
        DOUBLE PRECISION,
    CSTCCMO
        DOUBLE PRECISION,
    CSTACMO
        DOUBLE PRECISION,
    CSTSAMBF
        DOUBLE PRECISION,
    CSTCAMBF
        DOUBLE PRECISION,
    CSTAAMBF
        DOUBLE PRECISION,
    CSTSCDL
        DOUBLE PRECISION,
    CSTCCDL
        DOUBLE PRECISION,
    CSTACDL
        DOUBLE PRECISION,
    CSTSCO1
        DOUBLE PRECISION,
    CSTCCO1
        DOUBLE PRECISION,
    CSTACO1
        DOUBLE PRECISION,
    CSTSCO2
        DOUBLE PRECISION,
    CSTCCO2
        DOUBLE PRECISION,
    CSTACO2
        DOUBLE PRECISION,
    CSTSCOP
        DOUBLE PRECISION,
    CSTCCOP
        DOUBLE PRECISION,
    CSTACOP
        DOUBLE PRECISION,
    CSTSCOO
        DOUBLE PRECISION,
    CSTCCOO
        DOUBLE PRECISION,
    CSTACOO
        DOUBLE PRECISION,
    CSTSADL
        DOUBLE PRECISION,
    CSTCADL
        DOUBLE PRECISION,
    CSTAADL
        DOUBLE PRECISION,
    CSTSAO1
        DOUBLE PRECISION,
    CSTCAO1
        DOUBLE PRECISION,
    CSTAAO1
        DOUBLE PRECISION,
    CSTSAO2
        DOUBLE PRECISION,
    CSTCAO2
        DOUBLE PRECISION,
    CSTAAO2
        DOUBLE PRECISION,
    CSTSAOP
        DOUBLE PRECISION,
    CSTCAOP
        DOUBLE PRECISION,
    CSTAAOP
        DOUBLE PRECISION,
    CSTSAOBF
        DOUBLE PRECISION,
    CSTCAOBF
        DOUBLE PRECISION,
    CSTAAOBF
        DOUBLE PRECISION,
    CSTSPUR
        DOUBLE PRECISION,
    CSTCPUR
        DOUBLE PRECISION,
    CSTAPUR
        DOUBLE PRECISION,
    CSTLSTAMAT
        DOUBLE PRECISION,
    CSTLSTAMATO
        DOUBLE PRECISION,
    CSTLSTALAB
        DOUBLE PRECISION,
    CSTLSTALABO
        DOUBLE PRECISION,
    PRTNO
        CHAR (18));
 
create table DELREC (
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
    PODLINENUM
        INTEGER,
    POHNO
        CHAR (10),
    DELQTY
        DOUBLE PRECISION,
    DELDUDAT
        INTEGER,
    DELVNDAT
        INTEGER,
    DELENDAT
        INTEGER,
    DELMRP
        INTEGER,
    DELRCDAT
        INTEGER,
    DELRTDAT
        INTEGER,
    DELIQTY
        DOUBLE PRECISION,
    DELSQTY
        DOUBLE PRECISION,
    DELRTVR
        DOUBLE PRECISION,
    DELRTVC
        DOUBLE PRECISION,
    DELCLDAT
        INTEGER,
    DELPRFLG
        SMALLINT);
 
create table DFAREC (
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
    DFACODE
        SMALLINT,
    ACTNO
        CHAR (24));
 
create table ECCREC (
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
    ECONO
        CHAR (10),
    ECCCOMM
        CHAR (60));
 
create table ECOREC (
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
    ECONO
        CHAR (10),
    ECOOREV
        CHAR (2),
    ECONREV
        CHAR (2),
    ECOENDAT
        INTEGER,
    ECOEFDAT
        INTEGER,
    PRTNO
        CHAR (18));
 
create table ENCREC (
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
    ENCCOMM
        CHAR (60),
    ENGNO
        CHAR (10));
 
create table ENGREC (
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
    ENGNO
        CHAR (10),
    ENGENDAT
        INTEGER);
 
create table ENDREC (
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
    ENDOREV
        CHAR (2),
    ENDNREV
        CHAR (2),
    ENDEFDAT
        INTEGER,
    ENGNO
        CHAR (10),
    PRTNO
        CHAR (18));
 
create table EMPREC (
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
    EMPNO
        CHAR (10),
    EMPLNAM
        CHAR (20),
    EMPFNAM
        CHAR (20),
    EMPSS
        CHAR (12),
    EMPSHFT
        SMALLINT,
    EMPHOURS
        DOUBLE PRECISION,
    EMPDEPT
        CHAR (10),
    EMPLABOR
        DOUBLE PRECISION,
    EMPOVER
        DOUBLE PRECISION,
    EMPCSTCAT
        CHAR (6),
    EMPSET
        SMALLINT);
 
create table FLDREC (
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
    FLDDESC
        CHAR (60),
    FLGCODE
        SMALLINT);
 
create table FLGREC (
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
    FLGCODE
        SMALLINT,
    FLGTYPE
        SMALLINT,
    FLGLVALU
        INTEGER,
    FLGDVALU
        DOUBLE PRECISION,
    FLGCVALU
        CHAR (30));
 
create table FORREC (
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
    FORDTC
        SMALLINT,
    FORRQTY
        DOUBLE PRECISION,
    FORDAT
        INTEGER,
    FORMRP
        SMALLINT,
    FORCQTY
        DOUBLE PRECISION,
    FORPACT
        CHAR (24),
    PRTNO
        CHAR (18),
    PRTNO51
        CHAR (18));
 
create table FSCREC (
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
    FSCDAT
        INTEGER,
    FSCPER
        CHAR (4),
    FSCWEEK
        INTEGER);
 
create table LABREC (
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
    LABCODE
        SMALLINT,
    LABSSTRT
        CHAR (8),
    LABSSTPT
        CHAR (8),
    LABSOPT
        DOUBLE PRECISION,
    LABRSTRT
        CHAR (8),
    LABRSTPT
        CHAR (8),
    LABROPT
        DOUBLE PRECISION,
    LABENDAT
        INTEGER,
    LABWKDAT
        INTEGER,
    LABFSC
        CHAR (4),
    LABSEQC
        SMALLINT,
    LABTOWKC
        CHAR (10),
    LABSEQM
        SMALLINT,
    LABESHRS
        DOUBLE PRECISION,
    LABERHRS
        DOUBLE PRECISION,
    LABEARN
        DOUBLE PRECISION,
    LABQTY
        DOUBLE PRECISION,
    LABDEPT
        CHAR (10),
    LABTYPE
        SMALLINT,
    LABCMD
        CHAR (6),
    LABGLFLG
        SMALLINT,
    LABLABR
        DOUBLE PRECISION,
    LABFLAG
        SMALLINT,
    LABSSET
        DOUBLE PRECISION,
    LABSLAB
        DOUBLE PRECISION,
    LABSFXB
        DOUBLE PRECISION,
    LABSVAB
        DOUBLE PRECISION,
    LABRCODE
        SMALLINT,
    LABCRACT
        CHAR (24),
    LABDRACT
        CHAR (24),
    LABPYORG
        CHAR (10),
    LABPYPAY1
        CHAR (8),
    LABPYPAY2
        CHAR (8),
    LABPYEVT1
        SMALLINT,
    LABPYEVT2
        SMALLINT,
    LABPYBTCH
        SMALLINT,
    LABPACT
        CHAR (24),
    LABCSTCAT
        CHAR (6),
    LABREF
        CHAR (10),
    LABPRTNO
        CHAR (18),
    LABMSOPT
        DOUBLE PRECISION,
    LABMROPT
        DOUBLE PRECISION,
    LABMESHRS
        DOUBLE PRECISION,
    LABMERHRS
        DOUBLE PRECISION,
    LABSMAC
        DOUBLE PRECISION,
    LABMBONO
        CHAR (10),
    LABINT
        INTEGER,
    LABCHAR12
        CHAR (12),
    ACTNO
        CHAR (24),
    ACTNO16
        CHAR (24),
    EMPNO
        CHAR (10),
    WKCNTR
        CHAR (10),
    PRTNO
        CHAR (18),
    WIPACTNO
        CHAR (24),
    WOHNO
        CHAR (10),
    PRTNO105
        CHAR (18),
    WIPACTNO105
        CHAR (24),
    WOHNO105
        CHAR (10),
    PRTNO108
        CHAR (18),
    WIPACTNO108
        CHAR (24),
    WOHNO108
        CHAR (10),
    EMPNO535
        CHAR (10));
 
create table LOCREC (
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
    PRTNO
        CHAR (18),
    LOCWAR
        CHAR (10),
    LOCCODE
        CHAR (10),
    LOCNET
        SMALLINT,
    LOCPRICOD
        SMALLINT,
    LOCFLG
        SMALLINT,
    LOCACTNO
        CHAR (24),
    LOCPRIKIT
        SMALLINT,
    LOCREPPT
        DOUBLE PRECISION,
    ACTNO
        CHAR (24),
    WARCODE
        CHAR (10),
    INVNO
        CHAR (10),
    INVNO521
        CHAR (10));
 
create table LOTREC (
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
    LOCCODE
        CHAR (10),
    LOCWAR
        CHAR (10),
    PRTNO
        CHAR (18),
    LOTNO
        CHAR (18),
    LOTQTY
        DOUBLE PRECISION,
    LOTCDAT
        INTEGER,
    LOTIDAT
        INTEGER,
    LOTRDAT
        INTEGER,
    LOTEXPDAT
        INTEGER,
    LOTPACT
        CHAR (24),
    LOTHSHSET
        SMALLINT);
 
create table MFGREC (
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
    MFGDAT
        INTEGER,
    MFGDAY
        SMALLINT);
 
create table MISREC (
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
    PRTNO
        CHAR (18),
    MISCPNO
        CHAR (18),
    MISITEM
        SMALLINT,
    MISSDOFF
        DOUBLE PRECISION,
    MISOWQTY
        DOUBLE PRECISION,
    MISISQTY
        DOUBLE PRECISION,
    MISSCQTY
        DOUBLE PRECISION,
    MISSEQ
        SMALLINT,
    MISSPQTY
        DOUBLE PRECISION,
    MISLINO
        SMALLINT,
    MISAVGAMAT
        DOUBLE PRECISION,
    MISAVGAMATO
        DOUBLE PRECISION,
    MISAVGALAB
        DOUBLE PRECISION,
    MISAVGALABO
        DOUBLE PRECISION,
    MISCSCQTY
        DOUBLE PRECISION,
    MISQPA
        DOUBLE PRECISION,
    MISYLD
        DOUBLE PRECISION,
    MISAOWQTY
        DOUBLE PRECISION,
    MISSDAT
        INTEGER,
    MISPRINT
        SMALLINT,
    MISKIT
        SMALLINT,
    MISUOM
        CHAR (2),
    MISUOMCONV
        DOUBLE PRECISION,
    MISUOMOWQTY
        DOUBLE PRECISION,
    MISUOMISQTY
        DOUBLE PRECISION,
    MISSCALE
        SMALLINT,
    MISINT
        INTEGER,
    MISCHAR12
        CHAR (12),
    PRTNO107
        CHAR (18),
    WIPACTNO107
        CHAR (24),
    WOHNO107
        CHAR (10));
 
create table MSCREC (
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
    MSCMPRT
        CHAR (18),
    MSCISQTY
        DOUBLE PRECISION,
    MSCSEQ
        SMALLINT,
    MSCPUR
        DOUBLE PRECISION,
    MSCOVH
        DOUBLE PRECISION,
    PRTNO
        CHAR (18),
    WIPACTNO
        CHAR (24),
    WOHNO
        CHAR (10));
 
create table MRHREC (
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
    PRTNO
        CHAR (18),
    MRHQOH
        DOUBLE PRECISION,
    MRHNQOH
        DOUBLE PRECISION,
    MRHREQQTY
        DOUBLE PRECISION,
    MRHFIRST
        INTEGER,
    MRHLAST
        INTEGER,
    MRHUQOH
        DOUBLE PRECISION,
    MRHUFLG
        SMALLINT);
 
create table MRLREC (
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
    MRLCODE
        SMALLINT);
 
create table MRQREC (
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
    MRQTYP
        SMALLINT,
    MRQADAT
        INTEGER,
    MRQDDAT
        INTEGER,
    MRQREQQTY
        DOUBLE PRECISION,
    MRQORDQTY
        DOUBLE PRECISION,
    MRQSHQTY
        DOUBLE PRECISION,
    MRQTLDT
        SMALLINT,
    MRQTLWR
        CHAR (18),
    MRQNLWR
        CHAR (18),
    MRQSEQ
        SMALLINT,
    PRTNO
        CHAR (18));
 
create table MTRREC (
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
    MTRFFLAG
        SMALLINT,
    MTRFWAR
        CHAR (10),
    MTRFLOC
        CHAR (10),
    MTRFLOT
        CHAR (18),
    MTRFWONO
        CHAR (10),
    MTRFSONO
        CHAR (10),
    MTRFPONO
        CHAR (10),
    MTRTFLAG
        SMALLINT,
    MTRTWAR
        CHAR (10),
    MTRTLOC
        CHAR (10),
    MTRTLOT
        CHAR (18),
    MTRTWONO
        CHAR (10),
    MTRTSONO
        CHAR (10),
    MTRTPONO
        CHAR (10),
    MTRWKCTR
        CHAR (10),
    MTRSEQ
        SMALLINT,
    MTRLOGON
        CHAR (12),
    MTRETIME
        CHAR (8),
    MTREDAT
        INTEGER,
    MTRCMD
        CHAR (6),
    MTRTDAT
        INTEGER,
    MTRGLFLG
        SMALLINT,
    MTRID
        CHAR (10),
    MTRMQTY
        DOUBLE PRECISION,
    MTRFQTY
        DOUBLE PRECISION,
    MTRTQTY
        DOUBLE PRECISION,
    MTRQOH
        DOUBLE PRECISION,
    MTRFSC
        CHAR (4),
    MTRMPRT
        CHAR (18),
    MTRPRJ
        CHAR (10),
    MTRCMT
        DOUBLE PRECISION,
    MTRCMO
        DOUBLE PRECISION,
    MTRCDL
        DOUBLE PRECISION,
    MTRCO1
        DOUBLE PRECISION,
    MTRCO2
        DOUBLE PRECISION,
    MTRCOP
        DOUBLE PRECISION,
    MTRCOO
        DOUBLE PRECISION,
    MTRAMO
        DOUBLE PRECISION,
    MTRADL
        DOUBLE PRECISION,
    MTRAO1
        DOUBLE PRECISION,
    MTRAO2
        DOUBLE PRECISION,
    MTRAOP
        DOUBLE PRECISION,
    MTRAOO
        DOUBLE PRECISION,
    MTRPUR
        DOUBLE PRECISION,
    MTRECST
        DOUBLE PRECISION,
    MTRAUDITDB
        CHAR (3),
    MTRAUDITTR
        INTEGER,
    MTRSCODE
        SMALLINT,
    ACTNO
        CHAR (24),
    ACTNO17
        CHAR (24),
    PRTNO
        CHAR (18));
 
create table OPCREC (
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
    OPCODE
        SMALLINT);
 
create table PODREC (
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
    POHNO
        CHAR (10),
    PODLINE
        SMALLINT,
    PODMPRT
        CHAR (18),
    PODPUOM
        CHAR (2),
    PODCONV
        DOUBLE PRECISION,
    PODREV
        CHAR (2),
    PODQTY
        DOUBLE PRECISION,
    PODQPRI
        DOUBLE PRECISION,
    PODDUDAT
        INTEGER,
    PODVNDAT
        INTEGER,
    PODTAX
        SMALLINT,
    PODPRJ
        CHAR (10),
    PODWO
        CHAR (10),
    PODSEQ
        SMALLINT,
    PODINSP
        CHAR (2),
    PODREQ
        CHAR (10),
    PODENDAT
        INTEGER,
    PODMRP
        INTEGER,
    PODRCDAT
        INTEGER,
    PODRTDAT
        INTEGER,
    PODIQTY
        DOUBLE PRECISION,
    PODSQTY
        DOUBLE PRECISION,
    PODRTVR
        DOUBLE PRECISION,
    PODRTVC
        DOUBLE PRECISION,
    PODCLDAT
        INTEGER,
    PODPRFLG
        SMALLINT,
    PODMFGNO
        CHAR (18),
    PODACTNO
        CHAR (24),
    PODDEST
        SMALLINT,
    PODPACT
        CHAR (24),
    PODCSTCAT
        CHAR (6),
    PODPO
        CHAR (10),
    PODNET
        SMALLINT,
    PODFCQPRI
        DOUBLE PRECISION,
    PODDUE
        DOUBLE PRECISION,
    PODTYP
        SMALLINT,
    PODLINENUM
        INTEGER,
    PODVSSNUM
        SMALLINT,
    PODMBONO
        CHAR (10),
    PODINT
        INTEGER,
    PODREAL
        DOUBLE PRECISION,
    PODCHAR12
        CHAR (12),
    PODTERMS
        INTEGER,
    PODMCOMMCOD
        CHAR (8),
    PODMWGT
        DOUBLE PRECISION,
    PODUNITPR
        DOUBLE PRECISION,
    PODFCUNITPR
        DOUBLE PRECISION,
    PODDISC
        DOUBLE PRECISION,
    PODHRDT
        INTEGER,
    PODCOHNO
        CHAR (10),
    ACTNO
        CHAR (24),
    PRTNO
        CHAR (18));
 
create table POHREC (
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
    POHNO
        CHAR (10),
    POHNET
        SMALLINT,
    POHBC
        CHAR (2),
    POHDAT
        INTEGER,
    POHENDAT
        INTEGER,
    POHPRFLG
        SMALLINT,
    POHPRDAT
        INTEGER,
    POHCLDAT
        INTEGER,
    POHCON
        SMALLINT,
    POHCODAT
        INTEGER,
    POHFOB
        SMALLINT,
    POHFRT
        SMALLINT,
    POHCONF
        CHAR (30),
    POHDPCT
        DOUBLE PRECISION,
    POHDDAYS
        SMALLINT,
    POHNDAYS
        SMALLINT,
    POHVIA
        CHAR (30),
    POHRQSTR
        CHAR (30),
    POHDEL
        CHAR (30),
    POHCURCOD
        CHAR (4),
    POHORIGEXRATE
        DOUBLE PRECISION,
    POHCUREXRATE
        DOUBLE PRECISION,
    POHTYP
        SMALLINT,
    POHINT
        INTEGER,
    POHCHAR12
        CHAR (12),
    POHTRAN
        INTEGER,
    POHPAYPLT
        CHAR (12),
    POHESTFRT
        DOUBLE PRECISION,
    POHFCESTFRT
        DOUBLE PRECISION,
    POHMAXVAL
        DOUBLE PRECISION,
    POHFCMAXVAL
        DOUBLE PRECISION,
    POHPRNTCNT
        INTEGER,
    POHCOHNO
        CHAR (10),
    POHAGENT
        CHAR (32),
    POHPOID
        INTEGER,
    VENCODE
        CHAR (10),
    VENCODE39
        CHAR (10),
    POHPRNTSET
        SMALLINT,
    VENCODE432
        CHAR (10),
    VENCODE433
        CHAR (10),
    POCOHSRTSET
        SMALLINT);
 
create table PONREC (
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
    PONCOM
        CHAR (60),
    PONTYP
        INTEGER,
    PODLINENUM
        INTEGER,
    POHNO
        CHAR (10),
    POHNO45
        CHAR (10),
    PRHNO
        INTEGER,
    PRDLINE
        SMALLINT,
    PRHNO480
        INTEGER);
 
create table PRTREC (
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
    PRTNO
        CHAR (18),
    PRTDESC
        CHAR (30),
    PRTCC
        SMALLINT,
    PRTSTAT
        CHAR (2),
    PRTSDAT
        INTEGER,
    PRTREV
        CHAR (2),
    PRTDWG
        CHAR (18),
    PRTTYP
        SMALLINT,
    PRTLST
        DOUBLE PRECISION,
    PRTCAT
        CHAR (18),
    PRTSC
        CHAR (2),
    PRTPUOM
        CHAR (2),
    PRTCUOM
        CHAR (2),
    PRTCONV
        DOUBLE PRECISION,
    PRTWGT
        DOUBLE PRECISION,
    PRTVOL
        DOUBLE PRECISION,
    PRTABC
        CHAR (2),
    PRTLOC
        SMALLINT,
    PRTLTF
        SMALLINT,
    PRTBC
        CHAR (2),
    PRTPC
        CHAR (2),
    PRTOPC
        SMALLINT,
    PRTDAYS
        SMALLINT,
    PRTROP
        INTEGER,
    PRTSS
        INTEGER,
    PRTMOQ
        INTEGER,
    PRTPAN
        INTEGER,
    PRTAOQ
        INTEGER,
    PRTYLD
        DOUBLE PRECISION,
    PRTFLT
        SMALLINT,
    PRTVLT
        DOUBLE PRECISION,
    PRTDLT
        SMALLINT,
    PRTALT
        SMALLINT,
    PRTDTF
        SMALLINT,
    PRTPTF
        SMALLINT,
    PRTMRT
        CHAR (18),
    PRTLEV
        SMALLINT,
    PRTCUSG
        DOUBLE PRECISION,
    PRTPUSG
        DOUBLE PRECISION,
    PRTFCOD
        SMALLINT,
    PRTQOH
        DOUBLE PRECISION,
    PRTSHLIFE
        INTEGER,
    PRTACTNO
        CHAR (24),
    PRTPRLOC
        CHAR (10),
    PRTISSPAN
        INTEGER,
    PRTISSSS
        INTEGER,
    PRTISSDAY
        SMALLINT,
    PRTBOMFRZ
        CHAR (2),
    PRTINVFLG
        SMALLINT,
    PRTNUMOPT
        SMALLINT,
    PRTPULLFLG
        SMALLINT,
    PRTEXPFAC
        DOUBLE PRECISION,
    PRTSYLDFLG
        SMALLINT,
    PRTPYLDFLG
        SMALLINT,
    PRTKITFLG
        SMALLINT,
    PRTCCGRP
        SMALLINT,
    PRTINT
        INTEGER,
    PRTCHAR12
        CHAR (12),
    PRTCHAR32
        CHAR (32),
    PRTCOMMCOD
        CHAR (8),
    PRTSPUNITFLG
        INTEGER,
    PRTSPUNITCNV
        DOUBLE PRECISION,
    PRTGCONV
        DOUBLE PRECISION,
    PRTCPLNFLG
        INTEGER,
    PRTACTSTAT
        CHAR (5),
    PRTACTDATE
        INTEGER,
    PRTMRPSET
        SMALLINT,
    PRTYLDSET
        SMALLINT);
 
create table PUNREC (
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
    PUNOQTY
        DOUBLE PRECISION,
    PUNCQTY
        DOUBLE PRECISION,
    PUNNLWR
        CHAR (18),
    PUNTLWR
        CHAR (18),
    PUNTLDT
        SMALLINT,
    PUNADAT
        INTEGER,
    PUNDDAT
        INTEGER,
    PUNPROJ
        CHAR (10),
    PUNPACT
        CHAR (24),
    PRTNO
        CHAR (18));
 
create table RCTREC (
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
    VENCODE
        CHAR (10),
    RCTPO
        CHAR (10),
    RCTMPRT
        CHAR (18),
    RCTPOLIN
        SMALLINT,
    RCTNO
        CHAR (10),
    RCTAUTH
        CHAR (20),
    RCTRDAT
        INTEGER,
    RCTENDAT
        INTEGER,
    RCTFLAG
        SMALLINT,
    RCTQTY
        DOUBLE PRECISION,
    RCTPKNO
        CHAR (10),
    RCTPKQTY
        DOUBLE PRECISION,
    RCTPUOM
        CHAR (2),
    RCTCONV
        DOUBLE PRECISION,
    RCTVIA
        CHAR (30),
    RCTQPRI
        DOUBLE PRECISION,
    RCTPRJ
        CHAR (10),
    RCTWO
        CHAR (10),
    RCTSEQ
        SMALLINT,
    RCTACTNO
        CHAR (24),
    RCTCMD
        CHAR (6),
    RCTSTDCST
        DOUBLE PRECISION,
    RCTINQTY
        DOUBLE PRECISION,
    RCTREV
        CHAR (2),
    RCTBC
        CHAR (2),
    RCTVNDAT
        INTEGER,
    RCTORQTY
        DOUBLE PRECISION,
    RCTDUDAT
        INTEGER,
    RCTDEST
        SMALLINT,
    RCTNET
        SMALLINT,
    RCTPACT
        CHAR (24),
    RCTCSTCAT
        CHAR (6),
    RCTCLINQTY
        DOUBLE PRECISION,
    RCTCURCOD
        CHAR (4),
    RCTFCQPRI
        DOUBLE PRECISION,
    RCTFCSTDCST
        DOUBLE PRECISION,
    RCTSQTY
        DOUBLE PRECISION,
    RCTRQTY
        DOUBLE PRECISION,
    RCTFPC
        CHAR (10),
    RCTPOLINUM
        INTEGER,
    RCTWAR
        CHAR (10),
    RCTLOC
        CHAR (10),
    RCTLOT
        CHAR (18),
    RCTNXTSEQ
        SMALLINT,
    RCTSCRQTY
        DOUBLE PRECISION,
    RCTCODE
        SMALLINT,
    RCTAPNO
        CHAR (10),
    RCTCARRIER
        CHAR (20),
    RCTBOL
        CHAR (20),
    RCTINBACCT
        CHAR (24),
    RCTQCFLG
        SMALLINT,
    RCTMBONO
        CHAR (10),
    RCTIQTY
        DOUBLE PRECISION,
    RCTVLOT
        CHAR (24),
    RCTILOT
        CHAR (24),
    RCTINT
        INTEGER,
    RCTREAL
        DOUBLE PRECISION,
    RCTCHAR12
        CHAR (12),
    RCTTERMS
        INTEGER,
    RCTTRAN
        INTEGER,
    RCTMCOMMCOD
        CHAR (8),
    RCTMWGT
        DOUBLE PRECISION,
    RCTSHIPCNTRY
        CHAR (4),
    RCTMODE
        INTEGER,
    RCTORIGCNTRY
        CHAR (4),
    RCTECRPTASL
        INTEGER,
    RCTECRPTSTAT
        INTEGER,
    RCTECRPTVAT
        INTEGER,
    RCTSPUNIT
        DOUBLE PRECISION,
    RCTPORT
        CHAR (4),
    RCTREGN
        CHAR (4),
    RCTREFNO
        CHAR (16),
    RCTSTATPROC
        CHAR (8),
    RCTECRPTDAT
        INTEGER,
    RCTTAX
        INTEGER,
    PODLINENUM
        INTEGER,
    POHNO
        CHAR (10),
    PODLINENUM42
        INTEGER,
    POHNO42
        CHAR (10),
    POHNO47
        CHAR (10),
    PRTNO
        CHAR (18),
    RCTNOHSHSET
        SMALLINT,
    BOLNO
        CHAR (20),
    FRTNO
        CHAR (16));
 
create table REFREC (
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
    REFINFO
        CHAR (30),
    BOMCPNO
        CHAR (18),
    BOMITEM
        SMALLINT);
 
create table RESREC (
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
    RESCODE
        CHAR (10),
    RESDESC
        CHAR (30),
    RESUOM
        CHAR (6),
    RESCAP
        DOUBLE PRECISION,
    RESTYP
        SMALLINT);
 
create table RQDREC (
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
    RQHNO
        CHAR (10),
    RQDLINE
        SMALLINT,
    RQDDQTY
        DOUBLE PRECISION,
    RQDOQTY
        DOUBLE PRECISION,
    RQDNDAT
        INTEGER,
    RQDCLDAT
        INTEGER,
    RQDMRP
        INTEGER,
    RQDREM
        CHAR (30),
    RQDSO
        CHAR (10),
    PRTNO
        CHAR (18));
 
create table RQHREC (
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
    RQHNO
        CHAR (10),
    RQHENDAT
        INTEGER,
    RQHPC
        CHAR (2),
    RQHRQSTR
        CHAR (30));
 
create table RTDREC (
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
    RTDDESC
        CHAR (30),
    PRTNO
        CHAR (18),
    RTGCODE
        SMALLINT,
    RTGSEQ
        SMALLINT);
 
create table RTGREC (
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
    PRTNO
        CHAR (18),
    RTGCODE
        SMALLINT,
    RTGSEQ
        SMALLINT,
    RTGTHR
        DOUBLE PRECISION,
    RTGORHR
        DOUBLE PRECISION,
    RTGOSHR
        DOUBLE PRECISION,
    RTGSLRHR
        DOUBLE PRECISION,
    RTGSLSHR
        DOUBLE PRECISION,
    RTGSMHR
        DOUBLE PRECISION,
    RTGSPROC
        DOUBLE PRECISION,
    RTGYLD
        DOUBLE PRECISION,
    RTGPLRHR
        DOUBLE PRECISION,
    RTGPLSHR
        DOUBLE PRECISION,
    RTGPMHR
        DOUBLE PRECISION,
    RTGPPROC
        DOUBLE PRECISION,
    RTGEFDAT
        INTEGER,
    RTGINDAT
        INTEGER,
    RTGPRUFLG
        SMALLINT,
    RTGCPFLG
        SMALLINT,
    RTGEGFLG
        SMALLINT,
    RTGQUE
        CHAR (10),
    RTGPMSHR
        DOUBLE PRECISION,
    RTGSMSHR
        DOUBLE PRECISION,
    RTGPYLD
        DOUBLE PRECISION,
    RTGYSCMT
        DOUBLE PRECISION,
    RTGYPCMT
        DOUBLE PRECISION,
    RTGYSCMO
        DOUBLE PRECISION,
    RTGYPCMO
        DOUBLE PRECISION,
    RTGYSADL
        DOUBLE PRECISION,
    RTGYPADL
        DOUBLE PRECISION,
    RTGYSCDL
        DOUBLE PRECISION,
    RTGYPCDL
        DOUBLE PRECISION,
    RTGYSAO1
        DOUBLE PRECISION,
    RTGYPAO1
        DOUBLE PRECISION,
    RTGYSCO1
        DOUBLE PRECISION,
    RTGYPCO1
        DOUBLE PRECISION,
    RTGYSAO2
        DOUBLE PRECISION,
    RTGYPAO2
        DOUBLE PRECISION,
    RTGYSCO2
        DOUBLE PRECISION,
    RTGYPCO2
        DOUBLE PRECISION,
    RTGYSAOP
        DOUBLE PRECISION,
    RTGYPAOP
        DOUBLE PRECISION,
    RTGYSCOP
        DOUBLE PRECISION,
    RTGYPCOP
        DOUBLE PRECISION,
    RTGYSAOO
        DOUBLE PRECISION,
    RTGYPAOO
        DOUBLE PRECISION,
    RTGYSCOO
        DOUBLE PRECISION,
    RTGYPCOO
        DOUBLE PRECISION,
    RTGNUM
        CHAR (6),
    WKCNTR
        CHAR (10));
 
create table SODREC (
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
    PRTNO
        CHAR (18),
    SOHNO
        CHAR (10),
    SODLINE
        SMALLINT,
    SODMRP
        SMALLINT,
    SODOQTY
        DOUBLE PRECISION,
    SODSQTY
        DOUBLE PRECISION,
    SODSCDAT
        INTEGER,
    SODFAM
        CHAR (18),
    SODEXPDAT
        INTEGER,
    SODSO
        CHAR (10),
    SODFPC
        CHAR (10),
    SODPACT
        CHAR (24),
    SODINT
        INTEGER,
    SODCHAR12
        CHAR (12));
 
create table SOHREC (
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
    SOHNO
        CHAR (10),
    SOHFPC
        CHAR (10),
    SOHDTC
        SMALLINT,
    SOHINT
        INTEGER,
    SOHCHAR12
        CHAR (12),
    SOHHSH2SET
        SMALLINT);
 
create table SPDREC (
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
    SPDDESC
        CHAR (60),
    SPNCODE
        CHAR (4));
 
create table SPNREC (
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
    SPNCODE
        CHAR (4));
 
create table TOOREC (
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
    TOONO
        CHAR (18),
    TOODESC
        CHAR (30));
 
create table TRDREC (
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
    TRKSEQ
        SMALLINT,
    TRDDESC
        CHAR (30),
    WKCNTR
        CHAR (10));
 
create table TRKREC (
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
    WKCNTR
        CHAR (10),
    TRKSEQ
        SMALLINT,
    TRKOPQTY
        DOUBLE PRECISION,
    TRKCTQTY
        DOUBLE PRECISION,
    TRKCAQTY
        DOUBLE PRECISION,
    TRKTIQTY
        DOUBLE PRECISION,
    TRKTSQTY
        DOUBLE PRECISION,
    TRKSTOFF
        DOUBLE PRECISION,
    TRKENOFF
        DOUBLE PRECISION,
    TRKCLDAT
        INTEGER,
    TRKTHR
        DOUBLE PRECISION,
    TRKORHR
        DOUBLE PRECISION,
    TRKOSHR
        DOUBLE PRECISION,
    TRKSLRHR
        DOUBLE PRECISION,
    TRKSLSHR
        DOUBLE PRECISION,
    TRKSMHR
        DOUBLE PRECISION,
    TRKSPROC
        DOUBLE PRECISION,
    TRKYLD
        DOUBLE PRECISION,
    TRKALRHR
        DOUBLE PRECISION,
    TRKALSHR
        DOUBLE PRECISION,
    TRKAMHR
        DOUBLE PRECISION,
    TRKAPROC
        DOUBLE PRECISION,
    TRKRWQTY
        DOUBLE PRECISION,
    TRKEHQTY
        DOUBLE PRECISION,
    TRKPRUFLG
        SMALLINT,
    TRKAMSHR
        DOUBLE PRECISION,
    TRKSMSHR
        DOUBLE PRECISION,
    TRKPCTLABCMP
        DOUBLE PRECISION,
    TRKYSCMT
        DOUBLE PRECISION,
    TRKYSCMO
        DOUBLE PRECISION,
    TRKYSADL
        DOUBLE PRECISION,
    TRKYSCDL
        DOUBLE PRECISION,
    TRKYSAO1
        DOUBLE PRECISION,
    TRKYSCO1
        DOUBLE PRECISION,
    TRKYSAO2
        DOUBLE PRECISION,
    TRKYSCO2
        DOUBLE PRECISION,
    TRKYSAOP
        DOUBLE PRECISION,
    TRKYSCOP
        DOUBLE PRECISION,
    TRKYSAOO
        DOUBLE PRECISION,
    TRKYSCOO
        DOUBLE PRECISION,
    TRKACTLAB
        DOUBLE PRECISION,
    TRKACTLABO
        DOUBLE PRECISION,
    PRTNO
        CHAR (18),
    RTGCODE
        SMALLINT,
    RTGSEQ
        SMALLINT,
    PRTNO110
        CHAR (18),
    WIPACTNO110
        CHAR (24),
    WOHNO110
        CHAR (10));
 
create table TWUREC (
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
    TWUCNT
        SMALLINT,
    PRTNO
        CHAR (18),
    RTGCODE
        SMALLINT,
    RTGSEQ
        SMALLINT,
    TOONO
        CHAR (18));
 
create table USGREC (
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
    USGPNO
        SMALLINT,
    USGAMT
        DOUBLE PRECISION,
    USGSDAT
        INTEGER,
    USGEDAT
        INTEGER,
    PRTNO
        CHAR (18));
 
create table VARREC (
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
    VARDAT
        INTEGER,
    VARFSC
        CHAR (4),
    VARCODE
        SMALLINT,
    VARGLFLG
        SMALLINT,
    VARAMT
        DOUBLE PRECISION,
    VARDLAB
        DOUBLE PRECISION,
    VARFXO
        DOUBLE PRECISION,
    VARVAO
        DOUBLE PRECISION,
    VAROUTP
        DOUBLE PRECISION,
    VAROUTPO
        DOUBLE PRECISION,
    VARMAT
        DOUBLE PRECISION,
    VARMATO
        DOUBLE PRECISION,
    ACTNO
        CHAR (24),
    ACTNO18
        CHAR (24),
    PRTNO
        CHAR (18),
    WIPACTNO
        CHAR (24),
    WOHNO
        CHAR (10));
 
create table VENREC (
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
    VENCODE
        CHAR (10),
    VENNAME
        CHAR (30),
    VENADR1
        CHAR (30),
    VENADR2
        CHAR (30),
    VENADR3
        CHAR (30),
    VENADR4
        CHAR (30),
    VENZIP
        CHAR (10),
    VENPHONE
        CHAR (12),
    VENCNTC
        CHAR (30),
    VENTYP
        CHAR (2),
    VENSTAT
        SMALLINT,
    VENTELNO
        CHAR (20),
    VENTELEX
        CHAR (12),
    VENCURFLG
        SMALLINT,
    VENCURCOD
        CHAR (4),
    VENFOB
        SMALLINT,
    VENFRT
        SMALLINT,
    VENDPCT
        DOUBLE PRECISION,
    VENDDAYS
        SMALLINT,
    VENNDAYS
        SMALLINT,
    VENVIA
        CHAR (30),
    VENFAX
        CHAR (24),
    VENINT
        INTEGER,
    VENCHAR12
        CHAR (12),
    VENPOMETHOD
        INTEGER,
    VENCNTRY
        CHAR (4),
    VENTAXID
        CHAR (20),
    VENHSTAT
        INTEGER,
    VENGEO
        CHAR (10),
    AP_VNDCODE
        CHAR (10));
 
create table VMCREC (
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
    VMCNAME
        CHAR (30),
    VMCPART
        CHAR (18),
    VMCLIST
        DOUBLE PRECISION,
    VMCREM
        CHAR (60),
    VMCPVEN
        SMALLINT,
    VMCPRTCERT
        SMALLINT,
    PRTNO
        CHAR (18),
    VENCODE
        CHAR (10),
    VMCHSHSET
        SMALLINT);
 
create table WARREC (
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
    WARCODE
        CHAR (10),
    WARADR1
        CHAR (30),
    WARADR2
        CHAR (30),
    WARADR3
        CHAR (30),
    WARADR4
        CHAR (30),
    WARZIP
        CHAR (10),
    WARPHONE
        CHAR (12),
    WARTELNO
        CHAR (20),
    WARTELEX
        CHAR (12),
    WARGEO
        CHAR (10));
 
create table WIPREC (
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
    WIPACTNO
        CHAR (24),
    ACTNO
        CHAR (24),
    ACTNO91
        CHAR (24),
    ACTNO93
        CHAR (24),
    ACTNO94
        CHAR (24),
    ACTNO95
        CHAR (24),
    ACTNO96
        CHAR (24),
    ACTNO97
        CHAR (24),
    ACTNO98
        CHAR (24),
    ACTNO511
        CHAR (24),
    ACTNO544
        CHAR (24),
    ACTNO545
        CHAR (24),
    ACTNO546
        CHAR (24));
 
create table WKCREC (
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
    WKCNTR
        CHAR (10),
    WKCDESC
        CHAR (30),
    WKCSUB
        SMALLINT,
    WKCDEPT
        CHAR (10),
    WKCSHNO
        DOUBLE PRECISION,
    WKCMHOUR
        DOUBLE PRECISION,
    WKCOHOUR
        DOUBLE PRECISION,
    WKCLHOUR
        DOUBLE PRECISION,
    WKCQUEUE
        DOUBLE PRECISION,
    WKCSLAB
        DOUBLE PRECISION,
    WKCSSET
        DOUBLE PRECISION,
    WKCSMAC
        DOUBLE PRECISION,
    WKCSFXB
        DOUBLE PRECISION,
    WKCSVAB
        DOUBLE PRECISION,
    WKCCLAB
        DOUBLE PRECISION,
    WKCCSET
        DOUBLE PRECISION,
    WKCCMAC
        DOUBLE PRECISION,
    WKCCFXB
        DOUBLE PRECISION,
    WKCCVAB
        DOUBLE PRECISION,
    WKCPIPTD
        DOUBLE PRECISION,
    WKCAIPTD
        DOUBLE PRECISION,
    WKCPOPTD
        DOUBLE PRECISION,
    WKCAOPTD
        DOUBLE PRECISION,
    WKCWIPLOC
        CHAR (10),
    WKCCSTCAT
        CHAR (6),
    WKCPRUFLG
        SMALLINT,
    WKCSBRABSFLG
        SMALLINT,
    WKCPBRABSFLG
        SMALLINT,
    WKCINT
        INTEGER,
    WKCCHAR12
        CHAR (12));
 
create table WOHREC (
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
    PRTNO
        CHAR (18),
    WIPACTNO
        CHAR (24),
    WOHNO
        CHAR (10),
    WOHTRKFLG
        SMALLINT,
    WOHREV
        CHAR (2),
    WOHPC
        CHAR (2),
    WOHENDAT
        INTEGER,
    WOHSDAT
        INTEGER,
    WOHSEQ
        INTEGER,
    WOHODDAT
        INTEGER,
    WOHLDDAT
        INTEGER,
    WOHMRP
        INTEGER,
    WOHCLDAT
        INTEGER,
    WOHOQTY
        DOUBLE PRECISION,
    WOHCQTY
        DOUBLE PRECISION,
    WOHSQTY
        DOUBLE PRECISION,
    WOHFINQTY
        DOUBLE PRECISION,
    WOHSTAT
        SMALLINT,
    WOHRWORK
        SMALLINT,
    WOHPRINT
        SMALLINT,
    WOHPRJ
        CHAR (10),
    WOHSO
        CHAR (10),
    WOHDIL
        DOUBLE PRECISION,
    WOHFXO
        DOUBLE PRECISION,
    WOHVAO
        DOUBLE PRECISION,
    WOHOUP
        DOUBLE PRECISION,
    WOHOUPO
        DOUBLE PRECISION,
    WOHSMAT
        DOUBLE PRECISION,
    WOHSMATO
        DOUBLE PRECISION,
    WOHSDIL
        DOUBLE PRECISION,
    WOHSFXO
        DOUBLE PRECISION,
    WOHSVAO
        DOUBLE PRECISION,
    WOHSOUP
        DOUBLE PRECISION,
    WOHSOUPO
        DOUBLE PRECISION,
    WOHCMCIN
        DOUBLE PRECISION,
    WOHCMOIN
        DOUBLE PRECISION,
    WOHLDLIN
        DOUBLE PRECISION,
    WOHLFOIN
        DOUBLE PRECISION,
    WOHLVOIN
        DOUBLE PRECISION,
    WOHLOPIN
        DOUBLE PRECISION,
    WOHLOOIN
        DOUBLE PRECISION,
    WOHAMCOT
        DOUBLE PRECISION,
    WOHAMOOT
        DOUBLE PRECISION,
    WOHADLOT
        DOUBLE PRECISION,
    WOHAFOOT
        DOUBLE PRECISION,
    WOHAVOOT
        DOUBLE PRECISION,
    WOHAOPOT
        DOUBLE PRECISION,
    WOHAOOOT
        DOUBLE PRECISION,
    WOHLTFLAG
        SMALLINT,
    WOHPACT
        CHAR (24),
    WOHCSTCAT
        CHAR (6),
    WOHNET
        SMALLINT,
    WOHOPTCHNGDATE
        INTEGER,
    WOHAQTY
        DOUBLE PRECISION,
    WOHPRDAT
        INTEGER,
    WOHKITDAT
        INTEGER,
    WOHMBONO
        CHAR (10),
    WOHUOM
        CHAR (2),
    WOHUOMCONV
        DOUBLE PRECISION,
    WOHUOMQTY
        DOUBLE PRECISION,
    WOHFORMULA
        CHAR (20),
    WOHINT
        INTEGER,
    WOHCHAR12
        CHAR (12));
 
create table MA_ACCTREC (
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
    MA_ACCTNO
        CHAR (24),
    MA_ACCTNAME
        CHAR (30),
    MA_ACCTMTD
        DOUBLE PRECISION,
    MA_ACCTYTD
        DOUBLE PRECISION,
    MA_ACCTSLT
        DOUBLE PRECISION,
    MA_ACCTACTDAT
        INTEGER,
    MA_ACCTFINTYPE
        SMALLINT,
    GL_ACCTNO
        CHAR (24));
 
create table MA_APCREC (
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
    MA_APCAMTAPP
        DOUBLE PRECISION,
    MA_APCFISC
        CHAR (4),
    MA_APCTRNDAT
        INTEGER,
    MA_APCENTDAT
        INTEGER,
    MA_APCUSER
        CHAR (12),
    MA_APCINHNO
        CHAR (10),
    MA_APCFCAMTAPP
        DOUBLE PRECISION,
    MA_APCEXRATE
        DOUBLE PRECISION,
    MA_APCUSERNODE
        CHAR (15),
    MA_BILNO
        CHAR (10),
    MA_BILNO187
        CHAR (10),
    MA_INHNO187
        CHAR (10));
 
create table MA_BILCTREC (
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
    MA_BILCT
        CHAR (6),
    MA_BILCTDESC
        CHAR (30),
    MA_BILCTACTDAT
        INTEGER);
 
create table MA_BILREC (
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
    MA_BILCT
        CHAR (6),
    MA_BILNO
        CHAR (10),
    MA_BILNAME
        CHAR (30),
    MA_BILADR1
        CHAR (30),
    MA_BILADR2
        CHAR (30),
    MA_BILADR3
        CHAR (30),
    MA_BILCITY
        CHAR (20),
    MA_BILSTATE
        CHAR (8),
    MA_BILZIP
        CHAR (10),
    MA_BILCTRY
        CHAR (10),
    MA_BILPHONE
        CHAR (20),
    MA_BILCNTC
        CHAR (30),
    MA_BILPAYTCOD
        CHAR (6),
    MA_BILDISPCT
        DOUBLE PRECISION,
    MA_BILBAL
        DOUBLE PRECISION,
    MA_BILLASTBAL
        DOUBLE PRECISION,
    MA_BILCIABAL
        DOUBLE PRECISION,
    MA_BILAVGDAYS
        SMALLINT,
    MA_BILSTMTCOD
        SMALLINT,
    MA_BILBILDAT
        SMALLINT,
    MA_BILLASTSTMTDAT
        INTEGER,
    MA_BILLASTINVDAT
        INTEGER,
    MA_BILLASTPAYDAT
        INTEGER,
    MA_BILHLDCOD
        CHAR (6),
    MA_BILCRCHKFLG
        SMALLINT,
    MA_BILCRLIM
        DOUBLE PRECISION,
    MA_BILCRLIMTOL
        DOUBLE PRECISION,
    MA_BILMAXOVRDUE
        DOUBLE PRECISION,
    MA_BILCRRATE
        CHAR (6),
    MA_BILRWDAT
        INTEGER,
    MA_BILPOTARAMT
        DOUBLE PRECISION,
    MA_BILPOTARUPDDAT
        INTEGER,
    MA_BILACTDAT
        INTEGER,
    MA_BILTELEX
        CHAR (12),
    MA_BILEXEMPT
        CHAR (20),
    MA_BILTXFLG
        SMALLINT,
    MA_BILTXCOD
        CHAR (6),
    MA_BILREMCOD
        CHAR (6),
    MA_BILCURFLG
        SMALLINT,
    MA_BILCURCOD
        CHAR (4),
    MA_BILSPNCOD
        CHAR (6),
    MA_BILBANKSORT
        CHAR (10),
    MA_BILBANKACCT
        CHAR (24),
    MA_BILBANKNAME
        CHAR (30),
    MA_BILBANKADR1
        CHAR (30),
    MA_BILCNTRY
        INTEGER,
    MA_BILCNTRYCOD
        CHAR (4),
    MA_BILGEO
        CHAR (10),
    MA_GLCT
        CHAR (6),
    MA_PRCT
        CHAR (6));
 
create table MA_BILSREC (
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
    MA_BILNO
        CHAR (10),
    MA_BILSMAMTPD
        DOUBLE PRECISION,
    MA_BILSYAMTPD
        DOUBLE PRECISION,
    MA_BILSMNOPAY
        INTEGER,
    MA_BILSYNOPAY
        INTEGER,
    MA_BILSMDISTKN
        DOUBLE PRECISION,
    MA_BILSYDISTKN
        DOUBLE PRECISION,
    MA_BILSMUDISTKN
        DOUBLE PRECISION,
    MA_BILSYUDISTKN
        DOUBLE PRECISION,
    MA_BILSMNOLATEPAY
        INTEGER,
    MA_BILSYNOLATEPAY
        INTEGER,
    MA_BILSMAMTLATEPAY
        DOUBLE PRECISION,
    MA_BILSYAMTLATEPAY
        DOUBLE PRECISION,
    MA_BILSMNOBADPAY
        INTEGER,
    MA_BILSYNOBADPAY
        INTEGER,
    MA_BILSMAMTBADPAY
        DOUBLE PRECISION,
    MA_BILSYAMTBADPAY
        DOUBLE PRECISION,
    MA_BILSMNOBADDEBT
        INTEGER,
    MA_BILSYNOBADDEBT
        INTEGER,
    MA_BILSMAMTBADDEBT
        DOUBLE PRECISION,
    MA_BILSYAMTBADDEBT
        DOUBLE PRECISION,
    MA_BILCT
        CHAR (6));
 
create table MA_CHGDREC (
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
    MA_CHGHNO
        CHAR (10),
    MA_PRODNO
        CHAR (18),
    MA_CHGDSODLIN
        SMALLINT,
    MA_CHGDSOCAT
        CHAR (6),
    MA_CHGDTOTPCT
        DOUBLE PRECISION,
    MA_CHGDOQTY
        DOUBLE PRECISION,
    MA_CHGDNQTY
        DOUBLE PRECISION,
    MA_CHGDLST
        DOUBLE PRECISION,
    MA_CHGDOADJ
        DOUBLE PRECISION,
    MA_CHGDNADJ
        DOUBLE PRECISION,
    MA_CHGDMCST
        DOUBLE PRECISION,
    MA_CHGDLCST
        DOUBLE PRECISION,
    MA_CHGDOCST
        DOUBLE PRECISION,
    MA_CHGDVOCST
        DOUBLE PRECISION,
    MA_CHGDODISPCT
        DOUBLE PRECISION,
    MA_CHGDNDISPCT
        DOUBLE PRECISION,
    MA_CHGDOPRTABDISPCT
        DOUBLE PRECISION,
    MA_CHGDNPRTABDISPCT
        DOUBLE PRECISION,
    MA_CHGDSA
        CHAR (6),
    MA_CHGDOSAPCT
        DOUBLE PRECISION,
    MA_CHGDNSAPCT
        DOUBLE PRECISION,
    MA_CHGDSCHDAT
        INTEGER,
    MA_CHGDOORGSCHDAT
        INTEGER,
    MA_CHGDOCOMBLFLG
        SMALLINT,
    MA_CHGDNLST
        DOUBLE PRECISION,
    MA_CHGHCONUM
        INTEGER,
    MA_CHGHCLASS
        SMALLINT,
    MA_RSNCOD
        CHAR (6),
    MA_PFAMCOD
        CHAR (6),
    MA_PLINCOD
        CHAR (6),
    MA_PRODNO260
        CHAR (18),
    MA_SODLIN260
        SMALLINT,
    MA_SOHNO260
        CHAR (10));
 
create table MA_CHGHREC (
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
    MA_RSNCOD
        CHAR (6),
    MA_CHGHNO
        CHAR (10),
    MA_CHGHDOCTYPE
        CHAR (2),
    MA_CHGHCONUM
        INTEGER,
    MA_CHGHGLNO
        INTEGER,
    MA_CHGHREF
        CHAR (10),
    MA_CHGHTYP
        CHAR (6),
    MA_CHGHFISC
        CHAR (4),
    MA_CHGHORGDAT
        INTEGER,
    MA_CHGHORGFISC
        CHAR (4),
    MA_CHGHENTDAT
        INTEGER,
    MA_CHGHSHPNO
        CHAR (10),
    MA_CHGHUSER
        CHAR (12),
    MA_CHGHORGENTDAT
        INTEGER,
    MA_CHGHCLASS
        SMALLINT,
    MA_CHGHUSERNODE
        CHAR (15));
 
create table MA_CIAREC (
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
    MA_BILNO
        CHAR (10),
    MA_CIAAMT
        DOUBLE PRECISION,
    MA_CIAAMTAPP
        DOUBLE PRECISION,
    MA_CIACHKNO
        CHAR (10),
    MA_CIASOH
        CHAR (10),
    MA_CIAFISC
        CHAR (4),
    MA_CIATRNDAT
        INTEGER,
    MA_CIAENTDAT
        INTEGER,
    MA_CIAUSER
        CHAR (12),
    MA_CIAPAYBCK
        DOUBLE PRECISION,
    MA_CIACURCOD
        CHAR (4),
    MA_CIAORIGEXRATE
        DOUBLE PRECISION,
    MA_CIACUREXRATE
        DOUBLE PRECISION,
    MA_CIAFCAMT
        DOUBLE PRECISION,
    MA_CIAFCAMTAPP
        DOUBLE PRECISION,
    MA_CIAFCPAYBCK
        DOUBLE PRECISION,
    MA_CIAPMTMETH
        SMALLINT,
    MA_CIAUSERNODE
        CHAR (15),
    MA_BILCT
        CHAR (6));
 
create table MA_CMDMREC (
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
    MA_CMHNO
        CHAR (10),
    MA_CMDMLIN
        SMALLINT,
    MA_CMDMTYP
        SMALLINT,
    MA_CMDMCOD
        CHAR (6),
    MA_CMDMOAMT
        DOUBLE PRECISION,
    MA_CMDMNAMT
        DOUBLE PRECISION,
    MA_CMDMACCT
        CHAR (24),
    MA_CMDMOTXFLG
        SMALLINT,
    MA_CMDMNTXFLG
        SMALLINT,
    MA_CMDMOTXCOD
        CHAR (6),
    MA_CMDMNTXCOD
        CHAR (6),
    MA_CMDMREFNO
        CHAR (10),
    MA_CMDMFCOAMT
        DOUBLE PRECISION,
    MA_CMDMFCNAMT
        DOUBLE PRECISION,
    MA_CMDMSHPNO
        CHAR (10),
    MA_BILNO
        CHAR (10),
    MA_RSNCOD
        CHAR (6),
    MA_INDMLIN
        SMALLINT,
    MA_INHNO
        CHAR (10));
 
create table MA_CMDREC (
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
    MA_CMHNO
        CHAR (10),
    MA_CMDLIN
        SMALLINT,
    MA_CMDOQTY
        DOUBLE PRECISION,
    MA_CMDNQTY
        DOUBLE PRECISION,
    MA_CMDLST
        DOUBLE PRECISION,
    MA_CMDOADJ
        DOUBLE PRECISION,
    MA_CMDNADJ
        DOUBLE PRECISION,
    MA_CMDMCST
        DOUBLE PRECISION,
    MA_CMDLCST
        DOUBLE PRECISION,
    MA_CMDOCST
        DOUBLE PRECISION,
    MA_CMDVOCST
        DOUBLE PRECISION,
    MA_CMDDISPCT
        DOUBLE PRECISION,
    MA_CMDPRTABDISPCT
        DOUBLE PRECISION,
    MA_CMDOTXFLG
        SMALLINT,
    MA_CMDNTXFLG
        SMALLINT,
    MA_CMDSOCAT
        CHAR (6),
    MA_CMDOTXCOD
        CHAR (6),
    MA_CMDNTXCOD
        CHAR (6),
    MA_CMDOTXPRC
        DOUBLE PRECISION,
    MA_CMDNTXPRC
        DOUBLE PRECISION,
    MA_CMDREFNO
        CHAR (10),
    MA_CMDFCOADJ
        DOUBLE PRECISION,
    MA_CMDFCNADJ
        DOUBLE PRECISION,
    MA_CMDSHPNO
        CHAR (10),
    MA_CMDCOMBLFLG
        SMALLINT,
    MA_BILNO
        CHAR (10),
    MA_RSNCOD
        CHAR (6),
    MA_INDSOLINE
        SMALLINT,
    MA_INHNO
        CHAR (10),
    MA_SODLIN
        SMALLINT,
    MA_SOHNO
        CHAR (10),
    MA_PFAMCOD
        CHAR (6),
    MA_PLINCOD
        CHAR (6),
    MA_PRODNO
        CHAR (18));
 
create table MA_CMHREC (
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
    MA_BILNO
        CHAR (10),
    MA_RSNCOD
        CHAR (6),
    MA_CMHNO
        CHAR (10),
    MA_CMHDAT
        INTEGER,
    MA_CMHFISC
        CHAR (4),
    MA_CMHPRDAT
        INTEGER,
    MA_CMHAMT
        DOUBLE PRECISION,
    MA_CMHTXBLAMT
        DOUBLE PRECISION,
    MA_CMHTXAMT
        DOUBLE PRECISION,
    MA_CMHREFNO
        CHAR (10),
    MA_CMHSOH
        CHAR (10),
    MA_CMHCPO
        CHAR (30),
    MA_CMHSHPNO
        CHAR (10),
    MA_CMHFRT
        CHAR (20),
    MA_CMHLADNO
        CHAR (20),
    MA_CMHRGA
        CHAR (10),
    MA_CMHENTDAT
        INTEGER,
    MA_CMHUSER
        CHAR (12),
    MA_CMHTXCOD
        CHAR (6),
    MA_CMHPRODTXCOD
        CHAR (6),
    MA_CMHTXFLG
        SMALLINT,
    MA_CMHPRODTXAMT
        DOUBLE PRECISION,
    MA_CMHPRODLICNO
        CHAR (20),
    MA_CMHLOCLICNO
        CHAR (20),
    MA_CMHCANCAMT
        DOUBLE PRECISION,
    MA_CMHREMBAL
        DOUBLE PRECISION,
    MA_CMHCURCOD
        CHAR (4),
    MA_CMHORIGEXRATE
        DOUBLE PRECISION,
    MA_CMHCUREXRATE
        DOUBLE PRECISION,
    MA_CMHFCAMT
        DOUBLE PRECISION,
    MA_CMHFCTXBLAMT
        DOUBLE PRECISION,
    MA_CMHFCTXAMT
        DOUBLE PRECISION,
    MA_CMHFCPRODTXAMT
        DOUBLE PRECISION,
    MA_CMHFCREMBAL
        DOUBLE PRECISION,
    MA_CMHFCCANCAMT
        DOUBLE PRECISION,
    MA_CMHUSERNODE
        CHAR (15),
    MA_CMHPAYTCOD
        CHAR (6),
    MA_CMHGEO
        CHAR (10),
    MA_CMHPST
        DOUBLE PRECISION,
    MA_CMHGST
        DOUBLE PRECISION,
    MA_BILCT
        CHAR (6),
    MA_CMHPRTSET
        SMALLINT,
    MA_BILNO166
        CHAR (10),
    MA_DMHNO166
        CHAR (10),
    MA_BILNO188
        CHAR (10),
    MA_INHNO188
        CHAR (10),
    MA_TXCOD
        CHAR (6));
 
create table MA_COMCLREC (
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
    MA_COMCLSAPCT
        DOUBLE PRECISION,
    MA_COMCLINHAMT
        DOUBLE PRECISION,
    MA_COMCLINDAMT
        DOUBLE PRECISION,
    MA_CHGDSODLIN
        SMALLINT,
    MA_CHGHNO
        CHAR (10),
    MA_PRODNO
        CHAR (18),
    MA_COMCINVNO
        CHAR (10),
    MA_INHNO
        CHAR (10),
    MA_SAMCOD
        CHAR (6));
 
create table MA_COMCREC (
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
    MA_INHNO
        CHAR (10),
    MA_SAMCOD
        CHAR (6),
    MA_COMCINVNO
        CHAR (10),
    MA_COMCSONO
        CHAR (10),
    MA_COMCDAT
        INTEGER,
    MA_COMCFISC
        CHAR (4),
    MA_COMCCRAMT
        DOUBLE PRECISION,
    MA_COMCAMT
        DOUBLE PRECISION,
    MA_COMCPAYAMT
        DOUBLE PRECISION,
    MA_BILNO
        CHAR (10),
    MA_BILNO251
        CHAR (10),
    MA_CTERCOD251
        CHAR (6),
    MA_SHPNO251
        CHAR (10),
    MA_SOHNO
        CHAR (10));
 
create table MA_COMOCLREC (
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
    MA_COMOCLSAPCT
        DOUBLE PRECISION,
    MA_CHGDSODLIN
        SMALLINT,
    MA_CHGHNO
        CHAR (10),
    MA_PRODNO
        CHAR (18),
    MA_SAMCOD
        CHAR (6),
    MA_SHPNO
        CHAR (10));
 
create table MA_COMOREC (
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
    MA_SAMCOD
        CHAR (6),
    MA_SHPNO
        CHAR (10),
    MA_COMOSONO
        CHAR (10),
    MA_COMOINVNO
        CHAR (10),
    MA_COMOCMNO
        CHAR (10),
    MA_COMOLIN
        SMALLINT,
    MA_COMOQTY
        DOUBLE PRECISION,
    MA_COMOLST
        DOUBLE PRECISION,
    MA_COMOADJ
        DOUBLE PRECISION,
    MA_COMOCMOADJ
        DOUBLE PRECISION,
    MA_COMOPRTABDISPCT
        DOUBLE PRECISION,
    MA_COMODISPCT
        DOUBLE PRECISION,
    MA_COMOTOTCST
        DOUBLE PRECISION,
    MA_COMOPCT
        DOUBLE PRECISION,
    MA_COMOTOTPCT
        DOUBLE PRECISION,
    MA_COMODAT
        INTEGER,
    MA_COMOFISC
        CHAR (4),
    MA_COMOVOIDDAT
        INTEGER,
    MA_COMOPRPCT
        DOUBLE PRECISION,
    MA_COMOQUONO
        CHAR (10),
    MA_CMDLIN
        SMALLINT,
    MA_CMHNO
        CHAR (10),
    MA_INDSOLINE
        SMALLINT,
    MA_INHNO
        CHAR (10),
    MA_SODLIN
        SMALLINT,
    MA_SOHNO
        CHAR (10),
    MA_PFAMCOD
        CHAR (6),
    MA_PLINCOD
        CHAR (6),
    MA_PRODNO
        CHAR (18),
    MA_BILNO
        CHAR (10),
    MA_CTERCOD
        CHAR (6),
    MA_PRODNO257
        CHAR (18),
    MA_SODLIN257
        SMALLINT,
    MA_SOHNO257
        CHAR (10),
    MA_QUOHNO
        CHAR (10),
    MA_SHPNO467
        CHAR (10));
 
create table MA_CPOREC (
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
    MA_CPONO
        CHAR (30));
 
create table MA_CTERREC (
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
    MA_CTERCOD
        CHAR (6),
    MA_CTERDESC
        CHAR (30),
    MA_CTERACTDAT
        INTEGER);
 
create table MA_DMHREC (
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
    MA_BILNO
        CHAR (10),
    MA_DMHNO
        CHAR (10),
    MA_DMHORIGBAL
        DOUBLE PRECISION,
    MA_DMHREMBAL
        DOUBLE PRECISION,
    MA_DMHSTATFLG
        SMALLINT,
    MA_DMHREFNO
        CHAR (10),
    MA_DMHDAT
        INTEGER,
    MA_DMHFISC
        CHAR (4),
    MA_DMHENTDAT
        INTEGER,
    MA_DMHUSER
        CHAR (12),
    MA_DMHCURCOD
        CHAR (4),
    MA_DMHEXRATE
        DOUBLE PRECISION,
    MA_DMHFCORIGBAL
        DOUBLE PRECISION,
    MA_DMHFCREMBAL
        DOUBLE PRECISION,
    MA_DMHUSERNODE
        CHAR (15),
    MA_BILCT
        CHAR (6),
    MA_BILNO191
        CHAR (10),
    MA_INHNO191
        CHAR (10));
 
create table MA_FRTREC (
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
    MA_FRTCOD
        CHAR (6),
    MA_FRTDESC
        CHAR (20),
    MA_FRTACCT
        CHAR (24),
    MA_FRTACTDAT
        INTEGER);
 
create table MA_FRTTREC (
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
    MA_FRTTCOD
        CHAR (6),
    MA_FRTTDESC
        CHAR (20),
    MA_FRTTFLG
        SMALLINT);
 
create table MA_GLCTREC (
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
    MA_GLCT
        CHAR (6),
    MA_GLCTDESC
        CHAR (30),
    MA_GLCTACTDAT
        INTEGER,
    MA_ACCTNO
        CHAR (24),
    MA_ACCTNO116
        CHAR (24),
    MA_ACCTNO117
        CHAR (24));
 
create table MA_GLPTREC (
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
    MA_GLPT
        CHAR (6),
    MA_GLPTDESC
        CHAR (30),
    MA_GLPTACTDAT
        INTEGER);
 
create table MA_GLTABREC (
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
    MA_GLTABCT
        CHAR (6),
    MA_GLTABPT
        CHAR (18),
    MA_GLTABACTNO
        CHAR (24),
    MA_ACCTNO
        CHAR (24),
    MA_ACCTNO119
        CHAR (24),
    MA_ACCTNO120
        CHAR (24),
    MA_ACCTNO121
        CHAR (24),
    ACTNO
        CHAR (24),
    MA_ACCTNO123
        CHAR (24),
    MA_ACCTNO124
        CHAR (24),
    MA_GLCT
        CHAR (6),
    MA_GLPT
        CHAR (6),
    MA_PFAMCOD
        CHAR (6),
    MA_PLINCOD
        CHAR (6),
    MA_PRODNO
        CHAR (18));
 
create table MA_HLDREC (
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
    MA_HLDCOD
        CHAR (6),
    MA_HLDDESC
        CHAR (30));
 
create table MA_INDMREC (
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
    MA_INHNO
        CHAR (10),
    MA_INDMLIN
        SMALLINT,
    MA_INDMTYP
        SMALLINT,
    MA_INDMCOD
        CHAR (6),
    MA_INDMAMT
        DOUBLE PRECISION,
    MA_INDMACCT
        CHAR (24),
    MA_INDMSHH
        CHAR (10),
    MA_INDMTXFLG
        SMALLINT,
    MA_INDMTXCOD
        CHAR (6),
    MA_INDMFCAMT
        DOUBLE PRECISION,
    MA_INDMPACT
        CHAR (24),
    MA_BILNO
        CHAR (10));
 
create table MA_INDREC (
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
    MA_INHNO
        CHAR (10),
    MA_SODLIN
        SMALLINT,
    MA_SOHNO
        CHAR (10),
    MA_INDQTY
        DOUBLE PRECISION,
    MA_INDLST
        DOUBLE PRECISION,
    MA_INDADJ
        DOUBLE PRECISION,
    MA_INDMCST
        DOUBLE PRECISION,
    MA_INDLCST
        DOUBLE PRECISION,
    MA_INDOCST
        DOUBLE PRECISION,
    MA_INDVOCST
        DOUBLE PRECISION,
    MA_INDDISPCT
        DOUBLE PRECISION,
    MA_INDPRTABDISPCT
        DOUBLE PRECISION,
    MA_INDTXFLG
        SMALLINT,
    MA_INDSOLINE
        SMALLINT,
    MA_INDTXPRC
        DOUBLE PRECISION,
    MA_INDTXCOD
        CHAR (6),
    MA_INDBLANKS
        CHAR (14),
    MA_INDFCADJ
        DOUBLE PRECISION,
    MA_BILNO
        CHAR (10),
    MA_PRODNO
        CHAR (18));
 
create table MA_INHREC (
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
    MA_BILNO
        CHAR (10),
    MA_INHNO
        CHAR (10),
    MA_INHDAT
        INTEGER,
    MA_INHFISC
        CHAR (4),
    MA_INHPRDAT
        INTEGER,
    MA_INHPAYTCOD
        CHAR (6),
    MA_INHTXAMT
        DOUBLE PRECISION,
    MA_INHORIGBAL
        DOUBLE PRECISION,
    MA_INHCASHRCTAMT
        DOUBLE PRECISION,
    MA_INHDMAMT
        DOUBLE PRECISION,
    MA_INHCMAMT
        DOUBLE PRECISION,
    MA_INHWOAMT
        DOUBLE PRECISION,
    MA_INHDISCLAIMED
        DOUBLE PRECISION,
    MA_INHAUTH
        CHAR (10),
    MA_INHENTDAT
        INTEGER,
    MA_INHUSER
        CHAR (12),
    MA_INHTXCOD
        CHAR (6),
    MA_INHINVTYPE
        SMALLINT,
    MA_INHSVDOCNO
        CHAR (24),
    MA_INHPRODLICNO
        CHAR (20),
    MA_INHLOCLICNO
        CHAR (20),
    MA_INHTXFLG
        SMALLINT,
    MA_INHPRODTXAMT
        DOUBLE PRECISION,
    MA_INHCURCOD
        CHAR (4),
    MA_INHORIGEXRATE
        DOUBLE PRECISION,
    MA_INHCUREXRATE
        DOUBLE PRECISION,
    MA_INHFCTXAMT
        DOUBLE PRECISION,
    MA_INHFCORIGBAL
        DOUBLE PRECISION,
    MA_INHFCCASHRCTAMT
        DOUBLE PRECISION,
    MA_INHFCDMAMT
        DOUBLE PRECISION,
    MA_INHFCCMAMT
        DOUBLE PRECISION,
    MA_INHFCWOAMT
        DOUBLE PRECISION,
    MA_INHFCDISCLAIMED
        DOUBLE PRECISION,
    MA_INHFCPRODTXAMT
        DOUBLE PRECISION,
    MA_INHUSERNODE
        CHAR (15),
    MA_INHUPDFLG
        SMALLINT,
    MA_INHGEO
        CHAR (10),
    MA_INHPST
        DOUBLE PRECISION,
    MA_INHGST
        DOUBLE PRECISION,
    MA_BILCT
        CHAR (6),
    MA_CPONO
        CHAR (30),
    MA_INHPRTSET
        SMALLINT,
    MA_INHUPDSET
        SMALLINT,
    MA_INT
        SMALLINT,
    MA_SOHNO
        CHAR (10),
    MA_TXCOD
        CHAR (6));
 
create table MA_INTREC (
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
    MA_INT
        SMALLINT,
    MA_INTDESC
        CHAR (30));
 
create table MA_PAYTDREC (
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
    MA_PAYTDDAYS
        SMALLINT,
    MA_PAYTDPCT
        DOUBLE PRECISION,
    MA_PAYTCOD
        CHAR (6));
 
create table MA_PAYTREC (
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
    MA_PAYTCOD
        CHAR (6),
    MA_PAYTDESC
        CHAR (20),
    MA_PAYTNDAYS
        SMALLINT);
 
create table MA_PFAMREC (
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
    MA_PFAMCOD
        CHAR (6),
    MA_PFAMDESC
        CHAR (30),
    MA_PFAMACTDAT
        INTEGER);
 
create table MA_PLINREC (
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
    MA_PFAMCOD
        CHAR (6),
    MA_PLINCOD
        CHAR (6),
    MA_PLINDESC
        CHAR (30),
    MA_PLINACTDAT
        INTEGER);
 
create table MA_POSTREC (
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
    MA_ACCTNO
        CHAR (24),
    MA_POSTTRNNO
        INTEGER,
    MA_POSTCOD
        CHAR (6),
    MA_POSTAMT
        DOUBLE PRECISION,
    MA_POSTDRCRFLG
        CHAR (2),
    MA_POSTCHKNO
        CHAR (10),
    MA_POSTFISC
        CHAR (4),
    MA_POSTTRNDAT
        INTEGER,
    MA_POSTENTDAT
        INTEGER,
    MA_POSTUSER
        CHAR (12),
    MA_POSTTRNFLG
        SMALLINT,
    MA_POSTAUDITNO
        INTEGER,
    MA_POSTAUDITDB
        CHAR (3),
    MA_POSTFCAMT
        DOUBLE PRECISION,
    MA_POSTEXRATE
        DOUBLE PRECISION,
    MA_POSTPMTMETH
        SMALLINT,
    MA_POSTUSERNODE
        CHAR (15),
    MA_BILNO
        CHAR (10),
    MA_INHNO
        CHAR (10),
    MA_BILCT
        CHAR (6),
    MA_BILNO135
        CHAR (10),
    MA_BILNO145
        CHAR (10),
    MA_BILNO156
        CHAR (10),
    MA_CMHNO156
        CHAR (10),
    MA_RSNCOD156
        CHAR (6),
    MA_BILNO158
        CHAR (10),
    MA_CMHNO158
        CHAR (10),
    MA_RSNCOD158
        CHAR (6),
    MA_BILNO190
        CHAR (10),
    MA_INHNO190
        CHAR (10),
    MA_BILNO195
        CHAR (10),
    MA_INHNO195
        CHAR (10),
    MA_BILNO201
        CHAR (10),
    MA_INHNO201
        CHAR (10),
    MA_BILNO202
        CHAR (10),
    MA_INHNO202
        CHAR (10),
    MA_PROJNO
        CHAR (24));
 
create table MA_PRCTREC (
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
    MA_PRCT
        CHAR (6),
    MA_PRCTDESC
        CHAR (30),
    MA_PRCTACTDAT
        INTEGER);
 
create table MA_PRODREC (
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
    MA_PFAMCOD
        CHAR (6),
    MA_PLINCOD
        CHAR (6),
    MA_PRODNO
        CHAR (18),
    MA_PRODPRPT
        CHAR (6),
    MA_PRODGLPT
        CHAR (6),
    MA_PRODDESC
        CHAR (30),
    MA_PRODUOM
        CHAR (2),
    MA_PRODWGT
        DOUBLE PRECISION,
    MA_PRODWGTUOM
        CHAR (2),
    MA_PRODVOL
        DOUBLE PRECISION,
    MA_PRODVOLUOM
        CHAR (2),
    MA_PRODLST
        DOUBLE PRECISION,
    MA_PRODFUTLST
        DOUBLE PRECISION,
    MA_PRODMCST
        DOUBLE PRECISION,
    MA_PRODLCST
        DOUBLE PRECISION,
    MA_PRODOCST
        DOUBLE PRECISION,
    MA_PRODVOCST
        DOUBLE PRECISION,
    MA_PRODINVFLG
        SMALLINT,
    MA_PRODCSTFLG
        SMALLINT,
    MA_PRODTXFLG
        SMALLINT,
    MA_PRODCOMFLG
        SMALLINT,
    MA_PRODSOFLG
        SMALLINT,
    MA_PRODSHPFLG
        SMALLINT,
    MA_PRODPAKFLG
        SMALLINT,
    MA_PRODINCMFLG
        SMALLINT,
    MA_PRODSERFLG
        SMALLINT,
    MA_PRODACTDAT
        INTEGER,
    MA_PRODTXCOD
        CHAR (6),
    MA_PRODTXPRC
        DOUBLE PRECISION,
    MA_PRODHISFLG
        SMALLINT,
    MA_PRODOPT
        SMALLINT,
    MA_PRODBLANKS
        CHAR (14),
    MA_PRODSPNCOD
        CHAR (6),
    MA_PRODCOMMOD
        CHAR (8),
    MA_PRODSPUNITFLG
        INTEGER,
    MA_PRODSPUNITCNV
        DOUBLE PRECISION,
    MA_GLPT
        CHAR (6),
    MA_PRPT
        CHAR (6));
 
create table MA_PRODSREC (
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
    MA_PRODNO
        CHAR (18),
    MA_PRODSMBU
        DOUBLE PRECISION,
    MA_PRODSYBU
        DOUBLE PRECISION,
    MA_PRODSMBLST
        DOUBLE PRECISION,
    MA_PRODSYBLST
        DOUBLE PRECISION,
    MA_PRODSMBNET
        DOUBLE PRECISION,
    MA_PRODSYBNET
        DOUBLE PRECISION,
    MA_PRODSMBMCST
        DOUBLE PRECISION,
    MA_PRODSYBMCST
        DOUBLE PRECISION,
    MA_PRODSMBLCST
        DOUBLE PRECISION,
    MA_PRODSYBLCST
        DOUBLE PRECISION,
    MA_PRODSMBOCST
        DOUBLE PRECISION,
    MA_PRODSYBOCST
        DOUBLE PRECISION,
    MA_PRODSMBVOCST
        DOUBLE PRECISION,
    MA_PRODSYBVOCST
        DOUBLE PRECISION,
    MA_PRODSMBCOM
        DOUBLE PRECISION,
    MA_PRODSYBCOM
        DOUBLE PRECISION,
    MA_PRODSMSU
        DOUBLE PRECISION,
    MA_PRODSYSU
        DOUBLE PRECISION,
    MA_PRODSMSLST
        DOUBLE PRECISION,
    MA_PRODSYSLST
        DOUBLE PRECISION,
    MA_PRODSMSNET
        DOUBLE PRECISION,
    MA_PRODSYSNET
        DOUBLE PRECISION,
    MA_PRODSMSMCST
        DOUBLE PRECISION,
    MA_PRODSYSMCST
        DOUBLE PRECISION,
    MA_PRODSMSLCST
        DOUBLE PRECISION,
    MA_PRODSYSLCST
        DOUBLE PRECISION,
    MA_PRODSMSOCST
        DOUBLE PRECISION,
    MA_PRODSYSOCST
        DOUBLE PRECISION,
    MA_PRODSMSVOCST
        DOUBLE PRECISION,
    MA_PRODSYSVOCST
        DOUBLE PRECISION,
    MA_PRODSMSCOM
        DOUBLE PRECISION,
    MA_PRODSYSCOM
        DOUBLE PRECISION,
    MA_PRODSCOMMSLST
        DOUBLE PRECISION,
    MA_PRODSCOMYSLST
        DOUBLE PRECISION,
    MA_PRODSCOMMSNET
        DOUBLE PRECISION,
    MA_PRODSCOMYSNET
        DOUBLE PRECISION,
    MA_PRODSCOMMBLST
        DOUBLE PRECISION,
    MA_PRODSCOMYBLST
        DOUBLE PRECISION,
    MA_PRODSCOMMBNET
        DOUBLE PRECISION,
    MA_PRODSCOMYBNET
        DOUBLE PRECISION,
    MA_PFAMCOD
        CHAR (6),
    MA_PLINCOD
        CHAR (6));
 
create table MA_PROJREC (
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
    MA_PROJNO
        CHAR (24),
    MA_PROJNAME
        CHAR (30),
    MA_PROJMTD
        DOUBLE PRECISION,
    MA_PROJYTD
        DOUBLE PRECISION,
    MA_PROJPTD
        DOUBLE PRECISION,
    MA_PROJOPNFLG
        SMALLINT,
    GL_PROJNO
        CHAR (24));
 
create table MA_PRPTREC (
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
    MA_PRPT
        CHAR (6),
    MA_PRPTDESC
        CHAR (30),
    MA_PRPTACTDAT
        INTEGER);
 
create table MA_PRTABREC (
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
    MA_PRTABCT
        CHAR (10),
    MA_PRTABPT
        CHAR (18),
    MA_PRTABQTY
        DOUBLE PRECISION,
    MA_PRTABEFFDAT
        INTEGER,
    MA_PRTABOBSDAT
        INTEGER,
    MA_PRTABDISPCT
        DOUBLE PRECISION,
    MA_PRTABDISFLG
        SMALLINT,
    MA_BILCT
        CHAR (6),
    MA_BILNO
        CHAR (10),
    MA_PFAMCOD
        CHAR (6),
    MA_PLINCOD
        CHAR (6),
    MA_PRODNO
        CHAR (18),
    MA_PRCT
        CHAR (6),
    MA_PRPT
        CHAR (6));
 
create table MA_RSNREC (
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
    MA_RSNCOD
        CHAR (6),
    MA_RSNDESC
        CHAR (30));
 
create table MA_SAMREC (
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
    MA_SAMCOD
        CHAR (6),
    MA_SAMTER
        CHAR (6),
    MA_SAMNAME
        CHAR (30),
    MA_SAMADR1
        CHAR (30),
    MA_SAMADR2
        CHAR (30),
    MA_SAMCITY
        CHAR (20),
    MA_SAMSTATE
        CHAR (8),
    MA_SAMZIP
        CHAR (10),
    MA_SAMCTRY
        CHAR (10),
    MA_SAMPHONE
        CHAR (20),
    MA_SAMSOPCT
        DOUBLE PRECISION,
    MA_SAMINPCT
        DOUBLE PRECISION,
    MA_SAMCRPCT
        DOUBLE PRECISION,
    MA_SAMBQUOTA
        DOUBLE PRECISION,
    MA_SAMSQUOTA
        DOUBLE PRECISION,
    MA_SAMACTDAT
        INTEGER,
    MA_SAMADR3
        CHAR (30),
    MA_SAMTELEX
        CHAR (12),
    MA_SAMGEO
        CHAR (10),
    MA_STERCOD
        CHAR (6));
 
create table MA_SAMSREC (
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
    MA_SAMSMBLST
        DOUBLE PRECISION,
    MA_SAMSYBLST
        DOUBLE PRECISION,
    MA_SAMSMBNET
        DOUBLE PRECISION,
    MA_SAMSYBNET
        DOUBLE PRECISION,
    MA_SAMSMBSTDCST
        DOUBLE PRECISION,
    MA_SAMSYBSTDCST
        DOUBLE PRECISION,
    MA_SAMSMBCOM
        DOUBLE PRECISION,
    MA_SAMSYBCOM
        DOUBLE PRECISION,
    MA_SAMSMSLST
        DOUBLE PRECISION,
    MA_SAMSYSLST
        DOUBLE PRECISION,
    MA_SAMSMSNET
        DOUBLE PRECISION,
    MA_SAMSYSNET
        DOUBLE PRECISION,
    MA_SAMSMSSTDCST
        DOUBLE PRECISION,
    MA_SAMSYSSTDCST
        DOUBLE PRECISION,
    MA_SAMSMSCOM
        DOUBLE PRECISION,
    MA_SAMSYSCOM
        DOUBLE PRECISION,
    MA_SAMSCOMMSLST
        DOUBLE PRECISION,
    MA_SAMSCOMYSLST
        DOUBLE PRECISION,
    MA_SAMSCOMMSNET
        DOUBLE PRECISION,
    MA_SAMSCOMYSNET
        DOUBLE PRECISION,
    MA_SAMSCOMMBLST
        DOUBLE PRECISION,
    MA_SAMSCOMYBLST
        DOUBLE PRECISION,
    MA_SAMSCOMMBNET
        DOUBLE PRECISION,
    MA_SAMSCOMYBNET
        DOUBLE PRECISION,
    MA_SAMCOD
        CHAR (6));
 
create table MA_SHDPREC (
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
    MA_SHHNO
        CHAR (10),
    MA_SODLIN
        SMALLINT,
    MA_SOHNO
        CHAR (10),
    MA_SHDPPART
        CHAR (18),
    MA_SHDPLOT
        CHAR (18),
    MA_SHDPQTY
        DOUBLE PRECISION,
    MA_SHDPITEMNO
        SMALLINT);
 
create table MA_SHDREC (
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
    MA_SHHNO
        CHAR (10),
    MA_SODLIN
        SMALLINT,
    MA_SOHNO
        CHAR (10),
    MA_SHDQTY
        DOUBLE PRECISION,
    MA_SHDBKORDQTY
        DOUBLE PRECISION,
    MA_SHDREQDAT
        INTEGER,
    MA_SHDORIGSCHDAT
        INTEGER,
    MA_SHDSCHDAT
        INTEGER,
    MA_SHDSOLINE
        SMALLINT,
    MA_SHDORIGQTY
        DOUBLE PRECISION,
    MA_SHDORIGIN
        CHAR (4),
    MA_SHDSPUNIT
        DOUBLE PRECISION,
    MA_PRODNO
        CHAR (18),
    MA_SOHNO259
        CHAR (10));
 
create table MA_SHHREC (
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
    MA_SOHNO
        CHAR (10),
    MA_SHHNO
        CHAR (10),
    MA_SHHNAME
        CHAR (30),
    MA_SHHADR1
        CHAR (30),
    MA_SHHADR2
        CHAR (30),
    MA_SHHADR3
        CHAR (30),
    MA_SHHCITY
        CHAR (20),
    MA_SHHSTATE
        CHAR (8),
    MA_SHHCTRY
        CHAR (10),
    MA_SHHZIP
        CHAR (10),
    MA_SHHWAR
        CHAR (10),
    MA_SHHSHPDAT
        INTEGER,
    MA_SHHFRTCOD
        CHAR (6),
    MA_SHHFRTTCOD
        CHAR (6),
    MA_SHHLADNO
        CHAR (20),
    MA_SHHDOCREQDAT
        INTEGER,
    MA_SHHDOCPRDAT
        INTEGER,
    MA_SHHPAKPRDAT
        INTEGER,
    MA_SHHENTDAT
        INTEGER,
    MA_SHHUSER
        CHAR (12),
    MA_SHHSVTRNFLG
        SMALLINT,
    MA_SHHUSERNODE
        CHAR (15),
    MA_SHHMODE
        INTEGER,
    MA_SHHREFNO
        CHAR (16),
    MA_SHHBOXFLG
        INTEGER,
    MA_SHHSALFLG
        INTEGER,
    MA_SHHSUPFLG
        INTEGER,
    MA_SHHPORT
        CHAR (4),
    MA_SHHDESTRGN
        CHAR (4),
    MA_SHHSTATPROC
        CHAR (8),
    MA_SHHRPTDAT
        INTEGER,
    MA_SHHGEO
        CHAR (10),
    MA_BILNO
        CHAR (10),
    MA_INHNO
        CHAR (10),
    MA_SHHPRTSET
        SMALLINT,
    MA_PAKPRTSET
        SMALLINT);
 
create table MA_SHPREC (
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
    MA_BILNO
        CHAR (10),
    MA_CTERCOD
        CHAR (6),
    MA_SHPNO
        CHAR (10),
    MA_SHPNAME
        CHAR (30),
    MA_SHPADR1
        CHAR (30),
    MA_SHPADR2
        CHAR (30),
    MA_SHPADR3
        CHAR (30),
    MA_SHPCITY
        CHAR (20),
    MA_SHPSTATE
        CHAR (8),
    MA_SHPZIP
        CHAR (10),
    MA_SHPCTRY
        CHAR (10),
    MA_SHPCNTC
        CHAR (30),
    MA_SHPPHONE
        CHAR (20),
    MA_SHPTER
        CHAR (6),
    MA_SHPTXFLG
        SMALLINT,
    MA_SHPPRI
        SMALLINT,
    MA_SHPSHPFLG
        SMALLINT,
    MA_SHPSIC
        CHAR (10),
    MA_SHPRESALE
        CHAR (20),
    MA_SHPWAR
        CHAR (10),
    MA_SHPTXCOD
        CHAR (6),
    MA_SHPSA
        CHAR (6),
    MA_SHPFRTTCOD
        CHAR (6),
    MA_SHPFRTCOD
        CHAR (6),
    MA_SHPACTDAT
        INTEGER,
    MA_SHPTELEX
        CHAR (12),
    MA_SHPSVTRNFLG
        SMALLINT,
    MA_SHPSPNCOD
        CHAR (6),
    MA_SHPCNTRY
        CHAR (4),
    MA_SHPGEO
        CHAR (10),
    MA_BILCT
        CHAR (6));
 
create table MA_SHPSREC (
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
    MA_SHPNO
        CHAR (10),
    MA_SHPSMBLST
        DOUBLE PRECISION,
    MA_SHPSYBLST
        DOUBLE PRECISION,
    MA_SHPSMBNET
        DOUBLE PRECISION,
    MA_SHPSYBNET
        DOUBLE PRECISION,
    MA_SHPSMBSTDCST
        DOUBLE PRECISION,
    MA_SHPSYBSTDCST
        DOUBLE PRECISION,
    MA_SHPSMBCOM
        DOUBLE PRECISION,
    MA_SHPSYBCOM
        DOUBLE PRECISION,
    MA_SHPSMSLST
        DOUBLE PRECISION,
    MA_SHPSYSLST
        DOUBLE PRECISION,
    MA_SHPSMSNET
        DOUBLE PRECISION,
    MA_SHPSYSNET
        DOUBLE PRECISION,
    MA_SHPSMSSTDCST
        DOUBLE PRECISION,
    MA_SHPSYSSTDCST
        DOUBLE PRECISION,
    MA_SHPSMSCOM
        DOUBLE PRECISION,
    MA_SHPSYSCOM
        DOUBLE PRECISION,
    MA_BILNO
        CHAR (10),
    MA_CTERCOD
        CHAR (6));
 
create table MA_SOCATREC (
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
    MA_SOCATCOD
        CHAR (6),
    MA_SOCATDESC
        CHAR (30),
    MA_SOCATACTDAT
        INTEGER,
    MA_SOCATMBLST
        DOUBLE PRECISION,
    MA_SOCATYBLST
        DOUBLE PRECISION,
    MA_SOCATMBNET
        DOUBLE PRECISION,
    MA_SOCATYBNET
        DOUBLE PRECISION,
    MA_SOCATMBSTDCST
        DOUBLE PRECISION,
    MA_SOCATYBSTDCST
        DOUBLE PRECISION,
    MA_SOCATMBCOM
        DOUBLE PRECISION,
    MA_SOCATYBCOM
        DOUBLE PRECISION,
    MA_SOCATMSLST
        DOUBLE PRECISION,
    MA_SOCATYSLST
        DOUBLE PRECISION,
    MA_SOCATMSNET
        DOUBLE PRECISION,
    MA_SOCATYSNET
        DOUBLE PRECISION,
    MA_SOCATMSSTDCST
        DOUBLE PRECISION,
    MA_SOCATYSSTDCST
        DOUBLE PRECISION,
    MA_SOCATMSCOM
        DOUBLE PRECISION,
    MA_SOCATYSCOM
        DOUBLE PRECISION);
 
create table MA_SODREC (
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
    MA_PRODNO
        CHAR (18),
    MA_SOHNO
        CHAR (10),
    MA_SODLIN
        SMALLINT,
    MA_SODORDQTY
        DOUBLE PRECISION,
    MA_SODSTGQTY
        DOUBLE PRECISION,
    MA_SODSHPQTY
        DOUBLE PRECISION,
    MA_SODINQTY
        DOUBLE PRECISION,
    MA_SODREQDAT
        INTEGER,
    MA_SODREQDATFLG
        SMALLINT,
    MA_SODORIGSCHDAT
        INTEGER,
    MA_SODSCHDAT
        INTEGER,
    MA_SODLST
        DOUBLE PRECISION,
    MA_SODADJ
        DOUBLE PRECISION,
    MA_SODMCST
        DOUBLE PRECISION,
    MA_SODLCST
        DOUBLE PRECISION,
    MA_SODOCST
        DOUBLE PRECISION,
    MA_SODVOCST
        DOUBLE PRECISION,
    MA_SODDISPCT
        DOUBLE PRECISION,
    MA_SODPRTABDISPCT
        DOUBLE PRECISION,
    MA_SODTOTSAPCT
        DOUBLE PRECISION,
    MA_SODCUSPART
        CHAR (18),
    MA_SODTXFLG
        SMALLINT,
    MA_SODMRP
        SMALLINT,
    MA_SODSOCAT
        CHAR (6),
    MA_SODHLDCOD
        CHAR (6),
    MA_SODWAR
        CHAR (10),
    MA_SODPIKPRDAT
        INTEGER,
    MA_SODTXPRC
        DOUBLE PRECISION,
    MA_SODTXCOD
        CHAR (6),
    MA_SODSO
        CHAR (10),
    MA_SODPACT
        CHAR (24),
    MA_SODOPT
        SMALLINT,
    MA_SODCOMPPRI
        SMALLINT,
    MA_SODCOMBLFLG
        SMALLINT,
    MA_SODBLANKS
        CHAR (14),
    MA_SODFCADJ
        DOUBLE PRECISION,
    MA_SODTERMS
        INTEGER,
    MA_BILCT
        CHAR (6),
    MA_BILNO
        CHAR (10),
    MA_PFAMCOD
        CHAR (6),
    MA_PLINCOD
        CHAR (6),
    MA_SHHNO
        CHAR (10),
    MA_SOHNO247
        CHAR (10));
 
create table MA_SOHREC (
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
    MA_SOHNO
        CHAR (10),
    MA_SOHDAT
        INTEGER,
    MA_SOHFISC
        CHAR (4),
    MA_SOHCNTRC
        CHAR (24),
    MA_SOHTOTSHPBL
        DOUBLE PRECISION,
    MA_SOHTOTNSHPBL
        DOUBLE PRECISION,
    MA_SOHTOTSHP
        DOUBLE PRECISION,
    MA_SOHTOTSHPBLIN
        DOUBLE PRECISION,
    MA_SOHTOTNSHPBLIN
        DOUBLE PRECISION,
    MA_SOHHLDCOD
        CHAR (6),
    MA_SOHAUTOHLD
        SMALLINT,
    MA_SOHACKPRDAT
        INTEGER,
    MA_SOHPAYTCOD
        CHAR (6),
    MA_SOHFRTCOD
        CHAR (6),
    MA_SOHFRTTCOD
        CHAR (6),
    MA_SOHREV
        SMALLINT,
    MA_SOHSAFLG
        SMALLINT,
    MA_SOHNAME
        CHAR (30),
    MA_SOHADR1
        CHAR (30),
    MA_SOHADR2
        CHAR (30),
    MA_SOHADR3
        CHAR (30),
    MA_SOHCITY
        CHAR (20),
    MA_SOHSTATE
        CHAR (8),
    MA_SOHZIP
        CHAR (10),
    MA_SOHCTRY
        CHAR (10),
    MA_SOHENTDAT
        INTEGER,
    MA_SOHUSER
        CHAR (12),
    MA_SOHTXCOD
        CHAR (6),
    MA_SOHPRODLICNO
        CHAR (20),
    MA_SOHLOCLICNO
        CHAR (20),
    MA_SOHTXFLG
        SMALLINT,
    MA_SOHCURCOD
        CHAR (4),
    MA_SOHORIGEXRATE
        DOUBLE PRECISION,
    MA_SOHCUREXRATE
        DOUBLE PRECISION,
    MA_SOHSOTYPE
        SMALLINT,
    MA_SOHORDTOT
        DOUBLE PRECISION,
    MA_SOHINTOT
        DOUBLE PRECISION,
    MA_SOHCLOSDAT
        INTEGER,
    MA_SOHUSERNODE
        CHAR (15),
    MA_SOHFCORDTOT
        DOUBLE PRECISION,
    MA_SOHFCINTOT
        DOUBLE PRECISION,
    MA_SOHUPDFLG
        SMALLINT,
    MA_SOHTRAN
        INTEGER,
    MA_SOHGEO
        CHAR (10),
    MA_CPONO
        CHAR (30),
    MA_BILNO
        CHAR (10),
    MA_CTERCOD
        CHAR (6),
    MA_SHPNO
        CHAR (10),
    MA_SOHPRTSET
        SMALLINT,
    MA_SOHUPDSET
        SMALLINT,
    MA_TXCOD
        CHAR (6),
    MA_SOHPBSET
        SMALLINT);
 
create table MA_SPFREC (
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
    MA_SPFCOD
        CHAR (6),
    MA_SPFDESC
        CHAR (20),
    MA_SPFACCT
        CHAR (24),
    MA_SPFDEFAMT
        DOUBLE PRECISION,
    MA_SPFACTDAT
        INTEGER);
 
create table MA_SPIREC (
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
    MA_SPIDESC
        CHAR (30),
    MA_SPIFLG
        SMALLINT,
    MA_APCAMTAPP
        DOUBLE PRECISION,
    MA_CMDMLIN
        SMALLINT,
    MA_CMHNO
        CHAR (10),
    MA_CMDLIN
        SMALLINT,
    MA_CMHNO149
        CHAR (10),
    MA_BILNO
        CHAR (10),
    MA_CMHNO154
        CHAR (10),
    MA_RSNCOD154
        CHAR (6),
    MA_BILNO168
        CHAR (10),
    MA_DMHNO168
        CHAR (10),
    MA_INDMLIN
        SMALLINT,
    MA_INHNO
        CHAR (10),
    MA_INDSOLINE
        SMALLINT,
    MA_INHNO185
        CHAR (10),
    MA_SODLIN185
        SMALLINT,
    MA_SOHNO185
        CHAR (10),
    MA_BILNO198
        CHAR (10),
    MA_INHNO198
        CHAR (10),
    MA_ACCTNO
        CHAR (24),
    MA_POSTTRNNO
        INTEGER,
    MA_SHHNO
        CHAR (10),
    MA_SODLIN
        SMALLINT,
    MA_SOHNO
        CHAR (10),
    MA_SHHNO248
        CHAR (10),
    MA_SOHNO248
        CHAR (10),
    MA_PRODNO
        CHAR (18),
    MA_SODLIN261
        SMALLINT,
    MA_SOHNO261
        CHAR (10),
    MA_SOHNO269
        CHAR (10),
    MA_INHNO426
        CHAR (10),
    MA_SVINDLIN426
        SMALLINT,
    MA_QUODLIN
        SMALLINT,
    MA_QUOHNO
        CHAR (10),
    MA_QUOHNO456
        CHAR (10),
    MA_SHPNO456
        CHAR (10));
 
create table MA_SPNREC (
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
    MA_SPNCOD
        CHAR (6),
    MA_SPNFLG
        SMALLINT);
 
create table MA_SPNLREC (
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
    MA_SPNLFLG
        SMALLINT,
    MA_SPNLSPNCOD
        CHAR (6),
    MA_CMDMLIN
        SMALLINT,
    MA_CMHNO
        CHAR (10),
    MA_CMDLIN
        SMALLINT,
    MA_CMHNO150
        CHAR (10),
    MA_BILNO
        CHAR (10),
    MA_CMHNO155
        CHAR (10),
    MA_RSNCOD155
        CHAR (6),
    MA_BILNO169
        CHAR (10),
    MA_DMHNO169
        CHAR (10),
    MA_INDMLIN
        SMALLINT,
    MA_INHNO
        CHAR (10),
    MA_INDSOLINE
        SMALLINT,
    MA_INHNO186
        CHAR (10),
    MA_SODLIN186
        SMALLINT,
    MA_SOHNO186
        CHAR (10),
    MA_BILNO199
        CHAR (10),
    MA_INHNO199
        CHAR (10),
    MA_SHHNO
        CHAR (10),
    MA_SODLIN
        SMALLINT,
    MA_SOHNO
        CHAR (10),
    MA_SHHNO249
        CHAR (10),
    MA_SOHNO249
        CHAR (10),
    MA_PRODNO
        CHAR (18),
    MA_SODLIN262
        SMALLINT,
    MA_SOHNO262
        CHAR (10),
    MA_SOHNO270
        CHAR (10),
    MA_SPNCOD
        CHAR (6),
    MA_INHNO427
        CHAR (10),
    MA_SVINDLIN427
        SMALLINT,
    MA_QUODLIN
        SMALLINT,
    MA_QUOHNO
        CHAR (10),
    MA_QUOHNO457
        CHAR (10),
    MA_SHPNO457
        CHAR (10));
 
create table MA_SPNDREC (
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
    MA_SPNDDESC
        CHAR (30),
    MA_SPNCOD
        CHAR (6));
 
create table MA_STERREC (
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
    MA_STERCOD
        CHAR (6),
    MA_STERDESC
        CHAR (30),
    MA_STERACTDAT
        INTEGER);
 
create table MA_STGREC (
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
    WARCODE
        CHAR (10),
    MA_STGLOC
        CHAR (10),
    MA_STGWAR
        CHAR (10),
    MA_STGACTNO
        CHAR (24),
    ACTNO
        CHAR (24));
 
create table MA_STGPREC (
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
    MA_STGPSLOC
        CHAR (10),
    MA_STGPPART
        CHAR (18),
    MA_STGPQTY
        DOUBLE PRECISION,
    MA_STGPLOT
        CHAR (18),
    MA_STGPDAT
        INTEGER,
    MA_STGPDLT
        INTEGER,
    MA_STGPFROMLOC
        CHAR (10),
    MA_STGPACTNO
        CHAR (24),
    MA_STGPSONO
        CHAR (10),
    MA_STGPSOLIN
        SMALLINT,
    MA_STGPWAR
        CHAR (10),
    MA_STGPITEMNO
        SMALLINT,
    PRTNO
        CHAR (18),
    MA_PRODNO
        CHAR (18),
    MA_SODLIN
        SMALLINT,
    MA_SOHNO
        CHAR (10),
    MA_STGWAR
        CHAR (10),
    WARCODE
        CHAR (10),
    MA_STGPHSHSET
        SMALLINT);
 
create table MA_STATEREC (
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
    MA_STATECOD
        CHAR (6),
    MA_STATEDESC
        CHAR (30),
    MA_STATEACCT
        CHAR (24),
    MA_STATEACTDAT
        INTEGER,
    MA_STATEMATTX
        SMALLINT,
    MA_STATELABTX
        SMALLINT,
    MA_STATEEXPTX
        SMALLINT,
    MA_STATEFRTTX
        SMALLINT,
    MA_STATEFLATTX
        SMALLINT,
    MA_STATEALTACCT
        CHAR (24));
 
create table MA_TOPREC (
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
    MA_PRODNO
        CHAR (18),
    MA_TOPPART
        CHAR (18),
    MA_TOPQTY
        DOUBLE PRECISION,
    MA_TOPSERFLG
        SMALLINT,
    MA_PFAMCOD
        CHAR (6),
    MA_PLINCOD
        CHAR (6),
    PRTNO
        CHAR (18),
    MA_PARTNO
        CHAR (18));
 
create table MA_TXREC (
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
    MA_TXCOD
        CHAR (6),
    MA_TXDESC
        CHAR (30),
    MA_TXTOTPCT
        DOUBLE PRECISION,
    MA_TXACCT
        CHAR (24),
    MA_TXMTXBLEAMT
        DOUBLE PRECISION,
    MA_TXYTXBLEAMT
        DOUBLE PRECISION,
    MA_TXMNTXBLEAMT
        DOUBLE PRECISION,
    MA_TXYNTXBLEAMT
        DOUBLE PRECISION,
    MA_TXACTDAT
        INTEGER,
    MA_TXALTACCT
        CHAR (24),
    MA_STATECOD
        CHAR (6));
 
create table MA_TXLREC (
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
    MA_TXLMTXAMT
        DOUBLE PRECISION,
    MA_TXLYTXAMT
        DOUBLE PRECISION,
    MA_TXCOD
        CHAR (6),
    MA_TXRTCOD
        CHAR (6));
 
create table MA_TXRTREC (
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
    MA_TXRTCOD
        CHAR (6),
    MA_TXRTDESC
        CHAR (30),
    MA_TXRT
        DOUBLE PRECISION,
    MA_TXRTACCT
        CHAR (24),
    MA_TXRTACTDAT
        INTEGER,
    MA_TXRTALTACCT
        CHAR (24),
    MA_TXTCOD
        CHAR (6));
 
create table MA_TXTREC (
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
    MA_TXTCOD
        CHAR (6),
    MA_TXTDESC
        CHAR (30),
    MA_TXTACTDAT
        INTEGER);
 
create table GL_ACCTREC (
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
    GL_ACCTNO
        CHAR (24),
    GL_ACCTNAME
        CHAR (30),
    GL_ACCTTYPE
        SMALLINT,
    GL_ACCTSTMT
        CHAR (2),
    GL_ACCTDRCR
        CHAR (2),
    GL_ACCTSTAT
        SMALLINT,
    GL_ACCTSTATFISC
        CHAR (4),
    GL_CLEARSET
        SMALLINT,
    GL_ISBS
        CHAR (2));
 
create table GL_ACCT_NREC (
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
    GL_ACCTDESC
        CHAR (60),
    GL_ACCTNO
        CHAR (24));
 
create table GL_ISBSREC (
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
    GL_ISBS
        CHAR (2));
 
create table GL_AAMTREC (
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
    GL_AAMTNO
        SMALLINT,
    GL_AAMTYR
        SMALLINT,
    GL_AAMTARAY1
        DOUBLE PRECISION,
    GL_AAMTARAY2
        DOUBLE PRECISION,
    GL_AAMTARAY3
        DOUBLE PRECISION,
    GL_AAMTARAY4
        DOUBLE PRECISION,
    GL_AAMTARAY5
        DOUBLE PRECISION,
    GL_AAMTARAY6
        DOUBLE PRECISION,
    GL_AAMTARAY7
        DOUBLE PRECISION,
    GL_AAMTARAY8
        DOUBLE PRECISION,
    GL_AAMTARAY9
        DOUBLE PRECISION,
    GL_AAMTARAY10
        DOUBLE PRECISION,
    GL_AAMTARAY11
        DOUBLE PRECISION,
    GL_AAMTARAY12
        DOUBLE PRECISION,
    GL_AAMTARAY13
        DOUBLE PRECISION,
    GL_AAMTARAY14
        DOUBLE PRECISION,
    GL_ACCTNO
        CHAR (24));
 
create table GL_ABUDREC (
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
    GL_ABUDYR
        SMALLINT,
    GL_ABUDNO
        SMALLINT,
    GL_ABUDARAY1
        DOUBLE PRECISION,
    GL_ABUDARAY2
        DOUBLE PRECISION,
    GL_ABUDARAY3
        DOUBLE PRECISION,
    GL_ABUDARAY4
        DOUBLE PRECISION,
    GL_ABUDARAY5
        DOUBLE PRECISION,
    GL_ABUDARAY6
        DOUBLE PRECISION,
    GL_ABUDARAY7
        DOUBLE PRECISION,
    GL_ABUDARAY8
        DOUBLE PRECISION,
    GL_ABUDARAY9
        DOUBLE PRECISION,
    GL_ABUDARAY10
        DOUBLE PRECISION,
    GL_ABUDARAY11
        DOUBLE PRECISION,
    GL_ABUDARAY12
        DOUBLE PRECISION,
    GL_ABUDARAY13
        DOUBLE PRECISION,
    GL_ABUDARAY14
        DOUBLE PRECISION,
    GL_ACCTNO
        CHAR (24),
    GL_ABUDNUM
        SMALLINT);
 
create table GL_LINKREC (
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
    GL_LINKNAME
        CHAR (24),
    GL_ACCTNO
        CHAR (24),
    GL_ACCTNO311
        CHAR (24),
    GL_ACCTNO312
        CHAR (24),
    GL_ACCTNO313
        CHAR (24),
    GL_ACCTNO314
        CHAR (24),
    GL_ACCTNO315
        CHAR (24),
    GL_ACCTNO316
        CHAR (24));
 
create table GL_LINK_NREC (
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
    GL_LINKDESC
        CHAR (60),
    GL_LINKNAME
        CHAR (24));
 
create table GL_ARPT_HREC (
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
    GL_ARPTNAME
        CHAR (30),
    GL_ARPTTYPE
        CHAR (2),
    GL_ARPTPFEED
        SMALLINT,
    GL_ARPTSTAT
        SMALLINT);
 
create table GL_ARPT_DREC (
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
    GL_ARPTNAME
        CHAR (30),
    GL_ARPTACCTNAME
        CHAR (30),
    GL_ARPTSEQ
        DOUBLE PRECISION,
    GL_ARPTTOT
        SMALLINT,
    GL_ARPTSKIP
        SMALLINT,
    GL_ARPTINDENT
        SMALLINT,
    GL_ACCTNO
        CHAR (24));
 
create table GL_ARPT_NREC (
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
    GL_ARPTDESC
        CHAR (60),
    GL_ARPTNAME
        CHAR (30));
 
create table GL_TRREC (
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
    GL_TRNO
        INTEGER,
    GL_JVNO
        CHAR (16),
    GL_FISC
        CHAR (4));
 
create table GL_TR_NREC (
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
    GL_TRDESC
        CHAR (60),
    GL_TRNO
        INTEGER);
 
create table GL_JVREC (
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
    GL_JVNO
        CHAR (16));
 
create table GL_JV_NREC (
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
    GL_JVDESC
        CHAR (60),
    GL_JVNO
        CHAR (16));
 
create table GL_POSTREC (
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
    GL_POSTTR
        INTEGER,
    GL_POSTJV
        CHAR (16),
    GL_POSTSOURCE
        CHAR (2),
    GL_POSTSOURCEDB
        CHAR (3),
    GL_POSTFISC
        CHAR (4),
    GL_POSTENTDATE
        INTEGER,
    GL_POSTTRDATE
        INTEGER,
    GL_POSTDRCR
        CHAR (2),
    GL_POSTAMT
        DOUBLE PRECISION,
    GL_POSTAUDITTRNO
        INTEGER,
    GL_POSTAUDITDB
        CHAR (3),
    GL_POSTACTNO
        CHAR (24),
    GL_POSTCCNO
        CHAR (6),
    GL_POSTHRS
        DOUBLE PRECISION,
    GL_ACCTNO
        CHAR (24),
    GL_PROJNO
        CHAR (24),
    GL_TRNO
        INTEGER);
 
create table GL_FISCREC (
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
    GL_FISC
        CHAR (4));
 
create table GL_PROJREC (
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
    GL_PROJNO
        CHAR (24),
    GL_PROJNAME
        CHAR (30),
    GL_PROJSTART
        INTEGER,
    GL_PROJFINISH
        INTEGER,
    GL_PROJEST
        INTEGER,
    GL_PROJBAL
        DOUBLE PRECISION,
    GL_PROJTYPE
        SMALLINT);
 
create table GL_PROJ_NREC (
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
    GL_PROJDESC
        CHAR (60),
    GL_PROJNO
        CHAR (24));
 
create table GL_PAMTREC (
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
    GL_PAMTNO
        SMALLINT,
    GL_PAMTYR
        SMALLINT,
    GL_PAMTARAY1
        DOUBLE PRECISION,
    GL_PAMTARAY2
        DOUBLE PRECISION,
    GL_PAMTARAY3
        DOUBLE PRECISION,
    GL_PAMTARAY4
        DOUBLE PRECISION,
    GL_PAMTARAY5
        DOUBLE PRECISION,
    GL_PAMTARAY6
        DOUBLE PRECISION,
    GL_PAMTARAY7
        DOUBLE PRECISION,
    GL_PAMTARAY8
        DOUBLE PRECISION,
    GL_PAMTARAY9
        DOUBLE PRECISION,
    GL_PAMTARAY10
        DOUBLE PRECISION,
    GL_PAMTARAY11
        DOUBLE PRECISION,
    GL_PAMTARAY12
        DOUBLE PRECISION,
    GL_PAMTARAY13
        DOUBLE PRECISION,
    GL_PAMTARAY14
        DOUBLE PRECISION,
    GL_PROJNO
        CHAR (24));
 
create table GL_PBUDREC (
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
    GL_PBUDYR
        SMALLINT,
    GL_PBUDNO
        SMALLINT,
    GL_PBUDARAY1
        DOUBLE PRECISION,
    GL_PBUDARAY2
        DOUBLE PRECISION,
    GL_PBUDARAY3
        DOUBLE PRECISION,
    GL_PBUDARAY4
        DOUBLE PRECISION,
    GL_PBUDARAY5
        DOUBLE PRECISION,
    GL_PBUDARAY6
        DOUBLE PRECISION,
    GL_PBUDARAY7
        DOUBLE PRECISION,
    GL_PBUDARAY8
        DOUBLE PRECISION,
    GL_PBUDARAY9
        DOUBLE PRECISION,
    GL_PBUDARAY10
        DOUBLE PRECISION,
    GL_PBUDARAY11
        DOUBLE PRECISION,
    GL_PBUDARAY12
        DOUBLE PRECISION,
    GL_PBUDARAY13
        DOUBLE PRECISION,
    GL_PBUDARAY14
        DOUBLE PRECISION,
    GL_PROJNO
        CHAR (24));
 
create table GL_PRPT_HREC (
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
    GL_PRPTNAME
        CHAR (30),
    GL_PRPTTYPE
        CHAR (2),
    GL_PRPTPFEED
        SMALLINT,
    GL_PRPTSTAT
        SMALLINT);
 
create table GL_PRPT_DREC (
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
    GL_PRPTPROJNAME
        CHAR (30),
    GL_PRPTSEQ
        DOUBLE PRECISION,
    GL_PRPTTOT
        SMALLINT,
    GL_PRPTSKIP
        SMALLINT,
    GL_PRPTINDENT
        SMALLINT,
    GL_PRPTNAME
        CHAR (30),
    GL_PROJNO
        CHAR (24));
 
create table GL_PRPT_NREC (
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
    GL_PRPTDESC
        CHAR (60),
    GL_PRPTNAME
        CHAR (30));
 
create table AP_ACCTREC (
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
    AP_ACCTNO
        CHAR (24),
    AP_ACCTNAME
        CHAR (30),
    AP_ACCTSTAT
        SMALLINT,
    AP_ACCTMTD
        DOUBLE PRECISION,
    AP_ACCTYTD
        DOUBLE PRECISION,
    AP_ACCTSLT
        DOUBLE PRECISION,
    AP_ACCTFINTYPE
        SMALLINT,
    GL_ACCTNO
        CHAR (24),
    AP_ACCTTYPE
        SMALLINT);
 
create table AP_ACCTTYPEREC (
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
    AP_ACCTTYPE
        SMALLINT,
    AP_DEFACCTSET
        SMALLINT);
 
create table AP_BANKREC (
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
    AP_BANKCODE
        SMALLINT,
    AP_BANKNAME
        CHAR (30),
    AP_BANKCASH
        CHAR (24),
    AP_BANKDISC
        CHAR (24),
    AP_BANKCURCOD
        CHAR (4),
    AP_BANKSORT
        CHAR (10),
    AP_BANKACCT
        CHAR (24),
    AP_BANKACCTNAME
        CHAR (30),
    AP_BANKADR1
        CHAR (30),
    AP_BANKADR2
        CHAR (30),
    AP_BANKADR3
        CHAR (30),
    AP_BANKADR4
        CHAR (30),
    AP_BANKADR5
        CHAR (10),
    AP_ACCTNO
        CHAR (24),
    AP_ACCTNO339
        CHAR (24));
 
create table AP_BATCHREC (
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
    AP_BATCHNO
        INTEGER,
    AP_BATCHAMT
        DOUBLE PRECISION,
    AP_BATCHUSERNAME
        CHAR (12),
    AP_BATCHHOLDF
        SMALLINT,
    AP_BATCHENTDATE
        INTEGER,
    AP_BATCHLSTDATE
        INTEGER,
    AP_BATCHLSTUSERNAME
        CHAR (12),
    AP_BATCHNOVCH
        SMALLINT,
    AP_BATCHUSERNODE
        CHAR (15),
    AP_BATCHLSTUSERNODE
        CHAR (15));
 
create table AP_CHKREC (
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
    AP_CHKNO
        INTEGER,
    AP_CHKBANK
        SMALLINT,
    AP_CHKAMT
        DOUBLE PRECISION,
    AP_CHKDATE
        INTEGER,
    AP_CHKREMIT
        CHAR (10),
    AP_CHKSTAT
        SMALLINT,
    AP_CHKTYPE
        SMALLINT,
    AP_CHKFISC
        CHAR (4),
    AP_CHKCNCVDDAT
        INTEGER,
    AP_CHKUSERNAME
        CHAR (12),
    AP_CHKFCAMT
        DOUBLE PRECISION,
    AP_CHKUSERNODE
        CHAR (15),
    AP_BANKCODE
        SMALLINT,
    AP_VNDCODE
        CHAR (10));
 
create table AP_INVRCTREC (
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
    AP_INRCUNITCST
        DOUBLE PRECISION,
    AP_INRCQTYINV
        DOUBLE PRECISION,
    AP_INRCPRTNO
        CHAR (18),
    AP_INRCDATE
        INTEGER,
    AP_INRCTNO
        CHAR (10),
    AP_INRCTQPRI
        DOUBLE PRECISION,
    AP_INRCTSTDCST
        DOUBLE PRECISION,
    AP_INRCTFLAG
        SMALLINT,
    AP_INRCTCONV
        DOUBLE PRECISION,
    AP_INRCTRDATE
        INTEGER,
    AP_INRCTQTY
        DOUBLE PRECISION,
    AP_INRCPRJACT
        CHAR (24),
    AP_INRCCSTCAT
        CHAR (6),
    AP_INRCTACTNO
        CHAR (24),
    AP_INRCTNET
        SMALLINT,
    AP_INRCTFCUNITCST
        DOUBLE PRECISION,
    AP_INRCTFCQPRI
        DOUBLE PRECISION,
    AP_INRCTFCSTDCST
        DOUBLE PRECISION,
    AP_INRCTTRANSNO
        INTEGER,
    AP_INRCTREMIT
        CHAR (10),
    AP_INRCTORDFRM
        CHAR (10),
    AP_INRCTVDDAT
        INTEGER,
    AP_POHVCHNO
        CHAR (10),
    AP_POHVCHVCHNO
        CHAR (10),
    RCTNO
        CHAR (10),
    VENCODE
        CHAR (10),
    AP_RCTNO
        CHAR (10));
 
create table AP_INVREC (
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
    AP_VNDCODE
        CHAR (10),
    AP_INVNO
        CHAR (10),
    AP_INVREMIT
        CHAR (10),
    AP_INVDATE
        INTEGER);
 
create table AP_VNOTEREC (
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
    AP_VNOTETYPE
        SMALLINT,
    AP_VNOTELINE
        SMALLINT,
    AP_VNOTE
        CHAR (30),
    AP_VCHNO
        CHAR (10));
 
create table AP_CNOTEREC (
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
    AP_CNOTETYPE
        SMALLINT,
    AP_CNOTELINE
        SMALLINT,
    AP_CNOTE
        CHAR (30),
    AP_CHKNO
        INTEGER);
 
create table AP_PDCHKREC (
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
    AP_PDCHKAMT
        DOUBLE PRECISION,
    AP_PDCHKDIS
        DOUBLE PRECISION,
    AP_PDVCHNO
        CHAR (10),
    AP_PDVCHTRANTYPE
        SMALLINT,
    AP_PDCHKFCAMT
        DOUBLE PRECISION,
    AP_PDCHKFCDIS
        DOUBLE PRECISION,
    AP_PDCHKEXVAR
        DOUBLE PRECISION,
    AP_PDCHKPMTMETH
        SMALLINT,
    AP_CHKNO
        INTEGER,
    AP_VCHNO
        CHAR (10));
 
create table AP_POHREC (
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
    AP_POHNO
        CHAR (10),
    AP_POHCURCOD
        CHAR (4),
    POHNO
        CHAR (10));
 
create table AP_POSTREC (
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
    AP_POSTTRANSNO
        INTEGER,
    AP_POSTACCTNO
        CHAR (24),
    AP_POSTVCHNO
        CHAR (10),
    AP_POSTCHKNO
        INTEGER,
    AP_POSTFISC
        CHAR (4),
    AP_POSTENTDATE
        INTEGER,
    AP_POSTTRANDATE
        INTEGER,
    AP_POSTPROJNO
        CHAR (24),
    AP_POSTAMT
        DOUBLE PRECISION,
    AP_POSTDESC
        CHAR (30),
    AP_POSTTRANSFERF
        SMALLINT,
    AP_POSTTRANTYPE
        SMALLINT,
    AP_POSTAUDITNO
        INTEGER,
    AP_POSTAUDITDBNO
        CHAR (3),
    AP_POSTCSTCAT
        CHAR (6),
    AP_POSTFCAMT
        DOUBLE PRECISION,
    AP_POSTVARFLG
        SMALLINT,
    AP_POSTEXRATE
        DOUBLE PRECISION,
    AP_POSTAUDITPLANT
        CHAR (10),
    AP_POSTVATTXVAL
        DOUBLE PRECISION,
    AP_POSTFCVATTXVAL
        DOUBLE PRECISION,
    AP_POSTCOSTTYPE
        SMALLINT,
    AP_ACCTNO
        CHAR (24),
    AP_CHKNO
        INTEGER,
    AP_PROJNO
        CHAR (24),
    AP_VCHNO
        CHAR (10),
    AP_VCHNO359
        CHAR (10),
    AP_VATCOD
        CHAR (4),
    AP_VATCOD525
        CHAR (4));
 
create table AP_POHVCHREC (
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
    AP_POHVCHNO
        CHAR (10),
    AP_POHVCHVCHNO
        CHAR (10),
    AP_POHNO
        CHAR (10),
    AP_VCHNO
        CHAR (10));
 
create table AP_PROJREC (
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
    AP_PROJNO
        CHAR (24),
    AP_PROJNAME
        CHAR (30),
    AP_PROJMTD
        DOUBLE PRECISION,
    AP_PROJYTD
        DOUBLE PRECISION,
    AP_PROJPTD
        DOUBLE PRECISION,
    AP_PROJSTAT
        SMALLINT,
    GL_PROJNO
        CHAR (24));
 
create table AP_VCHREC (
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
    AP_VCHNO
        CHAR (10),
    AP_VCHORDFRM
        CHAR (10),
    AP_VCHREMIT
        CHAR (10),
    AP_VCHINVOICE
        CHAR (10),
    AP_VCHENTDATE
        INTEGER,
    AP_VCHTRANDATE
        INTEGER,
    AP_VCHINVDATE
        INTEGER,
    AP_VCHSCHDATE
        INTEGER,
    AP_VCHAMT
        DOUBLE PRECISION,
    AP_VCHNONDISAMT
        DOUBLE PRECISION,
    AP_VCHDISPCT
        DOUBLE PRECISION,
    AP_VCHDISAMT
        DOUBLE PRECISION,
    AP_VCHDISDATE
        INTEGER,
    AP_VCHPAYDATE
        INTEGER,
    AP_VCHFISC
        CHAR (4),
    AP_VCH1099F
        SMALLINT,
    AP_VCHPOHNO
        CHAR (10),
    AP_VCHHOLDF
        SMALLINT,
    AP_VCHGROSSPD
        DOUBLE PRECISION,
    AP_VCHWRITOFFAMT
        DOUBLE PRECISION,
    AP_VCHCLOSEF
        SMALLINT,
    AP_VCHBANK
        SMALLINT,
    AP_VCHTRANTYPE
        SMALLINT,
    AP_VCHUSERNAME
        CHAR (12),
    AP_VCHBATCHNO
        INTEGER,
    AP_VCHSEPPAYF
        SMALLINT,
    AP_VCHTRMCHNGF
        INTEGER,
    AP_VCHAMTONHLD
        DOUBLE PRECISION,
    AP_VCHAMTINVRCT
        DOUBLE PRECISION,
    AP_VCHASSOC
        CHAR (10),
    AP_VCHCLOSEDATE
        INTEGER,
    AP_VCHCURCOD
        CHAR (4),
    AP_VCHORIGEXRATE
        DOUBLE PRECISION,
    AP_VCHCUREXRATE
        DOUBLE PRECISION,
    AP_VCHPOHEXRATE
        DOUBLE PRECISION,
    AP_VCHFCAMT
        DOUBLE PRECISION,
    AP_VCHFCNONDISAMT
        DOUBLE PRECISION,
    AP_VCHFCDISAMT
        DOUBLE PRECISION,
    AP_VCHFCGROSSPD
        DOUBLE PRECISION,
    AP_VCHFCWRITOFFAMT
        DOUBLE PRECISION,
    AP_VCHFCAMTONHLD
        DOUBLE PRECISION,
    AP_VCHFCAMTINVRCT
        DOUBLE PRECISION,
    AP_VCHPMTMETH
        SMALLINT,
    AP_VCHUSERNODE
        CHAR (15),
    AP_VCHPAYPLT
        CHAR (12),
    AP_VCHORIGVCHNO
        CHAR (12),
    AP_VCHORIGPLT
        CHAR (12),
    AP_BANKCODE
        SMALLINT,
    AP_BANKCODE345
        SMALLINT,
    AP_BATCHNO
        INTEGER,
    AP_BATCHNO348
        INTEGER,
    AP_INVNO
        CHAR (10),
    AP_VNDCODE
        CHAR (10),
    VENCODE
        CHAR (10),
    VENCODE366
        CHAR (10),
    AP_VNDCODE369
        CHAR (10),
    AP_VNDCODE370
        CHAR (10),
    AP_RECPAYNO
        CHAR (10));
 
create table AP_DMVCHREC (
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
    AP_DEBITNO
        CHAR (10),
    AP_VCHNO
        CHAR (10),
    AP_VCHNO361
        CHAR (10));
 
create table AP_VNDREC (
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
    AP_VNDCODE
        CHAR (10),
    AP_VNDNAME
        CHAR (30),
    AP_VNDADR1
        CHAR (30),
    AP_VNDADR2
        CHAR (30),
    AP_VNDADR3
        CHAR (30),
    AP_VNDADR4
        CHAR (30),
    AP_VNDZIP
        CHAR (10),
    AP_VNDPHONE
        CHAR (12),
    AP_VNDCNTCT
        CHAR (30),
    AP_VNDTYPE
        CHAR (2),
    AP_VNDDISPCT
        DOUBLE PRECISION,
    AP_VNDNETDAY
        INTEGER,
    AP_VNDDISDAY
        INTEGER,
    AP_VND1099F
        SMALLINT,
    AP_VNDSIC
        SMALLINT,
    AP_VNDHOLDF
        SMALLINT,
    AP_VNDBANK
        SMALLINT,
    AP_VNDAPACCT
        CHAR (24),
    AP_VNDPPACCT
        CHAR (24),
    AP_VNDMTDPAY
        DOUBLE PRECISION,
    AP_VNDYTDPAY
        DOUBLE PRECISION,
    AP_VNDMTDDIS
        DOUBLE PRECISION,
    AP_VNDYTDDIS
        DOUBLE PRECISION,
    AP_VNDMTDDLOST
        DOUBLE PRECISION,
    AP_VNDYTDDLOST
        DOUBLE PRECISION,
    AP_VNDNOPAY
        INTEGER,
    AP_VNDNOVCHYTD
        INTEGER,
    AP_VNDDAYSTOPAY
        INTEGER,
    AP_VNDAPBALDUE
        DOUBLE PRECISION,
    AP_VNDEMPF
        SMALLINT,
    AP_VNDEMPDEPT
        CHAR (24),
    AP_VNDTEMPF
        SMALLINT,
    AP_VNDTELNO
        CHAR (20),
    AP_VNDTELEX
        CHAR (12),
    AP_VNDLOCKADR1
        CHAR (30),
    AP_VNDLOCKADR2
        CHAR (30),
    AP_VNDLOCKADR3
        CHAR (30),
    AP_VNDLOCKADR4
        CHAR (30),
    AP_VNDLOCKZIP
        CHAR (10),
    AP_VNDTAXID
        CHAR (16),
    AP_VNDSTAT
        SMALLINT,
    AP_VNDFRACCT
        CHAR (24),
    AP_VNDCURFLG
        SMALLINT,
    AP_VNDCURCOD
        CHAR (4),
    AP_VNDPMTMETH
        SMALLINT,
    AP_VNDBANKSORT
        CHAR (10),
    AP_VNDBANKACCT
        CHAR (24),
    AP_VNDBANKNAME
        CHAR (30),
    AP_VNDBANKTYPE
        SMALLINT,
    AP_VNDFAX
        CHAR (24),
    AP_VNDCENTRALFLG
        INTEGER,
    AP_ACCTNO
        CHAR (24),
    AP_ACCTNO342
        CHAR (24),
    AP_BANKCODE
        SMALLINT);
 
create table FA_ACCTREC (
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
    FA_ACCTNO
        CHAR (24),
    FA_ACCTNAME
        CHAR (30),
    FA_ACCTMTD
        DOUBLE PRECISION,
    FA_ACCTYTD
        DOUBLE PRECISION,
    FA_ACCTSLT
        DOUBLE PRECISION,
    GL_ACCTNO
        CHAR (24));
 
create table FA_PROJREC (
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
    FA_PROJNO
        CHAR (24),
    FA_PROJNAME
        CHAR (30),
    FA_PROJMTD
        DOUBLE PRECISION,
    FA_PROJYTD
        DOUBLE PRECISION,
    FA_PROJPTD
        DOUBLE PRECISION,
    GL_PROJNO
        CHAR (24));
 
create table MATREC (
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
    MATFFLAG
        SMALLINT,
    MATFWAR
        CHAR (10),
    MATFLOC
        CHAR (10),
    MATFLOT
        CHAR (18),
    MATFWONO
        CHAR (10),
    MATFSONO
        CHAR (10),
    MATFPONO
        CHAR (10),
    MATTFLAG
        SMALLINT,
    MATTWAR
        CHAR (10),
    MATTLOC
        CHAR (10),
    MATTLOT
        CHAR (18),
    MATTWONO
        CHAR (10),
    MATTSONO
        CHAR (10),
    MATTPONO
        CHAR (10),
    MATWKCTR
        CHAR (10),
    MATSEQ
        SMALLINT,
    MATLOGON
        CHAR (12),
    MATETIME
        CHAR (8),
    MATEDAT
        INTEGER,
    MATCMD
        CHAR (6),
    MATTDAT
        INTEGER,
    MATGLFLG
        SMALLINT,
    MATID
        CHAR (10),
    MATMQTY
        DOUBLE PRECISION,
    MATFQTY
        DOUBLE PRECISION,
    MATTQTY
        DOUBLE PRECISION,
    MATQOH
        DOUBLE PRECISION,
    MATFSC
        CHAR (4),
    MATMPRT
        CHAR (18),
    MATPRJ
        CHAR (10),
    MATCMT
        DOUBLE PRECISION,
    MATCMO
        DOUBLE PRECISION,
    MATCDL
        DOUBLE PRECISION,
    MATCO1
        DOUBLE PRECISION,
    MATCO2
        DOUBLE PRECISION,
    MATCOP
        DOUBLE PRECISION,
    MATCOO
        DOUBLE PRECISION,
    MATAMO
        DOUBLE PRECISION,
    MATADL
        DOUBLE PRECISION,
    MATAO1
        DOUBLE PRECISION,
    MATAO2
        DOUBLE PRECISION,
    MATAOP
        DOUBLE PRECISION,
    MATAOO
        DOUBLE PRECISION,
    MATPUR
        DOUBLE PRECISION,
    MATECST
        DOUBLE PRECISION,
    MATAUDITDB
        CHAR (3),
    MATAUDITTR
        INTEGER,
    MATSCODE
        SMALLINT,
    MATCRACCT
        CHAR (24),
    MATDRACCT
        CHAR (24),
    MATFIRNO
        CHAR (10),
    MATTIRNO
        CHAR (10),
    MATFENG
        CHAR (10),
    MATTENG
        CHAR (10),
    MATSVQOH
        DOUBLE PRECISION,
    MATTYP
        SMALLINT,
    MATARC
        SMALLINT,
    MATFPACT
        CHAR (24),
    MATTPACT
        CHAR (24),
    MATPONET
        SMALLINT,
    MATUSERNODE
        CHAR (15),
    MATFPC
        CHAR (10),
    MATUOM
        CHAR (2),
    MATUOMCONV
        DOUBLE PRECISION,
    MATUOMQTY
        DOUBLE PRECISION,
    MATFORMULA
        CHAR (20),
    MATTMBONO
        CHAR (10),
    MATFMBONO
        CHAR (10),
    PRTNO
        CHAR (18));
 
create table MISREFREC (
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
    MISREFINFO
        CHAR (30),
    MISITEM
        SMALLINT,
    PRTNO
        CHAR (18));
 
create table QOHREC (
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
    PRTNO
        CHAR (18),
    QOHWAR
        CHAR (10),
    QOHNET
        DOUBLE PRECISION,
    QOHNON
        DOUBLE PRECISION,
    WARCODE
        CHAR (10));
 
create table AP_RCTREC (
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
    AP_RCTNO
        CHAR (10));
 
create table GL_BATCHREC (
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
    GL_BATCHNUM
        CHAR (10),
    GL_BATCHSEQ
        DOUBLE PRECISION,
    GL_BATCHDESC
        CHAR (30),
    GL_BATCHLASTRUN
        INTEGER,
    GL_BATCHTYPE
        SMALLINT,
    GL_BATCHBUDNO
        SMALLINT);
 
create table GL_RE_HREC (
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
    GL_RENAME
        CHAR (16),
    GL_RESEQ
        DOUBLE PRECISION,
    GL_RESTAT
        INTEGER,
    GL_RELASTRUN
        INTEGER,
    GL_REFINALFISC
        CHAR (4),
    GL_REJV
        CHAR (16),
    GL_BATCHNUM
        CHAR (10));
 
create table GL_RE_DREC (
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
    GL_REDRCR
        CHAR (2),
    GL_REAMT
        DOUBLE PRECISION,
    GL_REACTNO
        CHAR (24),
    GL_RECCNO
        CHAR (6),
    GL_ACCTNO
        CHAR (24),
    GL_PROJNO
        CHAR (24),
    GL_RENAME
        CHAR (16));
 
create table GL_RE_NREC (
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
    GL_REDESC
        CHAR (60),
    GL_RENAME
        CHAR (16));
 
create table GL_FP_HREC (
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
    GL_FPNAME
        CHAR (16),
    GL_FPSEQ
        DOUBLE PRECISION,
    GL_FPSTAT
        SMALLINT,
    GL_FPLASTRUN
        INTEGER,
    GL_FPFINALFISC
        CHAR (4),
    GL_FPJV
        CHAR (16),
    GL_FPFRTYPE
        SMALLINT,
    GL_FPOFFACTNO
        CHAR (24),
    GL_FPOFFCCNO
        CHAR (6),
    GL_ACCTNO
        CHAR (24),
    GL_PROJNO
        CHAR (24),
    GL_BATCHNUM
        CHAR (10));
 
create table GL_FP_DREC (
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
    GL_FPPCT
        DOUBLE PRECISION,
    GL_FPACTNO
        CHAR (24),
    GL_FPCCNO
        CHAR (6),
    GL_ACCTNO
        CHAR (24),
    GL_PROJNO
        CHAR (24),
    GL_FPNAME
        CHAR (16));
 
create table GL_FP_NREC (
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
    GL_FPDESC
        CHAR (60),
    GL_FPNAME
        CHAR (16));
 
create table GL_VP_HREC (
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
    GL_VPNAME
        CHAR (16),
    GL_VPSEQ
        DOUBLE PRECISION,
    GL_VPSTAT
        SMALLINT,
    GL_VPLASTRUN
        INTEGER,
    GL_VPFINALFISC
        CHAR (4),
    GL_VPJV
        CHAR (16),
    GL_VPFRTYPE
        SMALLINT,
    GL_VPRATIOTYPE
        SMALLINT,
    GL_VPOFFACTNO
        CHAR (24),
    GL_VPOFFCCNO
        CHAR (6),
    GL_ACCTNO
        CHAR (24),
    GL_PROJNO
        CHAR (24),
    GL_BATCHNUM
        CHAR (10));
 
create table GL_VP_DREC (
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
    GL_VPNAME
        CHAR (16),
    GL_VPACTNO
        CHAR (24),
    GL_VPCCNO
        CHAR (6),
    GL_ACCTNO
        CHAR (24),
    GL_PROJNO
        CHAR (24));
 
create table GL_VPNUM_DREC (
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
    GL_VPNUMOP
        SMALLINT,
    GL_ACCTNO
        CHAR (24),
    GL_VPACTNO
        CHAR (24),
    GL_VPNAME
        CHAR (16));
 
create table GL_VPDEN_DREC (
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
    GL_VPDENOP
        SMALLINT,
    GL_ACCTNO
        CHAR (24),
    GL_VPNAME
        CHAR (16));
 
create table GL_VP_NREC (
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
    GL_VPDESC
        CHAR (60),
    GL_VPNAME
        CHAR (16));
 
create table GL_ABUDNUMREC (
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
    GL_ABUDNUM
        SMALLINT,
    GL_ABUDDESC
        CHAR (60),
    GL_ABUDFLG
        SMALLINT);
 
create table GL_FPFRLINKREC (
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
    GL_ACCTNO
        CHAR (24),
    GL_FPNAME
        CHAR (16));
 
create table GL_VPFRLINKREC (
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
    GL_ACCTNO
        CHAR (24),
    GL_VPNAME
        CHAR (16));
 
create table MA_SERREC (
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
    MA_SERNO
        CHAR (18),
    MA_SERPRTNO
        CHAR (18),
    MA_SERBLANKS
        CHAR (14),
    MA_SEROWN
        CHAR (18),
    MA_SERITEMNO
        SMALLINT,
    MA_SHDPLOT
        CHAR (18),
    MA_SHDPPART
        CHAR (18),
    MA_SHHNO
        CHAR (10),
    MA_SODLIN
        SMALLINT,
    MA_SOHNO
        CHAR (10),
    MA_SHHNO431
        CHAR (10),
    MA_SODLIN431
        SMALLINT,
    MA_SOHNO431
        CHAR (10));
 
create table MA_SVINDREC (
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
    MA_INHNO
        CHAR (10),
    MA_SVINDLIN
        SMALLINT,
    MA_SVINDCODE
        CHAR (18),
    MA_SVINDDESC
        CHAR (30),
    MA_SVINDUOM
        CHAR (2),
    MA_SVINDTYPE
        CHAR (4),
    MA_SVINDQTY
        DOUBLE PRECISION,
    MA_SVINDUNITPRI
        DOUBLE PRECISION,
    MA_SVINDNETEXT
        DOUBLE PRECISION,
    MA_SVINDTXFLG
        SMALLINT,
    MA_SVINDSLACCT
        CHAR (24),
    MA_SVINDDSACCT
        CHAR (24),
    MA_SVINDSERNO
        CHAR (18),
    MA_SVINDMODEL
        CHAR (18),
    MA_SVINDUNITREV
        CHAR (6),
    MA_SVINDTXPRC
        DOUBLE PRECISION,
    MA_SVINDTXCOD
        CHAR (6),
    MA_SVINDMARACCT
        CHAR (24),
    MA_SVINDNETPRI
        DOUBLE PRECISION,
    MA_SVINDDISPCT
        DOUBLE PRECISION,
    MA_SVINDFCNETEXT
        DOUBLE PRECISION,
    MA_SVINDFCNETPRI
        DOUBLE PRECISION,
    MA_SVINHSITE
        CHAR (10));
 
create table MA_SVINHREC (
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
    MA_INHNO
        CHAR (10),
    MA_SVINHSITE
        CHAR (10),
    MA_SVINHPRODNO
        CHAR (18),
    MA_SVINHUNITDESC
        CHAR (30),
    MA_SVINHSERNO
        CHAR (18),
    MA_SVINHMODEL
        CHAR (18),
    MA_SVINHUNITREV
        CHAR (6),
    MA_SVINHIRNO
        CHAR (10),
    MA_SVINHNAME
        CHAR (30),
    MA_SVINHADR1
        CHAR (30),
    MA_SVINHADR2
        CHAR (30),
    MA_SVINHADR3
        CHAR (30),
    MA_SVINHCITY
        CHAR (20),
    MA_SVINHSTATE
        CHAR (8),
    MA_SVINHZIP
        CHAR (10),
    MA_SVINHCTRY
        CHAR (10),
    MA_SVINHGEO
        CHAR (10),
    MA_BILNO
        CHAR (10));
 
create table INVREC (
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
    INVNO
        CHAR (10),
    INVDESC
        CHAR (30),
    INVFLG
        SMALLINT,
    INVACTFLG
        SMALLINT,
    INVACTNO
        CHAR (24),
    INVNET
        SMALLINT,
    INVNPFLG
        SMALLINT);
 
create table MA_REMREC (
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
    MA_REMCOD
        CHAR (6),
    MA_REMADR1
        CHAR (30),
    MA_REMADR2
        CHAR (30),
    MA_REMADR3
        CHAR (30),
    MA_REMCITY
        CHAR (20),
    MA_REMSTATE
        CHAR (8),
    MA_REMZIP
        CHAR (10),
    MA_REMCTRY
        CHAR (10),
    MA_REMGEO
        CHAR (10));
 
create table AP_VTPSTREC (
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
    AP_VTPSTTXVAL
        DOUBLE PRECISION,
    AP_VTPSTTXAMT
        DOUBLE PRECISION,
    AP_VTPSTFSC
        CHAR (4),
    AP_VTPSTTYP
        SMALLINT,
    AP_VTPSTFCTXVAL
        DOUBLE PRECISION,
    AP_VTPSTFCTXAMT
        DOUBLE PRECISION,
    AP_VTPSTCHK
        INTEGER,
    AP_VTPSTCHKBNK
        SMALLINT,
    AP_VCHNO
        CHAR (10),
    AP_VATCOD
        CHAR (4));
 
create table AP_VATREC (
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
    AP_VATCOD
        CHAR (4),
    AP_VATDESC
        CHAR (30),
    AP_VATRAT
        DOUBLE PRECISION,
    AP_VATMTDPU
        DOUBLE PRECISION,
    AP_VATMTD1PU
        DOUBLE PRECISION,
    AP_VATMTD2PU
        DOUBLE PRECISION,
    AP_VATMTD3PU
        DOUBLE PRECISION,
    AP_VATYTDPU
        DOUBLE PRECISION,
    AP_VATMTDTX
        DOUBLE PRECISION,
    AP_VATMTD1TX
        DOUBLE PRECISION,
    AP_VATMTD2TX
        DOUBLE PRECISION,
    AP_VATMTD3TX
        DOUBLE PRECISION,
    AP_VATYTDTX
        DOUBLE PRECISION,
    AP_VATGLACCT
        CHAR (24),
    AP_VATGLCRACCT
        CHAR (24));
 
create table ACSTREC (
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
    ACSTQTY
        DOUBLE PRECISION,
    ACSTMAT
        DOUBLE PRECISION,
    ACSTMATO
        DOUBLE PRECISION,
    ACSTLAB
        DOUBLE PRECISION,
    ACSTLABO
        DOUBLE PRECISION,
    LOCCODE
        CHAR (10),
    LOCWAR
        CHAR (10),
    LOTNO
        CHAR (18),
    PRTNO
        CHAR (18));
 
create table MA_QUODREC (
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
    MA_QUOHNO
        CHAR (10),
    MA_QUODLIN
        SMALLINT,
    MA_QUODORDQTY
        DOUBLE PRECISION,
    MA_QUODREQDAT
        INTEGER,
    MA_QUODREQDATFLG
        SMALLINT,
    MA_QUODORIGSCHDAT
        INTEGER,
    MA_QUODSCHDAT
        INTEGER,
    MA_QUODLST
        DOUBLE PRECISION,
    MA_QUODADJ
        DOUBLE PRECISION,
    MA_QUODMCST
        DOUBLE PRECISION,
    MA_QUODLCST
        DOUBLE PRECISION,
    MA_QUODOCST
        DOUBLE PRECISION,
    MA_QUODVOCST
        DOUBLE PRECISION,
    MA_QUODDISPCT
        DOUBLE PRECISION,
    MA_QUODPRTABDISPCT
        DOUBLE PRECISION,
    MA_QUODTOTSAPCT
        DOUBLE PRECISION,
    MA_QUODCUSPART
        CHAR (18),
    MA_QUODTXFLG
        SMALLINT,
    MA_QUODMRP
        SMALLINT,
    MA_QUODSOCAT
        CHAR (6),
    MA_QUODWAR
        CHAR (10),
    MA_QUODPRODNO
        CHAR (18),
    MA_QUODOPT
        SMALLINT,
    MA_QUODCOMPPRI
        SMALLINT,
    MA_QUODTXPRC
        DOUBLE PRECISION,
    MA_QUODTXCOD
        CHAR (6),
    MA_QUODCOMBLFLG
        SMALLINT,
    MA_QUODFCADJ
        DOUBLE PRECISION,
    MA_QUODPACT
        CHAR (24),
    MA_QUODTERMS
        INTEGER,
    MA_SHPNO
        CHAR (10),
    MA_PRODNO
        CHAR (18),
    MA_SODLIN
        SMALLINT,
    MA_SOHNO
        CHAR (10));
 
create table MA_QUOHREC (
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
    MA_SHPNO
        CHAR (10),
    MA_QUOHNO
        CHAR (10),
    MA_QUOHSTAT
        SMALLINT,
    MA_QUOHFISC
        CHAR (4),
    MA_QUOHRSNCOD
        CHAR (6),
    MA_QUOHDAT
        INTEGER,
    MA_QUOHENTDAT
        INTEGER,
    MA_QUOHEXPDAT
        INTEGER,
    MA_QUOHRESDAT
        INTEGER,
    MA_QUOHUPDDAT
        INTEGER,
    MA_QUOHPRTDAT
        INTEGER,
    MA_QUOHCNTRC
        CHAR (24),
    MA_QUOHPAYTCOD
        CHAR (6),
    MA_QUOHFRTCOD
        CHAR (6),
    MA_QUOHFRTTCOD
        CHAR (6),
    MA_QUOHTXCOD
        CHAR (6),
    MA_QUOHREV
        SMALLINT,
    MA_QUOHUSER
        CHAR (12),
    MA_QUOHSACOD
        CHAR (6),
    MA_QUOHTYPE
        CHAR (6),
    MA_QUOHCPONO
        CHAR (30),
    MA_QUOHNAME
        CHAR (30),
    MA_QUOHADR1
        CHAR (30),
    MA_QUOHADR2
        CHAR (30),
    MA_QUOHADR3
        CHAR (30),
    MA_QUOHCITY
        CHAR (20),
    MA_QUOHSTATE
        CHAR (8),
    MA_QUOHZIP
        CHAR (10),
    MA_QUOHCTRY
        CHAR (10),
    MA_QUOHPRODLICNO
        CHAR (20),
    MA_QUOHLOCLICNO
        CHAR (20),
    MA_QUOHTXFLG
        SMALLINT,
    MA_QUOHSAFLG
        SMALLINT,
    MA_QUOHCURCOD
        CHAR (4),
    MA_QUOHORIGEXRATE
        DOUBLE PRECISION,
    MA_QUOHCUREXRATE
        DOUBLE PRECISION,
    MA_QUOHUSERNODE
        CHAR (15),
    MA_QUOHTRAN
        INTEGER,
    MA_QUOHGEO
        CHAR (10),
    MA_QUOHPRTSET
        SMALLINT,
    MA_QUOHUPDSET
        SMALLINT,
    MA_BILNO
        CHAR (10),
    MA_CTERCOD
        CHAR (6),
    MA_SOHNO
        CHAR (10));
 
create table MA_OPTREC (
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
    MA_OPTCOMPNO
        CHAR (18),
    MA_OPTDESC
        CHAR (30),
    MA_OPTFTRNO
        CHAR (18),
    MA_OPTQPA
        DOUBLE PRECISION,
    MA_OPTREQOPT
        SMALLINT,
    MA_OPTSORTKEY
        SMALLINT,
    MA_OPTPRNTFLG
        SMALLINT,
    MA_OPTPRIPRNTFLG
        SMALLINT,
    MA_OPTLST
        DOUBLE PRECISION,
    MA_OPTADJ
        DOUBLE PRECISION,
    MA_OPTDISPCT
        DOUBLE PRECISION,
    MA_OPTPRTABDISPCT
        DOUBLE PRECISION,
    MA_OPTMCST
        DOUBLE PRECISION,
    MA_OPTLCST
        DOUBLE PRECISION,
    MA_OPTOCST
        DOUBLE PRECISION,
    MA_OPTVOCST
        DOUBLE PRECISION,
    MA_OPTKITPKFLG
        SMALLINT,
    MA_OPTMINQPA
        DOUBLE PRECISION,
    MA_OPTMAXQPA
        DOUBLE PRECISION,
    MA_OPTFCADJ
        DOUBLE PRECISION,
    MA_OPTSERFLG
        SMALLINT,
    MA_OPTITEMNO
        SMALLINT,
    MA_PFAMCOD
        CHAR (6),
    MA_PLINCOD
        CHAR (6),
    MA_PRODNO
        CHAR (18),
    MA_QUODLIN
        SMALLINT,
    MA_QUOHNO
        CHAR (10),
    MA_PRODNO466
        CHAR (18),
    MA_SODLIN466
        SMALLINT,
    MA_SOHNO466
        CHAR (10),
    MA_PARTNO
        CHAR (18));
 
create table MA_INHLREC (
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
    MA_INHLDAT
        INTEGER,
    MA_INHLFISC
        CHAR (4),
    MA_INHLAMT
        DOUBLE PRECISION,
    MA_INHLTXBLAMT
        DOUBLE PRECISION,
    MA_INHLTXAMT
        DOUBLE PRECISION,
    MA_INHLPRODTXAMT
        DOUBLE PRECISION,
    MA_INHLREFNO
        CHAR (10),
    MA_INHLSOH
        CHAR (10),
    MA_INHLCPO
        CHAR (30),
    MA_INHLSHPNO
        CHAR (10),
    MA_INHLDMHNO
        CHAR (10),
    MA_INHLVDPOSTTRNNO
        INTEGER,
    MA_INHLFCAMT
        DOUBLE PRECISION,
    MA_INHLFCTXBLAMT
        DOUBLE PRECISION,
    MA_INHLFCTXAMT
        DOUBLE PRECISION,
    MA_INHLEXRATE
        DOUBLE PRECISION,
    MA_INHLFCPRODTXAMT
        DOUBLE PRECISION,
    MA_BILNO
        CHAR (10),
    MA_INHNO
        CHAR (10),
    MA_BILNO469
        CHAR (10),
    MA_CMHNO469
        CHAR (10),
    MA_RSNCOD469
        CHAR (6));
 
create table MA_DMHLREC (
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
    MA_DMHLAMT
        DOUBLE PRECISION,
    MA_DMHLREFNO
        CHAR (10),
    MA_DMHLFCAMT
        DOUBLE PRECISION,
    MA_BILNO
        CHAR (10),
    MA_DMHNO
        CHAR (10),
    MA_BILNO471
        CHAR (10),
    MA_CMHNO471
        CHAR (10),
    MA_RSNCOD471
        CHAR (6));
 
create table AP_HDRREC (
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
    AP_HDRSYSDEFFLG
        SMALLINT,
    AP_HDRBNKCODFLG
        SMALLINT,
    AP_HDRNONDISFLG
        SMALLINT,
    AP_HDRDISPCTFLG
        SMALLINT,
    AP_HDRDISAMTFLG
        SMALLINT,
    AP_HDRDISDAYFLG
        SMALLINT,
    AP_HDRSEPPAYFLG
        SMALLINT,
    AP_HDRNETDAYFLG
        SMALLINT,
    AP_HDRVCHHLDFLG
        SMALLINT,
    AP_HDRAMTHLDFLG
        SMALLINT,
    AP_HDR1099FLG
        SMALLINT,
    AP_HDRSCHPAYFLG
        SMALLINT,
    AP_HDRVCHPMTFLG
        SMALLINT,
    AP_HDRSET
        SMALLINT);
 
create table PRHREC (
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
    PRHNO
        INTEGER,
    PRHNET
        SMALLINT,
    PRHPC
        CHAR (2),
    PRHBC
        CHAR (2),
    PRHDEPT
        CHAR (10),
    PRHAMT
        DOUBLE PRECISION,
    PRHENDAT
        INTEGER,
    PRHCNVDAT
        INTEGER,
    PRHCHGDAT
        INTEGER,
    PRHSTAT
        SMALLINT,
    PRHSVEN
        CHAR (10),
    PRHPRNT
        SMALLINT,
    PRHPRDAT
        INTEGER,
    PRHAUT
        CHAR (12),
    PRHUSERNODE
        CHAR (15),
    PRHREMAMT
        DOUBLE PRECISION,
    PRHHSHSET
        SMALLINT,
    POHNO
        CHAR (10),
    VENCODE
        CHAR (10),
    IDCODE
        CHAR (4),
    AUTLOGON
        CHAR (12));
 
create table PRDREC (
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
    PRHNO
        INTEGER,
    PRDLINE
        SMALLINT,
    PRDMPRT
        CHAR (18),
    PRDREV
        CHAR (2),
    PRDDDAT
        INTEGER,
    PRDADAT
        INTEGER,
    PRDENDAT
        INTEGER,
    PRDPUOM
        CHAR (2),
    PRDCONV
        DOUBLE PRECISION,
    PRDACTNO
        CHAR (24),
    PRDQTY
        DOUBLE PRECISION,
    PRDNET
        SMALLINT,
    PRDPRH
        INTEGER,
    PRDSTAT
        SMALLINT,
    PRDCOST
        DOUBLE PRECISION,
    PRDCONVQTY
        DOUBLE PRECISION,
    PODLINENUM
        INTEGER,
    POHNO
        CHAR (10),
    PRTNO
        CHAR (18));
 
create table AUTREC (
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
    AUTLOGON
        CHAR (12),
    AUTLEV
        DOUBLE PRECISION,
    AUTUSERNODE
        CHAR (15),
    AUTHSHSET
        SMALLINT);
 
create table APPREC (
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
    APPDATE
        INTEGER,
    APPFLAG
        SMALLINT,
    APPCODE
        SMALLINT,
    AUTLOGON
        CHAR (12),
    PRHNO
        INTEGER);
 
create table IDREC (
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
    IDCODE
        CHAR (4),
    IDNAME
        CHAR (20),
    IDTYPE
        SMALLINT,
    IDHSHSET
        SMALLINT);
 
create table PFAMREC (
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
    PFAMPRTNO
        CHAR (18),
    PRTNO
        CHAR (18),
    PFAMHSHSET
        SMALLINT);
 
create table AP_SEARCHREC (
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
    AP_SEARCHSTRING
        CHAR (2),
    AP_SEARCHHSHSET
        SMALLINT,
    AP_SEARCHSRTSET
        SMALLINT);
 
create table DESREC (
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
    DESDESC
        CHAR (60),
    DESCODE
        SMALLINT,
    PRTNO
        CHAR (18));
 
create table AP_RECPAYREC (
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
    AP_RECPAYNO
        CHAR (10),
    AP_RECPAYREMIT
        CHAR (10),
    AP_RECPAYAMT
        DOUBLE PRECISION,
    AP_RECPAYNOVCH
        SMALLINT,
    AP_RECPAYNOCREAT
        SMALLINT,
    AP_RECPAYNXTDATE
        INTEGER,
    AP_RECPAYNXTFLG
        SMALLINT,
    AP_RECPAYUSERNAME
        CHAR (12),
    AP_RECPAYCHNGDATE
        INTEGER,
    AP_RECPAYCHNGUSER
        CHAR (12),
    AP_RECPAYSTAT
        SMALLINT,
    AP_RECPAYPOHNO
        CHAR (10),
    AP_RECPAYDUEDATE
        SMALLINT,
    AP_RECPAYLSTDATE
        INTEGER,
    AP_RECPAYLSTVCHNO
        CHAR (10),
    AP_RECPAYUSERNODE
        CHAR (15),
    AP_RECPAYCHNGNODE
        CHAR (15),
    AP_RECPAY1099F
        SMALLINT,
    AP_RECPAYPMTMETH
        SMALLINT,
    AP_RECPAYPLT
        CHAR (12),
    AP_RECPAYCHNSET
        SMALLINT);
 
create table AP_RECPOSTREC (
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
    AP_RECPOSTACCTNO
        CHAR (24),
    AP_RECPOSTAMT
        DOUBLE PRECISION,
    AP_RECPOSTTRANTYPE
        SMALLINT,
    AP_RECPOSTDESC
        CHAR (30),
    AP_RECPOSTPROJNO
        CHAR (24),
    AP_RECPOSTCSTCAT
        CHAR (6),
    AP_RECPOSTVATTXVAL
        DOUBLE PRECISION,
    AP_RECPAYNO
        CHAR (10));
 
create table AP_RECNOTEREC (
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
    AP_RECNOTELINE
        SMALLINT,
    AP_RECNOTE
        CHAR (30),
    AP_RECPAYNO
        CHAR (10));
 
create table FSCCALREC (
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
    FSCCALYEAR
        INTEGER,
    FSCCALPER1
        INTEGER,
    FSCCALPER2
        INTEGER,
    FSCCALPER3
        INTEGER,
    FSCCALPER4
        INTEGER,
    FSCCALPER5
        INTEGER,
    FSCCALPER6
        INTEGER,
    FSCCALPER7
        INTEGER,
    FSCCALPER8
        INTEGER,
    FSCCALPER9
        INTEGER,
    FSCCALPER10
        INTEGER,
    FSCCALPER11
        INTEGER,
    FSCCALPER12
        INTEGER,
    FSCCALPER13
        INTEGER,
    FSCCALEND
        INTEGER,
    FSCCALNEWWEEK
        INTEGER);
 
create table CURREC (
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
    CURCOD
        CHAR (4),
    CURDESC
        CHAR (30),
    CURAMTPF
        SMALLINT,
    CURDISPPF
        SMALLINT,
    CURPRIPF
        SMALLINT,
    CUROMACCT
        CHAR (24),
    CURAPACCT
        CHAR (24),
    CURAPRATE
        DOUBLE PRECISION,
    CURPORATE
        DOUBLE PRECISION,
    CUROMRATE
        DOUBLE PRECISION,
    CURLDU
        DOUBLE PRECISION,
    CUROFRATE
        DOUBLE PRECISION);
 
create table CUREXREC (
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
    CUREXFISC
        CHAR (4),
    CUREXAPRATE
        DOUBLE PRECISION,
    CUREXPORATE
        DOUBLE PRECISION,
    CUREXOMRATE
        DOUBLE PRECISION,
    CUREXEAPRATE
        DOUBLE PRECISION,
    CUREXEPORATE
        DOUBLE PRECISION,
    CUREXEOMRATE
        DOUBLE PRECISION,
    CUREXENTDAT
        INTEGER,
    CUREXUSER
        CHAR (12),
    CUREXUSERNODE
        CHAR (15),
    CUREXOFRATE
        DOUBLE PRECISION,
    CUREXEOFRATE
        DOUBLE PRECISION,
    CURCOD
        CHAR (4));
 
create table MA_FCPRTABREC (
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
    MA_FCPRTABCT
        CHAR (10),
    MA_FCPRTABPT
        CHAR (18),
    MA_FCPRTABCURCOD
        CHAR (4),
    MA_FCPRTABQTY
        DOUBLE PRECISION,
    MA_FCPRTABEFFDAT
        INTEGER,
    MA_FCPRTABOBSDAT
        INTEGER,
    MA_FCPRTABDISPCT
        DOUBLE PRECISION,
    MA_FCPRTABDISFLG
        SMALLINT,
    MA_BILCT
        CHAR (6),
    MA_BILNO
        CHAR (10),
    MA_PFAMCOD
        CHAR (6),
    MA_PLINCOD
        CHAR (6),
    MA_PRODNO
        CHAR (18),
    MA_PRCT
        CHAR (6),
    MA_PRPT
        CHAR (6));
 
create table MA_PARTREC (
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
    MA_PARTNO
        CHAR (18),
    MA_PARTDESC
        CHAR (30));
 
create table INTREC (
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
    INTPC
        CHAR (10),
    INTIPO
        CHAR (10),
    INTACCT
        CHAR (24),
    INTQTYSHP
        DOUBLE PRECISION,
    INTSHPDAT
        INTEGER,
    INTSHPID
        CHAR (10),
    INTSHPTYP
        SMALLINT,
    INTQTYREC
        DOUBLE PRECISION,
    INTRECDAT
        INTEGER,
    INTQTYLOST
        DOUBLE PRECISION,
    INTBLNUM
        CHAR (20),
    INTPRTDAT
        INTEGER,
    INTSET
        SMALLINT,
    PRTNO
        CHAR (18),
    SODLINE
        SMALLINT,
    SOHNO
        CHAR (10),
    PRTNO516
        CHAR (18),
    WARCODE
        CHAR (10));
 
create table IRCTREC (
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
    IRCTPC
        CHAR (10),
    IRCTIPO
        CHAR (10),
    IRCTQTY
        DOUBLE PRECISION,
    IRCTTYP
        SMALLINT,
    IRCTSYDAT
        INTEGER,
    IRCTCMD
        CHAR (6),
    IRCTID
        SMALLINT,
    IRCTBDAT
        INTEGER,
    IRCTBID
        INTEGER,
    PRTNO
        CHAR (18),
    IRCTSET
        SMALLINT,
    PODLINENUM
        INTEGER,
    POHNO
        CHAR (10),
    VENCODE
        CHAR (10));
 
create table INDFREC (
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
    INDFPLNT
        CHAR (10),
    INDFMDAYS
        INTEGER,
    INDFACCT
        CHAR (24),
    INDFNAME
        CHAR (3),
    INDFHSHSET
        SMALLINT);
 
create table AP_1099REC (
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
    AP_1099FNAME
        CHAR (20),
    AP_1099LNAME
        CHAR (20),
    AP_1099ADDR
        CHAR (40),
    AP_1099CITY
        CHAR (29),
    AP_1099STATE
        CHAR (2),
    AP_1099ZIP
        CHAR (9),
    AP_1099NAMECTRL
        CHAR (4),
    AP_1099TINTYPE
        CHAR (1),
    AP_1099FCFLAG
        CHAR (1),
    AP_VNDCODE
        CHAR (10));
 
create table AP_BTCHEFTREC (
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
    AP_BTCHEFTNO
        INTEGER,
    AP_BTCHEFTDATE
        INTEGER,
    AP_BTCHEFTUSER
        CHAR (12),
    AP_BTCHEFTUSERNODE
        CHAR (15));
 
create table AP_PMTREC (
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
    AP_PMTEFTNO
        INTEGER,
    AP_PMTBANKSORT
        CHAR (10),
    AP_PMTVNDBANKSORT
        CHAR (10),
    AP_PMTVNDBANKACCT
        CHAR (24),
    AP_PMTVNDBANKNAME
        CHAR (30),
    AP_PMTVNDBANKTYPE
        SMALLINT,
    AP_PMTVNDCODE
        CHAR (10),
    AP_PMTCREATEDATE
        INTEGER,
    AP_PMTAMT
        DOUBLE PRECISION,
    AP_PMTFCAMT
        DOUBLE PRECISION,
    AP_PMTCURCOD
        CHAR (4),
    AP_PMTEXRATE
        DOUBLE PRECISION,
    AP_PMTBTCHNO
        INTEGER,
    AP_PMTSUBMITDATE
        INTEGER,
    AP_PMTBANKCODE
        SMALLINT,
    AP_PMTNOTTRANSSET
        SMALLINT,
    AP_BTCHEFTNO
        INTEGER);
 
create table PAYREC (
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
    PAYCODE
        CHAR (8));
 
create table AP_PAYOR1099REC (
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
    AP_PAYOR1099HSHKEY
        CHAR (1),
    AP_PAYOR1099NAME
        CHAR (40),
    AP_PAYOR1099ADDR
        CHAR (40),
    AP_PAYOR1099CITY
        CHAR (29),
    AP_PAYOR1099STATE
        CHAR (2),
    AP_PAYOR1099ZIP
        CHAR (9),
    AP_PAYOR1099TIN
        CHAR (16),
    AP_PAYOR1099NAMECTRL
        CHAR (4),
    AP_PAYOR1099TCC
        CHAR (5),
    AP_PAYOR1099FCFLAG
        CHAR (1),
    AP_PAYOR1099ADDR2
        CHAR (40));
 
create table AP_PNOTREC (
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
    AP_PNOTNO
        CHAR (10),
    AP_PNOTVNDCODE
        CHAR (10),
    AP_PNOTTYPE
        SMALLINT,
    AP_PNOTAMT
        DOUBLE PRECISION,
    AP_PNOTBANKCODE
        SMALLINT,
    AP_PNOTCHKNO
        INTEGER,
    AP_PNOTPRNTFLG
        SMALLINT,
    AP_PNOTSTAT
        SMALLINT,
    AP_PNOTCREDATE
        INTEGER,
    AP_PNOTDUEDATE
        INTEGER,
    AP_PNOTACCTNO
        CHAR (24),
    AP_PNOTCURCOD
        CHAR (4));
 
create table AP_PNOTVCHREC (
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
    AP_PNOTVCHVCHNO
        CHAR (10),
    AP_PNOTVCHAMT
        DOUBLE PRECISION,
    AP_VCHNO
        CHAR (10),
    AP_PNOTNO
        CHAR (10));
 
create table MA_PNOTREC (
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
    MA_PNOTNO
        CHAR (10),
    MA_PNOTBILNO
        CHAR (10),
    MA_PNOTTYPE
        SMALLINT,
    MA_PNOTAMT
        DOUBLE PRECISION,
    MA_PNOTPRNTFLG
        SMALLINT,
    MA_PNOTSTAT
        SMALLINT,
    MA_PNOTCREDATE
        INTEGER,
    MA_PNOTDUEDATE
        INTEGER,
    MA_PNOTACCTNO
        CHAR (24),
    MA_PNOTCURCOD
        CHAR (4));
 
create table MA_PNOTINVREC (
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
    MA_PNOTINVINHNO
        CHAR (10),
    MA_PNOTINVAMT
        DOUBLE PRECISION,
    MA_BILNO
        CHAR (10),
    MA_INHNO
        CHAR (10));
 
create table CPRREC (
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
    CPRPOHNO
        CHAR (10),
    CPRPODLINENUM
        INTEGER,
    CPRPRHNO
        INTEGER,
    CPRPRDLINE
        SMALLINT,
    CPRPODQTY
        DOUBLE PRECISION,
    CPRPRHCNVDAT
        INTEGER,
    POHNO
        CHAR (10),
    PRHNO
        INTEGER);
 
create table AP_PAYPLTREC (
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
    AP_PAYORIGPLT
        CHAR (12),
    AP_PAYPLT
        CHAR (12),
    AP_PAYCLEARACCT
        CHAR (24),
    AP_PAYORIGFILE
        CHAR (44));
 
create table AP_PLTREC (
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
    AP_PLTCODE
        CHAR (12),
    AP_PLTTYPE
        INTEGER,
    AP_PLTDESC
        CHAR (32),
    AP_PLTFREIGHTACCT
        CHAR (24),
    AP_PLTVND
        CHAR (12),
    AP_PLTLSTTRDATE
        INTEGER,
    AP_VNDCODE
        CHAR (10));
 
create table FRTREC (
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
    FRTNO
        CHAR (16),
    FRTNAME
        CHAR (32));
 
create table BOLREC (
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
    FRTNO
        CHAR (16),
    BOLNO
        CHAR (20),
    BOLUSERNAME
        CHAR (12),
    BOLENTDAT
        INTEGER,
    BOLSTAT
        INTEGER,
    BOLORIGFRTNO
        CHAR (16),
    BOLFRTNO
        CHAR (16),
    BOLUSERNODE
        CHAR (24));
 
create table BOLLREC (
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
    BOLLNO
        CHAR (20),
    BOLLPOHNO
        CHAR (12),
    POHNO
        CHAR (10),
    BOLNO
        CHAR (20),
    FRTNO
        CHAR (16));
 
create table BYDREC (
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
    BYDCOD
        CHAR (2),
    BYDUSERDEF1
        CHAR (6),
    BYDDESC
        CHAR (32));
 
create table POPREC (
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
    POPCST
        DOUBLE PRECISION,
    POPAMTPD
        DOUBLE PRECISION,
    POPSEPCHGFLG
        INTEGER,
    POPCHGTYP
        INTEGER,
    POPPERUNIT
        INTEGER,
    POPACTNO
        CHAR (24),
    POPFCCST
        DOUBLE PRECISION,
    POPFCAMTPD
        DOUBLE PRECISION,
    POPVCHFLG
        INTEGER,
    POPLINENUM
        INTEGER,
    POPSTAT
        INTEGER,
    POPPRTNO
        CHAR (18),
    POPPACT
        CHAR (24),
    POPCSTCAT
        CHAR (6),
    POPUSERDEF1
        INTEGER,
    PODLINENUM
        INTEGER,
    POHNO
        CHAR (10),
    POHNO583
        CHAR (10));
 
create table POMREC (
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
    POMPCT
        DOUBLE PRECISION,
    POMACTNO
        CHAR (24),
    PODLINENUM
        INTEGER,
    POHNO
        CHAR (10));
 
create table RCTMREC (
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
    RCTMPCT
        DOUBLE PRECISION,
    RCTMACTNO
        CHAR (24),
    RCTNO
        CHAR (10),
    VENCODE
        CHAR (10));
 
create table GENREC (
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
    GENITMCOD
        CHAR (20),
    GENPUOM
        CHAR (2),
    GENUSERDEF1
        CHAR (2),
    GENDESC
        CHAR (32));
 
create table COHREC (
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
    COHNO
        CHAR (10),
    COHBC
        CHAR (2),
    COHVENDOR
        CHAR (10),
    COHBILLTO
        CHAR (10),
    COHDPCT
        DOUBLE PRECISION,
    COHQTY
        DOUBLE PRECISION,
    COHQPRI
        DOUBLE PRECISION,
    COHFCQPRI
        DOUBLE PRECISION,
    COHMAXVAL
        DOUBLE PRECISION,
    COHFCMAXVAL
        DOUBLE PRECISION,
    COHNET
        INTEGER,
    COHDAT
        INTEGER,
    COHENDAT
        INTEGER,
    COHPRFLG
        INTEGER,
    COHPRDAT
        INTEGER,
    COHCLDAT
        INTEGER,
    COHCON
        INTEGER,
    COHCODAT
        INTEGER,
    COHFOB
        INTEGER,
    COHFRT
        INTEGER,
    COHDDAYS
        INTEGER,
    COHNDAYS
        INTEGER,
    COHTYP
        INTEGER,
    COHEXPDAT
        INTEGER,
    COHPRNTCNT
        INTEGER,
    COHCURCOD
        CHAR (4),
    COHAGENT
        CHAR (32),
    COHGENITM
        CHAR (20),
    COHPURCHUOM
        CHAR (2),
    COHCONF
        CHAR (30),
    COHVIA
        CHAR (30),
    COHRQSTR
        CHAR (30),
    COHPAYPLNT
        CHAR (10),
    COHTRAN
        INTEGER,
    COHUSERDEF1
        CHAR (2),
    COHUSERDEF2
        INTEGER,
    VENCODE
        CHAR (10));
 
create table CDLREC (
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
    CDLPRTNO
        CHAR (18),
    CDLPUOM
        CHAR (2),
    CDLUNITPR
        DOUBLE PRECISION,
    CDLFCUNITPR
        DOUBLE PRECISION,
    CDLGCONV
        DOUBLE PRECISION,
    CDLDISC
        DOUBLE PRECISION,
    CDLQPRI
        DOUBLE PRECISION,
    CDLFCQPRI
        DOUBLE PRECISION,
    CDLQTY
        DOUBLE PRECISION,
    CDLCONV
        DOUBLE PRECISION,
    CDLMWGT
        DOUBLE PRECISION,
    CDLLINENUM
        INTEGER,
    CDLPRTTYP
        INTEGER,
    CDLENDAT
        INTEGER,
    CDLCLDAT
        INTEGER,
    CDLTYP
        INTEGER,
    CDLPRFLG
        INTEGER,
    CDLREV
        CHAR (2),
    CDLCOHNO
        CHAR (10),
    CDLMFGNO
        CHAR (18),
    CDLCHAR8
        CHAR (8),
    CDLMCOMMCOD
        CHAR (8),
    CDLMPRTDESC
        CHAR (32),
    CDLVSSNUM
        INTEGER,
    PRTNO
        CHAR (18));
 
create table CDAREC (
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
    CDAPLTCOD
        CHAR (10),
    CDACOHNO
        CHAR (10),
    CDAPRTNO
        CHAR (18),
    CDAASQTY
        DOUBLE PRECISION,
    CDAALQTY
        DOUBLE PRECISION,
    CDARCVQTY
        DOUBLE PRECISION,
    CDATERMS
        INTEGER,
    CDAPOTYP
        INTEGER,
    CDAACTNO
        CHAR (24),
    CDAUSERDEF1
        CHAR (6),
    CDAUSERDEF2
        INTEGER,
    CDLLINENUM
        INTEGER,
    CDLPRTNO
        CHAR (18));
 
create table CDPREC (
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
    CDPPONO
        CHAR (10),
    CDPPOID
        INTEGER,
    CDPALLOCQTY
        DOUBLE PRECISION,
    CDPRCVQTY
        DOUBLE PRECISION,
    CDPRELQTY
        DOUBLE PRECISION,
    CDPSTAT
        INTEGER,
    CDPUSERDEF1
        CHAR (6),
    CDPUSERDEF2
        INTEGER);
 
create table CDPLREC (
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
    CDPLPOLINE
        INTEGER,
    CDPLCLDAT
        INTEGER,
    CDPLCNTRALLQTY
        DOUBLE PRECISION,
    CDPLLOCCHGQTY
        DOUBLE PRECISION,
    CDPLALLOCQTY
        DOUBLE PRECISION,
    CDPLTRANSDAT
        CHAR (24),
    CDPLHRDT
        INTEGER,
    CDPLPUOM
        CHAR (2),
    CDPLDUDAT
        INTEGER,
    CDPLRELQTY
        DOUBLE PRECISION,
    CDPLRCVQTY
        DOUBLE PRECISION,
    CDPLERRFLG
        INTEGER,
    CDPLERRSTAT
        CHAR (72));
 
create table COPREC (
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
    COPCST
        DOUBLE PRECISION,
    COPSEPCHGFLG
        INTEGER,
    COPCHGTYP
        INTEGER,
    COPPERUNIT
        INTEGER,
    COPFCCST
        DOUBLE PRECISION,
    COPUSERDEF1
        INTEGER,
    CDLLINENUM
        INTEGER,
    CDLPRTNO
        CHAR (18));
 
create table CONREC (
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
    CONTYP
        INTEGER,
    CONCOM
        CHAR (60),
    CDLLINENUM
        INTEGER,
    CDLPRTNO
        CHAR (18));
 
create table AP_INVRCTMREC (
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
    AP_INRCTMPCT
        DOUBLE PRECISION,
    AP_INRCTMACTNO
        CHAR (24));
 
create table AP_BOLREC (
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
    AP_BOLNO
        CHAR (20),
    AP_BOLVNDCODE
        CHAR (12),
    AP_BOLAMT
        DOUBLE PRECISION,
    AP_BOLFCAMT
        DOUBLE PRECISION,
    AP_VNDCODE
        CHAR (10));
 
create table AP_BOLLREC (
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
    AP_BOLLNO
        CHAR (20),
    AP_BOLLVCHNO
        CHAR (12),
    AP_BOLLAMT
        DOUBLE PRECISION,
    AP_BOLLFCAMT
        DOUBLE PRECISION,
    AP_BOLLVDDATE
        INTEGER,
    AP_BOLLVCHTRTYPE
        INTEGER,
    AP_VCHNO
        CHAR (10),
    AP_BOLNO
        CHAR (20));
 
create table MA_FLDREC (
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
    MA_FLDNO
        INTEGER,
    MA_FLDATTRIBUTE
        INTEGER,
    MA_FLDDEFAULT
        CHAR (30),
    MA_FLDTYPE
        INTEGER,
    MA_FLDBLANKS
        CHAR (2),
    MA_USRNAME
        CHAR (12));
 
create table MA_USRREC (
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
    MA_USRNAME
        CHAR (12),
    MA_USRCMD
        CHAR (6),
    MA_USRBLANKS
        CHAR (2));
 
create table AP_POPREC (
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
    AP_POPPOHNO
        CHAR (10),
    AP_POPPRTNO
        CHAR (18),
    AP_POPLINENUM
        INTEGER,
    AP_POPACTNO
        CHAR (24),
    AP_POPCST
        DOUBLE PRECISION,
    AP_POPFCCST
        DOUBLE PRECISION,
    AP_POPAMTPD
        DOUBLE PRECISION,
    AP_POPFCAMTPD
        DOUBLE PRECISION,
    AP_POPCHGTYP
        SMALLINT,
    AP_POPVCHTRDATE
        INTEGER,
    AP_POPREMIT
        CHAR (10),
    AP_POPORDFROM
        CHAR (10),
    AP_POPTRANSNO
        INTEGER,
    AP_POPVDDATE
        INTEGER,
    AP_POPPACT
        CHAR (24),
    AP_POPCSTCAT
        CHAR (6),
    AP_POPPODTYP
        SMALLINT,
    AP_POPVCHTRTYPE
        INTEGER,
    AP_POPUSERDEF1
        INTEGER,
    AP_POHVCHNO
        CHAR (10),
    AP_POHVCHVCHNO
        CHAR (10));
 
create table ED_TPREC (
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
    ED_TPCOD
        CHAR (16),
    ED_TPDESC
        CHAR (30));
 
create table ED_ENTREC (
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
    ED_ENTTPCOD
        CHAR (16),
    ED_ENTITY
        CHAR (20),
    ED_ENTMMTYP
        INTEGER,
    ED_ENTMMCOD
        CHAR (10),
    ED_ENTDESC
        CHAR (30),
    ED_TPCOD
        CHAR (16),
    ED_ENTMMHSHSET
        SMALLINT);
 
create table ED_DOCXRFREC (
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
    ED_DOCXRFTYP
        CHAR (3),
    ED_DOCXRFFLG
        INTEGER,
    ED_DOCXRFTPDOCNO
        CHAR (10),
    ED_DOCXRFTPDOCLN
        DOUBLE PRECISION,
    ED_DOCXRFMMDOCNO
        CHAR (10),
    ED_DOCXRFMMDOCLN
        DOUBLE PRECISION,
    ED_ENTTPCOD
        CHAR (16),
    ED_AUDTPCOD
        CHAR (16));
 
create table ED_PRDXRFREC (
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
    ED_PRDXRFMMPRDNO
        CHAR (18),
    ED_PRDXRFMMDESC
        CHAR (30),
    ED_PRDXRFTPPRTNO
        CHAR (20),
    ED_PRDXRFTPDESC
        CHAR (30),
    ED_ENTTPCOD
        CHAR (16),
    ED_TPCOD
        CHAR (16),
    ED_PRDHSHSET
        SMALLINT);
 
create table ED_AUDREC (
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
    ED_AUDTPCOD
        CHAR (16),
    ED_AUDDOCTYP
        CHAR (3),
    ED_AUDDOCFLG
        INTEGER,
    ED_AUDTPENTITY
        CHAR (20),
    ED_AUDTPMMCOD
        CHAR (10),
    ED_AUDTPMMTYP
        INTEGER,
    ED_AUDDATE
        INTEGER,
    ED_AUDTIME
        INTEGER,
    ED_AUDFILNAM
        CHAR (80),
    ED_AUDFILVER
        INTEGER,
    ED_AUDTOTRECP
        INTEGER,
    ED_AUDTOTRECR
        INTEGER,
    ED_ENTTPCOD
        CHAR (16));
 

 

 

 
create table ACTDFASET (
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
 
create table ACTHSHSET (
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
 
create table ACTLOCSET (
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
 
create table ACTPODSET (
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
 
create table BOMSET (
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
 
create table CCSRTSET (
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
 
create table CLDPOHSET (
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
 
create table CODHSHSET (
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
 
create table COMSET (
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
 
create table CRLABSET (
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
 
create table CRMTRSET (
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
 
create table CRVARSET (
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
 
create table CSTSET (
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
 
create table DELRCTSET (
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
 
create table DFAHSHSET (
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
 
create table DRLABSET (
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
 
create table DRMTRSET (
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
 
create table DRVARSET (
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
 
create table ECCSET (
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
 
create table ECOHSHSET (
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
 
create table ECOSET (
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
 
create table ENGENCSET (
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
 
create table ENGHSHSET (
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
 
create table ENGENDSET (
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
 
create table EMPHSHSET (
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
 
create table EMPLABSET (
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
 
create table FLDSET (
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
 
create table FLGHSHSET (
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
 
create table FSCHSHSET (
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
 
create table FSCSET (
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
 
create table LOCLOTSET (
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
 
create table LOCSET (
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
 
create table MFGSET (
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
 
create table MRHMRQSET (
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
 
create table MRLHSHSET (
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
 
create table MRLMRHSET (
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
 
create table OPCHSHSET (
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
 
create table OPCPRTSET (
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
 
create table OPNPOHSET (
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
 
create table PODDELSET (
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
 
create table PODPONSET (
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
 
create table PODRCTSET (
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
 
create table POHHSHSET (
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
 
create table POHPODSET (
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
 
create table POHPONSET (
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
 
create table POHPRNTSET (
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
 
create table POHRCTSET (
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
 
create table PRTBORSET (
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
 
create table PRTENDSET (
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
 
create table PRTFAMSET (
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
 
create table PRTFORSET (
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
 
create table PRTHSHSET (
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
 
create table PRTMISSET (
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
 
create table PRTMRPSET (
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
 
create table PRTMRHSET (
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
 
create table PRTMTRSET (
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
 
create table PRTPODSET (
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
 
create table PRTPUNSET (
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
 
create table PRTRCTSET (
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
 
create table PRTRQDSET (
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
 
create table PRTRTGSET (
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
 
create table PRTSODSET (
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
 
create table PRTSRTSET (
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
 
create table PRTUSGSET (
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
 
create table PRTVMCSET (
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
 
create table PRTWOHSET (
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
 
create table RCTHSHSET (
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
 
create table REFSET (
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
 
create table RESBORSET (
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
 
create table RESHSHSET (
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
 
create table RQHHSHSET (
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
 
create table RQHRQDSET (
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
 
create table RTDSET (
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
 
create table RTGTRKSET (
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
 
create table RTGTWUSET (
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
 
create table SODFAMSET (
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
 
create table SOHHSHSET (
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
 
create table SOHSODSET (
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
 
create table SPDSET (
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
 
create table SPNHSHSET (
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
 
create table TOOHSHSET (
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
 
create table TOOTWUSET (
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
 
create table TRKTRDSET (
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
 
create table VENHSHSET (
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
 
create table VENRCTSET (
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
 
create table VENVMCSET (
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
 
create table WARHSHSET (
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
 
create table WARLOCSET (
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
 
create table WARSET (
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
 
create table WIPCONSET (
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
 
create table WIPEFFSET (
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
 
create table WIPHSHSET (
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
 
create table WIPJOBSET (
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
 
create table WIPLOTSET (
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
 
create table WIPMATSET (
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
 
create table WIPMETSET (
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
 
create table WIPRATSET (
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
 
create table WIPSET (
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
 
create table WIPWOHSET (
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
 
create table WKCHSHSET (
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
 
create table WKCLABSET (
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
 
create table WKCRTGSET (
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
 
create table WKCTRKSET (
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
 
create table WOHACLSET (
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
 
create table WOHEALSET (
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
 
create table WOHHSHSET (
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
 
create table WOHMISSET (
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
 
create table WOHMOVSET (
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
 
create table WOHMSCSET (
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
 
create table WOHTRKSET (
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
 
create table WOHVARSET (
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
 
create table MA_ACCTHSHSET (
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
 
create table MA_ACCTPOSTSET (
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
 
create table MA_ACCTSRTSET (
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
 
create table MA_ACCTTRASET (
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
 
create table MA_ACCTPPDSET (
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
 
create table MA_ACCTUPPDSET (
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
 
create table MA_ACCTSALESET (
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
 
create table MA_ACCTLINDSET (
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
 
create table MA_ACCTPRTDSET (
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
 
create table MA_ACCTPRVARSET (
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
 
create table MA_ACTCOGSSET (
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
 
create table MA_ACCTCOGSSET (
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
 
create table MA_ACCTRETSET (
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
 
create table MA_ACTSTGSET (
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
 
create table MA_INHAPCPOSTSET (
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
 
create table MA_APCSPISET (
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
 
create table MA_BILCIASET (
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
 
create table MA_BILCMHSET (
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
 
create table MA_BILCTBILSET (
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
 
create table MA_BILCTHSHSET (
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
 
create table MA_BILDMHSET (
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
 
create table MA_BILHSHSET (
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
 
create table MA_BILINHSET (
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
 
create table MA_BILPOSTSET (
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
 
create table MA_BILPRTABSET (
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
 
create table MA_BILBILSSET (
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
 
create table MA_BILSHPSET (
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
 
create table MA_BILSODSET (
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
 
create table MA_CHGDCOMCLSET (
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
 
create table MA_CHGDCOMOCLSET (
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
 
create table MA_CHGHHSHSET (
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
 
create table MA_CHGHCHGDSET (
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
 
create table MA_CIAAPCSET (
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
 
create table MA_CIAPOSTSET (
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
 
create table MA_CMDCOMOSET (
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
 
create table MA_CMDMSPISET (
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
 
create table MA_CMDMSPNLSET (
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
 
create table MA_CMDSPISET (
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
 
create table MA_CMDSPNLSET (
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
 
create table MA_CMHCMDSET (
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
 
create table MA_CMHCMDMSET (
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
 
create table MA_CMHHSHSET (
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
 
create table MA_CMHSPISET (
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
 
create table MA_CMHSPNLSET (
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
 
create table MA_CMHPOSTSET (
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
 
create table MA_CMHPRTSET (
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
 
create table MA_CMHVDPOSTSET (
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
 
create table MA_COMCCOMCLSET (
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
 
create table MA_COMOCOMOCLSET (
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
 
create table MA_CPOHSHSET (
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
 
create table MA_CPOINHSET (
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
 
create table MA_CPOSOHSET (
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
 
create table MA_CTERHSHSET (
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
 
create table MA_CTERSHPSET (
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
 
create table MA_DMHCMHSET (
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
 
create table MA_DMHHSHSET (
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
 
create table MA_DMHSPISET (
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
 
create table MA_DMHSPNLSET (
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
 
create table MA_FRTHSHSET (
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
 
create table MA_FRTTHSHSET (
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
 
create table MA_GLCTBILSET (
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
 
create table MA_GLCTHSHSET (
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
 
create table MA_GLPTHSHSET (
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
 
create table MA_GLPTPRODSET (
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
 
create table MA_GLCTTABSET (
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
 
create table MA_GLTABHSHSET (
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
 
create table MA_GLPTTABSET (
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
 
create table MA_HLDHSHSET (
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
 
create table MA_INDCMDSET (
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
 
create table MA_INDCOMOSET (
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
 
create table MA_INDMCMDMSET (
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
 
create table MA_INDMSPISET (
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
 
create table MA_INDMSPNLSET (
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
 
create table MA_INDSPISET (
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
 
create table MA_INDSPNLSET (
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
 
create table MA_INHAPCSET (
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
 
create table MA_INHCMHSET (
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
 
create table MA_INHCOMCSET (
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
 
create table MA_INHCRPOSTSET (
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
 
create table MA_INHDMHSET (
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
 
create table MA_INHHSHSET (
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
 
create table MA_INHINDMSET (
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
 
create table MA_INHINDSET (
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
 
create table MA_INHPOSTSET (
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
 
create table MA_INHPRTSET (
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
 
create table MA_INHSHHSET (
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
 
create table MA_INHSPISET (
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
 
create table MA_INHSPNLSET (
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
 
create table MA_INHUPDSET (
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
 
create table MA_INHVDPOSTSET (
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
 
create table MA_INHWOPOSTSET (
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
 
create table MA_INTHSHSET (
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
 
create table MA_INTINHSET (
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
 
create table MA_PAYTHSHSET (
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
 
create table MA_PAYTPAYTDSET (
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
 
create table MA_PFAMHSHSET (
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
 
create table MA_PFAMPLINSET (
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
 
create table MA_PLINHSHSET (
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
 
create table MA_PLINPRODSET (
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
 
create table MA_POSTHSHSET (
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
 
create table MA_POSTSPISET (
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
 
create table MA_PRCTBILSET (
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
 
create table MA_PRCTHSHSET (
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
 
create table MA_PRODCHGDSET (
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
 
create table MA_PRODCMDSET (
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
 
create table MA_PRODCOMOSET (
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
 
create table MA_PRODHSHSET (
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
 
create table MA_PRODGLTABSET (
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
 
create table MA_PRODPRTABSET (
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
 
create table MA_PRODPRODSSET (
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
 
create table MA_PRODSODSET (
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
 
create table MA_PRODTOPSET (
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
 
create table MA_PROJHSHSET (
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
 
create table MA_PROJPOSTSET (
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
 
create table MA_PRPTHSHSET (
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
 
create table MA_PRPTPRODSET (
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
 
create table MA_PRCTPRTABSET (
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
 
create table MA_PRTABHSHSET (
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
 
create table MA_PRPTPRTABSET (
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
 
create table MA_PRTSTGPSET (
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
 
create table MA_PRTTOPSET (
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
 
create table MA_RSNCHGHSET (
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
 
create table MA_RSNCMHSET (
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
 
create table MA_RSNHSHSET (
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
 
create table MA_SAMCOMCSET (
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
 
create table MA_SAMCOMOSET (
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
 
create table MA_SAMHSHSET (
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
 
create table MA_SAMSAMSSET (
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
 
create table MA_SHDSHDPSET (
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
 
create table MA_SHDSPISET (
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
 
create table MA_SHDSPNLSET (
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
 
create table MA_SHHHSHSET (
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
 
create table MA_SHHPRTSET (
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
 
create table MA_SHHSHDSET (
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
 
create table MA_PAKPRTSET (
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
 
create table MA_SHHSODSET (
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
 
create table MA_SHHSPISET (
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
 
create table MA_SHHSPNLSET (
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
 
create table MA_SHPCOMOSET (
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
 
create table MA_SHPCOMCSET (
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
 
create table MA_SHPHSHSET (
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
 
create table MA_SHPSHPSSET (
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
 
create table MA_SHPSOHSET (
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
 
create table MA_SOCATHSHSET (
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
 
create table MA_SODSTGPSET (
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
 
create table MA_SODCOMOSET (
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
 
create table MA_SODINDSET (
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
 
create table MA_SODSHDSET (
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
 
create table MA_SODCHGDSET (
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
 
create table MA_SODSPISET (
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
 
create table MA_SODSPNLSET (
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
 
create table MA_SOHCOMCSET (
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
 
create table MA_SOHHSHSET (
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
 
create table MA_SOHINHSET (
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
 
create table MA_SOHPRTSET (
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
 
create table MA_SOHSHHSET (
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
 
create table MA_SOHSODSET (
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
 
create table MA_SOHSPISET (
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
 
create table MA_SOHSPNLSET (
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
 
create table MA_SOHUPDSET (
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
 
create table MA_SPFHSHSET (
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
 
create table MA_SPNHSHSET (
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
 
create table MA_SPNSPNDSET (
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
 
create table MA_SPNSPNLSET (
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
 
create table MA_STERHSHSET (
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
 
create table MA_STERSAMSET (
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
 
create table MA_STGHSHSET (
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
 
create table MA_STGSTGPSET (
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
 
create table MA_STATEHSHSET (
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
 
create table MA_STATETXSET (
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
 
create table MA_TXHSHSET (
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
 
create table MA_TXCMHSET (
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
 
create table MA_TXINHSET (
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
 
create table MA_TXSOHSET (
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
 
create table MA_TXTXLSET (
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
 
create table MA_TXRTHSHSET (
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
 
create table MA_TXRTTXLSET (
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
 
create table MA_TXTHSHSET (
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
 
create table MA_TXTTXRTSET (
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
 
create table MA_WARSTGSET (
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
 
create table GL_ACCTHSHSET (
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
 
create table GL_ISBSHSHSET (
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
 
create table GL_LINKHSHSET (
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
 
create table GL_JVHSHSET (
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
 
create table GL_TRHSHSET (
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
 
create table GL_PROJHSHSET (
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
 
create table GL_ARPTHSHSET (
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
 
create table GL_PRPTHSHSET (
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
 
create table GL_FISCHSHSET (
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
 
create table GL_CLEARSET (
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
 
create table GL_ACCTMASET (
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
 
create table GL_ACCTAPSET (
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
 
create table GL_ACCTFASET (
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
 
create table GL_ACCTPOSTSET (
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
 
create table GL_ACCTRPTSET (
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
 
create table GL_ACCTAMTSET (
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
 
create table GL_ACCTBUDSET (
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
 
create table GL_ACCTDESCSET (
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
 
create table GL_MCLINKSET (
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
 
create table GL_MOLINKSET (
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
 
create table GL_DLLINKSET (
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
 
create table GL_FOLINKSET (
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
 
create table GL_VOLINKSET (
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
 
create table GL_OPLINKSET (
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
 
create table GL_OOLINKSET (
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
 
create table GL_LINKMFGSET (
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
 
create table GL_LINKDESCSET (
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
 
create table GL_ARPTSET (
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
 
create table GL_ARPTDESCSET (
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
 
create table GL_PRPTSET (
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
 
create table GL_PRPTDESCSET (
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
 
create table GL_PROJMASET (
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
 
create table GL_PROJAPSET (
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
 
create table GL_PROJFASET (
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
 
create table GL_PROJPOSTSET (
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
 
create table GL_PROJAMTSET (
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
 
create table GL_PROJBUDSET (
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
 
create table GL_PROJDESCSET (
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
 
create table GL_PROJRPTSET (
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
 
create table GL_JVTRSET (
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
 
create table GL_JVDESCSET (
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
 
create table GL_TRPOSTSET (
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
 
create table GL_TRDESCSET (
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
 
create table GL_FISCTRSET (
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
 
create table GL_ISBSACCTSET (
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
 
create table AP_ACCTSET (
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
 
create table AP_CASHBNKSET (
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
 
create table AP_DISCBNKSET (
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
 
create table AP_APVNDSET (
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
 
create table AP_ACCTTYPESET (
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
 
create table AP_PPVNDSET (
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
 
create table AP_BNKCHKSET (
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
 
create table AP_BNKVCHSET (
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
 
create table AP_BNKOPENSET (
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
 
create table AP_BNKVNDSET (
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
 
create table AP_BCHVCHSET (
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
 
create table AP_BCHHOLDSET (
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
 
create table AP_CHKNOTSET (
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
 
create table AP_PDCHKSET (
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
 
create table AP_CHKPOSTSET (
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
 
create table AP_INVVCHSET (
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
 
create table AP_POHPOHSET (
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
 
create table AP_POHVCHSET (
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
 
create table AP_INVRCTSET (
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
 
create table AP_PROJPOSTSET (
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
 
create table AP_RCTINRCSET (
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
 
create table AP_VCHPOSTSET (
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
 
create table AP_APPOSTSET (
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
 
create table AP_DMVCHSET (
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
 
create table AP_VCHDMSET (
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
 
create table AP_VCHPOHSET (
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
 
create table AP_VCHNOTSET (
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
 
create table AP_VCHCHKSET (
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
 
create table AP_VENVCHSET (
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
 
create table AP_VENHOLDSET (
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
 
create table AP_VNDCHKSET (
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
 
create table AP_VNDINVSET (
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
 
create table AP_VNDHOLDSET (
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
 
create table AP_VNDVCHSET (
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
 
create table AP_VNDVENSET (
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
 
create table AP_ACCTHSHSET (
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
 
create table AP_POHHSHSET (
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
 
create table AP_BATCHHSHSET (
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
 
create table AP_BNKHSHSET (
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
 
create table AP_CHKHSHSET (
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
 
create table AP_INVHSHSET (
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
 
create table AP_PROJHSHSET (
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
 
create table AP_VCHHSHSET (
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
 
create table AP_VNDHSHSET (
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
 
create table FA_ACCTHSHSET (
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
 
create table FA_PROJHSHSET (
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
 
create table PRTMATSET (
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
 
create table AP_DEFACCTSET (
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
 
create table MISMISREFSET (
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
 
create table PRTQOHSET (
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
 
create table WARQOHSET (
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
 
create table AP_RCTSET (
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
 
create table AP_RCTHSHSET (
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
 
create table GL_BATCHSET (
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
 
create table GL_BATCHSHSET (
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
 
create table GL_REHSHSET (
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
 
create table GL_FPHSHSET (
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
 
create table GL_VPHSHSET (
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
 
create table GL_ABUDHSHSET (
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
 
create table GL_ABUDSET (
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
 
create table GL_FPOFFACCTSET (
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
 
create table GL_REACCTSET (
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
 
create table GL_FPFRACCTSET (
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
 
create table GL_FPTOACCTSET (
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
 
create table GL_VPDENSET (
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
 
create table GL_VPTOACCTSET (
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
 
create table GL_VPNUMACCTSET (
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
 
create table GL_VPFRACCTSET (
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
 
create table GL_VPOFFACCTSET (
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
 
create table GL_VPOFFPROJSET (
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
 
create table GL_VPTOPROJSET (
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
 
create table GL_FPTOPROJSET (
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
 
create table GL_FPOFFPROJSET (
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
 
create table GL_REPROJSET (
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
 
create table GL_REBATSET (
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
 
create table GL_FPBATSET (
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
 
create table GL_VPBATSET (
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
 
create table GL_REDESCSET (
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
 
create table GL_REAMTSET (
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
 
create table GL_FPFRSET (
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
 
create table GL_FPDESCSET (
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
 
create table GL_FPTOPCTSET (
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
 
create table GL_VPFRSET (
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
 
create table GL_VPDESCSET (
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
 
create table GL_VPDENACCTSET (
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
 
create table GL_VPTOSET (
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
 
create table GL_VPNUMSET (
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
 
create table GL_ABUDNUMSET (
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
 
create table MA_INHSVINHSET (
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
 
create table MA_SVINDSPISET (
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
 
create table MA_SVINDSPNLSET (
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
 
create table MA_SVINHSVINDSET (
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
 
create table MA_SERHSHSET (
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
 
create table MA_SHDPSERSET (
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
 
create table MA_SHDSERSET (
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
 
create table VENSHPSET (
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
 
create table VENBILSET (
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
 
create table INVHSHSET (
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
 
create table INVLOCSET (
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
 
create table MA_REMHSHSET (
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
 
create table AP_VCHVTPSTSET (
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
 
create table ACTMCSET (
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
 
create table ACTMOSET (
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
 
create table ACTDLSET (
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
 
create table ACTFOSET (
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
 
create table ACTVOSET (
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
 
create table ACTOPSET (
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
 
create table ACTOOSET (
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
 
create table ACTPCSET (
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
 
create table ACTPOSET (
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
 
create table AP_VATHSHSET (
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
 
create table AP_VATVTPSTSET (
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
 
create table LOTACSTSET (
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
 
create table MA_QUODSPISET (
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
 
create table MA_QUODSPNLSET (
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
 
create table MA_QUODHSHSET (
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
 
create table MA_QUOHHSHSET (
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
 
create table MA_QUOHPRTSET (
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
 
create table MA_QUOHQUODSET (
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
 
create table MA_QUOHSPISET (
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
 
create table MA_QUOHSPNLSET (
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
 
create table MA_QUOHUPDSET (
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
 
create table MA_SHPQUOHSET (
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
 
create table MA_SODQUODSET (
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
 
create table MA_SOHQUOHSET (
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
 
create table VMCHSHSET (
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
 
create table LOTHSHSET (
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
 
create table MA_PRODOPTSET (
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
 
create table MA_QUODOPTSET (
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
 
create table MA_SODOPTSET (
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
 
create table MA_QUOHCOMOSET (
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
 
create table MA_INHINHLSET (
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
 
create table MA_CMHINHLSET (
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
 
create table MA_DMHDMHLSET (
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
 
create table MA_CMHDMHLSET (
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
 
create table AP_HDRSET (
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
 
create table AP_HDRVNDSET (
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
 
create table PRHHSHSET (
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
 
create table PRHPRDSET (
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
 
create table POHPRHSET (
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
 
create table PODPRDSET (
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
 
create table PRTPRDSET (
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
 
create table PRHPONSET (
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
 
create table PRDPONSET (
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
 
create table VENPRHSET (
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
 
create table AUTHSHSET (
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
 
create table AUTAPPSET (
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
 
create table PRHAPPSET (
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
 
create table IDPRHSET (
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
 
create table IDHSHSET (
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
 
create table PRTPFAMSET (
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
 
create table AP_SEARCHHSHSET (
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
 
create table AP_SEARCHVNDSET (
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
 
create table PRTDESSET (
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
 
create table AP_SEARCHSRTSET (
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
 
create table AP_RECPAYHSHSET (
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
 
create table AP_RECPAYVCHSET (
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
 
create table AP_RECPAYPOSTSET (
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
 
create table AP_RECPAYNOTESET (
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
 
create table FSCCALHSHSET (
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
 
create table FSCCALSET (
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
 
create table CURHSHSET (
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
 
create table CURCUREXSET (
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
 
create table MA_BILFCPRTABSET (
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
 
create table MA_PRODFCPRTABSET (
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
 
create table MA_PRCTFCPRTABSET (
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
 
create table MA_PRPTFCPRTABSET (
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
 
create table MA_FCPRTABHSHSET (
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
 
create table AP_VATPOSTSET (
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
 
create table MA_PARTTOPSET (
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
 
create table MA_PARTHSHSET (
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
 
create table MA_STGPHSHSET (
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
 
create table MA_SOHPBSET (
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
 
create table RCTNOHSHSET (
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
 
create table WIPYLDSET (
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
 
create table PRTYLDSET (
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
 
create table INDFHSHSET (
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
 
create table INTSET (
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
 
create table SODINTSET (
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
 
create table PRTINTSET (
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
 
create table PRTIRCTSET (
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
 
create table IRCTSET (
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
 
create table PODIRCTSET (
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
 
create table VENIRCTSET (
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
 
create table INVLOC2SET (
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
 
create table SOHHSH2SET (
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
 
create table PFAMHSHSET (
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
 
create table WARINTSET (
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
 
create table AP_VATPOST2SET (
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
 
create table AP_VND1099SET (
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
 
create table AP_BEFTHSHSET (
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
 
create table AP_PMTNOTTRANSSET (
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
 
create table AP_PMTHSHSET (
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
 
create table AP_BEFTPMTSET (
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
 
create table AP_RECPAYCHNSET (
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
 
create table PAYHSHSET (
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
 
create table PAYSET (
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
 
create table EMPSET (
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
 
create table EMPLABPYSET (
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
 
create table AP_PAYOR1099HSHSET (
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
 
create table AUTPRHSET (
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
 
create table AP_PNOTHSHSET (
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
 
create table AP_VCHPNOTVCHSET (
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
 
create table AP_PNOTPNOTVCHSET (
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
 
create table MA_PNOTHSHSET (
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
 
create table MA_INHPNOTINVSET (
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
 
create table MA_PNOTPNOTINVSET (
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
 
create table WIPBYPSET (
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
 
create table WIPMIXSET (
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
 
create table WIPMBOSET (
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
 
create table POHCPRSET (
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
 
create table PRHCPRSET (
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
 
create table MA_PARTOPTSET (
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
 
create table AP_PAYPLTSET (
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
 
create table AP_VNDPLTSET (
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
 
create table CDACDPSET (
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
 
create table CDLCDASET (
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
 
create table CDLCONSET (
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
 
create table CDLCOPSET (
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
 
create table COHCDLSET (
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
 
create table COHCONSET (
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
 
create table COHHSHSET (
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
 
create table POCOHSRTSET (
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
 
create table PRTCDLSET (
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
 
create table VENCOHSET (
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
 
create table GENHSHSET (
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
 
create table GENPRTSET (
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
 
create table BYDHSHSET (
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
 
create table PODPOPSET (
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
 
create table PODPOMSET (
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
 
create table RCTRCTMSET (
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
 
create table AP_INVRCTRCTMSET (
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
 
create table POHBOLLSET (
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
 
create table BOLBOLLSET (
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
 
create table BOLRCTSET (
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
 
create table BOLHSHSET (
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
 
create table FRTHSHSET (
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
 
create table FRTBOLSET (
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
 
create table BOLOPENSET (
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
 
create table CDPCDPLSET (
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
 
create table AP_VCHBOLLSET (
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
 
create table AP_BOLBOLLSET (
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
 
create table AP_BOLHSHSET (
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
 
create table AP_VNDBOLSET (
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
 
create table MA_USRHSHSET (
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
 
create table MA_USRFLDSET (
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
 
create table POHPOPSET (
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
 
create table AP_POPSET (
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
 
create table ED_TPHSHSET (
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
 
create table ED_TPENTSET (
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
 
create table ED_ENTHSHSET (
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
 
create table ED_ENTAUDSET (
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
 
create table ED_ENTPRDXRFSET (
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
 
create table ED_AUDHSHSET (
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
 
create table ED_ENTDOCSET (
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
 
create table ED_AUDDOCSET (
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
 
create table ED_ENTMMHSHSET (
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
 
create table ED_TPPRDXRFSET (
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
 
create table ED_PRDHSHSET (
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
 

-- RMU/EXTRACT for Oracle Rdb V7.2-200                   11-OCT-2018 10:44:00.15
--
--                              Index Definitions
--
--------------------------------------------------------------------------------
-- no indices defined

-- RMU/EXTRACT for Oracle Rdb V7.2-200                   11-OCT-2018 10:44:00.15
--
--                           Storage Map Definitions
--
--------------------------------------------------------------------------------
-- no storage maps defined

-- RMU/EXTRACT for Oracle Rdb V7.2-200                   11-OCT-2018 10:44:00.15
--
--                               View Definitions
--
--------------------------------------------------------------------------------
-- no views defined

-- RMU/EXTRACT for Oracle Rdb V7.2-200                   11-OCT-2018 10:44:00.15
--
--                             Trigger Definitions
--
--------------------------------------------------------------------------------
-- no triggers defined

-- RMU/EXTRACT for Oracle Rdb V7.2-200                   11-OCT-2018 10:44:00.15
--
--                              Module Definitions
--
--------------------------------------------------------------------------------
-- no modules defined

-- RMU/EXTRACT for Oracle Rdb V7.2-200                   11-OCT-2018 10:44:00.15
--
--                          Query Outline Definitions
--
--------------------------------------------------------------------------------
-- no outlines defined
