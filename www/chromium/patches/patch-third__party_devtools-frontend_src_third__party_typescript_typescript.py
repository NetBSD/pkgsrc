$NetBSD: patch-third__party_devtools-frontend_src_third__party_typescript_typescript.py,v 1.1 2026/09/22 13:41:31 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- third_party/devtools-frontend/src/third_party/typescript/typescript.py.orig	2026-09-14 22:17:16.000000000 +0000
+++ third_party/devtools-frontend/src/third_party/typescript/typescript.py
@@ -10,6 +10,9 @@ import os
 
 
 def GetBinaryPath():
+    if platform.system() in ['OpenBSD', 'FreeBSD', 'NetBSD']:
+        return "tsc"
+
     if platform.machine() == 'arm64':
         darwin_path = 'mac-arm64'
     else:
