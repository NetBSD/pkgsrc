$NetBSD: patch-gpu_command__buffer_service_shared__image_ozone__image__backing.cc,v 1.3 2026/08/09 06:31:17 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- gpu/command_buffer/service/shared_image/ozone_image_backing.cc.orig	2026-08-05 20:17:42.000000000 +0000
+++ gpu/command_buffer/service/shared_image/ozone_image_backing.cc
@@ -497,7 +497,7 @@ std::unique_ptr<VulkanImageRepresentatio
     native_pixmap_handle.planes[1].offset = image_size.GetArea();
     native_pixmap_handle.planes[1].size = image_size.GetArea() / 2;
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
     base::CheckedNumeric<uint64_t> checked_required =
         native_pixmap_handle.planes[1].offset;
     checked_required += native_pixmap_handle.planes[1].size;
