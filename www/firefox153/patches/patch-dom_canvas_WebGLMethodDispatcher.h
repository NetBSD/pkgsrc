$NetBSD: patch-dom_canvas_WebGLMethodDispatcher.h,v 1.1 2026/08/27 01:23:16 gutteridge Exp $

- Work around broken WebGL method dispatch on NetBSD.
  From PR pkg/60579: www/firefox: WebGL does not work on NetBSD

--- dom/canvas/WebGLMethodDispatcher.h.orig	2026-07-27 13:13:11.000000000 +0000
+++ dom/canvas/WebGLMethodDispatcher.h
@@ -31,7 +31,18 @@ class WebGLMethodDispatcher
 
 // Defines each method the WebGLMethodDispatcher handles.  The COUNTER value
 // is used as a cross-process ID for each of the methods.
+#ifdef __NetBSD__
+// XXX: NetBSD system headers use __COUNTER__ in __CTASSERT(), so
+//      __COUNTER__ may already have been incremented when this header is
+//      included.  Normalize the method IDs so that they start at zero.
+constexpr size_t kWebGLMethodDispatcherCounterBase = __COUNTER__ + 1;
+
+#define DEFINE_ASYNC(_METHOD)                                      \
+  DEFINE_METHOD_DISPATCHER(                                        \
+      __COUNTER__ - kWebGLMethodDispatcherCounterBase, _METHOD, 0)
+#else
 #define DEFINE_ASYNC(_METHOD) DEFINE_METHOD_DISPATCHER(__COUNTER__, _METHOD, 0)
+#endif
 
 DEFINE_ASYNC(HostWebGLContext::CreateBuffer)
 DEFINE_ASYNC(HostWebGLContext::CreateFramebuffer)
