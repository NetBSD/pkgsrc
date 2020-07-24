$NetBSD: patch-mozilla-release_js_src_jsfriendapi.h,v 1.2 2020/07/24 07:29:32 fox Exp $

* Fix va_list error.

Taken from www/firefox

--- mozilla-release/js/src/jsfriendapi.h.orig	2020-05-22 02:11:19.000000000 +0000
+++ mozilla-release/js/src/jsfriendapi.h
@@ -14,6 +14,7 @@
 #include "mozilla/PodOperations.h"
 #include "mozilla/UniquePtr.h"
 
+#include <stdarg.h>
 #include "jspubtd.h"
 
 #include "js/CallArgs.h"
