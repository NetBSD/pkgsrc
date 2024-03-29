$NetBSD: patch-src_3rdparty_chromium_ui_ozone_generate__constructor__list.py,v 1.1 2023/06/08 20:38:06 markd Exp $

build with python3

--- src/3rdparty/chromium/ui/ozone/generate_constructor_list.py.orig	2022-03-30 09:48:18.000000000 +0000
+++ src/3rdparty/chromium/ui/ozone/generate_constructor_list.py
@@ -45,12 +45,15 @@ Example Output: ./ui/ozone/generate_cons
   }  // namespace ui
 """
 
+try:
+    from StringIO import StringIO  # for Python 2
+except ImportError:
+    from io import StringIO  # for Python 3
 import optparse
 import os
 import collections
 import re
 import sys
-import string
 
 
 def GetTypedefName(typename):
@@ -68,7 +71,7 @@ def GetConstructorName(typename, platfor
   This is just "Create" + typename + platform.
   """
 
-  return 'Create' + typename + string.capitalize(platform)
+  return 'Create' + typename + platform.capitalize()
 
 
 def GenerateConstructorList(out, namespace, export, typenames, platforms,
@@ -163,12 +166,14 @@ def main(argv):
     sys.exit(1)
 
   # Write to standard output or file specified by --output_cc.
-  out_cc = sys.stdout
+  out_cc = getattr(sys.stdout, 'buffer', sys.stdout)
   if options.output_cc:
     out_cc = open(options.output_cc, 'wb')
 
-  GenerateConstructorList(out_cc, options.namespace, options.export,
+  out_cc_str = StringIO()
+  GenerateConstructorList(out_cc_str, options.namespace, options.export,
                           typenames, platforms, includes, usings)
+  out_cc.write(out_cc_str.getvalue().encode('utf-8'))
 
   if options.output_cc:
     out_cc.close()
