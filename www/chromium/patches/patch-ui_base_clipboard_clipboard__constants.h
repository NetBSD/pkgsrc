$NetBSD: patch-ui_base_clipboard_clipboard__constants.h,v 1.24 2026/08/09 06:31:24 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- ui/base/clipboard/clipboard_constants.h.orig	2026-08-05 20:17:42.000000000 +0000
+++ ui/base/clipboard/clipboard_constants.h
@@ -44,7 +44,7 @@ inline constexpr char kMimeTypeWindowDra
 
 // ----- LINUX & CHROMEOS & FUCHSIA MIME TYPES -----
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_FUCHSIA)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_BSD)
 inline constexpr char kMimeTypeLinuxUtf8String[] = "UTF8_STRING";
 inline constexpr char kMimeTypeLinuxString[] = "STRING";
 inline constexpr char kMimeTypeLinuxText[] = "TEXT";
@@ -57,7 +57,7 @@ inline constexpr char kMimeTypePortalFil
         // BUILDFLAG(IS_FUCHSIA)
 
 #if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_FUCHSIA) || \
-    BUILDFLAG(IS_ANDROID)
+    BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_BSD)
 inline constexpr char kMimeTypeSourceUrl[] = "chromium/x-source-url";
 #endif  // BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) ||
         // BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_ANDROID)
