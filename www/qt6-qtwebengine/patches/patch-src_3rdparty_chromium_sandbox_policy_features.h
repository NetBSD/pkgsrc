$NetBSD: patch-src_3rdparty_chromium_sandbox_policy_features.h,v 1.2 2026/04/30 06:39:42 adam Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- src/3rdparty/chromium/sandbox/policy/features.h.orig	2026-03-16 11:40:07.000000000 +0000
+++ src/3rdparty/chromium/sandbox/policy/features.h
@@ -17,7 +17,7 @@ namespace sandbox::policy::features {
 #if BUILDFLAG(IS_QTWEBENGINE) || (!BUILDFLAG(IS_MAC) && !BUILDFLAG(IS_FUCHSIA))
 SANDBOX_POLICY_EXPORT BASE_DECLARE_FEATURE(kNetworkServiceSandbox);
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 SANDBOX_POLICY_EXPORT BASE_DECLARE_FEATURE(kNetworkServiceSyscallFilter);
 SANDBOX_POLICY_EXPORT BASE_DECLARE_FEATURE(kNetworkServiceFileAllowlist);
 #endif  // BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
@@ -43,7 +43,7 @@ SANDBOX_POLICY_EXPORT BASE_DECLARE_FEATU
 SANDBOX_POLICY_EXPORT BASE_DECLARE_FEATURE(kSpectreVariant2Mitigation);
 #endif  // BUILDFLAG(IS_CHROMEOS)
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 SANDBOX_POLICY_EXPORT BASE_DECLARE_FEATURE(kHigherRendererMemoryLimit);
 #endif  // BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
 
