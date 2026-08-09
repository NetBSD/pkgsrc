$NetBSD: patch-ui_base_clipboard_clipboard__non__backed.cc,v 1.24 2026/08/09 06:31:24 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- ui/base/clipboard/clipboard_non_backed.cc.orig	2026-08-05 20:17:42.000000000 +0000
+++ ui/base/clipboard/clipboard_non_backed.cc
@@ -459,7 +459,7 @@ ClipboardNonBacked::ClipboardNonBacked()
   // so create internal clipboards for platform supported clipboard buffers.
   constexpr ClipboardBuffer kClipboardBuffers[] = {
     ClipboardBuffer::kCopyPaste,
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_FUCHSIA)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_BSD)
     ClipboardBuffer::kSelection,
 #endif
 #if BUILDFLAG(IS_MAC)
