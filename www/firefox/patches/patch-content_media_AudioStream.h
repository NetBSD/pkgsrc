$NetBSD: patch-content_media_AudioStream.h,v 1.2 2014/06/11 00:40:59 ryoon Exp $

--- content/media/AudioStream.h.orig	2014-05-29 23:30:33.000000000 +0000
+++ content/media/AudioStream.h
@@ -15,6 +15,7 @@
 #include "mozilla/StaticMutex.h"
 
 #include "cubeb/cubeb.h"
+#include "soundtouch/SoundTouch.h"
 
 template <>
 class nsAutoRefTraits<cubeb_stream> : public nsPointerRefTraits<cubeb_stream>
@@ -24,7 +25,7 @@ public:
 };
 
 namespace soundtouch {
-class SoundTouch;
+class MOZ_IMPORT_API SoundTouch;
 }
 
 namespace mozilla {
