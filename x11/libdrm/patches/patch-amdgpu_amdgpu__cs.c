$NetBSD: patch-amdgpu_amdgpu__cs.c,v 1.1 2015/08/18 13:26:29 richard Exp $
at least on SunOS, alloca needs alloca.h
--- amdgpu/amdgpu_cs.c.orig	2015-08-13 22:27:03.000000000 +0000
+++ amdgpu/amdgpu_cs.c
@@ -32,7 +32,9 @@
 #include <pthread.h>
 #include <sched.h>
 #include <sys/ioctl.h>
-
+#ifdef HAVE_ALLOCA_H
+#include <alloca.h>
+#endif
 #include "xf86drm.h"
 #include "amdgpu_drm.h"
 #include "amdgpu_internal.h"
