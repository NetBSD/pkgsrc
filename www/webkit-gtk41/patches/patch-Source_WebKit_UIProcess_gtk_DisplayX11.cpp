$NetBSD: patch-Source_WebKit_UIProcess_gtk_DisplayX11.cpp,v 1.1 2026/08/30 14:25:06 wiz Exp $

https://github.com/WebKit/WebKit/pull/64743

--- Source/WebKit/UIProcess/gtk/DisplayX11.cpp.orig	2026-05-11 22:39:33.571425983 +0000
+++ Source/WebKit/UIProcess/gtk/DisplayX11.cpp
@@ -41,6 +41,10 @@
 #include <gdk/gdkx.h>
 #endif
 
+#ifdef Status
+#undef Status
+#endif
+
 namespace WebKit {
 using namespace WebCore;
 
