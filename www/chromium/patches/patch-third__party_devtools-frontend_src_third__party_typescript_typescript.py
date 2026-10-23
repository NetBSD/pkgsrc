$NetBSD: patch-third__party_devtools-frontend_src_third__party_typescript_typescript.py,v 1.7 2026/10/23 15:05:34 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- third_party/devtools-frontend/src/third_party/typescript/typescript.py.orig	2026-10-19 20:07:21.000000000 +0000
+++ third_party/devtools-frontend/src/third_party/typescript/typescript.py
@@ -18,6 +18,9 @@ def GetBinaryPath():
     relative = {
         'Darwin': (darwin_path, 'src', 'lib', 'tsc'),
         'Linux': ('linux-amd64', 'src', 'lib', 'tsc'),
+        'OpenBSD': ('linux-amd64', 'src', 'lib', 'tsc'),
+        'FreeBSD': ('linux-amd64', 'src', 'lib', 'tsc'),
+        'NetBSD': ('linux-amd64', 'src', 'lib', 'tsc'),
         'Windows': ('windows-amd64', 'src', 'lib', 'tsc.exe'),
     }[platform.system()]
 
