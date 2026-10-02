$NetBSD: patch-gpu_command__buffer_service_shared__image_ozone__image__backing.cc,v 1.7 2026/10/02 11:43:31 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- gpu/command_buffer/service/shared_image/ozone_image_backing.cc.orig	2026-09-22 00:09:16.000000000 +0000
+++ gpu/command_buffer/service/shared_image/ozone_image_backing.cc
@@ -500,7 +500,7 @@ std::unique_ptr<VulkanImageRepresentatio
     native_pixmap_handle.planes[1].offset = image_size.GetArea();
     native_pixmap_handle.planes[1].size = image_size.GetArea() / 2;
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
     base::CheckedNumeric<uint64_t> checked_required =
         native_pixmap_handle.planes[1].offset;
     checked_required += native_pixmap_handle.planes[1].size;
