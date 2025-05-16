$NetBSD: patch-chrome_browser_ui_views_tabs_tab__strip__combo__button.cc,v 1.1 2025/05/16 16:08:20 wiz Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/ui/views/tabs/tab_strip_combo_button.cc.orig	2025-05-05 19:21:24.000000000 +0000
+++ chrome/browser/ui/views/tabs/tab_strip_combo_button.cc
@@ -97,7 +97,7 @@ TabStripComboButton::TabStripComboButton
       base::BindRepeating(&TabStripComboButton::OnNewTabButtonStateChanged,
                           base::Unretained(this))));
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // The New Tab Button can be middle-clicked on Linux.
   new_tab_button->SetTriggerableEventFlags(
       new_tab_button->GetTriggerableEventFlags() | ui::EF_MIDDLE_MOUSE_BUTTON);
