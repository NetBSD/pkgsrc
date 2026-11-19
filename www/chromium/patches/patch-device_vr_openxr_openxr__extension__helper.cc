$NetBSD: patch-device_vr_openxr_openxr__extension__helper.cc,v 1.1 2026/11/19 19:46:02 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- device/vr/openxr/openxr_extension_helper.cc.orig	2026-11-11 21:01:38.000000000 +0000
+++ device/vr/openxr/openxr_extension_helper.cc
@@ -227,7 +227,7 @@ bool OpenXrExtensionHelper::IsFeatureSup
       return IsExtensionSupported(
           XR_MSFT_SECONDARY_VIEW_CONFIGURATION_EXTENSION_NAME);
     case device::mojom::XRSessionFeature::LAYERS:
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
       // Few Linux runtimes support all of these, so the graphics binding
       // refuses the layer types it cannot create instead.
       return true;
