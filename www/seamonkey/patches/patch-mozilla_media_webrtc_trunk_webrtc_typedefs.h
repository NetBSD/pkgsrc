$NetBSD: patch-mozilla_media_webrtc_trunk_webrtc_typedefs.h,v 1.1 2013/05/23 13:25:30 ryoon Exp $

--- mozilla/media/webrtc/trunk/webrtc/typedefs.h.orig	2013-05-03 03:08:07.000000000 +0000
+++ mozilla/media/webrtc/trunk/webrtc/typedefs.h
@@ -21,7 +21,7 @@
 // For access to standard POSIXish features, use WEBRTC_POSIX instead of a
 // more specific macro.
 #if defined(WEBRTC_MAC) || defined(WEBRTC_LINUX) || \
-    defined(WEBRTC_ANDROID)
+    defined(WEBRTC_ANDROID) || defined(WEBRTC_BSD)
 #define WEBRTC_POSIX
 #endif
 
