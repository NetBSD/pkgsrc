$NetBSD: patch-third__party_blink_common_features.cc,v 1.4 2025/10/16 19:43:34 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- third_party/blink/common/features.cc.orig	2025-10-13 21:41:26.000000000 +0000
+++ third_party/blink/common/features.cc
@@ -572,7 +572,7 @@ BASE_FEATURE_PARAM(base::TimeDelta,
 BASE_FEATURE(DevToolsImprovedNetworkError, base::FEATURE_DISABLED_BY_DEFAULT);
 
 BASE_FEATURE(DirectCompositorThreadIpc,
-#if BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC)
+#if BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
              base::FEATURE_ENABLED_BY_DEFAULT
 #else
              base::FEATURE_DISABLED_BY_DEFAULT
