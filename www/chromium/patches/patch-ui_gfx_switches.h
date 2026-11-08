$NetBSD: patch-ui_gfx_switches.h,v 1.32 2026/11/08 15:39:13 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- ui/gfx/switches.h.orig	2026-11-02 23:22:33.000000000 +0000
+++ ui/gfx/switches.h
@@ -19,7 +19,7 @@ GFX_SWITCHES_EXPORT extern const char kF
 GFX_SWITCHES_EXPORT extern const char kHeadless[];
 GFX_SWITCHES_EXPORT extern const char kScreenInfo[];
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 GFX_SWITCHES_EXPORT extern const char kX11Display[];
 GFX_SWITCHES_EXPORT extern const char kNoXshm[];
 #endif
@@ -43,7 +43,7 @@ GFX_SWITCHES_EXPORT BASE_DECLARE_FEATURE
 // data.
 GFX_SWITCHES_EXPORT BASE_DECLARE_FEATURE(kHarfBuzzZeroCopyFontTable);
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 // When enabled, fontconfig initialization is done asynchronously on a worker
 // thread to prevent blocking browser startup. See https://crbug.com/41496758.
 GFX_SWITCHES_EXPORT BASE_DECLARE_FEATURE(kAsyncFontconfigInitialization);
