$NetBSD: patch-include_servermd.h,v 1.1 2024/07/22 02:01:18 nat Exp $

Fix arm build.
--- include/servermd.h.orig	2024-07-22 01:47:46.337865363 +0000
+++ include/servermd.h
@@ -326,7 +326,7 @@ SOFTWARE.
 
 
 /* linux on the Compaq Itsy */
-#if defined(linux) && defined(__arm__)
+#if defined(__arm__)
 #define IMAGE_BYTE_ORDER	LSBFirst
 #define BITMAP_BIT_ORDER	LSBFirst
 #define GLYPHPADBYTES		4
