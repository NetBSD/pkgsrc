$NetBSD: patch-remoting_base_constants.h,v 1.17 2026/05/10 15:30:01 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- remoting/base/constants.h.orig	2026-04-28 23:05:57.000000000 +0200
+++ remoting/base/constants.h
@@ -27,7 +27,7 @@ const int kDefaultDpi = 96;
 // The video frame rate.
 constexpr int kTargetFrameRate = 30;
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 inline constexpr char kChromeRemoteDesktopSessionEnvVar[] =
     "CHROME_REMOTE_DESKTOP_SESSION";
 #endif
