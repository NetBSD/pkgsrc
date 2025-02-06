$NetBSD: patch-chrome_browser_ui_passwords_manage__passwords__ui__controller.cc,v 1.1 2025/02/06 09:57:52 wiz Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/ui/passwords/manage_passwords_ui_controller.cc.orig	2024-12-17 17:58:49.000000000 +0000
+++ chrome/browser/ui/passwords/manage_passwords_ui_controller.cc
@@ -97,7 +97,7 @@ namespace {
 
 using Logger = autofill::SavePasswordProgressLogger;
 
-#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 // Should be kept in sync with constant declared in
 // bubble_controllers/relaunch_chrome_bubble_controller.cc.
 constexpr int kMaxNumberOfTimesKeychainErrorBubbleIsShown = 3;
@@ -517,7 +517,7 @@ void ManagePasswordsUIController::OnBiom
 }
 
 void ManagePasswordsUIController::OnKeychainError() {
-#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   CHECK(!dialog_controller_);
   PrefService* prefs =
       Profile::FromBrowserContext(web_contents()->GetBrowserContext())
