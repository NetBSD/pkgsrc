$NetBSD: patch-content_public_common_content__switches.cc,v 1.19 2026/05/10 15:29:58 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- content/public/common/content_switches.cc.orig	2026-04-28 23:05:57.000000000 +0200
+++ content/public/common/content_switches.cc
@@ -349,6 +349,8 @@ const char kEnableIsolatedWebAppsInRende
 // builds.
 const char kEnableLogging[]                 = "enable-logging";
 
+const char kDisableUnveil[]                 = "disable-unveil";
+
 // Enables the type, downlinkMax attributes of the NetInfo API. Also, enables
 // triggering of change attribute of the NetInfo API when there is a change in
 // the connection type.
@@ -942,7 +944,7 @@ const char kPreventResizingContentsForTe
     "prevent-resizing-contents-for-testing";
 #endif
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 // Allows sending text-to-speech requests to speech-dispatcher, a common
 // Linux speech service. Because it's buggy, the user must explicitly
 // enable it so that visiting a random webpage can't cause instability.
