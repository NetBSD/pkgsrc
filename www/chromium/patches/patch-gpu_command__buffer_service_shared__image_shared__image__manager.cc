$NetBSD: patch-gpu_command__buffer_service_shared__image_shared__image__manager.cc,v 1.14 2026/01/19 16:14:16 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- gpu/command_buffer/service/shared_image/shared_image_manager.cc.orig	2026-01-07 00:50:30.000000000 +0000
+++ gpu/command_buffer/service/shared_image/shared_image_manager.cc
@@ -769,7 +769,7 @@ bool SharedImageManager::SupportsScanout
   return true;
 #elif BUILDFLAG(IS_ANDROID)
   return true;
-#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_FUCHSIA)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_BSD)
   return supports_overlays_on_ozone_;
 #elif BUILDFLAG(IS_WIN)
   return gl::DirectCompositionTextureSupported();
