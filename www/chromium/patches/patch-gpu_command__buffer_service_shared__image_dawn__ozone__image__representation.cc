$NetBSD: patch-gpu_command__buffer_service_shared__image_dawn__ozone__image__representation.cc,v 1.6 2026/08/09 06:31:17 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- gpu/command_buffer/service/shared_image/dawn_ozone_image_representation.cc.orig	2026-08-05 20:17:42.000000000 +0000
+++ gpu/command_buffer/service/shared_image/dawn_ozone_image_representation.cc
@@ -194,6 +194,7 @@ void DawnOzoneImageRepresentation::EndAc
   if (!texture_) {
     return;
   }
+#if 0
   wgpu::SharedTextureMemoryEndAccessState end_access_desc = {};
   wgpu::SharedTextureMemoryVkImageLayoutEndState end_layout{};
   end_access_desc.nextInChain = &end_layout;
@@ -243,6 +244,12 @@ void DawnOzoneImageRepresentation::EndAc
 
   texture_.Destroy();
   texture_ = nullptr;
+#else
+    LOG(ERROR) << "Failed to end access for DawnOzoneImageRepresentation";
+    texture_.Destroy();
+    texture_ = nullptr;
+    return;
+#endif
 }
 
 }  // namespace gpu
