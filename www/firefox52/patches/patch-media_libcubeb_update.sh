$NetBSD: patch-media_libcubeb_update.sh,v 1.1 2017/04/27 01:55:57 ryoon Exp $

--- media/libcubeb/update.sh.orig	2016-10-31 20:15:39.000000000 +0000
+++ media/libcubeb/update.sh
@@ -16,6 +16,7 @@ cp $1/src/cubeb_audiounit.cpp src
 cp $1/src/cubeb_osx_run_loop.h src
 cp $1/src/cubeb_jack.cpp src
 cp $1/src/cubeb_opensl.c src
+cp $1/src/cubeb_oss.c src
 cp $1/src/cubeb_panner.cpp src
 cp $1/src/cubeb_panner.h src
 cp $1/src/cubeb_pulse.c src
