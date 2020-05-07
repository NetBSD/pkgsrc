$NetBSD: patch-mozilla_media_libcubeb_update.sh,v 1.4 2020/05/07 19:36:53 nia Exp $

- Sun Audio support.

--- mozilla/media/libcubeb/update.sh.orig	2020-04-01 11:01:50.000000000 +0000
+++ mozilla/media/libcubeb/update.sh
@@ -32,6 +32,7 @@ cp $1/src/cubeb_ringbuffer.h src
 cp $1/src/cubeb_sndio.c src
 cp $1/src/cubeb_strings.c src
 cp $1/src/cubeb_strings.h src
+cp $1/src/cubeb_sun.c src
 cp $1/src/cubeb_utils.h src
 cp $1/src/cubeb_utils_unix.h src
 cp $1/src/cubeb_utils_win.h src
