$NetBSD: patch-Source_WebCore_platform_graphics_skia_PlatformDisplaySkia.cpp,v 1.1 2026/08/30 14:25:05 wiz Exp $

https://github.com/WebKit/WebKit/pull/64743

--- Source/WebCore/platform/graphics/skia/PlatformDisplaySkia.cpp.orig	2026-05-11 22:05:44.502856896 +0000
+++ Source/WebCore/platform/graphics/skia/PlatformDisplaySkia.cpp
@@ -59,6 +59,10 @@ WTF_IGNORE_WARNINGS_IN_THIRD_PARTY_CODE_BEGIN
 #include <xf86drm.h>
 #endif
 
+#ifdef None
+#undef None
+#endif
+
 namespace WebCore {
 
 #if PLATFORM(GTK) || PLATFORM(WPE)
