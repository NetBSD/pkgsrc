$NetBSD: patch-src_3rdparty_chromium_chrome_browser_ui_webui_signin_profile__picker__handler.cc,v 1.1 2025/12/21 09:38:20 markd Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- src/3rdparty/chromium/chrome/browser/ui/webui/signin/profile_picker_handler.cc.orig	2025-11-14 07:55:10.000000000 +0000
+++ src/3rdparty/chromium/chrome/browser/ui/webui/signin/profile_picker_handler.cc
@@ -164,7 +164,7 @@ base::Value::Dict CreateProfileEntry(con
       IDS_PROFILE_PICKER_PROFILE_CARD_LABEL, local_profile_name);
   if (AccountInfo::IsManaged(entry->GetHostedDomain())) {
     profile_entry.Set("avatarBadge", "cr:domain");
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
   } else if (base::FeatureList::IsEnabled(
                  supervised_user::kShowKiteForSupervisedUsers) &&
              entry->IsSupervised()) {
