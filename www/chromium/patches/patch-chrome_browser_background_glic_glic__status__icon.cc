$NetBSD: patch-chrome_browser_background_glic_glic__status__icon.cc,v 1.13 2026/01/19 16:14:08 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/background/glic/glic_status_icon.cc.orig	2026-01-07 00:50:30.000000000 +0000
+++ chrome/browser/background/glic/glic_status_icon.cc
@@ -111,7 +111,7 @@ GlicStatusIcon::GlicStatusIcon(GlicContr
     return;
   }
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // Set a vector icon for proper theming on Linux.
   status_icon_->SetIcon(
       GlicVectorIconManager::GetVectorIcon(IDR_GLIC_BUTTON_VECTOR_ICON));
@@ -166,7 +166,7 @@ GlicStatusIcon::~GlicStatusIcon() {
 
   context_menu_ = nullptr;
   if (status_icon_) {
-#if !BUILDFLAG(IS_LINUX)
+#if !BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     status_icon_->RemoveObserver(this);
 #endif
     std::unique_ptr<StatusIcon> removed_icon =
@@ -304,7 +304,7 @@ void GlicStatusIcon::UpdateHotkey(const 
 }
 
 void GlicStatusIcon::UpdateVisibilityOfExitInContextMenu() {
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   if (context_menu_) {
     const bool is_visible = BrowserList::GetInstance()->empty();
     const std::optional<size_t> index =
@@ -382,7 +382,7 @@ std::unique_ptr<StatusIconMenuModel> Gli
   menu->AddItem(IDC_GLIC_STATUS_ICON_MENU_SETTINGS,
                 l10n_util::GetStringUTF16(IDS_GLIC_STATUS_ICON_MENU_SETTINGS));
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   menu->AddSeparator(ui::NORMAL_SEPARATOR);
   menu->AddItem(IDC_GLIC_STATUS_ICON_MENU_EXIT,
                 l10n_util::GetStringUTF16(IDS_GLIC_STATUS_ICON_MENU_EXIT));
