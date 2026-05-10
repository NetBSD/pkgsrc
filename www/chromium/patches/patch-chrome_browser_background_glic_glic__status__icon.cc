$NetBSD: patch-chrome_browser_background_glic_glic__status__icon.cc,v 1.18 2026/05/10 15:29:49 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/background/glic/glic_status_icon.cc.orig	2026-04-28 23:05:57.000000000 +0200
+++ chrome/browser/background/glic/glic_status_icon.cc
@@ -95,7 +95,7 @@ GlicStatusIcon::GlicStatusIcon(GlicContr
 GlicStatusIcon::~GlicStatusIcon() {
   context_menu_ = nullptr;
   if (status_icon_) {
-#if !BUILDFLAG(IS_LINUX)
+#if !BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     status_icon_->RemoveObserver(this);
 #endif
     std::unique_ptr<StatusIcon> removed_icon =
@@ -116,7 +116,7 @@ void GlicStatusIcon::Init() {
     return;
   }
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // Set a vector icon for proper theming on Linux.
   status_icon_->SetIcon(
       GlicVectorIconManager::GetVectorIcon(IDR_GLIC_BUTTON_VECTOR_ICON));
@@ -214,7 +214,7 @@ void GlicStatusIcon::UpdateHotkey(const 
 }
 
 void GlicStatusIcon::UpdateVisibilityOfExitInContextMenu() {
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   if (context_menu_) {
     const bool is_visible = GlobalBrowserCollection::GetInstance()->IsEmpty();
     const std::optional<size_t> index =
@@ -276,7 +276,7 @@ std::unique_ptr<StatusIconMenuModel> Gli
   menu->AddItem(IDC_GLIC_STATUS_ICON_MENU_SETTINGS,
                 l10n_util::GetStringUTF16(IDS_GLIC_STATUS_ICON_MENU_SETTINGS));
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   menu->AddSeparator(ui::NORMAL_SEPARATOR);
   menu->AddItem(IDC_GLIC_STATUS_ICON_MENU_EXIT,
                 l10n_util::GetStringUTF16(IDS_GLIC_STATUS_ICON_MENU_EXIT));
