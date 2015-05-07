$NetBSD: patch-libkms_vmwgfx.c,v 1.3 2015/05/07 06:31:06 wiz Exp $

Provide compatibility errno number for non-Linux.

--- libkms/vmwgfx.c.orig	2015-05-06 23:04:31.000000000 +0000
+++ libkms/vmwgfx.c
@@ -39,6 +39,10 @@
 #include "libdrm_macros.h"
 #include "vmwgfx_drm.h"
 
+#ifndef ERESTART
+#define ERESTART 85
+#endif
+
 struct vmwgfx_bo
 {
 	struct kms_bo base;
