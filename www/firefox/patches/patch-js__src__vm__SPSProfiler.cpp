$NetBSD: patch-js__src__vm__SPSProfiler.cpp,v 1.1 2013/06/21 23:11:42 ryoon Exp $

Unclear fallout from our version of bug 840242, attachment v1: some architectures
fail to link if we do not add the inlines here - might be compiler/arch specific.


--- js/src/vm/SPSProfiler.cpp.orig	2013-05-11 21:19:36.000000000 +0200
+++ js/src/vm/SPSProfiler.cpp	2013-06-15 11:49:39.000000000 +0200
@@ -9,6 +9,7 @@
 
 #include "jsnum.h"
 #include "jsscript.h"
+#include "jscntxtinlines.h"
 
 #include "methodjit/MethodJIT.h"
 #include "methodjit/Compiler.h"
