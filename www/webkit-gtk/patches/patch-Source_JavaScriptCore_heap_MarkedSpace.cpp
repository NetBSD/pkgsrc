$NetBSD: patch-Source_JavaScriptCore_heap_MarkedSpace.cpp,v 1.2 2020/03/10 18:14:04 leot Exp $

Avoid ambiguous function call.

--- Source/JavaScriptCore/heap/MarkedSpace.cpp.orig	2020-02-04 10:23:59.000000000 +0000
+++ Source/JavaScriptCore/heap/MarkedSpace.cpp
@@ -30,6 +30,8 @@
 #include "MarkedSpaceInlines.h"
 #include <wtf/ListDump.h>
 
+using std::pow;
+
 namespace JSC {
 
 std::array<size_t, MarkedSpace::numSizeClasses> MarkedSpace::s_sizeClassForSizeStep;
