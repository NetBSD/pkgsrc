$NetBSD: patch-components_password__manager_core_browser_stub__password__manager__client.cc,v 1.19 2026/05/10 15:29:56 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- components/password_manager/core/browser/stub_password_manager_client.cc.orig	2026-04-28 23:05:57.000000000 +0200
+++ components/password_manager/core/browser/stub_password_manager_client.cc
@@ -231,7 +231,7 @@ version_info::Channel StubPasswordManage
 }
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 void StubPasswordManagerClient::OpenPasswordDetailsBubble(
     const password_manager::PasswordForm& form) {}
 void StubPasswordManagerClient::MaybeShowSavePasswordPrimingPromo(
