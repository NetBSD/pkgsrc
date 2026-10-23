$NetBSD: patch-chrome_browser_ui_views_autofill_popup_popup__base__view.cc,v 1.1 2026/10/23 15:05:20 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/ui/views/autofill/popup/popup_base_view.cc.orig	2026-10-19 20:07:21.000000000 +0000
+++ chrome/browser/ui/views/autofill/popup/popup_base_view.cc
@@ -135,7 +135,7 @@ class PopupBaseView::Widget : public vie
     // and setups is not consistent). This is not required for regular
     // Autofill popup use, but it makes certain attacks (those based on the
     // popup being obscured) less practical.
-    if constexpr (BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX)) {
+    if constexpr (BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)) {
       // On ChromeOS and Linux, `Activatable::kYes` and `kSecuritySurface` are
       // incompatible because `kSecuritySurface` windows force accelerated
       // desktop-level widgets (subsurfaces) which do not support reliable
