$NetBSD: patch-mozilla_content_media_AudioStream.cpp,v 1.3 2014/06/22 08:54:39 ryoon Exp $

--- mozilla/content/media/AudioStream.cpp.orig	2014-06-13 00:46:03.000000000 +0000
+++ mozilla/content/media/AudioStream.cpp
@@ -13,7 +13,6 @@
 #include "mozilla/Mutex.h"
 #include <algorithm>
 #include "mozilla/Preferences.h"
-#include "soundtouch/SoundTouch.h"
 #include "Latency.h"
 
 namespace mozilla {
