$NetBSD: patch-ffmpeg_libavcodec_bitstream.h,v 1.1 2026/06/14 10:12:56 nia Exp $

Fix build with recent GNU toolchains.

--- ffmpeg/libavcodec/bitstream.h.orig	2026-06-14 10:05:08.928376357 +0000
+++ ffmpeg/libavcodec/bitstream.h
@@ -53,26 +53,8 @@ extern const uint8_t ff_reverse[256];
 
 extern const uint8_t ff_reverse[256];
 
-#if defined(ARCH_X86)
-// avoid +32 for shift optimization (gcc should do that ...)
-static inline  int32_t NEG_SSR32( int32_t a, int8_t s){
-    asm ("sarl %1, %0\n\t"
-         : "+r" (a)
-         : "ic" ((uint8_t)(-s))
-    );
-    return a;
-}
-static inline uint32_t NEG_USR32(uint32_t a, int8_t s){
-    asm ("shrl %1, %0\n\t"
-         : "+r" (a)
-         : "ic" ((uint8_t)(-s))
-    );
-    return a;
-}
-#else
-#    define NEG_SSR32(a,s) ((( int32_t)(a))>>(32-(s)))
-#    define NEG_USR32(a,s) (((uint32_t)(a))>>(32-(s)))
-#endif
+#define NEG_SSR32(a,s) ((( int32_t)(a))>>(32-(s)))
+#define NEG_USR32(a,s) (((uint32_t)(a))>>(32-(s)))
 
 /* bit output */
 
