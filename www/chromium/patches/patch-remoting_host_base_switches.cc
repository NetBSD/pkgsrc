$NetBSD: patch-remoting_host_base_switches.cc,v 1.25 2026/09/02 13:13:34 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- remoting/host/base/switches.cc.orig	2026-08-31 22:47:51.000000000 +0000
+++ remoting/host/base/switches.cc
@@ -25,13 +25,13 @@ const char kProcessTypeEvaluateCapabilit
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
 
