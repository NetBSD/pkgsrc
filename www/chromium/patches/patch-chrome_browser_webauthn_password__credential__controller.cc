$NetBSD: patch-chrome_browser_webauthn_password__credential__controller.cc,v 1.5 2025/09/08 13:24:22 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/webauthn/password_credential_controller.cc.orig	2025-08-29 18:50:09.000000000 +0000
+++ chrome/browser/webauthn/password_credential_controller.cc
@@ -46,7 +46,7 @@ password_manager::PasswordManagerClient*
 
 #if !BUILDFLAG(IS_ANDROID)
 std::u16string GetAuthenticationMessage(std::string_view rp_id) {
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   return u"";
 #else
   return l10n_util::GetStringFUTF16(IDS_PASSWORD_MANAGER_FILLING_REAUTH,
