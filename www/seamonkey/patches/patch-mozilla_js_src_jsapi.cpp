$NetBSD: patch-mozilla_js_src_jsapi.cpp,v 1.4 2015/09/21 05:03:45 ryoon Exp $

--- mozilla/js/src/jsapi.cpp.orig	2015-09-02 09:27:32.000000000 +0000
+++ mozilla/js/src/jsapi.cpp
@@ -115,7 +115,7 @@ using js::frontend::Parser;
 #define JS_ADDRESSOF_VA_LIST(ap) (&(ap))
 #endif
 
-bool
+JS_PUBLIC_API(bool)
 JS::CallArgs::requireAtLeast(JSContext* cx, const char* fnname, unsigned required) {
     if (length() < required) {
         char numArgsStr[40];
