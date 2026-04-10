$NetBSD: patch-tools_grit_grit_node_base.py,v 1.17 2026/04/10 17:32:01 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- tools/grit/grit/node/base.py.orig	2026-04-06 16:25:54.000000000 +0000
+++ tools/grit/grit/node/base.py
@@ -491,7 +491,8 @@ class Node:
         value = defs
 
       elif name == 'is_linux':
-        value = target_platform == 'linux'
+        value = (target_platform == 'linux'
+                 or 'bsd' in target_platform)
       elif name == 'is_chromeos':
         value = target_platform == 'chromeos'
       elif name == 'is_macosx':
