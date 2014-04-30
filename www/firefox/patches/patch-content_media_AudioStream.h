$NetBSD: patch-content_media_AudioStream.h,v 1.1 2014/04/30 15:07:18 ryoon Exp $

--- content/media/AudioStream.h.orig	2014-04-18 02:02:42.000000000 +0000
+++ content/media/AudioStream.h
@@ -15,6 +15,7 @@
 #include "mozilla/StaticMutex.h"
 
 #include "cubeb/cubeb.h"
+#include "soundtouch/SoundTouch.h"
 
 template <>
 class nsAutoRefTraits<cubeb_stream> : public nsPointerRefTraits<cubeb_stream>
