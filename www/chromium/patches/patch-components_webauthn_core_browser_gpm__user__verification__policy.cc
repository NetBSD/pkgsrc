$NetBSD: patch-components_webauthn_core_browser_gpm__user__verification__policy.cc,v 1.5 2026/04/21 15:21:15 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- components/webauthn/core/browser/gpm_user_verification_policy.cc.orig	2026-04-14 23:31:37.000000000 +0200
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
