$NetBSD: patch-src_main.c,v 1.1 2021/06/03 15:11:05 cirnatdan Exp $

Disable gjs stack dumps?

--- src/main.c.orig	2021-03-20 12:17:01.570519000 +0000
+++ src/main.c
@@ -352,6 +352,7 @@ dump_gjs_stack_on_signal_handler (int si
 static void
 dump_gjs_stack_on_signal (int signo)
 {
+#if 0
   struct sigaction sa = {
     .sa_flags   = SA_RESETHAND | SA_NODEFER,
     .sa_handler = dump_gjs_stack_on_signal_handler,
@@ -361,6 +362,7 @@ dump_gjs_stack_on_signal (int signo)
 
   sigaction (signo, &sa, NULL);
   _tracked_signals[signo] = TRUE;
+#endif
 }
 
 static gboolean
