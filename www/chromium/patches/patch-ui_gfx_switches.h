$NetBSD: patch-ui_gfx_switches.h,v 1.3 2025/07/07 09:23:39 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- ui/gfx/switches.h.orig	2025-06-30 06:54:11.000000000 +0000
+++ ui/gfx/switches.h
@@ -19,7 +19,7 @@ GFX_SWITCHES_EXPORT extern const char kF
 GFX_SWITCHES_EXPORT extern const char kHeadless[];
 GFX_SWITCHES_EXPORT extern const char kScreenInfo[];
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 GFX_SWITCHES_EXPORT extern const char kX11Display[];
 GFX_SWITCHES_EXPORT extern const char kNoXshm[];
 #endif
