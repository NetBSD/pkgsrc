$NetBSD: patch-chrome_browser_sessions_session__restore.cc,v 1.32 2026/11/08 15:38:55 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/sessions/session_restore.cc.orig	2026-11-02 23:22:33.000000000 +0000
+++ chrome/browser/sessions/session_restore.cc
@@ -136,7 +136,7 @@
 #include "ui/aura/window_occlusion_tracker.h"
 #endif
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "chrome/browser/ui/webui/whats_new/whats_new_fetcher.h"
 #endif  // BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
 
@@ -1423,7 +1423,7 @@ class SessionRestoreImpl : public Browse
     bool is_first_tab = true;
     for (const auto& startup_tab : startup_tabs) {
       const GURL& url = startup_tab.url;
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
       if (url == whats_new::GetWebUIStartupURL()) {
         whats_new::StartWhatsNewFetch(browser);
         continue;
