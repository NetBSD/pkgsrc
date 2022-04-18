$NetBSD: patch-src_3rdparty_chromium_ui_gfx_native__widget__types.h,v 1.2 2022/04/18 11:18:19 adam Exp $

--- src/3rdparty/chromium/ui/gfx/native_widget_types.h.orig	2021-02-19 16:41:59.000000000 +0000
+++ src/3rdparty/chromium/ui/gfx/native_widget_types.h
@@ -103,7 +103,7 @@ class ViewAndroid;
 #endif
 class SkBitmap;
 
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_LINUX) || defined(OS_BSD)) && !defined(OS_CHROMEOS)
 extern "C" {
 struct _AtkObject;
 typedef struct _AtkObject AtkObject;
@@ -204,7 +204,7 @@ typedef id NativeViewAccessible;
 #elif defined(OS_MAC)
 typedef NSFont* NativeFont;
 typedef id NativeViewAccessible;
-#elif defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#elif (defined(OS_LINUX) || defined(OS_BSD)) && !defined(OS_CHROMEOS)
 // Linux doesn't have a native font type.
 typedef AtkObject* NativeViewAccessible;
 #else
