$NetBSD: patch-remoting_host_security__key_remote__security__key__main.cc,v 1.12 2026/01/19 16:14:18 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- remoting/host/security_key/remote_security_key_main.cc.orig	2026-01-07 00:50:30.000000000 +0000
+++ remoting/host/security_key/remote_security_key_main.cc
@@ -24,7 +24,7 @@
 #include "remoting/host/security_key/security_key_message_handler.h"
 #include "remoting/host/usage_stats_consent.h"
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "remoting/base/crash/crash_reporting_crashpad.h"
 #endif  // BUILDFLAG(IS_LINUX)
 
@@ -96,7 +96,7 @@ int RemoteSecurityKeyMain(int argc, char
 
 #if defined(REMOTING_ENABLE_CRASH_REPORTING)
   if (IsUsageStatsAllowed()) {
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     InitializeCrashpadReporting();
 #elif BUILDFLAG(IS_WIN)
     InitializeBreakpadReporting();
