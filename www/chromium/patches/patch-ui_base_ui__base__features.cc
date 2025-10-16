$NetBSD: patch-ui_base_ui__base__features.cc,v 1.8 2025/10/16 19:43:37 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- ui/base/ui_base_features.cc.orig	2025-10-13 21:41:26.000000000 +0000
+++ ui/base/ui_base_features.cc
@@ -124,7 +124,7 @@ BASE_FEATURE(kWaylandLinuxDrmSyncobj,
 // Controls whether support for Wayland's per-surface scaling is enabled.
 BASE_FEATURE(kWaylandPerSurfaceScale,
              "WaylandPerSurfaceScale",
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
              base::FEATURE_ENABLED_BY_DEFAULT
 #else
              base::FEATURE_DISABLED_BY_DEFAULT
@@ -200,7 +200,7 @@ BASE_FEATURE(kUiCompositorUsesLayerLists
 // native apps on Windows.
 BASE_FEATURE(kExperimentalFlingAnimation,
              "ExperimentalFlingAnimation",
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
              base::FEATURE_ENABLED_BY_DEFAULT
 #else
              base::FEATURE_DISABLED_BY_DEFAULT
@@ -298,7 +298,7 @@ bool IsForcedColorsEnabled() {
 BASE_FEATURE(kEyeDropper,
              "EyeDropper",
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
              base::FEATURE_ENABLED_BY_DEFAULT
 #else
              base::FEATURE_DISABLED_BY_DEFAULT
