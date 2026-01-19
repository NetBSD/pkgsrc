$NetBSD: patch-components_eye__dropper_eye__dropper__view.cc,v 1.14 2026/01/19 16:14:13 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- components/eye_dropper/eye_dropper_view.cc.orig	2026-01-07 00:50:30.000000000 +0000
+++ components/eye_dropper/eye_dropper_view.cc
@@ -214,7 +214,7 @@ EyeDropperView::EyeDropperView(gfx::Nati
   // EyeDropper/WidgetDelegate.
   set_owned_by_client(OwnedByClientPassKey());
   SetPreferredSize(GetSize());
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // Use TYPE_MENU for Linux to ensure that the eye dropper view is displayed
   // above the color picker.
   views::Widget::InitParams params(
