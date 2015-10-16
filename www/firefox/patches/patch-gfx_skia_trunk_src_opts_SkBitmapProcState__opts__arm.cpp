$NetBSD: patch-gfx_skia_trunk_src_opts_SkBitmapProcState__opts__arm.cpp,v 1.1 2015/10/16 12:59:36 jmcneill Exp $

--- gfx/skia/trunk/src/opts/SkBitmapProcState_opts_arm.cpp.orig	2015-09-29 21:44:50.000000000 +0000
+++ gfx/skia/trunk/src/opts/SkBitmapProcState_opts_arm.cpp
@@ -97,7 +97,11 @@ void SI8_D16_nofilter_DX_arm(const SkBit
             "2:                                        \n\t"
             : [xx] "+r" (xx), [count8] "+r" (count8), [colors] "+r" (colors)
             : [table] "r" (table), [srcAddr] "r" (srcAddr)
+#if defined(__NetBSD__)
+            : "memory", "cc", "r4", "r5", "r6", "r7", "r8", "r9", "r10"
+#else
             : "memory", "cc", "r4", "r5", "r6", "r7", "r8", "r9", "r10", "r11"
+#endif
         );
 
         for (i = (count & 7); i > 0; --i) {
@@ -181,7 +185,11 @@ void SI8_opaque_D32_nofilter_DX_arm(cons
             "4:                                       \n\t"   // exit
             : [xx] "+r" (xx), [count] "+r" (count), [colors] "+r" (colors)
             : [table] "r" (table), [srcAddr] "r" (srcAddr)
+#if defined(__NetBSD__)
+            : "memory", "cc", "r4", "r5", "r6", "r7", "r8", "r9", "r10"
+#else
             : "memory", "cc", "r4", "r5", "r6", "r7", "r8", "r9", "r10", "r11"
+#endif
         );
     }
 
