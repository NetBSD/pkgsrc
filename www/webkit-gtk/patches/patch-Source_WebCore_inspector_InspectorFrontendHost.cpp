$NetBSD: patch-Source_WebCore_inspector_InspectorFrontendHost.cpp,v 1.1 2018/10/24 18:31:07 leot Exp $

Add support for NetBSD.

--- Source/WebCore/inspector/InspectorFrontendHost.cpp.orig	2018-08-06 14:07:41.000000000 +0000
+++ Source/WebCore/inspector/InspectorFrontendHost.cpp
@@ -279,6 +279,8 @@ String InspectorFrontendHost::platform()
     return "freebsd"_s;
 #elif OS(OPENBSD)
     return "openbsd"_s;
+#elif OS(NETBSD)
+    return "netbsd"_s;
 #else
     return "unknown"_s;
 #endif
