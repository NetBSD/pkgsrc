$NetBSD: patch-Source_JavaScriptCore_assembler_ARM64Assembler.h,v 1.1 2018/11/13 20:11:38 leot Exp $

Add support for FreeBSD and NetBSD.

Based on patch from FreeBSD ports but using __builtin___clear_cache()
instead of __clear_cache() (the former is also available in gcc).

--- Source/JavaScriptCore/assembler/ARM64Assembler.h.orig	2018-10-27 21:20:55.000000000 +0000
+++ Source/JavaScriptCore/assembler/ARM64Assembler.h
@@ -2863,6 +2863,8 @@ public:
     {
 #if OS(IOS)
         sys_cache_control(kCacheFunctionPrepareForExecution, code, size);
+#elif OS(FREEBSD) || OS(NETBSD)
+        __builtin___clear_cache(code, reinterpret_cast<char*>(code) + size);
 #elif OS(FUCHSIA)
         zx_cache_flush(code, size, ZX_CACHE_FLUSH_INSN);
 #elif OS(LINUX)
