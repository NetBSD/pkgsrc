$NetBSD: patch-chrome_browser_accessibility_page__colors__controller.cc,v 1.1 2025/10/16 19:43:20 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/accessibility/page_colors_controller.cc.orig	2025-10-13 21:41:26.000000000 +0000
+++ chrome/browser/accessibility/page_colors_controller.cc
@@ -11,7 +11,7 @@
 #include "components/prefs/pref_service.h"
 #include "ui/native_theme/native_theme.h"
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "ui/linux/linux_ui.h"
 #include "ui/linux/linux_ui_factory.h"
 #endif  // BUILDFLAG(IS_LINUX)
@@ -88,7 +88,7 @@ void PageColorsController::OnPreferredCo
 
 void PageColorsController::OnPageColorsChanged() {
   auto* native_theme = ui::NativeTheme::GetInstanceForNativeUi();
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // Allow the Linux native theme to update its state for page colors.
   if (auto* linux_ui_theme = ui::GetDefaultLinuxUiTheme()) {
     if (auto* linux_native_theme = linux_ui_theme->GetNativeTheme()) {
