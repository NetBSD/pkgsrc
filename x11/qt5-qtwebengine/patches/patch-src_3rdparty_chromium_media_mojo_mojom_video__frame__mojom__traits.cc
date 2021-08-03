$NetBSD: patch-src_3rdparty_chromium_media_mojo_mojom_video__frame__mojom__traits.cc,v 1.1 2021/08/03 21:04:35 markd Exp $

--- src/3rdparty/chromium/media/mojo/mojom/video_frame_mojom_traits.cc.orig	2020-07-08 21:40:45.000000000 +0000
+++ src/3rdparty/chromium/media/mojo/mojom/video_frame_mojom_traits.cc
@@ -21,7 +21,7 @@
 #include "ui/gfx/mojom/buffer_types_mojom_traits.h"
 #include "ui/gfx/mojom/color_space_mojom_traits.h"
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 #include "base/posix/eintr_wrapper.h"
 #endif  // defined(OS_LINUX)
 
@@ -63,7 +63,7 @@ media::mojom::VideoFrameDataPtr MakeVide
             std::move(offsets)));
   }
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   if (input->storage_type() == media::VideoFrame::STORAGE_DMABUFS) {
     std::vector<mojo::PlatformHandle> dmabuf_fds;
 
@@ -166,7 +166,7 @@ bool StructTraits<media::mojom::VideoFra
         shared_buffer_data.TakeFrameData(),
         shared_buffer_data.frame_data_size(), std::move(offsets),
         std::move(strides), timestamp);
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   } else if (data.is_dmabuf_data()) {
     media::mojom::DmabufVideoFrameDataDataView dmabuf_data;
     data.GetDmabufDataDataView(&dmabuf_data);
