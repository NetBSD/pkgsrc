$NetBSD: patch-mozilla_media_webrtc_trunk_webrtc_video__engine_vie__defines.h,v 1.1 2013/05/23 13:25:30 ryoon Exp $

--- mozilla/media/webrtc/trunk/webrtc/video_engine/vie_defines.h.orig	2013-05-03 03:08:07.000000000 +0000
+++ mozilla/media/webrtc/trunk/webrtc/video_engine/vie_defines.h
@@ -173,7 +173,7 @@ inline int ChannelId(const int moduleId)
 
 // Linux specific.
 #ifndef WEBRTC_ANDROID
-#ifdef WEBRTC_LINUX
+#if defined(WEBRTC_LINUX) || defined(WEBRTC_BSD)
   //  Build information macros.
   #if defined(_DEBUG)
   #define BUILDMODE "d"
