$NetBSD: patch-content_media_AudioStream.h,v 1.10 2014/12/01 18:11:14 ryoon Exp $

--- content/media/AudioStream.h.orig	2014-11-21 03:37:24.000000000 +0000
+++ content/media/AudioStream.h
@@ -17,7 +17,7 @@
 #include "CubebUtils.h"
 
 namespace soundtouch {
-class SoundTouch;
+class MOZ_IMPORT_API SoundTouch;
 }
 
 namespace mozilla {
