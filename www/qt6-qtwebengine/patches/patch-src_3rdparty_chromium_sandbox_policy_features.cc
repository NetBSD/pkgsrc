$NetBSD: patch-src_3rdparty_chromium_sandbox_policy_features.cc,v 1.1 2025/12/21 09:38:35 markd Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- src/3rdparty/chromium/sandbox/policy/features.cc.orig	2025-10-02 00:36:39.000000000 +0000
+++ src/3rdparty/chromium/sandbox/policy/features.cc
@@ -20,9 +20,13 @@ namespace sandbox::policy::features {
 // (Only causes an effect when feature kNetworkServiceInProcess is disabled.)
 BASE_FEATURE(kNetworkServiceSandbox,
              "NetworkServiceSandbox",
+#if BUILDFLAG(IS_BSD)
+             base::FEATURE_ENABLED_BY_DEFAULT);
+#else
              base::FEATURE_DISABLED_BY_DEFAULT);
+#endif
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 // Enables a fine-grained seccomp-BPF syscall filter for the network service.
 // Only has an effect if IsNetworkSandboxEnabled() returns true.
 // If the network service sandbox is enabled and |kNetworkServiceSyscallFilter|
@@ -135,7 +139,7 @@ BASE_FEATURE(kSpectreVariant2Mitigation,
              base::FEATURE_ENABLED_BY_DEFAULT);
 #endif  // BUILDFLAG(IS_CHROMEOS_ASH)
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 // Increase the renderer sandbox memory limit. As of 2023, there are no limits
 // on macOS, and a 1TiB limit on Windows. There are reports of users bumping
 // into the limit. This increases the limit by 2x compared to the default
