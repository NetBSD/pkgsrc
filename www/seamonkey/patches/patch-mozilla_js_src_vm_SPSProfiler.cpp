$NetBSD: patch-mozilla_js_src_vm_SPSProfiler.cpp,v 1.4 2013/12/26 13:17:37 ryoon Exp $

--- mozilla/js/src/vm/SPSProfiler.cpp.orig	2013-12-11 04:28:45.000000000 +0000
+++ mozilla/js/src/vm/SPSProfiler.cpp
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
