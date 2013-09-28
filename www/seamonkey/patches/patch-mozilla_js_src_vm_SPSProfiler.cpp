$NetBSD: patch-mozilla_js_src_vm_SPSProfiler.cpp,v 1.2 2013/09/28 14:37:05 ryoon Exp $

--- mozilla/js/src/vm/SPSProfiler.cpp.orig	2013-09-16 18:26:43.000000000 +0000
+++ mozilla/js/src/vm/SPSProfiler.cpp
@@ -8,6 +8,7 @@
 
 #include "jsnum.h"
 #include "jsscript.h"
+#include "jscntxtinlines.h"
 
 #include "vm/SPSProfiler.h"
 #include "vm/StringBuffer.h"
