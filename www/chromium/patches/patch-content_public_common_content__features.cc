$NetBSD: patch-content_public_common_content__features.cc,v 1.14 2026/01/19 16:14:15 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- content/public/common/content_features.cc.orig	2026-01-07 00:50:30.000000000 +0000
+++ content/public/common/content_features.cc
@@ -117,7 +117,7 @@ BASE_FEATURE(kAudioServiceLaunchOnStartu
 
 // Runs the audio service in a separate process.
 BASE_FEATURE(kAudioServiceOutOfProcess,
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
              base::FEATURE_ENABLED_BY_DEFAULT
 #else
              base::FEATURE_DISABLED_BY_DEFAULT
@@ -1146,10 +1146,10 @@ BASE_FEATURE(kWebAssemblyTiering, base::
 
 // Enable WebAssembly trap handler.
 BASE_FEATURE(kWebAssemblyTrapHandler,
-#if ((BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_WIN) ||  \
+#if ((BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_WIN) ||  \
       BUILDFLAG(IS_MAC)) &&                                                  \
      defined(ARCH_CPU_X86_64)) ||                                            \
-    ((BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_MAC)) && \
+    ((BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_MAC)) && \
      defined(ARCH_CPU_ARM64))
              base::FEATURE_ENABLED_BY_DEFAULT
 #else
@@ -1206,7 +1206,11 @@ BASE_FEATURE(kWebUIInProcessResourceLoad
 
 // Controls whether the WebUSB API is enabled:
 // https://wicg.github.io/webusb
+#if BUILDFLAG(IS_BSD)
+BASE_FEATURE(kWebUsb, "WebUSB", base::FEATURE_DISABLED_BY_DEFAULT);
+#else
 BASE_FEATURE(kWebUsb, "WebUSB", base::FEATURE_ENABLED_BY_DEFAULT);
+#endif
 
 // Apply `PrefetchPriority::kHighest` for Webview Prefetch API.
 BASE_FEATURE(kWebViewPrefetchHighestPrefetchPriority,
