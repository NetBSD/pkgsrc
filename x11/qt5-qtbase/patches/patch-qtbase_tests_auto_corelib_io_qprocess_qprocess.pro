$NetBSD: patch-qtbase_tests_auto_corelib_io_qprocess_qprocess.pro,v 1.1 2013/12/13 14:38:35 ryoon Exp $

* Pass whitespace(s) in filename test cases.

--- qtbase/tests/auto/corelib/io/qprocess/qprocess.pro.orig	2013-11-27 01:01:09.000000000 +0000
+++ qtbase/tests/auto/corelib/io/qprocess/qprocess.pro
@@ -3,10 +3,7 @@ TEMPLATE = subdirs
 include(qprocess.pri)
 SUBDIRS  = $$SUBPROGRAMS
 # Add special cases
-SUBDIRS += testProcessSpacesArgs/nospace.pro \
-           testProcessSpacesArgs/onespace.pro \
-           testProcessSpacesArgs/twospaces.pro \
-           testSpaceInName
+SUBDIRS += testProcessSpacesArgs/nospace.pro
 
 win32:!wince*:SUBDIRS+=testProcessEchoGui
 
