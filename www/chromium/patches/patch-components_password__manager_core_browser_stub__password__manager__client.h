$NetBSD: patch-components_password__manager_core_browser_stub__password__manager__client.h,v 1.23 2026/07/08 13:42:22 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- components/password_manager/core/browser/stub_password_manager_client.h.orig	2026-07-06 22:58:46.000000000 +0000
+++ components/password_manager/core/browser/stub_password_manager_client.h
@@ -86,7 +86,7 @@ class StubPasswordManagerClient : public
   MockPasswordFeatureManager* GetPasswordFeatureManager();
   version_info::Channel GetChannel() const override;
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   void OpenPasswordDetailsBubble(
       const password_manager::PasswordForm& form) override;
   void MaybeShowSavePasswordPrimingPromo(const GURL& current_url) override;
