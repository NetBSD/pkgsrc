$NetBSD: patch-src_3rdparty_chromium_tools_grit_grit_util.py,v 1.1 2023/06/08 20:38:06 markd Exp $

build with python3

--- src/3rdparty/chromium/tools/grit/grit/util.py.orig	2022-03-30 09:48:18.000000000 +0000
+++ src/3rdparty/chromium/tools/grit/grit/util.py
@@ -211,7 +211,7 @@ def ReadFile(filename, encoding):
     mode = 'rb'
     encoding = None
   else:
-    mode = 'rU'
+    mode = 'r'
 
   with io.open(abs(filename), mode, encoding=encoding) as f:
     return f.read()
