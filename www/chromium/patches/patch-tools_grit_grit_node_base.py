$NetBSD: patch-tools_grit_grit_node_base.py,v 1.28 2026/10/02 11:43:39 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- tools/grit/grit/node/base.py.orig	2026-09-22 00:09:16.000000000 +0000
+++ tools/grit/grit/node/base.py
@@ -511,7 +511,8 @@ class Node:
         value = defs
 
       elif name == 'is_linux':
-        value = target_platform == 'linux'
+        value = (target_platform == 'linux'
+                 or 'bsd' in target_platform)
       elif name == 'is_chromeos':
         value = target_platform == 'chromeos'
       elif name == 'is_macosx':
