$NetBSD: patch-media_libcubeb_update.sh,v 1.3 2017/08/10 14:46:15 ryoon Exp $

--- media/libcubeb/update.sh.orig	2017-07-31 16:20:49.000000000 +0000
+++ media/libcubeb/update.sh
@@ -20,6 +20,7 @@ cp $1/src/cubeb_log.h src
 cp $1/src/cubeb_mixer.cpp src
 cp $1/src/cubeb_mixer.h src
 cp $1/src/cubeb_opensl.c src
+cp $1/src/cubeb_oss.c src
 cp $1/src/cubeb_osx_run_loop.h src
 cp $1/src/cubeb_panner.cpp src
 cp $1/src/cubeb_panner.h src
