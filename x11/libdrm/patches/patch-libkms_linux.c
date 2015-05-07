$NetBSD: patch-libkms_linux.c,v 1.2 2015/05/07 06:31:06 wiz Exp $

--- libkms/linux.c.orig	2015-05-06 23:04:31.000000000 +0000
+++ libkms/linux.c
@@ -40,6 +40,11 @@
 #include <string.h>
 #include <unistd.h>
 #include <sys/stat.h>
+#ifdef __sun
+#include <sys/types.h>
+#include <sys/mkdev.h>
+#endif
+
 
 #include "libdrm_macros.h"
 #include "internal.h"
