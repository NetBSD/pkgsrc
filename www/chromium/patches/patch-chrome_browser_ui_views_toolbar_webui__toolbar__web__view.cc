$NetBSD: patch-chrome_browser_ui_views_toolbar_webui__toolbar__web__view.cc,v 1.2 2026/10/16 15:30:48 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/ui/views/toolbar/webui_toolbar_web_view.cc.orig	2026-10-14 21:09:54.000000000 +0000
+++ chrome/browser/ui/views/toolbar/webui_toolbar_web_view.cc
@@ -571,7 +571,7 @@ void WebUIToolbarWebView::AddedToWidget(
     if (features::IsWebUIExtensionsContainerEnabled()) {
       extensions_container_.Init(web_contents());
     }
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     if (features::IsWebUIMediaButtonEnabled()) {
       media_control_.Init();
     }
@@ -977,7 +977,7 @@ WebUIToolbarWebView::GetAvatarToolbarBut
 }
 
 MediaToolbarButton* WebUIToolbarWebView::GetMediaToolbarButton() {
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   if (features::IsWebUIMediaButtonEnabled()) {
     return &media_control_;
   }
@@ -1775,7 +1775,7 @@ gfx::Size WebUIToolbarWebView::ComputeLa
   button_count += features::IsWebUIPerformanceInterventionButtonEnabled() &&
                   performance_intervention_control_.IsButtonShowing();
   button_count += features::IsWebUIAppMenuButtonEnabled();
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   button_count +=
       features::IsWebUIMediaButtonEnabled() && media_control_.IsButtonShowing();
 #endif
