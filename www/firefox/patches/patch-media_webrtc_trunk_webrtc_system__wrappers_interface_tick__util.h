$NetBSD: patch-media_webrtc_trunk_webrtc_system__wrappers_interface_tick__util.h,v 1.1 2013/05/23 13:12:13 ryoon Exp $

--- media/webrtc/trunk/webrtc/system_wrappers/interface/tick_util.h.orig	2013-05-11 19:19:46.000000000 +0000
+++ media/webrtc/trunk/webrtc/system_wrappers/interface/tick_util.h
@@ -194,7 +194,7 @@ inline WebRtc_Word64 TickTime::QueryOsFo
   }
   result.ticks_ = now + (num_wrap_time_get_time << 32);
 #endif
-#elif defined(WEBRTC_LINUX)
+#elif defined(WEBRTC_LINUX) || defined(WEBRTC_BSD)
   struct timespec ts;
   // TODO(wu): Remove CLOCK_REALTIME implementation.
 #ifdef WEBRTC_CLOCK_TYPE_REALTIME
@@ -241,7 +241,7 @@ inline WebRtc_Word64 TickTime::Milliseco
 #else
   return ticks;
 #endif
-#elif defined(WEBRTC_LINUX) || defined(WEBRTC_MAC)
+#elif defined(WEBRTC_LINUX) || defined(WEBRTC_BSD) || defined(WEBRTC_MAC)
   return ticks / 1000000LL;
 #else
   return ticks / 1000LL;
@@ -258,7 +258,7 @@ inline WebRtc_Word64 TickTime::Microseco
 #else
   return ticks * 1000LL;
 #endif
-#elif defined(WEBRTC_LINUX) || defined(WEBRTC_MAC)
+#elif defined(WEBRTC_LINUX) || defined(WEBRTC_BSD) || defined(WEBRTC_MAC)
   return ticks / 1000LL;
 #else
   return ticks;
@@ -278,7 +278,7 @@ inline WebRtc_Word64 TickTime::Milliseco
 #else
   return ms;
 #endif
-#elif defined(WEBRTC_LINUX) || defined(WEBRTC_MAC)
+#elif defined(WEBRTC_LINUX) || defined(WEBRTC_BSD) || defined(WEBRTC_MAC)
   return ms * 1000000LL;
 #else
   return ms * 1000LL;
@@ -294,7 +294,7 @@ inline WebRtc_Word64 TickTime::TicksToMi
 #else
   return ticks;
 #endif
-#elif defined(WEBRTC_LINUX) || defined(WEBRTC_MAC)
+#elif defined(WEBRTC_LINUX) || defined(WEBRTC_BSD) || defined(WEBRTC_MAC)
   return ticks / 1000000LL;
 #else
   return ticks / 1000LL;
@@ -323,7 +323,7 @@ inline WebRtc_Word64 TickInterval::Milli
   // interval_ is in ms
   return interval_;
 #endif
-#elif defined(WEBRTC_LINUX) || defined(WEBRTC_MAC)
+#elif defined(WEBRTC_LINUX) || defined(WEBRTC_BSD) || defined(WEBRTC_MAC)
   // interval_ is in ns
   return interval_ / 1000000;
 #else
@@ -342,7 +342,7 @@ inline WebRtc_Word64 TickInterval::Micro
   // interval_ is in ms
   return interval_ * 1000LL;
 #endif
-#elif defined(WEBRTC_LINUX) || defined(WEBRTC_MAC)
+#elif defined(WEBRTC_LINUX) || defined(WEBRTC_BSD) || defined(WEBRTC_MAC)
   // interval_ is in ns
   return interval_ / 1000;
 #else
