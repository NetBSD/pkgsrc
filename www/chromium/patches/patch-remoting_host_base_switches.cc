$NetBSD: patch-remoting_host_base_switches.cc,v 1.5 2025/08/13 07:44:28 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- remoting/host/base/switches.cc.orig	2025-07-29 22:51:44.000000000 +0000
+++ remoting/host/base/switches.cc
@@ -23,13 +23,13 @@ const char kProcessTypeEvaluateCapabilit
 const char kProcessTypeFileChooser[] = "file_chooser";
 const char kProcessTypeUrlForwarderConfigurator[] =
     "url_forwarder_configurator";
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 const char kProcessTypeXSessionChooser[] = "xsession_chooser";
 #endif  // BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
 
 const char kEvaluateCapabilitySwitchName[] = "evaluate-type";
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 const char kEnableWtmpdb[] = "enable-wtmpdb";
 #endif
 
