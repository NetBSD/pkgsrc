$NetBSD: patch-content_common_features.cc,v 1.25 2026/09/02 13:13:31 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- content/common/features.cc.orig	2026-08-31 22:47:51.000000000 +0000
+++ content/common/features.cc
@@ -222,7 +222,7 @@ BASE_FEATURE(kKillOnUnexpectedOriginHead
 BASE_FEATURE(kEmbeddingRequiresOptIn, base::FEATURE_DISABLED_BY_DEFAULT);
 
 // Enables error reporting for JS errors inside DevTools frontend host
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 BASE_FEATURE(kEnableDevToolsJsErrorReporting,
              base::FEATURE_DISABLED_BY_DEFAULT);
 #endif  // BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
@@ -302,12 +302,12 @@ BASE_FEATURE_ENUM_PARAM(FontDataServiceT
                         FontDataServiceTypefaceType::kDwrite,
                         &font_data_service_typeface);
 #endif  // BUILDFLAG(IS_WIN)
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 const base::FeatureParam<FontDataServiceTypefaceType>::Option
     font_data_service_typeface[] = {
         {FontDataServiceTypefaceType::kFreetype, "Freetype"},
         {FontDataServiceTypefaceType::kFontations, "Fontations"}};
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 BASE_FEATURE(kFontDataServiceLinux, base::FEATURE_ENABLED_BY_DEFAULT);
 BASE_FEATURE_ENUM_PARAM(FontDataServiceTypefaceType,
                         kFontDataServiceTypefaceType,
@@ -330,11 +330,11 @@ BASE_FEATURE_ENUM_PARAM(FontDataServiceT
 BASE_FEATURE(kFontDataServiceForCSSLocalFonts,
              base::FEATURE_DISABLED_BY_DEFAULT);
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 bool IsFontDataServiceEnabled() {
 #if BUILDFLAG(IS_WIN)
   return base::FeatureList::IsEnabled(features::kFontDataServiceAllWebContents);
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   return base::FeatureList::IsEnabled(features::kFontDataServiceLinux);
 #elif BUILDFLAG(IS_CHROMEOS)
   return base::FeatureList::IsEnabled(features::kFontDataServiceChromeOS);
