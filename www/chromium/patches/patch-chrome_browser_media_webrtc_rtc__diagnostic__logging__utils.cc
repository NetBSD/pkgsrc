$NetBSD: patch-chrome_browser_media_webrtc_rtc__diagnostic__logging__utils.cc,v 1.1 2026/04/10 17:31:49 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/media/webrtc/rtc_diagnostic_logging_utils.cc.orig	2026-04-06 16:25:54.000000000 +0000
+++ chrome/browser/media/webrtc/rtc_diagnostic_logging_utils.cc
@@ -22,7 +22,7 @@
 #include "url/origin.h"
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 #define WEBRTC_DIAGNOSTIC_LOGGING_SUPPORTED 1
 #else
 #define WEBRTC_DIAGNOSTIC_LOGGING_SUPPORTED 0
