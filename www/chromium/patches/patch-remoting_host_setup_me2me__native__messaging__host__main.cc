$NetBSD: patch-remoting_host_setup_me2me__native__messaging__host__main.cc,v 1.4 2025/09/08 13:24:29 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- remoting/host/setup/me2me_native_messaging_host_main.cc.orig	2025-08-29 18:50:09.000000000 +0000
+++ remoting/host/setup/me2me_native_messaging_host_main.cc
@@ -41,7 +41,7 @@
 #include "base/apple/scoped_nsautorelease_pool.h"
 #endif  // BUILDFLAG(IS_APPLE)
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "remoting/base/crash/crash_reporting_crashpad.h"
 #endif  // BUILDFLAG(IS_LINUX)
 
@@ -99,7 +99,7 @@ int Me2MeNativeMessagingHostMain(int arg
   // needs to be initialized first, so that the preference for crash-reporting
   // can be looked up in the config file.
   if (IsUsageStatsAllowed()) {
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     InitializeCrashpadReporting();
 #elif BUILDFLAG(IS_WIN)
     InitializeBreakpadReporting();
