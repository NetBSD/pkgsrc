$NetBSD: patch-content_media_AudioStream.h,v 1.7 2014/10/13 20:53:46 joerg Exp $

--- content/media/AudioStream.h.orig	2014-09-24 01:05:11.000000000 +0000
+++ content/media/AudioStream.h
@@ -17,6 +17,7 @@
 #include "mozilla/RefPtr.h"
 
 #include "cubeb/cubeb.h"
+#include "soundtouch/SoundTouch.h"
 
 template <>
 class nsAutoRefTraits<cubeb_stream> : public nsPointerRefTraits<cubeb_stream>
@@ -25,10 +26,6 @@ public:
   static void Release(cubeb_stream* aStream) { cubeb_stream_destroy(aStream); }
 };
 
-namespace soundtouch {
-class SoundTouch;
-}
-
 namespace mozilla {
 
 class AudioStream;
