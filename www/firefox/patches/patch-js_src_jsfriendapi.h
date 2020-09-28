$NetBSD: patch-js_src_jsfriendapi.h,v 1.3 2020/09/28 13:30:01 ryoon Exp $

* Fix va_list error.

--- js/src/jsfriendapi.h.orig	2020-09-17 00:32:45.000000000 +0000
+++ js/src/jsfriendapi.h
@@ -10,6 +10,7 @@
 #include "mozilla/MemoryReporting.h"
 #include "mozilla/PodOperations.h"
 
+#include <stdarg.h>
 #include "jspubtd.h"
 
 #include "js/CallArgs.h"
