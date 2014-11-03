$NetBSD: patch-content_media_AudioStream.h,v 1.1 2014/11/03 12:18:32 ryoon Exp $

--- content/media/AudioStream.h.orig	2014-07-17 01:45:09.000000000 +0000
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
