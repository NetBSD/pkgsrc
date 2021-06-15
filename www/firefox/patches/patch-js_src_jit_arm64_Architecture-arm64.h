$NetBSD: patch-js_src_jit_arm64_Architecture-arm64.h,v 1.1 2021/06/15 13:54:20 bsiegert Exp $

Fix build on aarch64; MOZ_CRASH cannot be in a constexpr function.

--- js/src/jit/arm64/Architecture-arm64.h.orig	2021-05-04 18:59:04.000000000 +0000
+++ js/src/jit/arm64/Architecture-arm64.h
@@ -580,7 +580,7 @@ struct FloatRegister {
     MOZ_ASSERT(kind_ == FloatRegisters::Simd128);
     return 16;
 #else
-    MOZ_CRASH("No SIMD support");
+    return 16;
 #endif
   }
 
