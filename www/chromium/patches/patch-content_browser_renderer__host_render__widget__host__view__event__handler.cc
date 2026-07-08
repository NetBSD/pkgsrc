$NetBSD: patch-content_browser_renderer__host_render__widget__host__view__event__handler.cc,v 1.23 2026/07/08 13:42:24 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- content/browser/renderer_host/render_widget_host_view_event_handler.cc.orig	2026-07-06 22:58:46.000000000 +0000
+++ content/browser/renderer_host/render_widget_host_view_event_handler.cc
@@ -617,7 +617,7 @@ bool RenderWidgetHostViewEventHandler::C
   if (event->type() == ui::EventType::kMouseExited) {
     if (mouse_locked || selection_popup)
       return false;
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
     // Don't forward the mouse leave message which is received when the context
     // menu is displayed by the page. This confuses the page and causes state
     // changes.
