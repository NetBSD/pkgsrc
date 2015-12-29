$NetBSD: patch-src_engine_zoom.c,v 1.2 2015/12/29 23:50:14 dholland Exp $

Fix compilation on NetBSD 7 on i386.

--- src/engine/zoom.c.orig	2015-11-01 20:40:43.000000000 -0800
+++ src/engine/zoom.c	2015-11-01 20:41:31.000000000 -0800
@@ -138,13 +138,11 @@
 #endif
 
 #ifndef USE_i386ASM
-static void
-moveoldpoints(void *data1, struct taskinfo *task, int r1, int r2)
-REGISTERS(0);
-static void fillline_8(int line) REGISTERS(0);
-static void fillline_16(int line) REGISTERS(0);
-static void fillline_24(int line) REGISTERS(0);
-static void fillline_32(int line) REGISTERS(0);
+static void moveoldpoints(void *data1, struct taskinfo *task, int r1, int r2);
+static INLINE void fillline_8(int line);
+static INLINE void fillline_16(int line);
+static INLINE void fillline_24(int line);
+static INLINE void fillline_32(int line);
 #endif
 
 /*first of all inline driver section */
