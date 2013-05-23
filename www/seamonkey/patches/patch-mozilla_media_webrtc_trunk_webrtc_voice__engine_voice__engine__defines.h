$NetBSD: patch-mozilla_media_webrtc_trunk_webrtc_voice__engine_voice__engine__defines.h,v 1.1 2013/05/23 13:25:30 ryoon Exp $

--- mozilla/media/webrtc/trunk/webrtc/voice_engine/voice_engine_defines.h.orig	2013-05-03 03:08:07.000000000 +0000
+++ mozilla/media/webrtc/trunk/webrtc/voice_engine/voice_engine_defines.h
@@ -414,7 +414,7 @@ namespace webrtc
 // *** WEBRTC_MAC ***
 // including iPhone
 
-#ifdef WEBRTC_MAC
+#if defined(WEBRTC_BSD) || defined(WEBRTC_MAC)
 
 #include <pthread.h>
 #include <sys/types.h>
@@ -431,6 +431,7 @@ namespace webrtc
 #include <sched.h>
 #include <sys/time.h>
 #include <time.h>
+#if !defined(WEBRTC_BSD)
 #include <AudioUnit/AudioUnit.h>
 #if !defined(WEBRTC_IOS)
   #include <CoreServices/CoreServices.h>
@@ -439,6 +440,7 @@ namespace webrtc
   #include <AudioToolbox/AudioConverter.h>
   #include <CoreAudio/HostTime.h>
 #endif
+#endif
 
 #define DWORD unsigned long int
 #define WINAPI
@@ -531,7 +533,7 @@ namespace webrtc
 
 #else
 #define IPHONE_NOT_SUPPORTED(stat)
-#endif  // #ifdef WEBRTC_MAC
+#endif  // #if defined(WEBRTC_BSD) || defined(WEBRTC_MAC)
 
 
 
