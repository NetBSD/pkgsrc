$NetBSD: patch-include_servermd.h,v 1.1 2015/04/25 11:47:03 tnn Exp $

Try to fix broken X_BYTE_ORDER handling for big endian.
Probably broken here:
http://cgit.freedesktop.org/xorg/xserver/commit/?id=4302484ef2e67b2e05756c7ee0834dce938f1b44

--- include/servermd.h.orig	2015-01-17 23:42:52.000000000 +0000
+++ include/servermd.h
@@ -52,10 +52,16 @@ SOFTWARE.
 #error xserver code must include dix-config.h before any other headers
 #endif
 
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
