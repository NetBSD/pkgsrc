$NetBSD: patch-gpu_command__buffer_client_test__shared__image__interface.h,v 1.2 2025/09/08 13:24:26 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- gpu/command_buffer/client/test_shared_image_interface.h.orig	2025-08-29 18:50:09.000000000 +0000
+++ gpu/command_buffer/client/test_shared_image_interface.h
@@ -37,7 +37,7 @@ class TestSharedImageInterface : public 
  public:
   TestSharedImageInterface();
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   // TODO(blundell): Fold this inside of a TestSII::CreateSI() variant and have
   // test clients that need the handle grab it from the created SI.
   static gfx::GpuMemoryBufferHandle CreatePixmapHandle(
