$NetBSD: patch-content_media_AudioStream.h,v 1.9 2014/10/17 16:49:09 joerg Exp $

--- content/media/AudioStream.h.orig	2014-10-11 09:06:20.000000000 +0000
+++ content/media/AudioStream.h
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
