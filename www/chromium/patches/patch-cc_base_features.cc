$NetBSD: patch-cc_base_features.cc,v 1.19 2026/05/10 15:29:48 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- cc/base/features.cc.orig	2026-04-28 23:05:57.000000000 +0200
+++ cc/base/features.cc
@@ -33,7 +33,7 @@ const base::FeatureParam<int> kDeferImpl
 // Note that kUseDMSAAForTiles only controls vulkan launch on android. We will
 // be using a separate flag to control the launch on GL.
 BASE_FEATURE(kUseDMSAAForTiles,
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_ANDROID)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_BSD)
              base::FEATURE_ENABLED_BY_DEFAULT
 #else
              base::FEATURE_DISABLED_BY_DEFAULT
