$NetBSD: patch-mozilla_modules_woff2_src_store__bytes.h,v 1.1 2017/08/18 23:55:07 ryoon Exp $

--- mozilla/modules/woff2/src/store_bytes.h.orig	2017-07-07 05:37:30.000000000 +0000
+++ mozilla/modules/woff2/src/store_bytes.h
@@ -34,10 +34,11 @@ inline size_t StoreU32(uint8_t* dst, siz
 
 inline size_t Store16(uint8_t* dst, size_t offset, int x) {
 #if (defined(__BYTE_ORDER__) && (__BYTE_ORDER__ == __ORDER_LITTLE_ENDIAN__))
-  *reinterpret_cast<uint16_t*>(dst + offset) =
-      ((x & 0xFF) << 8) | ((x & 0xFF00) >> 8);
+  uint16_t v = ((x & 0xFF) << 8) | ((x & 0xFF00) >> 8);
+  memcpy(dst + offset, &v, 2);
 #elif (defined(__BYTE_ORDER__) && (__BYTE_ORDER__ == __ORDER_BIG_ENDIAN__))
-  *reinterpret_cast<uint16_t*>(dst + offset) = static_cast<uint16_t>(x);
+  uint16_t v = static_cast<uint16_t>(x);
+  memcpy(dst + offset, &v, 2);
 #else
   dst[offset] = x >> 8;
   dst[offset + 1] = x;
@@ -54,11 +55,13 @@ inline void StoreU32(uint32_t val, size_
 
 inline void Store16(int val, size_t* offset, uint8_t* dst) {
 #if (defined(__BYTE_ORDER__) && (__BYTE_ORDER__ == __ORDER_LITTLE_ENDIAN__))
-  *reinterpret_cast<uint16_t*>(dst + *offset) =
+  uint16_t v = ((val & 0xFF) << 8) | ((val & 0xFF00) >> 8);
+  memcpy(dst + *offset, &v, 2);
       ((val & 0xFF) << 8) | ((val & 0xFF00) >> 8);
   *offset += 2;
 #elif (defined(__BYTE_ORDER__) && (__BYTE_ORDER__ == __ORDER_BIG_ENDIAN__))
-  *reinterpret_cast<uint16_t*>(dst + *offset) = static_cast<uint16_t>(val);
+  uint16_t v = static_cast<uint16_t>(val);
+  memcpy(dst + *offset, &v, 2);
   *offset += 2;
 #else
   dst[(*offset)++] = val >> 8;
