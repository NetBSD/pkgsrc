$NetBSD: patch-content_browser_web__contents_web__contents__impl.cc,v 1.2 2026/09/22 13:41:26 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- content/browser/web_contents/web_contents_impl.cc.orig	2026-09-14 22:17:16.000000000 +0000
+++ content/browser/web_contents/web_contents_impl.cc
@@ -1380,7 +1380,7 @@ WebContentsImpl::WebContentsImpl(Browser
       SlowWebPreferenceCache::GetInstance());
   renderer_preferences_.caret_blink_interval =
       native_theme->caret_blink_interval();
-#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
   renderer_preferences_.use_overlay_scrollbar =
       native_theme->use_overlay_scrollbar();
 #endif
@@ -12639,7 +12639,7 @@ void WebContentsImpl::OnNativeThemeUpdat
   HandleColorRelatedStateChanges();
 
   const auto caret_blink_interval = observed_theme->caret_blink_interval();
-#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
   const auto use_overlay_scrollbar = observed_theme->use_overlay_scrollbar();
 #endif
   bool renderer_preference_changed = false;
@@ -12647,7 +12647,7 @@ void WebContentsImpl::OnNativeThemeUpdat
     renderer_preferences_.caret_blink_interval = caret_blink_interval;
     renderer_preference_changed = true;
   }
-#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
   if (renderer_preferences_.use_overlay_scrollbar != use_overlay_scrollbar) {
     renderer_preferences_.use_overlay_scrollbar = use_overlay_scrollbar;
     renderer_preference_changed = true;
