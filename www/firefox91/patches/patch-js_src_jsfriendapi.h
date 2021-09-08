$NetBSD: patch-js_src_jsfriendapi.h,v 1.1 2021/09/08 22:19:50 nia Exp $

* Fix va_list error.

--- js/src/jsfriendapi.h.orig	2020-09-17 00:32:45.000000000 +0000
+++ js/src/jsfriendapi.h
@@ -10,6 +10,7 @@
 #include "mozilla/MemoryReporting.h"
 #include "mozilla/PodOperations.h"
 
+#include <stdarg.h>
 #include "jspubtd.h"
 
 #include "js/CallArgs.h"
