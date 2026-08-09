$NetBSD: patch-ui_views_views__features.cc,v 1.1 2026/08/09 06:31:25 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- ui/views/views_features.cc.orig	2026-08-05 20:17:42.000000000 +0000
+++ ui/views/views_features.cc
@@ -50,7 +50,7 @@ BASE_FEATURE(kKeyboardAccessibleTooltipI
              base::FEATURE_ENABLED_BY_DEFAULT);
 
 // Uses NativeViewHostAuraWithClipWindow instead of NativeViewHostAura.
-#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 BASE_FEATURE(kUseNativeViewHostAuraWithClipWindow,
              base::FEATURE_DISABLED_BY_DEFAULT);
 #else
