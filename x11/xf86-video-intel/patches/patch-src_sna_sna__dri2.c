$NetBSD: patch-src_sna_sna__dri2.c,v 1.1 2015/03/03 01:02:05 khorben Exp $

--- src/sna/sna_dri2.c.orig	2014-12-20 12:46:23.000000000 +0000
+++ src/sna/sna_dri2.c
@@ -247,6 +247,7 @@ inline static void *dri2_window_get_fron
 
 #define xorg_can_triple_buffer() 0
 #define swap_limit(d, l) false
+#define mark_stale(b)
 
 #else
 
