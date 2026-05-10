$NetBSD: patch-chrome_browser_password__manager_chrome__password__manager__client.cc,v 1.19 2026/05/10 15:29:50 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/password_manager/chrome_password_manager_client.cc.orig	2026-04-28 23:05:57.000000000 +0200
+++ chrome/browser/password_manager/chrome_password_manager_client.cc
@@ -703,7 +703,7 @@ void ChromePasswordManagerClient::Contin
 bool ChromePasswordManagerClient::IsReauthBeforeFillingRequired(
     device_reauth::DeviceAuthenticator* authenticator) {
 #if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   if (!GetLocalStatePrefs() || !GetPrefs() || !authenticator) {
     return false;
   }
@@ -988,7 +988,7 @@ void ChromePasswordManagerClient::Notify
 }
 
 void ChromePasswordManagerClient::NotifyKeychainError() {
-#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   PasswordsClientUIDelegate* manage_passwords_ui_controller =
       PasswordsClientUIDelegateFromWebContents(web_contents());
   if (manage_passwords_ui_controller) {
@@ -2033,7 +2033,7 @@ void ChromePasswordManagerClient::HideFi
 bool ChromePasswordManagerClient::IsPasswordManagementEnabledForCurrentPage(
     const GURL& url) const {
 #if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   if (IsPasswordManagerForUrlDisallowedByPolicy(url)) {
     return false;
   }
@@ -2072,7 +2072,7 @@ bool ChromePasswordManagerClient::IsPass
 }
 
 #if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 bool ChromePasswordManagerClient::IsPasswordManagerForUrlDisallowedByPolicy(
     const GURL& url) const {
   if (!GetPrefs() || !GetPrefs()->HasPrefPath(
