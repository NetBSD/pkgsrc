$NetBSD: patch-headless_lib_browser_headless__web__contents__impl.cc,v 1.9 2025/11/04 14:55:41 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- headless/lib/browser/headless_web_contents_impl.cc.orig	2025-10-24 16:42:30.000000000 +0000
+++ headless/lib/browser/headless_web_contents_impl.cc
@@ -69,7 +69,7 @@ BASE_FEATURE(kPrerender2InHeadlessMode, 
 namespace {
 
 void UpdatePrefsFromSystemSettings(blink::RendererPreferences* prefs) {
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
   content::UpdateFontRendererPreferencesFromSystemSettings(prefs);
 #endif
 
