$NetBSD: patch-components_segmentation__platform_embedder_default__model_cross__device__user__segment.cc,v 1.7 2025/09/12 16:02:27 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- components/segmentation_platform/embedder/default_model/cross_device_user_segment.cc.orig	2025-09-08 23:21:33.000000000 +0000
+++ components/segmentation_platform/embedder/default_model/cross_device_user_segment.cc
@@ -147,7 +147,7 @@ void CrossDeviceUserSegment::ExecuteMode
 // Check for current device type and subtract it from the device count
 // calculation.
 #if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || \
-    BUILDFLAG(IS_WIN)
+    BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
   desktop_count -= 1;
 #elif BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_IOS)
   if (ui::GetDeviceFormFactor() == ui::DEVICE_FORM_FACTOR_TABLET) {
