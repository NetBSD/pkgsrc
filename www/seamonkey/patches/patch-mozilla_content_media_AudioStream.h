$NetBSD: patch-mozilla_content_media_AudioStream.h,v 1.2 2014/11/02 05:40:31 ryoon Exp $

--- mozilla/content/media/AudioStream.h.orig	2014-10-14 06:36:05.000000000 +0000
+++ mozilla/content/media/AudioStream.h
@@ -17,6 +17,7 @@
 #include "mozilla/RefPtr.h"
 
 #include "cubeb/cubeb.h"
+#include "soundtouch/SoundTouch.h"
 
 template <>
 class nsAutoRefTraits<cubeb_stream> : public nsPointerRefTraits<cubeb_stream>
@@ -26,7 +27,6 @@ public:
 };
 
 namespace soundtouch {
-class SoundTouch;
 }
 
 namespace mozilla {
