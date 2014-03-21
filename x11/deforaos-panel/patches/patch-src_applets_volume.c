$NetBSD: patch-src_applets_volume.c,v 1.1 2014/03/21 14:38:01 jperkin Exp $

Fix SunOS includes.

--- src/applets/volume.c.orig	2013-02-04 22:23:50.000000000 +0000
+++ src/applets/volume.c
@@ -19,7 +19,7 @@
 
 
 #include <sys/ioctl.h>
-#if defined(__NetBSD__) || defined(__sun__)
+#if defined(__NetBSD__)
 # include <sys/audioio.h>
 #elif defined(__linux__)
 # include <alsa/asoundlib.h>
