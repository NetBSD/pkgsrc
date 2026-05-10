$NetBSD: patch-components_segmentation__platform_embedder_default__model_cross__device__user__segment.cc,v 1.19 2026/05/10 15:29:56 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- components/segmentation_platform/embedder/default_model/cross_device_user_segment.cc.orig	2026-04-28 23:05:57.000000000 +0200
+++ components/segmentation_platform/embedder/default_model/cross_device_user_segment.cc
@@ -122,7 +122,7 @@ void CrossDeviceUserSegment::ExecuteMode
 // Check for current device type and subtract it from the device count
 // calculation.
 #if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || \
-    BUILDFLAG(IS_WIN)
+    BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
   desktop_count -= 1;
 #elif BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_IOS)
   if (ui::GetDeviceFormFactor() == ui::DEVICE_FORM_FACTOR_TABLET) {
