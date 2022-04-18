$NetBSD: patch-src_3rdparty_chromium_ui_base_ui__base__features.cc,v 1.2 2022/04/18 11:18:19 adam Exp $

--- src/3rdparty/chromium/ui/base/ui_base_features.cc.orig	2021-02-19 16:41:59.000000000 +0000
+++ src/3rdparty/chromium/ui/base/ui_base_features.cc
@@ -133,7 +133,7 @@ const base::Feature kPrecisionTouchpadLo
 #endif  // defined(OS_WIN)
 
 #if defined(OS_WIN) || defined(OS_APPLE) || defined(OS_LINUX) || \
-    defined(OS_CHROMEOS)
+    defined(OS_CHROMEOS) || defined(OS_BSD)
 // Enables stylus appearing as touch when in contact with digitizer.
 const base::Feature kDirectManipulationStylus = {
     "DirectManipulationStylus",
@@ -183,7 +183,7 @@ bool IsCSSColorSchemeUARenderingEnabled(
 // Mac launch bug.
 const base::Feature kFormControlsRefresh = {"FormControlsRefresh",
 #if defined(OS_WIN) || defined(OS_CHROMEOS) || defined(OS_LINUX) || \
-    defined(OS_APPLE)
+    defined(OS_APPLE) || defined(OS_BSD)
                                             base::FEATURE_ENABLED_BY_DEFAULT
 #else
                                             base::FEATURE_DISABLED_BY_DEFAULT
