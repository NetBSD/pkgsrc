$NetBSD: patch-Source_WebCore_bindings_js_JSInspectorFrontendHostCustom.cpp,v 1.1 2013/02/02 16:59:35 jmcneill Exp $

--- Source/WebCore/bindings/js/JSInspectorFrontendHostCustom.cpp.orig	2012-10-16 15:22:38.000000000 +0000
+++ Source/WebCore/bindings/js/JSInspectorFrontendHostCustom.cpp
@@ -61,6 +61,8 @@ JSValue JSInspectorFrontendHost::platfor
     DEFINE_STATIC_LOCAL(const String, platform, ("linux"));
 #elif OS(FREEBSD)
     DEFINE_STATIC_LOCAL(const String, platform, ("freebsd"));
+#elif OS(NETBSD)
+    DEFINE_STATIC_LOCAL(const String, platform, ("netbsd"));
 #elif OS(OPENBSD)
     DEFINE_STATIC_LOCAL(const String, platform, ("openbsd"));
 #elif OS(SOLARIS)
