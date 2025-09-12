$NetBSD: patch-content_common_features.cc,v 1.7 2025/09/12 16:02:29 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- content/common/features.cc.orig	2025-09-08 23:21:33.000000000 +0000
+++ content/common/features.cc
@@ -170,7 +170,7 @@ BASE_FEATURE(kEmbeddingRequiresOptIn,
              base::FEATURE_DISABLED_BY_DEFAULT);
 
 // Enables error reporting for JS errors inside DevTools frontend host
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 BASE_FEATURE(kEnableDevToolsJsErrorReporting,
              "EnableDevToolsJsErrorReporting",
              base::FEATURE_DISABLED_BY_DEFAULT);
