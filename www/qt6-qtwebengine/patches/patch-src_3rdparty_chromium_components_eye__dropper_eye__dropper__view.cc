$NetBSD: patch-src_3rdparty_chromium_components_eye__dropper_eye__dropper__view.cc,v 1.1 2025/12/21 09:38:22 markd Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- src/3rdparty/chromium/components/eye_dropper/eye_dropper_view.cc.orig	2025-05-29 01:27:28.000000000 +0000
+++ src/3rdparty/chromium/components/eye_dropper/eye_dropper_view.cc
@@ -203,7 +203,7 @@ EyeDropperView::EyeDropperView(gfx::Nati
   // EyeDropper/WidgetDelegate.
   set_owned_by_client();
   SetPreferredSize(GetSize());
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // Use TYPE_MENU for Linux to ensure that the eye dropper view is displayed
   // above the color picker.
   views::Widget::InitParams params(
