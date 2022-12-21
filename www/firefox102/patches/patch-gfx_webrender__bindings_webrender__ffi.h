$NetBSD: patch-gfx_webrender__bindings_webrender__ffi.h,v 1.2 2022/12/21 10:10:37 nia Exp $

https://bugzilla.mozilla.org/show_bug.cgi?id=1773259

--- gfx/webrender_bindings/webrender_ffi.h.orig	2022-11-07 21:06:45.000000000 +0000
+++ gfx/webrender_bindings/webrender_ffi.h
@@ -73,8 +73,6 @@ struct WrPipelineInfo;
 struct WrPipelineIdAndEpoch;
 using WrPipelineIdEpochs = nsTArray<WrPipelineIdAndEpoch>;
 
-const uint64_t ROOT_CLIP_CHAIN = ~0;
-
 }  // namespace wr
 }  // namespace mozilla
 
