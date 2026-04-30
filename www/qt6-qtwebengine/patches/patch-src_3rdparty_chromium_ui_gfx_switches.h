$NetBSD: patch-src_3rdparty_chromium_ui_gfx_switches.h,v 1.2 2026/04/30 06:39:45 adam Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- src/3rdparty/chromium/ui/gfx/switches.h.orig	2026-03-16 11:40:07.000000000 +0000
+++ src/3rdparty/chromium/ui/gfx/switches.h
@@ -19,7 +19,7 @@ GFX_SWITCHES_EXPORT extern const char kF
 GFX_SWITCHES_EXPORT extern const char kHeadless[];
 GFX_SWITCHES_EXPORT extern const char kScreenInfo[];
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 GFX_SWITCHES_EXPORT extern const char kX11Display[];
 GFX_SWITCHES_EXPORT extern const char kNoXshm[];
 #endif
