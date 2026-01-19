$NetBSD: patch-content_common_features.h,v 1.14 2026/01/19 16:14:15 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- content/common/features.h.orig	2026-01-07 00:50:30.000000000 +0000
+++ content/common/features.h
@@ -67,7 +67,7 @@ CONTENT_EXPORT BASE_DECLARE_FEATURE(kCom
 CONTENT_EXPORT BASE_DECLARE_FEATURE(kCopyFromSurfaceAlwaysCallCallback);
 CONTENT_EXPORT BASE_DECLARE_FEATURE(kCriticalClientHint);
 CONTENT_EXPORT BASE_DECLARE_FEATURE(kDocumentPolicyNegotiation);
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 CONTENT_EXPORT BASE_DECLARE_FEATURE(kEnableDevToolsJsErrorReporting);
 #endif  // BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
 CONTENT_EXPORT BASE_DECLARE_FEATURE(kEnforceSameDocumentOriginInvariants);
@@ -106,7 +106,7 @@ enum class FontDataServiceTypefaceType {
 CONTENT_EXPORT BASE_DECLARE_FEATURE_PARAM(FontDataServiceTypefaceType,
                                           kFontDataServiceTypefaceType);
 #endif  // BUILDFLAG(IS_WIN)
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 CONTENT_EXPORT BASE_DECLARE_FEATURE(kFontDataServiceLinux);
 enum class FontDataServiceTypefaceType {
   kFreetype,
@@ -116,7 +116,7 @@ CONTENT_EXPORT BASE_DECLARE_FEATURE_PARA
                                           kFontDataServiceTypefaceType);
 #endif  // BUILDFLAG(IS_LINUX)
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 bool IsFontDataServiceEnabled();
 #endif
 
