$NetBSD: patch-ui_gfx_native__widget__types.h,v 1.7 2025/09/12 16:02:38 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- ui/gfx/native_widget_types.h.orig	2025-09-08 23:21:33.000000000 +0000
+++ ui/gfx/native_widget_types.h
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
