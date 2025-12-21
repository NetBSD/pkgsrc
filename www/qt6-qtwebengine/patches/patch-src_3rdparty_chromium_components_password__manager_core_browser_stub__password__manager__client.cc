$NetBSD: patch-src_3rdparty_chromium_components_password__manager_core_browser_stub__password__manager__client.cc,v 1.1 2025/12/21 09:38:24 markd Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- src/3rdparty/chromium/components/password_manager/core/browser/stub_password_manager_client.cc.orig	2025-10-02 00:36:39.000000000 +0000
+++ src/3rdparty/chromium/components/password_manager/core/browser/stub_password_manager_client.cc
@@ -199,7 +199,7 @@ version_info::Channel StubPasswordManage
 }
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 void StubPasswordManagerClient::OpenPasswordDetailsBubble(
     const password_manager::PasswordForm& form) {}
 #endif  // BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) ||
