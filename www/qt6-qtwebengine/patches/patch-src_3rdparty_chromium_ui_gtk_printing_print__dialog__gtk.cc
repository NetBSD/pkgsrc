$NetBSD: patch-src_3rdparty_chromium_ui_gtk_printing_print__dialog__gtk.cc,v 1.1 2025/12/21 09:38:48 markd Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- src/3rdparty/chromium/ui/gtk/printing/print_dialog_gtk.cc.orig	2025-05-29 01:27:28.000000000 +0000
+++ src/3rdparty/chromium/ui/gtk/printing/print_dialog_gtk.cc
@@ -439,7 +439,7 @@ void PrintDialogGtk::ShowDialog(
   GtkPrintCapabilities cap = static_cast<GtkPrintCapabilities>(
       GTK_PRINT_CAPABILITY_GENERATE_PDF | GTK_PRINT_CAPABILITY_PAGE_SET |
       GTK_PRINT_CAPABILITY_COPIES | GTK_PRINT_CAPABILITY_COLLATE |
-      GTK_PRINT_CAPABILITY_REVERSE);
+      GTK_PRINT_CAPABILITY_REVERSE | GTK_PRINT_CAPABILITY_GENERATE_PS);
   gtk_print_unix_dialog_set_manual_capabilities(
       GTK_PRINT_UNIX_DIALOG(dialog_.get()), cap);
   gtk_print_unix_dialog_set_embed_page_setup(
