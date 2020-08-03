$NetBSD: patch-Source_JavaScriptCore_assembler_ARM64Assembler.h,v 1.2 2020/08/03 08:36:23 jmcneill Exp $

--- Source/JavaScriptCore/assembler/ARM64Assembler.h.orig	2016-04-10 06:48:36.000000000 +0000
+++ Source/JavaScriptCore/assembler/ARM64Assembler.h
@@ -32,6 +32,7 @@
 #include <wtf/Assertions.h>
 #include <wtf/Vector.h>
 #include <stdint.h>
+#include <limits.h>
 
 #define CHECK_DATASIZE_OF(datasize) ASSERT(datasize == 32 || datasize == 64)
 #define DATASIZE_OF(datasize) ((datasize == 64) ? Datasize_64 : Datasize_32)
@@ -2756,6 +2757,9 @@ public:
     {
 #if OS(IOS)
         sys_cache_control(kCacheFunctionPrepareForExecution, code, size);
+#elif OS(NETBSD)
+        char* begin = reinterpret_cast<char*>(code);
+        __builtin___clear_cache(begin, begin + size);
 #else
 #error "The cacheFlush support is missing on this platform."
 #endif
