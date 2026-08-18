$NetBSD: patch-src_3rdparty_chromium_content_common_features.h,v 1.4 2026/08/18 18:26:06 adam Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- src/3rdparty/chromium/content/common/features.h.orig	2026-08-11 12:42:19.000000000 +0000
+++ src/3rdparty/chromium/content/common/features.h
@@ -63,7 +63,7 @@ CONTENT_EXPORT BASE_DECLARE_FEATURE(kWor
 CONTENT_EXPORT BASE_DECLARE_FEATURE(kDocumentPolicyNegotiation);
 CONTENT_EXPORT BASE_DECLARE_FEATURE(kDumpOnOriginHeaderMismatch);
 CONTENT_EXPORT BASE_DECLARE_FEATURE(kDumpOnUnexpectedOriginHeader);
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 CONTENT_EXPORT BASE_DECLARE_FEATURE(kEnableDevToolsJsErrorReporting);
 #endif  // BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
 CONTENT_EXPORT BASE_DECLARE_FEATURE(kEnforceSameDocumentOriginInvariants);
