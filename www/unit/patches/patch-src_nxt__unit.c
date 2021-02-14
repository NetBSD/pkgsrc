$NetBSD: patch-src_nxt__unit.c,v 1.1 2021/02/14 11:56:57 otis Exp $

Use more apropriate format specifier for shm prefix.

This patch is going to be reviewed by the vendor.

--- src/nxt_unit.c.orig	2020-11-19 18:12:30.000000000 +0000
+++ src/nxt_unit.c
@@ -3762,8 +3762,8 @@ nxt_unit_shm_open(nxt_unit_ctx_t *ctx, s
 #if (NXT_HAVE_MEMFD_CREATE || NXT_HAVE_SHM_OPEN)
     char             name[64];
 
-    snprintf(name, sizeof(name), NXT_SHM_PREFIX "unit.%d.%p",
-             lib->pid, (void *) pthread_self());
+    snprintf(name, sizeof(name), NXT_SHM_PREFIX "unit.%d.%p",
+             lib->pid, (void *) (uintptr_t)pthread_self());
 #endif
 
 #if (NXT_HAVE_MEMFD_CREATE)
