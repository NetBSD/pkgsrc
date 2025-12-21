$NetBSD: patch-src_3rdparty_chromium_sandbox_policy_features.h,v 1.1 2025/12/21 09:38:36 markd Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- src/3rdparty/chromium/sandbox/policy/features.h.orig	2025-10-02 00:36:39.000000000 +0000
+++ src/3rdparty/chromium/sandbox/policy/features.h
@@ -18,7 +18,7 @@ namespace sandbox::policy::features {
 #if defined(TOOLKIT_QT) || (!BUILDFLAG(IS_MAC) && !BUILDFLAG(IS_FUCHSIA))
 SANDBOX_POLICY_EXPORT BASE_DECLARE_FEATURE(kNetworkServiceSandbox);
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 SANDBOX_POLICY_EXPORT BASE_DECLARE_FEATURE(kNetworkServiceSyscallFilter);
 SANDBOX_POLICY_EXPORT BASE_DECLARE_FEATURE(kNetworkServiceFileAllowlist);
 #endif  // BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
@@ -45,7 +45,7 @@ SANDBOX_POLICY_EXPORT BASE_DECLARE_FEATU
 SANDBOX_POLICY_EXPORT BASE_DECLARE_FEATURE(kSpectreVariant2Mitigation);
 #endif  // BUILDFLAG(IS_CHROMEOS_ASH)
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 SANDBOX_POLICY_EXPORT BASE_DECLARE_FEATURE(kHigherRendererMemoryLimit);
 #endif  // BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
 
