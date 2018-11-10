# RcProfileHelperGui

Summary		: Replicator Console Profile Helper Application.
Author		: Timothy Peer, eNVy Systems, Inc.
Create Date : Jan 2015
Git Uploaded: Nov 11, 2018

===================================

The repository contains software and example files that can be processed to generate C++ source code. Source code 
is written to perform data replications from source database to target database using the Microsoft ODBC
as the primary transport.  The replication is performed in such a manner to permit full table - "bulk copy" 
data transfers from a single source to a single target.  The source code and implementation methodology can
be modified to easily replicate a single source database to many target databases using ODBC.

DOCUMENTATION:

You may wish to refer to the Git documentation (to do) to obtain clarification on details of the tool.  The 
example Oracle Rdb Extract ASCII text files were extracted from eNVy SQL databases generated using 
eNVy Warehouse Suite for Oracle Codasyl DBMS.  The SQL Database is an auto-generated SQL data model derived 
from an OpenVMS Oracle Codasyl DBMS schema (dbo/dump/schema/option=debug). 

Though the application was developed for eNVy OpenVMS clients, the tool would seem a good fit to perform ODBC-
ODBC replication to/from for most ODBC v3 compliant databases. 

DEPENDENCIES: 

This project is dependent on the following projects: 

 -- Qt Framework V5.n (the application was compiled on 5.11).
 -- NvLibQ - a Qt base class library which contains helper classes used by RcProfileHelperGui and other replication projects. 

CHANGELOG:
 
 
