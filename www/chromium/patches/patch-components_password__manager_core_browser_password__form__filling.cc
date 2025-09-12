$NetBSD: patch-components_password__manager_core_browser_password__form__filling.cc,v 1.5 2025/09/12 16:02:27 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- components/password_manager/core/browser/password_form_filling.cc.orig	2025-09-08 23:21:33.000000000 +0000
+++ components/password_manager/core/browser/password_form_filling.cc
@@ -178,7 +178,7 @@ LikelyFormFilling SendFillInformationToR
 #endif
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
     if (!should_show_popup_without_passwords) {
       client->MaybeShowSavePasswordPrimingPromo(observed_form.url);
     }
