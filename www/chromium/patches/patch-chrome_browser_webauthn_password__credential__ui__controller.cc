$NetBSD: patch-chrome_browser_webauthn_password__credential__ui__controller.cc,v 1.6 2025/12/23 13:22:16 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/webauthn/password_credential_ui_controller.cc.orig	2025-12-17 23:05:18.000000000 +0000
+++ chrome/browser/webauthn/password_credential_ui_controller.cc
@@ -26,7 +26,7 @@ using content::WebContents;
 namespace {
 
 std::u16string GetAuthenticationMessage(std::string_view rp_id) {
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   return u"";
 #else
   return l10n_util::GetStringFUTF16(IDS_PASSWORD_MANAGER_FILLING_REAUTH,
