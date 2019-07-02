$NetBSD: patch-Source_JavaScriptCore_assembler_ARM64Assembler.h,v 1.4 2019/07/02 10:48:08 leot Exp $

- Add support for FreeBSD and NetBSD.
  Based on patch from FreeBSD ports but using __builtin___clear_cache()
  instead of __clear_cache() (the former is also available in gcc).

--- Source/JavaScriptCore/assembler/ARM64Assembler.h.orig	2019-02-12 11:21:03.000000000 +0000
+++ Source/JavaScriptCore/assembler/ARM64Assembler.h
@@ -2874,6 +2874,8 @@ public:
     {
 #if OS(IOS_FAMILY)
         sys_cache_control(kCacheFunctionPrepareForExecution, code, size);
+#elif OS(FREEBSD) || OS(NETBSD)
+        __builtin___clear_cache(code, reinterpret_cast<char*>(code) + size);
 #elif OS(FUCHSIA)
         zx_cache_flush(code, size, ZX_CACHE_FLUSH_INSN);
 #elif OS(LINUX)
