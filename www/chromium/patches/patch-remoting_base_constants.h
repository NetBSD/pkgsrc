$NetBSD: patch-remoting_base_constants.h,v 1.31 2026/11/19 19:46:04 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- remoting/base/constants.h.orig	2026-11-11 21:01:38.000000000 +0000
+++ remoting/base/constants.h
@@ -30,7 +30,7 @@ const int kDefaultDpi = 96;
 // The video frame rate.
 constexpr int kTargetFrameRate = 30;
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 inline constexpr char kChromeRemoteDesktopSessionEnvVar[] =
     "CHROME_REMOTE_DESKTOP_SESSION";
 
