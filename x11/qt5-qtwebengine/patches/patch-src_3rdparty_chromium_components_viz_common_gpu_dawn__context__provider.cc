$NetBSD: patch-src_3rdparty_chromium_components_viz_common_gpu_dawn__context__provider.cc,v 1.1 2021/08/03 21:04:35 markd Exp $

--- src/3rdparty/chromium/components/viz/common/gpu/dawn_context_provider.cc.orig	2020-07-08 21:40:41.000000000 +0000
+++ src/3rdparty/chromium/components/viz/common/gpu/dawn_context_provider.cc
@@ -17,7 +17,7 @@ namespace {
 dawn_native::BackendType GetDefaultBackendType() {
 #if defined(OS_WIN)
   return dawn_native::BackendType::D3D12;
-#elif defined(OS_LINUX)
+#elif defined(OS_LINUX) || defined(OS_BSD)
   return dawn_native::BackendType::Vulkan;
 #else
   NOTREACHED();
