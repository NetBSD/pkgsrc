$NetBSD: patch-chrome_browser_ui_webui_signin_profile__picker__handler.cc,v 1.1 2025/02/06 09:57:55 wiz Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/ui/webui/signin/profile_picker_handler.cc.orig	2024-12-17 17:58:49.000000000 +0000
+++ chrome/browser/ui/webui/signin/profile_picker_handler.cc
@@ -209,7 +209,7 @@ base::Value::Dict CreateProfileEntry(con
 
   if (AccountInfo::IsManaged(entry->GetHostedDomain())) {
     profile_entry.Set("avatarBadge", "cr:domain");
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
   } else if (base::FeatureList::IsEnabled(
                  supervised_user::kShowKiteForSupervisedUsers) &&
              entry->IsSupervised()) {
@@ -1211,7 +1211,7 @@ void ProfilePickerHandler::BeginFirstWeb
 }
 
 void ProfilePickerHandler::MaybeUpdateGuestMode() {
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
   if (!base::FeatureList::IsEnabled(
           supervised_user::kHideGuestModeForSupervisedUsers)) {
     return;
