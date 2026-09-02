$NetBSD: patch-ui_gfx_render__text__harfbuzz.cc,v 1.4 2026/09/02 13:13:39 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- ui/gfx/render_text_harfbuzz.cc.orig	2026-08-31 22:47:51.000000000 +0000
+++ ui/gfx/render_text_harfbuzz.cc
@@ -203,7 +203,7 @@ const char* GetPlatformColorEmojiFontNam
   return "Segoe UI Emoji";
 #elif BUILDFLAG(IS_APPLE)
   return "Apple Color Emoji";
-#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   return "Noto Color Emoji";
 #else
   return nullptr;
