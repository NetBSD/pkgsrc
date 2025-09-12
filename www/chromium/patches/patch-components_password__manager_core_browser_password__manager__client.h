$NetBSD: patch-components_password__manager_core_browser_password__manager__client.h,v 1.7 2025/09/12 16:02:27 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- components/password_manager/core/browser/password_manager_client.h.orig	2025-09-08 23:21:33.000000000 +0000
+++ components/password_manager/core/browser/password_manager_client.h
@@ -31,7 +31,7 @@
 #include "net/cert/cert_status_flags.h"
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 #include "base/i18n/rtl.h"
 #include "components/password_manager/core/browser/password_cross_domain_confirmation_popup_controller.h"
 #include "ui/gfx/geometry/rect_f.h"
@@ -545,7 +545,7 @@ class PasswordManagerClient {
   virtual void TriggerSignIn(signin_metrics::AccessPoint access_point) const;
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   // Shows the bubble with the details of the `form`.
   virtual void OpenPasswordDetailsBubble(
       const password_manager::PasswordForm& form) = 0;
