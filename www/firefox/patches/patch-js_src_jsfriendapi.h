$NetBSD: patch-js_src_jsfriendapi.h,v 1.2.4.1 2020/10/29 12:18:54 spz Exp $

* Fix va_list error.

--- js/src/jsfriendapi.h.orig	2020-09-17 00:32:45.000000000 +0000
+++ js/src/jsfriendapi.h
@@ -10,6 +10,7 @@
 #include "mozilla/MemoryReporting.h"
 #include "mozilla/PodOperations.h"
 
+#include <stdarg.h>
 #include "jspubtd.h"
 
 #include "js/CallArgs.h"
