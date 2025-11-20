$NetBSD: patch-content_public_common_content__switches.cc,v 1.10 2025/11/20 08:36:15 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- content/public/common/content_switches.cc.orig	2025-11-14 20:31:45.000000000 +0000
+++ content/public/common/content_switches.cc
@@ -347,6 +347,8 @@ const char kEnableIsolatedWebAppsInRende
 // builds.
 const char kEnableLogging[]                 = "enable-logging";
 
+const char kDisableUnveil[]                 = "disable-unveil";
+
 // Enables the type, downlinkMax attributes of the NetInfo API. Also, enables
 // triggering of change attribute of the NetInfo API when there is a change in
 // the connection type.
@@ -940,7 +942,7 @@ const char kPreventResizingContentsForTe
     "prevent-resizing-contents-for-testing";
 #endif
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 // Allows sending text-to-speech requests to speech-dispatcher, a common
 // Linux speech service. Because it's buggy, the user must explicitly
 // enable it so that visiting a random webpage can't cause instability.
