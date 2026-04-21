$NetBSD: patch-chrome_common_media_component__widevine__cdm__hint__file__linux.h,v 1.18 2026/04/21 15:21:12 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/common/media/component_widevine_cdm_hint_file_linux.h.orig	2026-04-14 23:31:37.000000000 +0200
+++ chrome/common/media/component_widevine_cdm_hint_file_linux.h
@@ -14,7 +14,7 @@
 #error "This file only applies when Widevine used."
 #endif
 
-#if !(BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS))
+#if !(BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD))
 #error "This file only applies to desktop Linux and ChromeOS."
 #endif
 
