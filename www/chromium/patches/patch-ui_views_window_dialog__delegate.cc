$NetBSD: patch-ui_views_window_dialog__delegate.cc,v 1.14 2026/01/19 16:14:23 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- ui/views/window/dialog_delegate.cc.orig	2026-01-07 00:50:30.000000000 +0000
+++ ui/views/window/dialog_delegate.cc
@@ -118,7 +118,7 @@ Widget* DialogDelegate::CreateDialogWidg
 
 // static
 bool DialogDelegate::CanSupportCustomFrame(gfx::NativeView parent) {
-#if BUILDFLAG(IS_LINUX) && BUILDFLAG(ENABLE_DESKTOP_AURA)
+#if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)) && BUILDFLAG(ENABLE_DESKTOP_AURA)
   // The new style doesn't support unparented dialogs on Linux desktop.
   return parent != nullptr;
 #else
