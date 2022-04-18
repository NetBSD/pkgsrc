$NetBSD: patch-src_3rdparty_chromium_gpu_command__buffer_common_gpu__memory__buffer__support.cc,v 1.2 2022/04/18 11:18:19 adam Exp $

--- src/3rdparty/chromium/gpu/command_buffer/common/gpu_memory_buffer_support.cc.orig	2021-02-19 16:41:59.000000000 +0000
+++ src/3rdparty/chromium/gpu/command_buffer/common/gpu_memory_buffer_support.cc
@@ -55,7 +55,7 @@ bool IsImageSizeValidForGpuMemoryBufferF
 uint32_t GetPlatformSpecificTextureTarget() {
 #if defined(OS_MAC)
   return macos_specific_texture_target;
-#elif defined(OS_ANDROID) || defined(OS_LINUX) || defined(OS_CHROMEOS)
+#elif defined(OS_ANDROID) || defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
   return GL_TEXTURE_EXTERNAL_OES;
 #elif defined(OS_WIN) || defined(OS_FUCHSIA)
   return GL_TEXTURE_2D;
@@ -85,7 +85,7 @@ GPU_EXPORT uint32_t GetBufferTextureTarg
 
 GPU_EXPORT bool NativeBufferNeedsPlatformSpecificTextureTarget(
     gfx::BufferFormat format) {
-#if defined(USE_OZONE) || defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(USE_OZONE) || defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
   // Always use GL_TEXTURE_2D as the target for RGB textures.
   // https://crbug.com/916728
   if (format == gfx::BufferFormat::R_8 || format == gfx::BufferFormat::RG_88 ||
