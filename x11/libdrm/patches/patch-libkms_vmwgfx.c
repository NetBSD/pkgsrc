$NetBSD: patch-libkms_vmwgfx.c,v 1.2 2014/10/01 09:39:30 wiz Exp $

Provide compatibility errno number for non-Linux.

--- libkms/vmwgfx.c.orig	2014-09-28 16:19:54.000000000 +0000
+++ libkms/vmwgfx.c
@@ -39,6 +39,10 @@
 #include "libdrm.h"
 #include "vmwgfx_drm.h"
 
+#ifndef ERESTART
+#define ERESTART 85
+#endif
+
 struct vmwgfx_bo
 {
 	struct kms_bo base;
