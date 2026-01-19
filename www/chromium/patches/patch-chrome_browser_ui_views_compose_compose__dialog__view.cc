$NetBSD: patch-chrome_browser_ui_views_compose_compose__dialog__view.cc,v 1.14 2026/01/19 16:14:10 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/ui/views/compose/compose_dialog_view.cc.orig	2026-01-07 00:50:30.000000000 +0000
+++ chrome/browser/ui/views/compose/compose_dialog_view.cc
@@ -160,7 +160,7 @@ void ComposeDialogView::OnBeforeBubbleWi
     views::Widget::InitParams* params,
     views::Widget* widget) const {
   WebUIBubbleDialogView::OnBeforeBubbleWidgetInit(params, widget);
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // In linux, windows may be clipped to their anchors' bounds,
   // resulting in visual errors, unless they use accelerated rendering. See
   // crbug.com/1445770 for details.
