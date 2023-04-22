$NetBSD: patch-get-edid_i2c-dev.h,v 1.1 2023/04/22 00:58:05 manu Exp $

Define Linux-centric types for other systems

--- get-edid/i2c-dev.h.orig	2022-04-13 17:08:35.570045956 +0200
+++ get-edid/i2c-dev.h	2022-04-13 17:09:03.120904790 +0200
@@ -24,9 +24,19 @@
 
 #ifndef LIB_I2CDEV_H
 #define LIB_I2CDEV_H
 
+#ifdef linux
 #include <linux/types.h>
+#else
+#include <sys/types.h>
+typedef uint32_t __u32;
+typedef uint16_t __u16;
+typedef uint8_t  __u8;
+typedef int32_t  __s32;
+typedef int16_t  __s16;
+typedef int8_t   __s8;
+#endif
 #include <sys/ioctl.h>
 
 
 /* -- i2c.h -- */
