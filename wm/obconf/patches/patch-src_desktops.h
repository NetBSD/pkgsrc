$NetBSD: patch-src_desktops.h,v 1.1 2026/08/17 16:37:58 ryoon Exp $

* Fix build with GCC 14.

--- src/desktops.h.orig	2026-08-17 16:31:31.509090721 +0000
+++ src/desktops.h
@@ -24,5 +24,6 @@ void desktops_setup_names(GtkWidget *w);
 
 void desktops_setup_num(GtkWidget *w);
 void desktops_setup_names(GtkWidget *w);
+void desktops_setup_tab();
 
 #endif
