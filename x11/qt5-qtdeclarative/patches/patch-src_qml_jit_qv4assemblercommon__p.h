$NetBSD: patch-src_qml_jit_qv4assemblercommon__p.h,v 1.1 2020/01/21 21:39:09 adam Exp $

Add NetBSD support.

--- src/qml/jit/qv4assemblercommon_p.h.orig	2020-01-21 16:34:07.735772770 +0000
+++ src/qml/jit/qv4assemblercommon_p.h
@@ -66,7 +66,7 @@ namespace QV4 {
 namespace JIT {
 
 #if defined(Q_PROCESSOR_X86_64) || defined(ENABLE_ALL_ASSEMBLERS_FOR_REFACTORING_PURPOSES)
-#if defined(Q_OS_LINUX) || defined(Q_OS_QNX) || defined(Q_OS_FREEBSD) || defined(Q_OS_DARWIN)
+#if defined(Q_OS_LINUX) || defined(Q_OS_QNX) || defined(Q_OS_FREEBSD) || defined(Q_OS_DARWIN) || defined(Q_OS_NETBSD)
 
 class PlatformAssembler_X86_64_SysV : public JSC::MacroAssembler<JSC::MacroAssemblerX86_64>
 {
