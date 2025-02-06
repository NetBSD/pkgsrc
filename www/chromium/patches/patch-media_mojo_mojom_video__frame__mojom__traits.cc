$NetBSD: patch-media_mojo_mojom_video__frame__mojom__traits.cc,v 1.1 2025/02/06 09:58:13 wiz Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- media/mojo/mojom/video_frame_mojom_traits.cc.orig	2024-12-17 17:58:49.000000000 +0000
+++ media/mojo/mojom/video_frame_mojom_traits.cc
@@ -27,7 +27,7 @@
 #include "ui/gfx/mojom/color_space_mojom_traits.h"
 #include "ui/gfx/mojom/hdr_metadata_mojom_traits.h"
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 #include "base/posix/eintr_wrapper.h"
 #endif  // BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
 
@@ -152,7 +152,7 @@ media::mojom::VideoFrameDataPtr MakeVide
             std::move(shared_image), std::move(mailbox_holder.sync_token),
             std::move(mailbox_holder.texture_target),
             std::move(input->ycbcr_info())));
-#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   } else if (input->HasOOPVDMailbox()) {
     return media::mojom::VideoFrameData::NewMailboxData(
         media::mojom::MailboxVideoFrameData::New(input->oopvd_mailbox()));
@@ -353,7 +353,7 @@ bool StructTraits<media::mojom::VideoFra
     frame = media::VideoFrame::WrapExternalGpuMemoryBuffer(
         visible_rect, natural_size, std::move(gpu_memory_buffer), shared_image,
         sync_token, base::NullCallback(), timestamp);
-#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   } else if (data.is_mailbox_data()) {
     media::mojom::MailboxVideoFrameDataDataView mailbox_data;
     data.GetMailboxDataDataView(&mailbox_data);
