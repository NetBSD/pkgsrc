$NetBSD: patch-chrome_browser_background_omnibox__everywhere_omnibox__everywhere__background__mode__manager.cc,v 1.1 2026/10/13 13:16:31 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/background/omnibox_everywhere/omnibox_everywhere_background_mode_manager.cc.orig	2026-10-06 00:06:58.000000000 +0000
+++ chrome/browser/background/omnibox_everywhere/omnibox_everywhere_background_mode_manager.cc
@@ -252,7 +252,7 @@ void OmniboxEverywhereBackgroundModeMana
 
 void OmniboxEverywhereBackgroundModeManager::
     UpdateVisibilityOfExitInContextMenu() {
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   if (context_menu_) {
     const bool is_visible = GlobalBrowserCollection::GetInstance()->IsEmpty();
     const std::optional<size_t> index = context_menu_->GetIndexOfCommandId(
@@ -306,7 +306,7 @@ void OmniboxEverywhereBackgroundModeMana
                 l10n_util::GetStringUTF16(
                     IDS_OMNIBOX_EVERYWHERE_STATUS_ICON_MENU_SETTINGS));
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   menu->AddSeparator(ui::NORMAL_SEPARATOR);
   menu->AddItem(
       IDC_OMNIBOX_EVERYWHERE_STATUS_ICON_MENU_EXIT,
