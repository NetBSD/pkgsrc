$NetBSD: patch-Source_WebKit_WebProcess_WebPage_CoordinatedGraphics_ThreadedCompositor.cpp,v 1.1 2026/08/30 14:25:06 wiz Exp $

https://github.com/WebKit/WebKit/pull/64743

--- Source/WebKit/WebProcess/WebPage/CoordinatedGraphics/ThreadedCompositor.cpp.orig	2026-05-11 22:43:24.758132262 +0000
+++ Source/WebKit/WebProcess/WebPage/CoordinatedGraphics/ThreadedCompositor.cpp
@@ -53,6 +53,19 @@
 #include <GLES2/gl2.h>
 #endif
 
+#ifdef Always
+#undef Always
+#endif
+#ifdef Below
+#undef Below
+#endif
+#ifdef None
+#undef None
+#endif
+#ifdef True
+#undef True
+#endif
+
 namespace WebKit {
 using namespace WebCore;
 
