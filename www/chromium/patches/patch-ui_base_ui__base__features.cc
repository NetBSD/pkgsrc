$NetBSD: patch-ui_base_ui__base__features.cc,v 1.11 2025/12/11 09:13:47 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- ui/base/ui_base_features.cc.orig	2025-11-19 21:40:05.000000000 +0000
+++ ui/base/ui_base_features.cc
@@ -108,7 +108,7 @@ BASE_FEATURE(kWaylandLinuxDrmSyncobj, ba
 
 // Controls whether support for Wayland's per-surface scaling is enabled.
 BASE_FEATURE(kWaylandPerSurfaceScale,
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
              base::FEATURE_ENABLED_BY_DEFAULT
 #else
              base::FEATURE_DISABLED_BY_DEFAULT
@@ -165,7 +165,7 @@ BASE_FEATURE(kUiCompositorUsesLayerLists
 // Enables the use of a touch fling curve that is based on the behavior of
 // native apps on Windows.
 BASE_FEATURE(kExperimentalFlingAnimation,
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
              base::FEATURE_ENABLED_BY_DEFAULT
 #else
              base::FEATURE_DISABLED_BY_DEFAULT
@@ -254,7 +254,7 @@ bool IsForcedColorsEnabled() {
 // milestones.
 BASE_FEATURE(kEyeDropper,
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
              base::FEATURE_ENABLED_BY_DEFAULT
 #else
              base::FEATURE_DISABLED_BY_DEFAULT
