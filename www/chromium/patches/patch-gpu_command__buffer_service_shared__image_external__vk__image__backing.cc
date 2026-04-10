$NetBSD: patch-gpu_command__buffer_service_shared__image_external__vk__image__backing.cc,v 1.17 2026/04/10 17:31:56 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- gpu/command_buffer/service/shared_image/external_vk_image_backing.cc.orig	2026-04-06 16:25:54.000000000 +0000
+++ gpu/command_buffer/service/shared_image/external_vk_image_backing.cc
@@ -52,7 +52,7 @@
 #include "ui/gl/gl_version_info.h"
 #include "ui/gl/scoped_binders.h"
 
-#if BUILDFLAG(IS_LINUX) && BUILDFLAG(USE_DAWN)
+#if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)) && BUILDFLAG(USE_DAWN)
 #include "gpu/command_buffer/service/shared_image/external_vk_image_dawn_representation.h"
 #if BUILDFLAG(DAWN_ENABLE_BACKEND_OPENGLES)
 #include "gpu/command_buffer/service/shared_image/dawn_gl_texture_representation.h"
@@ -734,7 +734,7 @@ std::unique_ptr<DawnImageRepresentation>
     wgpu::BackendType backend_type,
     std::vector<wgpu::TextureFormat> view_formats,
     scoped_refptr<SharedContextState> context_state) {
-#if BUILDFLAG(IS_LINUX) && BUILDFLAG(USE_DAWN)
+#if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)) && BUILDFLAG(USE_DAWN)
   auto wgpu_format = ToDawnFormat(format());
 
   if (wgpu_format == wgpu::TextureFormat::Undefined) {
