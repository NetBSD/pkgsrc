$NetBSD: patch-src_3rdparty_chromium_gpu_command__buffer_client_test__shared__image__interface.cc,v 1.1 2026/04/30 06:39:40 adam Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- src/3rdparty/chromium/gpu/command_buffer/client/test_shared_image_interface.cc.orig	2026-03-16 11:40:07.000000000 +0000
+++ src/3rdparty/chromium/gpu/command_buffer/client/test_shared_image_interface.cc
@@ -30,7 +30,7 @@
 #include "ui/gfx/gpu_fence.h"
 #include "ui/gfx/gpu_memory_buffer_handle.h"
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 #include <fcntl.h>
 #endif
 
@@ -154,7 +154,7 @@ TestSharedImageInterface::TestSharedImag
 TestSharedImageInterface::~TestSharedImageInterface() = default;
 
 // static
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 gfx::GpuMemoryBufferHandle TestSharedImageInterface::CreatePixmapHandle(
     const gfx::Size& size,
     gfx::BufferFormat format) {
