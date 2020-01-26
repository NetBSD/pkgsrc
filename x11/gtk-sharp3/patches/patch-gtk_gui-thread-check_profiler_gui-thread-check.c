$NetBSD: patch-gtk_gui-thread-check_profiler_gui-thread-check.c,v 1.1 2020/01/26 13:45:11 nia Exp $

Fix build with newer Mono versions.

--- gtk/gui-thread-check/profiler/gui-thread-check.c.orig	2014-06-05 15:06:30.000000000 +0000
+++ gtk/gui-thread-check/profiler/gui-thread-check.c
@@ -93,6 +93,5 @@ mono_profiler_startup (const char *desc)
 	
 	mono_profiler_install (NULL, NULL);
 	mono_profiler_install_enter_leave (simple_method_enter, NULL);
-	mono_profiler_set_events (MONO_PROFILE_ENTER_LEAVE);
 }
 
