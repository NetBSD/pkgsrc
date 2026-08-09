$NetBSD: patch-content_public_common_content__features.cc,v 1.24 2026/08/09 06:31:17 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- content/public/common/content_features.cc.orig	2026-08-05 20:17:42.000000000 +0000
+++ content/public/common/content_features.cc
@@ -147,7 +147,7 @@ BASE_FEATURE(kAttachUnownedInnerWebConte
 
 // Runs the audio service in a separate process.
 BASE_FEATURE(kAudioServiceOutOfProcess,
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
              base::FEATURE_ENABLED_BY_DEFAULT
 #else
              base::FEATURE_DISABLED_BY_DEFAULT
@@ -157,7 +157,7 @@ BASE_FEATURE(kAudioServiceOutOfProcess,
 // Enables the audio-service sandbox. This feature has an effect only when the
 // kAudioServiceOutOfProcess feature is enabled.
 BASE_FEATURE(kAudioServiceSandbox,
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_FUCHSIA)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_BSD)
              base::FEATURE_ENABLED_BY_DEFAULT
 #else
              base::FEATURE_DISABLED_BY_DEFAULT
@@ -1251,10 +1251,10 @@ BASE_FEATURE(kWebAssemblyTiering, base::
 
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
@@ -1315,7 +1315,11 @@ BASE_FEATURE(kWebUIInProcessResourceLoad
 
 // Controls whether the WebUSB API is enabled:
 // https://wicg.github.io/webusb
+#if BUILDFLAG(IS_BSD)
+BASE_FEATURE(kWebUsb, "WebUSB", base::FEATURE_DISABLED_BY_DEFAULT);
+#else
 BASE_FEATURE(kWebUsb, "WebUSB", base::FEATURE_ENABLED_BY_DEFAULT);
+#endif
 
 // Apply `PrefetchPriority::kHighest` for Webview Prefetch API.
 BASE_FEATURE(kWebViewPrefetchHighestPrefetchPriority,
