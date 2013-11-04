$NetBSD: patch-mozilla_js_src_vm_SPSProfiler.cpp,v 1.3 2013/11/04 06:01:46 ryoon Exp $

--- mozilla/js/src/vm/SPSProfiler.cpp.orig	2013-10-29 01:20:57.000000000 +0000
+++ mozilla/js/src/vm/SPSProfiler.cpp
@@ -10,6 +10,7 @@
 
 #include "jsnum.h"
 #include "jsscript.h"
+#include "jscntxtinlines.h"
 
 #include "jit/BaselineJIT.h"
 #include "vm/StringBuffer.h"
