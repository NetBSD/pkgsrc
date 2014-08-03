$NetBSD: patch-Source_WebCore_bindings_js_JSInspectorFrontendHostCustom.cpp,v 1.2 2014/08/03 22:30:05 wiz Exp $

--- Source/WebCore/bindings/js/JSInspectorFrontendHostCustom.cpp.orig	2014-04-14 06:40:45.000000000 +0000
+++ Source/WebCore/bindings/js/JSInspectorFrontendHostCustom.cpp
@@ -61,6 +61,8 @@ JSValue JSInspectorFrontendHost::platfor
     DEFINE_STATIC_LOCAL(const String, platform, (ASCIILiteral("linux")));
 #elif OS(FREEBSD)
     DEFINE_STATIC_LOCAL(const String, platform, (ASCIILiteral("freebsd")));
+#elif OS(NETBSD)
+    DEFINE_STATIC_LOCAL(const String, platform, (ASCIILiteral("netbsd")));
 #elif OS(OPENBSD)
     DEFINE_STATIC_LOCAL(const String, platform, (ASCIILiteral("openbsd")));
 #elif OS(SOLARIS)
