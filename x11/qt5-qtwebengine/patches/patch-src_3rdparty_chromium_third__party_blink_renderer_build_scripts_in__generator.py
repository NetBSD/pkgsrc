$NetBSD: patch-src_3rdparty_chromium_third__party_blink_renderer_build_scripts_in__generator.py,v 1.1 2023/06/08 20:38:06 markd Exp $

build with python3

--- src/3rdparty/chromium/third_party/blink/renderer/build/scripts/in_generator.py.orig	2022-03-30 09:48:18.000000000 +0000
+++ src/3rdparty/chromium/third_party/blink/renderer/build/scripts/in_generator.py
@@ -32,10 +32,15 @@ import os
 import os.path
 import shlex
 import shutil
+import sys
 import optparse
 
 from in_file import InFile
 
+# TODO: Remove this once Python2 is obsoleted.
+if sys.version_info.major != 2:
+    basestring = str
+
 
 #########################################################
 # This is now deprecated - use json5_generator.py instead
