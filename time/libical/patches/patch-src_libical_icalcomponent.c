$NetBSD: patch-src_libical_icalcomponent.c,v 1.1 2018/05/14 08:34:56 jperkin Exp $

Need limits.h for *_MAX

--- src/libical/icalcomponent.c.orig	2018-02-27 15:34:25.000000000 +0000
+++ src/libical/icalcomponent.c
@@ -28,6 +28,7 @@
 #include "icaltimezone.h"
 
 #include <assert.h>
+#include <limits.h>
 #include <stdlib.h>
 
 struct icalcomponent_impl
