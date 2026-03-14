$NetBSD: patch-components_password__manager_core_browser_password__manager__client.h,v 1.16 2026/03/14 12:40:32 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- components/password_manager/core/browser/password_manager_client.h.orig	2026-03-11 22:12:25.000000000 +0000
+++ components/password_manager/core/browser/password_manager_client.h
@@ -30,7 +30,7 @@
 #include "net/cert/cert_status_flags.h"
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 #include "base/i18n/rtl.h"
 #include "components/password_manager/core/browser/password_cross_domain_confirmation_popup_controller.h"
 #include "ui/gfx/geometry/rect_f.h"
@@ -544,7 +544,7 @@ class PasswordManagerClient {
   virtual void TriggerSignIn(signin_metrics::AccessPoint access_point) const;
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   // Shows the bubble with the details of the `form`.
   virtual void OpenPasswordDetailsBubble(
       const password_manager::PasswordForm& form) = 0;
