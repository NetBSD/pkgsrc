$NetBSD: patch-Source_JavaScriptCore_heap_MarkedSpace.cpp,v 1.3 2020/09/11 14:47:35 leot Exp $

Avoid ambiguous function call.

--- Source/JavaScriptCore/heap/MarkedSpace.cpp.orig	2020-08-12 09:17:52.000000000 +0000
+++ Source/JavaScriptCore/heap/MarkedSpace.cpp
@@ -28,6 +28,8 @@
 #include "MarkedSpaceInlines.h"
 #include <wtf/ListDump.h>
 
+using std::pow;
+
 namespace JSC {
 
 std::array<unsigned, MarkedSpace::numSizeClasses> MarkedSpace::s_sizeClassForSizeStep;
