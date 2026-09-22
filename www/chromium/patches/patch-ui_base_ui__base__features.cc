$NetBSD: patch-ui_base_ui__base__features.cc,v 1.26 2026/09/22 13:41:33 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- ui/base/ui_base_features.cc.orig	2026-09-14 22:17:16.000000000 +0000
+++ ui/base/ui_base_features.cc
@@ -148,7 +148,7 @@ BASE_FEATURE(kWaylandExternalBeginFrameS
              base::FEATURE_DISABLED_BY_DEFAULT);
 #endif  // BUILDFLAG(IS_OZONE)
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 BASE_FEATURE(kGlobalShortcutsPortalPreferredTrigger,
              base::FEATURE_DISABLED_BY_DEFAULT);
 #endif
@@ -204,7 +204,7 @@ BASE_FEATURE(kUiCompositorUsesLayerLists
 // Enables the use of a touch fling curve that is based on the behavior of
 // native apps on Windows.
 BASE_FEATURE(kExperimentalFlingAnimation,
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
              base::FEATURE_ENABLED_BY_DEFAULT
 #else
              base::FEATURE_DISABLED_BY_DEFAULT
@@ -278,7 +278,7 @@ bool IsTouchTextEditingRedesignEnabled()
 // This feature enables drag and drop using touch input devices.
 BASE_FEATURE(kTouchDragAndDrop,
 #if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_WIN) || \
-    BUILDFLAG(IS_LINUX)
+    BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
              base::FEATURE_ENABLED_BY_DEFAULT
 #else
              base::FEATURE_DISABLED_BY_DEFAULT
@@ -305,7 +305,7 @@ bool IsForcedColorsEnabled() {
 // milestones.
 BASE_FEATURE(kEyeDropper,
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
              base::FEATURE_ENABLED_BY_DEFAULT
 #else
              base::FEATURE_DISABLED_BY_DEFAULT
@@ -527,7 +527,7 @@ BASE_FEATURE(kWebUIRoundedIcons, base::F
 // Updates the default dark neutrals for the theme palette.
 BASE_FEATURE(kChromeDarkNeutrals26, base::FEATURE_DISABLED_BY_DEFAULT);
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 BASE_FEATURE(kUsePortalAccentColor, base::FEATURE_ENABLED_BY_DEFAULT);
 #endif
 
