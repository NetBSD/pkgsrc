$NetBSD: patch-src_delta_lbxdelta.c,v 1.1 2015/10/23 09:53:35 tnn Exp $

--- src/delta/lbxdelta.c.orig	2009-12-04 22:42:12.000000000 +0000
+++ src/delta/lbxdelta.c
@@ -47,12 +47,12 @@ extern struct ReqStats LbxRequestStats[L
 /* Copied from xc/programs/Xserver/include/xorg/os.h */
 #ifndef _HAVE_XALLOC_DECLS
 #define _HAVE_XALLOC_DECLS
-#include <X11/Xdefs.h>
 
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
 
 /*
