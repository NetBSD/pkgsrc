$NetBSD: patch-components_password__manager_core_browser_password__autofill__manager.h,v 1.10 2026/01/19 16:14:13 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- components/password_manager/core/browser/password_autofill_manager.h.orig	2026-01-07 00:50:30.000000000 +0000
+++ components/password_manager/core/browser/password_autofill_manager.h
@@ -291,7 +291,7 @@ class PasswordAutofillManager : public a
 
   // Stores the controller of warning popup UI on cross domain filling.
 #if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_CHROMEOS) || \
-    BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_ANDROID)
+    BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_BSD)
   std::unique_ptr<PasswordCrossDomainConfirmationPopupController>
       cross_domain_confirmation_controller_;
 #endif
