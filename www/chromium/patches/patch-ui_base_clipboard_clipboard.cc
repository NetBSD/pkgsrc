$NetBSD: patch-ui_base_clipboard_clipboard.cc,v 1.6 2026/05/10 15:30:07 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- ui/base/clipboard/clipboard.cc.orig	2026-04-28 23:05:57.000000000 +0200
+++ ui/base/clipboard/clipboard.cc
@@ -28,7 +28,7 @@
 #include "ui/gfx/geometry/size.h"
 #include "url/gurl.h"
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "ui/linux/linux_ui.h"
 #endif
 
@@ -115,7 +115,7 @@ bool Clipboard::IsSupportedClipboardBuff
 
 // static
 bool Clipboard::IsMiddleClickPasteEnabled() {
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   if (auto* linux_ui = ui::LinuxUi::instance()) {
     return linux_ui->PrimaryPasteEnabled();
   }
