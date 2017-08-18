$NetBSD: patch-mozilla_media_libcubeb_update.sh,v 1.1 2017/08/18 23:55:07 ryoon Exp $

--- mozilla/media/libcubeb/update.sh.orig	2017-07-07 05:37:16.000000000 +0000
+++ mozilla/media/libcubeb/update.sh
@@ -16,6 +16,7 @@ cp $1/src/cubeb_audiounit.cpp src
 cp $1/src/cubeb_osx_run_loop.h src
 cp $1/src/cubeb_jack.cpp src
 cp $1/src/cubeb_opensl.c src
+cp $1/src/cubeb_oss.c src
 cp $1/src/cubeb_panner.cpp src
 cp $1/src/cubeb_panner.h src
 cp $1/src/cubeb_pulse.c src
