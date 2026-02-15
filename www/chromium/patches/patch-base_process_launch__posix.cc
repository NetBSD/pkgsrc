$NetBSD: patch-base_process_launch__posix.cc,v 1.15 2026/02/15 09:03:55 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- base/process/launch_posix.cc.orig	2026-02-03 22:07:10.000000000 +0000
+++ base/process/launch_posix.cc
@@ -218,6 +218,8 @@ static const char kFDDir[] = "/dev/fd";
 static const char kFDDir[] = "/dev/fd";
 #elif BUILDFLAG(IS_OPENBSD)
 static const char kFDDir[] = "/dev/fd";
+#elif BUILDFLAG(IS_NETBSD)
+static const char kFDDir[] = "/dev/fd";
 #elif BUILDFLAG(IS_ANDROID)
 static const char kFDDir[] = "/proc/self/fd";
 #endif
