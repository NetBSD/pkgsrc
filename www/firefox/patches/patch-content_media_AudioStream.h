$NetBSD: patch-content_media_AudioStream.h,v 1.4 2014/07/24 14:57:12 ryoon Exp $

--- content/media/AudioStream.h.orig	2014-07-17 01:45:09.000000000 +0000
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
