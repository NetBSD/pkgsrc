$NetBSD: patch-chrome_browser_ui_toolbar_app__menu__model.cc,v 1.3 2026/09/22 13:41:21 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/ui/toolbar/app_menu_model.cc.orig	2026-09-14 22:17:16.000000000 +0000
+++ chrome/browser/ui/toolbar/app_menu_model.cc
@@ -264,7 +264,7 @@ std::u16string GetUpgradeDialogTitleText
     return l10n_util::GetStringUTF16(IDS_UPGRADE_BUBBLE_MENU_ITEM);
   }
 #if BUILDFLAG(GOOGLE_CHROME_BRANDING) && \
-    (BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX))
+    (BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD))
   return l10n_util::GetStringUTF16(IDS_RELAUNCH_TO_UPDATE_ALT);
 #else
   return l10n_util::GetStringUTF16(IDS_RELAUNCH_TO_UPDATE);
@@ -2491,7 +2491,7 @@ void AppMenuModel::Build() {
 
     SetAccessibleNameAt(GetIndexOfCommandId(IDC_SHOW_MANAGEMENT_PAGE).value(),
                         GetManagedUiMenuItemTooltip(browser_->GetProfile()));
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     if (enterprise_util::IsBrowserManaged(browser_->GetProfile()) &&
         base::FeatureList::IsEnabled(features::kEnterpriseReleaseNotes)) {
       AddItemWithStringIdAndVectorIcon(
