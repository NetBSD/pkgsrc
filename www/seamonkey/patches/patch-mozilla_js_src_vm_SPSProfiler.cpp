$NetBSD: patch-mozilla_js_src_vm_SPSProfiler.cpp,v 1.5 2014/06/22 08:54:39 ryoon Exp $

--- mozilla/js/src/vm/SPSProfiler.cpp.orig	2014-06-13 00:46:08.000000000 +0000
+++ mozilla/js/src/vm/SPSProfiler.cpp
@@ -4,6 +4,8 @@
  * License, v. 2.0. If a copy of the MPL was not distributed with this
  * file, You can obtain one at http://mozilla.org/MPL/2.0/. */
 
+#include "jscntxtinlines.h"
+
 #include "vm/SPSProfiler.h"
 
 #include "mozilla/DebugOnly.h"
