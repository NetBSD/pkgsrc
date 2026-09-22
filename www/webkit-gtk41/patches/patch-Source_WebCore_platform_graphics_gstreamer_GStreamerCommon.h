$NetBSD: patch-Source_WebCore_platform_graphics_gstreamer_GStreamerCommon.h,v 1.1 2026/09/22 12:27:03 wiz Exp $

Bug fix for 2.54.0
https://lists.webkit.org/archives/list/webkit-gtk@lists.webkit.org/thread/FPLRIJ2HSM3Q43TKUH64OR5DBXYVGMZ3/

--- Source/WebCore/platform/graphics/gstreamer/GStreamerCommon.h.orig	2026-09-18 08:36:48.629470640 +0000
+++ Source/WebCore/platform/graphics/gstreamer/GStreamerCommon.h
@@ -36,7 +36,7 @@
 #include <wtf/text/CStringView.h>
 
 #if USE(GSTREAMER_GL)
-#include "GraphicsTypesGL.h"
+#include "WebCore/GraphicsTypesGL.h"
 #endif
 
 namespace WebCore {
