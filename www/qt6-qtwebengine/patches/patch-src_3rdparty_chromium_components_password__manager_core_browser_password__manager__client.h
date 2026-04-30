$NetBSD: patch-src_3rdparty_chromium_components_password__manager_core_browser_password__manager__client.h,v 1.2 2026/04/30 06:39:38 adam Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- src/3rdparty/chromium/components/password_manager/core/browser/password_manager_client.h.orig	2026-03-16 11:40:07.000000000 +0000
+++ src/3rdparty/chromium/components/password_manager/core/browser/password_manager_client.h
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
