$NetBSD: patch-sandbox_policy_features.cc,v 1.15 2026/02/15 09:04:09 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- sandbox/policy/features.cc.orig	2026-02-03 22:07:10.000000000 +0000
+++ sandbox/policy/features.cc
@@ -99,7 +99,7 @@ BASE_FEATURE(kWinSboxStrictHandleChecks,
 BASE_FEATURE(kSpectreVariant2Mitigation, base::FEATURE_ENABLED_BY_DEFAULT);
 #endif  // BUILDFLAG(IS_CHROMEOS)
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 // Increase the renderer sandbox memory limit. As of 2023, there are no limits
 // on macOS, and a 1TiB limit on Windows. There are reports of users bumping
 // into the limit. This increases the limit by 2x compared to the default
