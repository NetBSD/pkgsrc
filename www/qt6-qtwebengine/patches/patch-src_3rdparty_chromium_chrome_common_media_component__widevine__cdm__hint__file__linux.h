$NetBSD: patch-src_3rdparty_chromium_chrome_common_media_component__widevine__cdm__hint__file__linux.h,v 1.1 2025/12/21 09:38:20 markd Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- src/3rdparty/chromium/chrome/common/media/component_widevine_cdm_hint_file_linux.h.orig	2025-05-29 01:27:28.000000000 +0000
+++ src/3rdparty/chromium/chrome/common/media/component_widevine_cdm_hint_file_linux.h
@@ -17,7 +17,7 @@
 
 // TODO(crbug.com/40118868): Revisit the macro expression once build flag switch
 // of lacros-chrome is complete.
-#if !(BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS))
+#if !(BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD))
 #error "This file only applies to desktop Linux and ChromeOS."
 #endif
 
