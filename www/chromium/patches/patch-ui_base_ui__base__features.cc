$NetBSD: patch-ui_base_ui__base__features.cc,v 1.25 2026/09/02 13:13:38 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- ui/base/ui_base_features.cc.orig	2026-08-31 22:47:51.000000000 +0000
+++ ui/base/ui_base_features.cc
@@ -144,7 +144,7 @@ BASE_FEATURE(kWaylandExternalBeginFrameS
              base::FEATURE_DISABLED_BY_DEFAULT);
 #endif  // BUILDFLAG(IS_OZONE)
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 BASE_FEATURE(kGlobalShortcutsPortalPreferredTrigger,
              base::FEATURE_DISABLED_BY_DEFAULT);
 #endif
@@ -200,7 +200,7 @@ BASE_FEATURE(kUiCompositorUsesLayerLists
 // Enables the use of a touch fling curve that is based on the behavior of
 // native apps on Windows.
 BASE_FEATURE(kExperimentalFlingAnimation,
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
              base::FEATURE_ENABLED_BY_DEFAULT
 #else
              base::FEATURE_DISABLED_BY_DEFAULT
@@ -274,7 +274,7 @@ bool IsTouchTextEditingRedesignEnabled()
 // This feature enables drag and drop using touch input devices.
 BASE_FEATURE(kTouchDragAndDrop,
 #if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_WIN) || \
-    BUILDFLAG(IS_LINUX)
+    BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
              base::FEATURE_ENABLED_BY_DEFAULT
 #else
              base::FEATURE_DISABLED_BY_DEFAULT
@@ -301,7 +301,7 @@ bool IsForcedColorsEnabled() {
 // milestones.
 BASE_FEATURE(kEyeDropper,
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
              base::FEATURE_ENABLED_BY_DEFAULT
 #else
              base::FEATURE_DISABLED_BY_DEFAULT
