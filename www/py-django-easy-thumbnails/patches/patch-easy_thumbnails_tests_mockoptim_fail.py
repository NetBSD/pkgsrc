$NetBSD: patch-easy_thumbnails_tests_mockoptim_fail.py,v 1.1 2014/04/12 10:10:28 adam Exp $

Python 3.x compatibility.

--- easy_thumbnails/tests/mockoptim_fail.py.orig	2014-04-12 09:51:02.000000000 +0000
+++ easy_thumbnails/tests/mockoptim_fail.py
@@ -2,5 +2,5 @@
 import sys
 # This file does nothing except to mock a optimizer which does not work
 
-print 'Bad JPEG file'
+print('Bad JPEG file')
 sys.exit(1)
