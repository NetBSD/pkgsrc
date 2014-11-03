$NetBSD: patch-content_media_AudioStream.cpp,v 1.1 2014/11/03 12:18:32 ryoon Exp $

--- content/media/AudioStream.cpp.orig	2014-04-18 02:02:42.000000000 +0000
+++ content/media/AudioStream.cpp
@@ -13,7 +13,6 @@
 #include "mozilla/Mutex.h"
 #include <algorithm>
 #include "mozilla/Preferences.h"
-#include "soundtouch/SoundTouch.h"
 #include "Latency.h"
 
 namespace mozilla {
