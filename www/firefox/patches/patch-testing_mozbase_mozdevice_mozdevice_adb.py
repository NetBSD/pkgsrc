$NetBSD: patch-testing_mozbase_mozdevice_mozdevice_adb.py,v 1.1 2024/10/11 13:55:47 wiz Exp $

Fix build with Python 3.13.

--- testing/mozbase/mozdevice/mozdevice/adb.py.orig	2024-10-11 13:42:22.039323223 +0000
+++ testing/mozbase/mozdevice/mozdevice/adb.py
@@ -4,7 +4,6 @@
 
 import io
 import os
-import pipes
 import posixpath
 import re
 import shlex
@@ -1286,8 +1285,6 @@ class ADBDevice(ADBCommand):
         """Utility function to return quoted version of command argument."""
         if hasattr(shlex, "quote"):
             quote = shlex.quote
-        elif hasattr(pipes, "quote"):
-            quote = pipes.quote
         else:
 
             def quote(arg):
