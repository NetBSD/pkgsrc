$NetBSD: patch-remoting_host_webauthn_remote__webauthn__main.cc,v 1.8 2025/11/20 08:36:20 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- remoting/host/webauthn/remote_webauthn_main.cc.orig	2025-11-14 20:31:45.000000000 +0000
+++ remoting/host/webauthn/remote_webauthn_main.cc
@@ -27,7 +27,7 @@
 #include "remoting/host/webauthn/remote_webauthn_caller_security_utils.h"
 #include "remoting/host/webauthn/remote_webauthn_native_messaging_host.h"
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "remoting/base/crash/crash_reporting_crashpad.h"
 #endif  // BUILDFLAG(IS_LINUX)
 
@@ -50,7 +50,7 @@ int RemoteWebAuthnMain(int argc, char** 
 
 #if defined(REMOTING_ENABLE_CRASH_REPORTING)
   if (IsUsageStatsAllowed()) {
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     InitializeCrashpadReporting();
 #elif BUILDFLAG(IS_WIN)
     InitializeBreakpadReporting();
