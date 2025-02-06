$NetBSD: patch-v8_tools_run.py,v 1.1 2025/02/06 09:58:37 wiz Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- v8/tools/run.py.orig	2024-12-17 17:58:49.000000000 +0000
+++ v8/tools/run.py
@@ -21,7 +21,7 @@ if cmd and cmd[0] == '--redirect-stdout'
   kwargs = dict(stdout=subprocess.PIPE)
   cmd = cmd[2:]
 
-process = subprocess.Popen(cmd, **kwargs)
+process = subprocess.Popen(cmd, env={"LD_LIBRARY_PATH":"${WRKSRC}/out/Release"}, **kwargs)
 stdout, _ = process.communicate()
 if stdout_file:
   with stdout_file.open('w') as f:
