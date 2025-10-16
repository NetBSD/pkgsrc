$NetBSD: patch-sandbox_policy_features.cc,v 1.8 2025/10/16 19:43:32 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- sandbox/policy/features.cc.orig	2025-10-13 21:41:26.000000000 +0000
+++ sandbox/policy/features.cc
@@ -19,7 +19,11 @@ namespace sandbox::policy::features {
 // (Only causes an effect when feature kNetworkServiceInProcess is disabled.)
 BASE_FEATURE(kNetworkServiceSandbox,
              "NetworkServiceSandbox",
+#if BUILDFLAG(IS_BSD)
+             base::FEATURE_ENABLED_BY_DEFAULT);
+#else
              base::FEATURE_DISABLED_BY_DEFAULT);
+#endif
 
 #if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
 // Enables a fine-grained seccomp-BPF syscall filter for the network service.
