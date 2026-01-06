$NetBSD: patch-media_ffvpx_libavcodec_x86_mathops.h,v 1.1 2026/01/06 15:15:46 ryoon Exp $

* From 128 to fix build under NetBSD/amd64 11.99.4.

--- media/ffvpx/libavcodec/x86/mathops.h.orig	2026-01-06 09:12:28.479025029 +0000
+++ media/ffvpx/libavcodec/x86/mathops.h
@@ -113,19 +113,31 @@ static inline  int32_t NEG_SSR32( int32_t a, int8_t s)
 // avoid +32 for shift optimization (gcc should do that ...)
 #define NEG_SSR32 NEG_SSR32
 static inline  int32_t NEG_SSR32( int32_t a, int8_t s){
+    if (__builtin_constant_p(s))
     __asm__ ("sarl %1, %0\n\t"
          : "+r" (a)
-         : "ic" ((uint8_t)(-s))
+         : "i" (-s & 0x1F)
     );
+    else
+        __asm__ ("sarl %1, %0\n\t"
+               : "+r" (a)
+               : "c" ((uint8_t)(-s))
+        );
     return a;
 }
 
 #define NEG_USR32 NEG_USR32
 static inline uint32_t NEG_USR32(uint32_t a, int8_t s){
+    if (__builtin_constant_p(s))
     __asm__ ("shrl %1, %0\n\t"
          : "+r" (a)
-         : "ic" ((uint8_t)(-s))
+         : "i" (-s & 0x1F)
     );
+    else
+        __asm__ ("shrl %1, %0\n\t"
+               : "+r" (a)
+               : "c" ((uint8_t)(-s))
+        );
     return a;
 }
 
