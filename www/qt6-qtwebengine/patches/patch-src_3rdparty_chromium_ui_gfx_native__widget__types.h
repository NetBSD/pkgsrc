$NetBSD: patch-src_3rdparty_chromium_ui_gfx_native__widget__types.h,v 1.1 2025/12/21 09:38:48 markd Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- src/3rdparty/chromium/ui/gfx/native_widget_types.h.orig	2025-10-02 00:36:39.000000000 +0000
+++ src/3rdparty/chromium/ui/gfx/native_widget_types.h
@@ -101,7 +101,7 @@ class ViewAndroid;
 #endif
 class SkBitmap;
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 extern "C" {
 struct _AtkObject;
 using AtkObject = struct _AtkObject;
@@ -214,7 +214,7 @@ using NativeViewAccessible = id;
 #else
 using NativeViewAccessible = struct objc_object*;
 #endif
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 // Linux doesn't have a native font type.
 using NativeViewAccessible = AtkObject*;
 #else
