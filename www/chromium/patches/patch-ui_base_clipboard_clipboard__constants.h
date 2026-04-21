$NetBSD: patch-ui_base_clipboard_clipboard__constants.h,v 1.18 2026/04/21 15:21:23 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- ui/base/clipboard/clipboard_constants.h.orig	2026-04-14 23:31:37.000000000 +0200
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
