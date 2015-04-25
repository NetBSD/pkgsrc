$NetBSD: patch-hw_xfree86_common_xf86sbusBus.h,v 1.1 2015/04/25 11:47:03 tnn Exp $

NetBSD/sparc64 support partially from xsrc.

--- hw/xfree86/common/xf86sbusBus.h.orig	2014-02-05 03:08:57.000000000 +0000
+++ hw/xfree86/common/xf86sbusBus.h
@@ -39,6 +39,8 @@
 #define SBUS_DEVICE_FFB		0x000b
 #define SBUS_DEVICE_GT		0x000c
 #define SBUS_DEVICE_MGX		0x000d
+#define SBUS_DEVICE_P9100	0x000e
+#define SBUS_DEVICE_AG10E	0x000f
 
 typedef struct sbus_prom_node {
     int node;
@@ -50,7 +52,7 @@ typedef struct sbus_device {
     int devId;
     int fbNum;
     int fd;
-    int width, height;
+  int width, height, size;
     sbusPromNode node;
     const char *descr;
     const char *device;
