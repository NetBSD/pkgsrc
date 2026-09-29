$NetBSD: patch-gpu_command__buffer_client_internal_mappable__buffer__native__pixmap.cc,v 1.6 2026/09/29 07:42:58 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- gpu/command_buffer/client/internal/mappable_buffer_native_pixmap.cc.orig	2026-09-22 00:09:16.000000000 +0000
+++ gpu/command_buffer/client/internal/mappable_buffer_native_pixmap.cc
@@ -64,7 +64,7 @@ MappableBufferNativePixmap::CreateFromHa
     viz::SharedImageFormat format,
     gfx::BufferUsage usage) {
   const bool supports_zero_copy_webgpu_import =
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
       handle.native_pixmap_handle().supports_zero_copy_webgpu_import;
 #else
       false;
