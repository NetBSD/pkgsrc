$NetBSD: patch-ui_gtk_select__file__dialog__linux__gtk.cc,v 1.9 2026/09/02 13:13:39 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- ui/gtk/select_file_dialog_linux_gtk.cc.orig	2026-08-31 22:47:51.000000000 +0000
+++ ui/gtk/select_file_dialog_linux_gtk.cc
@@ -57,7 +57,8 @@ namespace {
 // GTK_RESPONSE_ACCEPT as the default button, which should be avoided to prevent
 // an exploit where the user is instructed to hold Enter before the dialog
 // appears.
-constexpr GtkResponseType kResponseTypeAccept = static_cast<GtkResponseType>(0);
+// My god ^^^^^ WTF
+constexpr GtkResponseType kResponseTypeAccept = static_cast<GtkResponseType>(GTK_RESPONSE_ACCEPT);
 
 // TODO(crbug.com/41469294): These getters will be unnecessary after
 // migrating to GtkFileChooserNative.
