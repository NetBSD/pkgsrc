$NetBSD: patch-ui_gtk_printing_print__dialog__gtk.cc,v 1.14 2026/01/19 16:14:23 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- ui/gtk/printing/print_dialog_gtk.cc.orig	2026-01-07 00:50:30.000000000 +0000
+++ ui/gtk/printing/print_dialog_gtk.cc
@@ -442,7 +442,7 @@ void PrintDialogGtk::ShowDialog(
   GtkPrintCapabilities cap = static_cast<GtkPrintCapabilities>(
       GTK_PRINT_CAPABILITY_GENERATE_PDF | GTK_PRINT_CAPABILITY_PAGE_SET |
       GTK_PRINT_CAPABILITY_COPIES | GTK_PRINT_CAPABILITY_COLLATE |
-      GTK_PRINT_CAPABILITY_REVERSE);
+      GTK_PRINT_CAPABILITY_REVERSE | GTK_PRINT_CAPABILITY_GENERATE_PS);
   gtk_print_unix_dialog_set_manual_capabilities(
       GTK_PRINT_UNIX_DIALOG(dialog_.get()), cap);
   gtk_print_unix_dialog_set_embed_page_setup(
