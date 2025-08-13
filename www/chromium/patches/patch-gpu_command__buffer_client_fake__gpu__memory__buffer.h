$NetBSD: patch-gpu_command__buffer_client_fake__gpu__memory__buffer.h,v 1.3 2025/08/13 07:44:26 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- gpu/command_buffer/client/fake_gpu_memory_buffer.h.orig	2025-07-29 22:51:44.000000000 +0000
+++ gpu/command_buffer/client/fake_gpu_memory_buffer.h
@@ -12,7 +12,7 @@
 
 namespace gpu {
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 // This method is used by tests to create a fake pixmap handle instead of
 // creating a FakeGpuMemoryBuffer. Once all tests are converted to use it,
 // FakeGpuMemoryBuffer will be removed and this file will be renamed
