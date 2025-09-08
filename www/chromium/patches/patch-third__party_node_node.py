$NetBSD: patch-third__party_node_node.py,v 1.6 2025/09/08 13:24:32 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- third_party/node/node.py.orig	2025-08-29 18:50:09.000000000 +0000
+++ third_party/node/node.py
@@ -20,6 +20,9 @@ def GetBinaryPath():
   return os_path.join(os_path.dirname(__file__), *{
     'Darwin': (darwin_path, darwin_name, 'bin', 'node'),
     'Linux': ('linux', 'node-linux-x64', 'bin', 'node'),
+    'OpenBSD': ('openbsd', 'node-openbsd', 'bin', 'node'),
+    'FreeBSD': ('freebsd', 'node-freebsd', 'bin', 'node'),
+    'NetBSD': ('netbsd', 'node-netbsd', 'bin', 'node'),
     'Windows': ('win', 'node.exe'),
   }[platform.system()])
 
