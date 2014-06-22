$NetBSD: patch-mozilla_content_media_AudioStream.h,v 1.1 2014/06/22 08:54:39 ryoon Exp $

--- mozilla/content/media/AudioStream.h.orig	2014-06-13 00:46:03.000000000 +0000
+++ mozilla/content/media/AudioStream.h
@@ -15,6 +15,7 @@
 #include "mozilla/StaticMutex.h"
 
 #include "cubeb/cubeb.h"
+#include "soundtouch/SoundTouch.h"
 
 template <>
 class nsAutoRefTraits<cubeb_stream> : public nsPointerRefTraits<cubeb_stream>
