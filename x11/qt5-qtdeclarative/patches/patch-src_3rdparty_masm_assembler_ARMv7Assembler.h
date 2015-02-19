$NetBSD: patch-src_3rdparty_masm_assembler_ARMv7Assembler.h,v 1.1 2015/02/19 22:29:18 joerg Exp $

--- src/3rdparty/masm/assembler/ARMv7Assembler.h.orig	2015-02-19 16:26:13.000000000 +0000
+++ src/3rdparty/masm/assembler/ARMv7Assembler.h
@@ -2311,6 +2311,8 @@ public:
         UNUSED_PARAM(code);
         UNUSED_PARAM(size);
 #endif
+#elif defined(__GNUC__)
+        __builtin___clear_cache(reinterpret_cast<char *>(code), reinterpret_cast<char *>(reinterpret_cast<uintptr_t>(code) + size));
 #else
 #error "The cacheFlush support is missing on this platform."
 #endif
