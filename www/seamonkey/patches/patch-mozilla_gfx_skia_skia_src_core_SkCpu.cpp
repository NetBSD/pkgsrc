$NetBSD: patch-mozilla_gfx_skia_skia_src_core_SkCpu.cpp,v 1.2 2021/02/08 12:26:20 ryoon Exp $

NetBSD/aarch64 doesn't have <sys/auxv.h>.

--- gfx/skia/skia/src/core/SkCpu.cpp.orig	2020-02-17 23:37:51.000000000 +0000
+++ gfx/skia/skia/src/core/SkCpu.cpp
@@ -74,7 +74,7 @@
         return features;
     }
 
-#elif defined(SK_CPU_ARM64) && __has_include(<sys/auxv.h>)
+#elif defined(SK_CPU_ARM64) && __has_include(<sys/auxv.h>) && !defined(__NetBSD__)
     #include <sys/auxv.h>
 
     static uint32_t read_cpu_features() {
