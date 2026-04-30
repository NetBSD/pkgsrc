$NetBSD: patch-src_3rdparty_chromium_gpu_command__buffer_client_test__shared__image__interface.h,v 1.1 2026/04/30 06:39:41 adam Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- src/3rdparty/chromium/gpu/command_buffer/client/test_shared_image_interface.h.orig	2026-03-16 11:40:07.000000000 +0000
+++ src/3rdparty/chromium/gpu/command_buffer/client/test_shared_image_interface.h
@@ -37,7 +37,7 @@ class TestSharedImageInterface : public 
  public:
   TestSharedImageInterface();
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   // TODO(blundell): Fold this inside of a TestSII::CreateSI() variant and have
   // test clients that need the handle grab it from the created SI.
   static gfx::GpuMemoryBufferHandle CreatePixmapHandle(
