$NetBSD: patch-src_3rdparty_chromium_ui_gfx_gpu__memory__buffer.cc,v 1.1 2021/08/03 21:04:36 markd Exp $

--- src/3rdparty/chromium/ui/gfx/gpu_memory_buffer.cc.orig	2020-07-15 18:56:34.000000000 +0000
+++ src/3rdparty/chromium/ui/gfx/gpu_memory_buffer.cc
@@ -34,7 +34,7 @@ GpuMemoryBufferHandle GpuMemoryBufferHan
   handle.region = region.Duplicate();
   handle.offset = offset;
   handle.stride = stride;
-#if defined(OS_LINUX) || defined(OS_FUCHSIA)
+#if defined(OS_LINUX) || defined(OS_FUCHSIA) || defined(OS_BSD)
   handle.native_pixmap_handle = CloneHandleForIPC(native_pixmap_handle);
 #elif defined(OS_MACOSX) && !defined(OS_IOS)
   NOTIMPLEMENTED();
