$NetBSD: patch-Source_JavaScriptCore_heap_MarkedSpace.cpp,v 1.4 2021/09/28 22:11:54 leot Exp $

Avoid ambiguous function call.

--- Source/JavaScriptCore/heap/MarkedSpace.cpp.orig	2021-09-01 09:16:46.000000000 +0000
+++ Source/JavaScriptCore/heap/MarkedSpace.cpp
@@ -29,6 +29,8 @@
 #include <wtf/ListDump.h>
 #include <wtf/SimpleStats.h>
 
+using std::pow;
+
 namespace JSC {
 
 std::array<unsigned, MarkedSpace::numSizeClasses> MarkedSpace::s_sizeClassForSizeStep;
