$NetBSD: patch-js_src_tests_lib_results.py,v 1.1 2024/10/11 13:55:47 wiz Exp $

Fix build with Python 3.13.

--- js/src/tests/lib/results.py.orig	2024-10-11 13:42:54.292672525 +0000
+++ js/src/tests/lib/results.py
@@ -1,5 +1,5 @@
 import json
-import pipes
+import shlex
 import re
 
 from .progressbar import NullProgressBar, ProgressBar
@@ -9,7 +9,7 @@ from .structuredlog import TestLogger
 
 
 def escape_cmdline(args):
-    return " ".join([pipes.quote(a) for a in args])
+    return " ".join([shlex.quote(a) for a in args])
 
 
 class TestOutput:
