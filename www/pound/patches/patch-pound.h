$NetBSD: patch-pound.h,v 1.1 2019/09/09 09:08:08 nia Exp $

[PATCH] Support for Openssl 1.1
https://github.com/graygnuorg/pound/commit/a2c9dde4d055ea8942afb150b7fc3a807d4e5d60.patch

--- pound.h.orig	2018-05-11 10:16:05.000000000 +0000
+++ pound.h
@@ -344,7 +344,9 @@ typedef struct _tn {
 /* maximal session key size */
 #define KEY_SIZE    127
 
-#if OPENSSL_VERSION_NUMBER >= 0x10000000L
+#if OPENSSL_VERSION_NUMBER >= 0x10100000L
+  DEFINE_LHASH_OF(TABNODE);
+#elif OPENSSL_VERSION_NUMBER >= 0x10000000L
 DECLARE_LHASH_OF(TABNODE);
 #endif
 
