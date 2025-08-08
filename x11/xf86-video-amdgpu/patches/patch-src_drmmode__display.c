$NetBSD: patch-src_drmmode__display.c,v 1.1 2025/08/08 11:28:14 wiz Exp $

https://gitlab.freedesktop.org/xorg/driver/xf86-video-amdgpu/-/issues/84

--- src/drmmode_display.c.orig	2025-08-08 11:23:35.638093875 +0000
+++ src/drmmode_display.c
@@ -3893,7 +3893,7 @@ out:
 	RRGetInfo(xf86ScrnToScreen(scrn), TRUE);
 }
 
-#ifdef HAVE_LIBUDEV
+#if HAVE_LIBUDEV
 static void drmmode_handle_uevents(int fd, void *closure)
 {
 	drmmode_ptr drmmode = closure;
@@ -3923,7 +3923,7 @@ static void drmmode_handle_uevents(int f
 
 void drmmode_uevent_init(ScrnInfoPtr scrn, drmmode_ptr drmmode)
 {
-#ifdef HAVE_LIBUDEV
+#if HAVE_LIBUDEV
 	struct udev *u;
 	struct udev_monitor *mon;
 
@@ -3955,7 +3955,7 @@ void drmmode_uevent_init(ScrnInfoPtr scr
 
 void drmmode_uevent_fini(ScrnInfoPtr scrn, drmmode_ptr drmmode)
 {
-#ifdef HAVE_LIBUDEV
+#if HAVE_LIBUDEV
 	if (drmmode->uevent_handler) {
 		struct udev *u = udev_monitor_get_udev(drmmode->uevent_monitor);
 		xf86RemoveGeneralHandler(drmmode->uevent_handler);
