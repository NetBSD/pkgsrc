$NetBSD: patch-chrome_browser_extensions_api_passwords__private_passwords__private__delegate__impl.cc,v 1.24 2026/08/09 06:31:08 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/extensions/api/passwords_private/passwords_private_delegate_impl.cc.orig	2026-08-05 20:17:42.000000000 +0000
+++ chrome/browser/extensions/api/passwords_private/passwords_private_delegate_impl.cc
@@ -638,7 +638,7 @@ void PasswordsPrivateDelegateImpl::OnFet
 }
 
 void PasswordsPrivateDelegateImpl::OsReauthTimeoutCall() {
-#if !BUILDFLAG(IS_LINUX)
+#if !BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   if (event_router_) {
     event_router_->OnPasswordManagerAuthTimeout();
   }
