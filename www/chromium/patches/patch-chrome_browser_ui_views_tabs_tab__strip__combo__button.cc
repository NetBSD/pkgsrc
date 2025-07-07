$NetBSD: patch-chrome_browser_ui_views_tabs_tab__strip__combo__button.cc,v 1.2 2025/07/07 09:23:28 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/ui/views/tabs/tab_strip_combo_button.cc.orig	2025-06-30 06:54:11.000000000 +0000
+++ chrome/browser/ui/views/tabs/tab_strip_combo_button.cc
@@ -94,7 +94,7 @@ TabStripComboButton::TabStripComboButton
       base::BindRepeating(&TabStripComboButton::OnNewTabButtonStateChanged,
                           base::Unretained(this))));
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // The New Tab Button can be middle-clicked on Linux.
   new_tab_button->SetTriggerableEventFlags(
       new_tab_button->GetTriggerableEventFlags() | ui::EF_MIDDLE_MOUSE_BUTTON);
