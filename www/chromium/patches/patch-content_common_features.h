$NetBSD: patch-content_common_features.h,v 1.1 2025/02/06 09:58:07 wiz Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- content/common/features.h.orig	2024-12-17 17:58:49.000000000 +0000
+++ content/common/features.h
@@ -34,7 +34,7 @@ CONTENT_EXPORT BASE_DECLARE_FEATURE(kDoc
 CONTENT_EXPORT BASE_DECLARE_FEATURE(kEnableBackForwardCacheForScreenReader);
 CONTENT_EXPORT BASE_DECLARE_FEATURE(
     kEnableBackForwardCacheForOngoingSubframeNavigation);
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 CONTENT_EXPORT BASE_DECLARE_FEATURE(kEnableDevToolsJsErrorReporting);
 #endif  // BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
 CONTENT_EXPORT BASE_DECLARE_FEATURE(kEmbeddingRequiresOptIn);
@@ -80,7 +80,7 @@ CONTENT_EXPORT extern const base::Featur
 CONTENT_EXPORT BASE_DECLARE_FEATURE(kGpuInfoCollectionSeparatePrefetch);
 #endif
 CONTENT_EXPORT BASE_DECLARE_FEATURE(kGroupNIKByJoiningOrigin);
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 CONTENT_EXPORT BASE_DECLARE_FEATURE(kHandleChildThreadTypeChangesInBrowser);
 #endif
 #if BUILDFLAG(IS_ANDROID)
