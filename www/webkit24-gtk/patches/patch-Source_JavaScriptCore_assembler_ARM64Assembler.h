$NetBSD: patch-Source_JavaScriptCore_assembler_ARM64Assembler.h,v 1.1 2020/08/02 17:41:41 jmcneill Exp $

--- Source/JavaScriptCore/assembler/ARM64Assembler.h.orig	2016-04-10 06:48:36.000000000 +0000
+++ Source/JavaScriptCore/assembler/ARM64Assembler.h
@@ -2756,6 +2756,9 @@ public:
     {
 #if OS(IOS)
         sys_cache_control(kCacheFunctionPrepareForExecution, code, size);
+#elif OS(NETBSD)
+        char* begin = reinterpret_cast<char*>(code);
+        __builtin___clear_cache(begin, begin + size);
 #else
 #error "The cacheFlush support is missing on this platform."
 #endif
