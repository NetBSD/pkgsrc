$NetBSD: patch-media_webrtc_trunk_webrtc_video__engine_vie__defines.h,v 1.1 2013/05/23 13:12:13 ryoon Exp $

--- media/webrtc/trunk/webrtc/video_engine/vie_defines.h.orig	2013-05-11 19:19:46.000000000 +0000
+++ media/webrtc/trunk/webrtc/video_engine/vie_defines.h
@@ -173,7 +173,7 @@ inline int ChannelId(const int moduleId)
 
 // Linux specific.
 #ifndef WEBRTC_ANDROID
-#ifdef WEBRTC_LINUX
+#if defined(WEBRTC_LINUX) || defined(WEBRTC_BSD)
   //  Build information macros.
   #if defined(_DEBUG)
   #define BUILDMODE "d"
