$NetBSD: patch-Source_WebCore_platform_graphics_gstreamer_MediaPlayerPrivateGStreamer.cpp,v 1.1 2019/05/17 16:11:17 leot Exp $

updateTextureMapperFlags() is available only if TEXTURE_MAPPER_GL is enabled.

--- Source/WebCore/platform/graphics/gstreamer/MediaPlayerPrivateGStreamer.cpp.orig	2019-05-09 09:36:07.000000000 +0000
+++ Source/WebCore/platform/graphics/gstreamer/MediaPlayerPrivateGStreamer.cpp
@@ -2460,7 +2460,9 @@ void MediaPlayerPrivateGStreamer::create
         else if (g_str_has_prefix(elementName.get(), "imxvpudecoder"))
             player->m_videoDecoderPlatform = WebKitGstVideoDecoderPlatform::ImxVPU;
 
+#if USE(TEXTURE_MAPPER_GL)
         player->updateTextureMapperFlags();
+#endif
     }), this);
 
     g_signal_connect_swapped(m_pipeline.get(), "source-setup", G_CALLBACK(sourceSetupCallback), this);
