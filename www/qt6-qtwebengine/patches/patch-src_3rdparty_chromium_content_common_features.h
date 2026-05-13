$NetBSD: patch-src_3rdparty_chromium_content_common_features.h,v 1.3 2026/05/13 05:31:25 adam Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- src/3rdparty/chromium/content/common/features.h.orig	2026-05-08 07:54:08.000000000 +0000
+++ src/3rdparty/chromium/content/common/features.h
@@ -61,7 +61,7 @@ CONTENT_EXPORT BASE_DECLARE_FEATURE(kCom
 CONTENT_EXPORT BASE_DECLARE_FEATURE(kCriticalClientHint);
 CONTENT_EXPORT BASE_DECLARE_FEATURE(kWorkerOrWorkletAgentDoubleReleaseFix);
 CONTENT_EXPORT BASE_DECLARE_FEATURE(kDocumentPolicyNegotiation);
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 CONTENT_EXPORT BASE_DECLARE_FEATURE(kEnableDevToolsJsErrorReporting);
 #endif  // BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
 CONTENT_EXPORT BASE_DECLARE_FEATURE(kEnforceSameDocumentOriginInvariants);
