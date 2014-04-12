$NetBSD: patch-libkms_vmwgfx.c,v 1.1 2014/04/12 09:28:42 wiz Exp $

Provide compatibility errno number for non-Linux.

--- libkms/vmwgfx.c.orig	2013-08-12 18:01:22.000000000 +0000
+++ libkms/vmwgfx.c
@@ -38,6 +38,10 @@
 #include "xf86drm.h"
 #include "vmwgfx_drm.h"
 
+#ifndef ERESTART
+#define ERESTART 85
+#endif
+
 struct vmwgfx_bo
 {
 	struct kms_bo base;
