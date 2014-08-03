$NetBSD: patch-Source_WebKit2_WebProcess_WebCoreSupport_WebPlatformStrategies.cpp,v 1.1 2014/08/03 22:07:39 wiz Exp $

--- Source/WebKit2/WebProcess/WebCoreSupport/WebPlatformStrategies.cpp.orig	2013-05-08 08:54:13.000000000 +0000
+++ Source/WebKit2/WebProcess/WebCoreSupport/WebPlatformStrategies.cpp
@@ -118,7 +118,7 @@ void handleDidGetPlugins(uint64_t reques
 
 static uint64_t generateRequestID()
 {
-    static int uniqueID;
+    static atomic_int uniqueID;
     return atomicIncrement(&uniqueID);
 }
 
