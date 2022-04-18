$NetBSD: patch-src_3rdparty_chromium_ui_views_examples_widget__example.cc,v 1.2 2022/04/18 11:18:19 adam Exp $

--- src/3rdparty/chromium/ui/views/examples/widget_example.cc.orig	2021-02-19 16:41:59.000000000 +0000
+++ src/3rdparty/chromium/ui/views/examples/widget_example.cc
@@ -67,7 +67,7 @@ void WidgetExample::CreateExampleView(Vi
               DIALOG);
   BuildButton(container, GetStringUTF16(IDS_WIDGET_MODAL_BUTTON_LABEL),
               MODAL_DIALOG);
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
   // Windows does not support TYPE_CONTROL top-level widgets.
   BuildButton(container, GetStringUTF16(IDS_WIDGET_CHILD_WIDGET_BUTTON_LABEL),
               CHILD);
