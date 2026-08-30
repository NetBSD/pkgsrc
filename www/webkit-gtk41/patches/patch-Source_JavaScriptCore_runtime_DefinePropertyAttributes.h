$NetBSD: patch-Source_JavaScriptCore_runtime_DefinePropertyAttributes.h,v 1.1 2026/08/30 14:25:05 wiz Exp $

In file included from /usr/pkg/include/EGL/eglplatform.h:134,
                 from /usr/pkg/include/epoxy/egl_generated.h:11,
                 from /usr/pkg/include/epoxy/egl.h:46,
                 from /tmp/wip/webkit-gtk60/work/webkitgtk-2.52.3/Source/WebKit/WebProcess/WebPage/CoordinatedGraphics/ThreadedCompositor.cpp:50,
                 from /tmp/wip/webkit-gtk60/work/webkitgtk-2.52.3/cmake-pkgsrc-build/DerivedSources/WebKit/unified-sources/UnifiedSource-54928a2b-33.cpp:1:
/tmp/wip/webkit-gtk60/work/webkitgtk-2.52.3/cmake-pkgsrc-build/JavaScriptCore/PrivateHeaders/JavaScriptCore/DefinePropertyAttributes.h:35:51: error: expected unqualified-id before numeric constant
   35 |     static_assert(!static_cast<uint8_t>(TriState::False), "TriState::False is 0.");
      |                                                   ^~~~~

https://github.com/WebKit/WebKit/pull/64743

--- Source/JavaScriptCore/runtime/DefinePropertyAttributes.h.orig	2026-05-11 22:44:47.752626610 +0000
+++ Source/JavaScriptCore/runtime/DefinePropertyAttributes.h
@@ -28,6 +28,10 @@
 #include <optional>
 #include <wtf/TriState.h>
 
+#ifdef False
+#undef False
+#endif
+
 namespace JSC {
 
 class DefinePropertyAttributes {
