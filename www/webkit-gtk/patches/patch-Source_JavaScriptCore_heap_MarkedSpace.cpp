$NetBSD: patch-Source_JavaScriptCore_heap_MarkedSpace.cpp,v 1.1 2018/06/15 09:17:02 jperkin Exp $

Avoid ambiguous function call.

--- Source/JavaScriptCore/heap/MarkedSpace.cpp.orig	2018-02-20 11:01:51.000000000 +0000
+++ Source/JavaScriptCore/heap/MarkedSpace.cpp
@@ -29,6 +29,8 @@
 #include "MarkedBlockInlines.h"
 #include <wtf/ListDump.h>
 
+using std::pow;
+
 namespace JSC {
 
 std::array<size_t, MarkedSpace::numSizeClasses> MarkedSpace::s_sizeClassForSizeStep;
