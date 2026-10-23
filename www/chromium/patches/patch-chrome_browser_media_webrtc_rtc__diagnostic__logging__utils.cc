$NetBSD: patch-chrome_browser_media_webrtc_rtc__diagnostic__logging__utils.cc,v 1.15 2026/10/23 15:05:18 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/media/webrtc/rtc_diagnostic_logging_utils.cc.orig	2026-10-19 20:07:21.000000000 +0000
+++ chrome/browser/media/webrtc/rtc_diagnostic_logging_utils.cc
@@ -32,7 +32,7 @@
 #include "url/origin.h"
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 #define WEBRTC_DIAGNOSTIC_LOGGING_SUPPORTED 1
 #else
 #define WEBRTC_DIAGNOSTIC_LOGGING_SUPPORTED 0
