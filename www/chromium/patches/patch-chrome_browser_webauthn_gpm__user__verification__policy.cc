$NetBSD: patch-chrome_browser_webauthn_gpm__user__verification__policy.cc,v 1.10 2025/11/20 08:36:11 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/webauthn/gpm_user_verification_policy.cc.orig	2025-11-14 20:31:45.000000000 +0000
+++ chrome/browser/webauthn/gpm_user_verification_policy.cc
@@ -17,7 +17,7 @@ bool GpmWillDoUserVerification(device::U
       return platform_has_biometrics;
 #elif BUILDFLAG(IS_MAC)
       return platform_has_biometrics;
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
       return false;
 #else
       // This default is for unit tests.
