$NetBSD: patch-components_webauthn_core_browser_gpm__user__verification__policy.cc,v 1.20 2026/11/19 19:46:00 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- components/webauthn/core/browser/gpm_user_verification_policy.cc.orig	2026-11-11 21:01:38.000000000 +0000
+++ components/webauthn/core/browser/gpm_user_verification_policy.cc
@@ -17,7 +17,7 @@ bool GpmWillDoUserVerification(device::U
     case device::UserVerificationRequirement::kPreferred:
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_IOS)
       return platform_has_biometrics;
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
       return false;
 #else
       // This default is for unit tests.
