$NetBSD: patch-content_media_AudioStream.h,v 1.3 2014/06/14 16:20:07 joerg Exp $

--- content/media/AudioStream.h.orig	2014-06-06 01:15:20.000000000 +0000
+++ content/media/AudioStream.h
@@ -15,6 +15,7 @@
 #include "mozilla/StaticMutex.h"
 
 #include "cubeb/cubeb.h"
+#include "soundtouch/SoundTouch.h"
 
 template <>
 class nsAutoRefTraits<cubeb_stream> : public nsPointerRefTraits<cubeb_stream>
@@ -23,10 +24,6 @@ public:
   static void Release(cubeb_stream* aStream) { cubeb_stream_destroy(aStream); }
 };
 
-namespace soundtouch {
-class SoundTouch;
-}
-
 namespace mozilla {
 
 class AudioStream;
