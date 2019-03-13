$NetBSD: patch-Source_JavaScriptCore_assembler_ARM64Assembler.h,v 1.3 2019/03/13 20:49:40 leot Exp $

- Bump m_compareRegister to hold values of JSC::ARM64Assembler::RegisterID
- Add support for FreeBSD and NetBSD.
  Based on patch from FreeBSD ports but using __builtin___clear_cache()
  instead of __clear_cache() (the former is also available in gcc).

--- Source/JavaScriptCore/assembler/ARM64Assembler.h.orig	2019-02-12 11:21:03.000000000 +0000
+++ Source/JavaScriptCore/assembler/ARM64Assembler.h
@@ -462,7 +462,7 @@ public:
                 JumpLinkType m_linkType : 8;
                 Condition m_condition : 4;
                 unsigned m_bitNumber : 6;
-                RegisterID m_compareRegister : 6;
+                RegisterID m_compareRegister : 8;
                 bool m_is64Bit : 1;
             } realTypes;
             struct CopyTypes {
@@ -2874,6 +2874,8 @@ public:
     {
 #if OS(IOS_FAMILY)
         sys_cache_control(kCacheFunctionPrepareForExecution, code, size);
+#elif OS(FREEBSD) || OS(NETBSD)
+        __builtin___clear_cache(code, reinterpret_cast<char*>(code) + size);
 #elif OS(FUCHSIA)
         zx_cache_flush(code, size, ZX_CACHE_FLUSH_INSN);
 #elif OS(LINUX)
