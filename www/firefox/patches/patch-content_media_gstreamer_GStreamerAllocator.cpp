$NetBSD: patch-content_media_gstreamer_GStreamerAllocator.cpp,v 1.3 2014/06/11 00:40:59 ryoon Exp $

--- content/media/gstreamer/GStreamerAllocator.cpp.orig	2014-05-29 23:30:33.000000000 +0000
+++ content/media/gstreamer/GStreamerAllocator.cpp
@@ -51,7 +51,6 @@ typedef struct
 #pragma GCC diagnostic ignored "-Wunused-function"
 G_DEFINE_TYPE(MozGfxMemoryAllocator, moz_gfx_memory_allocator, GST_TYPE_ALLOCATOR);
 G_DEFINE_TYPE(MozGfxBufferPool, moz_gfx_buffer_pool, GST_TYPE_VIDEO_BUFFER_POOL);
-#pragma GCC diagnostic pop
 
 void
 moz_gfx_memory_reset(MozGfxMemory *mem)
