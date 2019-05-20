$NetBSD: patch-Source_WebCore_platform_graphics_gstreamer_MediaPlayerPrivateGStreamerBase.cpp,v 1.1 2019/05/20 11:15:48 leot Exp $

Backport upstream changeset 243690 to fix the build when GSTREAMER_GL
is not used, via:

 <https://trac.webkit.org/changeset/243690/webkit>

--- Source/WebCore/platform/graphics/gstreamer/MediaPlayerPrivateGStreamerBase.cpp.orig	2019-05-09 09:32:33.000000000 +0000
+++ Source/WebCore/platform/graphics/gstreamer/MediaPlayerPrivateGStreamerBase.cpp
@@ -1000,11 +1000,13 @@ void MediaPlayerPrivateGStreamerBase::up
         break;
     }
 
+#if USE(GSTREAMER_GL)
     // When the imxvpudecoder is used, the texture sampling of the
     // directviv-uploaded texture returns an RGB value, so there's no need to
     // convert it.
     if (m_videoDecoderPlatform != WebKitGstVideoDecoderPlatform::ImxVPU)
         m_textureMapperFlags |= TEXTURE_MAPPER_COLOR_CONVERT_FLAG;
+#endif
 }
 #endif
 
