$NetBSD: patch-remoting_host_remote__open__url_remote__open__url__main.cc,v 1.12 2026/01/19 16:14:18 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- remoting/host/remote_open_url/remote_open_url_main.cc.orig	2026-01-07 00:50:30.000000000 +0000
+++ remoting/host/remote_open_url/remote_open_url_main.cc
@@ -27,7 +27,7 @@
 #include "remoting/host/usage_stats_consent.h"
 #include "ui/base/l10n/l10n_util.h"
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "remoting/base/crash/crash_reporting_crashpad.h"
 #endif  // BUILDFLAG(IS_LINUX)
 
@@ -51,7 +51,7 @@ int RemoteOpenUrlMain(int argc, char** a
 
 #if defined(REMOTING_ENABLE_CRASH_REPORTING)
   if (IsUsageStatsAllowed()) {
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     InitializeCrashpadReporting();
 #elif BUILDFLAG(IS_WIN)
     InitializeBreakpadReporting();
