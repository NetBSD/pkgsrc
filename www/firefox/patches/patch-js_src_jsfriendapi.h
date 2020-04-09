$NetBSD: patch-js_src_jsfriendapi.h,v 1.1 2020/04/09 14:01:26 ryoon Exp $

* Fix va_list error.

--- js/src/jsfriendapi.h.orig	2020-04-03 19:34:47.000000000 +0000
+++ js/src/jsfriendapi.h
@@ -13,6 +13,7 @@
 #include "mozilla/MemoryReporting.h"
 #include "mozilla/UniquePtr.h"
 
+#include <stdarg.h>
 #include "jspubtd.h"
 
 #include "js/CallArgs.h"
