$NetBSD: patch-components_eye__dropper_eye__dropper__view.cc,v 1.1 2025/02/06 09:57:59 wiz Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- components/eye_dropper/eye_dropper_view.cc.orig	2024-12-17 17:58:49.000000000 +0000
+++ components/eye_dropper/eye_dropper_view.cc
@@ -203,7 +203,7 @@ EyeDropperView::EyeDropperView(gfx::Nati
   // EyeDropper/WidgetDelegate.
   set_owned_by_client();
   SetPreferredSize(GetSize());
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // Use TYPE_MENU for Linux to ensure that the eye dropper view is displayed
   // above the color picker.
   views::Widget::InitParams params(
