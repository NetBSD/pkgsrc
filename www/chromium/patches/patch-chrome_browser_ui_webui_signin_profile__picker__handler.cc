$NetBSD: patch-chrome_browser_ui_webui_signin_profile__picker__handler.cc,v 1.3 2025/07/07 09:23:29 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/ui/webui/signin/profile_picker_handler.cc.orig	2025-06-30 06:54:11.000000000 +0000
+++ chrome/browser/ui/webui/signin/profile_picker_handler.cc
@@ -165,7 +165,7 @@ base::Value::Dict CreateProfileEntry(con
       IDS_PROFILE_PICKER_PROFILE_CARD_LABEL, local_profile_name);
   if (AccountInfo::IsManaged(entry->GetHostedDomain())) {
     profile_entry.Set("avatarBadge", "cr:domain");
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
   } else if (base::FeatureList::IsEnabled(
                  supervised_user::kShowKiteForSupervisedUsers) &&
              entry->IsSupervised()) {
