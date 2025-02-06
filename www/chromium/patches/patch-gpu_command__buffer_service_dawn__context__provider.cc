$NetBSD: patch-gpu_command__buffer_service_dawn__context__provider.cc,v 1.1 2025/02/06 09:58:09 wiz Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- gpu/command_buffer/service/dawn_context_provider.cc.orig	2024-12-17 17:58:49.000000000 +0000
+++ gpu/command_buffer/service/dawn_context_provider.cc
@@ -302,7 +302,7 @@ wgpu::BackendType DawnContextProvider::G
   return base::FeatureList::IsEnabled(features::kSkiaGraphiteDawnUseD3D12)
              ? wgpu::BackendType::D3D12
              : wgpu::BackendType::D3D11;
-#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_BSD)
   return wgpu::BackendType::Vulkan;
 #elif BUILDFLAG(IS_APPLE)
   return wgpu::BackendType::Metal;
