$NetBSD: patch-content_media_AudioStream.h,v 1.6 2014/10/05 01:59:08 ryoon Exp $

--- content/media/AudioStream.h.orig	2014-09-24 01:05:11.000000000 +0000
+++ content/media/AudioStream.h
@@ -17,6 +17,7 @@
 #include "mozilla/RefPtr.h"
 
 #include "cubeb/cubeb.h"
+#include "soundtouch/SoundTouch.h"
 
 template <>
 class nsAutoRefTraits<cubeb_stream> : public nsPointerRefTraits<cubeb_stream>
@@ -26,7 +27,7 @@ public:
 };
 
 namespace soundtouch {
-class SoundTouch;
+class MOZ_IMPORT_API SoundTouch;
 }
 
 namespace mozilla {
