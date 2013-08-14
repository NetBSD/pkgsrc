$NetBSD: patch-Source_JavaScriptCore_dfg_DFGNode.h,v 1.1 2013/08/14 22:16:54 jmcneill Exp $

--- Source/JavaScriptCore/dfg/DFGNode.h.orig	2012-11-23 20:12:15.000000000 +0000
+++ Source/JavaScriptCore/dfg/DFGNode.h
@@ -65,7 +65,7 @@ struct StructureTransitionData {
 struct OpInfo {
     explicit OpInfo(int32_t value) : m_value(static_cast<uintptr_t>(value)) { }
     explicit OpInfo(uint32_t value) : m_value(static_cast<uintptr_t>(value)) { }
-#if OS(DARWIN) || USE(JSVALUE64)
+#if OS(DARWIN) || (CPU(ARM) && OS(NETBSD)) || USE(JSVALUE64)
     explicit OpInfo(size_t value) : m_value(static_cast<uintptr_t>(value)) { }
 #endif
     explicit OpInfo(void* value) : m_value(reinterpret_cast<uintptr_t>(value)) { }
