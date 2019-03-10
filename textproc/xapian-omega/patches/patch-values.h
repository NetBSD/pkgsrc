$NetBSD: patch-values.h,v 1.1 2019/03/10 13:21:05 schmonz Exp $

Avoid conflicting with system bswap32().

--- values.h.orig	2019-03-02 01:45:31.000000000 +0000
+++ values.h
@@ -38,7 +38,7 @@ enum value_slot {
 };
 
 #ifndef WORDS_BIGENDIAN
-inline std::uint32_t bswap32(std::uint32_t v) {
+inline std::uint32_t xapian_bswap32(std::uint32_t v) {
 # if HAVE_DECL___BUILTIN_BSWAP32
     return __builtin_bswap32(v);
 # elif HAVE_DECL__BYTESWAP_ULONG
@@ -55,7 +55,7 @@ inline std::uint32_t binary_string_to_in
     std::uint32_t v;
     std::memcpy(&v, s.data(), 4);
 #ifndef WORDS_BIGENDIAN
-    v = bswap32(v);
+    v = xapian_bswap32(v);
 #endif
     return v;
 }
@@ -63,7 +63,7 @@ inline std::uint32_t binary_string_to_in
 inline std::string int_to_binary_string(std::uint32_t v)
 {
 #ifndef WORDS_BIGENDIAN
-    v = bswap32(v);
+    v = xapian_bswap32(v);
 #endif
     return std::string(reinterpret_cast<const char*>(&v), 4);
 }
