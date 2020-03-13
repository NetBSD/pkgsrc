$NetBSD: patch-media_libcubeb_update.sh,v 1.1.6.1 2020/03/13 20:02:45 bsiegert Exp $

Add Sun audio support.

--- media/libcubeb/update.sh.orig	2019-05-29 15:39:11.000000000 +0000
+++ media/libcubeb/update.sh
@@ -25,6 +25,7 @@ cp $1/src/cubeb_log.h src
 cp $1/src/cubeb_mixer.cpp src
 cp $1/src/cubeb_mixer.h src
 cp $1/src/cubeb_opensl.c src
+cp $1/src/cubeb_sun.c src
 cp $1/src/cubeb-jni.cpp src
 cp $1/src/cubeb-jni.h src
 cp $1/src/android/cubeb-output-latency.h src/android
