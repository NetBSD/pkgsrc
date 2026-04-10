$NetBSD: patch-third__party_blink_renderer_modules_webgl_webgl__rendering__context__base.cc,v 1.17 2026/04/10 17:31:59 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- third_party/blink/renderer/modules/webgl/webgl_rendering_context_base.cc.orig	2026-04-06 16:25:54.000000000 +0000
+++ third_party/blink/renderer/modules/webgl/webgl_rendering_context_base.cc
@@ -6425,7 +6425,7 @@ void WebGLRenderingContextBase::TexImage
       params.function_id == kTexImage2D ||
       (params.function_id == kTexSubImage2D &&
        base::FeatureList::IsEnabled(kAllowGpuUploadForTexSubImageOnAndroid));
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // TODO(crbug.com/1181562): TexSubImage2D via the GPU path performs poorly on
   // Linux when used with frames backed by SharedImages holding shared memory.
   // We don't have a way to differentiate this case from that of true texture
