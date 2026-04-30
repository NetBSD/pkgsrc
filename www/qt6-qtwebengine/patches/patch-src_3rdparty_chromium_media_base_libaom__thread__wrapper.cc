$NetBSD: patch-src_3rdparty_chromium_media_base_libaom__thread__wrapper.cc,v 1.2 2026/04/30 06:39:41 adam Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- src/3rdparty/chromium/media/base/libaom_thread_wrapper.cc.orig	2026-03-16 11:40:07.000000000 +0000
+++ src/3rdparty/chromium/media/base/libaom_thread_wrapper.cc
@@ -5,17 +5,21 @@
 #include "base/logging.h"
 #include "media/base/codec_worker_impl.h"
 #include "media/base/libvpx_thread_wrapper.h"
+#if !BUILDFLAG(IS_BSD)
 #include "third_party/libaom/source/libaom/aom_util/aom_thread.h"
+#endif
 
 namespace media {
 
 void InitLibAomThreadWrapper() {
+#if !BUILDFLAG(IS_BSD)
   const AVxWorkerInterface interface =
       CodecWorkerImpl<AVxWorkerInterface, AVxWorkerImpl, AVxWorker,
                       AVxWorkerStatus, AVX_WORKER_STATUS_NOT_OK,
                       AVX_WORKER_STATUS_OK,
                       AVX_WORKER_STATUS_WORKING>::GetCodecWorkerInterface();
   CHECK(aom_set_worker_interface(&interface));
+#endif
 }
 
 }  // namespace media
