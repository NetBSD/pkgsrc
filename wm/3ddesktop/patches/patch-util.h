$NetBSD: patch-util.h,v 1.1 2012/03/02 14:57:08 hans Exp $

--- util.h.orig	2005-06-20 13:06:50.000000000 +0200
+++ util.h	2012-03-02 15:48:57.476209637 +0100
@@ -24,6 +24,11 @@
 #include <sys/param.h> // BSD 
 #ifdef BSD
 #include <sys/endian.h>
+#elif defined(__sun)
+#include <sys/byteorder.h>
+#ifdef _BIG_ENDIAN
+#define __BIG_ENDIAN__
+#endif
 #else
 #include <endian.h>
 #endif
