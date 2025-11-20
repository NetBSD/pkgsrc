$NetBSD: patch-remoting_host_base_switches.h,v 1.10 2025/11/20 08:36:19 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- remoting/host/base/switches.h.orig	2025-11-14 20:31:45.000000000 +0000
+++ remoting/host/base/switches.h
@@ -35,13 +35,13 @@ extern const char kProcessTypeRdpDesktop
 extern const char kProcessTypeEvaluateCapability[];
 extern const char kProcessTypeFileChooser[];
 extern const char kProcessTypeUrlForwarderConfigurator[];
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 extern const char kProcessTypeXSessionChooser[];
 #endif  // BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
 
 extern const char kEvaluateCapabilitySwitchName[];
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 // Used to record client sessions to wtmpd.
 extern const char kEnableWtmpdb[];
 #endif
