$NetBSD: patch-chrome_browser_password__manager_chrome__password__manager__client.cc,v 1.32 2026/11/08 15:38:55 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/password_manager/chrome_password_manager_client.cc.orig	2026-11-02 23:22:33.000000000 +0000
+++ chrome/browser/password_manager/chrome_password_manager_client.cc
@@ -1027,7 +1027,7 @@ void ChromePasswordManagerClient::Notify
 }
 
 void ChromePasswordManagerClient::NotifyKeychainError() {
-#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   PasswordsClientUIDelegate* manage_passwords_ui_controller =
       PasswordsClientUIDelegateFromWebContents(web_contents());
   if (manage_passwords_ui_controller) {
@@ -2024,7 +2024,7 @@ template <typename T>
 bool ChromePasswordManagerClient::IsReauthBeforeFillingRequiredImpl(
     T* availability_provider) {
 #if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   if (!GetLocalStatePrefs() || !GetPrefs() || !availability_provider) {
     return false;
   }
@@ -2186,7 +2186,7 @@ void ChromePasswordManagerClient::HideFi
 bool ChromePasswordManagerClient::IsPasswordManagementEnabledForCurrentPage(
     const GURL& url) const {
 #if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   if (IsPasswordManagerForUrlDisallowedByPolicy(url)) {
     return false;
   }
@@ -2225,7 +2225,7 @@ bool ChromePasswordManagerClient::IsPass
 }
 
 #if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 bool ChromePasswordManagerClient::IsPasswordManagerForUrlDisallowedByPolicy(
     const GURL& url) const {
   if (!GetPrefs() || !GetPrefs()->HasPrefPath(
