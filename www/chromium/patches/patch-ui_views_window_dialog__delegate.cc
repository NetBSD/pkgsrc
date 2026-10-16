$NetBSD: patch-ui_views_window_dialog__delegate.cc,v 1.30 2026/10/16 15:31:04 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- ui/views/window/dialog_delegate.cc.orig	2026-10-14 21:09:54.000000000 +0000
+++ ui/views/window/dialog_delegate.cc
@@ -126,7 +126,7 @@ Widget* DialogDelegate::CreateDialogWidg
 
 // static
 bool DialogDelegate::CanSupportCustomFrame(gfx::NativeView parent) {
-#if BUILDFLAG(IS_LINUX) && BUILDFLAG(ENABLE_DESKTOP_AURA)
+#if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)) && BUILDFLAG(ENABLE_DESKTOP_AURA)
   // The new style doesn't support unparented dialogs on Linux desktop.
   return parent != nullptr;
 #else
