$NetBSD: patch-src_3rdparty_masm_assembler_ARMAssembler.h,v 1.1 2015/02/19 22:29:18 joerg Exp $

--- src/3rdparty/masm/assembler/ARMAssembler.h.orig	2015-02-19 16:29:13.000000000 +0000
+++ src/3rdparty/masm/assembler/ARMAssembler.h
@@ -1069,6 +1069,8 @@ namespace JSC {
             UNUSED_PARAM(size);
 #elif OS(QNX)
             msync(code, size, MS_INVALIDATE_ICACHE);
+#elif defined(__GNUC__)
+        __builtin___clear_cache(reinterpret_cast<char *>(code), reinterpret_cast<char *>(reinterpret_cast<uintptr_t>(code) + size));
 #else
 #error "The cacheFlush support is missing on this platform."
 #endif
