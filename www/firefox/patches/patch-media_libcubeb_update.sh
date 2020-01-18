$NetBSD: patch-media_libcubeb_update.sh,v 1.7 2020/01/18 15:32:40 nia Exp $

--- media/libcubeb/update.sh.orig	Wed Jan  8 01:23:35 2020
+++ media/libcubeb/update.sh
@@ -25,6 +25,7 @@ cp $1/src/cubeb_log.h src
 cp $1/src/cubeb_mixer.cpp src
 cp $1/src/cubeb_mixer.h src
 cp $1/src/cubeb_opensl.c src
+cp $1/src/cubeb_sun.c src
 cp $1/src/cubeb-jni.cpp src
 cp $1/src/cubeb-jni.h src
 cp $1/src/android/cubeb-output-latency.h src/android
