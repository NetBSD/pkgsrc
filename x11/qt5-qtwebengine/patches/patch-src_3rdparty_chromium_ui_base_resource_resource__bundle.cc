$NetBSD: patch-src_3rdparty_chromium_ui_base_resource_resource__bundle.cc,v 1.1 2021/08/03 21:04:36 markd Exp $

--- src/3rdparty/chromium/ui/base/resource/resource_bundle.cc.orig	2020-07-15 18:56:49.000000000 +0000
+++ src/3rdparty/chromium/ui/base/resource/resource_bundle.cc
@@ -841,7 +841,7 @@ void ResourceBundle::ReloadFonts() {
 }
 
 ScaleFactor ResourceBundle::GetMaxScaleFactor() const {
-#if defined(OS_WIN) || defined(OS_LINUX)
+#if defined(OS_WIN) || defined(OS_LINUX) || defined(OS_BSD)
   return max_scale_factor_;
 #else
   return GetSupportedScaleFactors().back();
@@ -894,7 +894,7 @@ void ResourceBundle::InitSharedInstance(
   // On platforms other than iOS, 100P is always a supported scale factor.
   // For Windows we have a separate case in this function.
   supported_scale_factors.push_back(SCALE_FACTOR_100P);
-#if defined(OS_MACOSX) || defined(OS_LINUX) || defined(OS_WIN)
+#if defined(OS_MACOSX) || defined(OS_LINUX) || defined(OS_WIN) || defined(OS_BSD)
   supported_scale_factors.push_back(SCALE_FACTOR_200P);
 #endif
 #endif
