$NetBSD: patch-Source_WebCore_loader_cache_CachedResource.h,v 1.1 2026/08/30 14:25:05 wiz Exp $

In file included from /usr/pkg/include/EGL/eglplatform.h:134,
                 from /usr/pkg/include/epoxy/egl_generated.h:11,
                 from /usr/pkg/include/epoxy/egl.h:46,
                 from /tmp/wip/webkit-gtk60/work/webkitgtk-2.52.3/Source/WebKit/WebProcess/WebPage/CoordinatedGraphics/ThreadedCompositor.cpp:50,
                 from /tmp/wip/webkit-gtk60/work/webkitgtk-2.52.3/cmake-pkgsrc-build/DerivedSources/WebKit/unified-sources/UnifiedSource-54928a2b-33.cpp:1:
/tmp/wip/webkit-gtk60/work/webkitgtk-2.52.3/cmake-pkgsrc-build/WebCore/PrivateHeaders/WebCore/CachedResource.h:120:10: error: expected identifier before 'int'
  120 |     enum Status : uint8_t {
      |          ^~~~~~

https://github.com/WebKit/WebKit/pull/64743

--- Source/WebCore/loader/cache/CachedResource.h.orig	2026-04-17 08:44:48.754804603 +0000
+++ Source/WebCore/loader/cache/CachedResource.h
@@ -45,6 +45,10 @@
 #include <wtf/WeakHashMap.h>
 #include <wtf/text/WTFString.h>
 
+#ifdef Status
+#undef Status
+#endif
+
 namespace WebCore {
 class CachedResource;
 class CachedResourceCallback;
