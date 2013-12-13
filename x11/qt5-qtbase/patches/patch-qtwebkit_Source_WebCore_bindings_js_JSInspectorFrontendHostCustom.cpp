$NetBSD: patch-qtwebkit_Source_WebCore_bindings_js_JSInspectorFrontendHostCustom.cpp,v 1.1 2013/12/13 14:38:35 ryoon Exp $

* Add NetBSD support

--- qtwebkit/Source/WebCore/bindings/js/JSInspectorFrontendHostCustom.cpp.orig	2013-11-27 01:01:47.000000000 +0000
+++ qtwebkit/Source/WebCore/bindings/js/JSInspectorFrontendHostCustom.cpp
@@ -63,6 +63,8 @@ JSValue JSInspectorFrontendHost::platfor
     DEFINE_STATIC_LOCAL(const String, platform, (ASCIILiteral("freebsd")));
 #elif OS(OPENBSD)
     DEFINE_STATIC_LOCAL(const String, platform, (ASCIILiteral("openbsd")));
+#elif OS(NETBSD)
+    DEFINE_STATIC_LOCAL(const String, platform, (ASCIILiteral("netbsd")));
 #elif OS(SOLARIS)
     DEFINE_STATIC_LOCAL(const String, platform, (ASCIILiteral("solaris")));
 #else
