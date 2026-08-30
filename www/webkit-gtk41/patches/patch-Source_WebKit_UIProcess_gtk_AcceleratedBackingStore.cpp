$NetBSD: patch-Source_WebKit_UIProcess_gtk_AcceleratedBackingStore.cpp,v 1.1 2026/08/30 14:25:06 wiz Exp $

Disable dma buf renderer by default.

--- Source/WebKit/UIProcess/gtk/AcceleratedBackingStore.cpp.orig	2025-09-23 16:55:17.436853256 +0000
+++ Source/WebKit/UIProcess/gtk/AcceleratedBackingStore.cpp
@@ -84,7 +84,11 @@ OptionSet<RendererBufferTransportMode> A
     static OptionSet<RendererBufferTransportMode> mode;
     static std::once_flag onceFlag;
     std::call_once(onceFlag, [] {
+#if defined(__NetBSD__)
+        const char* disableDMABuf = "1";
+#else
         const char* disableDMABuf = getenv("WEBKIT_DISABLE_DMABUF_RENDERER");
+#endif
         if (disableDMABuf && g_strcmp0(disableDMABuf, "0"))
             return;
 
