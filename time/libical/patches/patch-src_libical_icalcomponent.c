$NetBSD: patch-src_libical_icalcomponent.c,v 1.2 2020/03/04 10:54:25 nia Exp $

Need limits.h for *_MAX

https://github.com/libical/libical/pull/420

--- src/libical/icalcomponent.c.orig	2018-02-27 15:34:25.000000000 +0000
+++ src/libical/icalcomponent.c
@@ -28,6 +28,7 @@
 #include "icaltimezone.h"
 
 #include <assert.h>
+#include <limits.h>
 #include <stdlib.h>
 
 struct icalcomponent_impl
