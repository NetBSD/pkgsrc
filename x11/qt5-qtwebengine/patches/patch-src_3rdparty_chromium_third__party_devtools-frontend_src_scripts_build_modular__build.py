$NetBSD: patch-src_3rdparty_chromium_third__party_devtools-frontend_src_scripts_build_modular__build.py,v 1.1 2023/06/08 20:38:06 markd Exp $

build with python3

--- src/3rdparty/chromium/third_party/devtools-frontend/src/scripts/build/modular_build.py.orig	2022-03-30 09:48:18.000000000 +0000
+++ src/3rdparty/chromium/third_party/devtools-frontend/src/scripts/build/modular_build.py
@@ -7,6 +7,8 @@
 Utilities for the modular DevTools build.
 """
 
+from __future__ import print_function
+
 import collections
 from os import path
 import os
@@ -40,7 +42,7 @@ def load_and_parse_json(filename):
     try:
         return json.loads(read_file(filename))
     except:
-        print 'ERROR: Failed to parse %s' % filename
+        print('ERROR: Failed to parse %s' % filename)
         raise
 
 class Descriptors:
@@ -57,7 +59,7 @@ class Descriptors:
 
     def application_json(self):
         result = dict()
-        result['modules'] = self.application.values()
+        result['modules'] = list(self.application.values())
         return json.dumps(result)
 
     def all_compiled_files(self):
