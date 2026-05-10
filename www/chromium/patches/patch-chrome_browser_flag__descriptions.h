$NetBSD: patch-chrome_browser_flag__descriptions.h,v 1.19 2026/05/10 15:29:50 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/flag_descriptions.h.orig	2026-04-28 23:05:57.000000000 +0200
+++ chrome/browser/flag_descriptions.h
@@ -8453,6 +8453,20 @@ inline constexpr char kAndroidEntraSsoDe
     "Enables native support for Entra SSO on Android provided by selected "
     "Authentication Brokers.";
 
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
