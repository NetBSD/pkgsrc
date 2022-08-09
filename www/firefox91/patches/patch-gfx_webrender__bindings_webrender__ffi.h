$NetBSD: patch-gfx_webrender__bindings_webrender__ffi.h,v 1.1 2022/08/09 13:39:28 nia Exp $

https://bugzilla.mozilla.org/show_bug.cgi?id=1773259

--- gfx/webrender_bindings/webrender_ffi.h.orig	2022-07-18 18:14:25.000000000 +0000
+++ gfx/webrender_bindings/webrender_ffi.h
@@ -73,8 +73,6 @@ struct WrPipelineInfo;
 struct WrPipelineIdAndEpoch;
 using WrPipelineIdEpochs = nsTArray<WrPipelineIdAndEpoch>;
 
-const uint64_t ROOT_CLIP_CHAIN = ~0;
-
 }  // namespace wr
 }  // namespace mozilla
 
