$NetBSD: patch-gpu_command__buffer_tests_gl__gpu__memory__buffer__unittest.cc,v 1.3 2025/07/07 09:23:33 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- gpu/command_buffer/tests/gl_gpu_memory_buffer_unittest.cc.orig	2025-06-30 06:54:11.000000000 +0000
+++ gpu/command_buffer/tests/gl_gpu_memory_buffer_unittest.cc
@@ -29,7 +29,7 @@
 #include "ui/gfx/half_float.h"
 #include "ui/gl/test/gl_test_support.h"
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 #include "gpu/ipc/common/gpu_memory_buffer_impl_native_pixmap.h"
 #include "ui/gfx/linux/client_native_pixmap_factory_dmabuf.h"
 #endif
@@ -72,7 +72,7 @@ class GpuMemoryBufferTest : public testi
   GLManager gl_;
 };
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 class GpuMemoryBufferTestEGL : public testing::Test,
                                public gpu::GpuCommandBufferTestEGL {
  public:
