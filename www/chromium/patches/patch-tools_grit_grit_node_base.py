$NetBSD: patch-tools_grit_grit_node_base.py,v 1.9 2025/11/04 14:55:49 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- tools/grit/grit/node/base.py.orig	2025-10-24 16:42:30.000000000 +0000
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
