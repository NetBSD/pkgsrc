$NetBSD: patch-mozilla_media_webrtc_trunk_webrtc_system__wrappers_source_clock.cc,v 1.1 2013/12/26 13:17:37 ryoon Exp $

--- mozilla/media/webrtc/trunk/webrtc/system_wrappers/source/clock.cc.orig	2013-12-11 04:28:57.000000000 +0000
+++ mozilla/media/webrtc/trunk/webrtc/system_wrappers/source/clock.cc
@@ -15,7 +15,7 @@
 #include <Windows.h>
 #include <WinSock.h>
 #include <MMSystem.h>
-#elif ((defined WEBRTC_LINUX) || (defined WEBRTC_MAC))
+#elif ((defined WEBRTC_LINUX) || (defined WEBRTC_BSD) || (defined WEBRTC_MAC))
 #include <sys/time.h>
 #include <time.h>
 #endif
@@ -209,7 +209,7 @@ class WindowsRealTimeClock : public Real
   WindowsHelpTimer* _helpTimer;
 };
 
-#elif ((defined WEBRTC_LINUX) || (defined WEBRTC_MAC))
+#elif ((defined WEBRTC_LINUX) || (defined WEBRTC_BSD) || (defined WEBRTC_MAC))
 class UnixRealTimeClock : public RealTimeClock {
  public:
   UnixRealTimeClock() {}
@@ -240,7 +240,7 @@ Clock* Clock::GetRealTimeClock() {
 #if defined(_WIN32)
   static WindowsRealTimeClock clock(&global_help_timer);
   return &clock;
-#elif defined(WEBRTC_LINUX) || defined(WEBRTC_MAC)
+#elif ((defined WEBRTC_LINUX) || (defined WEBRTC_BSD) || (defined WEBRTC_MAC))
   static UnixRealTimeClock clock;
   return &clock;
 #else
