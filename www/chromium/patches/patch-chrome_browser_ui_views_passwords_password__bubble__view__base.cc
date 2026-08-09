$NetBSD: patch-chrome_browser_ui_views_passwords_password__bubble__view__base.cc,v 1.24 2026/08/09 06:31:11 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/ui/views/passwords/password_bubble_view_base.cc.orig	2026-08-05 20:17:42.000000000 +0000
+++ chrome/browser/ui/views/passwords/password_bubble_view_base.cc
@@ -43,7 +43,7 @@
 #include "ui/base/metadata/metadata_impl_macros.h"
 #include "ui/views/controls/button/button.h"
 
-#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "chrome/browser/ui/views/passwords/password_relaunch_chrome_view.h"
 #endif
 
@@ -165,7 +165,7 @@ PasswordBubbleViewBase* PasswordBubbleVi
   } else if (model_state ==
              password_manager::ui::NOTIFY_RECEIVED_SHARED_CREDENTIALS) {
     view = new SharedPasswordsNotificationView(web_contents, anchor_view);
-#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   } else if (model_state == password_manager::ui::KEYCHAIN_ERROR_STATE) {
     view = new RelaunchChromeView(
         web_contents, anchor_view,
