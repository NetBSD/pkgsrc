$NetBSD: patch-js__src__vm__SPSProfiler.cpp,v 1.4 2013/12/15 13:54:37 ryoon Exp $

Unclear fallout from our version of bug 840242, attachment v1: some architectures
fail to link if we do not add the inlines here - might be compiler/arch specific.


--- js/src/vm/SPSProfiler.cpp.orig	2013-12-05 16:07:40.000000000 +0000
+++ js/src/vm/SPSProfiler.cpp
@@ -4,12 +4,15 @@
  * License, v. 2.0. If a copy of the MPL was not distributed with this
  * file, You can obtain one at http://mozilla.org/MPL/2.0/. */
 
+#include "jscntxtinlines.h"
+
 #include "vm/SPSProfiler.h"
 
 #include "mozilla/DebugOnly.h"
 
 #include "jsnum.h"
 #include "jsscript.h"
+#include "jscntxtinlines.h"
 
 #include "jit/BaselineJIT.h"
 #include "vm/StringBuffer.h"
