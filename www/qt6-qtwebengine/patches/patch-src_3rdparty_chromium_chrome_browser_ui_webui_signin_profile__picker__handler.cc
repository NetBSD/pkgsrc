$NetBSD: patch-src_3rdparty_chromium_chrome_browser_ui_webui_signin_profile__picker__handler.cc,v 1.2 2026/04/30 06:39:36 adam Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- src/3rdparty/chromium/chrome/browser/ui/webui/signin/profile_picker_handler.cc.orig	2026-03-16 11:40:07.000000000 +0000
+++ src/3rdparty/chromium/chrome/browser/ui/webui/signin/profile_picker_handler.cc
@@ -168,7 +168,7 @@ base::Value::Dict CreateProfileEntry(con
       IDS_PROFILE_PICKER_PROFILE_CARD_LABEL, local_profile_name);
   if (entry->GetIsManaged() == signin::Tribool::kTrue) {
     profile_entry.Set("avatarBadge", "cr:domain");
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
   } else if (entry->IsSupervised()) {
     profileCardButtonLabel = l10n_util::GetStringFUTF16(
         IDS_PROFILE_PICKER_PROFILE_CARD_LABEL_SUPERVISED, local_profile_name);
