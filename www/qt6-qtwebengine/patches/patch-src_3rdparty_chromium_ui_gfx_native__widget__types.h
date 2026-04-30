$NetBSD: patch-src_3rdparty_chromium_ui_gfx_native__widget__types.h,v 1.2 2026/04/30 06:39:45 adam Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- src/3rdparty/chromium/ui/gfx/native_widget_types.h.orig	2026-03-16 11:40:07.000000000 +0000
+++ src/3rdparty/chromium/ui/gfx/native_widget_types.h
@@ -102,7 +102,7 @@ class ViewAndroid;
 #endif
 class SkBitmap;
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 extern "C" {
 struct _AtkObject;
 using AtkObject = struct _AtkObject;
@@ -186,7 +186,7 @@ using NativeViewAccessible = IAccessible
 using NativeViewAccessible = base::apple::OwnedNSObject;
 #elif BUILDFLAG(IS_MAC)
 using NativeViewAccessible = base::apple::OwnedNSAccessibility;
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 // Linux doesn't have a native accessibility type.
 using NativeViewAccessible = AtkObject*;
 #else
