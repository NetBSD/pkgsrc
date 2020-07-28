$NetBSD: patch-Source_WebCore_rendering_RenderLayerBacking.h,v 1.1 2020/07/28 14:24:03 leot Exp $

Define non-stardard __WORDSIZE.

--- Source/WebCore/rendering/RenderLayerBacking.h.orig	2020-02-04 10:24:08.000000000 +0000
+++ Source/WebCore/rendering/RenderLayerBacking.h
@@ -33,6 +33,10 @@
 #include "RenderLayerCompositor.h"
 #include "ScrollingCoordinator.h"
 
+#ifndef __WORDSIZE
+#define __WORDSIZE (__SIZEOF_LONG__ * 8)
+#endif
+
 namespace WebCore {
 
 class EventRegionContext;
