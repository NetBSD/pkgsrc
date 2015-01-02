$NetBSD: patch-mozilla_content_media_AudioStream.h,v 1.3 2015/01/02 04:26:21 ryoon Exp $

--- mozilla/content/media/AudioStream.h.orig	2014-12-03 06:22:34.000000000 +0000
+++ mozilla/content/media/AudioStream.h
@@ -17,7 +17,7 @@
 #include "CubebUtils.h"
 
 namespace soundtouch {
-class SoundTouch;
+class MOZ_IMPORT_API SoundTouch;
 }
 
 namespace mozilla {
