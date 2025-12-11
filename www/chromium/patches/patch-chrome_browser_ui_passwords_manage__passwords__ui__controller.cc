$NetBSD: patch-chrome_browser_ui_passwords_manage__passwords__ui__controller.cc,v 1.11 2025/12/11 09:13:32 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/ui/passwords/manage_passwords_ui_controller.cc.orig	2025-11-19 21:40:05.000000000 +0000
+++ chrome/browser/ui/passwords/manage_passwords_ui_controller.cc
@@ -116,7 +116,7 @@ namespace {
 
 using Logger = autofill::SavePasswordProgressLogger;
 
-#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 // Should be kept in sync with constant declared in
 // bubble_controllers/relaunch_chrome_bubble_controller.cc.
 constexpr int kMaxNumberOfTimesKeychainErrorBubbleIsShown = 3;
@@ -628,7 +628,7 @@ void ManagePasswordsUIController::OnBiom
 }
 
 void ManagePasswordsUIController::OnKeychainError() {
-#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   CHECK(!dialog_controller_);
   PrefService* prefs =
       Profile::FromBrowserContext(web_contents()->GetBrowserContext())
