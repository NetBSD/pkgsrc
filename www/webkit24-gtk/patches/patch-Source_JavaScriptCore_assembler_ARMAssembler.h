$NetBSD: patch-Source_JavaScriptCore_assembler_ARMAssembler.h,v 1.1 2015/07/12 00:37:47 wiz Exp $

--- Source/JavaScriptCore/assembler/ARMAssembler.h.orig	2014-10-21 08:06:38.000000000 +0000
+++ Source/JavaScriptCore/assembler/ARMAssembler.h
@@ -1121,6 +1121,9 @@ namespace JSC {
             linuxPageFlush(current, end);
 #elif OS(WINCE)
             CacheRangeFlush(code, size, CACHE_SYNC_ALL);
+#elif OS(NETBSD)
+            char* begin = reinterpret_cast<char*>(code);
+            __builtin___clear_cache(begin, begin + size);
 #else
 #error "The cacheFlush support is missing on this platform."
 #endif
