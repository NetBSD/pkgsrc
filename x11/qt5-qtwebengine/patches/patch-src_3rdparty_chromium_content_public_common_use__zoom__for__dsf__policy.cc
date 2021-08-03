$NetBSD: patch-src_3rdparty_chromium_content_public_common_use__zoom__for__dsf__policy.cc,v 1.1 2021/08/03 21:04:35 markd Exp $

--- src/3rdparty/chromium/content/public/common/use_zoom_for_dsf_policy.cc.orig	2020-07-08 21:40:42.000000000 +0000
+++ src/3rdparty/chromium/content/public/common/use_zoom_for_dsf_policy.cc
@@ -25,7 +25,7 @@ const base::Feature kUseZoomForDsfEnable
 #endif
 
 bool IsUseZoomForDSFEnabledByDefault() {
-#if defined(OS_LINUX) || defined(OS_FUCHSIA)
+#if defined(OS_LINUX) || defined(OS_FUCHSIA) || defined(OS_BSD)
   return true;
 #elif defined(OS_WIN) || defined(OS_ANDROID)
   return base::FeatureList::IsEnabled(kUseZoomForDsfEnabledByDefault);
