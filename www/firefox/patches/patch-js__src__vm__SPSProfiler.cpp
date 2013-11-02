$NetBSD: patch-js__src__vm__SPSProfiler.cpp,v 1.3 2013/11/02 22:57:55 ryoon Exp $

Unclear fallout from our version of bug 840242, attachment v1: some architectures
fail to link if we do not add the inlines here - might be compiler/arch specific.


--- js/src/vm/SPSProfiler.cpp.orig	2013-10-25 22:27:26.000000000 +0000
+++ js/src/vm/SPSProfiler.cpp
@@ -10,6 +10,7 @@
 
 #include "jsnum.h"
 #include "jsscript.h"
+#include "jscntxtinlines.h"
 
 #include "jit/BaselineJIT.h"
 #include "vm/StringBuffer.h"
