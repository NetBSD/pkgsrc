$NetBSD: patch-src_3rdparty_chromium_content_public_common_use__zoom__for__dsf__policy.cc,v 1.2 2022/04/18 11:18:19 adam Exp $

--- src/3rdparty/chromium/content/public/common/use_zoom_for_dsf_policy.cc.orig	2021-02-19 16:41:59.000000000 +0000
+++ src/3rdparty/chromium/content/public/common/use_zoom_for_dsf_policy.cc
@@ -25,7 +25,7 @@ const base::Feature kUseZoomForDsfEnable
 #endif
 
 bool IsUseZoomForDSFEnabledByDefault() {
-#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_FUCHSIA)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_FUCHSIA) || defined(OS_BSD)
   return true;
 #elif defined(OS_WIN) || defined(OS_ANDROID)
   return base::FeatureList::IsEnabled(kUseZoomForDsfEnabledByDefault);
