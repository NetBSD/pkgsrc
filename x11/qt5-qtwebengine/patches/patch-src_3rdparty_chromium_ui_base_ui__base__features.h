$NetBSD: patch-src_3rdparty_chromium_ui_base_ui__base__features.h,v 1.2 2022/04/18 11:18:19 adam Exp $

--- src/3rdparty/chromium/ui/base/ui_base_features.h.orig	2021-02-19 16:41:59.000000000 +0000
+++ src/3rdparty/chromium/ui/base/ui_base_features.h
@@ -61,7 +61,7 @@ COMPONENT_EXPORT(UI_BASE_FEATURES) bool 
 #endif  // defined(OS_WIN)
 
 #if defined(OS_WIN) || defined(OS_APPLE) || defined(OS_LINUX) || \
-    defined(OS_CHROMEOS)
+    defined(OS_CHROMEOS) || defined(OS_BSD)
 COMPONENT_EXPORT(UI_BASE_FEATURES)
 extern const base::Feature kDirectManipulationStylus;
 #endif  // defined(OS_WIN) || defined(OS_APPLE) || defined(OS_LINUX) ||
