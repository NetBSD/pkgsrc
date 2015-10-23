$NetBSD: patch-src_lbx__zlib_lbx__zlib.h,v 1.1 2015/10/23 09:53:35 tnn Exp $

--- src/lbx_zlib/lbx_zlib.h.orig	2009-11-03 05:52:21.000000000 +0000
+++ src/lbx_zlib/lbx_zlib.h
@@ -129,16 +129,17 @@ extern int FlushIovBuf ( int fd, struct 
 #define _HAVE_XALLOC_DECLS
 #include <X11/Xdefs.h>
 
-extern pointer Xalloc(unsigned long /*amount*/);
-extern pointer Xcalloc(unsigned long /*amount*/);
-extern pointer Xrealloc(pointer /*ptr*/, unsigned long /*amount*/);
-extern void Xfree(pointer /*ptr*/);
+#include <stdlib.h>
+#define Xalloc malloc
+#define Xcalloc calloc
+#define Xrealloc realloc
+#define Xfree free
 #endif
 
 /* lbx_zlib.c */
-unsigned long stream_out_compressed;
-unsigned long stream_out_uncompressed;
-unsigned long stream_out_plain;
-unsigned long stream_in_compressed;
-unsigned long stream_in_uncompressed;
-unsigned long stream_in_plain;
+extern unsigned long stream_out_compressed;
+extern unsigned long stream_out_uncompressed;
+extern unsigned long stream_out_plain;
+extern unsigned long stream_in_compressed;
+extern unsigned long stream_in_uncompressed;
+extern unsigned long stream_in_plain;
