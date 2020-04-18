$NetBSD: patch-mozilla-release_js_src_jsfriendapi.h,v 1.1 2020/04/18 07:58:36 fox Exp $

* Fix va_list error.

Taken from www/firefox

--- mozilla-release/js/src/jsfriendapi.h.orig	2020-04-03 19:34:47.000000000 +0000
+++ mozilla-release/js/src/jsfriendapi.h
@@ -13,6 +13,7 @@
 #include "mozilla/MemoryReporting.h"
 #include "mozilla/UniquePtr.h"
 
+#include <stdarg.h>
 #include "jspubtd.h"
 
 #include "js/CallArgs.h"
