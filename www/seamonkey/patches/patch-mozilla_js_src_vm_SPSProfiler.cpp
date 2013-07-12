$NetBSD: patch-mozilla_js_src_vm_SPSProfiler.cpp,v 1.1 2013/07/12 12:24:10 ryoon Exp $

--- mozilla/js/src/vm/SPSProfiler.cpp.orig	2013-06-20 04:35:09.000000000 +0000
+++ mozilla/js/src/vm/SPSProfiler.cpp
@@ -9,6 +9,7 @@
 
 #include "jsnum.h"
 #include "jsscript.h"
+#include "jscntxtinlines.h"
 
 #include "methodjit/MethodJIT.h"
 #include "methodjit/Compiler.h"
