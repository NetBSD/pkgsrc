$NetBSD: patch-intel_intel__bufmgr__gem.c,v 1.3 2012/08/13 07:02:01 wiz Exp $

ETIME is not defined on DragonFly BSD, work around it.
From PR 46649; upstream report at
   https://bugs.freedesktop.org/show_bug.cgi?id=52549

--- intel/intel_bufmgr_gem.c.orig	2012-08-11 18:49:45.000000000 +0000
+++ intel/intel_bufmgr_gem.c
@@ -54,6 +54,9 @@
 #include <stdbool.h>
 
 #include "errno.h"
+#ifndef ETIME
+#define ETIME ETIMEDOUT
+#endif
 #include "libdrm_lists.h"
 #include "intel_bufmgr.h"
 #include "intel_bufmgr_priv.h"
