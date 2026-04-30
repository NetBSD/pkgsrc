$NetBSD: patch-src_3rdparty_chromium_chrome_common_media_component__widevine__cdm__hint__file__linux.h,v 1.2 2026/04/30 06:39:37 adam Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- src/3rdparty/chromium/chrome/common/media/component_widevine_cdm_hint_file_linux.h.orig	2026-03-16 11:40:07.000000000 +0000
+++ src/3rdparty/chromium/chrome/common/media/component_widevine_cdm_hint_file_linux.h
@@ -14,7 +14,7 @@
 #error "This file only applies when Widevine used."
 #endif
 
-#if !(BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS))
+#if !(BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD))
 #error "This file only applies to desktop Linux and ChromeOS."
 #endif
 
