$NetBSD: patch-src_3rdparty_chromium_content_common_features.h,v 1.2 2026/04/30 06:39:40 adam Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- src/3rdparty/chromium/content/common/features.h.orig	2026-03-16 11:40:07.000000000 +0000
+++ src/3rdparty/chromium/content/common/features.h
@@ -60,7 +60,7 @@ CONTENT_EXPORT BASE_DECLARE_FEATURE(kCom
 CONTENT_EXPORT BASE_DECLARE_FEATURE(kCommittedOriginTracking);
 CONTENT_EXPORT BASE_DECLARE_FEATURE(kCriticalClientHint);
 CONTENT_EXPORT BASE_DECLARE_FEATURE(kDocumentPolicyNegotiation);
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 CONTENT_EXPORT BASE_DECLARE_FEATURE(kEnableDevToolsJsErrorReporting);
 #endif  // BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
 CONTENT_EXPORT BASE_DECLARE_FEATURE(kEnforceSameDocumentOriginInvariants);
