$NetBSD: patch-content_public_common_content__features.cc,v 1.6 2025/09/08 13:24:26 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- content/public/common/content_features.cc.orig	2025-08-29 18:50:09.000000000 +0000
+++ content/public/common/content_features.cc
@@ -103,7 +103,7 @@ BASE_FEATURE(kAudioServiceLaunchOnStartu
 // Runs the audio service in a separate process.
 BASE_FEATURE(kAudioServiceOutOfProcess,
              "AudioServiceOutOfProcess",
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
              base::FEATURE_ENABLED_BY_DEFAULT
 #else
              base::FEATURE_DISABLED_BY_DEFAULT
@@ -1394,9 +1394,9 @@ BASE_FEATURE(kWebAssemblyTiering,
 BASE_FEATURE(kWebAssemblyTrapHandler,
              "WebAssemblyTrapHandler",
 #if ((BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_WIN) ||  \
-      BUILDFLAG(IS_MAC)) &&                                                  \
+      BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)) &&                             \
      defined(ARCH_CPU_X86_64)) ||                                            \
-    ((BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_MAC)) && \
+    ((BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)) && \
      defined(ARCH_CPU_ARM64))
              base::FEATURE_ENABLED_BY_DEFAULT
 #else
@@ -1453,7 +1453,11 @@ BASE_FEATURE(kWebUIJSErrorReportingExten
 
 // Controls whether the WebUSB API is enabled:
 // https://wicg.github.io/webusb
+#if BUILDFLAG(IS_BSD)
+BASE_FEATURE(kWebUsb, "WebUSB", base::FEATURE_DISABLED_BY_DEFAULT);
+#else
 BASE_FEATURE(kWebUsb, "WebUSB", base::FEATURE_ENABLED_BY_DEFAULT);
+#endif
 
 // Apply `PrefetchPriority::kHighest` for Webview Prefetch API.
 BASE_FEATURE(kWebViewPrefetchHighestPrefetchPriority,
