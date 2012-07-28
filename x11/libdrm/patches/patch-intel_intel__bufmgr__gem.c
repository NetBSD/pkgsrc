$NetBSD: patch-intel_intel__bufmgr__gem.c,v 1.2 2012/07/28 18:01:26 dholland Exp $

ETIME is not defined on DragonFly BSD, work around it.
From PR 46649; upstream report at
   https://bugs.freedesktop.org/show_bug.cgi?id=52549

--- intel/intel_bufmgr_gem.c.orig	2012-07-02 15:22:14.326942000 +0000
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
