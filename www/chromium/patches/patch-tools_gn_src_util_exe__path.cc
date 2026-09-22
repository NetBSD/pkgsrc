$NetBSD: patch-tools_gn_src_util_exe__path.cc,v 1.26 2026/09/22 13:41:33 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- tools/gn/src/util/exe_path.cc.orig	2026-09-14 22:17:16.000000000 +0000
+++ tools/gn/src/util/exe_path.cc
@@ -15,7 +15,7 @@
 #include <windows.h>
 
 #include "base/win/win_util.h"
-#elif defined(OS_FREEBSD) || defined(OS_NETBSD)
+#elif defined(OS_FREEBSD) || defined(OS_NETBSD) || defined(OS_OPENBSD)
 #include <limits.h>
 #include <sys/sysctl.h>
 #include <sys/types.h>
@@ -26,6 +26,10 @@
 #include <stdlib.h>
 #endif
 
+#if defined(OS_OPENBSD)
+#include <sys/param.h>
+#endif
+
 #if defined(OS_MACOSX)
 
 base::FilePath GetExePath() {
@@ -104,6 +108,20 @@ base::FilePath GetExePath() {
   return base::FilePath(raw);
 }
 
+#elif defined(OS_OPENBSD)
+
+base::FilePath GetExePath() {
+#if (OpenBSD >= 202610)
+  char execpath[PATH_MAX];
+  if (getexecpath(execpath, sizeof(execpath)) != 0)
+    return base::FilePath();
+
+  return base::FilePath(execpath);
+#else
+  return base::FilePath();
+#endif
+}
+
 #elif defined(OS_ZOS)
 
 base::FilePath GetExePath() {
