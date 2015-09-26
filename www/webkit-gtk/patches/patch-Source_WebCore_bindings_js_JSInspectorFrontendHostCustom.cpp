$NetBSD: patch-Source_WebCore_bindings_js_JSInspectorFrontendHostCustom.cpp,v 1.4 2015/09/26 10:16:38 leot Exp $

--- Source/WebCore/bindings/js/JSInspectorFrontendHostCustom.cpp.orig	2015-09-21 07:29:46.000000000 +0000
+++ Source/WebCore/bindings/js/JSInspectorFrontendHostCustom.cpp
@@ -59,6 +59,8 @@ JSValue JSInspectorFrontendHost::platfor
     DEPRECATED_DEFINE_STATIC_LOCAL(const String, platform, (ASCIILiteral("linux")));
 #elif OS(FREEBSD)
     DEPRECATED_DEFINE_STATIC_LOCAL(const String, platform, (ASCIILiteral("freebsd")));
+#elif OS(NETBSD)
+    DEPRECATED_DEFINE_STATIC_LOCAL(const String, platform, (ASCIILiteral("netbsd")));
 #elif OS(OPENBSD)
     DEPRECATED_DEFINE_STATIC_LOCAL(const String, platform, (ASCIILiteral("openbsd")));
 #elif OS(SOLARIS)
