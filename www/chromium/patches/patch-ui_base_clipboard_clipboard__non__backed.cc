$NetBSD: patch-ui_base_clipboard_clipboard__non__backed.cc,v 1.32 2026/11/08 15:39:13 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- ui/base/clipboard/clipboard_non_backed.cc.orig	2026-11-02 23:22:33.000000000 +0000
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
