$NetBSD: patch-content_common_features.h,v 1.9 2025/11/04 14:55:40 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- content/common/features.h.orig	2025-10-24 16:42:30.000000000 +0000
+++ content/common/features.h
@@ -60,7 +60,7 @@ CONTENT_EXPORT BASE_DECLARE_FEATURE(kCom
 CONTENT_EXPORT BASE_DECLARE_FEATURE(kCommittedOriginTracking);
 CONTENT_EXPORT BASE_DECLARE_FEATURE(kCriticalClientHint);
 CONTENT_EXPORT BASE_DECLARE_FEATURE(kDocumentPolicyNegotiation);
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 CONTENT_EXPORT BASE_DECLARE_FEATURE(kEnableDevToolsJsErrorReporting);
 #endif  // BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
 CONTENT_EXPORT BASE_DECLARE_FEATURE(kEnforceSameDocumentOriginInvariants);
