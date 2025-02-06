$NetBSD: patch-ui_gtk_gtk__compat.cc,v 1.1 2025/02/06 09:58:33 wiz Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- ui/gtk/gtk_compat.cc.orig	2024-12-17 17:58:49.000000000 +0000
+++ ui/gtk/gtk_compat.cc
@@ -62,27 +62,47 @@ auto DlCast(void* symbol) {
 }
 
 void* GetLibGio() {
+#if BUILDFLAG(IS_BSD)
+  static void* libgio = DlOpen("libgio-2.0.so");
+#else
   static void* libgio = DlOpen("libgio-2.0.so.0");
+#endif
   return libgio;
 }
 
 void* GetLibGdkPixbuf() {
+#if BUILDFLAG(IS_BSD)
+  static void* libgdk_pixbuf = DlOpen("libgdk_pixbuf-2.0.so");
+#else
   static void* libgdk_pixbuf = DlOpen("libgdk_pixbuf-2.0.so.0");
+#endif
   return libgdk_pixbuf;
 }
 
 void* GetLibGdk3() {
+#if BUILDFLAG(IS_BSD)
+  static void* libgdk3 = DlOpen("libgdk-3.so");
+#else
   static void* libgdk3 = DlOpen("libgdk-3.so.0");
+#endif
   return libgdk3;
 }
 
 void* GetLibGtk3(bool check = true) {
+#if BUILDFLAG(IS_BSD)
+  static void* libgtk3 = DlOpen("libgtk-3.so", check);
+#else
   static void* libgtk3 = DlOpen("libgtk-3.so.0", check);
+#endif
   return libgtk3;
 }
 
 void* GetLibGtk4(bool check = true) {
+#if BUILDFLAG(IS_BSD)
+  static void* libgtk4 = DlOpen("libgtk-4.so", check);
+#else
   static void* libgtk4 = DlOpen("libgtk-4.so.1", check);
+#endif
   return libgtk4;
 }
 
