$NetBSD: patch-media_libcubeb_update.sh,v 1.2 2019/06/14 08:11:35 nia Exp $

--- media/libcubeb/update.sh.orig	2017-07-10 16:18:12.000000000 +0000
+++ media/libcubeb/update.sh
@@ -17,6 +17,8 @@ cp $1/src/cubeb_audiounit.cpp src
 cp $1/src/cubeb_osx_run_loop.h src
 cp $1/src/cubeb_jack.cpp src
 cp $1/src/cubeb_opensl.c src
+cp $1/src/cubeb_oss.c src
+cp $1/src/cubeb_sun.c src
 cp $1/src/cubeb_panner.cpp src
 cp $1/src/cubeb_panner.h src
 cp $1/src/cubeb_pulse.c src
