$NetBSD: patch-mozilla_media_libsydneyaudio_src_sydney__audio__pulseaudio.c,v 1.4 2013/01/07 21:55:30 ryoon Exp $

--- mozilla/media/libsydneyaudio/src/sydney_audio_pulseaudio.c.orig	2012-11-18 10:19:46.000000000 +0000
+++ mozilla/media/libsydneyaudio/src/sydney_audio_pulseaudio.c
@@ -6,7 +6,9 @@
 #include <stdio.h>
 #include <string.h>
 #include <pthread.h>
+_Pragma("GCC visibility push(default)")
 #include <pulse/pulseaudio.h>
+_Pragma("GCC visibility pop")
 #include "sydney_audio.h"
 
 /* Pulseaudio implementation based heavily on sydney_audio_alsa.c */
