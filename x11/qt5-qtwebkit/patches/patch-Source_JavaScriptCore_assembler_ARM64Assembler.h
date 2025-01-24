$NetBSD: patch-Source_JavaScriptCore_assembler_ARM64Assembler.h,v 1.4 2025/01/24 11:54:37 wiz Exp $

Find a valid clear cache for Darwin/arm64 and NetBSD/arm64.

--- Source/JavaScriptCore/assembler/ARM64Assembler.h.orig	2020-03-04 17:16:37.000000000 +0000
+++ Source/JavaScriptCore/assembler/ARM64Assembler.h
@@ -34,6 +34,9 @@
 #include <wtf/Assertions.h>
 #include <wtf/Vector.h>
 #include <stdint.h>
+#if OS(IOS) || OS(MAC_OS_X)
+#include <libkern/OSCacheControl.h>
+#endif
 
 #define CHECK_DATASIZE_OF(datasize) ASSERT(datasize == 32 || datasize == 64)
 #define DATASIZE_OF(datasize) ((datasize == 64) ? Datasize_64 : Datasize_32)
@@ -2664,8 +2667,10 @@ public:
 
     static void cacheFlush(void* code, size_t size)
     {
-#if OS(IOS)
+#if OS(IOS) || OS(MAC_OS_X)
         sys_cache_control(kCacheFunctionPrepareForExecution, code, size);
+#elif OS(NETBSD)
+	__builtin___clear_cache(code, reinterpret_cast<char*>(code) + size);
 #elif OS(LINUX)
         size_t page = pageSize();
         uintptr_t current = reinterpret_cast<uintptr_t>(code);
