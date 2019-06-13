$NetBSD: patch-mozilla_media_libcubeb_update.sh,v 1.2 2019/06/13 10:53:11 nia Exp $

--- mozilla/media/libcubeb/update.sh.orig	2018-07-12 02:17:34.000000000 +0000
+++ mozilla/media/libcubeb/update.sh
@@ -17,6 +17,7 @@ cp $1/src/cubeb_audiounit.cpp src
 cp $1/src/cubeb_osx_run_loop.h src
 cp $1/src/cubeb_jack.cpp src
 cp $1/src/cubeb_opensl.c src
+cp $1/src/cubeb_oss.c src
 cp $1/src/cubeb_panner.cpp src
 cp $1/src/cubeb_panner.h src
 cp $1/src/cubeb_pulse.c src
@@ -25,6 +26,7 @@ cp $1/src/cubeb_resampler.h src
 cp $1/src/cubeb_resampler_internal.h src
 cp $1/src/cubeb_ring_array.h src
 cp $1/src/cubeb_sndio.c src
+cp $1/src/cubeb_sun.c src
 cp $1/src/cubeb_utils.h src
 cp $1/src/cubeb_utils_unix.h src
 cp $1/src/cubeb_utils_win.h src
