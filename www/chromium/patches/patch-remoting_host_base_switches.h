$NetBSD: patch-remoting_host_base_switches.h,v 1.18 2026/04/21 15:21:19 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- remoting/host/base/switches.h.orig	2026-04-14 23:31:37.000000000 +0200
+++ remoting/host/base/switches.h
@@ -36,14 +36,14 @@ extern const char kProcessTypeRdpDesktop
 extern const char kProcessTypeEvaluateCapability[];
 extern const char kProcessTypeFileChooser[];
 extern const char kProcessTypeUrlForwarderConfigurator[];
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 extern const char kProcessTypeXSessionChooser[];
 extern const char kProcessTypeUserSystemdEnv[];
 #endif  // BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
 
 extern const char kEvaluateCapabilitySwitchName[];
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 // Used to record client sessions to wtmpd.
 extern const char kEnableWtmpdb[];
 
