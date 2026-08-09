$NetBSD: patch-v8_tools_run.py,v 1.24 2026/08/09 06:31:26 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- v8/tools/run.py.orig	2026-08-05 20:17:42.000000000 +0000
+++ v8/tools/run.py
@@ -21,7 +21,7 @@ if cmd and cmd[0] == '--redirect-stdout'
   kwargs = dict(stdout=subprocess.PIPE)
   cmd = cmd[2:]
 
-process = subprocess.Popen(cmd, **kwargs)
+process = subprocess.Popen(cmd, env={"LD_LIBRARY_PATH":"@WRKSRC@/out/Release"}, **kwargs)
 stdout, _ = process.communicate()
 if stdout_file:
   with stdout_file.open('w') as f:
