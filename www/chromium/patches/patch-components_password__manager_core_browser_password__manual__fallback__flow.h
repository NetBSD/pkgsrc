$NetBSD: patch-components_password__manager_core_browser_password__manual__fallback__flow.h,v 1.29 2026/10/13 13:16:39 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- components/password_manager/core/browser/password_manual_fallback_flow.h.orig	2026-10-06 00:06:58.000000000 +0000
+++ components/password_manager/core/browser/password_manual_fallback_flow.h
@@ -20,7 +20,7 @@
 #include "components/password_manager/core/browser/ui/saved_passwords_presenter.h"
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 #include "components/password_manager/core/browser/password_cross_domain_confirmation_popup_controller.h"
 #endif  // BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) ||
         // BUILDFLAG(IS_CHROMEOS)
@@ -186,7 +186,7 @@ class PasswordManualFallbackFlow : publi
   std::unique_ptr<device_reauth::DeviceAuthenticator> authenticator_;
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   std::unique_ptr<PasswordCrossDomainConfirmationPopupController>
       cross_domain_confirmation_popup_controller_;
 #endif  // BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) ||
