$NetBSD: patch-src_3rdparty_chromium_components_password__manager_core_browser_stub__password__manager__client.h,v 1.2 2026/04/30 06:39:39 adam Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- src/3rdparty/chromium/components/password_manager/core/browser/stub_password_manager_client.h.orig	2026-03-16 11:40:07.000000000 +0000
+++ src/3rdparty/chromium/components/password_manager/core/browser/stub_password_manager_client.h
@@ -77,7 +77,7 @@ class StubPasswordManagerClient : public
   MockPasswordFeatureManager* GetPasswordFeatureManager();
   version_info::Channel GetChannel() const override;
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   void OpenPasswordDetailsBubble(
       const password_manager::PasswordForm& form) override;
   void MaybeShowSavePasswordPrimingPromo(const GURL& current_url) override;
