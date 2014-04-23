$NetBSD: patch-qtwebkit_Source_JavaScriptCore_API_ObjCCallbackFunction.h,v 1.1 2014/04/23 07:05:31 adam Exp $

--- qtwebkit/Source/JavaScriptCore/API/ObjCCallbackFunction.h.orig	2014-04-21 21:08:37.000000000 +0000
+++ qtwebkit/Source/JavaScriptCore/API/ObjCCallbackFunction.h
@@ -29,7 +29,7 @@
 
 #if JSC_OBJC_API_ENABLED
 
-#import <JavaScriptCore/JSCallbackFunction.h>
+#import <JavaScriptCore/API/JSCallbackFunction.h>
 
 #if defined(__OBJC__)
 JSObjectRef objCCallbackFunctionForMethod(JSContext *, Class, Protocol *, BOOL isInstanceMethod, SEL, const char* types);
