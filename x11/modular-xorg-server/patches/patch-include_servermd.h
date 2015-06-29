$NetBSD: patch-include_servermd.h,v 1.2 2015/06/29 11:12:45 wiz Exp $

Try to fix broken X_BYTE_ORDER handling for big endian.
Probably broken here:
http://cgit.freedesktop.org/xorg/xserver/commit/?id=4302484ef2e67b2e05756c7ee0834dce938f1b44

--- include/servermd.h.orig	2015-06-16 15:21:07.000000000 +0000
+++ include/servermd.h
@@ -54,10 +54,16 @@ SOFTWARE.
 
 #include <X11/Xarch.h>		/* for X_LITTLE_ENDIAN/X_BIG_ENDIAN */
 
-#if X_BYTE_ORDER == X_LITTLE_ENDIAN
+#ifndef X_LITTLE_ENDIAN
+#define X_LITTLE_ENDIAN 1234
+#endif
+#ifndef X_BIG_ENDIAN
+#define X_BIG_ENDIAN 4321
+#endif
+#if X_BYTE_ORDER == X_LITTLE_ENDIAN && defined(X_LITTLE_ENDIAN)
 #define IMAGE_BYTE_ORDER        LSBFirst
 #define BITMAP_BIT_ORDER        LSBFirst
-#elif X_BYTE_ORDER == X_BIG_ENDIAN
+#elif X_BYTE_ORDER == X_BIG_ENDIAN && defined(X_BIG_ENDIAN)
 #define IMAGE_BYTE_ORDER        MSBFirst
 #define BITMAP_BIT_ORDER        MSBFirst
 #else
