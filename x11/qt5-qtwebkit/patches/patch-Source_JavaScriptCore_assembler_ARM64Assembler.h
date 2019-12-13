$NetBSD: patch-Source_JavaScriptCore_assembler_ARM64Assembler.h,v 1.1 2019/12/13 09:48:02 mrg Exp $

find a valid clear cache for netbsd/arm64.

--- Source/JavaScriptCore/assembler/ARM64Assembler.h.orig	2019-12-07 02:31:00.900806242 -0800
+++ Source/JavaScriptCore/assembler/ARM64Assembler.h	2019-12-07 02:30:09.650436008 -0800
@@ -2666,6 +2666,8 @@
     {
 #if OS(IOS)
         sys_cache_control(kCacheFunctionPrepareForExecution, code, size);
+#elif OS(NETBSD)
+	__builtin___clear_cache(code, reinterpret_cast<char*>(code) + size);
 #elif OS(LINUX)
         size_t page = pageSize();
         uintptr_t current = reinterpret_cast<uintptr_t>(code);
