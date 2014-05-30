$NetBSD: patch-toolkit_library_nsStaticXULComponents.cpp,v 1.1 2014/05/30 03:03:36 pho Exp $

Don't assume cocoa toolkit just because OS_ARCH is Darwin.

--- toolkit/library/nsStaticXULComponents.cpp.orig	2014-05-06 22:56:34.000000000 +0000
+++ toolkit/library/nsStaticXULComponents.cpp
@@ -29,7 +29,7 @@
 
 #ifdef XP_WIN
 #  define WIDGET_MODULES MODULE(nsWidgetModule)
-#elif defined(XP_MACOSX)
+#elif defined(MOZ_WIDGET_COCOA)
 #  define WIDGET_MODULES MODULE(nsWidgetMacModule)
 #elif defined(XP_OS2)
 #  define WIDGET_MODULES MODULE(nsWidgetOS2Module)
@@ -122,7 +122,7 @@
 #define UNIXPROXY_MODULE
 #endif
 
-#if defined(XP_MACOSX)
+#if defined(MOZ_WIDGET_COCOA)
 #define OSXPROXY_MODULE MODULE(nsOSXProxyModule)
 #else
 #define OSXPROXY_MODULE
