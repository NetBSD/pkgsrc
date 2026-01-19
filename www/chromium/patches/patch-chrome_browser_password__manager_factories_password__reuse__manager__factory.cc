$NetBSD: patch-chrome_browser_password__manager_factories_password__reuse__manager__factory.cc,v 1.10 2026/01/19 16:14:09 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/password_manager/factories/password_reuse_manager_factory.cc.orig	2026-01-07 00:50:30.000000000 +0000
+++ chrome/browser/password_manager/factories/password_reuse_manager_factory.cc
@@ -125,7 +125,7 @@ PasswordReuseManagerFactory::BuildServic
   // Prepare password hash data for reuse detection.
   reuse_manager->PreparePasswordHashData(GetSignInStateForMetrics(profile));
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   std::unique_ptr<password_manager::PasswordReuseManagerSigninNotifier>
       notifier = std::make_unique<
           password_manager::PasswordReuseManagerSigninNotifierImpl>(
