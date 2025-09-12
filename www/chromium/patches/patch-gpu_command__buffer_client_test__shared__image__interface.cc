$NetBSD: patch-gpu_command__buffer_client_test__shared__image__interface.cc,v 1.3 2025/09/12 16:02:30 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- gpu/command_buffer/client/test_shared_image_interface.cc.orig	2025-09-08 23:21:33.000000000 +0000
+++ gpu/command_buffer/client/test_shared_image_interface.cc
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
