$NetBSD: patch-chrome_browser_media_webrtc_rtc__diagnostic__logging__utils.cc,v 1.3 2026/05/10 15:29:50 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/media/webrtc/rtc_diagnostic_logging_utils.cc.orig	2026-04-28 23:05:57.000000000 +0200
+++ chrome/browser/media/webrtc/rtc_diagnostic_logging_utils.cc
@@ -22,7 +22,7 @@
 #include "url/origin.h"
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 #define WEBRTC_DIAGNOSTIC_LOGGING_SUPPORTED 1
 #else
 #define WEBRTC_DIAGNOSTIC_LOGGING_SUPPORTED 0
