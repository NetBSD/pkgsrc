$NetBSD: patch-src_nxt__router.c,v 1.1 2021/02/14 11:56:57 otis Exp $

Silence warning.

This patch is going to be reviewed by the vendor.

--- src/nxt_router.c.orig	2020-10-08 16:04:40.000000000 +0000
+++ src/nxt_router.c
@@ -3692,7 +3692,7 @@ nxt_router_thread_exit_handler(nxt_task_
     nxt_event_engine_t   *engine;
     nxt_thread_handle_t  handle;
 
-    handle = (nxt_thread_handle_t) obj;
+    handle = (nxt_thread_handle_t)(uintptr_t) obj;
     link = data;
 
     nxt_thread_wait(handle);
