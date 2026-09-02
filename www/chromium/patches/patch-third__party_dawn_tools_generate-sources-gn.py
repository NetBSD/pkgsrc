$NetBSD: patch-third__party_dawn_tools_generate-sources-gn.py,v 1.2 2026/09/02 13:13:36 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- third_party/dawn/tools/generate-sources-gn.py.orig	2026-08-31 22:47:51.000000000 +0000
+++ third_party/dawn/tools/generate-sources-gn.py
@@ -1,4 +1,4 @@
-#!/usr/bin/env vpython3
+#!@PYTHONBIN@
 # Copyright 2026 The Dawn & Tint Authors
 #
 # Redistribution and use in source and binary forms, with or without
@@ -40,8 +40,7 @@ from tools.python import cipd_deps
 
 
 def main() -> int:
-    go_binary = os.path.join(DAWN_ROOT, 'tools', 'golang',
-                             cipd_deps.get_cipd_platform(), 'bin', 'go')
+    go_binary = "@GOBIN@"
     if sys.platform == 'win32':
         go_binary += '.exe'
 
