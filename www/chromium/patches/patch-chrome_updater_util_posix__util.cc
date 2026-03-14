$NetBSD: patch-chrome_updater_util_posix__util.cc,v 1.16 2026/03/14 12:40:30 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/updater/util/posix_util.cc.orig	2026-03-11 22:12:25.000000000 +0000
+++ chrome/updater/util/posix_util.cc
@@ -20,7 +20,7 @@
 #include "chrome/updater/updater_branding.h"
 #include "chrome/updater/util/util.h"
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "chrome/updater/util/linux_util.h"
 #endif
 
