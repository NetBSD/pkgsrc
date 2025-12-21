$NetBSD: patch-src_3rdparty_chromium_ui_base_clipboard_clipboard__constants.h,v 1.1 2025/12/21 09:38:46 markd Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- src/3rdparty/chromium/ui/base/clipboard/clipboard_constants.h.orig	2024-12-17 17:58:49.000000000 +0000
+++ src/3rdparty/chromium/ui/base/clipboard/clipboard_constants.h
@@ -48,7 +48,7 @@ extern const char kMimeTypeDataTransferE
 
 // ----- LINUX & CHROMEOS & FUCHSIA MIME TYPES -----
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_FUCHSIA)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_BSD)
 COMPONENT_EXPORT(UI_BASE_CLIPBOARD_TYPES)
 extern const char kMimeTypeLinuxUtf8String[];
 COMPONENT_EXPORT(UI_BASE_CLIPBOARD_TYPES)
