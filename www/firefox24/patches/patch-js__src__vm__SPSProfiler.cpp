$NetBSD: patch-js__src__vm__SPSProfiler.cpp,v 1.1 2013/11/03 04:51:59 ryoon Exp $

Unclear fallout from our version of bug 840242, attachment v1: some architectures
fail to link if we do not add the inlines here - might be compiler/arch specific.


--- js/src/vm/SPSProfiler.cpp.orig	2013-09-10 03:43:39.000000000 +0000
+++ js/src/vm/SPSProfiler.cpp
@@ -8,6 +8,7 @@
 
 #include "jsnum.h"
 #include "jsscript.h"
+#include "jscntxtinlines.h"
 
 #include "vm/SPSProfiler.h"
 #include "vm/StringBuffer.h"
