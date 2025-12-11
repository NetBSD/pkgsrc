$NetBSD: patch-components_password__manager_core_browser_password__form__filling.cc,v 1.9 2025/12/11 09:13:36 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- components/password_manager/core/browser/password_form_filling.cc.orig	2025-11-19 21:40:05.000000000 +0000
+++ components/password_manager/core/browser/password_form_filling.cc
@@ -197,7 +197,7 @@ LikelyFormFilling SendFillInformationToR
 #endif
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
     if (!should_show_popup_without_passwords) {
       client->MaybeShowSavePasswordPrimingPromo(observed_form.url);
     }
