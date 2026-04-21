$NetBSD: patch-chrome_browser_flag__descriptions.h,v 1.18 2026/04/21 15:21:09 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/flag_descriptions.h.orig	2026-04-14 23:31:37.000000000 +0200
+++ chrome/browser/flag_descriptions.h
@@ -8413,6 +8413,20 @@ inline constexpr char kEnableOktaSSOName
 inline constexpr char kEnableOktaSSODescription[] =
     "Enables native support for Okta SSO on managed MacOS devices.";
 
+#if BUILDFLAG(IS_BSD)
+inline constexpr char kAudioBackendName[] =
+    "Audio Backend";
+inline constexpr char kAudioBackendDescription[] =
+#if BUILDFLAG(IS_OPENBSD)
+    "Select the desired audio backend to use. The default is sndio.";
+#elif BUILDFLAG(IS_NETBSD)
+    "Select the desired audio backend to use. The default is audioio.";
+#elif BUILDFLAG(IS_FREEBSD)
+    "Select the desired audio backend to use. The default will automatically "
+    "enumerate through the supported backends.";
+#endif
+#endif
+
 // ============================================================================
 // Don't just add flags to the end, put them in the alphabetical order.
 // ============================================================================
