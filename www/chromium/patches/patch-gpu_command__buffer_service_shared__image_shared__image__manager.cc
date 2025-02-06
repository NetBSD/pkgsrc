$NetBSD: patch-gpu_command__buffer_service_shared__image_shared__image__manager.cc,v 1.1 2025/02/06 09:58:10 wiz Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- gpu/command_buffer/service/shared_image/shared_image_manager.cc.orig	2024-12-17 17:58:49.000000000 +0000
+++ gpu/command_buffer/service/shared_image/shared_image_manager.cc
@@ -605,7 +605,7 @@ bool SharedImageManager::SupportsScanout
   return true;
 #elif BUILDFLAG(IS_ANDROID)
   return base::AndroidHardwareBufferCompat::IsSupportAvailable();
-#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_FUCHSIA)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_BSD)
   // We are in the process of tightening scanout support on Ozone to be guarded
   // by overlays being supported rather than merely native pixmaps being
   // supported, as native pixmap support doesn't always imply that those native
