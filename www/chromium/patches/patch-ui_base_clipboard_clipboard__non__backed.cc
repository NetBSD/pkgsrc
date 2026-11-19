$NetBSD: patch-ui_base_clipboard_clipboard__non__backed.cc,v 1.33 2026/11/19 19:46:10 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- ui/base/clipboard/clipboard_non_backed.cc.orig	2026-11-11 21:01:38.000000000 +0000
+++ ui/base/clipboard/clipboard_non_backed.cc
@@ -472,7 +472,7 @@ ClipboardNonBacked::ClipboardNonBacked()
   // so create internal clipboards for platform supported clipboard buffers.
   constexpr ClipboardBuffer kClipboardBuffers[] = {
       ClipboardBuffer::kCopyPaste,
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_FUCHSIA)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_BSD)
       ClipboardBuffer::kSelection,
 #endif
 #if BUILDFLAG(IS_MAC)
