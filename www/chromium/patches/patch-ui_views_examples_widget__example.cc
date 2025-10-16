$NetBSD: patch-ui_views_examples_widget__example.cc,v 1.8 2025/10/16 19:43:38 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- ui/views/examples/widget_example.cc.orig	2025-10-13 21:41:26.000000000 +0000
+++ ui/views/examples/widget_example.cc
@@ -51,7 +51,7 @@ void WidgetExample::CreateExampleView(Vi
   modal_button->SetCallback(
       base::BindRepeating(&WidgetExample::CreateDialogWidget,
                           base::Unretained(this), modal_button, true));
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   // Windows does not support TYPE_CONTROL top-level widgets.
   LabelButton* control_button = BuildButton(
       container, GetStringUTF16(IDS_WIDGET_CHILD_WIDGET_BUTTON_LABEL));
