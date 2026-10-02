$NetBSD: patch-third__party_typescript_typescript.py,v 1.4 2026/10/02 11:43:38 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- third_party/typescript/typescript.py.orig	2026-09-22 00:09:16.000000000 +0000
+++ third_party/typescript/typescript.py
@@ -19,6 +19,9 @@ def GetBinaryPath():
   return os_path.normpath(os_path.join(os_path.dirname(__file__), *{
     'Darwin': (darwin_path, 'src', 'lib', 'tsc'),
     'Linux': ('linux-amd64', 'src', 'lib', 'tsc'),
+    'OpenBSD': ('linux-amd64', 'src', 'lib', 'tsc'),
+    'FreeBSD': ('linux-amd64', 'src', 'lib', 'tsc'),
+    'NetBSD': ('linux-amd64', 'src', 'lib', 'tsc'),
     'Windows': ('windows-amd64', 'src', 'lib', 'tsc.exe'),
   }[platform.system()]))
 
