$NetBSD: patch-src_3rdparty_chromium_gpu_command__buffer_service_external__vk__image__backing.cc,v 1.1 2021/08/03 21:04:35 markd Exp $

--- src/3rdparty/chromium/gpu/command_buffer/service/external_vk_image_backing.cc.orig	2020-11-07 01:22:36.000000000 +0000
+++ src/3rdparty/chromium/gpu/command_buffer/service/external_vk_image_backing.cc
@@ -29,7 +29,7 @@
 #include "ui/gl/buildflags.h"
 #include "ui/gl/gl_context.h"
 
-#if defined(OS_LINUX) && BUILDFLAG(USE_DAWN)
+#if (defined(OS_LINUX) || defined(OS_BSD)) && BUILDFLAG(USE_DAWN)
 #include "gpu/command_buffer/service/external_vk_image_dawn_representation.h"
 #endif
 
@@ -37,7 +37,7 @@
 #include "gpu/vulkan/fuchsia/vulkan_fuchsia_ext.h"
 #endif
 
-#if defined(OS_LINUX) || defined(OS_ANDROID) || defined(OS_FUCHSIA)
+#if defined(OS_LINUX) || defined(OS_ANDROID) || defined(OS_FUCHSIA) || defined(OS_BSD)
 #define GL_DEDICATED_MEMORY_OBJECT_EXT 0x9581
 #define GL_TEXTURE_TILING_EXT 0x9580
 #define GL_TILING_TYPES_EXT 0x9583
@@ -510,7 +510,7 @@ std::unique_ptr<SharedImageRepresentatio
 ExternalVkImageBacking::ProduceDawn(SharedImageManager* manager,
                                     MemoryTypeTracker* tracker,
                                     WGPUDevice wgpuDevice) {
-#if defined(OS_LINUX) && BUILDFLAG(USE_DAWN)
+#if (defined(OS_LINUX) || defined(OS_BSD)) && BUILDFLAG(USE_DAWN)
   auto wgpu_format = viz::ToWGPUFormat(format());
 
   if (wgpu_format == WGPUTextureFormat_Undefined) {
@@ -537,7 +537,7 @@ ExternalVkImageBacking::ProduceDawn(Shar
 
 GLuint ExternalVkImageBacking::ProduceGLTextureInternal() {
 #if defined(OS_LINUX) || defined(OS_ANDROID) || defined(OS_FUCHSIA) || \
-    defined(OS_WIN)
+    defined(OS_WIN) || defined(OS_BSD)
   GrVkImageInfo image_info;
   bool result = backend_texture_.getVkImageInfo(&image_info);
   DCHECK(result);
@@ -545,7 +545,7 @@ GLuint ExternalVkImageBacking::ProduceGL
   gl::GLApi* api = gl::g_current_gl_context;
   GLuint memory_object = 0;
   if (!use_separate_gl_texture()) {
-#if defined(OS_LINUX) || defined(OS_ANDROID)
+#if defined(OS_LINUX) || defined(OS_ANDROID) || defined(OS_BSD)
     auto memory_fd = image_->GetMemoryFd();
     if (!memory_fd.is_valid()) {
       return 0;
@@ -623,7 +623,7 @@ ExternalVkImageBacking::ProduceGLTexture
   }
 
 #if defined(OS_LINUX) || defined(OS_ANDROID) || defined(OS_FUCHSIA) || \
-    defined(OS_WIN)
+    defined(OS_WIN) || defined(OS_BSD)
   if (!texture_) {
     GLuint texture_service_id = ProduceGLTextureInternal();
     if (!texture_service_id)
@@ -667,7 +667,7 @@ ExternalVkImageBacking::ProduceGLTexture
   }
 
 #if defined(OS_LINUX) || defined(OS_ANDROID) || defined(OS_FUCHSIA) || \
-    defined(OS_WIN)
+    defined(OS_WIN) || defined(OS_BSD)
   if (!texture_passthrough_) {
     GLuint texture_service_id = ProduceGLTextureInternal();
     if (!texture_service_id)
