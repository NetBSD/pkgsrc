$NetBSD: patch-sandbox_policy_features.h,v 1.13 2026/09/02 13:13:34 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- sandbox/policy/features.h.orig	2026-08-31 22:47:51.000000000 +0000
+++ sandbox/policy/features.h
@@ -46,7 +46,7 @@ SANDBOX_POLICY_EXPORT BASE_DECLARE_FEATU
 SANDBOX_POLICY_EXPORT BASE_DECLARE_FEATURE(kSpectreVariant2Mitigation);
 #endif  // BUILDFLAG(IS_CHROMEOS)
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 SANDBOX_POLICY_EXPORT BASE_DECLARE_FEATURE(kHigherRendererMemoryLimit);
 #endif  // BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
 
