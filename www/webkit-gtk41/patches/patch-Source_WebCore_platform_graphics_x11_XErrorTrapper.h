$NetBSD: patch-Source_WebCore_platform_graphics_x11_XErrorTrapper.h,v 1.1 2026/08/30 14:25:05 wiz Exp $

https://github.com/WebKit/WebKit/pull/64743

--- Source/WebCore/platform/graphics/x11/XErrorTrapper.h.orig	2026-05-17 18:13:35.817512800 +0000
+++ Source/WebCore/platform/graphics/x11/XErrorTrapper.h
@@ -27,8 +27,20 @@
 
 #if PLATFORM(X11)
 #include <X11/Xlib.h>
+#ifdef Above
+#undef Above
+#endif
+#ifdef Always
+#undef Always
+#endif
+#ifdef Below
+#undef Below
+#endif
 #ifdef Success
 #undef Success
+#endif
+#ifdef True
+#undef True
 #endif
 #include <wtf/Vector.h>
 
