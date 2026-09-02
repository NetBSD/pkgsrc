$NetBSD: patch-chrome_browser_ui_views_passwords_password__bubble__view__base.cc,v 1.25 2026/09/02 13:13:26 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/ui/views/passwords/password_bubble_view_base.cc.orig	2026-08-31 22:47:51.000000000 +0000
+++ chrome/browser/ui/views/passwords/password_bubble_view_base.cc
@@ -36,7 +36,7 @@
 #include "components/tabs/public/tab_interface.h"
 #include "ui/base/metadata/metadata_impl_macros.h"
 
-#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "chrome/browser/ui/views/passwords/password_relaunch_chrome_view.h"
 #endif
 
@@ -158,7 +158,7 @@ PasswordBubbleViewBase* PasswordBubbleVi
   } else if (model_state ==
              password_manager::ui::NOTIFY_RECEIVED_SHARED_CREDENTIALS) {
     view = new SharedPasswordsNotificationView(web_contents, anchor_view);
-#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   } else if (model_state == password_manager::ui::KEYCHAIN_ERROR_STATE) {
     view = new RelaunchChromeView(
         web_contents, anchor_view,
