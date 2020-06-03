$NetBSD: patch-js_src_jsfriendapi.h,v 1.2 2020/06/03 09:00:24 ryoon Exp $

* Fix va_list error.

--- js/src/jsfriendapi.h.orig	2020-05-22 02:11:19.000000000 +0000
+++ js/src/jsfriendapi.h
@@ -14,6 +14,7 @@
 #include "mozilla/PodOperations.h"
 #include "mozilla/UniquePtr.h"
 
+#include <stdarg.h>
 #include "jspubtd.h"
 
 #include "js/CallArgs.h"
