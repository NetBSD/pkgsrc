$NetBSD: patch-chrome_browser_ui_webui_signin_profile__picker__handler.cc,v 1.18 2026/04/21 15:21:12 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/ui/webui/signin/profile_picker_handler.cc.orig	2026-04-14 23:31:37.000000000 +0200
+++ chrome/browser/ui/webui/signin/profile_picker_handler.cc
@@ -178,7 +178,7 @@ base::DictValue CreateProfileState(const
       IDS_PROFILE_PICKER_PROFILE_CARD_LABEL, local_profile_name);
   if (entry->GetIsManaged() == signin::Tribool::kTrue) {
     profile_entry.Set("avatarBadge", "cr:domain");
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
   } else if (entry->IsSupervised()) {
     profileCardButtonLabel = l10n_util::GetStringFUTF16(
         IDS_PROFILE_PICKER_PROFILE_CARD_LABEL_SUPERVISED, local_profile_name);
