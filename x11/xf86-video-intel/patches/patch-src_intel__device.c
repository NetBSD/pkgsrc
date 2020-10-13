$NetBSD: patch-src_intel__device.c,v 1.1 2020/10/13 04:38:30 maya Exp $

Try i915kms as a kernel module name, from freebsd ports
_WITH_GETLINE for freebsd.

--- src/intel_device.c.orig	2020-05-15 16:56:58.000000000 +0000
+++ src/intel_device.c
@@ -28,6 +28,9 @@
 #include "config.h"
 #endif
 
+#define _WITH_GETLINE	/* to expose getline() in stdio.h on FreeBSD */
+#include <stdio.h>	/* for getline() */
+
 #include <sys/types.h>
 #include <sys/stat.h>
 #include <assert.h>
@@ -204,6 +207,7 @@ static inline struct intel_device *intel
 }
 
 static const char *kernel_module_names[] ={
+	"i915kms",
 	"i915",
 	NULL,
 };
