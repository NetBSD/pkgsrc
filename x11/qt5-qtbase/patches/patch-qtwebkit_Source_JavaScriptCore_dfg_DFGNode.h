$NetBSD: patch-qtwebkit_Source_JavaScriptCore_dfg_DFGNode.h,v 1.1 2013/12/13 14:38:35 ryoon Exp $

* Add NetBSD support

--- qtwebkit/Source/JavaScriptCore/dfg/DFGNode.h.orig	2013-11-27 01:01:48.000000000 +0000
+++ qtwebkit/Source/JavaScriptCore/dfg/DFGNode.h
@@ -73,7 +73,7 @@ struct NewArrayBufferData {
 struct OpInfo {
     explicit OpInfo(int32_t value) : m_value(static_cast<uintptr_t>(value)) { }
     explicit OpInfo(uint32_t value) : m_value(static_cast<uintptr_t>(value)) { }
-#if OS(DARWIN) || USE(JSVALUE64)
+#if OS(DARWIN) || (CPU(ARM) && OS(NETBSD)) || USE(JSVALUE64)
     explicit OpInfo(size_t value) : m_value(static_cast<uintptr_t>(value)) { }
 #endif
     explicit OpInfo(void* value) : m_value(reinterpret_cast<uintptr_t>(value)) { }
