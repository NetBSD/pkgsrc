$NetBSD: patch-chrome_browser_password__manager_password__reuse__manager__factory.cc,v 1.4 2025/07/25 16:17:11 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/password_manager/password_reuse_manager_factory.cc.orig	2025-07-21 19:32:31.000000000 +0000
+++ chrome/browser/password_manager/password_reuse_manager_factory.cc
@@ -128,7 +128,7 @@ PasswordReuseManagerFactory::BuildServic
   // Prepare password hash data for reuse detection.
   reuse_manager->PreparePasswordHashData(GetSignInStateForMetrics(profile));
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   std::unique_ptr<password_manager::PasswordReuseManagerSigninNotifier>
       notifier = std::make_unique<
           password_manager::PasswordReuseManagerSigninNotifierImpl>(
