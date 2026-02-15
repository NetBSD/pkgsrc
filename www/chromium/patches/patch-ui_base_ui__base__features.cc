$NetBSD: patch-ui_base_ui__base__features.cc,v 1.15 2026/02/15 09:04:13 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- ui/base/ui_base_features.cc.orig	2026-02-03 22:07:10.000000000 +0000
+++ ui/base/ui_base_features.cc
@@ -109,7 +109,7 @@ BASE_FEATURE(kOzoneBubblesUsePlatformWid
 
 // Controls whether support for Wayland's per-surface scaling is enabled.
 BASE_FEATURE(kWaylandPerSurfaceScale,
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
              base::FEATURE_ENABLED_BY_DEFAULT
 #else
              base::FEATURE_DISABLED_BY_DEFAULT
@@ -174,7 +174,7 @@ BASE_FEATURE(kUiCompositorUsesLayerLists
 // Enables the use of a touch fling curve that is based on the behavior of
 // native apps on Windows.
 BASE_FEATURE(kExperimentalFlingAnimation,
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
              base::FEATURE_ENABLED_BY_DEFAULT
 #else
              base::FEATURE_DISABLED_BY_DEFAULT
@@ -263,7 +263,7 @@ bool IsForcedColorsEnabled() {
 // milestones.
 BASE_FEATURE(kEyeDropper,
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
              base::FEATURE_ENABLED_BY_DEFAULT
 #else
              base::FEATURE_DISABLED_BY_DEFAULT
