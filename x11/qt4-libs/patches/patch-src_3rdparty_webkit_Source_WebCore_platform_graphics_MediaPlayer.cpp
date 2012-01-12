$NetBSD: patch-src_3rdparty_webkit_Source_WebCore_platform_graphics_MediaPlayer.cpp,v 1.1 2012/01/12 22:59:58 adam Exp $

--- src/3rdparty/webkit/Source/WebCore/platform/graphics/MediaPlayer.cpp.orig	2012-01-08 12:03:43.000000000 +0000
+++ src/3rdparty/webkit/Source/WebCore/platform/graphics/MediaPlayer.cpp
@@ -192,9 +192,6 @@ static Vector<MediaPlayerFactory*>& inst
             MediaPlayerPrivateAVFoundationObjC::registerMediaEngine(addMediaEngine);
 #endif
 
-#if !PLATFORM(GTK) && !PLATFORM(EFL) && !(PLATFORM(QT) && USE(GSTREAMER))
-        PlatformMediaEngineClassName::registerMediaEngine(addMediaEngine);
-#endif
     }
 
     return installedEngines;
