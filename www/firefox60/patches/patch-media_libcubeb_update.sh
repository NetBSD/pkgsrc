$NetBSD: patch-media_libcubeb_update.sh,v 1.2 2019/06/13 14:16:37 nia Exp $

--- media/libcubeb/update.sh.orig	2019-05-14 19:13:23.000000000 +0000
+++ media/libcubeb/update.sh
@@ -20,6 +20,8 @@ cp $1/src/cubeb_log.h src
 cp $1/src/cubeb_mixer.cpp src
 cp $1/src/cubeb_mixer.h src
 cp $1/src/cubeb_opensl.c src
+cp $1/src/cubeb_oss.c src
+cp $1/src/cubeb_sun.c src
 cp $1/src/cubeb-jni.cpp src
 cp $1/src/cubeb-jni.h src
 cp $1/src/android/cubeb-output-latency.h src/android
