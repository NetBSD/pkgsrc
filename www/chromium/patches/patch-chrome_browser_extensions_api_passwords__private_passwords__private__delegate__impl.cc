$NetBSD: patch-chrome_browser_extensions_api_passwords__private_passwords__private__delegate__impl.cc,v 1.10 2025/11/20 08:36:07 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/extensions/api/passwords_private/passwords_private_delegate_impl.cc.orig	2025-11-14 20:31:45.000000000 +0000
+++ chrome/browser/extensions/api/passwords_private/passwords_private_delegate_impl.cc
@@ -660,7 +660,7 @@ void PasswordsPrivateDelegateImpl::OnFet
 }
 
 void PasswordsPrivateDelegateImpl::OsReauthTimeoutCall() {
-#if !BUILDFLAG(IS_LINUX)
+#if !BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_BSD)
   PasswordsPrivateEventRouter* router =
       PasswordsPrivateEventRouterFactory::GetForProfile(profile_);
   if (router) {
