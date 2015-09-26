$NetBSD: patch-Source_JavaScriptCore_dfg_DFGNode.h,v 1.4 2015/09/26 10:16:38 leot Exp $

--- Source/JavaScriptCore/dfg/DFGNode.h.orig	2015-09-21 07:29:46.000000000 +0000
+++ Source/JavaScriptCore/dfg/DFGNode.h
@@ -221,7 +221,7 @@ struct OpInfo {
     OpInfo() : m_value(0) { }
     explicit OpInfo(int32_t value) : m_value(static_cast<uintptr_t>(value)) { }
     explicit OpInfo(uint32_t value) : m_value(static_cast<uintptr_t>(value)) { }
-#if OS(DARWIN) || USE(JSVALUE64)
+#if OS(DARWIN) || (CPU(ARM) && OS(NETBSD)) || USE(JSVALUE64)
     explicit OpInfo(size_t value) : m_value(static_cast<uintptr_t>(value)) { }
 #endif
     explicit OpInfo(void* value) : m_value(reinterpret_cast<uintptr_t>(value)) { }
