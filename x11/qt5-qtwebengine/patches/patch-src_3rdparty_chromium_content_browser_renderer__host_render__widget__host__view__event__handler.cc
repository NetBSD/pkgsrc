$NetBSD: patch-src_3rdparty_chromium_content_browser_renderer__host_render__widget__host__view__event__handler.cc,v 1.1 2021/08/03 21:04:35 markd Exp $

--- src/3rdparty/chromium/content/browser/renderer_host/render_widget_host_view_event_handler.cc.orig	2020-07-08 21:41:48.000000000 +0000
+++ src/3rdparty/chromium/content/browser/renderer_host/render_widget_host_view_event_handler.cc
@@ -653,7 +653,7 @@ bool RenderWidgetHostViewEventHandler::C
   if (event->type() == ui::ET_MOUSE_EXITED) {
     if (mouse_locked || selection_popup)
       return false;
-#if defined(OS_WIN) || defined(OS_LINUX)
+#if defined(OS_WIN) || defined(OS_LINUX) || defined(OS_BSD)
     // Don't forward the mouse leave message which is received when the context
     // menu is displayed by the page. This confuses the page and causes state
     // changes.
