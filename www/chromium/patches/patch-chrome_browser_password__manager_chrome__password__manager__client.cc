$NetBSD: patch-chrome_browser_password__manager_chrome__password__manager__client.cc,v 1.6 2025/09/08 13:24:19 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/password_manager/chrome_password_manager_client.cc.orig	2025-08-29 18:50:09.000000000 +0000
+++ chrome/browser/password_manager/chrome_password_manager_client.cc
@@ -729,7 +729,7 @@ void ChromePasswordManagerClient::
 bool ChromePasswordManagerClient::IsReauthBeforeFillingRequired(
     device_reauth::DeviceAuthenticator* authenticator) {
 #if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   if (!GetLocalStatePrefs() || !GetPrefs() || !authenticator) {
     return false;
   }
@@ -1008,7 +1008,7 @@ void ChromePasswordManagerClient::Notify
 }
 
 void ChromePasswordManagerClient::NotifyKeychainError() {
-#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   PasswordsClientUIDelegate* manage_passwords_ui_controller =
       PasswordsClientUIDelegateFromWebContents(web_contents());
   if (manage_passwords_ui_controller) {
@@ -2083,7 +2083,7 @@ void ChromePasswordManagerClient::HideFi
 bool ChromePasswordManagerClient::IsPasswordManagementEnabledForCurrentPage(
     const GURL& url) const {
 #if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   if (IsPasswordManagerForUrlDisallowedByPolicy(url)) {
     return false;
   }
@@ -2122,7 +2122,7 @@ bool ChromePasswordManagerClient::IsPass
 }
 
 #if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 bool ChromePasswordManagerClient::IsPasswordManagerForUrlDisallowedByPolicy(
     const GURL& url) const {
   if (!GetPrefs() || !GetPrefs()->HasPrefPath(
