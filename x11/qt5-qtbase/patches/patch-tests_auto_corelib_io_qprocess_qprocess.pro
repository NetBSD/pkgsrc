$NetBSD: patch-tests_auto_corelib_io_qprocess_qprocess.pro,v 1.2 2018/01/17 19:30:47 markd Exp $

* Pass whitespace(s) in filename test cases.

--- tests/auto/corelib/io/qprocess/qprocess.pro.orig	2017-01-18 14:20:58.000000000 +0000
+++ tests/auto/corelib/io/qprocess/qprocess.pro
@@ -3,10 +3,7 @@ TEMPLATE = subdirs
 include(qprocess.pri)
 SUBDIRS  = $$SUBPROGRAMS
 # Add special cases
-SUBDIRS += testProcessSpacesArgs/nospace.pro \
-           testProcessSpacesArgs/onespace.pro \
-           testProcessSpacesArgs/twospaces.pro \
-           testSpaceInName
+SUBDIRS += testProcessSpacesArgs/nospace.pro
 
 win32 {
     SUBDIRS += \
