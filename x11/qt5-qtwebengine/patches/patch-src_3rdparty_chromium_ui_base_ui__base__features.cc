$NetBSD: patch-src_3rdparty_chromium_ui_base_ui__base__features.cc,v 1.1 2021/08/03 21:04:36 markd Exp $

--- src/3rdparty/chromium/ui/base/ui_base_features.cc.orig	2020-11-07 01:22:36.000000000 +0000
+++ src/3rdparty/chromium/ui/base/ui_base_features.cc
@@ -121,7 +121,7 @@ const base::Feature kPrecisionTouchpadLo
     "PrecisionTouchpadLogging", base::FEATURE_DISABLED_BY_DEFAULT};
 #endif  // defined(OS_WIN)
 
-#if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX)
+#if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX) || defined(OS_BSD)
 // Enables stylus appearing as touch when in contact with digitizer.
 const base::Feature kDirectManipulationStylus = {
     "DirectManipulationStylus",
@@ -158,7 +158,7 @@ bool IsEyeDropperEnabled() {
 // Mac launch bug.
 const base::Feature kFormControlsRefresh = {"FormControlsRefresh",
 #if defined(OS_WIN) || defined(OS_CHROMEOS) || defined(OS_LINUX) || \
-    defined(OS_MACOSX)
+    defined(OS_MACOSX) || defined(OS_BSD)
                                             base::FEATURE_ENABLED_BY_DEFAULT
 #else
                                             base::FEATURE_DISABLED_BY_DEFAULT
