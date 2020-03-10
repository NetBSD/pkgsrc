$NetBSD: patch-Source_JavaScriptCore_assembler_ARM64Assembler.h,v 1.5 2020/03/10 18:14:04 leot Exp $

- Add support for FreeBSD and NetBSD.
  Based on patch from FreeBSD ports but using __builtin___clear_cache()
  instead of __clear_cache() (the former is also available in gcc).

--- Source/JavaScriptCore/assembler/ARM64Assembler.h.orig	2020-02-04 10:23:58.000000000 +0000
+++ Source/JavaScriptCore/assembler/ARM64Assembler.h
@@ -2809,6 +2809,8 @@ public:
     {
 #if OS(DARWIN)
         sys_cache_control(kCacheFunctionPrepareForExecution, code, size);
+#elif OS(FREEBSD) || OS(NETBSD)
+        __builtin___clear_cache(code, reinterpret_cast<char*>(code) + size);
 #elif OS(FUCHSIA)
         zx_cache_flush(code, size, ZX_CACHE_FLUSH_INSN);
 #elif OS(LINUX)
