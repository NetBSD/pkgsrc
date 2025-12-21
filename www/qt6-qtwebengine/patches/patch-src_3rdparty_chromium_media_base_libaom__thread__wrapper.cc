$NetBSD: patch-src_3rdparty_chromium_media_base_libaom__thread__wrapper.cc,v 1.1 2025/12/21 09:38:31 markd Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- src/3rdparty/chromium/media/base/libaom_thread_wrapper.cc.orig	2025-05-29 01:27:28.000000000 +0000
+++ src/3rdparty/chromium/media/base/libaom_thread_wrapper.cc
@@ -10,12 +10,14 @@
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
