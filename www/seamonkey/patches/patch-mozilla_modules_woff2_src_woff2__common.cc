$NetBSD: patch-mozilla_modules_woff2_src_woff2__common.cc,v 1.1 2017/08/18 23:55:07 ryoon Exp $

--- mozilla/modules/woff2/src/woff2_common.cc.orig	2017-07-07 05:37:53.000000000 +0000
+++ mozilla/modules/woff2/src/woff2_common.cc
@@ -25,12 +25,13 @@ uint32_t ComputeULongSum(const uint8_t* 
   uint32_t checksum = 0;
   size_t aligned_size = size & ~3;
   for (size_t i = 0; i < aligned_size; i += 4) {
+    uint32_t v;
+    memcpy(&v, buf + i, 4);
 #if (defined(__BYTE_ORDER__) && (__BYTE_ORDER__ == __ORDER_LITTLE_ENDIAN__))
-    uint32_t v = *reinterpret_cast<const uint32_t*>(buf + i);
     checksum += (((v & 0xFF) << 24) | ((v & 0xFF00) << 8) |
       ((v & 0xFF0000) >> 8) | ((v & 0xFF000000) >> 24));
 #elif (defined(__BYTE_ORDER__) && (__BYTE_ORDER__ == __ORDER_BIG_ENDIAN__))
-    checksum += *reinterpret_cast<const uint32_t*>(buf + i);
+    checksum += v;
 #else
     checksum += (buf[i] << 24) | (buf[i + 1] << 16) |
       (buf[i + 2] << 8) | buf[i + 3];
