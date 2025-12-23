$NetBSD: patch-chrome_browser_flag__descriptions.h,v 1.13 2025/12/23 13:22:13 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/flag_descriptions.h.orig	2025-12-17 23:05:18.000000000 +0000
+++ chrome/browser/flag_descriptions.h
@@ -8586,6 +8586,20 @@ inline constexpr char kHandleMdmErrorsFo
 inline constexpr char kHandleMdmErrorsForDasherAccountsDescription[] =
     "Enables the mdm error handling feature for dasher accounts";
 
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
