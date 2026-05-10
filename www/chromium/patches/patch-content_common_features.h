$NetBSD: patch-content_common_features.h,v 1.19 2026/05/10 15:29:58 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- content/common/features.h.orig	2026-04-28 23:05:57.000000000 +0200
+++ content/common/features.h
@@ -81,7 +81,7 @@ CONTENT_EXPORT BASE_DECLARE_FEATURE(kDoc
 CONTENT_EXPORT BASE_DECLARE_FEATURE(kDumpOnInvalidNavigationHeaders);
 CONTENT_EXPORT BASE_DECLARE_FEATURE(kDumpOnOriginHeaderMismatch);
 CONTENT_EXPORT BASE_DECLARE_FEATURE(kDumpOnUnexpectedOriginHeader);
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 CONTENT_EXPORT BASE_DECLARE_FEATURE(kEnableDevToolsJsErrorReporting);
 #endif  // BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
 CONTENT_EXPORT BASE_DECLARE_FEATURE(kEnforceSameDocumentOriginInvariants);
@@ -120,8 +120,8 @@ enum class FontDataServiceTypefaceType {
 CONTENT_EXPORT BASE_DECLARE_FEATURE_PARAM(FontDataServiceTypefaceType,
                                           kFontDataServiceTypefaceType);
 #endif  // BUILDFLAG(IS_WIN)
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 CONTENT_EXPORT BASE_DECLARE_FEATURE(kFontDataServiceLinux);
 #else
 CONTENT_EXPORT BASE_DECLARE_FEATURE(kFontDataServiceChromeOS);
@@ -134,7 +134,7 @@ CONTENT_EXPORT BASE_DECLARE_FEATURE_PARA
                                           kFontDataServiceTypefaceType);
 #endif  // BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 bool IsFontDataServiceEnabled();
 #endif
 
