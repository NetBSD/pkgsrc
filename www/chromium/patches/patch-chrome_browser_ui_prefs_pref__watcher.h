$NetBSD: patch-chrome_browser_ui_prefs_pref__watcher.h,v 1.5 2026/04/21 15:21:11 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/ui/prefs/pref_watcher.h.orig	2026-04-14 23:31:37.000000000 +0200
+++ chrome/browser/ui/prefs/pref_watcher.h
@@ -53,7 +53,7 @@ class PrefWatcher : public KeyedService,
   // blink::RendererPreferences.
   std::set<raw_ptr<PrefsTabHelper, SetExperimental>> tab_helpers_;
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   friend class PrimaryPastePrefHelper;
   std::unique_ptr<PrimaryPastePrefHelper> primary_paste_pref_helper_;
 #endif
