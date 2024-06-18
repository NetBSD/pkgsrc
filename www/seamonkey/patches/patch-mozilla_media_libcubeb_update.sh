$NetBSD: patch-mozilla_media_libcubeb_update.sh,v 1.6 2024/06/18 03:17:01 ryoon Exp $

- Sun Audio support.

--- media/libcubeb/update.sh.orig	2024-06-17 07:44:24.370778492 +0000
+++ media/libcubeb/update.sh
@@ -41,6 +41,7 @@ cp $1/src/cubeb_ringbuffer.h src
 cp $1/src/cubeb_sndio.c src
 cp $1/src/cubeb_strings.c src
 cp $1/src/cubeb_strings.h src
+cp $1/src/cubeb_sun.c src
 cp $1/src/cubeb_utils.h src
 cp $1/src/cubeb_utils.cpp src
 cp $1/src/cubeb_utils_unix.h src
