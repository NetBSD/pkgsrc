$NetBSD: patch-ui_gfx_native__ui__types.h,v 1.6 2026/01/19 16:14:22 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- ui/gfx/native_ui_types.h.orig	2026-01-07 00:50:30.000000000 +0000
+++ ui/gfx/native_ui_types.h
@@ -101,7 +101,7 @@ class ViewAndroid;
 }  // namespace ui
 #endif
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 extern "C" {
 struct _AtkObject;
 using AtkObject = struct _AtkObject;
@@ -190,7 +190,7 @@ using NativeViewAccessible = IAccessible
 using NativeViewAccessible = base::apple::OwnedNSObject;
 #elif BUILDFLAG(IS_MAC)
 using NativeViewAccessible = base::apple::OwnedNSAccessibility;
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 // Linux doesn't have a native accessibility type.
 using NativeViewAccessible = AtkObject*;
 #else
