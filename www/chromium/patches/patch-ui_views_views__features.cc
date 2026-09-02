$NetBSD: patch-ui_views_views__features.cc,v 1.2 2026/09/02 13:13:40 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- ui/views/views_features.cc.orig	2026-08-31 22:47:51.000000000 +0000
+++ ui/views/views_features.cc
@@ -50,7 +50,7 @@ BASE_FEATURE(kKeyboardAccessibleTooltipI
              base::FEATURE_ENABLED_BY_DEFAULT);
 
 // If enabled, NativeViewHost controls the layers of the native view.
-#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 BASE_FEATURE(kNativeViewHostManagesLayers, base::FEATURE_ENABLED_BY_DEFAULT);
 #else
 BASE_FEATURE(kNativeViewHostManagesLayers, base::FEATURE_DISABLED_BY_DEFAULT);
