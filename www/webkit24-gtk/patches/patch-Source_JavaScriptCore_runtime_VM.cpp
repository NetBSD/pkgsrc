$NetBSD: patch-Source_JavaScriptCore_runtime_VM.cpp,v 1.1 2016/12/03 16:30:05 martin Exp $

Allow this to build without ENABLE(ASSEMBLER)

--- Source/JavaScriptCore/runtime/VM.cpp.orig	2016-04-10 08:48:36.000000000 +0200
+++ Source/JavaScriptCore/runtime/VM.cpp	2016-12-02 15:53:07.033628829 +0100
@@ -205,6 +205,8 @@
     , m_newStringsSinceLastHashCons(0)
 #if ENABLE(ASSEMBLER)
     , m_canUseAssembler(enableAssembler(executableAllocator))
+#else
+#define	m_canUseAssembler	false
 #endif
 #if ENABLE(JIT)
     , m_canUseJIT(m_canUseAssembler && Options::useJIT())
